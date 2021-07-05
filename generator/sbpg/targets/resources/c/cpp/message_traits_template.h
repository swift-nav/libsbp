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
#include <libsbp/v4/sbp_msg.h>
((*- for i in includes *))
#include <libsbp/v4/(((i)))>
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
template<>
struct MessageTraits<(((m.type_name)))> {
  static constexpr sbp_msg_type_t id = (((m.v4_msg_type)));
  static const (((m.type_name)))& get(const sbp_msg_t &msg) {
    return msg.(((m.union_member_name)));
  }
  static (((m.type_name)))& get(sbp_msg_t &msg) {
    return msg.(((m.union_member_name)));
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const (((m.type_name))) &msg, sbp_write_fn_t write) {
    return (((m.send_fn)))(state, sender_id, &msg, write);
  }
};
((* endif *))
((* endfor *))


} // namespace sbp

#endif //LIBSBP_CPP_MESSAGE_TRAITS_H

