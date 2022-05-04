#include "targets.h"
#include "common.h"
#include "device.h"
#include "msp.h"
#include "msptypes.h"

#define BACKPACK_TIMEOUT 20    // How often to chech for backpack commands

extern bool InBindingMode;
extern Stream *LoggingBackpack;

bool TxBackpackWiFiReadyToSend = false;
bool VRxBackpackWiFiReadyToSend = false;

#if defined(GPIO_PIN_BACKPACK_EN)

#ifndef PASSTHROUGH_BAUD
#define PASSTHROUGH_BAUD BACKPACK_LOGGING_BAUD
#endif

#include "CRSF.h"
#include "hwTimer.h"

void startPassthrough()
{
    // stop everyhting
    devicesStop();
    Radio.End();
    hwTimer::stop();
    CRSF::End();

    // get ready for passthrough
    if (GPIO_PIN_RCSIGNAL_RX == GPIO_PIN_RCSIGNAL_TX)
    {
        // if we have a single S.PORT pin for RX then we assume the standard UART pins for passthrough
        CRSF::Port.begin(PASSTHROUGH_BAUD, SERIAL_8N1, 3, 1);
    }
    else
    {
        CRSF::Port.begin(PASSTHROUGH_BAUD, SERIAL_8N1, GPIO_PIN_RCSIGNAL_RX, GPIO_PIN_RCSIGNAL_TX);
    }
    disableLoopWDT();

    HardwareSerial &backpack = *(HardwareSerial*)LoggingBackpack;
    if (PASSTHROUGH_BAUD != BACKPACK_LOGGING_BAUD && PASSTHROUGH_BAUD != -1)
    {
        backpack.begin(PASSTHROUGH_BAUD, SERIAL_8N1, GPIO_PIN_DEBUG_RX, GPIO_PIN_DEBUG_TX);
    }

    // reset ESP8285 into bootloader mode
    digitalWrite(GPIO_PIN_BACKPACK_BOOT, HIGH);
    delay(100);
    digitalWrite(GPIO_PIN_BACKPACK_EN, LOW);
    delay(100);
    digitalWrite(GPIO_PIN_BACKPACK_EN, HIGH);
    delay(50);
    digitalWrite(GPIO_PIN_BACKPACK_BOOT, LOW);

    CRSF::Port.flush();
    backpack.flush();

    uint8_t buf[64];
    while (backpack.available())
        backpack.readBytes(buf, sizeof(buf));

    // go hard!
    for (;;)
    {
        int r = CRSF::Port.available();
        if (r > sizeof(buf))
            r = sizeof(buf);
        r = CRSF::Port.readBytes(buf, r);
        backpack.write(buf, r);

        r = backpack.available();
        if (r > sizeof(buf))
            r = sizeof(buf);
        r = backpack.readBytes(buf, r);
        CRSF::Port.write(buf, r);
    }
}
#endif

static void BackpackWiFiToMSPOut(uint16_t command)
{
    mspPacket_t packet;
    packet.reset();
    packet.makeCommand();
    packet.function = command;
    packet.addByte(0);

    MSP::sendPacket(&packet, LoggingBackpack); // send to tx-backpack as MSP
}

void BackpackBinding()
{
    mspPacket_t packet;
    packet.reset();
    packet.makeCommand();
    packet.function = MSP_ELRS_BIND;
    packet.addByte(MasterUID[0]);
    packet.addByte(MasterUID[1]);
    packet.addByte(MasterUID[2]);
    packet.addByte(MasterUID[3]);
    packet.addByte(MasterUID[4]);
    packet.addByte(MasterUID[5]);

    MSP::sendPacket(&packet, LoggingBackpack); // send to tx-backpack as MSP
}

static void initialize()
{
#ifdef GPIO_PIN_BACKPACK_EN
    if (GPIO_PIN_BACKPACK_EN != UNDEF_PIN)
    {
        pinMode(0, INPUT); // setup so we can detect pinchange for passthrough mode
        // reset the ESP8285 so we know it's running
        pinMode(GPIO_PIN_BACKPACK_BOOT, OUTPUT);
        pinMode(GPIO_PIN_BACKPACK_EN, OUTPUT);
        digitalWrite(GPIO_PIN_BACKPACK_EN, LOW);   // enable low
        digitalWrite(GPIO_PIN_BACKPACK_BOOT, LOW); // bootloader pin high
        delay(50);
        digitalWrite(GPIO_PIN_BACKPACK_EN, HIGH); // enable high
    }
#endif
}

static int start()
{
    if (OPT_USE_TX_BACKPACK)
    {
        return DURATION_IMMEDIATELY;
    }
    return DURATION_NEVER;
}

static int timeout()
{
    if (InBindingMode)
    {
        BackpackBinding();
        return 1000;        // don't check for another second so we don't spam too hard :-)
    }

    if (TxBackpackWiFiReadyToSend && connectionState < MODE_STATES)
    {
        TxBackpackWiFiReadyToSend = false;
        BackpackWiFiToMSPOut(MSP_ELRS_SET_TX_BACKPACK_WIFI_MODE);
    }

    if (VRxBackpackWiFiReadyToSend && connectionState < MODE_STATES)
    {
        VRxBackpackWiFiReadyToSend = false;
        BackpackWiFiToMSPOut(MSP_ELRS_SET_VRX_BACKPACK_WIFI_MODE);
    }

#ifdef GPIO_PIN_BACKPACK_EN
    if (GPIO_PIN_BACKPACK_EN != UNDEF_PIN)
    {
        if (!digitalRead(0))
        {
            startPassthrough();
            return DURATION_NEVER;
        }
    }
#endif
    return BACKPACK_TIMEOUT;
}

device_t Backpack_device = {
    .initialize = initialize,
    .start = start,
    .event = NULL,
    .timeout = timeout
};
