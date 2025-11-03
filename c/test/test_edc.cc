/*
 * Copyright (C) 2011-2021 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swift-nav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

#include <edc.h>
#include <gtest/gtest.h>

namespace {

const u8 *test_data = (const u8 *)"123456789";

TEST(Edc, test_crc16_ccitt) {
  u16 crc;

  crc = crc16_ccitt(test_data, 0, 0);
  EXPECT_EQ(crc, 0)
      << "CRC of empty buffer with starting value 0 should be 0, not " << crc;

  crc = crc16_ccitt(test_data, 0, 22);
  EXPECT_EQ(crc, 22)
      << "CRC of empty buffer with starting value 22 should be 22, not " << crc;

  /* Test value taken from python crcmod package tests, see:
   * http://crcmod.sourceforge.net/crcmod.predefined.html */
  crc = crc16_ccitt(test_data, 9, 0);
  EXPECT_EQ(crc, 0x31C3) << "CRC of \"123456789\" should be 0x31C3, not "
                         << crc;
}

}  // namespace
