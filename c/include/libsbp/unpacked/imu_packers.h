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
#include <libsbp/string.h>
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_imu_raw_t(const sbp_msg_imu_raw_t *msg) {
  size_t packed_size = 0;
  (void)msg;
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

static inline bool sbp_pack_sbp_msg_imu_raw_t(u8 *buf, size_t len, const sbp_msg_imu_raw_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_imu_raw_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->tow_f);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->acc_x);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->acc_y);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->acc_z);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->gyr_x);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->gyr_y);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->gyr_z);
  return true;
}

static inline bool sbp_unpack_sbp_msg_imu_raw_t(const uint8_t *buf, size_t len, sbp_msg_imu_raw_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->tow_f);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->acc_x);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->acc_y);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->acc_z);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->gyr_x);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->gyr_y);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->gyr_z);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_imu_aux_t(const sbp_msg_imu_aux_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->imu_type);
  packed_size += sbp_packed_size_s16(&msg->temp);
  packed_size += sbp_packed_size_u8(&msg->imu_conf);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_imu_aux_t(u8 *buf, size_t len, const sbp_msg_imu_aux_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_imu_aux_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->imu_type);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->temp);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->imu_conf);
  return true;
}

static inline bool sbp_unpack_sbp_msg_imu_aux_t(const uint8_t *buf, size_t len, sbp_msg_imu_aux_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->imu_type);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->temp);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->imu_conf);
  return true;
}

#endif
