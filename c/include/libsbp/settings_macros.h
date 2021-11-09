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
 * Automatically generated from yaml/swiftnav/sbp/settings.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_SETTINGS_MACROS_H
#define LIBSBP_SETTINGS_MACROS_H

#define SBP_MSG_SETTINGS_SAVE 0x00A1
/**
 * Encoded length of sbp_msg_settings_save_t (V4 API) and
 * msg_settings_save_t (legacy API)
 */
#define SBP_MSG_SETTINGS_SAVE_ENCODED_LEN 0u

#define SBP_MSG_SETTINGS_WRITE 0x00A0
/**
 * The maximum number of items that can be stored in
 * sbp_msg_settings_write_t::setting (V4 API) or msg_settings_write_t::setting
 * (legacy API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_SETTINGS_WRITE_SETTING_MAX 255u

/**
 * Encoded length of sbp_msg_settings_write_t (V4 API) and
 * msg_settings_write_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_settings_write_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SETTINGS_WRITE_ENCODED_OVERHEAD 0u

#define SBP_MSG_SETTINGS_WRITE_RESP 0x00AF
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_MASK (0x3)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_SHIFT (0u)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_GET(flags)           \
  ((u8)(((flags) >> SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_SHIFT) & \
        SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_MASK))
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_SET(flags, val)                  \
  do {                                                                        \
    (flags) =                                                                 \
        (u8)((flags) | (((val) & (SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_MASK)) \
                        << (SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_SHIFT)));    \
  } while (0)

#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_ACCEPTED_VALUE_UPDATED (0)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_REJECTED_VALUE_UNPARSABLE_OR_OUT_OF_RANGE \
  (1)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_REJECTED_REQUESTED_SETTING_DOES_NOT_EXIST \
  (2)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_REJECTED_SETTING_NAME_COULD_NOT_BE_PARSED \
  (3)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_REJECTED_SETTING_IS_READ_ONLY (4)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_REJECTED_MODIFICATION_IS_TEMPORARILY_DISABLED \
  (5)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_REJECTED_UNSPECIFIED_ERROR (6)
/**
 * The maximum number of items that can be stored in
 * sbp_msg_settings_write_resp_t::setting (V4 API) or
 * msg_settings_write_resp_t::setting (legacy API) before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_SETTINGS_WRITE_RESP_SETTING_MAX 254u

/**
 * Encoded length of sbp_msg_settings_write_resp_t (V4 API) and
 * msg_settings_write_resp_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_settings_write_resp_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SETTINGS_WRITE_RESP_ENCODED_OVERHEAD 1u

#define SBP_MSG_SETTINGS_READ_REQ 0x00A4
/**
 * The maximum number of items that can be stored in
 * sbp_msg_settings_read_req_t::setting (V4 API) or
 * msg_settings_read_req_t::setting (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_SETTINGS_READ_REQ_SETTING_MAX 255u

/**
 * Encoded length of sbp_msg_settings_read_req_t (V4 API) and
 * msg_settings_read_req_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_settings_read_req_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SETTINGS_READ_REQ_ENCODED_OVERHEAD 0u

#define SBP_MSG_SETTINGS_READ_RESP 0x00A5
/**
 * The maximum number of items that can be stored in
 * sbp_msg_settings_read_resp_t::setting (V4 API) or
 * msg_settings_read_resp_t::setting (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_SETTINGS_READ_RESP_SETTING_MAX 255u

/**
 * Encoded length of sbp_msg_settings_read_resp_t (V4 API) and
 * msg_settings_read_resp_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_settings_read_resp_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SETTINGS_READ_RESP_ENCODED_OVERHEAD 0u

#define SBP_MSG_SETTINGS_READ_BY_INDEX_REQ 0x00A2
/**
 * Encoded length of sbp_msg_settings_read_by_index_req_t (V4 API) and
 * msg_settings_read_by_index_req_t (legacy API)
 */
#define SBP_MSG_SETTINGS_READ_BY_INDEX_REQ_ENCODED_LEN 2u

#define SBP_MSG_SETTINGS_READ_BY_INDEX_RESP 0x00A7
/**
 * The maximum number of items that can be stored in
 * sbp_msg_settings_read_by_index_resp_t::setting (V4 API) or
 * msg_settings_read_by_index_resp_t::setting (legacy API) before the maximum
 * SBP message size is exceeded
 */
#define SBP_MSG_SETTINGS_READ_BY_INDEX_RESP_SETTING_MAX 253u

/**
 * Encoded length of sbp_msg_settings_read_by_index_resp_t (V4 API) and
 * msg_settings_read_by_index_resp_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_settings_read_by_index_resp_encoded_len to determine the actual size
 * of an instance of this message. Users of the legacy API are required to track
 * the encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SETTINGS_READ_BY_INDEX_RESP_ENCODED_OVERHEAD 2u

#define SBP_MSG_SETTINGS_READ_BY_INDEX_DONE 0x00A6
/**
 * Encoded length of sbp_msg_settings_read_by_index_done_t (V4 API) and
 * msg_settings_read_by_index_done_t (legacy API)
 */
#define SBP_MSG_SETTINGS_READ_BY_INDEX_DONE_ENCODED_LEN 0u

#define SBP_MSG_SETTINGS_REGISTER 0x00AE
/**
 * The maximum number of items that can be stored in
 * sbp_msg_settings_register_t::setting (V4 API) or
 * msg_settings_register_t::setting (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_SETTINGS_REGISTER_SETTING_MAX 255u

/**
 * Encoded length of sbp_msg_settings_register_t (V4 API) and
 * msg_settings_register_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_settings_register_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SETTINGS_REGISTER_ENCODED_OVERHEAD 0u

#define SBP_MSG_SETTINGS_REGISTER_RESP 0x01AF
#define SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_MASK (0x3)
#define SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_SHIFT (0u)
#define SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_GET(flags)           \
  ((u8)(((flags) >> SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_SHIFT) & \
        SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_MASK))
#define SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_SET(flags, val)             \
  do {                                                                         \
    (flags) = (u8)(                                                            \
        (flags) | (((val) & (SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_MASK)) \
                   << (SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_SHIFT)));    \
  } while (0)

#define SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_ACCEPTED_REQUESTED_DEFAULT_VALUE_RETURNED \
  (0)
#define SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_ACCEPTED_SETTING_FOUND_IN_PERMANENT_STORAGE_VALUE_FROM_STORAGE_RETURNED \
  (1)
#define SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_REJECTED_SETTING_ALREADY_REGISTERED_VALUE_FROM_MEMORY_RETURNED \
  (2)
#define SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_REJECTED_MALFORMED_MESSAGE \
  (3)
/**
 * The maximum number of items that can be stored in
 * sbp_msg_settings_register_resp_t::setting (V4 API) or
 * msg_settings_register_resp_t::setting (legacy API) before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_SETTINGS_REGISTER_RESP_SETTING_MAX 254u

/**
 * Encoded length of sbp_msg_settings_register_resp_t (V4 API) and
 * msg_settings_register_resp_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_settings_register_resp_encoded_len to determine the actual size of
 * an instance of this message. Users of the legacy API are required to track
 * the encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SETTINGS_REGISTER_RESP_ENCODED_OVERHEAD 1u

#endif /* LIBSBP_SETTINGS_MACROS_H */
