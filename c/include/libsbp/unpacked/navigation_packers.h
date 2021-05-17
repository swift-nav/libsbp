#ifndef LIBSBP_NAVIGATION_PACKERS_H
#define LIBSBP_NAVIGATION_PACKERS_H

#ifndef LIBSBP_NAVIGATION_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/navigation.h instead"
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
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_gps_time_t(const sbp_msg_gps_time_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u16(&msg->wn);
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->ns_residual);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_gps_time_t(u8 *buf, size_t len, const sbp_msg_gps_time_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_gps_time_t(msg) > len) { return false; }
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->wn);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->ns_residual);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_gps_time_t(const uint8_t *buf, size_t len, sbp_msg_gps_time_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->wn);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->ns_residual);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_gps_time_gnss_t(const sbp_msg_gps_time_gnss_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u16(&msg->wn);
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->ns_residual);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_gps_time_gnss_t(u8 *buf, size_t len, const sbp_msg_gps_time_gnss_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_gps_time_gnss_t(msg) > len) { return false; }
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->wn);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->ns_residual);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_gps_time_gnss_t(const uint8_t *buf, size_t len, sbp_msg_gps_time_gnss_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->wn);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->ns_residual);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_utc_time_t(const sbp_msg_utc_time_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->flags);
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u16(&msg->year);
  packed_size += sbp_packed_size_u8(&msg->month);
  packed_size += sbp_packed_size_u8(&msg->day);
  packed_size += sbp_packed_size_u8(&msg->hours);
  packed_size += sbp_packed_size_u8(&msg->minutes);
  packed_size += sbp_packed_size_u8(&msg->seconds);
  packed_size += sbp_packed_size_u32(&msg->ns);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_utc_time_t(u8 *buf, size_t len, const sbp_msg_utc_time_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_utc_time_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->year);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->month);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->day);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->hours);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->minutes);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->seconds);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->ns);
  return true;
}

static inline bool sbp_unpack_sbp_msg_utc_time_t(const uint8_t *buf, size_t len, sbp_msg_utc_time_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->year);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->month);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->day);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->hours);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->minutes);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->seconds);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->ns);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_utc_time_gnss_t(const sbp_msg_utc_time_gnss_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->flags);
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u16(&msg->year);
  packed_size += sbp_packed_size_u8(&msg->month);
  packed_size += sbp_packed_size_u8(&msg->day);
  packed_size += sbp_packed_size_u8(&msg->hours);
  packed_size += sbp_packed_size_u8(&msg->minutes);
  packed_size += sbp_packed_size_u8(&msg->seconds);
  packed_size += sbp_packed_size_u32(&msg->ns);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_utc_time_gnss_t(u8 *buf, size_t len, const sbp_msg_utc_time_gnss_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_utc_time_gnss_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->year);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->month);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->day);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->hours);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->minutes);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->seconds);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->ns);
  return true;
}

