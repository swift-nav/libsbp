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
 * Automatically generated from yaml/swiftnav/sbp/file_io.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_FILE_IO_MACROS_H
#define LIBSBP_FILE_IO_MACROS_H

#define SBP_MSG_FILEIO_READ_REQ 0x00A8
/**
 * Encoded length of sbp_msg_fileio_read_req_t (V4 API) and
 * msg_fileio_read_req_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_fileio_read_req_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_FILEIO_READ_REQ_ENCODED_OVERHEAD 9u

#define SBP_MSG_FILEIO_READ_RESP 0x00A3
/**
 * Encoded length of sbp_msg_fileio_read_resp_t (V4 API) and
 * msg_fileio_read_resp_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_fileio_read_resp_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_FILEIO_READ_RESP_ENCODED_OVERHEAD 4u

#define SBP_MSG_FILEIO_READ_DIR_REQ 0x00A9
/**
 * Encoded length of sbp_msg_fileio_read_dir_req_t (V4 API) and
 * msg_fileio_read_dir_req_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_fileio_read_dir_req_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_FILEIO_READ_DIR_REQ_ENCODED_OVERHEAD 8u

#define SBP_MSG_FILEIO_READ_DIR_RESP 0x00AA
/**
 * Encoded length of sbp_msg_fileio_read_dir_resp_t (V4 API) and
 * msg_fileio_read_dir_resp_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_fileio_read_dir_resp_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_FILEIO_READ_DIR_RESP_ENCODED_OVERHEAD 4u

#define SBP_MSG_FILEIO_REMOVE 0x00AC
/**
 * Encoded length of sbp_msg_fileio_remove_t (V4 API) and
 * msg_fileio_remove_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_fileio_remove_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_FILEIO_REMOVE_ENCODED_OVERHEAD 0u

#define SBP_MSG_FILEIO_WRITE_REQ 0x00AD
/**
 * Encoded length of sbp_msg_fileio_write_req_t (V4 API) and
 * msg_fileio_write_req_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_fileio_write_req_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_FILEIO_WRITE_REQ_ENCODED_OVERHEAD 8u

#define SBP_MSG_FILEIO_WRITE_RESP 0x00AB
/**
 * Encoded length of sbp_msg_fileio_write_resp_t (V4 API) and
 * msg_fileio_write_resp_t (legacy API)
 */
#define SBP_MSG_FILEIO_WRITE_RESP_ENCODED_LEN 4u

#define SBP_MSG_FILEIO_CONFIG_REQ 0x1001
/**
 * Encoded length of sbp_msg_fileio_config_req_t (V4 API) and
 * msg_fileio_config_req_t (legacy API)
 */
#define SBP_MSG_FILEIO_CONFIG_REQ_ENCODED_LEN 4u

#define SBP_MSG_FILEIO_CONFIG_RESP 0x1002
/**
 * Encoded length of sbp_msg_fileio_config_resp_t (V4 API) and
 * msg_fileio_config_resp_t (legacy API)
 */
#define SBP_MSG_FILEIO_CONFIG_RESP_ENCODED_LEN 16u

#endif /* LIBSBP_FILE_IO_MACROS_H */
