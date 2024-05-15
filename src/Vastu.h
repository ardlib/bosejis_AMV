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
#ifndef _VASTU_H_
#define _VASTU_H_

// वस्तु Specification in अंकितक
//
// | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
// |           |-------------------| = वस्तु(5)

#include <Arduino.h>

//-------------------------------------------------------------
// Primary

// Bytes वस्तु Collection of byte values of Variable मात्रा With
// 2 Byte मात्रा field (64K Bytes) supporting UTF-8
// 0b0000_0001
#define Vastu_Bytes ((byte)(0x01))

// U16 वस्तु unsigned 16-bit Integer 2 Byte Only
// 0b0000_0010
#define Vastu_U16 ((byte)(0x02))

// U32 वस्तु unsigned 32-bit Integer 4 Byte Only
// 0b0000_0011
#define Vastu_U32 ((byte)(0x03))

// U64 वस्तु unsigned 64-bit Integer 8 Byte Only
// 0b0000_0100
#define Vastu_U64 ((byte)(0x04))

// F32 वस्तु Floating Point 32-bit of size 4 Byte Only
// 0b0000_0101
#define Vastu_F32 ((byte)(0x05))

// F64 वस्तु Floating Point 64-bit of size 8 Byte Only
// 0b0000_0110
#define Vastu_F64 ((byte)(0x06))

// U8 वस्तु like Bool only 1 Byte Unsigned
// 0b0000_0111
#define Vastu_U8 ((byte)(0x07))

// I8 वस्तु Single int8 type
// 0b0000_1000
#define Vastu_I8 ((byte)(0x08))

// I16 वस्तु signed 16-bit Integer 2 Byte Only
// 0b0000_1001
#define Vastu_I16 ((byte)(0x09))

// I32 वस्तु signed 32-bit Integer 4 Byte Only
// 0b0000_1010
#define Vastu_I32 ((byte)(0x0A))

// Bool वस्तु Single byte Boolean
// 0b0000_1011
#define Vastu_Bool ((byte)(0x0B))

// String वस्तु NULL terminated collection of Characters of Variable मात्रा With
// 2 Byte मात्रा field (64K Bytes) supporting UTF-8
// 0b0000_1100
#define Vastu_String ((byte)(0x0D))

// I64 वस्तु signed 64-bit Integer 8 Byte Only
// 0b0000_1101
#define Vastu_I64 ((byte)(0x0E))

// 0b0000_1110
// 0b0000_1111

// 0b0001_0000
// 0b0001_0001
// 0b0001_0010
// 0b0001_0011

// ID वस्तु Identifier or Small Address of 4 Byte Only
// 0b0001_0100
#define Vastu_ID ((byte)(0x14))

// Proto वस्तु Protocol Identifier / Version of 4 Byte Only
// 0b0001_0101
#define Vastu_Proto ((byte)(0x15))

// CMD वस्तु Command Field of 4 Byte Only
// 0b0001_0110
#define Vastu_CMD ((byte)(0x16))

// ADDR वस्तु Full IEEE IPv6 64-Bit Address of 8 Byte Only
// 0b0001_0111
#define Vastu_ADDR ((byte)(0x17))

// CRC32 वस्तु for CRC32 CCITT Poly of 4 Byte Only
// 0b0001_1000
#define Vastu_CRC32 ((byte)(0x18))

// 0b0001_1010

// Sampurna वस्तु for total transaction size in Bytes unit with
// size of 8 Byte Only. This includes the whole block of data
// sent as one Transaction. It may be split into Chunks as needed.
// 0b0001_1010
#define Vastu_Sampurna ((byte)(0x1A))

//-------------------------------------------------------------------
// Higher Order

// Array वस्तु that includes a sequence of वस्तु taken together
// With 2 Byte Size field (64K वस्तु Units)
// 0b0001_1011
#define Vastu_Array ((byte)(0x1B))

// Tuples वस्तु that is a MAP like sequence containing Key:Value Pairs
// With 2 Byte Size field (64K वस्तु Pairs)
// 0b0001_1100
#define Vastu_Tuples ((byte)(0x1C))

