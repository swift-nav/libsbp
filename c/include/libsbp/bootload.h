#ifndef LIBSBP_BOOTLOAD_MESSAGES_H
#define LIBSBP_BOOTLOAD_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
/** Bootloading handshake request (host => device)
 *
 * The handshake message request from the host establishes a
 * handshake between the device bootloader and the host. The
 * response from the device is MSG_BOOTLOADER_HANDSHAKE_RESP.
 */
#define SBP_MSG_BOOTLOADER_HANDSHAKE_REQ 0x00B3

typedef struct
{
  char dummy_to_avoid_empty_struct___do_not_use;
} sbp_msg_bootloader_handshake_req_t;

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

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_bootloader_handshake_req_t &a, const sbp_msg_bootloader_handshake_req_t &b)
{
  (void)a;
  (void)b;

  return true;
}

static inline bool operator!=(const sbp_msg_bootloader_handshake_req_t &a, const sbp_msg_bootloader_handshake_req_t &b)
{
  return !(a == b);
}
#endif
/** Bootloading handshake response (host <= device)
 *
 * The handshake message response from the device establishes a
 * handshake between the device bootloader and the host. The
 * request from the host is MSG_BOOTLOADER_HANDSHAKE_REQ.  The
 * payload contains the bootloader version number and the SBP
 * protocol version number.
 */
#define SBP_MSG_BOOTLOADER_HANDSHAKE_RESP 0x00B4

#define SBP_BOOTLOADER_HANDSHAKE_RESP_FLAGS_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK (0xff)
#define SBP_BOOTLOADER_HANDSHAKE_RESP_FLAGS_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT (8u)
#define SBP_BOOTLOADER_HANDSHAKE_RESP_FLAGS_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_GET(flags) \
  (((flags) >> SBP_BOOTLOADER_HANDSHAKE_RESP_FLAGS_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT) & \
   SBP_BOOTLOADER_HANDSHAKE_RESP_FLAGS_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK)
#define SBP_BOOTLOADER_HANDSHAKE_RESP_FLAGS_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_BOOTLOADER_HANDSHAKE_RESP_FLAGS_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK)) \
                 << (SBP_BOOTLOADER_HANDSHAKE_RESP_FLAGS_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT))); \
  } while (0)

#define SBP_BOOTLOADER_HANDSHAKE_RESP_FLAGS_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK (0xff)
#define SBP_BOOTLOADER_HANDSHAKE_RESP_FLAGS_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT (0u)
#define SBP_BOOTLOADER_HANDSHAKE_RESP_FLAGS_SBP_MINOR_PROTOCOL_VERSION_NUMBER_GET(flags) \
  (((flags) >> SBP_BOOTLOADER_HANDSHAKE_RESP_FLAGS_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT) & \
   SBP_BOOTLOADER_HANDSHAKE_RESP_FLAGS_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK)
#define SBP_BOOTLOADER_HANDSHAKE_RESP_FLAGS_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_BOOTLOADER_HANDSHAKE_RESP_FLAGS_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK)) \
                 << (SBP_BOOTLOADER_HANDSHAKE_RESP_FLAGS_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT))); \
  } while (0)

typedef struct
{

  /**
   * Bootloader flags
   */
  u32 flags;
  /**
   * Bootloader version number
   */
  char version[252];
} sbp_msg_bootloader_handshake_resp_t;

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
  offset += 4;
  if (offset + sbp_strlen(msg->version, "none") > len)
  {
    return false;
  }
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
  offset += 4;
  offset += sbp_unpack_string((const char *)buf + offset, len - offset, msg->version, "none");
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_bootloader_handshake_resp_t &a,
                              const sbp_msg_bootloader_handshake_resp_t &b)
{
  (void)a;
  (void)b;

  if (a.flags != b.flags)
  {
    return false;
  }
  if (sbp_strcmp(a.version, b.version, "none") != 0)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_bootloader_handshake_resp_t &a,
                              const sbp_msg_bootloader_handshake_resp_t &b)
{
  return !(a == b);
}
#endif
/** Bootloader jump to application (host => device)
 *
 * The host initiates the bootloader to jump to the application.
 */
