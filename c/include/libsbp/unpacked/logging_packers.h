#ifndef LIBSBP_LOGGING_PACKERS_H
#define LIBSBP_LOGGING_PACKERS_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/string2.h>
//#include <libsbp/unpacked/logging.h>

static inline size_t sbp_packed_size_sbp_msg_log_t(const sbp_msg_log_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->level) + 0 /*sbp_msg_log_t_text_packed_len( msg->text )*/;
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
  // NOLINTNEXTLINE
  offset += 1;
  // offset += sbp_msg_log_t_text_pack( msg->text, buf + offset, (uint8_t)(len - offset ));
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
  // NOLINTNEXTLINE
  offset += 1;
  // offset += sbp_msg_log_t_text_unpack( msg->text, buf + offset, (uint8_t)(len - offset ));
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_fwd_t(const sbp_msg_fwd_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->source) + sizeof(msg->protocol) +
         0 /*sbp_msg_fwd_t_fwd_payload_packed_len( msg->fwd_payload )*/;
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
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgprotocol = msg->protocol;
  memcpy(buf + offset, &msgprotocol, 1);
  // NOLINTNEXTLINE
  offset += 1;
  // offset += sbp_msg_fwd_t_fwd_payload_pack( msg->fwd_payload, buf + offset, (uint8_t)(len - offset ));
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
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->protocol, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  // offset += sbp_msg_fwd_t_fwd_payload_unpack( msg->fwd_payload, buf + offset, (uint8_t)(len - offset ));
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_print_dep_t(const sbp_msg_print_dep_t *msg)
{
  (void)msg;
  return 0 + 0 /*sbp_msg_print_dep_t_text_packed_len( msg->text )*/;
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

  // offset += sbp_msg_print_dep_t_text_pack( msg->text, buf + offset, (uint8_t)(len - offset ));
  return true;
}

static inline bool sbp_unpack_sbp_msg_print_dep_t(const u8 *buf, size_t len, sbp_msg_print_dep_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  // offset += sbp_msg_print_dep_t_text_unpack( msg->text, buf + offset, (uint8_t)(len - offset ));
  return true;
}

#endif
