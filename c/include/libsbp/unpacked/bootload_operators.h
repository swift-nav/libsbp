#ifndef LIBSBP_BOOTLOAD_OPERATORS_H
#define LIBSBP_BOOTLOAD_OPERATORS_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/bootload.h>
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
  if (a.version_count != b.version_count)
  {
    return false;
  }
  for (size_t version_idx = 0; version_idx < (size_t)a.version_count; version_idx++)
  {

    if (a.version[version_idx] != b.version[version_idx])
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_bootloader_handshake_resp_t &a,
                              const sbp_msg_bootloader_handshake_resp_t &b)
{
  return !(a == b);
}
#endif
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
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_bootloader_handshake_dep_a_t &a,
                              const sbp_msg_bootloader_handshake_dep_a_t &b)
{
  (void)a;
  (void)b;

  if (a.handshake_count != b.handshake_count)
  {
    return false;
  }
  for (size_t handshake_idx = 0; handshake_idx < (size_t)a.handshake_count; handshake_idx++)
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

#endif
