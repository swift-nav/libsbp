#ifndef LIBSBP_LOGGING_MESSAGES_H
#define LIBSBP_LOGGING_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/string/multipart.h>
#include <libsbp/unpacked/string/double_null_terminated.h>
#include <libsbp/unpacked/string/unterminated.h>
#include <libsbp/unpacked/string/null_terminated.h>
#include <libsbp/unpacked/string/binary.h>

#ifdef __cplusplus
  extern "C" {
#endif
#define SBP_LOG_LOGGING_LEVEL_MASK (0x7)
#define SBP_LOG_LOGGING_LEVEL_SHIFT (0u)
#define SBP_LOG_LOGGING_LEVEL_GET(flags) \
                             (((flags) >> SBP_LOG_LOGGING_LEVEL_SHIFT) \
                             & SBP_LOG_LOGGING_LEVEL_MASK)
#define SBP_LOG_LOGGING_LEVEL_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_LOG_LOGGING_LEVEL_MASK)) \
                             << (SBP_LOG_LOGGING_LEVEL_SHIFT)));} while(0)
                             

#define SBP_LOG_LOGGING_LEVEL_EMERG (0)
#define SBP_LOG_LOGGING_LEVEL_ALERT (1)
#define SBP_LOG_LOGGING_LEVEL_CRIT (2)
#define SBP_LOG_LOGGING_LEVEL_ERROR (3)
#define SBP_LOG_LOGGING_LEVEL_WARN (4)
#define SBP_LOG_LOGGING_LEVEL_NOTICE (5)
#define SBP_LOG_LOGGING_LEVEL_INFO (6)
#define SBP_LOG_LOGGING_LEVEL_DEBUG (7)
/** Plaintext logging messages with levels
 *
((m.desc|commentify)))
 */
#define SBP_MSG_LOG       0x0401
typedef struct {
  u8 level;
  sbp_unterminated_string_t text;
} sbp_msg_log_t;
  void sbp_msg_log_t_text_init(sbp_unterminated_string_t *s);
  bool sbp_msg_log_t_text_valid(const sbp_unterminated_string_t *s);
  int sbp_msg_log_t_text_strcmp(const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b);
  uint8_t sbp_msg_log_t_text_packed_len(const sbp_unterminated_string_t *s);
  uint8_t sbp_msg_log_t_text_space_remaining(const sbp_unterminated_string_t *s);
  bool sbp_msg_log_t_text_set(sbp_unterminated_string_t *s, const char *new_str);
  bool sbp_msg_log_t_text_printf(sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_log_t_text_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap);
  bool sbp_msg_log_t_text_append_printf(sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_log_t_text_append_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap);
  const char *sbp_msg_log_t_text_get(const sbp_unterminated_string_t *s);

size_t sbp_packed_size_sbp_msg_log_t(const sbp_msg_log_t *msg);
s8 sbp_pack_sbp_msg_log_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_log_t *msg);
s8 sbp_unpack_sbp_msg_log_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_log_t *msg);

int sbp_cmp_sbp_msg_log_t(const sbp_msg_log_t *a, const sbp_msg_log_t *b);


/** Wrapper for FWD a separate stream of information over SBP
 *
((m.desc|commentify)))
 */
#define SBP_MSG_FWD       0x0402
typedef struct {
  u8 source;
  u8 protocol;
  sbp_binary_string_t fwd_payload;
} sbp_msg_fwd_t;
  void sbp_msg_fwd_t_fwd_payload_init(sbp_binary_string_t *s);
  bool sbp_msg_fwd_t_fwd_payload_valid(const sbp_binary_string_t *s);
  int sbp_msg_fwd_t_fwd_payload_strcmp(const sbp_binary_string_t *a, const sbp_binary_string_t *b);
  uint8_t sbp_msg_fwd_t_fwd_payload_packed_len(const sbp_binary_string_t *s);
  uint8_t sbp_msg_fwd_t_fwd_payload_space_remaining(const sbp_binary_string_t *s);
  bool sbp_msg_fwd_t_fwd_payload_set(sbp_binary_string_t *s, const char *new_str, uint8_t new_str_len);
  bool sbp_msg_fwd_t_fwd_payload_get(const sbp_binary_string_t *s, uint8_t *str_len);

