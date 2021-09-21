/**
 * Copyright (C) 2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

#include <gtest/gtest.h>

#include <libsbp/cpp/stdio.h>
#include <libsbp/cpp/message_handler.h>
#include <libsbp/v4/observation/MSG_OBS.h>

namespace {

struct SbpParams {
  u16 sender_id;
  sbp_msg_type_t msg_type;
  sbp_msg_t sbp_msg;
};

  /**
 * `GnssHandler` is the parent class that all diagnostic handlers
 * analyzing GNSS-related metrics will inherit from. It defines a common
 * interface that the handlers must all adhere to, and also implements common
 * functionality.
 */
class MsgObsHandler : public sbp::MessageHandler<sbp_msg_obs_t> {
  public:
    MsgObsHandler(sbp::State *state) : sbp::MessageHandler<sbp_msg_obs_t>(state), sbp_params_() {}

    SbpParams get_sbp_params() const {
      return sbp_params_;
    }

protected:
    void handle_sbp_msg(uint16_t sender_id, const sbp_msg_obs_t &msg) override {
      sbp_params_.sender_id = sender_id;
      sbp_params_.msg_type = SbpMsgObs;
      sbp_params_.sbp_msg.obs = msg;
    }

    SbpParams sbp_params_;
};

class SbpStdioTest : public ::testing::Test {
protected:
  int num_entries_in_file(const std::string &input_file) {
    sbp::SbpFileReader reader = sbp::SbpFileReader(input_file.data());
    sbp::State state;
    state.set_reader(&reader);
    MsgObsHandler handler(&state);

    int count = 0;
    while (true) {
      s8 status = state.process();
      if (status < SBP_OK) {
        break;
      }
      if (status == SBP_OK_CALLBACK_EXECUTED) {
        count++;
      }
    }
    return count;
  }

  void write_to_file(const std::string &input_file, const std::string &output_file) {
    sbp::SbpFileReader reader = sbp::SbpFileReader(input_file.data());
    sbp::SbpFileWriter writer = sbp::SbpFileWriter(output_file.data());
    sbp::State state;
    state.set_reader(&reader);
    state.set_writer(&writer);
    MsgObsHandler handler(&state);

    while (true) {
      s8 status = state.process();
      if (status < SBP_OK) {
        break;
      }
      if (status == SBP_OK_CALLBACK_EXECUTED) {
        SbpParams sbp_params = handler.get_sbp_params();
        state.send_message(sbp_params.sender_id, sbp_params.msg_type, sbp_params.sbp_msg);
        state.send_message(sbp_params.sender_id, sbp_params.msg_type, sbp_params.sbp_msg);
        state.send_message(sbp_params.sender_id, sbp_params.msg_type, sbp_params.sbp_msg);
      }
    }
  }
};

TEST_F(SbpStdioTest, ReadsSbpFiles) {
  EXPECT_EQ(num_entries_in_file("msg_obs.sbp"), 3);
}

TEST_F(SbpStdioTest, WritesToSbpFiles) {
  write_to_file("msg_obs.sbp", "msg_obs_output.sbp");
  EXPECT_EQ(num_entries_in_file("msg_obs_output.sbp"), 9);
}

} // namespace
