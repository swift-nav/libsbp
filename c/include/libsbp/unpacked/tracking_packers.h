#ifndef LIBSBP_TRACKING_PACKERS_H
#define LIBSBP_TRACKING_PACKERS_H

#ifndef LIBSBP_TRACKING_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/tracking.h instead"
#endif

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/string2.h>

static inline size_t
sbp_packed_size_sbp_msg_tracking_state_detailed_dep_a_t(const sbp_msg_tracking_state_detailed_dep_a_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->recv_time) + (0 + sizeof(msg->tot.tow) + sizeof(msg->tot.ns_residual) + sizeof(msg->tot.wn)) +
         sizeof(msg->P) + sizeof(msg->P_std) + (0 + sizeof(msg->L.i) + sizeof(msg->L.f)) + sizeof(msg->cn0) +
         sizeof(msg->lock) + (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code)) + sizeof(msg->doppler) +
         sizeof(msg->doppler_std) + sizeof(msg->uptime) + sizeof(msg->clock_offset) + sizeof(msg->clock_drift) +
         sizeof(msg->corr_spacing) + sizeof(msg->acceleration) + sizeof(msg->sync_flags) + sizeof(msg->tow_flags) +
         sizeof(msg->track_flags) + sizeof(msg->nav_flags) + sizeof(msg->pset_flags) + sizeof(msg->misc_flags);
}

