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


/** Wrapper for FWD a separate stream of information over SBP
 *
((m.desc|commentify)))
 */
#define SBP_MSG_FWD       0x0402
typedef struct {
  u8 source;
  u8 protocol;
  char fwd_payload[253];
  u8 n_fwd_payload;
} sbp_msg_fwd_t;


/** Deprecated
 *
((m.desc|commentify)))
 */
#define SBP_MSG_PRINT_DEP 0x0010
typedef struct {
  sbp_unterminated_string_t text;
} sbp_msg_print_dep_t;



#include <libsbp/unpacked/logging_operators.h>
#include <libsbp/unpacked/logging_packers.h>

#endif /* LIBSBP_LOGGING_MESSAGES_H */
