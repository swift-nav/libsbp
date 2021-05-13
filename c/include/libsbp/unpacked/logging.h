#ifndef LIBSBP_LOGGING_MESSAGES_H
#define LIBSBP_LOGGING_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>
  /** Plaintext logging messages with levels
   *
 * This message contains a human-readable payload string from the
 * device containing errors, warnings and informational messages at
 * ERROR, WARNING, DEBUG, INFO logging levels.
   */
#define SBP_MSG_LOG       0x0401

	#define SBP_LOG_LEVEL_LOGGING_LEVEL_MASK (0x7)
#define SBP_LOG_LEVEL_LOGGING_LEVEL_SHIFT (0u)
#define SBP_LOG_LEVEL_LOGGING_LEVEL_GET(flags) \
                             (((flags) >> SBP_LOG_LEVEL_LOGGING_LEVEL_SHIFT) \
                             & SBP_LOG_LEVEL_LOGGING_LEVEL_MASK)
#define SBP_LOG_LEVEL_LOGGING_LEVEL_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_LOG_LEVEL_LOGGING_LEVEL_MASK)) \
                             << (SBP_LOG_LEVEL_LOGGING_LEVEL_SHIFT)));} while(0)
                             

#define SBP_LOG_LEVEL_LOGGING_LEVEL_EMERG (0)
#define SBP_LOG_LEVEL_LOGGING_LEVEL_ALERT (1)
#define SBP_LOG_LEVEL_LOGGING_LEVEL_CRIT (2)
#define SBP_LOG_LEVEL_LOGGING_LEVEL_ERROR (3)
#define SBP_LOG_LEVEL_LOGGING_LEVEL_WARN (4)
#define SBP_LOG_LEVEL_LOGGING_LEVEL_NOTICE (5)
#define SBP_LOG_LEVEL_LOGGING_LEVEL_INFO (6)
#define SBP_LOG_LEVEL_LOGGING_LEVEL_DEBUG (7)
typedef struct {
  
  /**
* Logging level
   */
    u8
  level
  ;
  /**
* Human-readable string
   */
  sbp_unterminated_string_t
  text
  ;
} sbp_msg_log_t;


#define sbp_msg_log_t_text_init(f) sbp_unterminated_string_init(f, 254)
#define sbp_msg_log_t_text_valid(f) sbp_unterminated_string_valid(f, 254)
#define sbp_msg_log_t_text_set(f,s) sbp_unterminated_string_set(f,s,254)
#define sbp_msg_log_t_text_printf(f,...) sbp_unterminated_string_printf(f,254,__VA_ARGS__)
#define sbp_msg_log_t_text_vprintf(f,ap) sbp_unterminated_string_vprintf(f,254,ap)
#define sbp_msg_log_t_text_packed_len(f) sbp_unterminated_string_packed_len(f,254)
#define sbp_msg_log_t_text_get(f) sbp_unterminated_string_get(f,254)
#define sbp_msg_log_t_text_len(f) ( sbp_msg_log_t_text_packed_len(f))
#define sbp_msg_log_t_text_strcmp(a,b) sbp_unterminated_string_strcmp(a,b,254)
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
#define SBP_MSG_FWD       0x0402

typedef struct {
  
  /**
* source identifier
   */
    u8
  source
  ;
  /**
* protocol identifier
   */
    u8
  protocol
  ;
  /**
* variable length wrapped binary message
   */
    char
  fwd_payload
    [253]
  ;
  /**
   * Number of items in fwd_payload
   */
  u8 n_fwd_payload;
} sbp_msg_fwd_t;


  /** Deprecated
   *
* Deprecated.
   */
#define SBP_MSG_PRINT_DEP 0x0010

typedef struct {
  
  /**
* Human-readable string
   */
  sbp_unterminated_string_t
  text
  ;
} sbp_msg_print_dep_t;


#define sbp_msg_print_dep_t_text_init(f) sbp_unterminated_string_init(f, 255)
#define sbp_msg_print_dep_t_text_valid(f) sbp_unterminated_string_valid(f, 255)
#define sbp_msg_print_dep_t_text_set(f,s) sbp_unterminated_string_set(f,s,255)
#define sbp_msg_print_dep_t_text_printf(f,...) sbp_unterminated_string_printf(f,255,__VA_ARGS__)
#define sbp_msg_print_dep_t_text_vprintf(f,ap) sbp_unterminated_string_vprintf(f,255,ap)
#define sbp_msg_print_dep_t_text_packed_len(f) sbp_unterminated_string_packed_len(f,255)
#define sbp_msg_print_dep_t_text_get(f) sbp_unterminated_string_get(f,255)
#define sbp_msg_print_dep_t_text_len(f) ( sbp_msg_print_dep_t_text_packed_len(f))
#define sbp_msg_print_dep_t_text_strcmp(a,b) sbp_unterminated_string_strcmp(a,b,255)

#include <libsbp/unpacked/logging_operators.h>
#include <libsbp/unpacked/logging_packers.h>

#endif /* LIBSBP_LOGGING_MESSAGES_H */
