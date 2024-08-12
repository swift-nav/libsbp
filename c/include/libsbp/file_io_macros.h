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
 * Automatically generated from yaml/swiftnav/sbp/file_io.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_FILE_IO_MACROS_H
#define LIBSBP_FILE_IO_MACROS_H

/**
 * The maximum number of items that can be stored in
 * sbp_msg_fileio_read_req_t::filename before the maximum SBP message size is
 * exceeded
 */
#define SBP_MSG_FILEIO_READ_REQ_FILENAME_MAX 246u

/**
 * Encoded length of sbp_msg_fileio_read_req_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_fileio_read_req_encoded_len to determine the actual size of an
 * instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_FILEIO_READ_REQ_ENCODED_OVERHEAD 9u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_fileio_read_resp_t::contents before the maximum SBP message size is
 * exceeded
 */
#define SBP_MSG_FILEIO_READ_RESP_CONTENTS_MAX 251u

/**
 * Encoded length of sbp_msg_fileio_read_resp_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_fileio_read_resp_encoded_len to determine the actual size of an
 * instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_FILEIO_READ_RESP_ENCODED_OVERHEAD 4u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_fileio_read_dir_req_t::dirname before the maximum SBP message size is
 * exceeded
 */
#define SBP_MSG_FILEIO_READ_DIR_REQ_DIRNAME_MAX 247u

/**
 * Encoded length of sbp_msg_fileio_read_dir_req_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_fileio_read_dir_req_encoded_len to determine the actual size of an
 * instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_FILEIO_READ_DIR_REQ_ENCODED_OVERHEAD 8u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_fileio_read_dir_resp_t::contents before the maximum SBP message size
 * is exceeded
 */
#define SBP_MSG_FILEIO_READ_DIR_RESP_CONTENTS_MAX 251u

/**
 * Encoded length of sbp_msg_fileio_read_dir_resp_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_fileio_read_dir_resp_encoded_len to determine the actual size of an
 * instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_FILEIO_READ_DIR_RESP_ENCODED_OVERHEAD 4u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_fileio_remove_t::filename before the maximum SBP message size is
 * exceeded
 */
#define SBP_MSG_FILEIO_REMOVE_FILENAME_MAX 255u

/**
 * Encoded length of sbp_msg_fileio_remove_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_fileio_remove_encoded_len to determine the actual size of an
 * instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_FILEIO_REMOVE_ENCODED_OVERHEAD 0u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_fileio_write_req_t::filename before the maximum SBP message size is
 * exceeded
 */
#define SBP_MSG_FILEIO_WRITE_REQ_FILENAME_MAX 247u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_fileio_write_req_t::data before the maximum SBP message size is
 * exceeded
 */
#define SBP_MSG_FILEIO_WRITE_REQ_DATA_MAX 247u

/**
 * Encoded length of sbp_msg_fileio_write_req_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_fileio_write_req_encoded_len to determine the actual size of an
 * instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_FILEIO_WRITE_REQ_ENCODED_OVERHEAD 8u

/**
 * Encoded length of sbp_msg_fileio_write_resp_t
 */
#define SBP_MSG_FILEIO_WRITE_RESP_ENCODED_LEN 4u

/**
 * Encoded length of sbp_msg_fileio_config_req_t
 */
#define SBP_MSG_FILEIO_CONFIG_REQ_ENCODED_LEN 4u

/**
 * Encoded length of sbp_msg_fileio_config_resp_t
 */
#define SBP_MSG_FILEIO_CONFIG_RESP_ENCODED_LEN 16u

#endif /* LIBSBP_FILE_IO_MACROS_H */
