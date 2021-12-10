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

((*- for p in packages *))
#include <libsbp/v4/(((p.name))).h>
((*- endfor *))
#include <libsbp/v4/sbp_msg.h>
#include <libsbp/sbp_msg_type.h>

namespace sbp {

/**
 * Type traits containing meta-information for each SBP message type.
 *
 * These are only meant to be used by the C++ library at compile time.
 * These are automatically generated, DO NOT EDIT.
 */
template<typename>
struct MessageTraits;

((* for m in real_messages *))
template<>
struct MessageTraits<(((m.type_name)))> {
  static constexpr sbp_msg_type_t id = (((m.v4_msg_type)));
  static const (((m.type_name)))& get(const sbp_msg_t &msg) {
    return msg.(((m.union_member_name)));
  }
  static (((m.type_name)))& get(sbp_msg_t &msg) {
    return msg.(((m.union_member_name)));
  }
  static void to_sbp_msg(const (((m.type_name)))& msg, sbp_msg_t *sbp_msg) {
    sbp_msg->(((m.union_member_name))) = msg;
  }
  static sbp_msg_t to_sbp_msg(const (((m.type_name)))& msg) {
    sbp_msg_t sbp_msg;
    sbp_msg.(((m.union_member_name))) = msg;
    return sbp_msg;
  }
  static s8 send(sbp_state_t *state, u16 sender_id, const (((m.type_name))) &msg, sbp_write_fn_t write) {
    return (((m.send_fn)))(state, sender_id, &msg, write);
  }
((*- if m.gnss_type_name *))
  static (((m.gnss_type_name))) to_gnss(const (((m.type_name)))& msg){
    sbp_msg_t sbp_msg;
    sbp_msg.(((m.union_member_name))) = msg;
    return sbp_msg.(((m.return_union_member_name)));
  }
  static (((m.type_name))) to_non_gnss(const (((m.type_name)))& msg) {
    return msg;
  }
((* endif *))
((*- if m.non_gnss_type_name *))
  static (((m.type_name))) to_gnss(const (((m.type_name)))& msg) {
    return msg;
  }
  static (((m.non_gnss_type_name))) to_non_gnss(const (((m.type_name)))& msg){
    sbp_msg_t sbp_msg;
    sbp_msg.(((m.union_member_name))) = msg;
    return sbp_msg.(((m.return_union_member_name)));
  }
((* endif *))
  static s8 encode(uint8_t *buf, uint8_t len, uint8_t *n_written, const (((m.type_name))) &msg){
    return (((m.public_encode_fn)))(buf, len, n_written, &msg);
  }
  static s8 decode(const uint8_t *buf, uint8_t len, uint8_t *n_read, (((m.type_name))) *msg){
    return (((m.public_decode_fn)))(buf, len, n_read, msg);
  }
  static size_t encoded_len(const (((m.type_name))) &msg) {
    return (((m.encoded_len_fn)))(&msg);
  }
};
((* endfor *))

} // namespace sbp

#endif //LIBSBP_CPP_MESSAGE_TRAITS_H

