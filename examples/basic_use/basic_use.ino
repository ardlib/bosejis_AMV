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
#define BUF_SIZE 100

// Functions
void Test_Ankitak();
void Test_VastuBytes();
void Test_VastuFrom();

// Globals
static char str_buf[STR_BUF_SIZE];
PString str(str_buf, STR_BUF_SIZE);

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
  delay(2000);
  Test_VastuFrom();
  /*
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
  */
}

void Test_Ankitak() {
  byte a = 0; // To be used for Ankitak
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

#define ARRAY_PRINT(X, Y, Z, SZ)                                               \
  str.begin();                                                                 \
  str.print(F(X));                                                             \
  str.print(F("(0x"));                                                         \
  str.Hex(Y);                                                                  \
  str.print(F(") = {"));                                                       \
  str.HexArray(Z, SZ);                                                         \
  str.print(F(" }"));                                                          \
  Serial.println(str);

#define ARRAY_PRINT2(X, Y, Z, SZ)                                              \
  str.begin();                                                                 \
  str.print(F(X));                                                             \
  str.print(F("(0x"));                                                         \
  str.Hex(Y);                                                                  \
  str.print(F(") = "));                                                        \
  str.print(Y);                                                                \
  str.print(F(" = {"));                                                        \
  str.HexArray(Z, SZ);                                                         \
  str.print(F(" }"));                                                          \
  Serial.println(str);

#define ARRAY_PRINT3(X, Y, Z, SZ, K)                                           \
  str.begin();                                                                 \
  str.print(F(X));                                                             \
  str.print(F("("));                                                           \
  str.print(Y, K);                                                             \
  str.print(F(") = {"));                                                       \
  str.HexArray(Z, SZ);                                                         \
  str.print(F(" }"));                                                          \
  Serial.println(str);

void Test_VastuBytes() {
  uint8_t buffer[BUF_SIZE];
  size_t sz, sz_alt;
  Buffer b;
  const char data[10] = "Hari Aum!";
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
  if (Vastu.Bytes((uint16_t)0x1234, buffer, &sz)) {
    ARRAY_PRINT(" uint16_t", (uint16_t)0x1234, buffer, sz);
  }
  Serial.println();

  sz = BUF_SIZE;
  if (Vastu.Bytes((uint32_t)0x12345678, buffer, &sz)) {
    ARRAY_PRINT(" uint32_t", (uint32_t)0x12345678, buffer, sz);
  }
  Serial.println();

  sz = BUF_SIZE;
  if (Vastu.Bytes((uint64_t)0x1234567890123456, buffer, &sz)) {
    ARRAY_PRINT(" uint64_t", (uint64_t)0x1234567890123456, buffer, sz);
  }
  Serial.println();

  sz = BUF_SIZE;
  if (Vastu.Bytes((float)3.14159, buffer, &sz)) {
    ARRAY_PRINT3(" float", float)3.14159, buffer, sz, 7);
  }
  Serial.println();

  sz = BUF_SIZE;
  if (Vastu.Bytes((double)3.14159265358979, buffer, &sz)) {
    ARRAY_PRINT3(" double", (double)3.14159265358979, buffer, sz, 14);
  }
  Serial.println();

  sz = BUF_SIZE;
  if (Vastu.Bytes((uint8_t)0x12, buffer, &sz)) {
    ARRAY_PRINT(" uint8_t", (uint8_t)0x12, buffer, sz);
  }
  Serial.println();

  sz = BUF_SIZE;
  if (Vastu.Bytes(' ', buffer, &sz)) {
    ARRAY_PRINT(" char", (uint8_t)' ', buffer, sz);
  }
  Serial.println();

  sz = BUF_SIZE;
  if (Vastu.Bytes((int16_t)-1234, buffer, &sz)) {
    ARRAY_PRINT2(" int16_t", (int16_t)-1234, buffer, sz);
  }
  Serial.println();

  sz = BUF_SIZE;
  if (Vastu.Bytes((int32_t)-12345678, buffer, &sz)) {
    ARRAY_PRINT2(" int32_t", (int32_t)-12345678, buffer, sz);
  }
  Serial.println();

  sz = BUF_SIZE;
  if (Vastu.Bytes(true, buffer, &sz)) {
    ARRAY_PRINT(" bool", (uint8_t) true, buffer, sz);
  }
  Serial.println();

  sz = BUF_SIZE;
  if (Vastu.Bytes((int64_t)-1234567890123456, buffer, &sz)) {
    ARRAY_PRINT(" int64_t", (int64_t)-1234567890123456, buffer, sz);
  }
  Serial.println();

  sz = BUF_SIZE;
  ID id;
  id.val = 0x12345678;
  if (Vastu.Bytes(id, buffer, &sz)) {
    ARRAY_PRINT(" ID", id.val, buffer, sz);
  }
  Serial.println();
}

