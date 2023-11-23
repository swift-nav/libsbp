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

#ifndef SBP_LEGACY_CPP_LEGACY_STATE_H
#define SBP_LEGACY_CPP_LEGACY_STATE_H

#include <libsbp/cpp/state.h>

SBP_MESSAGE(
  "The legacy libsbp API has been deprecated. This file and all symbols contained will "
  "be removed in version 6. You should immediately switch over to the modern libsbp API.")

namespace sbp {

class SBP_DEPRECATED LegacyState : public State {
public:
  using State::State;

  SBP_DEPRECATED s8 send_message(u16 msg_type, u16 sender_id, u8 length, const u8 payload[]) {
    // NOLINTNEXTLINE
    return sbp_payload_send(get_state(), msg_type, sender_id, length,
                            const_cast<u8 *>(payload), &State::write_func);
  }

  SBP_DEPRECATED s8 process_payload(u16 sender_id, u16 msg_type, u8 msg_length,
                     const u8 payload[]) {
    // NOLINTNEXTLINE
    return sbp_payload_process(get_state(), sender_id, msg_type, msg_length,
                               const_cast<u8 *>(payload));
  }
};

}  // namespace sbp

#endif
