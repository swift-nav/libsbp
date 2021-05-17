#ifndef LIBSBP_SOLUTION_META_PACKERS_H
#define LIBSBP_SOLUTION_META_PACKERS_H

#ifndef LIBSBP_SOLUTION_META_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/solution_meta.h instead"
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
                                                                                                              
static inline size_t sbp_packed_size_sbp_solution_input_type_t(const sbp_solution_input_type_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->sensor_type);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline size_t sbp_pack_sbp_solution_input_type_t(u8 *buf, size_t len, const sbp_solution_input_type_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_solution_input_type_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->sensor_type);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return offset;
}

static inline size_t sbp_unpack_sbp_solution_input_type_t(const uint8_t *buf, size_t len, sbp_solution_input_type_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->sensor_type);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_soln_meta_dep_a_t(const sbp_msg_soln_meta_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u16(&msg->pdop);
  packed_size += sbp_packed_size_u16(&msg->hdop);
  packed_size += sbp_packed_size_u16(&msg->vdop);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u16(&msg->age_corrections);
  packed_size += sbp_packed_size_u8(&msg->alignment_status);
  packed_size += sbp_packed_size_u32(&msg->last_used_gnss_pos_tow);
  packed_size += sbp_packed_size_u32(&msg->last_used_gnss_vel_tow);
  packed_size += (msg->n_sol_in * sbp_packed_size_sbp_solution_input_type_t(&msg->sol_in[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_soln_meta_dep_a_t(u8 *buf, size_t len, const sbp_msg_soln_meta_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_soln_meta_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->pdop);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->hdop);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->vdop);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->age_corrections);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->alignment_status);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->last_used_gnss_pos_tow);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->last_used_gnss_vel_tow);
  for (uint8_t i = 0; i < msg->n_sol_in; i++) 
  {
    offset += sbp_pack_sbp_solution_input_type_t(buf + offset, len - offset, &msg->sol_in[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_soln_meta_dep_a_t(const uint8_t *buf, size_t len, sbp_msg_soln_meta_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->pdop);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->hdop);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->vdop);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->age_corrections);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->alignment_status);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->last_used_gnss_pos_tow);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->last_used_gnss_vel_tow);
  msg->n_sol_in = (uint8_t)((len - offset) / sbp_packed_size_sbp_solution_input_type_t(&msg->sol_in[0]));
  for (uint8_t i = 0; i < msg->n_sol_in; i++)
  {
    offset += sbp_unpack_sbp_solution_input_type_t(buf + offset, len - offset, &msg->sol_in[i]);
  }
  return true;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_soln_meta_t(const sbp_msg_soln_meta_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u16(&msg->pdop);
  packed_size += sbp_packed_size_u16(&msg->hdop);
  packed_size += sbp_packed_size_u16(&msg->vdop);
  packed_size += sbp_packed_size_u16(&msg->age_corrections);
  packed_size += sbp_packed_size_u32(&msg->age_gnss);
  packed_size += (msg->n_sol_in * sbp_packed_size_sbp_solution_input_type_t(&msg->sol_in[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_soln_meta_t(u8 *buf, size_t len, const sbp_msg_soln_meta_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_soln_meta_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->pdop);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->hdop);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->vdop);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->age_corrections);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->age_gnss);
  for (uint8_t i = 0; i < msg->n_sol_in; i++) 
  {
    offset += sbp_pack_sbp_solution_input_type_t(buf + offset, len - offset, &msg->sol_in[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_soln_meta_t(const uint8_t *buf, size_t len, sbp_msg_soln_meta_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->pdop);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->hdop);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->vdop);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->age_corrections);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->age_gnss);
  msg->n_sol_in = (uint8_t)((len - offset) / sbp_packed_size_sbp_solution_input_type_t(&msg->sol_in[0]));
  for (uint8_t i = 0; i < msg->n_sol_in; i++)
  {
    offset += sbp_unpack_sbp_solution_input_type_t(buf + offset, len - offset, &msg->sol_in[i]);
  }
  return true;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_gnss_input_type_t(const sbp_gnss_input_type_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline size_t sbp_pack_sbp_gnss_input_type_t(u8 *buf, size_t len, const sbp_gnss_input_type_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_gnss_input_type_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return offset;
}

static inline size_t sbp_unpack_sbp_gnss_input_type_t(const uint8_t *buf, size_t len, sbp_gnss_input_type_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_imu_input_type_t(const sbp_imu_input_type_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline size_t sbp_pack_sbp_imu_input_type_t(u8 *buf, size_t len, const sbp_imu_input_type_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_imu_input_type_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return offset;
}

static inline size_t sbp_unpack_sbp_imu_input_type_t(const uint8_t *buf, size_t len, sbp_imu_input_type_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_odo_input_type_t(const sbp_odo_input_type_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline size_t sbp_pack_sbp_odo_input_type_t(u8 *buf, size_t len, const sbp_odo_input_type_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_odo_input_type_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return offset;
}

static inline size_t sbp_unpack_sbp_odo_input_type_t(const uint8_t *buf, size_t len, sbp_odo_input_type_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return offset;
}

#endif
