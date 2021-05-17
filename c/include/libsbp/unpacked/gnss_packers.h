#ifndef LIBSBP_GNSS_PACKERS_H
#define LIBSBP_GNSS_PACKERS_H

#ifndef LIBSBP_GNSS_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/gnss.h instead"
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
                                                                                                              
static inline size_t sbp_packed_size_sbp_sbp_gnss_signal_t(const sbp_sbp_gnss_signal_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->sat);
  packed_size += sbp_packed_size_u8(&msg->code);
  return packed_size;
}

static inline size_t sbp_pack_sbp_sbp_gnss_signal_t(u8 *buf, size_t len, const sbp_sbp_gnss_signal_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_sbp_gnss_signal_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->sat);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->code);
  return offset;
}

static inline size_t sbp_unpack_sbp_sbp_gnss_signal_t(const uint8_t *buf, size_t len, sbp_sbp_gnss_signal_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->sat);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->code);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_sv_id_t(const sbp_sv_id_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->satId);
  packed_size += sbp_packed_size_u8(&msg->constellation);
  return packed_size;
}

static inline size_t sbp_pack_sbp_sv_id_t(u8 *buf, size_t len, const sbp_sv_id_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_sv_id_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->satId);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->constellation);
  return offset;
}

static inline size_t sbp_unpack_sbp_sv_id_t(const uint8_t *buf, size_t len, sbp_sv_id_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->satId);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->constellation);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_gnss_signal_dep_t(const sbp_gnss_signal_dep_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u16(&msg->sat);
  packed_size += sbp_packed_size_u8(&msg->code);
  packed_size += sbp_packed_size_u8(&msg->reserved);
  return packed_size;
}

static inline size_t sbp_pack_sbp_gnss_signal_dep_t(u8 *buf, size_t len, const sbp_gnss_signal_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_gnss_signal_dep_t(msg) > len) { return false; }
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->sat);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->code);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->reserved);
  return offset;
}

static inline size_t sbp_unpack_sbp_gnss_signal_dep_t(const uint8_t *buf, size_t len, sbp_gnss_signal_dep_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->sat);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->code);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->reserved);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_gps_time_dep_t(const sbp_gps_time_dep_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u16(&msg->wn);
  return packed_size;
}

static inline size_t sbp_pack_sbp_gps_time_dep_t(u8 *buf, size_t len, const sbp_gps_time_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_gps_time_dep_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->wn);
  return offset;
}

static inline size_t sbp_unpack_sbp_gps_time_dep_t(const uint8_t *buf, size_t len, sbp_gps_time_dep_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->wn);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_gps_time_sec_t(const sbp_gps_time_sec_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u16(&msg->wn);
  return packed_size;
}

static inline size_t sbp_pack_sbp_gps_time_sec_t(u8 *buf, size_t len, const sbp_gps_time_sec_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_gps_time_sec_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->wn);
  return offset;
}

static inline size_t sbp_unpack_sbp_gps_time_sec_t(const uint8_t *buf, size_t len, sbp_gps_time_sec_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->wn);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_sbp_gps_time_t(const sbp_sbp_gps_time_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->ns_residual);
  packed_size += sbp_packed_size_u16(&msg->wn);
  return packed_size;
}

static inline size_t sbp_pack_sbp_sbp_gps_time_t(u8 *buf, size_t len, const sbp_sbp_gps_time_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_sbp_gps_time_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->ns_residual);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->wn);
  return offset;
}

static inline size_t sbp_unpack_sbp_sbp_gps_time_t(const uint8_t *buf, size_t len, sbp_sbp_gps_time_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tow);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->ns_residual);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->wn);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_carrier_phase_t(const sbp_carrier_phase_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_s32(&msg->i);
  packed_size += sbp_packed_size_u8(&msg->f);
  return packed_size;
}

static inline size_t sbp_pack_sbp_carrier_phase_t(u8 *buf, size_t len, const sbp_carrier_phase_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_carrier_phase_t(msg) > len) { return false; }
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->i);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->f);
  return offset;
}

static inline size_t sbp_unpack_sbp_carrier_phase_t(const uint8_t *buf, size_t len, sbp_carrier_phase_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->i);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->f);
  return offset;
}

#endif
