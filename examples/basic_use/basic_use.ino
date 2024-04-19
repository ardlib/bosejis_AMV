/**
 * Basic Usage Example.
 *
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

#include <bosejis_AMV.h>

// Size Constants
#define BUF_MAX 8
#define CHARR_MAX 20
#define VALUE2_MAX 6

//Global Variables
byte a; // To be used for Ankitak
uint32_t value1 = 0x1234ABCD;
size_t sz,sz2;
uint8_t buf[BUF_MAX];
ID name;
uint8_t value2[VALUE2_MAX] = {
   0x03, 0x04, 0xAA, 0xDB, 0x3C, 0x71
};
uint16_t checksum;
char strm[CHARR_MAX];
CRC32 crc;

void setup() {
   Serial.begin(115200);
   while(!Serial){}
}

void loop() {
   delay(2000);
   Serial.println("---------------------------");
   Serial.println("Ankitak usage");
   Serial.print("Response      : 0x");
   a = Ankitak.Response(a);
   Serial.println(a, HEX);
   Serial.print("With Checksum : 0x");
   a = Ankitak.WithChecksum(a);
   Serial.println(a, HEX);
   Serial.print("Is Response   : ");
   Serial.println(Ankitak.IsResponse(a));
   Serial.print("Has Checksum  : ");
   Serial.println(Ankitak.HasChecksum(a));
   sz = BUF_MAX;
   if (Vastu.Bytes(value1, buf, &sz)) {
      Serial.println("Vastu - Bytes usage1");
      Serial.print("Original Value: 0x");
      Serial.println(value1, HEX);
      Serial.print("Size          : ");
      Serial.println(sz);
      Serial.print("Converted     : ");
      for(int i = 0; i < sz; i++) {
         Serial.print(buf[i], HEX);
         Serial.print(' ');
      }
      Serial.println();
   }
   name.val = 0x6789EF12;
   sz = BUF_MAX;
   if (Vastu.Bytes(name, buf, &sz)) {
      Serial.println("Vastu - Bytes usage2");
      Serial.print("Original Value: 0x");
      Serial.println(name.val, HEX);
      Serial.print("Size          : ");
      Serial.println(sz);
      Serial.print("Converted     : ");
      for(int i = 0; i < sz; i++) {
         Serial.print(buf[i], HEX);
         Serial.print(' ');
      }
      Serial.println();
   }
   Serial.println();
   checksum = Checksum(value2, VALUE2_MAX);
   Serial.println("Checksum and HexStream usage");
   Serial.print("Input Data     : ");
   sz = CHARR_MAX;
   HexStream(value2, VALUE2_MAX, strm, &sz);
   Serial.println(strm);
   Serial.print("Checksum Value : 0x");
   Serial.println(checksum, HEX);
   Serial.println();
   Serial.println("HexDecode and CalcCRC32_CCITT usage");
   sz2 = BUF_MAX;
   HexDecode(strm, sz, buf, &sz2);
   Serial.print("HexDecode      : ");
   for(int i = 0; i < sz2; i++) {
      Serial.print(buf[i], HEX);
      Serial.print(' ');
   }
   Serial.println();
   crc.val = CalcCRC32_CCITT(value2, VALUE2_MAX);
   Serial.print("CalcCRC32_CCITT: ");
   Serial.println(crc.val, HEX);
   Serial.println();
}