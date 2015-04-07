/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Bhaskar Mookerji <mookerji@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

#include <check.h>
#include <file_io.h>

START_TEST(test_sbp_file_io_msgs)
{
}
END_TEST

Suite* file_io_suite(void)
{
  Suite *s = suite_create("SBP file_io tests");
  TCase *tc_file_io = tcase_create("SBP_file_io");
  tcase_add_test(tc_file_io, test_sbp_file_io_msgs);
  suite_add_tcase(s, tc_file_io);
  return s;
}