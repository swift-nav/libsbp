/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrSatelliteApcDepA.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>

#include <libsbp/common.h>
#include <libsbp/cpp/state.h>

// Obviously we don't normally want to silence this message, but we also need to
// still test the legacy implementation for as long as it exists. By silencing
// these messages here we can get a less noisy build in libsbp
#ifdef SBP_MESSAGE
#undef SBP_MESSAGE
#define SBP_MESSAGE(x)
#endif
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
#include <libsbp/legacy/ssr.h>
class Test_legacy_auto_check_sbp_ssr_MsgSsrSatelliteApcDepA0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_ssr_satellite_apc_dep_t> {
 public:
  Test_legacy_auto_check_sbp_ssr_MsgSsrSatelliteApcDepA0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_ssr_satellite_apc_dep_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_ssr_satellite_apc_dep_t *>(last_msg_storage_)),
        last_msg_len_(),
        last_sender_id_(),
        n_callbacks_logged_(),
        dummy_wr_(),
        dummy_rd_(),
        dummy_buff_() {
    set_reader(this);
    set_writer(this);
  }

  s32 read(uint8_t *buf, const uint32_t n) override {
    uint32_t real_n = n;
    memcpy(buf, dummy_buff_ + dummy_rd_, real_n);
    dummy_rd_ += real_n;
    return (s32)real_n;
  }

  s32 write(const uint8_t *buf, uint32_t n) override {
    uint32_t real_n = n;
    memcpy(dummy_buff_ + dummy_wr_, buf, real_n);
    dummy_wr_ += real_n;
    return (s32)real_n;
  }

 protected:
  void handle_sbp_msg(uint16_t sender_id, uint8_t message_length,
                      const msg_ssr_satellite_apc_dep_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_ssr_satellite_apc_dep_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_ssr_MsgSsrSatelliteApcDepA0, Test) {
  uint8_t encoded_frame[] = {
      85,  4,   6,   56,  19,  224, 203, 169, 240, 78,  4,   213, 171, 254, 214,
      212, 4,   8,   33,  31,  80,  21,  4,   105, 225, 39,  139, 124, 149, 48,
      15,  214, 197, 141, 32,  33,  135, 150, 148, 123, 49,  135, 97,  39,  90,
      20,  169, 239, 47,  153, 175, 35,  145, 145, 123, 194, 2,   102, 74,  149,
      95,  171, 238, 249, 7,   237, 170, 125, 106, 158, 83,  188, 181, 194, 27,
      84,  226, 142, 123, 77,  217, 248, 67,  215, 129, 114, 138, 25,  240, 10,
      56,  76,  61,  161, 216, 22,  181, 174, 33,  13,  252, 236, 230, 196, 128,
      215, 239, 234, 179, 220, 44,  212, 57,  44,  173, 49,  36,  137, 248, 235,
      97,  112, 157, 139, 26,  115, 192, 31,  85,  127, 228, 81,  252, 219, 249,
      110, 147, 8,   161, 215, 212, 180, 25,  83,  144, 247, 12,  27,  199, 173,
      74,  23,  4,   239, 103, 223, 220, 139, 91,  127, 214, 86,  48,  203, 228,
      99,  45,  83,  159, 11,  250, 135, 170, 42,  217, 199, 233, 42,  170, 78,
      206, 41,  43,  81,  247, 99,  198, 144, 2,   132, 2,   224, 220, 148, 58,
      85,  138, 210, 200, 158, 7,   158, 67,  46,  200, 132, 118, 241, 13,  37,
      62,  107, 253, 190, 136, 66,  9,   84,  155, 86,  180, 41,  196, 40,  119,
      101, 252, 223, 144, 153, 50,  13,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_ssr_satellite_apc_dep_t *test_msg =
      (msg_ssr_satellite_apc_dep_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  if (sizeof(test_msg->apc) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0]));
  }
  if (sizeof(test_msg->apc[0].pco) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pco[0]));
  }
  test_msg->apc[0].pco[0] = -21547;
  if (sizeof(test_msg->apc[0].pco) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pco[0]));
  }
  test_msg->apc[0].pco[1] = -10498;
  if (sizeof(test_msg->apc[0].pco) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pco[0]));
  }
  test_msg->apc[0].pco[2] = 1236;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[0] = 8;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[1] = 33;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[2] = 31;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[3] = 80;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[4] = 21;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[5] = 4;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[6] = 105;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[7] = -31;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[8] = 39;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[9] = -117;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[10] = 124;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[11] = -107;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[12] = 48;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[13] = 15;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[14] = -42;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[15] = -59;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[16] = -115;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[17] = 32;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[18] = 33;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[19] = -121;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[20] = -106;
  test_msg->apc[0].sat_info = 240;
  test_msg->apc[0].sid.code = 169;
  test_msg->apc[0].sid.sat = 203;
  test_msg->apc[0].svn = 1102;
  if (sizeof(test_msg->apc) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0]));
  }
  if (sizeof(test_msg->apc[1].pco) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[1].pco[0]));
  }
  test_msg->apc[1].pco[0] = 23079;
  if (sizeof(test_msg->apc[1].pco) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[1].pco[0]));
  }
  test_msg->apc[1].pco[1] = -22252;
  if (sizeof(test_msg->apc[1].pco) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[1].pco[0]));
  }
  test_msg->apc[1].pco[2] = 12271;
  if (sizeof(test_msg->apc[1].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[1].pcv[0]));
  }
  test_msg->apc[1].pcv[0] = -103;
  if (sizeof(test_msg->apc[1].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[1].pcv[0]));
  }
  test_msg->apc[1].pcv[1] = -81;
  if (sizeof(test_msg->apc[1].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[1].pcv[0]));
  }
  test_msg->apc[1].pcv[2] = 35;
  if (sizeof(test_msg->apc[1].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[1].pcv[0]));
  }
  test_msg->apc[1].pcv[3] = -111;
  if (sizeof(test_msg->apc[1].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[1].pcv[0]));
  }
  test_msg->apc[1].pcv[4] = -111;
  if (sizeof(test_msg->apc[1].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[1].pcv[0]));
  }
  test_msg->apc[1].pcv[5] = 123;
  if (sizeof(test_msg->apc[1].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[1].pcv[0]));
  }
  test_msg->apc[1].pcv[6] = -62;
  if (sizeof(test_msg->apc[1].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[1].pcv[0]));
  }
  test_msg->apc[1].pcv[7] = 2;
  if (sizeof(test_msg->apc[1].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[1].pcv[0]));
  }
  test_msg->apc[1].pcv[8] = 102;
  if (sizeof(test_msg->apc[1].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[1].pcv[0]));
  }
  test_msg->apc[1].pcv[9] = 74;
  if (sizeof(test_msg->apc[1].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[1].pcv[0]));
  }
  test_msg->apc[1].pcv[10] = -107;
  if (sizeof(test_msg->apc[1].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[1].pcv[0]));
  }
  test_msg->apc[1].pcv[11] = 95;
  if (sizeof(test_msg->apc[1].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[1].pcv[0]));
  }
  test_msg->apc[1].pcv[12] = -85;
  if (sizeof(test_msg->apc[1].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[1].pcv[0]));
  }
  test_msg->apc[1].pcv[13] = -18;
  if (sizeof(test_msg->apc[1].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[1].pcv[0]));
  }
  test_msg->apc[1].pcv[14] = -7;
  if (sizeof(test_msg->apc[1].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[1].pcv[0]));
  }
  test_msg->apc[1].pcv[15] = 7;
  if (sizeof(test_msg->apc[1].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[1].pcv[0]));
  }
  test_msg->apc[1].pcv[16] = -19;
  if (sizeof(test_msg->apc[1].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[1].pcv[0]));
  }
  test_msg->apc[1].pcv[17] = -86;
  if (sizeof(test_msg->apc[1].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[1].pcv[0]));
  }
  test_msg->apc[1].pcv[18] = 125;
  if (sizeof(test_msg->apc[1].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[1].pcv[0]));
  }
  test_msg->apc[1].pcv[19] = 106;
  if (sizeof(test_msg->apc[1].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[1].pcv[0]));
  }
  test_msg->apc[1].pcv[20] = -98;
  test_msg->apc[1].sat_info = 49;
  test_msg->apc[1].sid.code = 123;
  test_msg->apc[1].sid.sat = 148;
  test_msg->apc[1].svn = 24967;
  if (sizeof(test_msg->apc) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0]));
  }
  if (sizeof(test_msg->apc[2].pco) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[2].pco[0]));
  }
  test_msg->apc[2].pco[0] = -7596;
  if (sizeof(test_msg->apc[2].pco) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[2].pco[0]));
  }
  test_msg->apc[2].pco[1] = 31630;
  if (sizeof(test_msg->apc[2].pco) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[2].pco[0]));
  }
  test_msg->apc[2].pco[2] = -9907;
  if (sizeof(test_msg->apc[2].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[2].pcv[0]));
  }
  test_msg->apc[2].pcv[0] = -8;
  if (sizeof(test_msg->apc[2].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[2].pcv[0]));
  }
  test_msg->apc[2].pcv[1] = 67;
  if (sizeof(test_msg->apc[2].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[2].pcv[0]));
  }
  test_msg->apc[2].pcv[2] = -41;
  if (sizeof(test_msg->apc[2].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[2].pcv[0]));
  }
  test_msg->apc[2].pcv[3] = -127;
  if (sizeof(test_msg->apc[2].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[2].pcv[0]));
  }
  test_msg->apc[2].pcv[4] = 114;
  if (sizeof(test_msg->apc[2].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[2].pcv[0]));
  }
  test_msg->apc[2].pcv[5] = -118;
  if (sizeof(test_msg->apc[2].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[2].pcv[0]));
  }
  test_msg->apc[2].pcv[6] = 25;
  if (sizeof(test_msg->apc[2].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[2].pcv[0]));
  }
  test_msg->apc[2].pcv[7] = -16;
  if (sizeof(test_msg->apc[2].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[2].pcv[0]));
  }
  test_msg->apc[2].pcv[8] = 10;
  if (sizeof(test_msg->apc[2].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[2].pcv[0]));
  }
  test_msg->apc[2].pcv[9] = 56;
  if (sizeof(test_msg->apc[2].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[2].pcv[0]));
  }
  test_msg->apc[2].pcv[10] = 76;
  if (sizeof(test_msg->apc[2].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[2].pcv[0]));
  }
  test_msg->apc[2].pcv[11] = 61;
  if (sizeof(test_msg->apc[2].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[2].pcv[0]));
  }
  test_msg->apc[2].pcv[12] = -95;
  if (sizeof(test_msg->apc[2].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[2].pcv[0]));
  }
  test_msg->apc[2].pcv[13] = -40;
  if (sizeof(test_msg->apc[2].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[2].pcv[0]));
  }
  test_msg->apc[2].pcv[14] = 22;
  if (sizeof(test_msg->apc[2].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[2].pcv[0]));
  }
  test_msg->apc[2].pcv[15] = -75;
  if (sizeof(test_msg->apc[2].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[2].pcv[0]));
  }
  test_msg->apc[2].pcv[16] = -82;
  if (sizeof(test_msg->apc[2].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[2].pcv[0]));
  }
  test_msg->apc[2].pcv[17] = 33;
  if (sizeof(test_msg->apc[2].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[2].pcv[0]));
  }
  test_msg->apc[2].pcv[18] = 13;
  if (sizeof(test_msg->apc[2].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[2].pcv[0]));
  }
  test_msg->apc[2].pcv[19] = -4;
  if (sizeof(test_msg->apc[2].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[2].pcv[0]));
  }
  test_msg->apc[2].pcv[20] = -20;
  test_msg->apc[2].sat_info = 181;
  test_msg->apc[2].sid.code = 188;
  test_msg->apc[2].sid.sat = 83;
  test_msg->apc[2].svn = 7106;
  if (sizeof(test_msg->apc) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0]));
  }
  if (sizeof(test_msg->apc[3].pco) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[3].pco[0]));
  }
  test_msg->apc[3].pco[0] = -19478;
  if (sizeof(test_msg->apc[3].pco) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[3].pco[0]));
  }
  test_msg->apc[3].pco[1] = 11484;
  if (sizeof(test_msg->apc[3].pco) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[3].pco[0]));
  }
  test_msg->apc[3].pco[2] = 14804;
  if (sizeof(test_msg->apc[3].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[3].pcv[0]));
  }
  test_msg->apc[3].pcv[0] = 44;
  if (sizeof(test_msg->apc[3].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[3].pcv[0]));
  }
  test_msg->apc[3].pcv[1] = -83;
  if (sizeof(test_msg->apc[3].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[3].pcv[0]));
  }
  test_msg->apc[3].pcv[2] = 49;
  if (sizeof(test_msg->apc[3].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[3].pcv[0]));
  }
  test_msg->apc[3].pcv[3] = 36;
  if (sizeof(test_msg->apc[3].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[3].pcv[0]));
  }
  test_msg->apc[3].pcv[4] = -119;
  if (sizeof(test_msg->apc[3].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[3].pcv[0]));
  }
  test_msg->apc[3].pcv[5] = -8;
  if (sizeof(test_msg->apc[3].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[3].pcv[0]));
  }
  test_msg->apc[3].pcv[6] = -21;
  if (sizeof(test_msg->apc[3].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[3].pcv[0]));
  }
  test_msg->apc[3].pcv[7] = 97;
  if (sizeof(test_msg->apc[3].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[3].pcv[0]));
  }
  test_msg->apc[3].pcv[8] = 112;
  if (sizeof(test_msg->apc[3].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[3].pcv[0]));
  }
  test_msg->apc[3].pcv[9] = -99;
  if (sizeof(test_msg->apc[3].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[3].pcv[0]));
  }
  test_msg->apc[3].pcv[10] = -117;
  if (sizeof(test_msg->apc[3].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[3].pcv[0]));
  }
  test_msg->apc[3].pcv[11] = 26;
  if (sizeof(test_msg->apc[3].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[3].pcv[0]));
  }
  test_msg->apc[3].pcv[12] = 115;
  if (sizeof(test_msg->apc[3].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[3].pcv[0]));
  }
  test_msg->apc[3].pcv[13] = -64;
  if (sizeof(test_msg->apc[3].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[3].pcv[0]));
  }
  test_msg->apc[3].pcv[14] = 31;
  if (sizeof(test_msg->apc[3].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[3].pcv[0]));
  }
  test_msg->apc[3].pcv[15] = 85;
  if (sizeof(test_msg->apc[3].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[3].pcv[0]));
  }
  test_msg->apc[3].pcv[16] = 127;
  if (sizeof(test_msg->apc[3].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[3].pcv[0]));
  }
  test_msg->apc[3].pcv[17] = -28;
  if (sizeof(test_msg->apc[3].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[3].pcv[0]));
  }
  test_msg->apc[3].pcv[18] = 81;
  if (sizeof(test_msg->apc[3].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[3].pcv[0]));
  }
  test_msg->apc[3].pcv[19] = -4;
  if (sizeof(test_msg->apc[3].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[3].pcv[0]));
  }
  test_msg->apc[3].pcv[20] = -37;
  test_msg->apc[3].sat_info = 128;
  test_msg->apc[3].sid.code = 196;
  test_msg->apc[3].sid.sat = 230;
  test_msg->apc[3].svn = 61399;
  if (sizeof(test_msg->apc) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0]));
  }
  if (sizeof(test_msg->apc[4].pco) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[4].pco[0]));
  }
  test_msg->apc[4].pco[0] = -11049;
  if (sizeof(test_msg->apc[4].pco) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[4].pco[0]));
  }
  test_msg->apc[4].pco[1] = 6580;
  if (sizeof(test_msg->apc[4].pco) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[4].pco[0]));
  }
  test_msg->apc[4].pco[2] = -28589;
  if (sizeof(test_msg->apc[4].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[4].pcv[0]));
  }
  test_msg->apc[4].pcv[0] = -9;
  if (sizeof(test_msg->apc[4].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[4].pcv[0]));
  }
  test_msg->apc[4].pcv[1] = 12;
  if (sizeof(test_msg->apc[4].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[4].pcv[0]));
  }
  test_msg->apc[4].pcv[2] = 27;
  if (sizeof(test_msg->apc[4].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[4].pcv[0]));
  }
  test_msg->apc[4].pcv[3] = -57;
  if (sizeof(test_msg->apc[4].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[4].pcv[0]));
  }
  test_msg->apc[4].pcv[4] = -83;
  if (sizeof(test_msg->apc[4].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[4].pcv[0]));
  }
  test_msg->apc[4].pcv[5] = 74;
  if (sizeof(test_msg->apc[4].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[4].pcv[0]));
  }
  test_msg->apc[4].pcv[6] = 23;
  if (sizeof(test_msg->apc[4].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[4].pcv[0]));
  }
  test_msg->apc[4].pcv[7] = 4;
  if (sizeof(test_msg->apc[4].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[4].pcv[0]));
  }
  test_msg->apc[4].pcv[8] = -17;
  if (sizeof(test_msg->apc[4].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[4].pcv[0]));
  }
  test_msg->apc[4].pcv[9] = 103;
  if (sizeof(test_msg->apc[4].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[4].pcv[0]));
  }
  test_msg->apc[4].pcv[10] = -33;
  if (sizeof(test_msg->apc[4].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[4].pcv[0]));
  }
  test_msg->apc[4].pcv[11] = -36;
  if (sizeof(test_msg->apc[4].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[4].pcv[0]));
  }
  test_msg->apc[4].pcv[12] = -117;
  if (sizeof(test_msg->apc[4].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[4].pcv[0]));
  }
  test_msg->apc[4].pcv[13] = 91;
  if (sizeof(test_msg->apc[4].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[4].pcv[0]));
  }
  test_msg->apc[4].pcv[14] = 127;
  if (sizeof(test_msg->apc[4].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[4].pcv[0]));
  }
  test_msg->apc[4].pcv[15] = -42;
  if (sizeof(test_msg->apc[4].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[4].pcv[0]));
  }
  test_msg->apc[4].pcv[16] = 86;
  if (sizeof(test_msg->apc[4].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[4].pcv[0]));
  }
  test_msg->apc[4].pcv[17] = 48;
  if (sizeof(test_msg->apc[4].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[4].pcv[0]));
  }
  test_msg->apc[4].pcv[18] = -53;
  if (sizeof(test_msg->apc[4].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[4].pcv[0]));
  }
  test_msg->apc[4].pcv[19] = -28;
  if (sizeof(test_msg->apc[4].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[4].pcv[0]));
  }
  test_msg->apc[4].pcv[20] = 99;
  test_msg->apc[4].sat_info = 147;
  test_msg->apc[4].sid.code = 110;
  test_msg->apc[4].sid.sat = 249;
  test_msg->apc[4].svn = 41224;
  if (sizeof(test_msg->apc) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0]));
  }
  if (sizeof(test_msg->apc[5].pco) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[5].pco[0]));
  }
  test_msg->apc[5].pco[0] = -21881;
  if (sizeof(test_msg->apc[5].pco) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[5].pco[0]));
  }
  test_msg->apc[5].pco[1] = -9942;
  if (sizeof(test_msg->apc[5].pco) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[5].pco[0]));
  }
  test_msg->apc[5].pco[2] = -5689;
  if (sizeof(test_msg->apc[5].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[5].pcv[0]));
  }
  test_msg->apc[5].pcv[0] = 42;
  if (sizeof(test_msg->apc[5].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[5].pcv[0]));
  }
  test_msg->apc[5].pcv[1] = -86;
  if (sizeof(test_msg->apc[5].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[5].pcv[0]));
  }
  test_msg->apc[5].pcv[2] = 78;
  if (sizeof(test_msg->apc[5].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[5].pcv[0]));
  }
  test_msg->apc[5].pcv[3] = -50;
  if (sizeof(test_msg->apc[5].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[5].pcv[0]));
  }
  test_msg->apc[5].pcv[4] = 41;
  if (sizeof(test_msg->apc[5].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[5].pcv[0]));
  }
  test_msg->apc[5].pcv[5] = 43;
  if (sizeof(test_msg->apc[5].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[5].pcv[0]));
  }
  test_msg->apc[5].pcv[6] = 81;
  if (sizeof(test_msg->apc[5].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[5].pcv[0]));
  }
  test_msg->apc[5].pcv[7] = -9;
  if (sizeof(test_msg->apc[5].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[5].pcv[0]));
  }
  test_msg->apc[5].pcv[8] = 99;
  if (sizeof(test_msg->apc[5].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[5].pcv[0]));
  }
  test_msg->apc[5].pcv[9] = -58;
  if (sizeof(test_msg->apc[5].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[5].pcv[0]));
  }
  test_msg->apc[5].pcv[10] = -112;
  if (sizeof(test_msg->apc[5].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[5].pcv[0]));
  }
  test_msg->apc[5].pcv[11] = 2;
  if (sizeof(test_msg->apc[5].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[5].pcv[0]));
  }
  test_msg->apc[5].pcv[12] = -124;
  if (sizeof(test_msg->apc[5].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[5].pcv[0]));
  }
  test_msg->apc[5].pcv[13] = 2;
  if (sizeof(test_msg->apc[5].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[5].pcv[0]));
  }
  test_msg->apc[5].pcv[14] = -32;
  if (sizeof(test_msg->apc[5].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[5].pcv[0]));
  }
  test_msg->apc[5].pcv[15] = -36;
  if (sizeof(test_msg->apc[5].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[5].pcv[0]));
  }
  test_msg->apc[5].pcv[16] = -108;
  if (sizeof(test_msg->apc[5].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[5].pcv[0]));
  }
  test_msg->apc[5].pcv[17] = 58;
  if (sizeof(test_msg->apc[5].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[5].pcv[0]));
  }
  test_msg->apc[5].pcv[18] = 85;
  if (sizeof(test_msg->apc[5].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[5].pcv[0]));
  }
  test_msg->apc[5].pcv[19] = -118;
  if (sizeof(test_msg->apc[5].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[5].pcv[0]));
  }
  test_msg->apc[5].pcv[20] = -46;
  test_msg->apc[5].sat_info = 159;
  test_msg->apc[5].sid.code = 83;
  test_msg->apc[5].sid.sat = 45;
  test_msg->apc[5].svn = 64011;
  if (sizeof(test_msg->apc) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0]));
  }
  if (sizeof(test_msg->apc[6].pco) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[6].pco[0]));
  }
  test_msg->apc[6].pco[0] = -14290;
  if (sizeof(test_msg->apc[6].pco) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[6].pco[0]));
  }
  test_msg->apc[6].pco[1] = 30340;
  if (sizeof(test_msg->apc[6].pco) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[6].pco[0]));
  }
  test_msg->apc[6].pco[2] = 3569;
  if (sizeof(test_msg->apc[6].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[6].pcv[0]));
  }
  test_msg->apc[6].pcv[0] = 37;
  if (sizeof(test_msg->apc[6].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[6].pcv[0]));
  }
  test_msg->apc[6].pcv[1] = 62;
  if (sizeof(test_msg->apc[6].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[6].pcv[0]));
  }
  test_msg->apc[6].pcv[2] = 107;
  if (sizeof(test_msg->apc[6].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[6].pcv[0]));
  }
  test_msg->apc[6].pcv[3] = -3;
  if (sizeof(test_msg->apc[6].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[6].pcv[0]));
  }
  test_msg->apc[6].pcv[4] = -66;
  if (sizeof(test_msg->apc[6].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[6].pcv[0]));
  }
  test_msg->apc[6].pcv[5] = -120;
  if (sizeof(test_msg->apc[6].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[6].pcv[0]));
  }
  test_msg->apc[6].pcv[6] = 66;
  if (sizeof(test_msg->apc[6].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[6].pcv[0]));
  }
  test_msg->apc[6].pcv[7] = 9;
  if (sizeof(test_msg->apc[6].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[6].pcv[0]));
  }
  test_msg->apc[6].pcv[8] = 84;
  if (sizeof(test_msg->apc[6].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[6].pcv[0]));
  }
  test_msg->apc[6].pcv[9] = -101;
  if (sizeof(test_msg->apc[6].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[6].pcv[0]));
  }
  test_msg->apc[6].pcv[10] = 86;
  if (sizeof(test_msg->apc[6].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[6].pcv[0]));
  }
  test_msg->apc[6].pcv[11] = -76;
  if (sizeof(test_msg->apc[6].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[6].pcv[0]));
  }
  test_msg->apc[6].pcv[12] = 41;
  if (sizeof(test_msg->apc[6].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[6].pcv[0]));
  }
  test_msg->apc[6].pcv[13] = -60;
  if (sizeof(test_msg->apc[6].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[6].pcv[0]));
  }
  test_msg->apc[6].pcv[14] = 40;
  if (sizeof(test_msg->apc[6].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[6].pcv[0]));
  }
  test_msg->apc[6].pcv[15] = 119;
  if (sizeof(test_msg->apc[6].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[6].pcv[0]));
  }
  test_msg->apc[6].pcv[16] = 101;
  if (sizeof(test_msg->apc[6].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[6].pcv[0]));
  }
  test_msg->apc[6].pcv[17] = -4;
  if (sizeof(test_msg->apc[6].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[6].pcv[0]));
  }
  test_msg->apc[6].pcv[18] = -33;
  if (sizeof(test_msg->apc[6].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[6].pcv[0]));
  }
  test_msg->apc[6].pcv[19] = -112;
  if (sizeof(test_msg->apc[6].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[6].pcv[0]));
  }
  test_msg->apc[6].pcv[20] = -103;
  test_msg->apc[6].sat_info = 7;
  test_msg->apc[6].sid.code = 158;
  test_msg->apc[6].sid.sat = 200;
  test_msg->apc[6].svn = 17310;

  EXPECT_EQ(send_message(0x604, 4920, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 4920);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->apc[0].pco[0], -21547)
      << "incorrect value for apc[0].pco[0], expected -21547, is "
      << last_msg_->apc[0].pco[0];
  EXPECT_EQ(last_msg_->apc[0].pco[1], -10498)
      << "incorrect value for apc[0].pco[1], expected -10498, is "
      << last_msg_->apc[0].pco[1];
  EXPECT_EQ(last_msg_->apc[0].pco[2], 1236)
      << "incorrect value for apc[0].pco[2], expected 1236, is "
      << last_msg_->apc[0].pco[2];
  EXPECT_EQ(last_msg_->apc[0].pcv[0], 8)
      << "incorrect value for apc[0].pcv[0], expected 8, is "
      << last_msg_->apc[0].pcv[0];
  EXPECT_EQ(last_msg_->apc[0].pcv[1], 33)
      << "incorrect value for apc[0].pcv[1], expected 33, is "
      << last_msg_->apc[0].pcv[1];
  EXPECT_EQ(last_msg_->apc[0].pcv[2], 31)
      << "incorrect value for apc[0].pcv[2], expected 31, is "
      << last_msg_->apc[0].pcv[2];
  EXPECT_EQ(last_msg_->apc[0].pcv[3], 80)
      << "incorrect value for apc[0].pcv[3], expected 80, is "
      << last_msg_->apc[0].pcv[3];
  EXPECT_EQ(last_msg_->apc[0].pcv[4], 21)
      << "incorrect value for apc[0].pcv[4], expected 21, is "
      << last_msg_->apc[0].pcv[4];
  EXPECT_EQ(last_msg_->apc[0].pcv[5], 4)
      << "incorrect value for apc[0].pcv[5], expected 4, is "
      << last_msg_->apc[0].pcv[5];
  EXPECT_EQ(last_msg_->apc[0].pcv[6], 105)
      << "incorrect value for apc[0].pcv[6], expected 105, is "
      << last_msg_->apc[0].pcv[6];
  EXPECT_EQ(last_msg_->apc[0].pcv[7], -31)
      << "incorrect value for apc[0].pcv[7], expected -31, is "
      << last_msg_->apc[0].pcv[7];
  EXPECT_EQ(last_msg_->apc[0].pcv[8], 39)
      << "incorrect value for apc[0].pcv[8], expected 39, is "
      << last_msg_->apc[0].pcv[8];
  EXPECT_EQ(last_msg_->apc[0].pcv[9], -117)
      << "incorrect value for apc[0].pcv[9], expected -117, is "
      << last_msg_->apc[0].pcv[9];
  EXPECT_EQ(last_msg_->apc[0].pcv[10], 124)
      << "incorrect value for apc[0].pcv[10], expected 124, is "
      << last_msg_->apc[0].pcv[10];
  EXPECT_EQ(last_msg_->apc[0].pcv[11], -107)
      << "incorrect value for apc[0].pcv[11], expected -107, is "
      << last_msg_->apc[0].pcv[11];
  EXPECT_EQ(last_msg_->apc[0].pcv[12], 48)
      << "incorrect value for apc[0].pcv[12], expected 48, is "
      << last_msg_->apc[0].pcv[12];
  EXPECT_EQ(last_msg_->apc[0].pcv[13], 15)
      << "incorrect value for apc[0].pcv[13], expected 15, is "
      << last_msg_->apc[0].pcv[13];
  EXPECT_EQ(last_msg_->apc[0].pcv[14], -42)
      << "incorrect value for apc[0].pcv[14], expected -42, is "
      << last_msg_->apc[0].pcv[14];
  EXPECT_EQ(last_msg_->apc[0].pcv[15], -59)
      << "incorrect value for apc[0].pcv[15], expected -59, is "
      << last_msg_->apc[0].pcv[15];
  EXPECT_EQ(last_msg_->apc[0].pcv[16], -115)
      << "incorrect value for apc[0].pcv[16], expected -115, is "
      << last_msg_->apc[0].pcv[16];
  EXPECT_EQ(last_msg_->apc[0].pcv[17], 32)
      << "incorrect value for apc[0].pcv[17], expected 32, is "
      << last_msg_->apc[0].pcv[17];
  EXPECT_EQ(last_msg_->apc[0].pcv[18], 33)
      << "incorrect value for apc[0].pcv[18], expected 33, is "
      << last_msg_->apc[0].pcv[18];
  EXPECT_EQ(last_msg_->apc[0].pcv[19], -121)
      << "incorrect value for apc[0].pcv[19], expected -121, is "
      << last_msg_->apc[0].pcv[19];
  EXPECT_EQ(last_msg_->apc[0].pcv[20], -106)
      << "incorrect value for apc[0].pcv[20], expected -106, is "
      << last_msg_->apc[0].pcv[20];
  EXPECT_EQ(last_msg_->apc[0].sat_info, 240)
      << "incorrect value for apc[0].sat_info, expected 240, is "
      << last_msg_->apc[0].sat_info;
  EXPECT_EQ(last_msg_->apc[0].sid.code, 169)
      << "incorrect value for apc[0].sid.code, expected 169, is "
      << last_msg_->apc[0].sid.code;
  EXPECT_EQ(last_msg_->apc[0].sid.sat, 203)
      << "incorrect value for apc[0].sid.sat, expected 203, is "
      << last_msg_->apc[0].sid.sat;
  EXPECT_EQ(last_msg_->apc[0].svn, 1102)
      << "incorrect value for apc[0].svn, expected 1102, is "
      << last_msg_->apc[0].svn;
  EXPECT_EQ(last_msg_->apc[1].pco[0], 23079)
      << "incorrect value for apc[1].pco[0], expected 23079, is "
      << last_msg_->apc[1].pco[0];
  EXPECT_EQ(last_msg_->apc[1].pco[1], -22252)
      << "incorrect value for apc[1].pco[1], expected -22252, is "
      << last_msg_->apc[1].pco[1];
  EXPECT_EQ(last_msg_->apc[1].pco[2], 12271)
      << "incorrect value for apc[1].pco[2], expected 12271, is "
      << last_msg_->apc[1].pco[2];
  EXPECT_EQ(last_msg_->apc[1].pcv[0], -103)
      << "incorrect value for apc[1].pcv[0], expected -103, is "
      << last_msg_->apc[1].pcv[0];
  EXPECT_EQ(last_msg_->apc[1].pcv[1], -81)
      << "incorrect value for apc[1].pcv[1], expected -81, is "
      << last_msg_->apc[1].pcv[1];
  EXPECT_EQ(last_msg_->apc[1].pcv[2], 35)
      << "incorrect value for apc[1].pcv[2], expected 35, is "
      << last_msg_->apc[1].pcv[2];
  EXPECT_EQ(last_msg_->apc[1].pcv[3], -111)
      << "incorrect value for apc[1].pcv[3], expected -111, is "
      << last_msg_->apc[1].pcv[3];
  EXPECT_EQ(last_msg_->apc[1].pcv[4], -111)
      << "incorrect value for apc[1].pcv[4], expected -111, is "
      << last_msg_->apc[1].pcv[4];
  EXPECT_EQ(last_msg_->apc[1].pcv[5], 123)
      << "incorrect value for apc[1].pcv[5], expected 123, is "
      << last_msg_->apc[1].pcv[5];
  EXPECT_EQ(last_msg_->apc[1].pcv[6], -62)
      << "incorrect value for apc[1].pcv[6], expected -62, is "
      << last_msg_->apc[1].pcv[6];
  EXPECT_EQ(last_msg_->apc[1].pcv[7], 2)
      << "incorrect value for apc[1].pcv[7], expected 2, is "
      << last_msg_->apc[1].pcv[7];
  EXPECT_EQ(last_msg_->apc[1].pcv[8], 102)
      << "incorrect value for apc[1].pcv[8], expected 102, is "
      << last_msg_->apc[1].pcv[8];
  EXPECT_EQ(last_msg_->apc[1].pcv[9], 74)
      << "incorrect value for apc[1].pcv[9], expected 74, is "
      << last_msg_->apc[1].pcv[9];
  EXPECT_EQ(last_msg_->apc[1].pcv[10], -107)
      << "incorrect value for apc[1].pcv[10], expected -107, is "
      << last_msg_->apc[1].pcv[10];
  EXPECT_EQ(last_msg_->apc[1].pcv[11], 95)
      << "incorrect value for apc[1].pcv[11], expected 95, is "
      << last_msg_->apc[1].pcv[11];
  EXPECT_EQ(last_msg_->apc[1].pcv[12], -85)
      << "incorrect value for apc[1].pcv[12], expected -85, is "
      << last_msg_->apc[1].pcv[12];
  EXPECT_EQ(last_msg_->apc[1].pcv[13], -18)
      << "incorrect value for apc[1].pcv[13], expected -18, is "
      << last_msg_->apc[1].pcv[13];
  EXPECT_EQ(last_msg_->apc[1].pcv[14], -7)
      << "incorrect value for apc[1].pcv[14], expected -7, is "
      << last_msg_->apc[1].pcv[14];
  EXPECT_EQ(last_msg_->apc[1].pcv[15], 7)
      << "incorrect value for apc[1].pcv[15], expected 7, is "
      << last_msg_->apc[1].pcv[15];
  EXPECT_EQ(last_msg_->apc[1].pcv[16], -19)
      << "incorrect value for apc[1].pcv[16], expected -19, is "
      << last_msg_->apc[1].pcv[16];
  EXPECT_EQ(last_msg_->apc[1].pcv[17], -86)
      << "incorrect value for apc[1].pcv[17], expected -86, is "
      << last_msg_->apc[1].pcv[17];
  EXPECT_EQ(last_msg_->apc[1].pcv[18], 125)
      << "incorrect value for apc[1].pcv[18], expected 125, is "
      << last_msg_->apc[1].pcv[18];
  EXPECT_EQ(last_msg_->apc[1].pcv[19], 106)
      << "incorrect value for apc[1].pcv[19], expected 106, is "
      << last_msg_->apc[1].pcv[19];
  EXPECT_EQ(last_msg_->apc[1].pcv[20], -98)
      << "incorrect value for apc[1].pcv[20], expected -98, is "
      << last_msg_->apc[1].pcv[20];
  EXPECT_EQ(last_msg_->apc[1].sat_info, 49)
      << "incorrect value for apc[1].sat_info, expected 49, is "
      << last_msg_->apc[1].sat_info;
  EXPECT_EQ(last_msg_->apc[1].sid.code, 123)
      << "incorrect value for apc[1].sid.code, expected 123, is "
      << last_msg_->apc[1].sid.code;
  EXPECT_EQ(last_msg_->apc[1].sid.sat, 148)
      << "incorrect value for apc[1].sid.sat, expected 148, is "
      << last_msg_->apc[1].sid.sat;
  EXPECT_EQ(last_msg_->apc[1].svn, 24967)
      << "incorrect value for apc[1].svn, expected 24967, is "
      << last_msg_->apc[1].svn;
  EXPECT_EQ(last_msg_->apc[2].pco[0], -7596)
      << "incorrect value for apc[2].pco[0], expected -7596, is "
      << last_msg_->apc[2].pco[0];
  EXPECT_EQ(last_msg_->apc[2].pco[1], 31630)
      << "incorrect value for apc[2].pco[1], expected 31630, is "
      << last_msg_->apc[2].pco[1];
  EXPECT_EQ(last_msg_->apc[2].pco[2], -9907)
      << "incorrect value for apc[2].pco[2], expected -9907, is "
      << last_msg_->apc[2].pco[2];
  EXPECT_EQ(last_msg_->apc[2].pcv[0], -8)
      << "incorrect value for apc[2].pcv[0], expected -8, is "
      << last_msg_->apc[2].pcv[0];
  EXPECT_EQ(last_msg_->apc[2].pcv[1], 67)
      << "incorrect value for apc[2].pcv[1], expected 67, is "
      << last_msg_->apc[2].pcv[1];
  EXPECT_EQ(last_msg_->apc[2].pcv[2], -41)
      << "incorrect value for apc[2].pcv[2], expected -41, is "
      << last_msg_->apc[2].pcv[2];
  EXPECT_EQ(last_msg_->apc[2].pcv[3], -127)
      << "incorrect value for apc[2].pcv[3], expected -127, is "
      << last_msg_->apc[2].pcv[3];
  EXPECT_EQ(last_msg_->apc[2].pcv[4], 114)
      << "incorrect value for apc[2].pcv[4], expected 114, is "
      << last_msg_->apc[2].pcv[4];
  EXPECT_EQ(last_msg_->apc[2].pcv[5], -118)
      << "incorrect value for apc[2].pcv[5], expected -118, is "
      << last_msg_->apc[2].pcv[5];
  EXPECT_EQ(last_msg_->apc[2].pcv[6], 25)
      << "incorrect value for apc[2].pcv[6], expected 25, is "
      << last_msg_->apc[2].pcv[6];
  EXPECT_EQ(last_msg_->apc[2].pcv[7], -16)
      << "incorrect value for apc[2].pcv[7], expected -16, is "
      << last_msg_->apc[2].pcv[7];
  EXPECT_EQ(last_msg_->apc[2].pcv[8], 10)
      << "incorrect value for apc[2].pcv[8], expected 10, is "
      << last_msg_->apc[2].pcv[8];
  EXPECT_EQ(last_msg_->apc[2].pcv[9], 56)
      << "incorrect value for apc[2].pcv[9], expected 56, is "
      << last_msg_->apc[2].pcv[9];
  EXPECT_EQ(last_msg_->apc[2].pcv[10], 76)
      << "incorrect value for apc[2].pcv[10], expected 76, is "
      << last_msg_->apc[2].pcv[10];
  EXPECT_EQ(last_msg_->apc[2].pcv[11], 61)
      << "incorrect value for apc[2].pcv[11], expected 61, is "
      << last_msg_->apc[2].pcv[11];
  EXPECT_EQ(last_msg_->apc[2].pcv[12], -95)
      << "incorrect value for apc[2].pcv[12], expected -95, is "
      << last_msg_->apc[2].pcv[12];
  EXPECT_EQ(last_msg_->apc[2].pcv[13], -40)
      << "incorrect value for apc[2].pcv[13], expected -40, is "
      << last_msg_->apc[2].pcv[13];
  EXPECT_EQ(last_msg_->apc[2].pcv[14], 22)
      << "incorrect value for apc[2].pcv[14], expected 22, is "
      << last_msg_->apc[2].pcv[14];
  EXPECT_EQ(last_msg_->apc[2].pcv[15], -75)
      << "incorrect value for apc[2].pcv[15], expected -75, is "
      << last_msg_->apc[2].pcv[15];
  EXPECT_EQ(last_msg_->apc[2].pcv[16], -82)
      << "incorrect value for apc[2].pcv[16], expected -82, is "
      << last_msg_->apc[2].pcv[16];
  EXPECT_EQ(last_msg_->apc[2].pcv[17], 33)
      << "incorrect value for apc[2].pcv[17], expected 33, is "
      << last_msg_->apc[2].pcv[17];
  EXPECT_EQ(last_msg_->apc[2].pcv[18], 13)
      << "incorrect value for apc[2].pcv[18], expected 13, is "
      << last_msg_->apc[2].pcv[18];
  EXPECT_EQ(last_msg_->apc[2].pcv[19], -4)
      << "incorrect value for apc[2].pcv[19], expected -4, is "
      << last_msg_->apc[2].pcv[19];
  EXPECT_EQ(last_msg_->apc[2].pcv[20], -20)
      << "incorrect value for apc[2].pcv[20], expected -20, is "
      << last_msg_->apc[2].pcv[20];
  EXPECT_EQ(last_msg_->apc[2].sat_info, 181)
      << "incorrect value for apc[2].sat_info, expected 181, is "
      << last_msg_->apc[2].sat_info;
  EXPECT_EQ(last_msg_->apc[2].sid.code, 188)
      << "incorrect value for apc[2].sid.code, expected 188, is "
      << last_msg_->apc[2].sid.code;
  EXPECT_EQ(last_msg_->apc[2].sid.sat, 83)
      << "incorrect value for apc[2].sid.sat, expected 83, is "
      << last_msg_->apc[2].sid.sat;
  EXPECT_EQ(last_msg_->apc[2].svn, 7106)
      << "incorrect value for apc[2].svn, expected 7106, is "
      << last_msg_->apc[2].svn;
  EXPECT_EQ(last_msg_->apc[3].pco[0], -19478)
      << "incorrect value for apc[3].pco[0], expected -19478, is "
      << last_msg_->apc[3].pco[0];
  EXPECT_EQ(last_msg_->apc[3].pco[1], 11484)
      << "incorrect value for apc[3].pco[1], expected 11484, is "
      << last_msg_->apc[3].pco[1];
  EXPECT_EQ(last_msg_->apc[3].pco[2], 14804)
      << "incorrect value for apc[3].pco[2], expected 14804, is "
      << last_msg_->apc[3].pco[2];
  EXPECT_EQ(last_msg_->apc[3].pcv[0], 44)
      << "incorrect value for apc[3].pcv[0], expected 44, is "
      << last_msg_->apc[3].pcv[0];
  EXPECT_EQ(last_msg_->apc[3].pcv[1], -83)
      << "incorrect value for apc[3].pcv[1], expected -83, is "
      << last_msg_->apc[3].pcv[1];
  EXPECT_EQ(last_msg_->apc[3].pcv[2], 49)
      << "incorrect value for apc[3].pcv[2], expected 49, is "
      << last_msg_->apc[3].pcv[2];
  EXPECT_EQ(last_msg_->apc[3].pcv[3], 36)
      << "incorrect value for apc[3].pcv[3], expected 36, is "
      << last_msg_->apc[3].pcv[3];
  EXPECT_EQ(last_msg_->apc[3].pcv[4], -119)
      << "incorrect value for apc[3].pcv[4], expected -119, is "
      << last_msg_->apc[3].pcv[4];
  EXPECT_EQ(last_msg_->apc[3].pcv[5], -8)
      << "incorrect value for apc[3].pcv[5], expected -8, is "
      << last_msg_->apc[3].pcv[5];
  EXPECT_EQ(last_msg_->apc[3].pcv[6], -21)
      << "incorrect value for apc[3].pcv[6], expected -21, is "
      << last_msg_->apc[3].pcv[6];
  EXPECT_EQ(last_msg_->apc[3].pcv[7], 97)
      << "incorrect value for apc[3].pcv[7], expected 97, is "
      << last_msg_->apc[3].pcv[7];
  EXPECT_EQ(last_msg_->apc[3].pcv[8], 112)
      << "incorrect value for apc[3].pcv[8], expected 112, is "
      << last_msg_->apc[3].pcv[8];
  EXPECT_EQ(last_msg_->apc[3].pcv[9], -99)
      << "incorrect value for apc[3].pcv[9], expected -99, is "
      << last_msg_->apc[3].pcv[9];
  EXPECT_EQ(last_msg_->apc[3].pcv[10], -117)
      << "incorrect value for apc[3].pcv[10], expected -117, is "
      << last_msg_->apc[3].pcv[10];
  EXPECT_EQ(last_msg_->apc[3].pcv[11], 26)
      << "incorrect value for apc[3].pcv[11], expected 26, is "
      << last_msg_->apc[3].pcv[11];
  EXPECT_EQ(last_msg_->apc[3].pcv[12], 115)
      << "incorrect value for apc[3].pcv[12], expected 115, is "
      << last_msg_->apc[3].pcv[12];
  EXPECT_EQ(last_msg_->apc[3].pcv[13], -64)
      << "incorrect value for apc[3].pcv[13], expected -64, is "
      << last_msg_->apc[3].pcv[13];
  EXPECT_EQ(last_msg_->apc[3].pcv[14], 31)
      << "incorrect value for apc[3].pcv[14], expected 31, is "
      << last_msg_->apc[3].pcv[14];
  EXPECT_EQ(last_msg_->apc[3].pcv[15], 85)
      << "incorrect value for apc[3].pcv[15], expected 85, is "
      << last_msg_->apc[3].pcv[15];
  EXPECT_EQ(last_msg_->apc[3].pcv[16], 127)
      << "incorrect value for apc[3].pcv[16], expected 127, is "
      << last_msg_->apc[3].pcv[16];
  EXPECT_EQ(last_msg_->apc[3].pcv[17], -28)
      << "incorrect value for apc[3].pcv[17], expected -28, is "
      << last_msg_->apc[3].pcv[17];
  EXPECT_EQ(last_msg_->apc[3].pcv[18], 81)
      << "incorrect value for apc[3].pcv[18], expected 81, is "
      << last_msg_->apc[3].pcv[18];
  EXPECT_EQ(last_msg_->apc[3].pcv[19], -4)
      << "incorrect value for apc[3].pcv[19], expected -4, is "
      << last_msg_->apc[3].pcv[19];
  EXPECT_EQ(last_msg_->apc[3].pcv[20], -37)
      << "incorrect value for apc[3].pcv[20], expected -37, is "
      << last_msg_->apc[3].pcv[20];
  EXPECT_EQ(last_msg_->apc[3].sat_info, 128)
      << "incorrect value for apc[3].sat_info, expected 128, is "
      << last_msg_->apc[3].sat_info;
  EXPECT_EQ(last_msg_->apc[3].sid.code, 196)
      << "incorrect value for apc[3].sid.code, expected 196, is "
      << last_msg_->apc[3].sid.code;
  EXPECT_EQ(last_msg_->apc[3].sid.sat, 230)
      << "incorrect value for apc[3].sid.sat, expected 230, is "
      << last_msg_->apc[3].sid.sat;
  EXPECT_EQ(last_msg_->apc[3].svn, 61399)
      << "incorrect value for apc[3].svn, expected 61399, is "
      << last_msg_->apc[3].svn;
  EXPECT_EQ(last_msg_->apc[4].pco[0], -11049)
      << "incorrect value for apc[4].pco[0], expected -11049, is "
      << last_msg_->apc[4].pco[0];
  EXPECT_EQ(last_msg_->apc[4].pco[1], 6580)
      << "incorrect value for apc[4].pco[1], expected 6580, is "
      << last_msg_->apc[4].pco[1];
  EXPECT_EQ(last_msg_->apc[4].pco[2], -28589)
      << "incorrect value for apc[4].pco[2], expected -28589, is "
      << last_msg_->apc[4].pco[2];
  EXPECT_EQ(last_msg_->apc[4].pcv[0], -9)
      << "incorrect value for apc[4].pcv[0], expected -9, is "
      << last_msg_->apc[4].pcv[0];
  EXPECT_EQ(last_msg_->apc[4].pcv[1], 12)
      << "incorrect value for apc[4].pcv[1], expected 12, is "
      << last_msg_->apc[4].pcv[1];
  EXPECT_EQ(last_msg_->apc[4].pcv[2], 27)
      << "incorrect value for apc[4].pcv[2], expected 27, is "
      << last_msg_->apc[4].pcv[2];
  EXPECT_EQ(last_msg_->apc[4].pcv[3], -57)
      << "incorrect value for apc[4].pcv[3], expected -57, is "
      << last_msg_->apc[4].pcv[3];
  EXPECT_EQ(last_msg_->apc[4].pcv[4], -83)
      << "incorrect value for apc[4].pcv[4], expected -83, is "
      << last_msg_->apc[4].pcv[4];
  EXPECT_EQ(last_msg_->apc[4].pcv[5], 74)
      << "incorrect value for apc[4].pcv[5], expected 74, is "
      << last_msg_->apc[4].pcv[5];
  EXPECT_EQ(last_msg_->apc[4].pcv[6], 23)
      << "incorrect value for apc[4].pcv[6], expected 23, is "
      << last_msg_->apc[4].pcv[6];
  EXPECT_EQ(last_msg_->apc[4].pcv[7], 4)
      << "incorrect value for apc[4].pcv[7], expected 4, is "
      << last_msg_->apc[4].pcv[7];
  EXPECT_EQ(last_msg_->apc[4].pcv[8], -17)
      << "incorrect value for apc[4].pcv[8], expected -17, is "
      << last_msg_->apc[4].pcv[8];
  EXPECT_EQ(last_msg_->apc[4].pcv[9], 103)
      << "incorrect value for apc[4].pcv[9], expected 103, is "
      << last_msg_->apc[4].pcv[9];
  EXPECT_EQ(last_msg_->apc[4].pcv[10], -33)
      << "incorrect value for apc[4].pcv[10], expected -33, is "
      << last_msg_->apc[4].pcv[10];
  EXPECT_EQ(last_msg_->apc[4].pcv[11], -36)
      << "incorrect value for apc[4].pcv[11], expected -36, is "
      << last_msg_->apc[4].pcv[11];
  EXPECT_EQ(last_msg_->apc[4].pcv[12], -117)
      << "incorrect value for apc[4].pcv[12], expected -117, is "
      << last_msg_->apc[4].pcv[12];
  EXPECT_EQ(last_msg_->apc[4].pcv[13], 91)
      << "incorrect value for apc[4].pcv[13], expected 91, is "
      << last_msg_->apc[4].pcv[13];
  EXPECT_EQ(last_msg_->apc[4].pcv[14], 127)
      << "incorrect value for apc[4].pcv[14], expected 127, is "
      << last_msg_->apc[4].pcv[14];
  EXPECT_EQ(last_msg_->apc[4].pcv[15], -42)
      << "incorrect value for apc[4].pcv[15], expected -42, is "
      << last_msg_->apc[4].pcv[15];
  EXPECT_EQ(last_msg_->apc[4].pcv[16], 86)
      << "incorrect value for apc[4].pcv[16], expected 86, is "
      << last_msg_->apc[4].pcv[16];
  EXPECT_EQ(last_msg_->apc[4].pcv[17], 48)
      << "incorrect value for apc[4].pcv[17], expected 48, is "
      << last_msg_->apc[4].pcv[17];
  EXPECT_EQ(last_msg_->apc[4].pcv[18], -53)
      << "incorrect value for apc[4].pcv[18], expected -53, is "
      << last_msg_->apc[4].pcv[18];
  EXPECT_EQ(last_msg_->apc[4].pcv[19], -28)
      << "incorrect value for apc[4].pcv[19], expected -28, is "
      << last_msg_->apc[4].pcv[19];
  EXPECT_EQ(last_msg_->apc[4].pcv[20], 99)
      << "incorrect value for apc[4].pcv[20], expected 99, is "
      << last_msg_->apc[4].pcv[20];
  EXPECT_EQ(last_msg_->apc[4].sat_info, 147)
      << "incorrect value for apc[4].sat_info, expected 147, is "
      << last_msg_->apc[4].sat_info;
  EXPECT_EQ(last_msg_->apc[4].sid.code, 110)
      << "incorrect value for apc[4].sid.code, expected 110, is "
      << last_msg_->apc[4].sid.code;
  EXPECT_EQ(last_msg_->apc[4].sid.sat, 249)
      << "incorrect value for apc[4].sid.sat, expected 249, is "
      << last_msg_->apc[4].sid.sat;
  EXPECT_EQ(last_msg_->apc[4].svn, 41224)
      << "incorrect value for apc[4].svn, expected 41224, is "
      << last_msg_->apc[4].svn;
  EXPECT_EQ(last_msg_->apc[5].pco[0], -21881)
      << "incorrect value for apc[5].pco[0], expected -21881, is "
      << last_msg_->apc[5].pco[0];
  EXPECT_EQ(last_msg_->apc[5].pco[1], -9942)
      << "incorrect value for apc[5].pco[1], expected -9942, is "
      << last_msg_->apc[5].pco[1];
  EXPECT_EQ(last_msg_->apc[5].pco[2], -5689)
      << "incorrect value for apc[5].pco[2], expected -5689, is "
      << last_msg_->apc[5].pco[2];
  EXPECT_EQ(last_msg_->apc[5].pcv[0], 42)
      << "incorrect value for apc[5].pcv[0], expected 42, is "
      << last_msg_->apc[5].pcv[0];
  EXPECT_EQ(last_msg_->apc[5].pcv[1], -86)
      << "incorrect value for apc[5].pcv[1], expected -86, is "
      << last_msg_->apc[5].pcv[1];
  EXPECT_EQ(last_msg_->apc[5].pcv[2], 78)
      << "incorrect value for apc[5].pcv[2], expected 78, is "
      << last_msg_->apc[5].pcv[2];
  EXPECT_EQ(last_msg_->apc[5].pcv[3], -50)
      << "incorrect value for apc[5].pcv[3], expected -50, is "
      << last_msg_->apc[5].pcv[3];
  EXPECT_EQ(last_msg_->apc[5].pcv[4], 41)
      << "incorrect value for apc[5].pcv[4], expected 41, is "
      << last_msg_->apc[5].pcv[4];
  EXPECT_EQ(last_msg_->apc[5].pcv[5], 43)
      << "incorrect value for apc[5].pcv[5], expected 43, is "
      << last_msg_->apc[5].pcv[5];
  EXPECT_EQ(last_msg_->apc[5].pcv[6], 81)
      << "incorrect value for apc[5].pcv[6], expected 81, is "
      << last_msg_->apc[5].pcv[6];
  EXPECT_EQ(last_msg_->apc[5].pcv[7], -9)
      << "incorrect value for apc[5].pcv[7], expected -9, is "
      << last_msg_->apc[5].pcv[7];
  EXPECT_EQ(last_msg_->apc[5].pcv[8], 99)
      << "incorrect value for apc[5].pcv[8], expected 99, is "
      << last_msg_->apc[5].pcv[8];
  EXPECT_EQ(last_msg_->apc[5].pcv[9], -58)
      << "incorrect value for apc[5].pcv[9], expected -58, is "
      << last_msg_->apc[5].pcv[9];
  EXPECT_EQ(last_msg_->apc[5].pcv[10], -112)
      << "incorrect value for apc[5].pcv[10], expected -112, is "
      << last_msg_->apc[5].pcv[10];
  EXPECT_EQ(last_msg_->apc[5].pcv[11], 2)
      << "incorrect value for apc[5].pcv[11], expected 2, is "
      << last_msg_->apc[5].pcv[11];
  EXPECT_EQ(last_msg_->apc[5].pcv[12], -124)
      << "incorrect value for apc[5].pcv[12], expected -124, is "
      << last_msg_->apc[5].pcv[12];
  EXPECT_EQ(last_msg_->apc[5].pcv[13], 2)
      << "incorrect value for apc[5].pcv[13], expected 2, is "
      << last_msg_->apc[5].pcv[13];
  EXPECT_EQ(last_msg_->apc[5].pcv[14], -32)
      << "incorrect value for apc[5].pcv[14], expected -32, is "
      << last_msg_->apc[5].pcv[14];
  EXPECT_EQ(last_msg_->apc[5].pcv[15], -36)
      << "incorrect value for apc[5].pcv[15], expected -36, is "
      << last_msg_->apc[5].pcv[15];
  EXPECT_EQ(last_msg_->apc[5].pcv[16], -108)
      << "incorrect value for apc[5].pcv[16], expected -108, is "
      << last_msg_->apc[5].pcv[16];
  EXPECT_EQ(last_msg_->apc[5].pcv[17], 58)
      << "incorrect value for apc[5].pcv[17], expected 58, is "
      << last_msg_->apc[5].pcv[17];
  EXPECT_EQ(last_msg_->apc[5].pcv[18], 85)
      << "incorrect value for apc[5].pcv[18], expected 85, is "
      << last_msg_->apc[5].pcv[18];
  EXPECT_EQ(last_msg_->apc[5].pcv[19], -118)
      << "incorrect value for apc[5].pcv[19], expected -118, is "
      << last_msg_->apc[5].pcv[19];
  EXPECT_EQ(last_msg_->apc[5].pcv[20], -46)
      << "incorrect value for apc[5].pcv[20], expected -46, is "
      << last_msg_->apc[5].pcv[20];
  EXPECT_EQ(last_msg_->apc[5].sat_info, 159)
      << "incorrect value for apc[5].sat_info, expected 159, is "
      << last_msg_->apc[5].sat_info;
  EXPECT_EQ(last_msg_->apc[5].sid.code, 83)
      << "incorrect value for apc[5].sid.code, expected 83, is "
      << last_msg_->apc[5].sid.code;
  EXPECT_EQ(last_msg_->apc[5].sid.sat, 45)
      << "incorrect value for apc[5].sid.sat, expected 45, is "
      << last_msg_->apc[5].sid.sat;
  EXPECT_EQ(last_msg_->apc[5].svn, 64011)
      << "incorrect value for apc[5].svn, expected 64011, is "
      << last_msg_->apc[5].svn;
  EXPECT_EQ(last_msg_->apc[6].pco[0], -14290)
      << "incorrect value for apc[6].pco[0], expected -14290, is "
      << last_msg_->apc[6].pco[0];
  EXPECT_EQ(last_msg_->apc[6].pco[1], 30340)
      << "incorrect value for apc[6].pco[1], expected 30340, is "
      << last_msg_->apc[6].pco[1];
  EXPECT_EQ(last_msg_->apc[6].pco[2], 3569)
      << "incorrect value for apc[6].pco[2], expected 3569, is "
      << last_msg_->apc[6].pco[2];
  EXPECT_EQ(last_msg_->apc[6].pcv[0], 37)
      << "incorrect value for apc[6].pcv[0], expected 37, is "
      << last_msg_->apc[6].pcv[0];
  EXPECT_EQ(last_msg_->apc[6].pcv[1], 62)
      << "incorrect value for apc[6].pcv[1], expected 62, is "
      << last_msg_->apc[6].pcv[1];
  EXPECT_EQ(last_msg_->apc[6].pcv[2], 107)
      << "incorrect value for apc[6].pcv[2], expected 107, is "
      << last_msg_->apc[6].pcv[2];
  EXPECT_EQ(last_msg_->apc[6].pcv[3], -3)
      << "incorrect value for apc[6].pcv[3], expected -3, is "
      << last_msg_->apc[6].pcv[3];
  EXPECT_EQ(last_msg_->apc[6].pcv[4], -66)
      << "incorrect value for apc[6].pcv[4], expected -66, is "
      << last_msg_->apc[6].pcv[4];
  EXPECT_EQ(last_msg_->apc[6].pcv[5], -120)
      << "incorrect value for apc[6].pcv[5], expected -120, is "
      << last_msg_->apc[6].pcv[5];
  EXPECT_EQ(last_msg_->apc[6].pcv[6], 66)
      << "incorrect value for apc[6].pcv[6], expected 66, is "
      << last_msg_->apc[6].pcv[6];
  EXPECT_EQ(last_msg_->apc[6].pcv[7], 9)
      << "incorrect value for apc[6].pcv[7], expected 9, is "
      << last_msg_->apc[6].pcv[7];
  EXPECT_EQ(last_msg_->apc[6].pcv[8], 84)
      << "incorrect value for apc[6].pcv[8], expected 84, is "
      << last_msg_->apc[6].pcv[8];
  EXPECT_EQ(last_msg_->apc[6].pcv[9], -101)
      << "incorrect value for apc[6].pcv[9], expected -101, is "
      << last_msg_->apc[6].pcv[9];
  EXPECT_EQ(last_msg_->apc[6].pcv[10], 86)
      << "incorrect value for apc[6].pcv[10], expected 86, is "
      << last_msg_->apc[6].pcv[10];
  EXPECT_EQ(last_msg_->apc[6].pcv[11], -76)
      << "incorrect value for apc[6].pcv[11], expected -76, is "
      << last_msg_->apc[6].pcv[11];
  EXPECT_EQ(last_msg_->apc[6].pcv[12], 41)
      << "incorrect value for apc[6].pcv[12], expected 41, is "
      << last_msg_->apc[6].pcv[12];
  EXPECT_EQ(last_msg_->apc[6].pcv[13], -60)
      << "incorrect value for apc[6].pcv[13], expected -60, is "
      << last_msg_->apc[6].pcv[13];
  EXPECT_EQ(last_msg_->apc[6].pcv[14], 40)
      << "incorrect value for apc[6].pcv[14], expected 40, is "
      << last_msg_->apc[6].pcv[14];
  EXPECT_EQ(last_msg_->apc[6].pcv[15], 119)
      << "incorrect value for apc[6].pcv[15], expected 119, is "
      << last_msg_->apc[6].pcv[15];
  EXPECT_EQ(last_msg_->apc[6].pcv[16], 101)
      << "incorrect value for apc[6].pcv[16], expected 101, is "
      << last_msg_->apc[6].pcv[16];
  EXPECT_EQ(last_msg_->apc[6].pcv[17], -4)
      << "incorrect value for apc[6].pcv[17], expected -4, is "
      << last_msg_->apc[6].pcv[17];
  EXPECT_EQ(last_msg_->apc[6].pcv[18], -33)
      << "incorrect value for apc[6].pcv[18], expected -33, is "
      << last_msg_->apc[6].pcv[18];
  EXPECT_EQ(last_msg_->apc[6].pcv[19], -112)
      << "incorrect value for apc[6].pcv[19], expected -112, is "
      << last_msg_->apc[6].pcv[19];
  EXPECT_EQ(last_msg_->apc[6].pcv[20], -103)
      << "incorrect value for apc[6].pcv[20], expected -103, is "
      << last_msg_->apc[6].pcv[20];
  EXPECT_EQ(last_msg_->apc[6].sat_info, 7)
      << "incorrect value for apc[6].sat_info, expected 7, is "
      << last_msg_->apc[6].sat_info;
  EXPECT_EQ(last_msg_->apc[6].sid.code, 158)
      << "incorrect value for apc[6].sid.code, expected 158, is "
      << last_msg_->apc[6].sid.code;
  EXPECT_EQ(last_msg_->apc[6].sid.sat, 200)
      << "incorrect value for apc[6].sid.sat, expected 200, is "
      << last_msg_->apc[6].sid.sat;
  EXPECT_EQ(last_msg_->apc[6].svn, 17310)
      << "incorrect value for apc[6].svn, expected 17310, is "
      << last_msg_->apc[6].svn;
}