// ChunkTotal वस्तु that defines the number of Chunks to be sent as parts
// of a complete संदेश With 2 Byte Size field (64K Chunks)
// 0b0001_1101
#define Vastu_ChunkTotal ((byte)(0x1D))

// ChunkIndex वस्तु that defines the Index of the Chunk or part of संदेश
// being sent With 2 Byte Index identifier
// 0b0001_1110
#define Vastu_ChunkIndex ((byte)(0x1E))

//---------------------------------------------------------------------
// Filter for वस्तु in the अंकितक
// 0b0001_1111
#define Vastu_Mask ((byte)(0x1F))

// Errors in वस्तु type
#define Vastu_Error ((int8_t)(-1))

// HalfWORD or 8-bit is Special Identifier for मात्रा in 1 Byte
#define HalfWORD 1
// WORD or 16-bit is Special Identifier for मात्रा in 2 Byte
#define WORD 2
// DWORD or 32-bit is Special Identifier for मात्रा in 4 Byte
#define DWORD 4
// QWORD or 64-bit is Special Identifier for मात्रा in 8 Byte
#define QWORD 8

// Buffer Compact type that describes both char[] and byte[] alike
typedef struct __attribute__((aligned(4))) Buffer_t {
  uint8_t *bytes;           // Buffer
  uint16_t size;            // Current Size of data in buffer
  uint8_t isNullTerminated; // If Its a Zero terminated string
  size_t capacity;          // Full capacity of the Buffer
  byte Vastu() {
    if (isNullTerminated != 0) {
      return Vastu_String;
    }
    return Vastu_Bytes;
  }
} Buffer;

// ID is an 32-bit Identifier or Small Address type
typedef struct __attribute__((aligned(4))) ID_t {
  uint32_t val;
} ID;

// Proto is an 32-bit Protocol Identifier / Version type
typedef struct __attribute__((aligned(4))) Proto_t {
  uint32_t val;
} Proto;

// CMD is 32-bit Command type
typedef struct __attribute__((aligned(4))) CMD_t {
  uint32_t val;
} CMD;

// ADDR is the Full IEEE IPv6 64-Bit Address type
typedef struct __attribute__((aligned(4))) ADDR_t {
  uint64_t val;
} ADDR;

// CRC32 for sending CRC32 CCITT Poly type data
typedef struct __attribute__((aligned(4))) CRC32_t {
  uint32_t val;
} CRC32;

// Sampurna for sending total transaction size in Bytes units.
// This includes the whole block of data sent as one Transaction.
// It may be split into Chunks as needed.
typedef struct __attribute__((aligned(4))) Sampurna_t {
  uint64_t val;
} Sampurna;

// Array is the size of a collection of Pulinda taken together
typedef struct __attribute__((aligned(4))) Array_t {
  uint16_t val;
} Array;

// Tuples is the size of a MAP like sequence containing
// Key:Value Pairs of Pulinda
typedef struct __attribute__((aligned(4))) Tuples_t {
  uint16_t val;
} Tuples;

// ChunkTotal is the total numbers of chunks in the sandesh
typedef struct __attribute__((aligned(4))) ChunkTotal_t {
  uint16_t val;
} ChunkTotal;

// ChunkIndex is the identifier for the current chunk
typedef struct __attribute__((aligned(4))) ChunkIndex_t {
  uint16_t val;
} ChunkIndex;

