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
#include <system.h>

START_TEST(test_sbp_system_msgs)
{
}
END_TEST

Suite* system_suite(void)
{
  Suite *s = suite_create("SBP system tests");
  TCase *tc_sys = tcase_create("SBP_system");
  tcase_add_test(tc_sys, test_sbp_system_msgs);
  suite_add_tcase(s, tc_sys);
  return s;
}