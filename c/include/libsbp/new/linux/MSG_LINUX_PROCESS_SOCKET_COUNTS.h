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
 * Automatically generated from yaml/swiftnav/sbp/linux.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_NEW_LINUX_MSG_LINUX_PROCESS_SOCKET_COUNTS_MESSAGES_H
#define LIBSBP_NEW_LINUX_MSG_LINUX_PROCESS_SOCKET_COUNTS_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/linux_macros.h>
#include <libsbp/new/string/double_null_terminated.h>
#include <libsbp/new/string/multipart.h>
#include <libsbp/new/string/null_terminated.h>
#include <libsbp/new/string/unterminated.h>

#ifdef __cplusplus
extern "C" {
#endif

struct sbp_state;
/******************************************************************************
 *
 * SBP_MSG_LINUX_PROCESS_SOCKET_COUNTS
 *
 *****************************************************************************/
/** A list of processes with high socket counts
 *
 * Top 10 list of processes with high socket counts.
 */
typedef struct {
  /**
   * sequence of this status message, values from 0-9
   */
  u8 index;

  /**
   * the PID of the process in question
   */
  u16 pid;

  /**
   * the number of sockets the process is using
   */
  u16 socket_count;

  /**
   * A bitfield indicating the socket types used: 0x1 (tcp), 0x2 (udp), 0x4
   * (unix stream), 0x8 (unix dgram), 0x10 (netlink), and 0x8000 (unknown)
   */
  u16 socket_types;

  /**
   * A bitfield indicating the socket states: 0x1 (established), 0x2 (syn-sent),
   * 0x4 (syn-recv), 0x8 (fin-wait-1), 0x10 (fin-wait-2), 0x20 (time-wait), 0x40
   * (closed), 0x80 (close-wait), 0x100 (last-ack), 0x200 (listen), 0x400
   * (closing), 0x800 (unconnected), and 0x8000 (unknown)
   */
  u16 socket_states;

  /**
   * the command line of the process in question
   */
  sbp_unterminated_string_t cmdline;
} sbp_msg_linux_process_socket_counts_t;

/**
 * Initialise sbp_msg_linux_process_socket_counts_t::cmdline to empty
 *
 * @param msg sbp_msg_linux_process_socket_counts_t instance
 */
void sbp_msg_linux_process_socket_counts_t_cmdline_init(
    sbp_unterminated_string_t *s);

/**
 * Test sbp_msg_linux_process_socket_counts_t::cmdline for validity
 *
 * @param msg sbp_msg_linux_process_socket_counts_t instance
 * @return true is sbp_msg_linux_process_socket_counts_t::cmdline is valid for
 * encoding purposes, false otherwise
 */
bool sbp_msg_linux_process_socket_counts_t_cmdline_valid(
    const sbp_unterminated_string_t *s);

/**
 * Tests 2 instances of sbp_msg_linux_process_socket_counts_t::cmdline for
 * equality
 *
 * Returns a value with the same definitions as #strcmp from the C standard
 * library
 *
 * @param a sbp_msg_linux_process_socket_counts_t instance
 * @param b sbp_msg_linux_process_socket_counts_t instance
 * @return 0 if equal, <0 if a<b, >0 if a>b
 */
int sbp_msg_linux_process_socket_counts_t_cmdline_strcmp(
    const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b);

/**
 * Get the encoded size of sbp_msg_linux_process_socket_counts_t::cmdline
 *
 * @param msg sbp_msg_linux_process_socket_counts_t instance
 * @return Size of sbp_msg_linux_process_socket_counts_t::cmdline in wire
 * representation
 */
uint8_t sbp_msg_linux_process_socket_counts_t_cmdline_packed_len(
    const sbp_unterminated_string_t *s);

/**
 * Query sbp_msg_linux_process_socket_counts_t::cmdline for remaining space
 *
 * Returns the number of bytes (not including NULL terminator) which can be
 * added to sbp_msg_linux_process_socket_counts_t::cmdline before it exceeds the
 * maximum size of the field in wire representation
 *
 * @param msg sbp_msg_linux_process_socket_counts_t instance
 * @return Maximum number of bytes that can be appended to the existing string
 */
uint8_t sbp_msg_linux_process_socket_counts_t_cmdline_space_remaining(
    const sbp_unterminated_string_t *s);
/**
 * Set sbp_msg_linux_process_socket_counts_t::cmdline
 *
 * Erase any existing content and replace with the specified string
 *
 * This function will return true if the new string was successfully applied. If
 * the specified string is longer than can be represented in wire encoding this
 * function will return false
 *
 * @param msg sbp_msg_linux_process_socket_counts_t instance
 * @param new_str New string
 * @return true on success, false otherwise
 */
bool sbp_msg_linux_process_socket_counts_t_cmdline_set(
    sbp_unterminated_string_t *s, const char *new_str);

/**
 * Set sbp_msg_linux_process_socket_counts_t::cmdline with printf style
 * formatting
 *
 * Erase any existing content and replace with the formatted string
 *
 * This function will return true if the new string was successfully applied. If
 * the operation would end up overflowing the maximum size of this field in wire
 * encoding the existing contents will be erased and this function will return
 * false.
 *
 * @param msg sbp_msg_linux_process_socket_counts_t instance
 * @param fmt printf style format string
 * @return true on success, false otherwise
 */
bool sbp_msg_linux_process_socket_counts_t_cmdline_printf(
    sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);

/**
 * Set sbp_msg_linux_process_socket_counts_t::cmdline with printf style
 * formatting
 *
 * Identical to #sbp_msg_linux_process_socket_counts_t_cmdline_printf except it
 * takes a va_list argument
 *
 * @param msg sbp_msg_linux_process_socket_counts_t instance
 * @param fmt printf style format string
 * @param ap Argument list
 * @return true on success, false otherwise
 */
bool sbp_msg_linux_process_socket_counts_t_cmdline_vprintf(
    sbp_unterminated_string_t *s, const char *fmt, va_list ap);

/**
 * Append sbp_msg_linux_process_socket_counts_t::cmdline with printf style
 * formatting
 *
 * The new string will be appended to the existing contents of the string (if
 * any). If the operation would end up overflowing the maximum size of this
 * field in wire encoding the existing contents will be unmodified and this
 * function will return false.
 *
 * @param msg sbp_msg_linux_process_socket_counts_t instance
 * @param fmt printf style format string
 * @return true on success, false otherwise
 */
bool sbp_msg_linux_process_socket_counts_t_cmdline_append_printf(
    sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);

/**
 * Append sbp_msg_linux_process_socket_counts_t::cmdline with printf style
 * formatting
 *
 * Identical to #sbp_msg_linux_process_socket_counts_t_cmdline_append_printf
 * except it takes a va_list argument
 *
 * @param msg sbp_msg_linux_process_socket_counts_t instance
 * @param fmt printf style format string
 * @param ap Argument list
 * @return true on success, false otherwise
 *
 */
bool sbp_msg_linux_process_socket_counts_t_cmdline_append_vprintf(
    sbp_unterminated_string_t *s, const char *fmt, va_list ap);

/**
 * Obtain the string value from sbp_msg_linux_process_socket_counts_t::cmdline
 *
 * @param msg sbp_msg_linux_process_socket_counts_t instance
 * @return String contents
 */
const char *sbp_msg_linux_process_socket_counts_t_cmdline_get(
    const sbp_unterminated_string_t *s);

/**
 * Obtain the length of sbp_msg_linux_process_socket_counts_t::cmdline
 *
 * The returned value does not include the NULL terminator.
 *
 * @param msg sbp_msg_linux_process_socket_counts_t instance
 * @return Length of section
 */
uint8_t sbp_msg_linux_process_socket_counts_t_cmdline_section_strlen(
    const sbp_unterminated_string_t *s, uint8_t section);

/**
 * Get encoded size of an instance of sbp_msg_linux_process_socket_counts_t
 *
 * @param msg sbp_msg_linux_process_socket_counts_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_linux_process_socket_counts_t(
    const sbp_msg_linux_process_socket_counts_t *msg);

/**
 * Encode an instance of sbp_msg_linux_process_socket_counts_t to wire
 * representation
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
 * @param msg Instance of sbp_msg_linux_process_socket_counts_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_linux_process_socket_counts_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_linux_process_socket_counts_t *msg);

/**
 * Decode an instance of sbp_msg_linux_process_socket_counts_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_linux_process_socket_counts_t message to the given instance. The
 * caller must specify the length of the buffer in the \p len parameter. If
 * non-null the number of bytes read from the buffer will be returned in \p
 * n_read.
 *
 * @param buf Wire representation of the sbp_msg_linux_process_socket_counts_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_linux_process_socket_counts_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_linux_process_socket_counts_t *msg);
/**
 * Send an instance of sbp_msg_linux_process_socket_counts_t with the given
 * write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_linux_process_socket_counts_t
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
s8 sbp_send_sbp_msg_linux_process_socket_counts_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_linux_process_socket_counts_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_linux_process_socket_counts_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_linux_process_socket_counts_t instance
 * @param b sbp_msg_linux_process_socket_counts_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_linux_process_socket_counts_t(
    const sbp_msg_linux_process_socket_counts_t *a,
    const sbp_msg_linux_process_socket_counts_t *b);

#ifdef __cplusplus
}
static inline bool operator==(
    const sbp_msg_linux_process_socket_counts_t &lhs,
    const sbp_msg_linux_process_socket_counts_t &rhs) {
  return sbp_cmp_sbp_msg_linux_process_socket_counts_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(
    const sbp_msg_linux_process_socket_counts_t &lhs,
    const sbp_msg_linux_process_socket_counts_t &rhs) {
  return sbp_cmp_sbp_msg_linux_process_socket_counts_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_linux_process_socket_counts_t &lhs,
                             const sbp_msg_linux_process_socket_counts_t &rhs) {
  return sbp_cmp_sbp_msg_linux_process_socket_counts_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(
    const sbp_msg_linux_process_socket_counts_t &lhs,
    const sbp_msg_linux_process_socket_counts_t &rhs) {
  return sbp_cmp_sbp_msg_linux_process_socket_counts_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_linux_process_socket_counts_t &lhs,
                             const sbp_msg_linux_process_socket_counts_t &rhs) {
  return sbp_cmp_sbp_msg_linux_process_socket_counts_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(
    const sbp_msg_linux_process_socket_counts_t &lhs,
    const sbp_msg_linux_process_socket_counts_t &rhs) {
  return sbp_cmp_sbp_msg_linux_process_socket_counts_t(&lhs, &rhs) >= 0;
}

#endif

#endif /* LIBSBP_NEW_LINUX_MESSAGES_H */
