#ifndef LIBSBP_SETTINGS_MESSAGES_H
#define LIBSBP_SETTINGS_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/string/multipart.h>
#include <libsbp/unpacked/string/sequence.h>
#include <libsbp/unpacked/string/unterminated.h>
#include <libsbp/unpacked/string/null_terminated.h>
#include <libsbp/unpacked/string/binary.h>

#ifdef __cplusplus
  extern "C" {
#endif
/** Save settings to flash (host => device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_SETTINGS_SAVE               0x00A1
typedef struct {
  char DO_NOT_USE_dummy_field_to_prevent_empty_struct;
} sbp_msg_settings_save_t;

size_t sbp_packed_size_sbp_msg_settings_save_t(const sbp_msg_settings_save_t *msg);
s8 sbp_pack_sbp_msg_settings_save_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_settings_save_t *msg);
s8 sbp_unpack_sbp_msg_settings_save_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_settings_save_t *msg);

int sbp_cmp_sbp_msg_settings_save_t(const sbp_msg_settings_save_t *a, const sbp_msg_settings_save_t *b);


/** Write device configuration settings (host => device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_SETTINGS_WRITE              0x00A0
typedef struct {
  sbp_multipart_string_t setting;
} sbp_msg_settings_write_t;
#define sbp_msg_settings_write_t_setting_init(f) sbp_multipart_string_init(f, 255, 3, 3)
#define sbp_msg_settings_write_t_setting_valid(f) sbp_multipart_string_valid(f, 255, 3, 3)
#define sbp_msg_settings_write_t_setting_packed_len(f) sbp_multipart_string_packed_len(f, 255, 3, 3)
#define sbp_msg_settings_write_t_setting_append(f,s) sbp_multipart_string_append(f, s, 255, 3, 3)
#define sbp_msg_settings_write_t_setting_append_printf(f, ...) sbp_multipart_string_append_printf(s, 255, 3, 3, __VA_ARGS__)
#define sbp_msg_settings_write_t_setting_append_vprintf(f, fmt,ap) sbp_multipart_string_append_vprintf(s, 255, 3, 3, fmt, ap)
#define sbp_msg_settings_write_t_setting_count_sections(f) sbp_multipart_string_count_sections(f, 255, 3, 3)
#define sbp_msg_settings_write_t_setting_get_section(f,s) sbp_multipart_string_get_section(f,s,255, 3, 3)
#define sbp_msg_settings_write_t_setting_section_len(f,s) sbp_multipart_string_section_len(f,s,255, 3, 3)
#define sbp_msg_settings_write_t_setting_space_remaining(f) sbp_multipart_string_space_remaining(f,255, 3, 3)
#define sbp_msg_settings_write_t_setting_strcmp(a,b) sbp_multipart_string_strcmp(a,b,255, 3, 3)

size_t sbp_packed_size_sbp_msg_settings_write_t(const sbp_msg_settings_write_t *msg);
s8 sbp_pack_sbp_msg_settings_write_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_settings_write_t *msg);
s8 sbp_unpack_sbp_msg_settings_write_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_settings_write_t *msg);

int sbp_cmp_sbp_msg_settings_write_t(const sbp_msg_settings_write_t *a, const sbp_msg_settings_write_t *b);


#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_MASK (0x3)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_SHIFT (0u)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_GET(flags) \
                             (((flags) >> SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_SHIFT) \
                             & SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_MASK)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_MASK)) \
                             << (SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_SHIFT)));} while(0)
                             

#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_ACCEPTED_VALUE_UPDATED (0)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_REJECTED_VALUE_UNPARSABLE_OR_OUT_OF_RANGE (1)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_REJECTED_REQUESTED_SETTING_DOES_NOT_EXIST (2)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_REJECTED_SETTING_NAME_COULD_NOT_BE_PARSED (3)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_REJECTED_SETTING_IS_READ_ONLY (4)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_REJECTED_MODIFICATION_IS_TEMPORARILY_DISABLED (5)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_REJECTED_UNSPECIFIED_ERROR (6)
/** Acknowledgement with status of MSG_SETTINGS_WRITE
 *
((m.desc|commentify)))
 */
#define SBP_MSG_SETTINGS_WRITE_RESP         0x00AF
typedef struct {
  u8 status;
  sbp_multipart_string_t setting;
} sbp_msg_settings_write_resp_t;
#define sbp_msg_settings_write_resp_t_setting_init(f) sbp_multipart_string_init(f, 254, 3, 3)
#define sbp_msg_settings_write_resp_t_setting_valid(f) sbp_multipart_string_valid(f, 254, 3, 3)
#define sbp_msg_settings_write_resp_t_setting_packed_len(f) sbp_multipart_string_packed_len(f, 254, 3, 3)
#define sbp_msg_settings_write_resp_t_setting_append(f,s) sbp_multipart_string_append(f, s, 254, 3, 3)
#define sbp_msg_settings_write_resp_t_setting_append_printf(f, ...) sbp_multipart_string_append_printf(s, 254, 3, 3, __VA_ARGS__)
#define sbp_msg_settings_write_resp_t_setting_append_vprintf(f, fmt,ap) sbp_multipart_string_append_vprintf(s, 254, 3, 3, fmt, ap)
#define sbp_msg_settings_write_resp_t_setting_count_sections(f) sbp_multipart_string_count_sections(f, 254, 3, 3)
#define sbp_msg_settings_write_resp_t_setting_get_section(f,s) sbp_multipart_string_get_section(f,s,254, 3, 3)
#define sbp_msg_settings_write_resp_t_setting_section_len(f,s) sbp_multipart_string_section_len(f,s,254, 3, 3)
#define sbp_msg_settings_write_resp_t_setting_space_remaining(f) sbp_multipart_string_space_remaining(f,254, 3, 3)
#define sbp_msg_settings_write_resp_t_setting_strcmp(a,b) sbp_multipart_string_strcmp(a,b,254, 3, 3)

size_t sbp_packed_size_sbp_msg_settings_write_resp_t(const sbp_msg_settings_write_resp_t *msg);
s8 sbp_pack_sbp_msg_settings_write_resp_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_settings_write_resp_t *msg);
s8 sbp_unpack_sbp_msg_settings_write_resp_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_settings_write_resp_t *msg);

