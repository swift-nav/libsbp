#ifndef LIBSBP_LOGGING_MESSAGES_H
#define LIBSBP_LOGGING_MESSAGES_H

#include <endian.h>
#include <math.h>
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
  char text[254];
} sbp_msg_log_t;

static inline size_t sbp_packed_size_sbp_msg_log_t(const sbp_msg_log_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->level) + sbp_strlen(msg->text, "none");
}

static inline bool sbp_pack_sbp_msg_log_t(u8 *buf, size_t len, const sbp_msg_log_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_log_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msglevel = msg->level;
  memcpy(buf + offset, &msglevel, 1);
  offset += 1;
  if (offset + sbp_strlen(msg->text, "none") > len)
  {
    return false;
  }
  offset += sbp_pack_string(buf + offset, msg->text, "none");
  return true;
}

static inline bool sbp_unpack_sbp_msg_log_t(const u8 *buf, size_t len, sbp_msg_log_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->level, buf + offset, 1);
  offset += 1;
  offset += sbp_unpack_string((const char *)buf + offset, len - offset, msg->text, "none");
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_log_t &a, const sbp_msg_log_t &b)
{
  (void)a;
  (void)b;

  if (a.level != b.level)
  {
    return false;
  }
  if (sbp_strcmp(a.text, b.text, "none") != 0)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_log_t &a, const sbp_msg_log_t &b)
{
  return !(a == b);
}
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
  char fwd_payload[253];
} sbp_msg_fwd_t;

static inline size_t sbp_packed_size_sbp_msg_fwd_t(const sbp_msg_fwd_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->source) + sizeof(msg->protocol) + sbp_strlen(msg->fwd_payload, "none");
}

static inline bool sbp_pack_sbp_msg_fwd_t(u8 *buf, size_t len, const sbp_msg_fwd_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_fwd_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsource = msg->source;
  memcpy(buf + offset, &msgsource, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgprotocol = msg->protocol;
  memcpy(buf + offset, &msgprotocol, 1);
  offset += 1;
  if (offset + sbp_strlen(msg->fwd_payload, "none") > len)
  {
    return false;
  }
  offset += sbp_pack_string(buf + offset, msg->fwd_payload, "none");
  return true;
}

static inline bool sbp_unpack_sbp_msg_fwd_t(const u8 *buf, size_t len, sbp_msg_fwd_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->source, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->protocol, buf + offset, 1);
  offset += 1;
  offset += sbp_unpack_string((const char *)buf + offset, len - offset, msg->fwd_payload, "none");
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_fwd_t &a, const sbp_msg_fwd_t &b)
{
  (void)a;
  (void)b;

  if (a.source != b.source)
  {
    return false;
  }

  if (a.protocol != b.protocol)
  {
    return false;
  }
  if (sbp_strcmp(a.fwd_payload, b.fwd_payload, "none") != 0)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_fwd_t &a, const sbp_msg_fwd_t &b)
{
  return !(a == b);
}
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
  char text[255];
} sbp_msg_print_dep_t;

static inline size_t sbp_packed_size_sbp_msg_print_dep_t(const sbp_msg_print_dep_t *msg)
{
  (void)msg;
  return 0 + sbp_strlen(msg->text, "none");
}

static inline bool sbp_pack_sbp_msg_print_dep_t(u8 *buf, size_t len, const sbp_msg_print_dep_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_print_dep_t(msg) > len)
  {
    return false;
  }

  if (offset + sbp_strlen(msg->text, "none") > len)
  {
    return false;
  }
  offset += sbp_pack_string(buf + offset, msg->text, "none");
  return true;
}

static inline bool sbp_unpack_sbp_msg_print_dep_t(const u8 *buf, size_t len, sbp_msg_print_dep_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  offset += sbp_unpack_string((const char *)buf + offset, len - offset, msg->text, "none");
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_print_dep_t &a, const sbp_msg_print_dep_t &b)
{
  (void)a;
  (void)b;

  if (sbp_strcmp(a.text, b.text, "none") != 0)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_print_dep_t &a, const sbp_msg_print_dep_t &b)
{
  return !(a == b);
}
#endif

#endif /* LIBSBP_LOGGING_MESSAGES_H */