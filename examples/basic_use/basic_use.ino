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
#include <bosejis_PString.h>

// Defines
#define SEPARATOR(X)                                                           \
  Serial.println(F("---------------------------"));                            \
  Serial.println(X);                                                           \
  Serial.println()
#define STR_BUF_SIZE 200

// Functions
void Test_Ankitak();
void Test_VastuBytes();

// Globals
static char str_buf[STR_BUF_SIZE];
PString str(str_buf, STR_BUF_SIZE);

/*
// Size Constants
#define BUF_MAX 8
#define CHARR_MAX 20
#define VALUE2_MAX 6

// Global Variables

uint32_t value1 = 0x1234ABCD, rvalue1;
size_t sz, sz2;
uint8_t buf[BUF_MAX];
ID name, rname;
uint8_t value2[VALUE2_MAX] = {0x03, 0x04, 0xAA, 0xDB, 0x3C, 0x71};
uint16_t checksum;
char strm[CHARR_MAX];
CRC32 crc;
*/

void setup() {
  delay(1000); // Startup Delay
  Serial.begin(115200);
  while (!Serial) {
  }
}

void loop() {
  delay(2000);
  Test_Ankitak();
  delay(2000);
  Test_VastuBytes();
  /*
  sz = BUF_MAX;
  if (Vastu.Bytes(value1, buf, &sz)) {
    Serial.println("Vastu - Bytes usage1");
    Serial.print("Original Value: 0x");
    Serial.println(value1, HEX);
    Serial.print("Size          : ");
    Serial.println(sz);
    Serial.print("Converted     : ");
    for (int i = 0; i < sz; i++) {
      Serial.print(buf[i], HEX);
      Serial.print(' ');
    }
    Serial.println();
  }
  if (Vastu.From(buf, sz, &rvalue1)) {
    Serial.println("Vastu - From usage1");
    Serial.print("Restored Value: 0x");
    Serial.println(rvalue1, HEX);
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
    for (int i = 0; i < sz; i++) {
      Serial.print(buf[i], HEX);
      Serial.print(' ');
    }
    Serial.println();
  }
  if (Vastu.From(buf, sz, &rname)) {
    Serial.println("Vastu - From usage2");
    Serial.print("Restored Value: 0x");
    Serial.println(rname.val, HEX);
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
  for (int i = 0; i < sz2; i++) {
    Serial.print(buf[i], HEX);
    Serial.print(' ');
  }
  Serial.println();
  crc.val = CalcCRC32_CCITT(value2, VALUE2_MAX);
  Serial.print("CalcCRC32_CCITT: ");
  Serial.println(crc.val, HEX);
  Serial.println();
  Serial.println("Buffer and ToBuffer usage");

  Buffer b;
  if (Vastu.ToBuffer(value2, VALUE2_MAX, &b)) {
    sz = BUF_MAX;
    if (Vastu.Bytes(b, buf, &sz)) {
      Serial.print("BufferValue: ");
      sz2 = CHARR_MAX;
      HexStream(buf, sz, strm, &sz2);
      Serial.println(strm);
    }
  }
  */
}

void Test_Ankitak() {
  byte a; // To be used for Ankitak
  SEPARATOR("Ankitak usage");
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
  Serial.println();
}

void Test_VastuBytes() {
#define BUF_SIZE 100
  uint8_t buffer[BUF_SIZE];
  size_t sz, sz_alt;
  Buffer b;
  char *data = "Hari Aum!";
  SEPARATOR("Vastu-Bytes usage");

  sz = BUF_SIZE;
  sz_alt = strlen(data);
  str.begin();
  if (Vastu.ToBuffer(data, sz_alt, &b)) {
    str.print(F("New Buffer with isNullTerminated = "));
    str.print(b.isNullTerminated);
    Serial.println(str);
    Serial.print(F("Original String       :\n "));
    Serial.println(data);
    str.begin();
    str.print(F("In Hex                   :\n {"));
    str.HexArray(data, sz_alt);
    str.print(F(" }"));
    Serial.println(str);
    Serial.print(F("String Size (in bytes): "));
    Serial.println(sz_alt);
    Serial.println();
    str.begin();
    sz = BUF_SIZE;
    if (Vastu.Bytes(b, buffer, &sz)) {
      str.print(F("Converting the Buffer "));
      str.print(F("first 2bytes are size) :\n {"));
      str.HexArray(buffer, sz);
      str.print(F(" }"));
      Serial.println(str);
    }
  }
  Serial.println();

  sz = BUF_SIZE;
  str.begin();
  if (Vastu.Bytes((uint8_t)34, buffer, &sz)) {
    str.print(F("Converting uint8_t value "));
    str.print(34);
    str.print(F(" Into Vastu-Bytes : {"));
    str.HexArray(buffer, sz);
    str.print(F(" }"));
    Serial.println(str);
  }
  Serial.println();
}