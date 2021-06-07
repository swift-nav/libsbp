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
 * Automatically generated from yaml/swiftnav/sbp/bootload.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_NEW_BOOTLOAD_MESSAGES_H
#define LIBSBP_NEW_BOOTLOAD_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/bootload_macros.h>
#include <libsbp/common.h>
#include <libsbp/new/string/double_null_terminated.h>
#include <libsbp/new/string/multipart.h>
#include <libsbp/new/string/null_terminated.h>
#include <libsbp/new/string/unterminated.h>

#ifdef __cplusplus
extern "C" {
#endif

struct sbp_state;

/** Bootloading handshake request (host => device)
 *
 * The handshake message request from the host establishes a handshake between
 * the device bootloader and the host. The response from the device is
 * MSG_BOOTLOADER_HANDSHAKE_RESP.
 */
typedef struct {
  /**
   * Do not use this field, it exists only to prevent illegal C syntax. Any
   * value written to this field will be ignored
   */
  char DO_NOT_USE_dummy_field_to_prevent_empty_struct;
} sbp_msg_bootloader_handshake_req_t;

/**
 * Get encoded size of an instance of sbp_msg_bootloader_handshake_req_t
 *
 * @param msg sbp_msg_bootloader_handshake_req_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_bootloader_handshake_req_t(
    const sbp_msg_bootloader_handshake_req_t *msg);

/**
 * Encode an instance of sbp_msg_bootloader_handshake_req_t to wire
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
 * @param msg Instance of sbp_msg_bootloader_handshake_req_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_bootloader_handshake_req_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_bootloader_handshake_req_t *msg);

/**
 * Decode an instance of sbp_msg_bootloader_handshake_req_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_bootloader_handshake_req_t message to the given instance. The caller
 * must specify the length of the buffer in the \p len parameter. If non-null
 * the number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_bootloader_handshake_req_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_bootloader_handshake_req_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_bootloader_handshake_req_t *msg);
/**
 * Send an instance of sbp_msg_bootloader_handshake_req_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_bootloader_handshake_req_t
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
s8 sbp_send_sbp_msg_bootloader_handshake_req_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_bootloader_handshake_req_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_bootloader_handshake_req_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_bootloader_handshake_req_t instance
 * @param b sbp_msg_bootloader_handshake_req_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_bootloader_handshake_req_t(
    const sbp_msg_bootloader_handshake_req_t *a,
    const sbp_msg_bootloader_handshake_req_t *b);

/** Bootloading handshake response (host <= device)
 *
 * The handshake message response from the device establishes a handshake
 * between the device bootloader and the host. The request from the host is
 * MSG_BOOTLOADER_HANDSHAKE_REQ.  The payload contains the bootloader version
 * number and the SBP protocol version number.
 */
typedef struct {
  /**
   * Bootloader flags
   */
  u32 flags;

  /**
   * Bootloader version number
   */
  sbp_unterminated_string_t version;
} sbp_msg_bootloader_handshake_resp_t;
void sbp_msg_bootloader_handshake_resp_t_version_init(
    sbp_unterminated_string_t *s);
bool sbp_msg_bootloader_handshake_resp_t_version_valid(
    const sbp_unterminated_string_t *s);
int sbp_msg_bootloader_handshake_resp_t_version_strcmp(
    const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b);
uint8_t sbp_msg_bootloader_handshake_resp_t_version_packed_len(
    const sbp_unterminated_string_t *s);
uint8_t sbp_msg_bootloader_handshake_resp_t_version_space_remaining(
    const sbp_unterminated_string_t *s);
bool sbp_msg_bootloader_handshake_resp_t_version_set(
    sbp_unterminated_string_t *s, const char *new_str);
bool sbp_msg_bootloader_handshake_resp_t_version_printf(
    sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_bootloader_handshake_resp_t_version_vprintf(
    sbp_unterminated_string_t *s, const char *fmt, va_list ap);
bool sbp_msg_bootloader_handshake_resp_t_version_append_printf(
    sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_bootloader_handshake_resp_t_version_append_vprintf(
    sbp_unterminated_string_t *s, const char *fmt, va_list ap);
const char *sbp_msg_bootloader_handshake_resp_t_version_get(
    const sbp_unterminated_string_t *s);

/**
 * Get encoded size of an instance of sbp_msg_bootloader_handshake_resp_t
 *
 * @param msg sbp_msg_bootloader_handshake_resp_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_bootloader_handshake_resp_t(
    const sbp_msg_bootloader_handshake_resp_t *msg);

/**
 * Encode an instance of sbp_msg_bootloader_handshake_resp_t to wire
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
 * @param msg Instance of sbp_msg_bootloader_handshake_resp_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_bootloader_handshake_resp_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_bootloader_handshake_resp_t *msg);

/**
 * Decode an instance of sbp_msg_bootloader_handshake_resp_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_bootloader_handshake_resp_t message to the given instance. The caller
 * must specify the length of the buffer in the \p len parameter. If non-null
 * the number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_bootloader_handshake_resp_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_bootloader_handshake_resp_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_bootloader_handshake_resp_t *msg);
/**
 * Send an instance of sbp_msg_bootloader_handshake_resp_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_bootloader_handshake_resp_t
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
s8 sbp_send_sbp_msg_bootloader_handshake_resp_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_bootloader_handshake_resp_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_bootloader_handshake_resp_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_bootloader_handshake_resp_t instance
 * @param b sbp_msg_bootloader_handshake_resp_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_bootloader_handshake_resp_t(
    const sbp_msg_bootloader_handshake_resp_t *a,
    const sbp_msg_bootloader_handshake_resp_t *b);

/** Bootloader jump to application (host => device)
 *
 * The host initiates the bootloader to jump to the application.
 */
typedef struct {
  /**
   * Ignored by the device
   */
  u8 jump;
} sbp_msg_bootloader_jump_to_app_t;

/**
 * Get encoded size of an instance of sbp_msg_bootloader_jump_to_app_t
 *
 * @param msg sbp_msg_bootloader_jump_to_app_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_bootloader_jump_to_app_t(
    const sbp_msg_bootloader_jump_to_app_t *msg);

/**
 * Encode an instance of sbp_msg_bootloader_jump_to_app_t to wire representation
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
 * @param msg Instance of sbp_msg_bootloader_jump_to_app_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_bootloader_jump_to_app_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_bootloader_jump_to_app_t *msg);

/**
 * Decode an instance of sbp_msg_bootloader_jump_to_app_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_bootloader_jump_to_app_t message to the given instance. The caller
 * must specify the length of the buffer in the \p len parameter. If non-null
 * the number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_bootloader_jump_to_app_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_bootloader_jump_to_app_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_bootloader_jump_to_app_t *msg);
/**
 * Send an instance of sbp_msg_bootloader_jump_to_app_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_bootloader_jump_to_app_t
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
s8 sbp_send_sbp_msg_bootloader_jump_to_app_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_bootloader_jump_to_app_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_bootloader_jump_to_app_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_bootloader_jump_to_app_t instance
 * @param b sbp_msg_bootloader_jump_to_app_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_bootloader_jump_to_app_t(
    const sbp_msg_bootloader_jump_to_app_t *a,
    const sbp_msg_bootloader_jump_to_app_t *b);

/** Read FPGA device ID over UART request (host => device)
 *
 * The device message from the host reads a unique device identifier from the
 * SwiftNAP, an FPGA. The host requests the ID by sending a
 * MSG_NAP_DEVICE_DNA_REQ message. The device responds with a
 * MSG_NAP_DEVICE_DNA_RESP message with the device ID in the payload. Note that
 * this ID is tied to the FPGA, and not related to the Piksi's serial number.
 */
typedef struct {
  /**
   * Do not use this field, it exists only to prevent illegal C syntax. Any
   * value written to this field will be ignored
   */
  char DO_NOT_USE_dummy_field_to_prevent_empty_struct;
} sbp_msg_nap_device_dna_req_t;

/**
 * Get encoded size of an instance of sbp_msg_nap_device_dna_req_t
 *
 * @param msg sbp_msg_nap_device_dna_req_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_nap_device_dna_req_t(
    const sbp_msg_nap_device_dna_req_t *msg);

/**
 * Encode an instance of sbp_msg_nap_device_dna_req_t to wire representation
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
 * @param msg Instance of sbp_msg_nap_device_dna_req_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_nap_device_dna_req_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_nap_device_dna_req_t *msg);

/**
 * Decode an instance of sbp_msg_nap_device_dna_req_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_nap_device_dna_req_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_nap_device_dna_req_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_nap_device_dna_req_t(const uint8_t *buf, uint8_t len,
                                           uint8_t *n_read,
                                           sbp_msg_nap_device_dna_req_t *msg);
/**
 * Send an instance of sbp_msg_nap_device_dna_req_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_nap_device_dna_req_t
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
s8 sbp_send_sbp_msg_nap_device_dna_req_t(
    struct sbp_state *s, u16 sender_id, const sbp_msg_nap_device_dna_req_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_nap_device_dna_req_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_nap_device_dna_req_t instance
 * @param b sbp_msg_nap_device_dna_req_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_nap_device_dna_req_t(const sbp_msg_nap_device_dna_req_t *a,
                                         const sbp_msg_nap_device_dna_req_t *b);

/** Read FPGA device ID over UART response (host <= device)
 *
 * The device message from the host reads a unique device identifier from the
 * SwiftNAP, an FPGA. The host requests the ID by sending a
 * MSG_NAP_DEVICE_DNA_REQ message. The device responds with a
 * MSG_NAP_DEVICE_DNA_RESP messagage with the device ID in the payload. Note
 * that this ID is tied to the FPGA, and not related to the Piksi's serial
 * number.
 */
typedef struct {
  /**
   * 57-bit SwiftNAP FPGA Device ID. Remaining bits are padded on the right.
   */
  u8 dna[8];
} sbp_msg_nap_device_dna_resp_t;

/**
 * Get encoded size of an instance of sbp_msg_nap_device_dna_resp_t
 *
 * @param msg sbp_msg_nap_device_dna_resp_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_nap_device_dna_resp_t(
    const sbp_msg_nap_device_dna_resp_t *msg);

/**
 * Encode an instance of sbp_msg_nap_device_dna_resp_t to wire representation
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
 * @param msg Instance of sbp_msg_nap_device_dna_resp_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_nap_device_dna_resp_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_nap_device_dna_resp_t *msg);

/**
 * Decode an instance of sbp_msg_nap_device_dna_resp_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_nap_device_dna_resp_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_nap_device_dna_resp_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_nap_device_dna_resp_t(const uint8_t *buf, uint8_t len,
                                            uint8_t *n_read,
                                            sbp_msg_nap_device_dna_resp_t *msg);
/**
 * Send an instance of sbp_msg_nap_device_dna_resp_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_nap_device_dna_resp_t
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
s8 sbp_send_sbp_msg_nap_device_dna_resp_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_nap_device_dna_resp_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_nap_device_dna_resp_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_nap_device_dna_resp_t instance
 * @param b sbp_msg_nap_device_dna_resp_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_nap_device_dna_resp_t(
    const sbp_msg_nap_device_dna_resp_t *a,
    const sbp_msg_nap_device_dna_resp_t *b);

/** Deprecated
 *
 * Deprecated.
 */
typedef struct {
  /**
   * Version number string (not NULL terminated)
   */
  sbp_unterminated_string_t handshake;
} sbp_msg_bootloader_handshake_dep_a_t;
void sbp_msg_bootloader_handshake_dep_a_t_handshake_init(
    sbp_unterminated_string_t *s);
bool sbp_msg_bootloader_handshake_dep_a_t_handshake_valid(
    const sbp_unterminated_string_t *s);
int sbp_msg_bootloader_handshake_dep_a_t_handshake_strcmp(
    const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b);
uint8_t sbp_msg_bootloader_handshake_dep_a_t_handshake_packed_len(
    const sbp_unterminated_string_t *s);
uint8_t sbp_msg_bootloader_handshake_dep_a_t_handshake_space_remaining(
    const sbp_unterminated_string_t *s);
bool sbp_msg_bootloader_handshake_dep_a_t_handshake_set(
    sbp_unterminated_string_t *s, const char *new_str);
bool sbp_msg_bootloader_handshake_dep_a_t_handshake_printf(
    sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_bootloader_handshake_dep_a_t_handshake_vprintf(
    sbp_unterminated_string_t *s, const char *fmt, va_list ap);
bool sbp_msg_bootloader_handshake_dep_a_t_handshake_append_printf(
    sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_bootloader_handshake_dep_a_t_handshake_append_vprintf(
    sbp_unterminated_string_t *s, const char *fmt, va_list ap);
const char *sbp_msg_bootloader_handshake_dep_a_t_handshake_get(
    const sbp_unterminated_string_t *s);

/**
 * Get encoded size of an instance of sbp_msg_bootloader_handshake_dep_a_t
 *
 * @param msg sbp_msg_bootloader_handshake_dep_a_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_bootloader_handshake_dep_a_t(
    const sbp_msg_bootloader_handshake_dep_a_t *msg);

/**
 * Encode an instance of sbp_msg_bootloader_handshake_dep_a_t to wire
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
 * @param msg Instance of sbp_msg_bootloader_handshake_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_bootloader_handshake_dep_a_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_bootloader_handshake_dep_a_t *msg);

/**
 * Decode an instance of sbp_msg_bootloader_handshake_dep_a_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_bootloader_handshake_dep_a_t message to the given instance. The
 * caller must specify the length of the buffer in the \p len parameter. If
 * non-null the number of bytes read from the buffer will be returned in \p
 * n_read.
 *
 * @param buf Wire representation of the sbp_msg_bootloader_handshake_dep_a_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_bootloader_handshake_dep_a_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_bootloader_handshake_dep_a_t *msg);
/**
 * Send an instance of sbp_msg_bootloader_handshake_dep_a_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_bootloader_handshake_dep_a_t
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
s8 sbp_send_sbp_msg_bootloader_handshake_dep_a_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_bootloader_handshake_dep_a_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_bootloader_handshake_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_bootloader_handshake_dep_a_t instance
 * @param b sbp_msg_bootloader_handshake_dep_a_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_bootloader_handshake_dep_a_t(
    const sbp_msg_bootloader_handshake_dep_a_t *a,
    const sbp_msg_bootloader_handshake_dep_a_t *b);

#ifdef __cplusplus
}
static inline bool operator==(const sbp_msg_bootloader_handshake_req_t &lhs,
                              const sbp_msg_bootloader_handshake_req_t &rhs) {
  return sbp_cmp_sbp_msg_bootloader_handshake_req_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_bootloader_handshake_req_t &lhs,
                              const sbp_msg_bootloader_handshake_req_t &rhs) {
  return sbp_cmp_sbp_msg_bootloader_handshake_req_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_bootloader_handshake_req_t &lhs,
                             const sbp_msg_bootloader_handshake_req_t &rhs) {
  return sbp_cmp_sbp_msg_bootloader_handshake_req_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_bootloader_handshake_req_t &lhs,
                              const sbp_msg_bootloader_handshake_req_t &rhs) {
  return sbp_cmp_sbp_msg_bootloader_handshake_req_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_bootloader_handshake_req_t &lhs,
                             const sbp_msg_bootloader_handshake_req_t &rhs) {
  return sbp_cmp_sbp_msg_bootloader_handshake_req_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_bootloader_handshake_req_t &lhs,
                              const sbp_msg_bootloader_handshake_req_t &rhs) {
  return sbp_cmp_sbp_msg_bootloader_handshake_req_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_bootloader_handshake_resp_t &lhs,
                              const sbp_msg_bootloader_handshake_resp_t &rhs) {
  return sbp_cmp_sbp_msg_bootloader_handshake_resp_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_bootloader_handshake_resp_t &lhs,
                              const sbp_msg_bootloader_handshake_resp_t &rhs) {
  return sbp_cmp_sbp_msg_bootloader_handshake_resp_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_bootloader_handshake_resp_t &lhs,
                             const sbp_msg_bootloader_handshake_resp_t &rhs) {
  return sbp_cmp_sbp_msg_bootloader_handshake_resp_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_bootloader_handshake_resp_t &lhs,
                              const sbp_msg_bootloader_handshake_resp_t &rhs) {
  return sbp_cmp_sbp_msg_bootloader_handshake_resp_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_bootloader_handshake_resp_t &lhs,
                             const sbp_msg_bootloader_handshake_resp_t &rhs) {
  return sbp_cmp_sbp_msg_bootloader_handshake_resp_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_bootloader_handshake_resp_t &lhs,
                              const sbp_msg_bootloader_handshake_resp_t &rhs) {
  return sbp_cmp_sbp_msg_bootloader_handshake_resp_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_bootloader_jump_to_app_t &lhs,
                              const sbp_msg_bootloader_jump_to_app_t &rhs) {
  return sbp_cmp_sbp_msg_bootloader_jump_to_app_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_bootloader_jump_to_app_t &lhs,
                              const sbp_msg_bootloader_jump_to_app_t &rhs) {
  return sbp_cmp_sbp_msg_bootloader_jump_to_app_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_bootloader_jump_to_app_t &lhs,
                             const sbp_msg_bootloader_jump_to_app_t &rhs) {
  return sbp_cmp_sbp_msg_bootloader_jump_to_app_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_bootloader_jump_to_app_t &lhs,
                              const sbp_msg_bootloader_jump_to_app_t &rhs) {
  return sbp_cmp_sbp_msg_bootloader_jump_to_app_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_bootloader_jump_to_app_t &lhs,
                             const sbp_msg_bootloader_jump_to_app_t &rhs) {
  return sbp_cmp_sbp_msg_bootloader_jump_to_app_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_bootloader_jump_to_app_t &lhs,
                              const sbp_msg_bootloader_jump_to_app_t &rhs) {
  return sbp_cmp_sbp_msg_bootloader_jump_to_app_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_nap_device_dna_req_t &lhs,
                              const sbp_msg_nap_device_dna_req_t &rhs) {
  return sbp_cmp_sbp_msg_nap_device_dna_req_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_nap_device_dna_req_t &lhs,
                              const sbp_msg_nap_device_dna_req_t &rhs) {
  return sbp_cmp_sbp_msg_nap_device_dna_req_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_nap_device_dna_req_t &lhs,
                             const sbp_msg_nap_device_dna_req_t &rhs) {
  return sbp_cmp_sbp_msg_nap_device_dna_req_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_nap_device_dna_req_t &lhs,
                              const sbp_msg_nap_device_dna_req_t &rhs) {
  return sbp_cmp_sbp_msg_nap_device_dna_req_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_nap_device_dna_req_t &lhs,
                             const sbp_msg_nap_device_dna_req_t &rhs) {
  return sbp_cmp_sbp_msg_nap_device_dna_req_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_nap_device_dna_req_t &lhs,
                              const sbp_msg_nap_device_dna_req_t &rhs) {
  return sbp_cmp_sbp_msg_nap_device_dna_req_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_nap_device_dna_resp_t &lhs,
                              const sbp_msg_nap_device_dna_resp_t &rhs) {
  return sbp_cmp_sbp_msg_nap_device_dna_resp_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_nap_device_dna_resp_t &lhs,
                              const sbp_msg_nap_device_dna_resp_t &rhs) {
  return sbp_cmp_sbp_msg_nap_device_dna_resp_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_nap_device_dna_resp_t &lhs,
                             const sbp_msg_nap_device_dna_resp_t &rhs) {
  return sbp_cmp_sbp_msg_nap_device_dna_resp_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_nap_device_dna_resp_t &lhs,
                              const sbp_msg_nap_device_dna_resp_t &rhs) {
  return sbp_cmp_sbp_msg_nap_device_dna_resp_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_nap_device_dna_resp_t &lhs,
                             const sbp_msg_nap_device_dna_resp_t &rhs) {
  return sbp_cmp_sbp_msg_nap_device_dna_resp_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_nap_device_dna_resp_t &lhs,
                              const sbp_msg_nap_device_dna_resp_t &rhs) {
  return sbp_cmp_sbp_msg_nap_device_dna_resp_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_bootloader_handshake_dep_a_t &lhs,
                              const sbp_msg_bootloader_handshake_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_bootloader_handshake_dep_a_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_bootloader_handshake_dep_a_t &lhs,
                              const sbp_msg_bootloader_handshake_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_bootloader_handshake_dep_a_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_bootloader_handshake_dep_a_t &lhs,
                             const sbp_msg_bootloader_handshake_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_bootloader_handshake_dep_a_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_bootloader_handshake_dep_a_t &lhs,
                              const sbp_msg_bootloader_handshake_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_bootloader_handshake_dep_a_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_bootloader_handshake_dep_a_t &lhs,
                             const sbp_msg_bootloader_handshake_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_bootloader_handshake_dep_a_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_bootloader_handshake_dep_a_t &lhs,
                              const sbp_msg_bootloader_handshake_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_bootloader_handshake_dep_a_t(&lhs, &rhs) >= 0;
}

#endif

#endif /* LIBSBP_NEW_BOOTLOAD_MESSAGES_H */
