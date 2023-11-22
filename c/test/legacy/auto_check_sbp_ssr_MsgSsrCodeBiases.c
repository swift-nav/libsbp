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

#include <check.h>
#include <libsbp/legacy/ssr.h>
#include <sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u8 len;
  u8 msg[SBP_MAX_PAYLOAD_LEN];
  void *context;
} last_msg;

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u16 msg_type;
  u8 msg_len;
  u8 msg[SBP_MAX_PAYLOAD_LEN];
  u16 frame_len;
  u8 frame[SBP_MAX_FRAME_LEN];
  void *context;
} last_frame;

static u32 dummy_wr = 0;
static u32 dummy_rd = 0;
static u8 dummy_buff[1024];
static void *last_io_context;

static int DUMMY_MEMORY_FOR_CALLBACKS = 0xdeadbeef;
static int DUMMY_MEMORY_FOR_IO = 0xdead0000;

static void dummy_reset() {
  dummy_rd = dummy_wr = 0;
  memset(dummy_buff, 0, sizeof(dummy_buff));
}

static s32 dummy_write(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(dummy_buff + dummy_wr, buff, real_n);
  dummy_wr += real_n;
  return real_n;
}

static s32 dummy_read(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(buff, dummy_buff + dummy_rd, real_n);
  dummy_rd += real_n;
  return real_n;
}

static void logging_reset() {
  memset(&last_msg, 0, sizeof(last_msg));
  memset(&last_frame, 0, sizeof(last_frame));
}

static void msg_callback(u16 sender_id, u8 len, u8 msg[], void *context) {
  last_msg.n_callbacks_logged++;
  last_msg.sender_id = sender_id;
  last_msg.len = len;
  last_msg.context = context;
  memcpy(last_msg.msg, msg, len);
}

static void frame_callback(u16 sender_id, u16 msg_type, u8 msg_len, u8 msg[],
                           u16 frame_len, u8 frame[], void *context) {
  last_frame.n_callbacks_logged++;
  last_frame.sender_id = sender_id;
  last_frame.msg_type = msg_type;
  last_frame.msg_len = msg_len;
  memcpy(last_frame.msg, msg, msg_len);
  last_frame.frame_len = frame_len;
  memcpy(last_frame.frame, frame, frame_len);
  last_frame.context = context;
}

