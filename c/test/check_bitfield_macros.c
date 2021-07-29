/*
 * Copyright (C) 2011-2021 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swift-nav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

#include <check.h>
#include <imu.h>
#include <navigation.h>
#include <stdio.h>
#include <system.h>

START_TEST(test_nav_bitfields) {
  msg_gps_time_t gps_t = {.wn = 1, .tow = 100, .ns_residual = 1, .flags = 0};

  SBP_GPS_TIME_TIME_SOURCE_SET(gps_t.flags, SBP_GPS_TIME_TIME_SOURCE_NONE);
  fail_unless(gps_t.flags == 0);
  uint8_t time_source = SBP_GPS_TIME_TIME_SOURCE_GET(gps_t.flags);
  fail_unless(time_source == 0);
  SBP_GPS_TIME_TIME_SOURCE_SET(gps_t.flags,
                               SBP_GPS_TIME_TIME_SOURCE_GNSS_SOLUTION);
  fail_unless(gps_t.flags == 1);
  time_source = SBP_GPS_TIME_TIME_SOURCE_GET(gps_t.flags);
  fail_unless(time_source == 1);
  SBP_GPS_TIME_TIME_SOURCE_SET(gps_t.flags,
                               SBP_GPS_TIME_TIME_SOURCE_PROPAGATED);

  msg_pos_llh_t pos = {.flags = 0};
  uint8_t ins_mode = SBP_POS_LLH_INERTIAL_NAVIGATION_MODE_GET(pos.flags);
  fail_unless(ins_mode == 0);
  SBP_POS_LLH_INERTIAL_NAVIGATION_MODE_SET(
      pos.flags, SBP_POS_LLH_INERTIAL_NAVIGATION_MODE_INS_USED);
  ins_mode = SBP_POS_LLH_INERTIAL_NAVIGATION_MODE_GET(pos.flags);
  fail_unless(ins_mode == 1);
  fail_unless(ins_mode == SBP_POS_LLH_INERTIAL_NAVIGATION_MODE_INS_USED);
  fail_unless(pos.flags == 0x8);
}
END_TEST

START_TEST(test_imu_bitfields) {
  msg_imu_raw_t imu = {.tow = 100};
  SBP_IMU_RAW_TIME_STATUS_SET(
      imu.tow,
      SBP_IMU_RAW_TIME_STATUS_REFERENCE_EPOCH_IS_TIME_OF_SYSTEM_STARTUP);
  fail_unless(imu.tow == (100 | 0x40000000));
  uint32_t tow =
      SBP_IMU_RAW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_GET(imu.tow);
  fail_unless(tow == (100));
}
END_TEST

START_TEST(test_ins_status_bitfields) {
  // TODO(?) : This test case currently failing
  msg_ins_status_t ins_status = {.flags = 0};
  SBP_INS_STATUS_INS_TYPE_SET(
      ins_status.flags, SBP_INS_STATUS_INS_TYPE_SMOOTHPOSE_LOOSELY_COUPLED);
  fail_unless(ins_status.flags == 0);
  SBP_INS_STATUS_INS_TYPE_SET(ins_status.flags,
                              SBP_INS_STATUS_INS_TYPE_STARLING);
  /* INS_TYPE is 3 MSBs of the word, "STARLING" is described by value 1, setting
   * bit 29 to 1 makes 0x20000000.  */
  fail_unless(ins_status.flags == 0x20000000);
}
END_TEST

Suite *bitfield_macros_suite(void) {
  Suite *s = suite_create("SBP_Bitfields");

  TCase *tc_core_2 = tcase_create("Core2");

  tcase_add_test(tc_core_2, test_nav_bitfields);
  tcase_add_test(tc_core_2, test_imu_bitfields);
  tcase_add_test(tc_core_2, test_ins_status_bitfields);
  suite_add_tcase(s, tc_core_2);

  return s;
}
