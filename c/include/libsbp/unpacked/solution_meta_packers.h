#ifndef LIBSBP_SOLUTION_META_PACKERS_H
#define LIBSBP_SOLUTION_META_PACKERS_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/string2.h>
//#include <libsbp/unpacked/solution_meta.h>

static inline size_t sbp_packed_size_sbp_solution_input_type_t(const sbp_solution_input_type_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->sensor_type) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_solution_input_type_t(u8 *buf, size_t len, const sbp_solution_input_type_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_solution_input_type_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsensor_type = msg->sensor_type;
  memcpy(buf + offset, &msgsensor_type, 1);
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
  return true;
}

static inline bool sbp_unpack_sbp_solution_input_type_t(const u8 *buf, size_t len, sbp_solution_input_type_t *msg)
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
  memcpy(&msg->sensor_type, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_soln_meta_dep_a_t(const sbp_msg_soln_meta_dep_a_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->pdop) + sizeof(msg->hdop) + sizeof(msg->vdop) + sizeof(msg->n_sats) +
         sizeof(msg->age_corrections) + sizeof(msg->alignment_status) + sizeof(msg->last_used_gnss_pos_tow) +
         sizeof(msg->last_used_gnss_vel_tow) +
         (msg->sol_in_count * (0 + sizeof(msg->sol_in[0].sensor_type) + sizeof(msg->sol_in[0].flags)));
}

