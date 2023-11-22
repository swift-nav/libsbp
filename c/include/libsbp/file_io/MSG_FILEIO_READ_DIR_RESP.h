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

#ifndef LIBSBP_V4_FILE_IO_MSG_FILEIO_READ_DIR_RESP_H
#define LIBSBP_V4_FILE_IO_MSG_FILEIO_READ_DIR_RESP_H

#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/file_io_macros.h>
#include <libsbp/v4/string/sbp_string.h>

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *
 * SBP_MSG_FILEIO_READ_DIR_RESP
 *
 *****************************************************************************/
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
  sbp_string_t contents;
} sbp_msg_fileio_read_dir_resp_t;

/**
 * Initialise sbp_msg_fileio_read_dir_resp_t::contents to empty
 *
 * @param msg sbp_msg_fileio_read_dir_resp_t instance
 */
SBP_EXPORT void sbp_msg_fileio_read_dir_resp_contents_init(
    sbp_msg_fileio_read_dir_resp_t *msg);

/**
 * Test sbp_msg_fileio_read_dir_resp_t::contents for validity
 *
 * @param msg sbp_msg_fileio_read_dir_resp_t instance
 * @return true is sbp_msg_fileio_read_dir_resp_t::contents is valid for
 * encoding purposes, false otherwise
 */
SBP_EXPORT bool sbp_msg_fileio_read_dir_resp_contents_valid(
    const sbp_msg_fileio_read_dir_resp_t *msg);

/**
 * Tests 2 instances of sbp_msg_fileio_read_dir_resp_t::contents for equality
 *
 * Returns a value with the same definitions as strcmp from the C standard
 * library
 *
 * @param a sbp_msg_fileio_read_dir_resp_t instance
 * @param b sbp_msg_fileio_read_dir_resp_t instance
 * @return 0 if equal, <0 if a<b, >0 if a>b
 */
SBP_EXPORT int sbp_msg_fileio_read_dir_resp_contents_strcmp(
    const sbp_msg_fileio_read_dir_resp_t *a,
    const sbp_msg_fileio_read_dir_resp_t *b);

/**
 * Get the encoded size of sbp_msg_fileio_read_dir_resp_t::contents
 *
 * @param msg sbp_msg_fileio_read_dir_resp_t instance
 * @return Size of sbp_msg_fileio_read_dir_resp_t::contents in wire
 * representation
 */
SBP_EXPORT size_t sbp_msg_fileio_read_dir_resp_contents_encoded_len(
    const sbp_msg_fileio_read_dir_resp_t *msg);

/**
 * Query sbp_msg_fileio_read_dir_resp_t::contents for remaining space
 *
 * Returns the number of bytes (not including NULL terminator) which can be
 * added to sbp_msg_fileio_read_dir_resp_t::contents before it exceeds the
 * maximum size of the field in wire representation
 *
 * @param msg sbp_msg_fileio_read_dir_resp_t instance
 * @return Maximum number of bytes that can be appended to the existing string
 */
SBP_EXPORT size_t sbp_msg_fileio_read_dir_resp_contents_space_remaining(
    const sbp_msg_fileio_read_dir_resp_t *msg);
/**
 * Return the number of sections in sbp_msg_fileio_read_dir_resp_t::contents
 *
 * @param msg sbp_msg_fileio_read_dir_resp_t instance
 * @return Number of sections in string
 */
SBP_EXPORT size_t sbp_msg_fileio_read_dir_resp_contents_count_sections(
    const sbp_msg_fileio_read_dir_resp_t *msg);

/**
 * Add a section to sbp_msg_fileio_read_dir_resp_t::contents
 *
 * The specified string will be appended to the field as a new section. If the
 * new section would end up overflowing the maximum encoded length of this field
 * the string will not be changed and this function will return false
 *
 * @param msg sbp_msg_fileio_read_dir_resp_t instance
 * @param new_str New string
 * @return true on success, false otherwise
 */
SBP_EXPORT bool sbp_msg_fileio_read_dir_resp_contents_add_section(
    sbp_msg_fileio_read_dir_resp_t *msg, const char *new_str);

