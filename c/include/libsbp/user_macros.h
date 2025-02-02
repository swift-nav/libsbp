/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/user.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_USER_MACROS_H
#define LIBSBP_USER_MACROS_H

/**
 * The maximum number of items that can be stored in
 * sbp_msg_user_data_t::contents before the maximum SBP message size is exceeded
 */
#define SBP_MSG_USER_DATA_CONTENTS_MAX 255u

/**
 * Encoded length of sbp_msg_user_data_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_user_data_encoded_len to determine the actual size of an instance
 * of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_USER_DATA_ENCODED_OVERHEAD 0u

#endif /* LIBSBP_USER_MACROS_H */
