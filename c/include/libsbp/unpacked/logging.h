#ifndef LIBSBP_LOGGING_MESSAGES_H
#define LIBSBP_LOGGING_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/string2.h>
/** Plaintext logging messages with levels
 *
 * This message contains a human-readable payload string from the
 * device containing errors, warnings and informational messages at
 * ERROR, WARNING, DEBUG, INFO logging levels.
 */
#define SBP_MSG_LOG 0x0401

#define SBP_LOG_LEVEL_LOGGING_LEVEL_MASK (0x7)
#define SBP_LOG_LEVEL_LOGGING_LEVEL_SHIFT (0u)
#define SBP_LOG_LEVEL_LOGGING_LEVEL_GET(flags) \
  (((flags) >> SBP_LOG_LEVEL_LOGGING_LEVEL_SHIFT) & SBP_LOG_LEVEL_LOGGING_LEVEL_MASK)
#define SBP_LOG_LEVEL_LOGGING_LEVEL_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_LOG_LEVEL_LOGGING_LEVEL_MASK)) << (SBP_LOG_LEVEL_LOGGING_LEVEL_SHIFT))); \
  } while (0)

#define SBP_LOG_LEVEL_LOGGING_LEVEL_EMERG (0)
#define SBP_LOG_LEVEL_LOGGING_LEVEL_ALERT (1)
#define SBP_LOG_LEVEL_LOGGING_LEVEL_CRIT (2)
#define SBP_LOG_LEVEL_LOGGING_LEVEL_ERROR (3)
#define SBP_LOG_LEVEL_LOGGING_LEVEL_WARN (4)
#define SBP_LOG_LEVEL_LOGGING_LEVEL_NOTICE (5)
#define SBP_LOG_LEVEL_LOGGING_LEVEL_INFO (6)
#define SBP_LOG_LEVEL_LOGGING_LEVEL_DEBUG (7)
typedef struct
{

  /**
   * Logging level
   */
  u8 level;
  /**
   * Human-readable string
   */
  sbp_unterminated_string_t text;
} sbp_msg_log_t;

#if 0
  static const sbp_unterminated_string_format_t sbp_msg_log_t_text_format = {
    /* .encoding = */ SBP_STRING_UNTERMINATED,
    /* .min_sections = */0u,
    /* .max_sections = */0u,
    /* .terminator = */0u,
    /* .max_encoded_len = */ 254u
  };
  static inline void sbp_msg_log_t_text_init(sbp_unterminated_string_t s) { sbp_unterminated_string_init(s, &sbp_msg_log_t_text_format); }
  static inline uint8_t sbp_msg_log_t_text_packed_len(const sbp_unterminated_string_t s) { return sbp_unterminated_string_packed_len(s, &sbp_msg_log_t_text_format); }
  static inline uint8_t sbp_msg_log_t_text_pack(const sbp_unterminated_string_t s, uint8_t *buf, uint8_t buf_len) { return sbp_unterminated_string_pack(s, &sbp_msg_log_t_text_format, buf, buf_len); }
  static inline uint8_t sbp_msg_log_t_text_unpack(sbp_unterminated_string_t s, const uint8_t *buf, uint8_t buf_len) { return sbp_unterminated_string_unpack(s, &sbp_msg_log_t_text_format, buf, buf_len); }
  static inline uint8_t sbp_msg_log_t_text_space_remaining(const sbp_unterminated_string_t s) { return sbp_unterminated_string_space_remaining(s, &sbp_msg_log_t_text_format); }
  static inline const char *sbp_msg_log_t_text_get(sbp_unterminated_string_t s) { return sbp_unterminated_string_get_section(s, &sbp_msg_log_t_text_format, 0); }
  static inline bool sbp_msg_log_t_text_set(sbp_unterminated_string_t s, const char *new_str) { return sbp_unterminated_string_set(s, &sbp_msg_log_t_text_format, new_str); }
#endif
/** Wrapper for FWD a separate stream of information over SBP
 *
 * This message provides the ability to forward messages over SBP.  This may take the form
 * of wrapping up SBP messages received by Piksi for logging purposes or wrapping
 * another protocol with SBP.
 *
 * The source identifier indicates from what interface a forwarded stream derived.
 * The protocol identifier identifies what the expected protocol the forwarded msg contains.
 * Protocol 0 represents SBP and the remaining values are implementation defined.
 */
#define SBP_MSG_FWD 0x0402

typedef struct
{

  /**
   * source identifier
   */
  u8 source;
  /**
   * protocol identifier
   */
  u8 protocol;
  /**
   * variable length wrapped binary message
   */
  sbp_unterminated_string_t fwd_payload;
} sbp_msg_fwd_t;