#define SBP_MSG_BOOTLOADER_JUMP_TO_APP 0x00B1

typedef struct
{

  /**
   * Ignored by the device
   */
  u8 jump;
} sbp_msg_bootloader_jump_to_app_t;

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
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_bootloader_jump_to_app_t &a, const sbp_msg_bootloader_jump_to_app_t &b)
{
  (void)a;
  (void)b;

  if (a.jump != b.jump)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_bootloader_jump_to_app_t &a, const sbp_msg_bootloader_jump_to_app_t &b)
{
  return !(a == b);
}
#endif
/** Read FPGA device ID over UART request (host => device)
 *
 * The device message from the host reads a unique device
 * identifier from the SwiftNAP, an FPGA. The host requests the ID
 * by sending a MSG_NAP_DEVICE_DNA_REQ message. The device
 * responds with a MSG_NAP_DEVICE_DNA_RESP message with the
 * device ID in the payload. Note that this ID is tied to the FPGA,
 * and not related to the Piksi's serial number.
 */
#define SBP_MSG_NAP_DEVICE_DNA_REQ 0x00DE

typedef struct
{
  char dummy_to_avoid_empty_struct___do_not_use;
} sbp_msg_nap_device_dna_req_t;

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

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_nap_device_dna_req_t &a, const sbp_msg_nap_device_dna_req_t &b)
{
  (void)a;
  (void)b;

  return true;
}

static inline bool operator!=(const sbp_msg_nap_device_dna_req_t &a, const sbp_msg_nap_device_dna_req_t &b)
{
  return !(a == b);
}
#endif
/** Read FPGA device ID over UART response (host <= device)
 *
 * The device message from the host reads a unique device
 * identifier from the SwiftNAP, an FPGA. The host requests the ID
 * by sending a MSG_NAP_DEVICE_DNA_REQ message. The device
 * responds with a MSG_NAP_DEVICE_DNA_RESP messagage with the
 * device ID in the payload. Note that this ID is tied to the FPGA,
 * and not related to the Piksi's serial number.
 */
#define SBP_MSG_NAP_DEVICE_DNA_RESP 0x00DD

typedef struct
{

  /**
   * 57-bit SwiftNAP FPGA Device ID. Remaining bits are padded
   * on the right.
   */
  u8 dna[8];
} sbp_msg_nap_device_dna_resp_t;

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
    offset += 1;
  }
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_nap_device_dna_resp_t &a, const sbp_msg_nap_device_dna_resp_t &b)
{
  (void)a;
  (void)b;

  for (size_t dna_idx = 0; dna_idx < 8; dna_idx++)
  {

    if (a.dna[dna_idx] != b.dna[dna_idx])
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_nap_device_dna_resp_t &a, const sbp_msg_nap_device_dna_resp_t &b)
{
  return !(a == b);
}
#endif
/** Deprecated
 *
 * Deprecated.
 */
#define SBP_MSG_BOOTLOADER_HANDSHAKE_DEP_A 0x00B0

typedef struct
{

  /**
   * Version number string (not NULL terminated)
   */
  u8 handshake[255];
  /**
   * Number of items in handshake
   */
  u8 n_handshake;
} sbp_msg_bootloader_handshake_dep_a_t;

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
    offset += 1;
  }
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_bootloader_handshake_dep_a_t &a,
                              const sbp_msg_bootloader_handshake_dep_a_t &b)
{
  (void)a;
  (void)b;

  if (a.n_handshake != b.n_handshake)
  {
    return false;
  }
  for (size_t handshake_idx = 0; handshake_idx < (size_t)a.n_handshake; handshake_idx++)
  {

    if (a.handshake[handshake_idx] != b.handshake[handshake_idx])
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_bootloader_handshake_dep_a_t &a,
                              const sbp_msg_bootloader_handshake_dep_a_t &b)
{
  return !(a == b);
}
#endif

#endif /* LIBSBP_BOOTLOAD_MESSAGES_H */