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
// spec/tests/yaml/swiftnav/sbp/soln_meta/test_MsgSolnMetaDepA.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>

#include <libsbp/common.h>

// Obviously we don't normally want to silence this message, but we also need to
// still test the legacy implementation for as long as it exists. By silencing
// these messages here we can get a less noisy build in libsbp
#ifdef SBP_MESSAGE
#undef SBP_MESSAGE
#define SBP_MESSAGE(x)
#endif
#include <libsbp/legacy/cpp/legacy_state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
#include <libsbp/legacy/solution_meta.h>

template <typename T, typename U = std::remove_reference_t<T>>
U get_as(const uint8_t *buf) {
  U v;
  memcpy(&v, buf, sizeof(T));
  return v;
}
class Test_legacy_auto_check_sbp_solution_meta_MsgSolnMetaDepA0
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_soln_meta_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_solution_meta_MsgSolnMetaDepA0()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_soln_meta_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_soln_meta_dep_a_t *>(last_msg_storage_)),
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
                      const msg_soln_meta_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_soln_meta_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_solution_meta_MsgSolnMetaDepA0, Test) {
  uint8_t encoded_frame[] = {
      85,  15,  255, 84,  241, 254, 183, 222, 157, 121, 5,   164, 238, 31,  190,
      115, 93,  59,  103, 36,  83,  161, 156, 46,  253, 67,  87,  200, 39,  250,
      245, 242, 228, 72,  18,  222, 11,  88,  207, 218, 231, 13,  226, 224, 22,
      196, 21,  242, 12,  89,  71,  219, 182, 85,  145, 204, 146, 40,  204, 51,
      21,  153, 227, 44,  15,  28,  255, 39,  205, 216, 240, 190, 93,  219, 103,
      42,  41,  182, 76,  222, 17,  23,  125, 31,  18,  229, 28,  47,  214, 25,
      100, 84,  106, 72,  48,  10,  222, 232, 235, 73,  109, 163, 51,  152, 133,
      235, 87,  70,  2,   108, 91,  101, 200, 55,  24,  156, 233, 73,  39,  66,
      97,  140, 252, 227, 230, 237, 135, 241, 245, 205, 70,  0,   219, 188, 107,
      136, 178, 58,  1,   29,  44,  213, 225, 147, 190, 96,  192, 108, 228, 15,
      203, 18,  3,   222, 180, 68,  101, 229, 223, 203, 243, 164, 92,  165, 220,
      159, 174, 121, 112, 167, 240, 40,  59,  3,   230, 52,  149, 148, 218, 142,
      212, 109, 176, 71,  179, 172, 77,  1,   193, 70,  147, 149, 23,  144, 148,
      239, 195, 186, 86,  30,  34,  143, 156, 207, 63,  55,  117, 255, 222, 222,
      219, 145, 224, 191, 210, 109, 86,  153, 21,  32,  226, 10,  60,  63,  106,
      236, 93,  96,  30,  163, 106, 238, 147, 133, 132, 107, 152, 214, 221, 185,
      202, 21,  252, 51,  130, 59,  166, 202, 127, 170, 58,  193, 215, 125, 22,
      58,  135, 47,  88,  142, 77,  211,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_soln_meta_dep_a_t *test_msg = (msg_soln_meta_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->age_corrections = 48671;
  test_msg->alignment_status = 115;
  test_msg->hdop = 31133;
  test_msg->last_used_gnss_pos_tow = 610745181;
  test_msg->last_used_gnss_vel_tow = 782016851;
  test_msg->n_sats = 238;
  test_msg->pdop = 57015;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[0].flags = 67;
  test_msg->sol_in[0].sensor_type = 253;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[1].flags = 200;
  test_msg->sol_in[1].sensor_type = 87;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[2].flags = 250;
  test_msg->sol_in[2].sensor_type = 39;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[3].flags = 242;
  test_msg->sol_in[3].sensor_type = 245;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[4].flags = 72;
  test_msg->sol_in[4].sensor_type = 228;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[5].flags = 222;
  test_msg->sol_in[5].sensor_type = 18;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[6].flags = 88;
  test_msg->sol_in[6].sensor_type = 11;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[7].flags = 218;
  test_msg->sol_in[7].sensor_type = 207;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[8].flags = 13;
  test_msg->sol_in[8].sensor_type = 231;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[9].flags = 224;
  test_msg->sol_in[9].sensor_type = 226;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[10].flags = 196;
  test_msg->sol_in[10].sensor_type = 22;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[11].flags = 242;
  test_msg->sol_in[11].sensor_type = 21;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[12].flags = 89;
  test_msg->sol_in[12].sensor_type = 12;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[13].flags = 219;
  test_msg->sol_in[13].sensor_type = 71;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[14].flags = 85;
  test_msg->sol_in[14].sensor_type = 182;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[15].flags = 204;
  test_msg->sol_in[15].sensor_type = 145;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[16].flags = 40;
  test_msg->sol_in[16].sensor_type = 146;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[17].flags = 51;
  test_msg->sol_in[17].sensor_type = 204;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[18].flags = 153;
  test_msg->sol_in[18].sensor_type = 21;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[19].flags = 44;
  test_msg->sol_in[19].sensor_type = 227;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[20].flags = 28;
  test_msg->sol_in[20].sensor_type = 15;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[21].flags = 39;
  test_msg->sol_in[21].sensor_type = 255;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[22].flags = 216;
  test_msg->sol_in[22].sensor_type = 205;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[23].flags = 190;
  test_msg->sol_in[23].sensor_type = 240;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[24].flags = 219;
  test_msg->sol_in[24].sensor_type = 93;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[25].flags = 42;
  test_msg->sol_in[25].sensor_type = 103;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[26].flags = 182;
  test_msg->sol_in[26].sensor_type = 41;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[27].flags = 222;
  test_msg->sol_in[27].sensor_type = 76;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[28].flags = 23;
  test_msg->sol_in[28].sensor_type = 17;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[29].flags = 31;
  test_msg->sol_in[29].sensor_type = 125;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[30].flags = 229;
  test_msg->sol_in[30].sensor_type = 18;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[31].flags = 47;
  test_msg->sol_in[31].sensor_type = 28;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[32].flags = 25;
  test_msg->sol_in[32].sensor_type = 214;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[33].flags = 84;
  test_msg->sol_in[33].sensor_type = 100;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[34].flags = 72;
  test_msg->sol_in[34].sensor_type = 106;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[35].flags = 10;
  test_msg->sol_in[35].sensor_type = 48;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[36].flags = 232;
  test_msg->sol_in[36].sensor_type = 222;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[37].flags = 73;
  test_msg->sol_in[37].sensor_type = 235;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[38].flags = 163;
  test_msg->sol_in[38].sensor_type = 109;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[39].flags = 152;
  test_msg->sol_in[39].sensor_type = 51;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[40].flags = 235;
  test_msg->sol_in[40].sensor_type = 133;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[41].flags = 70;
  test_msg->sol_in[41].sensor_type = 87;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[42].flags = 108;
  test_msg->sol_in[42].sensor_type = 2;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[43].flags = 101;
  test_msg->sol_in[43].sensor_type = 91;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[44].flags = 55;
  test_msg->sol_in[44].sensor_type = 200;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[45].flags = 156;
  test_msg->sol_in[45].sensor_type = 24;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[46].flags = 73;
  test_msg->sol_in[46].sensor_type = 233;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[47].flags = 66;
  test_msg->sol_in[47].sensor_type = 39;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[48].flags = 140;
  test_msg->sol_in[48].sensor_type = 97;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[49].flags = 227;
  test_msg->sol_in[49].sensor_type = 252;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[50].flags = 237;
  test_msg->sol_in[50].sensor_type = 230;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[51].flags = 241;
  test_msg->sol_in[51].sensor_type = 135;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[52].flags = 205;
  test_msg->sol_in[52].sensor_type = 245;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[53].flags = 0;
  test_msg->sol_in[53].sensor_type = 70;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[54].flags = 188;
  test_msg->sol_in[54].sensor_type = 219;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[55].flags = 136;
  test_msg->sol_in[55].sensor_type = 107;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[56].flags = 58;
  test_msg->sol_in[56].sensor_type = 178;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[57].flags = 29;
  test_msg->sol_in[57].sensor_type = 1;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[58].flags = 213;
  test_msg->sol_in[58].sensor_type = 44;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[59].flags = 147;
  test_msg->sol_in[59].sensor_type = 225;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[60].flags = 96;
  test_msg->sol_in[60].sensor_type = 190;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[61].flags = 108;
  test_msg->sol_in[61].sensor_type = 192;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[62].flags = 15;
  test_msg->sol_in[62].sensor_type = 228;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[63].flags = 18;
  test_msg->sol_in[63].sensor_type = 203;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[64].flags = 222;
  test_msg->sol_in[64].sensor_type = 3;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[65].flags = 68;
  test_msg->sol_in[65].sensor_type = 180;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[66].flags = 229;
  test_msg->sol_in[66].sensor_type = 101;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[67].flags = 203;
  test_msg->sol_in[67].sensor_type = 223;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[68].flags = 164;
  test_msg->sol_in[68].sensor_type = 243;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[69].flags = 165;
  test_msg->sol_in[69].sensor_type = 92;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[70].flags = 159;
  test_msg->sol_in[70].sensor_type = 220;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[71].flags = 121;
  test_msg->sol_in[71].sensor_type = 174;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[72].flags = 167;
  test_msg->sol_in[72].sensor_type = 112;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[73].flags = 40;
  test_msg->sol_in[73].sensor_type = 240;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[74].flags = 3;
  test_msg->sol_in[74].sensor_type = 59;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[75].flags = 52;
  test_msg->sol_in[75].sensor_type = 230;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[76].flags = 148;
  test_msg->sol_in[76].sensor_type = 149;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[77].flags = 142;
  test_msg->sol_in[77].sensor_type = 218;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[78].flags = 109;
  test_msg->sol_in[78].sensor_type = 212;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[79].flags = 71;
  test_msg->sol_in[79].sensor_type = 176;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[80].flags = 172;
  test_msg->sol_in[80].sensor_type = 179;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[81].flags = 1;
  test_msg->sol_in[81].sensor_type = 77;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[82].flags = 70;
  test_msg->sol_in[82].sensor_type = 193;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[83].flags = 149;
  test_msg->sol_in[83].sensor_type = 147;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[84].flags = 144;
  test_msg->sol_in[84].sensor_type = 23;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[85].flags = 239;
  test_msg->sol_in[85].sensor_type = 148;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[86].flags = 186;
  test_msg->sol_in[86].sensor_type = 195;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[87].flags = 30;
  test_msg->sol_in[87].sensor_type = 86;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[88].flags = 143;
  test_msg->sol_in[88].sensor_type = 34;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[89].flags = 207;
  test_msg->sol_in[89].sensor_type = 156;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[90].flags = 55;
  test_msg->sol_in[90].sensor_type = 63;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[91].flags = 255;
  test_msg->sol_in[91].sensor_type = 117;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[92].flags = 222;
  test_msg->sol_in[92].sensor_type = 222;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[93].flags = 145;
  test_msg->sol_in[93].sensor_type = 219;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[94].flags = 191;
  test_msg->sol_in[94].sensor_type = 224;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[95].flags = 109;
  test_msg->sol_in[95].sensor_type = 210;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[96].flags = 153;
  test_msg->sol_in[96].sensor_type = 86;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[97].flags = 32;
  test_msg->sol_in[97].sensor_type = 21;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[98].flags = 10;
  test_msg->sol_in[98].sensor_type = 226;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[99].flags = 63;
  test_msg->sol_in[99].sensor_type = 60;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[100].flags = 236;
  test_msg->sol_in[100].sensor_type = 106;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[101].flags = 96;
  test_msg->sol_in[101].sensor_type = 93;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[102].flags = 163;
  test_msg->sol_in[102].sensor_type = 30;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[103].flags = 238;
  test_msg->sol_in[103].sensor_type = 106;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[104].flags = 133;
  test_msg->sol_in[104].sensor_type = 147;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[105].flags = 107;
  test_msg->sol_in[105].sensor_type = 132;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[106].flags = 214;
  test_msg->sol_in[106].sensor_type = 152;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[107].flags = 185;
  test_msg->sol_in[107].sensor_type = 221;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[108].flags = 21;
  test_msg->sol_in[108].sensor_type = 202;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[109].flags = 51;
  test_msg->sol_in[109].sensor_type = 252;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[110].flags = 59;
  test_msg->sol_in[110].sensor_type = 130;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[111].flags = 202;
  test_msg->sol_in[111].sensor_type = 166;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[112].flags = 170;
  test_msg->sol_in[112].sensor_type = 127;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[113].flags = 193;
  test_msg->sol_in[113].sensor_type = 58;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[114].flags = 125;
  test_msg->sol_in[114].sensor_type = 215;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[115].flags = 58;
  test_msg->sol_in[115].sensor_type = 22;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[116].flags = 47;
  test_msg->sol_in[116].sensor_type = 135;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[117].flags = 142;
  test_msg->sol_in[117].sensor_type = 88;
  test_msg->vdop = 41989;

  EXPECT_EQ(send_message(0xff0f, 61780, test_msg_len, test_msg_storage),
            SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 61780);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(get_as<decltype(last_msg_->age_corrections)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->age_corrections)),
            48671)
      << "incorrect value for age_corrections, expected 48671, is "
      << last_msg_->age_corrections;
  EXPECT_EQ(
      get_as<decltype(last_msg_->alignment_status)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->alignment_status)),
      115)
      << "incorrect value for alignment_status, expected 115, is "
      << last_msg_->alignment_status;
  EXPECT_EQ(get_as<decltype(last_msg_->hdop)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->hdop)),
            31133)
      << "incorrect value for hdop, expected 31133, is " << last_msg_->hdop;
  EXPECT_EQ(get_as<decltype(last_msg_->last_used_gnss_pos_tow)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->last_used_gnss_pos_tow)),
            610745181)
      << "incorrect value for last_used_gnss_pos_tow, expected 610745181, is "
      << last_msg_->last_used_gnss_pos_tow;
  EXPECT_EQ(get_as<decltype(last_msg_->last_used_gnss_vel_tow)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->last_used_gnss_vel_tow)),
            782016851)
      << "incorrect value for last_used_gnss_vel_tow, expected 782016851, is "
      << last_msg_->last_used_gnss_vel_tow;
  EXPECT_EQ(get_as<decltype(last_msg_->n_sats)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->n_sats)),
            238)
      << "incorrect value for n_sats, expected 238, is " << last_msg_->n_sats;
  EXPECT_EQ(get_as<decltype(last_msg_->pdop)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->pdop)),
            57015)
      << "incorrect value for pdop, expected 57015, is " << last_msg_->pdop;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[0].flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[0].flags)),
            67)
      << "incorrect value for sol_in[0].flags, expected 67, is "
      << last_msg_->sol_in[0].flags;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[0].sensor_type)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[0].sensor_type)),
      253)
      << "incorrect value for sol_in[0].sensor_type, expected 253, is "
      << last_msg_->sol_in[0].sensor_type;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[1].flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[1].flags)),
            200)
      << "incorrect value for sol_in[1].flags, expected 200, is "
      << last_msg_->sol_in[1].flags;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[1].sensor_type)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[1].sensor_type)),
      87)
      << "incorrect value for sol_in[1].sensor_type, expected 87, is "
      << last_msg_->sol_in[1].sensor_type;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[2].flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[2].flags)),
            250)
      << "incorrect value for sol_in[2].flags, expected 250, is "
      << last_msg_->sol_in[2].flags;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[2].sensor_type)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[2].sensor_type)),
      39)
      << "incorrect value for sol_in[2].sensor_type, expected 39, is "
      << last_msg_->sol_in[2].sensor_type;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[3].flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[3].flags)),
            242)
      << "incorrect value for sol_in[3].flags, expected 242, is "
      << last_msg_->sol_in[3].flags;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[3].sensor_type)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[3].sensor_type)),
      245)
      << "incorrect value for sol_in[3].sensor_type, expected 245, is "
      << last_msg_->sol_in[3].sensor_type;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[4].flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[4].flags)),
            72)
      << "incorrect value for sol_in[4].flags, expected 72, is "
      << last_msg_->sol_in[4].flags;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[4].sensor_type)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[4].sensor_type)),
      228)
      << "incorrect value for sol_in[4].sensor_type, expected 228, is "
      << last_msg_->sol_in[4].sensor_type;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[5].flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[5].flags)),
            222)
      << "incorrect value for sol_in[5].flags, expected 222, is "
      << last_msg_->sol_in[5].flags;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[5].sensor_type)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[5].sensor_type)),
      18)
      << "incorrect value for sol_in[5].sensor_type, expected 18, is "
      << last_msg_->sol_in[5].sensor_type;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[6].flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[6].flags)),
            88)
      << "incorrect value for sol_in[6].flags, expected 88, is "
      << last_msg_->sol_in[6].flags;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[6].sensor_type)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[6].sensor_type)),
      11)
      << "incorrect value for sol_in[6].sensor_type, expected 11, is "
      << last_msg_->sol_in[6].sensor_type;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[7].flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[7].flags)),
            218)
      << "incorrect value for sol_in[7].flags, expected 218, is "
      << last_msg_->sol_in[7].flags;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[7].sensor_type)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[7].sensor_type)),
      207)
      << "incorrect value for sol_in[7].sensor_type, expected 207, is "
      << last_msg_->sol_in[7].sensor_type;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[8].flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[8].flags)),
            13)
      << "incorrect value for sol_in[8].flags, expected 13, is "
      << last_msg_->sol_in[8].flags;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[8].sensor_type)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[8].sensor_type)),
      231)
      << "incorrect value for sol_in[8].sensor_type, expected 231, is "
      << last_msg_->sol_in[8].sensor_type;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[9].flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[9].flags)),
            224)
      << "incorrect value for sol_in[9].flags, expected 224, is "
      << last_msg_->sol_in[9].flags;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[9].sensor_type)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[9].sensor_type)),
      226)
      << "incorrect value for sol_in[9].sensor_type, expected 226, is "
      << last_msg_->sol_in[9].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[10].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[10].flags)),
      196)
      << "incorrect value for sol_in[10].flags, expected 196, is "
      << last_msg_->sol_in[10].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[10].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[10].sensor_type)),
            22)
      << "incorrect value for sol_in[10].sensor_type, expected 22, is "
      << last_msg_->sol_in[10].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[11].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[11].flags)),
      242)
      << "incorrect value for sol_in[11].flags, expected 242, is "
      << last_msg_->sol_in[11].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[11].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[11].sensor_type)),
            21)
      << "incorrect value for sol_in[11].sensor_type, expected 21, is "
      << last_msg_->sol_in[11].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[12].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[12].flags)),
      89)
      << "incorrect value for sol_in[12].flags, expected 89, is "
      << last_msg_->sol_in[12].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[12].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[12].sensor_type)),
            12)
      << "incorrect value for sol_in[12].sensor_type, expected 12, is "
      << last_msg_->sol_in[12].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[13].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[13].flags)),
      219)
      << "incorrect value for sol_in[13].flags, expected 219, is "
      << last_msg_->sol_in[13].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[13].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[13].sensor_type)),
            71)
      << "incorrect value for sol_in[13].sensor_type, expected 71, is "
      << last_msg_->sol_in[13].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[14].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[14].flags)),
      85)
      << "incorrect value for sol_in[14].flags, expected 85, is "
      << last_msg_->sol_in[14].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[14].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[14].sensor_type)),
            182)
      << "incorrect value for sol_in[14].sensor_type, expected 182, is "
      << last_msg_->sol_in[14].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[15].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[15].flags)),
      204)
      << "incorrect value for sol_in[15].flags, expected 204, is "
      << last_msg_->sol_in[15].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[15].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[15].sensor_type)),
            145)
      << "incorrect value for sol_in[15].sensor_type, expected 145, is "
      << last_msg_->sol_in[15].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[16].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[16].flags)),
      40)
      << "incorrect value for sol_in[16].flags, expected 40, is "
      << last_msg_->sol_in[16].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[16].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[16].sensor_type)),
            146)
      << "incorrect value for sol_in[16].sensor_type, expected 146, is "
      << last_msg_->sol_in[16].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[17].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[17].flags)),
      51)
      << "incorrect value for sol_in[17].flags, expected 51, is "
      << last_msg_->sol_in[17].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[17].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[17].sensor_type)),
            204)
      << "incorrect value for sol_in[17].sensor_type, expected 204, is "
      << last_msg_->sol_in[17].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[18].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[18].flags)),
      153)
      << "incorrect value for sol_in[18].flags, expected 153, is "
      << last_msg_->sol_in[18].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[18].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[18].sensor_type)),
            21)
      << "incorrect value for sol_in[18].sensor_type, expected 21, is "
      << last_msg_->sol_in[18].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[19].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[19].flags)),
      44)
      << "incorrect value for sol_in[19].flags, expected 44, is "
      << last_msg_->sol_in[19].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[19].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[19].sensor_type)),
            227)
      << "incorrect value for sol_in[19].sensor_type, expected 227, is "
      << last_msg_->sol_in[19].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[20].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[20].flags)),
      28)
      << "incorrect value for sol_in[20].flags, expected 28, is "
      << last_msg_->sol_in[20].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[20].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[20].sensor_type)),
            15)
      << "incorrect value for sol_in[20].sensor_type, expected 15, is "
      << last_msg_->sol_in[20].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[21].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[21].flags)),
      39)
      << "incorrect value for sol_in[21].flags, expected 39, is "
      << last_msg_->sol_in[21].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[21].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[21].sensor_type)),
            255)
      << "incorrect value for sol_in[21].sensor_type, expected 255, is "
      << last_msg_->sol_in[21].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[22].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[22].flags)),
      216)
      << "incorrect value for sol_in[22].flags, expected 216, is "
      << last_msg_->sol_in[22].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[22].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[22].sensor_type)),
            205)
      << "incorrect value for sol_in[22].sensor_type, expected 205, is "
      << last_msg_->sol_in[22].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[23].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[23].flags)),
      190)
      << "incorrect value for sol_in[23].flags, expected 190, is "
      << last_msg_->sol_in[23].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[23].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[23].sensor_type)),
            240)
      << "incorrect value for sol_in[23].sensor_type, expected 240, is "
      << last_msg_->sol_in[23].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[24].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[24].flags)),
      219)
      << "incorrect value for sol_in[24].flags, expected 219, is "
      << last_msg_->sol_in[24].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[24].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[24].sensor_type)),
            93)
      << "incorrect value for sol_in[24].sensor_type, expected 93, is "
      << last_msg_->sol_in[24].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[25].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[25].flags)),
      42)
      << "incorrect value for sol_in[25].flags, expected 42, is "
      << last_msg_->sol_in[25].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[25].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[25].sensor_type)),
            103)
      << "incorrect value for sol_in[25].sensor_type, expected 103, is "
      << last_msg_->sol_in[25].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[26].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[26].flags)),
      182)
      << "incorrect value for sol_in[26].flags, expected 182, is "
      << last_msg_->sol_in[26].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[26].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[26].sensor_type)),
            41)
      << "incorrect value for sol_in[26].sensor_type, expected 41, is "
      << last_msg_->sol_in[26].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[27].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[27].flags)),
      222)
      << "incorrect value for sol_in[27].flags, expected 222, is "
      << last_msg_->sol_in[27].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[27].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[27].sensor_type)),
            76)
      << "incorrect value for sol_in[27].sensor_type, expected 76, is "
      << last_msg_->sol_in[27].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[28].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[28].flags)),
      23)
      << "incorrect value for sol_in[28].flags, expected 23, is "
      << last_msg_->sol_in[28].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[28].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[28].sensor_type)),
            17)
      << "incorrect value for sol_in[28].sensor_type, expected 17, is "
      << last_msg_->sol_in[28].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[29].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[29].flags)),
      31)
      << "incorrect value for sol_in[29].flags, expected 31, is "
      << last_msg_->sol_in[29].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[29].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[29].sensor_type)),
            125)
      << "incorrect value for sol_in[29].sensor_type, expected 125, is "
      << last_msg_->sol_in[29].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[30].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[30].flags)),
      229)
      << "incorrect value for sol_in[30].flags, expected 229, is "
      << last_msg_->sol_in[30].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[30].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[30].sensor_type)),
            18)
      << "incorrect value for sol_in[30].sensor_type, expected 18, is "
      << last_msg_->sol_in[30].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[31].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[31].flags)),
      47)
      << "incorrect value for sol_in[31].flags, expected 47, is "
      << last_msg_->sol_in[31].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[31].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[31].sensor_type)),
            28)
      << "incorrect value for sol_in[31].sensor_type, expected 28, is "
      << last_msg_->sol_in[31].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[32].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[32].flags)),
      25)
      << "incorrect value for sol_in[32].flags, expected 25, is "
      << last_msg_->sol_in[32].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[32].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[32].sensor_type)),
            214)
      << "incorrect value for sol_in[32].sensor_type, expected 214, is "
      << last_msg_->sol_in[32].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[33].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[33].flags)),
      84)
      << "incorrect value for sol_in[33].flags, expected 84, is "
      << last_msg_->sol_in[33].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[33].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[33].sensor_type)),
            100)
      << "incorrect value for sol_in[33].sensor_type, expected 100, is "
      << last_msg_->sol_in[33].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[34].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[34].flags)),
      72)
      << "incorrect value for sol_in[34].flags, expected 72, is "
      << last_msg_->sol_in[34].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[34].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[34].sensor_type)),
            106)
      << "incorrect value for sol_in[34].sensor_type, expected 106, is "
      << last_msg_->sol_in[34].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[35].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[35].flags)),
      10)
      << "incorrect value for sol_in[35].flags, expected 10, is "
      << last_msg_->sol_in[35].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[35].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[35].sensor_type)),
            48)
      << "incorrect value for sol_in[35].sensor_type, expected 48, is "
      << last_msg_->sol_in[35].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[36].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[36].flags)),
      232)
      << "incorrect value for sol_in[36].flags, expected 232, is "
      << last_msg_->sol_in[36].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[36].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[36].sensor_type)),
            222)
      << "incorrect value for sol_in[36].sensor_type, expected 222, is "
      << last_msg_->sol_in[36].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[37].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[37].flags)),
      73)
      << "incorrect value for sol_in[37].flags, expected 73, is "
      << last_msg_->sol_in[37].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[37].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[37].sensor_type)),
            235)
      << "incorrect value for sol_in[37].sensor_type, expected 235, is "
      << last_msg_->sol_in[37].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[38].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[38].flags)),
      163)
      << "incorrect value for sol_in[38].flags, expected 163, is "
      << last_msg_->sol_in[38].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[38].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[38].sensor_type)),
            109)
      << "incorrect value for sol_in[38].sensor_type, expected 109, is "
      << last_msg_->sol_in[38].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[39].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[39].flags)),
      152)
      << "incorrect value for sol_in[39].flags, expected 152, is "
      << last_msg_->sol_in[39].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[39].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[39].sensor_type)),
            51)
      << "incorrect value for sol_in[39].sensor_type, expected 51, is "
      << last_msg_->sol_in[39].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[40].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[40].flags)),
      235)
      << "incorrect value for sol_in[40].flags, expected 235, is "
      << last_msg_->sol_in[40].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[40].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[40].sensor_type)),
            133)
      << "incorrect value for sol_in[40].sensor_type, expected 133, is "
      << last_msg_->sol_in[40].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[41].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[41].flags)),
      70)
      << "incorrect value for sol_in[41].flags, expected 70, is "
      << last_msg_->sol_in[41].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[41].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[41].sensor_type)),
            87)
      << "incorrect value for sol_in[41].sensor_type, expected 87, is "
      << last_msg_->sol_in[41].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[42].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[42].flags)),
      108)
      << "incorrect value for sol_in[42].flags, expected 108, is "
      << last_msg_->sol_in[42].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[42].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[42].sensor_type)),
            2)
      << "incorrect value for sol_in[42].sensor_type, expected 2, is "
      << last_msg_->sol_in[42].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[43].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[43].flags)),
      101)
      << "incorrect value for sol_in[43].flags, expected 101, is "
      << last_msg_->sol_in[43].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[43].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[43].sensor_type)),
            91)
      << "incorrect value for sol_in[43].sensor_type, expected 91, is "
      << last_msg_->sol_in[43].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[44].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[44].flags)),
      55)
      << "incorrect value for sol_in[44].flags, expected 55, is "
      << last_msg_->sol_in[44].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[44].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[44].sensor_type)),
            200)
      << "incorrect value for sol_in[44].sensor_type, expected 200, is "
      << last_msg_->sol_in[44].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[45].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[45].flags)),
      156)
      << "incorrect value for sol_in[45].flags, expected 156, is "
      << last_msg_->sol_in[45].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[45].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[45].sensor_type)),
            24)
      << "incorrect value for sol_in[45].sensor_type, expected 24, is "
      << last_msg_->sol_in[45].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[46].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[46].flags)),
      73)
      << "incorrect value for sol_in[46].flags, expected 73, is "
      << last_msg_->sol_in[46].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[46].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[46].sensor_type)),
            233)
      << "incorrect value for sol_in[46].sensor_type, expected 233, is "
      << last_msg_->sol_in[46].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[47].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[47].flags)),
      66)
      << "incorrect value for sol_in[47].flags, expected 66, is "
      << last_msg_->sol_in[47].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[47].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[47].sensor_type)),
            39)
      << "incorrect value for sol_in[47].sensor_type, expected 39, is "
      << last_msg_->sol_in[47].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[48].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[48].flags)),
      140)
      << "incorrect value for sol_in[48].flags, expected 140, is "
      << last_msg_->sol_in[48].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[48].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[48].sensor_type)),
            97)
      << "incorrect value for sol_in[48].sensor_type, expected 97, is "
      << last_msg_->sol_in[48].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[49].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[49].flags)),
      227)
      << "incorrect value for sol_in[49].flags, expected 227, is "
      << last_msg_->sol_in[49].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[49].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[49].sensor_type)),
            252)
      << "incorrect value for sol_in[49].sensor_type, expected 252, is "
      << last_msg_->sol_in[49].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[50].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[50].flags)),
      237)
      << "incorrect value for sol_in[50].flags, expected 237, is "
      << last_msg_->sol_in[50].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[50].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[50].sensor_type)),
            230)
      << "incorrect value for sol_in[50].sensor_type, expected 230, is "
      << last_msg_->sol_in[50].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[51].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[51].flags)),
      241)
      << "incorrect value for sol_in[51].flags, expected 241, is "
      << last_msg_->sol_in[51].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[51].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[51].sensor_type)),
            135)
      << "incorrect value for sol_in[51].sensor_type, expected 135, is "
      << last_msg_->sol_in[51].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[52].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[52].flags)),
      205)
      << "incorrect value for sol_in[52].flags, expected 205, is "
      << last_msg_->sol_in[52].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[52].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[52].sensor_type)),
            245)
      << "incorrect value for sol_in[52].sensor_type, expected 245, is "
      << last_msg_->sol_in[52].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[53].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[53].flags)),
      0)
      << "incorrect value for sol_in[53].flags, expected 0, is "
      << last_msg_->sol_in[53].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[53].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[53].sensor_type)),
            70)
      << "incorrect value for sol_in[53].sensor_type, expected 70, is "
      << last_msg_->sol_in[53].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[54].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[54].flags)),
      188)
      << "incorrect value for sol_in[54].flags, expected 188, is "
      << last_msg_->sol_in[54].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[54].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[54].sensor_type)),
            219)
      << "incorrect value for sol_in[54].sensor_type, expected 219, is "
      << last_msg_->sol_in[54].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[55].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[55].flags)),
      136)
      << "incorrect value for sol_in[55].flags, expected 136, is "
      << last_msg_->sol_in[55].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[55].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[55].sensor_type)),
            107)
      << "incorrect value for sol_in[55].sensor_type, expected 107, is "
      << last_msg_->sol_in[55].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[56].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[56].flags)),
      58)
      << "incorrect value for sol_in[56].flags, expected 58, is "
      << last_msg_->sol_in[56].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[56].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[56].sensor_type)),
            178)
      << "incorrect value for sol_in[56].sensor_type, expected 178, is "
      << last_msg_->sol_in[56].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[57].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[57].flags)),
      29)
      << "incorrect value for sol_in[57].flags, expected 29, is "
      << last_msg_->sol_in[57].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[57].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[57].sensor_type)),
            1)
      << "incorrect value for sol_in[57].sensor_type, expected 1, is "
      << last_msg_->sol_in[57].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[58].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[58].flags)),
      213)
      << "incorrect value for sol_in[58].flags, expected 213, is "
      << last_msg_->sol_in[58].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[58].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[58].sensor_type)),
            44)
      << "incorrect value for sol_in[58].sensor_type, expected 44, is "
      << last_msg_->sol_in[58].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[59].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[59].flags)),
      147)
      << "incorrect value for sol_in[59].flags, expected 147, is "
      << last_msg_->sol_in[59].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[59].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[59].sensor_type)),
            225)
      << "incorrect value for sol_in[59].sensor_type, expected 225, is "
      << last_msg_->sol_in[59].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[60].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[60].flags)),
      96)
      << "incorrect value for sol_in[60].flags, expected 96, is "
      << last_msg_->sol_in[60].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[60].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[60].sensor_type)),
            190)
      << "incorrect value for sol_in[60].sensor_type, expected 190, is "
      << last_msg_->sol_in[60].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[61].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[61].flags)),
      108)
      << "incorrect value for sol_in[61].flags, expected 108, is "
      << last_msg_->sol_in[61].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[61].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[61].sensor_type)),
            192)
      << "incorrect value for sol_in[61].sensor_type, expected 192, is "
      << last_msg_->sol_in[61].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[62].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[62].flags)),
      15)
      << "incorrect value for sol_in[62].flags, expected 15, is "
      << last_msg_->sol_in[62].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[62].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[62].sensor_type)),
            228)
      << "incorrect value for sol_in[62].sensor_type, expected 228, is "
      << last_msg_->sol_in[62].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[63].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[63].flags)),
      18)
      << "incorrect value for sol_in[63].flags, expected 18, is "
      << last_msg_->sol_in[63].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[63].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[63].sensor_type)),
            203)
      << "incorrect value for sol_in[63].sensor_type, expected 203, is "
      << last_msg_->sol_in[63].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[64].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[64].flags)),
      222)
      << "incorrect value for sol_in[64].flags, expected 222, is "
      << last_msg_->sol_in[64].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[64].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[64].sensor_type)),
            3)
      << "incorrect value for sol_in[64].sensor_type, expected 3, is "
      << last_msg_->sol_in[64].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[65].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[65].flags)),
      68)
      << "incorrect value for sol_in[65].flags, expected 68, is "
      << last_msg_->sol_in[65].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[65].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[65].sensor_type)),
            180)
      << "incorrect value for sol_in[65].sensor_type, expected 180, is "
      << last_msg_->sol_in[65].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[66].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[66].flags)),
      229)
      << "incorrect value for sol_in[66].flags, expected 229, is "
      << last_msg_->sol_in[66].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[66].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[66].sensor_type)),
            101)
      << "incorrect value for sol_in[66].sensor_type, expected 101, is "
      << last_msg_->sol_in[66].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[67].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[67].flags)),
      203)
      << "incorrect value for sol_in[67].flags, expected 203, is "
      << last_msg_->sol_in[67].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[67].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[67].sensor_type)),
            223)
      << "incorrect value for sol_in[67].sensor_type, expected 223, is "
      << last_msg_->sol_in[67].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[68].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[68].flags)),
      164)
      << "incorrect value for sol_in[68].flags, expected 164, is "
      << last_msg_->sol_in[68].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[68].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[68].sensor_type)),
            243)
      << "incorrect value for sol_in[68].sensor_type, expected 243, is "
      << last_msg_->sol_in[68].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[69].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[69].flags)),
      165)
      << "incorrect value for sol_in[69].flags, expected 165, is "
      << last_msg_->sol_in[69].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[69].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[69].sensor_type)),
            92)
      << "incorrect value for sol_in[69].sensor_type, expected 92, is "
      << last_msg_->sol_in[69].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[70].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[70].flags)),
      159)
      << "incorrect value for sol_in[70].flags, expected 159, is "
      << last_msg_->sol_in[70].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[70].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[70].sensor_type)),
            220)
      << "incorrect value for sol_in[70].sensor_type, expected 220, is "
      << last_msg_->sol_in[70].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[71].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[71].flags)),
      121)
      << "incorrect value for sol_in[71].flags, expected 121, is "
      << last_msg_->sol_in[71].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[71].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[71].sensor_type)),
            174)
      << "incorrect value for sol_in[71].sensor_type, expected 174, is "
      << last_msg_->sol_in[71].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[72].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[72].flags)),
      167)
      << "incorrect value for sol_in[72].flags, expected 167, is "
      << last_msg_->sol_in[72].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[72].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[72].sensor_type)),
            112)
      << "incorrect value for sol_in[72].sensor_type, expected 112, is "
      << last_msg_->sol_in[72].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[73].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[73].flags)),
      40)
      << "incorrect value for sol_in[73].flags, expected 40, is "
      << last_msg_->sol_in[73].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[73].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[73].sensor_type)),
            240)
      << "incorrect value for sol_in[73].sensor_type, expected 240, is "
      << last_msg_->sol_in[73].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[74].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[74].flags)),
      3)
      << "incorrect value for sol_in[74].flags, expected 3, is "
      << last_msg_->sol_in[74].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[74].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[74].sensor_type)),
            59)
      << "incorrect value for sol_in[74].sensor_type, expected 59, is "
      << last_msg_->sol_in[74].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[75].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[75].flags)),
      52)
      << "incorrect value for sol_in[75].flags, expected 52, is "
      << last_msg_->sol_in[75].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[75].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[75].sensor_type)),
            230)
      << "incorrect value for sol_in[75].sensor_type, expected 230, is "
      << last_msg_->sol_in[75].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[76].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[76].flags)),
      148)
      << "incorrect value for sol_in[76].flags, expected 148, is "
      << last_msg_->sol_in[76].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[76].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[76].sensor_type)),
            149)
      << "incorrect value for sol_in[76].sensor_type, expected 149, is "
      << last_msg_->sol_in[76].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[77].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[77].flags)),
      142)
      << "incorrect value for sol_in[77].flags, expected 142, is "
      << last_msg_->sol_in[77].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[77].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[77].sensor_type)),
            218)
      << "incorrect value for sol_in[77].sensor_type, expected 218, is "
      << last_msg_->sol_in[77].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[78].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[78].flags)),
      109)
      << "incorrect value for sol_in[78].flags, expected 109, is "
      << last_msg_->sol_in[78].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[78].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[78].sensor_type)),
            212)
      << "incorrect value for sol_in[78].sensor_type, expected 212, is "
      << last_msg_->sol_in[78].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[79].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[79].flags)),
      71)
      << "incorrect value for sol_in[79].flags, expected 71, is "
      << last_msg_->sol_in[79].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[79].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[79].sensor_type)),
            176)
      << "incorrect value for sol_in[79].sensor_type, expected 176, is "
      << last_msg_->sol_in[79].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[80].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[80].flags)),
      172)
      << "incorrect value for sol_in[80].flags, expected 172, is "
      << last_msg_->sol_in[80].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[80].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[80].sensor_type)),
            179)
      << "incorrect value for sol_in[80].sensor_type, expected 179, is "
      << last_msg_->sol_in[80].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[81].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[81].flags)),
      1)
      << "incorrect value for sol_in[81].flags, expected 1, is "
      << last_msg_->sol_in[81].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[81].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[81].sensor_type)),
            77)
      << "incorrect value for sol_in[81].sensor_type, expected 77, is "
      << last_msg_->sol_in[81].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[82].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[82].flags)),
      70)
      << "incorrect value for sol_in[82].flags, expected 70, is "
      << last_msg_->sol_in[82].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[82].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[82].sensor_type)),
            193)
      << "incorrect value for sol_in[82].sensor_type, expected 193, is "
      << last_msg_->sol_in[82].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[83].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[83].flags)),
      149)
      << "incorrect value for sol_in[83].flags, expected 149, is "
      << last_msg_->sol_in[83].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[83].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[83].sensor_type)),
            147)
      << "incorrect value for sol_in[83].sensor_type, expected 147, is "
      << last_msg_->sol_in[83].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[84].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[84].flags)),
      144)
      << "incorrect value for sol_in[84].flags, expected 144, is "
      << last_msg_->sol_in[84].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[84].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[84].sensor_type)),
            23)
      << "incorrect value for sol_in[84].sensor_type, expected 23, is "
      << last_msg_->sol_in[84].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[85].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[85].flags)),
      239)
      << "incorrect value for sol_in[85].flags, expected 239, is "
      << last_msg_->sol_in[85].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[85].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[85].sensor_type)),
            148)
      << "incorrect value for sol_in[85].sensor_type, expected 148, is "
      << last_msg_->sol_in[85].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[86].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[86].flags)),
      186)
      << "incorrect value for sol_in[86].flags, expected 186, is "
      << last_msg_->sol_in[86].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[86].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[86].sensor_type)),
            195)
      << "incorrect value for sol_in[86].sensor_type, expected 195, is "
      << last_msg_->sol_in[86].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[87].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[87].flags)),
      30)
      << "incorrect value for sol_in[87].flags, expected 30, is "
      << last_msg_->sol_in[87].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[87].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[87].sensor_type)),
            86)
      << "incorrect value for sol_in[87].sensor_type, expected 86, is "
      << last_msg_->sol_in[87].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[88].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[88].flags)),
      143)
      << "incorrect value for sol_in[88].flags, expected 143, is "
      << last_msg_->sol_in[88].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[88].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[88].sensor_type)),
            34)
      << "incorrect value for sol_in[88].sensor_type, expected 34, is "
      << last_msg_->sol_in[88].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[89].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[89].flags)),
      207)
      << "incorrect value for sol_in[89].flags, expected 207, is "
      << last_msg_->sol_in[89].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[89].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[89].sensor_type)),
            156)
      << "incorrect value for sol_in[89].sensor_type, expected 156, is "
      << last_msg_->sol_in[89].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[90].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[90].flags)),
      55)
      << "incorrect value for sol_in[90].flags, expected 55, is "
      << last_msg_->sol_in[90].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[90].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[90].sensor_type)),
            63)
      << "incorrect value for sol_in[90].sensor_type, expected 63, is "
      << last_msg_->sol_in[90].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[91].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[91].flags)),
      255)
      << "incorrect value for sol_in[91].flags, expected 255, is "
      << last_msg_->sol_in[91].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[91].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[91].sensor_type)),
            117)
      << "incorrect value for sol_in[91].sensor_type, expected 117, is "
      << last_msg_->sol_in[91].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[92].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[92].flags)),
      222)
      << "incorrect value for sol_in[92].flags, expected 222, is "
      << last_msg_->sol_in[92].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[92].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[92].sensor_type)),
            222)
      << "incorrect value for sol_in[92].sensor_type, expected 222, is "
      << last_msg_->sol_in[92].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[93].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[93].flags)),
      145)
      << "incorrect value for sol_in[93].flags, expected 145, is "
      << last_msg_->sol_in[93].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[93].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[93].sensor_type)),
            219)
      << "incorrect value for sol_in[93].sensor_type, expected 219, is "
      << last_msg_->sol_in[93].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[94].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[94].flags)),
      191)
      << "incorrect value for sol_in[94].flags, expected 191, is "
      << last_msg_->sol_in[94].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[94].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[94].sensor_type)),
            224)
      << "incorrect value for sol_in[94].sensor_type, expected 224, is "
      << last_msg_->sol_in[94].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[95].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[95].flags)),
      109)
      << "incorrect value for sol_in[95].flags, expected 109, is "
      << last_msg_->sol_in[95].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[95].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[95].sensor_type)),
            210)
      << "incorrect value for sol_in[95].sensor_type, expected 210, is "
      << last_msg_->sol_in[95].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[96].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[96].flags)),
      153)
      << "incorrect value for sol_in[96].flags, expected 153, is "
      << last_msg_->sol_in[96].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[96].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[96].sensor_type)),
            86)
      << "incorrect value for sol_in[96].sensor_type, expected 86, is "
      << last_msg_->sol_in[96].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[97].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[97].flags)),
      32)
      << "incorrect value for sol_in[97].flags, expected 32, is "
      << last_msg_->sol_in[97].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[97].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[97].sensor_type)),
            21)
      << "incorrect value for sol_in[97].sensor_type, expected 21, is "
      << last_msg_->sol_in[97].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[98].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[98].flags)),
      10)
      << "incorrect value for sol_in[98].flags, expected 10, is "
      << last_msg_->sol_in[98].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[98].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[98].sensor_type)),
            226)
      << "incorrect value for sol_in[98].sensor_type, expected 226, is "
      << last_msg_->sol_in[98].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[99].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[99].flags)),
      63)
      << "incorrect value for sol_in[99].flags, expected 63, is "
      << last_msg_->sol_in[99].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[99].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[99].sensor_type)),
            60)
      << "incorrect value for sol_in[99].sensor_type, expected 60, is "
      << last_msg_->sol_in[99].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[100].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[100].flags)),
      236)
      << "incorrect value for sol_in[100].flags, expected 236, is "
      << last_msg_->sol_in[100].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[100].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[100].sensor_type)),
            106)
      << "incorrect value for sol_in[100].sensor_type, expected 106, is "
      << last_msg_->sol_in[100].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[101].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[101].flags)),
      96)
      << "incorrect value for sol_in[101].flags, expected 96, is "
      << last_msg_->sol_in[101].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[101].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[101].sensor_type)),
            93)
      << "incorrect value for sol_in[101].sensor_type, expected 93, is "
      << last_msg_->sol_in[101].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[102].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[102].flags)),
      163)
      << "incorrect value for sol_in[102].flags, expected 163, is "
      << last_msg_->sol_in[102].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[102].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[102].sensor_type)),
            30)
      << "incorrect value for sol_in[102].sensor_type, expected 30, is "
      << last_msg_->sol_in[102].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[103].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[103].flags)),
      238)
      << "incorrect value for sol_in[103].flags, expected 238, is "
      << last_msg_->sol_in[103].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[103].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[103].sensor_type)),
            106)
      << "incorrect value for sol_in[103].sensor_type, expected 106, is "
      << last_msg_->sol_in[103].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[104].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[104].flags)),
      133)
      << "incorrect value for sol_in[104].flags, expected 133, is "
      << last_msg_->sol_in[104].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[104].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[104].sensor_type)),
            147)
      << "incorrect value for sol_in[104].sensor_type, expected 147, is "
      << last_msg_->sol_in[104].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[105].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[105].flags)),
      107)
      << "incorrect value for sol_in[105].flags, expected 107, is "
      << last_msg_->sol_in[105].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[105].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[105].sensor_type)),
            132)
      << "incorrect value for sol_in[105].sensor_type, expected 132, is "
      << last_msg_->sol_in[105].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[106].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[106].flags)),
      214)
      << "incorrect value for sol_in[106].flags, expected 214, is "
      << last_msg_->sol_in[106].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[106].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[106].sensor_type)),
            152)
      << "incorrect value for sol_in[106].sensor_type, expected 152, is "
      << last_msg_->sol_in[106].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[107].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[107].flags)),
      185)
      << "incorrect value for sol_in[107].flags, expected 185, is "
      << last_msg_->sol_in[107].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[107].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[107].sensor_type)),
            221)
      << "incorrect value for sol_in[107].sensor_type, expected 221, is "
      << last_msg_->sol_in[107].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[108].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[108].flags)),
      21)
      << "incorrect value for sol_in[108].flags, expected 21, is "
      << last_msg_->sol_in[108].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[108].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[108].sensor_type)),
            202)
      << "incorrect value for sol_in[108].sensor_type, expected 202, is "
      << last_msg_->sol_in[108].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[109].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[109].flags)),
      51)
      << "incorrect value for sol_in[109].flags, expected 51, is "
      << last_msg_->sol_in[109].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[109].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[109].sensor_type)),
            252)
      << "incorrect value for sol_in[109].sensor_type, expected 252, is "
      << last_msg_->sol_in[109].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[110].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[110].flags)),
      59)
      << "incorrect value for sol_in[110].flags, expected 59, is "
      << last_msg_->sol_in[110].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[110].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[110].sensor_type)),
            130)
      << "incorrect value for sol_in[110].sensor_type, expected 130, is "
      << last_msg_->sol_in[110].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[111].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[111].flags)),
      202)
      << "incorrect value for sol_in[111].flags, expected 202, is "
      << last_msg_->sol_in[111].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[111].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[111].sensor_type)),
            166)
      << "incorrect value for sol_in[111].sensor_type, expected 166, is "
      << last_msg_->sol_in[111].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[112].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[112].flags)),
      170)
      << "incorrect value for sol_in[112].flags, expected 170, is "
      << last_msg_->sol_in[112].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[112].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[112].sensor_type)),
            127)
      << "incorrect value for sol_in[112].sensor_type, expected 127, is "
      << last_msg_->sol_in[112].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[113].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[113].flags)),
      193)
      << "incorrect value for sol_in[113].flags, expected 193, is "
      << last_msg_->sol_in[113].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[113].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[113].sensor_type)),
            58)
      << "incorrect value for sol_in[113].sensor_type, expected 58, is "
      << last_msg_->sol_in[113].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[114].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[114].flags)),
      125)
      << "incorrect value for sol_in[114].flags, expected 125, is "
      << last_msg_->sol_in[114].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[114].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[114].sensor_type)),
            215)
      << "incorrect value for sol_in[114].sensor_type, expected 215, is "
      << last_msg_->sol_in[114].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[115].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[115].flags)),
      58)
      << "incorrect value for sol_in[115].flags, expected 58, is "
      << last_msg_->sol_in[115].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[115].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[115].sensor_type)),
            22)
      << "incorrect value for sol_in[115].sensor_type, expected 22, is "
      << last_msg_->sol_in[115].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[116].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[116].flags)),
      47)
      << "incorrect value for sol_in[116].flags, expected 47, is "
      << last_msg_->sol_in[116].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[116].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[116].sensor_type)),
            135)
      << "incorrect value for sol_in[116].sensor_type, expected 135, is "
      << last_msg_->sol_in[116].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[117].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[117].flags)),
      142)
      << "incorrect value for sol_in[117].flags, expected 142, is "
      << last_msg_->sol_in[117].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[117].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[117].sensor_type)),
            88)
      << "incorrect value for sol_in[117].sensor_type, expected 88, is "
      << last_msg_->sol_in[117].sensor_type;
  EXPECT_EQ(get_as<decltype(last_msg_->vdop)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->vdop)),
            41989)
      << "incorrect value for vdop, expected 41989, is " << last_msg_->vdop;
}