/**
 * Add a section to sbp_msg_fileio_read_dir_resp_t::contents with printf style
 * formatting
 *
 * A new section will be added to the field according to the specified printf
 * style format string and arguments. If the operation would end up overflowing
 * the maximum size of this field in wire encoding the existing contents will be
 * unmodified and this function will return false.
 *
 * @param msg sbp_msg_fileio_read_dir_resp_t instance
 * @param fmt printf style format string
 * @return true on success, false otherwise
 */
SBP_EXPORT bool sbp_msg_fileio_read_dir_resp_contents_add_section_printf(
    sbp_msg_fileio_read_dir_resp_t *msg, const char *fmt, ...)
    SBP_ATTR_FORMAT(2, 3);

/**
 * Add a section to sbp_msg_fileio_read_dir_resp_t::contents with printf style
 * formatting
 *
 * Identical to #sbp_msg_fileio_read_dir_resp_contents_add_section_printf except
 * it takes a va_list argument
 *
 * @param msg sbp_msg_fileio_read_dir_resp_t instance
 * @param fmt printf style format string
 * @param ap Argument list
 * @return true on success, false otherwise
 */
SBP_EXPORT bool sbp_msg_fileio_read_dir_resp_contents_add_section_vprintf(
    sbp_msg_fileio_read_dir_resp_t *msg, const char *fmt, va_list ap)
    SBP_ATTR_VFORMAT(2);

/**
 * Append a string to the last section in
 * sbp_msg_fileio_read_dir_resp_t::contents
 *
 * If the field is currently empty this function will behave exactly like
 * #sbp_msg_fileio_read_dir_resp_contents_add_section
 *
 * If the field already contains one or more sections the given string will be
 * appended on to the last section in the string.
 *
 * If the operation would end up overflowing the maximum size of this field in
 * wire encoding the existing contents will be unmodified and this function will
 * return false.
 *
 * @param msg sbp_msg_fileio_read_dir_resp_t instance
 * @param str New string
 * @return true on success, false otherwise
 */
SBP_EXPORT bool sbp_msg_fileio_read_dir_resp_contents_append(
    sbp_msg_fileio_read_dir_resp_t *msg, const char *str);

/**
 * Append a string to the last section in
 * sbp_msg_fileio_read_dir_resp_t::contents with printf style formatting
 *
 * If the field is currently empty this function will behave exactly like
 * #sbp_msg_fileio_read_dir_resp_contents_add_section_printf
 *
 * If the field already contains one or more sections the given string will be
 * appended on to the last section in the string.
 *
 * If the operation would end up overflowing the maximum size of this field in
 * wire encoding the existing contents will be unmodified and this function will
 * return false.
 *
 * @param msg sbp_msg_fileio_read_dir_resp_t instance
 * @param fmt printf style format string
 * @return true on success, false otherwise
 */
SBP_EXPORT bool sbp_msg_fileio_read_dir_resp_contents_append_printf(
    sbp_msg_fileio_read_dir_resp_t *msg, const char *fmt, ...)
    SBP_ATTR_FORMAT(2, 3);

/**
 * Append a string to the last section in
 * sbp_msg_fileio_read_dir_resp_t::contents with printf style formatting
 *
 * If the field is currently empty this function will behave exactly like
 * #sbp_msg_fileio_read_dir_resp_contents_add_section_vprintf
 *
 * If the field already contains one or more sections the given string will be
 * sppended on to the last section in the string.
 *
 * If the operation would end overflowing the maximum size of this field in wire
 * encoding the existing contents will be unmodified and this function will
 * return false.
 *
 * @param msg sbp_msg_fileio_read_dir_resp_t instance
 * @param fmt printf style format string
 * @param ap Argument list
 * @return true on success, false otherwise
 */
SBP_EXPORT bool sbp_msg_fileio_read_dir_resp_contents_append_vprintf(
    sbp_msg_fileio_read_dir_resp_t *msg, const char *fmt, va_list ap)
    SBP_ATTR_VFORMAT(2);

