#ifndef LIBSBP_VEHICLE_PACKERS_H
#define LIBSBP_VEHICLE_PACKERS_H

#ifndef LIBSBP_VEHICLE_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/vehicle.h instead"
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
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_odometry_t(const sbp_msg_odometry_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->velocity);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_odometry_t(sbp_pack_ctx_t *ctx, const sbp_msg_odometry_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->velocity)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_odometry_t(sbp_unpack_ctx_t *ctx, sbp_msg_odometry_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->velocity)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_wheeltick_t(const sbp_msg_wheeltick_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u64(&msg->time);
  packed_size += sbp_packed_size_u8(&msg->flags);
  packed_size += sbp_packed_size_u8(&msg->source);
  packed_size += sbp_packed_size_s32(&msg->ticks);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_wheeltick_t(sbp_pack_ctx_t *ctx, const sbp_msg_wheeltick_t *msg)
{
  if (!sbp_pack_u64(ctx, &msg->time)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->source)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->ticks)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_wheeltick_t(sbp_unpack_ctx_t *ctx, sbp_msg_wheeltick_t *msg)
{
  if (!sbp_unpack_u64(ctx, &msg->time)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->source)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->ticks)) { return false; }
  return true;
}

#endif
