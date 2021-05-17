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
#include <libsbp/string.h>
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_baseline_heading_t(const sbp_msg_baseline_heading_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u32(&msg->heading);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_baseline_heading_t(u8 *buf, size_t len, const sbp_msg_baseline_heading_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_baseline_heading_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->heading);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_baseline_heading_t(const uint8_t *buf, size_t len, sbp_msg_baseline_heading_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->heading);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_orient_quat_t(const sbp_msg_orient_quat_t *msg) {
  size_t packed_size = 0;
  (void)msg;
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

static inline bool sbp_pack_sbp_msg_orient_quat_t(u8 *buf, size_t len, const sbp_msg_orient_quat_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_orient_quat_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->w);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->x);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->y);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->z);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->w_accuracy);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->x_accuracy);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->y_accuracy);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->z_accuracy);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_orient_quat_t(const uint8_t *buf, size_t len, sbp_msg_orient_quat_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->w);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->x);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->y);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->z);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->w_accuracy);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->x_accuracy);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->y_accuracy);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->z_accuracy);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_orient_euler_t(const sbp_msg_orient_euler_t *msg) {
  size_t packed_size = 0;
  (void)msg;
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

static inline bool sbp_pack_sbp_msg_orient_euler_t(u8 *buf, size_t len, const sbp_msg_orient_euler_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_orient_euler_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->roll);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->pitch);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->yaw);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->roll_accuracy);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->pitch_accuracy);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->yaw_accuracy);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_orient_euler_t(const uint8_t *buf, size_t len, sbp_msg_orient_euler_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->roll);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->pitch);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->yaw);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->roll_accuracy);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->pitch_accuracy);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->yaw_accuracy);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_angular_rate_t(const sbp_msg_angular_rate_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->x);
  packed_size += sbp_packed_size_s32(&msg->y);
  packed_size += sbp_packed_size_s32(&msg->z);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_angular_rate_t(u8 *buf, size_t len, const sbp_msg_angular_rate_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_angular_rate_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->x);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->y);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->z);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_angular_rate_t(const uint8_t *buf, size_t len, sbp_msg_angular_rate_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->x);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->y);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->z);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

#endif
