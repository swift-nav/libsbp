#ifndef LIBSBP_IMU_PACKERS_H
#define LIBSBP_IMU_PACKERS_H

#ifndef LIBSBP_IMU_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/imu.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/base.h>
#include <libsbp/unpacked/common.h>
#include <libsbp/string.h>
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_imu_raw_t(const sbp_msg_imu_raw_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u8(&msg->tow_f);
  packed_size += sbp_packed_size_s16(&msg->acc_x);
  packed_size += sbp_packed_size_s16(&msg->acc_y);
  packed_size += sbp_packed_size_s16(&msg->acc_z);
  packed_size += sbp_packed_size_s16(&msg->gyr_x);
  packed_size += sbp_packed_size_s16(&msg->gyr_y);
  packed_size += sbp_packed_size_s16(&msg->gyr_z);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_imu_raw_t(sbp_pack_ctx_t *ctx, const sbp_msg_imu_raw_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->tow_f)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->acc_x)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->acc_y)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->acc_z)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->gyr_x)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->gyr_y)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->gyr_z)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_imu_raw_t(sbp_unpack_ctx_t *ctx, sbp_msg_imu_raw_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->tow_f)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->acc_x)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->acc_y)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->acc_z)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->gyr_x)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->gyr_y)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->gyr_z)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_imu_aux_t(const sbp_msg_imu_aux_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->imu_type);
  packed_size += sbp_packed_size_s16(&msg->temp);
  packed_size += sbp_packed_size_u8(&msg->imu_conf);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_imu_aux_t(sbp_pack_ctx_t *ctx, const sbp_msg_imu_aux_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->imu_type)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->temp)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->imu_conf)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_imu_aux_t(sbp_unpack_ctx_t *ctx, sbp_msg_imu_aux_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->imu_type)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->temp)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->imu_conf)) { return false; }
  return true;
}

#endif