/**
 * Obtain a section from sbp_msg_fileio_read_dir_resp_t::contents
 *
 * Returns a pointer to the given subsection in the field. Sections are
 * 0-indexed, the \p section parameters must be less than the value returned
 * from #sbp_msg_fileio_read_dir_resp_contents_count_sections.
 *
 * @param msg sbp_msg_fileio_read_dir_resp_t instance
 * @param section Section number
 * @return Pointer to C string, NULL on error
 */
SBP_EXPORT const char *sbp_msg_fileio_read_dir_resp_contents_get_section(
    const sbp_msg_fileio_read_dir_resp_t *msg, size_t section);

/**
 * Obtain the length of a section in sbp_msg_fileio_read_dir_resp_t::contents
 *
 * The returned value does not include the NULL terminator.
 *
 * If the given section does not exist 0 is returned.
 *
 * @param msg sbp_msg_fileio_read_dir_resp_t instance
 * @param section Section number
 * @return Length of section
 */
SBP_EXPORT size_t sbp_msg_fileio_read_dir_resp_contents_section_strlen(
    const sbp_msg_fileio_read_dir_resp_t *msg, size_t section);

/**
 * Get encoded size of an instance of sbp_msg_fileio_read_dir_resp_t
 *
 * @param msg sbp_msg_fileio_read_dir_resp_t instance
 * @return Length of on-wire representation
 */
static inline size_t sbp_msg_fileio_read_dir_resp_encoded_len(
    const sbp_msg_fileio_read_dir_resp_t *msg) {
  return SBP_MSG_FILEIO_READ_DIR_RESP_ENCODED_OVERHEAD +
         sbp_msg_fileio_read_dir_resp_contents_encoded_len(msg);
}

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
SBP_EXPORT s8 sbp_msg_fileio_read_dir_resp_encode(
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
SBP_EXPORT s8 sbp_msg_fileio_read_dir_resp_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_fileio_read_dir_resp_t *msg);
/**
 * Send an instance of sbp_msg_fileio_read_dir_resp_t with the given write
 * function
 *
 * An equivalent of #sbp_message_send which operates specifically on
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
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8 sbp_msg_fileio_read_dir_resp_send(
    sbp_state_t *s, u16 sender_id, const sbp_msg_fileio_read_dir_resp_t *msg,
    sbp_write_fn_t write);

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
SBP_EXPORT int sbp_msg_fileio_read_dir_resp_cmp(
    const sbp_msg_fileio_read_dir_resp_t *a,
    const sbp_msg_fileio_read_dir_resp_t *b);

#ifdef __cplusplus
}

static inline bool operator==(const sbp_msg_fileio_read_dir_resp_t &lhs,
                              const sbp_msg_fileio_read_dir_resp_t &rhs) {
  return sbp_msg_fileio_read_dir_resp_cmp(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_fileio_read_dir_resp_t &lhs,
                              const sbp_msg_fileio_read_dir_resp_t &rhs) {
  return sbp_msg_fileio_read_dir_resp_cmp(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_fileio_read_dir_resp_t &lhs,
                             const sbp_msg_fileio_read_dir_resp_t &rhs) {
  return sbp_msg_fileio_read_dir_resp_cmp(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_fileio_read_dir_resp_t &lhs,
                              const sbp_msg_fileio_read_dir_resp_t &rhs) {
  return sbp_msg_fileio_read_dir_resp_cmp(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_fileio_read_dir_resp_t &lhs,
                             const sbp_msg_fileio_read_dir_resp_t &rhs) {
  return sbp_msg_fileio_read_dir_resp_cmp(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_fileio_read_dir_resp_t &lhs,
                              const sbp_msg_fileio_read_dir_resp_t &rhs) {
  return sbp_msg_fileio_read_dir_resp_cmp(&lhs, &rhs) >= 0;
}

#endif  // ifdef __cplusplus

#endif /* LIBSBP_V4_FILE_IO_MSG_FILEIO_READ_DIR_RESP_H */
