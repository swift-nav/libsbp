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

#include <gtest/gtest.h>
#include <libsbp/imu.h>
#include <libsbp/navigation.h>
#include <libsbp/observation.h>
#include <libsbp/system.h>
#include <stdio.h>

namespace {

TEST(BitfieldMacros, test_nav_bitfields) {
  sbp_msg_gps_time_t gps_t = {
      .wn = 1, .tow = 100, .ns_residual = 1, .flags = 0};

  SBP_GPS_TIME_TIME_SOURCE_SET(gps_t.flags, SBP_GPS_TIME_TIME_SOURCE_NONE);
  EXPECT_EQ(gps_t.flags, 0);
  uint8_t time_source = SBP_GPS_TIME_TIME_SOURCE_GET(gps_t.flags);
  EXPECT_EQ(time_source, 0);
  SBP_GPS_TIME_TIME_SOURCE_SET(gps_t.flags,
                               SBP_GPS_TIME_TIME_SOURCE_GNSS_SOLUTION);
  EXPECT_EQ(gps_t.flags, 1);
  time_source = SBP_GPS_TIME_TIME_SOURCE_GET(gps_t.flags);
  EXPECT_EQ(time_source, 1);
  SBP_GPS_TIME_TIME_SOURCE_SET(gps_t.flags,
                               SBP_GPS_TIME_TIME_SOURCE_PROPAGATED);

  sbp_msg_pos_llh_t pos = {};
  uint8_t ins_mode = SBP_POS_LLH_INERTIAL_NAVIGATION_MODE_GET(pos.flags);
  EXPECT_EQ(ins_mode, 0);
  SBP_POS_LLH_INERTIAL_NAVIGATION_MODE_SET(
      pos.flags, SBP_POS_LLH_INERTIAL_NAVIGATION_MODE_INS_USED);
  ins_mode = SBP_POS_LLH_INERTIAL_NAVIGATION_MODE_GET(pos.flags);
  EXPECT_EQ(ins_mode, 1);
  EXPECT_EQ(ins_mode, SBP_POS_LLH_INERTIAL_NAVIGATION_MODE_INS_USED);
  EXPECT_EQ(pos.flags, 0x8);
}

TEST(BitfieldMacros, test_imu_bitfields) {
  sbp_msg_imu_raw_t imu = {};
  imu.tow = 100;
  SBP_IMU_RAW_TIME_STATUS_SET(
      imu.tow,
      SBP_IMU_RAW_TIME_STATUS_REFERENCE_EPOCH_IS_TIME_OF_SYSTEM_STARTUP);
  EXPECT_EQ(imu.tow, (100 | 0x40000000));
  SBP_IMU_RAW_TIME_STATUS_SET(
      imu.tow, (u32)SBP_IMU_RAW_TIME_STATUS_REFERENCE_EPOCH_IS_UNKNOWN);
  EXPECT_EQ(imu.tow, (100 | 0x80000000));
  uint32_t tow =
      SBP_IMU_RAW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_GET(imu.tow);
  EXPECT_EQ(tow, 100);
}

TEST(BitfieldMacros, test_ins_status_bitfields) {
  // TODO(?) : This test case currently failing
  sbp_msg_ins_status_t ins_status = {.flags = 0};
  SBP_INS_STATUS_INS_TYPE_SET(
      ins_status.flags, SBP_INS_STATUS_INS_TYPE_SMOOTHPOSE_LOOSELY_COUPLED);
  EXPECT_EQ(ins_status.flags, 0);
  SBP_INS_STATUS_INS_TYPE_SET(ins_status.flags,
                              SBP_INS_STATUS_INS_TYPE_STARLING);
  /* INS_TYPE is 3 MSBs of the word, "STARLING" is described by value 1, setting
   * bit 29 to 1 makes 0x20000000.  */
  EXPECT_EQ(ins_status.flags, 0x20000000);
}

TEST(BitfieldMacros, test_packed_obs_bitfields) {
  u8 flags = 0x0F;

  SBP_PACKEDOBSCONTENT_RAIM_EXCLUSION_SET(flags, 0x80);
  EXPECT_EQ(flags, 0x0F);

  SBP_PACKEDOBSCONTENT_RAIM_EXCLUSION_SET(flags, 1);
  EXPECT_EQ(flags, 0x8F);
}

}  // namespace
