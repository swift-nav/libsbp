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
// spec/tests/yaml/swiftnav/sbp/soln_meta/test_MsgSolnMeta.yaml by generate.py.
// Do not modify by hand!

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
class Test_legacy_auto_check_sbp_solution_meta_MsgSolnMeta0
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_soln_meta_t> {
 public:
  Test_legacy_auto_check_sbp_solution_meta_MsgSolnMeta0()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_soln_meta_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_soln_meta_t *>(last_msg_storage_)),
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
                      const msg_soln_meta_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_soln_meta_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_solution_meta_MsgSolnMeta0, Test) {
  uint8_t encoded_frame[] = {
      85,  14,  255, 0,   60,  254, 48,  208, 65,  216, 122, 45,  196, 160, 144,
      228, 8,   83,  89,  87,  3,   213, 95,  109, 86,  131, 71,  70,  84,  73,
      131, 26,  82,  247, 140, 97,  115, 110, 118, 253, 2,   122, 186, 148, 122,
      148, 180, 231, 68,  46,  190, 102, 243, 48,  192, 15,  208, 89,  56,  10,
      245, 2,   254, 201, 120, 32,  126, 2,   83,  161, 238, 123, 102, 230, 76,
      190, 225, 182, 207, 228, 7,   218, 117, 89,  29,  191, 56,  248, 185, 255,
      46,  18,  72,  142, 82,  113, 26,  4,   172, 254, 178, 136, 113, 115, 58,
      193, 89,  227, 182, 246, 76,  77,  108, 245, 41,  31,  70,  124, 249, 145,
      15,  78,  228, 38,  241, 129, 8,   176, 251, 72,  248, 80,  115, 244, 231,
      145, 191, 190, 178, 168, 89,  233, 69,  176, 174, 140, 182, 141, 81,  82,
      92,  79,  101, 223, 100, 64,  184, 215, 124, 37,  21,  227, 135, 102, 72,
      36,  219, 56,  146, 90,  219, 104, 227, 102, 83,  12,  41,  122, 173, 94,
      1,   174, 134, 130, 104, 237, 116, 249, 107, 230, 130, 123, 25,  162, 57,
      223, 193, 174, 146, 193, 239, 44,  246, 197, 214, 80,  83,  100, 66,  72,
      133, 137, 140, 82,  2,   2,   96,  9,   96,  158, 134, 97,  43,  129, 141,
      25,  183, 200, 214, 57,  248, 103, 222, 65,  195, 15,  244, 21,  180, 46,
      140, 130, 36,  17,  194, 209, 65,  254, 115, 103, 152, 129, 234, 235, 194,
      234, 170, 201, 210, 154, 150, 247,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_soln_meta_t *test_msg = (msg_soln_meta_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->age_corrections = 21256;
  test_msg->age_gnss = 3573765977;
  test_msg->hdop = 41156;
  test_msg->pdop = 11642;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[0].flags = 109;
  test_msg->sol_in[0].sensor_type = 95;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[1].flags = 131;
  test_msg->sol_in[1].sensor_type = 86;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[2].flags = 70;
  test_msg->sol_in[2].sensor_type = 71;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[3].flags = 73;
  test_msg->sol_in[3].sensor_type = 84;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[4].flags = 26;
  test_msg->sol_in[4].sensor_type = 131;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[5].flags = 247;
  test_msg->sol_in[5].sensor_type = 82;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[6].flags = 97;
  test_msg->sol_in[6].sensor_type = 140;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[7].flags = 110;
  test_msg->sol_in[7].sensor_type = 115;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[8].flags = 253;
  test_msg->sol_in[8].sensor_type = 118;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[9].flags = 122;
  test_msg->sol_in[9].sensor_type = 2;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[10].flags = 148;
  test_msg->sol_in[10].sensor_type = 186;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[11].flags = 148;
  test_msg->sol_in[11].sensor_type = 122;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[12].flags = 231;
  test_msg->sol_in[12].sensor_type = 180;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[13].flags = 46;
  test_msg->sol_in[13].sensor_type = 68;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[14].flags = 102;
  test_msg->sol_in[14].sensor_type = 190;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[15].flags = 48;
  test_msg->sol_in[15].sensor_type = 243;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[16].flags = 15;
  test_msg->sol_in[16].sensor_type = 192;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[17].flags = 89;
  test_msg->sol_in[17].sensor_type = 208;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[18].flags = 10;
  test_msg->sol_in[18].sensor_type = 56;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[19].flags = 2;
  test_msg->sol_in[19].sensor_type = 245;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[20].flags = 201;
  test_msg->sol_in[20].sensor_type = 254;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[21].flags = 32;
  test_msg->sol_in[21].sensor_type = 120;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[22].flags = 2;
  test_msg->sol_in[22].sensor_type = 126;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[23].flags = 161;
  test_msg->sol_in[23].sensor_type = 83;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[24].flags = 123;
  test_msg->sol_in[24].sensor_type = 238;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[25].flags = 230;
  test_msg->sol_in[25].sensor_type = 102;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[26].flags = 190;
  test_msg->sol_in[26].sensor_type = 76;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[27].flags = 182;
  test_msg->sol_in[27].sensor_type = 225;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[28].flags = 228;
  test_msg->sol_in[28].sensor_type = 207;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[29].flags = 218;
  test_msg->sol_in[29].sensor_type = 7;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[30].flags = 89;
  test_msg->sol_in[30].sensor_type = 117;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[31].flags = 191;
  test_msg->sol_in[31].sensor_type = 29;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[32].flags = 248;
  test_msg->sol_in[32].sensor_type = 56;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[33].flags = 255;
  test_msg->sol_in[33].sensor_type = 185;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[34].flags = 18;
  test_msg->sol_in[34].sensor_type = 46;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[35].flags = 142;
  test_msg->sol_in[35].sensor_type = 72;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[36].flags = 113;
  test_msg->sol_in[36].sensor_type = 82;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[37].flags = 4;
  test_msg->sol_in[37].sensor_type = 26;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[38].flags = 254;
  test_msg->sol_in[38].sensor_type = 172;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[39].flags = 136;
  test_msg->sol_in[39].sensor_type = 178;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[40].flags = 115;
  test_msg->sol_in[40].sensor_type = 113;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[41].flags = 193;
  test_msg->sol_in[41].sensor_type = 58;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[42].flags = 227;
  test_msg->sol_in[42].sensor_type = 89;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[43].flags = 246;
  test_msg->sol_in[43].sensor_type = 182;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[44].flags = 77;
  test_msg->sol_in[44].sensor_type = 76;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[45].flags = 245;
  test_msg->sol_in[45].sensor_type = 108;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[46].flags = 31;
  test_msg->sol_in[46].sensor_type = 41;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[47].flags = 124;
  test_msg->sol_in[47].sensor_type = 70;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[48].flags = 145;
  test_msg->sol_in[48].sensor_type = 249;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[49].flags = 78;
  test_msg->sol_in[49].sensor_type = 15;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[50].flags = 38;
  test_msg->sol_in[50].sensor_type = 228;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[51].flags = 129;
  test_msg->sol_in[51].sensor_type = 241;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[52].flags = 176;
  test_msg->sol_in[52].sensor_type = 8;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[53].flags = 72;
  test_msg->sol_in[53].sensor_type = 251;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[54].flags = 80;
  test_msg->sol_in[54].sensor_type = 248;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[55].flags = 244;
  test_msg->sol_in[55].sensor_type = 115;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[56].flags = 145;
  test_msg->sol_in[56].sensor_type = 231;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[57].flags = 190;
  test_msg->sol_in[57].sensor_type = 191;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[58].flags = 168;
  test_msg->sol_in[58].sensor_type = 178;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[59].flags = 233;
  test_msg->sol_in[59].sensor_type = 89;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[60].flags = 176;
  test_msg->sol_in[60].sensor_type = 69;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[61].flags = 140;
  test_msg->sol_in[61].sensor_type = 174;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[62].flags = 141;
  test_msg->sol_in[62].sensor_type = 182;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[63].flags = 82;
  test_msg->sol_in[63].sensor_type = 81;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[64].flags = 79;
  test_msg->sol_in[64].sensor_type = 92;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[65].flags = 223;
  test_msg->sol_in[65].sensor_type = 101;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[66].flags = 64;
  test_msg->sol_in[66].sensor_type = 100;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[67].flags = 215;
  test_msg->sol_in[67].sensor_type = 184;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[68].flags = 37;
  test_msg->sol_in[68].sensor_type = 124;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[69].flags = 227;
  test_msg->sol_in[69].sensor_type = 21;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[70].flags = 102;
  test_msg->sol_in[70].sensor_type = 135;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[71].flags = 36;
  test_msg->sol_in[71].sensor_type = 72;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[72].flags = 56;
  test_msg->sol_in[72].sensor_type = 219;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[73].flags = 90;
  test_msg->sol_in[73].sensor_type = 146;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[74].flags = 104;
  test_msg->sol_in[74].sensor_type = 219;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[75].flags = 102;
  test_msg->sol_in[75].sensor_type = 227;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[76].flags = 12;
  test_msg->sol_in[76].sensor_type = 83;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[77].flags = 122;
  test_msg->sol_in[77].sensor_type = 41;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[78].flags = 94;
  test_msg->sol_in[78].sensor_type = 173;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[79].flags = 174;
  test_msg->sol_in[79].sensor_type = 1;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[80].flags = 130;
  test_msg->sol_in[80].sensor_type = 134;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[81].flags = 237;
  test_msg->sol_in[81].sensor_type = 104;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[82].flags = 249;
  test_msg->sol_in[82].sensor_type = 116;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[83].flags = 230;
  test_msg->sol_in[83].sensor_type = 107;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[84].flags = 123;
  test_msg->sol_in[84].sensor_type = 130;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[85].flags = 162;
  test_msg->sol_in[85].sensor_type = 25;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[86].flags = 223;
  test_msg->sol_in[86].sensor_type = 57;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[87].flags = 174;
  test_msg->sol_in[87].sensor_type = 193;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[88].flags = 193;
  test_msg->sol_in[88].sensor_type = 146;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[89].flags = 44;
  test_msg->sol_in[89].sensor_type = 239;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[90].flags = 197;
  test_msg->sol_in[90].sensor_type = 246;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[91].flags = 80;
  test_msg->sol_in[91].sensor_type = 214;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[92].flags = 100;
  test_msg->sol_in[92].sensor_type = 83;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[93].flags = 72;
  test_msg->sol_in[93].sensor_type = 66;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[94].flags = 137;
  test_msg->sol_in[94].sensor_type = 133;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[95].flags = 82;
  test_msg->sol_in[95].sensor_type = 140;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[96].flags = 2;
  test_msg->sol_in[96].sensor_type = 2;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[97].flags = 9;
  test_msg->sol_in[97].sensor_type = 96;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[98].flags = 158;
  test_msg->sol_in[98].sensor_type = 96;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[99].flags = 97;
  test_msg->sol_in[99].sensor_type = 134;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[100].flags = 129;
  test_msg->sol_in[100].sensor_type = 43;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[101].flags = 25;
  test_msg->sol_in[101].sensor_type = 141;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[102].flags = 200;
  test_msg->sol_in[102].sensor_type = 183;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[103].flags = 57;
  test_msg->sol_in[103].sensor_type = 214;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[104].flags = 103;
  test_msg->sol_in[104].sensor_type = 248;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[105].flags = 65;
  test_msg->sol_in[105].sensor_type = 222;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[106].flags = 15;
  test_msg->sol_in[106].sensor_type = 195;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[107].flags = 21;
  test_msg->sol_in[107].sensor_type = 244;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[108].flags = 46;
  test_msg->sol_in[108].sensor_type = 180;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[109].flags = 130;
  test_msg->sol_in[109].sensor_type = 140;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[110].flags = 17;
  test_msg->sol_in[110].sensor_type = 36;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[111].flags = 209;
  test_msg->sol_in[111].sensor_type = 194;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[112].flags = 254;
  test_msg->sol_in[112].sensor_type = 65;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[113].flags = 103;
  test_msg->sol_in[113].sensor_type = 115;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[114].flags = 129;
  test_msg->sol_in[114].sensor_type = 152;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[115].flags = 235;
  test_msg->sol_in[115].sensor_type = 234;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[116].flags = 234;
  test_msg->sol_in[116].sensor_type = 194;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[117].flags = 201;
  test_msg->sol_in[117].sensor_type = 170;
  if (sizeof(test_msg->sol_in) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sol_in[0]));
  }
  test_msg->sol_in[118].flags = 154;
  test_msg->sol_in[118].sensor_type = 210;
  test_msg->tow = 3628191792;
  test_msg->vdop = 58512;

  EXPECT_EQ(send_message(0xff0e, 15360, test_msg_len, test_msg_storage),
            SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 15360);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(get_as<decltype(last_msg_->age_corrections)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->age_corrections)),
            21256)
      << "incorrect value for age_corrections, expected 21256, is "
      << last_msg_->age_corrections;
  EXPECT_EQ(get_as<decltype(last_msg_->age_gnss)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->age_gnss)),
            3573765977)
      << "incorrect value for age_gnss, expected 3573765977, is "
      << last_msg_->age_gnss;
  EXPECT_EQ(get_as<decltype(last_msg_->hdop)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->hdop)),
            41156)
      << "incorrect value for hdop, expected 41156, is " << last_msg_->hdop;
  EXPECT_EQ(get_as<decltype(last_msg_->pdop)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->pdop)),
            11642)
      << "incorrect value for pdop, expected 11642, is " << last_msg_->pdop;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[0].flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[0].flags)),
            109)
      << "incorrect value for sol_in[0].flags, expected 109, is "
      << last_msg_->sol_in[0].flags;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[0].sensor_type)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[0].sensor_type)),
      95)
      << "incorrect value for sol_in[0].sensor_type, expected 95, is "
      << last_msg_->sol_in[0].sensor_type;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[1].flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[1].flags)),
            131)
      << "incorrect value for sol_in[1].flags, expected 131, is "
      << last_msg_->sol_in[1].flags;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[1].sensor_type)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[1].sensor_type)),
      86)
      << "incorrect value for sol_in[1].sensor_type, expected 86, is "
      << last_msg_->sol_in[1].sensor_type;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[2].flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[2].flags)),
            70)
      << "incorrect value for sol_in[2].flags, expected 70, is "
      << last_msg_->sol_in[2].flags;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[2].sensor_type)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[2].sensor_type)),
      71)
      << "incorrect value for sol_in[2].sensor_type, expected 71, is "
      << last_msg_->sol_in[2].sensor_type;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[3].flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[3].flags)),
            73)
      << "incorrect value for sol_in[3].flags, expected 73, is "
      << last_msg_->sol_in[3].flags;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[3].sensor_type)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[3].sensor_type)),
      84)
      << "incorrect value for sol_in[3].sensor_type, expected 84, is "
      << last_msg_->sol_in[3].sensor_type;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[4].flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[4].flags)),
            26)
      << "incorrect value for sol_in[4].flags, expected 26, is "
      << last_msg_->sol_in[4].flags;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[4].sensor_type)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[4].sensor_type)),
      131)
      << "incorrect value for sol_in[4].sensor_type, expected 131, is "
      << last_msg_->sol_in[4].sensor_type;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[5].flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[5].flags)),
            247)
      << "incorrect value for sol_in[5].flags, expected 247, is "
      << last_msg_->sol_in[5].flags;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[5].sensor_type)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[5].sensor_type)),
      82)
      << "incorrect value for sol_in[5].sensor_type, expected 82, is "
      << last_msg_->sol_in[5].sensor_type;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[6].flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[6].flags)),
            97)
      << "incorrect value for sol_in[6].flags, expected 97, is "
      << last_msg_->sol_in[6].flags;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[6].sensor_type)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[6].sensor_type)),
      140)
      << "incorrect value for sol_in[6].sensor_type, expected 140, is "
      << last_msg_->sol_in[6].sensor_type;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[7].flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[7].flags)),
            110)
      << "incorrect value for sol_in[7].flags, expected 110, is "
      << last_msg_->sol_in[7].flags;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[7].sensor_type)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[7].sensor_type)),
      115)
      << "incorrect value for sol_in[7].sensor_type, expected 115, is "
      << last_msg_->sol_in[7].sensor_type;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[8].flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[8].flags)),
            253)
      << "incorrect value for sol_in[8].flags, expected 253, is "
      << last_msg_->sol_in[8].flags;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[8].sensor_type)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[8].sensor_type)),
      118)
      << "incorrect value for sol_in[8].sensor_type, expected 118, is "
      << last_msg_->sol_in[8].sensor_type;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[9].flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[9].flags)),
            122)
      << "incorrect value for sol_in[9].flags, expected 122, is "
      << last_msg_->sol_in[9].flags;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[9].sensor_type)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[9].sensor_type)),
      2)
      << "incorrect value for sol_in[9].sensor_type, expected 2, is "
      << last_msg_->sol_in[9].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[10].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[10].flags)),
      148)
      << "incorrect value for sol_in[10].flags, expected 148, is "
      << last_msg_->sol_in[10].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[10].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[10].sensor_type)),
            186)
      << "incorrect value for sol_in[10].sensor_type, expected 186, is "
      << last_msg_->sol_in[10].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[11].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[11].flags)),
      148)
      << "incorrect value for sol_in[11].flags, expected 148, is "
      << last_msg_->sol_in[11].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[11].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[11].sensor_type)),
            122)
      << "incorrect value for sol_in[11].sensor_type, expected 122, is "
      << last_msg_->sol_in[11].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[12].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[12].flags)),
      231)
      << "incorrect value for sol_in[12].flags, expected 231, is "
      << last_msg_->sol_in[12].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[12].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[12].sensor_type)),
            180)
      << "incorrect value for sol_in[12].sensor_type, expected 180, is "
      << last_msg_->sol_in[12].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[13].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[13].flags)),
      46)
      << "incorrect value for sol_in[13].flags, expected 46, is "
      << last_msg_->sol_in[13].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[13].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[13].sensor_type)),
            68)
      << "incorrect value for sol_in[13].sensor_type, expected 68, is "
      << last_msg_->sol_in[13].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[14].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[14].flags)),
      102)
      << "incorrect value for sol_in[14].flags, expected 102, is "
      << last_msg_->sol_in[14].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[14].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[14].sensor_type)),
            190)
      << "incorrect value for sol_in[14].sensor_type, expected 190, is "
      << last_msg_->sol_in[14].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[15].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[15].flags)),
      48)
      << "incorrect value for sol_in[15].flags, expected 48, is "
      << last_msg_->sol_in[15].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[15].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[15].sensor_type)),
            243)
      << "incorrect value for sol_in[15].sensor_type, expected 243, is "
      << last_msg_->sol_in[15].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[16].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[16].flags)),
      15)
      << "incorrect value for sol_in[16].flags, expected 15, is "
      << last_msg_->sol_in[16].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[16].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[16].sensor_type)),
            192)
      << "incorrect value for sol_in[16].sensor_type, expected 192, is "
      << last_msg_->sol_in[16].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[17].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[17].flags)),
      89)
      << "incorrect value for sol_in[17].flags, expected 89, is "
      << last_msg_->sol_in[17].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[17].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[17].sensor_type)),
            208)
      << "incorrect value for sol_in[17].sensor_type, expected 208, is "
      << last_msg_->sol_in[17].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[18].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[18].flags)),
      10)
      << "incorrect value for sol_in[18].flags, expected 10, is "
      << last_msg_->sol_in[18].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[18].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[18].sensor_type)),
            56)
      << "incorrect value for sol_in[18].sensor_type, expected 56, is "
      << last_msg_->sol_in[18].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[19].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[19].flags)),
      2)
      << "incorrect value for sol_in[19].flags, expected 2, is "
      << last_msg_->sol_in[19].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[19].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[19].sensor_type)),
            245)
      << "incorrect value for sol_in[19].sensor_type, expected 245, is "
      << last_msg_->sol_in[19].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[20].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[20].flags)),
      201)
      << "incorrect value for sol_in[20].flags, expected 201, is "
      << last_msg_->sol_in[20].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[20].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[20].sensor_type)),
            254)
      << "incorrect value for sol_in[20].sensor_type, expected 254, is "
      << last_msg_->sol_in[20].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[21].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[21].flags)),
      32)
      << "incorrect value for sol_in[21].flags, expected 32, is "
      << last_msg_->sol_in[21].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[21].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[21].sensor_type)),
            120)
      << "incorrect value for sol_in[21].sensor_type, expected 120, is "
      << last_msg_->sol_in[21].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[22].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[22].flags)),
      2)
      << "incorrect value for sol_in[22].flags, expected 2, is "
      << last_msg_->sol_in[22].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[22].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[22].sensor_type)),
            126)
      << "incorrect value for sol_in[22].sensor_type, expected 126, is "
      << last_msg_->sol_in[22].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[23].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[23].flags)),
      161)
      << "incorrect value for sol_in[23].flags, expected 161, is "
      << last_msg_->sol_in[23].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[23].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[23].sensor_type)),
            83)
      << "incorrect value for sol_in[23].sensor_type, expected 83, is "
      << last_msg_->sol_in[23].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[24].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[24].flags)),
      123)
      << "incorrect value for sol_in[24].flags, expected 123, is "
      << last_msg_->sol_in[24].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[24].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[24].sensor_type)),
            238)
      << "incorrect value for sol_in[24].sensor_type, expected 238, is "
      << last_msg_->sol_in[24].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[25].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[25].flags)),
      230)
      << "incorrect value for sol_in[25].flags, expected 230, is "
      << last_msg_->sol_in[25].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[25].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[25].sensor_type)),
            102)
      << "incorrect value for sol_in[25].sensor_type, expected 102, is "
      << last_msg_->sol_in[25].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[26].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[26].flags)),
      190)
      << "incorrect value for sol_in[26].flags, expected 190, is "
      << last_msg_->sol_in[26].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[26].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[26].sensor_type)),
            76)
      << "incorrect value for sol_in[26].sensor_type, expected 76, is "
      << last_msg_->sol_in[26].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[27].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[27].flags)),
      182)
      << "incorrect value for sol_in[27].flags, expected 182, is "
      << last_msg_->sol_in[27].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[27].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[27].sensor_type)),
            225)
      << "incorrect value for sol_in[27].sensor_type, expected 225, is "
      << last_msg_->sol_in[27].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[28].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[28].flags)),
      228)
      << "incorrect value for sol_in[28].flags, expected 228, is "
      << last_msg_->sol_in[28].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[28].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[28].sensor_type)),
            207)
      << "incorrect value for sol_in[28].sensor_type, expected 207, is "
      << last_msg_->sol_in[28].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[29].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[29].flags)),
      218)
      << "incorrect value for sol_in[29].flags, expected 218, is "
      << last_msg_->sol_in[29].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[29].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[29].sensor_type)),
            7)
      << "incorrect value for sol_in[29].sensor_type, expected 7, is "
      << last_msg_->sol_in[29].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[30].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[30].flags)),
      89)
      << "incorrect value for sol_in[30].flags, expected 89, is "
      << last_msg_->sol_in[30].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[30].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[30].sensor_type)),
            117)
      << "incorrect value for sol_in[30].sensor_type, expected 117, is "
      << last_msg_->sol_in[30].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[31].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[31].flags)),
      191)
      << "incorrect value for sol_in[31].flags, expected 191, is "
      << last_msg_->sol_in[31].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[31].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[31].sensor_type)),
            29)
      << "incorrect value for sol_in[31].sensor_type, expected 29, is "
      << last_msg_->sol_in[31].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[32].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[32].flags)),
      248)
      << "incorrect value for sol_in[32].flags, expected 248, is "
      << last_msg_->sol_in[32].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[32].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[32].sensor_type)),
            56)
      << "incorrect value for sol_in[32].sensor_type, expected 56, is "
      << last_msg_->sol_in[32].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[33].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[33].flags)),
      255)
      << "incorrect value for sol_in[33].flags, expected 255, is "
      << last_msg_->sol_in[33].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[33].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[33].sensor_type)),
            185)
      << "incorrect value for sol_in[33].sensor_type, expected 185, is "
      << last_msg_->sol_in[33].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[34].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[34].flags)),
      18)
      << "incorrect value for sol_in[34].flags, expected 18, is "
      << last_msg_->sol_in[34].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[34].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[34].sensor_type)),
            46)
      << "incorrect value for sol_in[34].sensor_type, expected 46, is "
      << last_msg_->sol_in[34].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[35].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[35].flags)),
      142)
      << "incorrect value for sol_in[35].flags, expected 142, is "
      << last_msg_->sol_in[35].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[35].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[35].sensor_type)),
            72)
      << "incorrect value for sol_in[35].sensor_type, expected 72, is "
      << last_msg_->sol_in[35].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[36].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[36].flags)),
      113)
      << "incorrect value for sol_in[36].flags, expected 113, is "
      << last_msg_->sol_in[36].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[36].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[36].sensor_type)),
            82)
      << "incorrect value for sol_in[36].sensor_type, expected 82, is "
      << last_msg_->sol_in[36].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[37].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[37].flags)),
      4)
      << "incorrect value for sol_in[37].flags, expected 4, is "
      << last_msg_->sol_in[37].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[37].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[37].sensor_type)),
            26)
      << "incorrect value for sol_in[37].sensor_type, expected 26, is "
      << last_msg_->sol_in[37].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[38].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[38].flags)),
      254)
      << "incorrect value for sol_in[38].flags, expected 254, is "
      << last_msg_->sol_in[38].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[38].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[38].sensor_type)),
            172)
      << "incorrect value for sol_in[38].sensor_type, expected 172, is "
      << last_msg_->sol_in[38].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[39].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[39].flags)),
      136)
      << "incorrect value for sol_in[39].flags, expected 136, is "
      << last_msg_->sol_in[39].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[39].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[39].sensor_type)),
            178)
      << "incorrect value for sol_in[39].sensor_type, expected 178, is "
      << last_msg_->sol_in[39].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[40].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[40].flags)),
      115)
      << "incorrect value for sol_in[40].flags, expected 115, is "
      << last_msg_->sol_in[40].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[40].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[40].sensor_type)),
            113)
      << "incorrect value for sol_in[40].sensor_type, expected 113, is "
      << last_msg_->sol_in[40].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[41].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[41].flags)),
      193)
      << "incorrect value for sol_in[41].flags, expected 193, is "
      << last_msg_->sol_in[41].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[41].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[41].sensor_type)),
            58)
      << "incorrect value for sol_in[41].sensor_type, expected 58, is "
      << last_msg_->sol_in[41].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[42].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[42].flags)),
      227)
      << "incorrect value for sol_in[42].flags, expected 227, is "
      << last_msg_->sol_in[42].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[42].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[42].sensor_type)),
            89)
      << "incorrect value for sol_in[42].sensor_type, expected 89, is "
      << last_msg_->sol_in[42].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[43].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[43].flags)),
      246)
      << "incorrect value for sol_in[43].flags, expected 246, is "
      << last_msg_->sol_in[43].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[43].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[43].sensor_type)),
            182)
      << "incorrect value for sol_in[43].sensor_type, expected 182, is "
      << last_msg_->sol_in[43].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[44].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[44].flags)),
      77)
      << "incorrect value for sol_in[44].flags, expected 77, is "
      << last_msg_->sol_in[44].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[44].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[44].sensor_type)),
            76)
      << "incorrect value for sol_in[44].sensor_type, expected 76, is "
      << last_msg_->sol_in[44].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[45].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[45].flags)),
      245)
      << "incorrect value for sol_in[45].flags, expected 245, is "
      << last_msg_->sol_in[45].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[45].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[45].sensor_type)),
            108)
      << "incorrect value for sol_in[45].sensor_type, expected 108, is "
      << last_msg_->sol_in[45].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[46].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[46].flags)),
      31)
      << "incorrect value for sol_in[46].flags, expected 31, is "
      << last_msg_->sol_in[46].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[46].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[46].sensor_type)),
            41)
      << "incorrect value for sol_in[46].sensor_type, expected 41, is "
      << last_msg_->sol_in[46].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[47].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[47].flags)),
      124)
      << "incorrect value for sol_in[47].flags, expected 124, is "
      << last_msg_->sol_in[47].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[47].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[47].sensor_type)),
            70)
      << "incorrect value for sol_in[47].sensor_type, expected 70, is "
      << last_msg_->sol_in[47].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[48].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[48].flags)),
      145)
      << "incorrect value for sol_in[48].flags, expected 145, is "
      << last_msg_->sol_in[48].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[48].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[48].sensor_type)),
            249)
      << "incorrect value for sol_in[48].sensor_type, expected 249, is "
      << last_msg_->sol_in[48].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[49].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[49].flags)),
      78)
      << "incorrect value for sol_in[49].flags, expected 78, is "
      << last_msg_->sol_in[49].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[49].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[49].sensor_type)),
            15)
      << "incorrect value for sol_in[49].sensor_type, expected 15, is "
      << last_msg_->sol_in[49].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[50].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[50].flags)),
      38)
      << "incorrect value for sol_in[50].flags, expected 38, is "
      << last_msg_->sol_in[50].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[50].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[50].sensor_type)),
            228)
      << "incorrect value for sol_in[50].sensor_type, expected 228, is "
      << last_msg_->sol_in[50].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[51].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[51].flags)),
      129)
      << "incorrect value for sol_in[51].flags, expected 129, is "
      << last_msg_->sol_in[51].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[51].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[51].sensor_type)),
            241)
      << "incorrect value for sol_in[51].sensor_type, expected 241, is "
      << last_msg_->sol_in[51].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[52].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[52].flags)),
      176)
      << "incorrect value for sol_in[52].flags, expected 176, is "
      << last_msg_->sol_in[52].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[52].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[52].sensor_type)),
            8)
      << "incorrect value for sol_in[52].sensor_type, expected 8, is "
      << last_msg_->sol_in[52].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[53].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[53].flags)),
      72)
      << "incorrect value for sol_in[53].flags, expected 72, is "
      << last_msg_->sol_in[53].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[53].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[53].sensor_type)),
            251)
      << "incorrect value for sol_in[53].sensor_type, expected 251, is "
      << last_msg_->sol_in[53].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[54].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[54].flags)),
      80)
      << "incorrect value for sol_in[54].flags, expected 80, is "
      << last_msg_->sol_in[54].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[54].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[54].sensor_type)),
            248)
      << "incorrect value for sol_in[54].sensor_type, expected 248, is "
      << last_msg_->sol_in[54].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[55].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[55].flags)),
      244)
      << "incorrect value for sol_in[55].flags, expected 244, is "
      << last_msg_->sol_in[55].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[55].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[55].sensor_type)),
            115)
      << "incorrect value for sol_in[55].sensor_type, expected 115, is "
      << last_msg_->sol_in[55].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[56].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[56].flags)),
      145)
      << "incorrect value for sol_in[56].flags, expected 145, is "
      << last_msg_->sol_in[56].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[56].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[56].sensor_type)),
            231)
      << "incorrect value for sol_in[56].sensor_type, expected 231, is "
      << last_msg_->sol_in[56].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[57].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[57].flags)),
      190)
      << "incorrect value for sol_in[57].flags, expected 190, is "
      << last_msg_->sol_in[57].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[57].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[57].sensor_type)),
            191)
      << "incorrect value for sol_in[57].sensor_type, expected 191, is "
      << last_msg_->sol_in[57].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[58].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[58].flags)),
      168)
      << "incorrect value for sol_in[58].flags, expected 168, is "
      << last_msg_->sol_in[58].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[58].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[58].sensor_type)),
            178)
      << "incorrect value for sol_in[58].sensor_type, expected 178, is "
      << last_msg_->sol_in[58].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[59].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[59].flags)),
      233)
      << "incorrect value for sol_in[59].flags, expected 233, is "
      << last_msg_->sol_in[59].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[59].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[59].sensor_type)),
            89)
      << "incorrect value for sol_in[59].sensor_type, expected 89, is "
      << last_msg_->sol_in[59].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[60].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[60].flags)),
      176)
      << "incorrect value for sol_in[60].flags, expected 176, is "
      << last_msg_->sol_in[60].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[60].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[60].sensor_type)),
            69)
      << "incorrect value for sol_in[60].sensor_type, expected 69, is "
      << last_msg_->sol_in[60].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[61].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[61].flags)),
      140)
      << "incorrect value for sol_in[61].flags, expected 140, is "
      << last_msg_->sol_in[61].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[61].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[61].sensor_type)),
            174)
      << "incorrect value for sol_in[61].sensor_type, expected 174, is "
      << last_msg_->sol_in[61].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[62].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[62].flags)),
      141)
      << "incorrect value for sol_in[62].flags, expected 141, is "
      << last_msg_->sol_in[62].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[62].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[62].sensor_type)),
            182)
      << "incorrect value for sol_in[62].sensor_type, expected 182, is "
      << last_msg_->sol_in[62].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[63].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[63].flags)),
      82)
      << "incorrect value for sol_in[63].flags, expected 82, is "
      << last_msg_->sol_in[63].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[63].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[63].sensor_type)),
            81)
      << "incorrect value for sol_in[63].sensor_type, expected 81, is "
      << last_msg_->sol_in[63].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[64].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[64].flags)),
      79)
      << "incorrect value for sol_in[64].flags, expected 79, is "
      << last_msg_->sol_in[64].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[64].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[64].sensor_type)),
            92)
      << "incorrect value for sol_in[64].sensor_type, expected 92, is "
      << last_msg_->sol_in[64].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[65].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[65].flags)),
      223)
      << "incorrect value for sol_in[65].flags, expected 223, is "
      << last_msg_->sol_in[65].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[65].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[65].sensor_type)),
            101)
      << "incorrect value for sol_in[65].sensor_type, expected 101, is "
      << last_msg_->sol_in[65].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[66].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[66].flags)),
      64)
      << "incorrect value for sol_in[66].flags, expected 64, is "
      << last_msg_->sol_in[66].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[66].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[66].sensor_type)),
            100)
      << "incorrect value for sol_in[66].sensor_type, expected 100, is "
      << last_msg_->sol_in[66].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[67].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[67].flags)),
      215)
      << "incorrect value for sol_in[67].flags, expected 215, is "
      << last_msg_->sol_in[67].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[67].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[67].sensor_type)),
            184)
      << "incorrect value for sol_in[67].sensor_type, expected 184, is "
      << last_msg_->sol_in[67].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[68].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[68].flags)),
      37)
      << "incorrect value for sol_in[68].flags, expected 37, is "
      << last_msg_->sol_in[68].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[68].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[68].sensor_type)),
            124)
      << "incorrect value for sol_in[68].sensor_type, expected 124, is "
      << last_msg_->sol_in[68].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[69].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[69].flags)),
      227)
      << "incorrect value for sol_in[69].flags, expected 227, is "
      << last_msg_->sol_in[69].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[69].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[69].sensor_type)),
            21)
      << "incorrect value for sol_in[69].sensor_type, expected 21, is "
      << last_msg_->sol_in[69].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[70].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[70].flags)),
      102)
      << "incorrect value for sol_in[70].flags, expected 102, is "
      << last_msg_->sol_in[70].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[70].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[70].sensor_type)),
            135)
      << "incorrect value for sol_in[70].sensor_type, expected 135, is "
      << last_msg_->sol_in[70].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[71].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[71].flags)),
      36)
      << "incorrect value for sol_in[71].flags, expected 36, is "
      << last_msg_->sol_in[71].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[71].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[71].sensor_type)),
            72)
      << "incorrect value for sol_in[71].sensor_type, expected 72, is "
      << last_msg_->sol_in[71].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[72].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[72].flags)),
      56)
      << "incorrect value for sol_in[72].flags, expected 56, is "
      << last_msg_->sol_in[72].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[72].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[72].sensor_type)),
            219)
      << "incorrect value for sol_in[72].sensor_type, expected 219, is "
      << last_msg_->sol_in[72].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[73].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[73].flags)),
      90)
      << "incorrect value for sol_in[73].flags, expected 90, is "
      << last_msg_->sol_in[73].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[73].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[73].sensor_type)),
            146)
      << "incorrect value for sol_in[73].sensor_type, expected 146, is "
      << last_msg_->sol_in[73].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[74].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[74].flags)),
      104)
      << "incorrect value for sol_in[74].flags, expected 104, is "
      << last_msg_->sol_in[74].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[74].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[74].sensor_type)),
            219)
      << "incorrect value for sol_in[74].sensor_type, expected 219, is "
      << last_msg_->sol_in[74].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[75].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[75].flags)),
      102)
      << "incorrect value for sol_in[75].flags, expected 102, is "
      << last_msg_->sol_in[75].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[75].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[75].sensor_type)),
            227)
      << "incorrect value for sol_in[75].sensor_type, expected 227, is "
      << last_msg_->sol_in[75].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[76].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[76].flags)),
      12)
      << "incorrect value for sol_in[76].flags, expected 12, is "
      << last_msg_->sol_in[76].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[76].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[76].sensor_type)),
            83)
      << "incorrect value for sol_in[76].sensor_type, expected 83, is "
      << last_msg_->sol_in[76].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[77].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[77].flags)),
      122)
      << "incorrect value for sol_in[77].flags, expected 122, is "
      << last_msg_->sol_in[77].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[77].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[77].sensor_type)),
            41)
      << "incorrect value for sol_in[77].sensor_type, expected 41, is "
      << last_msg_->sol_in[77].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[78].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[78].flags)),
      94)
      << "incorrect value for sol_in[78].flags, expected 94, is "
      << last_msg_->sol_in[78].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[78].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[78].sensor_type)),
            173)
      << "incorrect value for sol_in[78].sensor_type, expected 173, is "
      << last_msg_->sol_in[78].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[79].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[79].flags)),
      174)
      << "incorrect value for sol_in[79].flags, expected 174, is "
      << last_msg_->sol_in[79].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[79].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[79].sensor_type)),
            1)
      << "incorrect value for sol_in[79].sensor_type, expected 1, is "
      << last_msg_->sol_in[79].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[80].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[80].flags)),
      130)
      << "incorrect value for sol_in[80].flags, expected 130, is "
      << last_msg_->sol_in[80].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[80].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[80].sensor_type)),
            134)
      << "incorrect value for sol_in[80].sensor_type, expected 134, is "
      << last_msg_->sol_in[80].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[81].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[81].flags)),
      237)
      << "incorrect value for sol_in[81].flags, expected 237, is "
      << last_msg_->sol_in[81].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[81].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[81].sensor_type)),
            104)
      << "incorrect value for sol_in[81].sensor_type, expected 104, is "
      << last_msg_->sol_in[81].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[82].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[82].flags)),
      249)
      << "incorrect value for sol_in[82].flags, expected 249, is "
      << last_msg_->sol_in[82].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[82].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[82].sensor_type)),
            116)
      << "incorrect value for sol_in[82].sensor_type, expected 116, is "
      << last_msg_->sol_in[82].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[83].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[83].flags)),
      230)
      << "incorrect value for sol_in[83].flags, expected 230, is "
      << last_msg_->sol_in[83].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[83].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[83].sensor_type)),
            107)
      << "incorrect value for sol_in[83].sensor_type, expected 107, is "
      << last_msg_->sol_in[83].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[84].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[84].flags)),
      123)
      << "incorrect value for sol_in[84].flags, expected 123, is "
      << last_msg_->sol_in[84].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[84].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[84].sensor_type)),
            130)
      << "incorrect value for sol_in[84].sensor_type, expected 130, is "
      << last_msg_->sol_in[84].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[85].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[85].flags)),
      162)
      << "incorrect value for sol_in[85].flags, expected 162, is "
      << last_msg_->sol_in[85].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[85].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[85].sensor_type)),
            25)
      << "incorrect value for sol_in[85].sensor_type, expected 25, is "
      << last_msg_->sol_in[85].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[86].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[86].flags)),
      223)
      << "incorrect value for sol_in[86].flags, expected 223, is "
      << last_msg_->sol_in[86].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[86].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[86].sensor_type)),
            57)
      << "incorrect value for sol_in[86].sensor_type, expected 57, is "
      << last_msg_->sol_in[86].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[87].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[87].flags)),
      174)
      << "incorrect value for sol_in[87].flags, expected 174, is "
      << last_msg_->sol_in[87].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[87].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[87].sensor_type)),
            193)
      << "incorrect value for sol_in[87].sensor_type, expected 193, is "
      << last_msg_->sol_in[87].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[88].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[88].flags)),
      193)
      << "incorrect value for sol_in[88].flags, expected 193, is "
      << last_msg_->sol_in[88].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[88].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[88].sensor_type)),
            146)
      << "incorrect value for sol_in[88].sensor_type, expected 146, is "
      << last_msg_->sol_in[88].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[89].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[89].flags)),
      44)
      << "incorrect value for sol_in[89].flags, expected 44, is "
      << last_msg_->sol_in[89].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[89].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[89].sensor_type)),
            239)
      << "incorrect value for sol_in[89].sensor_type, expected 239, is "
      << last_msg_->sol_in[89].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[90].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[90].flags)),
      197)
      << "incorrect value for sol_in[90].flags, expected 197, is "
      << last_msg_->sol_in[90].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[90].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[90].sensor_type)),
            246)
      << "incorrect value for sol_in[90].sensor_type, expected 246, is "
      << last_msg_->sol_in[90].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[91].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[91].flags)),
      80)
      << "incorrect value for sol_in[91].flags, expected 80, is "
      << last_msg_->sol_in[91].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[91].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[91].sensor_type)),
            214)
      << "incorrect value for sol_in[91].sensor_type, expected 214, is "
      << last_msg_->sol_in[91].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[92].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[92].flags)),
      100)
      << "incorrect value for sol_in[92].flags, expected 100, is "
      << last_msg_->sol_in[92].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[92].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[92].sensor_type)),
            83)
      << "incorrect value for sol_in[92].sensor_type, expected 83, is "
      << last_msg_->sol_in[92].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[93].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[93].flags)),
      72)
      << "incorrect value for sol_in[93].flags, expected 72, is "
      << last_msg_->sol_in[93].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[93].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[93].sensor_type)),
            66)
      << "incorrect value for sol_in[93].sensor_type, expected 66, is "
      << last_msg_->sol_in[93].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[94].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[94].flags)),
      137)
      << "incorrect value for sol_in[94].flags, expected 137, is "
      << last_msg_->sol_in[94].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[94].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[94].sensor_type)),
            133)
      << "incorrect value for sol_in[94].sensor_type, expected 133, is "
      << last_msg_->sol_in[94].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[95].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[95].flags)),
      82)
      << "incorrect value for sol_in[95].flags, expected 82, is "
      << last_msg_->sol_in[95].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[95].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[95].sensor_type)),
            140)
      << "incorrect value for sol_in[95].sensor_type, expected 140, is "
      << last_msg_->sol_in[95].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[96].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[96].flags)),
      2)
      << "incorrect value for sol_in[96].flags, expected 2, is "
      << last_msg_->sol_in[96].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[96].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[96].sensor_type)),
            2)
      << "incorrect value for sol_in[96].sensor_type, expected 2, is "
      << last_msg_->sol_in[96].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[97].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[97].flags)),
      9)
      << "incorrect value for sol_in[97].flags, expected 9, is "
      << last_msg_->sol_in[97].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[97].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[97].sensor_type)),
            96)
      << "incorrect value for sol_in[97].sensor_type, expected 96, is "
      << last_msg_->sol_in[97].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[98].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[98].flags)),
      158)
      << "incorrect value for sol_in[98].flags, expected 158, is "
      << last_msg_->sol_in[98].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[98].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[98].sensor_type)),
            96)
      << "incorrect value for sol_in[98].sensor_type, expected 96, is "
      << last_msg_->sol_in[98].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[99].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[99].flags)),
      97)
      << "incorrect value for sol_in[99].flags, expected 97, is "
      << last_msg_->sol_in[99].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[99].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[99].sensor_type)),
            134)
      << "incorrect value for sol_in[99].sensor_type, expected 134, is "
      << last_msg_->sol_in[99].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[100].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[100].flags)),
      129)
      << "incorrect value for sol_in[100].flags, expected 129, is "
      << last_msg_->sol_in[100].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[100].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[100].sensor_type)),
            43)
      << "incorrect value for sol_in[100].sensor_type, expected 43, is "
      << last_msg_->sol_in[100].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[101].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[101].flags)),
      25)
      << "incorrect value for sol_in[101].flags, expected 25, is "
      << last_msg_->sol_in[101].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[101].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[101].sensor_type)),
            141)
      << "incorrect value for sol_in[101].sensor_type, expected 141, is "
      << last_msg_->sol_in[101].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[102].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[102].flags)),
      200)
      << "incorrect value for sol_in[102].flags, expected 200, is "
      << last_msg_->sol_in[102].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[102].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[102].sensor_type)),
            183)
      << "incorrect value for sol_in[102].sensor_type, expected 183, is "
      << last_msg_->sol_in[102].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[103].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[103].flags)),
      57)
      << "incorrect value for sol_in[103].flags, expected 57, is "
      << last_msg_->sol_in[103].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[103].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[103].sensor_type)),
            214)
      << "incorrect value for sol_in[103].sensor_type, expected 214, is "
      << last_msg_->sol_in[103].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[104].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[104].flags)),
      103)
      << "incorrect value for sol_in[104].flags, expected 103, is "
      << last_msg_->sol_in[104].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[104].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[104].sensor_type)),
            248)
      << "incorrect value for sol_in[104].sensor_type, expected 248, is "
      << last_msg_->sol_in[104].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[105].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[105].flags)),
      65)
      << "incorrect value for sol_in[105].flags, expected 65, is "
      << last_msg_->sol_in[105].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[105].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[105].sensor_type)),
            222)
      << "incorrect value for sol_in[105].sensor_type, expected 222, is "
      << last_msg_->sol_in[105].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[106].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[106].flags)),
      15)
      << "incorrect value for sol_in[106].flags, expected 15, is "
      << last_msg_->sol_in[106].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[106].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[106].sensor_type)),
            195)
      << "incorrect value for sol_in[106].sensor_type, expected 195, is "
      << last_msg_->sol_in[106].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[107].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[107].flags)),
      21)
      << "incorrect value for sol_in[107].flags, expected 21, is "
      << last_msg_->sol_in[107].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[107].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[107].sensor_type)),
            244)
      << "incorrect value for sol_in[107].sensor_type, expected 244, is "
      << last_msg_->sol_in[107].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[108].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[108].flags)),
      46)
      << "incorrect value for sol_in[108].flags, expected 46, is "
      << last_msg_->sol_in[108].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[108].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[108].sensor_type)),
            180)
      << "incorrect value for sol_in[108].sensor_type, expected 180, is "
      << last_msg_->sol_in[108].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[109].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[109].flags)),
      130)
      << "incorrect value for sol_in[109].flags, expected 130, is "
      << last_msg_->sol_in[109].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[109].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[109].sensor_type)),
            140)
      << "incorrect value for sol_in[109].sensor_type, expected 140, is "
      << last_msg_->sol_in[109].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[110].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[110].flags)),
      17)
      << "incorrect value for sol_in[110].flags, expected 17, is "
      << last_msg_->sol_in[110].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[110].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[110].sensor_type)),
            36)
      << "incorrect value for sol_in[110].sensor_type, expected 36, is "
      << last_msg_->sol_in[110].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[111].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[111].flags)),
      209)
      << "incorrect value for sol_in[111].flags, expected 209, is "
      << last_msg_->sol_in[111].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[111].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[111].sensor_type)),
            194)
      << "incorrect value for sol_in[111].sensor_type, expected 194, is "
      << last_msg_->sol_in[111].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[112].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[112].flags)),
      254)
      << "incorrect value for sol_in[112].flags, expected 254, is "
      << last_msg_->sol_in[112].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[112].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[112].sensor_type)),
            65)
      << "incorrect value for sol_in[112].sensor_type, expected 65, is "
      << last_msg_->sol_in[112].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[113].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[113].flags)),
      103)
      << "incorrect value for sol_in[113].flags, expected 103, is "
      << last_msg_->sol_in[113].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[113].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[113].sensor_type)),
            115)
      << "incorrect value for sol_in[113].sensor_type, expected 115, is "
      << last_msg_->sol_in[113].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[114].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[114].flags)),
      129)
      << "incorrect value for sol_in[114].flags, expected 129, is "
      << last_msg_->sol_in[114].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[114].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[114].sensor_type)),
            152)
      << "incorrect value for sol_in[114].sensor_type, expected 152, is "
      << last_msg_->sol_in[114].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[115].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[115].flags)),
      235)
      << "incorrect value for sol_in[115].flags, expected 235, is "
      << last_msg_->sol_in[115].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[115].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[115].sensor_type)),
            234)
      << "incorrect value for sol_in[115].sensor_type, expected 234, is "
      << last_msg_->sol_in[115].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[116].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[116].flags)),
      234)
      << "incorrect value for sol_in[116].flags, expected 234, is "
      << last_msg_->sol_in[116].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[116].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[116].sensor_type)),
            194)
      << "incorrect value for sol_in[116].sensor_type, expected 194, is "
      << last_msg_->sol_in[116].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[117].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[117].flags)),
      201)
      << "incorrect value for sol_in[117].flags, expected 201, is "
      << last_msg_->sol_in[117].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[117].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[117].sensor_type)),
            170)
      << "incorrect value for sol_in[117].sensor_type, expected 170, is "
      << last_msg_->sol_in[117].sensor_type;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sol_in[118].flags)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sol_in[118].flags)),
      154)
      << "incorrect value for sol_in[118].flags, expected 154, is "
      << last_msg_->sol_in[118].flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_in[118].sensor_type)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sol_in[118].sensor_type)),
            210)
      << "incorrect value for sol_in[118].sensor_type, expected 210, is "
      << last_msg_->sol_in[118].sensor_type;
  EXPECT_EQ(get_as<decltype(last_msg_->tow)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->tow)),
            3628191792)
      << "incorrect value for tow, expected 3628191792, is " << last_msg_->tow;
  EXPECT_EQ(get_as<decltype(last_msg_->vdop)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->vdop)),
            58512)
      << "incorrect value for vdop, expected 58512, is " << last_msg_->vdop;
}
