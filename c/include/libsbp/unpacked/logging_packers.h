#ifndef LIBSBP_LOGGING_PACKERS_H
#define LIBSBP_LOGGING_PACKERS_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/logging.h>

static inline size_t sbp_packed_size_sbp_msg_log_t(const sbp_msg_log_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->level) + (msg->text_count * sizeof(msg->text[0]));
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
  for (size_t msgtext_idx = 0; msgtext_idx < (size_t)msg->text_count; msgtext_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    char msgtextmsgtext_idx = msg->text[msgtext_idx];
    memcpy(buf + offset, &msgtextmsgtext_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
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
  msg->text_count = (u8)((len - offset) / 1);

  for (size_t msgtext_idx = 0; msgtext_idx < msg->text_count; msgtext_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->text[msgtext_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_fwd_t(const sbp_msg_fwd_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->source) + sizeof(msg->protocol) + (msg->fwd_payload_count * sizeof(msg->fwd_payload[0]));
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
  for (size_t msgfwd_payload_idx = 0; msgfwd_payload_idx < (size_t)msg->fwd_payload_count; msgfwd_payload_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    char msgfwd_payloadmsgfwd_payload_idx = msg->fwd_payload[msgfwd_payload_idx];
    memcpy(buf + offset, &msgfwd_payloadmsgfwd_payload_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
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
  msg->fwd_payload_count = (u8)((len - offset) / 1);

  for (size_t msgfwd_payload_idx = 0; msgfwd_payload_idx < msg->fwd_payload_count; msgfwd_payload_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->fwd_payload[msgfwd_payload_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_print_dep_t(const sbp_msg_print_dep_t *msg)
{
  (void)msg;
  return 0 + (msg->text_count * sizeof(msg->text[0]));
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

  for (size_t msgtext_idx = 0; msgtext_idx < (size_t)msg->text_count; msgtext_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    char msgtextmsgtext_idx = msg->text[msgtext_idx];
    memcpy(buf + offset, &msgtextmsgtext_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_print_dep_t(const u8 *buf, size_t len, sbp_msg_print_dep_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  msg->text_count = (u8)((len - offset) / 1);

  for (size_t msgtext_idx = 0; msgtext_idx < msg->text_count; msgtext_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->text[msgtext_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

#endif
