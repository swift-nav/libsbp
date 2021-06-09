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

/*****************************************************************************
 * Automatically generated with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_CPP_MESSAGE_TRAITS_H
#define LIBSBP_CPP_MESSAGE_TRAITS_H

#include <libsbp/sbp.h>
#include <libsbp/new/sbp_msg.h>
((*- for i in includes *))
#include <libsbp/new/(((i))).h>
((*- endfor *))

namespace sbp {

/**
 * Type traits containing meta-information for each SBP message type.
 *
 * These are only meant to be used by the C++ library at compile time.
 * These are automatically generated, DO NOT EDIT.
 */
template<typename>
struct MessageTraits;

((* for m in msgs *))
((*- if m.is_real_message *))
((*- set msg_type = m.identifier|convert_unpacked *))
((*- set member_name = m.identifier|convert_unpacked_union *))
template<>
struct MessageTraits<(((msg_type)))> {
  static constexpr u16 id = SBP_(((m.identifier)));
  static const (((msg_type)))& get(const sbp_msg_t &msg) {
    return msg.(((member_name)));
  }
  static (((msg_type)))& get(sbp_msg_t &msg) {
    return msg.(((member_name)));
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const (((msg_type))) &msg, s32 (*write)(u8 *, u32, void *)) {
    return sbp_send_(((msg_type)))(state, sender_id, &msg, write);
  }
};
((* endif *))
((* endfor *))


} // namespace sbp

#endif //LIBSBP_CPP_MESSAGE_TRAITS_H

