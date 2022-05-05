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
 * The maximum number of items that can be stored in
 * sbp_msg_fileio_read_req_t::filename (V4 API) or
 * msg_fileio_read_req_t::filename (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_FILEIO_READ_REQ_FILENAME_MAX 246u

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
 * The maximum number of items that can be stored in
 * sbp_msg_fileio_read_resp_t::contents (V4 API) or
 * msg_fileio_read_resp_t::contents (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_FILEIO_READ_RESP_CONTENTS_MAX 251u

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
 * The maximum number of items that can be stored in
 * sbp_msg_fileio_read_dir_req_t::dirname (V4 API) or
 * msg_fileio_read_dir_req_t::dirname (legacy API) before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_FILEIO_READ_DIR_REQ_DIRNAME_MAX 247u

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
 * The maximum number of items that can be stored in
 * sbp_msg_fileio_read_dir_resp_t::contents (V4 API) or
 * msg_fileio_read_dir_resp_t::contents (legacy API) before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_FILEIO_READ_DIR_RESP_CONTENTS_MAX 251u

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
 * The maximum number of items that can be stored in
 * sbp_msg_fileio_remove_t::filename (V4 API) or msg_fileio_remove_t::filename
 * (legacy API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_FILEIO_REMOVE_FILENAME_MAX 255u

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
 * The maximum number of items that can be stored in
 * sbp_msg_fileio_write_req_t::filename (V4 API) or
 * msg_fileio_write_req_t::filename (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_FILEIO_WRITE_REQ_FILENAME_MAX 247u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_fileio_write_req_t::data (V4 API) or msg_fileio_write_req_t::data
 * (legacy API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_FILEIO_WRITE_REQ_DATA_MAX 247u

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
