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
 * Automatically generated from yaml/swiftnav/sbp/file_io.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_NEW_FILE_IO_MESSAGES_H
#define LIBSBP_NEW_FILE_IO_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/file_io_macros.h>
#include <libsbp/new/string/double_null_terminated.h>
#include <libsbp/new/string/multipart.h>
#include <libsbp/new/string/null_terminated.h>
#include <libsbp/new/string/unterminated.h>

#ifdef __cplusplus
extern "C" {
#endif

struct sbp_state;

/** Read file from the file system (host => device)
 *
 * The file read message reads a certain length (up to 255 bytes) from a given
 * offset into a file, and returns the data in a MSG_FILEIO_READ_RESP message
 * where the message length field indicates how many bytes were succesfully
 * read.The sequence number in the request will be returned in the response. If
 * the message is invalid, a followup MSG_PRINT message will print "Invalid
 * fileio read message". A device will only respond to this message when it is
 * received from sender ID 0x42.
 */
typedef struct {
  /**
   * Read sequence number
   */
  u32 sequence;

  /**
   * File offset [bytes]
   */
  u32 offset;

  /**
   * Chunk size to read [bytes]
   */
  u8 chunk_size;

  /**
   * Name of the file to read from
   */
  sbp_null_terminated_string_t filename;
} sbp_msg_fileio_read_req_t;
void sbp_msg_fileio_read_req_t_filename_init(sbp_null_terminated_string_t *s);
bool sbp_msg_fileio_read_req_t_filename_valid(
    const sbp_null_terminated_string_t *s);
int sbp_msg_fileio_read_req_t_filename_strcmp(
    const sbp_null_terminated_string_t *a,
    const sbp_null_terminated_string_t *b);
uint8_t sbp_msg_fileio_read_req_t_filename_packed_len(
    const sbp_null_terminated_string_t *s);
uint8_t sbp_msg_fileio_read_req_t_filename_space_remaining(
    const sbp_null_terminated_string_t *s);
bool sbp_msg_fileio_read_req_t_filename_set(sbp_null_terminated_string_t *s,
                                            const char *new_str);
bool sbp_msg_fileio_read_req_t_filename_printf(sbp_null_terminated_string_t *s,
                                               const char *fmt, ...)
    SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_fileio_read_req_t_filename_vprintf(sbp_null_terminated_string_t *s,
                                                const char *fmt, va_list ap);
bool sbp_msg_fileio_read_req_t_filename_append_printf(
    sbp_null_terminated_string_t *s, const char *fmt, ...)
    SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_fileio_read_req_t_filename_append_vprintf(
    sbp_null_terminated_string_t *s, const char *fmt, va_list ap);
const char *sbp_msg_fileio_read_req_t_filename_get(
    const sbp_null_terminated_string_t *s);

/**
 * Get encoded size of an instance of sbp_msg_fileio_read_req_t
 *
 * @param msg sbp_msg_fileio_read_req_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_fileio_read_req_t(
    const sbp_msg_fileio_read_req_t *msg);

/**
 * Encode an instance of sbp_msg_fileio_read_req_t to wire representation
 *
 * This function encodes the given instance in to the user provided buffer. The
 * buffer provided to this function must be large enough to store the encoded
 * message otherwise it will return SBP_ENCODE_ERROR without writing anything to
 * the buffer.
 *
 * Specify the length of the destination buffer in the \p len parameter. If
 * non-null the number of bytes written to the buffer will be returned in \p
 * n_written.
 *
 * @param buf Destination buffer
 * @param len Length of \p buf
 * @param n_written If not null, on success will be set to the number of bytes
 * written to \p buf
 * @param msg Instance of sbp_msg_fileio_read_req_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_fileio_read_req_t(uint8_t *buf, uint8_t len,
                                        uint8_t *n_written,
                                        const sbp_msg_fileio_read_req_t *msg);

/**
 * Decode an instance of sbp_msg_fileio_read_req_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_fileio_read_req_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_fileio_read_req_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_fileio_read_req_t(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_fileio_read_req_t *msg);
/**
 * Send an instance of sbp_msg_fileio_read_req_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_fileio_read_req_t
 *
 * The given message will be encoded to wire representation and passed in to the
 * given write function callback. The write callback will be called several
 * times for each invocation of this function.
 *
 * @param s SBP state
 * @param sender_id SBP sender id
 * @param msg Message to send
 * @param write Write function
 * @param SBP_OK on success, or other libsbp error code
 */
s8 sbp_send_sbp_msg_fileio_read_req_t(struct sbp_state *s, u16 sender_id,
                                      const sbp_msg_fileio_read_req_t *msg,
                                      s32 (*write)(u8 *buff, u32 n,
                                                   void *context));

/**
 * Compare two instances of sbp_msg_fileio_read_req_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_fileio_read_req_t instance
 * @param b sbp_msg_fileio_read_req_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_fileio_read_req_t(const sbp_msg_fileio_read_req_t *a,
                                      const sbp_msg_fileio_read_req_t *b);

/** File read from the file system (host <= device)
 *
 * The file read message reads a certain length (up to 255 bytes) from a given
 * offset into a file, and returns the data in a message where the message
 * length field indicates how many bytes were succesfully read. The sequence
 * number in the response is preserved from the request.
 */
typedef struct {
  /**
   * Read sequence number
   */
  u32 sequence;

  /**
   * Contents of read file
   */
  u8 contents[251];
  /**
   * Number of elements in contents
   *
   * When sending a message fill in this field with the number elements set in
   * contents before calling an appropriate libsbp send function
   *
   * When receiving a message query this field for the number of elements in
   * contents. The value of any elements beyond the index specified in this
   * field is undefined
   */
  u8 n_contents;
} sbp_msg_fileio_read_resp_t;

/**
 * Get encoded size of an instance of sbp_msg_fileio_read_resp_t
 *
 * @param msg sbp_msg_fileio_read_resp_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_fileio_read_resp_t(
    const sbp_msg_fileio_read_resp_t *msg);

/**
 * Encode an instance of sbp_msg_fileio_read_resp_t to wire representation
 *
 * This function encodes the given instance in to the user provided buffer. The
 * buffer provided to this function must be large enough to store the encoded
 * message otherwise it will return SBP_ENCODE_ERROR without writing anything to
 * the buffer.
 *
 * Specify the length of the destination buffer in the \p len parameter. If
 * non-null the number of bytes written to the buffer will be returned in \p
 * n_written.
 *
 * @param buf Destination buffer
 * @param len Length of \p buf
 * @param n_written If not null, on success will be set to the number of bytes
 * written to \p buf
 * @param msg Instance of sbp_msg_fileio_read_resp_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_fileio_read_resp_t(uint8_t *buf, uint8_t len,
                                         uint8_t *n_written,
                                         const sbp_msg_fileio_read_resp_t *msg);

/**
 * Decode an instance of sbp_msg_fileio_read_resp_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_fileio_read_resp_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_fileio_read_resp_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_fileio_read_resp_t(const uint8_t *buf, uint8_t len,
                                         uint8_t *n_read,
                                         sbp_msg_fileio_read_resp_t *msg);
/**
 * Send an instance of sbp_msg_fileio_read_resp_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_fileio_read_resp_t
 *
 * The given message will be encoded to wire representation and passed in to the
 * given write function callback. The write callback will be called several
 * times for each invocation of this function.
 *
 * @param s SBP state
 * @param sender_id SBP sender id
 * @param msg Message to send
 * @param write Write function
 * @param SBP_OK on success, or other libsbp error code
 */
s8 sbp_send_sbp_msg_fileio_read_resp_t(struct sbp_state *s, u16 sender_id,
                                       const sbp_msg_fileio_read_resp_t *msg,
                                       s32 (*write)(u8 *buff, u32 n,
                                                    void *context));

/**
 * Compare two instances of sbp_msg_fileio_read_resp_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_fileio_read_resp_t instance
 * @param b sbp_msg_fileio_read_resp_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_fileio_read_resp_t(const sbp_msg_fileio_read_resp_t *a,
                                       const sbp_msg_fileio_read_resp_t *b);

/** List files in a directory (host => device)
 *
 * The read directory message lists the files in a directory on the device's
 * onboard flash file system.  The offset parameter can be used to skip the
 * first n elements of the file list. Returns a MSG_FILEIO_READ_DIR_RESP message
 * containing the directory listings as a NULL delimited list. The listing is
 * chunked over multiple SBP packets. The sequence number in the request will be
 * returned in the response.  If message is invalid, a followup MSG_PRINT
 * message will print "Invalid fileio read message". A device will only respond
 * to this message when it is received from sender ID 0x42.
 */
typedef struct {
  /**
   * Read sequence number
   */
  u32 sequence;

  /**
   * The offset to skip the first n elements of the file list
   */
  u32 offset;

  /**
   * Name of the directory to list
   */
  sbp_null_terminated_string_t dirname;
} sbp_msg_fileio_read_dir_req_t;
void sbp_msg_fileio_read_dir_req_t_dirname_init(
    sbp_null_terminated_string_t *s);
bool sbp_msg_fileio_read_dir_req_t_dirname_valid(
    const sbp_null_terminated_string_t *s);
int sbp_msg_fileio_read_dir_req_t_dirname_strcmp(
    const sbp_null_terminated_string_t *a,
    const sbp_null_terminated_string_t *b);
uint8_t sbp_msg_fileio_read_dir_req_t_dirname_packed_len(
    const sbp_null_terminated_string_t *s);
uint8_t sbp_msg_fileio_read_dir_req_t_dirname_space_remaining(
    const sbp_null_terminated_string_t *s);
bool sbp_msg_fileio_read_dir_req_t_dirname_set(sbp_null_terminated_string_t *s,
                                               const char *new_str);
bool sbp_msg_fileio_read_dir_req_t_dirname_printf(
    sbp_null_terminated_string_t *s, const char *fmt, ...)
    SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_fileio_read_dir_req_t_dirname_vprintf(
    sbp_null_terminated_string_t *s, const char *fmt, va_list ap);
bool sbp_msg_fileio_read_dir_req_t_dirname_append_printf(
    sbp_null_terminated_string_t *s, const char *fmt, ...)
    SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_fileio_read_dir_req_t_dirname_append_vprintf(
    sbp_null_terminated_string_t *s, const char *fmt, va_list ap);
const char *sbp_msg_fileio_read_dir_req_t_dirname_get(
    const sbp_null_terminated_string_t *s);

/**
 * Get encoded size of an instance of sbp_msg_fileio_read_dir_req_t
 *
 * @param msg sbp_msg_fileio_read_dir_req_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_fileio_read_dir_req_t(
    const sbp_msg_fileio_read_dir_req_t *msg);

/**
 * Encode an instance of sbp_msg_fileio_read_dir_req_t to wire representation
 *
 * This function encodes the given instance in to the user provided buffer. The
 * buffer provided to this function must be large enough to store the encoded
 * message otherwise it will return SBP_ENCODE_ERROR without writing anything to
 * the buffer.
 *
 * Specify the length of the destination buffer in the \p len parameter. If
 * non-null the number of bytes written to the buffer will be returned in \p
 * n_written.
 *
 * @param buf Destination buffer
 * @param len Length of \p buf
 * @param n_written If not null, on success will be set to the number of bytes
 * written to \p buf
 * @param msg Instance of sbp_msg_fileio_read_dir_req_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_fileio_read_dir_req_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_fileio_read_dir_req_t *msg);

/**
 * Decode an instance of sbp_msg_fileio_read_dir_req_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_fileio_read_dir_req_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_fileio_read_dir_req_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_fileio_read_dir_req_t(const uint8_t *buf, uint8_t len,
                                            uint8_t *n_read,
                                            sbp_msg_fileio_read_dir_req_t *msg);
/**
 * Send an instance of sbp_msg_fileio_read_dir_req_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_fileio_read_dir_req_t
 *
 * The given message will be encoded to wire representation and passed in to the
 * given write function callback. The write callback will be called several
 * times for each invocation of this function.
 *
 * @param s SBP state
 * @param sender_id SBP sender id
 * @param msg Message to send
 * @param write Write function
 * @param SBP_OK on success, or other libsbp error code
 */
s8 sbp_send_sbp_msg_fileio_read_dir_req_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_fileio_read_dir_req_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_fileio_read_dir_req_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_fileio_read_dir_req_t instance
 * @param b sbp_msg_fileio_read_dir_req_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_fileio_read_dir_req_t(
    const sbp_msg_fileio_read_dir_req_t *a,
    const sbp_msg_fileio_read_dir_req_t *b);

/** Files listed in a directory (host <= device)
 *
 * The read directory message lists the files in a directory on the device's
 * onboard flash file system. Message contains the directory listings as a NULL
 * delimited list. The listing is chunked over multiple SBP packets and the end
 * of the list is identified by an packet with no entries. The sequence number
 * in the response is preserved from the request.
 */
typedef struct {
  /**
   * Read sequence number
   */
  u32 sequence;

  /**
   * Contents of read directory
   */
  sbp_multipart_string_t contents;
} sbp_msg_fileio_read_dir_resp_t;
void sbp_msg_fileio_read_dir_resp_t_contents_init(sbp_multipart_string_t *s);
bool sbp_msg_fileio_read_dir_resp_t_contents_valid(
    const sbp_multipart_string_t *s);
int sbp_msg_fileio_read_dir_resp_t_contents_strcmp(
    const sbp_multipart_string_t *a, const sbp_multipart_string_t *b);
uint8_t sbp_msg_fileio_read_dir_resp_t_contents_packed_len(
    const sbp_multipart_string_t *s);
uint8_t sbp_msg_fileio_read_dir_resp_t_contents_space_remaining(
    const sbp_multipart_string_t *s);
uint8_t sbp_msg_fileio_read_dir_resp_t_contents_count_sections(
    const sbp_multipart_string_t *s);
bool sbp_msg_fileio_read_dir_resp_t_contents_add_section(
    sbp_multipart_string_t *s, const char *new_str);
bool sbp_msg_fileio_read_dir_resp_t_contents_add_section_printf(
    sbp_multipart_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_fileio_read_dir_resp_t_contents_add_section_vprintf(
    sbp_multipart_string_t *s, const char *fmt, va_list ap);
bool sbp_msg_fileio_read_dir_resp_t_contents_append(sbp_multipart_string_t *s,
                                                    const char *str);
bool sbp_msg_fileio_read_dir_resp_t_contents_append_printf(
    sbp_multipart_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_fileio_read_dir_resp_t_contents_append_vprintf(
    sbp_multipart_string_t *s, const char *fmt, va_list ap);
const char *sbp_msg_fileio_read_dir_resp_t_contents_get_section(
    const sbp_multipart_string_t *s, uint8_t section);
uint8_t sbp_msg_fileio_read_dir_resp_t_contents_section_strlen(
    const sbp_multipart_string_t *s, uint8_t section);

/**
 * Get encoded size of an instance of sbp_msg_fileio_read_dir_resp_t
 *
 * @param msg sbp_msg_fileio_read_dir_resp_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_fileio_read_dir_resp_t(
    const sbp_msg_fileio_read_dir_resp_t *msg);

/**
 * Encode an instance of sbp_msg_fileio_read_dir_resp_t to wire representation
 *
 * This function encodes the given instance in to the user provided buffer. The
 * buffer provided to this function must be large enough to store the encoded
 * message otherwise it will return SBP_ENCODE_ERROR without writing anything to
 * the buffer.
 *
 * Specify the length of the destination buffer in the \p len parameter. If
 * non-null the number of bytes written to the buffer will be returned in \p
 * n_written.
 *
 * @param buf Destination buffer
 * @param len Length of \p buf
 * @param n_written If not null, on success will be set to the number of bytes
 * written to \p buf
 * @param msg Instance of sbp_msg_fileio_read_dir_resp_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_fileio_read_dir_resp_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_fileio_read_dir_resp_t *msg);

/**
 * Decode an instance of sbp_msg_fileio_read_dir_resp_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_fileio_read_dir_resp_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_fileio_read_dir_resp_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_fileio_read_dir_resp_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_fileio_read_dir_resp_t *msg);
/**
 * Send an instance of sbp_msg_fileio_read_dir_resp_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_fileio_read_dir_resp_t
 *
 * The given message will be encoded to wire representation and passed in to the
 * given write function callback. The write callback will be called several
 * times for each invocation of this function.
 *
 * @param s SBP state
 * @param sender_id SBP sender id
 * @param msg Message to send
 * @param write Write function
 * @param SBP_OK on success, or other libsbp error code
 */
s8 sbp_send_sbp_msg_fileio_read_dir_resp_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_fileio_read_dir_resp_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_fileio_read_dir_resp_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_fileio_read_dir_resp_t instance
 * @param b sbp_msg_fileio_read_dir_resp_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_fileio_read_dir_resp_t(
    const sbp_msg_fileio_read_dir_resp_t *a,
    const sbp_msg_fileio_read_dir_resp_t *b);

/** Delete a file from the file system (host => device)
 *
 * The file remove message deletes a file from the file system. If the message
 * is invalid, a followup MSG_PRINT message will print "Invalid fileio remove
 * message". A device will only process this message when it is received from
 * sender ID 0x42.
 */
typedef struct {
  /**
   * Name of the file to delete
   */
  sbp_null_terminated_string_t filename;
} sbp_msg_fileio_remove_t;
void sbp_msg_fileio_remove_t_filename_init(sbp_null_terminated_string_t *s);
bool sbp_msg_fileio_remove_t_filename_valid(
    const sbp_null_terminated_string_t *s);
int sbp_msg_fileio_remove_t_filename_strcmp(
    const sbp_null_terminated_string_t *a,
    const sbp_null_terminated_string_t *b);
uint8_t sbp_msg_fileio_remove_t_filename_packed_len(
    const sbp_null_terminated_string_t *s);
uint8_t sbp_msg_fileio_remove_t_filename_space_remaining(
    const sbp_null_terminated_string_t *s);
bool sbp_msg_fileio_remove_t_filename_set(sbp_null_terminated_string_t *s,
                                          const char *new_str);
bool sbp_msg_fileio_remove_t_filename_printf(sbp_null_terminated_string_t *s,
                                             const char *fmt, ...)
    SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_fileio_remove_t_filename_vprintf(sbp_null_terminated_string_t *s,
                                              const char *fmt, va_list ap);
bool sbp_msg_fileio_remove_t_filename_append_printf(
    sbp_null_terminated_string_t *s, const char *fmt, ...)
    SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_fileio_remove_t_filename_append_vprintf(
    sbp_null_terminated_string_t *s, const char *fmt, va_list ap);
const char *sbp_msg_fileio_remove_t_filename_get(
    const sbp_null_terminated_string_t *s);

/**
 * Get encoded size of an instance of sbp_msg_fileio_remove_t
 *
 * @param msg sbp_msg_fileio_remove_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_fileio_remove_t(
    const sbp_msg_fileio_remove_t *msg);

/**
 * Encode an instance of sbp_msg_fileio_remove_t to wire representation
 *
 * This function encodes the given instance in to the user provided buffer. The
 * buffer provided to this function must be large enough to store the encoded
 * message otherwise it will return SBP_ENCODE_ERROR without writing anything to
 * the buffer.
 *
 * Specify the length of the destination buffer in the \p len parameter. If
 * non-null the number of bytes written to the buffer will be returned in \p
 * n_written.
 *
 * @param buf Destination buffer
 * @param len Length of \p buf
 * @param n_written If not null, on success will be set to the number of bytes
 * written to \p buf
 * @param msg Instance of sbp_msg_fileio_remove_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_fileio_remove_t(uint8_t *buf, uint8_t len,
                                      uint8_t *n_written,
                                      const sbp_msg_fileio_remove_t *msg);

/**
 * Decode an instance of sbp_msg_fileio_remove_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_fileio_remove_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_fileio_remove_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_fileio_remove_t(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_fileio_remove_t *msg);
/**
 * Send an instance of sbp_msg_fileio_remove_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_fileio_remove_t
 *
 * The given message will be encoded to wire representation and passed in to the
 * given write function callback. The write callback will be called several
 * times for each invocation of this function.
 *
 * @param s SBP state
 * @param sender_id SBP sender id
 * @param msg Message to send
 * @param write Write function
 * @param SBP_OK on success, or other libsbp error code
 */
s8 sbp_send_sbp_msg_fileio_remove_t(struct sbp_state *s, u16 sender_id,
                                    const sbp_msg_fileio_remove_t *msg,
                                    s32 (*write)(u8 *buff, u32 n,
                                                 void *context));

/**
 * Compare two instances of sbp_msg_fileio_remove_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_fileio_remove_t instance
 * @param b sbp_msg_fileio_remove_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_fileio_remove_t(const sbp_msg_fileio_remove_t *a,
                                    const sbp_msg_fileio_remove_t *b);

/** Write to file (host => device)
 *
 * The file write message writes a certain length (up to 255 bytes) of data to a
 * file at a given offset. Returns a copy of the original MSG_FILEIO_WRITE_RESP
 * message to check integrity of the write. The sequence number in the request
 * will be returned in the response. If message is invalid, a followup MSG_PRINT
 * message will print "Invalid fileio write message". A device will only process
 * this message when it is received from sender ID 0x42.
 */
typedef struct {
  /**
   * Write sequence number
   */
  u32 sequence;

  /**
   * Offset into the file at which to start writing in bytes [bytes]
   */
  u32 offset;

  /**
   * Name of the file to write to
   */
  sbp_null_terminated_string_t filename;

  /**
   * Variable-length array of data to write
   */
  u8 data[247];
  /**
   * Number of elements in data
   *
   * When sending a message fill in this field with the number elements set in
   * data before calling an appropriate libsbp send function
   *
   * When receiving a message query this field for the number of elements in
   * data. The value of any elements beyond the index specified in this field is
   * undefined
   */
  u8 n_data;
} sbp_msg_fileio_write_req_t;
void sbp_msg_fileio_write_req_t_filename_init(sbp_null_terminated_string_t *s);
bool sbp_msg_fileio_write_req_t_filename_valid(
    const sbp_null_terminated_string_t *s);
int sbp_msg_fileio_write_req_t_filename_strcmp(
    const sbp_null_terminated_string_t *a,
    const sbp_null_terminated_string_t *b);
uint8_t sbp_msg_fileio_write_req_t_filename_packed_len(
    const sbp_null_terminated_string_t *s);
uint8_t sbp_msg_fileio_write_req_t_filename_space_remaining(
    const sbp_null_terminated_string_t *s);
bool sbp_msg_fileio_write_req_t_filename_set(sbp_null_terminated_string_t *s,
                                             const char *new_str);
bool sbp_msg_fileio_write_req_t_filename_printf(sbp_null_terminated_string_t *s,
                                                const char *fmt, ...)
    SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_fileio_write_req_t_filename_vprintf(
    sbp_null_terminated_string_t *s, const char *fmt, va_list ap);
bool sbp_msg_fileio_write_req_t_filename_append_printf(
    sbp_null_terminated_string_t *s, const char *fmt, ...)
    SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_fileio_write_req_t_filename_append_vprintf(
    sbp_null_terminated_string_t *s, const char *fmt, va_list ap);
const char *sbp_msg_fileio_write_req_t_filename_get(
    const sbp_null_terminated_string_t *s);

/**
 * Get encoded size of an instance of sbp_msg_fileio_write_req_t
 *
 * @param msg sbp_msg_fileio_write_req_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_fileio_write_req_t(
    const sbp_msg_fileio_write_req_t *msg);

/**
 * Encode an instance of sbp_msg_fileio_write_req_t to wire representation
 *
 * This function encodes the given instance in to the user provided buffer. The
 * buffer provided to this function must be large enough to store the encoded
 * message otherwise it will return SBP_ENCODE_ERROR without writing anything to
 * the buffer.
 *
 * Specify the length of the destination buffer in the \p len parameter. If
 * non-null the number of bytes written to the buffer will be returned in \p
 * n_written.
 *
 * @param buf Destination buffer
 * @param len Length of \p buf
 * @param n_written If not null, on success will be set to the number of bytes
 * written to \p buf
 * @param msg Instance of sbp_msg_fileio_write_req_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_fileio_write_req_t(uint8_t *buf, uint8_t len,
                                         uint8_t *n_written,
                                         const sbp_msg_fileio_write_req_t *msg);

/**
 * Decode an instance of sbp_msg_fileio_write_req_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_fileio_write_req_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_fileio_write_req_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_fileio_write_req_t(const uint8_t *buf, uint8_t len,
                                         uint8_t *n_read,
                                         sbp_msg_fileio_write_req_t *msg);
/**
 * Send an instance of sbp_msg_fileio_write_req_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_fileio_write_req_t
 *
 * The given message will be encoded to wire representation and passed in to the
 * given write function callback. The write callback will be called several
 * times for each invocation of this function.
 *
 * @param s SBP state
 * @param sender_id SBP sender id
 * @param msg Message to send
 * @param write Write function
 * @param SBP_OK on success, or other libsbp error code
 */
s8 sbp_send_sbp_msg_fileio_write_req_t(struct sbp_state *s, u16 sender_id,
                                       const sbp_msg_fileio_write_req_t *msg,
                                       s32 (*write)(u8 *buff, u32 n,
                                                    void *context));

/**
 * Compare two instances of sbp_msg_fileio_write_req_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_fileio_write_req_t instance
 * @param b sbp_msg_fileio_write_req_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_fileio_write_req_t(const sbp_msg_fileio_write_req_t *a,
                                       const sbp_msg_fileio_write_req_t *b);

/** File written to (host <= device)
 *
 * The file write message writes a certain length (up to 255 bytes) of data to a
 * file at a given offset. The message is a copy of the original
 * MSG_FILEIO_WRITE_REQ message to check integrity of the write. The sequence
 * number in the response is preserved from the request.
 */
typedef struct {
  /**
   * Write sequence number
   */
  u32 sequence;
} sbp_msg_fileio_write_resp_t;

/**
 * Get encoded size of an instance of sbp_msg_fileio_write_resp_t
 *
 * @param msg sbp_msg_fileio_write_resp_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_fileio_write_resp_t(
    const sbp_msg_fileio_write_resp_t *msg);

/**
 * Encode an instance of sbp_msg_fileio_write_resp_t to wire representation
 *
 * This function encodes the given instance in to the user provided buffer. The
 * buffer provided to this function must be large enough to store the encoded
 * message otherwise it will return SBP_ENCODE_ERROR without writing anything to
 * the buffer.
 *
 * Specify the length of the destination buffer in the \p len parameter. If
 * non-null the number of bytes written to the buffer will be returned in \p
 * n_written.
 *
 * @param buf Destination buffer
 * @param len Length of \p buf
 * @param n_written If not null, on success will be set to the number of bytes
 * written to \p buf
 * @param msg Instance of sbp_msg_fileio_write_resp_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_fileio_write_resp_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_fileio_write_resp_t *msg);

/**
 * Decode an instance of sbp_msg_fileio_write_resp_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_fileio_write_resp_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_fileio_write_resp_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_fileio_write_resp_t(const uint8_t *buf, uint8_t len,
                                          uint8_t *n_read,
                                          sbp_msg_fileio_write_resp_t *msg);
/**
 * Send an instance of sbp_msg_fileio_write_resp_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_fileio_write_resp_t
 *
 * The given message will be encoded to wire representation and passed in to the
 * given write function callback. The write callback will be called several
 * times for each invocation of this function.
 *
 * @param s SBP state
 * @param sender_id SBP sender id
 * @param msg Message to send
 * @param write Write function
 * @param SBP_OK on success, or other libsbp error code
 */
s8 sbp_send_sbp_msg_fileio_write_resp_t(struct sbp_state *s, u16 sender_id,
                                        const sbp_msg_fileio_write_resp_t *msg,
                                        s32 (*write)(u8 *buff, u32 n,
                                                     void *context));

/**
 * Compare two instances of sbp_msg_fileio_write_resp_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_fileio_write_resp_t instance
 * @param b sbp_msg_fileio_write_resp_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_fileio_write_resp_t(const sbp_msg_fileio_write_resp_t *a,
                                        const sbp_msg_fileio_write_resp_t *b);

/** Request advice on the optimal configuration for FileIO
 *
 * Requests advice on the optimal configuration for a FileIO transfer.  Newer
 * version of FileIO can support greater throughput by supporting a large window
 * of FileIO data that can be in-flight during read or write operations.
 */
typedef struct {
  /**
   * Advice sequence number
   */
  u32 sequence;
} sbp_msg_fileio_config_req_t;

/**
 * Get encoded size of an instance of sbp_msg_fileio_config_req_t
 *
 * @param msg sbp_msg_fileio_config_req_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_fileio_config_req_t(
    const sbp_msg_fileio_config_req_t *msg);

/**
 * Encode an instance of sbp_msg_fileio_config_req_t to wire representation
 *
 * This function encodes the given instance in to the user provided buffer. The
 * buffer provided to this function must be large enough to store the encoded
 * message otherwise it will return SBP_ENCODE_ERROR without writing anything to
 * the buffer.
 *
 * Specify the length of the destination buffer in the \p len parameter. If
 * non-null the number of bytes written to the buffer will be returned in \p
 * n_written.
 *
 * @param buf Destination buffer
 * @param len Length of \p buf
 * @param n_written If not null, on success will be set to the number of bytes
 * written to \p buf
 * @param msg Instance of sbp_msg_fileio_config_req_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_fileio_config_req_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_fileio_config_req_t *msg);

/**
 * Decode an instance of sbp_msg_fileio_config_req_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_fileio_config_req_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_fileio_config_req_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_fileio_config_req_t(const uint8_t *buf, uint8_t len,
                                          uint8_t *n_read,
                                          sbp_msg_fileio_config_req_t *msg);
/**
 * Send an instance of sbp_msg_fileio_config_req_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_fileio_config_req_t
 *
 * The given message will be encoded to wire representation and passed in to the
 * given write function callback. The write callback will be called several
 * times for each invocation of this function.
 *
 * @param s SBP state
 * @param sender_id SBP sender id
 * @param msg Message to send
 * @param write Write function
 * @param SBP_OK on success, or other libsbp error code
 */
s8 sbp_send_sbp_msg_fileio_config_req_t(struct sbp_state *s, u16 sender_id,
                                        const sbp_msg_fileio_config_req_t *msg,
                                        s32 (*write)(u8 *buff, u32 n,
                                                     void *context));

/**
 * Compare two instances of sbp_msg_fileio_config_req_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_fileio_config_req_t instance
 * @param b sbp_msg_fileio_config_req_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_fileio_config_req_t(const sbp_msg_fileio_config_req_t *a,
                                        const sbp_msg_fileio_config_req_t *b);

/** Response with advice on the optimal configuration for FileIO.

 *
* The advice on the optimal configuration for a FileIO transfer.  Newer version
of FileIO can support greater throughput by supporting a large window of FileIO
data that can be in-flight during read or write operations.
 */
typedef struct {
  /**
   * Advice sequence number
   */
  u32 sequence;

  /**
   * The number of SBP packets in the data in-flight window
   */
  u32 window_size;

  /**
   * The number of SBP packets sent in one PDU
   */
  u32 batch_size;

  /**
   * The version of FileIO that is supported
   */
  u32 fileio_version;
} sbp_msg_fileio_config_resp_t;

/**
 * Get encoded size of an instance of sbp_msg_fileio_config_resp_t
 *
 * @param msg sbp_msg_fileio_config_resp_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_fileio_config_resp_t(
    const sbp_msg_fileio_config_resp_t *msg);

/**
 * Encode an instance of sbp_msg_fileio_config_resp_t to wire representation
 *
 * This function encodes the given instance in to the user provided buffer. The
 * buffer provided to this function must be large enough to store the encoded
 * message otherwise it will return SBP_ENCODE_ERROR without writing anything to
 * the buffer.
 *
 * Specify the length of the destination buffer in the \p len parameter. If
 * non-null the number of bytes written to the buffer will be returned in \p
 * n_written.
 *
 * @param buf Destination buffer
 * @param len Length of \p buf
 * @param n_written If not null, on success will be set to the number of bytes
 * written to \p buf
 * @param msg Instance of sbp_msg_fileio_config_resp_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_fileio_config_resp_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_fileio_config_resp_t *msg);

/**
 * Decode an instance of sbp_msg_fileio_config_resp_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_fileio_config_resp_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_fileio_config_resp_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_fileio_config_resp_t(const uint8_t *buf, uint8_t len,
                                           uint8_t *n_read,
                                           sbp_msg_fileio_config_resp_t *msg);
/**
 * Send an instance of sbp_msg_fileio_config_resp_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_fileio_config_resp_t
 *
 * The given message will be encoded to wire representation and passed in to the
 * given write function callback. The write callback will be called several
 * times for each invocation of this function.
 *
 * @param s SBP state
 * @param sender_id SBP sender id
 * @param msg Message to send
 * @param write Write function
 * @param SBP_OK on success, or other libsbp error code
 */
s8 sbp_send_sbp_msg_fileio_config_resp_t(
    struct sbp_state *s, u16 sender_id, const sbp_msg_fileio_config_resp_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_fileio_config_resp_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_fileio_config_resp_t instance
 * @param b sbp_msg_fileio_config_resp_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_fileio_config_resp_t(const sbp_msg_fileio_config_resp_t *a,
                                         const sbp_msg_fileio_config_resp_t *b);

#ifdef __cplusplus
}
static inline bool operator==(const sbp_msg_fileio_read_req_t &lhs,
                              const sbp_msg_fileio_read_req_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_read_req_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_fileio_read_req_t &lhs,
                              const sbp_msg_fileio_read_req_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_read_req_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_fileio_read_req_t &lhs,
                             const sbp_msg_fileio_read_req_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_read_req_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_fileio_read_req_t &lhs,
                              const sbp_msg_fileio_read_req_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_read_req_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_fileio_read_req_t &lhs,
                             const sbp_msg_fileio_read_req_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_read_req_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_fileio_read_req_t &lhs,
                              const sbp_msg_fileio_read_req_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_read_req_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_fileio_read_resp_t &lhs,
                              const sbp_msg_fileio_read_resp_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_read_resp_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_fileio_read_resp_t &lhs,
                              const sbp_msg_fileio_read_resp_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_read_resp_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_fileio_read_resp_t &lhs,
                             const sbp_msg_fileio_read_resp_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_read_resp_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_fileio_read_resp_t &lhs,
                              const sbp_msg_fileio_read_resp_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_read_resp_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_fileio_read_resp_t &lhs,
                             const sbp_msg_fileio_read_resp_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_read_resp_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_fileio_read_resp_t &lhs,
                              const sbp_msg_fileio_read_resp_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_read_resp_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_fileio_read_dir_req_t &lhs,
                              const sbp_msg_fileio_read_dir_req_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_read_dir_req_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_fileio_read_dir_req_t &lhs,
                              const sbp_msg_fileio_read_dir_req_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_read_dir_req_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_fileio_read_dir_req_t &lhs,
                             const sbp_msg_fileio_read_dir_req_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_read_dir_req_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_fileio_read_dir_req_t &lhs,
                              const sbp_msg_fileio_read_dir_req_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_read_dir_req_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_fileio_read_dir_req_t &lhs,
                             const sbp_msg_fileio_read_dir_req_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_read_dir_req_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_fileio_read_dir_req_t &lhs,
                              const sbp_msg_fileio_read_dir_req_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_read_dir_req_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_fileio_read_dir_resp_t &lhs,
                              const sbp_msg_fileio_read_dir_resp_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_read_dir_resp_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_fileio_read_dir_resp_t &lhs,
                              const sbp_msg_fileio_read_dir_resp_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_read_dir_resp_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_fileio_read_dir_resp_t &lhs,
                             const sbp_msg_fileio_read_dir_resp_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_read_dir_resp_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_fileio_read_dir_resp_t &lhs,
                              const sbp_msg_fileio_read_dir_resp_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_read_dir_resp_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_fileio_read_dir_resp_t &lhs,
                             const sbp_msg_fileio_read_dir_resp_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_read_dir_resp_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_fileio_read_dir_resp_t &lhs,
                              const sbp_msg_fileio_read_dir_resp_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_read_dir_resp_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_fileio_remove_t &lhs,
                              const sbp_msg_fileio_remove_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_remove_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_fileio_remove_t &lhs,
                              const sbp_msg_fileio_remove_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_remove_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_fileio_remove_t &lhs,
                             const sbp_msg_fileio_remove_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_remove_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_fileio_remove_t &lhs,
                              const sbp_msg_fileio_remove_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_remove_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_fileio_remove_t &lhs,
                             const sbp_msg_fileio_remove_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_remove_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_fileio_remove_t &lhs,
                              const sbp_msg_fileio_remove_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_remove_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_fileio_write_req_t &lhs,
                              const sbp_msg_fileio_write_req_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_write_req_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_fileio_write_req_t &lhs,
                              const sbp_msg_fileio_write_req_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_write_req_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_fileio_write_req_t &lhs,
                             const sbp_msg_fileio_write_req_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_write_req_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_fileio_write_req_t &lhs,
                              const sbp_msg_fileio_write_req_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_write_req_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_fileio_write_req_t &lhs,
                             const sbp_msg_fileio_write_req_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_write_req_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_fileio_write_req_t &lhs,
                              const sbp_msg_fileio_write_req_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_write_req_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_fileio_write_resp_t &lhs,
                              const sbp_msg_fileio_write_resp_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_write_resp_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_fileio_write_resp_t &lhs,
                              const sbp_msg_fileio_write_resp_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_write_resp_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_fileio_write_resp_t &lhs,
                             const sbp_msg_fileio_write_resp_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_write_resp_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_fileio_write_resp_t &lhs,
                              const sbp_msg_fileio_write_resp_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_write_resp_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_fileio_write_resp_t &lhs,
                             const sbp_msg_fileio_write_resp_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_write_resp_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_fileio_write_resp_t &lhs,
                              const sbp_msg_fileio_write_resp_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_write_resp_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_fileio_config_req_t &lhs,
                              const sbp_msg_fileio_config_req_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_config_req_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_fileio_config_req_t &lhs,
                              const sbp_msg_fileio_config_req_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_config_req_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_fileio_config_req_t &lhs,
                             const sbp_msg_fileio_config_req_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_config_req_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_fileio_config_req_t &lhs,
                              const sbp_msg_fileio_config_req_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_config_req_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_fileio_config_req_t &lhs,
                             const sbp_msg_fileio_config_req_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_config_req_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_fileio_config_req_t &lhs,
                              const sbp_msg_fileio_config_req_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_config_req_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_fileio_config_resp_t &lhs,
                              const sbp_msg_fileio_config_resp_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_config_resp_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_fileio_config_resp_t &lhs,
                              const sbp_msg_fileio_config_resp_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_config_resp_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_fileio_config_resp_t &lhs,
                             const sbp_msg_fileio_config_resp_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_config_resp_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_fileio_config_resp_t &lhs,
                              const sbp_msg_fileio_config_resp_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_config_resp_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_fileio_config_resp_t &lhs,
                             const sbp_msg_fileio_config_resp_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_config_resp_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_fileio_config_resp_t &lhs,
                              const sbp_msg_fileio_config_resp_t &rhs) {
  return sbp_cmp_sbp_msg_fileio_config_resp_t(&lhs, &rhs) >= 0;
}

#endif

#endif /* LIBSBP_NEW_FILE_IO_MESSAGES_H */
