/*
 * Copyright (C) 2021 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swift-nav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef LIBSBP_V4_API_H
#define LIBSBP_V4_API_H

#include <libsbp/v4/sbp_msg.h>
#include <libsbp/sbp_msg_type.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*sbp_decoded_callback_t)(u16 sender_id, sbp_msg_type_t msg_type, const sbp_msg_t *msg, void *context);

SBP_EXPORT s8 sbp_callback_register(sbp_state_t* s, sbp_msg_type_t msg_type, sbp_decoded_callback_t cb, void* context,
                         sbp_msg_callbacks_node_t *node);
SBP_EXPORT s8 sbp_all_message_callback_register(sbp_state_t *s, sbp_decoded_callback_t cb, void* context,
                                 sbp_msg_callbacks_node_t *node);
SBP_EXPORT s8 sbp_message_process(sbp_state_t *s, u16 sender_id, sbp_msg_type_t msg_type, const sbp_msg_t *msg);
SBP_EXPORT s8 sbp_message_send(sbp_state_t *s, sbp_msg_type_t msg_type, u16 sender_id, const sbp_msg_t *msg,
                    sbp_write_fn_t write);

#ifdef __cplusplus
}
#endif

#endif /* LIBSBP_V4_API_H */