static inline bool sbp_pack_sbp_msg_tracking_state_detailed_dep_a_t(u8 *buf,
                                                                    size_t len,
                                                                    const sbp_msg_tracking_state_detailed_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_tracking_state_detailed_dep_a_t(msg) > len)
  {
    return false;
  }

  if (offset + 8 > len)
  {
    return false;
  }
  u64 msgrecv_time = htole64(msg->recv_time);
  memcpy(buf + offset, &msgrecv_time, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtottow = htole32(msg->tot.tow);
  memcpy(buf + offset, &msgtottow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtotns_residual = htole32(*(const u32 *)&msg->tot.ns_residual);
  memcpy(buf + offset, &msgtotns_residual, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtotwn = htole16(msg->tot.wn);
  memcpy(buf + offset, &msgtotwn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgP = htole32(msg->P);
  memcpy(buf + offset, &msgP, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgP_std = htole16(msg->P_std);
  memcpy(buf + offset, &msgP_std, 2);
  // NOLINTNEXTLINE
  offset += 2;

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
  u32 msgdoppler = htole32(*(const u32 *)&msg->doppler);
  memcpy(buf + offset, &msgdoppler, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgdoppler_std = htole16(msg->doppler_std);
  memcpy(buf + offset, &msgdoppler_std, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msguptime = htole32(msg->uptime);
  memcpy(buf + offset, &msguptime, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgclock_offset = htole16(*(const u16 *)&msg->clock_offset);
  memcpy(buf + offset, &msgclock_offset, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgclock_drift = htole16(*(const u16 *)&msg->clock_drift);
  memcpy(buf + offset, &msgclock_drift, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcorr_spacing = htole16(msg->corr_spacing);
  memcpy(buf + offset, &msgcorr_spacing, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  s8 msgacceleration = msg->acceleration;
  memcpy(buf + offset, &msgacceleration, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsync_flags = msg->sync_flags;
  memcpy(buf + offset, &msgsync_flags, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgtow_flags = msg->tow_flags;
  memcpy(buf + offset, &msgtow_flags, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgtrack_flags = msg->track_flags;
  memcpy(buf + offset, &msgtrack_flags, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgnav_flags = msg->nav_flags;
  memcpy(buf + offset, &msgnav_flags, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgpset_flags = msg->pset_flags;
  memcpy(buf + offset, &msgpset_flags, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgmisc_flags = msg->misc_flags;
  memcpy(buf + offset, &msgmisc_flags, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_tracking_state_detailed_dep_a_t(const u8 *buf,
                                                                      size_t len,
                                                                      sbp_msg_tracking_state_detailed_dep_a_t *msg)
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
  memcpy(&msg->recv_time, buf + offset, 8);
  msg->recv_time = le64toh(msg->recv_time);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->tot.tow, buf + offset, 4);
  msg->tot.tow = le32toh(msg->tot.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->tot.ns_residual, buf + offset, 4);
  u32 msgtotns_residual = *(const u32 *)&msg->tot.ns_residual;
  msgtotns_residual = le32toh(msgtotns_residual);
  msg->tot.ns_residual = *(const s32 *)&msgtotns_residual;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->tot.wn, buf + offset, 2);
  msg->tot.wn = le16toh(msg->tot.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->P, buf + offset, 4);
  msg->P = le32toh(msg->P);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->P_std, buf + offset, 2);
  msg->P_std = le16toh(msg->P_std);
  // NOLINTNEXTLINE
  offset += 2;

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
  memcpy(&msg->doppler, buf + offset, 4);
  u32 msgdoppler = *(const u32 *)&msg->doppler;
  msgdoppler = le32toh(msgdoppler);
  msg->doppler = *(const s32 *)&msgdoppler;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->doppler_std, buf + offset, 2);
  msg->doppler_std = le16toh(msg->doppler_std);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->uptime, buf + offset, 4);
  msg->uptime = le32toh(msg->uptime);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->clock_offset, buf + offset, 2);
  u16 msgclock_offset = *(const u16 *)&msg->clock_offset;
  msgclock_offset = le16toh(msgclock_offset);
  msg->clock_offset = *(const s16 *)&msgclock_offset;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->clock_drift, buf + offset, 2);
  u16 msgclock_drift = *(const u16 *)&msg->clock_drift;
  msgclock_drift = le16toh(msgclock_drift);
  msg->clock_drift = *(const s16 *)&msgclock_drift;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->corr_spacing, buf + offset, 2);
  msg->corr_spacing = le16toh(msg->corr_spacing);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->acceleration, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sync_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->tow_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->track_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->nav_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->pset_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->misc_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t
sbp_packed_size_sbp_msg_tracking_state_detailed_dep_t(const sbp_msg_tracking_state_detailed_dep_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->recv_time) + (0 + sizeof(msg->tot.tow) + sizeof(msg->tot.wn)) + sizeof(msg->P) +
         sizeof(msg->P_std) + (0 + sizeof(msg->L.i) + sizeof(msg->L.f)) + sizeof(msg->cn0) + sizeof(msg->lock) +
         (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code) + sizeof(msg->sid.reserved)) + sizeof(msg->doppler) +
         sizeof(msg->doppler_std) + sizeof(msg->uptime) + sizeof(msg->clock_offset) + sizeof(msg->clock_drift) +
         sizeof(msg->corr_spacing) + sizeof(msg->acceleration) + sizeof(msg->sync_flags) + sizeof(msg->tow_flags) +
         sizeof(msg->track_flags) + sizeof(msg->nav_flags) + sizeof(msg->pset_flags) + sizeof(msg->misc_flags);
}

static inline bool
sbp_pack_sbp_msg_tracking_state_detailed_dep_t(u8 *buf, size_t len, const sbp_msg_tracking_state_detailed_dep_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_tracking_state_detailed_dep_t(msg) > len)
  {
    return false;
  }

  if (offset + 8 > len)
  {
    return false;
  }
  u64 msgrecv_time = htole64(msg->recv_time);
  memcpy(buf + offset, &msgrecv_time, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtottow = htole32(msg->tot.tow);
  memcpy(buf + offset, &msgtottow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtotwn = htole16(msg->tot.wn);
  memcpy(buf + offset, &msgtotwn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgP = htole32(msg->P);
  memcpy(buf + offset, &msgP, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgP_std = htole16(msg->P_std);
  memcpy(buf + offset, &msgP_std, 2);
  // NOLINTNEXTLINE
  offset += 2;

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

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgdoppler = htole32(*(const u32 *)&msg->doppler);
  memcpy(buf + offset, &msgdoppler, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgdoppler_std = htole16(msg->doppler_std);
  memcpy(buf + offset, &msgdoppler_std, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msguptime = htole32(msg->uptime);
  memcpy(buf + offset, &msguptime, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgclock_offset = htole16(*(const u16 *)&msg->clock_offset);
  memcpy(buf + offset, &msgclock_offset, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgclock_drift = htole16(*(const u16 *)&msg->clock_drift);
  memcpy(buf + offset, &msgclock_drift, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcorr_spacing = htole16(msg->corr_spacing);
  memcpy(buf + offset, &msgcorr_spacing, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  s8 msgacceleration = msg->acceleration;
  memcpy(buf + offset, &msgacceleration, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsync_flags = msg->sync_flags;
  memcpy(buf + offset, &msgsync_flags, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgtow_flags = msg->tow_flags;
  memcpy(buf + offset, &msgtow_flags, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgtrack_flags = msg->track_flags;
  memcpy(buf + offset, &msgtrack_flags, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgnav_flags = msg->nav_flags;
  memcpy(buf + offset, &msgnav_flags, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgpset_flags = msg->pset_flags;
  memcpy(buf + offset, &msgpset_flags, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgmisc_flags = msg->misc_flags;
  memcpy(buf + offset, &msgmisc_flags, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool
sbp_unpack_sbp_msg_tracking_state_detailed_dep_t(const u8 *buf, size_t len, sbp_msg_tracking_state_detailed_dep_t *msg)
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
  memcpy(&msg->recv_time, buf + offset, 8);
  msg->recv_time = le64toh(msg->recv_time);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->tot.tow, buf + offset, 4);
  msg->tot.tow = le32toh(msg->tot.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->tot.wn, buf + offset, 2);
  msg->tot.wn = le16toh(msg->tot.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->P, buf + offset, 4);
  msg->P = le32toh(msg->P);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->P_std, buf + offset, 2);
  msg->P_std = le16toh(msg->P_std);
  // NOLINTNEXTLINE
  offset += 2;

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

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->doppler, buf + offset, 4);
  u32 msgdoppler = *(const u32 *)&msg->doppler;
  msgdoppler = le32toh(msgdoppler);
  msg->doppler = *(const s32 *)&msgdoppler;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->doppler_std, buf + offset, 2);
  msg->doppler_std = le16toh(msg->doppler_std);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->uptime, buf + offset, 4);
  msg->uptime = le32toh(msg->uptime);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->clock_offset, buf + offset, 2);
  u16 msgclock_offset = *(const u16 *)&msg->clock_offset;
  msgclock_offset = le16toh(msgclock_offset);
  msg->clock_offset = *(const s16 *)&msgclock_offset;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->clock_drift, buf + offset, 2);
  u16 msgclock_drift = *(const u16 *)&msg->clock_drift;
  msgclock_drift = le16toh(msgclock_drift);
  msg->clock_drift = *(const s16 *)&msgclock_drift;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->corr_spacing, buf + offset, 2);
  msg->corr_spacing = le16toh(msg->corr_spacing);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->acceleration, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sync_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->tow_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->track_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->nav_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->pset_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->misc_flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_tracking_channel_state_t(const sbp_tracking_channel_state_t *msg)
{
  (void)msg;
  return 0 + (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code)) + sizeof(msg->fcn) + sizeof(msg->cn0);
}

static inline bool sbp_pack_sbp_tracking_channel_state_t(u8 *buf, size_t len, const sbp_tracking_channel_state_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_tracking_channel_state_t(msg) > len)
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
  u8 msgfcn = msg->fcn;
  memcpy(buf + offset, &msgfcn, 1);
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
  return true;
}

static inline bool sbp_unpack_sbp_tracking_channel_state_t(const u8 *buf, size_t len, sbp_tracking_channel_state_t *msg)
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
  memcpy(&msg->fcn, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->cn0, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_tracking_state_t(const sbp_msg_tracking_state_t *msg)
{
  (void)msg;
  return 0 + (msg->states_count * (0 + (0 + sizeof(msg->states[0].sid.sat) + sizeof(msg->states[0].sid.code)) +
                                   sizeof(msg->states[0].fcn) + sizeof(msg->states[0].cn0)));
}

static inline bool sbp_pack_sbp_msg_tracking_state_t(u8 *buf, size_t len, const sbp_msg_tracking_state_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_tracking_state_t(msg) > len)
  {
    return false;
  }

  for (size_t msgstates_idx = 0; msgstates_idx < (size_t)msg->states_count; msgstates_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstatesmsgstates_idxsidsat = msg->states[msgstates_idx].sid.sat;
    memcpy(buf + offset, &msgstatesmsgstates_idxsidsat, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstatesmsgstates_idxsidcode = msg->states[msgstates_idx].sid.code;
    memcpy(buf + offset, &msgstatesmsgstates_idxsidcode, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstatesmsgstates_idxfcn = msg->states[msgstates_idx].fcn;
    memcpy(buf + offset, &msgstatesmsgstates_idxfcn, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstatesmsgstates_idxcn0 = msg->states[msgstates_idx].cn0;
    memcpy(buf + offset, &msgstatesmsgstates_idxcn0, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_tracking_state_t(const u8 *buf, size_t len, sbp_msg_tracking_state_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  msg->states_count = (u8)((len - offset) / 4);

  for (size_t msgstates_idx = 0; msgstates_idx < msg->states_count; msgstates_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->states[msgstates_idx].sid.sat, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->states[msgstates_idx].sid.code, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->states[msgstates_idx].fcn, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->states[msgstates_idx].cn0, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_measurement_state_t(const sbp_measurement_state_t *msg)
{
  (void)msg;
  return 0 + (0 + sizeof(msg->mesid.sat) + sizeof(msg->mesid.code)) + sizeof(msg->cn0);
}

static inline bool sbp_pack_sbp_measurement_state_t(u8 *buf, size_t len, const sbp_measurement_state_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_measurement_state_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgmesidsat = msg->mesid.sat;
  memcpy(buf + offset, &msgmesidsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgmesidcode = msg->mesid.code;
  memcpy(buf + offset, &msgmesidcode, 1);
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
  return true;
}

static inline bool sbp_unpack_sbp_measurement_state_t(const u8 *buf, size_t len, sbp_measurement_state_t *msg)
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
  memcpy(&msg->mesid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->mesid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->cn0, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_measurement_state_t(const sbp_msg_measurement_state_t *msg)
{
  (void)msg;
  return 0 + (msg->states_count * (0 + (0 + sizeof(msg->states[0].mesid.sat) + sizeof(msg->states[0].mesid.code)) +
                                   sizeof(msg->states[0].cn0)));
}

static inline bool sbp_pack_sbp_msg_measurement_state_t(u8 *buf, size_t len, const sbp_msg_measurement_state_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_measurement_state_t(msg) > len)
  {
    return false;
  }

  for (size_t msgstates_idx = 0; msgstates_idx < (size_t)msg->states_count; msgstates_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstatesmsgstates_idxmesidsat = msg->states[msgstates_idx].mesid.sat;
    memcpy(buf + offset, &msgstatesmsgstates_idxmesidsat, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstatesmsgstates_idxmesidcode = msg->states[msgstates_idx].mesid.code;
    memcpy(buf + offset, &msgstatesmsgstates_idxmesidcode, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstatesmsgstates_idxcn0 = msg->states[msgstates_idx].cn0;
    memcpy(buf + offset, &msgstatesmsgstates_idxcn0, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_measurement_state_t(const u8 *buf, size_t len, sbp_msg_measurement_state_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  msg->states_count = (u8)((len - offset) / 3);

  for (size_t msgstates_idx = 0; msgstates_idx < msg->states_count; msgstates_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->states[msgstates_idx].mesid.sat, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->states[msgstates_idx].mesid.code, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->states[msgstates_idx].cn0, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_tracking_channel_correlation_t(const sbp_tracking_channel_correlation_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->I) + sizeof(msg->Q);
}

static inline bool
sbp_pack_sbp_tracking_channel_correlation_t(u8 *buf, size_t len, const sbp_tracking_channel_correlation_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_tracking_channel_correlation_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgI = htole16(*(const u16 *)&msg->I);
  memcpy(buf + offset, &msgI, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgQ = htole16(*(const u16 *)&msg->Q);
  memcpy(buf + offset, &msgQ, 2);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool
sbp_unpack_sbp_tracking_channel_correlation_t(const u8 *buf, size_t len, sbp_tracking_channel_correlation_t *msg)
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
  memcpy(&msg->I, buf + offset, 2);
  u16 msgI = *(const u16 *)&msg->I;
  msgI = le16toh(msgI);
  msg->I = *(const s16 *)&msgI;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->Q, buf + offset, 2);
  u16 msgQ = *(const u16 *)&msg->Q;
  msgQ = le16toh(msgQ);
  msg->Q = *(const s16 *)&msgQ;
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_tracking_iq_t(const sbp_msg_tracking_iq_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->channel) + (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code)) +
         (3 * (0 + sizeof(msg->corrs[0].I) + sizeof(msg->corrs[0].Q)));
}

static inline bool sbp_pack_sbp_msg_tracking_iq_t(u8 *buf, size_t len, const sbp_msg_tracking_iq_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_tracking_iq_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgchannel = msg->channel;
  memcpy(buf + offset, &msgchannel, 1);
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
  for (size_t msgcorrs_idx = 0; msgcorrs_idx < 3; msgcorrs_idx++)
  {

    if (offset + 2 > len)
    {
      return false;
    }
    u16 msgcorrsmsgcorrs_idxI = htole16(*(const u16 *)&msg->corrs[msgcorrs_idx].I);
    memcpy(buf + offset, &msgcorrsmsgcorrs_idxI, 2);
    // NOLINTNEXTLINE
    offset += 2;

    if (offset + 2 > len)
    {
      return false;
    }
    u16 msgcorrsmsgcorrs_idxQ = htole16(*(const u16 *)&msg->corrs[msgcorrs_idx].Q);
    memcpy(buf + offset, &msgcorrsmsgcorrs_idxQ, 2);
    // NOLINTNEXTLINE
    offset += 2;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_tracking_iq_t(const u8 *buf, size_t len, sbp_msg_tracking_iq_t *msg)
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
  memcpy(&msg->channel, buf + offset, 1);
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
  for (size_t msgcorrs_idx = 0; msgcorrs_idx < 3; msgcorrs_idx++)
  {

    if (offset + 2 > len)
    {
      return false;
    }
    memcpy(&msg->corrs[msgcorrs_idx].I, buf + offset, 2);
    u16 msgcorrsmsgcorrs_idxI = *(const u16 *)&msg->corrs[msgcorrs_idx].I;
    msgcorrsmsgcorrs_idxI = le16toh(msgcorrsmsgcorrs_idxI);
    msg->corrs[msgcorrs_idx].I = *(const s16 *)&msgcorrsmsgcorrs_idxI;
    // NOLINTNEXTLINE
    offset += 2;

    if (offset + 2 > len)
    {
      return false;
    }
    memcpy(&msg->corrs[msgcorrs_idx].Q, buf + offset, 2);
    u16 msgcorrsmsgcorrs_idxQ = *(const u16 *)&msg->corrs[msgcorrs_idx].Q;
    msgcorrsmsgcorrs_idxQ = le16toh(msgcorrsmsgcorrs_idxQ);
    msg->corrs[msgcorrs_idx].Q = *(const s16 *)&msgcorrsmsgcorrs_idxQ;
    // NOLINTNEXTLINE
    offset += 2;
  }
  return true;
}

static inline size_t
sbp_packed_size_sbp_tracking_channel_correlation_dep_t(const sbp_tracking_channel_correlation_dep_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->I) + sizeof(msg->Q);
}

static inline bool
sbp_pack_sbp_tracking_channel_correlation_dep_t(u8 *buf, size_t len, const sbp_tracking_channel_correlation_dep_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_tracking_channel_correlation_dep_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgI = htole32(*(const u32 *)&msg->I);
  memcpy(buf + offset, &msgI, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgQ = htole32(*(const u32 *)&msg->Q);
  memcpy(buf + offset, &msgQ, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_tracking_channel_correlation_dep_t(const u8 *buf,
                                                                     size_t len,
                                                                     sbp_tracking_channel_correlation_dep_t *msg)
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
  memcpy(&msg->I, buf + offset, 4);
  u32 msgI = *(const u32 *)&msg->I;
  msgI = le32toh(msgI);
  msg->I = *(const s32 *)&msgI;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->Q, buf + offset, 4);
  u32 msgQ = *(const u32 *)&msg->Q;
  msgQ = le32toh(msgQ);
  msg->Q = *(const s32 *)&msgQ;
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_tracking_iq_dep_b_t(const sbp_msg_tracking_iq_dep_b_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->channel) + (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code)) +
         (3 * (0 + sizeof(msg->corrs[0].I) + sizeof(msg->corrs[0].Q)));
}

static inline bool sbp_pack_sbp_msg_tracking_iq_dep_b_t(u8 *buf, size_t len, const sbp_msg_tracking_iq_dep_b_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_tracking_iq_dep_b_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgchannel = msg->channel;
  memcpy(buf + offset, &msgchannel, 1);
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
  for (size_t msgcorrs_idx = 0; msgcorrs_idx < 3; msgcorrs_idx++)
  {

    if (offset + 4 > len)
    {
      return false;
    }
    u32 msgcorrsmsgcorrs_idxI = htole32(*(const u32 *)&msg->corrs[msgcorrs_idx].I);
    memcpy(buf + offset, &msgcorrsmsgcorrs_idxI, 4);
    // NOLINTNEXTLINE
    offset += 4;

    if (offset + 4 > len)
    {
      return false;
    }
    u32 msgcorrsmsgcorrs_idxQ = htole32(*(const u32 *)&msg->corrs[msgcorrs_idx].Q);
    memcpy(buf + offset, &msgcorrsmsgcorrs_idxQ, 4);
    // NOLINTNEXTLINE
    offset += 4;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_tracking_iq_dep_b_t(const u8 *buf, size_t len, sbp_msg_tracking_iq_dep_b_t *msg)
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
  memcpy(&msg->channel, buf + offset, 1);
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
  for (size_t msgcorrs_idx = 0; msgcorrs_idx < 3; msgcorrs_idx++)
  {

    if (offset + 4 > len)
    {
      return false;
    }
    memcpy(&msg->corrs[msgcorrs_idx].I, buf + offset, 4);
    u32 msgcorrsmsgcorrs_idxI = *(const u32 *)&msg->corrs[msgcorrs_idx].I;
    msgcorrsmsgcorrs_idxI = le32toh(msgcorrsmsgcorrs_idxI);
    msg->corrs[msgcorrs_idx].I = *(const s32 *)&msgcorrsmsgcorrs_idxI;
    // NOLINTNEXTLINE
    offset += 4;

    if (offset + 4 > len)
    {
      return false;
    }
    memcpy(&msg->corrs[msgcorrs_idx].Q, buf + offset, 4);
    u32 msgcorrsmsgcorrs_idxQ = *(const u32 *)&msg->corrs[msgcorrs_idx].Q;
    msgcorrsmsgcorrs_idxQ = le32toh(msgcorrsmsgcorrs_idxQ);
    msg->corrs[msgcorrs_idx].Q = *(const s32 *)&msgcorrsmsgcorrs_idxQ;
    // NOLINTNEXTLINE
    offset += 4;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_tracking_iq_dep_a_t(const sbp_msg_tracking_iq_dep_a_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->channel) + (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code) + sizeof(msg->sid.reserved)) +
         (3 * (0 + sizeof(msg->corrs[0].I) + sizeof(msg->corrs[0].Q)));
}

static inline bool sbp_pack_sbp_msg_tracking_iq_dep_a_t(u8 *buf, size_t len, const sbp_msg_tracking_iq_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_tracking_iq_dep_a_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgchannel = msg->channel;
  memcpy(buf + offset, &msgchannel, 1);
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
  for (size_t msgcorrs_idx = 0; msgcorrs_idx < 3; msgcorrs_idx++)
  {

    if (offset + 4 > len)
    {
      return false;
    }
    u32 msgcorrsmsgcorrs_idxI = htole32(*(const u32 *)&msg->corrs[msgcorrs_idx].I);
    memcpy(buf + offset, &msgcorrsmsgcorrs_idxI, 4);
    // NOLINTNEXTLINE
    offset += 4;

    if (offset + 4 > len)
    {
      return false;
    }
    u32 msgcorrsmsgcorrs_idxQ = htole32(*(const u32 *)&msg->corrs[msgcorrs_idx].Q);
    memcpy(buf + offset, &msgcorrsmsgcorrs_idxQ, 4);
    // NOLINTNEXTLINE
    offset += 4;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_tracking_iq_dep_a_t(const u8 *buf, size_t len, sbp_msg_tracking_iq_dep_a_t *msg)
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
  memcpy(&msg->channel, buf + offset, 1);
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
  for (size_t msgcorrs_idx = 0; msgcorrs_idx < 3; msgcorrs_idx++)
  {

    if (offset + 4 > len)
    {
      return false;
    }
    memcpy(&msg->corrs[msgcorrs_idx].I, buf + offset, 4);
    u32 msgcorrsmsgcorrs_idxI = *(const u32 *)&msg->corrs[msgcorrs_idx].I;
    msgcorrsmsgcorrs_idxI = le32toh(msgcorrsmsgcorrs_idxI);
    msg->corrs[msgcorrs_idx].I = *(const s32 *)&msgcorrsmsgcorrs_idxI;
    // NOLINTNEXTLINE
    offset += 4;

    if (offset + 4 > len)
    {
      return false;
    }
    memcpy(&msg->corrs[msgcorrs_idx].Q, buf + offset, 4);
    u32 msgcorrsmsgcorrs_idxQ = *(const u32 *)&msg->corrs[msgcorrs_idx].Q;
    msgcorrsmsgcorrs_idxQ = le32toh(msgcorrsmsgcorrs_idxQ);
    msg->corrs[msgcorrs_idx].Q = *(const s32 *)&msgcorrsmsgcorrs_idxQ;
    // NOLINTNEXTLINE
    offset += 4;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_tracking_channel_state_dep_a_t(const sbp_tracking_channel_state_dep_a_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->state) + sizeof(msg->prn) + sizeof(msg->cn0);
}

static inline bool
sbp_pack_sbp_tracking_channel_state_dep_a_t(u8 *buf, size_t len, const sbp_tracking_channel_state_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_tracking_channel_state_dep_a_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgstate = msg->state;
  memcpy(buf + offset, &msgstate, 1);
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

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcn0 = msg->cn0;
  memcpy(buf + offset, &msgcn0, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool
sbp_unpack_sbp_tracking_channel_state_dep_a_t(const u8 *buf, size_t len, sbp_tracking_channel_state_dep_a_t *msg)
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
  memcpy(&msg->state, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->prn, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cn0, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_tracking_state_dep_a_t(const sbp_msg_tracking_state_dep_a_t *msg)
{
  (void)msg;
  return 0 + (msg->states_count *
              (0 + sizeof(msg->states[0].state) + sizeof(msg->states[0].prn) + sizeof(msg->states[0].cn0)));
}

static inline bool
sbp_pack_sbp_msg_tracking_state_dep_a_t(u8 *buf, size_t len, const sbp_msg_tracking_state_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_tracking_state_dep_a_t(msg) > len)
  {
    return false;
  }

  for (size_t msgstates_idx = 0; msgstates_idx < (size_t)msg->states_count; msgstates_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstatesmsgstates_idxstate = msg->states[msgstates_idx].state;
    memcpy(buf + offset, &msgstatesmsgstates_idxstate, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstatesmsgstates_idxprn = msg->states[msgstates_idx].prn;
    memcpy(buf + offset, &msgstatesmsgstates_idxprn, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 4 > len)
    {
      return false;
    }
    float msgstatesmsgstates_idxcn0 = msg->states[msgstates_idx].cn0;
    memcpy(buf + offset, &msgstatesmsgstates_idxcn0, 4);
    // NOLINTNEXTLINE
    offset += 4;
  }
  return true;
}

static inline bool
sbp_unpack_sbp_msg_tracking_state_dep_a_t(const u8 *buf, size_t len, sbp_msg_tracking_state_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  msg->states_count = (u8)((len - offset) / 6);

  for (size_t msgstates_idx = 0; msgstates_idx < msg->states_count; msgstates_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->states[msgstates_idx].state, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->states[msgstates_idx].prn, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 4 > len)
    {
      return false;
    }
    memcpy(&msg->states[msgstates_idx].cn0, buf + offset, 4);
    // NOLINTNEXTLINE
    offset += 4;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_tracking_channel_state_dep_b_t(const sbp_tracking_channel_state_dep_b_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->state) + (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code) + sizeof(msg->sid.reserved)) +
         sizeof(msg->cn0);
}

static inline bool
sbp_pack_sbp_tracking_channel_state_dep_b_t(u8 *buf, size_t len, const sbp_tracking_channel_state_dep_b_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_tracking_channel_state_dep_b_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgstate = msg->state;
  memcpy(buf + offset, &msgstate, 1);
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

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcn0 = msg->cn0;
  memcpy(buf + offset, &msgcn0, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool
sbp_unpack_sbp_tracking_channel_state_dep_b_t(const u8 *buf, size_t len, sbp_tracking_channel_state_dep_b_t *msg)
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
  memcpy(&msg->state, buf + offset, 1);
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

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cn0, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_tracking_state_dep_b_t(const sbp_msg_tracking_state_dep_b_t *msg)
{
  (void)msg;
  return 0 + (msg->states_count * (0 + sizeof(msg->states[0].state) +
                                   (0 + sizeof(msg->states[0].sid.sat) + sizeof(msg->states[0].sid.code) +
                                    sizeof(msg->states[0].sid.reserved)) +
                                   sizeof(msg->states[0].cn0)));
}

static inline bool
sbp_pack_sbp_msg_tracking_state_dep_b_t(u8 *buf, size_t len, const sbp_msg_tracking_state_dep_b_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_tracking_state_dep_b_t(msg) > len)
  {
    return false;
  }

  for (size_t msgstates_idx = 0; msgstates_idx < (size_t)msg->states_count; msgstates_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstatesmsgstates_idxstate = msg->states[msgstates_idx].state;
    memcpy(buf + offset, &msgstatesmsgstates_idxstate, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 2 > len)
    {
      return false;
    }
    u16 msgstatesmsgstates_idxsidsat = htole16(msg->states[msgstates_idx].sid.sat);
    memcpy(buf + offset, &msgstatesmsgstates_idxsidsat, 2);
    // NOLINTNEXTLINE
    offset += 2;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstatesmsgstates_idxsidcode = msg->states[msgstates_idx].sid.code;
    memcpy(buf + offset, &msgstatesmsgstates_idxsidcode, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstatesmsgstates_idxsidreserved = msg->states[msgstates_idx].sid.reserved;
    memcpy(buf + offset, &msgstatesmsgstates_idxsidreserved, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 4 > len)
    {
      return false;
    }
    float msgstatesmsgstates_idxcn0 = msg->states[msgstates_idx].cn0;
    memcpy(buf + offset, &msgstatesmsgstates_idxcn0, 4);
    // NOLINTNEXTLINE
    offset += 4;
  }
  return true;
}

static inline bool
sbp_unpack_sbp_msg_tracking_state_dep_b_t(const u8 *buf, size_t len, sbp_msg_tracking_state_dep_b_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  msg->states_count = (u8)((len - offset) / 9);

  for (size_t msgstates_idx = 0; msgstates_idx < msg->states_count; msgstates_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->states[msgstates_idx].state, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 2 > len)
    {
      return false;
    }
    memcpy(&msg->states[msgstates_idx].sid.sat, buf + offset, 2);
    msg->states[msgstates_idx].sid.sat = le16toh(msg->states[msgstates_idx].sid.sat);
    // NOLINTNEXTLINE
    offset += 2;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->states[msgstates_idx].sid.code, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->states[msgstates_idx].sid.reserved, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 4 > len)
    {
      return false;
    }
    memcpy(&msg->states[msgstates_idx].cn0, buf + offset, 4);
    // NOLINTNEXTLINE
    offset += 4;
  }
  return true;
}

#endif
