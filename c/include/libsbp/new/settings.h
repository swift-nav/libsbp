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

#ifdef __cplusplus
extern "C" {
#endif

struct sbp_state;
/** Save settings to flash (host => device)
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_SETTINGS_MESSAGES_H
#define SBP_MSG_SETTINGS_SAVE 0x00A1
#endif
typedef struct {
  char DO_NOT_USE_dummy_field_to_prevent_empty_struct;
} sbp_msg_settings_save_t;

size_t sbp_packed_size_sbp_msg_settings_save_t(
    const sbp_msg_settings_save_t *msg);
s8 sbp_encode_sbp_msg_settings_save_t(uint8_t *buf, uint8_t len,
                                      uint8_t *n_written,
                                      const sbp_msg_settings_save_t *msg);
s8 sbp_decode_sbp_msg_settings_save_t(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_settings_save_t *msg);
s8 sbp_send_sbp_msg_settings_save_t(struct sbp_state *s, u16 sender_id,
                                    const sbp_msg_settings_save_t *msg,
                                    s32 (*write)(u8 *buff, u32 n,
                                                 void *context));

int sbp_cmp_sbp_msg_settings_save_t(const sbp_msg_settings_save_t *a,
                                    const sbp_msg_settings_save_t *b);

/** Write device configuration settings (host => device)
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_SETTINGS_MESSAGES_H
#define SBP_MSG_SETTINGS_WRITE 0x00A0
#endif
typedef struct {
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

size_t sbp_packed_size_sbp_msg_settings_write_t(
    const sbp_msg_settings_write_t *msg);
s8 sbp_encode_sbp_msg_settings_write_t(uint8_t *buf, uint8_t len,
                                       uint8_t *n_written,
                                       const sbp_msg_settings_write_t *msg);
s8 sbp_decode_sbp_msg_settings_write_t(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_msg_settings_write_t *msg);
s8 sbp_send_sbp_msg_settings_write_t(struct sbp_state *s, u16 sender_id,
                                     const sbp_msg_settings_write_t *msg,
                                     s32 (*write)(u8 *buff, u32 n,
                                                  void *context));

int sbp_cmp_sbp_msg_settings_write_t(const sbp_msg_settings_write_t *a,
                                     const sbp_msg_settings_write_t *b);

#ifndef LIBSBP_LEGACY_SETTINGS_MESSAGES_H
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_MASK (0x3)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_SHIFT (0u)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_GET(flags)      \
  (((flags) >> SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_SHIFT) & \
   SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_MASK)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_SET(flags, val)           \
  do {                                                                 \
    ((flags) |= (((val) & (SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_MASK)) \
                 << (SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_SHIFT)));    \
  } while (0)

#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_ACCEPTED_VALUE_UPDATED (0)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_REJECTED_VALUE_UNPARSABLE_OR_OUT_OF_RANGE \
  (1)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_REJECTED_REQUESTED_SETTING_DOES_NOT_EXIST \
  (2)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_REJECTED_SETTING_NAME_COULD_NOT_BE_PARSED \
  (3)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_REJECTED_SETTING_IS_READ_ONLY (4)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_REJECTED_MODIFICATION_IS_TEMPORARILY_DISABLED \
  (5)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_REJECTED_UNSPECIFIED_ERROR (6)
#endif
/** Acknowledgement with status of MSG_SETTINGS_WRITE
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_SETTINGS_MESSAGES_H
#define SBP_MSG_SETTINGS_WRITE_RESP 0x00AF
#endif
typedef struct {
  u8 status;
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

size_t sbp_packed_size_sbp_msg_settings_write_resp_t(
    const sbp_msg_settings_write_resp_t *msg);
s8 sbp_encode_sbp_msg_settings_write_resp_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_settings_write_resp_t *msg);
s8 sbp_decode_sbp_msg_settings_write_resp_t(const uint8_t *buf, uint8_t len,
                                            uint8_t *n_read,
                                            sbp_msg_settings_write_resp_t *msg);
s8 sbp_send_sbp_msg_settings_write_resp_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_settings_write_resp_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_settings_write_resp_t(
    const sbp_msg_settings_write_resp_t *a,
    const sbp_msg_settings_write_resp_t *b);

/** Read device configuration settings (host => device)
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_SETTINGS_MESSAGES_H
#define SBP_MSG_SETTINGS_READ_REQ 0x00A4
#endif
typedef struct {
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

size_t sbp_packed_size_sbp_msg_settings_read_req_t(
    const sbp_msg_settings_read_req_t *msg);
s8 sbp_encode_sbp_msg_settings_read_req_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_settings_read_req_t *msg);
s8 sbp_decode_sbp_msg_settings_read_req_t(const uint8_t *buf, uint8_t len,
                                          uint8_t *n_read,
                                          sbp_msg_settings_read_req_t *msg);
s8 sbp_send_sbp_msg_settings_read_req_t(struct sbp_state *s, u16 sender_id,
                                        const sbp_msg_settings_read_req_t *msg,
                                        s32 (*write)(u8 *buff, u32 n,
                                                     void *context));

int sbp_cmp_sbp_msg_settings_read_req_t(const sbp_msg_settings_read_req_t *a,
                                        const sbp_msg_settings_read_req_t *b);

/** Read device configuration settings (host <= device)
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_SETTINGS_MESSAGES_H
#define SBP_MSG_SETTINGS_READ_RESP 0x00A5
#endif
typedef struct {
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

size_t sbp_packed_size_sbp_msg_settings_read_resp_t(
    const sbp_msg_settings_read_resp_t *msg);
s8 sbp_encode_sbp_msg_settings_read_resp_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_settings_read_resp_t *msg);
s8 sbp_decode_sbp_msg_settings_read_resp_t(const uint8_t *buf, uint8_t len,
                                           uint8_t *n_read,
                                           sbp_msg_settings_read_resp_t *msg);
s8 sbp_send_sbp_msg_settings_read_resp_t(
    struct sbp_state *s, u16 sender_id, const sbp_msg_settings_read_resp_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_settings_read_resp_t(const sbp_msg_settings_read_resp_t *a,
                                         const sbp_msg_settings_read_resp_t *b);

/** Read setting by direct index (host => device)
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_SETTINGS_MESSAGES_H
#define SBP_MSG_SETTINGS_READ_BY_INDEX_REQ 0x00A2
#endif
typedef struct {
  u16 index;
} sbp_msg_settings_read_by_index_req_t;

size_t sbp_packed_size_sbp_msg_settings_read_by_index_req_t(
    const sbp_msg_settings_read_by_index_req_t *msg);
s8 sbp_encode_sbp_msg_settings_read_by_index_req_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_settings_read_by_index_req_t *msg);
s8 sbp_decode_sbp_msg_settings_read_by_index_req_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_settings_read_by_index_req_t *msg);
s8 sbp_send_sbp_msg_settings_read_by_index_req_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_settings_read_by_index_req_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_settings_read_by_index_req_t(
    const sbp_msg_settings_read_by_index_req_t *a,
    const sbp_msg_settings_read_by_index_req_t *b);

/** Read setting by direct index (host <= device)
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_SETTINGS_MESSAGES_H
#define SBP_MSG_SETTINGS_READ_BY_INDEX_RESP 0x00A7
#endif
typedef struct {
  u16 index;
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

size_t sbp_packed_size_sbp_msg_settings_read_by_index_resp_t(
    const sbp_msg_settings_read_by_index_resp_t *msg);
s8 sbp_encode_sbp_msg_settings_read_by_index_resp_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_settings_read_by_index_resp_t *msg);
s8 sbp_decode_sbp_msg_settings_read_by_index_resp_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_settings_read_by_index_resp_t *msg);
s8 sbp_send_sbp_msg_settings_read_by_index_resp_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_settings_read_by_index_resp_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_settings_read_by_index_resp_t(
    const sbp_msg_settings_read_by_index_resp_t *a,
    const sbp_msg_settings_read_by_index_resp_t *b);

/** Finished reading settings (host <= device)
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_SETTINGS_MESSAGES_H
#define SBP_MSG_SETTINGS_READ_BY_INDEX_DONE 0x00A6
#endif
typedef struct {
  char DO_NOT_USE_dummy_field_to_prevent_empty_struct;
} sbp_msg_settings_read_by_index_done_t;

size_t sbp_packed_size_sbp_msg_settings_read_by_index_done_t(
    const sbp_msg_settings_read_by_index_done_t *msg);
s8 sbp_encode_sbp_msg_settings_read_by_index_done_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_settings_read_by_index_done_t *msg);
s8 sbp_decode_sbp_msg_settings_read_by_index_done_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_settings_read_by_index_done_t *msg);
s8 sbp_send_sbp_msg_settings_read_by_index_done_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_settings_read_by_index_done_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_settings_read_by_index_done_t(
    const sbp_msg_settings_read_by_index_done_t *a,
    const sbp_msg_settings_read_by_index_done_t *b);

/** Register setting and default value (device => host)
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_SETTINGS_MESSAGES_H
#define SBP_MSG_SETTINGS_REGISTER 0x00AE
#endif
typedef struct {
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

size_t sbp_packed_size_sbp_msg_settings_register_t(
    const sbp_msg_settings_register_t *msg);
s8 sbp_encode_sbp_msg_settings_register_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_settings_register_t *msg);
s8 sbp_decode_sbp_msg_settings_register_t(const uint8_t *buf, uint8_t len,
                                          uint8_t *n_read,
                                          sbp_msg_settings_register_t *msg);
s8 sbp_send_sbp_msg_settings_register_t(struct sbp_state *s, u16 sender_id,
                                        const sbp_msg_settings_register_t *msg,
                                        s32 (*write)(u8 *buff, u32 n,
                                                     void *context));

int sbp_cmp_sbp_msg_settings_register_t(const sbp_msg_settings_register_t *a,
                                        const sbp_msg_settings_register_t *b);

#ifndef LIBSBP_LEGACY_SETTINGS_MESSAGES_H
#define SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_MASK (0x3)
#define SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_SHIFT (0u)
#define SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_GET(flags)      \
  (((flags) >> SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_SHIFT) & \
   SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_MASK)
#define SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_SET(flags, val)           \
  do {                                                                       \
    ((flags) |= (((val) & (SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_MASK)) \
                 << (SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_SHIFT)));    \
  } while (0)

#define SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_ACCEPTED_REQUESTED_DEFAULT_VALUE_RETURNED \
  (0)
#define SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_ACCEPTED_SETTING_FOUND_IN_PERMANENT_STORAGE_VALUE_FROM_STORAGE_RETURNED \
  (1)
#define SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_REJECTED_SETTING_ALREADY_REGISTERED_VALUE_FROM_MEMORY_RETURNED \
  (2)
#define SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_REJECTED_MALFORMED_MESSAGE \
  (3)
#endif
/** Register setting and default value (device <= host)
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_SETTINGS_MESSAGES_H
#define SBP_MSG_SETTINGS_REGISTER_RESP 0x01AF
#endif
typedef struct {
  u8 status;
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

size_t sbp_packed_size_sbp_msg_settings_register_resp_t(
    const sbp_msg_settings_register_resp_t *msg);
s8 sbp_encode_sbp_msg_settings_register_resp_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_settings_register_resp_t *msg);
s8 sbp_decode_sbp_msg_settings_register_resp_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_settings_register_resp_t *msg);
s8 sbp_send_sbp_msg_settings_register_resp_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_settings_register_resp_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_settings_register_resp_t(
    const sbp_msg_settings_register_resp_t *a,
    const sbp_msg_settings_register_resp_t *b);

#ifdef __cplusplus
}
static inline bool operator==(const sbp_msg_settings_save_t &a,
                              const sbp_msg_settings_save_t &b) {
  return sbp_cmp_sbp_msg_settings_save_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_settings_save_t &a,
                              const sbp_msg_settings_save_t &b) {
  return sbp_cmp_sbp_msg_settings_save_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_settings_save_t &a,
                             const sbp_msg_settings_save_t &b) {
  return sbp_cmp_sbp_msg_settings_save_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_settings_save_t &a,
                              const sbp_msg_settings_save_t &b) {
  return sbp_cmp_sbp_msg_settings_save_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_settings_save_t &a,
                             const sbp_msg_settings_save_t &b) {
  return sbp_cmp_sbp_msg_settings_save_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_settings_save_t &a,
                              const sbp_msg_settings_save_t &b) {
  return sbp_cmp_sbp_msg_settings_save_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_settings_write_t &a,
                              const sbp_msg_settings_write_t &b) {
  return sbp_cmp_sbp_msg_settings_write_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_settings_write_t &a,
                              const sbp_msg_settings_write_t &b) {
  return sbp_cmp_sbp_msg_settings_write_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_settings_write_t &a,
                             const sbp_msg_settings_write_t &b) {
  return sbp_cmp_sbp_msg_settings_write_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_settings_write_t &a,
                              const sbp_msg_settings_write_t &b) {
  return sbp_cmp_sbp_msg_settings_write_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_settings_write_t &a,
                             const sbp_msg_settings_write_t &b) {
  return sbp_cmp_sbp_msg_settings_write_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_settings_write_t &a,
                              const sbp_msg_settings_write_t &b) {
  return sbp_cmp_sbp_msg_settings_write_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_settings_write_resp_t &a,
                              const sbp_msg_settings_write_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_write_resp_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_settings_write_resp_t &a,
                              const sbp_msg_settings_write_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_write_resp_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_settings_write_resp_t &a,
                             const sbp_msg_settings_write_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_write_resp_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_settings_write_resp_t &a,
                              const sbp_msg_settings_write_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_write_resp_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_settings_write_resp_t &a,
                             const sbp_msg_settings_write_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_write_resp_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_settings_write_resp_t &a,
                              const sbp_msg_settings_write_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_write_resp_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_settings_read_req_t &a,
                              const sbp_msg_settings_read_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_req_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_settings_read_req_t &a,
                              const sbp_msg_settings_read_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_req_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_settings_read_req_t &a,
                             const sbp_msg_settings_read_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_req_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_settings_read_req_t &a,
                              const sbp_msg_settings_read_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_req_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_settings_read_req_t &a,
                             const sbp_msg_settings_read_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_req_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_settings_read_req_t &a,
                              const sbp_msg_settings_read_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_req_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_settings_read_resp_t &a,
                              const sbp_msg_settings_read_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_resp_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_settings_read_resp_t &a,
                              const sbp_msg_settings_read_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_resp_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_settings_read_resp_t &a,
                             const sbp_msg_settings_read_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_resp_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_settings_read_resp_t &a,
                              const sbp_msg_settings_read_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_resp_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_settings_read_resp_t &a,
                             const sbp_msg_settings_read_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_resp_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_settings_read_resp_t &a,
                              const sbp_msg_settings_read_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_resp_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_settings_read_by_index_req_t &a,
                              const sbp_msg_settings_read_by_index_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_req_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_settings_read_by_index_req_t &a,
                              const sbp_msg_settings_read_by_index_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_req_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_settings_read_by_index_req_t &a,
                             const sbp_msg_settings_read_by_index_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_req_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_settings_read_by_index_req_t &a,
                              const sbp_msg_settings_read_by_index_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_req_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_settings_read_by_index_req_t &a,
                             const sbp_msg_settings_read_by_index_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_req_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_settings_read_by_index_req_t &a,
                              const sbp_msg_settings_read_by_index_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_req_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_settings_read_by_index_resp_t &a,
                              const sbp_msg_settings_read_by_index_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_resp_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_settings_read_by_index_resp_t &a,
                              const sbp_msg_settings_read_by_index_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_resp_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_settings_read_by_index_resp_t &a,
                             const sbp_msg_settings_read_by_index_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_resp_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_settings_read_by_index_resp_t &a,
                              const sbp_msg_settings_read_by_index_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_resp_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_settings_read_by_index_resp_t &a,
                             const sbp_msg_settings_read_by_index_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_resp_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_settings_read_by_index_resp_t &a,
                              const sbp_msg_settings_read_by_index_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_resp_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_settings_read_by_index_done_t &a,
                              const sbp_msg_settings_read_by_index_done_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_done_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_settings_read_by_index_done_t &a,
                              const sbp_msg_settings_read_by_index_done_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_done_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_settings_read_by_index_done_t &a,
                             const sbp_msg_settings_read_by_index_done_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_done_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_settings_read_by_index_done_t &a,
                              const sbp_msg_settings_read_by_index_done_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_done_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_settings_read_by_index_done_t &a,
                             const sbp_msg_settings_read_by_index_done_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_done_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_settings_read_by_index_done_t &a,
                              const sbp_msg_settings_read_by_index_done_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_done_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_settings_register_t &a,
                              const sbp_msg_settings_register_t &b) {
  return sbp_cmp_sbp_msg_settings_register_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_settings_register_t &a,
                              const sbp_msg_settings_register_t &b) {
  return sbp_cmp_sbp_msg_settings_register_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_settings_register_t &a,
                             const sbp_msg_settings_register_t &b) {
  return sbp_cmp_sbp_msg_settings_register_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_settings_register_t &a,
                              const sbp_msg_settings_register_t &b) {
  return sbp_cmp_sbp_msg_settings_register_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_settings_register_t &a,
                             const sbp_msg_settings_register_t &b) {
  return sbp_cmp_sbp_msg_settings_register_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_settings_register_t &a,
                              const sbp_msg_settings_register_t &b) {
  return sbp_cmp_sbp_msg_settings_register_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_settings_register_resp_t &a,
                              const sbp_msg_settings_register_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_register_resp_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_settings_register_resp_t &a,
                              const sbp_msg_settings_register_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_register_resp_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_settings_register_resp_t &a,
                             const sbp_msg_settings_register_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_register_resp_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_settings_register_resp_t &a,
                              const sbp_msg_settings_register_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_register_resp_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_settings_register_resp_t &a,
                             const sbp_msg_settings_register_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_register_resp_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_settings_register_resp_t &a,
                              const sbp_msg_settings_register_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_register_resp_t(&a, &b) >= 0;
}

#endif

#endif /* LIBSBP_NEW_SETTINGS_MESSAGES_H */
