/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrGriddedCorrectionDepA.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/sbp.h>
#include <libsbp/ssr.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA,
     test_auto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA) {
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

    sbp_callback_register(&sbp_state, SbpMsgSsrGriddedCorrectionDepA,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  250, 5,   108, 106, 254, 164, 217, 44,  53,  98,  93,  63,  147,
        104, 252, 133, 245, 28,  95,  100, 147, 41,  33,  92,  87,  25,  142,
        151, 74,  151, 95,  94,  7,   146, 237, 45,  167, 86,  42,  116, 224,
        169, 234, 220, 23,  176, 18,  13,  178, 79,  160, 160, 110, 15,  53,
        206, 151, 158, 22,  117, 184, 48,  170, 82,  40,  53,  122, 69,  180,
        110, 38,  65,  104, 244, 19,  238, 227, 88,  169, 164, 146, 63,  37,
        183, 85,  71,  235, 168, 114, 211, 105, 221, 156, 60,  18,  230, 2,
        142, 172, 16,  39,  33,  126, 106, 99,  188, 234, 41,  162, 197, 138,
        227, 80,  12,  54,  67,  238, 5,   93,  1,   207, 129, 13,  46,  115,
        49,  58,  185, 127, 156, 200, 96,  217, 202, 15,  245, 55,  198, 81,
        218, 132, 70,  73,  82,  147, 26,  255, 14,  134, 96,  138, 55,  214,
        83,  156, 170, 163, 79,  173, 228, 115, 51,  241, 107, 245, 112, 168,
        210, 10,  5,   117, 1,   57,  108, 248, 212, 145, 119, 226, 165, 5,
        141, 202, 106, 0,   60,  36,  61,  243, 203, 216, 215, 12,  137, 16,
        28,  247, 115, 152, 181, 119, 208, 228, 203, 236, 34,  167, 196, 32,
        109, 1,   17,  101, 200, 25,  94,  125, 168, 137, 157, 4,   164, 29,
        31,  48,  132, 72,  229, 126, 186, 68,  76,  133, 21,  0,   180, 139,
        164, 148, 119, 149, 214, 120, 177, 201, 80,  80,  105, 10,  136, 118,
        77,  46,  233, 233, 227, 11,  158, 103, 167, 216,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ssr_gridded_correction_dep_a.header.iod_atmo = 245;

    test_msg.ssr_gridded_correction_dep_a.header.num_msgs = 37695;

    test_msg.ssr_gridded_correction_dep_a.header.seq_num = 64616;

    test_msg.ssr_gridded_correction_dep_a.header.time.tow = 892131748;

    test_msg.ssr_gridded_correction_dep_a.header.time.wn = 23906;

    test_msg.ssr_gridded_correction_dep_a.header.tropo_quality_indicator = 28;

    test_msg.ssr_gridded_correction_dep_a.header.update_interval = 133;

    test_msg.ssr_gridded_correction_dep_a.index = 25695;

    test_msg.ssr_gridded_correction_dep_a.n_stec_residuals = 47;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[0].residual = -26738;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[0].stddev = 74;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[0]
        .sv_id.constellation = 25;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[0].sv_id.satId = 87;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[1].residual = 1886;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[1].stddev = 146;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[1]
        .sv_id.constellation = 95;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[1].sv_id.satId = 151;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[2].residual = 22183;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[2].stddev = 42;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[2]
        .sv_id.constellation = 45;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[2].sv_id.satId = 237;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[3].residual = -5463;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[3].stddev = 220;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[3]
        .sv_id.constellation = 224;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[3].sv_id.satId = 116;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[4].residual = 3346;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[4].stddev = 178;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[4]
        .sv_id.constellation = 176;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[4].sv_id.satId = 23;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[5].residual = 28320;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[5].stddev = 15;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[5]
        .sv_id.constellation = 160;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[5].sv_id.satId = 79;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[6].residual = -24937;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[6].stddev = 22;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[6]
        .sv_id.constellation = 206;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[6].sv_id.satId = 53;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[7].residual = -21968;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[7].stddev = 82;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[7]
        .sv_id.constellation = 184;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[7].sv_id.satId = 117;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[8].residual = 17786;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[8].stddev = 180;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[8]
        .sv_id.constellation = 53;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[8].sv_id.satId = 40;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[9].residual = 26689;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[9].stddev = 244;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[9]
        .sv_id.constellation = 38;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[9].sv_id.satId = 110;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[10].residual = 22755;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[10].stddev = 169;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[10]
        .sv_id.constellation = 238;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[10].sv_id.satId = 19;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[11].residual = 9535;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[11].stddev = 183;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[11]
        .sv_id.constellation = 146;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[11].sv_id.satId = 164;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[12].residual = -22293;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[12].stddev = 114;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[12]
        .sv_id.constellation = 71;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[12].sv_id.satId = 85;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[13].residual = -25379;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[13].stddev = 60;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[13]
        .sv_id.constellation = 105;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[13].sv_id.satId = 211;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[14].residual = -29182;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[14].stddev = 172;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[14]
        .sv_id.constellation = 230;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[14].sv_id.satId = 18;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[15].residual = 32289;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[15].stddev = 106;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[15]
        .sv_id.constellation = 39;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[15].sv_id.satId = 16;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[16].residual = 10730;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[16].stddev = 162;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[16]
        .sv_id.constellation = 188;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[16].sv_id.satId = 99;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[17].residual = 20707;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[17].stddev = 12;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[17]
        .sv_id.constellation = 138;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[17].sv_id.satId = 197;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[18].residual = 1518;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[18].stddev = 93;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[18]
        .sv_id.constellation = 67;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[18].sv_id.satId = 54;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[19].residual = 3457;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[19].stddev = 46;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[19]
        .sv_id.constellation = 207;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[19].sv_id.satId = 1;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[20].residual = -18118;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[20].stddev = 127;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[20]
        .sv_id.constellation = 49;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[20].sv_id.satId = 115;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[21].residual = -9888;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[21].stddev = 202;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[21]
        .sv_id.constellation = 200;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[21].sv_id.satId = 156;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[22].residual = -14793;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[22].stddev = 81;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[22]
        .sv_id.constellation = 245;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[22].sv_id.satId = 15;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[23].residual = 18758;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[23].stddev = 82;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[23]
        .sv_id.constellation = 132;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[23].sv_id.satId = 218;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[24].residual = 3839;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[24].stddev = 134;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[24]
        .sv_id.constellation = 26;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[24].sv_id.satId = 147;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[25].residual = -10697;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[25].stddev = 83;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[25]
        .sv_id.constellation = 138;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[25].sv_id.satId = 96;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[26].residual = 20387;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[26].stddev = 173;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[26]
        .sv_id.constellation = 170;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[26].sv_id.satId = 156;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[27].residual = -3789;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[27].stddev = 107;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[27]
        .sv_id.constellation = 115;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[27].sv_id.satId = 228;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[28].residual = -11608;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[28].stddev = 10;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[28]
        .sv_id.constellation = 112;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[28].sv_id.satId = 245;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[29].residual = 14593;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[29].stddev = 108;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[29]
        .sv_id.constellation = 117;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[29].sv_id.satId = 5;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[30].residual = 30609;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[30].stddev = 226;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[30]
        .sv_id.constellation = 212;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[30].sv_id.satId = 248;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[31].residual = -13683;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[31].stddev = 106;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[31]
        .sv_id.constellation = 5;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[31].sv_id.satId = 165;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[32].residual = 15652;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[32].stddev = 243;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[32]
        .sv_id.constellation = 60;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[32].sv_id.satId = 0;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[33].residual = 3287;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[33].stddev = 137;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[33]
        .sv_id.constellation = 216;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[33].sv_id.satId = 203;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[34].residual = 29687;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[34].stddev = 152;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[34]
        .sv_id.constellation = 28;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[34].sv_id.satId = 16;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[35].residual = -6960;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[35].stddev = 203;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[35]
        .sv_id.constellation = 119;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[35].sv_id.satId = 181;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[36].residual = -15193;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[36].stddev = 32;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[36]
        .sv_id.constellation = 34;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[36].sv_id.satId = 236;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[37].residual = 25873;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[37].stddev = 200;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[37]
        .sv_id.constellation = 1;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[37].sv_id.satId = 109;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[38].residual = -22403;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[38].stddev = 137;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[38]
        .sv_id.constellation = 94;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[38].sv_id.satId = 25;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[39].residual = 7588;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[39].stddev = 31;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[39]
        .sv_id.constellation = 4;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[39].sv_id.satId = 157;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[40].residual = -6840;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[40].stddev = 126;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[40]
        .sv_id.constellation = 132;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[40].sv_id.satId = 48;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[41].residual = -31412;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[41].stddev = 21;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[41]
        .sv_id.constellation = 68;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[41].sv_id.satId = 186;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[42].residual = -23413;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[42].stddev = 148;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[42]
        .sv_id.constellation = 180;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[42].sv_id.satId = 0;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[43].residual = 30934;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[43].stddev = 177;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[43]
        .sv_id.constellation = 149;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[43].sv_id.satId = 119;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[44].residual = 26960;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[44].stddev = 10;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[44]
        .sv_id.constellation = 80;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[44].sv_id.satId = 201;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[45].residual = 11853;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[45].stddev = 233;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[45]
        .sv_id.constellation = 118;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[45].sv_id.satId = 136;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[46].residual = -25077;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[46].stddev = 103;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[46]
        .sv_id.constellation = 227;

    test_msg.ssr_gridded_correction_dep_a.stec_residuals[46].sv_id.satId = 233;

    test_msg.ssr_gridded_correction_dep_a.tropo_delay_correction.hydro = 10643;

    test_msg.ssr_gridded_correction_dep_a.tropo_delay_correction.stddev = 92;

    test_msg.ssr_gridded_correction_dep_a.tropo_delay_correction.wet = 33;

    sbp_message_send(&sbp_state, SbpMsgSsrGriddedCorrectionDepA, 27244,
                     &test_msg, &dummy_write);

    EXPECT_EQ(dummy_wr, sizeof(encoded_frame))
        << "not enough data was written to dummy_buff (expected: "
        << sizeof(encoded_frame) << ", actual: " << dummy_wr << ")";
    EXPECT_EQ(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)), 0)
        << "frame was not encoded properly";

    while (dummy_rd < dummy_wr) {
      EXPECT_GE(sbp_process(&sbp_state, &dummy_read), SBP_OK)
          << "sbp_process threw an error!";
    }

    EXPECT_EQ(last_msg.n_callbacks_logged, 1)
        << "msg_callback: one callback should have been logged";
    EXPECT_EQ(last_msg.sender_id, 27244)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgSsrGriddedCorrectionDepA, &last_msg.msg,
                              &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.header.iod_atmo, 245)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.header.iod_atmo, "
           "expected 245, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.header.iod_atmo;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.header.num_msgs, 37695)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.header.num_msgs, "
           "expected 37695, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.header.num_msgs;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.header.seq_num, 64616)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.header.seq_num, expected "
           "64616, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.header.seq_num;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.header.time.tow,
              892131748)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.header.time.tow, "
           "expected 892131748, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.header.time.tow;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.header.time.wn, 23906)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.header.time.wn, expected "
           "23906, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.header.time.wn;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.header
                  .tropo_quality_indicator,
              28)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.header.tropo_quality_"
           "indicator, expected 28, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.header
               .tropo_quality_indicator;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.header.update_interval,
              133)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.header.update_interval, "
           "expected 133, is "
        << (int64_t)
               last_msg.msg.ssr_gridded_correction_dep_a.header.update_interval;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.index, 25695)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.index, expected 25695, "
           "is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.index;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.n_stec_residuals, 47)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.n_stec_residuals, "
           "expected 47, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.n_stec_residuals;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[0].residual,
        -26738)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[0]."
           "residual, expected -26738, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[0]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[0].stddev, 74)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[0].stddev,"
           " expected 74, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[0]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[0]
                  .sv_id.constellation,
              25)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[0].sv_id."
           "constellation, expected 25, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[0]
               .sv_id.constellation;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[0].sv_id.satId,
        87)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[0].sv_id."
           "satId, expected 87, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[0]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[1].residual,
        1886)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[1]."
           "residual, expected 1886, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[1]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[1].stddev, 146)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[1].stddev,"
           " expected 146, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[1]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[1]
                  .sv_id.constellation,
              95)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[1].sv_id."
           "constellation, expected 95, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[1]
               .sv_id.constellation;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[1].sv_id.satId,
        151)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[1].sv_id."
           "satId, expected 151, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[1]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[2].residual,
        22183)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[2]."
           "residual, expected 22183, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[2]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[2].stddev, 42)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[2].stddev,"
           " expected 42, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[2]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[2]
                  .sv_id.constellation,
              45)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[2].sv_id."
           "constellation, expected 45, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[2]
               .sv_id.constellation;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[2].sv_id.satId,
        237)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[2].sv_id."
           "satId, expected 237, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[2]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[3].residual,
        -5463)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[3]."
           "residual, expected -5463, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[3]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[3].stddev, 220)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[3].stddev,"
           " expected 220, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[3]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[3]
                  .sv_id.constellation,
              224)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[3].sv_id."
           "constellation, expected 224, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[3]
               .sv_id.constellation;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[3].sv_id.satId,
        116)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[3].sv_id."
           "satId, expected 116, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[3]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[4].residual,
        3346)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[4]."
           "residual, expected 3346, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[4]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[4].stddev, 178)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[4].stddev,"
           " expected 178, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[4]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[4]
                  .sv_id.constellation,
              176)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[4].sv_id."
           "constellation, expected 176, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[4]
               .sv_id.constellation;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[4].sv_id.satId,
        23)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[4].sv_id."
           "satId, expected 23, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[4]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[5].residual,
        28320)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[5]."
           "residual, expected 28320, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[5]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[5].stddev, 15)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[5].stddev,"
           " expected 15, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[5]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[5]
                  .sv_id.constellation,
              160)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[5].sv_id."
           "constellation, expected 160, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[5]
               .sv_id.constellation;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[5].sv_id.satId,
        79)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[5].sv_id."
           "satId, expected 79, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[5]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[6].residual,
        -24937)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[6]."
           "residual, expected -24937, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[6]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[6].stddev, 22)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[6].stddev,"
           " expected 22, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[6]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[6]
                  .sv_id.constellation,
              206)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[6].sv_id."
           "constellation, expected 206, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[6]
               .sv_id.constellation;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[6].sv_id.satId,
        53)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[6].sv_id."
           "satId, expected 53, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[6]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[7].residual,
        -21968)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[7]."
           "residual, expected -21968, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[7]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[7].stddev, 82)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[7].stddev,"
           " expected 82, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[7]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[7]
                  .sv_id.constellation,
              184)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[7].sv_id."
           "constellation, expected 184, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[7]
               .sv_id.constellation;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[7].sv_id.satId,
        117)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[7].sv_id."
           "satId, expected 117, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[7]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[8].residual,
        17786)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[8]."
           "residual, expected 17786, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[8]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[8].stddev, 180)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[8].stddev,"
           " expected 180, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[8]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[8]
                  .sv_id.constellation,
              53)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[8].sv_id."
           "constellation, expected 53, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[8]
               .sv_id.constellation;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[8].sv_id.satId,
        40)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[8].sv_id."
           "satId, expected 40, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[8]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[9].residual,
        26689)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[9]."
           "residual, expected 26689, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[9]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[9].stddev, 244)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[9].stddev,"
           " expected 244, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[9]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[9]
                  .sv_id.constellation,
              38)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[9].sv_id."
           "constellation, expected 38, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[9]
               .sv_id.constellation;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[9].sv_id.satId,
        110)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[9].sv_id."
           "satId, expected 110, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[9]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[10].residual,
        22755)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[10]."
           "residual, expected 22755, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[10]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[10].stddev,
        169)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[10]."
           "stddev, expected 169, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[10]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[10]
                  .sv_id.constellation,
              238)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[10].sv_id."
           "constellation, expected 238, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[10]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[10]
                  .sv_id.satId,
              19)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[10].sv_id."
           "satId, expected 19, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[10]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[11].residual,
        9535)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[11]."
           "residual, expected 9535, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[11]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[11].stddev,
        183)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[11]."
           "stddev, expected 183, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[11]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[11]
                  .sv_id.constellation,
              146)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[11].sv_id."
           "constellation, expected 146, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[11]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[11]
                  .sv_id.satId,
              164)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[11].sv_id."
           "satId, expected 164, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[11]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[12].residual,
        -22293)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[12]."
           "residual, expected -22293, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[12]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[12].stddev,
        114)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[12]."
           "stddev, expected 114, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[12]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[12]
                  .sv_id.constellation,
              71)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[12].sv_id."
           "constellation, expected 71, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[12]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[12]
                  .sv_id.satId,
              85)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[12].sv_id."
           "satId, expected 85, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[12]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[13].residual,
        -25379)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[13]."
           "residual, expected -25379, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[13]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[13].stddev, 60)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[13]."
           "stddev, expected 60, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[13]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[13]
                  .sv_id.constellation,
              105)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[13].sv_id."
           "constellation, expected 105, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[13]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[13]
                  .sv_id.satId,
              211)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[13].sv_id."
           "satId, expected 211, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[13]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[14].residual,
        -29182)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[14]."
           "residual, expected -29182, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[14]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[14].stddev,
        172)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[14]."
           "stddev, expected 172, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[14]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[14]
                  .sv_id.constellation,
              230)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[14].sv_id."
           "constellation, expected 230, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[14]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[14]
                  .sv_id.satId,
              18)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[14].sv_id."
           "satId, expected 18, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[14]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[15].residual,
        32289)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[15]."
           "residual, expected 32289, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[15]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[15].stddev,
        106)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[15]."
           "stddev, expected 106, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[15]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[15]
                  .sv_id.constellation,
              39)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[15].sv_id."
           "constellation, expected 39, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[15]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[15]
                  .sv_id.satId,
              16)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[15].sv_id."
           "satId, expected 16, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[15]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[16].residual,
        10730)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[16]."
           "residual, expected 10730, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[16]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[16].stddev,
        162)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[16]."
           "stddev, expected 162, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[16]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[16]
                  .sv_id.constellation,
              188)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[16].sv_id."
           "constellation, expected 188, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[16]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[16]
                  .sv_id.satId,
              99)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[16].sv_id."
           "satId, expected 99, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[16]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[17].residual,
        20707)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[17]."
           "residual, expected 20707, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[17]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[17].stddev, 12)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[17]."
           "stddev, expected 12, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[17]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[17]
                  .sv_id.constellation,
              138)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[17].sv_id."
           "constellation, expected 138, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[17]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[17]
                  .sv_id.satId,
              197)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[17].sv_id."
           "satId, expected 197, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[17]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[18].residual,
        1518)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[18]."
           "residual, expected 1518, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[18]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[18].stddev, 93)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[18]."
           "stddev, expected 93, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[18]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[18]
                  .sv_id.constellation,
              67)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[18].sv_id."
           "constellation, expected 67, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[18]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[18]
                  .sv_id.satId,
              54)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[18].sv_id."
           "satId, expected 54, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[18]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[19].residual,
        3457)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[19]."
           "residual, expected 3457, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[19]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[19].stddev, 46)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[19]."
           "stddev, expected 46, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[19]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[19]
                  .sv_id.constellation,
              207)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[19].sv_id."
           "constellation, expected 207, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[19]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[19]
                  .sv_id.satId,
              1)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[19].sv_id."
           "satId, expected 1, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[19]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[20].residual,
        -18118)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[20]."
           "residual, expected -18118, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[20]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[20].stddev,
        127)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[20]."
           "stddev, expected 127, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[20]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[20]
                  .sv_id.constellation,
              49)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[20].sv_id."
           "constellation, expected 49, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[20]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[20]
                  .sv_id.satId,
              115)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[20].sv_id."
           "satId, expected 115, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[20]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[21].residual,
        -9888)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[21]."
           "residual, expected -9888, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[21]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[21].stddev,
        202)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[21]."
           "stddev, expected 202, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[21]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[21]
                  .sv_id.constellation,
              200)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[21].sv_id."
           "constellation, expected 200, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[21]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[21]
                  .sv_id.satId,
              156)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[21].sv_id."
           "satId, expected 156, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[21]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[22].residual,
        -14793)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[22]."
           "residual, expected -14793, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[22]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[22].stddev, 81)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[22]."
           "stddev, expected 81, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[22]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[22]
                  .sv_id.constellation,
              245)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[22].sv_id."
           "constellation, expected 245, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[22]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[22]
                  .sv_id.satId,
              15)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[22].sv_id."
           "satId, expected 15, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[22]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[23].residual,
        18758)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[23]."
           "residual, expected 18758, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[23]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[23].stddev, 82)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[23]."
           "stddev, expected 82, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[23]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[23]
                  .sv_id.constellation,
              132)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[23].sv_id."
           "constellation, expected 132, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[23]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[23]
                  .sv_id.satId,
              218)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[23].sv_id."
           "satId, expected 218, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[23]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[24].residual,
        3839)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[24]."
           "residual, expected 3839, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[24]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[24].stddev,
        134)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[24]."
           "stddev, expected 134, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[24]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[24]
                  .sv_id.constellation,
              26)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[24].sv_id."
           "constellation, expected 26, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[24]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[24]
                  .sv_id.satId,
              147)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[24].sv_id."
           "satId, expected 147, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[24]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[25].residual,
        -10697)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[25]."
           "residual, expected -10697, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[25]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[25].stddev, 83)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[25]."
           "stddev, expected 83, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[25]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[25]
                  .sv_id.constellation,
              138)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[25].sv_id."
           "constellation, expected 138, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[25]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[25]
                  .sv_id.satId,
              96)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[25].sv_id."
           "satId, expected 96, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[25]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[26].residual,
        20387)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[26]."
           "residual, expected 20387, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[26]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[26].stddev,
        173)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[26]."
           "stddev, expected 173, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[26]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[26]
                  .sv_id.constellation,
              170)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[26].sv_id."
           "constellation, expected 170, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[26]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[26]
                  .sv_id.satId,
              156)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[26].sv_id."
           "satId, expected 156, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[26]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[27].residual,
        -3789)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[27]."
           "residual, expected -3789, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[27]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[27].stddev,
        107)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[27]."
           "stddev, expected 107, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[27]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[27]
                  .sv_id.constellation,
              115)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[27].sv_id."
           "constellation, expected 115, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[27]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[27]
                  .sv_id.satId,
              228)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[27].sv_id."
           "satId, expected 228, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[27]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[28].residual,
        -11608)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[28]."
           "residual, expected -11608, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[28]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[28].stddev, 10)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[28]."
           "stddev, expected 10, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[28]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[28]
                  .sv_id.constellation,
              112)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[28].sv_id."
           "constellation, expected 112, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[28]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[28]
                  .sv_id.satId,
              245)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[28].sv_id."
           "satId, expected 245, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[28]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[29].residual,
        14593)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[29]."
           "residual, expected 14593, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[29]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[29].stddev,
        108)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[29]."
           "stddev, expected 108, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[29]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[29]
                  .sv_id.constellation,
              117)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[29].sv_id."
           "constellation, expected 117, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[29]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[29]
                  .sv_id.satId,
              5)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[29].sv_id."
           "satId, expected 5, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[29]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[30].residual,
        30609)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[30]."
           "residual, expected 30609, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[30]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[30].stddev,
        226)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[30]."
           "stddev, expected 226, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[30]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[30]
                  .sv_id.constellation,
              212)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[30].sv_id."
           "constellation, expected 212, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[30]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[30]
                  .sv_id.satId,
              248)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[30].sv_id."
           "satId, expected 248, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[30]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[31].residual,
        -13683)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[31]."
           "residual, expected -13683, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[31]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[31].stddev,
        106)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[31]."
           "stddev, expected 106, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[31]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[31]
                  .sv_id.constellation,
              5)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[31].sv_id."
           "constellation, expected 5, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[31]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[31]
                  .sv_id.satId,
              165)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[31].sv_id."
           "satId, expected 165, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[31]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[32].residual,
        15652)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[32]."
           "residual, expected 15652, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[32]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[32].stddev,
        243)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[32]."
           "stddev, expected 243, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[32]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[32]
                  .sv_id.constellation,
              60)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[32].sv_id."
           "constellation, expected 60, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[32]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[32]
                  .sv_id.satId,
              0)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[32].sv_id."
           "satId, expected 0, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[32]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[33].residual,
        3287)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[33]."
           "residual, expected 3287, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[33]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[33].stddev,
        137)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[33]."
           "stddev, expected 137, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[33]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[33]
                  .sv_id.constellation,
              216)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[33].sv_id."
           "constellation, expected 216, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[33]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[33]
                  .sv_id.satId,
              203)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[33].sv_id."
           "satId, expected 203, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[33]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[34].residual,
        29687)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[34]."
           "residual, expected 29687, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[34]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[34].stddev,
        152)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[34]."
           "stddev, expected 152, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[34]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[34]
                  .sv_id.constellation,
              28)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[34].sv_id."
           "constellation, expected 28, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[34]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[34]
                  .sv_id.satId,
              16)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[34].sv_id."
           "satId, expected 16, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[34]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[35].residual,
        -6960)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[35]."
           "residual, expected -6960, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[35]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[35].stddev,
        203)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[35]."
           "stddev, expected 203, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[35]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[35]
                  .sv_id.constellation,
              119)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[35].sv_id."
           "constellation, expected 119, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[35]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[35]
                  .sv_id.satId,
              181)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[35].sv_id."
           "satId, expected 181, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[35]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[36].residual,
        -15193)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[36]."
           "residual, expected -15193, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[36]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[36].stddev, 32)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[36]."
           "stddev, expected 32, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[36]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[36]
                  .sv_id.constellation,
              34)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[36].sv_id."
           "constellation, expected 34, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[36]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[36]
                  .sv_id.satId,
              236)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[36].sv_id."
           "satId, expected 236, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[36]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[37].residual,
        25873)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[37]."
           "residual, expected 25873, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[37]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[37].stddev,
        200)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[37]."
           "stddev, expected 200, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[37]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[37]
                  .sv_id.constellation,
              1)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[37].sv_id."
           "constellation, expected 1, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[37]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[37]
                  .sv_id.satId,
              109)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[37].sv_id."
           "satId, expected 109, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[37]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[38].residual,
        -22403)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[38]."
           "residual, expected -22403, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[38]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[38].stddev,
        137)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[38]."
           "stddev, expected 137, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[38]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[38]
                  .sv_id.constellation,
              94)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[38].sv_id."
           "constellation, expected 94, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[38]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[38]
                  .sv_id.satId,
              25)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[38].sv_id."
           "satId, expected 25, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[38]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[39].residual,
        7588)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[39]."
           "residual, expected 7588, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[39]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[39].stddev, 31)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[39]."
           "stddev, expected 31, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[39]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[39]
                  .sv_id.constellation,
              4)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[39].sv_id."
           "constellation, expected 4, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[39]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[39]
                  .sv_id.satId,
              157)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[39].sv_id."
           "satId, expected 157, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[39]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[40].residual,
        -6840)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[40]."
           "residual, expected -6840, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[40]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[40].stddev,
        126)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[40]."
           "stddev, expected 126, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[40]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[40]
                  .sv_id.constellation,
              132)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[40].sv_id."
           "constellation, expected 132, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[40]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[40]
                  .sv_id.satId,
              48)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[40].sv_id."
           "satId, expected 48, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[40]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[41].residual,
        -31412)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[41]."
           "residual, expected -31412, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[41]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[41].stddev, 21)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[41]."
           "stddev, expected 21, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[41]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[41]
                  .sv_id.constellation,
              68)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[41].sv_id."
           "constellation, expected 68, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[41]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[41]
                  .sv_id.satId,
              186)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[41].sv_id."
           "satId, expected 186, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[41]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[42].residual,
        -23413)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[42]."
           "residual, expected -23413, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[42]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[42].stddev,
        148)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[42]."
           "stddev, expected 148, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[42]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[42]
                  .sv_id.constellation,
              180)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[42].sv_id."
           "constellation, expected 180, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[42]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[42]
                  .sv_id.satId,
              0)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[42].sv_id."
           "satId, expected 0, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[42]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[43].residual,
        30934)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[43]."
           "residual, expected 30934, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[43]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[43].stddev,
        177)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[43]."
           "stddev, expected 177, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[43]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[43]
                  .sv_id.constellation,
              149)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[43].sv_id."
           "constellation, expected 149, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[43]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[43]
                  .sv_id.satId,
              119)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[43].sv_id."
           "satId, expected 119, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[43]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[44].residual,
        26960)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[44]."
           "residual, expected 26960, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[44]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[44].stddev, 10)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[44]."
           "stddev, expected 10, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[44]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[44]
                  .sv_id.constellation,
              80)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[44].sv_id."
           "constellation, expected 80, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[44]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[44]
                  .sv_id.satId,
              201)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[44].sv_id."
           "satId, expected 201, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[44]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[45].residual,
        11853)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[45]."
           "residual, expected 11853, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[45]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[45].stddev,
        233)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[45]."
           "stddev, expected 233, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[45]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[45]
                  .sv_id.constellation,
              118)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[45].sv_id."
           "constellation, expected 118, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[45]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[45]
                  .sv_id.satId,
              136)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[45].sv_id."
           "satId, expected 136, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[45]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[46].residual,
        -25077)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[46]."
           "residual, expected -25077, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[46]
               .residual;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[46].stddev,
        103)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[46]."
           "stddev, expected 103, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[46]
               .stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[46]
                  .sv_id.constellation,
              227)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[46].sv_id."
           "constellation, expected 227, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[46]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[46]
                  .sv_id.satId,
              233)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[46].sv_id."
           "satId, expected 233, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a.stec_residuals[46]
               .sv_id.satId;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.tropo_delay_correction.hydro,
        10643)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.tropo_delay_correction."
           "hydro, expected 10643, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a
               .tropo_delay_correction.hydro;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.tropo_delay_correction.stddev,
        92)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.tropo_delay_correction."
           "stddev, expected 92, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a
               .tropo_delay_correction.stddev;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_dep_a.tropo_delay_correction.wet,
        33)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_dep_a.tropo_delay_correction."
           "wet, expected 33, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_dep_a
               .tropo_delay_correction.wet;
  }
}

}  // namespace
