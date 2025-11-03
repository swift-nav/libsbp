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
// spec/tests/yaml/swiftnav/sbp/settings/test_MsgSettingsReadByIndexResp.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/sbp.h>
#include <libsbp/settings.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_settings_MsgSettingsReadByIndexResp,
     test_auto_check_sbp_settings_MsgSettingsReadByIndexResp) {
  sbp_msg_callbacks_node_t n;

  // State of the SBP message parser.
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

    sbp_callback_register(&sbp_state, SbpMsgSettingsReadByIndexResp,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  167, 0,   246, 215, 78,  0,   0,   116, 101, 108, 101, 109,
        101, 116, 114, 121, 95,  114, 97,  100, 105, 111, 0,   99,  111,
        110, 102, 105, 103, 117, 114, 97,  116, 105, 111, 110, 95,  115,
        116, 114, 105, 110, 103, 0,   65,  84,  38,  70,  44,  65,  84,
        83,  49,  61,  49,  49,  53,  44,  65,  84,  83,  50,  61,  49,
        50,  56,  44,  65,  84,  83,  53,  61,  48,  44,  65,  84,  38,
        87,  44,  65,  84,  90,  0,   248, 233,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.settings_read_by_index_resp.index = 0;

    EXPECT_TRUE(sbp_msg_settings_read_by_index_resp_setting_add_section(
        &test_msg.settings_read_by_index_resp, "telemetry_radio"))
        << "Can't assign section 0";
    EXPECT_TRUE(sbp_msg_settings_read_by_index_resp_setting_add_section(
        &test_msg.settings_read_by_index_resp, "configuration_string"))
        << "Can't assign section 1";
    EXPECT_TRUE(sbp_msg_settings_read_by_index_resp_setting_add_section(
        &test_msg.settings_read_by_index_resp,
        "AT&F,ATS1=115,ATS2=128,ATS5=0,AT&W,ATZ"))
        << "Can't assign section 2";
    EXPECT_EQ(sbp_msg_settings_read_by_index_resp_setting_encoded_len(
                  &test_msg.settings_read_by_index_resp),
              76)
        << "String not encoded properly";

    sbp_message_send(&sbp_state, SbpMsgSettingsReadByIndexResp, 55286,
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
    EXPECT_EQ(last_msg.sender_id, 55286)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgSettingsReadByIndexResp, &last_msg.msg,
                              &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.settings_read_by_index_resp.index, 0)
        << "incorrect value for "
           "last_msg.msg.settings_read_by_index_resp.index, expected 0, is "
        << (int64_t)last_msg.msg.settings_read_by_index_resp.index;

    EXPECT_EQ(sbp_msg_settings_read_by_index_resp_setting_encoded_len(
                  &last_msg.msg.settings_read_by_index_resp),
              76)
        << "Invalid encoded len";
    EXPECT_EQ(strcmp(sbp_msg_settings_read_by_index_resp_setting_get_section(
                         &last_msg.msg.settings_read_by_index_resp, 0),
                     "telemetry_radio"),
              0)
        << "Section 0 not decoded properly";
    EXPECT_EQ(strcmp(sbp_msg_settings_read_by_index_resp_setting_get_section(
                         &last_msg.msg.settings_read_by_index_resp, 1),
                     "configuration_string"),
              0)
        << "Section 1 not decoded properly";
    EXPECT_EQ(strcmp(sbp_msg_settings_read_by_index_resp_setting_get_section(
                         &last_msg.msg.settings_read_by_index_resp, 2),
                     "AT&F,ATS1=115,ATS2=128,ATS5=0,AT&W,ATZ"),
              0)
        << "Section 2 not decoded properly";
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_callback_register(&sbp_state, SbpMsgSettingsReadByIndexResp,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  167, 0,  246, 215, 35,  1,   0,  117, 97, 114, 116, 95,  102, 116,
        100, 105, 0,  109, 111, 100, 101, 0,  83,  66, 80,  0,   101, 110, 117,
        109, 58,  83, 66,  80,  44,  78,  77, 69,  65, 0,   167, 243,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.settings_read_by_index_resp.index = 1;

    EXPECT_TRUE(sbp_msg_settings_read_by_index_resp_setting_add_section(
        &test_msg.settings_read_by_index_resp, "uart_ftdi"))
        << "Can't assign section 0";
    EXPECT_TRUE(sbp_msg_settings_read_by_index_resp_setting_add_section(
        &test_msg.settings_read_by_index_resp, "mode"))
        << "Can't assign section 1";
    EXPECT_TRUE(sbp_msg_settings_read_by_index_resp_setting_add_section(
        &test_msg.settings_read_by_index_resp, "SBP"))
        << "Can't assign section 2";
    EXPECT_TRUE(sbp_msg_settings_read_by_index_resp_setting_add_section(
        &test_msg.settings_read_by_index_resp, "enum:SBP,NMEA"))
        << "Can't assign section 3";
    EXPECT_EQ(sbp_msg_settings_read_by_index_resp_setting_encoded_len(
                  &test_msg.settings_read_by_index_resp),
              33)
        << "String not encoded properly";

    sbp_message_send(&sbp_state, SbpMsgSettingsReadByIndexResp, 55286,
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
    EXPECT_EQ(last_msg.sender_id, 55286)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgSettingsReadByIndexResp, &last_msg.msg,
                              &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.settings_read_by_index_resp.index, 1)
        << "incorrect value for "
           "last_msg.msg.settings_read_by_index_resp.index, expected 1, is "
        << (int64_t)last_msg.msg.settings_read_by_index_resp.index;

    EXPECT_EQ(sbp_msg_settings_read_by_index_resp_setting_encoded_len(
                  &last_msg.msg.settings_read_by_index_resp),
              33)
        << "Invalid encoded len";
    EXPECT_EQ(strcmp(sbp_msg_settings_read_by_index_resp_setting_get_section(
                         &last_msg.msg.settings_read_by_index_resp, 0),
                     "uart_ftdi"),
              0)
        << "Section 0 not decoded properly";
    EXPECT_EQ(strcmp(sbp_msg_settings_read_by_index_resp_setting_get_section(
                         &last_msg.msg.settings_read_by_index_resp, 1),
                     "mode"),
              0)
        << "Section 1 not decoded properly";
    EXPECT_EQ(strcmp(sbp_msg_settings_read_by_index_resp_setting_get_section(
                         &last_msg.msg.settings_read_by_index_resp, 2),
                     "SBP"),
              0)
        << "Section 2 not decoded properly";
    EXPECT_EQ(strcmp(sbp_msg_settings_read_by_index_resp_setting_get_section(
                         &last_msg.msg.settings_read_by_index_resp, 3),
                     "enum:SBP,NMEA"),
              0)
        << "Section 3 not decoded properly";
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_callback_register(&sbp_state, SbpMsgSettingsReadByIndexResp,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  167, 0,   246, 215, 35,  2,   0,   117, 97,  114,
        116, 95,  102, 116, 100, 105, 0,   115, 98,  112, 95,
        109, 101, 115, 115, 97,  103, 101, 95,  109, 97,  115,
        107, 0,   54,  53,  53,  51,  53,  0,   4,   56,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.settings_read_by_index_resp.index = 2;

    EXPECT_TRUE(sbp_msg_settings_read_by_index_resp_setting_add_section(
        &test_msg.settings_read_by_index_resp, "uart_ftdi"))
        << "Can't assign section 0";
    EXPECT_TRUE(sbp_msg_settings_read_by_index_resp_setting_add_section(
        &test_msg.settings_read_by_index_resp, "sbp_message_mask"))
        << "Can't assign section 1";
    EXPECT_TRUE(sbp_msg_settings_read_by_index_resp_setting_add_section(
        &test_msg.settings_read_by_index_resp, "65535"))
        << "Can't assign section 2";
    EXPECT_EQ(sbp_msg_settings_read_by_index_resp_setting_encoded_len(
                  &test_msg.settings_read_by_index_resp),
              33)
        << "String not encoded properly";

    sbp_message_send(&sbp_state, SbpMsgSettingsReadByIndexResp, 55286,
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
    EXPECT_EQ(last_msg.sender_id, 55286)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgSettingsReadByIndexResp, &last_msg.msg,
                              &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.settings_read_by_index_resp.index, 2)
        << "incorrect value for "
           "last_msg.msg.settings_read_by_index_resp.index, expected 2, is "
        << (int64_t)last_msg.msg.settings_read_by_index_resp.index;

    EXPECT_EQ(sbp_msg_settings_read_by_index_resp_setting_encoded_len(
                  &last_msg.msg.settings_read_by_index_resp),
              33)
        << "Invalid encoded len";
    EXPECT_EQ(strcmp(sbp_msg_settings_read_by_index_resp_setting_get_section(
                         &last_msg.msg.settings_read_by_index_resp, 0),
                     "uart_ftdi"),
              0)
        << "Section 0 not decoded properly";
    EXPECT_EQ(strcmp(sbp_msg_settings_read_by_index_resp_setting_get_section(
                         &last_msg.msg.settings_read_by_index_resp, 1),
                     "sbp_message_mask"),
              0)
        << "Section 1 not decoded properly";
    EXPECT_EQ(strcmp(sbp_msg_settings_read_by_index_resp_setting_get_section(
                         &last_msg.msg.settings_read_by_index_resp, 2),
                     "65535"),
              0)
        << "Section 2 not decoded properly";
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_callback_register(&sbp_state, SbpMsgSettingsReadByIndexResp,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  167, 0,   246, 215, 29, 3,  0,   117, 97,  114, 116, 95,
        102, 116, 100, 105, 0,   98, 97, 117, 100, 114, 97,  116, 101,
        0,   49,  48,  48,  48,  48, 48, 48,  0,   242, 146,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.settings_read_by_index_resp.index = 3;

    EXPECT_TRUE(sbp_msg_settings_read_by_index_resp_setting_add_section(
        &test_msg.settings_read_by_index_resp, "uart_ftdi"))
        << "Can't assign section 0";
    EXPECT_TRUE(sbp_msg_settings_read_by_index_resp_setting_add_section(
        &test_msg.settings_read_by_index_resp, "baudrate"))
        << "Can't assign section 1";
    EXPECT_TRUE(sbp_msg_settings_read_by_index_resp_setting_add_section(
        &test_msg.settings_read_by_index_resp, "1000000"))
        << "Can't assign section 2";
    EXPECT_EQ(sbp_msg_settings_read_by_index_resp_setting_encoded_len(
                  &test_msg.settings_read_by_index_resp),
              27)
        << "String not encoded properly";

    sbp_message_send(&sbp_state, SbpMsgSettingsReadByIndexResp, 55286,
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
    EXPECT_EQ(last_msg.sender_id, 55286)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgSettingsReadByIndexResp, &last_msg.msg,
                              &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.settings_read_by_index_resp.index, 3)
        << "incorrect value for "
           "last_msg.msg.settings_read_by_index_resp.index, expected 3, is "
        << (int64_t)last_msg.msg.settings_read_by_index_resp.index;

    EXPECT_EQ(sbp_msg_settings_read_by_index_resp_setting_encoded_len(
                  &last_msg.msg.settings_read_by_index_resp),
              27)
        << "Invalid encoded len";
    EXPECT_EQ(strcmp(sbp_msg_settings_read_by_index_resp_setting_get_section(
                         &last_msg.msg.settings_read_by_index_resp, 0),
                     "uart_ftdi"),
              0)
        << "Section 0 not decoded properly";
    EXPECT_EQ(strcmp(sbp_msg_settings_read_by_index_resp_setting_get_section(
                         &last_msg.msg.settings_read_by_index_resp, 1),
                     "baudrate"),
              0)
        << "Section 1 not decoded properly";
    EXPECT_EQ(strcmp(sbp_msg_settings_read_by_index_resp_setting_get_section(
                         &last_msg.msg.settings_read_by_index_resp, 2),
                     "1000000"),
              0)
        << "Section 2 not decoded properly";
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_callback_register(&sbp_state, SbpMsgSettingsReadByIndexResp,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  167, 0,  246, 215, 36,  4,   0,   117, 97, 114, 116, 95, 117, 97,
        114, 116, 97, 0,   109, 111, 100, 101, 0,   83, 66,  80,  0,  101, 110,
        117, 109, 58, 83,  66,  80,  44,  78,  77,  69, 65,  0,   22, 4,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.settings_read_by_index_resp.index = 4;

    EXPECT_TRUE(sbp_msg_settings_read_by_index_resp_setting_add_section(
        &test_msg.settings_read_by_index_resp, "uart_uarta"))
        << "Can't assign section 0";
    EXPECT_TRUE(sbp_msg_settings_read_by_index_resp_setting_add_section(
        &test_msg.settings_read_by_index_resp, "mode"))
        << "Can't assign section 1";
    EXPECT_TRUE(sbp_msg_settings_read_by_index_resp_setting_add_section(
        &test_msg.settings_read_by_index_resp, "SBP"))
        << "Can't assign section 2";
    EXPECT_TRUE(sbp_msg_settings_read_by_index_resp_setting_add_section(
        &test_msg.settings_read_by_index_resp, "enum:SBP,NMEA"))
        << "Can't assign section 3";
    EXPECT_EQ(sbp_msg_settings_read_by_index_resp_setting_encoded_len(
                  &test_msg.settings_read_by_index_resp),
              34)
        << "String not encoded properly";

    sbp_message_send(&sbp_state, SbpMsgSettingsReadByIndexResp, 55286,
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
    EXPECT_EQ(last_msg.sender_id, 55286)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgSettingsReadByIndexResp, &last_msg.msg,
                              &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.settings_read_by_index_resp.index, 4)
        << "incorrect value for "
           "last_msg.msg.settings_read_by_index_resp.index, expected 4, is "
        << (int64_t)last_msg.msg.settings_read_by_index_resp.index;

    EXPECT_EQ(sbp_msg_settings_read_by_index_resp_setting_encoded_len(
                  &last_msg.msg.settings_read_by_index_resp),
              34)
        << "Invalid encoded len";
    EXPECT_EQ(strcmp(sbp_msg_settings_read_by_index_resp_setting_get_section(
                         &last_msg.msg.settings_read_by_index_resp, 0),
                     "uart_uarta"),
              0)
        << "Section 0 not decoded properly";
    EXPECT_EQ(strcmp(sbp_msg_settings_read_by_index_resp_setting_get_section(
                         &last_msg.msg.settings_read_by_index_resp, 1),
                     "mode"),
              0)
        << "Section 1 not decoded properly";
    EXPECT_EQ(strcmp(sbp_msg_settings_read_by_index_resp_setting_get_section(
                         &last_msg.msg.settings_read_by_index_resp, 2),
                     "SBP"),
              0)
        << "Section 2 not decoded properly";
    EXPECT_EQ(strcmp(sbp_msg_settings_read_by_index_resp_setting_get_section(
                         &last_msg.msg.settings_read_by_index_resp, 3),
                     "enum:SBP,NMEA"),
              0)
        << "Section 3 not decoded properly";
  }
}

}  // namespace