static inline bool sbp_unpack_sbp_msg_utc_time_gnss_t(const uint8_t *buf, size_t len, sbp_msg_utc_time_gnss_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->year);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->month);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->day);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->hours);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->minutes);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->seconds);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->ns);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_dops_t(const sbp_msg_dops_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u16(&msg->gdop);
  packed_size += sbp_packed_size_u16(&msg->pdop);
  packed_size += sbp_packed_size_u16(&msg->tdop);
  packed_size += sbp_packed_size_u16(&msg->hdop);
  packed_size += sbp_packed_size_u16(&msg->vdop);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_dops_t(u8 *buf, size_t len, const sbp_msg_dops_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_dops_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->gdop);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->pdop);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->tdop);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->hdop);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->vdop);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_dops_t(const uint8_t *buf, size_t len, sbp_msg_dops_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->gdop);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->pdop);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->tdop);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->hdop);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->vdop);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_pos_ecef_t(const sbp_msg_pos_ecef_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_double(&msg->x);
  packed_size += sbp_packed_size_double(&msg->y);
  packed_size += sbp_packed_size_double(&msg->z);
  packed_size += sbp_packed_size_u16(&msg->accuracy);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_pos_ecef_t(u8 *buf, size_t len, const sbp_msg_pos_ecef_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_pos_ecef_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->x);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->y);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->z);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->accuracy);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_ecef_t(const uint8_t *buf, size_t len, sbp_msg_pos_ecef_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->x);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->y);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->z);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->accuracy);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_pos_ecef_cov_t(const sbp_msg_pos_ecef_cov_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_double(&msg->x);
  packed_size += sbp_packed_size_double(&msg->y);
  packed_size += sbp_packed_size_double(&msg->z);
  packed_size += sbp_packed_size_float(&msg->cov_x_x);
  packed_size += sbp_packed_size_float(&msg->cov_x_y);
  packed_size += sbp_packed_size_float(&msg->cov_x_z);
  packed_size += sbp_packed_size_float(&msg->cov_y_y);
  packed_size += sbp_packed_size_float(&msg->cov_y_z);
  packed_size += sbp_packed_size_float(&msg->cov_z_z);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_pos_ecef_cov_t(u8 *buf, size_t len, const sbp_msg_pos_ecef_cov_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_pos_ecef_cov_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->x);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->y);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->z);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_x_x);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_x_y);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_x_z);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_y_y);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_y_z);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_z_z);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_ecef_cov_t(const uint8_t *buf, size_t len, sbp_msg_pos_ecef_cov_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->x);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->y);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->z);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_x_x);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_x_y);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_x_z);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_y_y);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_y_z);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_z_z);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_pos_llh_t(const sbp_msg_pos_llh_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_double(&msg->lat);
  packed_size += sbp_packed_size_double(&msg->lon);
  packed_size += sbp_packed_size_double(&msg->height);
  packed_size += sbp_packed_size_u16(&msg->h_accuracy);
  packed_size += sbp_packed_size_u16(&msg->v_accuracy);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_pos_llh_t(u8 *buf, size_t len, const sbp_msg_pos_llh_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_pos_llh_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->lat);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->lon);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->height);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->h_accuracy);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->v_accuracy);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_llh_t(const uint8_t *buf, size_t len, sbp_msg_pos_llh_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->lat);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->lon);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->height);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->h_accuracy);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->v_accuracy);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_pos_llh_cov_t(const sbp_msg_pos_llh_cov_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_double(&msg->lat);
  packed_size += sbp_packed_size_double(&msg->lon);
  packed_size += sbp_packed_size_double(&msg->height);
  packed_size += sbp_packed_size_float(&msg->cov_n_n);
  packed_size += sbp_packed_size_float(&msg->cov_n_e);
  packed_size += sbp_packed_size_float(&msg->cov_n_d);
  packed_size += sbp_packed_size_float(&msg->cov_e_e);
  packed_size += sbp_packed_size_float(&msg->cov_e_d);
  packed_size += sbp_packed_size_float(&msg->cov_d_d);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_pos_llh_cov_t(u8 *buf, size_t len, const sbp_msg_pos_llh_cov_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_pos_llh_cov_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->lat);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->lon);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->height);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_n_n);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_n_e);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_n_d);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_e_e);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_e_d);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_d_d);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_llh_cov_t(const uint8_t *buf, size_t len, sbp_msg_pos_llh_cov_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->lat);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->lon);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->height);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_n_n);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_n_e);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_n_d);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_e_e);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_e_d);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_d_d);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_baseline_ecef_t(const sbp_msg_baseline_ecef_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->x);
  packed_size += sbp_packed_size_s32(&msg->y);
  packed_size += sbp_packed_size_s32(&msg->z);
  packed_size += sbp_packed_size_u16(&msg->accuracy);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_baseline_ecef_t(u8 *buf, size_t len, const sbp_msg_baseline_ecef_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_baseline_ecef_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->x);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->y);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->z);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->accuracy);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_baseline_ecef_t(const uint8_t *buf, size_t len, sbp_msg_baseline_ecef_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->x);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->y);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->z);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->accuracy);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_baseline_ned_t(const sbp_msg_baseline_ned_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->n);
  packed_size += sbp_packed_size_s32(&msg->e);
  packed_size += sbp_packed_size_s32(&msg->d);
  packed_size += sbp_packed_size_u16(&msg->h_accuracy);
  packed_size += sbp_packed_size_u16(&msg->v_accuracy);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_baseline_ned_t(u8 *buf, size_t len, const sbp_msg_baseline_ned_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_baseline_ned_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->n);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->e);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->d);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->h_accuracy);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->v_accuracy);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_baseline_ned_t(const uint8_t *buf, size_t len, sbp_msg_baseline_ned_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->n);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->e);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->d);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->h_accuracy);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->v_accuracy);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_vel_ecef_t(const sbp_msg_vel_ecef_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->x);
  packed_size += sbp_packed_size_s32(&msg->y);
  packed_size += sbp_packed_size_s32(&msg->z);
  packed_size += sbp_packed_size_u16(&msg->accuracy);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_vel_ecef_t(u8 *buf, size_t len, const sbp_msg_vel_ecef_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_vel_ecef_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->x);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->y);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->z);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->accuracy);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ecef_t(const uint8_t *buf, size_t len, sbp_msg_vel_ecef_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->x);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->y);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->z);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->accuracy);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_vel_ecef_cov_t(const sbp_msg_vel_ecef_cov_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->x);
  packed_size += sbp_packed_size_s32(&msg->y);
  packed_size += sbp_packed_size_s32(&msg->z);
  packed_size += sbp_packed_size_float(&msg->cov_x_x);
  packed_size += sbp_packed_size_float(&msg->cov_x_y);
  packed_size += sbp_packed_size_float(&msg->cov_x_z);
  packed_size += sbp_packed_size_float(&msg->cov_y_y);
  packed_size += sbp_packed_size_float(&msg->cov_y_z);
  packed_size += sbp_packed_size_float(&msg->cov_z_z);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_vel_ecef_cov_t(u8 *buf, size_t len, const sbp_msg_vel_ecef_cov_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_vel_ecef_cov_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->x);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->y);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->z);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_x_x);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_x_y);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_x_z);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_y_y);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_y_z);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_z_z);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ecef_cov_t(const uint8_t *buf, size_t len, sbp_msg_vel_ecef_cov_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->x);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->y);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->z);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_x_x);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_x_y);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_x_z);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_y_y);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_y_z);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_z_z);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_vel_ned_t(const sbp_msg_vel_ned_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->n);
  packed_size += sbp_packed_size_s32(&msg->e);
  packed_size += sbp_packed_size_s32(&msg->d);
  packed_size += sbp_packed_size_u16(&msg->h_accuracy);
  packed_size += sbp_packed_size_u16(&msg->v_accuracy);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_vel_ned_t(u8 *buf, size_t len, const sbp_msg_vel_ned_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_vel_ned_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->n);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->e);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->d);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->h_accuracy);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->v_accuracy);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ned_t(const uint8_t *buf, size_t len, sbp_msg_vel_ned_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->n);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->e);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->d);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->h_accuracy);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->v_accuracy);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_vel_ned_cov_t(const sbp_msg_vel_ned_cov_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->n);
  packed_size += sbp_packed_size_s32(&msg->e);
  packed_size += sbp_packed_size_s32(&msg->d);
  packed_size += sbp_packed_size_float(&msg->cov_n_n);
  packed_size += sbp_packed_size_float(&msg->cov_n_e);
  packed_size += sbp_packed_size_float(&msg->cov_n_d);
  packed_size += sbp_packed_size_float(&msg->cov_e_e);
  packed_size += sbp_packed_size_float(&msg->cov_e_d);
  packed_size += sbp_packed_size_float(&msg->cov_d_d);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_vel_ned_cov_t(u8 *buf, size_t len, const sbp_msg_vel_ned_cov_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_vel_ned_cov_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->n);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->e);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->d);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_n_n);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_n_e);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_n_d);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_e_e);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_e_d);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_d_d);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ned_cov_t(const uint8_t *buf, size_t len, sbp_msg_vel_ned_cov_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->n);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->e);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->d);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_n_n);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_n_e);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_n_d);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_e_e);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_e_d);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_d_d);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_pos_ecef_gnss_t(const sbp_msg_pos_ecef_gnss_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_double(&msg->x);
  packed_size += sbp_packed_size_double(&msg->y);
  packed_size += sbp_packed_size_double(&msg->z);
  packed_size += sbp_packed_size_u16(&msg->accuracy);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_pos_ecef_gnss_t(u8 *buf, size_t len, const sbp_msg_pos_ecef_gnss_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_pos_ecef_gnss_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->x);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->y);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->z);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->accuracy);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_ecef_gnss_t(const uint8_t *buf, size_t len, sbp_msg_pos_ecef_gnss_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->x);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->y);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->z);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->accuracy);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_pos_ecef_cov_gnss_t(const sbp_msg_pos_ecef_cov_gnss_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_double(&msg->x);
  packed_size += sbp_packed_size_double(&msg->y);
  packed_size += sbp_packed_size_double(&msg->z);
  packed_size += sbp_packed_size_float(&msg->cov_x_x);
  packed_size += sbp_packed_size_float(&msg->cov_x_y);
  packed_size += sbp_packed_size_float(&msg->cov_x_z);
  packed_size += sbp_packed_size_float(&msg->cov_y_y);
  packed_size += sbp_packed_size_float(&msg->cov_y_z);
  packed_size += sbp_packed_size_float(&msg->cov_z_z);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_pos_ecef_cov_gnss_t(u8 *buf, size_t len, const sbp_msg_pos_ecef_cov_gnss_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_pos_ecef_cov_gnss_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->x);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->y);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->z);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_x_x);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_x_y);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_x_z);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_y_y);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_y_z);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_z_z);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_ecef_cov_gnss_t(const uint8_t *buf, size_t len, sbp_msg_pos_ecef_cov_gnss_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->x);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->y);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->z);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_x_x);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_x_y);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_x_z);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_y_y);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_y_z);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_z_z);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_pos_llh_gnss_t(const sbp_msg_pos_llh_gnss_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_double(&msg->lat);
  packed_size += sbp_packed_size_double(&msg->lon);
  packed_size += sbp_packed_size_double(&msg->height);
  packed_size += sbp_packed_size_u16(&msg->h_accuracy);
  packed_size += sbp_packed_size_u16(&msg->v_accuracy);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_pos_llh_gnss_t(u8 *buf, size_t len, const sbp_msg_pos_llh_gnss_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_pos_llh_gnss_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->lat);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->lon);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->height);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->h_accuracy);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->v_accuracy);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_llh_gnss_t(const uint8_t *buf, size_t len, sbp_msg_pos_llh_gnss_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->lat);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->lon);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->height);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->h_accuracy);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->v_accuracy);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_pos_llh_cov_gnss_t(const sbp_msg_pos_llh_cov_gnss_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_double(&msg->lat);
  packed_size += sbp_packed_size_double(&msg->lon);
  packed_size += sbp_packed_size_double(&msg->height);
  packed_size += sbp_packed_size_float(&msg->cov_n_n);
  packed_size += sbp_packed_size_float(&msg->cov_n_e);
  packed_size += sbp_packed_size_float(&msg->cov_n_d);
  packed_size += sbp_packed_size_float(&msg->cov_e_e);
  packed_size += sbp_packed_size_float(&msg->cov_e_d);
  packed_size += sbp_packed_size_float(&msg->cov_d_d);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_pos_llh_cov_gnss_t(u8 *buf, size_t len, const sbp_msg_pos_llh_cov_gnss_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_pos_llh_cov_gnss_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->lat);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->lon);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->height);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_n_n);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_n_e);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_n_d);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_e_e);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_e_d);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_d_d);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_llh_cov_gnss_t(const uint8_t *buf, size_t len, sbp_msg_pos_llh_cov_gnss_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->lat);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->lon);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->height);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_n_n);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_n_e);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_n_d);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_e_e);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_e_d);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_d_d);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_vel_ecef_gnss_t(const sbp_msg_vel_ecef_gnss_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->x);
  packed_size += sbp_packed_size_s32(&msg->y);
  packed_size += sbp_packed_size_s32(&msg->z);
  packed_size += sbp_packed_size_u16(&msg->accuracy);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_vel_ecef_gnss_t(u8 *buf, size_t len, const sbp_msg_vel_ecef_gnss_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_vel_ecef_gnss_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->x);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->y);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->z);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->accuracy);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ecef_gnss_t(const uint8_t *buf, size_t len, sbp_msg_vel_ecef_gnss_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->x);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->y);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->z);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->accuracy);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_vel_ecef_cov_gnss_t(const sbp_msg_vel_ecef_cov_gnss_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->x);
  packed_size += sbp_packed_size_s32(&msg->y);
  packed_size += sbp_packed_size_s32(&msg->z);
  packed_size += sbp_packed_size_float(&msg->cov_x_x);
  packed_size += sbp_packed_size_float(&msg->cov_x_y);
  packed_size += sbp_packed_size_float(&msg->cov_x_z);
  packed_size += sbp_packed_size_float(&msg->cov_y_y);
  packed_size += sbp_packed_size_float(&msg->cov_y_z);
  packed_size += sbp_packed_size_float(&msg->cov_z_z);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_vel_ecef_cov_gnss_t(u8 *buf, size_t len, const sbp_msg_vel_ecef_cov_gnss_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_vel_ecef_cov_gnss_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->x);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->y);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->z);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_x_x);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_x_y);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_x_z);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_y_y);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_y_z);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_z_z);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ecef_cov_gnss_t(const uint8_t *buf, size_t len, sbp_msg_vel_ecef_cov_gnss_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->x);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->y);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->z);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_x_x);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_x_y);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_x_z);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_y_y);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_y_z);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_z_z);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_vel_ned_gnss_t(const sbp_msg_vel_ned_gnss_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->n);
  packed_size += sbp_packed_size_s32(&msg->e);
  packed_size += sbp_packed_size_s32(&msg->d);
  packed_size += sbp_packed_size_u16(&msg->h_accuracy);
  packed_size += sbp_packed_size_u16(&msg->v_accuracy);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_vel_ned_gnss_t(u8 *buf, size_t len, const sbp_msg_vel_ned_gnss_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_vel_ned_gnss_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->n);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->e);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->d);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->h_accuracy);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->v_accuracy);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ned_gnss_t(const uint8_t *buf, size_t len, sbp_msg_vel_ned_gnss_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->n);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->e);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->d);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->h_accuracy);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->v_accuracy);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_vel_ned_cov_gnss_t(const sbp_msg_vel_ned_cov_gnss_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->n);
  packed_size += sbp_packed_size_s32(&msg->e);
  packed_size += sbp_packed_size_s32(&msg->d);
  packed_size += sbp_packed_size_float(&msg->cov_n_n);
  packed_size += sbp_packed_size_float(&msg->cov_n_e);
  packed_size += sbp_packed_size_float(&msg->cov_n_d);
  packed_size += sbp_packed_size_float(&msg->cov_e_e);
  packed_size += sbp_packed_size_float(&msg->cov_e_d);
  packed_size += sbp_packed_size_float(&msg->cov_d_d);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_vel_ned_cov_gnss_t(u8 *buf, size_t len, const sbp_msg_vel_ned_cov_gnss_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_vel_ned_cov_gnss_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->n);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->e);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->d);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_n_n);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_n_e);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_n_d);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_e_e);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_e_d);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_d_d);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ned_cov_gnss_t(const uint8_t *buf, size_t len, sbp_msg_vel_ned_cov_gnss_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->n);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->e);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->d);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_n_n);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_n_e);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_n_d);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_e_e);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_e_d);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_d_d);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_vel_body_t(const sbp_msg_vel_body_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->x);
  packed_size += sbp_packed_size_s32(&msg->y);
  packed_size += sbp_packed_size_s32(&msg->z);
  packed_size += sbp_packed_size_float(&msg->cov_x_x);
  packed_size += sbp_packed_size_float(&msg->cov_x_y);
  packed_size += sbp_packed_size_float(&msg->cov_x_z);
  packed_size += sbp_packed_size_float(&msg->cov_y_y);
  packed_size += sbp_packed_size_float(&msg->cov_y_z);
  packed_size += sbp_packed_size_float(&msg->cov_z_z);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_vel_body_t(u8 *buf, size_t len, const sbp_msg_vel_body_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_vel_body_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->x);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->y);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->z);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_x_x);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_x_y);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_x_z);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_y_y);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_y_z);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cov_z_z);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_body_t(const uint8_t *buf, size_t len, sbp_msg_vel_body_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->x);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->y);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->z);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_x_x);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_x_y);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_x_z);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_y_y);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_y_z);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cov_z_z);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_age_corrections_t(const sbp_msg_age_corrections_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u16(&msg->age);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_age_corrections_t(u8 *buf, size_t len, const sbp_msg_age_corrections_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_age_corrections_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->age);
  return true;
}

