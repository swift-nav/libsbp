/**
 * Copyright (C) 2019-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef SBP_CPP_STATE_H
#define SBP_CPP_STATE_H

#include <libsbp/sbp.h>
#include <libsbp/cpp/message_traits.h>

namespace sbp {

class IReader {
 public:
  virtual ~IReader() = default;

  virtual s32 read(u8 *buffer, u32 buffer_length) = 0;
};

class IWriter {
 public:
  virtual ~IWriter() = default;

  virtual s32 write(const u8 *buffer, u32 buffer_length) = 0;
};

class State {
 private:
  sbp_state_t state_;
  IReader *reader_;
  IWriter *writer_;

  State(const State&) = delete;
  
  State& operator=(const State&) = delete;

  static s32 read_func(u8 *buff, u32 n, void *ctx) {
    State *instance = static_cast<State *>(ctx);
    return instance->reader_->read(buff, n);
  }

  static s32 write_func(u8 *buff, u32 n, void *ctx) {
    State *instance = static_cast<State *>(ctx);
    return instance->writer_->write(buff, n);
  }

 public:
  State() : state_(), reader_(nullptr), writer_(nullptr) {
    sbp_state_init(&state_);
    sbp_state_set_io_context(&state_, this);
  }

  explicit State(IReader *reader, IWriter *writer) : State() {
    reader_ = reader;
    writer_ = writer;
  }

  virtual ~State() = default;

  sbp_state_t *get_state() { return &state_; }

  void set_reader(IReader *reader) { reader_ = reader; }

  void set_writer(IWriter *writer) { writer_ = writer; }

  s8 process() {
    return sbp_process(&state_, &read_func);
  }

  s8 send_message(u16 msg_type, u16 sender_id, u8 length, const u8 payload[]) {
    // NOLINTNEXTLINE
    return sbp_payload_send(&state_, msg_type, sender_id, length, const_cast<u8 *>(payload), &write_func);
  }

  s8 process_payload(u16 sender_id, u16 msg_type, u8 msg_length, const u8 payload[]) {
    // NOLINTNEXTLINE
    return sbp_payload_process(&state_, sender_id, msg_type, msg_length, const_cast<u8 *>(payload));
  }

  s8 process_message(u16 sender_id, sbp_msg_type_t msg_type, const sbp_msg_t *msg) {
    return sbp_message_process(&state_, sender_id, msg_type, msg);
  }

  template<typename T>
  s8 send_message(u16 sender_id, const T &msg) {
    return sbp::MessageTraits<T>::send(&state_, sender_id, msg, &write_func);
  }

  s8 send_message(u16 sender_id, sbp_msg_type_t msg_type, const sbp_msg_t &msg) {
    return sbp_message_send(&state_, msg_type, sender_id, &msg, &write_func);
  }
};

} // namespace sbp

#endif //SBP_CPP_STATE_H
