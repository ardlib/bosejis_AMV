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
#ifndef _ANKITAK_H_
#define _ANKITAK_H_

// अंकितक Specification
//
// | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
// |           |-------------------| = वस्तु
// |-----------|                     = अंकितक
//   *--------------------------------- = Request(0)/Response(1)
//       *----------------------------- = Option Prakriya(1)
//           *------------------------- = Option 2 Byte Checksum(1)

#include <Arduino.h>

// Request अंकितक 0b0000_0000
#define Ankitak_Request ((byte)(0x00))

// Response अंकितक 0b1000_0000
#define Ankitak_Response ((byte)(0x80))

// Checksum enabled अंकितक that have a 2 Byte Checksum included 0b0010_0000
#define Ankitak_Checksum ((byte)(0x20))

// Prakriya enabled अंकितक that needs to run additional functions
// on the पुलिंदा. 0b0100_0000
#define Ankitak_Prakriya ((byte)(0x40))

// Filter for अंकितक 0b1110_0000
#define Ankitak_Mask ((byte)(0xE0))

// maskReqRes is a mask for अंकितक to set or clear
// Request / Response bit. 0b1000_0000
#define _Ankitak_maskReqRes ((byte)(0x80))

// _Ankitak_t is the C++ representation of अंकितक
class _Ankitak_t {
public:
  // WithPrakriya enables Additional functions for अंकितक
  byte WithPrakriya(byte a) {
    a = (a | Ankitak_Prakriya);
    return a;
  };

  // WithChecksum enables addition of Checksum for अंकितक
  byte WithChecksum(byte a) {
    a = (a | Ankitak_Checksum);
    return a;
  };

  // HasPrakriya check is the अंकितक has additional function enabled
  bool HasPrakriya(byte a) {
    return (a & Ankitak_Prakriya) == Ankitak_Prakriya;
  };

  // HasChecksum tells if the अंकितक has 2 Byte Checksum included
  bool HasChecksum(byte a) {
    return (a & Ankitak_Checksum) == Ankitak_Checksum;
  };

  // Request converts the अंकितक to indicate request पुलिंदा
  byte Request(byte a) {
    a = ((a & (~_Ankitak_maskReqRes)) | Ankitak_Request);
    return a;
  };

  // Response converts the अंकितक to indicate response पुलिंदा
  byte Response(byte a) {
    a = ((a & (~_Ankitak_maskReqRes)) | Ankitak_Response);
    return a;
  };

  // IsRequest tells if the अंकितक is for a request पुलिंदा
  bool IsRequest(byte a) {
    return (a & _Ankitak_maskReqRes) == Ankitak_Request;
  };

  // IsResponse tells if the अंकितक is for a response पुलिंदा
  bool IsResponse(byte a) {
    return (a & _Ankitak_maskReqRes) == Ankitak_Response;
  };
};

static _Ankitak_t Ankitak;

#endif /* _ANKITAK_H_ */
