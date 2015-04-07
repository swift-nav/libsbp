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
#include <bootload.h>

START_TEST(test_sbp_bootload_msgs)
{
}
END_TEST

Suite* bootload_suite(void)
{
  Suite *s = suite_create("SBP bootload tests");
  TCase *tc_boot = tcase_create("SBP_boot");
  tcase_add_test(tc_boot, test_sbp_bootload_msgs);
  suite_add_tcase(s, tc_boot);
  return s;
}