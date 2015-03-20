/*
 * Copyright (C) 2011-2015 Swift Navigation Inc.
 * Contact: Fergus Noble <fergus@swift-nav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

#include <check.h>
#include <edc.h>

const u8 *test_data = (u8*)"123456789";

START_TEST(test_crc16_ccitt)
{
  u16 crc;

  crc = crc16_ccitt(test_data, 0, 0);
  fail_unless(crc == 0,
    "CRC of empty buffer with starting value 0 should be 0, not %d", crc);

  crc = crc16_ccitt(test_data, 0, 22);
  fail_unless(crc == 22,
    "CRC of empty buffer with starting value 22 should be 22, not %d", crc);

  /* Test value taken from python crcmod package tests, see:
   * http://crcmod.sourceforge.net/crcmod.predefined.html */
  crc = crc16_ccitt(test_data, 9, 0);
  fail_unless(crc == 0x31C3,
    "CRC of \"123456789\" should be 0x31C3, not 0x%04X", crc);
}
END_TEST

Suite* edc_suite(void)
{
  Suite *s = suite_create("Error Detection and Correction");

  TCase *tc_crc = tcase_create("CRC");
  tcase_add_test(tc_crc, test_crc16_ccitt);
  suite_add_tcase(s, tc_crc);

  return s;
}
