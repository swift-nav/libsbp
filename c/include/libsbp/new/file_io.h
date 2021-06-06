#ifndef LIBSBP_FILE_IO_MESSAGES_H
#define LIBSBP_FILE_IO_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/new/string/multipart.h>
#include <libsbp/new/string/double_null_terminated.h>
#include <libsbp/new/string/unterminated.h>
#include <libsbp/new/string/null_terminated.h>

#ifdef __cplusplus
  extern "C" {
#endif

struct sbp_state;
/** Read file from the file system (host => device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_FILEIO_READ_REQ      0x00A8
typedef struct {
  u32 sequence;
  u32 offset;
  u8 chunk_size;
  sbp_null_terminated_string_t filename;
} sbp_msg_fileio_read_req_t;
  void sbp_msg_fileio_read_req_t_filename_init(sbp_null_terminated_string_t *s);
  bool sbp_msg_fileio_read_req_t_filename_valid(const sbp_null_terminated_string_t *s);
  int sbp_msg_fileio_read_req_t_filename_strcmp(const sbp_null_terminated_string_t *a, const sbp_null_terminated_string_t *b);
  uint8_t sbp_msg_fileio_read_req_t_filename_packed_len(const sbp_null_terminated_string_t *s);
  uint8_t sbp_msg_fileio_read_req_t_filename_space_remaining(const sbp_null_terminated_string_t *s);
  bool sbp_msg_fileio_read_req_t_filename_set(sbp_null_terminated_string_t *s, const char *new_str);
  bool sbp_msg_fileio_read_req_t_filename_printf(sbp_null_terminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_fileio_read_req_t_filename_vprintf(sbp_null_terminated_string_t *s, const char *fmt, va_list ap);
  bool sbp_msg_fileio_read_req_t_filename_append_printf(sbp_null_terminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_fileio_read_req_t_filename_append_vprintf(sbp_null_terminated_string_t *s, const char *fmt, va_list ap);
  const char *sbp_msg_fileio_read_req_t_filename_get(const sbp_null_terminated_string_t *s);

size_t sbp_packed_size_sbp_msg_fileio_read_req_t(const sbp_msg_fileio_read_req_t *msg);
s8 sbp_encode_sbp_msg_fileio_read_req_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_fileio_read_req_t *msg);
s8 sbp_decode_sbp_msg_fileio_read_req_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_fileio_read_req_t *msg);
s8 sbp_send_sbp_msg_fileio_read_req_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_fileio_read_req_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_fileio_read_req_t(const sbp_msg_fileio_read_req_t *a, const sbp_msg_fileio_read_req_t *b);


/** File read from the file system (host <= device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_FILEIO_READ_RESP     0x00A3
typedef struct {
  u32 sequence;
  u8 contents[251];
  u8 n_contents;
} sbp_msg_fileio_read_resp_t;

size_t sbp_packed_size_sbp_msg_fileio_read_resp_t(const sbp_msg_fileio_read_resp_t *msg);
s8 sbp_encode_sbp_msg_fileio_read_resp_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_fileio_read_resp_t *msg);
s8 sbp_decode_sbp_msg_fileio_read_resp_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_fileio_read_resp_t *msg);
s8 sbp_send_sbp_msg_fileio_read_resp_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_fileio_read_resp_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_fileio_read_resp_t(const sbp_msg_fileio_read_resp_t *a, const sbp_msg_fileio_read_resp_t *b);


/** List files in a directory (host => device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_FILEIO_READ_DIR_REQ  0x00A9
typedef struct {
  u32 sequence;
  u32 offset;
  sbp_null_terminated_string_t dirname;
} sbp_msg_fileio_read_dir_req_t;
  void sbp_msg_fileio_read_dir_req_t_dirname_init(sbp_null_terminated_string_t *s);
  bool sbp_msg_fileio_read_dir_req_t_dirname_valid(const sbp_null_terminated_string_t *s);
  int sbp_msg_fileio_read_dir_req_t_dirname_strcmp(const sbp_null_terminated_string_t *a, const sbp_null_terminated_string_t *b);
  uint8_t sbp_msg_fileio_read_dir_req_t_dirname_packed_len(const sbp_null_terminated_string_t *s);
  uint8_t sbp_msg_fileio_read_dir_req_t_dirname_space_remaining(const sbp_null_terminated_string_t *s);
  bool sbp_msg_fileio_read_dir_req_t_dirname_set(sbp_null_terminated_string_t *s, const char *new_str);
  bool sbp_msg_fileio_read_dir_req_t_dirname_printf(sbp_null_terminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_fileio_read_dir_req_t_dirname_vprintf(sbp_null_terminated_string_t *s, const char *fmt, va_list ap);
  bool sbp_msg_fileio_read_dir_req_t_dirname_append_printf(sbp_null_terminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_fileio_read_dir_req_t_dirname_append_vprintf(sbp_null_terminated_string_t *s, const char *fmt, va_list ap);
  const char *sbp_msg_fileio_read_dir_req_t_dirname_get(const sbp_null_terminated_string_t *s);

size_t sbp_packed_size_sbp_msg_fileio_read_dir_req_t(const sbp_msg_fileio_read_dir_req_t *msg);
s8 sbp_encode_sbp_msg_fileio_read_dir_req_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_fileio_read_dir_req_t *msg);
s8 sbp_decode_sbp_msg_fileio_read_dir_req_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_fileio_read_dir_req_t *msg);
s8 sbp_send_sbp_msg_fileio_read_dir_req_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_fileio_read_dir_req_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_fileio_read_dir_req_t(const sbp_msg_fileio_read_dir_req_t *a, const sbp_msg_fileio_read_dir_req_t *b);


/** Files listed in a directory (host <= device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_FILEIO_READ_DIR_RESP 0x00AA
typedef struct {
  u32 sequence;
  sbp_multipart_string_t contents;
} sbp_msg_fileio_read_dir_resp_t;
  void sbp_msg_fileio_read_dir_resp_t_contents_init(sbp_multipart_string_t *s);
  bool sbp_msg_fileio_read_dir_resp_t_contents_valid(const sbp_multipart_string_t *s);
  int sbp_msg_fileio_read_dir_resp_t_contents_strcmp(const sbp_multipart_string_t *a, const sbp_multipart_string_t *b);
  uint8_t sbp_msg_fileio_read_dir_resp_t_contents_packed_len(const sbp_multipart_string_t *s);
  uint8_t sbp_msg_fileio_read_dir_resp_t_contents_space_remaining(const sbp_multipart_string_t *s);
  uint8_t sbp_msg_fileio_read_dir_resp_t_contents_count_sections(const sbp_multipart_string_t *s);
  bool sbp_msg_fileio_read_dir_resp_t_contents_add_section(sbp_multipart_string_t *s, const char *new_str);
  bool sbp_msg_fileio_read_dir_resp_t_contents_add_section_printf(sbp_multipart_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_fileio_read_dir_resp_t_contents_add_section_vprintf(sbp_multipart_string_t *s, const char *fmt, va_list ap);
  bool sbp_msg_fileio_read_dir_resp_t_contents_append(sbp_multipart_string_t *s, const char *str);
  bool sbp_msg_fileio_read_dir_resp_t_contents_append_printf(sbp_multipart_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_fileio_read_dir_resp_t_contents_append_vprintf(sbp_multipart_string_t *s, const char *fmt, va_list ap);
  const char *sbp_msg_fileio_read_dir_resp_t_contents_get_section(const sbp_multipart_string_t *s, uint8_t section);
  uint8_t sbp_msg_fileio_read_dir_resp_t_contents_section_strlen(const sbp_multipart_string_t *s, uint8_t section);

size_t sbp_packed_size_sbp_msg_fileio_read_dir_resp_t(const sbp_msg_fileio_read_dir_resp_t *msg);
s8 sbp_encode_sbp_msg_fileio_read_dir_resp_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_fileio_read_dir_resp_t *msg);
s8 sbp_decode_sbp_msg_fileio_read_dir_resp_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_fileio_read_dir_resp_t *msg);
s8 sbp_send_sbp_msg_fileio_read_dir_resp_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_fileio_read_dir_resp_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_fileio_read_dir_resp_t(const sbp_msg_fileio_read_dir_resp_t *a, const sbp_msg_fileio_read_dir_resp_t *b);


/** Delete a file from the file system (host => device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_FILEIO_REMOVE        0x00AC
typedef struct {
  sbp_null_terminated_string_t filename;
} sbp_msg_fileio_remove_t;
  void sbp_msg_fileio_remove_t_filename_init(sbp_null_terminated_string_t *s);
  bool sbp_msg_fileio_remove_t_filename_valid(const sbp_null_terminated_string_t *s);
  int sbp_msg_fileio_remove_t_filename_strcmp(const sbp_null_terminated_string_t *a, const sbp_null_terminated_string_t *b);
  uint8_t sbp_msg_fileio_remove_t_filename_packed_len(const sbp_null_terminated_string_t *s);
  uint8_t sbp_msg_fileio_remove_t_filename_space_remaining(const sbp_null_terminated_string_t *s);
  bool sbp_msg_fileio_remove_t_filename_set(sbp_null_terminated_string_t *s, const char *new_str);
  bool sbp_msg_fileio_remove_t_filename_printf(sbp_null_terminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_fileio_remove_t_filename_vprintf(sbp_null_terminated_string_t *s, const char *fmt, va_list ap);
  bool sbp_msg_fileio_remove_t_filename_append_printf(sbp_null_terminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_fileio_remove_t_filename_append_vprintf(sbp_null_terminated_string_t *s, const char *fmt, va_list ap);
  const char *sbp_msg_fileio_remove_t_filename_get(const sbp_null_terminated_string_t *s);

size_t sbp_packed_size_sbp_msg_fileio_remove_t(const sbp_msg_fileio_remove_t *msg);
s8 sbp_encode_sbp_msg_fileio_remove_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_fileio_remove_t *msg);
s8 sbp_decode_sbp_msg_fileio_remove_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_fileio_remove_t *msg);
s8 sbp_send_sbp_msg_fileio_remove_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_fileio_remove_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_fileio_remove_t(const sbp_msg_fileio_remove_t *a, const sbp_msg_fileio_remove_t *b);


/** Write to file (host => device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_FILEIO_WRITE_REQ     0x00AD
typedef struct {
  u32 sequence;
  u32 offset;
  sbp_null_terminated_string_t filename;
  u8 data[247];
  u8 n_data;
} sbp_msg_fileio_write_req_t;
  void sbp_msg_fileio_write_req_t_filename_init(sbp_null_terminated_string_t *s);
  bool sbp_msg_fileio_write_req_t_filename_valid(const sbp_null_terminated_string_t *s);
  int sbp_msg_fileio_write_req_t_filename_strcmp(const sbp_null_terminated_string_t *a, const sbp_null_terminated_string_t *b);
  uint8_t sbp_msg_fileio_write_req_t_filename_packed_len(const sbp_null_terminated_string_t *s);
  uint8_t sbp_msg_fileio_write_req_t_filename_space_remaining(const sbp_null_terminated_string_t *s);
  bool sbp_msg_fileio_write_req_t_filename_set(sbp_null_terminated_string_t *s, const char *new_str);
  bool sbp_msg_fileio_write_req_t_filename_printf(sbp_null_terminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_fileio_write_req_t_filename_vprintf(sbp_null_terminated_string_t *s, const char *fmt, va_list ap);
  bool sbp_msg_fileio_write_req_t_filename_append_printf(sbp_null_terminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_fileio_write_req_t_filename_append_vprintf(sbp_null_terminated_string_t *s, const char *fmt, va_list ap);
  const char *sbp_msg_fileio_write_req_t_filename_get(const sbp_null_terminated_string_t *s);

size_t sbp_packed_size_sbp_msg_fileio_write_req_t(const sbp_msg_fileio_write_req_t *msg);
s8 sbp_encode_sbp_msg_fileio_write_req_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_fileio_write_req_t *msg);
s8 sbp_decode_sbp_msg_fileio_write_req_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_fileio_write_req_t *msg);
s8 sbp_send_sbp_msg_fileio_write_req_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_fileio_write_req_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_fileio_write_req_t(const sbp_msg_fileio_write_req_t *a, const sbp_msg_fileio_write_req_t *b);


/** File written to (host <= device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_FILEIO_WRITE_RESP    0x00AB
typedef struct {
  u32 sequence;
} sbp_msg_fileio_write_resp_t;

size_t sbp_packed_size_sbp_msg_fileio_write_resp_t(const sbp_msg_fileio_write_resp_t *msg);
s8 sbp_encode_sbp_msg_fileio_write_resp_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_fileio_write_resp_t *msg);
s8 sbp_decode_sbp_msg_fileio_write_resp_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_fileio_write_resp_t *msg);
s8 sbp_send_sbp_msg_fileio_write_resp_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_fileio_write_resp_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_fileio_write_resp_t(const sbp_msg_fileio_write_resp_t *a, const sbp_msg_fileio_write_resp_t *b);


/** Request advice on the optimal configuration for FileIO
 *
((m.desc|commentify)))
 */
#define SBP_MSG_FILEIO_CONFIG_REQ    0x1001
typedef struct {
  u32 sequence;
} sbp_msg_fileio_config_req_t;

size_t sbp_packed_size_sbp_msg_fileio_config_req_t(const sbp_msg_fileio_config_req_t *msg);
s8 sbp_encode_sbp_msg_fileio_config_req_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_fileio_config_req_t *msg);
s8 sbp_decode_sbp_msg_fileio_config_req_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_fileio_config_req_t *msg);
s8 sbp_send_sbp_msg_fileio_config_req_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_fileio_config_req_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_fileio_config_req_t(const sbp_msg_fileio_config_req_t *a, const sbp_msg_fileio_config_req_t *b);