// Vastu_t is the C++ representation of वस्तु
class Vastu_t {
public:
  // Matra returns the length of the first data parameter in पुलिंदा for
  // identification of वस्तु type.
  // In case there are error it returns the special Error value.
  // This value is not including the अंकितक and actual size of वस्तु.
  // In order to determine if the वस्तु type includes a length or not,
  // the `IsVariable` functions needs to be used.
  byte Matra(byte v) {
    switch (v & Vastu_Mask) {
    case Vastu_Bytes:
      return WORD;
    case Vastu_U16:
      return WORD;
    case Vastu_U32:
      return DWORD;
    case Vastu_U64:
      return QWORD;
    case Vastu_F32:
      return DWORD;
    case Vastu_F64:
      return QWORD;
    case Vastu_U8:
      return HalfWORD;
    case Vastu_I8:
      return HalfWORD;
    case Vastu_I16:
      return WORD;
    case Vastu_I32:
      return DWORD;
    case Vastu_Bool:
      return HalfWORD;
    case Vastu_String:
      return WORD;
    case Vastu_I64:
      return QWORD;
    case Vastu_ID:
      return DWORD;
    case Vastu_Proto:
      return DWORD;
    case Vastu_CMD:
      return DWORD;
    case Vastu_ADDR:
      return QWORD;
    case Vastu_CRC32:
      return DWORD;
    case Vastu_Sampurna:
      return QWORD;
    case Vastu_Array:
      return WORD;
    case Vastu_Tuples:
      return WORD;
    case Vastu_ChunkTotal:
      return WORD;
    case Vastu_ChunkIndex:
      return WORD;
    default:
      return Vastu_Error;
    }
  }

  // IsVariable returns if the वस्तु is of Variable Size or not.
  // It also infers that if the size is included in the पुलिंदा or not.
  bool IsVariable(byte v) {
    switch (v) {
    case Vastu_Bytes:
    case Vastu_String:
      return true;
    default:
      return false;
    }
  }

  // IsHighOrder returns if the वस्तु type is of Higher order collection
  // or not.
  bool IsHigherOrder(byte v) {
    switch (v) {
    case Vastu_Array:
    case Vastu_Tuples:
    case Vastu_ChunkTotal:
    case Vastu_ChunkIndex:
      return true;
    default:
      return false;
    }
  }

  // Parichay helps to Determine the Vastu Type

  byte Parichay(byte *b) {
    (void)b;
    return Vastu_Bytes;
  }
  byte Parichay(const byte *b) {
    (void)b;
    return Vastu_Bytes;
  }
  byte Parichay(uint16_t b) {
    (void)b;
    return Vastu_U16;
  }
  byte Parichay(uint32_t b) {
    (void)b;
    return Vastu_U32;
  }
  byte Parichay(uint64_t b) {
    (void)b;
    return Vastu_U64;
  }
  byte Parichay(float b) {
    (void)b;
    return Vastu_F32;
  }
  byte Parichay(double b) {
    (void)b;
    return Vastu_F64;
  }
  byte Parichay(byte b) {
    (void)b;
    return Vastu_U8;
  }
  byte Parichay(char b) {
    (void)b;
    return Vastu_I8;
  }
  byte Parichay(int8_t b) {
    (void)b;
    return Vastu_I8;
  }
  byte Parichay(int16_t b) {
    (void)b;
    return Vastu_I16;
  }
  byte Parichay(int32_t b) {
    (void)b;
    return Vastu_I32;
  }
  byte Parichay(bool b) {
    (void)b;
    return Vastu_Bool;
  }
  byte Parichay(char *b) {
    (void)b;
    return Vastu_String;
  }
  byte Parichay(const char *b) {
    (void)b;
    return Vastu_String;
  }
  byte Parichay(int64_t b) {
    (void)b;
    return Vastu_I64;
  }
  byte Parichay(ID b) {
    (void)b;
    return Vastu_ID;
  }
  byte Parichay(Proto b) {
    (void)b;
    return Vastu_Proto;
  }
  byte Parichay(CMD b) {
    (void)b;
    return Vastu_CMD;
  }
  byte Parichay(ADDR b) {
    (void)b;
    return Vastu_ADDR;
  }
  byte Parichay(CRC32 b) {
    (void)b;
    return Vastu_CRC32;
  }
  byte Parichay(Sampurna b) {
    (void)b;
    return Vastu_Sampurna;
  }
  byte Parichay(Array b) {
    (void)b;
    return Vastu_Array;
  }
  byte Parichay(Tuples b) {
    (void)b;
    return Vastu_Tuples;
  }
  byte Parichay(ChunkTotal b) {
    (void)b;
    return Vastu_ChunkTotal;
  }
  byte Parichay(ChunkIndex b) {
    (void)b;
    return Vastu_ChunkIndex;
  }

