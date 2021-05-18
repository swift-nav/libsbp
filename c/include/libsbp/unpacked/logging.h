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
#include <libsbp/unpacked/string/sequence.h>
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
#define sbp_msg_log_t_text_init(f) sbp_unterminated_string_init(f, 254)
#define sbp_msg_log_t_text_valid(f) sbp_unterminated_string_valid(f, 254)
#define sbp_msg_log_t_text_set(f,s) sbp_unterminated_string_set(f,s,254)
#define sbp_msg_log_t_text_printf(f,...) sbp_unterminated_string_printf(f,254,__VA_ARGS__)
#define sbp_msg_log_t_text_vprintf(f,fmt,ap) sbp_unterminated_string_vprintf(f,254,fmt,ap)
#define sbp_msg_log_t_text_packed_len(f) sbp_unterminated_string_packed_len(f,254)
#define sbp_msg_log_t_text_get(f) sbp_unterminated_string_get(f,254)
#define sbp_msg_log_t_text_len(f) ( sbp_msg_log_t_text_packed_len(f))
#define sbp_msg_log_t_text_strcmp(a,b) sbp_unterminated_string_strcmp(a,b,254)

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
#define sbp_msg_fwd_t_fwd_payload_init(f) sbp_binary_string_init(f, 253)
#define sbp_msg_fwd_t_fwd_payload_valid(f) sbp_binary_string_valid(f, 253)
#define sbp_msg_fwd_t_fwd_payload_set(f,s,n) sbp_binary_string_set(f, s, n, 253)
#define sbp_msg_fwd_t_fwd_payload_get(f,n) sbp_binary_string_get(f,n,253)
#define sbp_msg_fwd_t_fwd_payload_strcmp(a,v) sbp_binary_string_strcmp(a,b,253)

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
#define sbp_msg_print_dep_t_text_init(f) sbp_unterminated_string_init(f, 255)
#define sbp_msg_print_dep_t_text_valid(f) sbp_unterminated_string_valid(f, 255)
#define sbp_msg_print_dep_t_text_set(f,s) sbp_unterminated_string_set(f,s,255)
#define sbp_msg_print_dep_t_text_printf(f,...) sbp_unterminated_string_printf(f,255,__VA_ARGS__)
#define sbp_msg_print_dep_t_text_vprintf(f,fmt,ap) sbp_unterminated_string_vprintf(f,255,fmt,ap)
#define sbp_msg_print_dep_t_text_packed_len(f) sbp_unterminated_string_packed_len(f,255)
#define sbp_msg_print_dep_t_text_get(f) sbp_unterminated_string_get(f,255)
#define sbp_msg_print_dep_t_text_len(f) ( sbp_msg_print_dep_t_text_packed_len(f))
#define sbp_msg_print_dep_t_text_strcmp(a,b) sbp_unterminated_string_strcmp(a,b,255)

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