/** Response with advice on the optimal configuration for FileIO.

 *
((m.desc|commentify)))
 */
#define SBP_MSG_FILEIO_CONFIG_RESP   0x1002
typedef struct {
  u32 sequence;
  u32 window_size;
  u32 batch_size;
  u32 fileio_version;
} sbp_msg_fileio_config_resp_t;

size_t sbp_packed_size_sbp_msg_fileio_config_resp_t(const sbp_msg_fileio_config_resp_t *msg);
s8 sbp_encode_sbp_msg_fileio_config_resp_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_fileio_config_resp_t *msg);
s8 sbp_decode_sbp_msg_fileio_config_resp_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_fileio_config_resp_t *msg);
s8 sbp_send_sbp_msg_fileio_config_resp_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_fileio_config_resp_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_fileio_config_resp_t(const sbp_msg_fileio_config_resp_t *a, const sbp_msg_fileio_config_resp_t *b);



#ifdef __cplusplus
  }
static inline bool operator==(const sbp_msg_fileio_read_req_t &a, const sbp_msg_fileio_read_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_req_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_fileio_read_req_t &a, const sbp_msg_fileio_read_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_req_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_fileio_read_req_t &a, const sbp_msg_fileio_read_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_req_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_fileio_read_req_t &a, const sbp_msg_fileio_read_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_req_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_fileio_read_req_t &a, const sbp_msg_fileio_read_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_req_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_fileio_read_req_t &a, const sbp_msg_fileio_read_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_req_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_fileio_read_resp_t &a, const sbp_msg_fileio_read_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_resp_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_fileio_read_resp_t &a, const sbp_msg_fileio_read_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_resp_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_fileio_read_resp_t &a, const sbp_msg_fileio_read_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_resp_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_fileio_read_resp_t &a, const sbp_msg_fileio_read_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_resp_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_fileio_read_resp_t &a, const sbp_msg_fileio_read_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_resp_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_fileio_read_resp_t &a, const sbp_msg_fileio_read_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_resp_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_fileio_read_dir_req_t &a, const sbp_msg_fileio_read_dir_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_dir_req_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_fileio_read_dir_req_t &a, const sbp_msg_fileio_read_dir_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_dir_req_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_fileio_read_dir_req_t &a, const sbp_msg_fileio_read_dir_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_dir_req_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_fileio_read_dir_req_t &a, const sbp_msg_fileio_read_dir_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_dir_req_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_fileio_read_dir_req_t &a, const sbp_msg_fileio_read_dir_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_dir_req_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_fileio_read_dir_req_t &a, const sbp_msg_fileio_read_dir_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_dir_req_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_fileio_read_dir_resp_t &a, const sbp_msg_fileio_read_dir_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_dir_resp_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_fileio_read_dir_resp_t &a, const sbp_msg_fileio_read_dir_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_dir_resp_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_fileio_read_dir_resp_t &a, const sbp_msg_fileio_read_dir_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_dir_resp_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_fileio_read_dir_resp_t &a, const sbp_msg_fileio_read_dir_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_dir_resp_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_fileio_read_dir_resp_t &a, const sbp_msg_fileio_read_dir_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_dir_resp_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_fileio_read_dir_resp_t &a, const sbp_msg_fileio_read_dir_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_dir_resp_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_fileio_remove_t &a, const sbp_msg_fileio_remove_t &b) {
  return sbp_cmp_sbp_msg_fileio_remove_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_fileio_remove_t &a, const sbp_msg_fileio_remove_t &b) {
  return sbp_cmp_sbp_msg_fileio_remove_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_fileio_remove_t &a, const sbp_msg_fileio_remove_t &b) {
  return sbp_cmp_sbp_msg_fileio_remove_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_fileio_remove_t &a, const sbp_msg_fileio_remove_t &b) {
  return sbp_cmp_sbp_msg_fileio_remove_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_fileio_remove_t &a, const sbp_msg_fileio_remove_t &b) {
  return sbp_cmp_sbp_msg_fileio_remove_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_fileio_remove_t &a, const sbp_msg_fileio_remove_t &b) {
  return sbp_cmp_sbp_msg_fileio_remove_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_fileio_write_req_t &a, const sbp_msg_fileio_write_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_write_req_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_fileio_write_req_t &a, const sbp_msg_fileio_write_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_write_req_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_fileio_write_req_t &a, const sbp_msg_fileio_write_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_write_req_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_fileio_write_req_t &a, const sbp_msg_fileio_write_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_write_req_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_fileio_write_req_t &a, const sbp_msg_fileio_write_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_write_req_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_fileio_write_req_t &a, const sbp_msg_fileio_write_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_write_req_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_fileio_write_resp_t &a, const sbp_msg_fileio_write_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_write_resp_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_fileio_write_resp_t &a, const sbp_msg_fileio_write_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_write_resp_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_fileio_write_resp_t &a, const sbp_msg_fileio_write_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_write_resp_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_fileio_write_resp_t &a, const sbp_msg_fileio_write_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_write_resp_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_fileio_write_resp_t &a, const sbp_msg_fileio_write_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_write_resp_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_fileio_write_resp_t &a, const sbp_msg_fileio_write_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_write_resp_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_fileio_config_req_t &a, const sbp_msg_fileio_config_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_config_req_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_fileio_config_req_t &a, const sbp_msg_fileio_config_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_config_req_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_fileio_config_req_t &a, const sbp_msg_fileio_config_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_config_req_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_fileio_config_req_t &a, const sbp_msg_fileio_config_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_config_req_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_fileio_config_req_t &a, const sbp_msg_fileio_config_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_config_req_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_fileio_config_req_t &a, const sbp_msg_fileio_config_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_config_req_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_fileio_config_resp_t &a, const sbp_msg_fileio_config_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_config_resp_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_fileio_config_resp_t &a, const sbp_msg_fileio_config_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_config_resp_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_fileio_config_resp_t &a, const sbp_msg_fileio_config_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_config_resp_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_fileio_config_resp_t &a, const sbp_msg_fileio_config_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_config_resp_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_fileio_config_resp_t &a, const sbp_msg_fileio_config_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_config_resp_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_fileio_config_resp_t &a, const sbp_msg_fileio_config_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_config_resp_t(&a, &b) >= 0;
}

#endif

#endif /* LIBSBP_FILE_IO_MESSAGES_H */
