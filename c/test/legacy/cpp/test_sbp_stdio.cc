/**
 * Copyright (C) 2020-2021 Swift Navigation Inc.
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

#include <libsbp/legacy/cpp/payload_handler.h>
#include <libsbp/legacy/cpp/sbp_stdio.h>

namespace {

struct SbpHeaderParams {
  uint16_t sender_id;
  uint16_t msg_type;
  uint8_t payload_len;
  msg_obs_t payload;
};

class MsgObsHandler : private sbp::PayloadHandler<msg_obs_t> {
 public:
  explicit MsgObsHandler(sbp::State *state)
      : sbp::PayloadHandler<msg_obs_t>(state), state_(state) {}

  void handle_sbp_msg(uint16_t sender_id, uint8_t message_length,
                      const msg_obs_t &msg) override {
    header_params_.sender_id = sender_id;
    header_params_.msg_type = SBP_MSG_OBS;
    header_params_.payload_len = message_length;
    header_params_.payload = msg;
  }

  void write_message() const {
    state_->send_message(
        header_params_.msg_type, header_params_.sender_id,
        header_params_.payload_len,
        // NOLINTNEXTLINE
        reinterpret_cast<const uint8_t *>(&header_params_.payload));
  }

  SbpHeaderParams get_header_params() { return header_params_; }

 private:
  SbpHeaderParams header_params_;
  sbp::State *state_;
};

class SbpStdioTest : public ::testing::Test {
 protected:
  static int num_entries_in_file(const std::string &input_file) {
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

  static void write_to_file(const std::string &input_file,
                            const std::string &output_file) {
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
        handler.write_message();
        handler.write_message();
        handler.write_message();
      }
    }
  }
};

TEST_F(SbpStdioTest, ReadsSbpFiles) {
  EXPECT_EQ(num_entries_in_file("gnss_data.sbp"), 3);
}

TEST_F(SbpStdioTest, WritesToSbpFiles) {
  write_to_file("gnss_data.sbp", "gnss_data_output.sbp");
  EXPECT_EQ(num_entries_in_file("gnss_data_output.sbp"), 9);
}

}  // namespace
