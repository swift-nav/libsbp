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

#ifndef LIBSBP_LEGACY_API_H
#define LIBSBP_LEGACY_API_H

#include <libsbp/common.h>

extern "C" {

struct sbp_state;
typedef struct sbp_state sbp_state_t;
struct sbp_msg_callbacks_node;
typedef struct sbp_msg_callbacks_node sbp_msg_callbacks_node_t;

/** SBP callback function prototype definitions. */
typedef void (*sbp_msg_callback_t)(u16 sender_id, u8 len, u8 msg[], void *context);
typedef void (*sbp_frame_callback_t)(u16 sender_id, u16 msg_type,
                                     u8 payload_len, u8 payload[],
                                     u16 frame_len, u8 frame[], void *context);

s8 sbp_payload_callback_register(sbp_state_t* s, u16 msg_type, sbp_msg_callback_t cb, void* context,
                         sbp_msg_callbacks_node_t *node);
s8 sbp_frame_callback_register(sbp_state_t* s, u16 msg_type,
                               sbp_frame_callback_t cb, void* context,
                               sbp_msg_callbacks_node_t *node);
s8 sbp_all_payload_callback_register(sbp_state_t *s, sbp_frame_callback_t cb,
                                 void *context, sbp_msg_callbacks_node_t *node);

s8 sbp_payload_process(sbp_state_t *s, u16 sender_id, u16 msg_type, u8 msg_len,
    u8 payload[]);
s8 sbp_payload_send(sbp_state_t *s, u16 msg_type, u16 sender_id, u8 len, u8 *payload,
                    s32 (*write)(u8 *buff, u32 n, void* context));

#ifdef __cplusplus
}
#endif

#endif /* LIBSBP_LEGACY_API_H */

