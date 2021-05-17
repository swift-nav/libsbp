#ifndef LIBSBP_ACQUISITION_PACKERS_H
#define LIBSBP_ACQUISITION_PACKERS_H

#ifndef LIBSBP_ACQUISITION_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/acquisition.h instead"
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
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_acq_result_t(const sbp_msg_acq_result_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_float(&msg->cn0);
  packed_size += sbp_packed_size_float(&msg->cp);
  packed_size += sbp_packed_size_float(&msg->cf);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_acq_result_t(u8 *buf, size_t len, const sbp_msg_acq_result_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_acq_result_t(msg) > len) { return false; }
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cn0);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cp);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cf);
  offset += sbp_pack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  return true;
}

static inline bool sbp_unpack_sbp_msg_acq_result_t(const uint8_t *buf, size_t len, sbp_msg_acq_result_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cn0);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cp);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cf);
  offset += sbp_unpack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_acq_result_dep_c_t(const sbp_msg_acq_result_dep_c_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_float(&msg->cn0);
  packed_size += sbp_packed_size_float(&msg->cp);
  packed_size += sbp_packed_size_float(&msg->cf);
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_acq_result_dep_c_t(u8 *buf, size_t len, const sbp_msg_acq_result_dep_c_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_acq_result_dep_c_t(msg) > len) { return false; }
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cn0);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cp);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cf);
  offset += sbp_pack_sbp_gnss_signal_dep_t(buf + offset, len - offset, &msg->sid);
  return true;
}

static inline bool sbp_unpack_sbp_msg_acq_result_dep_c_t(const uint8_t *buf, size_t len, sbp_msg_acq_result_dep_c_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cn0);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cp);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cf);
  offset += sbp_unpack_sbp_gnss_signal_dep_t(buf + offset, len - offset, &msg->sid);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_acq_result_dep_b_t(const sbp_msg_acq_result_dep_b_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_float(&msg->snr);
  packed_size += sbp_packed_size_float(&msg->cp);
  packed_size += sbp_packed_size_float(&msg->cf);
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_acq_result_dep_b_t(u8 *buf, size_t len, const sbp_msg_acq_result_dep_b_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_acq_result_dep_b_t(msg) > len) { return false; }
  offset += sbp_pack_float(buf + offset, len - offset, &msg->snr);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cp);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cf);
  offset += sbp_pack_sbp_gnss_signal_dep_t(buf + offset, len - offset, &msg->sid);
  return true;
}

static inline bool sbp_unpack_sbp_msg_acq_result_dep_b_t(const uint8_t *buf, size_t len, sbp_msg_acq_result_dep_b_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->snr);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cp);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cf);
  offset += sbp_unpack_sbp_gnss_signal_dep_t(buf + offset, len - offset, &msg->sid);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_acq_result_dep_a_t(const sbp_msg_acq_result_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_float(&msg->snr);
  packed_size += sbp_packed_size_float(&msg->cp);
  packed_size += sbp_packed_size_float(&msg->cf);
  packed_size += sbp_packed_size_u8(&msg->prn);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_acq_result_dep_a_t(u8 *buf, size_t len, const sbp_msg_acq_result_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_acq_result_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_float(buf + offset, len - offset, &msg->snr);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cp);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cf);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->prn);
  return true;
}

static inline bool sbp_unpack_sbp_msg_acq_result_dep_a_t(const uint8_t *buf, size_t len, sbp_msg_acq_result_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->snr);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cp);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cf);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->prn);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_acq_sv_profile_t(const sbp_acq_sv_profile_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->job_type);
  packed_size += sbp_packed_size_u8(&msg->status);
  packed_size += sbp_packed_size_u16(&msg->cn0);
  packed_size += sbp_packed_size_u8(&msg->int_time);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_u16(&msg->bin_width);
  packed_size += sbp_packed_size_u32(&msg->timestamp);
  packed_size += sbp_packed_size_u32(&msg->time_spent);
  packed_size += sbp_packed_size_s32(&msg->cf_min);
  packed_size += sbp_packed_size_s32(&msg->cf_max);
  packed_size += sbp_packed_size_s32(&msg->cf);
  packed_size += sbp_packed_size_u32(&msg->cp);
  return packed_size;
}

static inline size_t sbp_pack_sbp_acq_sv_profile_t(u8 *buf, size_t len, const sbp_acq_sv_profile_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_acq_sv_profile_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->job_type);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->status);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->cn0);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->int_time);
  offset += sbp_pack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->bin_width);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->timestamp);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->time_spent);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->cf_min);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->cf_max);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->cf);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->cp);
  return offset;
}

