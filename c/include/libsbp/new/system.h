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
 * Automatically generated from yaml/swiftnav/sbp/system.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_NEW_SYSTEM_MESSAGES_H
#define LIBSBP_NEW_SYSTEM_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/new/string/double_null_terminated.h>
#include <libsbp/new/string/multipart.h>
#include <libsbp/new/string/null_terminated.h>
#include <libsbp/new/string/unterminated.h>
#include <libsbp/system_macros.h>

#ifdef __cplusplus
extern "C" {
#endif

struct sbp_state;

/** System start-up message
 *
 * The system start-up message is sent once on system start-up. It notifies the
 * host or other attached devices that the system has started and is now ready
 * to respond to commands or configuration requests.
 */
typedef struct {
  /**
   * Cause of startup
   */
  u8 cause;

  /**
   * Startup type
   */
  u8 startup_type;

  /**
   * Reserved
   */
  u16 reserved;
} sbp_msg_startup_t;

/**
 * Get encoded size of an instance of sbp_msg_startup_t
 *
 * @param msg sbp_msg_startup_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_startup_t(const sbp_msg_startup_t *msg);

/**
 * Encode an instance of sbp_msg_startup_t to wire representation
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
 * @param msg Instance of sbp_msg_startup_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_startup_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                const sbp_msg_startup_t *msg);

/**
 * Decode an instance of sbp_msg_startup_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_startup_t message
 * to the given instance. The caller must specify the length of the buffer in
 * the \p len parameter. If non-null the number of bytes read from the buffer
 * will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_startup_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_startup_t(const uint8_t *buf, uint8_t len,
                                uint8_t *n_read, sbp_msg_startup_t *msg);
/**
 * Send an instance of sbp_msg_startup_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_startup_t
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
s8 sbp_send_sbp_msg_startup_t(struct sbp_state *s, u16 sender_id,
                              const sbp_msg_startup_t *msg,
                              s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_startup_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_startup_t instance
 * @param b sbp_msg_startup_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_startup_t(const sbp_msg_startup_t *a,
                              const sbp_msg_startup_t *b);

/** Status of received corrections
 *
 * This message provides information about the receipt of Differential
 * corrections.  It is expected to be sent with each receipt of a complete
 * corrections packet.
 */
typedef struct {
  /**
   * Status flags
   */
  u8 flags;

  /**
   * Latency of observation receipt [deci-seconds]
   */
  u16 latency;

  /**
   * Number of signals from base station
   */
  u8 num_signals;

  /**
   * Corrections source string
   */
  sbp_unterminated_string_t source;
} sbp_msg_dgnss_status_t;
void sbp_msg_dgnss_status_t_source_init(sbp_unterminated_string_t *s);
bool sbp_msg_dgnss_status_t_source_valid(const sbp_unterminated_string_t *s);
int sbp_msg_dgnss_status_t_source_strcmp(const sbp_unterminated_string_t *a,
                                         const sbp_unterminated_string_t *b);
uint8_t sbp_msg_dgnss_status_t_source_packed_len(
    const sbp_unterminated_string_t *s);
uint8_t sbp_msg_dgnss_status_t_source_space_remaining(
    const sbp_unterminated_string_t *s);
bool sbp_msg_dgnss_status_t_source_set(sbp_unterminated_string_t *s,
                                       const char *new_str);
bool sbp_msg_dgnss_status_t_source_printf(sbp_unterminated_string_t *s,
                                          const char *fmt, ...)
    SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_dgnss_status_t_source_vprintf(sbp_unterminated_string_t *s,
                                           const char *fmt, va_list ap);
bool sbp_msg_dgnss_status_t_source_append_printf(sbp_unterminated_string_t *s,
                                                 const char *fmt, ...)
    SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_dgnss_status_t_source_append_vprintf(sbp_unterminated_string_t *s,
                                                  const char *fmt, va_list ap);
const char *sbp_msg_dgnss_status_t_source_get(
    const sbp_unterminated_string_t *s);

/**
 * Get encoded size of an instance of sbp_msg_dgnss_status_t
 *
 * @param msg sbp_msg_dgnss_status_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_dgnss_status_t(
    const sbp_msg_dgnss_status_t *msg);

/**
 * Encode an instance of sbp_msg_dgnss_status_t to wire representation
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
 * @param msg Instance of sbp_msg_dgnss_status_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_dgnss_status_t(uint8_t *buf, uint8_t len,
                                     uint8_t *n_written,
                                     const sbp_msg_dgnss_status_t *msg);

/**
 * Decode an instance of sbp_msg_dgnss_status_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_dgnss_status_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_dgnss_status_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_dgnss_status_t(const uint8_t *buf, uint8_t len,
                                     uint8_t *n_read,
                                     sbp_msg_dgnss_status_t *msg);
/**
 * Send an instance of sbp_msg_dgnss_status_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_dgnss_status_t
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
s8 sbp_send_sbp_msg_dgnss_status_t(struct sbp_state *s, u16 sender_id,
                                   const sbp_msg_dgnss_status_t *msg,
                                   s32 (*write)(u8 *buff, u32 n,
                                                void *context));

/**
 * Compare two instances of sbp_msg_dgnss_status_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_dgnss_status_t instance
 * @param b sbp_msg_dgnss_status_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_dgnss_status_t(const sbp_msg_dgnss_status_t *a,
                                   const sbp_msg_dgnss_status_t *b);

/** System heartbeat message
 *
 * The heartbeat message is sent periodically to inform the host or other
 * attached devices that the system is running. It is used to monitor system
 * malfunctions. It also contains status flags that indicate to the host the
 * status of the system and whether it is operating correctly. Currently, the
 * expected heartbeat interval is 1 sec.
 *
 */
typedef struct {
  /**
   * Status flags
   */
  u32 flags;
} sbp_msg_heartbeat_t;

/**
 * Get encoded size of an instance of sbp_msg_heartbeat_t
 *
 * @param msg sbp_msg_heartbeat_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_heartbeat_t(const sbp_msg_heartbeat_t *msg);

/**
 * Encode an instance of sbp_msg_heartbeat_t to wire representation
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
 * @param msg Instance of sbp_msg_heartbeat_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_heartbeat_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_heartbeat_t *msg);

/**
 * Decode an instance of sbp_msg_heartbeat_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_heartbeat_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_heartbeat_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_heartbeat_t(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read, sbp_msg_heartbeat_t *msg);
/**
 * Send an instance of sbp_msg_heartbeat_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_heartbeat_t
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
s8 sbp_send_sbp_msg_heartbeat_t(struct sbp_state *s, u16 sender_id,
                                const sbp_msg_heartbeat_t *msg,
                                s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_heartbeat_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_heartbeat_t instance
 * @param b sbp_msg_heartbeat_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_heartbeat_t(const sbp_msg_heartbeat_t *a,
                                const sbp_msg_heartbeat_t *b);

/** Sub-system Status report
 *
 * Report the general and specific state of a sub-system.  If the generic state
 * is reported as initializing, the specific state should be ignored.
 */
typedef struct {
  /**
   * Identity of reporting subsystem
   */
  u16 component;

  /**
   * Generic form status report
   */
  u8 generic;

  /**
   * Subsystem specific status code
   */
  u8 specific;
} sbp_sub_system_report_t;

/**
 * Get encoded size of an instance of sbp_sub_system_report_t
 *
 * @param msg sbp_sub_system_report_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_sub_system_report_t(
    const sbp_sub_system_report_t *msg);

/**
 * Encode an instance of sbp_sub_system_report_t to wire representation
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
 * @param msg Instance of sbp_sub_system_report_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_sub_system_report_t(uint8_t *buf, uint8_t len,
                                      uint8_t *n_written,
                                      const sbp_sub_system_report_t *msg);

/**
 * Decode an instance of sbp_sub_system_report_t from wire representation
 *
 * This function decodes the wire representation of a sbp_sub_system_report_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_sub_system_report_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_sub_system_report_t(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_sub_system_report_t *msg);

/**
 * Compare two instances of sbp_sub_system_report_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_sub_system_report_t instance
 * @param b sbp_sub_system_report_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_sub_system_report_t(const sbp_sub_system_report_t *a,
                                    const sbp_sub_system_report_t *b);

/** Status report message
 *
 * The status report is sent periodically to inform the host or other attached
 * devices that the system is running. It is used to monitor system
 * malfunctions. It contains status reports that indicate to the host the status
 * of each sub-system and whether it is operating correctly.
 *
 */
typedef struct {
  /**
   * Identity of reporting system
   */
  u16 reporting_system;

  /**
   * SBP protocol version
   */
  u16 sbp_version;

  /**
   * Increments on each status report sent
   */
  u32 sequence;

  /**
   * Number of seconds since system start-up
   */
  u32 uptime;

  /**
   * Reported status of individual subsystems
   */
  sbp_sub_system_report_t status[60];
  /**
   * Number of elements in status
   *
   * When sending a message fill in this field with the number elements set in
   * status before calling an appropriate libsbp send function
   *
   * When receiving a message query this field for the number of elements in
   * status. The value of any elements beyond the index specified in this field
   * is undefined
   */
  u8 n_status;
} sbp_msg_status_report_t;

/**
 * Get encoded size of an instance of sbp_msg_status_report_t
 *
 * @param msg sbp_msg_status_report_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_status_report_t(
    const sbp_msg_status_report_t *msg);

/**
 * Encode an instance of sbp_msg_status_report_t to wire representation
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
 * @param msg Instance of sbp_msg_status_report_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_status_report_t(uint8_t *buf, uint8_t len,
                                      uint8_t *n_written,
                                      const sbp_msg_status_report_t *msg);

/**
 * Decode an instance of sbp_msg_status_report_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_status_report_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_status_report_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_status_report_t(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_status_report_t *msg);
/**
 * Send an instance of sbp_msg_status_report_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_status_report_t
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
s8 sbp_send_sbp_msg_status_report_t(struct sbp_state *s, u16 sender_id,
                                    const sbp_msg_status_report_t *msg,
                                    s32 (*write)(u8 *buff, u32 n,
                                                 void *context));

/**
 * Compare two instances of sbp_msg_status_report_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_status_report_t instance
 * @param b sbp_msg_status_report_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_status_report_t(const sbp_msg_status_report_t *a,
                                    const sbp_msg_status_report_t *b);

/** Inertial Navigation System status message
 *
 * The INS status message describes the state of the operation and
 * initialization of the inertial navigation system.
 */
typedef struct {
  /**
   * Status flags
   */
  u32 flags;
} sbp_msg_ins_status_t;

/**
 * Get encoded size of an instance of sbp_msg_ins_status_t
 *
 * @param msg sbp_msg_ins_status_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_ins_status_t(const sbp_msg_ins_status_t *msg);

/**
 * Encode an instance of sbp_msg_ins_status_t to wire representation
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
 * @param msg Instance of sbp_msg_ins_status_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_ins_status_t(uint8_t *buf, uint8_t len,
                                   uint8_t *n_written,
                                   const sbp_msg_ins_status_t *msg);

/**
 * Decode an instance of sbp_msg_ins_status_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_ins_status_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ins_status_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_ins_status_t(const uint8_t *buf, uint8_t len,
                                   uint8_t *n_read, sbp_msg_ins_status_t *msg);
/**
 * Send an instance of sbp_msg_ins_status_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ins_status_t
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
s8 sbp_send_sbp_msg_ins_status_t(struct sbp_state *s, u16 sender_id,
                                 const sbp_msg_ins_status_t *msg,
                                 s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_ins_status_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ins_status_t instance
 * @param b sbp_msg_ins_status_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_ins_status_t(const sbp_msg_ins_status_t *a,
                                 const sbp_msg_ins_status_t *b);

/** Experimental telemetry message
 *
 * The CSAC telemetry message has an implementation defined telemetry string
 * from a device. It is not produced or available on general Swift Products. It
 * is intended to be a low rate message for status purposes.
 */
typedef struct {
  /**
   * Index representing the type of telemetry in use.  It is implemention
   * defined.
   */
  u8 id;

  /**
   * Comma separated list of values as defined by the index
   */
  sbp_unterminated_string_t telemetry;
} sbp_msg_csac_telemetry_t;
void sbp_msg_csac_telemetry_t_telemetry_init(sbp_unterminated_string_t *s);
bool sbp_msg_csac_telemetry_t_telemetry_valid(
    const sbp_unterminated_string_t *s);
int sbp_msg_csac_telemetry_t_telemetry_strcmp(
    const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b);
uint8_t sbp_msg_csac_telemetry_t_telemetry_packed_len(
    const sbp_unterminated_string_t *s);
uint8_t sbp_msg_csac_telemetry_t_telemetry_space_remaining(
    const sbp_unterminated_string_t *s);
bool sbp_msg_csac_telemetry_t_telemetry_set(sbp_unterminated_string_t *s,
                                            const char *new_str);
bool sbp_msg_csac_telemetry_t_telemetry_printf(sbp_unterminated_string_t *s,
                                               const char *fmt, ...)
    SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_csac_telemetry_t_telemetry_vprintf(sbp_unterminated_string_t *s,
                                                const char *fmt, va_list ap);
bool sbp_msg_csac_telemetry_t_telemetry_append_printf(
    sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_csac_telemetry_t_telemetry_append_vprintf(
    sbp_unterminated_string_t *s, const char *fmt, va_list ap);
const char *sbp_msg_csac_telemetry_t_telemetry_get(
    const sbp_unterminated_string_t *s);

/**
 * Get encoded size of an instance of sbp_msg_csac_telemetry_t
 *
 * @param msg sbp_msg_csac_telemetry_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_csac_telemetry_t(
    const sbp_msg_csac_telemetry_t *msg);

/**
 * Encode an instance of sbp_msg_csac_telemetry_t to wire representation
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
 * @param msg Instance of sbp_msg_csac_telemetry_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_csac_telemetry_t(uint8_t *buf, uint8_t len,
                                       uint8_t *n_written,
                                       const sbp_msg_csac_telemetry_t *msg);

/**
 * Decode an instance of sbp_msg_csac_telemetry_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_csac_telemetry_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_csac_telemetry_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_csac_telemetry_t(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_msg_csac_telemetry_t *msg);
/**
 * Send an instance of sbp_msg_csac_telemetry_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_csac_telemetry_t
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
s8 sbp_send_sbp_msg_csac_telemetry_t(struct sbp_state *s, u16 sender_id,
                                     const sbp_msg_csac_telemetry_t *msg,
                                     s32 (*write)(u8 *buff, u32 n,
                                                  void *context));

/**
 * Compare two instances of sbp_msg_csac_telemetry_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_csac_telemetry_t instance
 * @param b sbp_msg_csac_telemetry_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_csac_telemetry_t(const sbp_msg_csac_telemetry_t *a,
                                     const sbp_msg_csac_telemetry_t *b);

/** Experimental telemetry message labels
 *
 * The CSAC telemetry message provides labels for each member of the string
 * produced by MSG_CSAC_TELEMETRY. It should be provided by a device at a lower
 * rate than the MSG_CSAC_TELEMETRY.
 */
typedef struct {
  /**
   * Index representing the type of telemetry in use.  It is implemention
   * defined.
   */
  u8 id;

  /**
   * Comma separated list of telemetry field values
   */
  sbp_unterminated_string_t telemetry_labels;
} sbp_msg_csac_telemetry_labels_t;
void sbp_msg_csac_telemetry_labels_t_telemetry_labels_init(
    sbp_unterminated_string_t *s);
bool sbp_msg_csac_telemetry_labels_t_telemetry_labels_valid(
    const sbp_unterminated_string_t *s);
int sbp_msg_csac_telemetry_labels_t_telemetry_labels_strcmp(
    const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b);
uint8_t sbp_msg_csac_telemetry_labels_t_telemetry_labels_packed_len(
    const sbp_unterminated_string_t *s);
uint8_t sbp_msg_csac_telemetry_labels_t_telemetry_labels_space_remaining(
    const sbp_unterminated_string_t *s);
bool sbp_msg_csac_telemetry_labels_t_telemetry_labels_set(
    sbp_unterminated_string_t *s, const char *new_str);
bool sbp_msg_csac_telemetry_labels_t_telemetry_labels_printf(
    sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_csac_telemetry_labels_t_telemetry_labels_vprintf(
    sbp_unterminated_string_t *s, const char *fmt, va_list ap);
bool sbp_msg_csac_telemetry_labels_t_telemetry_labels_append_printf(
    sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_csac_telemetry_labels_t_telemetry_labels_append_vprintf(
    sbp_unterminated_string_t *s, const char *fmt, va_list ap);
const char *sbp_msg_csac_telemetry_labels_t_telemetry_labels_get(
    const sbp_unterminated_string_t *s);

/**
 * Get encoded size of an instance of sbp_msg_csac_telemetry_labels_t
 *
 * @param msg sbp_msg_csac_telemetry_labels_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_csac_telemetry_labels_t(
    const sbp_msg_csac_telemetry_labels_t *msg);

/**
 * Encode an instance of sbp_msg_csac_telemetry_labels_t to wire representation
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
 * @param msg Instance of sbp_msg_csac_telemetry_labels_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_csac_telemetry_labels_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_csac_telemetry_labels_t *msg);

/**
 * Decode an instance of sbp_msg_csac_telemetry_labels_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_csac_telemetry_labels_t message to the given instance. The caller
 * must specify the length of the buffer in the \p len parameter. If non-null
 * the number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_csac_telemetry_labels_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_csac_telemetry_labels_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_csac_telemetry_labels_t *msg);
/**
 * Send an instance of sbp_msg_csac_telemetry_labels_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_csac_telemetry_labels_t
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
s8 sbp_send_sbp_msg_csac_telemetry_labels_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_csac_telemetry_labels_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_csac_telemetry_labels_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_csac_telemetry_labels_t instance
 * @param b sbp_msg_csac_telemetry_labels_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_csac_telemetry_labels_t(
    const sbp_msg_csac_telemetry_labels_t *a,
    const sbp_msg_csac_telemetry_labels_t *b);

/** Inertial Navigation System update status message
 *
 * The INS update status message contains informations about executed and
 * rejected INS updates. This message is expected to be extended in the future
 * as new types of measurements are being added.
 */
typedef struct {
  /**
   * GPS Time of Week [ms]
   */
  u32 tow;

  /**
   * GNSS position update status flags
   */
  u8 gnsspos;

  /**
   * GNSS velocity update status flags
   */
  u8 gnssvel;

  /**
   * Wheelticks update status flags
   */
  u8 wheelticks;

  /**
   * Wheelticks update status flags
   */
  u8 speed;

  /**
   * NHC update status flags
   */
  u8 nhc;

  /**
   * Zero velocity update status flags
   */
  u8 zerovel;
} sbp_msg_ins_updates_t;

/**
 * Get encoded size of an instance of sbp_msg_ins_updates_t
 *
 * @param msg sbp_msg_ins_updates_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_ins_updates_t(const sbp_msg_ins_updates_t *msg);

/**
 * Encode an instance of sbp_msg_ins_updates_t to wire representation
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
 * @param msg Instance of sbp_msg_ins_updates_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_ins_updates_t(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_msg_ins_updates_t *msg);

/**
 * Decode an instance of sbp_msg_ins_updates_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_ins_updates_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_ins_updates_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_ins_updates_t(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_msg_ins_updates_t *msg);
/**
 * Send an instance of sbp_msg_ins_updates_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_ins_updates_t
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
s8 sbp_send_sbp_msg_ins_updates_t(struct sbp_state *s, u16 sender_id,
                                  const sbp_msg_ins_updates_t *msg,
                                  s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_ins_updates_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_ins_updates_t instance
 * @param b sbp_msg_ins_updates_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_ins_updates_t(const sbp_msg_ins_updates_t *a,
                                  const sbp_msg_ins_updates_t *b);

/** Offset of the local time with respect to GNSS time
 *
 * The GNSS time offset message contains the information that is needed to
 * translate messages tagged with a local timestamp (e.g. IMU or wheeltick
 * messages) to GNSS time for the sender producing this message.
 */
typedef struct {
  /**
   * Weeks portion of the time offset [weeks]
   */
  s16 weeks;

  /**
   * Milliseconds portion of the time offset [ms]
   */
  s32 milliseconds;

  /**
   * Microseconds portion of the time offset [microseconds]
   */
  s16 microseconds;

  /**
   * Status flags (reserved)
   */
  u8 flags;
} sbp_msg_gnss_time_offset_t;

/**
 * Get encoded size of an instance of sbp_msg_gnss_time_offset_t
 *
 * @param msg sbp_msg_gnss_time_offset_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_gnss_time_offset_t(
    const sbp_msg_gnss_time_offset_t *msg);

/**
 * Encode an instance of sbp_msg_gnss_time_offset_t to wire representation
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
 * @param msg Instance of sbp_msg_gnss_time_offset_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_gnss_time_offset_t(uint8_t *buf, uint8_t len,
                                         uint8_t *n_written,
                                         const sbp_msg_gnss_time_offset_t *msg);

/**
 * Decode an instance of sbp_msg_gnss_time_offset_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_gnss_time_offset_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_gnss_time_offset_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_gnss_time_offset_t(const uint8_t *buf, uint8_t len,
                                         uint8_t *n_read,
                                         sbp_msg_gnss_time_offset_t *msg);
/**
 * Send an instance of sbp_msg_gnss_time_offset_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_gnss_time_offset_t
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
s8 sbp_send_sbp_msg_gnss_time_offset_t(struct sbp_state *s, u16 sender_id,
                                       const sbp_msg_gnss_time_offset_t *msg,
                                       s32 (*write)(u8 *buff, u32 n,
                                                    void *context));

/**
 * Compare two instances of sbp_msg_gnss_time_offset_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_gnss_time_offset_t instance
 * @param b sbp_msg_gnss_time_offset_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_gnss_time_offset_t(const sbp_msg_gnss_time_offset_t *a,
                                       const sbp_msg_gnss_time_offset_t *b);

/** Local time at detection of PPS pulse
 *
 * The PPS time message contains the value of the sender's local time in
 * microseconds at the moment a pulse is detected on the PPS input. This is to
 * be used for syncronisation of sensor data sampled with a local timestamp
 * (e.g. IMU or wheeltick messages) where GNSS time is unknown to the sender.
 *
 */
typedef struct {
  /**
   * Local time in microseconds [microseconds]
   */
  u64 time;

  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_pps_time_t;

/**
 * Get encoded size of an instance of sbp_msg_pps_time_t
 *
 * @param msg sbp_msg_pps_time_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_pps_time_t(const sbp_msg_pps_time_t *msg);

/**
 * Encode an instance of sbp_msg_pps_time_t to wire representation
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
 * @param msg Instance of sbp_msg_pps_time_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_pps_time_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_msg_pps_time_t *msg);

/**
 * Decode an instance of sbp_msg_pps_time_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_pps_time_t message
 * to the given instance. The caller must specify the length of the buffer in
 * the \p len parameter. If non-null the number of bytes read from the buffer
 * will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_pps_time_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_pps_time_t(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read, sbp_msg_pps_time_t *msg);
/**
 * Send an instance of sbp_msg_pps_time_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_pps_time_t
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
s8 sbp_send_sbp_msg_pps_time_t(struct sbp_state *s, u16 sender_id,
                               const sbp_msg_pps_time_t *msg,
                               s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_pps_time_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_pps_time_t instance
 * @param b sbp_msg_pps_time_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_pps_time_t(const sbp_msg_pps_time_t *a,
                               const sbp_msg_pps_time_t *b);

/** Solution Group Metadata
 *
 * This leading message lists the time metadata of the Solution Group. It also
 * lists the atomic contents (i.e. types of messages included) of the Solution
 * Group.
 */
typedef struct {
  /**
   * Id of the Msgs Group, 0 is Unknown, 1 is Bestpos, 2 is Gnss
   */
  u8 group_id;

  /**
   * Status flags (reserved)
   */
  u8 flags;

  /**
   * Size of list group_msgs
   */
  u8 n_group_msgs;

  /**
   * An inorder list of message types included in the Solution Group, including
   * GROUP_META itself
   */
  u16 group_msgs[126];
} sbp_msg_group_meta_t;

/**
 * Get encoded size of an instance of sbp_msg_group_meta_t
 *
 * @param msg sbp_msg_group_meta_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_group_meta_t(const sbp_msg_group_meta_t *msg);

/**
 * Encode an instance of sbp_msg_group_meta_t to wire representation
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
 * @param msg Instance of sbp_msg_group_meta_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_group_meta_t(uint8_t *buf, uint8_t len,
                                   uint8_t *n_written,
                                   const sbp_msg_group_meta_t *msg);

/**
 * Decode an instance of sbp_msg_group_meta_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_group_meta_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_group_meta_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_group_meta_t(const uint8_t *buf, uint8_t len,
                                   uint8_t *n_read, sbp_msg_group_meta_t *msg);
/**
 * Send an instance of sbp_msg_group_meta_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_group_meta_t
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
s8 sbp_send_sbp_msg_group_meta_t(struct sbp_state *s, u16 sender_id,
                                 const sbp_msg_group_meta_t *msg,
                                 s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_group_meta_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_group_meta_t instance
 * @param b sbp_msg_group_meta_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_group_meta_t(const sbp_msg_group_meta_t *a,
                                 const sbp_msg_group_meta_t *b);

#ifdef __cplusplus
}
static inline bool operator==(const sbp_msg_startup_t &lhs,
                              const sbp_msg_startup_t &rhs) {
  return sbp_cmp_sbp_msg_startup_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_startup_t &lhs,
                              const sbp_msg_startup_t &rhs) {
  return sbp_cmp_sbp_msg_startup_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_startup_t &lhs,
                             const sbp_msg_startup_t &rhs) {
  return sbp_cmp_sbp_msg_startup_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_startup_t &lhs,
                              const sbp_msg_startup_t &rhs) {
  return sbp_cmp_sbp_msg_startup_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_startup_t &lhs,
                             const sbp_msg_startup_t &rhs) {
  return sbp_cmp_sbp_msg_startup_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_startup_t &lhs,
                              const sbp_msg_startup_t &rhs) {
  return sbp_cmp_sbp_msg_startup_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_dgnss_status_t &lhs,
                              const sbp_msg_dgnss_status_t &rhs) {
  return sbp_cmp_sbp_msg_dgnss_status_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_dgnss_status_t &lhs,
                              const sbp_msg_dgnss_status_t &rhs) {
  return sbp_cmp_sbp_msg_dgnss_status_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_dgnss_status_t &lhs,
                             const sbp_msg_dgnss_status_t &rhs) {
  return sbp_cmp_sbp_msg_dgnss_status_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_dgnss_status_t &lhs,
                              const sbp_msg_dgnss_status_t &rhs) {
  return sbp_cmp_sbp_msg_dgnss_status_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_dgnss_status_t &lhs,
                             const sbp_msg_dgnss_status_t &rhs) {
  return sbp_cmp_sbp_msg_dgnss_status_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_dgnss_status_t &lhs,
                              const sbp_msg_dgnss_status_t &rhs) {
  return sbp_cmp_sbp_msg_dgnss_status_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_heartbeat_t &lhs,
                              const sbp_msg_heartbeat_t &rhs) {
  return sbp_cmp_sbp_msg_heartbeat_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_heartbeat_t &lhs,
                              const sbp_msg_heartbeat_t &rhs) {
  return sbp_cmp_sbp_msg_heartbeat_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_heartbeat_t &lhs,
                             const sbp_msg_heartbeat_t &rhs) {
  return sbp_cmp_sbp_msg_heartbeat_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_heartbeat_t &lhs,
                              const sbp_msg_heartbeat_t &rhs) {
  return sbp_cmp_sbp_msg_heartbeat_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_heartbeat_t &lhs,
                             const sbp_msg_heartbeat_t &rhs) {
  return sbp_cmp_sbp_msg_heartbeat_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_heartbeat_t &lhs,
                              const sbp_msg_heartbeat_t &rhs) {
  return sbp_cmp_sbp_msg_heartbeat_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_sub_system_report_t &lhs,
                              const sbp_sub_system_report_t &rhs) {
  return sbp_cmp_sbp_sub_system_report_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_sub_system_report_t &lhs,
                              const sbp_sub_system_report_t &rhs) {
  return sbp_cmp_sbp_sub_system_report_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_sub_system_report_t &lhs,
                             const sbp_sub_system_report_t &rhs) {
  return sbp_cmp_sbp_sub_system_report_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_sub_system_report_t &lhs,
                              const sbp_sub_system_report_t &rhs) {
  return sbp_cmp_sbp_sub_system_report_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_sub_system_report_t &lhs,
                             const sbp_sub_system_report_t &rhs) {
  return sbp_cmp_sbp_sub_system_report_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_sub_system_report_t &lhs,
                              const sbp_sub_system_report_t &rhs) {
  return sbp_cmp_sbp_sub_system_report_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_status_report_t &lhs,
                              const sbp_msg_status_report_t &rhs) {
  return sbp_cmp_sbp_msg_status_report_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_status_report_t &lhs,
                              const sbp_msg_status_report_t &rhs) {
  return sbp_cmp_sbp_msg_status_report_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_status_report_t &lhs,
                             const sbp_msg_status_report_t &rhs) {
  return sbp_cmp_sbp_msg_status_report_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_status_report_t &lhs,
                              const sbp_msg_status_report_t &rhs) {
  return sbp_cmp_sbp_msg_status_report_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_status_report_t &lhs,
                             const sbp_msg_status_report_t &rhs) {
  return sbp_cmp_sbp_msg_status_report_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_status_report_t &lhs,
                              const sbp_msg_status_report_t &rhs) {
  return sbp_cmp_sbp_msg_status_report_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_ins_status_t &lhs,
                              const sbp_msg_ins_status_t &rhs) {
  return sbp_cmp_sbp_msg_ins_status_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ins_status_t &lhs,
                              const sbp_msg_ins_status_t &rhs) {
  return sbp_cmp_sbp_msg_ins_status_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ins_status_t &lhs,
                             const sbp_msg_ins_status_t &rhs) {
  return sbp_cmp_sbp_msg_ins_status_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ins_status_t &lhs,
                              const sbp_msg_ins_status_t &rhs) {
  return sbp_cmp_sbp_msg_ins_status_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ins_status_t &lhs,
                             const sbp_msg_ins_status_t &rhs) {
  return sbp_cmp_sbp_msg_ins_status_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ins_status_t &lhs,
                              const sbp_msg_ins_status_t &rhs) {
  return sbp_cmp_sbp_msg_ins_status_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_csac_telemetry_t &lhs,
                              const sbp_msg_csac_telemetry_t &rhs) {
  return sbp_cmp_sbp_msg_csac_telemetry_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_csac_telemetry_t &lhs,
                              const sbp_msg_csac_telemetry_t &rhs) {
  return sbp_cmp_sbp_msg_csac_telemetry_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_csac_telemetry_t &lhs,
                             const sbp_msg_csac_telemetry_t &rhs) {
  return sbp_cmp_sbp_msg_csac_telemetry_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_csac_telemetry_t &lhs,
                              const sbp_msg_csac_telemetry_t &rhs) {
  return sbp_cmp_sbp_msg_csac_telemetry_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_csac_telemetry_t &lhs,
                             const sbp_msg_csac_telemetry_t &rhs) {
  return sbp_cmp_sbp_msg_csac_telemetry_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_csac_telemetry_t &lhs,
                              const sbp_msg_csac_telemetry_t &rhs) {
  return sbp_cmp_sbp_msg_csac_telemetry_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_csac_telemetry_labels_t &lhs,
                              const sbp_msg_csac_telemetry_labels_t &rhs) {
  return sbp_cmp_sbp_msg_csac_telemetry_labels_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_csac_telemetry_labels_t &lhs,
                              const sbp_msg_csac_telemetry_labels_t &rhs) {
  return sbp_cmp_sbp_msg_csac_telemetry_labels_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_csac_telemetry_labels_t &lhs,
                             const sbp_msg_csac_telemetry_labels_t &rhs) {
  return sbp_cmp_sbp_msg_csac_telemetry_labels_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_csac_telemetry_labels_t &lhs,
                              const sbp_msg_csac_telemetry_labels_t &rhs) {
  return sbp_cmp_sbp_msg_csac_telemetry_labels_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_csac_telemetry_labels_t &lhs,
                             const sbp_msg_csac_telemetry_labels_t &rhs) {
  return sbp_cmp_sbp_msg_csac_telemetry_labels_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_csac_telemetry_labels_t &lhs,
                              const sbp_msg_csac_telemetry_labels_t &rhs) {
  return sbp_cmp_sbp_msg_csac_telemetry_labels_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_ins_updates_t &lhs,
                              const sbp_msg_ins_updates_t &rhs) {
  return sbp_cmp_sbp_msg_ins_updates_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_ins_updates_t &lhs,
                              const sbp_msg_ins_updates_t &rhs) {
  return sbp_cmp_sbp_msg_ins_updates_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_ins_updates_t &lhs,
                             const sbp_msg_ins_updates_t &rhs) {
  return sbp_cmp_sbp_msg_ins_updates_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_ins_updates_t &lhs,
                              const sbp_msg_ins_updates_t &rhs) {
  return sbp_cmp_sbp_msg_ins_updates_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_ins_updates_t &lhs,
                             const sbp_msg_ins_updates_t &rhs) {
  return sbp_cmp_sbp_msg_ins_updates_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_ins_updates_t &lhs,
                              const sbp_msg_ins_updates_t &rhs) {
  return sbp_cmp_sbp_msg_ins_updates_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_gnss_time_offset_t &lhs,
                              const sbp_msg_gnss_time_offset_t &rhs) {
  return sbp_cmp_sbp_msg_gnss_time_offset_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_gnss_time_offset_t &lhs,
                              const sbp_msg_gnss_time_offset_t &rhs) {
  return sbp_cmp_sbp_msg_gnss_time_offset_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_gnss_time_offset_t &lhs,
                             const sbp_msg_gnss_time_offset_t &rhs) {
  return sbp_cmp_sbp_msg_gnss_time_offset_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_gnss_time_offset_t &lhs,
                              const sbp_msg_gnss_time_offset_t &rhs) {
  return sbp_cmp_sbp_msg_gnss_time_offset_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_gnss_time_offset_t &lhs,
                             const sbp_msg_gnss_time_offset_t &rhs) {
  return sbp_cmp_sbp_msg_gnss_time_offset_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_gnss_time_offset_t &lhs,
                              const sbp_msg_gnss_time_offset_t &rhs) {
  return sbp_cmp_sbp_msg_gnss_time_offset_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_pps_time_t &lhs,
                              const sbp_msg_pps_time_t &rhs) {
  return sbp_cmp_sbp_msg_pps_time_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_pps_time_t &lhs,
                              const sbp_msg_pps_time_t &rhs) {
  return sbp_cmp_sbp_msg_pps_time_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_pps_time_t &lhs,
                             const sbp_msg_pps_time_t &rhs) {
  return sbp_cmp_sbp_msg_pps_time_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_pps_time_t &lhs,
                              const sbp_msg_pps_time_t &rhs) {
  return sbp_cmp_sbp_msg_pps_time_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_pps_time_t &lhs,
                             const sbp_msg_pps_time_t &rhs) {
  return sbp_cmp_sbp_msg_pps_time_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_pps_time_t &lhs,
                              const sbp_msg_pps_time_t &rhs) {
  return sbp_cmp_sbp_msg_pps_time_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_group_meta_t &lhs,
                              const sbp_msg_group_meta_t &rhs) {
  return sbp_cmp_sbp_msg_group_meta_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_group_meta_t &lhs,
                              const sbp_msg_group_meta_t &rhs) {
  return sbp_cmp_sbp_msg_group_meta_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_group_meta_t &lhs,
                             const sbp_msg_group_meta_t &rhs) {
  return sbp_cmp_sbp_msg_group_meta_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_group_meta_t &lhs,
                              const sbp_msg_group_meta_t &rhs) {
  return sbp_cmp_sbp_msg_group_meta_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_group_meta_t &lhs,
                             const sbp_msg_group_meta_t &rhs) {
  return sbp_cmp_sbp_msg_group_meta_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_group_meta_t &lhs,
                              const sbp_msg_group_meta_t &rhs) {
  return sbp_cmp_sbp_msg_group_meta_t(&lhs, &rhs) >= 0;
}

#endif

#endif /* LIBSBP_NEW_SYSTEM_MESSAGES_H */