size_t sbp_packed_size_sbp_msg_fwd_t(const sbp_msg_fwd_t *msg);
s8 sbp_pack_sbp_msg_fwd_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_fwd_t *msg);
s8 sbp_unpack_sbp_msg_fwd_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_fwd_t *msg);

int sbp_cmp_sbp_msg_fwd_t(const sbp_msg_fwd_t *a, const sbp_msg_fwd_t *b);


/** Deprecated
 *
((m.desc|commentify)))
 */
#define SBP_MSG_PRINT_DEP 0x0010
typedef struct {
  sbp_unterminated_string_t text;
} sbp_msg_print_dep_t;
  void sbp_msg_print_dep_t_text_init(sbp_unterminated_string_t *s);
  bool sbp_msg_print_dep_t_text_valid(const sbp_unterminated_string_t *s);
  int sbp_msg_print_dep_t_text_strcmp(const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b);
  uint8_t sbp_msg_print_dep_t_text_packed_len(const sbp_unterminated_string_t *s);
  uint8_t sbp_msg_print_dep_t_text_space_remaining(const sbp_unterminated_string_t *s);
  bool sbp_msg_print_dep_t_text_set(sbp_unterminated_string_t *s, const char *new_str);
  bool sbp_msg_print_dep_t_text_printf(sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_print_dep_t_text_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap);
  bool sbp_msg_print_dep_t_text_append_printf(sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_print_dep_t_text_append_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap);
  const char *sbp_msg_print_dep_t_text_get(const sbp_unterminated_string_t *s);

size_t sbp_packed_size_sbp_msg_print_dep_t(const sbp_msg_print_dep_t *msg);
s8 sbp_pack_sbp_msg_print_dep_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_print_dep_t *msg);
s8 sbp_unpack_sbp_msg_print_dep_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_print_dep_t *msg);

int sbp_cmp_sbp_msg_print_dep_t(const sbp_msg_print_dep_t *a, const sbp_msg_print_dep_t *b);



#ifdef __cplusplus
  }
static inline bool operator==(const sbp_msg_log_t &a, const sbp_msg_log_t &b) {
  return sbp_cmp_sbp_msg_log_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_log_t &a, const sbp_msg_log_t &b) {
  return sbp_cmp_sbp_msg_log_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_log_t &a, const sbp_msg_log_t &b) {
  return sbp_cmp_sbp_msg_log_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_log_t &a, const sbp_msg_log_t &b) {
  return sbp_cmp_sbp_msg_log_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_log_t &a, const sbp_msg_log_t &b) {
  return sbp_cmp_sbp_msg_log_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_log_t &a, const sbp_msg_log_t &b) {
  return sbp_cmp_sbp_msg_log_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_fwd_t &a, const sbp_msg_fwd_t &b) {
  return sbp_cmp_sbp_msg_fwd_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_fwd_t &a, const sbp_msg_fwd_t &b) {
  return sbp_cmp_sbp_msg_fwd_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_fwd_t &a, const sbp_msg_fwd_t &b) {
  return sbp_cmp_sbp_msg_fwd_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_fwd_t &a, const sbp_msg_fwd_t &b) {
  return sbp_cmp_sbp_msg_fwd_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_fwd_t &a, const sbp_msg_fwd_t &b) {
  return sbp_cmp_sbp_msg_fwd_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_fwd_t &a, const sbp_msg_fwd_t &b) {
  return sbp_cmp_sbp_msg_fwd_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_print_dep_t &a, const sbp_msg_print_dep_t &b) {
  return sbp_cmp_sbp_msg_print_dep_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_print_dep_t &a, const sbp_msg_print_dep_t &b) {
  return sbp_cmp_sbp_msg_print_dep_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_print_dep_t &a, const sbp_msg_print_dep_t &b) {
  return sbp_cmp_sbp_msg_print_dep_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_print_dep_t &a, const sbp_msg_print_dep_t &b) {
  return sbp_cmp_sbp_msg_print_dep_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_print_dep_t &a, const sbp_msg_print_dep_t &b) {
  return sbp_cmp_sbp_msg_print_dep_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_print_dep_t &a, const sbp_msg_print_dep_t &b) {
  return sbp_cmp_sbp_msg_print_dep_t(&a, &b) >= 0;
}

#endif

#endif /* LIBSBP_LOGGING_MESSAGES_H */