static inline size_t sbp_unpack_sbp_acq_sv_profile_t(const uint8_t *buf, size_t len, sbp_acq_sv_profile_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->job_type);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->status);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->cn0);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->int_time);
  offset += sbp_unpack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->bin_width);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->timestamp);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->time_spent);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->cf_min);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->cf_max);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->cf);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->cp);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_acq_sv_profile_dep_t(const sbp_acq_sv_profile_dep_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->job_type);
  packed_size += sbp_packed_size_u8(&msg->status);
  packed_size += sbp_packed_size_u16(&msg->cn0);
  packed_size += sbp_packed_size_u8(&msg->int_time);
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  packed_size += sbp_packed_size_u16(&msg->bin_width);
  packed_size += sbp_packed_size_u32(&msg->timestamp);
  packed_size += sbp_packed_size_u32(&msg->time_spent);
  packed_size += sbp_packed_size_s32(&msg->cf_min);
  packed_size += sbp_packed_size_s32(&msg->cf_max);
  packed_size += sbp_packed_size_s32(&msg->cf);
  packed_size += sbp_packed_size_u32(&msg->cp);
  return packed_size;
}

static inline size_t sbp_pack_sbp_acq_sv_profile_dep_t(u8 *buf, size_t len, const sbp_acq_sv_profile_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_acq_sv_profile_dep_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->job_type);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->status);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->cn0);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->int_time);
  offset += sbp_pack_sbp_gnss_signal_dep_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->bin_width);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->timestamp);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->time_spent);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->cf_min);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->cf_max);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->cf);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->cp);
  return offset;
}

static inline size_t sbp_unpack_sbp_acq_sv_profile_dep_t(const uint8_t *buf, size_t len, sbp_acq_sv_profile_dep_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->job_type);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->status);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->cn0);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->int_time);
  offset += sbp_unpack_sbp_gnss_signal_dep_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->bin_width);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->timestamp);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->time_spent);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->cf_min);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->cf_max);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->cf);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->cp);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_acq_sv_profile_t(const sbp_msg_acq_sv_profile_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += (msg->n_acq_sv_profile * sbp_packed_size_sbp_acq_sv_profile_t(&msg->acq_sv_profile[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_acq_sv_profile_t(u8 *buf, size_t len, const sbp_msg_acq_sv_profile_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_acq_sv_profile_t(msg) > len) { return false; }
  for (uint8_t i = 0; i < msg->n_acq_sv_profile; i++) 
  {
    offset += sbp_pack_sbp_acq_sv_profile_t(buf + offset, len - offset, &msg->acq_sv_profile[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_acq_sv_profile_t(const uint8_t *buf, size_t len, sbp_msg_acq_sv_profile_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  msg->n_acq_sv_profile = (uint8_t)((len - offset) / sbp_packed_size_sbp_acq_sv_profile_t(&msg->acq_sv_profile[0]));
  for (uint8_t i = 0; i < msg->n_acq_sv_profile; i++)
  {
    offset += sbp_unpack_sbp_acq_sv_profile_t(buf + offset, len - offset, &msg->acq_sv_profile[i]);
  }
  return true;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_acq_sv_profile_dep_t(const sbp_msg_acq_sv_profile_dep_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += (msg->n_acq_sv_profile * sbp_packed_size_sbp_acq_sv_profile_dep_t(&msg->acq_sv_profile[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_acq_sv_profile_dep_t(u8 *buf, size_t len, const sbp_msg_acq_sv_profile_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_acq_sv_profile_dep_t(msg) > len) { return false; }
  for (uint8_t i = 0; i < msg->n_acq_sv_profile; i++) 
  {
    offset += sbp_pack_sbp_acq_sv_profile_dep_t(buf + offset, len - offset, &msg->acq_sv_profile[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_acq_sv_profile_dep_t(const uint8_t *buf, size_t len, sbp_msg_acq_sv_profile_dep_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  msg->n_acq_sv_profile = (uint8_t)((len - offset) / sbp_packed_size_sbp_acq_sv_profile_dep_t(&msg->acq_sv_profile[0]));
  for (uint8_t i = 0; i < msg->n_acq_sv_profile; i++)
  {
    offset += sbp_unpack_sbp_acq_sv_profile_dep_t(buf + offset, len - offset, &msg->acq_sv_profile[i]);
  }
  return true;
  return true;
}

#endif
