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
 * Automatically generated from yaml/swiftnav/sbp/linux.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_NEW_LINUX_MESSAGES_H
#define LIBSBP_NEW_LINUX_MESSAGES_H

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

/** List CPU state on the system. DEPRECATED
 *
 * This message indicates the process state of the top 10 heaviest consumers of
 * CPU on the system.
 */
typedef struct {
  /**
   * sequence of this status message, values from 0-9
   */
  u8 index;

  /**
   * the PID of the process
   */
  u16 pid;

  /**
   * percent of cpu used, expressed as a fraction of 256
   */
  u8 pcpu;

  /**
   * fixed length string representing the thread name
   */
  char tname[15];

  /**
   * the command line (as much as it fits in the remaining packet)
   */
  sbp_unterminated_string_t cmdline;
} sbp_msg_linux_cpu_state_dep_a_t;
void sbp_msg_linux_cpu_state_dep_a_t_cmdline_init(sbp_unterminated_string_t *s);
bool sbp_msg_linux_cpu_state_dep_a_t_cmdline_valid(
    const sbp_unterminated_string_t *s);
int sbp_msg_linux_cpu_state_dep_a_t_cmdline_strcmp(
    const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b);
uint8_t sbp_msg_linux_cpu_state_dep_a_t_cmdline_packed_len(
    const sbp_unterminated_string_t *s);
uint8_t sbp_msg_linux_cpu_state_dep_a_t_cmdline_space_remaining(
    const sbp_unterminated_string_t *s);
bool sbp_msg_linux_cpu_state_dep_a_t_cmdline_set(sbp_unterminated_string_t *s,
                                                 const char *new_str);
