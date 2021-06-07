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
 * Automatically generated from yaml/swiftnav/sbp/settings.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_NEW_SETTINGS_MESSAGES_H
#define LIBSBP_NEW_SETTINGS_MESSAGES_H

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
#include <libsbp/settings_macros.h>

#ifdef __cplusplus
extern "C" {
#endif

struct sbp_state;

/** Save settings to flash (host => device)
 *
 * The save settings message persists the device's current settings
 * configuration to its onboard flash memory file system.
 */
typedef struct {
  /**
   * Do not use this field, it exists only to prevent illegal C syntax. Any
   * value written to this field will be ignored
   */
  char DO_NOT_USE_dummy_field_to_prevent_empty_struct;
} sbp_msg_settings_save_t;

/**
 * Get encoded size of an instance of sbp_msg_settings_save_t
 *
 * @param msg sbp_msg_settings_save_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_settings_save_t(
    const sbp_msg_settings_save_t *msg);

/**
 * Encode an instance of sbp_msg_settings_save_t to wire representation
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
 * @param msg Instance of sbp_msg_settings_save_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_settings_save_t(uint8_t *buf, uint8_t len,
                                      uint8_t *n_written,
                                      const sbp_msg_settings_save_t *msg);

/**
 * Decode an instance of sbp_msg_settings_save_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_settings_save_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_settings_save_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_settings_save_t(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_settings_save_t *msg);
/**
 * Send an instance of sbp_msg_settings_save_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_settings_save_t
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
s8 sbp_send_sbp_msg_settings_save_t(struct sbp_state *s, u16 sender_id,
                                    const sbp_msg_settings_save_t *msg,
                                    s32 (*write)(u8 *buff, u32 n,
                                                 void *context));

/**
 * Compare two instances of sbp_msg_settings_save_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_settings_save_t instance
 * @param b sbp_msg_settings_save_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_settings_save_t(const sbp_msg_settings_save_t *a,
                                    const sbp_msg_settings_save_t *b);

/** Write device configuration settings (host => device)
 *
 * The setting message writes the device configuration for a particular setting
 * via A NULL-terminated and NULL-delimited string with contents
 * "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence denotes
 * the NULL character and where quotation marks are omitted. A device will only
 * process to this message when it is received from sender ID 0x42. An example
 * string that could be sent to a device is "solution\0soln_freq\010\0".
 */
typedef struct {
  /**
   * A NULL-terminated and NULL-delimited string with contents
   * "SECTION_SETTING\0SETTING\0VALUE\0"
   */
  sbp_multipart_string_t setting;
} sbp_msg_settings_write_t;
void sbp_msg_settings_write_t_setting_init(sbp_multipart_string_t *s);
bool sbp_msg_settings_write_t_setting_valid(const sbp_multipart_string_t *s);
int sbp_msg_settings_write_t_setting_strcmp(const sbp_multipart_string_t *a,
                                            const sbp_multipart_string_t *b);
uint8_t sbp_msg_settings_write_t_setting_packed_len(
    const sbp_multipart_string_t *s);
uint8_t sbp_msg_settings_write_t_setting_space_remaining(
    const sbp_multipart_string_t *s);
uint8_t sbp_msg_settings_write_t_setting_count_sections(
    const sbp_multipart_string_t *s);
bool sbp_msg_settings_write_t_setting_add_section(sbp_multipart_string_t *s,
                                                  const char *new_str);
bool sbp_msg_settings_write_t_setting_add_section_printf(
    sbp_multipart_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_settings_write_t_setting_add_section_vprintf(
    sbp_multipart_string_t *s, const char *fmt, va_list ap);
bool sbp_msg_settings_write_t_setting_append(sbp_multipart_string_t *s,
                                             const char *str);
bool sbp_msg_settings_write_t_setting_append_printf(sbp_multipart_string_t *s,
                                                    const char *fmt, ...)
    SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_settings_write_t_setting_append_vprintf(sbp_multipart_string_t *s,
                                                     const char *fmt,
                                                     va_list ap);
const char *sbp_msg_settings_write_t_setting_get_section(
    const sbp_multipart_string_t *s, uint8_t section);
uint8_t sbp_msg_settings_write_t_setting_section_strlen(
    const sbp_multipart_string_t *s, uint8_t section);

/**
 * Get encoded size of an instance of sbp_msg_settings_write_t
 *
 * @param msg sbp_msg_settings_write_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_settings_write_t(
    const sbp_msg_settings_write_t *msg);

/**
 * Encode an instance of sbp_msg_settings_write_t to wire representation
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
 * @param msg Instance of sbp_msg_settings_write_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_settings_write_t(uint8_t *buf, uint8_t len,
                                       uint8_t *n_written,
                                       const sbp_msg_settings_write_t *msg);

/**
 * Decode an instance of sbp_msg_settings_write_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_settings_write_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_settings_write_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_settings_write_t(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_msg_settings_write_t *msg);
/**
 * Send an instance of sbp_msg_settings_write_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_settings_write_t
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
s8 sbp_send_sbp_msg_settings_write_t(struct sbp_state *s, u16 sender_id,
                                     const sbp_msg_settings_write_t *msg,
                                     s32 (*write)(u8 *buff, u32 n,
                                                  void *context));

/**
 * Compare two instances of sbp_msg_settings_write_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_settings_write_t instance
 * @param b sbp_msg_settings_write_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_settings_write_t(const sbp_msg_settings_write_t *a,
                                     const sbp_msg_settings_write_t *b);

/** Acknowledgement with status of MSG_SETTINGS_WRITE
 *
 * Return the status of a write request with the new value of the setting.  If
 * the requested value is rejected, the current value will be returned. The
 * string field is a NULL-terminated and NULL-delimited string with contents
 * "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence denotes
 * the NULL character and where quotation marks are omitted. An example string
 * that could be sent from device is "solution\0soln_freq\010\0".
 */
typedef struct {
  /**
   * Write status
   */
  u8 status;

  /**
   * A NULL-terminated and delimited string with contents
   * "SECTION_SETTING\0SETTING\0VALUE\0"
   */
  sbp_multipart_string_t setting;
} sbp_msg_settings_write_resp_t;
void sbp_msg_settings_write_resp_t_setting_init(sbp_multipart_string_t *s);
bool sbp_msg_settings_write_resp_t_setting_valid(
    const sbp_multipart_string_t *s);
int sbp_msg_settings_write_resp_t_setting_strcmp(
    const sbp_multipart_string_t *a, const sbp_multipart_string_t *b);
uint8_t sbp_msg_settings_write_resp_t_setting_packed_len(
    const sbp_multipart_string_t *s);
uint8_t sbp_msg_settings_write_resp_t_setting_space_remaining(
    const sbp_multipart_string_t *s);
uint8_t sbp_msg_settings_write_resp_t_setting_count_sections(
    const sbp_multipart_string_t *s);
bool sbp_msg_settings_write_resp_t_setting_add_section(
    sbp_multipart_string_t *s, const char *new_str);
bool sbp_msg_settings_write_resp_t_setting_add_section_printf(
    sbp_multipart_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_settings_write_resp_t_setting_add_section_vprintf(
    sbp_multipart_string_t *s, const char *fmt, va_list ap);
bool sbp_msg_settings_write_resp_t_setting_append(sbp_multipart_string_t *s,
                                                  const char *str);
bool sbp_msg_settings_write_resp_t_setting_append_printf(
    sbp_multipart_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_settings_write_resp_t_setting_append_vprintf(
    sbp_multipart_string_t *s, const char *fmt, va_list ap);
const char *sbp_msg_settings_write_resp_t_setting_get_section(
    const sbp_multipart_string_t *s, uint8_t section);
uint8_t sbp_msg_settings_write_resp_t_setting_section_strlen(
    const sbp_multipart_string_t *s, uint8_t section);

/**
 * Get encoded size of an instance of sbp_msg_settings_write_resp_t
 *
 * @param msg sbp_msg_settings_write_resp_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_settings_write_resp_t(
    const sbp_msg_settings_write_resp_t *msg);

/**
 * Encode an instance of sbp_msg_settings_write_resp_t to wire representation
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
 * @param msg Instance of sbp_msg_settings_write_resp_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_settings_write_resp_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_settings_write_resp_t *msg);

/**
 * Decode an instance of sbp_msg_settings_write_resp_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_settings_write_resp_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_settings_write_resp_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_settings_write_resp_t(const uint8_t *buf, uint8_t len,
                                            uint8_t *n_read,
                                            sbp_msg_settings_write_resp_t *msg);
/**
 * Send an instance of sbp_msg_settings_write_resp_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_settings_write_resp_t
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
s8 sbp_send_sbp_msg_settings_write_resp_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_settings_write_resp_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_settings_write_resp_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_settings_write_resp_t instance
 * @param b sbp_msg_settings_write_resp_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_settings_write_resp_t(
    const sbp_msg_settings_write_resp_t *a,
    const sbp_msg_settings_write_resp_t *b);

/** Read device configuration settings (host => device)
 *
 * The setting message that reads the device configuration. The string field is
 * a NULL-terminated and NULL-delimited string with contents
 * "SECTION_SETTING\0SETTING\0" where the '\0' escape sequence denotes the NULL
 * character and where quotation marks are omitted. An example string that could
 * be sent to a device is "solution\0soln_freq\0". A device will only respond to
 * this message when it is received from sender ID 0x42. A device should respond
 * with a MSG_SETTINGS_READ_RESP message (msg_id 0x00A5).
 */
typedef struct {
  /**
   * A NULL-terminated and NULL-delimited string with contents
   * "SECTION_SETTING\0SETTING\0"
   */
  sbp_multipart_string_t setting;
} sbp_msg_settings_read_req_t;
void sbp_msg_settings_read_req_t_setting_init(sbp_multipart_string_t *s);
bool sbp_msg_settings_read_req_t_setting_valid(const sbp_multipart_string_t *s);
int sbp_msg_settings_read_req_t_setting_strcmp(const sbp_multipart_string_t *a,
                                               const sbp_multipart_string_t *b);
uint8_t sbp_msg_settings_read_req_t_setting_packed_len(
    const sbp_multipart_string_t *s);
uint8_t sbp_msg_settings_read_req_t_setting_space_remaining(
    const sbp_multipart_string_t *s);
uint8_t sbp_msg_settings_read_req_t_setting_count_sections(
    const sbp_multipart_string_t *s);
bool sbp_msg_settings_read_req_t_setting_add_section(sbp_multipart_string_t *s,
                                                     const char *new_str);
bool sbp_msg_settings_read_req_t_setting_add_section_printf(
    sbp_multipart_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_settings_read_req_t_setting_add_section_vprintf(
    sbp_multipart_string_t *s, const char *fmt, va_list ap);
bool sbp_msg_settings_read_req_t_setting_append(sbp_multipart_string_t *s,
                                                const char *str);
bool sbp_msg_settings_read_req_t_setting_append_printf(
    sbp_multipart_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_settings_read_req_t_setting_append_vprintf(
    sbp_multipart_string_t *s, const char *fmt, va_list ap);
const char *sbp_msg_settings_read_req_t_setting_get_section(
    const sbp_multipart_string_t *s, uint8_t section);
uint8_t sbp_msg_settings_read_req_t_setting_section_strlen(
    const sbp_multipart_string_t *s, uint8_t section);

/**
 * Get encoded size of an instance of sbp_msg_settings_read_req_t
 *
 * @param msg sbp_msg_settings_read_req_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_settings_read_req_t(
    const sbp_msg_settings_read_req_t *msg);

/**
 * Encode an instance of sbp_msg_settings_read_req_t to wire representation
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
 * @param msg Instance of sbp_msg_settings_read_req_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_settings_read_req_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_settings_read_req_t *msg);

/**
 * Decode an instance of sbp_msg_settings_read_req_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_settings_read_req_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_settings_read_req_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_settings_read_req_t(const uint8_t *buf, uint8_t len,
                                          uint8_t *n_read,
                                          sbp_msg_settings_read_req_t *msg);
/**
 * Send an instance of sbp_msg_settings_read_req_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_settings_read_req_t
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
s8 sbp_send_sbp_msg_settings_read_req_t(struct sbp_state *s, u16 sender_id,
                                        const sbp_msg_settings_read_req_t *msg,
                                        s32 (*write)(u8 *buff, u32 n,
                                                     void *context));

/**
 * Compare two instances of sbp_msg_settings_read_req_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_settings_read_req_t instance
 * @param b sbp_msg_settings_read_req_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_settings_read_req_t(const sbp_msg_settings_read_req_t *a,
                                        const sbp_msg_settings_read_req_t *b);

/** Read device configuration settings (host <= device)
 *
 * The setting message wich which the device responds after a
 * MSG_SETTING_READ_REQ is sent to device. The string field is a NULL-terminated
 * and NULL-delimited string with contents "SECTION_SETTING\0SETTING\0VALUE\0"
 * where the '\0' escape sequence denotes the NULL character and where quotation
 * marks are omitted. An example string that could be sent from device is
 * "solution\0soln_freq\010\0".
 */
typedef struct {
  /**
   * A NULL-terminated and NULL-delimited string with contents
   * "SECTION_SETTING\0SETTING\0VALUE\0"
   */
  sbp_multipart_string_t setting;
} sbp_msg_settings_read_resp_t;
void sbp_msg_settings_read_resp_t_setting_init(sbp_multipart_string_t *s);
bool sbp_msg_settings_read_resp_t_setting_valid(
    const sbp_multipart_string_t *s);
int sbp_msg_settings_read_resp_t_setting_strcmp(
    const sbp_multipart_string_t *a, const sbp_multipart_string_t *b);
uint8_t sbp_msg_settings_read_resp_t_setting_packed_len(
    const sbp_multipart_string_t *s);
uint8_t sbp_msg_settings_read_resp_t_setting_space_remaining(
    const sbp_multipart_string_t *s);
uint8_t sbp_msg_settings_read_resp_t_setting_count_sections(
    const sbp_multipart_string_t *s);
bool sbp_msg_settings_read_resp_t_setting_add_section(sbp_multipart_string_t *s,
                                                      const char *new_str);
bool sbp_msg_settings_read_resp_t_setting_add_section_printf(
    sbp_multipart_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_settings_read_resp_t_setting_add_section_vprintf(
    sbp_multipart_string_t *s, const char *fmt, va_list ap);
bool sbp_msg_settings_read_resp_t_setting_append(sbp_multipart_string_t *s,
                                                 const char *str);
bool sbp_msg_settings_read_resp_t_setting_append_printf(
    sbp_multipart_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_settings_read_resp_t_setting_append_vprintf(
    sbp_multipart_string_t *s, const char *fmt, va_list ap);
const char *sbp_msg_settings_read_resp_t_setting_get_section(
    const sbp_multipart_string_t *s, uint8_t section);
uint8_t sbp_msg_settings_read_resp_t_setting_section_strlen(
    const sbp_multipart_string_t *s, uint8_t section);

/**
 * Get encoded size of an instance of sbp_msg_settings_read_resp_t
 *
 * @param msg sbp_msg_settings_read_resp_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_settings_read_resp_t(
    const sbp_msg_settings_read_resp_t *msg);

/**
 * Encode an instance of sbp_msg_settings_read_resp_t to wire representation
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
 * @param msg Instance of sbp_msg_settings_read_resp_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_settings_read_resp_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_settings_read_resp_t *msg);

/**
 * Decode an instance of sbp_msg_settings_read_resp_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_settings_read_resp_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_settings_read_resp_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_settings_read_resp_t(const uint8_t *buf, uint8_t len,
                                           uint8_t *n_read,
                                           sbp_msg_settings_read_resp_t *msg);
/**
 * Send an instance of sbp_msg_settings_read_resp_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_settings_read_resp_t
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
s8 sbp_send_sbp_msg_settings_read_resp_t(
    struct sbp_state *s, u16 sender_id, const sbp_msg_settings_read_resp_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_settings_read_resp_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_settings_read_resp_t instance
 * @param b sbp_msg_settings_read_resp_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_settings_read_resp_t(const sbp_msg_settings_read_resp_t *a,
                                         const sbp_msg_settings_read_resp_t *b);

/** Read setting by direct index (host => device)
 *
 * The settings message for iterating through the settings values. A device will
 * respond to this message with a "MSG_SETTINGS_READ_BY_INDEX_RESP".
 */
typedef struct {
  /**
   * An index into the device settings, with values ranging from 0 to
   * length(settings).
   */
  u16 index;
} sbp_msg_settings_read_by_index_req_t;

/**
 * Get encoded size of an instance of sbp_msg_settings_read_by_index_req_t
 *
 * @param msg sbp_msg_settings_read_by_index_req_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_settings_read_by_index_req_t(
    const sbp_msg_settings_read_by_index_req_t *msg);

/**
 * Encode an instance of sbp_msg_settings_read_by_index_req_t to wire
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
 * @param msg Instance of sbp_msg_settings_read_by_index_req_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_settings_read_by_index_req_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_settings_read_by_index_req_t *msg);

/**
 * Decode an instance of sbp_msg_settings_read_by_index_req_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_settings_read_by_index_req_t message to the given instance. The
 * caller must specify the length of the buffer in the \p len parameter. If
 * non-null the number of bytes read from the buffer will be returned in \p
 * n_read.
 *
 * @param buf Wire representation of the sbp_msg_settings_read_by_index_req_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_settings_read_by_index_req_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_settings_read_by_index_req_t *msg);
/**
 * Send an instance of sbp_msg_settings_read_by_index_req_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_settings_read_by_index_req_t
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
s8 sbp_send_sbp_msg_settings_read_by_index_req_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_settings_read_by_index_req_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_settings_read_by_index_req_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_settings_read_by_index_req_t instance
 * @param b sbp_msg_settings_read_by_index_req_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_settings_read_by_index_req_t(
    const sbp_msg_settings_read_by_index_req_t *a,
    const sbp_msg_settings_read_by_index_req_t *b);

/** Read setting by direct index (host <= device)
 *
 * The settings message that reports the value of a setting at an index.
 *
 */
typedef struct {
  /**
   * An index into the device settings, with values ranging from 0 to
   * length(settings)
   */
  u16 index;

  /**
   * A NULL-terminated and delimited string with contents
   * "SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0"
   */
  sbp_multipart_string_t setting;
} sbp_msg_settings_read_by_index_resp_t;
void sbp_msg_settings_read_by_index_resp_t_setting_init(
    sbp_multipart_string_t *s);
bool sbp_msg_settings_read_by_index_resp_t_setting_valid(
    const sbp_multipart_string_t *s);
int sbp_msg_settings_read_by_index_resp_t_setting_strcmp(
    const sbp_multipart_string_t *a, const sbp_multipart_string_t *b);
uint8_t sbp_msg_settings_read_by_index_resp_t_setting_packed_len(
    const sbp_multipart_string_t *s);
uint8_t sbp_msg_settings_read_by_index_resp_t_setting_space_remaining(
    const sbp_multipart_string_t *s);
uint8_t sbp_msg_settings_read_by_index_resp_t_setting_count_sections(
    const sbp_multipart_string_t *s);
bool sbp_msg_settings_read_by_index_resp_t_setting_add_section(
    sbp_multipart_string_t *s, const char *new_str);
bool sbp_msg_settings_read_by_index_resp_t_setting_add_section_printf(
    sbp_multipart_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_settings_read_by_index_resp_t_setting_add_section_vprintf(
    sbp_multipart_string_t *s, const char *fmt, va_list ap);
bool sbp_msg_settings_read_by_index_resp_t_setting_append(
    sbp_multipart_string_t *s, const char *str);
bool sbp_msg_settings_read_by_index_resp_t_setting_append_printf(
    sbp_multipart_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_settings_read_by_index_resp_t_setting_append_vprintf(
    sbp_multipart_string_t *s, const char *fmt, va_list ap);
const char *sbp_msg_settings_read_by_index_resp_t_setting_get_section(
    const sbp_multipart_string_t *s, uint8_t section);
uint8_t sbp_msg_settings_read_by_index_resp_t_setting_section_strlen(
    const sbp_multipart_string_t *s, uint8_t section);

/**
 * Get encoded size of an instance of sbp_msg_settings_read_by_index_resp_t
 *
 * @param msg sbp_msg_settings_read_by_index_resp_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_settings_read_by_index_resp_t(
    const sbp_msg_settings_read_by_index_resp_t *msg);

/**
 * Encode an instance of sbp_msg_settings_read_by_index_resp_t to wire
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
 * @param msg Instance of sbp_msg_settings_read_by_index_resp_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_settings_read_by_index_resp_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_settings_read_by_index_resp_t *msg);

/**
 * Decode an instance of sbp_msg_settings_read_by_index_resp_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_settings_read_by_index_resp_t message to the given instance. The
 * caller must specify the length of the buffer in the \p len parameter. If
 * non-null the number of bytes read from the buffer will be returned in \p
 * n_read.
 *
 * @param buf Wire representation of the sbp_msg_settings_read_by_index_resp_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_settings_read_by_index_resp_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_settings_read_by_index_resp_t *msg);
/**
 * Send an instance of sbp_msg_settings_read_by_index_resp_t with the given
 * write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_settings_read_by_index_resp_t
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
s8 sbp_send_sbp_msg_settings_read_by_index_resp_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_settings_read_by_index_resp_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_settings_read_by_index_resp_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_settings_read_by_index_resp_t instance
 * @param b sbp_msg_settings_read_by_index_resp_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_settings_read_by_index_resp_t(
    const sbp_msg_settings_read_by_index_resp_t *a,
    const sbp_msg_settings_read_by_index_resp_t *b);

/** Finished reading settings (host <= device)
 *
 * The settings message for indicating end of the settings values.
 */
typedef struct {
  /**
   * Do not use this field, it exists only to prevent illegal C syntax. Any
   * value written to this field will be ignored
   */
  char DO_NOT_USE_dummy_field_to_prevent_empty_struct;
} sbp_msg_settings_read_by_index_done_t;

/**
 * Get encoded size of an instance of sbp_msg_settings_read_by_index_done_t
 *
 * @param msg sbp_msg_settings_read_by_index_done_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_settings_read_by_index_done_t(
    const sbp_msg_settings_read_by_index_done_t *msg);

/**
 * Encode an instance of sbp_msg_settings_read_by_index_done_t to wire
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
 * @param msg Instance of sbp_msg_settings_read_by_index_done_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_settings_read_by_index_done_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_settings_read_by_index_done_t *msg);

/**
 * Decode an instance of sbp_msg_settings_read_by_index_done_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_settings_read_by_index_done_t message to the given instance. The
 * caller must specify the length of the buffer in the \p len parameter. If
 * non-null the number of bytes read from the buffer will be returned in \p
 * n_read.
 *
 * @param buf Wire representation of the sbp_msg_settings_read_by_index_done_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_settings_read_by_index_done_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_settings_read_by_index_done_t *msg);
/**
 * Send an instance of sbp_msg_settings_read_by_index_done_t with the given
 * write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_settings_read_by_index_done_t
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
s8 sbp_send_sbp_msg_settings_read_by_index_done_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_settings_read_by_index_done_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_settings_read_by_index_done_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_settings_read_by_index_done_t instance
 * @param b sbp_msg_settings_read_by_index_done_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_settings_read_by_index_done_t(
    const sbp_msg_settings_read_by_index_done_t *a,
    const sbp_msg_settings_read_by_index_done_t *b);

/** Register setting and default value (device => host)
 *
 * This message registers the presence and default value of a setting with a
 * settings daemon.  The host should reply with MSG_SETTINGS_WRITE for this
 * setting to set the initial value.
 */
typedef struct {
  /**
   * A NULL-terminated and delimited string with contents
   * "SECTION_SETTING\0SETTING\0VALUE".
   */
  sbp_multipart_string_t setting;
} sbp_msg_settings_register_t;
void sbp_msg_settings_register_t_setting_init(sbp_multipart_string_t *s);
bool sbp_msg_settings_register_t_setting_valid(const sbp_multipart_string_t *s);
int sbp_msg_settings_register_t_setting_strcmp(const sbp_multipart_string_t *a,
                                               const sbp_multipart_string_t *b);
uint8_t sbp_msg_settings_register_t_setting_packed_len(
    const sbp_multipart_string_t *s);
uint8_t sbp_msg_settings_register_t_setting_space_remaining(
    const sbp_multipart_string_t *s);
uint8_t sbp_msg_settings_register_t_setting_count_sections(
    const sbp_multipart_string_t *s);
bool sbp_msg_settings_register_t_setting_add_section(sbp_multipart_string_t *s,
                                                     const char *new_str);
bool sbp_msg_settings_register_t_setting_add_section_printf(
    sbp_multipart_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_settings_register_t_setting_add_section_vprintf(
    sbp_multipart_string_t *s, const char *fmt, va_list ap);
bool sbp_msg_settings_register_t_setting_append(sbp_multipart_string_t *s,
                                                const char *str);
bool sbp_msg_settings_register_t_setting_append_printf(
    sbp_multipart_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_settings_register_t_setting_append_vprintf(
    sbp_multipart_string_t *s, const char *fmt, va_list ap);
const char *sbp_msg_settings_register_t_setting_get_section(
    const sbp_multipart_string_t *s, uint8_t section);
uint8_t sbp_msg_settings_register_t_setting_section_strlen(
    const sbp_multipart_string_t *s, uint8_t section);

/**
 * Get encoded size of an instance of sbp_msg_settings_register_t
 *
 * @param msg sbp_msg_settings_register_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_settings_register_t(
    const sbp_msg_settings_register_t *msg);

/**
 * Encode an instance of sbp_msg_settings_register_t to wire representation
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
 * @param msg Instance of sbp_msg_settings_register_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_settings_register_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_settings_register_t *msg);

/**
 * Decode an instance of sbp_msg_settings_register_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_settings_register_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_settings_register_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_settings_register_t(const uint8_t *buf, uint8_t len,
                                          uint8_t *n_read,
                                          sbp_msg_settings_register_t *msg);
/**
 * Send an instance of sbp_msg_settings_register_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_settings_register_t
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
s8 sbp_send_sbp_msg_settings_register_t(struct sbp_state *s, u16 sender_id,
                                        const sbp_msg_settings_register_t *msg,
                                        s32 (*write)(u8 *buff, u32 n,
                                                     void *context));

/**
 * Compare two instances of sbp_msg_settings_register_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_settings_register_t instance
 * @param b sbp_msg_settings_register_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_settings_register_t(const sbp_msg_settings_register_t *a,
                                        const sbp_msg_settings_register_t *b);

/** Register setting and default value (device <= host)
 *
 * This message responds to setting registration with the effective value. The
 * effective value shall differ from the given default value if setting was
 * already registered or is available in the permanent setting storage and had a
 * different value.
 */
typedef struct {
  /**
   * Register status
   */
  u8 status;

  /**
   * A NULL-terminated and delimited string with contents
   * "SECTION_SETTING\0SETTING\0VALUE". The meaning of value is defined
   * according to the status field.
   */
  sbp_multipart_string_t setting;
} sbp_msg_settings_register_resp_t;
void sbp_msg_settings_register_resp_t_setting_init(sbp_multipart_string_t *s);
bool sbp_msg_settings_register_resp_t_setting_valid(
    const sbp_multipart_string_t *s);
int sbp_msg_settings_register_resp_t_setting_strcmp(
    const sbp_multipart_string_t *a, const sbp_multipart_string_t *b);
uint8_t sbp_msg_settings_register_resp_t_setting_packed_len(
    const sbp_multipart_string_t *s);
uint8_t sbp_msg_settings_register_resp_t_setting_space_remaining(
    const sbp_multipart_string_t *s);
uint8_t sbp_msg_settings_register_resp_t_setting_count_sections(
    const sbp_multipart_string_t *s);
bool sbp_msg_settings_register_resp_t_setting_add_section(
    sbp_multipart_string_t *s, const char *new_str);
bool sbp_msg_settings_register_resp_t_setting_add_section_printf(
    sbp_multipart_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_settings_register_resp_t_setting_add_section_vprintf(
    sbp_multipart_string_t *s, const char *fmt, va_list ap);
bool sbp_msg_settings_register_resp_t_setting_append(sbp_multipart_string_t *s,
                                                     const char *str);
bool sbp_msg_settings_register_resp_t_setting_append_printf(
    sbp_multipart_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2, 3);
bool sbp_msg_settings_register_resp_t_setting_append_vprintf(
    sbp_multipart_string_t *s, const char *fmt, va_list ap);
const char *sbp_msg_settings_register_resp_t_setting_get_section(
    const sbp_multipart_string_t *s, uint8_t section);
uint8_t sbp_msg_settings_register_resp_t_setting_section_strlen(
    const sbp_multipart_string_t *s, uint8_t section);

/**
 * Get encoded size of an instance of sbp_msg_settings_register_resp_t
 *
 * @param msg sbp_msg_settings_register_resp_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_settings_register_resp_t(
    const sbp_msg_settings_register_resp_t *msg);

/**
 * Encode an instance of sbp_msg_settings_register_resp_t to wire representation
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
 * @param msg Instance of sbp_msg_settings_register_resp_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_settings_register_resp_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_settings_register_resp_t *msg);

/**
 * Decode an instance of sbp_msg_settings_register_resp_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_settings_register_resp_t message to the given instance. The caller
 * must specify the length of the buffer in the \p len parameter. If non-null
 * the number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_settings_register_resp_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_settings_register_resp_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_settings_register_resp_t *msg);
/**
 * Send an instance of sbp_msg_settings_register_resp_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_settings_register_resp_t
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
s8 sbp_send_sbp_msg_settings_register_resp_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_settings_register_resp_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_settings_register_resp_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_settings_register_resp_t instance
 * @param b sbp_msg_settings_register_resp_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_settings_register_resp_t(
    const sbp_msg_settings_register_resp_t *a,
    const sbp_msg_settings_register_resp_t *b);

#ifdef __cplusplus
}
static inline bool operator==(const sbp_msg_settings_save_t &lhs,
                              const sbp_msg_settings_save_t &rhs) {
  return sbp_cmp_sbp_msg_settings_save_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_settings_save_t &lhs,
                              const sbp_msg_settings_save_t &rhs) {
  return sbp_cmp_sbp_msg_settings_save_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_settings_save_t &lhs,
                             const sbp_msg_settings_save_t &rhs) {
  return sbp_cmp_sbp_msg_settings_save_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_settings_save_t &lhs,
                              const sbp_msg_settings_save_t &rhs) {
  return sbp_cmp_sbp_msg_settings_save_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_settings_save_t &lhs,
                             const sbp_msg_settings_save_t &rhs) {
  return sbp_cmp_sbp_msg_settings_save_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_settings_save_t &lhs,
                              const sbp_msg_settings_save_t &rhs) {
  return sbp_cmp_sbp_msg_settings_save_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_settings_write_t &lhs,
                              const sbp_msg_settings_write_t &rhs) {
  return sbp_cmp_sbp_msg_settings_write_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_settings_write_t &lhs,
                              const sbp_msg_settings_write_t &rhs) {
  return sbp_cmp_sbp_msg_settings_write_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_settings_write_t &lhs,
                             const sbp_msg_settings_write_t &rhs) {
  return sbp_cmp_sbp_msg_settings_write_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_settings_write_t &lhs,
                              const sbp_msg_settings_write_t &rhs) {
  return sbp_cmp_sbp_msg_settings_write_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_settings_write_t &lhs,
                             const sbp_msg_settings_write_t &rhs) {
  return sbp_cmp_sbp_msg_settings_write_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_settings_write_t &lhs,
                              const sbp_msg_settings_write_t &rhs) {
  return sbp_cmp_sbp_msg_settings_write_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_settings_write_resp_t &lhs,
                              const sbp_msg_settings_write_resp_t &rhs) {
  return sbp_cmp_sbp_msg_settings_write_resp_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_settings_write_resp_t &lhs,
                              const sbp_msg_settings_write_resp_t &rhs) {
  return sbp_cmp_sbp_msg_settings_write_resp_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_settings_write_resp_t &lhs,
                             const sbp_msg_settings_write_resp_t &rhs) {
  return sbp_cmp_sbp_msg_settings_write_resp_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_settings_write_resp_t &lhs,
                              const sbp_msg_settings_write_resp_t &rhs) {
  return sbp_cmp_sbp_msg_settings_write_resp_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_settings_write_resp_t &lhs,
                             const sbp_msg_settings_write_resp_t &rhs) {
  return sbp_cmp_sbp_msg_settings_write_resp_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_settings_write_resp_t &lhs,
                              const sbp_msg_settings_write_resp_t &rhs) {
  return sbp_cmp_sbp_msg_settings_write_resp_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_settings_read_req_t &lhs,
                              const sbp_msg_settings_read_req_t &rhs) {
  return sbp_cmp_sbp_msg_settings_read_req_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_settings_read_req_t &lhs,
                              const sbp_msg_settings_read_req_t &rhs) {
  return sbp_cmp_sbp_msg_settings_read_req_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_settings_read_req_t &lhs,
                             const sbp_msg_settings_read_req_t &rhs) {
  return sbp_cmp_sbp_msg_settings_read_req_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_settings_read_req_t &lhs,
                              const sbp_msg_settings_read_req_t &rhs) {
  return sbp_cmp_sbp_msg_settings_read_req_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_settings_read_req_t &lhs,
                             const sbp_msg_settings_read_req_t &rhs) {
  return sbp_cmp_sbp_msg_settings_read_req_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_settings_read_req_t &lhs,
                              const sbp_msg_settings_read_req_t &rhs) {
  return sbp_cmp_sbp_msg_settings_read_req_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_settings_read_resp_t &lhs,
                              const sbp_msg_settings_read_resp_t &rhs) {
  return sbp_cmp_sbp_msg_settings_read_resp_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_settings_read_resp_t &lhs,
                              const sbp_msg_settings_read_resp_t &rhs) {
  return sbp_cmp_sbp_msg_settings_read_resp_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_settings_read_resp_t &lhs,
                             const sbp_msg_settings_read_resp_t &rhs) {
  return sbp_cmp_sbp_msg_settings_read_resp_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_settings_read_resp_t &lhs,
                              const sbp_msg_settings_read_resp_t &rhs) {
  return sbp_cmp_sbp_msg_settings_read_resp_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_settings_read_resp_t &lhs,
                             const sbp_msg_settings_read_resp_t &rhs) {
  return sbp_cmp_sbp_msg_settings_read_resp_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_settings_read_resp_t &lhs,
                              const sbp_msg_settings_read_resp_t &rhs) {
  return sbp_cmp_sbp_msg_settings_read_resp_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_settings_read_by_index_req_t &lhs,
                              const sbp_msg_settings_read_by_index_req_t &rhs) {
  return sbp_cmp_sbp_msg_settings_read_by_index_req_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_settings_read_by_index_req_t &lhs,
                              const sbp_msg_settings_read_by_index_req_t &rhs) {
  return sbp_cmp_sbp_msg_settings_read_by_index_req_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_settings_read_by_index_req_t &lhs,
                             const sbp_msg_settings_read_by_index_req_t &rhs) {
  return sbp_cmp_sbp_msg_settings_read_by_index_req_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_settings_read_by_index_req_t &lhs,
                              const sbp_msg_settings_read_by_index_req_t &rhs) {
  return sbp_cmp_sbp_msg_settings_read_by_index_req_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_settings_read_by_index_req_t &lhs,
                             const sbp_msg_settings_read_by_index_req_t &rhs) {
  return sbp_cmp_sbp_msg_settings_read_by_index_req_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_settings_read_by_index_req_t &lhs,
                              const sbp_msg_settings_read_by_index_req_t &rhs) {
  return sbp_cmp_sbp_msg_settings_read_by_index_req_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(
    const sbp_msg_settings_read_by_index_resp_t &lhs,
    const sbp_msg_settings_read_by_index_resp_t &rhs) {
  return sbp_cmp_sbp_msg_settings_read_by_index_resp_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(
    const sbp_msg_settings_read_by_index_resp_t &lhs,
    const sbp_msg_settings_read_by_index_resp_t &rhs) {
  return sbp_cmp_sbp_msg_settings_read_by_index_resp_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_settings_read_by_index_resp_t &lhs,
                             const sbp_msg_settings_read_by_index_resp_t &rhs) {
  return sbp_cmp_sbp_msg_settings_read_by_index_resp_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(
    const sbp_msg_settings_read_by_index_resp_t &lhs,
    const sbp_msg_settings_read_by_index_resp_t &rhs) {
  return sbp_cmp_sbp_msg_settings_read_by_index_resp_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_settings_read_by_index_resp_t &lhs,
                             const sbp_msg_settings_read_by_index_resp_t &rhs) {
  return sbp_cmp_sbp_msg_settings_read_by_index_resp_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(
    const sbp_msg_settings_read_by_index_resp_t &lhs,
    const sbp_msg_settings_read_by_index_resp_t &rhs) {
  return sbp_cmp_sbp_msg_settings_read_by_index_resp_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(
    const sbp_msg_settings_read_by_index_done_t &lhs,
    const sbp_msg_settings_read_by_index_done_t &rhs) {
  return sbp_cmp_sbp_msg_settings_read_by_index_done_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(
    const sbp_msg_settings_read_by_index_done_t &lhs,
    const sbp_msg_settings_read_by_index_done_t &rhs) {
  return sbp_cmp_sbp_msg_settings_read_by_index_done_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_settings_read_by_index_done_t &lhs,
                             const sbp_msg_settings_read_by_index_done_t &rhs) {
  return sbp_cmp_sbp_msg_settings_read_by_index_done_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(
    const sbp_msg_settings_read_by_index_done_t &lhs,
    const sbp_msg_settings_read_by_index_done_t &rhs) {
  return sbp_cmp_sbp_msg_settings_read_by_index_done_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_settings_read_by_index_done_t &lhs,
                             const sbp_msg_settings_read_by_index_done_t &rhs) {
  return sbp_cmp_sbp_msg_settings_read_by_index_done_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(
    const sbp_msg_settings_read_by_index_done_t &lhs,
    const sbp_msg_settings_read_by_index_done_t &rhs) {
  return sbp_cmp_sbp_msg_settings_read_by_index_done_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_settings_register_t &lhs,
                              const sbp_msg_settings_register_t &rhs) {
  return sbp_cmp_sbp_msg_settings_register_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_settings_register_t &lhs,
                              const sbp_msg_settings_register_t &rhs) {
  return sbp_cmp_sbp_msg_settings_register_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_settings_register_t &lhs,
                             const sbp_msg_settings_register_t &rhs) {
  return sbp_cmp_sbp_msg_settings_register_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_settings_register_t &lhs,
                              const sbp_msg_settings_register_t &rhs) {
  return sbp_cmp_sbp_msg_settings_register_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_settings_register_t &lhs,
                             const sbp_msg_settings_register_t &rhs) {
  return sbp_cmp_sbp_msg_settings_register_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_settings_register_t &lhs,
                              const sbp_msg_settings_register_t &rhs) {
  return sbp_cmp_sbp_msg_settings_register_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_settings_register_resp_t &lhs,
                              const sbp_msg_settings_register_resp_t &rhs) {
  return sbp_cmp_sbp_msg_settings_register_resp_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_settings_register_resp_t &lhs,
                              const sbp_msg_settings_register_resp_t &rhs) {
  return sbp_cmp_sbp_msg_settings_register_resp_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_settings_register_resp_t &lhs,
                             const sbp_msg_settings_register_resp_t &rhs) {
  return sbp_cmp_sbp_msg_settings_register_resp_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_settings_register_resp_t &lhs,
                              const sbp_msg_settings_register_resp_t &rhs) {
  return sbp_cmp_sbp_msg_settings_register_resp_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_settings_register_resp_t &lhs,
                             const sbp_msg_settings_register_resp_t &rhs) {
  return sbp_cmp_sbp_msg_settings_register_resp_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_settings_register_resp_t &lhs,
                              const sbp_msg_settings_register_resp_t &rhs) {
  return sbp_cmp_sbp_msg_settings_register_resp_t(&lhs, &rhs) >= 0;
}

#endif

#endif /* LIBSBP_NEW_SETTINGS_MESSAGES_H */
