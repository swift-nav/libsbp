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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrGriddedCorrectionNoStdDepA.yaml
// by generate.py. Do not modify by hand!

#include <check.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/ssr.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  sbp_msg_type_t msg_type;
  sbp_msg_t msg;
  void *context;
} last_msg;

static u32 dummy_wr = 0;
static u32 dummy_rd = 0;
static u8 dummy_buff[1024];
static void *last_io_context;

static void *DUMMY_MEMORY_FOR_CALLBACKS = (void *)0xdeadbeef;
static void *DUMMY_MEMORY_FOR_IO = (void *)0xdead0000;

static void dummy_reset() {
  dummy_rd = dummy_wr = 0;
  memset(dummy_buff, 0, sizeof(dummy_buff));
}

static s32 dummy_write(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(dummy_buff + dummy_wr, buff, real_n);
  dummy_wr += real_n;
  return (s32)real_n;
}

static s32 dummy_read(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(buff, dummy_buff + dummy_rd, real_n);
  dummy_rd += real_n;
  return (s32)real_n;
}

static void logging_reset() { memset(&last_msg, 0, sizeof(last_msg)); }

static void msg_callback(u16 sender_id, sbp_msg_type_t msg_type,
                         const sbp_msg_t *msg, void *context) {
  last_msg.n_callbacks_logged++;
  last_msg.sender_id = sender_id;
  last_msg.msg_type = msg_type;
  last_msg.msg = *msg;
  last_msg.context = context;
}

