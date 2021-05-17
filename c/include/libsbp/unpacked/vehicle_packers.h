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
#include <libsbp/string.h>
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_odometry_t(const sbp_msg_odometry_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->velocity);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_odometry_t(u8 *buf, size_t len, const sbp_msg_odometry_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_odometry_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->velocity);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_odometry_t(const uint8_t *buf, size_t len, sbp_msg_odometry_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->velocity);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_wheeltick_t(const sbp_msg_wheeltick_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u64(&msg->time);
  packed_size += sbp_packed_size_u8(&msg->flags);
  packed_size += sbp_packed_size_u8(&msg->source);
  packed_size += sbp_packed_size_s32(&msg->ticks);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_wheeltick_t(u8 *buf, size_t len, const sbp_msg_wheeltick_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_wheeltick_t(msg) > len) { return false; }
  offset += sbp_pack_u64(buf + offset, len - offset, &msg->time);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->source);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->ticks);
  return true;
}

static inline bool sbp_unpack_sbp_msg_wheeltick_t(const uint8_t *buf, size_t len, sbp_msg_wheeltick_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u64(buf + offset, len - offset, &msg->time);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->source);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->ticks);
  return true;
}

#endif
