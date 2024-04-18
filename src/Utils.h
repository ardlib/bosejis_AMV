/**
 * बोसजी की अंकितक - मात्रा - वस्तू लाइब्रेरी
 * ===============================
 * अंकितक - मात्रा - वस्तू आदिलेख एवं उसका संयोग।
 *
 * एक रचनात्मक भारतीय उत्पाद।
 *
 * Boseji's AMV Library
 * The AMV Protocol Implementation.
 *
 * Sources
 * -------
 * https://github.com/ardlib/bosejis_AMV
 *
 * License
 * --------
 * SPDX: GPL-3.0-or-later
 *
 *  bosejis_AMV - The AMV Protocol Implementation
 *  Copyright (C) 2012-2024 by Abhijit Bose (aka. Boseji)
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef _UTILS_H_
#define _UTILS_H_

#include <Arduino.h>

// Checksum helps to calculate the 16-bit checksum value needed in पुलिंदा
uint16_t Checksum(uint8_t *buf, size_t sz) {
  uint32_t ck = 0;
  for (size_t i = 0; i < sz; i++ ) {
    ck += buf[i];
  }
  // Intel Hex Checksum Calculation
  // https://www.kanda.com/blog/microcontrollers/intel-hex-files-explained/
  // https://www.fischl.de/hex_checksum_calculator/
  ck = (0x10000U - (ck & 0xFFFFU)) & 0xFFFFU;
   
  return ck;
}

// HexStream helps to convert a byte stream into hex encoded character
// buffer for display purpose.
bool HexStream(uint8_t *in, size_t in_max, char *out, size_t *out_max) {
    size_t i,j;
    byte b;
    if (*out_max < (in_max << 1)) {
        return false;
    }
    memset(out, 0, *out_max);
    for (i = 0, j = 0; i < in_max; i++) {
        b = (in[i] >> 4) & 0x0FU;
        out[j++] = b>9 ? (b - 10 + 'a') : (b + '0');
        b = in[i] & 0x0FU;
        out[j++] = b>9 ? (b - 10 + 'a') : (b + '0');
    }
    *out_max = j;
    return true;
}

// HexDecode helps to convert a hex encoded character buffer back into
// its byte stream form for processing.
bool HexDecode(char *in, size_t in_max, uint8_t *out, size_t *out_max) {
  size_t i,j;
  byte b;
  if (*out_max < (in_max >> 1)) {
    return false;
  }
  memset(out, 0, *out_max);
  for (i = 0, j = 0; i < in_max; i++ ) {
    b = 0;
    if(in[i] >= 'A' && in[i] <= 'F') {
      b = ((uint8_t)(in[i]-'A')) + 10U;
    } else if(in[i] >= 'a' && in[i] <= 'f') {
      b = ((uint8_t)(in[i]-'a')) + 10U;
    } else if (in[i] >= '0' && in[i] <= '9') {
      b = ((uint8_t)(in[i]-'0'));
    }
    i++; // Next Character
    b <<= 4; // Make the Lower nibble space
    if(in[i] >= 'A' && in[i] <= 'F') {
      b |= ((uint8_t)(in[i]-'A')) + 10U;
    } else if(in[i] >= 'a' && in[i] <= 'f') {
      b |= ((uint8_t)(in[i]-'a')) + 10U;
    } else if (in[i] >= '0' && in[i] <= '9') {
      b |= ((uint8_t)(in[i]-'0'));
    }
    out[j++] = b;
  }
  *out_max = j;
  return true;
}

const PROGMEM uint32_t _crc_table[16] = {
    0x00000000, 0x1db71064, 0x3b6e20c8, 0x26d930ac,
    0x76dc4190, 0x6b6b51f4, 0x4db26158, 0x5005713c,
    0xedb88320, 0xf00f9344, 0xd6d6a3e8, 0xcb61b38c,
    0x9b64c2b0, 0x86d3d2d4, 0xa00ae278, 0xbdbdf21c
};

// CalcCRC32_CCITT helps to calculate the 32-but CRC as per the
// CCITT32	with Poly:	0x04c11db7.
// Sources:
// https://excamera.com/sphinx/article-crc.html
// https://www.mrob.com/pub/comp/crc-all.html
// For Checking Online:
// https://crccalc.com/
uint32_t CalcCRC32_CCITT(uint8_t *s, size_t sz)
{
  uint32_t crc = ~0L;
  byte tbl_idx;
  size_t i;
  for (i = 0; i < sz; i++) {  
    tbl_idx = crc ^ (s[i] >> (0 * 4));
    crc = pgm_read_dword_near(_crc_table + (tbl_idx & 0x0f)) ^ (crc >> 4);
    tbl_idx = crc ^ (s[i] >> (1 * 4));
    crc = pgm_read_dword_near(_crc_table + (tbl_idx & 0x0f)) ^ (crc >> 4);
  }
  crc = ~crc;
  return crc;
}

#endif /* _UTILS_H_ */