int sbp_cmp_sbp_msg_settings_write_resp_t(const sbp_msg_settings_write_resp_t *a, const sbp_msg_settings_write_resp_t *b);


/** Read device configuration settings (host => device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_SETTINGS_READ_REQ           0x00A4
typedef struct {
  sbp_multipart_string_t setting;
} sbp_msg_settings_read_req_t;
#define sbp_msg_settings_read_req_t_setting_init(f) sbp_multipart_string_init(f, 255, 2, 2)
#define sbp_msg_settings_read_req_t_setting_valid(f) sbp_multipart_string_valid(f, 255, 2, 2)
#define sbp_msg_settings_read_req_t_setting_packed_len(f) sbp_multipart_string_packed_len(f, 255, 2, 2)
#define sbp_msg_settings_read_req_t_setting_append(f,s) sbp_multipart_string_append(f, s, 255, 2, 2)
#define sbp_msg_settings_read_req_t_setting_append_printf(f, ...) sbp_multipart_string_append_printf(s, 255, 2, 2, __VA_ARGS__)
#define sbp_msg_settings_read_req_t_setting_append_vprintf(f, fmt,ap) sbp_multipart_string_append_vprintf(s, 255, 2, 2, fmt, ap)
#define sbp_msg_settings_read_req_t_setting_count_sections(f) sbp_multipart_string_count_sections(f, 255, 2, 2)
#define sbp_msg_settings_read_req_t_setting_get_section(f,s) sbp_multipart_string_get_section(f,s,255, 2, 2)
#define sbp_msg_settings_read_req_t_setting_section_len(f,s) sbp_multipart_string_section_len(f,s,255, 2, 2)
#define sbp_msg_settings_read_req_t_setting_space_remaining(f) sbp_multipart_string_space_remaining(f,255, 2, 2)
#define sbp_msg_settings_read_req_t_setting_strcmp(a,b) sbp_multipart_string_strcmp(a,b,255, 2, 2)

size_t sbp_packed_size_sbp_msg_settings_read_req_t(const sbp_msg_settings_read_req_t *msg);
s8 sbp_pack_sbp_msg_settings_read_req_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_settings_read_req_t *msg);
s8 sbp_unpack_sbp_msg_settings_read_req_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_settings_read_req_t *msg);

int sbp_cmp_sbp_msg_settings_read_req_t(const sbp_msg_settings_read_req_t *a, const sbp_msg_settings_read_req_t *b);


/** Read device configuration settings (host <= device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_SETTINGS_READ_RESP          0x00A5
typedef struct {
  sbp_multipart_string_t setting;
} sbp_msg_settings_read_resp_t;
#define sbp_msg_settings_read_resp_t_setting_init(f) sbp_multipart_string_init(f, 255, 3, 3)
#define sbp_msg_settings_read_resp_t_setting_valid(f) sbp_multipart_string_valid(f, 255, 3, 3)
#define sbp_msg_settings_read_resp_t_setting_packed_len(f) sbp_multipart_string_packed_len(f, 255, 3, 3)
#define sbp_msg_settings_read_resp_t_setting_append(f,s) sbp_multipart_string_append(f, s, 255, 3, 3)
#define sbp_msg_settings_read_resp_t_setting_append_printf(f, ...) sbp_multipart_string_append_printf(s, 255, 3, 3, __VA_ARGS__)
#define sbp_msg_settings_read_resp_t_setting_append_vprintf(f, fmt,ap) sbp_multipart_string_append_vprintf(s, 255, 3, 3, fmt, ap)
#define sbp_msg_settings_read_resp_t_setting_count_sections(f) sbp_multipart_string_count_sections(f, 255, 3, 3)
#define sbp_msg_settings_read_resp_t_setting_get_section(f,s) sbp_multipart_string_get_section(f,s,255, 3, 3)
#define sbp_msg_settings_read_resp_t_setting_section_len(f,s) sbp_multipart_string_section_len(f,s,255, 3, 3)
#define sbp_msg_settings_read_resp_t_setting_space_remaining(f) sbp_multipart_string_space_remaining(f,255, 3, 3)
#define sbp_msg_settings_read_resp_t_setting_strcmp(a,b) sbp_multipart_string_strcmp(a,b,255, 3, 3)

size_t sbp_packed_size_sbp_msg_settings_read_resp_t(const sbp_msg_settings_read_resp_t *msg);
s8 sbp_pack_sbp_msg_settings_read_resp_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_settings_read_resp_t *msg);
s8 sbp_unpack_sbp_msg_settings_read_resp_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_settings_read_resp_t *msg);

int sbp_cmp_sbp_msg_settings_read_resp_t(const sbp_msg_settings_read_resp_t *a, const sbp_msg_settings_read_resp_t *b);


/** Read setting by direct index (host => device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_SETTINGS_READ_BY_INDEX_REQ  0x00A2
typedef struct {
  u16 index;
} sbp_msg_settings_read_by_index_req_t;

size_t sbp_packed_size_sbp_msg_settings_read_by_index_req_t(const sbp_msg_settings_read_by_index_req_t *msg);
s8 sbp_pack_sbp_msg_settings_read_by_index_req_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_settings_read_by_index_req_t *msg);
s8 sbp_unpack_sbp_msg_settings_read_by_index_req_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_settings_read_by_index_req_t *msg);

int sbp_cmp_sbp_msg_settings_read_by_index_req_t(const sbp_msg_settings_read_by_index_req_t *a, const sbp_msg_settings_read_by_index_req_t *b);


/** Read setting by direct index (host <= device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_SETTINGS_READ_BY_INDEX_RESP 0x00A7
typedef struct {
  u16 index;
  sbp_multipart_string_t setting;
} sbp_msg_settings_read_by_index_resp_t;
#define sbp_msg_settings_read_by_index_resp_t_setting_init(f) sbp_multipart_string_init(f, 253, 3, 4)
#define sbp_msg_settings_read_by_index_resp_t_setting_valid(f) sbp_multipart_string_valid(f, 253, 3, 4)
#define sbp_msg_settings_read_by_index_resp_t_setting_packed_len(f) sbp_multipart_string_packed_len(f, 253, 3, 4)
#define sbp_msg_settings_read_by_index_resp_t_setting_append(f,s) sbp_multipart_string_append(f, s, 253, 3, 4)
#define sbp_msg_settings_read_by_index_resp_t_setting_append_printf(f, ...) sbp_multipart_string_append_printf(s, 253, 3, 4, __VA_ARGS__)
#define sbp_msg_settings_read_by_index_resp_t_setting_append_vprintf(f, fmt,ap) sbp_multipart_string_append_vprintf(s, 253, 3, 4, fmt, ap)
#define sbp_msg_settings_read_by_index_resp_t_setting_count_sections(f) sbp_multipart_string_count_sections(f, 253, 3, 4)
#define sbp_msg_settings_read_by_index_resp_t_setting_get_section(f,s) sbp_multipart_string_get_section(f,s,253, 3, 4)
#define sbp_msg_settings_read_by_index_resp_t_setting_section_len(f,s) sbp_multipart_string_section_len(f,s,253, 3, 4)
#define sbp_msg_settings_read_by_index_resp_t_setting_space_remaining(f) sbp_multipart_string_space_remaining(f,253, 3, 4)
#define sbp_msg_settings_read_by_index_resp_t_setting_strcmp(a,b) sbp_multipart_string_strcmp(a,b,253, 3, 4)

size_t sbp_packed_size_sbp_msg_settings_read_by_index_resp_t(const sbp_msg_settings_read_by_index_resp_t *msg);
s8 sbp_pack_sbp_msg_settings_read_by_index_resp_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_settings_read_by_index_resp_t *msg);
s8 sbp_unpack_sbp_msg_settings_read_by_index_resp_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_settings_read_by_index_resp_t *msg);

int sbp_cmp_sbp_msg_settings_read_by_index_resp_t(const sbp_msg_settings_read_by_index_resp_t *a, const sbp_msg_settings_read_by_index_resp_t *b);


/** Finished reading settings (host <= device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_SETTINGS_READ_BY_INDEX_DONE 0x00A6
typedef struct {
  char DO_NOT_USE_dummy_field_to_prevent_empty_struct;
} sbp_msg_settings_read_by_index_done_t;

size_t sbp_packed_size_sbp_msg_settings_read_by_index_done_t(const sbp_msg_settings_read_by_index_done_t *msg);
s8 sbp_pack_sbp_msg_settings_read_by_index_done_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_settings_read_by_index_done_t *msg);
s8 sbp_unpack_sbp_msg_settings_read_by_index_done_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_settings_read_by_index_done_t *msg);

int sbp_cmp_sbp_msg_settings_read_by_index_done_t(const sbp_msg_settings_read_by_index_done_t *a, const sbp_msg_settings_read_by_index_done_t *b);


/** Register setting and default value (device => host)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_SETTINGS_REGISTER           0x00AE
typedef struct {
  sbp_multipart_string_t setting;
} sbp_msg_settings_register_t;
#define sbp_msg_settings_register_t_setting_init(f) sbp_multipart_string_init(f, 255, 3, 3)
#define sbp_msg_settings_register_t_setting_valid(f) sbp_multipart_string_valid(f, 255, 3, 3)
#define sbp_msg_settings_register_t_setting_packed_len(f) sbp_multipart_string_packed_len(f, 255, 3, 3)
#define sbp_msg_settings_register_t_setting_append(f,s) sbp_multipart_string_append(f, s, 255, 3, 3)
#define sbp_msg_settings_register_t_setting_append_printf(f, ...) sbp_multipart_string_append_printf(s, 255, 3, 3, __VA_ARGS__)
#define sbp_msg_settings_register_t_setting_append_vprintf(f, fmt,ap) sbp_multipart_string_append_vprintf(s, 255, 3, 3, fmt, ap)
#define sbp_msg_settings_register_t_setting_count_sections(f) sbp_multipart_string_count_sections(f, 255, 3, 3)
#define sbp_msg_settings_register_t_setting_get_section(f,s) sbp_multipart_string_get_section(f,s,255, 3, 3)
#define sbp_msg_settings_register_t_setting_section_len(f,s) sbp_multipart_string_section_len(f,s,255, 3, 3)
#define sbp_msg_settings_register_t_setting_space_remaining(f) sbp_multipart_string_space_remaining(f,255, 3, 3)
#define sbp_msg_settings_register_t_setting_strcmp(a,b) sbp_multipart_string_strcmp(a,b,255, 3, 3)

size_t sbp_packed_size_sbp_msg_settings_register_t(const sbp_msg_settings_register_t *msg);
s8 sbp_pack_sbp_msg_settings_register_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_settings_register_t *msg);
s8 sbp_unpack_sbp_msg_settings_register_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_settings_register_t *msg);

int sbp_cmp_sbp_msg_settings_register_t(const sbp_msg_settings_register_t *a, const sbp_msg_settings_register_t *b);


#define SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_MASK (0x3)
#define SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_SHIFT (0u)
#define SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_GET(flags) \
                             (((flags) >> SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_SHIFT) \
                             & SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_MASK)
#define SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_MASK)) \
                             << (SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_SHIFT)));} while(0)
                             

#define SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_ACCEPTED_REQUESTED_DEFAULT_VALUE_RETURNED (0)
#define SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_ACCEPTED_SETTING_FOUND_IN_PERMANENT_STORAGE_VALUE_FROM_STORAGE_RETURNED (1)
#define SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_REJECTED_SETTING_ALREADY_REGISTERED_VALUE_FROM_MEMORY_RETURNED (2)
#define SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_REJECTED_MALFORMED_MESSAGE (3)
/** Register setting and default value (device <= host)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_SETTINGS_REGISTER_RESP      0x01AF
typedef struct {
  u8 status;
  sbp_multipart_string_t setting;
} sbp_msg_settings_register_resp_t;
#define sbp_msg_settings_register_resp_t_setting_init(f) sbp_multipart_string_init(f, 254, 3, 3)
#define sbp_msg_settings_register_resp_t_setting_valid(f) sbp_multipart_string_valid(f, 254, 3, 3)
#define sbp_msg_settings_register_resp_t_setting_packed_len(f) sbp_multipart_string_packed_len(f, 254, 3, 3)
#define sbp_msg_settings_register_resp_t_setting_append(f,s) sbp_multipart_string_append(f, s, 254, 3, 3)
#define sbp_msg_settings_register_resp_t_setting_append_printf(f, ...) sbp_multipart_string_append_printf(s, 254, 3, 3, __VA_ARGS__)
#define sbp_msg_settings_register_resp_t_setting_append_vprintf(f, fmt,ap) sbp_multipart_string_append_vprintf(s, 254, 3, 3, fmt, ap)
#define sbp_msg_settings_register_resp_t_setting_count_sections(f) sbp_multipart_string_count_sections(f, 254, 3, 3)
#define sbp_msg_settings_register_resp_t_setting_get_section(f,s) sbp_multipart_string_get_section(f,s,254, 3, 3)
#define sbp_msg_settings_register_resp_t_setting_section_len(f,s) sbp_multipart_string_section_len(f,s,254, 3, 3)
#define sbp_msg_settings_register_resp_t_setting_space_remaining(f) sbp_multipart_string_space_remaining(f,254, 3, 3)
#define sbp_msg_settings_register_resp_t_setting_strcmp(a,b) sbp_multipart_string_strcmp(a,b,254, 3, 3)

size_t sbp_packed_size_sbp_msg_settings_register_resp_t(const sbp_msg_settings_register_resp_t *msg);
s8 sbp_pack_sbp_msg_settings_register_resp_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_settings_register_resp_t *msg);
s8 sbp_unpack_sbp_msg_settings_register_resp_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_settings_register_resp_t *msg);

int sbp_cmp_sbp_msg_settings_register_resp_t(const sbp_msg_settings_register_resp_t *a, const sbp_msg_settings_register_resp_t *b);



#ifdef __cplusplus
  }
static inline bool operator==(const sbp_msg_settings_save_t &a, const sbp_msg_settings_save_t &b) {
  return sbp_cmp_sbp_msg_settings_save_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_settings_save_t &a, const sbp_msg_settings_save_t &b) {
  return sbp_cmp_sbp_msg_settings_save_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_settings_save_t &a, const sbp_msg_settings_save_t &b) {
  return sbp_cmp_sbp_msg_settings_save_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_settings_save_t &a, const sbp_msg_settings_save_t &b) {
  return sbp_cmp_sbp_msg_settings_save_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_settings_save_t &a, const sbp_msg_settings_save_t &b) {
  return sbp_cmp_sbp_msg_settings_save_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_settings_save_t &a, const sbp_msg_settings_save_t &b) {
  return sbp_cmp_sbp_msg_settings_save_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_settings_write_t &a, const sbp_msg_settings_write_t &b) {
  return sbp_cmp_sbp_msg_settings_write_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_settings_write_t &a, const sbp_msg_settings_write_t &b) {
  return sbp_cmp_sbp_msg_settings_write_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_settings_write_t &a, const sbp_msg_settings_write_t &b) {
  return sbp_cmp_sbp_msg_settings_write_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_settings_write_t &a, const sbp_msg_settings_write_t &b) {
  return sbp_cmp_sbp_msg_settings_write_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_settings_write_t &a, const sbp_msg_settings_write_t &b) {
  return sbp_cmp_sbp_msg_settings_write_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_settings_write_t &a, const sbp_msg_settings_write_t &b) {
  return sbp_cmp_sbp_msg_settings_write_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_settings_write_resp_t &a, const sbp_msg_settings_write_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_write_resp_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_settings_write_resp_t &a, const sbp_msg_settings_write_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_write_resp_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_settings_write_resp_t &a, const sbp_msg_settings_write_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_write_resp_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_settings_write_resp_t &a, const sbp_msg_settings_write_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_write_resp_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_settings_write_resp_t &a, const sbp_msg_settings_write_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_write_resp_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_settings_write_resp_t &a, const sbp_msg_settings_write_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_write_resp_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_settings_read_req_t &a, const sbp_msg_settings_read_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_req_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_settings_read_req_t &a, const sbp_msg_settings_read_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_req_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_settings_read_req_t &a, const sbp_msg_settings_read_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_req_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_settings_read_req_t &a, const sbp_msg_settings_read_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_req_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_settings_read_req_t &a, const sbp_msg_settings_read_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_req_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_settings_read_req_t &a, const sbp_msg_settings_read_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_req_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_settings_read_resp_t &a, const sbp_msg_settings_read_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_resp_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_settings_read_resp_t &a, const sbp_msg_settings_read_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_resp_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_settings_read_resp_t &a, const sbp_msg_settings_read_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_resp_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_settings_read_resp_t &a, const sbp_msg_settings_read_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_resp_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_settings_read_resp_t &a, const sbp_msg_settings_read_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_resp_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_settings_read_resp_t &a, const sbp_msg_settings_read_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_resp_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_settings_read_by_index_req_t &a, const sbp_msg_settings_read_by_index_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_req_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_settings_read_by_index_req_t &a, const sbp_msg_settings_read_by_index_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_req_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_settings_read_by_index_req_t &a, const sbp_msg_settings_read_by_index_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_req_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_settings_read_by_index_req_t &a, const sbp_msg_settings_read_by_index_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_req_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_settings_read_by_index_req_t &a, const sbp_msg_settings_read_by_index_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_req_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_settings_read_by_index_req_t &a, const sbp_msg_settings_read_by_index_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_req_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_settings_read_by_index_resp_t &a, const sbp_msg_settings_read_by_index_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_resp_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_settings_read_by_index_resp_t &a, const sbp_msg_settings_read_by_index_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_resp_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_settings_read_by_index_resp_t &a, const sbp_msg_settings_read_by_index_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_resp_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_settings_read_by_index_resp_t &a, const sbp_msg_settings_read_by_index_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_resp_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_settings_read_by_index_resp_t &a, const sbp_msg_settings_read_by_index_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_resp_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_settings_read_by_index_resp_t &a, const sbp_msg_settings_read_by_index_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_resp_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_settings_read_by_index_done_t &a, const sbp_msg_settings_read_by_index_done_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_done_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_settings_read_by_index_done_t &a, const sbp_msg_settings_read_by_index_done_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_done_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_settings_read_by_index_done_t &a, const sbp_msg_settings_read_by_index_done_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_done_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_settings_read_by_index_done_t &a, const sbp_msg_settings_read_by_index_done_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_done_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_settings_read_by_index_done_t &a, const sbp_msg_settings_read_by_index_done_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_done_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_settings_read_by_index_done_t &a, const sbp_msg_settings_read_by_index_done_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_done_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_settings_register_t &a, const sbp_msg_settings_register_t &b) {
  return sbp_cmp_sbp_msg_settings_register_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_settings_register_t &a, const sbp_msg_settings_register_t &b) {
  return sbp_cmp_sbp_msg_settings_register_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_settings_register_t &a, const sbp_msg_settings_register_t &b) {
  return sbp_cmp_sbp_msg_settings_register_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_settings_register_t &a, const sbp_msg_settings_register_t &b) {
  return sbp_cmp_sbp_msg_settings_register_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_settings_register_t &a, const sbp_msg_settings_register_t &b) {
  return sbp_cmp_sbp_msg_settings_register_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_settings_register_t &a, const sbp_msg_settings_register_t &b) {
  return sbp_cmp_sbp_msg_settings_register_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_settings_register_resp_t &a, const sbp_msg_settings_register_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_register_resp_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_settings_register_resp_t &a, const sbp_msg_settings_register_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_register_resp_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_settings_register_resp_t &a, const sbp_msg_settings_register_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_register_resp_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_settings_register_resp_t &a, const sbp_msg_settings_register_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_register_resp_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_settings_register_resp_t &a, const sbp_msg_settings_register_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_register_resp_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_settings_register_resp_t &a, const sbp_msg_settings_register_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_register_resp_t(&a, &b) >= 0;
}

#endif

#endif /* LIBSBP_SETTINGS_MESSAGES_H */