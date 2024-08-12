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
// spec/tests/yaml/swiftnav/sbp/soln_meta/test_MsgSolnMetaDepA.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <libsbp/sbp.h>
#include <libsbp/solution_meta.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  sbp_msg_type_t msg_type;
  sbp_msg_t msg;
  void *context;
} last_msg;

static size_t dummy_wr = 0;
static size_t dummy_rd = 0;
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
  size_t real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(dummy_buff + dummy_wr, buff, real_n);
  dummy_wr += real_n;
  return (s32)real_n;
}

static s32 dummy_read(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  size_t real_n = n;  //(dummy_n > n) ? n : dummy_n;
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

START_TEST(test_auto_check_sbp_solution_meta_MsgSolnMetaDepA) {
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

    sbp_callback_register(&sbp_state, 0xff0f, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  15,  255, 84,  241, 254, 183, 222, 157, 121, 5,   164, 238, 31,
        190, 115, 93,  59,  103, 36,  83,  161, 156, 46,  253, 67,  87,  200,
        39,  250, 245, 242, 228, 72,  18,  222, 11,  88,  207, 218, 231, 13,
        226, 224, 22,  196, 21,  242, 12,  89,  71,  219, 182, 85,  145, 204,
        146, 40,  204, 51,  21,  153, 227, 44,  15,  28,  255, 39,  205, 216,
        240, 190, 93,  219, 103, 42,  41,  182, 76,  222, 17,  23,  125, 31,
        18,  229, 28,  47,  214, 25,  100, 84,  106, 72,  48,  10,  222, 232,
        235, 73,  109, 163, 51,  152, 133, 235, 87,  70,  2,   108, 91,  101,
        200, 55,  24,  156, 233, 73,  39,  66,  97,  140, 252, 227, 230, 237,
        135, 241, 245, 205, 70,  0,   219, 188, 107, 136, 178, 58,  1,   29,
        44,  213, 225, 147, 190, 96,  192, 108, 228, 15,  203, 18,  3,   222,
        180, 68,  101, 229, 223, 203, 243, 164, 92,  165, 220, 159, 174, 121,
        112, 167, 240, 40,  59,  3,   230, 52,  149, 148, 218, 142, 212, 109,
        176, 71,  179, 172, 77,  1,   193, 70,  147, 149, 23,  144, 148, 239,
        195, 186, 86,  30,  34,  143, 156, 207, 63,  55,  117, 255, 222, 222,
        219, 145, 224, 191, 210, 109, 86,  153, 21,  32,  226, 10,  60,  63,
        106, 236, 93,  96,  30,  163, 106, 238, 147, 133, 132, 107, 152, 214,
        221, 185, 202, 21,  252, 51,  130, 59,  166, 202, 127, 170, 58,  193,
        215, 125, 22,  58,  135, 47,  88,  142, 77,  211,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.soln_meta_dep_a.age_corrections = 48671;

    test_msg.soln_meta_dep_a.alignment_status = 115;

    test_msg.soln_meta_dep_a.hdop = 31133;

    test_msg.soln_meta_dep_a.last_used_gnss_pos_tow = 610745181;

    test_msg.soln_meta_dep_a.last_used_gnss_vel_tow = 782016851;

    test_msg.soln_meta_dep_a.n_sats = 238;

    test_msg.soln_meta_dep_a.n_sol_in = 118;

    test_msg.soln_meta_dep_a.pdop = 57015;

    test_msg.soln_meta_dep_a.sol_in[0].flags = 67;

    test_msg.soln_meta_dep_a.sol_in[0].sensor_type = 253;

    test_msg.soln_meta_dep_a.sol_in[1].flags = 200;

    test_msg.soln_meta_dep_a.sol_in[1].sensor_type = 87;

    test_msg.soln_meta_dep_a.sol_in[2].flags = 250;

    test_msg.soln_meta_dep_a.sol_in[2].sensor_type = 39;

    test_msg.soln_meta_dep_a.sol_in[3].flags = 242;

    test_msg.soln_meta_dep_a.sol_in[3].sensor_type = 245;

    test_msg.soln_meta_dep_a.sol_in[4].flags = 72;

    test_msg.soln_meta_dep_a.sol_in[4].sensor_type = 228;

    test_msg.soln_meta_dep_a.sol_in[5].flags = 222;

    test_msg.soln_meta_dep_a.sol_in[5].sensor_type = 18;

    test_msg.soln_meta_dep_a.sol_in[6].flags = 88;

    test_msg.soln_meta_dep_a.sol_in[6].sensor_type = 11;

    test_msg.soln_meta_dep_a.sol_in[7].flags = 218;

    test_msg.soln_meta_dep_a.sol_in[7].sensor_type = 207;

    test_msg.soln_meta_dep_a.sol_in[8].flags = 13;

    test_msg.soln_meta_dep_a.sol_in[8].sensor_type = 231;

    test_msg.soln_meta_dep_a.sol_in[9].flags = 224;

    test_msg.soln_meta_dep_a.sol_in[9].sensor_type = 226;

    test_msg.soln_meta_dep_a.sol_in[10].flags = 196;

    test_msg.soln_meta_dep_a.sol_in[10].sensor_type = 22;

    test_msg.soln_meta_dep_a.sol_in[11].flags = 242;

    test_msg.soln_meta_dep_a.sol_in[11].sensor_type = 21;

    test_msg.soln_meta_dep_a.sol_in[12].flags = 89;

    test_msg.soln_meta_dep_a.sol_in[12].sensor_type = 12;

    test_msg.soln_meta_dep_a.sol_in[13].flags = 219;

    test_msg.soln_meta_dep_a.sol_in[13].sensor_type = 71;

    test_msg.soln_meta_dep_a.sol_in[14].flags = 85;

    test_msg.soln_meta_dep_a.sol_in[14].sensor_type = 182;

    test_msg.soln_meta_dep_a.sol_in[15].flags = 204;

    test_msg.soln_meta_dep_a.sol_in[15].sensor_type = 145;

    test_msg.soln_meta_dep_a.sol_in[16].flags = 40;

    test_msg.soln_meta_dep_a.sol_in[16].sensor_type = 146;

    test_msg.soln_meta_dep_a.sol_in[17].flags = 51;

    test_msg.soln_meta_dep_a.sol_in[17].sensor_type = 204;

    test_msg.soln_meta_dep_a.sol_in[18].flags = 153;

    test_msg.soln_meta_dep_a.sol_in[18].sensor_type = 21;

    test_msg.soln_meta_dep_a.sol_in[19].flags = 44;

    test_msg.soln_meta_dep_a.sol_in[19].sensor_type = 227;

    test_msg.soln_meta_dep_a.sol_in[20].flags = 28;

    test_msg.soln_meta_dep_a.sol_in[20].sensor_type = 15;

    test_msg.soln_meta_dep_a.sol_in[21].flags = 39;

    test_msg.soln_meta_dep_a.sol_in[21].sensor_type = 255;

    test_msg.soln_meta_dep_a.sol_in[22].flags = 216;

    test_msg.soln_meta_dep_a.sol_in[22].sensor_type = 205;

    test_msg.soln_meta_dep_a.sol_in[23].flags = 190;

    test_msg.soln_meta_dep_a.sol_in[23].sensor_type = 240;

    test_msg.soln_meta_dep_a.sol_in[24].flags = 219;

    test_msg.soln_meta_dep_a.sol_in[24].sensor_type = 93;

    test_msg.soln_meta_dep_a.sol_in[25].flags = 42;

    test_msg.soln_meta_dep_a.sol_in[25].sensor_type = 103;

    test_msg.soln_meta_dep_a.sol_in[26].flags = 182;

    test_msg.soln_meta_dep_a.sol_in[26].sensor_type = 41;

    test_msg.soln_meta_dep_a.sol_in[27].flags = 222;

    test_msg.soln_meta_dep_a.sol_in[27].sensor_type = 76;

    test_msg.soln_meta_dep_a.sol_in[28].flags = 23;

    test_msg.soln_meta_dep_a.sol_in[28].sensor_type = 17;

    test_msg.soln_meta_dep_a.sol_in[29].flags = 31;

    test_msg.soln_meta_dep_a.sol_in[29].sensor_type = 125;

    test_msg.soln_meta_dep_a.sol_in[30].flags = 229;

    test_msg.soln_meta_dep_a.sol_in[30].sensor_type = 18;

    test_msg.soln_meta_dep_a.sol_in[31].flags = 47;

    test_msg.soln_meta_dep_a.sol_in[31].sensor_type = 28;

    test_msg.soln_meta_dep_a.sol_in[32].flags = 25;

    test_msg.soln_meta_dep_a.sol_in[32].sensor_type = 214;

    test_msg.soln_meta_dep_a.sol_in[33].flags = 84;

    test_msg.soln_meta_dep_a.sol_in[33].sensor_type = 100;

    test_msg.soln_meta_dep_a.sol_in[34].flags = 72;

    test_msg.soln_meta_dep_a.sol_in[34].sensor_type = 106;

    test_msg.soln_meta_dep_a.sol_in[35].flags = 10;

    test_msg.soln_meta_dep_a.sol_in[35].sensor_type = 48;

    test_msg.soln_meta_dep_a.sol_in[36].flags = 232;

    test_msg.soln_meta_dep_a.sol_in[36].sensor_type = 222;

    test_msg.soln_meta_dep_a.sol_in[37].flags = 73;

    test_msg.soln_meta_dep_a.sol_in[37].sensor_type = 235;

    test_msg.soln_meta_dep_a.sol_in[38].flags = 163;

    test_msg.soln_meta_dep_a.sol_in[38].sensor_type = 109;

    test_msg.soln_meta_dep_a.sol_in[39].flags = 152;

    test_msg.soln_meta_dep_a.sol_in[39].sensor_type = 51;

    test_msg.soln_meta_dep_a.sol_in[40].flags = 235;

    test_msg.soln_meta_dep_a.sol_in[40].sensor_type = 133;

    test_msg.soln_meta_dep_a.sol_in[41].flags = 70;

    test_msg.soln_meta_dep_a.sol_in[41].sensor_type = 87;

    test_msg.soln_meta_dep_a.sol_in[42].flags = 108;

    test_msg.soln_meta_dep_a.sol_in[42].sensor_type = 2;

    test_msg.soln_meta_dep_a.sol_in[43].flags = 101;

    test_msg.soln_meta_dep_a.sol_in[43].sensor_type = 91;

    test_msg.soln_meta_dep_a.sol_in[44].flags = 55;

    test_msg.soln_meta_dep_a.sol_in[44].sensor_type = 200;

    test_msg.soln_meta_dep_a.sol_in[45].flags = 156;

    test_msg.soln_meta_dep_a.sol_in[45].sensor_type = 24;

    test_msg.soln_meta_dep_a.sol_in[46].flags = 73;

    test_msg.soln_meta_dep_a.sol_in[46].sensor_type = 233;

    test_msg.soln_meta_dep_a.sol_in[47].flags = 66;

    test_msg.soln_meta_dep_a.sol_in[47].sensor_type = 39;

    test_msg.soln_meta_dep_a.sol_in[48].flags = 140;

    test_msg.soln_meta_dep_a.sol_in[48].sensor_type = 97;

    test_msg.soln_meta_dep_a.sol_in[49].flags = 227;

    test_msg.soln_meta_dep_a.sol_in[49].sensor_type = 252;

    test_msg.soln_meta_dep_a.sol_in[50].flags = 237;

    test_msg.soln_meta_dep_a.sol_in[50].sensor_type = 230;

    test_msg.soln_meta_dep_a.sol_in[51].flags = 241;

    test_msg.soln_meta_dep_a.sol_in[51].sensor_type = 135;

    test_msg.soln_meta_dep_a.sol_in[52].flags = 205;

    test_msg.soln_meta_dep_a.sol_in[52].sensor_type = 245;

    test_msg.soln_meta_dep_a.sol_in[53].flags = 0;

    test_msg.soln_meta_dep_a.sol_in[53].sensor_type = 70;

    test_msg.soln_meta_dep_a.sol_in[54].flags = 188;

    test_msg.soln_meta_dep_a.sol_in[54].sensor_type = 219;

    test_msg.soln_meta_dep_a.sol_in[55].flags = 136;

    test_msg.soln_meta_dep_a.sol_in[55].sensor_type = 107;

    test_msg.soln_meta_dep_a.sol_in[56].flags = 58;

    test_msg.soln_meta_dep_a.sol_in[56].sensor_type = 178;

    test_msg.soln_meta_dep_a.sol_in[57].flags = 29;

    test_msg.soln_meta_dep_a.sol_in[57].sensor_type = 1;

    test_msg.soln_meta_dep_a.sol_in[58].flags = 213;

    test_msg.soln_meta_dep_a.sol_in[58].sensor_type = 44;

    test_msg.soln_meta_dep_a.sol_in[59].flags = 147;

    test_msg.soln_meta_dep_a.sol_in[59].sensor_type = 225;

    test_msg.soln_meta_dep_a.sol_in[60].flags = 96;

    test_msg.soln_meta_dep_a.sol_in[60].sensor_type = 190;

    test_msg.soln_meta_dep_a.sol_in[61].flags = 108;

    test_msg.soln_meta_dep_a.sol_in[61].sensor_type = 192;

    test_msg.soln_meta_dep_a.sol_in[62].flags = 15;

    test_msg.soln_meta_dep_a.sol_in[62].sensor_type = 228;

    test_msg.soln_meta_dep_a.sol_in[63].flags = 18;

    test_msg.soln_meta_dep_a.sol_in[63].sensor_type = 203;

    test_msg.soln_meta_dep_a.sol_in[64].flags = 222;

    test_msg.soln_meta_dep_a.sol_in[64].sensor_type = 3;

    test_msg.soln_meta_dep_a.sol_in[65].flags = 68;

    test_msg.soln_meta_dep_a.sol_in[65].sensor_type = 180;

    test_msg.soln_meta_dep_a.sol_in[66].flags = 229;

    test_msg.soln_meta_dep_a.sol_in[66].sensor_type = 101;

    test_msg.soln_meta_dep_a.sol_in[67].flags = 203;

    test_msg.soln_meta_dep_a.sol_in[67].sensor_type = 223;

    test_msg.soln_meta_dep_a.sol_in[68].flags = 164;

    test_msg.soln_meta_dep_a.sol_in[68].sensor_type = 243;

    test_msg.soln_meta_dep_a.sol_in[69].flags = 165;

    test_msg.soln_meta_dep_a.sol_in[69].sensor_type = 92;

    test_msg.soln_meta_dep_a.sol_in[70].flags = 159;

    test_msg.soln_meta_dep_a.sol_in[70].sensor_type = 220;

    test_msg.soln_meta_dep_a.sol_in[71].flags = 121;

    test_msg.soln_meta_dep_a.sol_in[71].sensor_type = 174;

    test_msg.soln_meta_dep_a.sol_in[72].flags = 167;

    test_msg.soln_meta_dep_a.sol_in[72].sensor_type = 112;

    test_msg.soln_meta_dep_a.sol_in[73].flags = 40;

    test_msg.soln_meta_dep_a.sol_in[73].sensor_type = 240;

    test_msg.soln_meta_dep_a.sol_in[74].flags = 3;

    test_msg.soln_meta_dep_a.sol_in[74].sensor_type = 59;

    test_msg.soln_meta_dep_a.sol_in[75].flags = 52;

    test_msg.soln_meta_dep_a.sol_in[75].sensor_type = 230;

    test_msg.soln_meta_dep_a.sol_in[76].flags = 148;

    test_msg.soln_meta_dep_a.sol_in[76].sensor_type = 149;

    test_msg.soln_meta_dep_a.sol_in[77].flags = 142;

    test_msg.soln_meta_dep_a.sol_in[77].sensor_type = 218;

    test_msg.soln_meta_dep_a.sol_in[78].flags = 109;

    test_msg.soln_meta_dep_a.sol_in[78].sensor_type = 212;

    test_msg.soln_meta_dep_a.sol_in[79].flags = 71;

    test_msg.soln_meta_dep_a.sol_in[79].sensor_type = 176;

    test_msg.soln_meta_dep_a.sol_in[80].flags = 172;

    test_msg.soln_meta_dep_a.sol_in[80].sensor_type = 179;

    test_msg.soln_meta_dep_a.sol_in[81].flags = 1;

    test_msg.soln_meta_dep_a.sol_in[81].sensor_type = 77;

    test_msg.soln_meta_dep_a.sol_in[82].flags = 70;

    test_msg.soln_meta_dep_a.sol_in[82].sensor_type = 193;

    test_msg.soln_meta_dep_a.sol_in[83].flags = 149;

    test_msg.soln_meta_dep_a.sol_in[83].sensor_type = 147;

    test_msg.soln_meta_dep_a.sol_in[84].flags = 144;

    test_msg.soln_meta_dep_a.sol_in[84].sensor_type = 23;

    test_msg.soln_meta_dep_a.sol_in[85].flags = 239;

    test_msg.soln_meta_dep_a.sol_in[85].sensor_type = 148;

    test_msg.soln_meta_dep_a.sol_in[86].flags = 186;

    test_msg.soln_meta_dep_a.sol_in[86].sensor_type = 195;

    test_msg.soln_meta_dep_a.sol_in[87].flags = 30;

    test_msg.soln_meta_dep_a.sol_in[87].sensor_type = 86;

    test_msg.soln_meta_dep_a.sol_in[88].flags = 143;

    test_msg.soln_meta_dep_a.sol_in[88].sensor_type = 34;

    test_msg.soln_meta_dep_a.sol_in[89].flags = 207;

    test_msg.soln_meta_dep_a.sol_in[89].sensor_type = 156;

    test_msg.soln_meta_dep_a.sol_in[90].flags = 55;

    test_msg.soln_meta_dep_a.sol_in[90].sensor_type = 63;

    test_msg.soln_meta_dep_a.sol_in[91].flags = 255;

    test_msg.soln_meta_dep_a.sol_in[91].sensor_type = 117;

    test_msg.soln_meta_dep_a.sol_in[92].flags = 222;

    test_msg.soln_meta_dep_a.sol_in[92].sensor_type = 222;

    test_msg.soln_meta_dep_a.sol_in[93].flags = 145;

    test_msg.soln_meta_dep_a.sol_in[93].sensor_type = 219;

    test_msg.soln_meta_dep_a.sol_in[94].flags = 191;

    test_msg.soln_meta_dep_a.sol_in[94].sensor_type = 224;

    test_msg.soln_meta_dep_a.sol_in[95].flags = 109;

    test_msg.soln_meta_dep_a.sol_in[95].sensor_type = 210;

    test_msg.soln_meta_dep_a.sol_in[96].flags = 153;

    test_msg.soln_meta_dep_a.sol_in[96].sensor_type = 86;

    test_msg.soln_meta_dep_a.sol_in[97].flags = 32;

    test_msg.soln_meta_dep_a.sol_in[97].sensor_type = 21;

    test_msg.soln_meta_dep_a.sol_in[98].flags = 10;

    test_msg.soln_meta_dep_a.sol_in[98].sensor_type = 226;

    test_msg.soln_meta_dep_a.sol_in[99].flags = 63;

    test_msg.soln_meta_dep_a.sol_in[99].sensor_type = 60;

    test_msg.soln_meta_dep_a.sol_in[100].flags = 236;

    test_msg.soln_meta_dep_a.sol_in[100].sensor_type = 106;

    test_msg.soln_meta_dep_a.sol_in[101].flags = 96;

    test_msg.soln_meta_dep_a.sol_in[101].sensor_type = 93;

    test_msg.soln_meta_dep_a.sol_in[102].flags = 163;

    test_msg.soln_meta_dep_a.sol_in[102].sensor_type = 30;

    test_msg.soln_meta_dep_a.sol_in[103].flags = 238;

    test_msg.soln_meta_dep_a.sol_in[103].sensor_type = 106;

    test_msg.soln_meta_dep_a.sol_in[104].flags = 133;

    test_msg.soln_meta_dep_a.sol_in[104].sensor_type = 147;

    test_msg.soln_meta_dep_a.sol_in[105].flags = 107;

    test_msg.soln_meta_dep_a.sol_in[105].sensor_type = 132;

    test_msg.soln_meta_dep_a.sol_in[106].flags = 214;

    test_msg.soln_meta_dep_a.sol_in[106].sensor_type = 152;

    test_msg.soln_meta_dep_a.sol_in[107].flags = 185;

    test_msg.soln_meta_dep_a.sol_in[107].sensor_type = 221;

    test_msg.soln_meta_dep_a.sol_in[108].flags = 21;

    test_msg.soln_meta_dep_a.sol_in[108].sensor_type = 202;

    test_msg.soln_meta_dep_a.sol_in[109].flags = 51;

    test_msg.soln_meta_dep_a.sol_in[109].sensor_type = 252;

    test_msg.soln_meta_dep_a.sol_in[110].flags = 59;

    test_msg.soln_meta_dep_a.sol_in[110].sensor_type = 130;

    test_msg.soln_meta_dep_a.sol_in[111].flags = 202;

    test_msg.soln_meta_dep_a.sol_in[111].sensor_type = 166;

    test_msg.soln_meta_dep_a.sol_in[112].flags = 170;

    test_msg.soln_meta_dep_a.sol_in[112].sensor_type = 127;

    test_msg.soln_meta_dep_a.sol_in[113].flags = 193;

    test_msg.soln_meta_dep_a.sol_in[113].sensor_type = 58;

    test_msg.soln_meta_dep_a.sol_in[114].flags = 125;

    test_msg.soln_meta_dep_a.sol_in[114].sensor_type = 215;

    test_msg.soln_meta_dep_a.sol_in[115].flags = 58;

    test_msg.soln_meta_dep_a.sol_in[115].sensor_type = 22;

    test_msg.soln_meta_dep_a.sol_in[116].flags = 47;

    test_msg.soln_meta_dep_a.sol_in[116].sensor_type = 135;

    test_msg.soln_meta_dep_a.sol_in[117].flags = 142;

    test_msg.soln_meta_dep_a.sol_in[117].sensor_type = 88;

    test_msg.soln_meta_dep_a.vdop = 41989;

    sbp_message_send(&sbp_state, SbpMsgSolnMetaDepA, 61780, &test_msg,
                     &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 61780,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgSolnMetaDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.age_corrections == 48671,
        "incorrect value for last_msg.msg.soln_meta_dep_a.age_corrections, "
        "expected 48671, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.age_corrections);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.alignment_status == 115,
        "incorrect value for last_msg.msg.soln_meta_dep_a.alignment_status, "
        "expected 115, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.alignment_status);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.hdop == 31133,
                  "incorrect value for last_msg.msg.soln_meta_dep_a.hdop, "
                  "expected 31133, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.hdop);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.last_used_gnss_pos_tow == 610745181,
        "incorrect value for "
        "last_msg.msg.soln_meta_dep_a.last_used_gnss_pos_tow, expected "
        "610745181, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.last_used_gnss_pos_tow);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.last_used_gnss_vel_tow == 782016851,
        "incorrect value for "
        "last_msg.msg.soln_meta_dep_a.last_used_gnss_vel_tow, expected "
        "782016851, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.last_used_gnss_vel_tow);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.n_sats == 238,
                  "incorrect value for last_msg.msg.soln_meta_dep_a.n_sats, "
                  "expected 238, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.n_sol_in == 118,
                  "incorrect value for last_msg.msg.soln_meta_dep_a.n_sol_in, "
                  "expected 118, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.n_sol_in);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.pdop == 57015,
                  "incorrect value for last_msg.msg.soln_meta_dep_a.pdop, "
                  "expected 57015, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.pdop);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[0].flags == 67,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[0].flags, "
        "expected 67, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[0].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[0].sensor_type == 253,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[0].sensor_type, "
                  "expected 253, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[0].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[1].flags == 200,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[1].flags, "
        "expected 200, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[1].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[1].sensor_type == 87,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[1].sensor_type, "
                  "expected 87, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[1].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[2].flags == 250,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[2].flags, "
        "expected 250, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[2].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[2].sensor_type == 39,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[2].sensor_type, "
                  "expected 39, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[2].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[3].flags == 242,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[3].flags, "
        "expected 242, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[3].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[3].sensor_type == 245,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[3].sensor_type, "
                  "expected 245, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[3].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[4].flags == 72,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[4].flags, "
        "expected 72, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[4].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[4].sensor_type == 228,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[4].sensor_type, "
                  "expected 228, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[4].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[5].flags == 222,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[5].flags, "
        "expected 222, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[5].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[5].sensor_type == 18,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[5].sensor_type, "
                  "expected 18, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[5].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[6].flags == 88,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[6].flags, "
        "expected 88, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[6].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[6].sensor_type == 11,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[6].sensor_type, "
                  "expected 11, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[6].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[7].flags == 218,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[7].flags, "
        "expected 218, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[7].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[7].sensor_type == 207,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[7].sensor_type, "
                  "expected 207, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[7].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[8].flags == 13,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[8].flags, "
        "expected 13, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[8].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[8].sensor_type == 231,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[8].sensor_type, "
                  "expected 231, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[8].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[9].flags == 224,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[9].flags, "
        "expected 224, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[9].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[9].sensor_type == 226,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[9].sensor_type, "
                  "expected 226, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[9].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[10].flags == 196,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[10].flags, "
        "expected 196, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[10].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[10].sensor_type == 22,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[10].sensor_type, "
                  "expected 22, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[10].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[11].flags == 242,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[11].flags, "
        "expected 242, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[11].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[11].sensor_type == 21,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[11].sensor_type, "
                  "expected 21, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[11].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[12].flags == 89,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[12].flags, "
        "expected 89, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[12].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[12].sensor_type == 12,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[12].sensor_type, "
                  "expected 12, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[12].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[13].flags == 219,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[13].flags, "
        "expected 219, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[13].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[13].sensor_type == 71,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[13].sensor_type, "
                  "expected 71, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[13].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[14].flags == 85,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[14].flags, "
        "expected 85, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[14].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[14].sensor_type == 182,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[14].sensor_type, "
                  "expected 182, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[14].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[15].flags == 204,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[15].flags, "
        "expected 204, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[15].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[15].sensor_type == 145,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[15].sensor_type, "
                  "expected 145, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[15].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[16].flags == 40,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[16].flags, "
        "expected 40, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[16].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[16].sensor_type == 146,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[16].sensor_type, "
                  "expected 146, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[16].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[17].flags == 51,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[17].flags, "
        "expected 51, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[17].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[17].sensor_type == 204,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[17].sensor_type, "
                  "expected 204, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[17].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[18].flags == 153,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[18].flags, "
        "expected 153, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[18].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[18].sensor_type == 21,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[18].sensor_type, "
                  "expected 21, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[18].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[19].flags == 44,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[19].flags, "
        "expected 44, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[19].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[19].sensor_type == 227,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[19].sensor_type, "
                  "expected 227, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[19].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[20].flags == 28,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[20].flags, "
        "expected 28, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[20].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[20].sensor_type == 15,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[20].sensor_type, "
                  "expected 15, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[20].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[21].flags == 39,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[21].flags, "
        "expected 39, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[21].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[21].sensor_type == 255,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[21].sensor_type, "
                  "expected 255, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[21].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[22].flags == 216,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[22].flags, "
        "expected 216, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[22].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[22].sensor_type == 205,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[22].sensor_type, "
                  "expected 205, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[22].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[23].flags == 190,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[23].flags, "
        "expected 190, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[23].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[23].sensor_type == 240,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[23].sensor_type, "
                  "expected 240, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[23].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[24].flags == 219,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[24].flags, "
        "expected 219, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[24].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[24].sensor_type == 93,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[24].sensor_type, "
                  "expected 93, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[24].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[25].flags == 42,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[25].flags, "
        "expected 42, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[25].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[25].sensor_type == 103,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[25].sensor_type, "
                  "expected 103, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[25].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[26].flags == 182,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[26].flags, "
        "expected 182, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[26].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[26].sensor_type == 41,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[26].sensor_type, "
                  "expected 41, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[26].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[27].flags == 222,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[27].flags, "
        "expected 222, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[27].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[27].sensor_type == 76,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[27].sensor_type, "
                  "expected 76, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[27].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[28].flags == 23,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[28].flags, "
        "expected 23, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[28].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[28].sensor_type == 17,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[28].sensor_type, "
                  "expected 17, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[28].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[29].flags == 31,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[29].flags, "
        "expected 31, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[29].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[29].sensor_type == 125,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[29].sensor_type, "
                  "expected 125, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[29].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[30].flags == 229,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[30].flags, "
        "expected 229, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[30].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[30].sensor_type == 18,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[30].sensor_type, "
                  "expected 18, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[30].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[31].flags == 47,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[31].flags, "
        "expected 47, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[31].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[31].sensor_type == 28,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[31].sensor_type, "
                  "expected 28, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[31].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[32].flags == 25,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[32].flags, "
        "expected 25, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[32].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[32].sensor_type == 214,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[32].sensor_type, "
                  "expected 214, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[32].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[33].flags == 84,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[33].flags, "
        "expected 84, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[33].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[33].sensor_type == 100,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[33].sensor_type, "
                  "expected 100, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[33].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[34].flags == 72,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[34].flags, "
        "expected 72, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[34].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[34].sensor_type == 106,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[34].sensor_type, "
                  "expected 106, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[34].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[35].flags == 10,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[35].flags, "
        "expected 10, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[35].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[35].sensor_type == 48,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[35].sensor_type, "
                  "expected 48, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[35].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[36].flags == 232,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[36].flags, "
        "expected 232, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[36].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[36].sensor_type == 222,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[36].sensor_type, "
                  "expected 222, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[36].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[37].flags == 73,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[37].flags, "
        "expected 73, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[37].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[37].sensor_type == 235,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[37].sensor_type, "
                  "expected 235, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[37].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[38].flags == 163,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[38].flags, "
        "expected 163, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[38].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[38].sensor_type == 109,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[38].sensor_type, "
                  "expected 109, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[38].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[39].flags == 152,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[39].flags, "
        "expected 152, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[39].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[39].sensor_type == 51,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[39].sensor_type, "
                  "expected 51, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[39].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[40].flags == 235,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[40].flags, "
        "expected 235, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[40].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[40].sensor_type == 133,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[40].sensor_type, "
                  "expected 133, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[40].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[41].flags == 70,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[41].flags, "
        "expected 70, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[41].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[41].sensor_type == 87,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[41].sensor_type, "
                  "expected 87, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[41].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[42].flags == 108,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[42].flags, "
        "expected 108, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[42].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[42].sensor_type == 2,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[42].sensor_type, "
                  "expected 2, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[42].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[43].flags == 101,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[43].flags, "
        "expected 101, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[43].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[43].sensor_type == 91,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[43].sensor_type, "
                  "expected 91, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[43].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[44].flags == 55,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[44].flags, "
        "expected 55, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[44].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[44].sensor_type == 200,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[44].sensor_type, "
                  "expected 200, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[44].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[45].flags == 156,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[45].flags, "
        "expected 156, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[45].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[45].sensor_type == 24,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[45].sensor_type, "
                  "expected 24, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[45].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[46].flags == 73,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[46].flags, "
        "expected 73, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[46].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[46].sensor_type == 233,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[46].sensor_type, "
                  "expected 233, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[46].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[47].flags == 66,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[47].flags, "
        "expected 66, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[47].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[47].sensor_type == 39,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[47].sensor_type, "
                  "expected 39, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[47].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[48].flags == 140,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[48].flags, "
        "expected 140, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[48].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[48].sensor_type == 97,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[48].sensor_type, "
                  "expected 97, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[48].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[49].flags == 227,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[49].flags, "
        "expected 227, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[49].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[49].sensor_type == 252,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[49].sensor_type, "
                  "expected 252, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[49].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[50].flags == 237,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[50].flags, "
        "expected 237, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[50].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[50].sensor_type == 230,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[50].sensor_type, "
                  "expected 230, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[50].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[51].flags == 241,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[51].flags, "
        "expected 241, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[51].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[51].sensor_type == 135,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[51].sensor_type, "
                  "expected 135, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[51].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[52].flags == 205,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[52].flags, "
        "expected 205, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[52].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[52].sensor_type == 245,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[52].sensor_type, "
                  "expected 245, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[52].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[53].flags == 0,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[53].flags, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[53].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[53].sensor_type == 70,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[53].sensor_type, "
                  "expected 70, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[53].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[54].flags == 188,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[54].flags, "
        "expected 188, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[54].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[54].sensor_type == 219,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[54].sensor_type, "
                  "expected 219, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[54].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[55].flags == 136,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[55].flags, "
        "expected 136, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[55].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[55].sensor_type == 107,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[55].sensor_type, "
                  "expected 107, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[55].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[56].flags == 58,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[56].flags, "
        "expected 58, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[56].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[56].sensor_type == 178,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[56].sensor_type, "
                  "expected 178, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[56].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[57].flags == 29,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[57].flags, "
        "expected 29, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[57].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[57].sensor_type == 1,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[57].sensor_type, "
                  "expected 1, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[57].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[58].flags == 213,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[58].flags, "
        "expected 213, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[58].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[58].sensor_type == 44,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[58].sensor_type, "
                  "expected 44, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[58].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[59].flags == 147,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[59].flags, "
        "expected 147, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[59].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[59].sensor_type == 225,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[59].sensor_type, "
                  "expected 225, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[59].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[60].flags == 96,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[60].flags, "
        "expected 96, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[60].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[60].sensor_type == 190,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[60].sensor_type, "
                  "expected 190, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[60].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[61].flags == 108,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[61].flags, "
        "expected 108, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[61].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[61].sensor_type == 192,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[61].sensor_type, "
                  "expected 192, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[61].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[62].flags == 15,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[62].flags, "
        "expected 15, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[62].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[62].sensor_type == 228,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[62].sensor_type, "
                  "expected 228, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[62].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[63].flags == 18,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[63].flags, "
        "expected 18, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[63].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[63].sensor_type == 203,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[63].sensor_type, "
                  "expected 203, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[63].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[64].flags == 222,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[64].flags, "
        "expected 222, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[64].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[64].sensor_type == 3,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[64].sensor_type, "
                  "expected 3, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[64].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[65].flags == 68,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[65].flags, "
        "expected 68, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[65].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[65].sensor_type == 180,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[65].sensor_type, "
                  "expected 180, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[65].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[66].flags == 229,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[66].flags, "
        "expected 229, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[66].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[66].sensor_type == 101,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[66].sensor_type, "
                  "expected 101, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[66].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[67].flags == 203,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[67].flags, "
        "expected 203, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[67].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[67].sensor_type == 223,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[67].sensor_type, "
                  "expected 223, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[67].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[68].flags == 164,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[68].flags, "
        "expected 164, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[68].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[68].sensor_type == 243,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[68].sensor_type, "
                  "expected 243, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[68].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[69].flags == 165,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[69].flags, "
        "expected 165, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[69].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[69].sensor_type == 92,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[69].sensor_type, "
                  "expected 92, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[69].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[70].flags == 159,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[70].flags, "
        "expected 159, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[70].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[70].sensor_type == 220,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[70].sensor_type, "
                  "expected 220, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[70].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[71].flags == 121,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[71].flags, "
        "expected 121, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[71].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[71].sensor_type == 174,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[71].sensor_type, "
                  "expected 174, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[71].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[72].flags == 167,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[72].flags, "
        "expected 167, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[72].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[72].sensor_type == 112,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[72].sensor_type, "
                  "expected 112, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[72].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[73].flags == 40,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[73].flags, "
        "expected 40, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[73].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[73].sensor_type == 240,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[73].sensor_type, "
                  "expected 240, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[73].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[74].flags == 3,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[74].flags, "
        "expected 3, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[74].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[74].sensor_type == 59,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[74].sensor_type, "
                  "expected 59, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[74].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[75].flags == 52,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[75].flags, "
        "expected 52, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[75].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[75].sensor_type == 230,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[75].sensor_type, "
                  "expected 230, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[75].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[76].flags == 148,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[76].flags, "
        "expected 148, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[76].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[76].sensor_type == 149,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[76].sensor_type, "
                  "expected 149, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[76].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[77].flags == 142,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[77].flags, "
        "expected 142, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[77].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[77].sensor_type == 218,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[77].sensor_type, "
                  "expected 218, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[77].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[78].flags == 109,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[78].flags, "
        "expected 109, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[78].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[78].sensor_type == 212,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[78].sensor_type, "
                  "expected 212, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[78].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[79].flags == 71,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[79].flags, "
        "expected 71, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[79].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[79].sensor_type == 176,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[79].sensor_type, "
                  "expected 176, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[79].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[80].flags == 172,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[80].flags, "
        "expected 172, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[80].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[80].sensor_type == 179,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[80].sensor_type, "
                  "expected 179, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[80].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[81].flags == 1,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[81].flags, "
        "expected 1, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[81].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[81].sensor_type == 77,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[81].sensor_type, "
                  "expected 77, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[81].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[82].flags == 70,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[82].flags, "
        "expected 70, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[82].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[82].sensor_type == 193,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[82].sensor_type, "
                  "expected 193, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[82].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[83].flags == 149,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[83].flags, "
        "expected 149, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[83].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[83].sensor_type == 147,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[83].sensor_type, "
                  "expected 147, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[83].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[84].flags == 144,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[84].flags, "
        "expected 144, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[84].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[84].sensor_type == 23,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[84].sensor_type, "
                  "expected 23, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[84].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[85].flags == 239,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[85].flags, "
        "expected 239, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[85].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[85].sensor_type == 148,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[85].sensor_type, "
                  "expected 148, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[85].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[86].flags == 186,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[86].flags, "
        "expected 186, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[86].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[86].sensor_type == 195,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[86].sensor_type, "
                  "expected 195, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[86].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[87].flags == 30,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[87].flags, "
        "expected 30, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[87].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[87].sensor_type == 86,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[87].sensor_type, "
                  "expected 86, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[87].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[88].flags == 143,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[88].flags, "
        "expected 143, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[88].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[88].sensor_type == 34,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[88].sensor_type, "
                  "expected 34, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[88].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[89].flags == 207,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[89].flags, "
        "expected 207, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[89].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[89].sensor_type == 156,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[89].sensor_type, "
                  "expected 156, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[89].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[90].flags == 55,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[90].flags, "
        "expected 55, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[90].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[90].sensor_type == 63,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[90].sensor_type, "
                  "expected 63, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[90].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[91].flags == 255,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[91].flags, "
        "expected 255, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[91].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[91].sensor_type == 117,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[91].sensor_type, "
                  "expected 117, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[91].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[92].flags == 222,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[92].flags, "
        "expected 222, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[92].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[92].sensor_type == 222,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[92].sensor_type, "
                  "expected 222, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[92].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[93].flags == 145,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[93].flags, "
        "expected 145, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[93].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[93].sensor_type == 219,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[93].sensor_type, "
                  "expected 219, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[93].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[94].flags == 191,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[94].flags, "
        "expected 191, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[94].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[94].sensor_type == 224,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[94].sensor_type, "
                  "expected 224, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[94].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[95].flags == 109,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[95].flags, "
        "expected 109, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[95].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[95].sensor_type == 210,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[95].sensor_type, "
                  "expected 210, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[95].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[96].flags == 153,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[96].flags, "
        "expected 153, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[96].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[96].sensor_type == 86,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[96].sensor_type, "
                  "expected 86, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[96].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[97].flags == 32,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[97].flags, "
        "expected 32, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[97].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[97].sensor_type == 21,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[97].sensor_type, "
                  "expected 21, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[97].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[98].flags == 10,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[98].flags, "
        "expected 10, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[98].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[98].sensor_type == 226,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[98].sensor_type, "
                  "expected 226, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[98].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[99].flags == 63,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[99].flags, "
        "expected 63, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[99].flags);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.sol_in[99].sensor_type == 60,
                  "incorrect value for "
                  "last_msg.msg.soln_meta_dep_a.sol_in[99].sensor_type, "
                  "expected 60, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[99].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[100].flags == 236,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[100].flags, "
        "expected 236, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[100].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[100].sensor_type == 106,
        "incorrect value for "
        "last_msg.msg.soln_meta_dep_a.sol_in[100].sensor_type, expected 106, "
        "is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[100].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[101].flags == 96,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[101].flags, "
        "expected 96, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[101].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[101].sensor_type == 93,
        "incorrect value for "
        "last_msg.msg.soln_meta_dep_a.sol_in[101].sensor_type, expected 93, is "
        "%" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[101].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[102].flags == 163,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[102].flags, "
        "expected 163, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[102].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[102].sensor_type == 30,
        "incorrect value for "
        "last_msg.msg.soln_meta_dep_a.sol_in[102].sensor_type, expected 30, is "
        "%" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[102].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[103].flags == 238,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[103].flags, "
        "expected 238, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[103].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[103].sensor_type == 106,
        "incorrect value for "
        "last_msg.msg.soln_meta_dep_a.sol_in[103].sensor_type, expected 106, "
        "is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[103].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[104].flags == 133,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[104].flags, "
        "expected 133, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[104].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[104].sensor_type == 147,
        "incorrect value for "
        "last_msg.msg.soln_meta_dep_a.sol_in[104].sensor_type, expected 147, "
        "is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[104].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[105].flags == 107,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[105].flags, "
        "expected 107, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[105].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[105].sensor_type == 132,
        "incorrect value for "
        "last_msg.msg.soln_meta_dep_a.sol_in[105].sensor_type, expected 132, "
        "is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[105].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[106].flags == 214,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[106].flags, "
        "expected 214, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[106].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[106].sensor_type == 152,
        "incorrect value for "
        "last_msg.msg.soln_meta_dep_a.sol_in[106].sensor_type, expected 152, "
        "is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[106].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[107].flags == 185,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[107].flags, "
        "expected 185, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[107].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[107].sensor_type == 221,
        "incorrect value for "
        "last_msg.msg.soln_meta_dep_a.sol_in[107].sensor_type, expected 221, "
        "is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[107].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[108].flags == 21,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[108].flags, "
        "expected 21, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[108].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[108].sensor_type == 202,
        "incorrect value for "
        "last_msg.msg.soln_meta_dep_a.sol_in[108].sensor_type, expected 202, "
        "is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[108].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[109].flags == 51,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[109].flags, "
        "expected 51, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[109].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[109].sensor_type == 252,
        "incorrect value for "
        "last_msg.msg.soln_meta_dep_a.sol_in[109].sensor_type, expected 252, "
        "is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[109].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[110].flags == 59,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[110].flags, "
        "expected 59, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[110].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[110].sensor_type == 130,
        "incorrect value for "
        "last_msg.msg.soln_meta_dep_a.sol_in[110].sensor_type, expected 130, "
        "is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[110].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[111].flags == 202,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[111].flags, "
        "expected 202, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[111].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[111].sensor_type == 166,
        "incorrect value for "
        "last_msg.msg.soln_meta_dep_a.sol_in[111].sensor_type, expected 166, "
        "is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[111].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[112].flags == 170,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[112].flags, "
        "expected 170, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[112].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[112].sensor_type == 127,
        "incorrect value for "
        "last_msg.msg.soln_meta_dep_a.sol_in[112].sensor_type, expected 127, "
        "is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[112].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[113].flags == 193,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[113].flags, "
        "expected 193, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[113].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[113].sensor_type == 58,
        "incorrect value for "
        "last_msg.msg.soln_meta_dep_a.sol_in[113].sensor_type, expected 58, is "
        "%" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[113].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[114].flags == 125,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[114].flags, "
        "expected 125, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[114].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[114].sensor_type == 215,
        "incorrect value for "
        "last_msg.msg.soln_meta_dep_a.sol_in[114].sensor_type, expected 215, "
        "is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[114].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[115].flags == 58,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[115].flags, "
        "expected 58, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[115].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[115].sensor_type == 22,
        "incorrect value for "
        "last_msg.msg.soln_meta_dep_a.sol_in[115].sensor_type, expected 22, is "
        "%" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[115].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[116].flags == 47,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[116].flags, "
        "expected 47, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[116].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[116].sensor_type == 135,
        "incorrect value for "
        "last_msg.msg.soln_meta_dep_a.sol_in[116].sensor_type, expected 135, "
        "is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[116].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[117].flags == 142,
        "incorrect value for last_msg.msg.soln_meta_dep_a.sol_in[117].flags, "
        "expected 142, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[117].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta_dep_a.sol_in[117].sensor_type == 88,
        "incorrect value for "
        "last_msg.msg.soln_meta_dep_a.sol_in[117].sensor_type, expected 88, is "
        "%" PRId64,
        (int64_t)last_msg.msg.soln_meta_dep_a.sol_in[117].sensor_type);

    ck_assert_msg(last_msg.msg.soln_meta_dep_a.vdop == 41989,
                  "incorrect value for last_msg.msg.soln_meta_dep_a.vdop, "
                  "expected 41989, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta_dep_a.vdop);
  }
}
END_TEST

Suite *auto_check_sbp_solution_meta_MsgSolnMetaDepA_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_solution_meta_MsgSolnMetaDepA");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_solution_meta_MsgSolnMetaDepA");
  tcase_add_test(tc_acq, test_auto_check_sbp_solution_meta_MsgSolnMetaDepA);
  suite_add_tcase(s, tc_acq);
  return s;
}