#define ARRAY_WITH_SIZE(PRINT, BUF, SZ)                                        \
  str.print(F(PRINT));                                                         \
  str.print(F("("));                                                           \
  str.print(SZ);                                                               \
  str.print(F(" bytes) :\n {"));                                               \
  str.HexArray(BUF, SZ);                                                       \
  str.println(F(" }"))

#define ARRAY_WITH_SIZE_PRINT(PRINT, DATA, SZ, VAL)                            \
  str.begin();                                                                 \
  str.print(F(PRINT));                                                         \
  str.print(F(" {"));                                                          \
  str.HexArray(DATA, SZ);                                                      \
  str.print(F(" } = 0x"));                                                     \
  str.Hex(VAL);                                                                \
  str.print(F(" = "));                                                         \
  str.print(VAL);                                                              \
  Serial.println(str);

#define ARRAY_WITH_SIZE_DECIMAL(PRINT, DATA, SZ, VAL, DECIMAL)                 \
  str.begin();                                                                 \
  str.print(F(PRINT));                                                         \
  str.print(F(" {"));                                                          \
  str.HexArray(DATA, SZ);                                                      \
  str.print(F(" } = "));                                                       \
  str.print(VAL, DECIMAL);                                                     \
  Serial.println(str);

#define ARRAY_WITH_SIZE_LARGE(PRINT, DATA, SZ, VAL)                            \
  str.begin();                                                                 \
  str.print(F(PRINT));                                                         \
  str.print(F(" {"));                                                          \
  str.HexArray(DATA, SZ);                                                      \
  str.print(F(" } = 0x"));                                                     \
  str.Hex(VAL);                                                                \
  Serial.println(str);

