#include "TXModule.h"
#include "LowPassFilter.h"

#ifdef FEATURE_OPENTX_SYNC_AUTOTUNE
static LPF LPF_OPENTX_SYNC_MARGIN(3);
static LPF LPF_OPENTX_SYNC_OFFSET(3);
#endif

void TXModule::begin(TransportLayer* dev)
{
  _dev = dev;
}

void ICACHE_RAM_ATTR TXModule::setPacketInterval(uint32_t interval)
{
    packetInterval = interval;

#ifdef FEATURE_OPENTX_SYNC_AUTOTUNE

    syncWaitPeriodCounter = millis();
    //TODO: no magic numbers
    syncOffsetSafeMargin = 1000;

    LPF_OPENTX_SYNC_OFFSET.init(0);
    LPF_OPENTX_SYNC_MARGIN.init(0);

#endif
}

void ICACHE_RAM_ATTR TXModule::onChannelDataIn()
{
    lastRecvChannels = micros();
}

void ICACHE_RAM_ATTR TXModule::onRadioPacketSent()
{
  syncOffset = micros() - lastRecvChannels;

  if (syncOffset > (int32_t)packetInterval)  // detect overrun case when the
                                             // packet arrives too late and
                                             // caculate negative offsets.
  {
      syncOffset = -(syncOffset % packetInterval);

#ifdef FEATURE_OPENTX_SYNC_AUTOTUNE
      // wait until we stablize after changing pkt rate
      if (millis() > (syncWaitPeriodCounter + AutoSyncWaitPeriod)) {
        syncOffsetSafeMargin =
            LPF_OPENTX_SYNC_MARGIN.update((syncOffsetSafeMargin - syncOffset) +
                                          //TODO: no magic numbers
                                          100);  // take worst case plus 50us
      }
#endif
  }

#ifdef FEATURE_OPENTX_SYNC_AUTOTUNE
  //TODO: no magic numbers
  if (syncOffsetSafeMargin > 4000) {
      syncOffsetSafeMargin = 4000;  // hard limit at no tune default
  } else if (syncOffsetSafeMargin < 1000) {
      syncOffsetSafeMargin = 1000;  // hard limit at no tune default
  }
#endif
}

void ICACHE_RAM_ATTR TXModule::send()
{
    // calculate mixer sync packet if needed
    sendSyncPacketToTX();
    flushTxBuffers();
}

void ICACHE_RAM_ATTR TXModule::poll(Channels* chan)
{
  while (_dev && _dev->available()) {
    char inChar = _dev->read();
    consumeInputByte(inChar, chan);
  }
}
