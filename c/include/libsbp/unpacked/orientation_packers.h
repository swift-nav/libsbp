#ifndef LIBSBP_ORIENTATION_PACKERS_H
#define LIBSBP_ORIENTATION_PACKERS_H

#ifndef LIBSBP_ORIENTATION_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/orientation.h instead"
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
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_baseline_heading_t(const sbp_msg_baseline_heading_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u32(&msg->heading);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_baseline_heading_t(sbp_pack_ctx_t *ctx, const sbp_msg_baseline_heading_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->heading)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_baseline_heading_t(sbp_unpack_ctx_t *ctx, sbp_msg_baseline_heading_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->heading)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_orient_quat_t(const sbp_msg_orient_quat_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->w);
  packed_size += sbp_packed_size_s32(&msg->x);
  packed_size += sbp_packed_size_s32(&msg->y);
  packed_size += sbp_packed_size_s32(&msg->z);
  packed_size += sbp_packed_size_float(&msg->w_accuracy);
  packed_size += sbp_packed_size_float(&msg->x_accuracy);
  packed_size += sbp_packed_size_float(&msg->y_accuracy);
  packed_size += sbp_packed_size_float(&msg->z_accuracy);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_orient_quat_t(sbp_pack_ctx_t *ctx, const sbp_msg_orient_quat_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->w)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->x)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->y)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->z)) { return false; }
  if (!sbp_pack_float(ctx, &msg->w_accuracy)) { return false; }
  if (!sbp_pack_float(ctx, &msg->x_accuracy)) { return false; }
  if (!sbp_pack_float(ctx, &msg->y_accuracy)) { return false; }
  if (!sbp_pack_float(ctx, &msg->z_accuracy)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_orient_quat_t(sbp_unpack_ctx_t *ctx, sbp_msg_orient_quat_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->w)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->x)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->y)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->z)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->w_accuracy)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->x_accuracy)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->y_accuracy)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->z_accuracy)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_orient_euler_t(const sbp_msg_orient_euler_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->roll);
  packed_size += sbp_packed_size_s32(&msg->pitch);
  packed_size += sbp_packed_size_s32(&msg->yaw);
  packed_size += sbp_packed_size_float(&msg->roll_accuracy);
  packed_size += sbp_packed_size_float(&msg->pitch_accuracy);
  packed_size += sbp_packed_size_float(&msg->yaw_accuracy);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_orient_euler_t(sbp_pack_ctx_t *ctx, const sbp_msg_orient_euler_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->roll)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->pitch)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->yaw)) { return false; }
  if (!sbp_pack_float(ctx, &msg->roll_accuracy)) { return false; }
  if (!sbp_pack_float(ctx, &msg->pitch_accuracy)) { return false; }
  if (!sbp_pack_float(ctx, &msg->yaw_accuracy)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_orient_euler_t(sbp_unpack_ctx_t *ctx, sbp_msg_orient_euler_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->roll)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->pitch)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->yaw)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->roll_accuracy)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->pitch_accuracy)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->yaw_accuracy)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_angular_rate_t(const sbp_msg_angular_rate_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->x);
  packed_size += sbp_packed_size_s32(&msg->y);
  packed_size += sbp_packed_size_s32(&msg->z);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_angular_rate_t(sbp_pack_ctx_t *ctx, const sbp_msg_angular_rate_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->x)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->y)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->z)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_angular_rate_t(sbp_unpack_ctx_t *ctx, sbp_msg_angular_rate_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->x)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->y)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->z)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

#endif
