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
// spec/tests/yaml/swiftnav/sbp/piksi/test_MsgCellModemStatus.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <libsbp/legacy/piksi.h>
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

START_TEST(test_legacy_auto_check_sbp_piksi_MsgCellModemStatus) {
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

    sbp_payload_callback_register(&sbp_state, 0xbe, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0xbe, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  190, 0,   19,  27,  255, 103, 205, 48,  6,   70,  123, 242, 46,
        52,  64,  176, 154, 98,  43,  132, 196, 89,  253, 161, 250, 174, 204,
        110, 47,  38,  187, 63,  102, 177, 162, 49,  80,  194, 37,  107, 60,
        225, 52,  101, 178, 142, 246, 21,  17,  93,  75,  169, 86,  16,  209,
        80,  243, 30,  206, 220, 206, 115, 47,  154, 91,  227, 88,  11,  1,
        85,  146, 100, 190, 232, 207, 61,  61,  201, 220, 31,  78,  34,  57,
        82,  59,  104, 65,  221, 0,   43,  210, 9,   32,  122, 29,  237, 11,
        151, 223, 18,  81,  204, 172, 234, 127, 3,   82,  133, 169, 12,  176,
        193, 0,   24,  121, 85,  55,  214, 198, 75,  234, 179, 214, 85,  94,
        115, 21,  73,  121, 75,  46,  158, 63,  100, 122, 213, 20,  85,  212,
        131, 50,  224, 218, 215, 215, 149, 2,   19,  129, 39,  164, 5,   175,
        6,   62,  51,  78,  66,  248, 116, 88,  90,  128, 226, 177, 0,   47,
        140, 33,  126, 221, 110, 144, 97,  74,  250, 181, 199, 27,  176, 65,
        185, 110, 92,  34,  44,  131, 96,  178, 40,  176, 4,   90,  36,  7,
        180, 244, 244, 23,  108, 171, 204, 196, 61,  51,  179, 242, 156, 81,
        83,  16,  15,  134, 40,  245, 253, 150, 94,  150, 144, 197, 113, 5,
        141, 232, 33,  101, 231, 38,  75,  178, 243, 119, 1,   248, 218, 86,
        7,   88,  197, 148, 240, 227, 2,   65,  173, 122, 143, 251, 156, 217,
        67,  239, 219, 31,  224, 176, 129, 81,  80,  40,  230,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_cell_modem_status_t *test_msg =
        (msg_cell_modem_status_t *)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[0] = 123;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[1] = 242;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[2] = 46;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[3] = 52;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[4] = 64;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[5] = 176;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[6] = 154;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[7] = 98;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[8] = 43;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[9] = 132;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[10] = 196;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[11] = 89;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[12] = 253;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[13] = 161;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[14] = 250;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[15] = 174;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[16] = 204;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[17] = 110;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[18] = 47;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[19] = 38;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[20] = 187;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[21] = 63;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[22] = 102;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[23] = 177;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[24] = 162;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[25] = 49;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[26] = 80;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[27] = 194;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[28] = 37;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[29] = 107;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[30] = 60;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[31] = 225;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[32] = 52;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[33] = 101;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[34] = 178;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[35] = 142;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[36] = 246;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[37] = 21;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[38] = 17;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[39] = 93;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[40] = 75;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[41] = 169;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[42] = 86;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[43] = 16;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[44] = 209;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[45] = 80;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[46] = 243;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[47] = 30;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[48] = 206;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[49] = 220;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[50] = 206;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[51] = 115;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[52] = 47;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[53] = 154;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[54] = 91;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[55] = 227;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[56] = 88;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[57] = 11;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[58] = 1;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[59] = 85;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[60] = 146;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[61] = 100;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[62] = 190;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[63] = 232;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[64] = 207;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[65] = 61;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[66] = 61;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[67] = 201;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[68] = 220;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[69] = 31;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[70] = 78;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[71] = 34;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[72] = 57;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[73] = 82;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[74] = 59;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[75] = 104;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[76] = 65;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[77] = 221;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[78] = 0;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[79] = 43;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[80] = 210;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[81] = 9;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[82] = 32;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[83] = 122;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[84] = 29;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[85] = 237;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[86] = 11;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[87] = 151;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[88] = 223;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[89] = 18;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[90] = 81;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[91] = 204;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[92] = 172;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[93] = 234;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[94] = 127;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[95] = 3;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[96] = 82;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[97] = 133;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[98] = 169;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[99] = 12;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[100] = 176;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[101] = 193;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[102] = 0;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[103] = 24;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[104] = 121;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[105] = 85;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[106] = 55;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[107] = 214;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[108] = 198;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[109] = 75;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[110] = 234;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[111] = 179;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[112] = 214;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[113] = 85;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[114] = 94;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[115] = 115;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[116] = 21;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[117] = 73;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[118] = 121;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[119] = 75;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[120] = 46;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[121] = 158;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[122] = 63;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[123] = 100;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[124] = 122;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[125] = 213;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[126] = 20;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[127] = 85;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[128] = 212;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[129] = 131;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[130] = 50;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[131] = 224;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[132] = 218;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[133] = 215;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[134] = 215;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[135] = 149;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[136] = 2;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[137] = 19;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[138] = 129;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[139] = 39;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[140] = 164;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[141] = 5;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[142] = 175;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[143] = 6;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[144] = 62;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[145] = 51;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[146] = 78;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[147] = 66;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[148] = 248;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[149] = 116;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[150] = 88;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[151] = 90;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[152] = 128;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[153] = 226;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[154] = 177;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[155] = 0;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[156] = 47;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[157] = 140;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[158] = 33;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[159] = 126;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[160] = 221;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[161] = 110;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[162] = 144;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[163] = 97;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[164] = 74;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[165] = 250;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[166] = 181;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[167] = 199;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[168] = 27;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[169] = 176;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[170] = 65;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[171] = 185;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[172] = 110;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[173] = 92;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[174] = 34;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[175] = 44;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[176] = 131;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[177] = 96;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[178] = 178;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[179] = 40;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[180] = 176;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[181] = 4;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[182] = 90;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[183] = 36;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[184] = 7;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[185] = 180;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[186] = 244;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[187] = 244;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[188] = 23;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[189] = 108;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[190] = 171;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[191] = 204;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[192] = 196;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[193] = 61;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[194] = 51;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[195] = 179;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[196] = 242;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[197] = 156;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[198] = 81;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[199] = 83;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[200] = 16;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[201] = 15;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[202] = 134;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[203] = 40;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[204] = 245;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[205] = 253;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[206] = 150;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[207] = 94;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[208] = 150;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[209] = 144;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[210] = 197;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[211] = 113;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[212] = 5;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[213] = 141;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[214] = 232;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[215] = 33;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[216] = 101;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[217] = 231;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[218] = 38;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[219] = 75;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[220] = 178;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[221] = 243;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[222] = 119;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[223] = 1;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[224] = 248;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[225] = 218;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[226] = 86;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[227] = 7;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[228] = 88;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[229] = 197;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[230] = 148;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[231] = 240;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[232] = 227;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[233] = 2;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[234] = 65;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[235] = 173;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[236] = 122;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[237] = 143;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[238] = 251;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[239] = 156;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[240] = 217;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[241] = 67;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[242] = 239;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[243] = 219;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[244] = 31;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[245] = 224;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[246] = 176;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[247] = 129;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[248] = 81;
    if (sizeof(test_msg->reserved) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->reserved[0]);
    }
    test_msg->reserved[249] = 80;
    test_msg->signal_error_rate = 8588.2001953125;
    test_msg->signal_strength = 103;
    sbp_payload_send(&sbp_state, 0xbe, 6931, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 6931,
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
    ck_assert_msg(last_frame.sender_id == 6931,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0xbe,
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
    msg_cell_modem_status_t *check_msg =
        (msg_cell_modem_status_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->reserved[0] == 123,
                  "incorrect value for reserved[0], expected 123, is %d",
                  check_msg->reserved[0]);
    ck_assert_msg(check_msg->reserved[1] == 242,
                  "incorrect value for reserved[1], expected 242, is %d",
                  check_msg->reserved[1]);
    ck_assert_msg(check_msg->reserved[2] == 46,
                  "incorrect value for reserved[2], expected 46, is %d",
                  check_msg->reserved[2]);
    ck_assert_msg(check_msg->reserved[3] == 52,
                  "incorrect value for reserved[3], expected 52, is %d",
                  check_msg->reserved[3]);
    ck_assert_msg(check_msg->reserved[4] == 64,
                  "incorrect value for reserved[4], expected 64, is %d",
                  check_msg->reserved[4]);
    ck_assert_msg(check_msg->reserved[5] == 176,
                  "incorrect value for reserved[5], expected 176, is %d",
                  check_msg->reserved[5]);
    ck_assert_msg(check_msg->reserved[6] == 154,
                  "incorrect value for reserved[6], expected 154, is %d",
                  check_msg->reserved[6]);
    ck_assert_msg(check_msg->reserved[7] == 98,
                  "incorrect value for reserved[7], expected 98, is %d",
                  check_msg->reserved[7]);
    ck_assert_msg(check_msg->reserved[8] == 43,
                  "incorrect value for reserved[8], expected 43, is %d",
                  check_msg->reserved[8]);
    ck_assert_msg(check_msg->reserved[9] == 132,
                  "incorrect value for reserved[9], expected 132, is %d",
                  check_msg->reserved[9]);
    ck_assert_msg(check_msg->reserved[10] == 196,
                  "incorrect value for reserved[10], expected 196, is %d",
                  check_msg->reserved[10]);
    ck_assert_msg(check_msg->reserved[11] == 89,
                  "incorrect value for reserved[11], expected 89, is %d",
                  check_msg->reserved[11]);
    ck_assert_msg(check_msg->reserved[12] == 253,
                  "incorrect value for reserved[12], expected 253, is %d",
                  check_msg->reserved[12]);
    ck_assert_msg(check_msg->reserved[13] == 161,
                  "incorrect value for reserved[13], expected 161, is %d",
                  check_msg->reserved[13]);
    ck_assert_msg(check_msg->reserved[14] == 250,
                  "incorrect value for reserved[14], expected 250, is %d",
                  check_msg->reserved[14]);
    ck_assert_msg(check_msg->reserved[15] == 174,
                  "incorrect value for reserved[15], expected 174, is %d",
                  check_msg->reserved[15]);
    ck_assert_msg(check_msg->reserved[16] == 204,
                  "incorrect value for reserved[16], expected 204, is %d",
                  check_msg->reserved[16]);
    ck_assert_msg(check_msg->reserved[17] == 110,
                  "incorrect value for reserved[17], expected 110, is %d",
                  check_msg->reserved[17]);
    ck_assert_msg(check_msg->reserved[18] == 47,
                  "incorrect value for reserved[18], expected 47, is %d",
                  check_msg->reserved[18]);
    ck_assert_msg(check_msg->reserved[19] == 38,
                  "incorrect value for reserved[19], expected 38, is %d",
                  check_msg->reserved[19]);
    ck_assert_msg(check_msg->reserved[20] == 187,
                  "incorrect value for reserved[20], expected 187, is %d",
                  check_msg->reserved[20]);
    ck_assert_msg(check_msg->reserved[21] == 63,
                  "incorrect value for reserved[21], expected 63, is %d",
                  check_msg->reserved[21]);
    ck_assert_msg(check_msg->reserved[22] == 102,
                  "incorrect value for reserved[22], expected 102, is %d",
                  check_msg->reserved[22]);
    ck_assert_msg(check_msg->reserved[23] == 177,
                  "incorrect value for reserved[23], expected 177, is %d",
                  check_msg->reserved[23]);
    ck_assert_msg(check_msg->reserved[24] == 162,
                  "incorrect value for reserved[24], expected 162, is %d",
                  check_msg->reserved[24]);
    ck_assert_msg(check_msg->reserved[25] == 49,
                  "incorrect value for reserved[25], expected 49, is %d",
                  check_msg->reserved[25]);
    ck_assert_msg(check_msg->reserved[26] == 80,
                  "incorrect value for reserved[26], expected 80, is %d",
                  check_msg->reserved[26]);
    ck_assert_msg(check_msg->reserved[27] == 194,
                  "incorrect value for reserved[27], expected 194, is %d",
                  check_msg->reserved[27]);
    ck_assert_msg(check_msg->reserved[28] == 37,
                  "incorrect value for reserved[28], expected 37, is %d",
                  check_msg->reserved[28]);
    ck_assert_msg(check_msg->reserved[29] == 107,
                  "incorrect value for reserved[29], expected 107, is %d",
                  check_msg->reserved[29]);
    ck_assert_msg(check_msg->reserved[30] == 60,
                  "incorrect value for reserved[30], expected 60, is %d",
                  check_msg->reserved[30]);
    ck_assert_msg(check_msg->reserved[31] == 225,
                  "incorrect value for reserved[31], expected 225, is %d",
                  check_msg->reserved[31]);
    ck_assert_msg(check_msg->reserved[32] == 52,
                  "incorrect value for reserved[32], expected 52, is %d",
                  check_msg->reserved[32]);
    ck_assert_msg(check_msg->reserved[33] == 101,
                  "incorrect value for reserved[33], expected 101, is %d",
                  check_msg->reserved[33]);
    ck_assert_msg(check_msg->reserved[34] == 178,
                  "incorrect value for reserved[34], expected 178, is %d",
                  check_msg->reserved[34]);
    ck_assert_msg(check_msg->reserved[35] == 142,
                  "incorrect value for reserved[35], expected 142, is %d",
                  check_msg->reserved[35]);
    ck_assert_msg(check_msg->reserved[36] == 246,
                  "incorrect value for reserved[36], expected 246, is %d",
                  check_msg->reserved[36]);
    ck_assert_msg(check_msg->reserved[37] == 21,
                  "incorrect value for reserved[37], expected 21, is %d",
                  check_msg->reserved[37]);
    ck_assert_msg(check_msg->reserved[38] == 17,
                  "incorrect value for reserved[38], expected 17, is %d",
                  check_msg->reserved[38]);
    ck_assert_msg(check_msg->reserved[39] == 93,
                  "incorrect value for reserved[39], expected 93, is %d",
                  check_msg->reserved[39]);
    ck_assert_msg(check_msg->reserved[40] == 75,
                  "incorrect value for reserved[40], expected 75, is %d",
                  check_msg->reserved[40]);
    ck_assert_msg(check_msg->reserved[41] == 169,
                  "incorrect value for reserved[41], expected 169, is %d",
                  check_msg->reserved[41]);
    ck_assert_msg(check_msg->reserved[42] == 86,
                  "incorrect value for reserved[42], expected 86, is %d",
                  check_msg->reserved[42]);
    ck_assert_msg(check_msg->reserved[43] == 16,
                  "incorrect value for reserved[43], expected 16, is %d",
                  check_msg->reserved[43]);
    ck_assert_msg(check_msg->reserved[44] == 209,
                  "incorrect value for reserved[44], expected 209, is %d",
                  check_msg->reserved[44]);
    ck_assert_msg(check_msg->reserved[45] == 80,
                  "incorrect value for reserved[45], expected 80, is %d",
                  check_msg->reserved[45]);
    ck_assert_msg(check_msg->reserved[46] == 243,
                  "incorrect value for reserved[46], expected 243, is %d",
                  check_msg->reserved[46]);
    ck_assert_msg(check_msg->reserved[47] == 30,
                  "incorrect value for reserved[47], expected 30, is %d",
                  check_msg->reserved[47]);
    ck_assert_msg(check_msg->reserved[48] == 206,
                  "incorrect value for reserved[48], expected 206, is %d",
                  check_msg->reserved[48]);
    ck_assert_msg(check_msg->reserved[49] == 220,
                  "incorrect value for reserved[49], expected 220, is %d",
                  check_msg->reserved[49]);
    ck_assert_msg(check_msg->reserved[50] == 206,
                  "incorrect value for reserved[50], expected 206, is %d",
                  check_msg->reserved[50]);
    ck_assert_msg(check_msg->reserved[51] == 115,
                  "incorrect value for reserved[51], expected 115, is %d",
                  check_msg->reserved[51]);
    ck_assert_msg(check_msg->reserved[52] == 47,
                  "incorrect value for reserved[52], expected 47, is %d",
                  check_msg->reserved[52]);
    ck_assert_msg(check_msg->reserved[53] == 154,
                  "incorrect value for reserved[53], expected 154, is %d",
                  check_msg->reserved[53]);
    ck_assert_msg(check_msg->reserved[54] == 91,
                  "incorrect value for reserved[54], expected 91, is %d",
                  check_msg->reserved[54]);
    ck_assert_msg(check_msg->reserved[55] == 227,
                  "incorrect value for reserved[55], expected 227, is %d",
                  check_msg->reserved[55]);
    ck_assert_msg(check_msg->reserved[56] == 88,
                  "incorrect value for reserved[56], expected 88, is %d",
                  check_msg->reserved[56]);
    ck_assert_msg(check_msg->reserved[57] == 11,
                  "incorrect value for reserved[57], expected 11, is %d",
                  check_msg->reserved[57]);
    ck_assert_msg(check_msg->reserved[58] == 1,
                  "incorrect value for reserved[58], expected 1, is %d",
                  check_msg->reserved[58]);
    ck_assert_msg(check_msg->reserved[59] == 85,
                  "incorrect value for reserved[59], expected 85, is %d",
                  check_msg->reserved[59]);
    ck_assert_msg(check_msg->reserved[60] == 146,
                  "incorrect value for reserved[60], expected 146, is %d",
                  check_msg->reserved[60]);
    ck_assert_msg(check_msg->reserved[61] == 100,
                  "incorrect value for reserved[61], expected 100, is %d",
                  check_msg->reserved[61]);
    ck_assert_msg(check_msg->reserved[62] == 190,
                  "incorrect value for reserved[62], expected 190, is %d",
                  check_msg->reserved[62]);
    ck_assert_msg(check_msg->reserved[63] == 232,
                  "incorrect value for reserved[63], expected 232, is %d",
                  check_msg->reserved[63]);
    ck_assert_msg(check_msg->reserved[64] == 207,
                  "incorrect value for reserved[64], expected 207, is %d",
                  check_msg->reserved[64]);
    ck_assert_msg(check_msg->reserved[65] == 61,
                  "incorrect value for reserved[65], expected 61, is %d",
                  check_msg->reserved[65]);
    ck_assert_msg(check_msg->reserved[66] == 61,
                  "incorrect value for reserved[66], expected 61, is %d",
                  check_msg->reserved[66]);
    ck_assert_msg(check_msg->reserved[67] == 201,
                  "incorrect value for reserved[67], expected 201, is %d",
                  check_msg->reserved[67]);
    ck_assert_msg(check_msg->reserved[68] == 220,
                  "incorrect value for reserved[68], expected 220, is %d",
                  check_msg->reserved[68]);
    ck_assert_msg(check_msg->reserved[69] == 31,
                  "incorrect value for reserved[69], expected 31, is %d",
                  check_msg->reserved[69]);
    ck_assert_msg(check_msg->reserved[70] == 78,
                  "incorrect value for reserved[70], expected 78, is %d",
                  check_msg->reserved[70]);
    ck_assert_msg(check_msg->reserved[71] == 34,
                  "incorrect value for reserved[71], expected 34, is %d",
                  check_msg->reserved[71]);
    ck_assert_msg(check_msg->reserved[72] == 57,
                  "incorrect value for reserved[72], expected 57, is %d",
                  check_msg->reserved[72]);
    ck_assert_msg(check_msg->reserved[73] == 82,
                  "incorrect value for reserved[73], expected 82, is %d",
                  check_msg->reserved[73]);
    ck_assert_msg(check_msg->reserved[74] == 59,
                  "incorrect value for reserved[74], expected 59, is %d",
                  check_msg->reserved[74]);
    ck_assert_msg(check_msg->reserved[75] == 104,
                  "incorrect value for reserved[75], expected 104, is %d",
                  check_msg->reserved[75]);
    ck_assert_msg(check_msg->reserved[76] == 65,
                  "incorrect value for reserved[76], expected 65, is %d",
                  check_msg->reserved[76]);
    ck_assert_msg(check_msg->reserved[77] == 221,
                  "incorrect value for reserved[77], expected 221, is %d",
                  check_msg->reserved[77]);
    ck_assert_msg(check_msg->reserved[78] == 0,
                  "incorrect value for reserved[78], expected 0, is %d",
                  check_msg->reserved[78]);
    ck_assert_msg(check_msg->reserved[79] == 43,
                  "incorrect value for reserved[79], expected 43, is %d",
                  check_msg->reserved[79]);
    ck_assert_msg(check_msg->reserved[80] == 210,
                  "incorrect value for reserved[80], expected 210, is %d",
                  check_msg->reserved[80]);
    ck_assert_msg(check_msg->reserved[81] == 9,
                  "incorrect value for reserved[81], expected 9, is %d",
                  check_msg->reserved[81]);
    ck_assert_msg(check_msg->reserved[82] == 32,
                  "incorrect value for reserved[82], expected 32, is %d",
                  check_msg->reserved[82]);
    ck_assert_msg(check_msg->reserved[83] == 122,
                  "incorrect value for reserved[83], expected 122, is %d",
                  check_msg->reserved[83]);
    ck_assert_msg(check_msg->reserved[84] == 29,
                  "incorrect value for reserved[84], expected 29, is %d",
                  check_msg->reserved[84]);
    ck_assert_msg(check_msg->reserved[85] == 237,
                  "incorrect value for reserved[85], expected 237, is %d",
                  check_msg->reserved[85]);
    ck_assert_msg(check_msg->reserved[86] == 11,
                  "incorrect value for reserved[86], expected 11, is %d",
                  check_msg->reserved[86]);
    ck_assert_msg(check_msg->reserved[87] == 151,
                  "incorrect value for reserved[87], expected 151, is %d",
                  check_msg->reserved[87]);
    ck_assert_msg(check_msg->reserved[88] == 223,
                  "incorrect value for reserved[88], expected 223, is %d",
                  check_msg->reserved[88]);
    ck_assert_msg(check_msg->reserved[89] == 18,
                  "incorrect value for reserved[89], expected 18, is %d",
                  check_msg->reserved[89]);
    ck_assert_msg(check_msg->reserved[90] == 81,
                  "incorrect value for reserved[90], expected 81, is %d",
                  check_msg->reserved[90]);
    ck_assert_msg(check_msg->reserved[91] == 204,
                  "incorrect value for reserved[91], expected 204, is %d",
                  check_msg->reserved[91]);
    ck_assert_msg(check_msg->reserved[92] == 172,
                  "incorrect value for reserved[92], expected 172, is %d",
                  check_msg->reserved[92]);
    ck_assert_msg(check_msg->reserved[93] == 234,
                  "incorrect value for reserved[93], expected 234, is %d",
                  check_msg->reserved[93]);
    ck_assert_msg(check_msg->reserved[94] == 127,
                  "incorrect value for reserved[94], expected 127, is %d",
                  check_msg->reserved[94]);
    ck_assert_msg(check_msg->reserved[95] == 3,
                  "incorrect value for reserved[95], expected 3, is %d",
                  check_msg->reserved[95]);
    ck_assert_msg(check_msg->reserved[96] == 82,
                  "incorrect value for reserved[96], expected 82, is %d",
                  check_msg->reserved[96]);
    ck_assert_msg(check_msg->reserved[97] == 133,
                  "incorrect value for reserved[97], expected 133, is %d",
                  check_msg->reserved[97]);
    ck_assert_msg(check_msg->reserved[98] == 169,
                  "incorrect value for reserved[98], expected 169, is %d",
                  check_msg->reserved[98]);
    ck_assert_msg(check_msg->reserved[99] == 12,
                  "incorrect value for reserved[99], expected 12, is %d",
                  check_msg->reserved[99]);
    ck_assert_msg(check_msg->reserved[100] == 176,
                  "incorrect value for reserved[100], expected 176, is %d",
                  check_msg->reserved[100]);
    ck_assert_msg(check_msg->reserved[101] == 193,
                  "incorrect value for reserved[101], expected 193, is %d",
                  check_msg->reserved[101]);
    ck_assert_msg(check_msg->reserved[102] == 0,
                  "incorrect value for reserved[102], expected 0, is %d",
                  check_msg->reserved[102]);
    ck_assert_msg(check_msg->reserved[103] == 24,
                  "incorrect value for reserved[103], expected 24, is %d",
                  check_msg->reserved[103]);
    ck_assert_msg(check_msg->reserved[104] == 121,
                  "incorrect value for reserved[104], expected 121, is %d",
                  check_msg->reserved[104]);
    ck_assert_msg(check_msg->reserved[105] == 85,
                  "incorrect value for reserved[105], expected 85, is %d",
                  check_msg->reserved[105]);
    ck_assert_msg(check_msg->reserved[106] == 55,
                  "incorrect value for reserved[106], expected 55, is %d",
                  check_msg->reserved[106]);
    ck_assert_msg(check_msg->reserved[107] == 214,
                  "incorrect value for reserved[107], expected 214, is %d",
                  check_msg->reserved[107]);
    ck_assert_msg(check_msg->reserved[108] == 198,
                  "incorrect value for reserved[108], expected 198, is %d",
                  check_msg->reserved[108]);
    ck_assert_msg(check_msg->reserved[109] == 75,
                  "incorrect value for reserved[109], expected 75, is %d",
                  check_msg->reserved[109]);
    ck_assert_msg(check_msg->reserved[110] == 234,
                  "incorrect value for reserved[110], expected 234, is %d",
                  check_msg->reserved[110]);
    ck_assert_msg(check_msg->reserved[111] == 179,
                  "incorrect value for reserved[111], expected 179, is %d",
                  check_msg->reserved[111]);
    ck_assert_msg(check_msg->reserved[112] == 214,
                  "incorrect value for reserved[112], expected 214, is %d",
                  check_msg->reserved[112]);
    ck_assert_msg(check_msg->reserved[113] == 85,
                  "incorrect value for reserved[113], expected 85, is %d",
                  check_msg->reserved[113]);
    ck_assert_msg(check_msg->reserved[114] == 94,
                  "incorrect value for reserved[114], expected 94, is %d",
                  check_msg->reserved[114]);
    ck_assert_msg(check_msg->reserved[115] == 115,
                  "incorrect value for reserved[115], expected 115, is %d",
                  check_msg->reserved[115]);
    ck_assert_msg(check_msg->reserved[116] == 21,
                  "incorrect value for reserved[116], expected 21, is %d",
                  check_msg->reserved[116]);
    ck_assert_msg(check_msg->reserved[117] == 73,
                  "incorrect value for reserved[117], expected 73, is %d",
                  check_msg->reserved[117]);
    ck_assert_msg(check_msg->reserved[118] == 121,
                  "incorrect value for reserved[118], expected 121, is %d",
                  check_msg->reserved[118]);
    ck_assert_msg(check_msg->reserved[119] == 75,
                  "incorrect value for reserved[119], expected 75, is %d",
                  check_msg->reserved[119]);
    ck_assert_msg(check_msg->reserved[120] == 46,
                  "incorrect value for reserved[120], expected 46, is %d",
                  check_msg->reserved[120]);
    ck_assert_msg(check_msg->reserved[121] == 158,
                  "incorrect value for reserved[121], expected 158, is %d",
                  check_msg->reserved[121]);
    ck_assert_msg(check_msg->reserved[122] == 63,
                  "incorrect value for reserved[122], expected 63, is %d",
                  check_msg->reserved[122]);
    ck_assert_msg(check_msg->reserved[123] == 100,
                  "incorrect value for reserved[123], expected 100, is %d",
                  check_msg->reserved[123]);
    ck_assert_msg(check_msg->reserved[124] == 122,
                  "incorrect value for reserved[124], expected 122, is %d",
                  check_msg->reserved[124]);
    ck_assert_msg(check_msg->reserved[125] == 213,
                  "incorrect value for reserved[125], expected 213, is %d",
                  check_msg->reserved[125]);
    ck_assert_msg(check_msg->reserved[126] == 20,
                  "incorrect value for reserved[126], expected 20, is %d",
                  check_msg->reserved[126]);
    ck_assert_msg(check_msg->reserved[127] == 85,
                  "incorrect value for reserved[127], expected 85, is %d",
                  check_msg->reserved[127]);
    ck_assert_msg(check_msg->reserved[128] == 212,
                  "incorrect value for reserved[128], expected 212, is %d",
                  check_msg->reserved[128]);
    ck_assert_msg(check_msg->reserved[129] == 131,
                  "incorrect value for reserved[129], expected 131, is %d",
                  check_msg->reserved[129]);
    ck_assert_msg(check_msg->reserved[130] == 50,
                  "incorrect value for reserved[130], expected 50, is %d",
                  check_msg->reserved[130]);
    ck_assert_msg(check_msg->reserved[131] == 224,
                  "incorrect value for reserved[131], expected 224, is %d",
                  check_msg->reserved[131]);
    ck_assert_msg(check_msg->reserved[132] == 218,
                  "incorrect value for reserved[132], expected 218, is %d",
                  check_msg->reserved[132]);
    ck_assert_msg(check_msg->reserved[133] == 215,
                  "incorrect value for reserved[133], expected 215, is %d",
                  check_msg->reserved[133]);
    ck_assert_msg(check_msg->reserved[134] == 215,
                  "incorrect value for reserved[134], expected 215, is %d",
                  check_msg->reserved[134]);
    ck_assert_msg(check_msg->reserved[135] == 149,
                  "incorrect value for reserved[135], expected 149, is %d",
                  check_msg->reserved[135]);
    ck_assert_msg(check_msg->reserved[136] == 2,
                  "incorrect value for reserved[136], expected 2, is %d",
                  check_msg->reserved[136]);
    ck_assert_msg(check_msg->reserved[137] == 19,
                  "incorrect value for reserved[137], expected 19, is %d",
                  check_msg->reserved[137]);
    ck_assert_msg(check_msg->reserved[138] == 129,
                  "incorrect value for reserved[138], expected 129, is %d",
                  check_msg->reserved[138]);
    ck_assert_msg(check_msg->reserved[139] == 39,
                  "incorrect value for reserved[139], expected 39, is %d",
                  check_msg->reserved[139]);
    ck_assert_msg(check_msg->reserved[140] == 164,
                  "incorrect value for reserved[140], expected 164, is %d",
                  check_msg->reserved[140]);
    ck_assert_msg(check_msg->reserved[141] == 5,
                  "incorrect value for reserved[141], expected 5, is %d",
                  check_msg->reserved[141]);
    ck_assert_msg(check_msg->reserved[142] == 175,
                  "incorrect value for reserved[142], expected 175, is %d",
                  check_msg->reserved[142]);
    ck_assert_msg(check_msg->reserved[143] == 6,
                  "incorrect value for reserved[143], expected 6, is %d",
                  check_msg->reserved[143]);
    ck_assert_msg(check_msg->reserved[144] == 62,
                  "incorrect value for reserved[144], expected 62, is %d",
                  check_msg->reserved[144]);
    ck_assert_msg(check_msg->reserved[145] == 51,
                  "incorrect value for reserved[145], expected 51, is %d",
                  check_msg->reserved[145]);
    ck_assert_msg(check_msg->reserved[146] == 78,
                  "incorrect value for reserved[146], expected 78, is %d",
                  check_msg->reserved[146]);
    ck_assert_msg(check_msg->reserved[147] == 66,
                  "incorrect value for reserved[147], expected 66, is %d",
                  check_msg->reserved[147]);
    ck_assert_msg(check_msg->reserved[148] == 248,
                  "incorrect value for reserved[148], expected 248, is %d",
                  check_msg->reserved[148]);
    ck_assert_msg(check_msg->reserved[149] == 116,
                  "incorrect value for reserved[149], expected 116, is %d",
                  check_msg->reserved[149]);
    ck_assert_msg(check_msg->reserved[150] == 88,
                  "incorrect value for reserved[150], expected 88, is %d",
                  check_msg->reserved[150]);
    ck_assert_msg(check_msg->reserved[151] == 90,
                  "incorrect value for reserved[151], expected 90, is %d",
                  check_msg->reserved[151]);
    ck_assert_msg(check_msg->reserved[152] == 128,
                  "incorrect value for reserved[152], expected 128, is %d",
                  check_msg->reserved[152]);
    ck_assert_msg(check_msg->reserved[153] == 226,
                  "incorrect value for reserved[153], expected 226, is %d",
                  check_msg->reserved[153]);
    ck_assert_msg(check_msg->reserved[154] == 177,
                  "incorrect value for reserved[154], expected 177, is %d",
                  check_msg->reserved[154]);
    ck_assert_msg(check_msg->reserved[155] == 0,
                  "incorrect value for reserved[155], expected 0, is %d",
                  check_msg->reserved[155]);
    ck_assert_msg(check_msg->reserved[156] == 47,
                  "incorrect value for reserved[156], expected 47, is %d",
                  check_msg->reserved[156]);
    ck_assert_msg(check_msg->reserved[157] == 140,
                  "incorrect value for reserved[157], expected 140, is %d",
                  check_msg->reserved[157]);
    ck_assert_msg(check_msg->reserved[158] == 33,
                  "incorrect value for reserved[158], expected 33, is %d",
                  check_msg->reserved[158]);
    ck_assert_msg(check_msg->reserved[159] == 126,
                  "incorrect value for reserved[159], expected 126, is %d",
                  check_msg->reserved[159]);
    ck_assert_msg(check_msg->reserved[160] == 221,
                  "incorrect value for reserved[160], expected 221, is %d",
                  check_msg->reserved[160]);
    ck_assert_msg(check_msg->reserved[161] == 110,
                  "incorrect value for reserved[161], expected 110, is %d",
                  check_msg->reserved[161]);
    ck_assert_msg(check_msg->reserved[162] == 144,
                  "incorrect value for reserved[162], expected 144, is %d",
                  check_msg->reserved[162]);
    ck_assert_msg(check_msg->reserved[163] == 97,
                  "incorrect value for reserved[163], expected 97, is %d",
                  check_msg->reserved[163]);
    ck_assert_msg(check_msg->reserved[164] == 74,
                  "incorrect value for reserved[164], expected 74, is %d",
                  check_msg->reserved[164]);
    ck_assert_msg(check_msg->reserved[165] == 250,
                  "incorrect value for reserved[165], expected 250, is %d",
                  check_msg->reserved[165]);
    ck_assert_msg(check_msg->reserved[166] == 181,
                  "incorrect value for reserved[166], expected 181, is %d",
                  check_msg->reserved[166]);
    ck_assert_msg(check_msg->reserved[167] == 199,
                  "incorrect value for reserved[167], expected 199, is %d",
                  check_msg->reserved[167]);
    ck_assert_msg(check_msg->reserved[168] == 27,
                  "incorrect value for reserved[168], expected 27, is %d",
                  check_msg->reserved[168]);
    ck_assert_msg(check_msg->reserved[169] == 176,
                  "incorrect value for reserved[169], expected 176, is %d",
                  check_msg->reserved[169]);
    ck_assert_msg(check_msg->reserved[170] == 65,
                  "incorrect value for reserved[170], expected 65, is %d",
                  check_msg->reserved[170]);
    ck_assert_msg(check_msg->reserved[171] == 185,
                  "incorrect value for reserved[171], expected 185, is %d",
                  check_msg->reserved[171]);
    ck_assert_msg(check_msg->reserved[172] == 110,
                  "incorrect value for reserved[172], expected 110, is %d",
                  check_msg->reserved[172]);
    ck_assert_msg(check_msg->reserved[173] == 92,
                  "incorrect value for reserved[173], expected 92, is %d",
                  check_msg->reserved[173]);
    ck_assert_msg(check_msg->reserved[174] == 34,
                  "incorrect value for reserved[174], expected 34, is %d",
                  check_msg->reserved[174]);
    ck_assert_msg(check_msg->reserved[175] == 44,
                  "incorrect value for reserved[175], expected 44, is %d",
                  check_msg->reserved[175]);
    ck_assert_msg(check_msg->reserved[176] == 131,
                  "incorrect value for reserved[176], expected 131, is %d",
                  check_msg->reserved[176]);
    ck_assert_msg(check_msg->reserved[177] == 96,
                  "incorrect value for reserved[177], expected 96, is %d",
                  check_msg->reserved[177]);
    ck_assert_msg(check_msg->reserved[178] == 178,
                  "incorrect value for reserved[178], expected 178, is %d",
                  check_msg->reserved[178]);
    ck_assert_msg(check_msg->reserved[179] == 40,
                  "incorrect value for reserved[179], expected 40, is %d",
                  check_msg->reserved[179]);
    ck_assert_msg(check_msg->reserved[180] == 176,
                  "incorrect value for reserved[180], expected 176, is %d",
                  check_msg->reserved[180]);
    ck_assert_msg(check_msg->reserved[181] == 4,
                  "incorrect value for reserved[181], expected 4, is %d",
                  check_msg->reserved[181]);
    ck_assert_msg(check_msg->reserved[182] == 90,
                  "incorrect value for reserved[182], expected 90, is %d",
                  check_msg->reserved[182]);
    ck_assert_msg(check_msg->reserved[183] == 36,
                  "incorrect value for reserved[183], expected 36, is %d",
                  check_msg->reserved[183]);
    ck_assert_msg(check_msg->reserved[184] == 7,
                  "incorrect value for reserved[184], expected 7, is %d",
                  check_msg->reserved[184]);
    ck_assert_msg(check_msg->reserved[185] == 180,
                  "incorrect value for reserved[185], expected 180, is %d",
                  check_msg->reserved[185]);
    ck_assert_msg(check_msg->reserved[186] == 244,
                  "incorrect value for reserved[186], expected 244, is %d",
                  check_msg->reserved[186]);
    ck_assert_msg(check_msg->reserved[187] == 244,
                  "incorrect value for reserved[187], expected 244, is %d",
                  check_msg->reserved[187]);
    ck_assert_msg(check_msg->reserved[188] == 23,
                  "incorrect value for reserved[188], expected 23, is %d",
                  check_msg->reserved[188]);
    ck_assert_msg(check_msg->reserved[189] == 108,
                  "incorrect value for reserved[189], expected 108, is %d",
                  check_msg->reserved[189]);
    ck_assert_msg(check_msg->reserved[190] == 171,
                  "incorrect value for reserved[190], expected 171, is %d",
                  check_msg->reserved[190]);
    ck_assert_msg(check_msg->reserved[191] == 204,
                  "incorrect value for reserved[191], expected 204, is %d",
                  check_msg->reserved[191]);
    ck_assert_msg(check_msg->reserved[192] == 196,
                  "incorrect value for reserved[192], expected 196, is %d",
                  check_msg->reserved[192]);
    ck_assert_msg(check_msg->reserved[193] == 61,
                  "incorrect value for reserved[193], expected 61, is %d",
                  check_msg->reserved[193]);
    ck_assert_msg(check_msg->reserved[194] == 51,
                  "incorrect value for reserved[194], expected 51, is %d",
                  check_msg->reserved[194]);
    ck_assert_msg(check_msg->reserved[195] == 179,
                  "incorrect value for reserved[195], expected 179, is %d",
                  check_msg->reserved[195]);
    ck_assert_msg(check_msg->reserved[196] == 242,
                  "incorrect value for reserved[196], expected 242, is %d",
                  check_msg->reserved[196]);
    ck_assert_msg(check_msg->reserved[197] == 156,
                  "incorrect value for reserved[197], expected 156, is %d",
                  check_msg->reserved[197]);
    ck_assert_msg(check_msg->reserved[198] == 81,
                  "incorrect value for reserved[198], expected 81, is %d",
                  check_msg->reserved[198]);
    ck_assert_msg(check_msg->reserved[199] == 83,
                  "incorrect value for reserved[199], expected 83, is %d",
                  check_msg->reserved[199]);
    ck_assert_msg(check_msg->reserved[200] == 16,
                  "incorrect value for reserved[200], expected 16, is %d",
                  check_msg->reserved[200]);
    ck_assert_msg(check_msg->reserved[201] == 15,
                  "incorrect value for reserved[201], expected 15, is %d",
                  check_msg->reserved[201]);
    ck_assert_msg(check_msg->reserved[202] == 134,
                  "incorrect value for reserved[202], expected 134, is %d",
                  check_msg->reserved[202]);
    ck_assert_msg(check_msg->reserved[203] == 40,
                  "incorrect value for reserved[203], expected 40, is %d",
                  check_msg->reserved[203]);
    ck_assert_msg(check_msg->reserved[204] == 245,
                  "incorrect value for reserved[204], expected 245, is %d",
                  check_msg->reserved[204]);
    ck_assert_msg(check_msg->reserved[205] == 253,
                  "incorrect value for reserved[205], expected 253, is %d",
                  check_msg->reserved[205]);
    ck_assert_msg(check_msg->reserved[206] == 150,
                  "incorrect value for reserved[206], expected 150, is %d",
                  check_msg->reserved[206]);
    ck_assert_msg(check_msg->reserved[207] == 94,
                  "incorrect value for reserved[207], expected 94, is %d",
                  check_msg->reserved[207]);
    ck_assert_msg(check_msg->reserved[208] == 150,
                  "incorrect value for reserved[208], expected 150, is %d",
                  check_msg->reserved[208]);
    ck_assert_msg(check_msg->reserved[209] == 144,
                  "incorrect value for reserved[209], expected 144, is %d",
                  check_msg->reserved[209]);
    ck_assert_msg(check_msg->reserved[210] == 197,
                  "incorrect value for reserved[210], expected 197, is %d",
                  check_msg->reserved[210]);
    ck_assert_msg(check_msg->reserved[211] == 113,
                  "incorrect value for reserved[211], expected 113, is %d",
                  check_msg->reserved[211]);
    ck_assert_msg(check_msg->reserved[212] == 5,
                  "incorrect value for reserved[212], expected 5, is %d",
                  check_msg->reserved[212]);
    ck_assert_msg(check_msg->reserved[213] == 141,
                  "incorrect value for reserved[213], expected 141, is %d",
                  check_msg->reserved[213]);
    ck_assert_msg(check_msg->reserved[214] == 232,
                  "incorrect value for reserved[214], expected 232, is %d",
                  check_msg->reserved[214]);
    ck_assert_msg(check_msg->reserved[215] == 33,
                  "incorrect value for reserved[215], expected 33, is %d",
                  check_msg->reserved[215]);
    ck_assert_msg(check_msg->reserved[216] == 101,
                  "incorrect value for reserved[216], expected 101, is %d",
                  check_msg->reserved[216]);
    ck_assert_msg(check_msg->reserved[217] == 231,
                  "incorrect value for reserved[217], expected 231, is %d",
                  check_msg->reserved[217]);
    ck_assert_msg(check_msg->reserved[218] == 38,
                  "incorrect value for reserved[218], expected 38, is %d",
                  check_msg->reserved[218]);
    ck_assert_msg(check_msg->reserved[219] == 75,
                  "incorrect value for reserved[219], expected 75, is %d",
                  check_msg->reserved[219]);
    ck_assert_msg(check_msg->reserved[220] == 178,
                  "incorrect value for reserved[220], expected 178, is %d",
                  check_msg->reserved[220]);
    ck_assert_msg(check_msg->reserved[221] == 243,
                  "incorrect value for reserved[221], expected 243, is %d",
                  check_msg->reserved[221]);
    ck_assert_msg(check_msg->reserved[222] == 119,
                  "incorrect value for reserved[222], expected 119, is %d",
                  check_msg->reserved[222]);
    ck_assert_msg(check_msg->reserved[223] == 1,
                  "incorrect value for reserved[223], expected 1, is %d",
                  check_msg->reserved[223]);
    ck_assert_msg(check_msg->reserved[224] == 248,
                  "incorrect value for reserved[224], expected 248, is %d",
                  check_msg->reserved[224]);
    ck_assert_msg(check_msg->reserved[225] == 218,
                  "incorrect value for reserved[225], expected 218, is %d",
                  check_msg->reserved[225]);
    ck_assert_msg(check_msg->reserved[226] == 86,
                  "incorrect value for reserved[226], expected 86, is %d",
                  check_msg->reserved[226]);
    ck_assert_msg(check_msg->reserved[227] == 7,
                  "incorrect value for reserved[227], expected 7, is %d",
                  check_msg->reserved[227]);
    ck_assert_msg(check_msg->reserved[228] == 88,
                  "incorrect value for reserved[228], expected 88, is %d",
                  check_msg->reserved[228]);
    ck_assert_msg(check_msg->reserved[229] == 197,
                  "incorrect value for reserved[229], expected 197, is %d",
                  check_msg->reserved[229]);
    ck_assert_msg(check_msg->reserved[230] == 148,
                  "incorrect value for reserved[230], expected 148, is %d",
                  check_msg->reserved[230]);
    ck_assert_msg(check_msg->reserved[231] == 240,
                  "incorrect value for reserved[231], expected 240, is %d",
                  check_msg->reserved[231]);
    ck_assert_msg(check_msg->reserved[232] == 227,
                  "incorrect value for reserved[232], expected 227, is %d",
                  check_msg->reserved[232]);
    ck_assert_msg(check_msg->reserved[233] == 2,
                  "incorrect value for reserved[233], expected 2, is %d",
                  check_msg->reserved[233]);
    ck_assert_msg(check_msg->reserved[234] == 65,
                  "incorrect value for reserved[234], expected 65, is %d",
                  check_msg->reserved[234]);
    ck_assert_msg(check_msg->reserved[235] == 173,
                  "incorrect value for reserved[235], expected 173, is %d",
                  check_msg->reserved[235]);
    ck_assert_msg(check_msg->reserved[236] == 122,
                  "incorrect value for reserved[236], expected 122, is %d",
                  check_msg->reserved[236]);
    ck_assert_msg(check_msg->reserved[237] == 143,
                  "incorrect value for reserved[237], expected 143, is %d",
                  check_msg->reserved[237]);
    ck_assert_msg(check_msg->reserved[238] == 251,
                  "incorrect value for reserved[238], expected 251, is %d",
                  check_msg->reserved[238]);
    ck_assert_msg(check_msg->reserved[239] == 156,
                  "incorrect value for reserved[239], expected 156, is %d",
                  check_msg->reserved[239]);
    ck_assert_msg(check_msg->reserved[240] == 217,
                  "incorrect value for reserved[240], expected 217, is %d",
                  check_msg->reserved[240]);
    ck_assert_msg(check_msg->reserved[241] == 67,
                  "incorrect value for reserved[241], expected 67, is %d",
                  check_msg->reserved[241]);
    ck_assert_msg(check_msg->reserved[242] == 239,
                  "incorrect value for reserved[242], expected 239, is %d",
                  check_msg->reserved[242]);
    ck_assert_msg(check_msg->reserved[243] == 219,
                  "incorrect value for reserved[243], expected 219, is %d",
                  check_msg->reserved[243]);
    ck_assert_msg(check_msg->reserved[244] == 31,
                  "incorrect value for reserved[244], expected 31, is %d",
                  check_msg->reserved[244]);
    ck_assert_msg(check_msg->reserved[245] == 224,
                  "incorrect value for reserved[245], expected 224, is %d",
                  check_msg->reserved[245]);
    ck_assert_msg(check_msg->reserved[246] == 176,
                  "incorrect value for reserved[246], expected 176, is %d",
                  check_msg->reserved[246]);
    ck_assert_msg(check_msg->reserved[247] == 129,
                  "incorrect value for reserved[247], expected 129, is %d",
                  check_msg->reserved[247]);
    ck_assert_msg(check_msg->reserved[248] == 81,
                  "incorrect value for reserved[248], expected 81, is %d",
                  check_msg->reserved[248]);
    ck_assert_msg(check_msg->reserved[249] == 80,
                  "incorrect value for reserved[249], expected 80, is %d",
                  check_msg->reserved[249]);
    ck_assert_msg(
        (check_msg->signal_error_rate * 100 - 8588.20019531 * 100) < 0.05,
        "incorrect value for signal_error_rate, expected 8588.20019531, is %f",
        check_msg->signal_error_rate);
    ck_assert_msg(check_msg->signal_strength == 103,
                  "incorrect value for signal_strength, expected 103, is %d",
                  check_msg->signal_strength);
  }
}
END_TEST

Suite *legacy_auto_check_sbp_piksi_MsgCellModemStatus_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: "
      "legacy_auto_check_sbp_piksi_MsgCellModemStatus");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_legacy_auto_check_sbp_piksi_MsgCellModemStatus");
  tcase_add_test(tc_acq, test_legacy_auto_check_sbp_piksi_MsgCellModemStatus);
  suite_add_tcase(s, tc_acq);
  return s;
}