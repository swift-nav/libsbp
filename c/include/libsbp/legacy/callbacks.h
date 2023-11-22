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

#ifndef LIBSBP_SBP_CALLBACKS_H
#define LIBSBP_SBP_CALLBACKS_H

#include <libsbp/common.h>

/** SBP callback function prototype definitions. */
typedef void (*sbp_msg_callback_t)(u16 sender_id, u8 len, u8 msg[], void *context);
typedef void (*sbp_frame_callback_t)(u16 sender_id, u16 msg_type,
                                     u8 payload_len, u8 payload[],
                                     u16 frame_len, u8 frame[], void *context);

#endif

