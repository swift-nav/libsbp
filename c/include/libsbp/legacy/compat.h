/*
 * Copyright (C) 2011-2021 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swift-nav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef LIBSBP_LEGACY_COMPAT_H
#define LIBSBP_LEGACY_COMPAT_H

#include <libsbp/common.h>
#include <libsbp/legacy/api.h>


#ifdef __cplusplus
extern "C" {
#endif 

SBP_DEPRECATED
static inline s8 sbp_register_callback(sbp_state_t* s, u16 msg_type, sbp_msg_callback_t cb, void* context, sbp_msg_callbacks_node_t *node)
{
  return sbp_payload_callback_register(s, msg_type, cb, context, node);
}

SBP_DEPRECATED
static inline s8 sbp_register_frame_callback(sbp_state_t* s, u16 msg_type, sbp_frame_callback_t cb, void* context, sbp_msg_callbacks_node_t *node)
{
  return sbp_frame_callback_register(s, msg_type, cb, context, node);
}

SBP_DEPRECATED
static inline s8 sbp_register_all_msg_callback(sbp_state_t* s, sbp_frame_callback_t cb, void* context, sbp_msg_callbacks_node_t *node)
{
  return sbp_all_payload_callback_register(s, cb, context, node);
}

SBP_DEPRECATED
static inline s8 sbp_process_frame(sbp_state_t *s, u16 sender_id, u16 msg_type, u8 payload_len, u8 payload[], u16 frame_len, u8 frame[], u8 cb_mask)
{
  return sbp_frame_process(s, sender_id, msg_type, payload_len, payload, frame_len, frame, cb_mask);
}

SBP_DEPRECATED
static inline s8 sbp_process_payload(sbp_state_t *s, u16 sender_id, u16 msg_type, u8 msg_len, u8 payload[])
{
  return sbp_payload_process(s, sender_id, msg_type, msg_len, payload);
}

SBP_DEPRECATED
static inline s8 sbp_send_message(sbp_state_t *s, u16 msg_type, u16 sender_id, u8 len, u8 payload[], sbp_write_fn_t write)
{
  return sbp_payload_send(s, msg_type, sender_id, len, payload, write);
}

#ifdef __cplusplus
}
#endif 

#endif /* LIBSBP_LEGACY_COMPAT_H */
