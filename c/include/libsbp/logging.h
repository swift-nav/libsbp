#ifndef LIBSBP_LOGGING_MESSAGES_H
#define LIBSBP_LOGGING_MESSAGES_H

#include <endian.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
/** Plaintext logging messages with levels
 *
 * This message contains a human-readable payload string from the
 * device containing errors, warnings and informational messages at
 * ERROR, WARNING, DEBUG, INFO logging levels.
 */
#define SBP_MSG_LOG 0x0401

#define SBP_LOG_LEVEL_LOGGING_LEVEL_MASK (0x7)
#define SBP_LOG_LEVEL_LOGGING_LEVEL_SHIFT (0u)
#define SBP_LOG_LEVEL_LOGGING_LEVEL_GET(flags)      \
  (((flags) >> SBP_LOG_LEVEL_LOGGING_LEVEL_SHIFT) & \
   SBP_LOG_LEVEL_LOGGING_LEVEL_MASK)
#define SBP_LOG_LEVEL_LOGGING_LEVEL_SET(flags, val)           \
  do {                                                        \
    ((flags) |= (((val) & (SBP_LOG_LEVEL_LOGGING_LEVEL_MASK)) \
                 << (SBP_LOG_LEVEL_LOGGING_LEVEL_SHIFT)));    \
  } while (0)

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
  u8 level;
  /**
   * Human-readable string
   */
  char text[254];
} sbp_msg_log_t;

static inline size_t sbp_packed_size_sbp_msg_log_t(const sbp_msg_log_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->level) + (strlen(msg->text) + 1);
}

static inline bool sbp_pack_sbp_msg_log_t(u8 *buf, size_t len,
                                          const sbp_msg_log_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_log_t(msg) > len) {
    return false;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msglevel = msg->level;
  memcpy(buf + offset, &msglevel, 1);
  offset += 1;
  strcpy((char *)(buf + offset), msg->text);
  offset += strlen(msg->text) + 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_log_t(const u8 *buf, size_t len,
                                            sbp_msg_log_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->level, buf + offset, 1);
  offset += 1;
  strcpy(msg->text, (const char *)buf + offset);
  offset += strlen(msg->text) + 1;
  return true;
}
/** Wrapper for FWD a separate stream of information over SBP
 *
 * This message provides the ability to forward messages over SBP.  This may
 * take the form of wrapping up SBP messages received by Piksi for logging
 * purposes or wrapping another protocol with SBP.
 *
 * The source identifier indicates from what interface a forwarded stream
 * derived. The protocol identifier identifies what the expected protocol the
 * forwarded msg contains. Protocol 0 represents SBP and the remaining values
 * are implementation defined.
 */
#define SBP_MSG_FWD 0x0402

typedef struct {
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
  char fwd_payload[253];
} sbp_msg_fwd_t;

static inline size_t sbp_packed_size_sbp_msg_fwd_t(const sbp_msg_fwd_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->source) + sizeof(msg->protocol) +
         (strlen(msg->fwd_payload) + 1);
}

static inline bool sbp_pack_sbp_msg_fwd_t(u8 *buf, size_t len,
                                          const sbp_msg_fwd_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_fwd_t(msg) > len) {
    return false;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgsource = msg->source;
  memcpy(buf + offset, &msgsource, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgprotocol = msg->protocol;
  memcpy(buf + offset, &msgprotocol, 1);
  offset += 1;
  strcpy((char *)(buf + offset), msg->fwd_payload);
  offset += strlen(msg->fwd_payload) + 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_fwd_t(const u8 *buf, size_t len,
                                            sbp_msg_fwd_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->source, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->protocol, buf + offset, 1);
  offset += 1;
  strcpy(msg->fwd_payload, (const char *)buf + offset);
  offset += strlen(msg->fwd_payload) + 1;
  return true;
}
/** Deprecated
 *
 * Deprecated.
 */
#define SBP_MSG_PRINT_DEP 0x0010

typedef struct {
  /**
   * Human-readable string
   */
  char text[255];
} sbp_msg_print_dep_t;

static inline size_t sbp_packed_size_sbp_msg_print_dep_t(
    const sbp_msg_print_dep_t *msg) {
  (void)msg;
  return 0 + (strlen(msg->text) + 1);
}

static inline bool sbp_pack_sbp_msg_print_dep_t(
    u8 *buf, size_t len, const sbp_msg_print_dep_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_print_dep_t(msg) > len) {
    return false;
  }

  strcpy((char *)(buf + offset), msg->text);
  offset += strlen(msg->text) + 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_print_dep_t(const u8 *buf, size_t len,
                                                  sbp_msg_print_dep_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  strcpy(msg->text, (const char *)buf + offset);
  offset += strlen(msg->text) + 1;
  return true;
}

#endif /* LIBSBP_LOGGING_MESSAGES_H */