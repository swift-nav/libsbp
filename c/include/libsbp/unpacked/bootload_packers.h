#ifndef LIBSBP_BOOTLOAD_PACKERS_H
#define LIBSBP_BOOTLOAD_PACKERS_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/bootload.h>

static inline size_t sbp_packed_size_sbp_msg_bootloader_handshake_req_t(const sbp_msg_bootloader_handshake_req_t *msg)
{
  (void)msg;
  return 0;
}

static inline bool
sbp_pack_sbp_msg_bootloader_handshake_req_t(u8 *buf, size_t len, const sbp_msg_bootloader_handshake_req_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_bootloader_handshake_req_t(msg) > len)
  {
    return false;
  }

  return true;
}

static inline bool
sbp_unpack_sbp_msg_bootloader_handshake_req_t(const u8 *buf, size_t len, sbp_msg_bootloader_handshake_req_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  return true;
}

static inline size_t sbp_packed_size_sbp_msg_bootloader_handshake_resp_t(const sbp_msg_bootloader_handshake_resp_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->flags) + sbp_strlen(msg->version, "none");
}

static inline bool
sbp_pack_sbp_msg_bootloader_handshake_resp_t(u8 *buf, size_t len, const sbp_msg_bootloader_handshake_resp_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_bootloader_handshake_resp_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgflags = htole32(msg->flags);
  memcpy(buf + offset, &msgflags, 4);
  // NOLINTNEXTLINE
  offset += 4;
  if (offset + sbp_strlen(msg->version, "none") > len)
  {
    return false;
  }
  // NOLINTNEXTLINE
  offset += sbp_pack_string(buf + offset, msg->version, "none");
  return true;
}

static inline bool
sbp_unpack_sbp_msg_bootloader_handshake_resp_t(const u8 *buf, size_t len, sbp_msg_bootloader_handshake_resp_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 4);
  msg->flags = le32toh(msg->flags);
  // NOLINTNEXTLINE
  offset += 4;
  // NOLINTNEXTLINE
  offset += sbp_unpack_string((const char *)buf + offset, len - offset, msg->version, "none");
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_bootloader_jump_to_app_t(const sbp_msg_bootloader_jump_to_app_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->jump);
}

static inline bool
sbp_pack_sbp_msg_bootloader_jump_to_app_t(u8 *buf, size_t len, const sbp_msg_bootloader_jump_to_app_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_bootloader_jump_to_app_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgjump = msg->jump;
  memcpy(buf + offset, &msgjump, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool
sbp_unpack_sbp_msg_bootloader_jump_to_app_t(const u8 *buf, size_t len, sbp_msg_bootloader_jump_to_app_t *msg)
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
  memcpy(&msg->jump, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_nap_device_dna_req_t(const sbp_msg_nap_device_dna_req_t *msg)
{
  (void)msg;
  return 0;
}

static inline bool sbp_pack_sbp_msg_nap_device_dna_req_t(u8 *buf, size_t len, const sbp_msg_nap_device_dna_req_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_nap_device_dna_req_t(msg) > len)
  {
    return false;
  }

  return true;
}

static inline bool sbp_unpack_sbp_msg_nap_device_dna_req_t(const u8 *buf, size_t len, sbp_msg_nap_device_dna_req_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  return true;
}

static inline size_t sbp_packed_size_sbp_msg_nap_device_dna_resp_t(const sbp_msg_nap_device_dna_resp_t *msg)
{
  (void)msg;
  return 0 + (8 * sizeof(msg->dna[0]));
}

static inline bool sbp_pack_sbp_msg_nap_device_dna_resp_t(u8 *buf, size_t len, const sbp_msg_nap_device_dna_resp_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_nap_device_dna_resp_t(msg) > len)
  {
    return false;
  }

  for (size_t msgdna_idx = 0; msgdna_idx < 8; msgdna_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgdnamsgdna_idx = msg->dna[msgdna_idx];
    memcpy(buf + offset, &msgdnamsgdna_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool
sbp_unpack_sbp_msg_nap_device_dna_resp_t(const u8 *buf, size_t len, sbp_msg_nap_device_dna_resp_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  for (size_t msgdna_idx = 0; msgdna_idx < 8; msgdna_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->dna[msgdna_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline size_t
sbp_packed_size_sbp_msg_bootloader_handshake_dep_a_t(const sbp_msg_bootloader_handshake_dep_a_t *msg)
{
  (void)msg;
  return 0 + (msg->n_handshake * sizeof(msg->handshake[0]));
}

static inline bool
sbp_pack_sbp_msg_bootloader_handshake_dep_a_t(u8 *buf, size_t len, const sbp_msg_bootloader_handshake_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_bootloader_handshake_dep_a_t(msg) > len)
  {
    return false;
  }

  for (size_t msghandshake_idx = 0; msghandshake_idx < (size_t)msg->n_handshake; msghandshake_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msghandshakemsghandshake_idx = msg->handshake[msghandshake_idx];
    memcpy(buf + offset, &msghandshakemsghandshake_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool
sbp_unpack_sbp_msg_bootloader_handshake_dep_a_t(const u8 *buf, size_t len, sbp_msg_bootloader_handshake_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  msg->n_handshake = (u8)((len - offset) / 1);

  for (size_t msghandshake_idx = 0; msghandshake_idx < msg->n_handshake; msghandshake_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->handshake[msghandshake_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

#endif
