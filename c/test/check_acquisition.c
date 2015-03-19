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
#include <acquisition.h>

START_TEST(test_sbp_acquisition_msgs)
{
}
END_TEST

Suite* acquisition_suite(void)
{
  Suite *s = suite_create("SBP acquisition tests");
  TCase *tc_acq = tcase_create("SBP_acq");
  tcase_add_test(tc_acq, test_sbp_acquisition_msgs);
  suite_add_tcase(s, tc_acq);
  return s;
}