  // ToBuffer helps to convert Streams char[] and byte[] into Buffer type

  bool ToBuffer(uint8_t *buf, uint16_t size, Buffer *b) {
    if (b == NULL || buf == NULL || size == 0)
      return false;
    b->bytes = buf;
    b->size = size;
    b->capacity = size;
    b->isNullTerminated = 0;
    return true;
  }

  bool ToBuffer(const byte *buf, uint16_t size, Buffer *b) {
    return ToBuffer((uint8_t *)buf, size, b);
  }

  bool ToBuffer(char *buf, uint16_t size, Buffer *b) {
    b->bytes = (uint8_t *)buf;
    b->size = size;
    b->capacity = size;
    b->isNullTerminated = 1;
    return true;
  }

  bool ToBuffer(const char *buf, uint16_t size, Buffer *b) {
    return ToBuffer((char *)buf, size, b);
  }

  // Bytes Helps to convert Vastu into its uint8_t[] representation.
  // The `sz` here serves to indicate size initially and return the
  // matra.

  bool Bytes(Buffer val, uint8_t *b, size_t *sz) {
    size_t val_sz = sizeof(val.size);
    if (b == NULL || sz == NULL)
      return false;
    if (*sz < (val_sz + val.size)) {
      return false;
    }
    *sz = val.size + val_sz;
    // Copy Data
    memcpy(b, &val.size, val_sz);
    memcpy(&b[val_sz], val.bytes, val.size);
    return true;
  }

  bool Bytes(uint16_t val, uint8_t *b, size_t *sz) {
    if (b == NULL || sz == NULL)
      return false;
    if (*sz < sizeof(val)) {
      return false;
    }
    *sz = sizeof(val); // Get the Matra
    // Copy Data
    memcpy(b, &val, *sz);
    return true;
  }

  bool Bytes(uint32_t val, uint8_t *b, size_t *sz) {
    if (b == NULL || sz == NULL)
      return false;
    if (*sz < sizeof(val)) {
      return false;
    }
    *sz = sizeof(val); // Get the Matra
    // Copy Data
    memcpy(b, &val, *sz);
    return true;
  }

  bool Bytes(uint64_t val, uint8_t *b, size_t *sz) {
    if (b == NULL || sz == NULL)
      return false;
    if (*sz < sizeof(val)) {
      return false;
    }
    *sz = sizeof(val); // Get the Matra
    // Copy Data
    memcpy(b, &val, *sz);
    return true;
  }

  bool Bytes(float val, uint8_t *b, size_t *sz) {
    if (b == NULL || sz == NULL)
      return false;
    if (*sz < sizeof(val)) {
      return false;
    }
    *sz = sizeof(val); // Get the Matra
    // Copy Data
    memcpy(b, &val, *sz);
    return true;
  }

  bool Bytes(double val, uint8_t *b, size_t *sz) {
    if (b == NULL || sz == NULL)
      return false;
    if (*sz < sizeof(val)) {
      return false;
    }
    *sz = sizeof(val); // Get the Matra
    // Copy Data
    memcpy(b, &val, *sz);
    return true;
  }

  bool Bytes(uint8_t val, uint8_t *b, size_t *sz) {
    if (b == NULL || sz == NULL)
      return false;
    if (*sz < sizeof(val)) {
      return false;
    }
    *sz = sizeof(val); // Get the Matra
    // Copy Data
    memcpy(b, &val, *sz);
    return true;
  }

  bool Bytes(int8_t val, uint8_t *b, size_t *sz) {
    if (b == NULL || sz == NULL)
      return false;
    if (*sz < sizeof(val)) {
      return false;
    }
    *sz = sizeof(val); // Get the Matra
    // Copy Data
    memcpy(b, &val, *sz);
    return true;
  }

  bool Bytes(char val, uint8_t *b, size_t *sz) {
    return Bytes(static_cast<int8_t>(val), b, sz);
  }