START_TEST(test_legacy_auto_check_sbp_ssr_MsgSsrCodeBiases) {
  static sbp_msg_callbacks_node_t n;
  static sbp_msg_callbacks_node_t n2;

  // State of the SBP message parser.
  // Must be statically allocated.
  sbp_state_t sbp_state;

  //
  // Run tests:
  //
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_payload_callback_register(&sbp_state, 0x5e1, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x5e1, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  225, 5,   39,  87,  253, 208, 90,  19,  23,  9,   66,  133, 241,
        254, 132, 51,  4,   131, 240, 120, 83,  148, 209, 213, 62,  228, 232,
        71,  66,  188, 210, 128, 54,  131, 152, 129, 111, 139, 242, 177, 145,
        44,  9,   245, 207, 241, 202, 150, 141, 50,  159, 220, 139, 37,  187,
        98,  191, 23,  128, 136, 167, 200, 6,   211, 90,  23,  244, 138, 215,
        209, 139, 13,  101, 32,  7,   18,  29,  70,  250, 109, 73,  202, 79,
        144, 9,   146, 69,  241, 52,  22,  99,  98,  204, 3,   171, 230, 180,
        75,  62,  145, 86,  130, 31,  30,  155, 37,  18,  55,  210, 39,  127,
        242, 66,  13,  237, 152, 170, 212, 15,  246, 59,  94,  180, 195, 157,
        69,  100, 119, 16,  68,  179, 175, 144, 113, 81,  82,  30,  151, 21,
        109, 41,  225, 8,   77,  164, 157, 0,   73,  30,  6,   78,  81,  143,
        116, 240, 151, 55,  185, 169, 254, 51,  39,  74,  175, 247, 34,  97,
        74,  97,  176, 48,  236, 173, 12,  174, 101, 130, 30,  169, 193, 190,
        204, 196, 123, 107, 25,  225, 74,  9,   10,  55,  3,   131, 246, 99,
        133, 34,  227, 203, 68,  18,  97,  223, 89,  192, 246, 50,  69,  91,
        10,  151, 74,  118, 110, 36,  168, 247, 160, 77,  179, 141, 178, 99,
        191, 120, 77,  192, 91,  224, 1,   226, 50,  87,  146, 148, 238, 100,
        179, 125, 227, 215, 104, 184, 31,  57,  90,  79,  21,  156, 245, 81,
        60,  93,  170, 60,  200, 167, 13,  125, 132,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_ssr_code_biases_t *test_msg = (msg_ssr_code_biases_t *)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[0].code = 51;
    test_msg->biases[0].value = -31996;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[1].code = 240;
    test_msg->biases[1].value = 21368;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[2].code = 148;
    test_msg->biases[2].value = -10799;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[3].code = 62;
    test_msg->biases[3].value = -5916;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[4].code = 71;
    test_msg->biases[4].value = -17342;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[5].code = 210;
    test_msg->biases[5].value = 13952;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[6].code = 131;
    test_msg->biases[6].value = -32360;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[7].code = 111;
    test_msg->biases[7].value = -3445;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[8].code = 177;
    test_msg->biases[8].value = 11409;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[9].code = 9;
    test_msg->biases[9].value = -12299;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[10].code = 241;
    test_msg->biases[10].value = -26934;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[11].code = 141;
    test_msg->biases[11].value = -24782;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[12].code = 220;
    test_msg->biases[12].value = 9611;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[13].code = 187;
    test_msg->biases[13].value = -16542;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[14].code = 23;
    test_msg->biases[14].value = -30592;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[15].code = 167;
    test_msg->biases[15].value = 1736;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[16].code = 211;
    test_msg->biases[16].value = 5978;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[17].code = 244;
    test_msg->biases[17].value = -10358;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[18].code = 209;
    test_msg->biases[18].value = 3467;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[19].code = 101;
    test_msg->biases[19].value = 1824;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[20].code = 18;
    test_msg->biases[20].value = 17949;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[21].code = 250;
    test_msg->biases[21].value = 18797;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[22].code = 202;
    test_msg->biases[22].value = -28593;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[23].code = 9;
    test_msg->biases[23].value = 17810;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[24].code = 241;
    test_msg->biases[24].value = 5684;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[25].code = 99;
    test_msg->biases[25].value = -13214;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[26].code = 3;
    test_msg->biases[26].value = -6485;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[27].code = 180;
    test_msg->biases[27].value = 15947;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[28].code = 145;
    test_msg->biases[28].value = -32170;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[29].code = 31;
    test_msg->biases[29].value = -25826;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[30].code = 37;
    test_msg->biases[30].value = 14098;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[31].code = 210;
    test_msg->biases[31].value = 32551;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[32].code = 242;
    test_msg->biases[32].value = 3394;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[33].code = 237;
    test_msg->biases[33].value = -21864;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[34].code = 212;
    test_msg->biases[34].value = -2545;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[35].code = 59;
    test_msg->biases[35].value = -19362;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[36].code = 195;
    test_msg->biases[36].value = 17821;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[37].code = 100;
    test_msg->biases[37].value = 4215;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[38].code = 68;
    test_msg->biases[38].value = -20557;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[39].code = 144;
    test_msg->biases[39].value = 20849;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[40].code = 82;
    test_msg->biases[40].value = -26850;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[41].code = 21;
    test_msg->biases[41].value = 10605;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[42].code = 225;
    test_msg->biases[42].value = 19720;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[43].code = 164;
    test_msg->biases[43].value = 157;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[44].code = 73;
    test_msg->biases[44].value = 1566;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[45].code = 78;
    test_msg->biases[45].value = -28847;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[46].code = 116;
    test_msg->biases[46].value = -26640;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[47].code = 55;
    test_msg->biases[47].value = -22087;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[48].code = 254;
    test_msg->biases[48].value = 10035;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[49].code = 74;
    test_msg->biases[49].value = -2129;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[50].code = 34;
    test_msg->biases[50].value = 19041;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[51].code = 97;
    test_msg->biases[51].value = 12464;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[52].code = 236;
    test_msg->biases[52].value = 3245;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[53].code = 174;
    test_msg->biases[53].value = -32155;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[54].code = 30;
    test_msg->biases[54].value = -15959;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[55].code = 190;
    test_msg->biases[55].value = -15156;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[56].code = 123;
    test_msg->biases[56].value = 6507;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[57].code = 225;
    test_msg->biases[57].value = 2378;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[58].code = 10;
    test_msg->biases[58].value = 823;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[59].code = 131;
    test_msg->biases[59].value = 25590;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[60].code = 133;
    test_msg->biases[60].value = -7390;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[61].code = 203;
    test_msg->biases[61].value = 4676;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[62].code = 97;
    test_msg->biases[62].value = 23007;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[63].code = 192;
    test_msg->biases[63].value = 13046;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[64].code = 69;
    test_msg->biases[64].value = 2651;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[65].code = 151;
    test_msg->biases[65].value = 30282;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[66].code = 110;
    test_msg->biases[66].value = -22492;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[67].code = 247;
    test_msg->biases[67].value = 19872;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[68].code = 179;
    test_msg->biases[68].value = -19827;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[69].code = 99;
    test_msg->biases[69].value = 30911;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[70].code = 77;
    test_msg->biases[70].value = 23488;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[71].code = 224;
    test_msg->biases[71].value = -7679;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[72].code = 50;
    test_msg->biases[72].value = -28073;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[73].code = 148;
    test_msg->biases[73].value = 25838;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[74].code = 179;
    test_msg->biases[74].value = -7299;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[75].code = 215;
    test_msg->biases[75].value = -18328;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[76].code = 31;
    test_msg->biases[76].value = 23097;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[77].code = 79;
    test_msg->biases[77].value = -25579;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[78].code = 245;
    test_msg->biases[78].value = 15441;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[79].code = 93;
    test_msg->biases[79].value = 15530;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[80].code = 200;
    test_msg->biases[80].value = 3495;
    test_msg->iod_ssr = 132;
    test_msg->sid.code = 241;
    test_msg->sid.sat = 133;
    test_msg->time.tow = 387144400;
    test_msg->time.wn = 16905;
    test_msg->update_interval = 254;
    sbp_payload_send(&sbp_state, 0x5e1, 22311, test_msg_len, test_msg_storage,
                     &dummy_write);

    ck_assert_msg(
        test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame "
        "from the spec is badly defined. Check your test spec");

    ck_assert_msg(dummy_wr == sizeof(encoded_frame),
                  "not enough data was written to dummy_buff");
    ck_assert_msg(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)) == 0,
                  "frame was not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_msg.n_callbacks_logged == 1,
                  "msg_callback: one callback should have been logged");
    ck_assert_msg(last_msg.sender_id == 22311,
                  "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
                  "msg_callback: len decoded incorrectly");
    ck_assert_msg(
        memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 22311,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x5e1,
                  "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
                  "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6,
                         sizeof(encoded_frame) - 8) == 0,
                  "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
                  "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(
        memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload
    // starts
    msg_ssr_code_biases_t *check_msg =
        (msg_ssr_code_biases_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->biases[0].code == 51,
                  "incorrect value for biases[0].code, expected 51, is %d",
                  check_msg->biases[0].code);
    ck_assert_msg(check_msg->biases[0].value == -31996,
                  "incorrect value for biases[0].value, expected -31996, is %d",
                  check_msg->biases[0].value);
    ck_assert_msg(check_msg->biases[1].code == 240,
                  "incorrect value for biases[1].code, expected 240, is %d",
                  check_msg->biases[1].code);
    ck_assert_msg(check_msg->biases[1].value == 21368,
                  "incorrect value for biases[1].value, expected 21368, is %d",
                  check_msg->biases[1].value);
    ck_assert_msg(check_msg->biases[2].code == 148,
                  "incorrect value for biases[2].code, expected 148, is %d",
                  check_msg->biases[2].code);
    ck_assert_msg(check_msg->biases[2].value == -10799,
                  "incorrect value for biases[2].value, expected -10799, is %d",
                  check_msg->biases[2].value);
    ck_assert_msg(check_msg->biases[3].code == 62,
                  "incorrect value for biases[3].code, expected 62, is %d",
                  check_msg->biases[3].code);
    ck_assert_msg(check_msg->biases[3].value == -5916,
                  "incorrect value for biases[3].value, expected -5916, is %d",
                  check_msg->biases[3].value);
    ck_assert_msg(check_msg->biases[4].code == 71,
                  "incorrect value for biases[4].code, expected 71, is %d",
                  check_msg->biases[4].code);
    ck_assert_msg(check_msg->biases[4].value == -17342,
                  "incorrect value for biases[4].value, expected -17342, is %d",
                  check_msg->biases[4].value);
    ck_assert_msg(check_msg->biases[5].code == 210,
                  "incorrect value for biases[5].code, expected 210, is %d",
                  check_msg->biases[5].code);
    ck_assert_msg(check_msg->biases[5].value == 13952,
                  "incorrect value for biases[5].value, expected 13952, is %d",
                  check_msg->biases[5].value);
    ck_assert_msg(check_msg->biases[6].code == 131,
                  "incorrect value for biases[6].code, expected 131, is %d",
                  check_msg->biases[6].code);
    ck_assert_msg(check_msg->biases[6].value == -32360,
                  "incorrect value for biases[6].value, expected -32360, is %d",
                  check_msg->biases[6].value);
    ck_assert_msg(check_msg->biases[7].code == 111,
                  "incorrect value for biases[7].code, expected 111, is %d",
                  check_msg->biases[7].code);
    ck_assert_msg(check_msg->biases[7].value == -3445,
                  "incorrect value for biases[7].value, expected -3445, is %d",
                  check_msg->biases[7].value);
    ck_assert_msg(check_msg->biases[8].code == 177,
                  "incorrect value for biases[8].code, expected 177, is %d",
                  check_msg->biases[8].code);
    ck_assert_msg(check_msg->biases[8].value == 11409,
                  "incorrect value for biases[8].value, expected 11409, is %d",
                  check_msg->biases[8].value);
    ck_assert_msg(check_msg->biases[9].code == 9,
                  "incorrect value for biases[9].code, expected 9, is %d",
                  check_msg->biases[9].code);
    ck_assert_msg(check_msg->biases[9].value == -12299,
                  "incorrect value for biases[9].value, expected -12299, is %d",
                  check_msg->biases[9].value);
    ck_assert_msg(check_msg->biases[10].code == 241,
                  "incorrect value for biases[10].code, expected 241, is %d",
                  check_msg->biases[10].code);
    ck_assert_msg(
        check_msg->biases[10].value == -26934,
        "incorrect value for biases[10].value, expected -26934, is %d",
        check_msg->biases[10].value);
    ck_assert_msg(check_msg->biases[11].code == 141,
                  "incorrect value for biases[11].code, expected 141, is %d",
                  check_msg->biases[11].code);
    ck_assert_msg(
        check_msg->biases[11].value == -24782,
        "incorrect value for biases[11].value, expected -24782, is %d",
        check_msg->biases[11].value);
    ck_assert_msg(check_msg->biases[12].code == 220,
                  "incorrect value for biases[12].code, expected 220, is %d",
                  check_msg->biases[12].code);
    ck_assert_msg(check_msg->biases[12].value == 9611,
                  "incorrect value for biases[12].value, expected 9611, is %d",
                  check_msg->biases[12].value);
    ck_assert_msg(check_msg->biases[13].code == 187,
                  "incorrect value for biases[13].code, expected 187, is %d",
                  check_msg->biases[13].code);
    ck_assert_msg(
        check_msg->biases[13].value == -16542,
        "incorrect value for biases[13].value, expected -16542, is %d",
        check_msg->biases[13].value);
    ck_assert_msg(check_msg->biases[14].code == 23,
                  "incorrect value for biases[14].code, expected 23, is %d",
                  check_msg->biases[14].code);
    ck_assert_msg(
        check_msg->biases[14].value == -30592,
        "incorrect value for biases[14].value, expected -30592, is %d",
        check_msg->biases[14].value);
    ck_assert_msg(check_msg->biases[15].code == 167,
                  "incorrect value for biases[15].code, expected 167, is %d",
                  check_msg->biases[15].code);
    ck_assert_msg(check_msg->biases[15].value == 1736,
                  "incorrect value for biases[15].value, expected 1736, is %d",
                  check_msg->biases[15].value);
    ck_assert_msg(check_msg->biases[16].code == 211,
                  "incorrect value for biases[16].code, expected 211, is %d",
                  check_msg->biases[16].code);
    ck_assert_msg(check_msg->biases[16].value == 5978,
                  "incorrect value for biases[16].value, expected 5978, is %d",
                  check_msg->biases[16].value);
    ck_assert_msg(check_msg->biases[17].code == 244,
                  "incorrect value for biases[17].code, expected 244, is %d",
                  check_msg->biases[17].code);
    ck_assert_msg(
        check_msg->biases[17].value == -10358,
        "incorrect value for biases[17].value, expected -10358, is %d",
        check_msg->biases[17].value);
    ck_assert_msg(check_msg->biases[18].code == 209,
                  "incorrect value for biases[18].code, expected 209, is %d",
                  check_msg->biases[18].code);
    ck_assert_msg(check_msg->biases[18].value == 3467,
                  "incorrect value for biases[18].value, expected 3467, is %d",
                  check_msg->biases[18].value);
    ck_assert_msg(check_msg->biases[19].code == 101,
                  "incorrect value for biases[19].code, expected 101, is %d",
                  check_msg->biases[19].code);
    ck_assert_msg(check_msg->biases[19].value == 1824,
                  "incorrect value for biases[19].value, expected 1824, is %d",
                  check_msg->biases[19].value);
    ck_assert_msg(check_msg->biases[20].code == 18,
                  "incorrect value for biases[20].code, expected 18, is %d",
                  check_msg->biases[20].code);
    ck_assert_msg(check_msg->biases[20].value == 17949,
                  "incorrect value for biases[20].value, expected 17949, is %d",
                  check_msg->biases[20].value);
    ck_assert_msg(check_msg->biases[21].code == 250,
                  "incorrect value for biases[21].code, expected 250, is %d",
                  check_msg->biases[21].code);
    ck_assert_msg(check_msg->biases[21].value == 18797,
                  "incorrect value for biases[21].value, expected 18797, is %d",
                  check_msg->biases[21].value);
    ck_assert_msg(check_msg->biases[22].code == 202,
                  "incorrect value for biases[22].code, expected 202, is %d",
                  check_msg->biases[22].code);
    ck_assert_msg(
        check_msg->biases[22].value == -28593,
        "incorrect value for biases[22].value, expected -28593, is %d",
        check_msg->biases[22].value);
    ck_assert_msg(check_msg->biases[23].code == 9,
                  "incorrect value for biases[23].code, expected 9, is %d",
                  check_msg->biases[23].code);
    ck_assert_msg(check_msg->biases[23].value == 17810,
                  "incorrect value for biases[23].value, expected 17810, is %d",
                  check_msg->biases[23].value);
    ck_assert_msg(check_msg->biases[24].code == 241,
                  "incorrect value for biases[24].code, expected 241, is %d",
                  check_msg->biases[24].code);
    ck_assert_msg(check_msg->biases[24].value == 5684,
                  "incorrect value for biases[24].value, expected 5684, is %d",
                  check_msg->biases[24].value);
    ck_assert_msg(check_msg->biases[25].code == 99,
                  "incorrect value for biases[25].code, expected 99, is %d",
                  check_msg->biases[25].code);
    ck_assert_msg(
        check_msg->biases[25].value == -13214,
        "incorrect value for biases[25].value, expected -13214, is %d",
        check_msg->biases[25].value);
    ck_assert_msg(check_msg->biases[26].code == 3,
                  "incorrect value for biases[26].code, expected 3, is %d",
                  check_msg->biases[26].code);
    ck_assert_msg(check_msg->biases[26].value == -6485,
                  "incorrect value for biases[26].value, expected -6485, is %d",
                  check_msg->biases[26].value);
    ck_assert_msg(check_msg->biases[27].code == 180,
                  "incorrect value for biases[27].code, expected 180, is %d",
                  check_msg->biases[27].code);
    ck_assert_msg(check_msg->biases[27].value == 15947,
                  "incorrect value for biases[27].value, expected 15947, is %d",
                  check_msg->biases[27].value);
    ck_assert_msg(check_msg->biases[28].code == 145,
                  "incorrect value for biases[28].code, expected 145, is %d",
                  check_msg->biases[28].code);
    ck_assert_msg(
        check_msg->biases[28].value == -32170,
        "incorrect value for biases[28].value, expected -32170, is %d",
        check_msg->biases[28].value);
    ck_assert_msg(check_msg->biases[29].code == 31,
                  "incorrect value for biases[29].code, expected 31, is %d",
                  check_msg->biases[29].code);
    ck_assert_msg(
        check_msg->biases[29].value == -25826,
        "incorrect value for biases[29].value, expected -25826, is %d",
        check_msg->biases[29].value);
    ck_assert_msg(check_msg->biases[30].code == 37,
                  "incorrect value for biases[30].code, expected 37, is %d",
                  check_msg->biases[30].code);
    ck_assert_msg(check_msg->biases[30].value == 14098,
                  "incorrect value for biases[30].value, expected 14098, is %d",
                  check_msg->biases[30].value);
    ck_assert_msg(check_msg->biases[31].code == 210,
                  "incorrect value for biases[31].code, expected 210, is %d",
                  check_msg->biases[31].code);
    ck_assert_msg(check_msg->biases[31].value == 32551,
                  "incorrect value for biases[31].value, expected 32551, is %d",
                  check_msg->biases[31].value);
    ck_assert_msg(check_msg->biases[32].code == 242,
                  "incorrect value for biases[32].code, expected 242, is %d",
                  check_msg->biases[32].code);
    ck_assert_msg(check_msg->biases[32].value == 3394,
                  "incorrect value for biases[32].value, expected 3394, is %d",
                  check_msg->biases[32].value);
    ck_assert_msg(check_msg->biases[33].code == 237,
                  "incorrect value for biases[33].code, expected 237, is %d",
                  check_msg->biases[33].code);
    ck_assert_msg(
        check_msg->biases[33].value == -21864,
        "incorrect value for biases[33].value, expected -21864, is %d",
        check_msg->biases[33].value);
    ck_assert_msg(check_msg->biases[34].code == 212,
                  "incorrect value for biases[34].code, expected 212, is %d",
                  check_msg->biases[34].code);
    ck_assert_msg(check_msg->biases[34].value == -2545,
                  "incorrect value for biases[34].value, expected -2545, is %d",
                  check_msg->biases[34].value);
    ck_assert_msg(check_msg->biases[35].code == 59,
                  "incorrect value for biases[35].code, expected 59, is %d",
                  check_msg->biases[35].code);
    ck_assert_msg(
        check_msg->biases[35].value == -19362,
        "incorrect value for biases[35].value, expected -19362, is %d",
        check_msg->biases[35].value);
    ck_assert_msg(check_msg->biases[36].code == 195,
                  "incorrect value for biases[36].code, expected 195, is %d",
                  check_msg->biases[36].code);
    ck_assert_msg(check_msg->biases[36].value == 17821,
                  "incorrect value for biases[36].value, expected 17821, is %d",
                  check_msg->biases[36].value);
    ck_assert_msg(check_msg->biases[37].code == 100,
                  "incorrect value for biases[37].code, expected 100, is %d",
                  check_msg->biases[37].code);
    ck_assert_msg(check_msg->biases[37].value == 4215,
                  "incorrect value for biases[37].value, expected 4215, is %d",
                  check_msg->biases[37].value);
    ck_assert_msg(check_msg->biases[38].code == 68,
                  "incorrect value for biases[38].code, expected 68, is %d",
                  check_msg->biases[38].code);
    ck_assert_msg(
        check_msg->biases[38].value == -20557,
        "incorrect value for biases[38].value, expected -20557, is %d",
        check_msg->biases[38].value);
    ck_assert_msg(check_msg->biases[39].code == 144,
                  "incorrect value for biases[39].code, expected 144, is %d",
                  check_msg->biases[39].code);
    ck_assert_msg(check_msg->biases[39].value == 20849,
                  "incorrect value for biases[39].value, expected 20849, is %d",
                  check_msg->biases[39].value);
    ck_assert_msg(check_msg->biases[40].code == 82,
                  "incorrect value for biases[40].code, expected 82, is %d",
                  check_msg->biases[40].code);
    ck_assert_msg(
        check_msg->biases[40].value == -26850,
        "incorrect value for biases[40].value, expected -26850, is %d",
        check_msg->biases[40].value);
    ck_assert_msg(check_msg->biases[41].code == 21,
                  "incorrect value for biases[41].code, expected 21, is %d",
                  check_msg->biases[41].code);
    ck_assert_msg(check_msg->biases[41].value == 10605,
                  "incorrect value for biases[41].value, expected 10605, is %d",
                  check_msg->biases[41].value);
    ck_assert_msg(check_msg->biases[42].code == 225,
                  "incorrect value for biases[42].code, expected 225, is %d",
                  check_msg->biases[42].code);
    ck_assert_msg(check_msg->biases[42].value == 19720,
                  "incorrect value for biases[42].value, expected 19720, is %d",
                  check_msg->biases[42].value);
    ck_assert_msg(check_msg->biases[43].code == 164,
                  "incorrect value for biases[43].code, expected 164, is %d",
                  check_msg->biases[43].code);
    ck_assert_msg(check_msg->biases[43].value == 157,
                  "incorrect value for biases[43].value, expected 157, is %d",
                  check_msg->biases[43].value);
    ck_assert_msg(check_msg->biases[44].code == 73,
                  "incorrect value for biases[44].code, expected 73, is %d",
                  check_msg->biases[44].code);
    ck_assert_msg(check_msg->biases[44].value == 1566,
                  "incorrect value for biases[44].value, expected 1566, is %d",
                  check_msg->biases[44].value);
    ck_assert_msg(check_msg->biases[45].code == 78,
                  "incorrect value for biases[45].code, expected 78, is %d",
                  check_msg->biases[45].code);
    ck_assert_msg(
        check_msg->biases[45].value == -28847,
        "incorrect value for biases[45].value, expected -28847, is %d",
        check_msg->biases[45].value);
    ck_assert_msg(check_msg->biases[46].code == 116,
                  "incorrect value for biases[46].code, expected 116, is %d",
                  check_msg->biases[46].code);
    ck_assert_msg(
        check_msg->biases[46].value == -26640,
        "incorrect value for biases[46].value, expected -26640, is %d",
        check_msg->biases[46].value);
    ck_assert_msg(check_msg->biases[47].code == 55,
                  "incorrect value for biases[47].code, expected 55, is %d",
                  check_msg->biases[47].code);
    ck_assert_msg(
        check_msg->biases[47].value == -22087,
        "incorrect value for biases[47].value, expected -22087, is %d",
        check_msg->biases[47].value);
    ck_assert_msg(check_msg->biases[48].code == 254,
                  "incorrect value for biases[48].code, expected 254, is %d",
                  check_msg->biases[48].code);
    ck_assert_msg(check_msg->biases[48].value == 10035,
                  "incorrect value for biases[48].value, expected 10035, is %d",
                  check_msg->biases[48].value);
    ck_assert_msg(check_msg->biases[49].code == 74,
                  "incorrect value for biases[49].code, expected 74, is %d",
                  check_msg->biases[49].code);
    ck_assert_msg(check_msg->biases[49].value == -2129,
                  "incorrect value for biases[49].value, expected -2129, is %d",
                  check_msg->biases[49].value);
    ck_assert_msg(check_msg->biases[50].code == 34,
                  "incorrect value for biases[50].code, expected 34, is %d",
                  check_msg->biases[50].code);
    ck_assert_msg(check_msg->biases[50].value == 19041,
                  "incorrect value for biases[50].value, expected 19041, is %d",
                  check_msg->biases[50].value);
    ck_assert_msg(check_msg->biases[51].code == 97,
                  "incorrect value for biases[51].code, expected 97, is %d",
                  check_msg->biases[51].code);
    ck_assert_msg(check_msg->biases[51].value == 12464,
                  "incorrect value for biases[51].value, expected 12464, is %d",
                  check_msg->biases[51].value);
    ck_assert_msg(check_msg->biases[52].code == 236,
                  "incorrect value for biases[52].code, expected 236, is %d",
                  check_msg->biases[52].code);
    ck_assert_msg(check_msg->biases[52].value == 3245,
                  "incorrect value for biases[52].value, expected 3245, is %d",
                  check_msg->biases[52].value);
    ck_assert_msg(check_msg->biases[53].code == 174,
                  "incorrect value for biases[53].code, expected 174, is %d",
                  check_msg->biases[53].code);
    ck_assert_msg(
        check_msg->biases[53].value == -32155,
        "incorrect value for biases[53].value, expected -32155, is %d",
        check_msg->biases[53].value);
    ck_assert_msg(check_msg->biases[54].code == 30,
                  "incorrect value for biases[54].code, expected 30, is %d",
                  check_msg->biases[54].code);
    ck_assert_msg(
        check_msg->biases[54].value == -15959,
        "incorrect value for biases[54].value, expected -15959, is %d",
        check_msg->biases[54].value);
    ck_assert_msg(check_msg->biases[55].code == 190,
                  "incorrect value for biases[55].code, expected 190, is %d",
                  check_msg->biases[55].code);
    ck_assert_msg(
        check_msg->biases[55].value == -15156,
        "incorrect value for biases[55].value, expected -15156, is %d",
        check_msg->biases[55].value);
    ck_assert_msg(check_msg->biases[56].code == 123,
                  "incorrect value for biases[56].code, expected 123, is %d",
                  check_msg->biases[56].code);
    ck_assert_msg(check_msg->biases[56].value == 6507,
                  "incorrect value for biases[56].value, expected 6507, is %d",
                  check_msg->biases[56].value);
    ck_assert_msg(check_msg->biases[57].code == 225,
                  "incorrect value for biases[57].code, expected 225, is %d",
                  check_msg->biases[57].code);
    ck_assert_msg(check_msg->biases[57].value == 2378,
                  "incorrect value for biases[57].value, expected 2378, is %d",
                  check_msg->biases[57].value);
    ck_assert_msg(check_msg->biases[58].code == 10,
                  "incorrect value for biases[58].code, expected 10, is %d",
                  check_msg->biases[58].code);
    ck_assert_msg(check_msg->biases[58].value == 823,
                  "incorrect value for biases[58].value, expected 823, is %d",
                  check_msg->biases[58].value);
    ck_assert_msg(check_msg->biases[59].code == 131,
                  "incorrect value for biases[59].code, expected 131, is %d",
                  check_msg->biases[59].code);
    ck_assert_msg(check_msg->biases[59].value == 25590,
                  "incorrect value for biases[59].value, expected 25590, is %d",
                  check_msg->biases[59].value);
    ck_assert_msg(check_msg->biases[60].code == 133,
                  "incorrect value for biases[60].code, expected 133, is %d",
                  check_msg->biases[60].code);
    ck_assert_msg(check_msg->biases[60].value == -7390,
                  "incorrect value for biases[60].value, expected -7390, is %d",
                  check_msg->biases[60].value);
    ck_assert_msg(check_msg->biases[61].code == 203,
                  "incorrect value for biases[61].code, expected 203, is %d",
                  check_msg->biases[61].code);
    ck_assert_msg(check_msg->biases[61].value == 4676,
                  "incorrect value for biases[61].value, expected 4676, is %d",
                  check_msg->biases[61].value);
    ck_assert_msg(check_msg->biases[62].code == 97,
                  "incorrect value for biases[62].code, expected 97, is %d",
                  check_msg->biases[62].code);
    ck_assert_msg(check_msg->biases[62].value == 23007,
                  "incorrect value for biases[62].value, expected 23007, is %d",
                  check_msg->biases[62].value);
    ck_assert_msg(check_msg->biases[63].code == 192,
                  "incorrect value for biases[63].code, expected 192, is %d",
                  check_msg->biases[63].code);
    ck_assert_msg(check_msg->biases[63].value == 13046,
                  "incorrect value for biases[63].value, expected 13046, is %d",
                  check_msg->biases[63].value);
    ck_assert_msg(check_msg->biases[64].code == 69,
                  "incorrect value for biases[64].code, expected 69, is %d",
                  check_msg->biases[64].code);
    ck_assert_msg(check_msg->biases[64].value == 2651,
                  "incorrect value for biases[64].value, expected 2651, is %d",
                  check_msg->biases[64].value);
    ck_assert_msg(check_msg->biases[65].code == 151,
                  "incorrect value for biases[65].code, expected 151, is %d",
                  check_msg->biases[65].code);
    ck_assert_msg(check_msg->biases[65].value == 30282,
                  "incorrect value for biases[65].value, expected 30282, is %d",
                  check_msg->biases[65].value);
    ck_assert_msg(check_msg->biases[66].code == 110,
                  "incorrect value for biases[66].code, expected 110, is %d",
                  check_msg->biases[66].code);
    ck_assert_msg(
        check_msg->biases[66].value == -22492,
        "incorrect value for biases[66].value, expected -22492, is %d",
        check_msg->biases[66].value);
    ck_assert_msg(check_msg->biases[67].code == 247,
                  "incorrect value for biases[67].code, expected 247, is %d",
                  check_msg->biases[67].code);
    ck_assert_msg(check_msg->biases[67].value == 19872,
                  "incorrect value for biases[67].value, expected 19872, is %d",
                  check_msg->biases[67].value);
    ck_assert_msg(check_msg->biases[68].code == 179,
                  "incorrect value for biases[68].code, expected 179, is %d",
                  check_msg->biases[68].code);
    ck_assert_msg(
        check_msg->biases[68].value == -19827,
        "incorrect value for biases[68].value, expected -19827, is %d",
        check_msg->biases[68].value);
    ck_assert_msg(check_msg->biases[69].code == 99,
                  "incorrect value for biases[69].code, expected 99, is %d",
                  check_msg->biases[69].code);
    ck_assert_msg(check_msg->biases[69].value == 30911,
                  "incorrect value for biases[69].value, expected 30911, is %d",
                  check_msg->biases[69].value);
    ck_assert_msg(check_msg->biases[70].code == 77,
                  "incorrect value for biases[70].code, expected 77, is %d",
                  check_msg->biases[70].code);
    ck_assert_msg(check_msg->biases[70].value == 23488,
                  "incorrect value for biases[70].value, expected 23488, is %d",
                  check_msg->biases[70].value);
    ck_assert_msg(check_msg->biases[71].code == 224,
                  "incorrect value for biases[71].code, expected 224, is %d",
                  check_msg->biases[71].code);
    ck_assert_msg(check_msg->biases[71].value == -7679,
                  "incorrect value for biases[71].value, expected -7679, is %d",
                  check_msg->biases[71].value);
    ck_assert_msg(check_msg->biases[72].code == 50,
                  "incorrect value for biases[72].code, expected 50, is %d",
                  check_msg->biases[72].code);
    ck_assert_msg(
        check_msg->biases[72].value == -28073,
        "incorrect value for biases[72].value, expected -28073, is %d",
        check_msg->biases[72].value);
    ck_assert_msg(check_msg->biases[73].code == 148,
                  "incorrect value for biases[73].code, expected 148, is %d",
                  check_msg->biases[73].code);
    ck_assert_msg(check_msg->biases[73].value == 25838,
                  "incorrect value for biases[73].value, expected 25838, is %d",
                  check_msg->biases[73].value);
    ck_assert_msg(check_msg->biases[74].code == 179,
                  "incorrect value for biases[74].code, expected 179, is %d",
                  check_msg->biases[74].code);
    ck_assert_msg(check_msg->biases[74].value == -7299,
                  "incorrect value for biases[74].value, expected -7299, is %d",
                  check_msg->biases[74].value);
    ck_assert_msg(check_msg->biases[75].code == 215,
                  "incorrect value for biases[75].code, expected 215, is %d",
                  check_msg->biases[75].code);
    ck_assert_msg(
        check_msg->biases[75].value == -18328,
        "incorrect value for biases[75].value, expected -18328, is %d",
        check_msg->biases[75].value);
    ck_assert_msg(check_msg->biases[76].code == 31,
                  "incorrect value for biases[76].code, expected 31, is %d",
                  check_msg->biases[76].code);
    ck_assert_msg(check_msg->biases[76].value == 23097,
                  "incorrect value for biases[76].value, expected 23097, is %d",
                  check_msg->biases[76].value);
    ck_assert_msg(check_msg->biases[77].code == 79,
                  "incorrect value for biases[77].code, expected 79, is %d",
                  check_msg->biases[77].code);
    ck_assert_msg(
        check_msg->biases[77].value == -25579,
        "incorrect value for biases[77].value, expected -25579, is %d",
        check_msg->biases[77].value);
    ck_assert_msg(check_msg->biases[78].code == 245,
                  "incorrect value for biases[78].code, expected 245, is %d",
                  check_msg->biases[78].code);
    ck_assert_msg(check_msg->biases[78].value == 15441,
                  "incorrect value for biases[78].value, expected 15441, is %d",
                  check_msg->biases[78].value);
    ck_assert_msg(check_msg->biases[79].code == 93,
                  "incorrect value for biases[79].code, expected 93, is %d",
                  check_msg->biases[79].code);
    ck_assert_msg(check_msg->biases[79].value == 15530,
                  "incorrect value for biases[79].value, expected 15530, is %d",
                  check_msg->biases[79].value);
    ck_assert_msg(check_msg->biases[80].code == 200,
                  "incorrect value for biases[80].code, expected 200, is %d",
                  check_msg->biases[80].code);
    ck_assert_msg(check_msg->biases[80].value == 3495,
                  "incorrect value for biases[80].value, expected 3495, is %d",
                  check_msg->biases[80].value);
    ck_assert_msg(check_msg->iod_ssr == 132,
                  "incorrect value for iod_ssr, expected 132, is %d",
                  check_msg->iod_ssr);
    ck_assert_msg(check_msg->sid.code == 241,
                  "incorrect value for sid.code, expected 241, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.sat == 133,
                  "incorrect value for sid.sat, expected 133, is %d",
                  check_msg->sid.sat);
    ck_assert_msg(check_msg->time.tow == 387144400,
                  "incorrect value for time.tow, expected 387144400, is %d",
                  check_msg->time.tow);
    ck_assert_msg(check_msg->time.wn == 16905,
                  "incorrect value for time.wn, expected 16905, is %d",
                  check_msg->time.wn);
    ck_assert_msg(check_msg->update_interval == 254,
                  "incorrect value for update_interval, expected 254, is %d",
                  check_msg->update_interval);
  }
}
END_TEST

Suite *legacy_auto_check_sbp_ssr_MsgSsrCodeBiases_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: legacy_auto_check_sbp_ssr_MsgSsrCodeBiases");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_legacy_auto_check_sbp_ssr_MsgSsrCodeBiases");
  tcase_add_test(tc_acq, test_legacy_auto_check_sbp_ssr_MsgSsrCodeBiases);
  suite_add_tcase(s, tc_acq);
  return s;
}