void Test_VastuFrom() {
  uint8_t buffer[BUF_SIZE];
  size_t sz;
  Buffer b;
  SEPARATOR("Vastu-From usage");
  do {
    sz = 11;
    uint16_t buf_sz;
    uint8_t data[] = {0x09, 0x00, /* Size */
                      0x48, 0x61, 0x72, 0x69, 0x20, 0x41, 0x75, 0x6d, 0x21};
    char buf[20];
    if (!Vastu.ToBuffer(buffer, BUF_SIZE, &b))
      return;
    if (!Vastu.From(data, sz, &b))
      return;
    str.begin();
    ARRAY_WITH_SIZE(" Input Data ", data, sz);
    ARRAY_WITH_SIZE(" Buffer ", buffer, b.size);
    Serial.println(str);
    b.isNullTerminated = 1;
    buf_sz = 20;
    if (!Vastu.FromBuffer(&b, buf, &buf_sz))
      return;
    Serial.print(F(" String Size (Adjusted): "));
    Serial.println(buf_sz);
    Serial.print(F(" String Value          : "));
    Serial.println(buf);
  } while (0);
  Serial.println();

  /*

 bool(0x1) = { 0x01 }

 int64_t(-1234567890123456) = { 0x40, 0x45, 0x75, 0xc3, 0x2a, 0x9d, 0xfb, 0xff }

 ID(0x12345678) = { 0x78, 0x56, 0x34, 0x12 }

  */
  do {
    uint8_t data[2] = {0x34, 0x12};
    uint16_t val;
    if (!Vastu.ToBuffer(buffer, BUF_SIZE, &b))
      return;
    if (!Vastu.From(data, 2, &val))
      return;
    ARRAY_WITH_SIZE_PRINT(" uint16_t", data, 2, val);
  } while (0);
  Serial.println();

  do {
    uint8_t data[4] = {0x78, 0x56, 0x34, 0x12};
    uint32_t val;
    if (!Vastu.ToBuffer(buffer, BUF_SIZE, &b))
      return;
    if (!Vastu.From(data, 4, &val))
      return;
    ARRAY_WITH_SIZE_PRINT(" uint32_t", data, 4, val);
  } while (0);
  Serial.println();

  do {
    uint8_t data[8] = {0x56, 0x34, 0x12, 0x90, 0x78, 0x56, 0x34, 0x12};
    uint64_t val;
    if (!Vastu.ToBuffer(buffer, BUF_SIZE, &b))
      return;
    if (!Vastu.From(data, 8, &val))
      return;
    ARRAY_WITH_SIZE_LARGE(" uint64_t", data, 8, val);
  } while (0);
  Serial.println();

  do {
    uint8_t data[4] = {0xd0, 0x0f, 0x49, 0x40};
    float val;
    if (!Vastu.ToBuffer(buffer, BUF_SIZE, &b))
      return;
    if (!Vastu.From(data, 4, &val))
      return;
    ARRAY_WITH_SIZE_DECIMAL(" float", data, 4, val, 7);
  } while (0);
  Serial.println();

  do {
    uint8_t data[8] = {0x11, 0x2d, 0x44, 0x54, 0xfb, 0x21, 0x09, 0x40};
    double val;
    if (!Vastu.ToBuffer(buffer, BUF_SIZE, &b))
      return;
    if (!Vastu.From(data, 8, &val))
      return;
    ARRAY_WITH_SIZE_DECIMAL(" double", data, 8, (double)val, 14);
  } while (0);
  Serial.println();

  do {
    uint8_t data[1] = {0x12};
    uint8_t val;
    if (!Vastu.ToBuffer(buffer, BUF_SIZE, &b))
      return;
    if (!Vastu.From(data, 1, &val))
      return;
    ARRAY_WITH_SIZE_PRINT(" uint8_t", data, 1, val);
  } while (0);
  Serial.println();

  do {
    uint8_t data[1] = {0x20};
    char val;
    if (!Vastu.ToBuffer(buffer, BUF_SIZE, &b))
      return;
    if (!Vastu.From(data, 1, &val))
      return;
    ARRAY_WITH_SIZE_PRINT(" char", data, 1, val);
  } while (0);
  Serial.println();

  do {
    uint8_t data[2] = {0x2e, 0xfb};
    int16_t val;
    if (!Vastu.ToBuffer(buffer, BUF_SIZE, &b))
      return;
    if (!Vastu.From(data, 2, &val))
      return;
    ARRAY_WITH_SIZE_PRINT(" int16_t", data, 2, val);
  } while (0);
  Serial.println();

  do {
    uint8_t data[4] = {0xb2, 0x9e, 0x43, 0xff};
    int32_t val;
    if (!Vastu.ToBuffer(buffer, BUF_SIZE, &b))
      return;
    if (!Vastu.From(data, 4, &val))
      return;
    ARRAY_WITH_SIZE_PRINT(" int32_t", data, 4, val);
  } while (0);
  Serial.println();

  do {
    uint8_t data[1] = {0x01};
    bool val;
    if (!Vastu.ToBuffer(buffer, BUF_SIZE, &b))
      return;
    if (!Vastu.From(data, 1, &val))
      return;
    ARRAY_WITH_SIZE_PRINT(" bool", data, 1, val);
  } while (0);
  Serial.println();

  do {
    uint8_t data[8] = {0x40, 0x45, 0x75, 0xc3, 0x2a, 0x9d, 0xfb, 0xff};
    int64_t val;
    if (!Vastu.ToBuffer(buffer, BUF_SIZE, &b))
      return;
    if (!Vastu.From(data, 8, &val))
      return;
    ARRAY_WITH_SIZE_LARGE(" int64_t", data, 8, val);
  } while (0);
  Serial.println();

  do {
    uint8_t data[4] = {0x78, 0x56, 0x34, 0x12};
    ID id;
    if (!Vastu.ToBuffer(buffer, BUF_SIZE, &b))
      return;
    if (!Vastu.From(data, 4, &id))
      return;
    ARRAY_WITH_SIZE_PRINT(" ID", data, 4, id.val);
  } while (0);
  Serial.println();
}