static inline bool sbp_unpack_sbp_msg_age_corrections_t(const uint8_t *buf, size_t len, sbp_msg_age_corrections_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->age);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_gps_time_dep_a_t(const sbp_msg_gps_time_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u16(&msg->wn);
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->ns_residual);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_gps_time_dep_a_t(u8 *buf, size_t len, const sbp_msg_gps_time_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_gps_time_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->wn);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->ns_residual);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_gps_time_dep_a_t(const uint8_t *buf, size_t len, sbp_msg_gps_time_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->wn);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->ns_residual);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_dops_dep_a_t(const sbp_msg_dops_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u16(&msg->gdop);
  packed_size += sbp_packed_size_u16(&msg->pdop);
  packed_size += sbp_packed_size_u16(&msg->tdop);
  packed_size += sbp_packed_size_u16(&msg->hdop);
  packed_size += sbp_packed_size_u16(&msg->vdop);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_dops_dep_a_t(u8 *buf, size_t len, const sbp_msg_dops_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_dops_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->gdop);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->pdop);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->tdop);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->hdop);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->vdop);
  return true;
}

static inline bool sbp_unpack_sbp_msg_dops_dep_a_t(const uint8_t *buf, size_t len, sbp_msg_dops_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->gdop);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->pdop);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->tdop);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->hdop);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->vdop);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_pos_ecef_dep_a_t(const sbp_msg_pos_ecef_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_double(&msg->x);
  packed_size += sbp_packed_size_double(&msg->y);
  packed_size += sbp_packed_size_double(&msg->z);
  packed_size += sbp_packed_size_u16(&msg->accuracy);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_pos_ecef_dep_a_t(u8 *buf, size_t len, const sbp_msg_pos_ecef_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_pos_ecef_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->x);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->y);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->z);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->accuracy);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_ecef_dep_a_t(const uint8_t *buf, size_t len, sbp_msg_pos_ecef_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->x);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->y);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->z);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->accuracy);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_pos_llh_dep_a_t(const sbp_msg_pos_llh_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_double(&msg->lat);
  packed_size += sbp_packed_size_double(&msg->lon);
  packed_size += sbp_packed_size_double(&msg->height);
  packed_size += sbp_packed_size_u16(&msg->h_accuracy);
  packed_size += sbp_packed_size_u16(&msg->v_accuracy);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_pos_llh_dep_a_t(u8 *buf, size_t len, const sbp_msg_pos_llh_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_pos_llh_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->lat);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->lon);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->height);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->h_accuracy);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->v_accuracy);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_llh_dep_a_t(const uint8_t *buf, size_t len, sbp_msg_pos_llh_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->lat);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->lon);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->height);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->h_accuracy);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->v_accuracy);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_baseline_ecef_dep_a_t(const sbp_msg_baseline_ecef_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->x);
  packed_size += sbp_packed_size_s32(&msg->y);
  packed_size += sbp_packed_size_s32(&msg->z);
  packed_size += sbp_packed_size_u16(&msg->accuracy);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_baseline_ecef_dep_a_t(u8 *buf, size_t len, const sbp_msg_baseline_ecef_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_baseline_ecef_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->x);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->y);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->z);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->accuracy);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_baseline_ecef_dep_a_t(const uint8_t *buf, size_t len, sbp_msg_baseline_ecef_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->x);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->y);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->z);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->accuracy);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_baseline_ned_dep_a_t(const sbp_msg_baseline_ned_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->n);
  packed_size += sbp_packed_size_s32(&msg->e);
  packed_size += sbp_packed_size_s32(&msg->d);
  packed_size += sbp_packed_size_u16(&msg->h_accuracy);
  packed_size += sbp_packed_size_u16(&msg->v_accuracy);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_baseline_ned_dep_a_t(u8 *buf, size_t len, const sbp_msg_baseline_ned_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_baseline_ned_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->n);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->e);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->d);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->h_accuracy);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->v_accuracy);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_baseline_ned_dep_a_t(const uint8_t *buf, size_t len, sbp_msg_baseline_ned_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->n);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->e);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->d);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->h_accuracy);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->v_accuracy);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_vel_ecef_dep_a_t(const sbp_msg_vel_ecef_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->x);
  packed_size += sbp_packed_size_s32(&msg->y);
  packed_size += sbp_packed_size_s32(&msg->z);
  packed_size += sbp_packed_size_u16(&msg->accuracy);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_vel_ecef_dep_a_t(u8 *buf, size_t len, const sbp_msg_vel_ecef_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_vel_ecef_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->x);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->y);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->z);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->accuracy);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ecef_dep_a_t(const uint8_t *buf, size_t len, sbp_msg_vel_ecef_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->x);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->y);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->z);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->accuracy);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_vel_ned_dep_a_t(const sbp_msg_vel_ned_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->n);
  packed_size += sbp_packed_size_s32(&msg->e);
  packed_size += sbp_packed_size_s32(&msg->d);
  packed_size += sbp_packed_size_u16(&msg->h_accuracy);
  packed_size += sbp_packed_size_u16(&msg->v_accuracy);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_vel_ned_dep_a_t(u8 *buf, size_t len, const sbp_msg_vel_ned_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_vel_ned_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->n);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->e);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->d);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->h_accuracy);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->v_accuracy);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ned_dep_a_t(const uint8_t *buf, size_t len, sbp_msg_vel_ned_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->n);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->e);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->d);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->h_accuracy);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->v_accuracy);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_baseline_heading_dep_a_t(const sbp_msg_baseline_heading_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u32(&msg->heading);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_baseline_heading_dep_a_t(u8 *buf, size_t len, const sbp_msg_baseline_heading_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_baseline_heading_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->heading);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->n_sats);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_baseline_heading_dep_a_t(const uint8_t *buf, size_t len, sbp_msg_baseline_heading_dep_a_t *msg) {
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
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_protection_level_dep_a_t(const sbp_msg_protection_level_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u16(&msg->vpl);
  packed_size += sbp_packed_size_u16(&msg->hpl);
  packed_size += sbp_packed_size_double(&msg->lat);
  packed_size += sbp_packed_size_double(&msg->lon);
  packed_size += sbp_packed_size_double(&msg->height);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_protection_level_dep_a_t(u8 *buf, size_t len, const sbp_msg_protection_level_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_protection_level_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->vpl);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->hpl);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->lat);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->lon);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->height);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_protection_level_dep_a_t(const uint8_t *buf, size_t len, sbp_msg_protection_level_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->vpl);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->hpl);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->lat);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->lon);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->height);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_protection_level_t(const sbp_msg_protection_level_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s16(&msg->wn);
  packed_size += sbp_packed_size_u16(&msg->hpl);
  packed_size += sbp_packed_size_u16(&msg->vpl);
  packed_size += sbp_packed_size_u16(&msg->atpl);
  packed_size += sbp_packed_size_u16(&msg->ctpl);
  packed_size += sbp_packed_size_u16(&msg->hvpl);
  packed_size += sbp_packed_size_u16(&msg->vvpl);
  packed_size += sbp_packed_size_u16(&msg->hopl);
  packed_size += sbp_packed_size_u16(&msg->popl);
  packed_size += sbp_packed_size_u16(&msg->ropl);
  packed_size += sbp_packed_size_double(&msg->lat);
  packed_size += sbp_packed_size_double(&msg->lon);
  packed_size += sbp_packed_size_double(&msg->height);
  packed_size += sbp_packed_size_s32(&msg->v_x);
  packed_size += sbp_packed_size_s32(&msg->v_y);
  packed_size += sbp_packed_size_s32(&msg->v_z);
  packed_size += sbp_packed_size_s32(&msg->roll);
  packed_size += sbp_packed_size_s32(&msg->pitch);
  packed_size += sbp_packed_size_s32(&msg->heading);
  packed_size += sbp_packed_size_u32(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_protection_level_t(u8 *buf, size_t len, const sbp_msg_protection_level_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_protection_level_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->wn);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->hpl);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->vpl);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->atpl);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->ctpl);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->hvpl);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->vvpl);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->hopl);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->popl);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->ropl);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->lat);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->lon);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->height);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->v_x);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->v_y);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->v_z);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->roll);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->pitch);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->heading);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_protection_level_t(const uint8_t *buf, size_t len, sbp_msg_protection_level_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->wn);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->hpl);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->vpl);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->atpl);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->ctpl);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->hvpl);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->vvpl);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->hopl);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->popl);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->ropl);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->lat);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->lon);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->height);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->v_x);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->v_y);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->v_z);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->roll);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->pitch);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->heading);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->flags);
  return true;
}

#endif
