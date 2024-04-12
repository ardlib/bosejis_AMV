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
    if (*out_max < (in_max * 2)) {
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

#endif /* _UTILS_H_ */
