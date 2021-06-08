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
 * Automatically generated from yaml/swiftnav/sbp/piksi.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_NEW_PIKSI_MESSAGES_H
#define LIBSBP_NEW_PIKSI_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/new/gnss.h>
#include <libsbp/new/string/double_null_terminated.h>
#include <libsbp/new/string/multipart.h>
#include <libsbp/new/string/null_terminated.h>
#include <libsbp/new/string/unterminated.h>
#include <libsbp/piksi_macros.h>

#ifdef __cplusplus
extern "C" {
#endif

struct sbp_state;

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_ALMANAC
 *
 *****************************************************************************/
/** Legacy message to load satellite almanac (host => Piksi)
 *
 * This is a legacy message for sending and loading a satellite alamanac onto
 * the Piksi's flash memory from the host.
 */
typedef struct {
  /**
   * Do not use this field, it exists only to prevent illegal C syntax. Any
   * value written to this field will be ignored
   */
  char DO_NOT_USE_dummy_field_to_prevent_empty_struct;
} sbp_msg_almanac_t;

/**
 * Get encoded size of an instance of sbp_msg_almanac_t
 *
 * @param msg sbp_msg_almanac_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_almanac_t(const sbp_msg_almanac_t *msg);

/**
 * Encode an instance of sbp_msg_almanac_t to wire representation
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
 * @param msg Instance of sbp_msg_almanac_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_almanac_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                const sbp_msg_almanac_t *msg);

/**
 * Decode an instance of sbp_msg_almanac_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_almanac_t message
 * to the given instance. The caller must specify the length of the buffer in
 * the \p len parameter. If non-null the number of bytes read from the buffer
 * will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_almanac_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_almanac_t(const uint8_t *buf, uint8_t len,
                                uint8_t *n_read, sbp_msg_almanac_t *msg);
/**
 * Send an instance of sbp_msg_almanac_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_almanac_t
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
s8 sbp_send_sbp_msg_almanac_t(struct sbp_state *s, u16 sender_id,
                              const sbp_msg_almanac_t *msg,
                              s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_almanac_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_almanac_t instance
 * @param b sbp_msg_almanac_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_almanac_t(const sbp_msg_almanac_t *a,
                              const sbp_msg_almanac_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_SET_TIME
 *
 *****************************************************************************/
/** Send GPS time from host (host => Piksi)
 *
 * This message sets up timing functionality using a coarse GPS time estimate
 * sent by the host.
 */
typedef struct {
  /**
   * Do not use this field, it exists only to prevent illegal C syntax. Any
   * value written to this field will be ignored
   */
  char DO_NOT_USE_dummy_field_to_prevent_empty_struct;
} sbp_msg_set_time_t;

/**
 * Get encoded size of an instance of sbp_msg_set_time_t
 *
 * @param msg sbp_msg_set_time_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_set_time_t(const sbp_msg_set_time_t *msg);

/**
 * Encode an instance of sbp_msg_set_time_t to wire representation
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
 * @param msg Instance of sbp_msg_set_time_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_set_time_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_msg_set_time_t *msg);

/**
 * Decode an instance of sbp_msg_set_time_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_set_time_t message
 * to the given instance. The caller must specify the length of the buffer in
 * the \p len parameter. If non-null the number of bytes read from the buffer
 * will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_set_time_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_set_time_t(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read, sbp_msg_set_time_t *msg);
/**
 * Send an instance of sbp_msg_set_time_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_set_time_t
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
s8 sbp_send_sbp_msg_set_time_t(struct sbp_state *s, u16 sender_id,
                               const sbp_msg_set_time_t *msg,
                               s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_set_time_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_set_time_t instance
 * @param b sbp_msg_set_time_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_set_time_t(const sbp_msg_set_time_t *a,
                               const sbp_msg_set_time_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_RESET
 *
 *****************************************************************************/
/** Reset the device (host => Piksi)
 *
 * This message from the host resets the Piksi back into the bootloader.
 */
typedef struct {
  /**
   * Reset flags
   */
  u32 flags;
} sbp_msg_reset_t;

/**
 * Get encoded size of an instance of sbp_msg_reset_t
 *
 * @param msg sbp_msg_reset_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_reset_t(const sbp_msg_reset_t *msg);

/**
 * Encode an instance of sbp_msg_reset_t to wire representation
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
 * @param msg Instance of sbp_msg_reset_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_reset_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                              const sbp_msg_reset_t *msg);

/**
 * Decode an instance of sbp_msg_reset_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_reset_t message to
 * the given instance. The caller must specify the length of the buffer in the
 * \p len parameter. If non-null the number of bytes read from the buffer will
 * be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_reset_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_reset_t(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                              sbp_msg_reset_t *msg);
/**
 * Send an instance of sbp_msg_reset_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_reset_t
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
s8 sbp_send_sbp_msg_reset_t(struct sbp_state *s, u16 sender_id,
                            const sbp_msg_reset_t *msg,
                            s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_reset_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_reset_t instance
 * @param b sbp_msg_reset_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_reset_t(const sbp_msg_reset_t *a, const sbp_msg_reset_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_RESET_DEP
 *
 *****************************************************************************/
/** Reset the device (host => Piksi)
 *
 * This message from the host resets the Piksi back into the bootloader.
 */
typedef struct {
  /**
   * Do not use this field, it exists only to prevent illegal C syntax. Any
   * value written to this field will be ignored
   */
  char DO_NOT_USE_dummy_field_to_prevent_empty_struct;
} sbp_msg_reset_dep_t;

/**
 * Get encoded size of an instance of sbp_msg_reset_dep_t
 *
 * @param msg sbp_msg_reset_dep_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_reset_dep_t(const sbp_msg_reset_dep_t *msg);

/**
 * Encode an instance of sbp_msg_reset_dep_t to wire representation
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
 * @param msg Instance of sbp_msg_reset_dep_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_reset_dep_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_reset_dep_t *msg);

/**
 * Decode an instance of sbp_msg_reset_dep_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_reset_dep_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_reset_dep_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_reset_dep_t(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read, sbp_msg_reset_dep_t *msg);
/**
 * Send an instance of sbp_msg_reset_dep_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_reset_dep_t
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
s8 sbp_send_sbp_msg_reset_dep_t(struct sbp_state *s, u16 sender_id,
                                const sbp_msg_reset_dep_t *msg,
                                s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_reset_dep_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_reset_dep_t instance
 * @param b sbp_msg_reset_dep_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_reset_dep_t(const sbp_msg_reset_dep_t *a,
                                const sbp_msg_reset_dep_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_CW_RESULTS
 *
 *****************************************************************************/
/** Legacy message for CW interference channel (Piksi => host)
 *
 * This is an unused legacy message for result reporting from the CW
 * interference channel on the SwiftNAP. This message will be removed in a
 * future release.
 */
typedef struct {
  /**
   * Do not use this field, it exists only to prevent illegal C syntax. Any
   * value written to this field will be ignored
   */
  char DO_NOT_USE_dummy_field_to_prevent_empty_struct;
} sbp_msg_cw_results_t;

/**
 * Get encoded size of an instance of sbp_msg_cw_results_t
 *
 * @param msg sbp_msg_cw_results_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_cw_results_t(const sbp_msg_cw_results_t *msg);

/**
 * Encode an instance of sbp_msg_cw_results_t to wire representation
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
 * @param msg Instance of sbp_msg_cw_results_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_cw_results_t(uint8_t *buf, uint8_t len,
                                   uint8_t *n_written,
                                   const sbp_msg_cw_results_t *msg);

/**
 * Decode an instance of sbp_msg_cw_results_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_cw_results_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_cw_results_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_cw_results_t(const uint8_t *buf, uint8_t len,
                                   uint8_t *n_read, sbp_msg_cw_results_t *msg);
/**
 * Send an instance of sbp_msg_cw_results_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_cw_results_t
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
s8 sbp_send_sbp_msg_cw_results_t(struct sbp_state *s, u16 sender_id,
                                 const sbp_msg_cw_results_t *msg,
                                 s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_cw_results_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_cw_results_t instance
 * @param b sbp_msg_cw_results_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_cw_results_t(const sbp_msg_cw_results_t *a,
                                 const sbp_msg_cw_results_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_CW_START
 *
 *****************************************************************************/
/** Legacy message for CW interference channel (host => Piksi)
 *
 * This is an unused legacy message from the host for starting the CW
 * interference channel on the SwiftNAP. This message will be removed in a
 * future release.
 */
typedef struct {
  /**
   * Do not use this field, it exists only to prevent illegal C syntax. Any
   * value written to this field will be ignored
   */
  char DO_NOT_USE_dummy_field_to_prevent_empty_struct;
} sbp_msg_cw_start_t;

/**
 * Get encoded size of an instance of sbp_msg_cw_start_t
 *
 * @param msg sbp_msg_cw_start_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_cw_start_t(const sbp_msg_cw_start_t *msg);

/**
 * Encode an instance of sbp_msg_cw_start_t to wire representation
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
 * @param msg Instance of sbp_msg_cw_start_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_cw_start_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_msg_cw_start_t *msg);

/**
 * Decode an instance of sbp_msg_cw_start_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_cw_start_t message
 * to the given instance. The caller must specify the length of the buffer in
 * the \p len parameter. If non-null the number of bytes read from the buffer
 * will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_cw_start_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_cw_start_t(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read, sbp_msg_cw_start_t *msg);
/**
 * Send an instance of sbp_msg_cw_start_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_cw_start_t
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
s8 sbp_send_sbp_msg_cw_start_t(struct sbp_state *s, u16 sender_id,
                               const sbp_msg_cw_start_t *msg,
                               s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_cw_start_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_cw_start_t instance
 * @param b sbp_msg_cw_start_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_cw_start_t(const sbp_msg_cw_start_t *a,
                               const sbp_msg_cw_start_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_RESET_FILTERS
 *
 *****************************************************************************/
/** Reset IAR filters (host => Piksi)
 *
 * This message resets either the DGNSS Kalman filters or Integer Ambiguity
 * Resolution (IAR) process.
 */
typedef struct {
  /**
   * Filter flags
   */
  u8 filter;
} sbp_msg_reset_filters_t;

/**
 * Get encoded size of an instance of sbp_msg_reset_filters_t
 *
 * @param msg sbp_msg_reset_filters_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_reset_filters_t(
    const sbp_msg_reset_filters_t *msg);

/**
 * Encode an instance of sbp_msg_reset_filters_t to wire representation
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
 * @param msg Instance of sbp_msg_reset_filters_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_reset_filters_t(uint8_t *buf, uint8_t len,
                                      uint8_t *n_written,
                                      const sbp_msg_reset_filters_t *msg);

/**
 * Decode an instance of sbp_msg_reset_filters_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_reset_filters_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_reset_filters_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_reset_filters_t(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_reset_filters_t *msg);
/**
 * Send an instance of sbp_msg_reset_filters_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_reset_filters_t
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
s8 sbp_send_sbp_msg_reset_filters_t(struct sbp_state *s, u16 sender_id,
                                    const sbp_msg_reset_filters_t *msg,
                                    s32 (*write)(u8 *buff, u32 n,
                                                 void *context));

/**
 * Compare two instances of sbp_msg_reset_filters_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_reset_filters_t instance
 * @param b sbp_msg_reset_filters_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_reset_filters_t(const sbp_msg_reset_filters_t *a,
                                    const sbp_msg_reset_filters_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_INIT_BASE_DEP
 *
 *****************************************************************************/
/** Deprecated
 *
 * Deprecated
 */
typedef struct {
  /**
   * Do not use this field, it exists only to prevent illegal C syntax. Any
   * value written to this field will be ignored
   */
  char DO_NOT_USE_dummy_field_to_prevent_empty_struct;
} sbp_msg_init_base_dep_t;

/**
 * Get encoded size of an instance of sbp_msg_init_base_dep_t
 *
 * @param msg sbp_msg_init_base_dep_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_init_base_dep_t(
    const sbp_msg_init_base_dep_t *msg);

/**
 * Encode an instance of sbp_msg_init_base_dep_t to wire representation
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
 * @param msg Instance of sbp_msg_init_base_dep_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_init_base_dep_t(uint8_t *buf, uint8_t len,
                                      uint8_t *n_written,
                                      const sbp_msg_init_base_dep_t *msg);

/**
 * Decode an instance of sbp_msg_init_base_dep_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_init_base_dep_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_init_base_dep_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_init_base_dep_t(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_init_base_dep_t *msg);
/**
 * Send an instance of sbp_msg_init_base_dep_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_init_base_dep_t
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
s8 sbp_send_sbp_msg_init_base_dep_t(struct sbp_state *s, u16 sender_id,
                                    const sbp_msg_init_base_dep_t *msg,
                                    s32 (*write)(u8 *buff, u32 n,
                                                 void *context));

/**
 * Compare two instances of sbp_msg_init_base_dep_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_init_base_dep_t instance
 * @param b sbp_msg_init_base_dep_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_init_base_dep_t(const sbp_msg_init_base_dep_t *a,
                                    const sbp_msg_init_base_dep_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_THREAD_STATE
 *
 *****************************************************************************/
/** State of an RTOS thread
 *
 * The thread usage message from the device reports real-time operating system
 * (RTOS) thread usage statistics for the named thread. The reported percentage
 * values must be normalized.
 */
typedef struct {
  /**
   * Thread name (NULL terminated)
   */
  char name[20];

  /**
   * Percentage cpu use for this thread. Values range from 0 - 1000 and needs to
   * be renormalized to 100
   */
  u16 cpu;

  /**
   * Free stack space for this thread [bytes]
   */
  u32 stack_free;
} sbp_msg_thread_state_t;

/**
 * Get encoded size of an instance of sbp_msg_thread_state_t
 *
 * @param msg sbp_msg_thread_state_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_thread_state_t(
    const sbp_msg_thread_state_t *msg);

/**
 * Encode an instance of sbp_msg_thread_state_t to wire representation
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
 * @param msg Instance of sbp_msg_thread_state_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_thread_state_t(uint8_t *buf, uint8_t len,
                                     uint8_t *n_written,
                                     const sbp_msg_thread_state_t *msg);

/**
 * Decode an instance of sbp_msg_thread_state_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_thread_state_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_thread_state_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_thread_state_t(const uint8_t *buf, uint8_t len,
                                     uint8_t *n_read,
                                     sbp_msg_thread_state_t *msg);
/**
 * Send an instance of sbp_msg_thread_state_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_thread_state_t
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
s8 sbp_send_sbp_msg_thread_state_t(struct sbp_state *s, u16 sender_id,
                                   const sbp_msg_thread_state_t *msg,
                                   s32 (*write)(u8 *buff, u32 n,
                                                void *context));

/**
 * Compare two instances of sbp_msg_thread_state_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_thread_state_t instance
 * @param b sbp_msg_thread_state_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_thread_state_t(const sbp_msg_thread_state_t *a,
                                   const sbp_msg_thread_state_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_UARTCHANNEL
 *
 *****************************************************************************/
/** State of the UART channel
 *
 * Throughput, utilization, and error counts on the RX/TX buffers of this UART
 * channel. The reported percentage values must be normalized.
 */
typedef struct {
  /**
   * UART transmit throughput [kB/s]
   */
  float tx_throughput;

  /**
   * UART receive throughput [kB/s]
   */
  float rx_throughput;

  /**
   * UART CRC error count
   */
  u16 crc_error_count;

  /**
   * UART IO error count
   */
  u16 io_error_count;

  /**
   * UART transmit buffer percentage utilization (ranges from 0 to 255)
   */
  u8 tx_buffer_level;

  /**
   * UART receive buffer percentage utilization (ranges from 0 to 255)
   */
  u8 rx_buffer_level;
} sbp_uart_channel_t;

/**
 * Get encoded size of an instance of sbp_uart_channel_t
 *
 * @param msg sbp_uart_channel_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_uart_channel_t(const sbp_uart_channel_t *msg);

/**
 * Encode an instance of sbp_uart_channel_t to wire representation
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
 * @param msg Instance of sbp_uart_channel_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_uart_channel_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_uart_channel_t *msg);

/**
 * Decode an instance of sbp_uart_channel_t from wire representation
 *
 * This function decodes the wire representation of a sbp_uart_channel_t message
 * to the given instance. The caller must specify the length of the buffer in
 * the \p len parameter. If non-null the number of bytes read from the buffer
 * will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_uart_channel_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_uart_channel_t(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read, sbp_uart_channel_t *msg);

/**
 * Compare two instances of sbp_uart_channel_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_uart_channel_t instance
 * @param b sbp_uart_channel_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_uart_channel_t(const sbp_uart_channel_t *a,
                               const sbp_uart_channel_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_PERIOD
 *
 *****************************************************************************/
/** base station observation message receipt period
 *
 * Statistics on the period of observations received from the base station. As
 * complete observation sets are received, their time of reception is compared
 * with the prior set''s time of reception. This measurement provides a proxy
 * for link quality as incomplete or missing sets will increase the period. Long
 * periods can cause momentary RTK solution outages.
 */
typedef struct {
  /**
   * Average period [ms]
   */
  s32 avg;

  /**
   * Minimum period [ms]
   */
  s32 pmin;

  /**
   * Maximum period [ms]
   */
  s32 pmax;

  /**
   * Smoothed estimate of the current period [ms]
   */
  s32 current;
} sbp_period_t;

/**
 * Get encoded size of an instance of sbp_period_t
 *
 * @param msg sbp_period_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_period_t(const sbp_period_t *msg);

/**
 * Encode an instance of sbp_period_t to wire representation
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
 * @param msg Instance of sbp_period_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_period_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                           const sbp_period_t *msg);

/**
 * Decode an instance of sbp_period_t from wire representation
 *
 * This function decodes the wire representation of a sbp_period_t message to
 * the given instance. The caller must specify the length of the buffer in the
 * \p len parameter. If non-null the number of bytes read from the buffer will
 * be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_period_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_period_t(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                           sbp_period_t *msg);

/**
 * Compare two instances of sbp_period_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_period_t instance
 * @param b sbp_period_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_period_t(const sbp_period_t *a, const sbp_period_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_LATENCY
 *
 *****************************************************************************/
/** Receiver-to-base station latency
 *
 * Statistics on the latency of observations received from the base station. As
 * observation packets are received their GPS time is compared to the current
 * GPS time calculated locally by the receiver to give a precise measurement of
 * the end-to-end communication latency in the system.
 */
typedef struct {
  /**
   * Average latency [ms]
   */
  s32 avg;

  /**
   * Minimum latency [ms]
   */
  s32 lmin;

  /**
   * Maximum latency [ms]
   */
  s32 lmax;

  /**
   * Smoothed estimate of the current latency [ms]
   */
  s32 current;
} sbp_latency_t;

/**
 * Get encoded size of an instance of sbp_latency_t
 *
 * @param msg sbp_latency_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_latency_t(const sbp_latency_t *msg);

/**
 * Encode an instance of sbp_latency_t to wire representation
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
 * @param msg Instance of sbp_latency_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_latency_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                            const sbp_latency_t *msg);

/**
 * Decode an instance of sbp_latency_t from wire representation
 *
 * This function decodes the wire representation of a sbp_latency_t message to
 * the given instance. The caller must specify the length of the buffer in the
 * \p len parameter. If non-null the number of bytes read from the buffer will
 * be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_latency_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_latency_t(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                            sbp_latency_t *msg);

/**
 * Compare two instances of sbp_latency_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_latency_t instance
 * @param b sbp_latency_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_latency_t(const sbp_latency_t *a, const sbp_latency_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_UART_STATE
 *
 *****************************************************************************/
/** State of the UART channels
 *
 * The UART message reports data latency and throughput of the UART channels
 * providing SBP I/O. On the default Piksi configuration, UARTs A and B are used
 * for telemetry radios, but can also be host access ports for embedded hosts,
 * or other interfaces in future. The reported percentage values must be
 * normalized. Observations latency and period can be used to assess the health
 * of the differential corrections link. Latency provides the timeliness of
 * received base observations while the period indicates their likelihood of
 * transmission.
 */
typedef struct {
  /**
   * State of UART A
   */
  sbp_uart_channel_t uart_a;

  /**
   * State of UART B
   */
  sbp_uart_channel_t uart_b;

  /**
   * State of UART FTDI (USB logger)
   */
  sbp_uart_channel_t uart_ftdi;

  /**
   * UART communication latency
   */
  sbp_latency_t latency;

  /**
   * Observation receipt period
   */
  sbp_period_t obs_period;
} sbp_msg_uart_state_t;

/**
 * Get encoded size of an instance of sbp_msg_uart_state_t
 *
 * @param msg sbp_msg_uart_state_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_uart_state_t(const sbp_msg_uart_state_t *msg);

/**
 * Encode an instance of sbp_msg_uart_state_t to wire representation
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
 * @param msg Instance of sbp_msg_uart_state_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_uart_state_t(uint8_t *buf, uint8_t len,
                                   uint8_t *n_written,
                                   const sbp_msg_uart_state_t *msg);

/**
 * Decode an instance of sbp_msg_uart_state_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_uart_state_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_uart_state_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_uart_state_t(const uint8_t *buf, uint8_t len,
                                   uint8_t *n_read, sbp_msg_uart_state_t *msg);
/**
 * Send an instance of sbp_msg_uart_state_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_uart_state_t
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
s8 sbp_send_sbp_msg_uart_state_t(struct sbp_state *s, u16 sender_id,
                                 const sbp_msg_uart_state_t *msg,
                                 s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_uart_state_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_uart_state_t instance
 * @param b sbp_msg_uart_state_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_uart_state_t(const sbp_msg_uart_state_t *a,
                                 const sbp_msg_uart_state_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_UART_STATE_DEPA
 *
 *****************************************************************************/
/** Deprecated
 *
 * Deprecated
 */
typedef struct {
  /**
   * State of UART A
   */
  sbp_uart_channel_t uart_a;

  /**
   * State of UART B
   */
  sbp_uart_channel_t uart_b;

  /**
   * State of UART FTDI (USB logger)
   */
  sbp_uart_channel_t uart_ftdi;

  /**
   * UART communication latency
   */
  sbp_latency_t latency;
} sbp_msg_uart_state_depa_t;

/**
 * Get encoded size of an instance of sbp_msg_uart_state_depa_t
 *
 * @param msg sbp_msg_uart_state_depa_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_uart_state_depa_t(
    const sbp_msg_uart_state_depa_t *msg);

/**
 * Encode an instance of sbp_msg_uart_state_depa_t to wire representation
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
 * @param msg Instance of sbp_msg_uart_state_depa_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_uart_state_depa_t(uint8_t *buf, uint8_t len,
                                        uint8_t *n_written,
                                        const sbp_msg_uart_state_depa_t *msg);

/**
 * Decode an instance of sbp_msg_uart_state_depa_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_uart_state_depa_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_uart_state_depa_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_uart_state_depa_t(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_uart_state_depa_t *msg);
/**
 * Send an instance of sbp_msg_uart_state_depa_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_uart_state_depa_t
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
s8 sbp_send_sbp_msg_uart_state_depa_t(struct sbp_state *s, u16 sender_id,
                                      const sbp_msg_uart_state_depa_t *msg,
                                      s32 (*write)(u8 *buff, u32 n,
                                                   void *context));

/**
 * Compare two instances of sbp_msg_uart_state_depa_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_uart_state_depa_t instance
 * @param b sbp_msg_uart_state_depa_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_uart_state_depa_t(const sbp_msg_uart_state_depa_t *a,
                                      const sbp_msg_uart_state_depa_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_IAR_STATE
 *
 *****************************************************************************/
/** State of the Integer Ambiguity Resolution (IAR) process
 *
 * This message reports the state of the Integer Ambiguity Resolution (IAR)
 * process, which resolves unknown integer ambiguities from double-differenced
 * carrier-phase measurements from satellite observations.
 */
typedef struct {
  /**
   * Number of integer ambiguity hypotheses remaining
   */
  u32 num_hyps;
} sbp_msg_iar_state_t;

/**
 * Get encoded size of an instance of sbp_msg_iar_state_t
 *
 * @param msg sbp_msg_iar_state_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_iar_state_t(const sbp_msg_iar_state_t *msg);

/**
 * Encode an instance of sbp_msg_iar_state_t to wire representation
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
 * @param msg Instance of sbp_msg_iar_state_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_iar_state_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_iar_state_t *msg);

/**
 * Decode an instance of sbp_msg_iar_state_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_iar_state_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_iar_state_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_iar_state_t(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read, sbp_msg_iar_state_t *msg);
/**
 * Send an instance of sbp_msg_iar_state_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_iar_state_t
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
s8 sbp_send_sbp_msg_iar_state_t(struct sbp_state *s, u16 sender_id,
                                const sbp_msg_iar_state_t *msg,
                                s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_iar_state_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_iar_state_t instance
 * @param b sbp_msg_iar_state_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_iar_state_t(const sbp_msg_iar_state_t *a,
                                const sbp_msg_iar_state_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_MASK_SATELLITE
 *
 *****************************************************************************/
/** Mask a satellite from use in Piksi subsystems
 *
 * This message allows setting a mask to prevent a particular satellite from
 * being used in various Piksi subsystems.
 */
typedef struct {
  /**
   * Mask of systems that should ignore this satellite.
   */
  u8 mask;

  /**
   * GNSS signal for which the mask is applied
   */
  sbp_sbp_gnss_signal_t sid;
} sbp_msg_mask_satellite_t;

/**
 * Get encoded size of an instance of sbp_msg_mask_satellite_t
 *
 * @param msg sbp_msg_mask_satellite_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_mask_satellite_t(
    const sbp_msg_mask_satellite_t *msg);

/**
 * Encode an instance of sbp_msg_mask_satellite_t to wire representation
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
 * @param msg Instance of sbp_msg_mask_satellite_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_mask_satellite_t(uint8_t *buf, uint8_t len,
                                       uint8_t *n_written,
                                       const sbp_msg_mask_satellite_t *msg);

/**
 * Decode an instance of sbp_msg_mask_satellite_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_mask_satellite_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_mask_satellite_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_mask_satellite_t(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_msg_mask_satellite_t *msg);
/**
 * Send an instance of sbp_msg_mask_satellite_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_mask_satellite_t
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
s8 sbp_send_sbp_msg_mask_satellite_t(struct sbp_state *s, u16 sender_id,
                                     const sbp_msg_mask_satellite_t *msg,
                                     s32 (*write)(u8 *buff, u32 n,
                                                  void *context));

/**
 * Compare two instances of sbp_msg_mask_satellite_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_mask_satellite_t instance
 * @param b sbp_msg_mask_satellite_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_mask_satellite_t(const sbp_msg_mask_satellite_t *a,
                                     const sbp_msg_mask_satellite_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_MASK_SATELLITE_DEP
 *
 *****************************************************************************/
/** Deprecated
 *
 * Deprecated.
 */
typedef struct {
  /**
   * Mask of systems that should ignore this satellite.
   */
  u8 mask;

  /**
   * GNSS signal for which the mask is applied
   */
  sbp_gnss_signal_dep_t sid;
} sbp_msg_mask_satellite_dep_t;

/**
 * Get encoded size of an instance of sbp_msg_mask_satellite_dep_t
 *
 * @param msg sbp_msg_mask_satellite_dep_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_mask_satellite_dep_t(
    const sbp_msg_mask_satellite_dep_t *msg);

/**
 * Encode an instance of sbp_msg_mask_satellite_dep_t to wire representation
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
 * @param msg Instance of sbp_msg_mask_satellite_dep_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_mask_satellite_dep_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_mask_satellite_dep_t *msg);

/**
 * Decode an instance of sbp_msg_mask_satellite_dep_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_mask_satellite_dep_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_mask_satellite_dep_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_mask_satellite_dep_t(const uint8_t *buf, uint8_t len,
                                           uint8_t *n_read,
                                           sbp_msg_mask_satellite_dep_t *msg);
/**
 * Send an instance of sbp_msg_mask_satellite_dep_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_mask_satellite_dep_t
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
s8 sbp_send_sbp_msg_mask_satellite_dep_t(
    struct sbp_state *s, u16 sender_id, const sbp_msg_mask_satellite_dep_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_mask_satellite_dep_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_mask_satellite_dep_t instance
 * @param b sbp_msg_mask_satellite_dep_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_mask_satellite_dep_t(const sbp_msg_mask_satellite_dep_t *a,
                                         const sbp_msg_mask_satellite_dep_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_DEVICE_MONITOR
 *
 *****************************************************************************/
/** Device temperature and voltage levels
 *
 * This message contains temperature and voltage level measurements from the
 * processor's monitoring system and the RF frontend die temperature if
 * available.
 */
typedef struct {
  /**
   * Device V_in [V / 1000]
   */
  s16 dev_vin;

  /**
   * Processor V_int [V / 1000]
   */
  s16 cpu_vint;

  /**
   * Processor V_aux [V / 1000]
   */
  s16 cpu_vaux;

  /**
   * Processor temperature [degrees C / 100]
   */
  s16 cpu_temperature;

  /**
   * Frontend temperature (if available) [degrees C / 100]
   */
  s16 fe_temperature;
} sbp_msg_device_monitor_t;

/**
 * Get encoded size of an instance of sbp_msg_device_monitor_t
 *
 * @param msg sbp_msg_device_monitor_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_device_monitor_t(
    const sbp_msg_device_monitor_t *msg);

/**
 * Encode an instance of sbp_msg_device_monitor_t to wire representation
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
 * @param msg Instance of sbp_msg_device_monitor_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_device_monitor_t(uint8_t *buf, uint8_t len,
                                       uint8_t *n_written,
                                       const sbp_msg_device_monitor_t *msg);

/**
 * Decode an instance of sbp_msg_device_monitor_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_device_monitor_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_device_monitor_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_device_monitor_t(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_msg_device_monitor_t *msg);
/**
 * Send an instance of sbp_msg_device_monitor_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_device_monitor_t
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
s8 sbp_send_sbp_msg_device_monitor_t(struct sbp_state *s, u16 sender_id,
                                     const sbp_msg_device_monitor_t *msg,
                                     s32 (*write)(u8 *buff, u32 n,
                                                  void *context));

/**
 * Compare two instances of sbp_msg_device_monitor_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_device_monitor_t instance
 * @param b sbp_msg_device_monitor_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_device_monitor_t(const sbp_msg_device_monitor_t *a,
                                     const sbp_msg_device_monitor_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_COMMAND_REQ
 *
 *****************************************************************************/
/** Execute a command (host => device)
 *
 * Request the recipient to execute an command. Output will be sent in MSG_LOG
 * messages, and the exit code will be returned with MSG_COMMAND_RESP.
 */
typedef struct {
  /**
   * Sequence number
   */
  u32 sequence;

  /**
   * Command line to execute
   */
  sbp_null_terminated_string_t command;
} sbp_msg_command_req_t;

/**
 * Initialise sbp_msg_command_req_t::command to empty
 *
 * @param msg sbp_msg_command_req_t instance
 */
void sbp_msg_command_req_t_command_init(sbp_null_terminated_string_t *s);

/**
 * Test sbp_msg_command_req_t::command for validity
 *
 * @param msg sbp_msg_command_req_t instance
 * @return true is sbp_msg_command_req_t::command is valid for encoding
 * purposes, false otherwise
 */
bool sbp_msg_command_req_t_command_valid(const sbp_null_terminated_string_t *s);

/**
 * Tests 2 instances of sbp_msg_command_req_t::command for equality
 *
 * Returns a value with the same definitions as #strcmp from the C standard
 * library
 *
 * @param a sbp_msg_command_req_t instance
 * @param b sbp_msg_command_req_t instance
 * @return 0 if equal, <0 if a<b, >0 if a>b
 */
int sbp_msg_command_req_t_command_strcmp(const sbp_null_terminated_string_t *a,
                                         const sbp_null_terminated_string_t *b);

/**
 * Get the encoded size of sbp_msg_command_req_t::command
 *
 * @param msg sbp_msg_command_req_t instance
 * @return Size of sbp_msg_command_req_t::command in wire representation
 */
uint8_t sbp_msg_command_req_t_command_packed_len(
    const sbp_null_terminated_string_t *s);

/**
 * Query sbp_msg_command_req_t::command for remaining space
 *
 * Returns the number of bytes (not including NULL terminator) which can be
 * added to sbp_msg_command_req_t::command before it exceeds the maximum size of
 * the field in wire representation
 *
 * @param msg sbp_msg_command_req_t instance
 * @return Maximum number of bytes that can be appended to the existing string
 */
uint8_t sbp_msg_command_req_t_command_space_remaining(
    const sbp_null_terminated_string_t *s);
/**
 * Set sbp_msg_command_req_t::command
 *
 * Erase any existing content and replace with the specified string
 *
 * This function will return true if the new string was successfully applied. If
 * the specified string is longer than can be represented in wire encoding this
 * function will return false
 *
 * @param msg sbp_msg_command_req_t instance
 * @param new_str New string
 * @return true on success, false otherwise
 */
bool sbp_msg_command_req_t_command_set(sbp_null_terminated_string_t *s,
                                       const char *new_str);

/**
 * Set sbp_msg_command_req_t::command with printf style formatting
 *
 * Erase any existing content and replace with the formatted string
 *
 * This function will return true if the new string was successfully applied. If
 * the operation would end up overflowing the maximum size of this field in wire
 * encoding the existing contents will be erased and this function will return
 * false.
 *
 * @param msg sbp_msg_command_req_t instance
 * @param fmt printf style format string
 * @return true on success, false otherwise
 */
bool sbp_msg_command_req_t_command_printf(sbp_null_terminated_string_t *s,
                                          const char *fmt, ...)
    SBP_ATTR_FORMAT(2, 3);

/**
 * Set sbp_msg_command_req_t::command with printf style formatting
 *
 * Identical to #sbp_msg_command_req_t_command_printf except it takes a va_list
 * argument
 *
 * @param msg sbp_msg_command_req_t instance
 * @param fmt printf style format string
 * @param ap Argument list
 * @return true on success, false otherwise
 */
bool sbp_msg_command_req_t_command_vprintf(sbp_null_terminated_string_t *s,
                                           const char *fmt, va_list ap);

/**
 * Append sbp_msg_command_req_t::command with printf style formatting
 *
 * The new string will be appended to the existing contents of the string (if
 * any). If the operation would end up overflowing the maximum size of this
 * field in wire encoding the existing contents will be unmodified and this
 * function will return false.
 *
 * @param msg sbp_msg_command_req_t instance
 * @param fmt printf style format string
 * @return true on success, false otherwise
 */
bool sbp_msg_command_req_t_command_append_printf(
    sbp_null_terminated_string_t *s, const char *fmt, ...)
    SBP_ATTR_FORMAT(2, 3);

/**
 * Append sbp_msg_command_req_t::command with printf style formatting
 *
 * Identical to #sbp_msg_command_req_t_command_append_printf except it takes a
 * va_list argument
 *
 * @param msg sbp_msg_command_req_t instance
 * @param fmt printf style format string
 * @param ap Argument list
 * @return true on success, false otherwise
 *
 */
bool sbp_msg_command_req_t_command_append_vprintf(
    sbp_null_terminated_string_t *s, const char *fmt, va_list ap);

/**
 * Obtain the string value from sbp_msg_command_req_t::command
 *
 * @param msg sbp_msg_command_req_t instance
 * @return String contents
 */
const char *sbp_msg_command_req_t_command_get(
    const sbp_null_terminated_string_t *s);

/**
 * Obtain the length of sbp_msg_command_req_t::command
 *
 * The returned value does not include the NULL terminator.
 *
 * @param msg sbp_msg_command_req_t instance
 * @return Length of section
 */
uint8_t sbp_msg_command_req_t_command_section_strlen(
    const sbp_null_terminated_string_t *s, uint8_t section);

/**
 * Get encoded size of an instance of sbp_msg_command_req_t
 *
 * @param msg sbp_msg_command_req_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_command_req_t(const sbp_msg_command_req_t *msg);

/**
 * Encode an instance of sbp_msg_command_req_t to wire representation
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
 * @param msg Instance of sbp_msg_command_req_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_command_req_t(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_msg_command_req_t *msg);

/**
 * Decode an instance of sbp_msg_command_req_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_command_req_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_command_req_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_command_req_t(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_msg_command_req_t *msg);
/**
 * Send an instance of sbp_msg_command_req_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_command_req_t
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
s8 sbp_send_sbp_msg_command_req_t(struct sbp_state *s, u16 sender_id,
                                  const sbp_msg_command_req_t *msg,
                                  s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_command_req_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_command_req_t instance
 * @param b sbp_msg_command_req_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_command_req_t(const sbp_msg_command_req_t *a,
                                  const sbp_msg_command_req_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_COMMAND_RESP
 *
 *****************************************************************************/
/** Exit code from executed command (device => host)
 *
 * The response to MSG_COMMAND_REQ with the return code of the command.  A
 * return code of zero indicates success.
 */
typedef struct {
  /**
   * Sequence number
   */
  u32 sequence;

  /**
   * Exit code
   */
  s32 code;
} sbp_msg_command_resp_t;

/**
 * Get encoded size of an instance of sbp_msg_command_resp_t
 *
 * @param msg sbp_msg_command_resp_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_command_resp_t(
    const sbp_msg_command_resp_t *msg);

/**
 * Encode an instance of sbp_msg_command_resp_t to wire representation
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
 * @param msg Instance of sbp_msg_command_resp_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_command_resp_t(uint8_t *buf, uint8_t len,
                                     uint8_t *n_written,
                                     const sbp_msg_command_resp_t *msg);

/**
 * Decode an instance of sbp_msg_command_resp_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_command_resp_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_command_resp_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_command_resp_t(const uint8_t *buf, uint8_t len,
                                     uint8_t *n_read,
                                     sbp_msg_command_resp_t *msg);
/**
 * Send an instance of sbp_msg_command_resp_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_command_resp_t
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
s8 sbp_send_sbp_msg_command_resp_t(struct sbp_state *s, u16 sender_id,
                                   const sbp_msg_command_resp_t *msg,
                                   s32 (*write)(u8 *buff, u32 n,
                                                void *context));

/**
 * Compare two instances of sbp_msg_command_resp_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_command_resp_t instance
 * @param b sbp_msg_command_resp_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_command_resp_t(const sbp_msg_command_resp_t *a,
                                   const sbp_msg_command_resp_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_COMMAND_OUTPUT
 *
 *****************************************************************************/
/** Command output
 *
 * Returns the standard output and standard error of the command requested by
 * MSG_COMMAND_REQ. The sequence number can be used to filter for filtering the
 * correct command.
 */
typedef struct {
  /**
   * Sequence number
   */
  u32 sequence;

  /**
   * Line of standard output or standard error
   */
  sbp_unterminated_string_t line;
} sbp_msg_command_output_t;

/**
 * Initialise sbp_msg_command_output_t::line to empty
 *
 * @param msg sbp_msg_command_output_t instance
 */
void sbp_msg_command_output_t_line_init(sbp_unterminated_string_t *s);

/**
 * Test sbp_msg_command_output_t::line for validity
 *
 * @param msg sbp_msg_command_output_t instance
 * @return true is sbp_msg_command_output_t::line is valid for encoding
 * purposes, false otherwise
 */
bool sbp_msg_command_output_t_line_valid(const sbp_unterminated_string_t *s);

/**
 * Tests 2 instances of sbp_msg_command_output_t::line for equality
 *
 * Returns a value with the same definitions as #strcmp from the C standard
 * library
 *
 * @param a sbp_msg_command_output_t instance
 * @param b sbp_msg_command_output_t instance
 * @return 0 if equal, <0 if a<b, >0 if a>b
 */
int sbp_msg_command_output_t_line_strcmp(const sbp_unterminated_string_t *a,
                                         const sbp_unterminated_string_t *b);

/**
 * Get the encoded size of sbp_msg_command_output_t::line
 *
 * @param msg sbp_msg_command_output_t instance
 * @return Size of sbp_msg_command_output_t::line in wire representation
 */
uint8_t sbp_msg_command_output_t_line_packed_len(
    const sbp_unterminated_string_t *s);

/**
 * Query sbp_msg_command_output_t::line for remaining space
 *
 * Returns the number of bytes (not including NULL terminator) which can be
 * added to sbp_msg_command_output_t::line before it exceeds the maximum size of
 * the field in wire representation
 *
 * @param msg sbp_msg_command_output_t instance
 * @return Maximum number of bytes that can be appended to the existing string
 */
uint8_t sbp_msg_command_output_t_line_space_remaining(
    const sbp_unterminated_string_t *s);
/**
 * Set sbp_msg_command_output_t::line
 *
 * Erase any existing content and replace with the specified string
 *
 * This function will return true if the new string was successfully applied. If
 * the specified string is longer than can be represented in wire encoding this
 * function will return false
 *
 * @param msg sbp_msg_command_output_t instance
 * @param new_str New string
 * @return true on success, false otherwise
 */
bool sbp_msg_command_output_t_line_set(sbp_unterminated_string_t *s,
                                       const char *new_str);

/**
 * Set sbp_msg_command_output_t::line with printf style formatting
 *
 * Erase any existing content and replace with the formatted string
 *
 * This function will return true if the new string was successfully applied. If
 * the operation would end up overflowing the maximum size of this field in wire
 * encoding the existing contents will be erased and this function will return
 * false.
 *
 * @param msg sbp_msg_command_output_t instance
 * @param fmt printf style format string
 * @return true on success, false otherwise
 */
bool sbp_msg_command_output_t_line_printf(sbp_unterminated_string_t *s,
                                          const char *fmt, ...)
    SBP_ATTR_FORMAT(2, 3);

/**
 * Set sbp_msg_command_output_t::line with printf style formatting
 *
 * Identical to #sbp_msg_command_output_t_line_printf except it takes a va_list
 * argument
 *
 * @param msg sbp_msg_command_output_t instance
 * @param fmt printf style format string
 * @param ap Argument list
 * @return true on success, false otherwise
 */
bool sbp_msg_command_output_t_line_vprintf(sbp_unterminated_string_t *s,
                                           const char *fmt, va_list ap);

/**
 * Append sbp_msg_command_output_t::line with printf style formatting
 *
 * The new string will be appended to the existing contents of the string (if
 * any). If the operation would end up overflowing the maximum size of this
 * field in wire encoding the existing contents will be unmodified and this
 * function will return false.
 *
 * @param msg sbp_msg_command_output_t instance
 * @param fmt printf style format string
 * @return true on success, false otherwise
 */
bool sbp_msg_command_output_t_line_append_printf(sbp_unterminated_string_t *s,
                                                 const char *fmt, ...)
    SBP_ATTR_FORMAT(2, 3);

/**
 * Append sbp_msg_command_output_t::line with printf style formatting
 *
 * Identical to #sbp_msg_command_output_t_line_append_printf except it takes a
 * va_list argument
 *
 * @param msg sbp_msg_command_output_t instance
 * @param fmt printf style format string
 * @param ap Argument list
 * @return true on success, false otherwise
 *
 */
bool sbp_msg_command_output_t_line_append_vprintf(sbp_unterminated_string_t *s,
                                                  const char *fmt, va_list ap);

/**
 * Obtain the string value from sbp_msg_command_output_t::line
 *
 * @param msg sbp_msg_command_output_t instance
 * @return String contents
 */
const char *sbp_msg_command_output_t_line_get(
    const sbp_unterminated_string_t *s);

/**
 * Obtain the length of sbp_msg_command_output_t::line
 *
 * The returned value does not include the NULL terminator.
 *
 * @param msg sbp_msg_command_output_t instance
 * @return Length of section
 */
uint8_t sbp_msg_command_output_t_line_section_strlen(
    const sbp_unterminated_string_t *s, uint8_t section);

/**
 * Get encoded size of an instance of sbp_msg_command_output_t
 *
 * @param msg sbp_msg_command_output_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_command_output_t(
    const sbp_msg_command_output_t *msg);

/**
 * Encode an instance of sbp_msg_command_output_t to wire representation
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
 * @param msg Instance of sbp_msg_command_output_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_command_output_t(uint8_t *buf, uint8_t len,
                                       uint8_t *n_written,
                                       const sbp_msg_command_output_t *msg);

/**
 * Decode an instance of sbp_msg_command_output_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_command_output_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_command_output_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_command_output_t(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_msg_command_output_t *msg);
/**
 * Send an instance of sbp_msg_command_output_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_command_output_t
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
s8 sbp_send_sbp_msg_command_output_t(struct sbp_state *s, u16 sender_id,
                                     const sbp_msg_command_output_t *msg,
                                     s32 (*write)(u8 *buff, u32 n,
                                                  void *context));

/**
 * Compare two instances of sbp_msg_command_output_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_command_output_t instance
 * @param b sbp_msg_command_output_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_command_output_t(const sbp_msg_command_output_t *a,
                                     const sbp_msg_command_output_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_NETWORK_STATE_REQ
 *
 *****************************************************************************/
/** Request state of Piksi network interfaces
 *
 * Request state of Piksi network interfaces. Output will be sent in
 * MSG_NETWORK_STATE_RESP messages.
 */
typedef struct {
  /**
   * Do not use this field, it exists only to prevent illegal C syntax. Any
   * value written to this field will be ignored
   */
  char DO_NOT_USE_dummy_field_to_prevent_empty_struct;
} sbp_msg_network_state_req_t;

/**
 * Get encoded size of an instance of sbp_msg_network_state_req_t
 *
 * @param msg sbp_msg_network_state_req_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_network_state_req_t(
    const sbp_msg_network_state_req_t *msg);

/**
 * Encode an instance of sbp_msg_network_state_req_t to wire representation
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
 * @param msg Instance of sbp_msg_network_state_req_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_network_state_req_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_network_state_req_t *msg);

/**
 * Decode an instance of sbp_msg_network_state_req_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_network_state_req_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_network_state_req_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_network_state_req_t(const uint8_t *buf, uint8_t len,
                                          uint8_t *n_read,
                                          sbp_msg_network_state_req_t *msg);
/**
 * Send an instance of sbp_msg_network_state_req_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_network_state_req_t
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
s8 sbp_send_sbp_msg_network_state_req_t(struct sbp_state *s, u16 sender_id,
                                        const sbp_msg_network_state_req_t *msg,
                                        s32 (*write)(u8 *buff, u32 n,
                                                     void *context));

/**
 * Compare two instances of sbp_msg_network_state_req_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_network_state_req_t instance
 * @param b sbp_msg_network_state_req_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_network_state_req_t(const sbp_msg_network_state_req_t *a,
                                        const sbp_msg_network_state_req_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_NETWORK_STATE_RESP
 *
 *****************************************************************************/
/** State of network interface
 *
 * The state of a network interface on the Piksi. Data is made to reflect output
 * of ifaddrs struct returned by getifaddrs in c.
 */
typedef struct {
  /**
   * IPv4 address (all zero when unavailable)
   */
  u8 ipv4_address[4];

  /**
   * IPv4 netmask CIDR notation
   */
  u8 ipv4_mask_size;

  /**
   * IPv6 address (all zero when unavailable)
   */
  u8 ipv6_address[16];

  /**
   * IPv6 netmask CIDR notation
   */
  u8 ipv6_mask_size;

  /**
   * Number of Rx bytes
   */
  u32 rx_bytes;

  /**
   * Number of Tx bytes
   */
  u32 tx_bytes;

  /**
   * Interface Name
   */
  char interface_name[16];

  /**
   * Interface flags from SIOCGIFFLAGS
   */
  u32 flags;
} sbp_msg_network_state_resp_t;

/**
 * Get encoded size of an instance of sbp_msg_network_state_resp_t
 *
 * @param msg sbp_msg_network_state_resp_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_network_state_resp_t(
    const sbp_msg_network_state_resp_t *msg);

/**
 * Encode an instance of sbp_msg_network_state_resp_t to wire representation
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
 * @param msg Instance of sbp_msg_network_state_resp_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_network_state_resp_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_network_state_resp_t *msg);

/**
 * Decode an instance of sbp_msg_network_state_resp_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_network_state_resp_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_network_state_resp_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_network_state_resp_t(const uint8_t *buf, uint8_t len,
                                           uint8_t *n_read,
                                           sbp_msg_network_state_resp_t *msg);
/**
 * Send an instance of sbp_msg_network_state_resp_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_network_state_resp_t
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
s8 sbp_send_sbp_msg_network_state_resp_t(
    struct sbp_state *s, u16 sender_id, const sbp_msg_network_state_resp_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_network_state_resp_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_network_state_resp_t instance
 * @param b sbp_msg_network_state_resp_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_network_state_resp_t(const sbp_msg_network_state_resp_t *a,
                                         const sbp_msg_network_state_resp_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_NETWORKUSAGE
 *
 *****************************************************************************/
/** Bandwidth usage measurement for a single interface
 *
 * The bandwidth usage for each interface can be reported within this struct and
 * utilize multiple fields to fully specify the type of traffic that is being
 * tracked. As either the interval of collection or the collection time may
 * vary, both a timestamp and period field is provided, though may not
 * necessarily be populated with a value.
 */
typedef struct {
  /**
   * Duration over which the measurement was collected [ms]
   */
  u64 duration;

  /**
   * Number of bytes handled in total within period
   */
  u64 total_bytes;

  /**
   * Number of bytes transmitted within period
   */
  u32 rx_bytes;

  /**
   * Number of bytes received within period
   */
  u32 tx_bytes;

  /**
   * Interface Name
   */
  char interface_name[16];
} sbp_network_usage_t;

/**
 * Get encoded size of an instance of sbp_network_usage_t
 *
 * @param msg sbp_network_usage_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_network_usage_t(const sbp_network_usage_t *msg);

/**
 * Encode an instance of sbp_network_usage_t to wire representation
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
 * @param msg Instance of sbp_network_usage_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_network_usage_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_network_usage_t *msg);

/**
 * Decode an instance of sbp_network_usage_t from wire representation
 *
 * This function decodes the wire representation of a sbp_network_usage_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_network_usage_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_network_usage_t(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read, sbp_network_usage_t *msg);

/**
 * Compare two instances of sbp_network_usage_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_network_usage_t instance
 * @param b sbp_network_usage_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_network_usage_t(const sbp_network_usage_t *a,
                                const sbp_network_usage_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_NETWORK_BANDWIDTH_USAGE
 *
 *****************************************************************************/
/** Bandwidth usage reporting message
 *
 * The bandwidth usage, a list of usage by interface.
 */
typedef struct {
  /**
   * Usage measurement array
   */
  sbp_network_usage_t interfaces[6];
  /**
   * Number of elements in interfaces
   *
   * When sending a message fill in this field with the number elements set in
   * interfaces before calling an appropriate libsbp send function
   *
   * When receiving a message query this field for the number of elements in
   * interfaces. The value of any elements beyond the index specified in this
   * field is undefined
   */
  u8 n_interfaces;
} sbp_msg_network_bandwidth_usage_t;

/**
 * Get encoded size of an instance of sbp_msg_network_bandwidth_usage_t
 *
 * @param msg sbp_msg_network_bandwidth_usage_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_network_bandwidth_usage_t(
    const sbp_msg_network_bandwidth_usage_t *msg);

/**
 * Encode an instance of sbp_msg_network_bandwidth_usage_t to wire
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
 * @param msg Instance of sbp_msg_network_bandwidth_usage_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_network_bandwidth_usage_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_network_bandwidth_usage_t *msg);

/**
 * Decode an instance of sbp_msg_network_bandwidth_usage_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_network_bandwidth_usage_t message to the given instance. The caller
 * must specify the length of the buffer in the \p len parameter. If non-null
 * the number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_network_bandwidth_usage_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_network_bandwidth_usage_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_network_bandwidth_usage_t *msg);
/**
 * Send an instance of sbp_msg_network_bandwidth_usage_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_network_bandwidth_usage_t
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
s8 sbp_send_sbp_msg_network_bandwidth_usage_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_network_bandwidth_usage_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_network_bandwidth_usage_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_network_bandwidth_usage_t instance
 * @param b sbp_msg_network_bandwidth_usage_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_network_bandwidth_usage_t(
    const sbp_msg_network_bandwidth_usage_t *a,
    const sbp_msg_network_bandwidth_usage_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_CELL_MODEM_STATUS
 *
 *****************************************************************************/
/** Cell modem information update message
 *
 * If a cell modem is present on a piksi device, this message will be send
 * periodically to update the host on the status of the modem and its various
 * parameters.
 */
typedef struct {
  /**
   * Received cell signal strength in dBm, zero translates to unknown [dBm]
   */
  s8 signal_strength;

  /**
   * BER as reported by the modem, zero translates to unknown
   */
  float signal_error_rate;

  /**
   * Unspecified data TBD for this schema
   */
  u8 reserved[250];
  /**
   * Number of elements in reserved
   *
   * When sending a message fill in this field with the number elements set in
   * reserved before calling an appropriate libsbp send function
   *
   * When receiving a message query this field for the number of elements in
   * reserved. The value of any elements beyond the index specified in this
   * field is undefined
   */
  u8 n_reserved;
} sbp_msg_cell_modem_status_t;

/**
 * Get encoded size of an instance of sbp_msg_cell_modem_status_t
 *
 * @param msg sbp_msg_cell_modem_status_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_cell_modem_status_t(
    const sbp_msg_cell_modem_status_t *msg);

/**
 * Encode an instance of sbp_msg_cell_modem_status_t to wire representation
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
 * @param msg Instance of sbp_msg_cell_modem_status_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_cell_modem_status_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_cell_modem_status_t *msg);

/**
 * Decode an instance of sbp_msg_cell_modem_status_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_cell_modem_status_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_cell_modem_status_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_cell_modem_status_t(const uint8_t *buf, uint8_t len,
                                          uint8_t *n_read,
                                          sbp_msg_cell_modem_status_t *msg);
/**
 * Send an instance of sbp_msg_cell_modem_status_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_cell_modem_status_t
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
s8 sbp_send_sbp_msg_cell_modem_status_t(struct sbp_state *s, u16 sender_id,
                                        const sbp_msg_cell_modem_status_t *msg,
                                        s32 (*write)(u8 *buff, u32 n,
                                                     void *context));

/**
 * Compare two instances of sbp_msg_cell_modem_status_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_cell_modem_status_t instance
 * @param b sbp_msg_cell_modem_status_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_cell_modem_status_t(const sbp_msg_cell_modem_status_t *a,
                                        const sbp_msg_cell_modem_status_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_SPECAN_DEP
 *
 *****************************************************************************/
/** Deprecated
 *
 * Deprecated.
 */
typedef struct {
  /**
   * Channel ID
   */
  u16 channel_tag;

  /**
   * Receiver time of this observation
   */
  sbp_gps_time_dep_t t;

  /**
   * Reference frequency of this packet [MHz]
   */
  float freq_ref;

  /**
   * Frequency step of points in this packet [MHz]
   */
  float freq_step;

  /**
   * Reference amplitude of this packet [dB]
   */
  float amplitude_ref;

  /**
   * Amplitude unit value of points in this packet [dB]
   */
  float amplitude_unit;

  /**
   * Amplitude values (in the above units) of points in this packet
   */
  u8 amplitude_value[231];
  /**
   * Number of elements in amplitude_value
   *
   * When sending a message fill in this field with the number elements set in
   * amplitude_value before calling an appropriate libsbp send function
   *
   * When receiving a message query this field for the number of elements in
   * amplitude_value. The value of any elements beyond the index specified in
   * this field is undefined
   */
  u8 n_amplitude_value;
} sbp_msg_specan_dep_t;

/**
 * Get encoded size of an instance of sbp_msg_specan_dep_t
 *
 * @param msg sbp_msg_specan_dep_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_specan_dep_t(const sbp_msg_specan_dep_t *msg);

/**
 * Encode an instance of sbp_msg_specan_dep_t to wire representation
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
 * @param msg Instance of sbp_msg_specan_dep_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_specan_dep_t(uint8_t *buf, uint8_t len,
                                   uint8_t *n_written,
                                   const sbp_msg_specan_dep_t *msg);

/**
 * Decode an instance of sbp_msg_specan_dep_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_specan_dep_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_specan_dep_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_specan_dep_t(const uint8_t *buf, uint8_t len,
                                   uint8_t *n_read, sbp_msg_specan_dep_t *msg);
/**
 * Send an instance of sbp_msg_specan_dep_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_specan_dep_t
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
s8 sbp_send_sbp_msg_specan_dep_t(struct sbp_state *s, u16 sender_id,
                                 const sbp_msg_specan_dep_t *msg,
                                 s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_specan_dep_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_specan_dep_t instance
 * @param b sbp_msg_specan_dep_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_specan_dep_t(const sbp_msg_specan_dep_t *a,
                                 const sbp_msg_specan_dep_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_SPECAN
 *
 *****************************************************************************/
/** Spectrum analyzer
 *
 * Spectrum analyzer packet.
 */
typedef struct {
  /**
   * Channel ID
   */
  u16 channel_tag;

  /**
   * Receiver time of this observation
   */
  sbp_sbp_gps_time_t t;

  /**
   * Reference frequency of this packet [MHz]
   */
  float freq_ref;

  /**
   * Frequency step of points in this packet [MHz]
   */
  float freq_step;

  /**
   * Reference amplitude of this packet [dB]
   */
  float amplitude_ref;

  /**
   * Amplitude unit value of points in this packet [dB]
   */
  float amplitude_unit;

  /**
   * Amplitude values (in the above units) of points in this packet
   */
  u8 amplitude_value[227];
  /**
   * Number of elements in amplitude_value
   *
   * When sending a message fill in this field with the number elements set in
   * amplitude_value before calling an appropriate libsbp send function
   *
   * When receiving a message query this field for the number of elements in
   * amplitude_value. The value of any elements beyond the index specified in
   * this field is undefined
   */
  u8 n_amplitude_value;
} sbp_msg_specan_t;

/**
 * Get encoded size of an instance of sbp_msg_specan_t
 *
 * @param msg sbp_msg_specan_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_specan_t(const sbp_msg_specan_t *msg);

/**
 * Encode an instance of sbp_msg_specan_t to wire representation
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
 * @param msg Instance of sbp_msg_specan_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_specan_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                               const sbp_msg_specan_t *msg);

/**
 * Decode an instance of sbp_msg_specan_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_specan_t message
 * to the given instance. The caller must specify the length of the buffer in
 * the \p len parameter. If non-null the number of bytes read from the buffer
 * will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_specan_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_specan_t(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                               sbp_msg_specan_t *msg);
/**
 * Send an instance of sbp_msg_specan_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_specan_t
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
s8 sbp_send_sbp_msg_specan_t(struct sbp_state *s, u16 sender_id,
                             const sbp_msg_specan_t *msg,
                             s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_specan_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_specan_t instance
 * @param b sbp_msg_specan_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_specan_t(const sbp_msg_specan_t *a,
                             const sbp_msg_specan_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_FRONT_END_GAIN
 *
 *****************************************************************************/
/** RF AGC status
 *
 * This message describes the gain of each channel in the receiver frontend.
 * Each gain is encoded as a non-dimensional percentage relative to the maximum
 * range possible for the gain stage of the frontend. By convention, each gain
 * array has 8 entries and the index of the array corresponding to the index of
 * the rf channel in the frontend. A gain of 127 percent encodes that rf channel
 * is not present in the hardware. A negative value implies an error for the
 * particular gain stage as reported by the frontend.
 */
typedef struct {
  /**
   * RF gain for each frontend channel [percent]
   */
  s8 rf_gain[8];

  /**
   * Intermediate frequency gain for each frontend channel [percent]
   */
  s8 if_gain[8];
} sbp_msg_front_end_gain_t;

/**
 * Get encoded size of an instance of sbp_msg_front_end_gain_t
 *
 * @param msg sbp_msg_front_end_gain_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_front_end_gain_t(
    const sbp_msg_front_end_gain_t *msg);

/**
 * Encode an instance of sbp_msg_front_end_gain_t to wire representation
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
 * @param msg Instance of sbp_msg_front_end_gain_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_front_end_gain_t(uint8_t *buf, uint8_t len,
                                       uint8_t *n_written,
                                       const sbp_msg_front_end_gain_t *msg);

/**
 * Decode an instance of sbp_msg_front_end_gain_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_front_end_gain_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_front_end_gain_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_front_end_gain_t(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_msg_front_end_gain_t *msg);
/**
 * Send an instance of sbp_msg_front_end_gain_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_front_end_gain_t
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
s8 sbp_send_sbp_msg_front_end_gain_t(struct sbp_state *s, u16 sender_id,
                                     const sbp_msg_front_end_gain_t *msg,
                                     s32 (*write)(u8 *buff, u32 n,
                                                  void *context));

/**
 * Compare two instances of sbp_msg_front_end_gain_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_front_end_gain_t instance
 * @param b sbp_msg_front_end_gain_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_front_end_gain_t(const sbp_msg_front_end_gain_t *a,
                                     const sbp_msg_front_end_gain_t *b);

#ifdef __cplusplus
}
static inline bool operator==(const sbp_msg_almanac_t &lhs,
                              const sbp_msg_almanac_t &rhs) {
  return sbp_cmp_sbp_msg_almanac_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_almanac_t &lhs,
                              const sbp_msg_almanac_t &rhs) {
  return sbp_cmp_sbp_msg_almanac_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_almanac_t &lhs,
                             const sbp_msg_almanac_t &rhs) {
  return sbp_cmp_sbp_msg_almanac_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_almanac_t &lhs,
                              const sbp_msg_almanac_t &rhs) {
  return sbp_cmp_sbp_msg_almanac_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_almanac_t &lhs,
                             const sbp_msg_almanac_t &rhs) {
  return sbp_cmp_sbp_msg_almanac_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_almanac_t &lhs,
                              const sbp_msg_almanac_t &rhs) {
  return sbp_cmp_sbp_msg_almanac_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_set_time_t &lhs,
                              const sbp_msg_set_time_t &rhs) {
  return sbp_cmp_sbp_msg_set_time_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_set_time_t &lhs,
                              const sbp_msg_set_time_t &rhs) {
  return sbp_cmp_sbp_msg_set_time_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_set_time_t &lhs,
                             const sbp_msg_set_time_t &rhs) {
  return sbp_cmp_sbp_msg_set_time_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_set_time_t &lhs,
                              const sbp_msg_set_time_t &rhs) {
  return sbp_cmp_sbp_msg_set_time_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_set_time_t &lhs,
                             const sbp_msg_set_time_t &rhs) {
  return sbp_cmp_sbp_msg_set_time_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_set_time_t &lhs,
                              const sbp_msg_set_time_t &rhs) {
  return sbp_cmp_sbp_msg_set_time_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_reset_t &lhs,
                              const sbp_msg_reset_t &rhs) {
  return sbp_cmp_sbp_msg_reset_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_reset_t &lhs,
                              const sbp_msg_reset_t &rhs) {
  return sbp_cmp_sbp_msg_reset_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_reset_t &lhs,
                             const sbp_msg_reset_t &rhs) {
  return sbp_cmp_sbp_msg_reset_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_reset_t &lhs,
                              const sbp_msg_reset_t &rhs) {
  return sbp_cmp_sbp_msg_reset_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_reset_t &lhs,
                             const sbp_msg_reset_t &rhs) {
  return sbp_cmp_sbp_msg_reset_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_reset_t &lhs,
                              const sbp_msg_reset_t &rhs) {
  return sbp_cmp_sbp_msg_reset_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_reset_dep_t &lhs,
                              const sbp_msg_reset_dep_t &rhs) {
  return sbp_cmp_sbp_msg_reset_dep_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_reset_dep_t &lhs,
                              const sbp_msg_reset_dep_t &rhs) {
  return sbp_cmp_sbp_msg_reset_dep_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_reset_dep_t &lhs,
                             const sbp_msg_reset_dep_t &rhs) {
  return sbp_cmp_sbp_msg_reset_dep_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_reset_dep_t &lhs,
                              const sbp_msg_reset_dep_t &rhs) {
  return sbp_cmp_sbp_msg_reset_dep_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_reset_dep_t &lhs,
                             const sbp_msg_reset_dep_t &rhs) {
  return sbp_cmp_sbp_msg_reset_dep_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_reset_dep_t &lhs,
                              const sbp_msg_reset_dep_t &rhs) {
  return sbp_cmp_sbp_msg_reset_dep_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_cw_results_t &lhs,
                              const sbp_msg_cw_results_t &rhs) {
  return sbp_cmp_sbp_msg_cw_results_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_cw_results_t &lhs,
                              const sbp_msg_cw_results_t &rhs) {
  return sbp_cmp_sbp_msg_cw_results_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_cw_results_t &lhs,
                             const sbp_msg_cw_results_t &rhs) {
  return sbp_cmp_sbp_msg_cw_results_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_cw_results_t &lhs,
                              const sbp_msg_cw_results_t &rhs) {
  return sbp_cmp_sbp_msg_cw_results_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_cw_results_t &lhs,
                             const sbp_msg_cw_results_t &rhs) {
  return sbp_cmp_sbp_msg_cw_results_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_cw_results_t &lhs,
                              const sbp_msg_cw_results_t &rhs) {
  return sbp_cmp_sbp_msg_cw_results_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_cw_start_t &lhs,
                              const sbp_msg_cw_start_t &rhs) {
  return sbp_cmp_sbp_msg_cw_start_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_cw_start_t &lhs,
                              const sbp_msg_cw_start_t &rhs) {
  return sbp_cmp_sbp_msg_cw_start_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_cw_start_t &lhs,
                             const sbp_msg_cw_start_t &rhs) {
  return sbp_cmp_sbp_msg_cw_start_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_cw_start_t &lhs,
                              const sbp_msg_cw_start_t &rhs) {
  return sbp_cmp_sbp_msg_cw_start_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_cw_start_t &lhs,
                             const sbp_msg_cw_start_t &rhs) {
  return sbp_cmp_sbp_msg_cw_start_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_cw_start_t &lhs,
                              const sbp_msg_cw_start_t &rhs) {
  return sbp_cmp_sbp_msg_cw_start_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_reset_filters_t &lhs,
                              const sbp_msg_reset_filters_t &rhs) {
  return sbp_cmp_sbp_msg_reset_filters_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_reset_filters_t &lhs,
                              const sbp_msg_reset_filters_t &rhs) {
  return sbp_cmp_sbp_msg_reset_filters_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_reset_filters_t &lhs,
                             const sbp_msg_reset_filters_t &rhs) {
  return sbp_cmp_sbp_msg_reset_filters_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_reset_filters_t &lhs,
                              const sbp_msg_reset_filters_t &rhs) {
  return sbp_cmp_sbp_msg_reset_filters_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_reset_filters_t &lhs,
                             const sbp_msg_reset_filters_t &rhs) {
  return sbp_cmp_sbp_msg_reset_filters_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_reset_filters_t &lhs,
                              const sbp_msg_reset_filters_t &rhs) {
  return sbp_cmp_sbp_msg_reset_filters_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_init_base_dep_t &lhs,
                              const sbp_msg_init_base_dep_t &rhs) {
  return sbp_cmp_sbp_msg_init_base_dep_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_init_base_dep_t &lhs,
                              const sbp_msg_init_base_dep_t &rhs) {
  return sbp_cmp_sbp_msg_init_base_dep_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_init_base_dep_t &lhs,
                             const sbp_msg_init_base_dep_t &rhs) {
  return sbp_cmp_sbp_msg_init_base_dep_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_init_base_dep_t &lhs,
                              const sbp_msg_init_base_dep_t &rhs) {
  return sbp_cmp_sbp_msg_init_base_dep_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_init_base_dep_t &lhs,
                             const sbp_msg_init_base_dep_t &rhs) {
  return sbp_cmp_sbp_msg_init_base_dep_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_init_base_dep_t &lhs,
                              const sbp_msg_init_base_dep_t &rhs) {
  return sbp_cmp_sbp_msg_init_base_dep_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_thread_state_t &lhs,
                              const sbp_msg_thread_state_t &rhs) {
  return sbp_cmp_sbp_msg_thread_state_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_thread_state_t &lhs,
                              const sbp_msg_thread_state_t &rhs) {
  return sbp_cmp_sbp_msg_thread_state_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_thread_state_t &lhs,
                             const sbp_msg_thread_state_t &rhs) {
  return sbp_cmp_sbp_msg_thread_state_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_thread_state_t &lhs,
                              const sbp_msg_thread_state_t &rhs) {
  return sbp_cmp_sbp_msg_thread_state_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_thread_state_t &lhs,
                             const sbp_msg_thread_state_t &rhs) {
  return sbp_cmp_sbp_msg_thread_state_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_thread_state_t &lhs,
                              const sbp_msg_thread_state_t &rhs) {
  return sbp_cmp_sbp_msg_thread_state_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_uart_channel_t &lhs,
                              const sbp_uart_channel_t &rhs) {
  return sbp_cmp_sbp_uart_channel_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_uart_channel_t &lhs,
                              const sbp_uart_channel_t &rhs) {
  return sbp_cmp_sbp_uart_channel_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_uart_channel_t &lhs,
                             const sbp_uart_channel_t &rhs) {
  return sbp_cmp_sbp_uart_channel_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_uart_channel_t &lhs,
                              const sbp_uart_channel_t &rhs) {
  return sbp_cmp_sbp_uart_channel_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_uart_channel_t &lhs,
                             const sbp_uart_channel_t &rhs) {
  return sbp_cmp_sbp_uart_channel_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_uart_channel_t &lhs,
                              const sbp_uart_channel_t &rhs) {
  return sbp_cmp_sbp_uart_channel_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_period_t &lhs,
                              const sbp_period_t &rhs) {
  return sbp_cmp_sbp_period_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_period_t &lhs,
                              const sbp_period_t &rhs) {
  return sbp_cmp_sbp_period_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_period_t &lhs, const sbp_period_t &rhs) {
  return sbp_cmp_sbp_period_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_period_t &lhs,
                              const sbp_period_t &rhs) {
  return sbp_cmp_sbp_period_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_period_t &lhs, const sbp_period_t &rhs) {
  return sbp_cmp_sbp_period_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_period_t &lhs,
                              const sbp_period_t &rhs) {
  return sbp_cmp_sbp_period_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_latency_t &lhs,
                              const sbp_latency_t &rhs) {
  return sbp_cmp_sbp_latency_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_latency_t &lhs,
                              const sbp_latency_t &rhs) {
  return sbp_cmp_sbp_latency_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_latency_t &lhs,
                             const sbp_latency_t &rhs) {
  return sbp_cmp_sbp_latency_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_latency_t &lhs,
                              const sbp_latency_t &rhs) {
  return sbp_cmp_sbp_latency_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_latency_t &lhs,
                             const sbp_latency_t &rhs) {
  return sbp_cmp_sbp_latency_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_latency_t &lhs,
                              const sbp_latency_t &rhs) {
  return sbp_cmp_sbp_latency_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_uart_state_t &lhs,
                              const sbp_msg_uart_state_t &rhs) {
  return sbp_cmp_sbp_msg_uart_state_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_uart_state_t &lhs,
                              const sbp_msg_uart_state_t &rhs) {
  return sbp_cmp_sbp_msg_uart_state_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_uart_state_t &lhs,
                             const sbp_msg_uart_state_t &rhs) {
  return sbp_cmp_sbp_msg_uart_state_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_uart_state_t &lhs,
                              const sbp_msg_uart_state_t &rhs) {
  return sbp_cmp_sbp_msg_uart_state_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_uart_state_t &lhs,
                             const sbp_msg_uart_state_t &rhs) {
  return sbp_cmp_sbp_msg_uart_state_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_uart_state_t &lhs,
                              const sbp_msg_uart_state_t &rhs) {
  return sbp_cmp_sbp_msg_uart_state_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_uart_state_depa_t &lhs,
                              const sbp_msg_uart_state_depa_t &rhs) {
  return sbp_cmp_sbp_msg_uart_state_depa_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_uart_state_depa_t &lhs,
                              const sbp_msg_uart_state_depa_t &rhs) {
  return sbp_cmp_sbp_msg_uart_state_depa_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_uart_state_depa_t &lhs,
                             const sbp_msg_uart_state_depa_t &rhs) {
  return sbp_cmp_sbp_msg_uart_state_depa_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_uart_state_depa_t &lhs,
                              const sbp_msg_uart_state_depa_t &rhs) {
  return sbp_cmp_sbp_msg_uart_state_depa_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_uart_state_depa_t &lhs,
                             const sbp_msg_uart_state_depa_t &rhs) {
  return sbp_cmp_sbp_msg_uart_state_depa_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_uart_state_depa_t &lhs,
                              const sbp_msg_uart_state_depa_t &rhs) {
  return sbp_cmp_sbp_msg_uart_state_depa_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_iar_state_t &lhs,
                              const sbp_msg_iar_state_t &rhs) {
  return sbp_cmp_sbp_msg_iar_state_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_iar_state_t &lhs,
                              const sbp_msg_iar_state_t &rhs) {
  return sbp_cmp_sbp_msg_iar_state_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_iar_state_t &lhs,
                             const sbp_msg_iar_state_t &rhs) {
  return sbp_cmp_sbp_msg_iar_state_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_iar_state_t &lhs,
                              const sbp_msg_iar_state_t &rhs) {
  return sbp_cmp_sbp_msg_iar_state_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_iar_state_t &lhs,
                             const sbp_msg_iar_state_t &rhs) {
  return sbp_cmp_sbp_msg_iar_state_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_iar_state_t &lhs,
                              const sbp_msg_iar_state_t &rhs) {
  return sbp_cmp_sbp_msg_iar_state_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_mask_satellite_t &lhs,
                              const sbp_msg_mask_satellite_t &rhs) {
  return sbp_cmp_sbp_msg_mask_satellite_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_mask_satellite_t &lhs,
                              const sbp_msg_mask_satellite_t &rhs) {
  return sbp_cmp_sbp_msg_mask_satellite_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_mask_satellite_t &lhs,
                             const sbp_msg_mask_satellite_t &rhs) {
  return sbp_cmp_sbp_msg_mask_satellite_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_mask_satellite_t &lhs,
                              const sbp_msg_mask_satellite_t &rhs) {
  return sbp_cmp_sbp_msg_mask_satellite_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_mask_satellite_t &lhs,
                             const sbp_msg_mask_satellite_t &rhs) {
  return sbp_cmp_sbp_msg_mask_satellite_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_mask_satellite_t &lhs,
                              const sbp_msg_mask_satellite_t &rhs) {
  return sbp_cmp_sbp_msg_mask_satellite_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_mask_satellite_dep_t &lhs,
                              const sbp_msg_mask_satellite_dep_t &rhs) {
  return sbp_cmp_sbp_msg_mask_satellite_dep_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_mask_satellite_dep_t &lhs,
                              const sbp_msg_mask_satellite_dep_t &rhs) {
  return sbp_cmp_sbp_msg_mask_satellite_dep_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_mask_satellite_dep_t &lhs,
                             const sbp_msg_mask_satellite_dep_t &rhs) {
  return sbp_cmp_sbp_msg_mask_satellite_dep_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_mask_satellite_dep_t &lhs,
                              const sbp_msg_mask_satellite_dep_t &rhs) {
  return sbp_cmp_sbp_msg_mask_satellite_dep_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_mask_satellite_dep_t &lhs,
                             const sbp_msg_mask_satellite_dep_t &rhs) {
  return sbp_cmp_sbp_msg_mask_satellite_dep_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_mask_satellite_dep_t &lhs,
                              const sbp_msg_mask_satellite_dep_t &rhs) {
  return sbp_cmp_sbp_msg_mask_satellite_dep_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_device_monitor_t &lhs,
                              const sbp_msg_device_monitor_t &rhs) {
  return sbp_cmp_sbp_msg_device_monitor_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_device_monitor_t &lhs,
                              const sbp_msg_device_monitor_t &rhs) {
  return sbp_cmp_sbp_msg_device_monitor_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_device_monitor_t &lhs,
                             const sbp_msg_device_monitor_t &rhs) {
  return sbp_cmp_sbp_msg_device_monitor_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_device_monitor_t &lhs,
                              const sbp_msg_device_monitor_t &rhs) {
  return sbp_cmp_sbp_msg_device_monitor_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_device_monitor_t &lhs,
                             const sbp_msg_device_monitor_t &rhs) {
  return sbp_cmp_sbp_msg_device_monitor_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_device_monitor_t &lhs,
                              const sbp_msg_device_monitor_t &rhs) {
  return sbp_cmp_sbp_msg_device_monitor_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_command_req_t &lhs,
                              const sbp_msg_command_req_t &rhs) {
  return sbp_cmp_sbp_msg_command_req_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_command_req_t &lhs,
                              const sbp_msg_command_req_t &rhs) {
  return sbp_cmp_sbp_msg_command_req_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_command_req_t &lhs,
                             const sbp_msg_command_req_t &rhs) {
  return sbp_cmp_sbp_msg_command_req_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_command_req_t &lhs,
                              const sbp_msg_command_req_t &rhs) {
  return sbp_cmp_sbp_msg_command_req_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_command_req_t &lhs,
                             const sbp_msg_command_req_t &rhs) {
  return sbp_cmp_sbp_msg_command_req_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_command_req_t &lhs,
                              const sbp_msg_command_req_t &rhs) {
  return sbp_cmp_sbp_msg_command_req_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_command_resp_t &lhs,
                              const sbp_msg_command_resp_t &rhs) {
  return sbp_cmp_sbp_msg_command_resp_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_command_resp_t &lhs,
                              const sbp_msg_command_resp_t &rhs) {
  return sbp_cmp_sbp_msg_command_resp_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_command_resp_t &lhs,
                             const sbp_msg_command_resp_t &rhs) {
  return sbp_cmp_sbp_msg_command_resp_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_command_resp_t &lhs,
                              const sbp_msg_command_resp_t &rhs) {
  return sbp_cmp_sbp_msg_command_resp_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_command_resp_t &lhs,
                             const sbp_msg_command_resp_t &rhs) {
  return sbp_cmp_sbp_msg_command_resp_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_command_resp_t &lhs,
                              const sbp_msg_command_resp_t &rhs) {
  return sbp_cmp_sbp_msg_command_resp_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_command_output_t &lhs,
                              const sbp_msg_command_output_t &rhs) {
  return sbp_cmp_sbp_msg_command_output_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_command_output_t &lhs,
                              const sbp_msg_command_output_t &rhs) {
  return sbp_cmp_sbp_msg_command_output_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_command_output_t &lhs,
                             const sbp_msg_command_output_t &rhs) {
  return sbp_cmp_sbp_msg_command_output_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_command_output_t &lhs,
                              const sbp_msg_command_output_t &rhs) {
  return sbp_cmp_sbp_msg_command_output_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_command_output_t &lhs,
                             const sbp_msg_command_output_t &rhs) {
  return sbp_cmp_sbp_msg_command_output_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_command_output_t &lhs,
                              const sbp_msg_command_output_t &rhs) {
  return sbp_cmp_sbp_msg_command_output_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_network_state_req_t &lhs,
                              const sbp_msg_network_state_req_t &rhs) {
  return sbp_cmp_sbp_msg_network_state_req_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_network_state_req_t &lhs,
                              const sbp_msg_network_state_req_t &rhs) {
  return sbp_cmp_sbp_msg_network_state_req_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_network_state_req_t &lhs,
                             const sbp_msg_network_state_req_t &rhs) {
  return sbp_cmp_sbp_msg_network_state_req_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_network_state_req_t &lhs,
                              const sbp_msg_network_state_req_t &rhs) {
  return sbp_cmp_sbp_msg_network_state_req_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_network_state_req_t &lhs,
                             const sbp_msg_network_state_req_t &rhs) {
  return sbp_cmp_sbp_msg_network_state_req_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_network_state_req_t &lhs,
                              const sbp_msg_network_state_req_t &rhs) {
  return sbp_cmp_sbp_msg_network_state_req_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_network_state_resp_t &lhs,
                              const sbp_msg_network_state_resp_t &rhs) {
  return sbp_cmp_sbp_msg_network_state_resp_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_network_state_resp_t &lhs,
                              const sbp_msg_network_state_resp_t &rhs) {
  return sbp_cmp_sbp_msg_network_state_resp_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_network_state_resp_t &lhs,
                             const sbp_msg_network_state_resp_t &rhs) {
  return sbp_cmp_sbp_msg_network_state_resp_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_network_state_resp_t &lhs,
                              const sbp_msg_network_state_resp_t &rhs) {
  return sbp_cmp_sbp_msg_network_state_resp_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_network_state_resp_t &lhs,
                             const sbp_msg_network_state_resp_t &rhs) {
  return sbp_cmp_sbp_msg_network_state_resp_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_network_state_resp_t &lhs,
                              const sbp_msg_network_state_resp_t &rhs) {
  return sbp_cmp_sbp_msg_network_state_resp_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_network_usage_t &lhs,
                              const sbp_network_usage_t &rhs) {
  return sbp_cmp_sbp_network_usage_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_network_usage_t &lhs,
                              const sbp_network_usage_t &rhs) {
  return sbp_cmp_sbp_network_usage_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_network_usage_t &lhs,
                             const sbp_network_usage_t &rhs) {
  return sbp_cmp_sbp_network_usage_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_network_usage_t &lhs,
                              const sbp_network_usage_t &rhs) {
  return sbp_cmp_sbp_network_usage_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_network_usage_t &lhs,
                             const sbp_network_usage_t &rhs) {
  return sbp_cmp_sbp_network_usage_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_network_usage_t &lhs,
                              const sbp_network_usage_t &rhs) {
  return sbp_cmp_sbp_network_usage_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_network_bandwidth_usage_t &lhs,
                              const sbp_msg_network_bandwidth_usage_t &rhs) {
  return sbp_cmp_sbp_msg_network_bandwidth_usage_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_network_bandwidth_usage_t &lhs,
                              const sbp_msg_network_bandwidth_usage_t &rhs) {
  return sbp_cmp_sbp_msg_network_bandwidth_usage_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_network_bandwidth_usage_t &lhs,
                             const sbp_msg_network_bandwidth_usage_t &rhs) {
  return sbp_cmp_sbp_msg_network_bandwidth_usage_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_network_bandwidth_usage_t &lhs,
                              const sbp_msg_network_bandwidth_usage_t &rhs) {
  return sbp_cmp_sbp_msg_network_bandwidth_usage_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_network_bandwidth_usage_t &lhs,
                             const sbp_msg_network_bandwidth_usage_t &rhs) {
  return sbp_cmp_sbp_msg_network_bandwidth_usage_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_network_bandwidth_usage_t &lhs,
                              const sbp_msg_network_bandwidth_usage_t &rhs) {
  return sbp_cmp_sbp_msg_network_bandwidth_usage_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_cell_modem_status_t &lhs,
                              const sbp_msg_cell_modem_status_t &rhs) {
  return sbp_cmp_sbp_msg_cell_modem_status_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_cell_modem_status_t &lhs,
                              const sbp_msg_cell_modem_status_t &rhs) {
  return sbp_cmp_sbp_msg_cell_modem_status_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_cell_modem_status_t &lhs,
                             const sbp_msg_cell_modem_status_t &rhs) {
  return sbp_cmp_sbp_msg_cell_modem_status_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_cell_modem_status_t &lhs,
                              const sbp_msg_cell_modem_status_t &rhs) {
  return sbp_cmp_sbp_msg_cell_modem_status_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_cell_modem_status_t &lhs,
                             const sbp_msg_cell_modem_status_t &rhs) {
  return sbp_cmp_sbp_msg_cell_modem_status_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_cell_modem_status_t &lhs,
                              const sbp_msg_cell_modem_status_t &rhs) {
  return sbp_cmp_sbp_msg_cell_modem_status_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_specan_dep_t &lhs,
                              const sbp_msg_specan_dep_t &rhs) {
  return sbp_cmp_sbp_msg_specan_dep_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_specan_dep_t &lhs,
                              const sbp_msg_specan_dep_t &rhs) {
  return sbp_cmp_sbp_msg_specan_dep_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_specan_dep_t &lhs,
                             const sbp_msg_specan_dep_t &rhs) {
  return sbp_cmp_sbp_msg_specan_dep_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_specan_dep_t &lhs,
                              const sbp_msg_specan_dep_t &rhs) {
  return sbp_cmp_sbp_msg_specan_dep_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_specan_dep_t &lhs,
                             const sbp_msg_specan_dep_t &rhs) {
  return sbp_cmp_sbp_msg_specan_dep_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_specan_dep_t &lhs,
                              const sbp_msg_specan_dep_t &rhs) {
  return sbp_cmp_sbp_msg_specan_dep_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_specan_t &lhs,
                              const sbp_msg_specan_t &rhs) {
  return sbp_cmp_sbp_msg_specan_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_specan_t &lhs,
                              const sbp_msg_specan_t &rhs) {
  return sbp_cmp_sbp_msg_specan_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_specan_t &lhs,
                             const sbp_msg_specan_t &rhs) {
  return sbp_cmp_sbp_msg_specan_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_specan_t &lhs,
                              const sbp_msg_specan_t &rhs) {
  return sbp_cmp_sbp_msg_specan_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_specan_t &lhs,
                             const sbp_msg_specan_t &rhs) {
  return sbp_cmp_sbp_msg_specan_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_specan_t &lhs,
                              const sbp_msg_specan_t &rhs) {
  return sbp_cmp_sbp_msg_specan_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_front_end_gain_t &lhs,
                              const sbp_msg_front_end_gain_t &rhs) {
  return sbp_cmp_sbp_msg_front_end_gain_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_front_end_gain_t &lhs,
                              const sbp_msg_front_end_gain_t &rhs) {
  return sbp_cmp_sbp_msg_front_end_gain_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_front_end_gain_t &lhs,
                             const sbp_msg_front_end_gain_t &rhs) {
  return sbp_cmp_sbp_msg_front_end_gain_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_front_end_gain_t &lhs,
                              const sbp_msg_front_end_gain_t &rhs) {
  return sbp_cmp_sbp_msg_front_end_gain_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_front_end_gain_t &lhs,
                             const sbp_msg_front_end_gain_t &rhs) {
  return sbp_cmp_sbp_msg_front_end_gain_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_front_end_gain_t &lhs,
                              const sbp_msg_front_end_gain_t &rhs) {
  return sbp_cmp_sbp_msg_front_end_gain_t(&lhs, &rhs) >= 0;
}

#endif

#endif /* LIBSBP_NEW_PIKSI_MESSAGES_H */