START_TEST(test_auto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA) {
  static sbp_msg_callbacks_node_t n;

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

    sbp_callback_register(&sbp_state, 0x5f0, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  240, 5,   102, 28,  254, 179, 240, 33,  169, 236, 34,  117, 245,
        67,  248, 233, 236, 230, 230, 103, 122, 63,  101, 231, 157, 115, 162,
        197, 146, 35,  107, 222, 109, 52,  41,  86,  12,  237, 184, 65,  204,
        137, 148, 171, 183, 11,  0,   180, 203, 172, 53,  196, 85,  186, 115,
        203, 92,  166, 30,  42,  13,  200, 71,  98,  137, 219, 160, 95,  216,
        95,  250, 99,  196, 92,  214, 159, 253, 195, 222, 233, 146, 233, 63,
        76,  24,  106, 40,  253, 65,  9,   183, 40,  215, 188, 59,  117, 69,
        97,  115, 60,  56,  0,   141, 207, 171, 54,  161, 23,  61,  0,   87,
        230, 123, 87,  36,  184, 255, 14,  163, 187, 224, 43,  151, 151, 104,
        39,  57,  5,   54,  48,  224, 181, 129, 60,  92,  171, 114, 109, 109,
        12,  23,  118, 8,   64,  159, 54,  216, 33,  20,  24,  68,  160, 36,
        38,  222, 145, 190, 92,  99,  108, 159, 232, 240, 227, 221, 253, 15,
        62,  23,  121, 185, 168, 116, 4,   147, 123, 72,  223, 119, 226, 242,
        161, 204, 180, 202, 137, 166, 58,  24,  124, 19,  181, 188, 16,  107,
        66,  231, 63,  1,   64,  252, 115, 62,  233, 97,  250, 86,  156, 221,
        49,  178, 32,  73,  198, 67,  249, 253, 74,  56,  38,  165, 119, 92,
        99,  44,  95,  131, 89,  192, 225, 55,  95,  171, 88,  205, 21,  116,
        231, 83,  71,  71,  100, 110, 217, 254, 152, 212, 18,  8,   40,  157,
        244, 54,  72,  240, 231, 189, 111, 195, 205, 81,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ssr_gridded_correction_no_std_dep_a.header.iod_atmo = 236;

    test_msg.ssr_gridded_correction_no_std_dep_a.header.num_msgs = 62837;

    test_msg.ssr_gridded_correction_no_std_dep_a.header.seq_num = 63555;

    test_msg.ssr_gridded_correction_no_std_dep_a.header.time.tow = 2837573811;

    test_msg.ssr_gridded_correction_no_std_dep_a.header.time.wn = 8940;

    test_msg.ssr_gridded_correction_no_std_dep_a.header
        .tropo_quality_indicator = 230;

    test_msg.ssr_gridded_correction_no_std_dep_a.header.update_interval = 233;

    test_msg.ssr_gridded_correction_no_std_dep_a.index = 26598;

    test_msg.ssr_gridded_correction_no_std_dep_a.n_stec_residuals = 59;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[0].residual =
        -23949;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[0]
        .sv_id.constellation = 157;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[0].sv_id.satId =
        231;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[1].residual =
        27427;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[1]
        .sv_id.constellation = 146;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[1].sv_id.satId =
        197;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[2].residual =
        10548;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[2]
        .sv_id.constellation = 109;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[2].sv_id.satId =
        222;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[3].residual =
        -18195;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[3]
        .sv_id.constellation = 12;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[3].sv_id.satId =
        86;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[4].residual =
        -27511;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[4]
        .sv_id.constellation = 204;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[4].sv_id.satId =
        65;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[5].residual =
        11;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[5]
        .sv_id.constellation = 183;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[5].sv_id.satId =
        171;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[6].residual =
        13740;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[6]
        .sv_id.constellation = 203;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[6].sv_id.satId =
        180;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[7].residual =
        29626;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[7]
        .sv_id.constellation = 85;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[7].sv_id.satId =
        196;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[8].residual =
        7846;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[8]
        .sv_id.constellation = 92;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[8].sv_id.satId =
        203;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[9].residual =
        18376;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[9]
        .sv_id.constellation = 13;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[9].sv_id.satId =
        42;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[10].residual =
        -24357;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[10]
        .sv_id.constellation = 137;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[10]
        .sv_id.satId = 98;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[11].residual =
        -1441;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[11]
        .sv_id.constellation = 216;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[11]
        .sv_id.satId = 95;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[12].residual =
        -10660;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[12]
        .sv_id.constellation = 196;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[12]
        .sv_id.satId = 99;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[13].residual =
        -8509;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[13]
        .sv_id.constellation = 253;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[13]
        .sv_id.satId = 159;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[14].residual =
        16361;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[14]
        .sv_id.constellation = 146;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[14]
        .sv_id.satId = 233;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[15].residual =
        10346;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[15]
        .sv_id.constellation = 24;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[15]
        .sv_id.satId = 76;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[16].residual =
        -18679;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[16]
        .sv_id.constellation = 65;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[16]
        .sv_id.satId = 253;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[17].residual =
        15292;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[17]
        .sv_id.constellation = 215;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[17]
        .sv_id.satId = 40;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[18].residual =
        29537;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[18]
        .sv_id.constellation = 69;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[18]
        .sv_id.satId = 117;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[19].residual =
        -29440;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[19]
        .sv_id.constellation = 56;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[19]
        .sv_id.satId = 60;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[20].residual =
        -24266;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[20]
        .sv_id.constellation = 171;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[20]
        .sv_id.satId = 207;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[21].residual =
        22272;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[21]
        .sv_id.constellation = 61;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[21]
        .sv_id.satId = 23;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[22].residual =
        9303;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[22]
        .sv_id.constellation = 123;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[22]
        .sv_id.satId = 230;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[23].residual =
        -23794;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[23]
        .sv_id.constellation = 255;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[23]
        .sv_id.satId = 184;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[24].residual =
        -26837;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[24]
        .sv_id.constellation = 224;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[24]
        .sv_id.satId = 187;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[25].residual =
        14631;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[25]
        .sv_id.constellation = 104;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[25]
        .sv_id.satId = 151;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[26].residual =
        -8144;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[26]
        .sv_id.constellation = 54;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[26]
        .sv_id.satId = 5;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[27].residual =
        23612;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[27]
        .sv_id.constellation = 129;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[27]
        .sv_id.satId = 181;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[28].residual =
        28013;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[28]
        .sv_id.constellation = 114;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[28]
        .sv_id.satId = 171;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[29].residual =
        2166;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[29]
        .sv_id.constellation = 23;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[29]
        .sv_id.satId = 12;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[30].residual =
        -10186;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[30]
        .sv_id.constellation = 159;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[30]
        .sv_id.satId = 64;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[31].residual =
        17432;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[31]
        .sv_id.constellation = 20;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[31]
        .sv_id.satId = 33;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[32].residual =
        -8666;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[32]
        .sv_id.constellation = 36;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[32]
        .sv_id.satId = 160;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[33].residual =
        25436;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[33]
        .sv_id.constellation = 190;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[33]
        .sv_id.satId = 145;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[34].residual =
        -3864;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[34]
        .sv_id.constellation = 159;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[34]
        .sv_id.satId = 108;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[35].residual =
        4093;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[35]
        .sv_id.constellation = 221;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[35]
        .sv_id.satId = 227;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[36].residual =
        -18055;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[36]
        .sv_id.constellation = 23;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[36]
        .sv_id.satId = 62;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[37].residual =
        -27900;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[37]
        .sv_id.constellation = 116;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[37]
        .sv_id.satId = 168;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[38].residual =
        30687;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[38]
        .sv_id.constellation = 72;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[38]
        .sv_id.satId = 123;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[39].residual =
        -13151;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[39]
        .sv_id.constellation = 242;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[39]
        .sv_id.satId = 226;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[40].residual =
        -22903;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[40]
        .sv_id.constellation = 202;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[40]
        .sv_id.satId = 180;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[41].residual =
        4988;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[41]
        .sv_id.constellation = 24;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[41]
        .sv_id.satId = 58;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[42].residual =
        27408;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[42]
        .sv_id.constellation = 188;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[42]
        .sv_id.satId = 181;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[43].residual =
        319;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[43]
        .sv_id.constellation = 231;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[43]
        .sv_id.satId = 66;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[44].residual =
        15987;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[44]
        .sv_id.constellation = 252;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[44]
        .sv_id.satId = 64;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[45].residual =
        22266;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[45]
        .sv_id.constellation = 97;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[45]
        .sv_id.satId = 233;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[46].residual =
        -19919;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[46]
        .sv_id.constellation = 221;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[46]
        .sv_id.satId = 156;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[47].residual =
        17350;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[47]
        .sv_id.constellation = 73;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[47]
        .sv_id.satId = 32;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[48].residual =
        14410;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[48]
        .sv_id.constellation = 253;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[48]
        .sv_id.satId = 249;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[49].residual =
        23671;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[49]
        .sv_id.constellation = 165;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[49]
        .sv_id.satId = 38;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[50].residual =
        -31905;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[50]
        .sv_id.constellation = 44;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[50]
        .sv_id.satId = 99;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[51].residual =
        14305;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[51]
        .sv_id.constellation = 192;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[51]
        .sv_id.satId = 89;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[52].residual =
        -12968;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[52]
        .sv_id.constellation = 171;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[52]
        .sv_id.satId = 95;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[53].residual =
        21479;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[53]
        .sv_id.constellation = 116;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[53]
        .sv_id.satId = 21;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[54].residual =
        28260;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[54]
        .sv_id.constellation = 71;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[54]
        .sv_id.satId = 71;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[55].residual =
        -11112;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[55]
        .sv_id.constellation = 254;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[55]
        .sv_id.satId = 217;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[56].residual =
        -25304;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[56]
        .sv_id.constellation = 8;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[56]
        .sv_id.satId = 18;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[57].residual =
        -4024;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[57]
        .sv_id.constellation = 54;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[57]
        .sv_id.satId = 244;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[58].residual =
        -15505;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[58]
        .sv_id.constellation = 189;

    test_msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[58]
        .sv_id.satId = 231;

    test_msg.ssr_gridded_correction_no_std_dep_a.tropo_delay_correction.hydro =
        16250;

    test_msg.ssr_gridded_correction_no_std_dep_a.tropo_delay_correction.wet =
        101;

    sbp_message_send(&sbp_state, SbpMsgSsrGriddedCorrectionNoStdDepA, 7270,
                     &test_msg, &dummy_write);

    ck_assert_msg(dummy_wr == sizeof(encoded_frame),
                  "not enough data was written to dummy_buff (expected: %zu, "
                  "actual: %zu)",
                  sizeof(encoded_frame), dummy_wr);
    ck_assert_msg(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)) == 0,
                  "frame was not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_msg.n_callbacks_logged == 1,
                  "msg_callback: one callback should have been logged");
    ck_assert_msg(last_msg.sender_id == 7270,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(sbp_message_cmp(SbpMsgSsrGriddedCorrectionNoStdDepA,
                                  &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.header.iod_atmo == 236,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.header.iod_atmo, "
        "expected 236, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.header.iod_atmo);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.header.num_msgs ==
            62837,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.header.num_msgs, "
        "expected 62837, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.header.num_msgs);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.header.seq_num ==
            63555,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.header.seq_num, "
        "expected 63555, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.header.seq_num);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.header.time.tow ==
            2837573811,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.header.time.tow, "
        "expected 2837573811, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.header.time.tow);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.header.time.wn == 8940,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.header.time.wn, "
        "expected 8940, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.header.time.wn);

    ck_assert_msg(last_msg.msg.ssr_gridded_correction_no_std_dep_a.header
                          .tropo_quality_indicator == 230,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_no_std_dep_a.header."
                  "tropo_quality_indicator, expected 230, is %d",
                  last_msg.msg.ssr_gridded_correction_no_std_dep_a.header
                      .tropo_quality_indicator);

    ck_assert_msg(last_msg.msg.ssr_gridded_correction_no_std_dep_a.header
                          .update_interval == 233,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_no_std_dep_a.header."
                  "update_interval, expected 233, is %d",
                  last_msg.msg.ssr_gridded_correction_no_std_dep_a.header
                      .update_interval);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.index == 26598,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.index, expected "
        "26598, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.index);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.n_stec_residuals == 59,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.n_stec_residuals, "
        "expected 59, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.n_stec_residuals);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[0]
                .residual == -23949,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[0]."
        "residual, expected -23949, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[0]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[0]
                .sv_id.constellation == 157,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[0].sv_"
        "id.constellation, expected 157, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[0]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[0]
                .sv_id.satId == 231,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[0].sv_"
        "id.satId, expected 231, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[0]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[1]
                .residual == 27427,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[1]."
        "residual, expected 27427, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[1]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[1]
                .sv_id.constellation == 146,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[1].sv_"
        "id.constellation, expected 146, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[1]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[1]
                .sv_id.satId == 197,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[1].sv_"
        "id.satId, expected 197, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[1]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[2]
                .residual == 10548,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[2]."
        "residual, expected 10548, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[2]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[2]
                .sv_id.constellation == 109,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[2].sv_"
        "id.constellation, expected 109, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[2]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[2]
                .sv_id.satId == 222,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[2].sv_"
        "id.satId, expected 222, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[2]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[3]
                .residual == -18195,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[3]."
        "residual, expected -18195, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[3]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[3]
                .sv_id.constellation == 12,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[3].sv_"
        "id.constellation, expected 12, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[3]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[3]
                .sv_id.satId == 86,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[3].sv_"
        "id.satId, expected 86, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[3]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[4]
                .residual == -27511,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[4]."
        "residual, expected -27511, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[4]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[4]
                .sv_id.constellation == 204,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[4].sv_"
        "id.constellation, expected 204, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[4]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[4]
                .sv_id.satId == 65,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[4].sv_"
        "id.satId, expected 65, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[4]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[5]
                .residual == 11,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[5]."
        "residual, expected 11, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[5]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[5]
                .sv_id.constellation == 183,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[5].sv_"
        "id.constellation, expected 183, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[5]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[5]
                .sv_id.satId == 171,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[5].sv_"
        "id.satId, expected 171, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[5]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[6]
                .residual == 13740,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[6]."
        "residual, expected 13740, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[6]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[6]
                .sv_id.constellation == 203,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[6].sv_"
        "id.constellation, expected 203, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[6]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[6]
                .sv_id.satId == 180,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[6].sv_"
        "id.satId, expected 180, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[6]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[7]
                .residual == 29626,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[7]."
        "residual, expected 29626, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[7]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[7]
                .sv_id.constellation == 85,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[7].sv_"
        "id.constellation, expected 85, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[7]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[7]
                .sv_id.satId == 196,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[7].sv_"
        "id.satId, expected 196, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[7]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[8]
                .residual == 7846,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[8]."
        "residual, expected 7846, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[8]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[8]
                .sv_id.constellation == 92,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[8].sv_"
        "id.constellation, expected 92, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[8]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[8]
                .sv_id.satId == 203,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[8].sv_"
        "id.satId, expected 203, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[8]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[9]
                .residual == 18376,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[9]."
        "residual, expected 18376, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[9]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[9]
                .sv_id.constellation == 13,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[9].sv_"
        "id.constellation, expected 13, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[9]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[9]
                .sv_id.satId == 42,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[9].sv_"
        "id.satId, expected 42, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[9]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[10]
                .residual == -24357,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[10]."
        "residual, expected -24357, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[10]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[10]
                .sv_id.constellation == 137,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[10]."
        "sv_id.constellation, expected 137, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[10]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[10]
                .sv_id.satId == 98,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[10]."
        "sv_id.satId, expected 98, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[10]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[11]
                .residual == -1441,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[11]."
        "residual, expected -1441, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[11]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[11]
                .sv_id.constellation == 216,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[11]."
        "sv_id.constellation, expected 216, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[11]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[11]
                .sv_id.satId == 95,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[11]."
        "sv_id.satId, expected 95, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[11]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[12]
                .residual == -10660,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[12]."
        "residual, expected -10660, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[12]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[12]
                .sv_id.constellation == 196,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[12]."
        "sv_id.constellation, expected 196, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[12]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[12]
                .sv_id.satId == 99,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[12]."
        "sv_id.satId, expected 99, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[12]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[13]
                .residual == -8509,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[13]."
        "residual, expected -8509, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[13]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[13]
                .sv_id.constellation == 253,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[13]."
        "sv_id.constellation, expected 253, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[13]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[13]
                .sv_id.satId == 159,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[13]."
        "sv_id.satId, expected 159, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[13]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[14]
                .residual == 16361,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[14]."
        "residual, expected 16361, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[14]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[14]
                .sv_id.constellation == 146,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[14]."
        "sv_id.constellation, expected 146, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[14]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[14]
                .sv_id.satId == 233,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[14]."
        "sv_id.satId, expected 233, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[14]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[15]
                .residual == 10346,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[15]."
        "residual, expected 10346, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[15]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[15]
                .sv_id.constellation == 24,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[15]."
        "sv_id.constellation, expected 24, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[15]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[15]
                .sv_id.satId == 76,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[15]."
        "sv_id.satId, expected 76, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[15]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[16]
                .residual == -18679,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[16]."
        "residual, expected -18679, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[16]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[16]
                .sv_id.constellation == 65,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[16]."
        "sv_id.constellation, expected 65, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[16]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[16]
                .sv_id.satId == 253,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[16]."
        "sv_id.satId, expected 253, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[16]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[17]
                .residual == 15292,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[17]."
        "residual, expected 15292, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[17]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[17]
                .sv_id.constellation == 215,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[17]."
        "sv_id.constellation, expected 215, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[17]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[17]
                .sv_id.satId == 40,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[17]."
        "sv_id.satId, expected 40, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[17]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[18]
                .residual == 29537,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[18]."
        "residual, expected 29537, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[18]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[18]
                .sv_id.constellation == 69,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[18]."
        "sv_id.constellation, expected 69, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[18]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[18]
                .sv_id.satId == 117,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[18]."
        "sv_id.satId, expected 117, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[18]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[19]
                .residual == -29440,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[19]."
        "residual, expected -29440, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[19]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[19]
                .sv_id.constellation == 56,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[19]."
        "sv_id.constellation, expected 56, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[19]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[19]
                .sv_id.satId == 60,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[19]."
        "sv_id.satId, expected 60, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[19]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[20]
                .residual == -24266,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[20]."
        "residual, expected -24266, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[20]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[20]
                .sv_id.constellation == 171,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[20]."
        "sv_id.constellation, expected 171, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[20]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[20]
                .sv_id.satId == 207,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[20]."
        "sv_id.satId, expected 207, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[20]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[21]
                .residual == 22272,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[21]."
        "residual, expected 22272, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[21]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[21]
                .sv_id.constellation == 61,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[21]."
        "sv_id.constellation, expected 61, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[21]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[21]
                .sv_id.satId == 23,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[21]."
        "sv_id.satId, expected 23, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[21]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[22]
                .residual == 9303,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[22]."
        "residual, expected 9303, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[22]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[22]
                .sv_id.constellation == 123,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[22]."
        "sv_id.constellation, expected 123, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[22]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[22]
                .sv_id.satId == 230,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[22]."
        "sv_id.satId, expected 230, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[22]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[23]
                .residual == -23794,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[23]."
        "residual, expected -23794, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[23]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[23]
                .sv_id.constellation == 255,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[23]."
        "sv_id.constellation, expected 255, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[23]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[23]
                .sv_id.satId == 184,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[23]."
        "sv_id.satId, expected 184, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[23]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[24]
                .residual == -26837,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[24]."
        "residual, expected -26837, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[24]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[24]
                .sv_id.constellation == 224,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[24]."
        "sv_id.constellation, expected 224, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[24]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[24]
                .sv_id.satId == 187,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[24]."
        "sv_id.satId, expected 187, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[24]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[25]
                .residual == 14631,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[25]."
        "residual, expected 14631, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[25]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[25]
                .sv_id.constellation == 104,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[25]."
        "sv_id.constellation, expected 104, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[25]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[25]
                .sv_id.satId == 151,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[25]."
        "sv_id.satId, expected 151, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[25]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[26]
                .residual == -8144,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[26]."
        "residual, expected -8144, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[26]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[26]
                .sv_id.constellation == 54,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[26]."
        "sv_id.constellation, expected 54, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[26]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[26]
                .sv_id.satId == 5,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[26]."
        "sv_id.satId, expected 5, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[26]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[27]
                .residual == 23612,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[27]."
        "residual, expected 23612, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[27]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[27]
                .sv_id.constellation == 129,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[27]."
        "sv_id.constellation, expected 129, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[27]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[27]
                .sv_id.satId == 181,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[27]."
        "sv_id.satId, expected 181, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[27]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[28]
                .residual == 28013,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[28]."
        "residual, expected 28013, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[28]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[28]
                .sv_id.constellation == 114,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[28]."
        "sv_id.constellation, expected 114, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[28]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[28]
                .sv_id.satId == 171,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[28]."
        "sv_id.satId, expected 171, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[28]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[29]
                .residual == 2166,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[29]."
        "residual, expected 2166, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[29]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[29]
                .sv_id.constellation == 23,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[29]."
        "sv_id.constellation, expected 23, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[29]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[29]
                .sv_id.satId == 12,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[29]."
        "sv_id.satId, expected 12, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[29]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[30]
                .residual == -10186,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[30]."
        "residual, expected -10186, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[30]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[30]
                .sv_id.constellation == 159,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[30]."
        "sv_id.constellation, expected 159, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[30]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[30]
                .sv_id.satId == 64,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[30]."
        "sv_id.satId, expected 64, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[30]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[31]
                .residual == 17432,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[31]."
        "residual, expected 17432, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[31]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[31]
                .sv_id.constellation == 20,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[31]."
        "sv_id.constellation, expected 20, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[31]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[31]
                .sv_id.satId == 33,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[31]."
        "sv_id.satId, expected 33, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[31]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[32]
                .residual == -8666,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[32]."
        "residual, expected -8666, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[32]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[32]
                .sv_id.constellation == 36,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[32]."
        "sv_id.constellation, expected 36, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[32]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[32]
                .sv_id.satId == 160,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[32]."
        "sv_id.satId, expected 160, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[32]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[33]
                .residual == 25436,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[33]."
        "residual, expected 25436, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[33]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[33]
                .sv_id.constellation == 190,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[33]."
        "sv_id.constellation, expected 190, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[33]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[33]
                .sv_id.satId == 145,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[33]."
        "sv_id.satId, expected 145, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[33]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[34]
                .residual == -3864,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[34]."
        "residual, expected -3864, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[34]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[34]
                .sv_id.constellation == 159,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[34]."
        "sv_id.constellation, expected 159, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[34]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[34]
                .sv_id.satId == 108,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[34]."
        "sv_id.satId, expected 108, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[34]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[35]
                .residual == 4093,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[35]."
        "residual, expected 4093, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[35]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[35]
                .sv_id.constellation == 221,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[35]."
        "sv_id.constellation, expected 221, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[35]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[35]
                .sv_id.satId == 227,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[35]."
        "sv_id.satId, expected 227, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[35]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[36]
                .residual == -18055,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[36]."
        "residual, expected -18055, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[36]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[36]
                .sv_id.constellation == 23,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[36]."
        "sv_id.constellation, expected 23, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[36]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[36]
                .sv_id.satId == 62,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[36]."
        "sv_id.satId, expected 62, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[36]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[37]
                .residual == -27900,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[37]."
        "residual, expected -27900, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[37]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[37]
                .sv_id.constellation == 116,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[37]."
        "sv_id.constellation, expected 116, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[37]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[37]
                .sv_id.satId == 168,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[37]."
        "sv_id.satId, expected 168, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[37]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[38]
                .residual == 30687,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[38]."
        "residual, expected 30687, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[38]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[38]
                .sv_id.constellation == 72,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[38]."
        "sv_id.constellation, expected 72, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[38]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[38]
                .sv_id.satId == 123,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[38]."
        "sv_id.satId, expected 123, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[38]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[39]
                .residual == -13151,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[39]."
        "residual, expected -13151, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[39]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[39]
                .sv_id.constellation == 242,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[39]."
        "sv_id.constellation, expected 242, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[39]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[39]
                .sv_id.satId == 226,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[39]."
        "sv_id.satId, expected 226, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[39]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[40]
                .residual == -22903,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[40]."
        "residual, expected -22903, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[40]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[40]
                .sv_id.constellation == 202,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[40]."
        "sv_id.constellation, expected 202, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[40]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[40]
                .sv_id.satId == 180,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[40]."
        "sv_id.satId, expected 180, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[40]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[41]
                .residual == 4988,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[41]."
        "residual, expected 4988, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[41]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[41]
                .sv_id.constellation == 24,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[41]."
        "sv_id.constellation, expected 24, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[41]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[41]
                .sv_id.satId == 58,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[41]."
        "sv_id.satId, expected 58, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[41]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[42]
                .residual == 27408,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[42]."
        "residual, expected 27408, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[42]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[42]
                .sv_id.constellation == 188,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[42]."
        "sv_id.constellation, expected 188, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[42]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[42]
                .sv_id.satId == 181,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[42]."
        "sv_id.satId, expected 181, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[42]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[43]
                .residual == 319,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[43]."
        "residual, expected 319, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[43]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[43]
                .sv_id.constellation == 231,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[43]."
        "sv_id.constellation, expected 231, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[43]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[43]
                .sv_id.satId == 66,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[43]."
        "sv_id.satId, expected 66, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[43]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[44]
                .residual == 15987,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[44]."
        "residual, expected 15987, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[44]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[44]
                .sv_id.constellation == 252,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[44]."
        "sv_id.constellation, expected 252, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[44]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[44]
                .sv_id.satId == 64,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[44]."
        "sv_id.satId, expected 64, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[44]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[45]
                .residual == 22266,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[45]."
        "residual, expected 22266, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[45]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[45]
                .sv_id.constellation == 97,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[45]."
        "sv_id.constellation, expected 97, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[45]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[45]
                .sv_id.satId == 233,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[45]."
        "sv_id.satId, expected 233, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[45]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[46]
                .residual == -19919,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[46]."
        "residual, expected -19919, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[46]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[46]
                .sv_id.constellation == 221,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[46]."
        "sv_id.constellation, expected 221, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[46]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[46]
                .sv_id.satId == 156,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[46]."
        "sv_id.satId, expected 156, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[46]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[47]
                .residual == 17350,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[47]."
        "residual, expected 17350, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[47]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[47]
                .sv_id.constellation == 73,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[47]."
        "sv_id.constellation, expected 73, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[47]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[47]
                .sv_id.satId == 32,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[47]."
        "sv_id.satId, expected 32, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[47]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[48]
                .residual == 14410,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[48]."
        "residual, expected 14410, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[48]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[48]
                .sv_id.constellation == 253,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[48]."
        "sv_id.constellation, expected 253, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[48]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[48]
                .sv_id.satId == 249,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[48]."
        "sv_id.satId, expected 249, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[48]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[49]
                .residual == 23671,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[49]."
        "residual, expected 23671, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[49]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[49]
                .sv_id.constellation == 165,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[49]."
        "sv_id.constellation, expected 165, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[49]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[49]
                .sv_id.satId == 38,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[49]."
        "sv_id.satId, expected 38, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[49]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[50]
                .residual == -31905,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[50]."
        "residual, expected -31905, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[50]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[50]
                .sv_id.constellation == 44,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[50]."
        "sv_id.constellation, expected 44, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[50]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[50]
                .sv_id.satId == 99,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[50]."
        "sv_id.satId, expected 99, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[50]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[51]
                .residual == 14305,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[51]."
        "residual, expected 14305, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[51]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[51]
                .sv_id.constellation == 192,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[51]."
        "sv_id.constellation, expected 192, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[51]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[51]
                .sv_id.satId == 89,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[51]."
        "sv_id.satId, expected 89, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[51]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[52]
                .residual == -12968,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[52]."
        "residual, expected -12968, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[52]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[52]
                .sv_id.constellation == 171,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[52]."
        "sv_id.constellation, expected 171, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[52]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[52]
                .sv_id.satId == 95,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[52]."
        "sv_id.satId, expected 95, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[52]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[53]
                .residual == 21479,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[53]."
        "residual, expected 21479, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[53]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[53]
                .sv_id.constellation == 116,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[53]."
        "sv_id.constellation, expected 116, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[53]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[53]
                .sv_id.satId == 21,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[53]."
        "sv_id.satId, expected 21, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[53]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[54]
                .residual == 28260,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[54]."
        "residual, expected 28260, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[54]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[54]
                .sv_id.constellation == 71,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[54]."
        "sv_id.constellation, expected 71, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[54]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[54]
                .sv_id.satId == 71,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[54]."
        "sv_id.satId, expected 71, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[54]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[55]
                .residual == -11112,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[55]."
        "residual, expected -11112, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[55]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[55]
                .sv_id.constellation == 254,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[55]."
        "sv_id.constellation, expected 254, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[55]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[55]
                .sv_id.satId == 217,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[55]."
        "sv_id.satId, expected 217, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[55]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[56]
                .residual == -25304,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[56]."
        "residual, expected -25304, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[56]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[56]
                .sv_id.constellation == 8,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[56]."
        "sv_id.constellation, expected 8, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[56]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[56]
                .sv_id.satId == 18,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[56]."
        "sv_id.satId, expected 18, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[56]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[57]
                .residual == -4024,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[57]."
        "residual, expected -4024, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[57]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[57]
                .sv_id.constellation == 54,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[57]."
        "sv_id.constellation, expected 54, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[57]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[57]
                .sv_id.satId == 244,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[57]."
        "sv_id.satId, expected 244, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[57]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[58]
                .residual == -15505,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[58]."
        "residual, expected -15505, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[58]
            .residual);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[58]
                .sv_id.constellation == 189,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[58]."
        "sv_id.constellation, expected 189, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[58]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[58]
                .sv_id.satId == 231,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[58]."
        "sv_id.satId, expected 231, is %d",
        last_msg.msg.ssr_gridded_correction_no_std_dep_a.stec_residuals[58]
            .sv_id.satId);

    ck_assert_msg(last_msg.msg.ssr_gridded_correction_no_std_dep_a
                          .tropo_delay_correction.hydro == 16250,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_no_std_dep_a.tropo_"
                  "delay_correction.hydro, expected 16250, is %d",
                  last_msg.msg.ssr_gridded_correction_no_std_dep_a
                      .tropo_delay_correction.hydro);

    ck_assert_msg(last_msg.msg.ssr_gridded_correction_no_std_dep_a
                          .tropo_delay_correction.wet == 101,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_no_std_dep_a.tropo_"
                  "delay_correction.wet, expected 101, is %d",
                  last_msg.msg.ssr_gridded_correction_no_std_dep_a
                      .tropo_delay_correction.wet);
  }
}
END_TEST

Suite *auto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: "
      "auto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA");
  tcase_add_test(tc_acq,
                 test_auto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA);
  suite_add_tcase(s, tc_acq);
  return s;
}