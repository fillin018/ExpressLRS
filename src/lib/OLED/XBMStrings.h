/*
 * This file is part of the ExpressLRS distribution (https://github.com/ExpressLRS/ExpressLRS).
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifdef TARGET_TX_GHOST

  static unsigned char ghost[] = {
    0x00, 0xF0, 0x0F, 0x00, 0x00, 0x7E, 0x7C, 0x00, 0x80, 0x03, 0xC0, 0x01,
    0xE0, 0x00, 0x00, 0x07, 0x70, 0x00, 0x00, 0x0E, 0x18, 0x00, 0x00, 0x18,
    0x0C, 0x38, 0x80, 0x31, 0x0C, 0xFC, 0xE0, 0x37, 0x06, 0x86, 0x31, 0x6C,
    0x06, 0x82, 0x31, 0x6C, 0x02, 0x82, 0x31, 0xCC, 0x03, 0xE2, 0x31, 0xCE,
    0x03, 0xE2, 0x31, 0xCF, 0x03, 0xE6, 0x31, 0xCF, 0x03, 0xCC, 0x60, 0xC6,
    0x03, 0x78, 0xC0, 0xC3, 0x03, 0x00, 0x00, 0xC0, 0x03, 0x00, 0x00, 0xC0,
    0x03, 0x00, 0x00, 0xC0, 0x03, 0x00, 0x00, 0xC0, 0x03, 0x00, 0x00, 0xC0,
    0x03, 0x00, 0x00, 0xC0, 0x03, 0x00, 0x00, 0xC0, 0x03, 0x00, 0x00, 0xC0,
    0x03, 0x00, 0x00, 0xC0, 0x03, 0x00, 0x00, 0xC0, 0x03, 0x00, 0x00, 0xC0,
    0x03, 0x00, 0x00, 0xC0, 0x03, 0x1F, 0xF8, 0xC0, 0x86, 0x31, 0x9C, 0xC1,
    0xEC, 0x60, 0x06, 0x77, 0x78, 0xC0, 0x03, 0x1E, };

#ifndef TARGET_TX_GHOST_LITE
  static unsigned char elrs40[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 0xC0,
    0xFF, 0x03, 0x00, 0x00, 0xF0, 0xE3, 0x0F, 0x00, 0x00, 0x78, 0x00, 0x1E,
    0x00, 0x00, 0x1C, 0x7E, 0x38, 0x00, 0x00, 0x8C, 0xFF, 0x31, 0x00, 0x00,
    0xE0, 0xC3, 0x07, 0x00, 0x00, 0xE0, 0x00, 0x07, 0x00, 0x00, 0x20, 0x7E,
    0x06, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x80, 0xC3, 0x01, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00,
    0x3C, 0x00, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00,
    0x00, 0x00, 0x01, 0x18, 0x80, 0x00, 0xC0, 0x07, 0x3C, 0xE0, 0x03, 0x60,
    0xF4, 0xFF, 0x2F, 0x06, 0x30, 0xF6, 0xFF, 0x6F, 0x0C, 0x18, 0x02, 0x00,
    0x40, 0x18, 0x08, 0x39, 0xFF, 0x9C, 0x10, 0x8C, 0x2C, 0x81, 0x34, 0x31,
    0xC4, 0x3C, 0x81, 0x3C, 0x23, 0x44, 0x18, 0x81, 0x18, 0x22, 0x44, 0x30,
    0xFF, 0x0C, 0x22, 0x44, 0xFC, 0x00, 0x3F, 0x22, 0x46, 0x86, 0x81, 0x61,
    0x62, 0x46, 0x3A, 0x81, 0x5C, 0x62, 0x46, 0x6C, 0x81, 0x36, 0x62, 0xC6,
    0x46, 0x99, 0x62, 0x63, 0x86, 0x63, 0x81, 0xC6, 0x61, 0xE6, 0xB1, 0x81,
    0x8D, 0x67, 0x06, 0xF8, 0x00, 0x1F, 0x60, 0x06, 0x0C, 0x00, 0x30, 0x60,
    0x06, 0x86, 0xFF, 0x61, 0x60, 0x06, 0x83, 0x81, 0xC1, 0x60, 0x06, 0x81,
    0x81, 0x81, 0x60, 0x86, 0xFD, 0xFF, 0xBF, 0x61, };

  static unsigned char elrs48[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x07, 0x00, 0x00,
    0x00, 0x00, 0xFC, 0x3F, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00,
    0x00, 0xC0, 0x1F, 0xF8, 0x03, 0x00, 0x00, 0xE0, 0x03, 0xC0, 0x07, 0x00,
    0x00, 0xF0, 0xF0, 0x0F, 0x0F, 0x00, 0x00, 0x70, 0xFC, 0x3F, 0x0E, 0x00,
    0x00, 0x00, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0x80, 0x0F, 0xF0, 0x00, 0x00,
    0x00, 0x80, 0x83, 0xE1, 0x01, 0x00, 0x00, 0x00, 0xF1, 0x8F, 0x00, 0x00,
    0x00, 0x00, 0xF8, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x1C, 0x00, 0x00,
    0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xC0, 0x03, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x03, 0x00, 0x00,
    0x00, 0x00, 0x40, 0x02, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x03, 0x00, 0x00,
    0x00, 0x00, 0xC0, 0x03, 0x00, 0x00, 0x00, 0x0F, 0xC0, 0x03, 0xF0, 0x00,
    0x80, 0x1B, 0x40, 0x02, 0xD8, 0x01, 0xC0, 0x91, 0xFF, 0xFF, 0x89, 0x03,
    0xE0, 0x98, 0xFF, 0xFF, 0x19, 0x07, 0x30, 0x18, 0x00, 0x00, 0x18, 0x0C,
    0x30, 0xCE, 0xF8, 0x1F, 0x33, 0x0C, 0x18, 0xE6, 0xF9, 0x9F, 0xE7, 0x18,
    0x08, 0xB3, 0x19, 0x98, 0xCD, 0x10, 0x8C, 0xE1, 0x19, 0x98, 0x87, 0x31,
    0x8C, 0xE1, 0x18, 0x18, 0x87, 0x31, 0x8C, 0x01, 0xF8, 0x1F, 0x80, 0x31,
    0x84, 0xE1, 0x03, 0xC2, 0x87, 0x21, 0x84, 0x39, 0x0E, 0x70, 0x9C, 0x21,
    0x84, 0x19, 0x0C, 0x30, 0x98, 0x21, 0x84, 0xED, 0x19, 0x98, 0xB7, 0x21,
    0x84, 0x31, 0x1B, 0xD8, 0x8C, 0x21, 0x84, 0x19, 0x9B, 0xD9, 0x98, 0x21,
    0x04, 0x0F, 0x9B, 0xD9, 0xF0, 0x20, 0xC4, 0x87, 0x09, 0x90, 0xE1, 0x23,
    0xC4, 0xC3, 0x0E, 0x70, 0xC3, 0x23, 0x04, 0x60, 0x07, 0xE0, 0x06, 0x20,
    0x04, 0x30, 0x00, 0x00, 0x0C, 0x20, 0x04, 0x18, 0xF8, 0x1F, 0x18, 0x20,
    0x04, 0x0C, 0xF8, 0x1F, 0x30, 0x20, 0x04, 0x06, 0x08, 0x10, 0x60, 0x20,
    0x04, 0xF6, 0xFF, 0xFF, 0x6F, 0x20, 0x04, 0xF2, 0xFF, 0xFF, 0x4F, 0x20,
    };

  static unsigned char elrs56[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0x03, 0x00, 0x00, 0x00, 0x00, 0xF8,
    0xFF, 0x0F, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0x3F, 0x00, 0x00, 0x00,
    0x00, 0x7F, 0x00, 0xFE, 0x00, 0x00, 0x00, 0x80, 0x1F, 0x00, 0xF8, 0x01,
    0x00, 0x00, 0xC0, 0x07, 0xFF, 0xE0, 0x03, 0x00, 0x00, 0xC0, 0xE3, 0xFF,
    0xC3, 0x03, 0x00, 0x00, 0xC0, 0xF1, 0xFF, 0x8F, 0x01, 0x00, 0x00, 0x00,
    0xF8, 0x81, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x3E, 0x00, 0x00,
    0x00, 0x00, 0x1C, 0x3E, 0x38, 0x00, 0x00, 0x00, 0x00, 0x88, 0xFF, 0x10,
    0x00, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0x03, 0x00, 0x00, 0x00, 0x00, 0xE0,
    0xE7, 0x03, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x81, 0x03, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x00,
    0x00, 0x18, 0x00, 0x3C, 0x00, 0x18, 0x00, 0x00, 0x3E, 0x00, 0x3C, 0x00,
    0x7C, 0x00, 0x00, 0x67, 0x00, 0x00, 0x00, 0xE6, 0x00, 0x80, 0x43, 0xFE,
    0xFF, 0x7F, 0xC2, 0x01, 0xC0, 0x61, 0xFE, 0xFF, 0x7F, 0x86, 0x03, 0xE0,
    0x60, 0x00, 0x00, 0x00, 0x06, 0x07, 0x70, 0x30, 0x00, 0x00, 0x00, 0x1C,
    0x0E, 0x30, 0x9C, 0x87, 0xFF, 0xE1, 0x19, 0x0C, 0x18, 0x8C, 0x8F, 0x00,
    0xF1, 0x31, 0x18, 0x18, 0xC6, 0x8C, 0x00, 0x31, 0x63, 0x18, 0x18, 0x83,
    0x8F, 0x00, 0xF1, 0xC1, 0x18, 0x08, 0x03, 0x87, 0x00, 0xE1, 0xC0, 0x10,
    0x0C, 0x03, 0x80, 0xFF, 0x01, 0xC0, 0x30, 0x0C, 0x03, 0x9F, 0xFF, 0xF9,
    0xC0, 0x30, 0x0C, 0xC3, 0x3F, 0x00, 0xFC, 0xC3, 0x30, 0x0C, 0xE3, 0x60,
    0x00, 0x06, 0xC7, 0x30, 0x0C, 0x73, 0xC0, 0x00, 0x03, 0xCE, 0x30, 0x0C,
    0xB3, 0xCF, 0x00, 0xF3, 0xCD, 0x30, 0x0C, 0xE3, 0x8D, 0x00, 0xB1, 0xC7,
    0x30, 0x0C, 0xE6, 0x98, 0x18, 0x19, 0x67, 0x30, 0x0C, 0x36, 0xD8, 0x18,
    0x1B, 0x6E, 0x30, 0x0C, 0x3C, 0xCC, 0x00, 0x33, 0x38, 0x30, 0x8C, 0x1F,
    0x6E, 0x00, 0x76, 0xF8, 0x31, 0x8C, 0x07, 0x77, 0x00, 0xEE, 0xE0, 0x31,
    0x0C, 0x80, 0x3B, 0x00, 0xDC, 0x01, 0x30, 0x0C, 0xC0, 0x01, 0x00, 0x80,
    0x03, 0x30, 0x0C, 0xE0, 0x00, 0x42, 0x01, 0x07, 0x30, 0x0C, 0x70, 0xC0,
    0xFF, 0x03, 0x0E, 0x30, 0x0C, 0x38, 0x40, 0x00, 0x02, 0x1C, 0x30, 0x0C,
    0x18, 0x40, 0x00, 0x02, 0x18, 0x30, 0x0C, 0xCC, 0xFF, 0xFF, 0xFF, 0x33,
    0x30, 0x0C, 0xCC, 0xFF, 0xFF, 0xFF, 0x33, 0x30, };
#endif

#endif

#if defined(USE_OLED_SPI_SMALL) || defined(TARGET_TX_GHOST)

  static unsigned char elrs32[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x0F, 0x00, 0x00, 0xFC, 0x3F, 0x00,
    0x00, 0x0E, 0x70, 0x00, 0x00, 0xE7, 0xE7, 0x00, 0x00, 0xF9, 0x9F, 0x00,
    0x00, 0x1C, 0x38, 0x00, 0x00, 0xCC, 0x33, 0x00, 0x00, 0xF0, 0x07, 0x00,
    0x00, 0x30, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00,
    0x00, 0x80, 0x01, 0x00, 0x00, 0x80, 0x01, 0x00, 0xE0, 0x80, 0x01, 0x07,
    0x30, 0xFD, 0xBF, 0x0C, 0x18, 0x01, 0x84, 0x19, 0xCC, 0x60, 0x05, 0x31,
    0x44, 0xE7, 0xE7, 0x22, 0x24, 0x27, 0xE4, 0x24, 0x22, 0x22, 0x44, 0x64,
    0x22, 0xEE, 0x77, 0x44, 0xA2, 0x11, 0x88, 0x44, 0xA2, 0x26, 0x64, 0x45,
    0x22, 0x29, 0x94, 0x44, 0xA2, 0xA8, 0x15, 0x45, 0x72, 0x14, 0x28, 0x4E,
    0x02, 0x1A, 0x58, 0x40, 0x02, 0x01, 0x80, 0x40, 0x82, 0xF0, 0x0F, 0x41,
    0x42, 0x10, 0x08, 0x42, 0x42, 0xFF, 0xFF, 0x42, };

#endif

#if defined(USE_OLED_SPI) || defined(USE_OLED_I2C)

  static unsigned char elrs64[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x3F, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x80, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xFF,
    0xFF, 0x07, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x7F, 0xFE, 0x0F, 0x00, 0x00,
    0x00, 0x00, 0xFC, 0x03, 0xC0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x00,
    0x00, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xF8, 0x0F, 0xFC, 0x00, 0x00,
    0x00, 0x00, 0x0F, 0xFE, 0x7F, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x87, 0xFF,
    0xFF, 0xF1, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0xFF, 0x03, 0x00, 0x00,
    0x00, 0x00, 0xE0, 0x07, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x01,
    0x80, 0x0F, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xF0, 0x07, 0x07, 0x00, 0x00,
    0x00, 0x00, 0x60, 0xF8, 0x1F, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE,
    0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x7F, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x1E, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06,
    0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0,
    0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x06, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x60, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0,
    0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x03, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xC0, 0x03, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x00, 0xC0,
    0x03, 0x00, 0x1F, 0x00, 0x00, 0xFC, 0x01, 0xE0, 0x07, 0x80, 0x3F, 0x00,
    0x00, 0x8E, 0x01, 0x00, 0x00, 0x80, 0x71, 0x00, 0x00, 0x87, 0xF3, 0xFF,
    0xFF, 0x8F, 0xE1, 0x00, 0x80, 0x83, 0xF1, 0xFF, 0xFF, 0x8F, 0xC1, 0x01,
    0xC0, 0x81, 0x01, 0x00, 0x00, 0x80, 0x81, 0x03, 0xE0, 0xE0, 0x00, 0x00,
    0x00, 0x00, 0x07, 0x07, 0x60, 0x60, 0x1C, 0xFC, 0x3F, 0x38, 0x06, 0x06,
    0x30, 0x30, 0x3E, 0xFC, 0x3F, 0x7C, 0x0C, 0x0C, 0x30, 0x18, 0x76, 0x0C,
    0x30, 0x6E, 0x18, 0x0C, 0x18, 0x0C, 0x66, 0x0C, 0x30, 0x66, 0x38, 0x18,
    0x18, 0x0C, 0x3E, 0x0C, 0x30, 0x7C, 0x30, 0x18, 0x18, 0x0E, 0x3C, 0x0C,
    0x30, 0x3C, 0x70, 0x18, 0x18, 0x06, 0x00, 0xFC, 0x3F, 0x00, 0x60, 0x18,
    0x18, 0x06, 0x78, 0xFC, 0x3F, 0x1E, 0x60, 0x18, 0x1C, 0x06, 0xFE, 0x01,
    0x80, 0x7F, 0x60, 0x38, 0x0C, 0x86, 0xC7, 0x03, 0xC0, 0xE3, 0x61, 0x30,
    0x0C, 0x86, 0x01, 0x07, 0xE0, 0x80, 0x61, 0x30, 0x0C, 0xC6, 0x18, 0x06,
    0x60, 0x18, 0x63, 0x30, 0x0C, 0xC6, 0x7E, 0x0E, 0x70, 0x7E, 0x63, 0x30,
    0x0C, 0xCE, 0x77, 0x0C, 0x30, 0xEE, 0x73, 0x30, 0x0C, 0x8C, 0xE3, 0x8C,
    0x31, 0xC7, 0x31, 0x30, 0x0C, 0xCC, 0xC1, 0x8C, 0x31, 0x83, 0x3B, 0x30,
    0x0C, 0xF8, 0xE0, 0x8E, 0x71, 0x07, 0x1F, 0x30, 0x0C, 0x78, 0x70, 0x06,
    0x60, 0x0E, 0x1E, 0x30, 0x0C, 0x3F, 0x38, 0x07, 0xE0, 0x1C, 0xFC, 0x30,
    0x0C, 0x0F, 0xDC, 0x03, 0xC0, 0x3B, 0xF0, 0x30, 0x0C, 0x00, 0xCE, 0x01,
    0x80, 0x73, 0x00, 0x30, 0x0C, 0x00, 0x07, 0x00, 0x00, 0xE0, 0x00, 0x30,
    0x0C, 0x80, 0x03, 0x00, 0x00, 0xC0, 0x01, 0x30, 0x0C, 0xC0, 0x01, 0xFE,
    0x7F, 0x80, 0x03, 0x30, 0x0C, 0xE0, 0x00, 0xFE, 0x7F, 0x00, 0x07, 0x30,
    0x0C, 0x60, 0x00, 0x06, 0x60, 0x00, 0x06, 0x30, 0x0C, 0x30, 0x00, 0x06,
    0x60, 0x00, 0x0E, 0x30, 0x0C, 0x30, 0xFE, 0xFF, 0xFF, 0x7F, 0x0C, 0x30,
    0x0C, 0x30, 0xFF, 0xFF, 0xFF, 0xFF, 0x0C, 0x30, };

#endif