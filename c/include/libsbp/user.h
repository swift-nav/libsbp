/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
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
 * Automatically generated from yaml/swiftnav/sbp/user.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup user User
 *
 *  * Messages reserved for use by the user.
 * \{ */

#ifndef LIBSBP_PACKED_USER_MESSAGES_H
#define LIBSBP_PACKED_USER_MESSAGES_H

#ifdef SBP_DISABLE_PACKED_HEADERS
#error "Packed SBP headers are disabled"
#endif

#include <libsbp/common.h>

SBP_PACK_START


/** User data
 *
 * This message can contain any application specific user data up to a
 * maximum length of 255 bytes per message.
 */
#define SBP_MSG_USER_DATA 0x0800
typedef struct SBP_ATTR_PACKED {
  
  /** 
   * User data payload 
   */
  u8 contents[0];
  
} msg_user_data_t;


/** \} */

SBP_PACK_END

#endif /* LIBSBP_USER_MESSAGES_H */