static inline bool sbp_pack_sbp_msg_soln_meta_dep_a_t(u8 *buf, size_t len, const sbp_msg_soln_meta_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_soln_meta_dep_a_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgpdop = htole16(msg->pdop);
  memcpy(buf + offset, &msgpdop, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msghdop = htole16(msg->hdop);
  memcpy(buf + offset, &msghdop, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgvdop = htole16(msg->vdop);
  memcpy(buf + offset, &msgvdop, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgage_corrections = htole16(msg->age_corrections);
  memcpy(buf + offset, &msgage_corrections, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgalignment_status = msg->alignment_status;
  memcpy(buf + offset, &msgalignment_status, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msglast_used_gnss_pos_tow = htole32(msg->last_used_gnss_pos_tow);
  memcpy(buf + offset, &msglast_used_gnss_pos_tow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msglast_used_gnss_vel_tow = htole32(msg->last_used_gnss_vel_tow);
  memcpy(buf + offset, &msglast_used_gnss_vel_tow, 4);
  // NOLINTNEXTLINE
  offset += 4;
  for (size_t msgsol_in_idx = 0; msgsol_in_idx < (size_t)msg->sol_in_count; msgsol_in_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgsol_inmsgsol_in_idxsensor_type = msg->sol_in[msgsol_in_idx].sensor_type;
    memcpy(buf + offset, &msgsol_inmsgsol_in_idxsensor_type, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgsol_inmsgsol_in_idxflags = msg->sol_in[msgsol_in_idx].flags;
    memcpy(buf + offset, &msgsol_inmsgsol_in_idxflags, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_soln_meta_dep_a_t(const u8 *buf, size_t len, sbp_msg_soln_meta_dep_a_t *msg)
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
  memcpy(&msg->pdop, buf + offset, 2);
  msg->pdop = le16toh(msg->pdop);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->hdop, buf + offset, 2);
  msg->hdop = le16toh(msg->hdop);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->vdop, buf + offset, 2);
  msg->vdop = le16toh(msg->vdop);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->age_corrections, buf + offset, 2);
  msg->age_corrections = le16toh(msg->age_corrections);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->alignment_status, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->last_used_gnss_pos_tow, buf + offset, 4);
  msg->last_used_gnss_pos_tow = le32toh(msg->last_used_gnss_pos_tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->last_used_gnss_vel_tow, buf + offset, 4);
  msg->last_used_gnss_vel_tow = le32toh(msg->last_used_gnss_vel_tow);
  // NOLINTNEXTLINE
  offset += 4;
  msg->sol_in_count = (u8)((len - offset) / 2);

  for (size_t msgsol_in_idx = 0; msgsol_in_idx < msg->sol_in_count; msgsol_in_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->sol_in[msgsol_in_idx].sensor_type, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->sol_in[msgsol_in_idx].flags, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_soln_meta_t(const sbp_msg_soln_meta_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->pdop) + sizeof(msg->hdop) + sizeof(msg->vdop) +
         sizeof(msg->age_corrections) + sizeof(msg->age_gnss) +
         (msg->sol_in_count * (0 + sizeof(msg->sol_in[0].sensor_type) + sizeof(msg->sol_in[0].flags)));
}

static inline bool sbp_pack_sbp_msg_soln_meta_t(u8 *buf, size_t len, const sbp_msg_soln_meta_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_soln_meta_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtow = htole32(msg->tow);
  memcpy(buf + offset, &msgtow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgpdop = htole16(msg->pdop);
  memcpy(buf + offset, &msgpdop, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msghdop = htole16(msg->hdop);
  memcpy(buf + offset, &msghdop, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgvdop = htole16(msg->vdop);
  memcpy(buf + offset, &msgvdop, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgage_corrections = htole16(msg->age_corrections);
  memcpy(buf + offset, &msgage_corrections, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgage_gnss = htole32(msg->age_gnss);
  memcpy(buf + offset, &msgage_gnss, 4);
  // NOLINTNEXTLINE
  offset += 4;
  for (size_t msgsol_in_idx = 0; msgsol_in_idx < (size_t)msg->sol_in_count; msgsol_in_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgsol_inmsgsol_in_idxsensor_type = msg->sol_in[msgsol_in_idx].sensor_type;
    memcpy(buf + offset, &msgsol_inmsgsol_in_idxsensor_type, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgsol_inmsgsol_in_idxflags = msg->sol_in[msgsol_in_idx].flags;
    memcpy(buf + offset, &msgsol_inmsgsol_in_idxflags, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_soln_meta_t(const u8 *buf, size_t len, sbp_msg_soln_meta_t *msg)
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
  memcpy(&msg->tow, buf + offset, 4);
  msg->tow = le32toh(msg->tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->pdop, buf + offset, 2);
  msg->pdop = le16toh(msg->pdop);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->hdop, buf + offset, 2);
  msg->hdop = le16toh(msg->hdop);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->vdop, buf + offset, 2);
  msg->vdop = le16toh(msg->vdop);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->age_corrections, buf + offset, 2);
  msg->age_corrections = le16toh(msg->age_corrections);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->age_gnss, buf + offset, 4);
  msg->age_gnss = le32toh(msg->age_gnss);
  // NOLINTNEXTLINE
  offset += 4;
  msg->sol_in_count = (u8)((len - offset) / 2);

  for (size_t msgsol_in_idx = 0; msgsol_in_idx < msg->sol_in_count; msgsol_in_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->sol_in[msgsol_in_idx].sensor_type, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->sol_in[msgsol_in_idx].flags, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_gnss_input_type_t(const sbp_gnss_input_type_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_gnss_input_type_t(u8 *buf, size_t len, const sbp_gnss_input_type_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_gnss_input_type_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_gnss_input_type_t(const u8 *buf, size_t len, sbp_gnss_input_type_t *msg)
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
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_imu_input_type_t(const sbp_imu_input_type_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_imu_input_type_t(u8 *buf, size_t len, const sbp_imu_input_type_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_imu_input_type_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_imu_input_type_t(const u8 *buf, size_t len, sbp_imu_input_type_t *msg)
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
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_odo_input_type_t(const sbp_odo_input_type_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_odo_input_type_t(u8 *buf, size_t len, const sbp_odo_input_type_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_odo_input_type_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_odo_input_type_t(const u8 *buf, size_t len, sbp_odo_input_type_t *msg)
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
  memcpy(&msg->flags, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

#endif