  bool Bytes(int16_t val, uint8_t *b, size_t *sz) {
    if (b == NULL || sz == NULL)
      return false;
    if (*sz < sizeof(val)) {
      return false;
    }
    *sz = sizeof(val); // Get the Matra
    // Copy Data
    memcpy(b, &val, *sz);
    return true;
  }

  bool Bytes(int32_t val, uint8_t *b, size_t *sz) {
    if (b == NULL || sz == NULL)
      return false;
    if (*sz < sizeof(val)) {
      return false;
    }
    *sz = sizeof(val); // Get the Matra
    // Copy Data
    memcpy(b, &val, *sz);
    return true;
  }

  bool Bytes(bool val, uint8_t *b, size_t *sz) {
    if (b == NULL || sz == NULL)
      return false;
    if (*sz < sizeof(val)) {
      return false;
    }
    *sz = sizeof(val); // Get the Matra
    // Copy Data
    memcpy(b, &val, *sz);
    return true;
  }

  bool Bytes(int64_t val, uint8_t *b, size_t *sz) {
    if (b == NULL || sz == NULL)
      return false;
    if (*sz < sizeof(val)) {
      return false;
    }
    *sz = sizeof(val); // Get the Matra
    // Copy Data
    memcpy(b, &val, *sz);
    return true;
  }

  bool Bytes(ID val, uint8_t *b, size_t *sz) { return Bytes(val.val, b, sz); }

  bool Bytes(Proto val, uint8_t *b, size_t *sz) {
    return Bytes(val.val, b, sz);
  }

  bool Bytes(CMD val, uint8_t *b, size_t *sz) { return Bytes(val.val, b, sz); }

  bool Bytes(ADDR val, uint8_t *b, size_t *sz) { return Bytes(val.val, b, sz); }

  bool Bytes(CRC32 val, uint8_t *b, size_t *sz) {
    return Bytes(val.val, b, sz);
  }

  bool Bytes(Sampurna val, uint8_t *b, size_t *sz) {
    return Bytes(val.val, b, sz);
  }

  bool Bytes(Array val, uint8_t *b, size_t *sz) {
    return Bytes(val.val, b, sz);
  }

  bool Bytes(Tuples val, uint8_t *b, size_t *sz) {
    return Bytes(val.val, b, sz);
  }

  bool Bytes(ChunkTotal val, uint8_t *b, size_t *sz) {
    return Bytes(val.val, b, sz);
  }

  bool Bytes(ChunkIndex val, uint8_t *b, size_t *sz) {
    return Bytes(val.val, b, sz);
  }

  // From Buffer Allows to convert from Buffer to char[]

  bool FromBuffer(Buffer *b, char *buf, uint16_t *sz) {
    if (b == NULL || buf == NULL || sz == NULL)
      return false;
    // Check Null termination and Size
    if (*sz < b->size || (b->isNullTerminated && *sz <= b->size)) {
      return false;
    }
    memcpy(buf, b->bytes, b->size);
    *sz = b->size;
    if (b->isNullTerminated) {
      buf[b->size] = 0;
      *sz += 1;
    }
    return true;
  }

  // From helps to convert Vastu from its uint8_t[] form back to
  // the actual data type.

  bool From(uint8_t *b, size_t sz, Buffer *val) {
    uint16_t pack_size;
    size_t total;
    if (val == NULL || b == NULL || sz == 0)
      return false;
    // First 2 bytes are size
    // pack_size = (((uint16_t)b[1]) << 8) | ((uint16_t)b[0]);
    memcpy(&pack_size, b, sizeof(pack_size));
    total = (sizeof(pack_size) + pack_size);
    // Check Size
    if (sz < total || val->capacity < pack_size) {
      return false;
    }
    // Copy Values
    memcpy(val->bytes, &b[sizeof(pack_size)], pack_size);
    val->size = pack_size;
    return true;
  }

  bool From(uint8_t *b, size_t sz, uint16_t *val) {
    if (val == NULL || b == NULL || sz == 0)
      return false;
    if (sz < sizeof(*val)) {
      return false;
    }
    memcpy(val, b, sizeof(*val));
    return true;
  }