#if 0
  static const sbp_unterminated_string_format_t sbp_msg_fwd_t_fwd_payload_format = {
    /* .encoding = */ SBP_STRING_UNTERMINATED,
    /* .min_sections = */0u,
    /* .max_sections = */0u,
    /* .terminator = */0u,
    /* .max_encoded_len = */ 253u
  };
  static inline void sbp_msg_fwd_t_fwd_payload_init(sbp_unterminated_string_t s) { sbp_unterminated_string_init(s, &sbp_msg_fwd_t_fwd_payload_format); }
  static inline uint8_t sbp_msg_fwd_t_fwd_payload_packed_len(const sbp_unterminated_string_t s) { return sbp_unterminated_string_packed_len(s, &sbp_msg_fwd_t_fwd_payload_format); }
  static inline uint8_t sbp_msg_fwd_t_fwd_payload_pack(const sbp_unterminated_string_t s, uint8_t *buf, uint8_t buf_len) { return sbp_unterminated_string_pack(s, &sbp_msg_fwd_t_fwd_payload_format, buf, buf_len); }
  static inline uint8_t sbp_msg_fwd_t_fwd_payload_unpack(sbp_unterminated_string_t s, const uint8_t *buf, uint8_t buf_len) { return sbp_unterminated_string_unpack(s, &sbp_msg_fwd_t_fwd_payload_format, buf, buf_len); }
  static inline uint8_t sbp_msg_fwd_t_fwd_payload_space_remaining(const sbp_unterminated_string_t s) { return sbp_unterminated_string_space_remaining(s, &sbp_msg_fwd_t_fwd_payload_format); }
  static inline const char *sbp_msg_fwd_t_fwd_payload_get(sbp_unterminated_string_t s) { return sbp_unterminated_string_get_section(s, &sbp_msg_fwd_t_fwd_payload_format, 0); }
  static inline bool sbp_msg_fwd_t_fwd_payload_set(sbp_unterminated_string_t s, const char *new_str) { return sbp_unterminated_string_set(s, &sbp_msg_fwd_t_fwd_payload_format, new_str); }
#endif
/** Deprecated
 *
 * Deprecated.
 */
#define SBP_MSG_PRINT_DEP 0x0010

typedef struct
{

  /**
   * Human-readable string
   */
  sbp_unterminated_string_t text;
} sbp_msg_print_dep_t;

#if 0
  static const sbp_unterminated_string_format_t sbp_msg_print_dep_t_text_format = {
    /* .encoding = */ SBP_STRING_UNTERMINATED,
    /* .min_sections = */0u,
    /* .max_sections = */0u,
    /* .terminator = */0u,
    /* .max_encoded_len = */ 255u
  };
  static inline void sbp_msg_print_dep_t_text_init(sbp_unterminated_string_t s) { sbp_unterminated_string_init(s, &sbp_msg_print_dep_t_text_format); }
  static inline uint8_t sbp_msg_print_dep_t_text_packed_len(const sbp_unterminated_string_t s) { return sbp_unterminated_string_packed_len(s, &sbp_msg_print_dep_t_text_format); }
  static inline uint8_t sbp_msg_print_dep_t_text_pack(const sbp_unterminated_string_t s, uint8_t *buf, uint8_t buf_len) { return sbp_unterminated_string_pack(s, &sbp_msg_print_dep_t_text_format, buf, buf_len); }
  static inline uint8_t sbp_msg_print_dep_t_text_unpack(sbp_unterminated_string_t s, const uint8_t *buf, uint8_t buf_len) { return sbp_unterminated_string_unpack(s, &sbp_msg_print_dep_t_text_format, buf, buf_len); }
  static inline uint8_t sbp_msg_print_dep_t_text_space_remaining(const sbp_unterminated_string_t s) { return sbp_unterminated_string_space_remaining(s, &sbp_msg_print_dep_t_text_format); }
  static inline const char *sbp_msg_print_dep_t_text_get(sbp_unterminated_string_t s) { return sbp_unterminated_string_get_section(s, &sbp_msg_print_dep_t_text_format, 0); }
  static inline bool sbp_msg_print_dep_t_text_set(sbp_unterminated_string_t s, const char *new_str) { return sbp_unterminated_string_set(s, &sbp_msg_print_dep_t_text_format, new_str); }
#endif

#include <libsbp/unpacked/logging_operators.h>
#include <libsbp/unpacked/logging_packers.h>

#endif /* LIBSBP_LOGGING_MESSAGES_H */
