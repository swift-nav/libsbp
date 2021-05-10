#ifndef LIBSBP_OBSERVATION_PACKERS_H
#define LIBSBP_OBSERVATION_PACKERS_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/string2.h>
//#include <libsbp/unpacked/observation.h>
//#include <libsbp/unpacked/gnss.h>

static inline size_t sbp_packed_size_sbp_observation_header_t(const sbp_observation_header_t *msg)
{
  (void)msg;
  return 0 + (0 + sizeof(msg->t.tow) + sizeof(msg->t.ns_residual) + sizeof(msg->t.wn)) + sizeof(msg->n_obs);
}

static inline bool sbp_pack_sbp_observation_header_t(u8 *buf, size_t len, const sbp_observation_header_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_observation_header_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgttow = htole32(msg->t.tow);
  memcpy(buf + offset, &msgttow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtns_residual = htole32(*(const u32 *)&msg->t.ns_residual);
  memcpy(buf + offset, &msgtns_residual, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtwn = htole16(msg->t.wn);
  memcpy(buf + offset, &msgtwn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_obs = msg->n_obs;
  memcpy(buf + offset, &msgn_obs, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_observation_header_t(const u8 *buf, size_t len, sbp_observation_header_t *msg)
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
  memcpy(&msg->t.tow, buf + offset, 4);
  msg->t.tow = le32toh(msg->t.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->t.ns_residual, buf + offset, 4);
  u32 msgtns_residual = *(const u32 *)&msg->t.ns_residual;
  msgtns_residual = le32toh(msgtns_residual);
  msg->t.ns_residual = *(const s32 *)&msgtns_residual;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->t.wn, buf + offset, 2);
  msg->t.wn = le16toh(msg->t.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_obs, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_doppler_t(const sbp_doppler_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->i) + sizeof(msg->f);
}

static inline bool sbp_pack_sbp_doppler_t(u8 *buf, size_t len, const sbp_doppler_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_doppler_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgi = htole16(*(const u16 *)&msg->i);
  memcpy(buf + offset, &msgi, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgf = msg->f;
  memcpy(buf + offset, &msgf, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_doppler_t(const u8 *buf, size_t len, sbp_doppler_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->i, buf + offset, 2);
  u16 msgi = *(const u16 *)&msg->i;
  msgi = le16toh(msgi);
  msg->i = *(const s16 *)&msgi;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->f, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_packed_obs_content_t(const sbp_packed_obs_content_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->P) + (0 + sizeof(msg->L.i) + sizeof(msg->L.f)) + (0 + sizeof(msg->D.i) + sizeof(msg->D.f)) +
         sizeof(msg->cn0) + sizeof(msg->lock) + sizeof(msg->flags) + (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code));
}

static inline bool sbp_pack_sbp_packed_obs_content_t(u8 *buf, size_t len, const sbp_packed_obs_content_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_packed_obs_content_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgP = htole32(msg->P);
  memcpy(buf + offset, &msgP, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgLi = htole32(*(const u32 *)&msg->L.i);
  memcpy(buf + offset, &msgLi, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgLf = msg->L.f;
  memcpy(buf + offset, &msgLf, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgDi = htole16(*(const u16 *)&msg->D.i);
  memcpy(buf + offset, &msgDi, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgDf = msg->D.f;
  memcpy(buf + offset, &msgDf, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcn0 = msg->cn0;
  memcpy(buf + offset, &msgcn0, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msglock = msg->lock;
  memcpy(buf + offset, &msglock, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidsat = msg->sid.sat;
  memcpy(buf + offset, &msgsidsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_packed_obs_content_t(const u8 *buf, size_t len, sbp_packed_obs_content_t *msg)
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
  memcpy(&msg->P, buf + offset, 4);
  msg->P = le32toh(msg->P);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->L.i, buf + offset, 4);
  u32 msgLi = *(const u32 *)&msg->L.i;
  msgLi = le32toh(msgLi);
  msg->L.i = *(const s32 *)&msgLi;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->L.f, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->D.i, buf + offset, 2);
  u16 msgDi = *(const u16 *)&msg->D.i;
  msgDi = le16toh(msgDi);
  msg->D.i = *(const s16 *)&msgDi;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->D.f, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->cn0, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->lock, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_packed_osr_content_t(const sbp_packed_osr_content_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->P) + (0 + sizeof(msg->L.i) + sizeof(msg->L.f)) + sizeof(msg->lock) + sizeof(msg->flags) +
         (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code)) + sizeof(msg->iono_std) + sizeof(msg->tropo_std) +
         sizeof(msg->range_std);
}

static inline bool sbp_pack_sbp_packed_osr_content_t(u8 *buf, size_t len, const sbp_packed_osr_content_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_packed_osr_content_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgP = htole32(msg->P);
  memcpy(buf + offset, &msgP, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgLi = htole32(*(const u32 *)&msg->L.i);
  memcpy(buf + offset, &msgLi, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgLf = msg->L.f;
  memcpy(buf + offset, &msgLf, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msglock = msg->lock;
  memcpy(buf + offset, &msglock, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidsat = msg->sid.sat;
  memcpy(buf + offset, &msgsidsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgiono_std = htole16(msg->iono_std);
  memcpy(buf + offset, &msgiono_std, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtropo_std = htole16(msg->tropo_std);
  memcpy(buf + offset, &msgtropo_std, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgrange_std = htole16(msg->range_std);
  memcpy(buf + offset, &msgrange_std, 2);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_packed_osr_content_t(const u8 *buf, size_t len, sbp_packed_osr_content_t *msg)
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
  memcpy(&msg->P, buf + offset, 4);
  msg->P = le32toh(msg->P);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->L.i, buf + offset, 4);
  u32 msgLi = *(const u32 *)&msg->L.i;
  msgLi = le32toh(msgLi);
  msg->L.i = *(const s32 *)&msgLi;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->L.f, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->lock, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->iono_std, buf + offset, 2);
  msg->iono_std = le16toh(msg->iono_std);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->tropo_std, buf + offset, 2);
  msg->tropo_std = le16toh(msg->tropo_std);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->range_std, buf + offset, 2);
  msg->range_std = le16toh(msg->range_std);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_obs_t(const sbp_msg_obs_t *msg)
{
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->header.t.tow) + sizeof(msg->header.t.ns_residual) + sizeof(msg->header.t.wn)) +
          sizeof(msg->header.n_obs)) +
         (msg->obs_count * (0 + sizeof(msg->obs[0].P) + (0 + sizeof(msg->obs[0].L.i) + sizeof(msg->obs[0].L.f)) +
                            (0 + sizeof(msg->obs[0].D.i) + sizeof(msg->obs[0].D.f)) + sizeof(msg->obs[0].cn0) +
                            sizeof(msg->obs[0].lock) + sizeof(msg->obs[0].flags) +
                            (0 + sizeof(msg->obs[0].sid.sat) + sizeof(msg->obs[0].sid.code))));
}

static inline bool sbp_pack_sbp_msg_obs_t(u8 *buf, size_t len, const sbp_msg_obs_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_obs_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgheaderttow = htole32(msg->header.t.tow);
  memcpy(buf + offset, &msgheaderttow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgheadertns_residual = htole32(*(const u32 *)&msg->header.t.ns_residual);
  memcpy(buf + offset, &msgheadertns_residual, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgheadertwn = htole16(msg->header.t.wn);
  memcpy(buf + offset, &msgheadertwn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgheadern_obs = msg->header.n_obs;
  memcpy(buf + offset, &msgheadern_obs, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgobs_idx = 0; msgobs_idx < (size_t)msg->obs_count; msgobs_idx++)
  {

    if (offset + 4 > len)
    {
      return false;
    }
    u32 msgobsmsgobs_idxP = htole32(msg->obs[msgobs_idx].P);
    memcpy(buf + offset, &msgobsmsgobs_idxP, 4);
    // NOLINTNEXTLINE
    offset += 4;

    if (offset + 4 > len)
    {
      return false;
    }
    u32 msgobsmsgobs_idxLi = htole32(*(const u32 *)&msg->obs[msgobs_idx].L.i);
    memcpy(buf + offset, &msgobsmsgobs_idxLi, 4);
    // NOLINTNEXTLINE
    offset += 4;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgobsmsgobs_idxLf = msg->obs[msgobs_idx].L.f;
    memcpy(buf + offset, &msgobsmsgobs_idxLf, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 2 > len)
    {
      return false;
    }
    u16 msgobsmsgobs_idxDi = htole16(*(const u16 *)&msg->obs[msgobs_idx].D.i);
    memcpy(buf + offset, &msgobsmsgobs_idxDi, 2);
    // NOLINTNEXTLINE
    offset += 2;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgobsmsgobs_idxDf = msg->obs[msgobs_idx].D.f;
    memcpy(buf + offset, &msgobsmsgobs_idxDf, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgobsmsgobs_idxcn0 = msg->obs[msgobs_idx].cn0;
    memcpy(buf + offset, &msgobsmsgobs_idxcn0, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgobsmsgobs_idxlock = msg->obs[msgobs_idx].lock;
    memcpy(buf + offset, &msgobsmsgobs_idxlock, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgobsmsgobs_idxflags = msg->obs[msgobs_idx].flags;
    memcpy(buf + offset, &msgobsmsgobs_idxflags, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgobsmsgobs_idxsidsat = msg->obs[msgobs_idx].sid.sat;
    memcpy(buf + offset, &msgobsmsgobs_idxsidsat, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgobsmsgobs_idxsidcode = msg->obs[msgobs_idx].sid.code;
    memcpy(buf + offset, &msgobsmsgobs_idxsidcode, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_obs_t(const u8 *buf, size_t len, sbp_msg_obs_t *msg)
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
  memcpy(&msg->header.t.tow, buf + offset, 4);
  msg->header.t.tow = le32toh(msg->header.t.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->header.t.ns_residual, buf + offset, 4);
  u32 msgheadertns_residual = *(const u32 *)&msg->header.t.ns_residual;
  msgheadertns_residual = le32toh(msgheadertns_residual);
  msg->header.t.ns_residual = *(const s32 *)&msgheadertns_residual;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->header.t.wn, buf + offset, 2);
  msg->header.t.wn = le16toh(msg->header.t.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->header.n_obs, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  msg->obs_count = (u8)((len - offset) / 17);

  for (size_t msgobs_idx = 0; msgobs_idx < msg->obs_count; msgobs_idx++)
  {

    if (offset + 4 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].P, buf + offset, 4);
    msg->obs[msgobs_idx].P = le32toh(msg->obs[msgobs_idx].P);
    // NOLINTNEXTLINE
    offset += 4;

    if (offset + 4 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].L.i, buf + offset, 4);
    u32 msgobsmsgobs_idxLi = *(const u32 *)&msg->obs[msgobs_idx].L.i;
    msgobsmsgobs_idxLi = le32toh(msgobsmsgobs_idxLi);
    msg->obs[msgobs_idx].L.i = *(const s32 *)&msgobsmsgobs_idxLi;
    // NOLINTNEXTLINE
    offset += 4;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].L.f, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 2 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].D.i, buf + offset, 2);
    u16 msgobsmsgobs_idxDi = *(const u16 *)&msg->obs[msgobs_idx].D.i;
    msgobsmsgobs_idxDi = le16toh(msgobsmsgobs_idxDi);
    msg->obs[msgobs_idx].D.i = *(const s16 *)&msgobsmsgobs_idxDi;
    // NOLINTNEXTLINE
    offset += 2;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].D.f, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].cn0, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].lock, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].flags, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].sid.sat, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].sid.code, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_base_pos_llh_t(const sbp_msg_base_pos_llh_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->lat) + sizeof(msg->lon) + sizeof(msg->height);
}

static inline bool sbp_pack_sbp_msg_base_pos_llh_t(u8 *buf, size_t len, const sbp_msg_base_pos_llh_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_base_pos_llh_t(msg) > len)
  {
    return false;
  }

  if (offset + 8 > len)
  {
    return false;
  }
  double msglat = msg->lat;
  memcpy(buf + offset, &msglat, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msglon = msg->lon;
  memcpy(buf + offset, &msglon, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgheight = msg->height;
  memcpy(buf + offset, &msgheight, 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline bool sbp_unpack_sbp_msg_base_pos_llh_t(const u8 *buf, size_t len, sbp_msg_base_pos_llh_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->lat, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->lon, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->height, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_base_pos_ecef_t(const sbp_msg_base_pos_ecef_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->x) + sizeof(msg->y) + sizeof(msg->z);
}

static inline bool sbp_pack_sbp_msg_base_pos_ecef_t(u8 *buf, size_t len, const sbp_msg_base_pos_ecef_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_base_pos_ecef_t(msg) > len)
  {
    return false;
  }

  if (offset + 8 > len)
  {
    return false;
  }
  double msgx = msg->x;
  memcpy(buf + offset, &msgx, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgy = msg->y;
  memcpy(buf + offset, &msgy, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgz = msg->z;
  memcpy(buf + offset, &msgz, 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline bool sbp_unpack_sbp_msg_base_pos_ecef_t(const u8 *buf, size_t len, sbp_msg_base_pos_ecef_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->x, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->y, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->z, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline size_t sbp_packed_size_sbp_ephemeris_common_content_t(const sbp_ephemeris_common_content_t *msg)
{
  (void)msg;
  return 0 + (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code)) + (0 + sizeof(msg->toe.tow) + sizeof(msg->toe.wn)) +
         sizeof(msg->ura) + sizeof(msg->fit_interval) + sizeof(msg->valid) + sizeof(msg->health_bits);
}

static inline bool
sbp_pack_sbp_ephemeris_common_content_t(u8 *buf, size_t len, const sbp_ephemeris_common_content_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_ephemeris_common_content_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidsat = msg->sid.sat;
  memcpy(buf + offset, &msgsidsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtoetow = htole32(msg->toe.tow);
  memcpy(buf + offset, &msgtoetow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtoewn = htole16(msg->toe.wn);
  memcpy(buf + offset, &msgtoewn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgura = msg->ura;
  memcpy(buf + offset, &msgura, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgfit_interval = htole32(msg->fit_interval);
  memcpy(buf + offset, &msgfit_interval, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgvalid = msg->valid;
  memcpy(buf + offset, &msgvalid, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msghealth_bits = msg->health_bits;
  memcpy(buf + offset, &msghealth_bits, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool
sbp_unpack_sbp_ephemeris_common_content_t(const u8 *buf, size_t len, sbp_ephemeris_common_content_t *msg)
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
  memcpy(&msg->sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->toe.tow, buf + offset, 4);
  msg->toe.tow = le32toh(msg->toe.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->toe.wn, buf + offset, 2);
  msg->toe.wn = le16toh(msg->toe.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->ura, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->fit_interval, buf + offset, 4);
  msg->fit_interval = le32toh(msg->fit_interval);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t
sbp_packed_size_sbp_ephemeris_common_content_dep_b_t(const sbp_ephemeris_common_content_dep_b_t *msg)
{
  (void)msg;
  return 0 + (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code)) + (0 + sizeof(msg->toe.tow) + sizeof(msg->toe.wn)) +
         sizeof(msg->ura) + sizeof(msg->fit_interval) + sizeof(msg->valid) + sizeof(msg->health_bits);
}

static inline bool
sbp_pack_sbp_ephemeris_common_content_dep_b_t(u8 *buf, size_t len, const sbp_ephemeris_common_content_dep_b_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_ephemeris_common_content_dep_b_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidsat = msg->sid.sat;
  memcpy(buf + offset, &msgsidsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtoetow = htole32(msg->toe.tow);
  memcpy(buf + offset, &msgtoetow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtoewn = htole16(msg->toe.wn);
  memcpy(buf + offset, &msgtoewn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgura = msg->ura;
  memcpy(buf + offset, &msgura, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgfit_interval = htole32(msg->fit_interval);
  memcpy(buf + offset, &msgfit_interval, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgvalid = msg->valid;
  memcpy(buf + offset, &msgvalid, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msghealth_bits = msg->health_bits;
  memcpy(buf + offset, &msghealth_bits, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool
sbp_unpack_sbp_ephemeris_common_content_dep_b_t(const u8 *buf, size_t len, sbp_ephemeris_common_content_dep_b_t *msg)
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
  memcpy(&msg->sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->toe.tow, buf + offset, 4);
  msg->toe.tow = le32toh(msg->toe.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->toe.wn, buf + offset, 2);
  msg->toe.wn = le16toh(msg->toe.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->ura, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->fit_interval, buf + offset, 4);
  msg->fit_interval = le32toh(msg->fit_interval);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t
sbp_packed_size_sbp_ephemeris_common_content_dep_a_t(const sbp_ephemeris_common_content_dep_a_t *msg)
{
  (void)msg;
  return 0 + (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code) + sizeof(msg->sid.reserved)) +
         (0 + sizeof(msg->toe.tow) + sizeof(msg->toe.wn)) + sizeof(msg->ura) + sizeof(msg->fit_interval) +
         sizeof(msg->valid) + sizeof(msg->health_bits);
}

static inline bool
sbp_pack_sbp_ephemeris_common_content_dep_a_t(u8 *buf, size_t len, const sbp_ephemeris_common_content_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_ephemeris_common_content_dep_a_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgsidsat = htole16(msg->sid.sat);
  memcpy(buf + offset, &msgsidsat, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidreserved = msg->sid.reserved;
  memcpy(buf + offset, &msgsidreserved, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtoetow = htole32(msg->toe.tow);
  memcpy(buf + offset, &msgtoetow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtoewn = htole16(msg->toe.wn);
  memcpy(buf + offset, &msgtoewn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgura = msg->ura;
  memcpy(buf + offset, &msgura, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgfit_interval = htole32(msg->fit_interval);
  memcpy(buf + offset, &msgfit_interval, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgvalid = msg->valid;
  memcpy(buf + offset, &msgvalid, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msghealth_bits = msg->health_bits;
  memcpy(buf + offset, &msghealth_bits, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool
sbp_unpack_sbp_ephemeris_common_content_dep_a_t(const u8 *buf, size_t len, sbp_ephemeris_common_content_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->sid.sat, buf + offset, 2);
  msg->sid.sat = le16toh(msg->sid.sat);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.reserved, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->toe.tow, buf + offset, 4);
  msg->toe.tow = le32toh(msg->toe.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->toe.wn, buf + offset, 2);
  msg->toe.wn = le16toh(msg->toe.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->ura, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->fit_interval, buf + offset, 4);
  msg->fit_interval = le32toh(msg->fit_interval);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_gps_dep_e_t(const sbp_msg_ephemeris_gps_dep_e_t *msg)
{
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code) + sizeof(msg->common.sid.reserved)) +
          (0 + sizeof(msg->common.toe.tow) + sizeof(msg->common.toe.wn)) + sizeof(msg->common.ura) +
          sizeof(msg->common.fit_interval) + sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         sizeof(msg->tgd) + sizeof(msg->c_rs) + sizeof(msg->c_rc) + sizeof(msg->c_uc) + sizeof(msg->c_us) +
         sizeof(msg->c_ic) + sizeof(msg->c_is) + sizeof(msg->dn) + sizeof(msg->m0) + sizeof(msg->ecc) +
         sizeof(msg->sqrta) + sizeof(msg->omega0) + sizeof(msg->omegadot) + sizeof(msg->w) + sizeof(msg->inc) +
         sizeof(msg->inc_dot) + sizeof(msg->af0) + sizeof(msg->af1) + sizeof(msg->af2) +
         (0 + sizeof(msg->toc.tow) + sizeof(msg->toc.wn)) + sizeof(msg->iode) + sizeof(msg->iodc);
}

static inline bool sbp_pack_sbp_msg_ephemeris_gps_dep_e_t(u8 *buf, size_t len, const sbp_msg_ephemeris_gps_dep_e_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_gps_dep_e_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcommonsidsat = htole16(msg->common.sid.sat);
  memcpy(buf + offset, &msgcommonsidsat, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidreserved = msg->common.sid.reserved;
  memcpy(buf + offset, &msgcommonsidreserved, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommontoetow = htole32(msg->common.toe.tow);
  memcpy(buf + offset, &msgcommontoetow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcommontoewn = htole16(msg->common.toe.wn);
  memcpy(buf + offset, &msgcommontoewn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommonfit_interval = htole32(msg->common.fit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgtgd = msg->tgd;
  memcpy(buf + offset, &msgtgd, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_rs = msg->c_rs;
  memcpy(buf + offset, &msgc_rs, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_rc = msg->c_rc;
  memcpy(buf + offset, &msgc_rc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_uc = msg->c_uc;
  memcpy(buf + offset, &msgc_uc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_us = msg->c_us;
  memcpy(buf + offset, &msgc_us, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_ic = msg->c_ic;
  memcpy(buf + offset, &msgc_ic, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_is = msg->c_is;
  memcpy(buf + offset, &msgc_is, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgdn = msg->dn;
  memcpy(buf + offset, &msgdn, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgm0 = msg->m0;
  memcpy(buf + offset, &msgm0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgecc = msg->ecc;
  memcpy(buf + offset, &msgecc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgsqrta = msg->sqrta;
  memcpy(buf + offset, &msgsqrta, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgomega0 = msg->omega0;
  memcpy(buf + offset, &msgomega0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgomegadot = msg->omegadot;
  memcpy(buf + offset, &msgomegadot, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgw = msg->w;
  memcpy(buf + offset, &msgw, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msginc = msg->inc;
  memcpy(buf + offset, &msginc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msginc_dot = msg->inc_dot;
  memcpy(buf + offset, &msginc_dot, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgaf0 = msg->af0;
  memcpy(buf + offset, &msgaf0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgaf1 = msg->af1;
  memcpy(buf + offset, &msgaf1, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgaf2 = msg->af2;
  memcpy(buf + offset, &msgaf2, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtoctow = htole32(msg->toc.tow);
  memcpy(buf + offset, &msgtoctow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtocwn = htole16(msg->toc.wn);
  memcpy(buf + offset, &msgtocwn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgiode = msg->iode;
  memcpy(buf + offset, &msgiode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgiodc = htole16(msg->iodc);
  memcpy(buf + offset, &msgiodc, 2);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool
sbp_unpack_sbp_msg_ephemeris_gps_dep_e_t(const u8 *buf, size_t len, sbp_msg_ephemeris_gps_dep_e_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->common.sid.sat, buf + offset, 2);
  msg->common.sid.sat = le16toh(msg->common.sid.sat);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.sid.reserved, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.toe.tow, buf + offset, 4);
  msg->common.toe.tow = le32toh(msg->common.toe.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->common.toe.wn, buf + offset, 2);
  msg->common.toe.wn = le16toh(msg->common.toe.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->tgd, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_rs, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_rc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_uc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_us, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_ic, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_is, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->dn, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->m0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->ecc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->sqrta, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->omega0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->omegadot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->w, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->inc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->inc_dot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->af0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->af1, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->af2, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->toc.tow, buf + offset, 4);
  msg->toc.tow = le32toh(msg->toc.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->toc.wn, buf + offset, 2);
  msg->toc.wn = le16toh(msg->toc.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->iode, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->iodc, buf + offset, 2);
  msg->iodc = le16toh(msg->iodc);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_gps_dep_f_t(const sbp_msg_ephemeris_gps_dep_f_t *msg)
{
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code)) +
          (0 + sizeof(msg->common.toe.tow) + sizeof(msg->common.toe.wn)) + sizeof(msg->common.ura) +
          sizeof(msg->common.fit_interval) + sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         sizeof(msg->tgd) + sizeof(msg->c_rs) + sizeof(msg->c_rc) + sizeof(msg->c_uc) + sizeof(msg->c_us) +
         sizeof(msg->c_ic) + sizeof(msg->c_is) + sizeof(msg->dn) + sizeof(msg->m0) + sizeof(msg->ecc) +
         sizeof(msg->sqrta) + sizeof(msg->omega0) + sizeof(msg->omegadot) + sizeof(msg->w) + sizeof(msg->inc) +
         sizeof(msg->inc_dot) + sizeof(msg->af0) + sizeof(msg->af1) + sizeof(msg->af2) +
         (0 + sizeof(msg->toc.tow) + sizeof(msg->toc.wn)) + sizeof(msg->iode) + sizeof(msg->iodc);
}

static inline bool sbp_pack_sbp_msg_ephemeris_gps_dep_f_t(u8 *buf, size_t len, const sbp_msg_ephemeris_gps_dep_f_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_gps_dep_f_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidsat = msg->common.sid.sat;
  memcpy(buf + offset, &msgcommonsidsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommontoetow = htole32(msg->common.toe.tow);
  memcpy(buf + offset, &msgcommontoetow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcommontoewn = htole16(msg->common.toe.wn);
  memcpy(buf + offset, &msgcommontoewn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommonfit_interval = htole32(msg->common.fit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgtgd = msg->tgd;
  memcpy(buf + offset, &msgtgd, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_rs = msg->c_rs;
  memcpy(buf + offset, &msgc_rs, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_rc = msg->c_rc;
  memcpy(buf + offset, &msgc_rc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_uc = msg->c_uc;
  memcpy(buf + offset, &msgc_uc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_us = msg->c_us;
  memcpy(buf + offset, &msgc_us, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_ic = msg->c_ic;
  memcpy(buf + offset, &msgc_ic, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_is = msg->c_is;
  memcpy(buf + offset, &msgc_is, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgdn = msg->dn;
  memcpy(buf + offset, &msgdn, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgm0 = msg->m0;
  memcpy(buf + offset, &msgm0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgecc = msg->ecc;
  memcpy(buf + offset, &msgecc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgsqrta = msg->sqrta;
  memcpy(buf + offset, &msgsqrta, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgomega0 = msg->omega0;
  memcpy(buf + offset, &msgomega0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgomegadot = msg->omegadot;
  memcpy(buf + offset, &msgomegadot, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgw = msg->w;
  memcpy(buf + offset, &msgw, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msginc = msg->inc;
  memcpy(buf + offset, &msginc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msginc_dot = msg->inc_dot;
  memcpy(buf + offset, &msginc_dot, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgaf0 = msg->af0;
  memcpy(buf + offset, &msgaf0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgaf1 = msg->af1;
  memcpy(buf + offset, &msgaf1, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgaf2 = msg->af2;
  memcpy(buf + offset, &msgaf2, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtoctow = htole32(msg->toc.tow);
  memcpy(buf + offset, &msgtoctow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtocwn = htole16(msg->toc.wn);
  memcpy(buf + offset, &msgtocwn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgiode = msg->iode;
  memcpy(buf + offset, &msgiode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgiodc = htole16(msg->iodc);
  memcpy(buf + offset, &msgiodc, 2);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool
sbp_unpack_sbp_msg_ephemeris_gps_dep_f_t(const u8 *buf, size_t len, sbp_msg_ephemeris_gps_dep_f_t *msg)
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
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.toe.tow, buf + offset, 4);
  msg->common.toe.tow = le32toh(msg->common.toe.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->common.toe.wn, buf + offset, 2);
  msg->common.toe.wn = le16toh(msg->common.toe.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->tgd, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_rs, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_rc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_uc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_us, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_ic, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_is, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->dn, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->m0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->ecc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->sqrta, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->omega0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->omegadot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->w, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->inc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->inc_dot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->af0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->af1, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->af2, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->toc.tow, buf + offset, 4);
  msg->toc.tow = le32toh(msg->toc.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->toc.wn, buf + offset, 2);
  msg->toc.wn = le16toh(msg->toc.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->iode, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->iodc, buf + offset, 2);
  msg->iodc = le16toh(msg->iodc);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_gps_t(const sbp_msg_ephemeris_gps_t *msg)
{
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code)) +
          (0 + sizeof(msg->common.toe.tow) + sizeof(msg->common.toe.wn)) + sizeof(msg->common.ura) +
          sizeof(msg->common.fit_interval) + sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         sizeof(msg->tgd) + sizeof(msg->c_rs) + sizeof(msg->c_rc) + sizeof(msg->c_uc) + sizeof(msg->c_us) +
         sizeof(msg->c_ic) + sizeof(msg->c_is) + sizeof(msg->dn) + sizeof(msg->m0) + sizeof(msg->ecc) +
         sizeof(msg->sqrta) + sizeof(msg->omega0) + sizeof(msg->omegadot) + sizeof(msg->w) + sizeof(msg->inc) +
         sizeof(msg->inc_dot) + sizeof(msg->af0) + sizeof(msg->af1) + sizeof(msg->af2) +
         (0 + sizeof(msg->toc.tow) + sizeof(msg->toc.wn)) + sizeof(msg->iode) + sizeof(msg->iodc);
}

static inline bool sbp_pack_sbp_msg_ephemeris_gps_t(u8 *buf, size_t len, const sbp_msg_ephemeris_gps_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_gps_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidsat = msg->common.sid.sat;
  memcpy(buf + offset, &msgcommonsidsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommontoetow = htole32(msg->common.toe.tow);
  memcpy(buf + offset, &msgcommontoetow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcommontoewn = htole16(msg->common.toe.wn);
  memcpy(buf + offset, &msgcommontoewn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommonfit_interval = htole32(msg->common.fit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgtgd = msg->tgd;
  memcpy(buf + offset, &msgtgd, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgc_rs = msg->c_rs;
  memcpy(buf + offset, &msgc_rs, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgc_rc = msg->c_rc;
  memcpy(buf + offset, &msgc_rc, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgc_uc = msg->c_uc;
  memcpy(buf + offset, &msgc_uc, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgc_us = msg->c_us;
  memcpy(buf + offset, &msgc_us, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgc_ic = msg->c_ic;
  memcpy(buf + offset, &msgc_ic, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgc_is = msg->c_is;
  memcpy(buf + offset, &msgc_is, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgdn = msg->dn;
  memcpy(buf + offset, &msgdn, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgm0 = msg->m0;
  memcpy(buf + offset, &msgm0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgecc = msg->ecc;
  memcpy(buf + offset, &msgecc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgsqrta = msg->sqrta;
  memcpy(buf + offset, &msgsqrta, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgomega0 = msg->omega0;
  memcpy(buf + offset, &msgomega0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgomegadot = msg->omegadot;
  memcpy(buf + offset, &msgomegadot, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgw = msg->w;
  memcpy(buf + offset, &msgw, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msginc = msg->inc;
  memcpy(buf + offset, &msginc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msginc_dot = msg->inc_dot;
  memcpy(buf + offset, &msginc_dot, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgaf0 = msg->af0;
  memcpy(buf + offset, &msgaf0, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgaf1 = msg->af1;
  memcpy(buf + offset, &msgaf1, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgaf2 = msg->af2;
  memcpy(buf + offset, &msgaf2, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtoctow = htole32(msg->toc.tow);
  memcpy(buf + offset, &msgtoctow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtocwn = htole16(msg->toc.wn);
  memcpy(buf + offset, &msgtocwn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgiode = msg->iode;
  memcpy(buf + offset, &msgiode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgiodc = htole16(msg->iodc);
  memcpy(buf + offset, &msgiodc, 2);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_gps_t(const u8 *buf, size_t len, sbp_msg_ephemeris_gps_t *msg)
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
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.toe.tow, buf + offset, 4);
  msg->common.toe.tow = le32toh(msg->common.toe.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->common.toe.wn, buf + offset, 2);
  msg->common.toe.wn = le16toh(msg->common.toe.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->tgd, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c_rs, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c_rc, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c_uc, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c_us, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c_ic, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c_is, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->dn, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->m0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->ecc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->sqrta, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->omega0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->omegadot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->w, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->inc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->inc_dot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->af0, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->af1, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->af2, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->toc.tow, buf + offset, 4);
  msg->toc.tow = le32toh(msg->toc.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->toc.wn, buf + offset, 2);
  msg->toc.wn = le16toh(msg->toc.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->iode, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->iodc, buf + offset, 2);
  msg->iodc = le16toh(msg->iodc);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_qzss_t(const sbp_msg_ephemeris_qzss_t *msg)
{
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code)) +
          (0 + sizeof(msg->common.toe.tow) + sizeof(msg->common.toe.wn)) + sizeof(msg->common.ura) +
          sizeof(msg->common.fit_interval) + sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         sizeof(msg->tgd) + sizeof(msg->c_rs) + sizeof(msg->c_rc) + sizeof(msg->c_uc) + sizeof(msg->c_us) +
         sizeof(msg->c_ic) + sizeof(msg->c_is) + sizeof(msg->dn) + sizeof(msg->m0) + sizeof(msg->ecc) +
         sizeof(msg->sqrta) + sizeof(msg->omega0) + sizeof(msg->omegadot) + sizeof(msg->w) + sizeof(msg->inc) +
         sizeof(msg->inc_dot) + sizeof(msg->af0) + sizeof(msg->af1) + sizeof(msg->af2) +
         (0 + sizeof(msg->toc.tow) + sizeof(msg->toc.wn)) + sizeof(msg->iode) + sizeof(msg->iodc);
}

static inline bool sbp_pack_sbp_msg_ephemeris_qzss_t(u8 *buf, size_t len, const sbp_msg_ephemeris_qzss_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_qzss_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidsat = msg->common.sid.sat;
  memcpy(buf + offset, &msgcommonsidsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommontoetow = htole32(msg->common.toe.tow);
  memcpy(buf + offset, &msgcommontoetow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcommontoewn = htole16(msg->common.toe.wn);
  memcpy(buf + offset, &msgcommontoewn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommonfit_interval = htole32(msg->common.fit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgtgd = msg->tgd;
  memcpy(buf + offset, &msgtgd, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgc_rs = msg->c_rs;
  memcpy(buf + offset, &msgc_rs, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgc_rc = msg->c_rc;
  memcpy(buf + offset, &msgc_rc, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgc_uc = msg->c_uc;
  memcpy(buf + offset, &msgc_uc, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgc_us = msg->c_us;
  memcpy(buf + offset, &msgc_us, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgc_ic = msg->c_ic;
  memcpy(buf + offset, &msgc_ic, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgc_is = msg->c_is;
  memcpy(buf + offset, &msgc_is, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgdn = msg->dn;
  memcpy(buf + offset, &msgdn, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgm0 = msg->m0;
  memcpy(buf + offset, &msgm0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgecc = msg->ecc;
  memcpy(buf + offset, &msgecc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgsqrta = msg->sqrta;
  memcpy(buf + offset, &msgsqrta, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgomega0 = msg->omega0;
  memcpy(buf + offset, &msgomega0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgomegadot = msg->omegadot;
  memcpy(buf + offset, &msgomegadot, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgw = msg->w;
  memcpy(buf + offset, &msgw, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msginc = msg->inc;
  memcpy(buf + offset, &msginc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msginc_dot = msg->inc_dot;
  memcpy(buf + offset, &msginc_dot, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgaf0 = msg->af0;
  memcpy(buf + offset, &msgaf0, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgaf1 = msg->af1;
  memcpy(buf + offset, &msgaf1, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgaf2 = msg->af2;
  memcpy(buf + offset, &msgaf2, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtoctow = htole32(msg->toc.tow);
  memcpy(buf + offset, &msgtoctow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtocwn = htole16(msg->toc.wn);
  memcpy(buf + offset, &msgtocwn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgiode = msg->iode;
  memcpy(buf + offset, &msgiode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgiodc = htole16(msg->iodc);
  memcpy(buf + offset, &msgiodc, 2);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_qzss_t(const u8 *buf, size_t len, sbp_msg_ephemeris_qzss_t *msg)
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
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.toe.tow, buf + offset, 4);
  msg->common.toe.tow = le32toh(msg->common.toe.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->common.toe.wn, buf + offset, 2);
  msg->common.toe.wn = le16toh(msg->common.toe.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->tgd, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c_rs, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c_rc, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c_uc, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c_us, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c_ic, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c_is, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->dn, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->m0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->ecc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->sqrta, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->omega0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->omegadot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->w, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->inc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->inc_dot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->af0, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->af1, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->af2, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->toc.tow, buf + offset, 4);
  msg->toc.tow = le32toh(msg->toc.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->toc.wn, buf + offset, 2);
  msg->toc.wn = le16toh(msg->toc.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->iode, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->iodc, buf + offset, 2);
  msg->iodc = le16toh(msg->iodc);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_bds_t(const sbp_msg_ephemeris_bds_t *msg)
{
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code)) +
          (0 + sizeof(msg->common.toe.tow) + sizeof(msg->common.toe.wn)) + sizeof(msg->common.ura) +
          sizeof(msg->common.fit_interval) + sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         sizeof(msg->tgd1) + sizeof(msg->tgd2) + sizeof(msg->c_rs) + sizeof(msg->c_rc) + sizeof(msg->c_uc) +
         sizeof(msg->c_us) + sizeof(msg->c_ic) + sizeof(msg->c_is) + sizeof(msg->dn) + sizeof(msg->m0) +
         sizeof(msg->ecc) + sizeof(msg->sqrta) + sizeof(msg->omega0) + sizeof(msg->omegadot) + sizeof(msg->w) +
         sizeof(msg->inc) + sizeof(msg->inc_dot) + sizeof(msg->af0) + sizeof(msg->af1) + sizeof(msg->af2) +
         (0 + sizeof(msg->toc.tow) + sizeof(msg->toc.wn)) + sizeof(msg->iode) + sizeof(msg->iodc);
}

static inline bool sbp_pack_sbp_msg_ephemeris_bds_t(u8 *buf, size_t len, const sbp_msg_ephemeris_bds_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_bds_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidsat = msg->common.sid.sat;
  memcpy(buf + offset, &msgcommonsidsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommontoetow = htole32(msg->common.toe.tow);
  memcpy(buf + offset, &msgcommontoetow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcommontoewn = htole16(msg->common.toe.wn);
  memcpy(buf + offset, &msgcommontoewn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommonfit_interval = htole32(msg->common.fit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgtgd1 = msg->tgd1;
  memcpy(buf + offset, &msgtgd1, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgtgd2 = msg->tgd2;
  memcpy(buf + offset, &msgtgd2, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgc_rs = msg->c_rs;
  memcpy(buf + offset, &msgc_rs, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgc_rc = msg->c_rc;
  memcpy(buf + offset, &msgc_rc, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgc_uc = msg->c_uc;
  memcpy(buf + offset, &msgc_uc, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgc_us = msg->c_us;
  memcpy(buf + offset, &msgc_us, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgc_ic = msg->c_ic;
  memcpy(buf + offset, &msgc_ic, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgc_is = msg->c_is;
  memcpy(buf + offset, &msgc_is, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgdn = msg->dn;
  memcpy(buf + offset, &msgdn, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgm0 = msg->m0;
  memcpy(buf + offset, &msgm0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgecc = msg->ecc;
  memcpy(buf + offset, &msgecc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgsqrta = msg->sqrta;
  memcpy(buf + offset, &msgsqrta, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgomega0 = msg->omega0;
  memcpy(buf + offset, &msgomega0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgomegadot = msg->omegadot;
  memcpy(buf + offset, &msgomegadot, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgw = msg->w;
  memcpy(buf + offset, &msgw, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msginc = msg->inc;
  memcpy(buf + offset, &msginc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msginc_dot = msg->inc_dot;
  memcpy(buf + offset, &msginc_dot, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgaf0 = msg->af0;
  memcpy(buf + offset, &msgaf0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgaf1 = msg->af1;
  memcpy(buf + offset, &msgaf1, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgaf2 = msg->af2;
  memcpy(buf + offset, &msgaf2, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtoctow = htole32(msg->toc.tow);
  memcpy(buf + offset, &msgtoctow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtocwn = htole16(msg->toc.wn);
  memcpy(buf + offset, &msgtocwn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgiode = msg->iode;
  memcpy(buf + offset, &msgiode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgiodc = htole16(msg->iodc);
  memcpy(buf + offset, &msgiodc, 2);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_bds_t(const u8 *buf, size_t len, sbp_msg_ephemeris_bds_t *msg)
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
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.toe.tow, buf + offset, 4);
  msg->common.toe.tow = le32toh(msg->common.toe.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->common.toe.wn, buf + offset, 2);
  msg->common.toe.wn = le16toh(msg->common.toe.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->tgd1, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->tgd2, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c_rs, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c_rc, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c_uc, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c_us, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c_ic, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c_is, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->dn, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->m0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->ecc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->sqrta, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->omega0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->omegadot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->w, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->inc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->inc_dot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->af0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->af1, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->af2, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->toc.tow, buf + offset, 4);
  msg->toc.tow = le32toh(msg->toc.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->toc.wn, buf + offset, 2);
  msg->toc.wn = le16toh(msg->toc.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->iode, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->iodc, buf + offset, 2);
  msg->iodc = le16toh(msg->iodc);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_gal_dep_a_t(const sbp_msg_ephemeris_gal_dep_a_t *msg)
{
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code)) +
          (0 + sizeof(msg->common.toe.tow) + sizeof(msg->common.toe.wn)) + sizeof(msg->common.ura) +
          sizeof(msg->common.fit_interval) + sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         sizeof(msg->bgd_e1e5a) + sizeof(msg->bgd_e1e5b) + sizeof(msg->c_rs) + sizeof(msg->c_rc) + sizeof(msg->c_uc) +
         sizeof(msg->c_us) + sizeof(msg->c_ic) + sizeof(msg->c_is) + sizeof(msg->dn) + sizeof(msg->m0) +
         sizeof(msg->ecc) + sizeof(msg->sqrta) + sizeof(msg->omega0) + sizeof(msg->omegadot) + sizeof(msg->w) +
         sizeof(msg->inc) + sizeof(msg->inc_dot) + sizeof(msg->af0) + sizeof(msg->af1) + sizeof(msg->af2) +
         (0 + sizeof(msg->toc.tow) + sizeof(msg->toc.wn)) + sizeof(msg->iode) + sizeof(msg->iodc);
}

static inline bool sbp_pack_sbp_msg_ephemeris_gal_dep_a_t(u8 *buf, size_t len, const sbp_msg_ephemeris_gal_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_gal_dep_a_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidsat = msg->common.sid.sat;
  memcpy(buf + offset, &msgcommonsidsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommontoetow = htole32(msg->common.toe.tow);
  memcpy(buf + offset, &msgcommontoetow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcommontoewn = htole16(msg->common.toe.wn);
  memcpy(buf + offset, &msgcommontoewn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommonfit_interval = htole32(msg->common.fit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgbgd_e1e5a = msg->bgd_e1e5a;
  memcpy(buf + offset, &msgbgd_e1e5a, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgbgd_e1e5b = msg->bgd_e1e5b;
  memcpy(buf + offset, &msgbgd_e1e5b, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgc_rs = msg->c_rs;
  memcpy(buf + offset, &msgc_rs, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgc_rc = msg->c_rc;
  memcpy(buf + offset, &msgc_rc, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgc_uc = msg->c_uc;
  memcpy(buf + offset, &msgc_uc, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgc_us = msg->c_us;
  memcpy(buf + offset, &msgc_us, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgc_ic = msg->c_ic;
  memcpy(buf + offset, &msgc_ic, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgc_is = msg->c_is;
  memcpy(buf + offset, &msgc_is, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgdn = msg->dn;
  memcpy(buf + offset, &msgdn, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgm0 = msg->m0;
  memcpy(buf + offset, &msgm0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgecc = msg->ecc;
  memcpy(buf + offset, &msgecc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgsqrta = msg->sqrta;
  memcpy(buf + offset, &msgsqrta, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgomega0 = msg->omega0;
  memcpy(buf + offset, &msgomega0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgomegadot = msg->omegadot;
  memcpy(buf + offset, &msgomegadot, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgw = msg->w;
  memcpy(buf + offset, &msgw, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msginc = msg->inc;
  memcpy(buf + offset, &msginc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msginc_dot = msg->inc_dot;
  memcpy(buf + offset, &msginc_dot, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgaf0 = msg->af0;
  memcpy(buf + offset, &msgaf0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgaf1 = msg->af1;
  memcpy(buf + offset, &msgaf1, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgaf2 = msg->af2;
  memcpy(buf + offset, &msgaf2, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtoctow = htole32(msg->toc.tow);
  memcpy(buf + offset, &msgtoctow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtocwn = htole16(msg->toc.wn);
  memcpy(buf + offset, &msgtocwn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgiode = htole16(msg->iode);
  memcpy(buf + offset, &msgiode, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgiodc = htole16(msg->iodc);
  memcpy(buf + offset, &msgiodc, 2);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool
sbp_unpack_sbp_msg_ephemeris_gal_dep_a_t(const u8 *buf, size_t len, sbp_msg_ephemeris_gal_dep_a_t *msg)
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
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.toe.tow, buf + offset, 4);
  msg->common.toe.tow = le32toh(msg->common.toe.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->common.toe.wn, buf + offset, 2);
  msg->common.toe.wn = le16toh(msg->common.toe.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->bgd_e1e5a, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->bgd_e1e5b, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c_rs, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c_rc, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c_uc, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c_us, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c_ic, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c_is, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->dn, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->m0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->ecc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->sqrta, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->omega0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->omegadot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->w, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->inc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->inc_dot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->af0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->af1, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->af2, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->toc.tow, buf + offset, 4);
  msg->toc.tow = le32toh(msg->toc.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->toc.wn, buf + offset, 2);
  msg->toc.wn = le16toh(msg->toc.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->iode, buf + offset, 2);
  msg->iode = le16toh(msg->iode);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->iodc, buf + offset, 2);
  msg->iodc = le16toh(msg->iodc);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_gal_t(const sbp_msg_ephemeris_gal_t *msg)
{
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code)) +
          (0 + sizeof(msg->common.toe.tow) + sizeof(msg->common.toe.wn)) + sizeof(msg->common.ura) +
          sizeof(msg->common.fit_interval) + sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         sizeof(msg->bgd_e1e5a) + sizeof(msg->bgd_e1e5b) + sizeof(msg->c_rs) + sizeof(msg->c_rc) + sizeof(msg->c_uc) +
         sizeof(msg->c_us) + sizeof(msg->c_ic) + sizeof(msg->c_is) + sizeof(msg->dn) + sizeof(msg->m0) +
         sizeof(msg->ecc) + sizeof(msg->sqrta) + sizeof(msg->omega0) + sizeof(msg->omegadot) + sizeof(msg->w) +
         sizeof(msg->inc) + sizeof(msg->inc_dot) + sizeof(msg->af0) + sizeof(msg->af1) + sizeof(msg->af2) +
         (0 + sizeof(msg->toc.tow) + sizeof(msg->toc.wn)) + sizeof(msg->iode) + sizeof(msg->iodc) + sizeof(msg->source);
}

static inline bool sbp_pack_sbp_msg_ephemeris_gal_t(u8 *buf, size_t len, const sbp_msg_ephemeris_gal_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_gal_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidsat = msg->common.sid.sat;
  memcpy(buf + offset, &msgcommonsidsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommontoetow = htole32(msg->common.toe.tow);
  memcpy(buf + offset, &msgcommontoetow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcommontoewn = htole16(msg->common.toe.wn);
  memcpy(buf + offset, &msgcommontoewn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommonfit_interval = htole32(msg->common.fit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgbgd_e1e5a = msg->bgd_e1e5a;
  memcpy(buf + offset, &msgbgd_e1e5a, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgbgd_e1e5b = msg->bgd_e1e5b;
  memcpy(buf + offset, &msgbgd_e1e5b, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgc_rs = msg->c_rs;
  memcpy(buf + offset, &msgc_rs, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgc_rc = msg->c_rc;
  memcpy(buf + offset, &msgc_rc, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgc_uc = msg->c_uc;
  memcpy(buf + offset, &msgc_uc, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgc_us = msg->c_us;
  memcpy(buf + offset, &msgc_us, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgc_ic = msg->c_ic;
  memcpy(buf + offset, &msgc_ic, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgc_is = msg->c_is;
  memcpy(buf + offset, &msgc_is, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgdn = msg->dn;
  memcpy(buf + offset, &msgdn, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgm0 = msg->m0;
  memcpy(buf + offset, &msgm0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgecc = msg->ecc;
  memcpy(buf + offset, &msgecc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgsqrta = msg->sqrta;
  memcpy(buf + offset, &msgsqrta, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgomega0 = msg->omega0;
  memcpy(buf + offset, &msgomega0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgomegadot = msg->omegadot;
  memcpy(buf + offset, &msgomegadot, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgw = msg->w;
  memcpy(buf + offset, &msgw, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msginc = msg->inc;
  memcpy(buf + offset, &msginc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msginc_dot = msg->inc_dot;
  memcpy(buf + offset, &msginc_dot, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgaf0 = msg->af0;
  memcpy(buf + offset, &msgaf0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgaf1 = msg->af1;
  memcpy(buf + offset, &msgaf1, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgaf2 = msg->af2;
  memcpy(buf + offset, &msgaf2, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtoctow = htole32(msg->toc.tow);
  memcpy(buf + offset, &msgtoctow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtocwn = htole16(msg->toc.wn);
  memcpy(buf + offset, &msgtocwn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgiode = htole16(msg->iode);
  memcpy(buf + offset, &msgiode, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgiodc = htole16(msg->iodc);
  memcpy(buf + offset, &msgiodc, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsource = msg->source;
  memcpy(buf + offset, &msgsource, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_gal_t(const u8 *buf, size_t len, sbp_msg_ephemeris_gal_t *msg)
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
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.toe.tow, buf + offset, 4);
  msg->common.toe.tow = le32toh(msg->common.toe.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->common.toe.wn, buf + offset, 2);
  msg->common.toe.wn = le16toh(msg->common.toe.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->bgd_e1e5a, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->bgd_e1e5b, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c_rs, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c_rc, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c_uc, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c_us, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c_ic, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c_is, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->dn, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->m0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->ecc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->sqrta, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->omega0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->omegadot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->w, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->inc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->inc_dot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->af0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->af1, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->af2, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->toc.tow, buf + offset, 4);
  msg->toc.tow = le32toh(msg->toc.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->toc.wn, buf + offset, 2);
  msg->toc.wn = le16toh(msg->toc.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->iode, buf + offset, 2);
  msg->iode = le16toh(msg->iode);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->iodc, buf + offset, 2);
  msg->iodc = le16toh(msg->iodc);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->source, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_sbas_dep_a_t(const sbp_msg_ephemeris_sbas_dep_a_t *msg)
{
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code) + sizeof(msg->common.sid.reserved)) +
          (0 + sizeof(msg->common.toe.tow) + sizeof(msg->common.toe.wn)) + sizeof(msg->common.ura) +
          sizeof(msg->common.fit_interval) + sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         (3 * sizeof(msg->pos[0])) + (3 * sizeof(msg->vel[0])) + (3 * sizeof(msg->acc[0])) + sizeof(msg->a_gf0) +
         sizeof(msg->a_gf1);
}

static inline bool
sbp_pack_sbp_msg_ephemeris_sbas_dep_a_t(u8 *buf, size_t len, const sbp_msg_ephemeris_sbas_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_sbas_dep_a_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcommonsidsat = htole16(msg->common.sid.sat);
  memcpy(buf + offset, &msgcommonsidsat, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidreserved = msg->common.sid.reserved;
  memcpy(buf + offset, &msgcommonsidreserved, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommontoetow = htole32(msg->common.toe.tow);
  memcpy(buf + offset, &msgcommontoetow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcommontoewn = htole16(msg->common.toe.wn);
  memcpy(buf + offset, &msgcommontoewn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommonfit_interval = htole32(msg->common.fit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    double msgposmsgpos_idx = msg->pos[msgpos_idx];
    memcpy(buf + offset, &msgposmsgpos_idx, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }
  for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    double msgvelmsgvel_idx = msg->vel[msgvel_idx];
    memcpy(buf + offset, &msgvelmsgvel_idx, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }
  for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    double msgaccmsgacc_idx = msg->acc[msgacc_idx];
    memcpy(buf + offset, &msgaccmsgacc_idx, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }

  if (offset + 8 > len)
  {
    return false;
  }
  double msga_gf0 = msg->a_gf0;
  memcpy(buf + offset, &msga_gf0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msga_gf1 = msg->a_gf1;
  memcpy(buf + offset, &msga_gf1, 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline bool
sbp_unpack_sbp_msg_ephemeris_sbas_dep_a_t(const u8 *buf, size_t len, sbp_msg_ephemeris_sbas_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->common.sid.sat, buf + offset, 2);
  msg->common.sid.sat = le16toh(msg->common.sid.sat);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.sid.reserved, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.toe.tow, buf + offset, 4);
  msg->common.toe.tow = le32toh(msg->common.toe.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->common.toe.wn, buf + offset, 2);
  msg->common.toe.wn = le16toh(msg->common.toe.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    memcpy(&msg->pos[msgpos_idx], buf + offset, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }
  for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    memcpy(&msg->vel[msgvel_idx], buf + offset, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }
  for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    memcpy(&msg->acc[msgacc_idx], buf + offset, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->a_gf0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->a_gf1, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_glo_dep_a_t(const sbp_msg_ephemeris_glo_dep_a_t *msg)
{
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code) + sizeof(msg->common.sid.reserved)) +
          (0 + sizeof(msg->common.toe.tow) + sizeof(msg->common.toe.wn)) + sizeof(msg->common.ura) +
          sizeof(msg->common.fit_interval) + sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         sizeof(msg->gamma) + sizeof(msg->tau) + (3 * sizeof(msg->pos[0])) + (3 * sizeof(msg->vel[0])) +
         (3 * sizeof(msg->acc[0]));
}

static inline bool sbp_pack_sbp_msg_ephemeris_glo_dep_a_t(u8 *buf, size_t len, const sbp_msg_ephemeris_glo_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_glo_dep_a_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcommonsidsat = htole16(msg->common.sid.sat);
  memcpy(buf + offset, &msgcommonsidsat, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidreserved = msg->common.sid.reserved;
  memcpy(buf + offset, &msgcommonsidreserved, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommontoetow = htole32(msg->common.toe.tow);
  memcpy(buf + offset, &msgcommontoetow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcommontoewn = htole16(msg->common.toe.wn);
  memcpy(buf + offset, &msgcommontoewn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommonfit_interval = htole32(msg->common.fit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 8 > len)
  {
    return false;
  }
  double msggamma = msg->gamma;
  memcpy(buf + offset, &msggamma, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgtau = msg->tau;
  memcpy(buf + offset, &msgtau, 8);
  // NOLINTNEXTLINE
  offset += 8;
  for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    double msgposmsgpos_idx = msg->pos[msgpos_idx];
    memcpy(buf + offset, &msgposmsgpos_idx, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }
  for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    double msgvelmsgvel_idx = msg->vel[msgvel_idx];
    memcpy(buf + offset, &msgvelmsgvel_idx, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }
  for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    double msgaccmsgacc_idx = msg->acc[msgacc_idx];
    memcpy(buf + offset, &msgaccmsgacc_idx, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }
  return true;
}

static inline bool
sbp_unpack_sbp_msg_ephemeris_glo_dep_a_t(const u8 *buf, size_t len, sbp_msg_ephemeris_glo_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->common.sid.sat, buf + offset, 2);
  msg->common.sid.sat = le16toh(msg->common.sid.sat);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.sid.reserved, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.toe.tow, buf + offset, 4);
  msg->common.toe.tow = le32toh(msg->common.toe.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->common.toe.wn, buf + offset, 2);
  msg->common.toe.wn = le16toh(msg->common.toe.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->gamma, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->tau, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
  for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    memcpy(&msg->pos[msgpos_idx], buf + offset, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }
  for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    memcpy(&msg->vel[msgvel_idx], buf + offset, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }
  for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    memcpy(&msg->acc[msgacc_idx], buf + offset, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_sbas_dep_b_t(const sbp_msg_ephemeris_sbas_dep_b_t *msg)
{
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code)) +
          (0 + sizeof(msg->common.toe.tow) + sizeof(msg->common.toe.wn)) + sizeof(msg->common.ura) +
          sizeof(msg->common.fit_interval) + sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         (3 * sizeof(msg->pos[0])) + (3 * sizeof(msg->vel[0])) + (3 * sizeof(msg->acc[0])) + sizeof(msg->a_gf0) +
         sizeof(msg->a_gf1);
}

static inline bool
sbp_pack_sbp_msg_ephemeris_sbas_dep_b_t(u8 *buf, size_t len, const sbp_msg_ephemeris_sbas_dep_b_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_sbas_dep_b_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidsat = msg->common.sid.sat;
  memcpy(buf + offset, &msgcommonsidsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommontoetow = htole32(msg->common.toe.tow);
  memcpy(buf + offset, &msgcommontoetow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcommontoewn = htole16(msg->common.toe.wn);
  memcpy(buf + offset, &msgcommontoewn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommonfit_interval = htole32(msg->common.fit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    double msgposmsgpos_idx = msg->pos[msgpos_idx];
    memcpy(buf + offset, &msgposmsgpos_idx, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }
  for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    double msgvelmsgvel_idx = msg->vel[msgvel_idx];
    memcpy(buf + offset, &msgvelmsgvel_idx, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }
  for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    double msgaccmsgacc_idx = msg->acc[msgacc_idx];
    memcpy(buf + offset, &msgaccmsgacc_idx, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }

  if (offset + 8 > len)
  {
    return false;
  }
  double msga_gf0 = msg->a_gf0;
  memcpy(buf + offset, &msga_gf0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msga_gf1 = msg->a_gf1;
  memcpy(buf + offset, &msga_gf1, 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline bool
sbp_unpack_sbp_msg_ephemeris_sbas_dep_b_t(const u8 *buf, size_t len, sbp_msg_ephemeris_sbas_dep_b_t *msg)
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
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.toe.tow, buf + offset, 4);
  msg->common.toe.tow = le32toh(msg->common.toe.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->common.toe.wn, buf + offset, 2);
  msg->common.toe.wn = le16toh(msg->common.toe.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    memcpy(&msg->pos[msgpos_idx], buf + offset, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }
  for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    memcpy(&msg->vel[msgvel_idx], buf + offset, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }
  for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    memcpy(&msg->acc[msgacc_idx], buf + offset, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->a_gf0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->a_gf1, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_sbas_t(const sbp_msg_ephemeris_sbas_t *msg)
{
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code)) +
          (0 + sizeof(msg->common.toe.tow) + sizeof(msg->common.toe.wn)) + sizeof(msg->common.ura) +
          sizeof(msg->common.fit_interval) + sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         (3 * sizeof(msg->pos[0])) + (3 * sizeof(msg->vel[0])) + (3 * sizeof(msg->acc[0])) + sizeof(msg->a_gf0) +
         sizeof(msg->a_gf1);
}

static inline bool sbp_pack_sbp_msg_ephemeris_sbas_t(u8 *buf, size_t len, const sbp_msg_ephemeris_sbas_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_sbas_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidsat = msg->common.sid.sat;
  memcpy(buf + offset, &msgcommonsidsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommontoetow = htole32(msg->common.toe.tow);
  memcpy(buf + offset, &msgcommontoetow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcommontoewn = htole16(msg->common.toe.wn);
  memcpy(buf + offset, &msgcommontoewn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommonfit_interval = htole32(msg->common.fit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    double msgposmsgpos_idx = msg->pos[msgpos_idx];
    memcpy(buf + offset, &msgposmsgpos_idx, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }
  for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++)
  {

    if (offset + 4 > len)
    {
      return false;
    }
    float msgvelmsgvel_idx = msg->vel[msgvel_idx];
    memcpy(buf + offset, &msgvelmsgvel_idx, 4);
    // NOLINTNEXTLINE
    offset += 4;
  }
  for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++)
  {

    if (offset + 4 > len)
    {
      return false;
    }
    float msgaccmsgacc_idx = msg->acc[msgacc_idx];
    memcpy(buf + offset, &msgaccmsgacc_idx, 4);
    // NOLINTNEXTLINE
    offset += 4;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  float msga_gf0 = msg->a_gf0;
  memcpy(buf + offset, &msga_gf0, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msga_gf1 = msg->a_gf1;
  memcpy(buf + offset, &msga_gf1, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_sbas_t(const u8 *buf, size_t len, sbp_msg_ephemeris_sbas_t *msg)
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
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.toe.tow, buf + offset, 4);
  msg->common.toe.tow = le32toh(msg->common.toe.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->common.toe.wn, buf + offset, 2);
  msg->common.toe.wn = le16toh(msg->common.toe.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    memcpy(&msg->pos[msgpos_idx], buf + offset, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }
  for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++)
  {

    if (offset + 4 > len)
    {
      return false;
    }
    memcpy(&msg->vel[msgvel_idx], buf + offset, 4);
    // NOLINTNEXTLINE
    offset += 4;
  }
  for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++)
  {

    if (offset + 4 > len)
    {
      return false;
    }
    memcpy(&msg->acc[msgacc_idx], buf + offset, 4);
    // NOLINTNEXTLINE
    offset += 4;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->a_gf0, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->a_gf1, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_glo_dep_b_t(const sbp_msg_ephemeris_glo_dep_b_t *msg)
{
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code)) +
          (0 + sizeof(msg->common.toe.tow) + sizeof(msg->common.toe.wn)) + sizeof(msg->common.ura) +
          sizeof(msg->common.fit_interval) + sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         sizeof(msg->gamma) + sizeof(msg->tau) + (3 * sizeof(msg->pos[0])) + (3 * sizeof(msg->vel[0])) +
         (3 * sizeof(msg->acc[0]));
}

static inline bool sbp_pack_sbp_msg_ephemeris_glo_dep_b_t(u8 *buf, size_t len, const sbp_msg_ephemeris_glo_dep_b_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_glo_dep_b_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidsat = msg->common.sid.sat;
  memcpy(buf + offset, &msgcommonsidsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommontoetow = htole32(msg->common.toe.tow);
  memcpy(buf + offset, &msgcommontoetow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcommontoewn = htole16(msg->common.toe.wn);
  memcpy(buf + offset, &msgcommontoewn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommonfit_interval = htole32(msg->common.fit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 8 > len)
  {
    return false;
  }
  double msggamma = msg->gamma;
  memcpy(buf + offset, &msggamma, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgtau = msg->tau;
  memcpy(buf + offset, &msgtau, 8);
  // NOLINTNEXTLINE
  offset += 8;
  for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    double msgposmsgpos_idx = msg->pos[msgpos_idx];
    memcpy(buf + offset, &msgposmsgpos_idx, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }
  for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    double msgvelmsgvel_idx = msg->vel[msgvel_idx];
    memcpy(buf + offset, &msgvelmsgvel_idx, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }
  for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    double msgaccmsgacc_idx = msg->acc[msgacc_idx];
    memcpy(buf + offset, &msgaccmsgacc_idx, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }
  return true;
}

static inline bool
sbp_unpack_sbp_msg_ephemeris_glo_dep_b_t(const u8 *buf, size_t len, sbp_msg_ephemeris_glo_dep_b_t *msg)
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
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.toe.tow, buf + offset, 4);
  msg->common.toe.tow = le32toh(msg->common.toe.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->common.toe.wn, buf + offset, 2);
  msg->common.toe.wn = le16toh(msg->common.toe.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->gamma, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->tau, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
  for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    memcpy(&msg->pos[msgpos_idx], buf + offset, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }
  for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    memcpy(&msg->vel[msgvel_idx], buf + offset, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }
  for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    memcpy(&msg->acc[msgacc_idx], buf + offset, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_glo_dep_c_t(const sbp_msg_ephemeris_glo_dep_c_t *msg)
{
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code)) +
          (0 + sizeof(msg->common.toe.tow) + sizeof(msg->common.toe.wn)) + sizeof(msg->common.ura) +
          sizeof(msg->common.fit_interval) + sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         sizeof(msg->gamma) + sizeof(msg->tau) + sizeof(msg->d_tau) + (3 * sizeof(msg->pos[0])) +
         (3 * sizeof(msg->vel[0])) + (3 * sizeof(msg->acc[0])) + sizeof(msg->fcn);
}

static inline bool sbp_pack_sbp_msg_ephemeris_glo_dep_c_t(u8 *buf, size_t len, const sbp_msg_ephemeris_glo_dep_c_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_glo_dep_c_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidsat = msg->common.sid.sat;
  memcpy(buf + offset, &msgcommonsidsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommontoetow = htole32(msg->common.toe.tow);
  memcpy(buf + offset, &msgcommontoetow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcommontoewn = htole16(msg->common.toe.wn);
  memcpy(buf + offset, &msgcommontoewn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommonfit_interval = htole32(msg->common.fit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 8 > len)
  {
    return false;
  }
  double msggamma = msg->gamma;
  memcpy(buf + offset, &msggamma, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgtau = msg->tau;
  memcpy(buf + offset, &msgtau, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgd_tau = msg->d_tau;
  memcpy(buf + offset, &msgd_tau, 8);
  // NOLINTNEXTLINE
  offset += 8;
  for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    double msgposmsgpos_idx = msg->pos[msgpos_idx];
    memcpy(buf + offset, &msgposmsgpos_idx, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }
  for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    double msgvelmsgvel_idx = msg->vel[msgvel_idx];
    memcpy(buf + offset, &msgvelmsgvel_idx, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }
  for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    double msgaccmsgacc_idx = msg->acc[msgacc_idx];
    memcpy(buf + offset, &msgaccmsgacc_idx, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgfcn = msg->fcn;
  memcpy(buf + offset, &msgfcn, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool
sbp_unpack_sbp_msg_ephemeris_glo_dep_c_t(const u8 *buf, size_t len, sbp_msg_ephemeris_glo_dep_c_t *msg)
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
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.toe.tow, buf + offset, 4);
  msg->common.toe.tow = le32toh(msg->common.toe.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->common.toe.wn, buf + offset, 2);
  msg->common.toe.wn = le16toh(msg->common.toe.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->gamma, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->tau, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->d_tau, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
  for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    memcpy(&msg->pos[msgpos_idx], buf + offset, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }
  for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    memcpy(&msg->vel[msgvel_idx], buf + offset, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }
  for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    memcpy(&msg->acc[msgacc_idx], buf + offset, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->fcn, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_glo_dep_d_t(const sbp_msg_ephemeris_glo_dep_d_t *msg)
{
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code)) +
          (0 + sizeof(msg->common.toe.tow) + sizeof(msg->common.toe.wn)) + sizeof(msg->common.ura) +
          sizeof(msg->common.fit_interval) + sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         sizeof(msg->gamma) + sizeof(msg->tau) + sizeof(msg->d_tau) + (3 * sizeof(msg->pos[0])) +
         (3 * sizeof(msg->vel[0])) + (3 * sizeof(msg->acc[0])) + sizeof(msg->fcn) + sizeof(msg->iod);
}

static inline bool sbp_pack_sbp_msg_ephemeris_glo_dep_d_t(u8 *buf, size_t len, const sbp_msg_ephemeris_glo_dep_d_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_glo_dep_d_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidsat = msg->common.sid.sat;
  memcpy(buf + offset, &msgcommonsidsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommontoetow = htole32(msg->common.toe.tow);
  memcpy(buf + offset, &msgcommontoetow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcommontoewn = htole16(msg->common.toe.wn);
  memcpy(buf + offset, &msgcommontoewn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommonfit_interval = htole32(msg->common.fit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 8 > len)
  {
    return false;
  }
  double msggamma = msg->gamma;
  memcpy(buf + offset, &msggamma, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgtau = msg->tau;
  memcpy(buf + offset, &msgtau, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgd_tau = msg->d_tau;
  memcpy(buf + offset, &msgd_tau, 8);
  // NOLINTNEXTLINE
  offset += 8;
  for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    double msgposmsgpos_idx = msg->pos[msgpos_idx];
    memcpy(buf + offset, &msgposmsgpos_idx, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }
  for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    double msgvelmsgvel_idx = msg->vel[msgvel_idx];
    memcpy(buf + offset, &msgvelmsgvel_idx, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }
  for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    double msgaccmsgacc_idx = msg->acc[msgacc_idx];
    memcpy(buf + offset, &msgaccmsgacc_idx, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgfcn = msg->fcn;
  memcpy(buf + offset, &msgfcn, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgiod = msg->iod;
  memcpy(buf + offset, &msgiod, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool
sbp_unpack_sbp_msg_ephemeris_glo_dep_d_t(const u8 *buf, size_t len, sbp_msg_ephemeris_glo_dep_d_t *msg)
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
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.toe.tow, buf + offset, 4);
  msg->common.toe.tow = le32toh(msg->common.toe.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->common.toe.wn, buf + offset, 2);
  msg->common.toe.wn = le16toh(msg->common.toe.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->gamma, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->tau, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->d_tau, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
  for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    memcpy(&msg->pos[msgpos_idx], buf + offset, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }
  for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    memcpy(&msg->vel[msgvel_idx], buf + offset, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }
  for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    memcpy(&msg->acc[msgacc_idx], buf + offset, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->fcn, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->iod, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_glo_t(const sbp_msg_ephemeris_glo_t *msg)
{
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code)) +
          (0 + sizeof(msg->common.toe.tow) + sizeof(msg->common.toe.wn)) + sizeof(msg->common.ura) +
          sizeof(msg->common.fit_interval) + sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         sizeof(msg->gamma) + sizeof(msg->tau) + sizeof(msg->d_tau) + (3 * sizeof(msg->pos[0])) +
         (3 * sizeof(msg->vel[0])) + (3 * sizeof(msg->acc[0])) + sizeof(msg->fcn) + sizeof(msg->iod);
}

static inline bool sbp_pack_sbp_msg_ephemeris_glo_t(u8 *buf, size_t len, const sbp_msg_ephemeris_glo_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_glo_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidsat = msg->common.sid.sat;
  memcpy(buf + offset, &msgcommonsidsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommontoetow = htole32(msg->common.toe.tow);
  memcpy(buf + offset, &msgcommontoetow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcommontoewn = htole16(msg->common.toe.wn);
  memcpy(buf + offset, &msgcommontoewn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommonfit_interval = htole32(msg->common.fit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  float msggamma = msg->gamma;
  memcpy(buf + offset, &msggamma, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgtau = msg->tau;
  memcpy(buf + offset, &msgtau, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgd_tau = msg->d_tau;
  memcpy(buf + offset, &msgd_tau, 4);
  // NOLINTNEXTLINE
  offset += 4;
  for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    double msgposmsgpos_idx = msg->pos[msgpos_idx];
    memcpy(buf + offset, &msgposmsgpos_idx, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }
  for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    double msgvelmsgvel_idx = msg->vel[msgvel_idx];
    memcpy(buf + offset, &msgvelmsgvel_idx, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }
  for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++)
  {

    if (offset + 4 > len)
    {
      return false;
    }
    float msgaccmsgacc_idx = msg->acc[msgacc_idx];
    memcpy(buf + offset, &msgaccmsgacc_idx, 4);
    // NOLINTNEXTLINE
    offset += 4;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgfcn = msg->fcn;
  memcpy(buf + offset, &msgfcn, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgiod = msg->iod;
  memcpy(buf + offset, &msgiod, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_glo_t(const u8 *buf, size_t len, sbp_msg_ephemeris_glo_t *msg)
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
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.toe.tow, buf + offset, 4);
  msg->common.toe.tow = le32toh(msg->common.toe.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->common.toe.wn, buf + offset, 2);
  msg->common.toe.wn = le16toh(msg->common.toe.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->gamma, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->tau, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->d_tau, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
  for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    memcpy(&msg->pos[msgpos_idx], buf + offset, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }
  for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    memcpy(&msg->vel[msgvel_idx], buf + offset, 8);
    // NOLINTNEXTLINE
    offset += 8;
  }
  for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++)
  {

    if (offset + 4 > len)
    {
      return false;
    }
    memcpy(&msg->acc[msgacc_idx], buf + offset, 4);
    // NOLINTNEXTLINE
    offset += 4;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->fcn, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->iod, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_dep_d_t(const sbp_msg_ephemeris_dep_d_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tgd) + sizeof(msg->c_rs) + sizeof(msg->c_rc) + sizeof(msg->c_uc) + sizeof(msg->c_us) +
         sizeof(msg->c_ic) + sizeof(msg->c_is) + sizeof(msg->dn) + sizeof(msg->m0) + sizeof(msg->ecc) +
         sizeof(msg->sqrta) + sizeof(msg->omega0) + sizeof(msg->omegadot) + sizeof(msg->w) + sizeof(msg->inc) +
         sizeof(msg->inc_dot) + sizeof(msg->af0) + sizeof(msg->af1) + sizeof(msg->af2) + sizeof(msg->toe_tow) +
         sizeof(msg->toe_wn) + sizeof(msg->toc_tow) + sizeof(msg->toc_wn) + sizeof(msg->valid) + sizeof(msg->healthy) +
         (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code) + sizeof(msg->sid.reserved)) + sizeof(msg->iode) +
         sizeof(msg->iodc) + sizeof(msg->reserved);
}

static inline bool sbp_pack_sbp_msg_ephemeris_dep_d_t(u8 *buf, size_t len, const sbp_msg_ephemeris_dep_d_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_dep_d_t(msg) > len)
  {
    return false;
  }

  if (offset + 8 > len)
  {
    return false;
  }
  double msgtgd = msg->tgd;
  memcpy(buf + offset, &msgtgd, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_rs = msg->c_rs;
  memcpy(buf + offset, &msgc_rs, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_rc = msg->c_rc;
  memcpy(buf + offset, &msgc_rc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_uc = msg->c_uc;
  memcpy(buf + offset, &msgc_uc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_us = msg->c_us;
  memcpy(buf + offset, &msgc_us, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_ic = msg->c_ic;
  memcpy(buf + offset, &msgc_ic, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_is = msg->c_is;
  memcpy(buf + offset, &msgc_is, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgdn = msg->dn;
  memcpy(buf + offset, &msgdn, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgm0 = msg->m0;
  memcpy(buf + offset, &msgm0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgecc = msg->ecc;
  memcpy(buf + offset, &msgecc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgsqrta = msg->sqrta;
  memcpy(buf + offset, &msgsqrta, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgomega0 = msg->omega0;
  memcpy(buf + offset, &msgomega0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgomegadot = msg->omegadot;
  memcpy(buf + offset, &msgomegadot, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgw = msg->w;
  memcpy(buf + offset, &msgw, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msginc = msg->inc;
  memcpy(buf + offset, &msginc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msginc_dot = msg->inc_dot;
  memcpy(buf + offset, &msginc_dot, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgaf0 = msg->af0;
  memcpy(buf + offset, &msgaf0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgaf1 = msg->af1;
  memcpy(buf + offset, &msgaf1, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgaf2 = msg->af2;
  memcpy(buf + offset, &msgaf2, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgtoe_tow = msg->toe_tow;
  memcpy(buf + offset, &msgtoe_tow, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtoe_wn = htole16(msg->toe_wn);
  memcpy(buf + offset, &msgtoe_wn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgtoc_tow = msg->toc_tow;
  memcpy(buf + offset, &msgtoc_tow, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtoc_wn = htole16(msg->toc_wn);
  memcpy(buf + offset, &msgtoc_wn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgvalid = msg->valid;
  memcpy(buf + offset, &msgvalid, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msghealthy = msg->healthy;
  memcpy(buf + offset, &msghealthy, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgsidsat = htole16(msg->sid.sat);
  memcpy(buf + offset, &msgsidsat, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidreserved = msg->sid.reserved;
  memcpy(buf + offset, &msgsidreserved, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgiode = msg->iode;
  memcpy(buf + offset, &msgiode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgiodc = htole16(msg->iodc);
  memcpy(buf + offset, &msgiodc, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgreserved = htole32(msg->reserved);
  memcpy(buf + offset, &msgreserved, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_dep_d_t(const u8 *buf, size_t len, sbp_msg_ephemeris_dep_d_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->tgd, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_rs, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_rc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_uc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_us, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_ic, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_is, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->dn, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->m0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->ecc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->sqrta, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->omega0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->omegadot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->w, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->inc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->inc_dot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->af0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->af1, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->af2, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->toe_tow, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->toe_wn, buf + offset, 2);
  msg->toe_wn = le16toh(msg->toe_wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->toc_tow, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->toc_wn, buf + offset, 2);
  msg->toc_wn = le16toh(msg->toc_wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->healthy, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->sid.sat, buf + offset, 2);
  msg->sid.sat = le16toh(msg->sid.sat);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.reserved, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->iode, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->iodc, buf + offset, 2);
  msg->iodc = le16toh(msg->iodc);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->reserved, buf + offset, 4);
  msg->reserved = le32toh(msg->reserved);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_dep_a_t(const sbp_msg_ephemeris_dep_a_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tgd) + sizeof(msg->c_rs) + sizeof(msg->c_rc) + sizeof(msg->c_uc) + sizeof(msg->c_us) +
         sizeof(msg->c_ic) + sizeof(msg->c_is) + sizeof(msg->dn) + sizeof(msg->m0) + sizeof(msg->ecc) +
         sizeof(msg->sqrta) + sizeof(msg->omega0) + sizeof(msg->omegadot) + sizeof(msg->w) + sizeof(msg->inc) +
         sizeof(msg->inc_dot) + sizeof(msg->af0) + sizeof(msg->af1) + sizeof(msg->af2) + sizeof(msg->toe_tow) +
         sizeof(msg->toe_wn) + sizeof(msg->toc_tow) + sizeof(msg->toc_wn) + sizeof(msg->valid) + sizeof(msg->healthy) +
         sizeof(msg->prn);
}

static inline bool sbp_pack_sbp_msg_ephemeris_dep_a_t(u8 *buf, size_t len, const sbp_msg_ephemeris_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_dep_a_t(msg) > len)
  {
    return false;
  }

  if (offset + 8 > len)
  {
    return false;
  }
  double msgtgd = msg->tgd;
  memcpy(buf + offset, &msgtgd, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_rs = msg->c_rs;
  memcpy(buf + offset, &msgc_rs, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_rc = msg->c_rc;
  memcpy(buf + offset, &msgc_rc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_uc = msg->c_uc;
  memcpy(buf + offset, &msgc_uc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_us = msg->c_us;
  memcpy(buf + offset, &msgc_us, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_ic = msg->c_ic;
  memcpy(buf + offset, &msgc_ic, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_is = msg->c_is;
  memcpy(buf + offset, &msgc_is, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgdn = msg->dn;
  memcpy(buf + offset, &msgdn, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgm0 = msg->m0;
  memcpy(buf + offset, &msgm0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgecc = msg->ecc;
  memcpy(buf + offset, &msgecc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgsqrta = msg->sqrta;
  memcpy(buf + offset, &msgsqrta, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgomega0 = msg->omega0;
  memcpy(buf + offset, &msgomega0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgomegadot = msg->omegadot;
  memcpy(buf + offset, &msgomegadot, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgw = msg->w;
  memcpy(buf + offset, &msgw, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msginc = msg->inc;
  memcpy(buf + offset, &msginc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msginc_dot = msg->inc_dot;
  memcpy(buf + offset, &msginc_dot, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgaf0 = msg->af0;
  memcpy(buf + offset, &msgaf0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgaf1 = msg->af1;
  memcpy(buf + offset, &msgaf1, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgaf2 = msg->af2;
  memcpy(buf + offset, &msgaf2, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgtoe_tow = msg->toe_tow;
  memcpy(buf + offset, &msgtoe_tow, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtoe_wn = htole16(msg->toe_wn);
  memcpy(buf + offset, &msgtoe_wn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgtoc_tow = msg->toc_tow;
  memcpy(buf + offset, &msgtoc_tow, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtoc_wn = htole16(msg->toc_wn);
  memcpy(buf + offset, &msgtoc_wn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgvalid = msg->valid;
  memcpy(buf + offset, &msgvalid, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msghealthy = msg->healthy;
  memcpy(buf + offset, &msghealthy, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgprn = msg->prn;
  memcpy(buf + offset, &msgprn, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_dep_a_t(const u8 *buf, size_t len, sbp_msg_ephemeris_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->tgd, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_rs, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_rc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_uc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_us, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_ic, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_is, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->dn, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->m0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->ecc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->sqrta, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->omega0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->omegadot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->w, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->inc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->inc_dot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->af0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->af1, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->af2, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->toe_tow, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->toe_wn, buf + offset, 2);
  msg->toe_wn = le16toh(msg->toe_wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->toc_tow, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->toc_wn, buf + offset, 2);
  msg->toc_wn = le16toh(msg->toc_wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->healthy, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->prn, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_dep_b_t(const sbp_msg_ephemeris_dep_b_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tgd) + sizeof(msg->c_rs) + sizeof(msg->c_rc) + sizeof(msg->c_uc) + sizeof(msg->c_us) +
         sizeof(msg->c_ic) + sizeof(msg->c_is) + sizeof(msg->dn) + sizeof(msg->m0) + sizeof(msg->ecc) +
         sizeof(msg->sqrta) + sizeof(msg->omega0) + sizeof(msg->omegadot) + sizeof(msg->w) + sizeof(msg->inc) +
         sizeof(msg->inc_dot) + sizeof(msg->af0) + sizeof(msg->af1) + sizeof(msg->af2) + sizeof(msg->toe_tow) +
         sizeof(msg->toe_wn) + sizeof(msg->toc_tow) + sizeof(msg->toc_wn) + sizeof(msg->valid) + sizeof(msg->healthy) +
         sizeof(msg->prn) + sizeof(msg->iode);
}

static inline bool sbp_pack_sbp_msg_ephemeris_dep_b_t(u8 *buf, size_t len, const sbp_msg_ephemeris_dep_b_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_dep_b_t(msg) > len)
  {
    return false;
  }

  if (offset + 8 > len)
  {
    return false;
  }
  double msgtgd = msg->tgd;
  memcpy(buf + offset, &msgtgd, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_rs = msg->c_rs;
  memcpy(buf + offset, &msgc_rs, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_rc = msg->c_rc;
  memcpy(buf + offset, &msgc_rc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_uc = msg->c_uc;
  memcpy(buf + offset, &msgc_uc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_us = msg->c_us;
  memcpy(buf + offset, &msgc_us, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_ic = msg->c_ic;
  memcpy(buf + offset, &msgc_ic, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_is = msg->c_is;
  memcpy(buf + offset, &msgc_is, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgdn = msg->dn;
  memcpy(buf + offset, &msgdn, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgm0 = msg->m0;
  memcpy(buf + offset, &msgm0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgecc = msg->ecc;
  memcpy(buf + offset, &msgecc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgsqrta = msg->sqrta;
  memcpy(buf + offset, &msgsqrta, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgomega0 = msg->omega0;
  memcpy(buf + offset, &msgomega0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgomegadot = msg->omegadot;
  memcpy(buf + offset, &msgomegadot, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgw = msg->w;
  memcpy(buf + offset, &msgw, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msginc = msg->inc;
  memcpy(buf + offset, &msginc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msginc_dot = msg->inc_dot;
  memcpy(buf + offset, &msginc_dot, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgaf0 = msg->af0;
  memcpy(buf + offset, &msgaf0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgaf1 = msg->af1;
  memcpy(buf + offset, &msgaf1, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgaf2 = msg->af2;
  memcpy(buf + offset, &msgaf2, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgtoe_tow = msg->toe_tow;
  memcpy(buf + offset, &msgtoe_tow, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtoe_wn = htole16(msg->toe_wn);
  memcpy(buf + offset, &msgtoe_wn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgtoc_tow = msg->toc_tow;
  memcpy(buf + offset, &msgtoc_tow, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtoc_wn = htole16(msg->toc_wn);
  memcpy(buf + offset, &msgtoc_wn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgvalid = msg->valid;
  memcpy(buf + offset, &msgvalid, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msghealthy = msg->healthy;
  memcpy(buf + offset, &msghealthy, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgprn = msg->prn;
  memcpy(buf + offset, &msgprn, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgiode = msg->iode;
  memcpy(buf + offset, &msgiode, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_dep_b_t(const u8 *buf, size_t len, sbp_msg_ephemeris_dep_b_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->tgd, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_rs, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_rc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_uc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_us, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_ic, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_is, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->dn, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->m0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->ecc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->sqrta, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->omega0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->omegadot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->w, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->inc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->inc_dot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->af0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->af1, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->af2, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->toe_tow, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->toe_wn, buf + offset, 2);
  msg->toe_wn = le16toh(msg->toe_wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->toc_tow, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->toc_wn, buf + offset, 2);
  msg->toc_wn = le16toh(msg->toc_wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->healthy, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->prn, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->iode, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ephemeris_dep_c_t(const sbp_msg_ephemeris_dep_c_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tgd) + sizeof(msg->c_rs) + sizeof(msg->c_rc) + sizeof(msg->c_uc) + sizeof(msg->c_us) +
         sizeof(msg->c_ic) + sizeof(msg->c_is) + sizeof(msg->dn) + sizeof(msg->m0) + sizeof(msg->ecc) +
         sizeof(msg->sqrta) + sizeof(msg->omega0) + sizeof(msg->omegadot) + sizeof(msg->w) + sizeof(msg->inc) +
         sizeof(msg->inc_dot) + sizeof(msg->af0) + sizeof(msg->af1) + sizeof(msg->af2) + sizeof(msg->toe_tow) +
         sizeof(msg->toe_wn) + sizeof(msg->toc_tow) + sizeof(msg->toc_wn) + sizeof(msg->valid) + sizeof(msg->healthy) +
         (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code) + sizeof(msg->sid.reserved)) + sizeof(msg->iode) +
         sizeof(msg->iodc) + sizeof(msg->reserved);
}

static inline bool sbp_pack_sbp_msg_ephemeris_dep_c_t(u8 *buf, size_t len, const sbp_msg_ephemeris_dep_c_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_dep_c_t(msg) > len)
  {
    return false;
  }

  if (offset + 8 > len)
  {
    return false;
  }
  double msgtgd = msg->tgd;
  memcpy(buf + offset, &msgtgd, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_rs = msg->c_rs;
  memcpy(buf + offset, &msgc_rs, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_rc = msg->c_rc;
  memcpy(buf + offset, &msgc_rc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_uc = msg->c_uc;
  memcpy(buf + offset, &msgc_uc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_us = msg->c_us;
  memcpy(buf + offset, &msgc_us, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_ic = msg->c_ic;
  memcpy(buf + offset, &msgc_ic, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgc_is = msg->c_is;
  memcpy(buf + offset, &msgc_is, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgdn = msg->dn;
  memcpy(buf + offset, &msgdn, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgm0 = msg->m0;
  memcpy(buf + offset, &msgm0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgecc = msg->ecc;
  memcpy(buf + offset, &msgecc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgsqrta = msg->sqrta;
  memcpy(buf + offset, &msgsqrta, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgomega0 = msg->omega0;
  memcpy(buf + offset, &msgomega0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgomegadot = msg->omegadot;
  memcpy(buf + offset, &msgomegadot, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgw = msg->w;
  memcpy(buf + offset, &msgw, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msginc = msg->inc;
  memcpy(buf + offset, &msginc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msginc_dot = msg->inc_dot;
  memcpy(buf + offset, &msginc_dot, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgaf0 = msg->af0;
  memcpy(buf + offset, &msgaf0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgaf1 = msg->af1;
  memcpy(buf + offset, &msgaf1, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgaf2 = msg->af2;
  memcpy(buf + offset, &msgaf2, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgtoe_tow = msg->toe_tow;
  memcpy(buf + offset, &msgtoe_tow, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtoe_wn = htole16(msg->toe_wn);
  memcpy(buf + offset, &msgtoe_wn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgtoc_tow = msg->toc_tow;
  memcpy(buf + offset, &msgtoc_tow, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtoc_wn = htole16(msg->toc_wn);
  memcpy(buf + offset, &msgtoc_wn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgvalid = msg->valid;
  memcpy(buf + offset, &msgvalid, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msghealthy = msg->healthy;
  memcpy(buf + offset, &msghealthy, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgsidsat = htole16(msg->sid.sat);
  memcpy(buf + offset, &msgsidsat, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidreserved = msg->sid.reserved;
  memcpy(buf + offset, &msgsidreserved, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgiode = msg->iode;
  memcpy(buf + offset, &msgiode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgiodc = htole16(msg->iodc);
  memcpy(buf + offset, &msgiodc, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgreserved = htole32(msg->reserved);
  memcpy(buf + offset, &msgreserved, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_dep_c_t(const u8 *buf, size_t len, sbp_msg_ephemeris_dep_c_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->tgd, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_rs, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_rc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_uc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_us, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_ic, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->c_is, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->dn, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->m0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->ecc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->sqrta, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->omega0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->omegadot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->w, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->inc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->inc_dot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->af0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->af1, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->af2, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->toe_tow, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->toe_wn, buf + offset, 2);
  msg->toe_wn = le16toh(msg->toe_wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->toc_tow, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->toc_wn, buf + offset, 2);
  msg->toc_wn = le16toh(msg->toc_wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->healthy, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->sid.sat, buf + offset, 2);
  msg->sid.sat = le16toh(msg->sid.sat);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.reserved, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->iode, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->iodc, buf + offset, 2);
  msg->iodc = le16toh(msg->iodc);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->reserved, buf + offset, 4);
  msg->reserved = le32toh(msg->reserved);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_observation_header_dep_t(const sbp_observation_header_dep_t *msg)
{
  (void)msg;
  return 0 + (0 + sizeof(msg->t.tow) + sizeof(msg->t.wn)) + sizeof(msg->n_obs);
}

static inline bool sbp_pack_sbp_observation_header_dep_t(u8 *buf, size_t len, const sbp_observation_header_dep_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_observation_header_dep_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgttow = htole32(msg->t.tow);
  memcpy(buf + offset, &msgttow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtwn = htole16(msg->t.wn);
  memcpy(buf + offset, &msgtwn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_obs = msg->n_obs;
  memcpy(buf + offset, &msgn_obs, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_observation_header_dep_t(const u8 *buf, size_t len, sbp_observation_header_dep_t *msg)
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
  memcpy(&msg->t.tow, buf + offset, 4);
  msg->t.tow = le32toh(msg->t.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->t.wn, buf + offset, 2);
  msg->t.wn = le16toh(msg->t.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_obs, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_carrier_phase_dep_a_t(const sbp_carrier_phase_dep_a_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->i) + sizeof(msg->f);
}

static inline bool sbp_pack_sbp_carrier_phase_dep_a_t(u8 *buf, size_t len, const sbp_carrier_phase_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_carrier_phase_dep_a_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgi = htole32(*(const u32 *)&msg->i);
  memcpy(buf + offset, &msgi, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgf = msg->f;
  memcpy(buf + offset, &msgf, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_carrier_phase_dep_a_t(const u8 *buf, size_t len, sbp_carrier_phase_dep_a_t *msg)
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
  memcpy(&msg->i, buf + offset, 4);
  u32 msgi = *(const u32 *)&msg->i;
  msgi = le32toh(msgi);
  msg->i = *(const s32 *)&msgi;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->f, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_packed_obs_content_dep_a_t(const sbp_packed_obs_content_dep_a_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->P) + (0 + sizeof(msg->L.i) + sizeof(msg->L.f)) + sizeof(msg->cn0) + sizeof(msg->lock) +
         sizeof(msg->prn);
}

static inline bool
sbp_pack_sbp_packed_obs_content_dep_a_t(u8 *buf, size_t len, const sbp_packed_obs_content_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_packed_obs_content_dep_a_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgP = htole32(msg->P);
  memcpy(buf + offset, &msgP, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgLi = htole32(*(const u32 *)&msg->L.i);
  memcpy(buf + offset, &msgLi, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgLf = msg->L.f;
  memcpy(buf + offset, &msgLf, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcn0 = msg->cn0;
  memcpy(buf + offset, &msgcn0, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msglock = htole16(msg->lock);
  memcpy(buf + offset, &msglock, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgprn = msg->prn;
  memcpy(buf + offset, &msgprn, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool
sbp_unpack_sbp_packed_obs_content_dep_a_t(const u8 *buf, size_t len, sbp_packed_obs_content_dep_a_t *msg)
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
  memcpy(&msg->P, buf + offset, 4);
  msg->P = le32toh(msg->P);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->L.i, buf + offset, 4);
  u32 msgLi = *(const u32 *)&msg->L.i;
  msgLi = le32toh(msgLi);
  msg->L.i = *(const s32 *)&msgLi;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->L.f, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->cn0, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->lock, buf + offset, 2);
  msg->lock = le16toh(msg->lock);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->prn, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_packed_obs_content_dep_b_t(const sbp_packed_obs_content_dep_b_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->P) + (0 + sizeof(msg->L.i) + sizeof(msg->L.f)) + sizeof(msg->cn0) + sizeof(msg->lock) +
         (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code) + sizeof(msg->sid.reserved));
}

static inline bool
sbp_pack_sbp_packed_obs_content_dep_b_t(u8 *buf, size_t len, const sbp_packed_obs_content_dep_b_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_packed_obs_content_dep_b_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgP = htole32(msg->P);
  memcpy(buf + offset, &msgP, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgLi = htole32(*(const u32 *)&msg->L.i);
  memcpy(buf + offset, &msgLi, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgLf = msg->L.f;
  memcpy(buf + offset, &msgLf, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcn0 = msg->cn0;
  memcpy(buf + offset, &msgcn0, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msglock = htole16(msg->lock);
  memcpy(buf + offset, &msglock, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgsidsat = htole16(msg->sid.sat);
  memcpy(buf + offset, &msgsidsat, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidreserved = msg->sid.reserved;
  memcpy(buf + offset, &msgsidreserved, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool
sbp_unpack_sbp_packed_obs_content_dep_b_t(const u8 *buf, size_t len, sbp_packed_obs_content_dep_b_t *msg)
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
  memcpy(&msg->P, buf + offset, 4);
  msg->P = le32toh(msg->P);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->L.i, buf + offset, 4);
  u32 msgLi = *(const u32 *)&msg->L.i;
  msgLi = le32toh(msgLi);
  msg->L.i = *(const s32 *)&msgLi;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->L.f, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->cn0, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->lock, buf + offset, 2);
  msg->lock = le16toh(msg->lock);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->sid.sat, buf + offset, 2);
  msg->sid.sat = le16toh(msg->sid.sat);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.reserved, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_packed_obs_content_dep_c_t(const sbp_packed_obs_content_dep_c_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->P) + (0 + sizeof(msg->L.i) + sizeof(msg->L.f)) + sizeof(msg->cn0) + sizeof(msg->lock) +
         (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code) + sizeof(msg->sid.reserved));
}

static inline bool
sbp_pack_sbp_packed_obs_content_dep_c_t(u8 *buf, size_t len, const sbp_packed_obs_content_dep_c_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_packed_obs_content_dep_c_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgP = htole32(msg->P);
  memcpy(buf + offset, &msgP, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgLi = htole32(*(const u32 *)&msg->L.i);
  memcpy(buf + offset, &msgLi, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgLf = msg->L.f;
  memcpy(buf + offset, &msgLf, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcn0 = msg->cn0;
  memcpy(buf + offset, &msgcn0, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msglock = htole16(msg->lock);
  memcpy(buf + offset, &msglock, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgsidsat = htole16(msg->sid.sat);
  memcpy(buf + offset, &msgsidsat, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidreserved = msg->sid.reserved;
  memcpy(buf + offset, &msgsidreserved, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool
sbp_unpack_sbp_packed_obs_content_dep_c_t(const u8 *buf, size_t len, sbp_packed_obs_content_dep_c_t *msg)
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
  memcpy(&msg->P, buf + offset, 4);
  msg->P = le32toh(msg->P);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->L.i, buf + offset, 4);
  u32 msgLi = *(const u32 *)&msg->L.i;
  msgLi = le32toh(msgLi);
  msg->L.i = *(const s32 *)&msgLi;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->L.f, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->cn0, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->lock, buf + offset, 2);
  msg->lock = le16toh(msg->lock);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->sid.sat, buf + offset, 2);
  msg->sid.sat = le16toh(msg->sid.sat);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.reserved, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_obs_dep_a_t(const sbp_msg_obs_dep_a_t *msg)
{
  (void)msg;
  return 0 + (0 + (0 + sizeof(msg->header.t.tow) + sizeof(msg->header.t.wn)) + sizeof(msg->header.n_obs)) +
         (msg->obs_count * (0 + sizeof(msg->obs[0].P) + (0 + sizeof(msg->obs[0].L.i) + sizeof(msg->obs[0].L.f)) +
                            sizeof(msg->obs[0].cn0) + sizeof(msg->obs[0].lock) + sizeof(msg->obs[0].prn)));
}

static inline bool sbp_pack_sbp_msg_obs_dep_a_t(u8 *buf, size_t len, const sbp_msg_obs_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_obs_dep_a_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgheaderttow = htole32(msg->header.t.tow);
  memcpy(buf + offset, &msgheaderttow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgheadertwn = htole16(msg->header.t.wn);
  memcpy(buf + offset, &msgheadertwn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgheadern_obs = msg->header.n_obs;
  memcpy(buf + offset, &msgheadern_obs, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgobs_idx = 0; msgobs_idx < (size_t)msg->obs_count; msgobs_idx++)
  {

    if (offset + 4 > len)
    {
      return false;
    }
    u32 msgobsmsgobs_idxP = htole32(msg->obs[msgobs_idx].P);
    memcpy(buf + offset, &msgobsmsgobs_idxP, 4);
    // NOLINTNEXTLINE
    offset += 4;

    if (offset + 4 > len)
    {
      return false;
    }
    u32 msgobsmsgobs_idxLi = htole32(*(const u32 *)&msg->obs[msgobs_idx].L.i);
    memcpy(buf + offset, &msgobsmsgobs_idxLi, 4);
    // NOLINTNEXTLINE
    offset += 4;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgobsmsgobs_idxLf = msg->obs[msgobs_idx].L.f;
    memcpy(buf + offset, &msgobsmsgobs_idxLf, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgobsmsgobs_idxcn0 = msg->obs[msgobs_idx].cn0;
    memcpy(buf + offset, &msgobsmsgobs_idxcn0, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 2 > len)
    {
      return false;
    }
    u16 msgobsmsgobs_idxlock = htole16(msg->obs[msgobs_idx].lock);
    memcpy(buf + offset, &msgobsmsgobs_idxlock, 2);
    // NOLINTNEXTLINE
    offset += 2;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgobsmsgobs_idxprn = msg->obs[msgobs_idx].prn;
    memcpy(buf + offset, &msgobsmsgobs_idxprn, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_obs_dep_a_t(const u8 *buf, size_t len, sbp_msg_obs_dep_a_t *msg)
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
  memcpy(&msg->header.t.tow, buf + offset, 4);
  msg->header.t.tow = le32toh(msg->header.t.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->header.t.wn, buf + offset, 2);
  msg->header.t.wn = le16toh(msg->header.t.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->header.n_obs, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  msg->obs_count = (u8)((len - offset) / 13);

  for (size_t msgobs_idx = 0; msgobs_idx < msg->obs_count; msgobs_idx++)
  {

    if (offset + 4 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].P, buf + offset, 4);
    msg->obs[msgobs_idx].P = le32toh(msg->obs[msgobs_idx].P);
    // NOLINTNEXTLINE
    offset += 4;

    if (offset + 4 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].L.i, buf + offset, 4);
    u32 msgobsmsgobs_idxLi = *(const u32 *)&msg->obs[msgobs_idx].L.i;
    msgobsmsgobs_idxLi = le32toh(msgobsmsgobs_idxLi);
    msg->obs[msgobs_idx].L.i = *(const s32 *)&msgobsmsgobs_idxLi;
    // NOLINTNEXTLINE
    offset += 4;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].L.f, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].cn0, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 2 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].lock, buf + offset, 2);
    msg->obs[msgobs_idx].lock = le16toh(msg->obs[msgobs_idx].lock);
    // NOLINTNEXTLINE
    offset += 2;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].prn, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_obs_dep_b_t(const sbp_msg_obs_dep_b_t *msg)
{
  (void)msg;
  return 0 + (0 + (0 + sizeof(msg->header.t.tow) + sizeof(msg->header.t.wn)) + sizeof(msg->header.n_obs)) +
         (msg->obs_count *
          (0 + sizeof(msg->obs[0].P) + (0 + sizeof(msg->obs[0].L.i) + sizeof(msg->obs[0].L.f)) +
           sizeof(msg->obs[0].cn0) + sizeof(msg->obs[0].lock) +
           (0 + sizeof(msg->obs[0].sid.sat) + sizeof(msg->obs[0].sid.code) + sizeof(msg->obs[0].sid.reserved))));
}

static inline bool sbp_pack_sbp_msg_obs_dep_b_t(u8 *buf, size_t len, const sbp_msg_obs_dep_b_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_obs_dep_b_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgheaderttow = htole32(msg->header.t.tow);
  memcpy(buf + offset, &msgheaderttow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgheadertwn = htole16(msg->header.t.wn);
  memcpy(buf + offset, &msgheadertwn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgheadern_obs = msg->header.n_obs;
  memcpy(buf + offset, &msgheadern_obs, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgobs_idx = 0; msgobs_idx < (size_t)msg->obs_count; msgobs_idx++)
  {

    if (offset + 4 > len)
    {
      return false;
    }
    u32 msgobsmsgobs_idxP = htole32(msg->obs[msgobs_idx].P);
    memcpy(buf + offset, &msgobsmsgobs_idxP, 4);
    // NOLINTNEXTLINE
    offset += 4;

    if (offset + 4 > len)
    {
      return false;
    }
    u32 msgobsmsgobs_idxLi = htole32(*(const u32 *)&msg->obs[msgobs_idx].L.i);
    memcpy(buf + offset, &msgobsmsgobs_idxLi, 4);
    // NOLINTNEXTLINE
    offset += 4;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgobsmsgobs_idxLf = msg->obs[msgobs_idx].L.f;
    memcpy(buf + offset, &msgobsmsgobs_idxLf, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgobsmsgobs_idxcn0 = msg->obs[msgobs_idx].cn0;
    memcpy(buf + offset, &msgobsmsgobs_idxcn0, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 2 > len)
    {
      return false;
    }
    u16 msgobsmsgobs_idxlock = htole16(msg->obs[msgobs_idx].lock);
    memcpy(buf + offset, &msgobsmsgobs_idxlock, 2);
    // NOLINTNEXTLINE
    offset += 2;

    if (offset + 2 > len)
    {
      return false;
    }
    u16 msgobsmsgobs_idxsidsat = htole16(msg->obs[msgobs_idx].sid.sat);
    memcpy(buf + offset, &msgobsmsgobs_idxsidsat, 2);
    // NOLINTNEXTLINE
    offset += 2;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgobsmsgobs_idxsidcode = msg->obs[msgobs_idx].sid.code;
    memcpy(buf + offset, &msgobsmsgobs_idxsidcode, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgobsmsgobs_idxsidreserved = msg->obs[msgobs_idx].sid.reserved;
    memcpy(buf + offset, &msgobsmsgobs_idxsidreserved, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_obs_dep_b_t(const u8 *buf, size_t len, sbp_msg_obs_dep_b_t *msg)
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
  memcpy(&msg->header.t.tow, buf + offset, 4);
  msg->header.t.tow = le32toh(msg->header.t.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->header.t.wn, buf + offset, 2);
  msg->header.t.wn = le16toh(msg->header.t.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->header.n_obs, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  msg->obs_count = (u8)((len - offset) / 16);

  for (size_t msgobs_idx = 0; msgobs_idx < msg->obs_count; msgobs_idx++)
  {

    if (offset + 4 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].P, buf + offset, 4);
    msg->obs[msgobs_idx].P = le32toh(msg->obs[msgobs_idx].P);
    // NOLINTNEXTLINE
    offset += 4;

    if (offset + 4 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].L.i, buf + offset, 4);
    u32 msgobsmsgobs_idxLi = *(const u32 *)&msg->obs[msgobs_idx].L.i;
    msgobsmsgobs_idxLi = le32toh(msgobsmsgobs_idxLi);
    msg->obs[msgobs_idx].L.i = *(const s32 *)&msgobsmsgobs_idxLi;
    // NOLINTNEXTLINE
    offset += 4;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].L.f, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].cn0, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 2 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].lock, buf + offset, 2);
    msg->obs[msgobs_idx].lock = le16toh(msg->obs[msgobs_idx].lock);
    // NOLINTNEXTLINE
    offset += 2;

    if (offset + 2 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].sid.sat, buf + offset, 2);
    msg->obs[msgobs_idx].sid.sat = le16toh(msg->obs[msgobs_idx].sid.sat);
    // NOLINTNEXTLINE
    offset += 2;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].sid.code, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].sid.reserved, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_obs_dep_c_t(const sbp_msg_obs_dep_c_t *msg)
{
  (void)msg;
  return 0 + (0 + (0 + sizeof(msg->header.t.tow) + sizeof(msg->header.t.wn)) + sizeof(msg->header.n_obs)) +
         (msg->obs_count *
          (0 + sizeof(msg->obs[0].P) + (0 + sizeof(msg->obs[0].L.i) + sizeof(msg->obs[0].L.f)) +
           sizeof(msg->obs[0].cn0) + sizeof(msg->obs[0].lock) +
           (0 + sizeof(msg->obs[0].sid.sat) + sizeof(msg->obs[0].sid.code) + sizeof(msg->obs[0].sid.reserved))));
}

static inline bool sbp_pack_sbp_msg_obs_dep_c_t(u8 *buf, size_t len, const sbp_msg_obs_dep_c_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_obs_dep_c_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgheaderttow = htole32(msg->header.t.tow);
  memcpy(buf + offset, &msgheaderttow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgheadertwn = htole16(msg->header.t.wn);
  memcpy(buf + offset, &msgheadertwn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgheadern_obs = msg->header.n_obs;
  memcpy(buf + offset, &msgheadern_obs, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgobs_idx = 0; msgobs_idx < (size_t)msg->obs_count; msgobs_idx++)
  {

    if (offset + 4 > len)
    {
      return false;
    }
    u32 msgobsmsgobs_idxP = htole32(msg->obs[msgobs_idx].P);
    memcpy(buf + offset, &msgobsmsgobs_idxP, 4);
    // NOLINTNEXTLINE
    offset += 4;

    if (offset + 4 > len)
    {
      return false;
    }
    u32 msgobsmsgobs_idxLi = htole32(*(const u32 *)&msg->obs[msgobs_idx].L.i);
    memcpy(buf + offset, &msgobsmsgobs_idxLi, 4);
    // NOLINTNEXTLINE
    offset += 4;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgobsmsgobs_idxLf = msg->obs[msgobs_idx].L.f;
    memcpy(buf + offset, &msgobsmsgobs_idxLf, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgobsmsgobs_idxcn0 = msg->obs[msgobs_idx].cn0;
    memcpy(buf + offset, &msgobsmsgobs_idxcn0, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 2 > len)
    {
      return false;
    }
    u16 msgobsmsgobs_idxlock = htole16(msg->obs[msgobs_idx].lock);
    memcpy(buf + offset, &msgobsmsgobs_idxlock, 2);
    // NOLINTNEXTLINE
    offset += 2;

    if (offset + 2 > len)
    {
      return false;
    }
    u16 msgobsmsgobs_idxsidsat = htole16(msg->obs[msgobs_idx].sid.sat);
    memcpy(buf + offset, &msgobsmsgobs_idxsidsat, 2);
    // NOLINTNEXTLINE
    offset += 2;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgobsmsgobs_idxsidcode = msg->obs[msgobs_idx].sid.code;
    memcpy(buf + offset, &msgobsmsgobs_idxsidcode, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgobsmsgobs_idxsidreserved = msg->obs[msgobs_idx].sid.reserved;
    memcpy(buf + offset, &msgobsmsgobs_idxsidreserved, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_obs_dep_c_t(const u8 *buf, size_t len, sbp_msg_obs_dep_c_t *msg)
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
  memcpy(&msg->header.t.tow, buf + offset, 4);
  msg->header.t.tow = le32toh(msg->header.t.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->header.t.wn, buf + offset, 2);
  msg->header.t.wn = le16toh(msg->header.t.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->header.n_obs, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  msg->obs_count = (u8)((len - offset) / 16);

  for (size_t msgobs_idx = 0; msgobs_idx < msg->obs_count; msgobs_idx++)
  {

    if (offset + 4 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].P, buf + offset, 4);
    msg->obs[msgobs_idx].P = le32toh(msg->obs[msgobs_idx].P);
    // NOLINTNEXTLINE
    offset += 4;

    if (offset + 4 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].L.i, buf + offset, 4);
    u32 msgobsmsgobs_idxLi = *(const u32 *)&msg->obs[msgobs_idx].L.i;
    msgobsmsgobs_idxLi = le32toh(msgobsmsgobs_idxLi);
    msg->obs[msgobs_idx].L.i = *(const s32 *)&msgobsmsgobs_idxLi;
    // NOLINTNEXTLINE
    offset += 4;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].L.f, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].cn0, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 2 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].lock, buf + offset, 2);
    msg->obs[msgobs_idx].lock = le16toh(msg->obs[msgobs_idx].lock);
    // NOLINTNEXTLINE
    offset += 2;

    if (offset + 2 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].sid.sat, buf + offset, 2);
    msg->obs[msgobs_idx].sid.sat = le16toh(msg->obs[msgobs_idx].sid.sat);
    // NOLINTNEXTLINE
    offset += 2;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].sid.code, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].sid.reserved, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_iono_t(const sbp_msg_iono_t *msg)
{
  (void)msg;
  return 0 + (0 + sizeof(msg->t_nmct.tow) + sizeof(msg->t_nmct.wn)) + sizeof(msg->a0) + sizeof(msg->a1) +
         sizeof(msg->a2) + sizeof(msg->a3) + sizeof(msg->b0) + sizeof(msg->b1) + sizeof(msg->b2) + sizeof(msg->b3);
}

static inline bool sbp_pack_sbp_msg_iono_t(u8 *buf, size_t len, const sbp_msg_iono_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_iono_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgt_nmcttow = htole32(msg->t_nmct.tow);
  memcpy(buf + offset, &msgt_nmcttow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgt_nmctwn = htole16(msg->t_nmct.wn);
  memcpy(buf + offset, &msgt_nmctwn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  double msga0 = msg->a0;
  memcpy(buf + offset, &msga0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msga1 = msg->a1;
  memcpy(buf + offset, &msga1, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msga2 = msg->a2;
  memcpy(buf + offset, &msga2, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msga3 = msg->a3;
  memcpy(buf + offset, &msga3, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgb0 = msg->b0;
  memcpy(buf + offset, &msgb0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgb1 = msg->b1;
  memcpy(buf + offset, &msgb1, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgb2 = msg->b2;
  memcpy(buf + offset, &msgb2, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgb3 = msg->b3;
  memcpy(buf + offset, &msgb3, 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline bool sbp_unpack_sbp_msg_iono_t(const u8 *buf, size_t len, sbp_msg_iono_t *msg)
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
  memcpy(&msg->t_nmct.tow, buf + offset, 4);
  msg->t_nmct.tow = le32toh(msg->t_nmct.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->t_nmct.wn, buf + offset, 2);
  msg->t_nmct.wn = le16toh(msg->t_nmct.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->a0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->a1, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->a2, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->a3, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->b0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->b1, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->b2, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->b3, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_sv_configuration_gps_dep_t(const sbp_msg_sv_configuration_gps_dep_t *msg)
{
  (void)msg;
  return 0 + (0 + sizeof(msg->t_nmct.tow) + sizeof(msg->t_nmct.wn)) + sizeof(msg->l2c_mask);
}

static inline bool
sbp_pack_sbp_msg_sv_configuration_gps_dep_t(u8 *buf, size_t len, const sbp_msg_sv_configuration_gps_dep_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_sv_configuration_gps_dep_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgt_nmcttow = htole32(msg->t_nmct.tow);
  memcpy(buf + offset, &msgt_nmcttow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgt_nmctwn = htole16(msg->t_nmct.wn);
  memcpy(buf + offset, &msgt_nmctwn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgl2c_mask = htole32(msg->l2c_mask);
  memcpy(buf + offset, &msgl2c_mask, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool
sbp_unpack_sbp_msg_sv_configuration_gps_dep_t(const u8 *buf, size_t len, sbp_msg_sv_configuration_gps_dep_t *msg)
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
  memcpy(&msg->t_nmct.tow, buf + offset, 4);
  msg->t_nmct.tow = le32toh(msg->t_nmct.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->t_nmct.wn, buf + offset, 2);
  msg->t_nmct.wn = le16toh(msg->t_nmct.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->l2c_mask, buf + offset, 4);
  msg->l2c_mask = le32toh(msg->l2c_mask);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_gnss_capb_t(const sbp_gnss_capb_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->gps_active) + sizeof(msg->gps_l2c) + sizeof(msg->gps_l5) + sizeof(msg->glo_active) +
         sizeof(msg->glo_l2of) + sizeof(msg->glo_l3) + sizeof(msg->sbas_active) + sizeof(msg->sbas_l5) +
         sizeof(msg->bds_active) + sizeof(msg->bds_d2nav) + sizeof(msg->bds_b2) + sizeof(msg->bds_b2a) +
         sizeof(msg->qzss_active) + sizeof(msg->gal_active) + sizeof(msg->gal_e5);
}

static inline bool sbp_pack_sbp_gnss_capb_t(u8 *buf, size_t len, const sbp_gnss_capb_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_gnss_capb_t(msg) > len)
  {
    return false;
  }

  if (offset + 8 > len)
  {
    return false;
  }
  u64 msggps_active = htole64(msg->gps_active);
  memcpy(buf + offset, &msggps_active, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  u64 msggps_l2c = htole64(msg->gps_l2c);
  memcpy(buf + offset, &msggps_l2c, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  u64 msggps_l5 = htole64(msg->gps_l5);
  memcpy(buf + offset, &msggps_l5, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgglo_active = htole32(msg->glo_active);
  memcpy(buf + offset, &msgglo_active, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgglo_l2of = htole32(msg->glo_l2of);
  memcpy(buf + offset, &msgglo_l2of, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgglo_l3 = htole32(msg->glo_l3);
  memcpy(buf + offset, &msgglo_l3, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 8 > len)
  {
    return false;
  }
  u64 msgsbas_active = htole64(msg->sbas_active);
  memcpy(buf + offset, &msgsbas_active, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  u64 msgsbas_l5 = htole64(msg->sbas_l5);
  memcpy(buf + offset, &msgsbas_l5, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  u64 msgbds_active = htole64(msg->bds_active);
  memcpy(buf + offset, &msgbds_active, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  u64 msgbds_d2nav = htole64(msg->bds_d2nav);
  memcpy(buf + offset, &msgbds_d2nav, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  u64 msgbds_b2 = htole64(msg->bds_b2);
  memcpy(buf + offset, &msgbds_b2, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  u64 msgbds_b2a = htole64(msg->bds_b2a);
  memcpy(buf + offset, &msgbds_b2a, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgqzss_active = htole32(msg->qzss_active);
  memcpy(buf + offset, &msgqzss_active, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 8 > len)
  {
    return false;
  }
  u64 msggal_active = htole64(msg->gal_active);
  memcpy(buf + offset, &msggal_active, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  u64 msggal_e5 = htole64(msg->gal_e5);
  memcpy(buf + offset, &msggal_e5, 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline bool sbp_unpack_sbp_gnss_capb_t(const u8 *buf, size_t len, sbp_gnss_capb_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->gps_active, buf + offset, 8);
  msg->gps_active = le64toh(msg->gps_active);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->gps_l2c, buf + offset, 8);
  msg->gps_l2c = le64toh(msg->gps_l2c);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->gps_l5, buf + offset, 8);
  msg->gps_l5 = le64toh(msg->gps_l5);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->glo_active, buf + offset, 4);
  msg->glo_active = le32toh(msg->glo_active);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->glo_l2of, buf + offset, 4);
  msg->glo_l2of = le32toh(msg->glo_l2of);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->glo_l3, buf + offset, 4);
  msg->glo_l3 = le32toh(msg->glo_l3);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->sbas_active, buf + offset, 8);
  msg->sbas_active = le64toh(msg->sbas_active);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->sbas_l5, buf + offset, 8);
  msg->sbas_l5 = le64toh(msg->sbas_l5);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->bds_active, buf + offset, 8);
  msg->bds_active = le64toh(msg->bds_active);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->bds_d2nav, buf + offset, 8);
  msg->bds_d2nav = le64toh(msg->bds_d2nav);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->bds_b2, buf + offset, 8);
  msg->bds_b2 = le64toh(msg->bds_b2);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->bds_b2a, buf + offset, 8);
  msg->bds_b2a = le64toh(msg->bds_b2a);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->qzss_active, buf + offset, 4);
  msg->qzss_active = le32toh(msg->qzss_active);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->gal_active, buf + offset, 8);
  msg->gal_active = le64toh(msg->gal_active);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->gal_e5, buf + offset, 8);
  msg->gal_e5 = le64toh(msg->gal_e5);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_gnss_capb_t(const sbp_msg_gnss_capb_t *msg)
{
  (void)msg;
  return 0 + (0 + sizeof(msg->t_nmct.tow) + sizeof(msg->t_nmct.wn)) +
         (0 + sizeof(msg->gc.gps_active) + sizeof(msg->gc.gps_l2c) + sizeof(msg->gc.gps_l5) +
          sizeof(msg->gc.glo_active) + sizeof(msg->gc.glo_l2of) + sizeof(msg->gc.glo_l3) + sizeof(msg->gc.sbas_active) +
          sizeof(msg->gc.sbas_l5) + sizeof(msg->gc.bds_active) + sizeof(msg->gc.bds_d2nav) + sizeof(msg->gc.bds_b2) +
          sizeof(msg->gc.bds_b2a) + sizeof(msg->gc.qzss_active) + sizeof(msg->gc.gal_active) + sizeof(msg->gc.gal_e5));
}

static inline bool sbp_pack_sbp_msg_gnss_capb_t(u8 *buf, size_t len, const sbp_msg_gnss_capb_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_gnss_capb_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgt_nmcttow = htole32(msg->t_nmct.tow);
  memcpy(buf + offset, &msgt_nmcttow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgt_nmctwn = htole16(msg->t_nmct.wn);
  memcpy(buf + offset, &msgt_nmctwn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  u64 msggcgps_active = htole64(msg->gc.gps_active);
  memcpy(buf + offset, &msggcgps_active, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  u64 msggcgps_l2c = htole64(msg->gc.gps_l2c);
  memcpy(buf + offset, &msggcgps_l2c, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  u64 msggcgps_l5 = htole64(msg->gc.gps_l5);
  memcpy(buf + offset, &msggcgps_l5, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msggcglo_active = htole32(msg->gc.glo_active);
  memcpy(buf + offset, &msggcglo_active, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msggcglo_l2of = htole32(msg->gc.glo_l2of);
  memcpy(buf + offset, &msggcglo_l2of, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msggcglo_l3 = htole32(msg->gc.glo_l3);
  memcpy(buf + offset, &msggcglo_l3, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 8 > len)
  {
    return false;
  }
  u64 msggcsbas_active = htole64(msg->gc.sbas_active);
  memcpy(buf + offset, &msggcsbas_active, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  u64 msggcsbas_l5 = htole64(msg->gc.sbas_l5);
  memcpy(buf + offset, &msggcsbas_l5, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  u64 msggcbds_active = htole64(msg->gc.bds_active);
  memcpy(buf + offset, &msggcbds_active, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  u64 msggcbds_d2nav = htole64(msg->gc.bds_d2nav);
  memcpy(buf + offset, &msggcbds_d2nav, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  u64 msggcbds_b2 = htole64(msg->gc.bds_b2);
  memcpy(buf + offset, &msggcbds_b2, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  u64 msggcbds_b2a = htole64(msg->gc.bds_b2a);
  memcpy(buf + offset, &msggcbds_b2a, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msggcqzss_active = htole32(msg->gc.qzss_active);
  memcpy(buf + offset, &msggcqzss_active, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 8 > len)
  {
    return false;
  }
  u64 msggcgal_active = htole64(msg->gc.gal_active);
  memcpy(buf + offset, &msggcgal_active, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  u64 msggcgal_e5 = htole64(msg->gc.gal_e5);
  memcpy(buf + offset, &msggcgal_e5, 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline bool sbp_unpack_sbp_msg_gnss_capb_t(const u8 *buf, size_t len, sbp_msg_gnss_capb_t *msg)
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
  memcpy(&msg->t_nmct.tow, buf + offset, 4);
  msg->t_nmct.tow = le32toh(msg->t_nmct.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->t_nmct.wn, buf + offset, 2);
  msg->t_nmct.wn = le16toh(msg->t_nmct.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->gc.gps_active, buf + offset, 8);
  msg->gc.gps_active = le64toh(msg->gc.gps_active);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->gc.gps_l2c, buf + offset, 8);
  msg->gc.gps_l2c = le64toh(msg->gc.gps_l2c);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->gc.gps_l5, buf + offset, 8);
  msg->gc.gps_l5 = le64toh(msg->gc.gps_l5);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->gc.glo_active, buf + offset, 4);
  msg->gc.glo_active = le32toh(msg->gc.glo_active);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->gc.glo_l2of, buf + offset, 4);
  msg->gc.glo_l2of = le32toh(msg->gc.glo_l2of);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->gc.glo_l3, buf + offset, 4);
  msg->gc.glo_l3 = le32toh(msg->gc.glo_l3);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->gc.sbas_active, buf + offset, 8);
  msg->gc.sbas_active = le64toh(msg->gc.sbas_active);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->gc.sbas_l5, buf + offset, 8);
  msg->gc.sbas_l5 = le64toh(msg->gc.sbas_l5);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->gc.bds_active, buf + offset, 8);
  msg->gc.bds_active = le64toh(msg->gc.bds_active);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->gc.bds_d2nav, buf + offset, 8);
  msg->gc.bds_d2nav = le64toh(msg->gc.bds_d2nav);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->gc.bds_b2, buf + offset, 8);
  msg->gc.bds_b2 = le64toh(msg->gc.bds_b2);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->gc.bds_b2a, buf + offset, 8);
  msg->gc.bds_b2a = le64toh(msg->gc.bds_b2a);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->gc.qzss_active, buf + offset, 4);
  msg->gc.qzss_active = le32toh(msg->gc.qzss_active);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->gc.gal_active, buf + offset, 8);
  msg->gc.gal_active = le64toh(msg->gc.gal_active);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->gc.gal_e5, buf + offset, 8);
  msg->gc.gal_e5 = le64toh(msg->gc.gal_e5);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_group_delay_dep_a_t(const sbp_msg_group_delay_dep_a_t *msg)
{
  (void)msg;
  return 0 + (0 + sizeof(msg->t_op.tow) + sizeof(msg->t_op.wn)) + sizeof(msg->prn) + sizeof(msg->valid) +
         sizeof(msg->tgd) + sizeof(msg->isc_l1ca) + sizeof(msg->isc_l2c);
}

static inline bool sbp_pack_sbp_msg_group_delay_dep_a_t(u8 *buf, size_t len, const sbp_msg_group_delay_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_group_delay_dep_a_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgt_optow = htole32(msg->t_op.tow);
  memcpy(buf + offset, &msgt_optow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgt_opwn = htole16(msg->t_op.wn);
  memcpy(buf + offset, &msgt_opwn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgprn = msg->prn;
  memcpy(buf + offset, &msgprn, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgvalid = msg->valid;
  memcpy(buf + offset, &msgvalid, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtgd = htole16(*(const u16 *)&msg->tgd);
  memcpy(buf + offset, &msgtgd, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgisc_l1ca = htole16(*(const u16 *)&msg->isc_l1ca);
  memcpy(buf + offset, &msgisc_l1ca, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgisc_l2c = htole16(*(const u16 *)&msg->isc_l2c);
  memcpy(buf + offset, &msgisc_l2c, 2);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_group_delay_dep_a_t(const u8 *buf, size_t len, sbp_msg_group_delay_dep_a_t *msg)
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
  memcpy(&msg->t_op.tow, buf + offset, 4);
  msg->t_op.tow = le32toh(msg->t_op.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->t_op.wn, buf + offset, 2);
  msg->t_op.wn = le16toh(msg->t_op.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->prn, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->tgd, buf + offset, 2);
  u16 msgtgd = *(const u16 *)&msg->tgd;
  msgtgd = le16toh(msgtgd);
  msg->tgd = *(const s16 *)&msgtgd;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->isc_l1ca, buf + offset, 2);
  u16 msgisc_l1ca = *(const u16 *)&msg->isc_l1ca;
  msgisc_l1ca = le16toh(msgisc_l1ca);
  msg->isc_l1ca = *(const s16 *)&msgisc_l1ca;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->isc_l2c, buf + offset, 2);
  u16 msgisc_l2c = *(const u16 *)&msg->isc_l2c;
  msgisc_l2c = le16toh(msgisc_l2c);
  msg->isc_l2c = *(const s16 *)&msgisc_l2c;
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_group_delay_dep_b_t(const sbp_msg_group_delay_dep_b_t *msg)
{
  (void)msg;
  return 0 + (0 + sizeof(msg->t_op.tow) + sizeof(msg->t_op.wn)) +
         (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code) + sizeof(msg->sid.reserved)) + sizeof(msg->valid) +
         sizeof(msg->tgd) + sizeof(msg->isc_l1ca) + sizeof(msg->isc_l2c);
}

static inline bool sbp_pack_sbp_msg_group_delay_dep_b_t(u8 *buf, size_t len, const sbp_msg_group_delay_dep_b_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_group_delay_dep_b_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgt_optow = htole32(msg->t_op.tow);
  memcpy(buf + offset, &msgt_optow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgt_opwn = htole16(msg->t_op.wn);
  memcpy(buf + offset, &msgt_opwn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgsidsat = htole16(msg->sid.sat);
  memcpy(buf + offset, &msgsidsat, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidreserved = msg->sid.reserved;
  memcpy(buf + offset, &msgsidreserved, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgvalid = msg->valid;
  memcpy(buf + offset, &msgvalid, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtgd = htole16(*(const u16 *)&msg->tgd);
  memcpy(buf + offset, &msgtgd, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgisc_l1ca = htole16(*(const u16 *)&msg->isc_l1ca);
  memcpy(buf + offset, &msgisc_l1ca, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgisc_l2c = htole16(*(const u16 *)&msg->isc_l2c);
  memcpy(buf + offset, &msgisc_l2c, 2);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_group_delay_dep_b_t(const u8 *buf, size_t len, sbp_msg_group_delay_dep_b_t *msg)
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
  memcpy(&msg->t_op.tow, buf + offset, 4);
  msg->t_op.tow = le32toh(msg->t_op.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->t_op.wn, buf + offset, 2);
  msg->t_op.wn = le16toh(msg->t_op.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->sid.sat, buf + offset, 2);
  msg->sid.sat = le16toh(msg->sid.sat);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.reserved, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->tgd, buf + offset, 2);
  u16 msgtgd = *(const u16 *)&msg->tgd;
  msgtgd = le16toh(msgtgd);
  msg->tgd = *(const s16 *)&msgtgd;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->isc_l1ca, buf + offset, 2);
  u16 msgisc_l1ca = *(const u16 *)&msg->isc_l1ca;
  msgisc_l1ca = le16toh(msgisc_l1ca);
  msg->isc_l1ca = *(const s16 *)&msgisc_l1ca;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->isc_l2c, buf + offset, 2);
  u16 msgisc_l2c = *(const u16 *)&msg->isc_l2c;
  msgisc_l2c = le16toh(msgisc_l2c);
  msg->isc_l2c = *(const s16 *)&msgisc_l2c;
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_group_delay_t(const sbp_msg_group_delay_t *msg)
{
  (void)msg;
  return 0 + (0 + sizeof(msg->t_op.tow) + sizeof(msg->t_op.wn)) + (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code)) +
         sizeof(msg->valid) + sizeof(msg->tgd) + sizeof(msg->isc_l1ca) + sizeof(msg->isc_l2c);
}

static inline bool sbp_pack_sbp_msg_group_delay_t(u8 *buf, size_t len, const sbp_msg_group_delay_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_group_delay_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgt_optow = htole32(msg->t_op.tow);
  memcpy(buf + offset, &msgt_optow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgt_opwn = htole16(msg->t_op.wn);
  memcpy(buf + offset, &msgt_opwn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidsat = msg->sid.sat;
  memcpy(buf + offset, &msgsidsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgvalid = msg->valid;
  memcpy(buf + offset, &msgvalid, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtgd = htole16(*(const u16 *)&msg->tgd);
  memcpy(buf + offset, &msgtgd, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgisc_l1ca = htole16(*(const u16 *)&msg->isc_l1ca);
  memcpy(buf + offset, &msgisc_l1ca, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgisc_l2c = htole16(*(const u16 *)&msg->isc_l2c);
  memcpy(buf + offset, &msgisc_l2c, 2);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_group_delay_t(const u8 *buf, size_t len, sbp_msg_group_delay_t *msg)
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
  memcpy(&msg->t_op.tow, buf + offset, 4);
  msg->t_op.tow = le32toh(msg->t_op.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->t_op.wn, buf + offset, 2);
  msg->t_op.wn = le16toh(msg->t_op.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->tgd, buf + offset, 2);
  u16 msgtgd = *(const u16 *)&msg->tgd;
  msgtgd = le16toh(msgtgd);
  msg->tgd = *(const s16 *)&msgtgd;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->isc_l1ca, buf + offset, 2);
  u16 msgisc_l1ca = *(const u16 *)&msg->isc_l1ca;
  msgisc_l1ca = le16toh(msgisc_l1ca);
  msg->isc_l1ca = *(const s16 *)&msgisc_l1ca;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->isc_l2c, buf + offset, 2);
  u16 msgisc_l2c = *(const u16 *)&msg->isc_l2c;
  msgisc_l2c = le16toh(msgisc_l2c);
  msg->isc_l2c = *(const s16 *)&msgisc_l2c;
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_almanac_common_content_t(const sbp_almanac_common_content_t *msg)
{
  (void)msg;
  return 0 + (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code)) + (0 + sizeof(msg->toa.tow) + sizeof(msg->toa.wn)) +
         sizeof(msg->ura) + sizeof(msg->fit_interval) + sizeof(msg->valid) + sizeof(msg->health_bits);
}

static inline bool sbp_pack_sbp_almanac_common_content_t(u8 *buf, size_t len, const sbp_almanac_common_content_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_almanac_common_content_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidsat = msg->sid.sat;
  memcpy(buf + offset, &msgsidsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtoatow = htole32(msg->toa.tow);
  memcpy(buf + offset, &msgtoatow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtoawn = htole16(msg->toa.wn);
  memcpy(buf + offset, &msgtoawn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgura = msg->ura;
  memcpy(buf + offset, &msgura, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgfit_interval = htole32(msg->fit_interval);
  memcpy(buf + offset, &msgfit_interval, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgvalid = msg->valid;
  memcpy(buf + offset, &msgvalid, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msghealth_bits = msg->health_bits;
  memcpy(buf + offset, &msghealth_bits, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_almanac_common_content_t(const u8 *buf, size_t len, sbp_almanac_common_content_t *msg)
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
  memcpy(&msg->sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->toa.tow, buf + offset, 4);
  msg->toa.tow = le32toh(msg->toa.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->toa.wn, buf + offset, 2);
  msg->toa.wn = le16toh(msg->toa.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->ura, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->fit_interval, buf + offset, 4);
  msg->fit_interval = le32toh(msg->fit_interval);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_almanac_common_content_dep_t(const sbp_almanac_common_content_dep_t *msg)
{
  (void)msg;
  return 0 + (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code) + sizeof(msg->sid.reserved)) +
         (0 + sizeof(msg->toa.tow) + sizeof(msg->toa.wn)) + sizeof(msg->ura) + sizeof(msg->fit_interval) +
         sizeof(msg->valid) + sizeof(msg->health_bits);
}

static inline bool
sbp_pack_sbp_almanac_common_content_dep_t(u8 *buf, size_t len, const sbp_almanac_common_content_dep_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_almanac_common_content_dep_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgsidsat = htole16(msg->sid.sat);
  memcpy(buf + offset, &msgsidsat, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidreserved = msg->sid.reserved;
  memcpy(buf + offset, &msgsidreserved, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtoatow = htole32(msg->toa.tow);
  memcpy(buf + offset, &msgtoatow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtoawn = htole16(msg->toa.wn);
  memcpy(buf + offset, &msgtoawn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgura = msg->ura;
  memcpy(buf + offset, &msgura, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgfit_interval = htole32(msg->fit_interval);
  memcpy(buf + offset, &msgfit_interval, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgvalid = msg->valid;
  memcpy(buf + offset, &msgvalid, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msghealth_bits = msg->health_bits;
  memcpy(buf + offset, &msghealth_bits, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool
sbp_unpack_sbp_almanac_common_content_dep_t(const u8 *buf, size_t len, sbp_almanac_common_content_dep_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->sid.sat, buf + offset, 2);
  msg->sid.sat = le16toh(msg->sid.sat);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.reserved, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->toa.tow, buf + offset, 4);
  msg->toa.tow = le32toh(msg->toa.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->toa.wn, buf + offset, 2);
  msg->toa.wn = le16toh(msg->toa.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->ura, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->fit_interval, buf + offset, 4);
  msg->fit_interval = le32toh(msg->fit_interval);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_almanac_gps_dep_t(const sbp_msg_almanac_gps_dep_t *msg)
{
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code) + sizeof(msg->common.sid.reserved)) +
          (0 + sizeof(msg->common.toa.tow) + sizeof(msg->common.toa.wn)) + sizeof(msg->common.ura) +
          sizeof(msg->common.fit_interval) + sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         sizeof(msg->m0) + sizeof(msg->ecc) + sizeof(msg->sqrta) + sizeof(msg->omega0) + sizeof(msg->omegadot) +
         sizeof(msg->w) + sizeof(msg->inc) + sizeof(msg->af0) + sizeof(msg->af1);
}

static inline bool sbp_pack_sbp_msg_almanac_gps_dep_t(u8 *buf, size_t len, const sbp_msg_almanac_gps_dep_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_almanac_gps_dep_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcommonsidsat = htole16(msg->common.sid.sat);
  memcpy(buf + offset, &msgcommonsidsat, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidreserved = msg->common.sid.reserved;
  memcpy(buf + offset, &msgcommonsidreserved, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommontoatow = htole32(msg->common.toa.tow);
  memcpy(buf + offset, &msgcommontoatow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcommontoawn = htole16(msg->common.toa.wn);
  memcpy(buf + offset, &msgcommontoawn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommonfit_interval = htole32(msg->common.fit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgm0 = msg->m0;
  memcpy(buf + offset, &msgm0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgecc = msg->ecc;
  memcpy(buf + offset, &msgecc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgsqrta = msg->sqrta;
  memcpy(buf + offset, &msgsqrta, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgomega0 = msg->omega0;
  memcpy(buf + offset, &msgomega0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgomegadot = msg->omegadot;
  memcpy(buf + offset, &msgomegadot, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgw = msg->w;
  memcpy(buf + offset, &msgw, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msginc = msg->inc;
  memcpy(buf + offset, &msginc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgaf0 = msg->af0;
  memcpy(buf + offset, &msgaf0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgaf1 = msg->af1;
  memcpy(buf + offset, &msgaf1, 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline bool sbp_unpack_sbp_msg_almanac_gps_dep_t(const u8 *buf, size_t len, sbp_msg_almanac_gps_dep_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->common.sid.sat, buf + offset, 2);
  msg->common.sid.sat = le16toh(msg->common.sid.sat);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.sid.reserved, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.toa.tow, buf + offset, 4);
  msg->common.toa.tow = le32toh(msg->common.toa.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->common.toa.wn, buf + offset, 2);
  msg->common.toa.wn = le16toh(msg->common.toa.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->m0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->ecc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->sqrta, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->omega0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->omegadot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->w, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->inc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->af0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->af1, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_almanac_gps_t(const sbp_msg_almanac_gps_t *msg)
{
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code)) +
          (0 + sizeof(msg->common.toa.tow) + sizeof(msg->common.toa.wn)) + sizeof(msg->common.ura) +
          sizeof(msg->common.fit_interval) + sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         sizeof(msg->m0) + sizeof(msg->ecc) + sizeof(msg->sqrta) + sizeof(msg->omega0) + sizeof(msg->omegadot) +
         sizeof(msg->w) + sizeof(msg->inc) + sizeof(msg->af0) + sizeof(msg->af1);
}

static inline bool sbp_pack_sbp_msg_almanac_gps_t(u8 *buf, size_t len, const sbp_msg_almanac_gps_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_almanac_gps_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidsat = msg->common.sid.sat;
  memcpy(buf + offset, &msgcommonsidsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommontoatow = htole32(msg->common.toa.tow);
  memcpy(buf + offset, &msgcommontoatow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcommontoawn = htole16(msg->common.toa.wn);
  memcpy(buf + offset, &msgcommontoawn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommonfit_interval = htole32(msg->common.fit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgm0 = msg->m0;
  memcpy(buf + offset, &msgm0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgecc = msg->ecc;
  memcpy(buf + offset, &msgecc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgsqrta = msg->sqrta;
  memcpy(buf + offset, &msgsqrta, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgomega0 = msg->omega0;
  memcpy(buf + offset, &msgomega0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgomegadot = msg->omegadot;
  memcpy(buf + offset, &msgomegadot, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgw = msg->w;
  memcpy(buf + offset, &msgw, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msginc = msg->inc;
  memcpy(buf + offset, &msginc, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgaf0 = msg->af0;
  memcpy(buf + offset, &msgaf0, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgaf1 = msg->af1;
  memcpy(buf + offset, &msgaf1, 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline bool sbp_unpack_sbp_msg_almanac_gps_t(const u8 *buf, size_t len, sbp_msg_almanac_gps_t *msg)
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
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.toa.tow, buf + offset, 4);
  msg->common.toa.tow = le32toh(msg->common.toa.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->common.toa.wn, buf + offset, 2);
  msg->common.toa.wn = le16toh(msg->common.toa.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->m0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->ecc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->sqrta, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->omega0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->omegadot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->w, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->inc, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->af0, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->af1, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_almanac_glo_dep_t(const sbp_msg_almanac_glo_dep_t *msg)
{
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code) + sizeof(msg->common.sid.reserved)) +
          (0 + sizeof(msg->common.toa.tow) + sizeof(msg->common.toa.wn)) + sizeof(msg->common.ura) +
          sizeof(msg->common.fit_interval) + sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         sizeof(msg->lambda_na) + sizeof(msg->t_lambda_na) + sizeof(msg->i) + sizeof(msg->t) + sizeof(msg->t_dot) +
         sizeof(msg->epsilon) + sizeof(msg->omega);
}

static inline bool sbp_pack_sbp_msg_almanac_glo_dep_t(u8 *buf, size_t len, const sbp_msg_almanac_glo_dep_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_almanac_glo_dep_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcommonsidsat = htole16(msg->common.sid.sat);
  memcpy(buf + offset, &msgcommonsidsat, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidreserved = msg->common.sid.reserved;
  memcpy(buf + offset, &msgcommonsidreserved, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommontoatow = htole32(msg->common.toa.tow);
  memcpy(buf + offset, &msgcommontoatow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcommontoawn = htole16(msg->common.toa.wn);
  memcpy(buf + offset, &msgcommontoawn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommonfit_interval = htole32(msg->common.fit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 8 > len)
  {
    return false;
  }
  double msglambda_na = msg->lambda_na;
  memcpy(buf + offset, &msglambda_na, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgt_lambda_na = msg->t_lambda_na;
  memcpy(buf + offset, &msgt_lambda_na, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgi = msg->i;
  memcpy(buf + offset, &msgi, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgt = msg->t;
  memcpy(buf + offset, &msgt, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgt_dot = msg->t_dot;
  memcpy(buf + offset, &msgt_dot, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgepsilon = msg->epsilon;
  memcpy(buf + offset, &msgepsilon, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgomega = msg->omega;
  memcpy(buf + offset, &msgomega, 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline bool sbp_unpack_sbp_msg_almanac_glo_dep_t(const u8 *buf, size_t len, sbp_msg_almanac_glo_dep_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->common.sid.sat, buf + offset, 2);
  msg->common.sid.sat = le16toh(msg->common.sid.sat);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.sid.reserved, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.toa.tow, buf + offset, 4);
  msg->common.toa.tow = le32toh(msg->common.toa.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->common.toa.wn, buf + offset, 2);
  msg->common.toa.wn = le16toh(msg->common.toa.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->lambda_na, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->t_lambda_na, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->i, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->t, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->t_dot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->epsilon, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->omega, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_almanac_glo_t(const sbp_msg_almanac_glo_t *msg)
{
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code)) +
          (0 + sizeof(msg->common.toa.tow) + sizeof(msg->common.toa.wn)) + sizeof(msg->common.ura) +
          sizeof(msg->common.fit_interval) + sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         sizeof(msg->lambda_na) + sizeof(msg->t_lambda_na) + sizeof(msg->i) + sizeof(msg->t) + sizeof(msg->t_dot) +
         sizeof(msg->epsilon) + sizeof(msg->omega);
}

static inline bool sbp_pack_sbp_msg_almanac_glo_t(u8 *buf, size_t len, const sbp_msg_almanac_glo_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_almanac_glo_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidsat = msg->common.sid.sat;
  memcpy(buf + offset, &msgcommonsidsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommontoatow = htole32(msg->common.toa.tow);
  memcpy(buf + offset, &msgcommontoatow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcommontoawn = htole16(msg->common.toa.wn);
  memcpy(buf + offset, &msgcommontoawn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcommonfit_interval = htole32(msg->common.fit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 8 > len)
  {
    return false;
  }
  double msglambda_na = msg->lambda_na;
  memcpy(buf + offset, &msglambda_na, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgt_lambda_na = msg->t_lambda_na;
  memcpy(buf + offset, &msgt_lambda_na, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgi = msg->i;
  memcpy(buf + offset, &msgi, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgt = msg->t;
  memcpy(buf + offset, &msgt, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgt_dot = msg->t_dot;
  memcpy(buf + offset, &msgt_dot, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgepsilon = msg->epsilon;
  memcpy(buf + offset, &msgepsilon, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgomega = msg->omega;
  memcpy(buf + offset, &msgomega, 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline bool sbp_unpack_sbp_msg_almanac_glo_t(const u8 *buf, size_t len, sbp_msg_almanac_glo_t *msg)
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
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.toa.tow, buf + offset, 4);
  msg->common.toa.tow = le32toh(msg->common.toa.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->common.toa.wn, buf + offset, 2);
  msg->common.toa.wn = le16toh(msg->common.toa.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->lambda_na, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->t_lambda_na, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->i, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->t, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->t_dot, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->epsilon, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->omega, buf + offset, 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_glo_biases_t(const sbp_msg_glo_biases_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->mask) + sizeof(msg->l1ca_bias) + sizeof(msg->l1p_bias) + sizeof(msg->l2ca_bias) +
         sizeof(msg->l2p_bias);
}

static inline bool sbp_pack_sbp_msg_glo_biases_t(u8 *buf, size_t len, const sbp_msg_glo_biases_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_glo_biases_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgmask = msg->mask;
  memcpy(buf + offset, &msgmask, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgl1ca_bias = htole16(*(const u16 *)&msg->l1ca_bias);
  memcpy(buf + offset, &msgl1ca_bias, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgl1p_bias = htole16(*(const u16 *)&msg->l1p_bias);
  memcpy(buf + offset, &msgl1p_bias, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgl2ca_bias = htole16(*(const u16 *)&msg->l2ca_bias);
  memcpy(buf + offset, &msgl2ca_bias, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgl2p_bias = htole16(*(const u16 *)&msg->l2p_bias);
  memcpy(buf + offset, &msgl2p_bias, 2);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_glo_biases_t(const u8 *buf, size_t len, sbp_msg_glo_biases_t *msg)
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
  memcpy(&msg->mask, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->l1ca_bias, buf + offset, 2);
  u16 msgl1ca_bias = *(const u16 *)&msg->l1ca_bias;
  msgl1ca_bias = le16toh(msgl1ca_bias);
  msg->l1ca_bias = *(const s16 *)&msgl1ca_bias;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->l1p_bias, buf + offset, 2);
  u16 msgl1p_bias = *(const u16 *)&msg->l1p_bias;
  msgl1p_bias = le16toh(msgl1p_bias);
  msg->l1p_bias = *(const s16 *)&msgl1p_bias;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->l2ca_bias, buf + offset, 2);
  u16 msgl2ca_bias = *(const u16 *)&msg->l2ca_bias;
  msgl2ca_bias = le16toh(msgl2ca_bias);
  msg->l2ca_bias = *(const s16 *)&msgl2ca_bias;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->l2p_bias, buf + offset, 2);
  u16 msgl2p_bias = *(const u16 *)&msg->l2p_bias;
  msgl2p_bias = le16toh(msgl2p_bias);
  msg->l2p_bias = *(const s16 *)&msgl2p_bias;
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_sv_az_el_t(const sbp_sv_az_el_t *msg)
{
  (void)msg;
  return 0 + (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code)) + sizeof(msg->az) + sizeof(msg->el);
}

static inline bool sbp_pack_sbp_sv_az_el_t(u8 *buf, size_t len, const sbp_sv_az_el_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_sv_az_el_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidsat = msg->sid.sat;
  memcpy(buf + offset, &msgsidsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgaz = msg->az;
  memcpy(buf + offset, &msgaz, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  s8 msgel = msg->el;
  memcpy(buf + offset, &msgel, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_sv_az_el_t(const u8 *buf, size_t len, sbp_sv_az_el_t *msg)
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
  memcpy(&msg->sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->az, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->el, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_sv_az_el_t(const sbp_msg_sv_az_el_t *msg)
{
  (void)msg;
  return 0 + (msg->azel_count * (0 + (0 + sizeof(msg->azel[0].sid.sat) + sizeof(msg->azel[0].sid.code)) +
                                 sizeof(msg->azel[0].az) + sizeof(msg->azel[0].el)));
}

static inline bool sbp_pack_sbp_msg_sv_az_el_t(u8 *buf, size_t len, const sbp_msg_sv_az_el_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_sv_az_el_t(msg) > len)
  {
    return false;
  }

  for (size_t msgazel_idx = 0; msgazel_idx < (size_t)msg->azel_count; msgazel_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgazelmsgazel_idxsidsat = msg->azel[msgazel_idx].sid.sat;
    memcpy(buf + offset, &msgazelmsgazel_idxsidsat, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgazelmsgazel_idxsidcode = msg->azel[msgazel_idx].sid.code;
    memcpy(buf + offset, &msgazelmsgazel_idxsidcode, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgazelmsgazel_idxaz = msg->azel[msgazel_idx].az;
    memcpy(buf + offset, &msgazelmsgazel_idxaz, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    s8 msgazelmsgazel_idxel = msg->azel[msgazel_idx].el;
    memcpy(buf + offset, &msgazelmsgazel_idxel, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_sv_az_el_t(const u8 *buf, size_t len, sbp_msg_sv_az_el_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  msg->azel_count = (u8)((len - offset) / 4);

  for (size_t msgazel_idx = 0; msgazel_idx < msg->azel_count; msgazel_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->azel[msgazel_idx].sid.sat, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->azel[msgazel_idx].sid.code, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->azel[msgazel_idx].az, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->azel[msgazel_idx].el, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_osr_t(const sbp_msg_osr_t *msg)
{
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->header.t.tow) + sizeof(msg->header.t.ns_residual) + sizeof(msg->header.t.wn)) +
          sizeof(msg->header.n_obs)) +
         (msg->obs_count *
          (0 + sizeof(msg->obs[0].P) + (0 + sizeof(msg->obs[0].L.i) + sizeof(msg->obs[0].L.f)) +
           sizeof(msg->obs[0].lock) + sizeof(msg->obs[0].flags) +
           (0 + sizeof(msg->obs[0].sid.sat) + sizeof(msg->obs[0].sid.code)) + sizeof(msg->obs[0].iono_std) +
           sizeof(msg->obs[0].tropo_std) + sizeof(msg->obs[0].range_std)));
}

static inline bool sbp_pack_sbp_msg_osr_t(u8 *buf, size_t len, const sbp_msg_osr_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_osr_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgheaderttow = htole32(msg->header.t.tow);
  memcpy(buf + offset, &msgheaderttow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgheadertns_residual = htole32(*(const u32 *)&msg->header.t.ns_residual);
  memcpy(buf + offset, &msgheadertns_residual, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgheadertwn = htole16(msg->header.t.wn);
  memcpy(buf + offset, &msgheadertwn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgheadern_obs = msg->header.n_obs;
  memcpy(buf + offset, &msgheadern_obs, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgobs_idx = 0; msgobs_idx < (size_t)msg->obs_count; msgobs_idx++)
  {

    if (offset + 4 > len)
    {
      return false;
    }
    u32 msgobsmsgobs_idxP = htole32(msg->obs[msgobs_idx].P);
    memcpy(buf + offset, &msgobsmsgobs_idxP, 4);
    // NOLINTNEXTLINE
    offset += 4;

    if (offset + 4 > len)
    {
      return false;
    }
    u32 msgobsmsgobs_idxLi = htole32(*(const u32 *)&msg->obs[msgobs_idx].L.i);
    memcpy(buf + offset, &msgobsmsgobs_idxLi, 4);
    // NOLINTNEXTLINE
    offset += 4;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgobsmsgobs_idxLf = msg->obs[msgobs_idx].L.f;
    memcpy(buf + offset, &msgobsmsgobs_idxLf, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgobsmsgobs_idxlock = msg->obs[msgobs_idx].lock;
    memcpy(buf + offset, &msgobsmsgobs_idxlock, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgobsmsgobs_idxflags = msg->obs[msgobs_idx].flags;
    memcpy(buf + offset, &msgobsmsgobs_idxflags, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgobsmsgobs_idxsidsat = msg->obs[msgobs_idx].sid.sat;
    memcpy(buf + offset, &msgobsmsgobs_idxsidsat, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgobsmsgobs_idxsidcode = msg->obs[msgobs_idx].sid.code;
    memcpy(buf + offset, &msgobsmsgobs_idxsidcode, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 2 > len)
    {
      return false;
    }
    u16 msgobsmsgobs_idxiono_std = htole16(msg->obs[msgobs_idx].iono_std);
    memcpy(buf + offset, &msgobsmsgobs_idxiono_std, 2);
    // NOLINTNEXTLINE
    offset += 2;

    if (offset + 2 > len)
    {
      return false;
    }
    u16 msgobsmsgobs_idxtropo_std = htole16(msg->obs[msgobs_idx].tropo_std);
    memcpy(buf + offset, &msgobsmsgobs_idxtropo_std, 2);
    // NOLINTNEXTLINE
    offset += 2;

    if (offset + 2 > len)
    {
      return false;
    }
    u16 msgobsmsgobs_idxrange_std = htole16(msg->obs[msgobs_idx].range_std);
    memcpy(buf + offset, &msgobsmsgobs_idxrange_std, 2);
    // NOLINTNEXTLINE
    offset += 2;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_osr_t(const u8 *buf, size_t len, sbp_msg_osr_t *msg)
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
  memcpy(&msg->header.t.tow, buf + offset, 4);
  msg->header.t.tow = le32toh(msg->header.t.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->header.t.ns_residual, buf + offset, 4);
  u32 msgheadertns_residual = *(const u32 *)&msg->header.t.ns_residual;
  msgheadertns_residual = le32toh(msgheadertns_residual);
  msg->header.t.ns_residual = *(const s32 *)&msgheadertns_residual;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->header.t.wn, buf + offset, 2);
  msg->header.t.wn = le16toh(msg->header.t.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->header.n_obs, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  msg->obs_count = (u8)((len - offset) / 19);

  for (size_t msgobs_idx = 0; msgobs_idx < msg->obs_count; msgobs_idx++)
  {

    if (offset + 4 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].P, buf + offset, 4);
    msg->obs[msgobs_idx].P = le32toh(msg->obs[msgobs_idx].P);
    // NOLINTNEXTLINE
    offset += 4;

    if (offset + 4 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].L.i, buf + offset, 4);
    u32 msgobsmsgobs_idxLi = *(const u32 *)&msg->obs[msgobs_idx].L.i;
    msgobsmsgobs_idxLi = le32toh(msgobsmsgobs_idxLi);
    msg->obs[msgobs_idx].L.i = *(const s32 *)&msgobsmsgobs_idxLi;
    // NOLINTNEXTLINE
    offset += 4;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].L.f, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].lock, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].flags, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].sid.sat, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].sid.code, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 2 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].iono_std, buf + offset, 2);
    msg->obs[msgobs_idx].iono_std = le16toh(msg->obs[msgobs_idx].iono_std);
    // NOLINTNEXTLINE
    offset += 2;

    if (offset + 2 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].tropo_std, buf + offset, 2);
    msg->obs[msgobs_idx].tropo_std = le16toh(msg->obs[msgobs_idx].tropo_std);
    // NOLINTNEXTLINE
    offset += 2;

    if (offset + 2 > len)
    {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].range_std, buf + offset, 2);
    msg->obs[msgobs_idx].range_std = le16toh(msg->obs[msgobs_idx].range_std);
    // NOLINTNEXTLINE
    offset += 2;
  }
  return true;
}

#endif