  bool From(uint8_t *b, size_t sz, uint32_t *val) {
    if (val == NULL || b == NULL || sz == 0)
      return false;
    if (sz < sizeof(*val)) {
      return false;
    }
    memcpy(val, b, sizeof(*val));
    return true;
  }

  bool From(uint8_t *b, size_t sz, uint64_t *val) {
    if (val == NULL || b == NULL || sz == 0)
      return false;
    if (sz < sizeof(*val)) {
      return false;
    }
    memcpy(val, b, sizeof(*val));
    return true;
  }

  bool From(uint8_t *b, size_t sz, float *val) {
    if (val == NULL || b == NULL || sz == 0)
      return false;
    if (sz < sizeof(*val)) {
      return false;
    }
    memcpy(val, b, sizeof(*val));
    return true;
  }

  bool From(uint8_t *b, size_t sz, double *val) {
    if (val == NULL || b == NULL || sz == 0)
      return false;
    if (sz < sizeof(*val)) {
      return false;
    }
    memcpy(val, b, sizeof(*val));
    return true;
  }

  bool From(uint8_t *b, size_t sz, uint8_t *val) {
    if (val == NULL || b == NULL || sz == 0)
      return false;
    if (sz < sizeof(*val)) {
      return false;
    }
    memcpy(val, b, sizeof(*val));
    return true;
  }

  bool From(uint8_t *b, size_t sz, int8_t *val) {
    if (val == NULL || b == NULL || sz == 0)
      return false;
    if (sz < sizeof(*val)) {
      return false;
    }
    memcpy(val, b, sizeof(*val));
    return true;
  }

  bool From(uint8_t *b, size_t sz, char *val) {
    return From(b, sz, (int8_t *)(val));
  }

  bool From(uint8_t *b, size_t sz, int16_t *val) {
    if (val == NULL || b == NULL || sz == 0)
      return false;
    if (sz < sizeof(*val)) {
      return false;
    }
    memcpy(val, b, sizeof(*val));
    return true;
  }

  bool From(uint8_t *b, size_t sz, int32_t *val) {
    if (val == NULL || b == NULL || sz == 0)
      return false;
    if (sz < sizeof(*val)) {
      return false;
    }
    memcpy(val, b, sizeof(*val));
    return true;
  }

  bool From(uint8_t *b, size_t sz, bool *val) {
    if (val == NULL || b == NULL || sz == 0)
      return false;
    if (sz < sizeof(*val)) {
      return false;
    }
    memcpy(val, b, sizeof(*val));
    return true;
  }

  bool From(uint8_t *b, size_t sz, int64_t *val) {
    if (val == NULL || b == NULL || sz == 0)
      return false;
    if (sz < sizeof(*val)) {
      return false;
    }
    memcpy(val, b, sizeof(*val));
    return true;
  }

  bool From(uint8_t *b, size_t sz, ID *val) { return From(b, sz, &val->val); }

  bool From(uint8_t *b, size_t sz, Proto *val) {
    return From(b, sz, &val->val);
  }

  bool From(uint8_t *b, size_t sz, CMD *val) { return From(b, sz, &val->val); }

  bool From(uint8_t *b, size_t sz, CRC32 *val) {
    return From(b, sz, &val->val);
  }

  bool From(uint8_t *b, size_t sz, Sampurna *val) {
    return From(b, sz, &val->val);
  }

  bool From(uint8_t *b, size_t sz, Array *val) {
    return From(b, sz, &val->val);
  }

  bool From(uint8_t *b, size_t sz, Tuples *val) {
    return From(b, sz, &val->val);
  }

  bool From(uint8_t *b, size_t sz, ChunkTotal *val) {
    return From(b, sz, &val->val);
  }

  bool From(uint8_t *b, size_t sz, ChunkIndex *val) {
    return From(b, sz, &val->val);
  }
};
static Vastu_t Vastu;

#endif /* _VASTU_H_ */