bool sbp_msg_linux_cpu_state_dep_a_t_cmdline_printf(
    sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_linux_cpu_state_dep_a_t_cmdline_vprintf(
    sbp_unterminated_string_t *s, const char *fmt, va_list ap);
bool sbp_msg_linux_cpu_state_dep_a_t_cmdline_append_printf(
    sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_linux_cpu_state_dep_a_t_cmdline_append_vprintf(
    sbp_unterminated_string_t *s, const char *fmt, va_list ap);
const char *sbp_msg_linux_cpu_state_dep_a_t_cmdline_get(
    const sbp_unterminated_string_t *s);

/**
 * Get encoded size of an instance of sbp_msg_linux_cpu_state_dep_a_t
 *
 * @param msg sbp_msg_linux_cpu_state_dep_a_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_linux_cpu_state_dep_a_t(
    const sbp_msg_linux_cpu_state_dep_a_t *msg);

/**
 * Encode an instance of sbp_msg_linux_cpu_state_dep_a_t to wire representation
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
 * @param msg Instance of sbp_msg_linux_cpu_state_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_linux_cpu_state_dep_a_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_linux_cpu_state_dep_a_t *msg);

/**
 * Decode an instance of sbp_msg_linux_cpu_state_dep_a_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_linux_cpu_state_dep_a_t message to the given instance. The caller
 * must specify the length of the buffer in the \p len parameter. If non-null
 * the number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_linux_cpu_state_dep_a_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_linux_cpu_state_dep_a_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_linux_cpu_state_dep_a_t *msg);
/**
 * Send an instance of sbp_msg_linux_cpu_state_dep_a_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_linux_cpu_state_dep_a_t
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
s8 sbp_send_sbp_msg_linux_cpu_state_dep_a_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_linux_cpu_state_dep_a_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_linux_cpu_state_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_linux_cpu_state_dep_a_t instance
 * @param b sbp_msg_linux_cpu_state_dep_a_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_linux_cpu_state_dep_a_t(
    const sbp_msg_linux_cpu_state_dep_a_t *a,
    const sbp_msg_linux_cpu_state_dep_a_t *b);

/** List memory state on the system. DEPRECATED
 *
 * This message indicates the process state of the top 10 heaviest consumers of
 * memory on the system.
 */
typedef struct {
  /**
   * sequence of this status message, values from 0-9
   */
  u8 index;

  /**
   * the PID of the process
   */
  u16 pid;

  /**
   * percent of memory used, expressed as a fraction of 256
   */
  u8 pmem;

  /**
   * fixed length string representing the thread name
   */
  char tname[15];

  /**
   * the command line (as much as it fits in the remaining packet)
   */
  sbp_unterminated_string_t cmdline;
} sbp_msg_linux_mem_state_dep_a_t;
void sbp_msg_linux_mem_state_dep_a_t_cmdline_init(sbp_unterminated_string_t *s);
bool sbp_msg_linux_mem_state_dep_a_t_cmdline_valid(
    const sbp_unterminated_string_t *s);
int sbp_msg_linux_mem_state_dep_a_t_cmdline_strcmp(
    const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b);
uint8_t sbp_msg_linux_mem_state_dep_a_t_cmdline_packed_len(
    const sbp_unterminated_string_t *s);
uint8_t sbp_msg_linux_mem_state_dep_a_t_cmdline_space_remaining(
    const sbp_unterminated_string_t *s);
bool sbp_msg_linux_mem_state_dep_a_t_cmdline_set(sbp_unterminated_string_t *s,
                                                 const char *new_str);
bool sbp_msg_linux_mem_state_dep_a_t_cmdline_printf(
    sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_linux_mem_state_dep_a_t_cmdline_vprintf(
    sbp_unterminated_string_t *s, const char *fmt, va_list ap);
bool sbp_msg_linux_mem_state_dep_a_t_cmdline_append_printf(
    sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_linux_mem_state_dep_a_t_cmdline_append_vprintf(
    sbp_unterminated_string_t *s, const char *fmt, va_list ap);
const char *sbp_msg_linux_mem_state_dep_a_t_cmdline_get(
    const sbp_unterminated_string_t *s);

/**
 * Get encoded size of an instance of sbp_msg_linux_mem_state_dep_a_t
 *
 * @param msg sbp_msg_linux_mem_state_dep_a_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_linux_mem_state_dep_a_t(
    const sbp_msg_linux_mem_state_dep_a_t *msg);

/**
 * Encode an instance of sbp_msg_linux_mem_state_dep_a_t to wire representation
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
 * @param msg Instance of sbp_msg_linux_mem_state_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_linux_mem_state_dep_a_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_linux_mem_state_dep_a_t *msg);

/**
 * Decode an instance of sbp_msg_linux_mem_state_dep_a_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_linux_mem_state_dep_a_t message to the given instance. The caller
 * must specify the length of the buffer in the \p len parameter. If non-null
 * the number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_linux_mem_state_dep_a_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_linux_mem_state_dep_a_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_linux_mem_state_dep_a_t *msg);
/**
 * Send an instance of sbp_msg_linux_mem_state_dep_a_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_linux_mem_state_dep_a_t
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
s8 sbp_send_sbp_msg_linux_mem_state_dep_a_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_linux_mem_state_dep_a_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_linux_mem_state_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_linux_mem_state_dep_a_t instance
 * @param b sbp_msg_linux_mem_state_dep_a_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_linux_mem_state_dep_a_t(
    const sbp_msg_linux_mem_state_dep_a_t *a,
    const sbp_msg_linux_mem_state_dep_a_t *b);

/** CPU, Memory and Process Starts/Stops. DEPRECATED
 *
 * This presents a summary of CPU and memory utilization.
 */
typedef struct {
  /**
   * total system memory
   */
  u16 mem_total;

  /**
   * percent of total cpu currently utilized
   */
  u8 pcpu;

  /**
   * percent of total memory currently utilized
   */
  u8 pmem;

  /**
   * number of processes that started during collection phase
   */
  u16 procs_starting;

  /**
   * number of processes that stopped during collection phase
   */
  u16 procs_stopping;

  /**
   * the count of processes on the system
   */
  u16 pid_count;
} sbp_msg_linux_sys_state_dep_a_t;

/**
 * Get encoded size of an instance of sbp_msg_linux_sys_state_dep_a_t
 *
 * @param msg sbp_msg_linux_sys_state_dep_a_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_linux_sys_state_dep_a_t(
    const sbp_msg_linux_sys_state_dep_a_t *msg);

/**
 * Encode an instance of sbp_msg_linux_sys_state_dep_a_t to wire representation
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
 * @param msg Instance of sbp_msg_linux_sys_state_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_linux_sys_state_dep_a_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_linux_sys_state_dep_a_t *msg);

/**
 * Decode an instance of sbp_msg_linux_sys_state_dep_a_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_linux_sys_state_dep_a_t message to the given instance. The caller
 * must specify the length of the buffer in the \p len parameter. If non-null
 * the number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_linux_sys_state_dep_a_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_linux_sys_state_dep_a_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_linux_sys_state_dep_a_t *msg);
/**
 * Send an instance of sbp_msg_linux_sys_state_dep_a_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_linux_sys_state_dep_a_t
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
s8 sbp_send_sbp_msg_linux_sys_state_dep_a_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_linux_sys_state_dep_a_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_linux_sys_state_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_linux_sys_state_dep_a_t instance
 * @param b sbp_msg_linux_sys_state_dep_a_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_linux_sys_state_dep_a_t(
    const sbp_msg_linux_sys_state_dep_a_t *a,
    const sbp_msg_linux_sys_state_dep_a_t *b);

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
void sbp_msg_linux_process_socket_counts_t_cmdline_init(
    sbp_unterminated_string_t *s);
bool sbp_msg_linux_process_socket_counts_t_cmdline_valid(
    const sbp_unterminated_string_t *s);
int sbp_msg_linux_process_socket_counts_t_cmdline_strcmp(
    const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b);
uint8_t sbp_msg_linux_process_socket_counts_t_cmdline_packed_len(
    const sbp_unterminated_string_t *s);
uint8_t sbp_msg_linux_process_socket_counts_t_cmdline_space_remaining(
    const sbp_unterminated_string_t *s);
bool sbp_msg_linux_process_socket_counts_t_cmdline_set(
    sbp_unterminated_string_t *s, const char *new_str);
bool sbp_msg_linux_process_socket_counts_t_cmdline_printf(
    sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_linux_process_socket_counts_t_cmdline_vprintf(
    sbp_unterminated_string_t *s, const char *fmt, va_list ap);
bool sbp_msg_linux_process_socket_counts_t_cmdline_append_printf(
    sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_linux_process_socket_counts_t_cmdline_append_vprintf(
    sbp_unterminated_string_t *s, const char *fmt, va_list ap);
const char *sbp_msg_linux_process_socket_counts_t_cmdline_get(
    const sbp_unterminated_string_t *s);

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

/** A list of processes with deep socket queues
 *
 * Top 10 list of sockets with deep queues.
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
   * the total amount of receive data queued for this process
   */
  u16 recv_queued;

  /**
   * the total amount of send data queued for this process
   */
  u16 send_queued;

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
   * Address of the largest queue, remote or local depending on the
   * directionality of the connection.
   */
  char address_of_largest[64];

  /**
   * the command line of the process in question
   */
  sbp_unterminated_string_t cmdline;
} sbp_msg_linux_process_socket_queues_t;
void sbp_msg_linux_process_socket_queues_t_cmdline_init(
    sbp_unterminated_string_t *s);
bool sbp_msg_linux_process_socket_queues_t_cmdline_valid(
    const sbp_unterminated_string_t *s);
int sbp_msg_linux_process_socket_queues_t_cmdline_strcmp(
    const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b);
uint8_t sbp_msg_linux_process_socket_queues_t_cmdline_packed_len(
    const sbp_unterminated_string_t *s);
uint8_t sbp_msg_linux_process_socket_queues_t_cmdline_space_remaining(
    const sbp_unterminated_string_t *s);
bool sbp_msg_linux_process_socket_queues_t_cmdline_set(
    sbp_unterminated_string_t *s, const char *new_str);
bool sbp_msg_linux_process_socket_queues_t_cmdline_printf(
    sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_linux_process_socket_queues_t_cmdline_vprintf(
    sbp_unterminated_string_t *s, const char *fmt, va_list ap);
bool sbp_msg_linux_process_socket_queues_t_cmdline_append_printf(
    sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_linux_process_socket_queues_t_cmdline_append_vprintf(
    sbp_unterminated_string_t *s, const char *fmt, va_list ap);
const char *sbp_msg_linux_process_socket_queues_t_cmdline_get(
    const sbp_unterminated_string_t *s);

/**
 * Get encoded size of an instance of sbp_msg_linux_process_socket_queues_t
 *
 * @param msg sbp_msg_linux_process_socket_queues_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_linux_process_socket_queues_t(
    const sbp_msg_linux_process_socket_queues_t *msg);

/**
 * Encode an instance of sbp_msg_linux_process_socket_queues_t to wire
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
 * @param msg Instance of sbp_msg_linux_process_socket_queues_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_linux_process_socket_queues_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_linux_process_socket_queues_t *msg);

/**
 * Decode an instance of sbp_msg_linux_process_socket_queues_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_linux_process_socket_queues_t message to the given instance. The
 * caller must specify the length of the buffer in the \p len parameter. If
 * non-null the number of bytes read from the buffer will be returned in \p
 * n_read.
 *
 * @param buf Wire representation of the sbp_msg_linux_process_socket_queues_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_linux_process_socket_queues_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_linux_process_socket_queues_t *msg);
/**
 * Send an instance of sbp_msg_linux_process_socket_queues_t with the given
 * write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_linux_process_socket_queues_t
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
s8 sbp_send_sbp_msg_linux_process_socket_queues_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_linux_process_socket_queues_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_linux_process_socket_queues_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_linux_process_socket_queues_t instance
 * @param b sbp_msg_linux_process_socket_queues_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_linux_process_socket_queues_t(
    const sbp_msg_linux_process_socket_queues_t *a,
    const sbp_msg_linux_process_socket_queues_t *b);

/** Summary of socket usage across the system
 *
 * Summaries the socket usage across the system.
 */
typedef struct {
  /**
   * average socket queue depths across all sockets on the system
   */
  u32 avg_queue_depth;

  /**
   * the max queue depth seen within the reporting period
   */
  u32 max_queue_depth;

  /**
   * A count for each socket type reported in the `socket_types_reported` field,
   * the first entry corresponds to the first enabled bit in `types_reported`.
   */
  u16 socket_state_counts[16];

  /**
   * A count for each socket type reported in the `socket_types_reported` field,
   * the first entry corresponds to the first enabled bit in `types_reported`.
   */
  u16 socket_type_counts[16];
} sbp_msg_linux_socket_usage_t;

/**
 * Get encoded size of an instance of sbp_msg_linux_socket_usage_t
 *
 * @param msg sbp_msg_linux_socket_usage_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_linux_socket_usage_t(
    const sbp_msg_linux_socket_usage_t *msg);

/**
 * Encode an instance of sbp_msg_linux_socket_usage_t to wire representation
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
 * @param msg Instance of sbp_msg_linux_socket_usage_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_linux_socket_usage_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_linux_socket_usage_t *msg);

/**
 * Decode an instance of sbp_msg_linux_socket_usage_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_linux_socket_usage_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_linux_socket_usage_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_linux_socket_usage_t(const uint8_t *buf, uint8_t len,
                                           uint8_t *n_read,
                                           sbp_msg_linux_socket_usage_t *msg);
/**
 * Send an instance of sbp_msg_linux_socket_usage_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_linux_socket_usage_t
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
s8 sbp_send_sbp_msg_linux_socket_usage_t(
    struct sbp_state *s, u16 sender_id, const sbp_msg_linux_socket_usage_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_linux_socket_usage_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_linux_socket_usage_t instance
 * @param b sbp_msg_linux_socket_usage_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_linux_socket_usage_t(const sbp_msg_linux_socket_usage_t *a,
                                         const sbp_msg_linux_socket_usage_t *b);

/** Summary of processes with large amounts of open file descriptors
 *
 * Top 10 list of processes with a large number of open file descriptors.
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
   * a count of the number of file descriptors opened by the process
   */
  u16 fd_count;

  /**
   * the command line of the process in question
   */
  sbp_unterminated_string_t cmdline;
} sbp_msg_linux_process_fd_count_t;
void sbp_msg_linux_process_fd_count_t_cmdline_init(
    sbp_unterminated_string_t *s);
bool sbp_msg_linux_process_fd_count_t_cmdline_valid(
    const sbp_unterminated_string_t *s);
int sbp_msg_linux_process_fd_count_t_cmdline_strcmp(
    const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b);
uint8_t sbp_msg_linux_process_fd_count_t_cmdline_packed_len(
    const sbp_unterminated_string_t *s);
uint8_t sbp_msg_linux_process_fd_count_t_cmdline_space_remaining(
    const sbp_unterminated_string_t *s);
bool sbp_msg_linux_process_fd_count_t_cmdline_set(sbp_unterminated_string_t *s,
                                                  const char *new_str);
bool sbp_msg_linux_process_fd_count_t_cmdline_printf(
    sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_linux_process_fd_count_t_cmdline_vprintf(
    sbp_unterminated_string_t *s, const char *fmt, va_list ap);
bool sbp_msg_linux_process_fd_count_t_cmdline_append_printf(
    sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_linux_process_fd_count_t_cmdline_append_vprintf(
    sbp_unterminated_string_t *s, const char *fmt, va_list ap);
const char *sbp_msg_linux_process_fd_count_t_cmdline_get(
    const sbp_unterminated_string_t *s);

/**
 * Get encoded size of an instance of sbp_msg_linux_process_fd_count_t
 *
 * @param msg sbp_msg_linux_process_fd_count_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_linux_process_fd_count_t(
    const sbp_msg_linux_process_fd_count_t *msg);

/**
 * Encode an instance of sbp_msg_linux_process_fd_count_t to wire representation
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
 * @param msg Instance of sbp_msg_linux_process_fd_count_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_linux_process_fd_count_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_linux_process_fd_count_t *msg);

/**
 * Decode an instance of sbp_msg_linux_process_fd_count_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_linux_process_fd_count_t message to the given instance. The caller
 * must specify the length of the buffer in the \p len parameter. If non-null
 * the number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_linux_process_fd_count_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_linux_process_fd_count_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_linux_process_fd_count_t *msg);
/**
 * Send an instance of sbp_msg_linux_process_fd_count_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_linux_process_fd_count_t
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
s8 sbp_send_sbp_msg_linux_process_fd_count_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_linux_process_fd_count_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_linux_process_fd_count_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_linux_process_fd_count_t instance
 * @param b sbp_msg_linux_process_fd_count_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_linux_process_fd_count_t(
    const sbp_msg_linux_process_fd_count_t *a,
    const sbp_msg_linux_process_fd_count_t *b);

/** Summary of open file descriptors on the system
 *
 * Summary of open file descriptors on the system.
 */
typedef struct {
  /**
   * count of total FDs open on the system
   */
  u32 sys_fd_count;

  /**
   * A null delimited list of strings which alternates between a string
   * representation of the process count and the file name whose count it being
   * reported.  That is, in C string syntax
   * "32\0/var/log/syslog\012\0/tmp/foo\0" with the end of the list being 2 NULL
   * terminators in a row.
   */
  sbp_double_null_terminated_string_t most_opened;
} sbp_msg_linux_process_fd_summary_t;
void sbp_msg_linux_process_fd_summary_t_most_opened_init(
    sbp_double_null_terminated_string_t *s);
bool sbp_msg_linux_process_fd_summary_t_most_opened_valid(
    const sbp_double_null_terminated_string_t *s);
int sbp_msg_linux_process_fd_summary_t_most_opened_strcmp(
    const sbp_double_null_terminated_string_t *a,
    const sbp_double_null_terminated_string_t *b);
uint8_t sbp_msg_linux_process_fd_summary_t_most_opened_packed_len(
    const sbp_double_null_terminated_string_t *s);
uint8_t sbp_msg_linux_process_fd_summary_t_most_opened_space_remaining(
    const sbp_double_null_terminated_string_t *s);
uint8_t sbp_msg_linux_process_fd_summary_t_most_opened_count_sections(
    const sbp_double_null_terminated_string_t *s);
bool sbp_msg_linux_process_fd_summary_t_most_opened_add_section(
    sbp_double_null_terminated_string_t *s, const char *new_str);
bool sbp_msg_linux_process_fd_summary_t_most_opened_add_section_printf(
    sbp_double_null_terminated_string_t *s, const char *fmt, ...)
    SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_linux_process_fd_summary_t_most_opened_add_section_vprintf(
    sbp_double_null_terminated_string_t *s, const char *fmt, va_list ap);
bool sbp_msg_linux_process_fd_summary_t_most_opened_append(
    sbp_double_null_terminated_string_t *s, const char *str);
bool sbp_msg_linux_process_fd_summary_t_most_opened_append_printf(
    sbp_double_null_terminated_string_t *s, const char *fmt, ...)
    SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_linux_process_fd_summary_t_most_opened_append_vprintf(
    sbp_double_null_terminated_string_t *s, const char *fmt, va_list ap);
const char *sbp_msg_linux_process_fd_summary_t_most_opened_get_section(
    const sbp_double_null_terminated_string_t *s, uint8_t section);
uint8_t sbp_msg_linux_process_fd_summary_t_most_opened_section_strlen(
    const sbp_double_null_terminated_string_t *s, uint8_t section);

/**
 * Get encoded size of an instance of sbp_msg_linux_process_fd_summary_t
 *
 * @param msg sbp_msg_linux_process_fd_summary_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_linux_process_fd_summary_t(
    const sbp_msg_linux_process_fd_summary_t *msg);

/**
 * Encode an instance of sbp_msg_linux_process_fd_summary_t to wire
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
 * @param msg Instance of sbp_msg_linux_process_fd_summary_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_linux_process_fd_summary_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_linux_process_fd_summary_t *msg);

/**
 * Decode an instance of sbp_msg_linux_process_fd_summary_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_linux_process_fd_summary_t message to the given instance. The caller
 * must specify the length of the buffer in the \p len parameter. If non-null
 * the number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_linux_process_fd_summary_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_linux_process_fd_summary_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_linux_process_fd_summary_t *msg);
/**
 * Send an instance of sbp_msg_linux_process_fd_summary_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_linux_process_fd_summary_t
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
s8 sbp_send_sbp_msg_linux_process_fd_summary_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_linux_process_fd_summary_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_linux_process_fd_summary_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_linux_process_fd_summary_t instance
 * @param b sbp_msg_linux_process_fd_summary_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_linux_process_fd_summary_t(
    const sbp_msg_linux_process_fd_summary_t *a,
    const sbp_msg_linux_process_fd_summary_t *b);

/** List CPU state on the system
 *
 * This message indicates the process state of the top 10 heaviest consumers of
 * CPU on the system, including a timestamp.
 */
typedef struct {
  /**
   * sequence of this status message, values from 0-9
   */
  u8 index;

  /**
   * the PID of the process
   */
  u16 pid;

  /**
   * percent of CPU used, expressed as a fraction of 256
   */
  u8 pcpu;

  /**
   * timestamp of message, refer to flags field for how to interpret
   */
  u32 time;

  /**
   * flags
   */
  u8 flags;

  /**
   * fixed length string representing the thread name
   */
  char tname[15];

  /**
   * the command line (as much as it fits in the remaining packet)
   */
  sbp_unterminated_string_t cmdline;
} sbp_msg_linux_cpu_state_t;
void sbp_msg_linux_cpu_state_t_cmdline_init(sbp_unterminated_string_t *s);
bool sbp_msg_linux_cpu_state_t_cmdline_valid(
    const sbp_unterminated_string_t *s);
int sbp_msg_linux_cpu_state_t_cmdline_strcmp(
    const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b);
uint8_t sbp_msg_linux_cpu_state_t_cmdline_packed_len(
    const sbp_unterminated_string_t *s);
uint8_t sbp_msg_linux_cpu_state_t_cmdline_space_remaining(
    const sbp_unterminated_string_t *s);
bool sbp_msg_linux_cpu_state_t_cmdline_set(sbp_unterminated_string_t *s,
                                           const char *new_str);
bool sbp_msg_linux_cpu_state_t_cmdline_printf(sbp_unterminated_string_t *s,
                                              const char *fmt, ...)
    SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_linux_cpu_state_t_cmdline_vprintf(sbp_unterminated_string_t *s,
                                               const char *fmt, va_list ap);
bool sbp_msg_linux_cpu_state_t_cmdline_append_printf(
    sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_linux_cpu_state_t_cmdline_append_vprintf(
    sbp_unterminated_string_t *s, const char *fmt, va_list ap);
const char *sbp_msg_linux_cpu_state_t_cmdline_get(
    const sbp_unterminated_string_t *s);

/**
 * Get encoded size of an instance of sbp_msg_linux_cpu_state_t
 *
 * @param msg sbp_msg_linux_cpu_state_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_linux_cpu_state_t(
    const sbp_msg_linux_cpu_state_t *msg);

/**
 * Encode an instance of sbp_msg_linux_cpu_state_t to wire representation
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
 * @param msg Instance of sbp_msg_linux_cpu_state_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_linux_cpu_state_t(uint8_t *buf, uint8_t len,
                                        uint8_t *n_written,
                                        const sbp_msg_linux_cpu_state_t *msg);

/**
 * Decode an instance of sbp_msg_linux_cpu_state_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_linux_cpu_state_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_linux_cpu_state_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_linux_cpu_state_t(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_linux_cpu_state_t *msg);
/**
 * Send an instance of sbp_msg_linux_cpu_state_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_linux_cpu_state_t
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
s8 sbp_send_sbp_msg_linux_cpu_state_t(struct sbp_state *s, u16 sender_id,
                                      const sbp_msg_linux_cpu_state_t *msg,
                                      s32 (*write)(u8 *buff, u32 n,
                                                   void *context));

/**
 * Compare two instances of sbp_msg_linux_cpu_state_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_linux_cpu_state_t instance
 * @param b sbp_msg_linux_cpu_state_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_linux_cpu_state_t(const sbp_msg_linux_cpu_state_t *a,
                                      const sbp_msg_linux_cpu_state_t *b);

/** List memory state on the system
 *
 * This message indicates the process state of the top 10 heaviest consumers of
 * memory on the system, including a timestamp.
 */
typedef struct {
  /**
   * sequence of this status message, values from 0-9
   */
  u8 index;

  /**
   * the PID of the process
   */
  u16 pid;

  /**
   * percent of memory used, expressed as a fraction of 256
   */
  u8 pmem;

  /**
   * timestamp of message, refer to flags field for how to interpret
   */
  u32 time;

  /**
   * flags
   */
  u8 flags;

  /**
   * fixed length string representing the thread name
   */
  char tname[15];

  /**
   * the command line (as much as it fits in the remaining packet)
   */
  sbp_unterminated_string_t cmdline;
} sbp_msg_linux_mem_state_t;
void sbp_msg_linux_mem_state_t_cmdline_init(sbp_unterminated_string_t *s);
bool sbp_msg_linux_mem_state_t_cmdline_valid(
    const sbp_unterminated_string_t *s);
int sbp_msg_linux_mem_state_t_cmdline_strcmp(
    const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b);
uint8_t sbp_msg_linux_mem_state_t_cmdline_packed_len(
    const sbp_unterminated_string_t *s);
uint8_t sbp_msg_linux_mem_state_t_cmdline_space_remaining(
    const sbp_unterminated_string_t *s);
bool sbp_msg_linux_mem_state_t_cmdline_set(sbp_unterminated_string_t *s,
                                           const char *new_str);
bool sbp_msg_linux_mem_state_t_cmdline_printf(sbp_unterminated_string_t *s,
                                              const char *fmt, ...)
    SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_linux_mem_state_t_cmdline_vprintf(sbp_unterminated_string_t *s,
                                               const char *fmt, va_list ap);
bool sbp_msg_linux_mem_state_t_cmdline_append_printf(
    sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_linux_mem_state_t_cmdline_append_vprintf(
    sbp_unterminated_string_t *s, const char *fmt, va_list ap);
const char *sbp_msg_linux_mem_state_t_cmdline_get(
    const sbp_unterminated_string_t *s);

/**
 * Get encoded size of an instance of sbp_msg_linux_mem_state_t
 *
 * @param msg sbp_msg_linux_mem_state_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_linux_mem_state_t(
    const sbp_msg_linux_mem_state_t *msg);

/**
 * Encode an instance of sbp_msg_linux_mem_state_t to wire representation
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
 * @param msg Instance of sbp_msg_linux_mem_state_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_linux_mem_state_t(uint8_t *buf, uint8_t len,
                                        uint8_t *n_written,
                                        const sbp_msg_linux_mem_state_t *msg);

/**
 * Decode an instance of sbp_msg_linux_mem_state_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_linux_mem_state_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_linux_mem_state_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_linux_mem_state_t(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_linux_mem_state_t *msg);
/**
 * Send an instance of sbp_msg_linux_mem_state_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_linux_mem_state_t
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
s8 sbp_send_sbp_msg_linux_mem_state_t(struct sbp_state *s, u16 sender_id,
                                      const sbp_msg_linux_mem_state_t *msg,
                                      s32 (*write)(u8 *buff, u32 n,
                                                   void *context));

/**
 * Compare two instances of sbp_msg_linux_mem_state_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_linux_mem_state_t instance
 * @param b sbp_msg_linux_mem_state_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_linux_mem_state_t(const sbp_msg_linux_mem_state_t *a,
                                      const sbp_msg_linux_mem_state_t *b);

/** CPU, Memory and Process Starts/Stops
 *
 * This presents a summary of CPU and memory utilization, including a timestamp.
 */
typedef struct {
  /**
   * total system memory, in MiB
   */
  u16 mem_total;

  /**
   * percent of CPU used, expressed as a fraction of 256
   */
  u8 pcpu;

  /**
   * percent of memory used, expressed as a fraction of 256
   */
  u8 pmem;

  /**
   * number of processes that started during collection phase
   */
  u16 procs_starting;

  /**
   * number of processes that stopped during collection phase
   */
  u16 procs_stopping;

  /**
   * the count of processes on the system
   */
  u16 pid_count;

  /**
   * timestamp of message, refer to flags field for how to interpret
   */
  u32 time;

  /**
   * flags
   */
  u8 flags;
} sbp_msg_linux_sys_state_t;

/**
 * Get encoded size of an instance of sbp_msg_linux_sys_state_t
 *
 * @param msg sbp_msg_linux_sys_state_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_linux_sys_state_t(
    const sbp_msg_linux_sys_state_t *msg);

/**
 * Encode an instance of sbp_msg_linux_sys_state_t to wire representation
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
 * @param msg Instance of sbp_msg_linux_sys_state_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_linux_sys_state_t(uint8_t *buf, uint8_t len,
                                        uint8_t *n_written,
                                        const sbp_msg_linux_sys_state_t *msg);

/**
 * Decode an instance of sbp_msg_linux_sys_state_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_linux_sys_state_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_linux_sys_state_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_linux_sys_state_t(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_linux_sys_state_t *msg);
/**
 * Send an instance of sbp_msg_linux_sys_state_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_linux_sys_state_t
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
s8 sbp_send_sbp_msg_linux_sys_state_t(struct sbp_state *s, u16 sender_id,
                                      const sbp_msg_linux_sys_state_t *msg,
                                      s32 (*write)(u8 *buff, u32 n,
                                                   void *context));

/**
 * Compare two instances of sbp_msg_linux_sys_state_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_linux_sys_state_t instance
 * @param b sbp_msg_linux_sys_state_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_linux_sys_state_t(const sbp_msg_linux_sys_state_t *a,
                                      const sbp_msg_linux_sys_state_t *b);

#ifdef __cplusplus
}
static inline bool operator==(const sbp_msg_linux_cpu_state_dep_a_t &lhs,
                              const sbp_msg_linux_cpu_state_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_linux_cpu_state_dep_a_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_linux_cpu_state_dep_a_t &lhs,
                              const sbp_msg_linux_cpu_state_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_linux_cpu_state_dep_a_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_linux_cpu_state_dep_a_t &lhs,
                             const sbp_msg_linux_cpu_state_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_linux_cpu_state_dep_a_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_linux_cpu_state_dep_a_t &lhs,
                              const sbp_msg_linux_cpu_state_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_linux_cpu_state_dep_a_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_linux_cpu_state_dep_a_t &lhs,
                             const sbp_msg_linux_cpu_state_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_linux_cpu_state_dep_a_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_linux_cpu_state_dep_a_t &lhs,
                              const sbp_msg_linux_cpu_state_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_linux_cpu_state_dep_a_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_linux_mem_state_dep_a_t &lhs,
                              const sbp_msg_linux_mem_state_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_linux_mem_state_dep_a_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_linux_mem_state_dep_a_t &lhs,
                              const sbp_msg_linux_mem_state_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_linux_mem_state_dep_a_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_linux_mem_state_dep_a_t &lhs,
                             const sbp_msg_linux_mem_state_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_linux_mem_state_dep_a_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_linux_mem_state_dep_a_t &lhs,
                              const sbp_msg_linux_mem_state_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_linux_mem_state_dep_a_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_linux_mem_state_dep_a_t &lhs,
                             const sbp_msg_linux_mem_state_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_linux_mem_state_dep_a_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_linux_mem_state_dep_a_t &lhs,
                              const sbp_msg_linux_mem_state_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_linux_mem_state_dep_a_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_linux_sys_state_dep_a_t &lhs,
                              const sbp_msg_linux_sys_state_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_linux_sys_state_dep_a_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_linux_sys_state_dep_a_t &lhs,
                              const sbp_msg_linux_sys_state_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_linux_sys_state_dep_a_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_linux_sys_state_dep_a_t &lhs,
                             const sbp_msg_linux_sys_state_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_linux_sys_state_dep_a_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_linux_sys_state_dep_a_t &lhs,
                              const sbp_msg_linux_sys_state_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_linux_sys_state_dep_a_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_linux_sys_state_dep_a_t &lhs,
                             const sbp_msg_linux_sys_state_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_linux_sys_state_dep_a_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_linux_sys_state_dep_a_t &lhs,
                              const sbp_msg_linux_sys_state_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_linux_sys_state_dep_a_t(&lhs, &rhs) >= 0;
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
static inline bool operator==(
    const sbp_msg_linux_process_socket_queues_t &lhs,
    const sbp_msg_linux_process_socket_queues_t &rhs) {
  return sbp_cmp_sbp_msg_linux_process_socket_queues_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(
    const sbp_msg_linux_process_socket_queues_t &lhs,
    const sbp_msg_linux_process_socket_queues_t &rhs) {
  return sbp_cmp_sbp_msg_linux_process_socket_queues_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_linux_process_socket_queues_t &lhs,
                             const sbp_msg_linux_process_socket_queues_t &rhs) {
  return sbp_cmp_sbp_msg_linux_process_socket_queues_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(
    const sbp_msg_linux_process_socket_queues_t &lhs,
    const sbp_msg_linux_process_socket_queues_t &rhs) {
  return sbp_cmp_sbp_msg_linux_process_socket_queues_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_linux_process_socket_queues_t &lhs,
                             const sbp_msg_linux_process_socket_queues_t &rhs) {
  return sbp_cmp_sbp_msg_linux_process_socket_queues_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(
    const sbp_msg_linux_process_socket_queues_t &lhs,
    const sbp_msg_linux_process_socket_queues_t &rhs) {
  return sbp_cmp_sbp_msg_linux_process_socket_queues_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_linux_socket_usage_t &lhs,
                              const sbp_msg_linux_socket_usage_t &rhs) {
  return sbp_cmp_sbp_msg_linux_socket_usage_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_linux_socket_usage_t &lhs,
                              const sbp_msg_linux_socket_usage_t &rhs) {
  return sbp_cmp_sbp_msg_linux_socket_usage_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_linux_socket_usage_t &lhs,
                             const sbp_msg_linux_socket_usage_t &rhs) {
  return sbp_cmp_sbp_msg_linux_socket_usage_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_linux_socket_usage_t &lhs,
                              const sbp_msg_linux_socket_usage_t &rhs) {
  return sbp_cmp_sbp_msg_linux_socket_usage_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_linux_socket_usage_t &lhs,
                             const sbp_msg_linux_socket_usage_t &rhs) {
  return sbp_cmp_sbp_msg_linux_socket_usage_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_linux_socket_usage_t &lhs,
                              const sbp_msg_linux_socket_usage_t &rhs) {
  return sbp_cmp_sbp_msg_linux_socket_usage_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_linux_process_fd_count_t &lhs,
                              const sbp_msg_linux_process_fd_count_t &rhs) {
  return sbp_cmp_sbp_msg_linux_process_fd_count_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_linux_process_fd_count_t &lhs,
                              const sbp_msg_linux_process_fd_count_t &rhs) {
  return sbp_cmp_sbp_msg_linux_process_fd_count_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_linux_process_fd_count_t &lhs,
                             const sbp_msg_linux_process_fd_count_t &rhs) {
  return sbp_cmp_sbp_msg_linux_process_fd_count_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_linux_process_fd_count_t &lhs,
                              const sbp_msg_linux_process_fd_count_t &rhs) {
  return sbp_cmp_sbp_msg_linux_process_fd_count_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_linux_process_fd_count_t &lhs,
                             const sbp_msg_linux_process_fd_count_t &rhs) {
  return sbp_cmp_sbp_msg_linux_process_fd_count_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_linux_process_fd_count_t &lhs,
                              const sbp_msg_linux_process_fd_count_t &rhs) {
  return sbp_cmp_sbp_msg_linux_process_fd_count_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_linux_process_fd_summary_t &lhs,
                              const sbp_msg_linux_process_fd_summary_t &rhs) {
  return sbp_cmp_sbp_msg_linux_process_fd_summary_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_linux_process_fd_summary_t &lhs,
                              const sbp_msg_linux_process_fd_summary_t &rhs) {
  return sbp_cmp_sbp_msg_linux_process_fd_summary_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_linux_process_fd_summary_t &lhs,
                             const sbp_msg_linux_process_fd_summary_t &rhs) {
  return sbp_cmp_sbp_msg_linux_process_fd_summary_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_linux_process_fd_summary_t &lhs,
                              const sbp_msg_linux_process_fd_summary_t &rhs) {
  return sbp_cmp_sbp_msg_linux_process_fd_summary_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_linux_process_fd_summary_t &lhs,
                             const sbp_msg_linux_process_fd_summary_t &rhs) {
  return sbp_cmp_sbp_msg_linux_process_fd_summary_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_linux_process_fd_summary_t &lhs,
                              const sbp_msg_linux_process_fd_summary_t &rhs) {
  return sbp_cmp_sbp_msg_linux_process_fd_summary_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_linux_cpu_state_t &lhs,
                              const sbp_msg_linux_cpu_state_t &rhs) {
  return sbp_cmp_sbp_msg_linux_cpu_state_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_linux_cpu_state_t &lhs,
                              const sbp_msg_linux_cpu_state_t &rhs) {
  return sbp_cmp_sbp_msg_linux_cpu_state_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_linux_cpu_state_t &lhs,
                             const sbp_msg_linux_cpu_state_t &rhs) {
  return sbp_cmp_sbp_msg_linux_cpu_state_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_linux_cpu_state_t &lhs,
                              const sbp_msg_linux_cpu_state_t &rhs) {
  return sbp_cmp_sbp_msg_linux_cpu_state_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_linux_cpu_state_t &lhs,
                             const sbp_msg_linux_cpu_state_t &rhs) {
  return sbp_cmp_sbp_msg_linux_cpu_state_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_linux_cpu_state_t &lhs,
                              const sbp_msg_linux_cpu_state_t &rhs) {
  return sbp_cmp_sbp_msg_linux_cpu_state_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_linux_mem_state_t &lhs,
                              const sbp_msg_linux_mem_state_t &rhs) {
  return sbp_cmp_sbp_msg_linux_mem_state_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_linux_mem_state_t &lhs,
                              const sbp_msg_linux_mem_state_t &rhs) {
  return sbp_cmp_sbp_msg_linux_mem_state_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_linux_mem_state_t &lhs,
                             const sbp_msg_linux_mem_state_t &rhs) {
  return sbp_cmp_sbp_msg_linux_mem_state_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_linux_mem_state_t &lhs,
                              const sbp_msg_linux_mem_state_t &rhs) {
  return sbp_cmp_sbp_msg_linux_mem_state_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_linux_mem_state_t &lhs,
                             const sbp_msg_linux_mem_state_t &rhs) {
  return sbp_cmp_sbp_msg_linux_mem_state_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_linux_mem_state_t &lhs,
                              const sbp_msg_linux_mem_state_t &rhs) {
  return sbp_cmp_sbp_msg_linux_mem_state_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_linux_sys_state_t &lhs,
                              const sbp_msg_linux_sys_state_t &rhs) {
  return sbp_cmp_sbp_msg_linux_sys_state_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_linux_sys_state_t &lhs,
                              const sbp_msg_linux_sys_state_t &rhs) {
  return sbp_cmp_sbp_msg_linux_sys_state_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_linux_sys_state_t &lhs,
                             const sbp_msg_linux_sys_state_t &rhs) {
  return sbp_cmp_sbp_msg_linux_sys_state_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_linux_sys_state_t &lhs,
                              const sbp_msg_linux_sys_state_t &rhs) {
  return sbp_cmp_sbp_msg_linux_sys_state_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_linux_sys_state_t &lhs,
                             const sbp_msg_linux_sys_state_t &rhs) {
  return sbp_cmp_sbp_msg_linux_sys_state_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_linux_sys_state_t &lhs,
                              const sbp_msg_linux_sys_state_t &rhs) {
  return sbp_cmp_sbp_msg_linux_sys_state_t(&lhs, &rhs) >= 0;
}

#endif

#endif /* LIBSBP_NEW_LINUX_MESSAGES_H */
