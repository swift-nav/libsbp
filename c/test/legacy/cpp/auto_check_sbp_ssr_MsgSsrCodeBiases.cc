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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrCodeBiases.yaml by generate.py.
// Do not modify by hand!

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
class Test_legacy_auto_check_sbp_ssr_MsgSsrCodeBiases0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_ssr_code_biases_t> {
 public:
  Test_legacy_auto_check_sbp_ssr_MsgSsrCodeBiases0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_ssr_code_biases_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_ssr_code_biases_t *>(last_msg_storage_)),
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
                      const msg_ssr_code_biases_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_ssr_code_biases_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_ssr_MsgSsrCodeBiases0, Test) {
  uint8_t encoded_frame[] = {
      85,  225, 5,   39,  87,  253, 208, 90,  19,  23,  9,   66,  133, 241, 254,
      132, 51,  4,   131, 240, 120, 83,  148, 209, 213, 62,  228, 232, 71,  66,
      188, 210, 128, 54,  131, 152, 129, 111, 139, 242, 177, 145, 44,  9,   245,
      207, 241, 202, 150, 141, 50,  159, 220, 139, 37,  187, 98,  191, 23,  128,
      136, 167, 200, 6,   211, 90,  23,  244, 138, 215, 209, 139, 13,  101, 32,
      7,   18,  29,  70,  250, 109, 73,  202, 79,  144, 9,   146, 69,  241, 52,
      22,  99,  98,  204, 3,   171, 230, 180, 75,  62,  145, 86,  130, 31,  30,
      155, 37,  18,  55,  210, 39,  127, 242, 66,  13,  237, 152, 170, 212, 15,
      246, 59,  94,  180, 195, 157, 69,  100, 119, 16,  68,  179, 175, 144, 113,
      81,  82,  30,  151, 21,  109, 41,  225, 8,   77,  164, 157, 0,   73,  30,
      6,   78,  81,  143, 116, 240, 151, 55,  185, 169, 254, 51,  39,  74,  175,
      247, 34,  97,  74,  97,  176, 48,  236, 173, 12,  174, 101, 130, 30,  169,
      193, 190, 204, 196, 123, 107, 25,  225, 74,  9,   10,  55,  3,   131, 246,
      99,  133, 34,  227, 203, 68,  18,  97,  223, 89,  192, 246, 50,  69,  91,
      10,  151, 74,  118, 110, 36,  168, 247, 160, 77,  179, 141, 178, 99,  191,
      120, 77,  192, 91,  224, 1,   226, 50,  87,  146, 148, 238, 100, 179, 125,
      227, 215, 104, 184, 31,  57,  90,  79,  21,  156, 245, 81,  60,  93,  170,
      60,  200, 167, 13,  125, 132,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_ssr_code_biases_t *test_msg = (msg_ssr_code_biases_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[0].code = 51;
  test_msg->biases[0].value = -31996;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[1].code = 240;
  test_msg->biases[1].value = 21368;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[2].code = 148;
  test_msg->biases[2].value = -10799;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[3].code = 62;
  test_msg->biases[3].value = -5916;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[4].code = 71;
  test_msg->biases[4].value = -17342;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[5].code = 210;
  test_msg->biases[5].value = 13952;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[6].code = 131;
  test_msg->biases[6].value = -32360;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[7].code = 111;
  test_msg->biases[7].value = -3445;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[8].code = 177;
  test_msg->biases[8].value = 11409;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[9].code = 9;
  test_msg->biases[9].value = -12299;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[10].code = 241;
  test_msg->biases[10].value = -26934;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[11].code = 141;
  test_msg->biases[11].value = -24782;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[12].code = 220;
  test_msg->biases[12].value = 9611;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[13].code = 187;
  test_msg->biases[13].value = -16542;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[14].code = 23;
  test_msg->biases[14].value = -30592;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[15].code = 167;
  test_msg->biases[15].value = 1736;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[16].code = 211;
  test_msg->biases[16].value = 5978;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[17].code = 244;
  test_msg->biases[17].value = -10358;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[18].code = 209;
  test_msg->biases[18].value = 3467;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[19].code = 101;
  test_msg->biases[19].value = 1824;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[20].code = 18;
  test_msg->biases[20].value = 17949;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[21].code = 250;
  test_msg->biases[21].value = 18797;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[22].code = 202;
  test_msg->biases[22].value = -28593;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[23].code = 9;
  test_msg->biases[23].value = 17810;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[24].code = 241;
  test_msg->biases[24].value = 5684;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[25].code = 99;
  test_msg->biases[25].value = -13214;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[26].code = 3;
  test_msg->biases[26].value = -6485;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[27].code = 180;
  test_msg->biases[27].value = 15947;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[28].code = 145;
  test_msg->biases[28].value = -32170;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[29].code = 31;
  test_msg->biases[29].value = -25826;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[30].code = 37;
  test_msg->biases[30].value = 14098;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[31].code = 210;
  test_msg->biases[31].value = 32551;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[32].code = 242;
  test_msg->biases[32].value = 3394;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[33].code = 237;
  test_msg->biases[33].value = -21864;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[34].code = 212;
  test_msg->biases[34].value = -2545;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[35].code = 59;
  test_msg->biases[35].value = -19362;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[36].code = 195;
  test_msg->biases[36].value = 17821;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[37].code = 100;
  test_msg->biases[37].value = 4215;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[38].code = 68;
  test_msg->biases[38].value = -20557;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[39].code = 144;
  test_msg->biases[39].value = 20849;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[40].code = 82;
  test_msg->biases[40].value = -26850;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[41].code = 21;
  test_msg->biases[41].value = 10605;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[42].code = 225;
  test_msg->biases[42].value = 19720;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[43].code = 164;
  test_msg->biases[43].value = 157;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[44].code = 73;
  test_msg->biases[44].value = 1566;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[45].code = 78;
  test_msg->biases[45].value = -28847;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[46].code = 116;
  test_msg->biases[46].value = -26640;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[47].code = 55;
  test_msg->biases[47].value = -22087;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[48].code = 254;
  test_msg->biases[48].value = 10035;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[49].code = 74;
  test_msg->biases[49].value = -2129;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[50].code = 34;
  test_msg->biases[50].value = 19041;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[51].code = 97;
  test_msg->biases[51].value = 12464;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[52].code = 236;
  test_msg->biases[52].value = 3245;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[53].code = 174;
  test_msg->biases[53].value = -32155;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[54].code = 30;
  test_msg->biases[54].value = -15959;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[55].code = 190;
  test_msg->biases[55].value = -15156;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[56].code = 123;
  test_msg->biases[56].value = 6507;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[57].code = 225;
  test_msg->biases[57].value = 2378;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[58].code = 10;
  test_msg->biases[58].value = 823;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[59].code = 131;
  test_msg->biases[59].value = 25590;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[60].code = 133;
  test_msg->biases[60].value = -7390;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[61].code = 203;
  test_msg->biases[61].value = 4676;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[62].code = 97;
  test_msg->biases[62].value = 23007;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[63].code = 192;
  test_msg->biases[63].value = 13046;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[64].code = 69;
  test_msg->biases[64].value = 2651;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[65].code = 151;
  test_msg->biases[65].value = 30282;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[66].code = 110;
  test_msg->biases[66].value = -22492;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[67].code = 247;
  test_msg->biases[67].value = 19872;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[68].code = 179;
  test_msg->biases[68].value = -19827;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[69].code = 99;
  test_msg->biases[69].value = 30911;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[70].code = 77;
  test_msg->biases[70].value = 23488;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[71].code = 224;
  test_msg->biases[71].value = -7679;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[72].code = 50;
  test_msg->biases[72].value = -28073;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[73].code = 148;
  test_msg->biases[73].value = 25838;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[74].code = 179;
  test_msg->biases[74].value = -7299;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[75].code = 215;
  test_msg->biases[75].value = -18328;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[76].code = 31;
  test_msg->biases[76].value = 23097;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[77].code = 79;
  test_msg->biases[77].value = -25579;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[78].code = 245;
  test_msg->biases[78].value = 15441;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[79].code = 93;
  test_msg->biases[79].value = 15530;
  if (sizeof(test_msg->biases) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->biases[0]));
  }
  test_msg->biases[80].code = 200;
  test_msg->biases[80].value = 3495;
  test_msg->iod_ssr = 132;
  test_msg->sid.code = 241;
  test_msg->sid.sat = 133;
  test_msg->time.tow = 387144400;
  test_msg->time.wn = 16905;
  test_msg->update_interval = 254;

  EXPECT_EQ(send_message(0x5e1, 22311, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 22311);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->biases[0].code, 51)
      << "incorrect value for biases[0].code, expected 51, is "
      << last_msg_->biases[0].code;
  EXPECT_EQ(last_msg_->biases[0].value, -31996)
      << "incorrect value for biases[0].value, expected -31996, is "
      << last_msg_->biases[0].value;
  EXPECT_EQ(last_msg_->biases[1].code, 240)
      << "incorrect value for biases[1].code, expected 240, is "
      << last_msg_->biases[1].code;
  EXPECT_EQ(last_msg_->biases[1].value, 21368)
      << "incorrect value for biases[1].value, expected 21368, is "
      << last_msg_->biases[1].value;
  EXPECT_EQ(last_msg_->biases[2].code, 148)
      << "incorrect value for biases[2].code, expected 148, is "
      << last_msg_->biases[2].code;
  EXPECT_EQ(last_msg_->biases[2].value, -10799)
      << "incorrect value for biases[2].value, expected -10799, is "
      << last_msg_->biases[2].value;
  EXPECT_EQ(last_msg_->biases[3].code, 62)
      << "incorrect value for biases[3].code, expected 62, is "
      << last_msg_->biases[3].code;
  EXPECT_EQ(last_msg_->biases[3].value, -5916)
      << "incorrect value for biases[3].value, expected -5916, is "
      << last_msg_->biases[3].value;
  EXPECT_EQ(last_msg_->biases[4].code, 71)
      << "incorrect value for biases[4].code, expected 71, is "
      << last_msg_->biases[4].code;
  EXPECT_EQ(last_msg_->biases[4].value, -17342)
      << "incorrect value for biases[4].value, expected -17342, is "
      << last_msg_->biases[4].value;
  EXPECT_EQ(last_msg_->biases[5].code, 210)
      << "incorrect value for biases[5].code, expected 210, is "
      << last_msg_->biases[5].code;
  EXPECT_EQ(last_msg_->biases[5].value, 13952)
      << "incorrect value for biases[5].value, expected 13952, is "
      << last_msg_->biases[5].value;
  EXPECT_EQ(last_msg_->biases[6].code, 131)
      << "incorrect value for biases[6].code, expected 131, is "
      << last_msg_->biases[6].code;
  EXPECT_EQ(last_msg_->biases[6].value, -32360)
      << "incorrect value for biases[6].value, expected -32360, is "
      << last_msg_->biases[6].value;
  EXPECT_EQ(last_msg_->biases[7].code, 111)
      << "incorrect value for biases[7].code, expected 111, is "
      << last_msg_->biases[7].code;
  EXPECT_EQ(last_msg_->biases[7].value, -3445)
      << "incorrect value for biases[7].value, expected -3445, is "
      << last_msg_->biases[7].value;
  EXPECT_EQ(last_msg_->biases[8].code, 177)
      << "incorrect value for biases[8].code, expected 177, is "
      << last_msg_->biases[8].code;
  EXPECT_EQ(last_msg_->biases[8].value, 11409)
      << "incorrect value for biases[8].value, expected 11409, is "
      << last_msg_->biases[8].value;
  EXPECT_EQ(last_msg_->biases[9].code, 9)
      << "incorrect value for biases[9].code, expected 9, is "
      << last_msg_->biases[9].code;
  EXPECT_EQ(last_msg_->biases[9].value, -12299)
      << "incorrect value for biases[9].value, expected -12299, is "
      << last_msg_->biases[9].value;
  EXPECT_EQ(last_msg_->biases[10].code, 241)
      << "incorrect value for biases[10].code, expected 241, is "
      << last_msg_->biases[10].code;
  EXPECT_EQ(last_msg_->biases[10].value, -26934)
      << "incorrect value for biases[10].value, expected -26934, is "
      << last_msg_->biases[10].value;
  EXPECT_EQ(last_msg_->biases[11].code, 141)
      << "incorrect value for biases[11].code, expected 141, is "
      << last_msg_->biases[11].code;
  EXPECT_EQ(last_msg_->biases[11].value, -24782)
      << "incorrect value for biases[11].value, expected -24782, is "
      << last_msg_->biases[11].value;
  EXPECT_EQ(last_msg_->biases[12].code, 220)
      << "incorrect value for biases[12].code, expected 220, is "
      << last_msg_->biases[12].code;
  EXPECT_EQ(last_msg_->biases[12].value, 9611)
      << "incorrect value for biases[12].value, expected 9611, is "
      << last_msg_->biases[12].value;
  EXPECT_EQ(last_msg_->biases[13].code, 187)
      << "incorrect value for biases[13].code, expected 187, is "
      << last_msg_->biases[13].code;
  EXPECT_EQ(last_msg_->biases[13].value, -16542)
      << "incorrect value for biases[13].value, expected -16542, is "
      << last_msg_->biases[13].value;
  EXPECT_EQ(last_msg_->biases[14].code, 23)
      << "incorrect value for biases[14].code, expected 23, is "
      << last_msg_->biases[14].code;
  EXPECT_EQ(last_msg_->biases[14].value, -30592)
      << "incorrect value for biases[14].value, expected -30592, is "
      << last_msg_->biases[14].value;
  EXPECT_EQ(last_msg_->biases[15].code, 167)
      << "incorrect value for biases[15].code, expected 167, is "
      << last_msg_->biases[15].code;
  EXPECT_EQ(last_msg_->biases[15].value, 1736)
      << "incorrect value for biases[15].value, expected 1736, is "
      << last_msg_->biases[15].value;
  EXPECT_EQ(last_msg_->biases[16].code, 211)
      << "incorrect value for biases[16].code, expected 211, is "
      << last_msg_->biases[16].code;
  EXPECT_EQ(last_msg_->biases[16].value, 5978)
      << "incorrect value for biases[16].value, expected 5978, is "
      << last_msg_->biases[16].value;
  EXPECT_EQ(last_msg_->biases[17].code, 244)
      << "incorrect value for biases[17].code, expected 244, is "
      << last_msg_->biases[17].code;
  EXPECT_EQ(last_msg_->biases[17].value, -10358)
      << "incorrect value for biases[17].value, expected -10358, is "
      << last_msg_->biases[17].value;
  EXPECT_EQ(last_msg_->biases[18].code, 209)
      << "incorrect value for biases[18].code, expected 209, is "
      << last_msg_->biases[18].code;
  EXPECT_EQ(last_msg_->biases[18].value, 3467)
      << "incorrect value for biases[18].value, expected 3467, is "
      << last_msg_->biases[18].value;
  EXPECT_EQ(last_msg_->biases[19].code, 101)
      << "incorrect value for biases[19].code, expected 101, is "
      << last_msg_->biases[19].code;
  EXPECT_EQ(last_msg_->biases[19].value, 1824)
      << "incorrect value for biases[19].value, expected 1824, is "
      << last_msg_->biases[19].value;
  EXPECT_EQ(last_msg_->biases[20].code, 18)
      << "incorrect value for biases[20].code, expected 18, is "
      << last_msg_->biases[20].code;
  EXPECT_EQ(last_msg_->biases[20].value, 17949)
      << "incorrect value for biases[20].value, expected 17949, is "
      << last_msg_->biases[20].value;
  EXPECT_EQ(last_msg_->biases[21].code, 250)
      << "incorrect value for biases[21].code, expected 250, is "
      << last_msg_->biases[21].code;
  EXPECT_EQ(last_msg_->biases[21].value, 18797)
      << "incorrect value for biases[21].value, expected 18797, is "
      << last_msg_->biases[21].value;
  EXPECT_EQ(last_msg_->biases[22].code, 202)
      << "incorrect value for biases[22].code, expected 202, is "
      << last_msg_->biases[22].code;
  EXPECT_EQ(last_msg_->biases[22].value, -28593)
      << "incorrect value for biases[22].value, expected -28593, is "
      << last_msg_->biases[22].value;
  EXPECT_EQ(last_msg_->biases[23].code, 9)
      << "incorrect value for biases[23].code, expected 9, is "
      << last_msg_->biases[23].code;
  EXPECT_EQ(last_msg_->biases[23].value, 17810)
      << "incorrect value for biases[23].value, expected 17810, is "
      << last_msg_->biases[23].value;
  EXPECT_EQ(last_msg_->biases[24].code, 241)
      << "incorrect value for biases[24].code, expected 241, is "
      << last_msg_->biases[24].code;
  EXPECT_EQ(last_msg_->biases[24].value, 5684)
      << "incorrect value for biases[24].value, expected 5684, is "
      << last_msg_->biases[24].value;
  EXPECT_EQ(last_msg_->biases[25].code, 99)
      << "incorrect value for biases[25].code, expected 99, is "
      << last_msg_->biases[25].code;
  EXPECT_EQ(last_msg_->biases[25].value, -13214)
      << "incorrect value for biases[25].value, expected -13214, is "
      << last_msg_->biases[25].value;
  EXPECT_EQ(last_msg_->biases[26].code, 3)
      << "incorrect value for biases[26].code, expected 3, is "
      << last_msg_->biases[26].code;
  EXPECT_EQ(last_msg_->biases[26].value, -6485)
      << "incorrect value for biases[26].value, expected -6485, is "
      << last_msg_->biases[26].value;
  EXPECT_EQ(last_msg_->biases[27].code, 180)
      << "incorrect value for biases[27].code, expected 180, is "
      << last_msg_->biases[27].code;
  EXPECT_EQ(last_msg_->biases[27].value, 15947)
      << "incorrect value for biases[27].value, expected 15947, is "
      << last_msg_->biases[27].value;
  EXPECT_EQ(last_msg_->biases[28].code, 145)
      << "incorrect value for biases[28].code, expected 145, is "
      << last_msg_->biases[28].code;
  EXPECT_EQ(last_msg_->biases[28].value, -32170)
      << "incorrect value for biases[28].value, expected -32170, is "
      << last_msg_->biases[28].value;
  EXPECT_EQ(last_msg_->biases[29].code, 31)
      << "incorrect value for biases[29].code, expected 31, is "
      << last_msg_->biases[29].code;
  EXPECT_EQ(last_msg_->biases[29].value, -25826)
      << "incorrect value for biases[29].value, expected -25826, is "
      << last_msg_->biases[29].value;
  EXPECT_EQ(last_msg_->biases[30].code, 37)
      << "incorrect value for biases[30].code, expected 37, is "
      << last_msg_->biases[30].code;
  EXPECT_EQ(last_msg_->biases[30].value, 14098)
      << "incorrect value for biases[30].value, expected 14098, is "
      << last_msg_->biases[30].value;
  EXPECT_EQ(last_msg_->biases[31].code, 210)
      << "incorrect value for biases[31].code, expected 210, is "
      << last_msg_->biases[31].code;
  EXPECT_EQ(last_msg_->biases[31].value, 32551)
      << "incorrect value for biases[31].value, expected 32551, is "
      << last_msg_->biases[31].value;
  EXPECT_EQ(last_msg_->biases[32].code, 242)
      << "incorrect value for biases[32].code, expected 242, is "
      << last_msg_->biases[32].code;
  EXPECT_EQ(last_msg_->biases[32].value, 3394)
      << "incorrect value for biases[32].value, expected 3394, is "
      << last_msg_->biases[32].value;
  EXPECT_EQ(last_msg_->biases[33].code, 237)
      << "incorrect value for biases[33].code, expected 237, is "
      << last_msg_->biases[33].code;
  EXPECT_EQ(last_msg_->biases[33].value, -21864)
      << "incorrect value for biases[33].value, expected -21864, is "
      << last_msg_->biases[33].value;
  EXPECT_EQ(last_msg_->biases[34].code, 212)
      << "incorrect value for biases[34].code, expected 212, is "
      << last_msg_->biases[34].code;
  EXPECT_EQ(last_msg_->biases[34].value, -2545)
      << "incorrect value for biases[34].value, expected -2545, is "
      << last_msg_->biases[34].value;
  EXPECT_EQ(last_msg_->biases[35].code, 59)
      << "incorrect value for biases[35].code, expected 59, is "
      << last_msg_->biases[35].code;
  EXPECT_EQ(last_msg_->biases[35].value, -19362)
      << "incorrect value for biases[35].value, expected -19362, is "
      << last_msg_->biases[35].value;
  EXPECT_EQ(last_msg_->biases[36].code, 195)
      << "incorrect value for biases[36].code, expected 195, is "
      << last_msg_->biases[36].code;
  EXPECT_EQ(last_msg_->biases[36].value, 17821)
      << "incorrect value for biases[36].value, expected 17821, is "
      << last_msg_->biases[36].value;
  EXPECT_EQ(last_msg_->biases[37].code, 100)
      << "incorrect value for biases[37].code, expected 100, is "
      << last_msg_->biases[37].code;
  EXPECT_EQ(last_msg_->biases[37].value, 4215)
      << "incorrect value for biases[37].value, expected 4215, is "
      << last_msg_->biases[37].value;
  EXPECT_EQ(last_msg_->biases[38].code, 68)
      << "incorrect value for biases[38].code, expected 68, is "
      << last_msg_->biases[38].code;
  EXPECT_EQ(last_msg_->biases[38].value, -20557)
      << "incorrect value for biases[38].value, expected -20557, is "
      << last_msg_->biases[38].value;
  EXPECT_EQ(last_msg_->biases[39].code, 144)
      << "incorrect value for biases[39].code, expected 144, is "
      << last_msg_->biases[39].code;
  EXPECT_EQ(last_msg_->biases[39].value, 20849)
      << "incorrect value for biases[39].value, expected 20849, is "
      << last_msg_->biases[39].value;
  EXPECT_EQ(last_msg_->biases[40].code, 82)
      << "incorrect value for biases[40].code, expected 82, is "
      << last_msg_->biases[40].code;
  EXPECT_EQ(last_msg_->biases[40].value, -26850)
      << "incorrect value for biases[40].value, expected -26850, is "
      << last_msg_->biases[40].value;
  EXPECT_EQ(last_msg_->biases[41].code, 21)
      << "incorrect value for biases[41].code, expected 21, is "
      << last_msg_->biases[41].code;
  EXPECT_EQ(last_msg_->biases[41].value, 10605)
      << "incorrect value for biases[41].value, expected 10605, is "
      << last_msg_->biases[41].value;
  EXPECT_EQ(last_msg_->biases[42].code, 225)
      << "incorrect value for biases[42].code, expected 225, is "
      << last_msg_->biases[42].code;
  EXPECT_EQ(last_msg_->biases[42].value, 19720)
      << "incorrect value for biases[42].value, expected 19720, is "
      << last_msg_->biases[42].value;
  EXPECT_EQ(last_msg_->biases[43].code, 164)
      << "incorrect value for biases[43].code, expected 164, is "
      << last_msg_->biases[43].code;
  EXPECT_EQ(last_msg_->biases[43].value, 157)
      << "incorrect value for biases[43].value, expected 157, is "
      << last_msg_->biases[43].value;
  EXPECT_EQ(last_msg_->biases[44].code, 73)
      << "incorrect value for biases[44].code, expected 73, is "
      << last_msg_->biases[44].code;
  EXPECT_EQ(last_msg_->biases[44].value, 1566)
      << "incorrect value for biases[44].value, expected 1566, is "
      << last_msg_->biases[44].value;
  EXPECT_EQ(last_msg_->biases[45].code, 78)
      << "incorrect value for biases[45].code, expected 78, is "
      << last_msg_->biases[45].code;
  EXPECT_EQ(last_msg_->biases[45].value, -28847)
      << "incorrect value for biases[45].value, expected -28847, is "
      << last_msg_->biases[45].value;
  EXPECT_EQ(last_msg_->biases[46].code, 116)
      << "incorrect value for biases[46].code, expected 116, is "
      << last_msg_->biases[46].code;
  EXPECT_EQ(last_msg_->biases[46].value, -26640)
      << "incorrect value for biases[46].value, expected -26640, is "
      << last_msg_->biases[46].value;
  EXPECT_EQ(last_msg_->biases[47].code, 55)
      << "incorrect value for biases[47].code, expected 55, is "
      << last_msg_->biases[47].code;
  EXPECT_EQ(last_msg_->biases[47].value, -22087)
      << "incorrect value for biases[47].value, expected -22087, is "
      << last_msg_->biases[47].value;
  EXPECT_EQ(last_msg_->biases[48].code, 254)
      << "incorrect value for biases[48].code, expected 254, is "
      << last_msg_->biases[48].code;
  EXPECT_EQ(last_msg_->biases[48].value, 10035)
      << "incorrect value for biases[48].value, expected 10035, is "
      << last_msg_->biases[48].value;
  EXPECT_EQ(last_msg_->biases[49].code, 74)
      << "incorrect value for biases[49].code, expected 74, is "
      << last_msg_->biases[49].code;
  EXPECT_EQ(last_msg_->biases[49].value, -2129)
      << "incorrect value for biases[49].value, expected -2129, is "
      << last_msg_->biases[49].value;
  EXPECT_EQ(last_msg_->biases[50].code, 34)
      << "incorrect value for biases[50].code, expected 34, is "
      << last_msg_->biases[50].code;
  EXPECT_EQ(last_msg_->biases[50].value, 19041)
      << "incorrect value for biases[50].value, expected 19041, is "
      << last_msg_->biases[50].value;
  EXPECT_EQ(last_msg_->biases[51].code, 97)
      << "incorrect value for biases[51].code, expected 97, is "
      << last_msg_->biases[51].code;
  EXPECT_EQ(last_msg_->biases[51].value, 12464)
      << "incorrect value for biases[51].value, expected 12464, is "
      << last_msg_->biases[51].value;
  EXPECT_EQ(last_msg_->biases[52].code, 236)
      << "incorrect value for biases[52].code, expected 236, is "
      << last_msg_->biases[52].code;
  EXPECT_EQ(last_msg_->biases[52].value, 3245)
      << "incorrect value for biases[52].value, expected 3245, is "
      << last_msg_->biases[52].value;
  EXPECT_EQ(last_msg_->biases[53].code, 174)
      << "incorrect value for biases[53].code, expected 174, is "
      << last_msg_->biases[53].code;
  EXPECT_EQ(last_msg_->biases[53].value, -32155)
      << "incorrect value for biases[53].value, expected -32155, is "
      << last_msg_->biases[53].value;
  EXPECT_EQ(last_msg_->biases[54].code, 30)
      << "incorrect value for biases[54].code, expected 30, is "
      << last_msg_->biases[54].code;
  EXPECT_EQ(last_msg_->biases[54].value, -15959)
      << "incorrect value for biases[54].value, expected -15959, is "
      << last_msg_->biases[54].value;
  EXPECT_EQ(last_msg_->biases[55].code, 190)
      << "incorrect value for biases[55].code, expected 190, is "
      << last_msg_->biases[55].code;
  EXPECT_EQ(last_msg_->biases[55].value, -15156)
      << "incorrect value for biases[55].value, expected -15156, is "
      << last_msg_->biases[55].value;
  EXPECT_EQ(last_msg_->biases[56].code, 123)
      << "incorrect value for biases[56].code, expected 123, is "
      << last_msg_->biases[56].code;
  EXPECT_EQ(last_msg_->biases[56].value, 6507)
      << "incorrect value for biases[56].value, expected 6507, is "
      << last_msg_->biases[56].value;
  EXPECT_EQ(last_msg_->biases[57].code, 225)
      << "incorrect value for biases[57].code, expected 225, is "
      << last_msg_->biases[57].code;
  EXPECT_EQ(last_msg_->biases[57].value, 2378)
      << "incorrect value for biases[57].value, expected 2378, is "
      << last_msg_->biases[57].value;
  EXPECT_EQ(last_msg_->biases[58].code, 10)
      << "incorrect value for biases[58].code, expected 10, is "
      << last_msg_->biases[58].code;
  EXPECT_EQ(last_msg_->biases[58].value, 823)
      << "incorrect value for biases[58].value, expected 823, is "
      << last_msg_->biases[58].value;
  EXPECT_EQ(last_msg_->biases[59].code, 131)
      << "incorrect value for biases[59].code, expected 131, is "
      << last_msg_->biases[59].code;
  EXPECT_EQ(last_msg_->biases[59].value, 25590)
      << "incorrect value for biases[59].value, expected 25590, is "
      << last_msg_->biases[59].value;
  EXPECT_EQ(last_msg_->biases[60].code, 133)
      << "incorrect value for biases[60].code, expected 133, is "
      << last_msg_->biases[60].code;
  EXPECT_EQ(last_msg_->biases[60].value, -7390)
      << "incorrect value for biases[60].value, expected -7390, is "
      << last_msg_->biases[60].value;
  EXPECT_EQ(last_msg_->biases[61].code, 203)
      << "incorrect value for biases[61].code, expected 203, is "
      << last_msg_->biases[61].code;
  EXPECT_EQ(last_msg_->biases[61].value, 4676)
      << "incorrect value for biases[61].value, expected 4676, is "
      << last_msg_->biases[61].value;
  EXPECT_EQ(last_msg_->biases[62].code, 97)
      << "incorrect value for biases[62].code, expected 97, is "
      << last_msg_->biases[62].code;
  EXPECT_EQ(last_msg_->biases[62].value, 23007)
      << "incorrect value for biases[62].value, expected 23007, is "
      << last_msg_->biases[62].value;
  EXPECT_EQ(last_msg_->biases[63].code, 192)
      << "incorrect value for biases[63].code, expected 192, is "
      << last_msg_->biases[63].code;
  EXPECT_EQ(last_msg_->biases[63].value, 13046)
      << "incorrect value for biases[63].value, expected 13046, is "
      << last_msg_->biases[63].value;
  EXPECT_EQ(last_msg_->biases[64].code, 69)
      << "incorrect value for biases[64].code, expected 69, is "
      << last_msg_->biases[64].code;
  EXPECT_EQ(last_msg_->biases[64].value, 2651)
      << "incorrect value for biases[64].value, expected 2651, is "
      << last_msg_->biases[64].value;
  EXPECT_EQ(last_msg_->biases[65].code, 151)
      << "incorrect value for biases[65].code, expected 151, is "
      << last_msg_->biases[65].code;
  EXPECT_EQ(last_msg_->biases[65].value, 30282)
      << "incorrect value for biases[65].value, expected 30282, is "
      << last_msg_->biases[65].value;
  EXPECT_EQ(last_msg_->biases[66].code, 110)
      << "incorrect value for biases[66].code, expected 110, is "
      << last_msg_->biases[66].code;
  EXPECT_EQ(last_msg_->biases[66].value, -22492)
      << "incorrect value for biases[66].value, expected -22492, is "
      << last_msg_->biases[66].value;
  EXPECT_EQ(last_msg_->biases[67].code, 247)
      << "incorrect value for biases[67].code, expected 247, is "
      << last_msg_->biases[67].code;
  EXPECT_EQ(last_msg_->biases[67].value, 19872)
      << "incorrect value for biases[67].value, expected 19872, is "
      << last_msg_->biases[67].value;
  EXPECT_EQ(last_msg_->biases[68].code, 179)
      << "incorrect value for biases[68].code, expected 179, is "
      << last_msg_->biases[68].code;
  EXPECT_EQ(last_msg_->biases[68].value, -19827)
      << "incorrect value for biases[68].value, expected -19827, is "
      << last_msg_->biases[68].value;
  EXPECT_EQ(last_msg_->biases[69].code, 99)
      << "incorrect value for biases[69].code, expected 99, is "
      << last_msg_->biases[69].code;
  EXPECT_EQ(last_msg_->biases[69].value, 30911)
      << "incorrect value for biases[69].value, expected 30911, is "
      << last_msg_->biases[69].value;
  EXPECT_EQ(last_msg_->biases[70].code, 77)
      << "incorrect value for biases[70].code, expected 77, is "
      << last_msg_->biases[70].code;
  EXPECT_EQ(last_msg_->biases[70].value, 23488)
      << "incorrect value for biases[70].value, expected 23488, is "
      << last_msg_->biases[70].value;
  EXPECT_EQ(last_msg_->biases[71].code, 224)
      << "incorrect value for biases[71].code, expected 224, is "
      << last_msg_->biases[71].code;
  EXPECT_EQ(last_msg_->biases[71].value, -7679)
      << "incorrect value for biases[71].value, expected -7679, is "
      << last_msg_->biases[71].value;
  EXPECT_EQ(last_msg_->biases[72].code, 50)
      << "incorrect value for biases[72].code, expected 50, is "
      << last_msg_->biases[72].code;
  EXPECT_EQ(last_msg_->biases[72].value, -28073)
      << "incorrect value for biases[72].value, expected -28073, is "
      << last_msg_->biases[72].value;
  EXPECT_EQ(last_msg_->biases[73].code, 148)
      << "incorrect value for biases[73].code, expected 148, is "
      << last_msg_->biases[73].code;
  EXPECT_EQ(last_msg_->biases[73].value, 25838)
      << "incorrect value for biases[73].value, expected 25838, is "
      << last_msg_->biases[73].value;
  EXPECT_EQ(last_msg_->biases[74].code, 179)
      << "incorrect value for biases[74].code, expected 179, is "
      << last_msg_->biases[74].code;
  EXPECT_EQ(last_msg_->biases[74].value, -7299)
      << "incorrect value for biases[74].value, expected -7299, is "
      << last_msg_->biases[74].value;
  EXPECT_EQ(last_msg_->biases[75].code, 215)
      << "incorrect value for biases[75].code, expected 215, is "
      << last_msg_->biases[75].code;
  EXPECT_EQ(last_msg_->biases[75].value, -18328)
      << "incorrect value for biases[75].value, expected -18328, is "
      << last_msg_->biases[75].value;
  EXPECT_EQ(last_msg_->biases[76].code, 31)
      << "incorrect value for biases[76].code, expected 31, is "
      << last_msg_->biases[76].code;
  EXPECT_EQ(last_msg_->biases[76].value, 23097)
      << "incorrect value for biases[76].value, expected 23097, is "
      << last_msg_->biases[76].value;
  EXPECT_EQ(last_msg_->biases[77].code, 79)
      << "incorrect value for biases[77].code, expected 79, is "
      << last_msg_->biases[77].code;
  EXPECT_EQ(last_msg_->biases[77].value, -25579)
      << "incorrect value for biases[77].value, expected -25579, is "
      << last_msg_->biases[77].value;
  EXPECT_EQ(last_msg_->biases[78].code, 245)
      << "incorrect value for biases[78].code, expected 245, is "
      << last_msg_->biases[78].code;
  EXPECT_EQ(last_msg_->biases[78].value, 15441)
      << "incorrect value for biases[78].value, expected 15441, is "
      << last_msg_->biases[78].value;
  EXPECT_EQ(last_msg_->biases[79].code, 93)
      << "incorrect value for biases[79].code, expected 93, is "
      << last_msg_->biases[79].code;
  EXPECT_EQ(last_msg_->biases[79].value, 15530)
      << "incorrect value for biases[79].value, expected 15530, is "
      << last_msg_->biases[79].value;
  EXPECT_EQ(last_msg_->biases[80].code, 200)
      << "incorrect value for biases[80].code, expected 200, is "
      << last_msg_->biases[80].code;
  EXPECT_EQ(last_msg_->biases[80].value, 3495)
      << "incorrect value for biases[80].value, expected 3495, is "
      << last_msg_->biases[80].value;
  EXPECT_EQ(last_msg_->iod_ssr, 132)
      << "incorrect value for iod_ssr, expected 132, is " << last_msg_->iod_ssr;
  EXPECT_EQ(last_msg_->sid.code, 241)
      << "incorrect value for sid.code, expected 241, is "
      << last_msg_->sid.code;
  EXPECT_EQ(last_msg_->sid.sat, 133)
      << "incorrect value for sid.sat, expected 133, is " << last_msg_->sid.sat;
  EXPECT_EQ(last_msg_->time.tow, 387144400)
      << "incorrect value for time.tow, expected 387144400, is "
      << last_msg_->time.tow;
  EXPECT_EQ(last_msg_->time.wn, 16905)
      << "incorrect value for time.wn, expected 16905, is "
      << last_msg_->time.wn;
  EXPECT_EQ(last_msg_->update_interval, 254)
      << "incorrect value for update_interval, expected 254, is "
      << last_msg_->update_interval;
}
