/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
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
 * Messages reserved for use by the user.
 * \{ */

#ifndef LIBSBP_LEGACY_USER_MESSAGES_H
#define LIBSBP_LEGACY_USER_MESSAGES_H

#include <libsbp/common.h>

SBP_MESSAGE(
    "The legacy libsbp API has been deprecated. This file and all symbols "
    "contained will "
    "be removed in version 6. You should immediately switch over to the modern "
    "libsbp API.")

#include <libsbp/user_macros.h>

SBP_PACK_START

/** User data
 *
 * This message can contain any application specific user data up to a maximum
 * length of 255 bytes per message.
 */

typedef struct SBP_ATTR_PACKED SBP_DEPRECATED {
  u8 contents[0]; /**< User data payload */
} msg_user_data_t;

/** \} */

SBP_PACK_END

#endif /* LIBSBP_LEGACY_USER_MESSAGES_H */