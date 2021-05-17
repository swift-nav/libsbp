#ifndef LIBSBP_OBSERVATION_PACKERS_H
#define LIBSBP_OBSERVATION_PACKERS_H

#ifndef LIBSBP_OBSERVATION_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/observation.h instead"
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
                                                                                                              
static inline size_t sbp_packed_size_sbp_observation_header_t(const sbp_observation_header_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_sbp_gps_time_t(&msg->t);
  packed_size += sbp_packed_size_u8(&msg->n_obs);
  return packed_size;
}

static inline size_t sbp_pack_sbp_observation_header_t(u8 *buf, size_t len, const sbp_observation_header_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_observation_header_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_sbp_gps_time_t(buf + offset, len - offset, &msg->t);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->n_obs);
  return offset;
}

static inline size_t sbp_unpack_sbp_observation_header_t(const uint8_t *buf, size_t len, sbp_observation_header_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_sbp_gps_time_t(buf + offset, len - offset, &msg->t);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->n_obs);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_doppler_t(const sbp_doppler_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_s16(&msg->i);
  packed_size += sbp_packed_size_u8(&msg->f);
  return packed_size;
}

static inline size_t sbp_pack_sbp_doppler_t(u8 *buf, size_t len, const sbp_doppler_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_doppler_t(msg) > len) { return false; }
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->i);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->f);
  return offset;
}

static inline size_t sbp_unpack_sbp_doppler_t(const uint8_t *buf, size_t len, sbp_doppler_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->i);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->f);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_packed_obs_content_t(const sbp_packed_obs_content_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->P);
  packed_size += sbp_packed_size_sbp_carrier_phase_t(&msg->L);
  packed_size += sbp_packed_size_sbp_doppler_t(&msg->D);
  packed_size += sbp_packed_size_u8(&msg->cn0);
  packed_size += sbp_packed_size_u8(&msg->lock);
  packed_size += sbp_packed_size_u8(&msg->flags);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  return packed_size;
}

static inline size_t sbp_pack_sbp_packed_obs_content_t(u8 *buf, size_t len, const sbp_packed_obs_content_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_packed_obs_content_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->P);
  offset += sbp_pack_sbp_carrier_phase_t(buf + offset, len - offset, &msg->L);
  offset += sbp_pack_sbp_doppler_t(buf + offset, len - offset, &msg->D);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->cn0);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->lock);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  offset += sbp_pack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  return offset;
}

static inline size_t sbp_unpack_sbp_packed_obs_content_t(const uint8_t *buf, size_t len, sbp_packed_obs_content_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->P);
  offset += sbp_unpack_sbp_carrier_phase_t(buf + offset, len - offset, &msg->L);
  offset += sbp_unpack_sbp_doppler_t(buf + offset, len - offset, &msg->D);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->cn0);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->lock);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  offset += sbp_unpack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_packed_osr_content_t(const sbp_packed_osr_content_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->P);
  packed_size += sbp_packed_size_sbp_carrier_phase_t(&msg->L);
  packed_size += sbp_packed_size_u8(&msg->lock);
  packed_size += sbp_packed_size_u8(&msg->flags);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_u16(&msg->iono_std);
  packed_size += sbp_packed_size_u16(&msg->tropo_std);
  packed_size += sbp_packed_size_u16(&msg->range_std);
  return packed_size;
}

static inline size_t sbp_pack_sbp_packed_osr_content_t(u8 *buf, size_t len, const sbp_packed_osr_content_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_packed_osr_content_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->P);
  offset += sbp_pack_sbp_carrier_phase_t(buf + offset, len - offset, &msg->L);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->lock);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->flags);
  offset += sbp_pack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->iono_std);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->tropo_std);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->range_std);
  return offset;
}

static inline size_t sbp_unpack_sbp_packed_osr_content_t(const uint8_t *buf, size_t len, sbp_packed_osr_content_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->P);
  offset += sbp_unpack_sbp_carrier_phase_t(buf + offset, len - offset, &msg->L);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->lock);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->flags);
  offset += sbp_unpack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->iono_std);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->tropo_std);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->range_std);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_obs_t(const sbp_msg_obs_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_observation_header_t(&msg->header);
  packed_size += (msg->n_obs * sbp_packed_size_sbp_packed_obs_content_t(&msg->obs[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_obs_t(u8 *buf, size_t len, const sbp_msg_obs_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_obs_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_observation_header_t(buf + offset, len - offset, &msg->header);
  for (uint8_t i = 0; i < msg->n_obs; i++) 
  {
    offset += sbp_pack_sbp_packed_obs_content_t(buf + offset, len - offset, &msg->obs[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_obs_t(const uint8_t *buf, size_t len, sbp_msg_obs_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_observation_header_t(buf + offset, len - offset, &msg->header);
  msg->n_obs = (uint8_t)((len - offset) / sbp_packed_size_sbp_packed_obs_content_t(&msg->obs[0]));
  for (uint8_t i = 0; i < msg->n_obs; i++)
  {
    offset += sbp_unpack_sbp_packed_obs_content_t(buf + offset, len - offset, &msg->obs[i]);
  }
  return true;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_base_pos_llh_t(const sbp_msg_base_pos_llh_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_double(&msg->lat);
  packed_size += sbp_packed_size_double(&msg->lon);
  packed_size += sbp_packed_size_double(&msg->height);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_base_pos_llh_t(u8 *buf, size_t len, const sbp_msg_base_pos_llh_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_base_pos_llh_t(msg) > len) { return false; }
  offset += sbp_pack_double(buf + offset, len - offset, &msg->lat);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->lon);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->height);
  return true;
}

static inline bool sbp_unpack_sbp_msg_base_pos_llh_t(const uint8_t *buf, size_t len, sbp_msg_base_pos_llh_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->lat);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->lon);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->height);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_base_pos_ecef_t(const sbp_msg_base_pos_ecef_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_double(&msg->x);
  packed_size += sbp_packed_size_double(&msg->y);
  packed_size += sbp_packed_size_double(&msg->z);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_base_pos_ecef_t(u8 *buf, size_t len, const sbp_msg_base_pos_ecef_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_base_pos_ecef_t(msg) > len) { return false; }
  offset += sbp_pack_double(buf + offset, len - offset, &msg->x);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->y);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->z);
  return true;
}

static inline bool sbp_unpack_sbp_msg_base_pos_ecef_t(const uint8_t *buf, size_t len, sbp_msg_base_pos_ecef_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->x);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->y);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->z);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_ephemeris_common_content_t(const sbp_ephemeris_common_content_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->toe);
  packed_size += sbp_packed_size_float(&msg->ura);
  packed_size += sbp_packed_size_u32(&msg->fit_interval);
  packed_size += sbp_packed_size_u8(&msg->valid);
  packed_size += sbp_packed_size_u8(&msg->health_bits);
  return packed_size;
}

static inline size_t sbp_pack_sbp_ephemeris_common_content_t(u8 *buf, size_t len, const sbp_ephemeris_common_content_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_ephemeris_common_content_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_pack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->toe);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->ura);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->fit_interval);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->valid);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->health_bits);
  return offset;
}

static inline size_t sbp_unpack_sbp_ephemeris_common_content_t(const uint8_t *buf, size_t len, sbp_ephemeris_common_content_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_unpack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->toe);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->ura);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->fit_interval);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->valid);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->health_bits);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_ephemeris_common_content_dep_b_t(const sbp_ephemeris_common_content_dep_b_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->toe);
  packed_size += sbp_packed_size_double(&msg->ura);
  packed_size += sbp_packed_size_u32(&msg->fit_interval);
  packed_size += sbp_packed_size_u8(&msg->valid);
  packed_size += sbp_packed_size_u8(&msg->health_bits);
  return packed_size;
}

static inline size_t sbp_pack_sbp_ephemeris_common_content_dep_b_t(u8 *buf, size_t len, const sbp_ephemeris_common_content_dep_b_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_ephemeris_common_content_dep_b_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_pack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->toe);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->ura);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->fit_interval);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->valid);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->health_bits);
  return offset;
}

static inline size_t sbp_unpack_sbp_ephemeris_common_content_dep_b_t(const uint8_t *buf, size_t len, sbp_ephemeris_common_content_dep_b_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_unpack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->toe);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->ura);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->fit_interval);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->valid);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->health_bits);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_ephemeris_common_content_dep_a_t(const sbp_ephemeris_common_content_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  packed_size += sbp_packed_size_sbp_gps_time_dep_t(&msg->toe);
  packed_size += sbp_packed_size_double(&msg->ura);
  packed_size += sbp_packed_size_u32(&msg->fit_interval);
  packed_size += sbp_packed_size_u8(&msg->valid);
  packed_size += sbp_packed_size_u8(&msg->health_bits);
  return packed_size;
}

static inline size_t sbp_pack_sbp_ephemeris_common_content_dep_a_t(u8 *buf, size_t len, const sbp_ephemeris_common_content_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_ephemeris_common_content_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_gnss_signal_dep_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_pack_sbp_gps_time_dep_t(buf + offset, len - offset, &msg->toe);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->ura);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->fit_interval);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->valid);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->health_bits);
  return offset;
}

static inline size_t sbp_unpack_sbp_ephemeris_common_content_dep_a_t(const uint8_t *buf, size_t len, sbp_ephemeris_common_content_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_gnss_signal_dep_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_unpack_sbp_gps_time_dep_t(buf + offset, len - offset, &msg->toe);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->ura);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->fit_interval);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->valid);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->health_bits);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_gps_dep_e_t(const sbp_msg_ephemeris_gps_dep_e_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_ephemeris_common_content_dep_a_t(&msg->common);
  packed_size += sbp_packed_size_double(&msg->tgd);
  packed_size += sbp_packed_size_double(&msg->c_rs);
  packed_size += sbp_packed_size_double(&msg->c_rc);
  packed_size += sbp_packed_size_double(&msg->c_uc);
  packed_size += sbp_packed_size_double(&msg->c_us);
  packed_size += sbp_packed_size_double(&msg->c_ic);
  packed_size += sbp_packed_size_double(&msg->c_is);
  packed_size += sbp_packed_size_double(&msg->dn);
  packed_size += sbp_packed_size_double(&msg->m0);
  packed_size += sbp_packed_size_double(&msg->ecc);
  packed_size += sbp_packed_size_double(&msg->sqrta);
  packed_size += sbp_packed_size_double(&msg->omega0);
  packed_size += sbp_packed_size_double(&msg->omegadot);
  packed_size += sbp_packed_size_double(&msg->w);
  packed_size += sbp_packed_size_double(&msg->inc);
  packed_size += sbp_packed_size_double(&msg->inc_dot);
  packed_size += sbp_packed_size_double(&msg->af0);
  packed_size += sbp_packed_size_double(&msg->af1);
  packed_size += sbp_packed_size_double(&msg->af2);
  packed_size += sbp_packed_size_sbp_gps_time_dep_t(&msg->toc);
  packed_size += sbp_packed_size_u8(&msg->iode);
  packed_size += sbp_packed_size_u16(&msg->iodc);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ephemeris_gps_dep_e_t(u8 *buf, size_t len, const sbp_msg_ephemeris_gps_dep_e_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_gps_dep_e_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_ephemeris_common_content_dep_a_t(buf + offset, len - offset, &msg->common);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->tgd);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_rs);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_rc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_uc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_us);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_ic);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_is);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->dn);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->m0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->ecc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->sqrta);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->omega0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->omegadot);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->w);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->inc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->inc_dot);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->af0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->af1);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->af2);
  offset += sbp_pack_sbp_gps_time_dep_t(buf + offset, len - offset, &msg->toc);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->iode);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->iodc);
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_gps_dep_e_t(const uint8_t *buf, size_t len, sbp_msg_ephemeris_gps_dep_e_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_ephemeris_common_content_dep_a_t(buf + offset, len - offset, &msg->common);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->tgd);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_rs);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_rc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_uc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_us);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_ic);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_is);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->dn);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->m0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->ecc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->sqrta);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->omega0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->omegadot);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->w);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->inc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->inc_dot);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->af0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->af1);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->af2);
  offset += sbp_unpack_sbp_gps_time_dep_t(buf + offset, len - offset, &msg->toc);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->iode);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->iodc);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_gps_dep_f_t(const sbp_msg_ephemeris_gps_dep_f_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_ephemeris_common_content_dep_b_t(&msg->common);
  packed_size += sbp_packed_size_double(&msg->tgd);
  packed_size += sbp_packed_size_double(&msg->c_rs);
  packed_size += sbp_packed_size_double(&msg->c_rc);
  packed_size += sbp_packed_size_double(&msg->c_uc);
  packed_size += sbp_packed_size_double(&msg->c_us);
  packed_size += sbp_packed_size_double(&msg->c_ic);
  packed_size += sbp_packed_size_double(&msg->c_is);
  packed_size += sbp_packed_size_double(&msg->dn);
  packed_size += sbp_packed_size_double(&msg->m0);
  packed_size += sbp_packed_size_double(&msg->ecc);
  packed_size += sbp_packed_size_double(&msg->sqrta);
  packed_size += sbp_packed_size_double(&msg->omega0);
  packed_size += sbp_packed_size_double(&msg->omegadot);
  packed_size += sbp_packed_size_double(&msg->w);
  packed_size += sbp_packed_size_double(&msg->inc);
  packed_size += sbp_packed_size_double(&msg->inc_dot);
  packed_size += sbp_packed_size_double(&msg->af0);
  packed_size += sbp_packed_size_double(&msg->af1);
  packed_size += sbp_packed_size_double(&msg->af2);
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->toc);
  packed_size += sbp_packed_size_u8(&msg->iode);
  packed_size += sbp_packed_size_u16(&msg->iodc);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ephemeris_gps_dep_f_t(u8 *buf, size_t len, const sbp_msg_ephemeris_gps_dep_f_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_gps_dep_f_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_ephemeris_common_content_dep_b_t(buf + offset, len - offset, &msg->common);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->tgd);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_rs);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_rc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_uc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_us);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_ic);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_is);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->dn);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->m0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->ecc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->sqrta);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->omega0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->omegadot);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->w);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->inc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->inc_dot);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->af0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->af1);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->af2);
  offset += sbp_pack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->toc);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->iode);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->iodc);
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_gps_dep_f_t(const uint8_t *buf, size_t len, sbp_msg_ephemeris_gps_dep_f_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_ephemeris_common_content_dep_b_t(buf + offset, len - offset, &msg->common);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->tgd);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_rs);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_rc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_uc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_us);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_ic);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_is);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->dn);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->m0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->ecc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->sqrta);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->omega0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->omegadot);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->w);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->inc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->inc_dot);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->af0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->af1);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->af2);
  offset += sbp_unpack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->toc);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->iode);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->iodc);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_gps_t(const sbp_msg_ephemeris_gps_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_ephemeris_common_content_t(&msg->common);
  packed_size += sbp_packed_size_float(&msg->tgd);
  packed_size += sbp_packed_size_float(&msg->c_rs);
  packed_size += sbp_packed_size_float(&msg->c_rc);
  packed_size += sbp_packed_size_float(&msg->c_uc);
  packed_size += sbp_packed_size_float(&msg->c_us);
  packed_size += sbp_packed_size_float(&msg->c_ic);
  packed_size += sbp_packed_size_float(&msg->c_is);
  packed_size += sbp_packed_size_double(&msg->dn);
  packed_size += sbp_packed_size_double(&msg->m0);
  packed_size += sbp_packed_size_double(&msg->ecc);
  packed_size += sbp_packed_size_double(&msg->sqrta);
  packed_size += sbp_packed_size_double(&msg->omega0);
  packed_size += sbp_packed_size_double(&msg->omegadot);
  packed_size += sbp_packed_size_double(&msg->w);
  packed_size += sbp_packed_size_double(&msg->inc);
  packed_size += sbp_packed_size_double(&msg->inc_dot);
  packed_size += sbp_packed_size_float(&msg->af0);
  packed_size += sbp_packed_size_float(&msg->af1);
  packed_size += sbp_packed_size_float(&msg->af2);
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->toc);
  packed_size += sbp_packed_size_u8(&msg->iode);
  packed_size += sbp_packed_size_u16(&msg->iodc);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ephemeris_gps_t(u8 *buf, size_t len, const sbp_msg_ephemeris_gps_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_gps_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_ephemeris_common_content_t(buf + offset, len - offset, &msg->common);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->tgd);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->c_rs);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->c_rc);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->c_uc);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->c_us);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->c_ic);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->c_is);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->dn);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->m0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->ecc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->sqrta);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->omega0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->omegadot);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->w);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->inc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->inc_dot);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->af0);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->af1);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->af2);
  offset += sbp_pack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->toc);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->iode);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->iodc);
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_gps_t(const uint8_t *buf, size_t len, sbp_msg_ephemeris_gps_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_ephemeris_common_content_t(buf + offset, len - offset, &msg->common);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->tgd);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->c_rs);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->c_rc);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->c_uc);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->c_us);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->c_ic);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->c_is);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->dn);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->m0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->ecc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->sqrta);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->omega0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->omegadot);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->w);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->inc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->inc_dot);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->af0);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->af1);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->af2);
  offset += sbp_unpack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->toc);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->iode);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->iodc);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_qzss_t(const sbp_msg_ephemeris_qzss_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_ephemeris_common_content_t(&msg->common);
  packed_size += sbp_packed_size_float(&msg->tgd);
  packed_size += sbp_packed_size_float(&msg->c_rs);
  packed_size += sbp_packed_size_float(&msg->c_rc);
  packed_size += sbp_packed_size_float(&msg->c_uc);
  packed_size += sbp_packed_size_float(&msg->c_us);
  packed_size += sbp_packed_size_float(&msg->c_ic);
  packed_size += sbp_packed_size_float(&msg->c_is);
  packed_size += sbp_packed_size_double(&msg->dn);
  packed_size += sbp_packed_size_double(&msg->m0);
  packed_size += sbp_packed_size_double(&msg->ecc);
  packed_size += sbp_packed_size_double(&msg->sqrta);
  packed_size += sbp_packed_size_double(&msg->omega0);
  packed_size += sbp_packed_size_double(&msg->omegadot);
  packed_size += sbp_packed_size_double(&msg->w);
  packed_size += sbp_packed_size_double(&msg->inc);
  packed_size += sbp_packed_size_double(&msg->inc_dot);
  packed_size += sbp_packed_size_float(&msg->af0);
  packed_size += sbp_packed_size_float(&msg->af1);
  packed_size += sbp_packed_size_float(&msg->af2);
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->toc);
  packed_size += sbp_packed_size_u8(&msg->iode);
  packed_size += sbp_packed_size_u16(&msg->iodc);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ephemeris_qzss_t(u8 *buf, size_t len, const sbp_msg_ephemeris_qzss_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_qzss_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_ephemeris_common_content_t(buf + offset, len - offset, &msg->common);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->tgd);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->c_rs);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->c_rc);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->c_uc);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->c_us);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->c_ic);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->c_is);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->dn);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->m0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->ecc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->sqrta);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->omega0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->omegadot);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->w);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->inc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->inc_dot);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->af0);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->af1);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->af2);
  offset += sbp_pack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->toc);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->iode);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->iodc);
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_qzss_t(const uint8_t *buf, size_t len, sbp_msg_ephemeris_qzss_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_ephemeris_common_content_t(buf + offset, len - offset, &msg->common);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->tgd);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->c_rs);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->c_rc);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->c_uc);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->c_us);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->c_ic);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->c_is);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->dn);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->m0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->ecc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->sqrta);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->omega0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->omegadot);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->w);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->inc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->inc_dot);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->af0);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->af1);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->af2);
  offset += sbp_unpack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->toc);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->iode);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->iodc);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_bds_t(const sbp_msg_ephemeris_bds_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_ephemeris_common_content_t(&msg->common);
  packed_size += sbp_packed_size_float(&msg->tgd1);
  packed_size += sbp_packed_size_float(&msg->tgd2);
  packed_size += sbp_packed_size_float(&msg->c_rs);
  packed_size += sbp_packed_size_float(&msg->c_rc);
  packed_size += sbp_packed_size_float(&msg->c_uc);
  packed_size += sbp_packed_size_float(&msg->c_us);
  packed_size += sbp_packed_size_float(&msg->c_ic);
  packed_size += sbp_packed_size_float(&msg->c_is);
  packed_size += sbp_packed_size_double(&msg->dn);
  packed_size += sbp_packed_size_double(&msg->m0);
  packed_size += sbp_packed_size_double(&msg->ecc);
  packed_size += sbp_packed_size_double(&msg->sqrta);
  packed_size += sbp_packed_size_double(&msg->omega0);
  packed_size += sbp_packed_size_double(&msg->omegadot);
  packed_size += sbp_packed_size_double(&msg->w);
  packed_size += sbp_packed_size_double(&msg->inc);
  packed_size += sbp_packed_size_double(&msg->inc_dot);
  packed_size += sbp_packed_size_double(&msg->af0);
  packed_size += sbp_packed_size_float(&msg->af1);
  packed_size += sbp_packed_size_float(&msg->af2);
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->toc);
  packed_size += sbp_packed_size_u8(&msg->iode);
  packed_size += sbp_packed_size_u16(&msg->iodc);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ephemeris_bds_t(u8 *buf, size_t len, const sbp_msg_ephemeris_bds_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_bds_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_ephemeris_common_content_t(buf + offset, len - offset, &msg->common);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->tgd1);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->tgd2);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->c_rs);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->c_rc);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->c_uc);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->c_us);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->c_ic);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->c_is);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->dn);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->m0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->ecc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->sqrta);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->omega0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->omegadot);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->w);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->inc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->inc_dot);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->af0);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->af1);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->af2);
  offset += sbp_pack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->toc);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->iode);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->iodc);
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_bds_t(const uint8_t *buf, size_t len, sbp_msg_ephemeris_bds_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_ephemeris_common_content_t(buf + offset, len - offset, &msg->common);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->tgd1);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->tgd2);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->c_rs);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->c_rc);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->c_uc);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->c_us);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->c_ic);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->c_is);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->dn);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->m0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->ecc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->sqrta);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->omega0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->omegadot);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->w);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->inc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->inc_dot);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->af0);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->af1);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->af2);
  offset += sbp_unpack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->toc);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->iode);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->iodc);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_gal_dep_a_t(const sbp_msg_ephemeris_gal_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_ephemeris_common_content_t(&msg->common);
  packed_size += sbp_packed_size_float(&msg->bgd_e1e5a);
  packed_size += sbp_packed_size_float(&msg->bgd_e1e5b);
  packed_size += sbp_packed_size_float(&msg->c_rs);
  packed_size += sbp_packed_size_float(&msg->c_rc);
  packed_size += sbp_packed_size_float(&msg->c_uc);
  packed_size += sbp_packed_size_float(&msg->c_us);
  packed_size += sbp_packed_size_float(&msg->c_ic);
  packed_size += sbp_packed_size_float(&msg->c_is);
  packed_size += sbp_packed_size_double(&msg->dn);
  packed_size += sbp_packed_size_double(&msg->m0);
  packed_size += sbp_packed_size_double(&msg->ecc);
  packed_size += sbp_packed_size_double(&msg->sqrta);
  packed_size += sbp_packed_size_double(&msg->omega0);
  packed_size += sbp_packed_size_double(&msg->omegadot);
  packed_size += sbp_packed_size_double(&msg->w);
  packed_size += sbp_packed_size_double(&msg->inc);
  packed_size += sbp_packed_size_double(&msg->inc_dot);
  packed_size += sbp_packed_size_double(&msg->af0);
  packed_size += sbp_packed_size_double(&msg->af1);
  packed_size += sbp_packed_size_float(&msg->af2);
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->toc);
  packed_size += sbp_packed_size_u16(&msg->iode);
  packed_size += sbp_packed_size_u16(&msg->iodc);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ephemeris_gal_dep_a_t(u8 *buf, size_t len, const sbp_msg_ephemeris_gal_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_gal_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_ephemeris_common_content_t(buf + offset, len - offset, &msg->common);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->bgd_e1e5a);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->bgd_e1e5b);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->c_rs);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->c_rc);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->c_uc);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->c_us);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->c_ic);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->c_is);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->dn);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->m0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->ecc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->sqrta);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->omega0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->omegadot);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->w);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->inc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->inc_dot);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->af0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->af1);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->af2);
  offset += sbp_pack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->toc);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->iode);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->iodc);
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_gal_dep_a_t(const uint8_t *buf, size_t len, sbp_msg_ephemeris_gal_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_ephemeris_common_content_t(buf + offset, len - offset, &msg->common);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->bgd_e1e5a);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->bgd_e1e5b);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->c_rs);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->c_rc);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->c_uc);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->c_us);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->c_ic);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->c_is);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->dn);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->m0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->ecc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->sqrta);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->omega0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->omegadot);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->w);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->inc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->inc_dot);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->af0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->af1);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->af2);
  offset += sbp_unpack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->toc);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->iode);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->iodc);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_gal_t(const sbp_msg_ephemeris_gal_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_ephemeris_common_content_t(&msg->common);
  packed_size += sbp_packed_size_float(&msg->bgd_e1e5a);
  packed_size += sbp_packed_size_float(&msg->bgd_e1e5b);
  packed_size += sbp_packed_size_float(&msg->c_rs);
  packed_size += sbp_packed_size_float(&msg->c_rc);
  packed_size += sbp_packed_size_float(&msg->c_uc);
  packed_size += sbp_packed_size_float(&msg->c_us);
  packed_size += sbp_packed_size_float(&msg->c_ic);
  packed_size += sbp_packed_size_float(&msg->c_is);
  packed_size += sbp_packed_size_double(&msg->dn);
  packed_size += sbp_packed_size_double(&msg->m0);
  packed_size += sbp_packed_size_double(&msg->ecc);
  packed_size += sbp_packed_size_double(&msg->sqrta);
  packed_size += sbp_packed_size_double(&msg->omega0);
  packed_size += sbp_packed_size_double(&msg->omegadot);
  packed_size += sbp_packed_size_double(&msg->w);
  packed_size += sbp_packed_size_double(&msg->inc);
  packed_size += sbp_packed_size_double(&msg->inc_dot);
  packed_size += sbp_packed_size_double(&msg->af0);
  packed_size += sbp_packed_size_double(&msg->af1);
  packed_size += sbp_packed_size_float(&msg->af2);
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->toc);
  packed_size += sbp_packed_size_u16(&msg->iode);
  packed_size += sbp_packed_size_u16(&msg->iodc);
  packed_size += sbp_packed_size_u8(&msg->source);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ephemeris_gal_t(u8 *buf, size_t len, const sbp_msg_ephemeris_gal_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_gal_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_ephemeris_common_content_t(buf + offset, len - offset, &msg->common);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->bgd_e1e5a);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->bgd_e1e5b);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->c_rs);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->c_rc);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->c_uc);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->c_us);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->c_ic);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->c_is);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->dn);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->m0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->ecc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->sqrta);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->omega0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->omegadot);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->w);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->inc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->inc_dot);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->af0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->af1);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->af2);
  offset += sbp_pack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->toc);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->iode);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->iodc);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->source);
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_gal_t(const uint8_t *buf, size_t len, sbp_msg_ephemeris_gal_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_ephemeris_common_content_t(buf + offset, len - offset, &msg->common);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->bgd_e1e5a);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->bgd_e1e5b);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->c_rs);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->c_rc);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->c_uc);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->c_us);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->c_ic);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->c_is);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->dn);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->m0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->ecc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->sqrta);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->omega0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->omegadot);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->w);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->inc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->inc_dot);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->af0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->af1);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->af2);
  offset += sbp_unpack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->toc);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->iode);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->iodc);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->source);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_sbas_dep_a_t(const sbp_msg_ephemeris_sbas_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_ephemeris_common_content_dep_a_t(&msg->common);
  packed_size += ( 3 * sbp_packed_size_double(&msg->pos[0]));
  packed_size += ( 3 * sbp_packed_size_double(&msg->vel[0]));
  packed_size += ( 3 * sbp_packed_size_double(&msg->acc[0]));
  packed_size += sbp_packed_size_double(&msg->a_gf0);
  packed_size += sbp_packed_size_double(&msg->a_gf1);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ephemeris_sbas_dep_a_t(u8 *buf, size_t len, const sbp_msg_ephemeris_sbas_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_sbas_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_ephemeris_common_content_dep_a_t(buf + offset, len - offset, &msg->common);
  for (uint8_t i = 0; i < 3; i++) 
  {
    offset += sbp_pack_double(buf + offset, len - offset, &msg->pos[i]);
  }
  for (uint8_t i = 0; i < 3; i++) 
  {
    offset += sbp_pack_double(buf + offset, len - offset, &msg->vel[i]);
  }
  for (uint8_t i = 0; i < 3; i++) 
  {
    offset += sbp_pack_double(buf + offset, len - offset, &msg->acc[i]);
  }
  offset += sbp_pack_double(buf + offset, len - offset, &msg->a_gf0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->a_gf1);
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_sbas_dep_a_t(const uint8_t *buf, size_t len, sbp_msg_ephemeris_sbas_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_ephemeris_common_content_dep_a_t(buf + offset, len - offset, &msg->common);
  for (uint8_t i = 0; i < 3; i++)
  {
    offset += sbp_unpack_double(buf + offset, len - offset, &msg->pos[i]);
  }
  for (uint8_t i = 0; i < 3; i++)
  {
    offset += sbp_unpack_double(buf + offset, len - offset, &msg->vel[i]);
  }
  for (uint8_t i = 0; i < 3; i++)
  {
    offset += sbp_unpack_double(buf + offset, len - offset, &msg->acc[i]);
  }
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->a_gf0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->a_gf1);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_glo_dep_a_t(const sbp_msg_ephemeris_glo_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_ephemeris_common_content_dep_a_t(&msg->common);
  packed_size += sbp_packed_size_double(&msg->gamma);
  packed_size += sbp_packed_size_double(&msg->tau);
  packed_size += ( 3 * sbp_packed_size_double(&msg->pos[0]));
  packed_size += ( 3 * sbp_packed_size_double(&msg->vel[0]));
  packed_size += ( 3 * sbp_packed_size_double(&msg->acc[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ephemeris_glo_dep_a_t(u8 *buf, size_t len, const sbp_msg_ephemeris_glo_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_glo_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_ephemeris_common_content_dep_a_t(buf + offset, len - offset, &msg->common);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->gamma);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->tau);
  for (uint8_t i = 0; i < 3; i++) 
  {
    offset += sbp_pack_double(buf + offset, len - offset, &msg->pos[i]);
  }
  for (uint8_t i = 0; i < 3; i++) 
  {
    offset += sbp_pack_double(buf + offset, len - offset, &msg->vel[i]);
  }
  for (uint8_t i = 0; i < 3; i++) 
  {
    offset += sbp_pack_double(buf + offset, len - offset, &msg->acc[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_glo_dep_a_t(const uint8_t *buf, size_t len, sbp_msg_ephemeris_glo_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_ephemeris_common_content_dep_a_t(buf + offset, len - offset, &msg->common);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->gamma);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->tau);
  for (uint8_t i = 0; i < 3; i++)
  {
    offset += sbp_unpack_double(buf + offset, len - offset, &msg->pos[i]);
  }
  for (uint8_t i = 0; i < 3; i++)
  {
    offset += sbp_unpack_double(buf + offset, len - offset, &msg->vel[i]);
  }
  for (uint8_t i = 0; i < 3; i++)
  {
    offset += sbp_unpack_double(buf + offset, len - offset, &msg->acc[i]);
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_sbas_dep_b_t(const sbp_msg_ephemeris_sbas_dep_b_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_ephemeris_common_content_dep_b_t(&msg->common);
  packed_size += ( 3 * sbp_packed_size_double(&msg->pos[0]));
  packed_size += ( 3 * sbp_packed_size_double(&msg->vel[0]));
  packed_size += ( 3 * sbp_packed_size_double(&msg->acc[0]));
  packed_size += sbp_packed_size_double(&msg->a_gf0);
  packed_size += sbp_packed_size_double(&msg->a_gf1);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ephemeris_sbas_dep_b_t(u8 *buf, size_t len, const sbp_msg_ephemeris_sbas_dep_b_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_sbas_dep_b_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_ephemeris_common_content_dep_b_t(buf + offset, len - offset, &msg->common);
  for (uint8_t i = 0; i < 3; i++) 
  {
    offset += sbp_pack_double(buf + offset, len - offset, &msg->pos[i]);
  }
  for (uint8_t i = 0; i < 3; i++) 
  {
    offset += sbp_pack_double(buf + offset, len - offset, &msg->vel[i]);
  }
  for (uint8_t i = 0; i < 3; i++) 
  {
    offset += sbp_pack_double(buf + offset, len - offset, &msg->acc[i]);
  }
  offset += sbp_pack_double(buf + offset, len - offset, &msg->a_gf0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->a_gf1);
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_sbas_dep_b_t(const uint8_t *buf, size_t len, sbp_msg_ephemeris_sbas_dep_b_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_ephemeris_common_content_dep_b_t(buf + offset, len - offset, &msg->common);
  for (uint8_t i = 0; i < 3; i++)
  {
    offset += sbp_unpack_double(buf + offset, len - offset, &msg->pos[i]);
  }
  for (uint8_t i = 0; i < 3; i++)
  {
    offset += sbp_unpack_double(buf + offset, len - offset, &msg->vel[i]);
  }
  for (uint8_t i = 0; i < 3; i++)
  {
    offset += sbp_unpack_double(buf + offset, len - offset, &msg->acc[i]);
  }
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->a_gf0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->a_gf1);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_sbas_t(const sbp_msg_ephemeris_sbas_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_ephemeris_common_content_t(&msg->common);
  packed_size += ( 3 * sbp_packed_size_double(&msg->pos[0]));
  packed_size += ( 3 * sbp_packed_size_float(&msg->vel[0]));
  packed_size += ( 3 * sbp_packed_size_float(&msg->acc[0]));
  packed_size += sbp_packed_size_float(&msg->a_gf0);
  packed_size += sbp_packed_size_float(&msg->a_gf1);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ephemeris_sbas_t(u8 *buf, size_t len, const sbp_msg_ephemeris_sbas_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_sbas_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_ephemeris_common_content_t(buf + offset, len - offset, &msg->common);
  for (uint8_t i = 0; i < 3; i++) 
  {
    offset += sbp_pack_double(buf + offset, len - offset, &msg->pos[i]);
  }
  for (uint8_t i = 0; i < 3; i++) 
  {
    offset += sbp_pack_float(buf + offset, len - offset, &msg->vel[i]);
  }
  for (uint8_t i = 0; i < 3; i++) 
  {
    offset += sbp_pack_float(buf + offset, len - offset, &msg->acc[i]);
  }
  offset += sbp_pack_float(buf + offset, len - offset, &msg->a_gf0);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->a_gf1);
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_sbas_t(const uint8_t *buf, size_t len, sbp_msg_ephemeris_sbas_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_ephemeris_common_content_t(buf + offset, len - offset, &msg->common);
  for (uint8_t i = 0; i < 3; i++)
  {
    offset += sbp_unpack_double(buf + offset, len - offset, &msg->pos[i]);
  }
  for (uint8_t i = 0; i < 3; i++)
  {
    offset += sbp_unpack_float(buf + offset, len - offset, &msg->vel[i]);
  }
  for (uint8_t i = 0; i < 3; i++)
  {
    offset += sbp_unpack_float(buf + offset, len - offset, &msg->acc[i]);
  }
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->a_gf0);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->a_gf1);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_glo_dep_b_t(const sbp_msg_ephemeris_glo_dep_b_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_ephemeris_common_content_dep_b_t(&msg->common);
  packed_size += sbp_packed_size_double(&msg->gamma);
  packed_size += sbp_packed_size_double(&msg->tau);
  packed_size += ( 3 * sbp_packed_size_double(&msg->pos[0]));
  packed_size += ( 3 * sbp_packed_size_double(&msg->vel[0]));
  packed_size += ( 3 * sbp_packed_size_double(&msg->acc[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ephemeris_glo_dep_b_t(u8 *buf, size_t len, const sbp_msg_ephemeris_glo_dep_b_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_glo_dep_b_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_ephemeris_common_content_dep_b_t(buf + offset, len - offset, &msg->common);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->gamma);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->tau);
  for (uint8_t i = 0; i < 3; i++) 
  {
    offset += sbp_pack_double(buf + offset, len - offset, &msg->pos[i]);
  }
  for (uint8_t i = 0; i < 3; i++) 
  {
    offset += sbp_pack_double(buf + offset, len - offset, &msg->vel[i]);
  }
  for (uint8_t i = 0; i < 3; i++) 
  {
    offset += sbp_pack_double(buf + offset, len - offset, &msg->acc[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_glo_dep_b_t(const uint8_t *buf, size_t len, sbp_msg_ephemeris_glo_dep_b_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_ephemeris_common_content_dep_b_t(buf + offset, len - offset, &msg->common);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->gamma);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->tau);
  for (uint8_t i = 0; i < 3; i++)
  {
    offset += sbp_unpack_double(buf + offset, len - offset, &msg->pos[i]);
  }
  for (uint8_t i = 0; i < 3; i++)
  {
    offset += sbp_unpack_double(buf + offset, len - offset, &msg->vel[i]);
  }
  for (uint8_t i = 0; i < 3; i++)
  {
    offset += sbp_unpack_double(buf + offset, len - offset, &msg->acc[i]);
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_glo_dep_c_t(const sbp_msg_ephemeris_glo_dep_c_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_ephemeris_common_content_dep_b_t(&msg->common);
  packed_size += sbp_packed_size_double(&msg->gamma);
  packed_size += sbp_packed_size_double(&msg->tau);
  packed_size += sbp_packed_size_double(&msg->d_tau);
  packed_size += ( 3 * sbp_packed_size_double(&msg->pos[0]));
  packed_size += ( 3 * sbp_packed_size_double(&msg->vel[0]));
  packed_size += ( 3 * sbp_packed_size_double(&msg->acc[0]));
  packed_size += sbp_packed_size_u8(&msg->fcn);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ephemeris_glo_dep_c_t(u8 *buf, size_t len, const sbp_msg_ephemeris_glo_dep_c_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_glo_dep_c_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_ephemeris_common_content_dep_b_t(buf + offset, len - offset, &msg->common);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->gamma);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->tau);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->d_tau);
  for (uint8_t i = 0; i < 3; i++) 
  {
    offset += sbp_pack_double(buf + offset, len - offset, &msg->pos[i]);
  }
  for (uint8_t i = 0; i < 3; i++) 
  {
    offset += sbp_pack_double(buf + offset, len - offset, &msg->vel[i]);
  }
  for (uint8_t i = 0; i < 3; i++) 
  {
    offset += sbp_pack_double(buf + offset, len - offset, &msg->acc[i]);
  }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->fcn);
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_glo_dep_c_t(const uint8_t *buf, size_t len, sbp_msg_ephemeris_glo_dep_c_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_ephemeris_common_content_dep_b_t(buf + offset, len - offset, &msg->common);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->gamma);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->tau);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->d_tau);
  for (uint8_t i = 0; i < 3; i++)
  {
    offset += sbp_unpack_double(buf + offset, len - offset, &msg->pos[i]);
  }
  for (uint8_t i = 0; i < 3; i++)
  {
    offset += sbp_unpack_double(buf + offset, len - offset, &msg->vel[i]);
  }
  for (uint8_t i = 0; i < 3; i++)
  {
    offset += sbp_unpack_double(buf + offset, len - offset, &msg->acc[i]);
  }
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->fcn);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_glo_dep_d_t(const sbp_msg_ephemeris_glo_dep_d_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_ephemeris_common_content_dep_b_t(&msg->common);
  packed_size += sbp_packed_size_double(&msg->gamma);
  packed_size += sbp_packed_size_double(&msg->tau);
  packed_size += sbp_packed_size_double(&msg->d_tau);
  packed_size += ( 3 * sbp_packed_size_double(&msg->pos[0]));
  packed_size += ( 3 * sbp_packed_size_double(&msg->vel[0]));
  packed_size += ( 3 * sbp_packed_size_double(&msg->acc[0]));
  packed_size += sbp_packed_size_u8(&msg->fcn);
  packed_size += sbp_packed_size_u8(&msg->iod);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ephemeris_glo_dep_d_t(u8 *buf, size_t len, const sbp_msg_ephemeris_glo_dep_d_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_glo_dep_d_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_ephemeris_common_content_dep_b_t(buf + offset, len - offset, &msg->common);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->gamma);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->tau);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->d_tau);
  for (uint8_t i = 0; i < 3; i++) 
  {
    offset += sbp_pack_double(buf + offset, len - offset, &msg->pos[i]);
  }
  for (uint8_t i = 0; i < 3; i++) 
  {
    offset += sbp_pack_double(buf + offset, len - offset, &msg->vel[i]);
  }
  for (uint8_t i = 0; i < 3; i++) 
  {
    offset += sbp_pack_double(buf + offset, len - offset, &msg->acc[i]);
  }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->fcn);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->iod);
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_glo_dep_d_t(const uint8_t *buf, size_t len, sbp_msg_ephemeris_glo_dep_d_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_ephemeris_common_content_dep_b_t(buf + offset, len - offset, &msg->common);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->gamma);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->tau);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->d_tau);
  for (uint8_t i = 0; i < 3; i++)
  {
    offset += sbp_unpack_double(buf + offset, len - offset, &msg->pos[i]);
  }
  for (uint8_t i = 0; i < 3; i++)
  {
    offset += sbp_unpack_double(buf + offset, len - offset, &msg->vel[i]);
  }
  for (uint8_t i = 0; i < 3; i++)
  {
    offset += sbp_unpack_double(buf + offset, len - offset, &msg->acc[i]);
  }
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->fcn);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->iod);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_glo_t(const sbp_msg_ephemeris_glo_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_ephemeris_common_content_t(&msg->common);
  packed_size += sbp_packed_size_float(&msg->gamma);
  packed_size += sbp_packed_size_float(&msg->tau);
  packed_size += sbp_packed_size_float(&msg->d_tau);
  packed_size += ( 3 * sbp_packed_size_double(&msg->pos[0]));
  packed_size += ( 3 * sbp_packed_size_double(&msg->vel[0]));
  packed_size += ( 3 * sbp_packed_size_float(&msg->acc[0]));
  packed_size += sbp_packed_size_u8(&msg->fcn);
  packed_size += sbp_packed_size_u8(&msg->iod);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ephemeris_glo_t(u8 *buf, size_t len, const sbp_msg_ephemeris_glo_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_glo_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_ephemeris_common_content_t(buf + offset, len - offset, &msg->common);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->gamma);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->tau);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->d_tau);
  for (uint8_t i = 0; i < 3; i++) 
  {
    offset += sbp_pack_double(buf + offset, len - offset, &msg->pos[i]);
  }
  for (uint8_t i = 0; i < 3; i++) 
  {
    offset += sbp_pack_double(buf + offset, len - offset, &msg->vel[i]);
  }
  for (uint8_t i = 0; i < 3; i++) 
  {
    offset += sbp_pack_float(buf + offset, len - offset, &msg->acc[i]);
  }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->fcn);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->iod);
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_glo_t(const uint8_t *buf, size_t len, sbp_msg_ephemeris_glo_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_ephemeris_common_content_t(buf + offset, len - offset, &msg->common);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->gamma);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->tau);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->d_tau);
  for (uint8_t i = 0; i < 3; i++)
  {
    offset += sbp_unpack_double(buf + offset, len - offset, &msg->pos[i]);
  }
  for (uint8_t i = 0; i < 3; i++)
  {
    offset += sbp_unpack_double(buf + offset, len - offset, &msg->vel[i]);
  }
  for (uint8_t i = 0; i < 3; i++)
  {
    offset += sbp_unpack_float(buf + offset, len - offset, &msg->acc[i]);
  }
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->fcn);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->iod);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_dep_d_t(const sbp_msg_ephemeris_dep_d_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_double(&msg->tgd);
  packed_size += sbp_packed_size_double(&msg->c_rs);
  packed_size += sbp_packed_size_double(&msg->c_rc);
  packed_size += sbp_packed_size_double(&msg->c_uc);
  packed_size += sbp_packed_size_double(&msg->c_us);
  packed_size += sbp_packed_size_double(&msg->c_ic);
  packed_size += sbp_packed_size_double(&msg->c_is);
  packed_size += sbp_packed_size_double(&msg->dn);
  packed_size += sbp_packed_size_double(&msg->m0);
  packed_size += sbp_packed_size_double(&msg->ecc);
  packed_size += sbp_packed_size_double(&msg->sqrta);
  packed_size += sbp_packed_size_double(&msg->omega0);
  packed_size += sbp_packed_size_double(&msg->omegadot);
  packed_size += sbp_packed_size_double(&msg->w);
  packed_size += sbp_packed_size_double(&msg->inc);
  packed_size += sbp_packed_size_double(&msg->inc_dot);
  packed_size += sbp_packed_size_double(&msg->af0);
  packed_size += sbp_packed_size_double(&msg->af1);
  packed_size += sbp_packed_size_double(&msg->af2);
  packed_size += sbp_packed_size_double(&msg->toe_tow);
  packed_size += sbp_packed_size_u16(&msg->toe_wn);
  packed_size += sbp_packed_size_double(&msg->toc_tow);
  packed_size += sbp_packed_size_u16(&msg->toc_wn);
  packed_size += sbp_packed_size_u8(&msg->valid);
  packed_size += sbp_packed_size_u8(&msg->healthy);
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  packed_size += sbp_packed_size_u8(&msg->iode);
  packed_size += sbp_packed_size_u16(&msg->iodc);
  packed_size += sbp_packed_size_u32(&msg->reserved);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ephemeris_dep_d_t(u8 *buf, size_t len, const sbp_msg_ephemeris_dep_d_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_dep_d_t(msg) > len) { return false; }
  offset += sbp_pack_double(buf + offset, len - offset, &msg->tgd);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_rs);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_rc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_uc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_us);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_ic);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_is);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->dn);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->m0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->ecc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->sqrta);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->omega0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->omegadot);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->w);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->inc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->inc_dot);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->af0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->af1);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->af2);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->toe_tow);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->toe_wn);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->toc_tow);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->toc_wn);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->valid);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->healthy);
  offset += sbp_pack_sbp_gnss_signal_dep_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->iode);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->iodc);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->reserved);
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_dep_d_t(const uint8_t *buf, size_t len, sbp_msg_ephemeris_dep_d_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->tgd);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_rs);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_rc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_uc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_us);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_ic);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_is);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->dn);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->m0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->ecc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->sqrta);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->omega0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->omegadot);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->w);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->inc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->inc_dot);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->af0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->af1);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->af2);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->toe_tow);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->toe_wn);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->toc_tow);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->toc_wn);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->valid);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->healthy);
  offset += sbp_unpack_sbp_gnss_signal_dep_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->iode);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->iodc);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->reserved);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_dep_a_t(const sbp_msg_ephemeris_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_double(&msg->tgd);
  packed_size += sbp_packed_size_double(&msg->c_rs);
  packed_size += sbp_packed_size_double(&msg->c_rc);
  packed_size += sbp_packed_size_double(&msg->c_uc);
  packed_size += sbp_packed_size_double(&msg->c_us);
  packed_size += sbp_packed_size_double(&msg->c_ic);
  packed_size += sbp_packed_size_double(&msg->c_is);
  packed_size += sbp_packed_size_double(&msg->dn);
  packed_size += sbp_packed_size_double(&msg->m0);
  packed_size += sbp_packed_size_double(&msg->ecc);
  packed_size += sbp_packed_size_double(&msg->sqrta);
  packed_size += sbp_packed_size_double(&msg->omega0);
  packed_size += sbp_packed_size_double(&msg->omegadot);
  packed_size += sbp_packed_size_double(&msg->w);
  packed_size += sbp_packed_size_double(&msg->inc);
  packed_size += sbp_packed_size_double(&msg->inc_dot);
  packed_size += sbp_packed_size_double(&msg->af0);
  packed_size += sbp_packed_size_double(&msg->af1);
  packed_size += sbp_packed_size_double(&msg->af2);
  packed_size += sbp_packed_size_double(&msg->toe_tow);
  packed_size += sbp_packed_size_u16(&msg->toe_wn);
  packed_size += sbp_packed_size_double(&msg->toc_tow);
  packed_size += sbp_packed_size_u16(&msg->toc_wn);
  packed_size += sbp_packed_size_u8(&msg->valid);
  packed_size += sbp_packed_size_u8(&msg->healthy);
  packed_size += sbp_packed_size_u8(&msg->prn);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ephemeris_dep_a_t(u8 *buf, size_t len, const sbp_msg_ephemeris_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_double(buf + offset, len - offset, &msg->tgd);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_rs);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_rc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_uc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_us);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_ic);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_is);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->dn);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->m0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->ecc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->sqrta);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->omega0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->omegadot);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->w);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->inc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->inc_dot);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->af0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->af1);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->af2);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->toe_tow);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->toe_wn);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->toc_tow);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->toc_wn);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->valid);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->healthy);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->prn);
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_dep_a_t(const uint8_t *buf, size_t len, sbp_msg_ephemeris_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->tgd);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_rs);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_rc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_uc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_us);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_ic);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_is);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->dn);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->m0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->ecc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->sqrta);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->omega0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->omegadot);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->w);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->inc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->inc_dot);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->af0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->af1);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->af2);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->toe_tow);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->toe_wn);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->toc_tow);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->toc_wn);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->valid);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->healthy);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->prn);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_dep_b_t(const sbp_msg_ephemeris_dep_b_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_double(&msg->tgd);
  packed_size += sbp_packed_size_double(&msg->c_rs);
  packed_size += sbp_packed_size_double(&msg->c_rc);
  packed_size += sbp_packed_size_double(&msg->c_uc);
  packed_size += sbp_packed_size_double(&msg->c_us);
  packed_size += sbp_packed_size_double(&msg->c_ic);
  packed_size += sbp_packed_size_double(&msg->c_is);
  packed_size += sbp_packed_size_double(&msg->dn);
  packed_size += sbp_packed_size_double(&msg->m0);
  packed_size += sbp_packed_size_double(&msg->ecc);
  packed_size += sbp_packed_size_double(&msg->sqrta);
  packed_size += sbp_packed_size_double(&msg->omega0);
  packed_size += sbp_packed_size_double(&msg->omegadot);
  packed_size += sbp_packed_size_double(&msg->w);
  packed_size += sbp_packed_size_double(&msg->inc);
  packed_size += sbp_packed_size_double(&msg->inc_dot);
  packed_size += sbp_packed_size_double(&msg->af0);
  packed_size += sbp_packed_size_double(&msg->af1);
  packed_size += sbp_packed_size_double(&msg->af2);
  packed_size += sbp_packed_size_double(&msg->toe_tow);
  packed_size += sbp_packed_size_u16(&msg->toe_wn);
  packed_size += sbp_packed_size_double(&msg->toc_tow);
  packed_size += sbp_packed_size_u16(&msg->toc_wn);
  packed_size += sbp_packed_size_u8(&msg->valid);
  packed_size += sbp_packed_size_u8(&msg->healthy);
  packed_size += sbp_packed_size_u8(&msg->prn);
  packed_size += sbp_packed_size_u8(&msg->iode);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ephemeris_dep_b_t(u8 *buf, size_t len, const sbp_msg_ephemeris_dep_b_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_dep_b_t(msg) > len) { return false; }
  offset += sbp_pack_double(buf + offset, len - offset, &msg->tgd);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_rs);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_rc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_uc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_us);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_ic);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_is);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->dn);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->m0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->ecc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->sqrta);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->omega0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->omegadot);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->w);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->inc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->inc_dot);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->af0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->af1);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->af2);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->toe_tow);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->toe_wn);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->toc_tow);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->toc_wn);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->valid);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->healthy);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->prn);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->iode);
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_dep_b_t(const uint8_t *buf, size_t len, sbp_msg_ephemeris_dep_b_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->tgd);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_rs);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_rc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_uc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_us);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_ic);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_is);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->dn);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->m0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->ecc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->sqrta);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->omega0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->omegadot);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->w);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->inc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->inc_dot);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->af0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->af1);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->af2);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->toe_tow);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->toe_wn);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->toc_tow);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->toc_wn);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->valid);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->healthy);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->prn);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->iode);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_dep_c_t(const sbp_msg_ephemeris_dep_c_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_double(&msg->tgd);
  packed_size += sbp_packed_size_double(&msg->c_rs);
  packed_size += sbp_packed_size_double(&msg->c_rc);
  packed_size += sbp_packed_size_double(&msg->c_uc);
  packed_size += sbp_packed_size_double(&msg->c_us);
  packed_size += sbp_packed_size_double(&msg->c_ic);
  packed_size += sbp_packed_size_double(&msg->c_is);
  packed_size += sbp_packed_size_double(&msg->dn);
  packed_size += sbp_packed_size_double(&msg->m0);
  packed_size += sbp_packed_size_double(&msg->ecc);
  packed_size += sbp_packed_size_double(&msg->sqrta);
  packed_size += sbp_packed_size_double(&msg->omega0);
  packed_size += sbp_packed_size_double(&msg->omegadot);
  packed_size += sbp_packed_size_double(&msg->w);
  packed_size += sbp_packed_size_double(&msg->inc);
  packed_size += sbp_packed_size_double(&msg->inc_dot);
  packed_size += sbp_packed_size_double(&msg->af0);
  packed_size += sbp_packed_size_double(&msg->af1);
  packed_size += sbp_packed_size_double(&msg->af2);
  packed_size += sbp_packed_size_double(&msg->toe_tow);
  packed_size += sbp_packed_size_u16(&msg->toe_wn);
  packed_size += sbp_packed_size_double(&msg->toc_tow);
  packed_size += sbp_packed_size_u16(&msg->toc_wn);
  packed_size += sbp_packed_size_u8(&msg->valid);
  packed_size += sbp_packed_size_u8(&msg->healthy);
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  packed_size += sbp_packed_size_u8(&msg->iode);
  packed_size += sbp_packed_size_u16(&msg->iodc);
  packed_size += sbp_packed_size_u32(&msg->reserved);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ephemeris_dep_c_t(u8 *buf, size_t len, const sbp_msg_ephemeris_dep_c_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_ephemeris_dep_c_t(msg) > len) { return false; }
  offset += sbp_pack_double(buf + offset, len - offset, &msg->tgd);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_rs);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_rc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_uc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_us);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_ic);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->c_is);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->dn);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->m0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->ecc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->sqrta);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->omega0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->omegadot);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->w);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->inc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->inc_dot);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->af0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->af1);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->af2);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->toe_tow);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->toe_wn);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->toc_tow);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->toc_wn);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->valid);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->healthy);
  offset += sbp_pack_sbp_gnss_signal_dep_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->iode);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->iodc);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->reserved);
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_dep_c_t(const uint8_t *buf, size_t len, sbp_msg_ephemeris_dep_c_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->tgd);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_rs);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_rc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_uc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_us);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_ic);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->c_is);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->dn);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->m0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->ecc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->sqrta);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->omega0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->omegadot);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->w);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->inc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->inc_dot);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->af0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->af1);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->af2);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->toe_tow);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->toe_wn);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->toc_tow);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->toc_wn);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->valid);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->healthy);
  offset += sbp_unpack_sbp_gnss_signal_dep_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->iode);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->iodc);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->reserved);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_observation_header_dep_t(const sbp_observation_header_dep_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_gps_time_dep_t(&msg->t);
  packed_size += sbp_packed_size_u8(&msg->n_obs);
  return packed_size;
}

static inline size_t sbp_pack_sbp_observation_header_dep_t(u8 *buf, size_t len, const sbp_observation_header_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_observation_header_dep_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_gps_time_dep_t(buf + offset, len - offset, &msg->t);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->n_obs);
  return offset;
}

static inline size_t sbp_unpack_sbp_observation_header_dep_t(const uint8_t *buf, size_t len, sbp_observation_header_dep_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_gps_time_dep_t(buf + offset, len - offset, &msg->t);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->n_obs);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_carrier_phase_dep_a_t(const sbp_carrier_phase_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_s32(&msg->i);
  packed_size += sbp_packed_size_u8(&msg->f);
  return packed_size;
}

static inline size_t sbp_pack_sbp_carrier_phase_dep_a_t(u8 *buf, size_t len, const sbp_carrier_phase_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_carrier_phase_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->i);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->f);
  return offset;
}

static inline size_t sbp_unpack_sbp_carrier_phase_dep_a_t(const uint8_t *buf, size_t len, sbp_carrier_phase_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->i);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->f);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_packed_obs_content_dep_a_t(const sbp_packed_obs_content_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->P);
  packed_size += sbp_packed_size_sbp_carrier_phase_dep_a_t(&msg->L);
  packed_size += sbp_packed_size_u8(&msg->cn0);
  packed_size += sbp_packed_size_u16(&msg->lock);
  packed_size += sbp_packed_size_u8(&msg->prn);
  return packed_size;
}

static inline size_t sbp_pack_sbp_packed_obs_content_dep_a_t(u8 *buf, size_t len, const sbp_packed_obs_content_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_packed_obs_content_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->P);
  offset += sbp_pack_sbp_carrier_phase_dep_a_t(buf + offset, len - offset, &msg->L);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->cn0);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->lock);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->prn);
  return offset;
}

static inline size_t sbp_unpack_sbp_packed_obs_content_dep_a_t(const uint8_t *buf, size_t len, sbp_packed_obs_content_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->P);
  offset += sbp_unpack_sbp_carrier_phase_dep_a_t(buf + offset, len - offset, &msg->L);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->cn0);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->lock);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->prn);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_packed_obs_content_dep_b_t(const sbp_packed_obs_content_dep_b_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->P);
  packed_size += sbp_packed_size_sbp_carrier_phase_dep_a_t(&msg->L);
  packed_size += sbp_packed_size_u8(&msg->cn0);
  packed_size += sbp_packed_size_u16(&msg->lock);
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  return packed_size;
}

static inline size_t sbp_pack_sbp_packed_obs_content_dep_b_t(u8 *buf, size_t len, const sbp_packed_obs_content_dep_b_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_packed_obs_content_dep_b_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->P);
  offset += sbp_pack_sbp_carrier_phase_dep_a_t(buf + offset, len - offset, &msg->L);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->cn0);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->lock);
  offset += sbp_pack_sbp_gnss_signal_dep_t(buf + offset, len - offset, &msg->sid);
  return offset;
}

static inline size_t sbp_unpack_sbp_packed_obs_content_dep_b_t(const uint8_t *buf, size_t len, sbp_packed_obs_content_dep_b_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->P);
  offset += sbp_unpack_sbp_carrier_phase_dep_a_t(buf + offset, len - offset, &msg->L);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->cn0);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->lock);
  offset += sbp_unpack_sbp_gnss_signal_dep_t(buf + offset, len - offset, &msg->sid);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_packed_obs_content_dep_c_t(const sbp_packed_obs_content_dep_c_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->P);
  packed_size += sbp_packed_size_sbp_carrier_phase_t(&msg->L);
  packed_size += sbp_packed_size_u8(&msg->cn0);
  packed_size += sbp_packed_size_u16(&msg->lock);
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  return packed_size;
}

static inline size_t sbp_pack_sbp_packed_obs_content_dep_c_t(u8 *buf, size_t len, const sbp_packed_obs_content_dep_c_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_packed_obs_content_dep_c_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->P);
  offset += sbp_pack_sbp_carrier_phase_t(buf + offset, len - offset, &msg->L);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->cn0);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->lock);
  offset += sbp_pack_sbp_gnss_signal_dep_t(buf + offset, len - offset, &msg->sid);
  return offset;
}

static inline size_t sbp_unpack_sbp_packed_obs_content_dep_c_t(const uint8_t *buf, size_t len, sbp_packed_obs_content_dep_c_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->P);
  offset += sbp_unpack_sbp_carrier_phase_t(buf + offset, len - offset, &msg->L);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->cn0);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->lock);
  offset += sbp_unpack_sbp_gnss_signal_dep_t(buf + offset, len - offset, &msg->sid);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_obs_dep_a_t(const sbp_msg_obs_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_observation_header_dep_t(&msg->header);
  packed_size += (msg->n_obs * sbp_packed_size_sbp_packed_obs_content_dep_a_t(&msg->obs[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_obs_dep_a_t(u8 *buf, size_t len, const sbp_msg_obs_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_obs_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_observation_header_dep_t(buf + offset, len - offset, &msg->header);
  for (uint8_t i = 0; i < msg->n_obs; i++) 
  {
    offset += sbp_pack_sbp_packed_obs_content_dep_a_t(buf + offset, len - offset, &msg->obs[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_obs_dep_a_t(const uint8_t *buf, size_t len, sbp_msg_obs_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_observation_header_dep_t(buf + offset, len - offset, &msg->header);
  msg->n_obs = (uint8_t)((len - offset) / sbp_packed_size_sbp_packed_obs_content_dep_a_t(&msg->obs[0]));
  for (uint8_t i = 0; i < msg->n_obs; i++)
  {
    offset += sbp_unpack_sbp_packed_obs_content_dep_a_t(buf + offset, len - offset, &msg->obs[i]);
  }
  return true;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_obs_dep_b_t(const sbp_msg_obs_dep_b_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_observation_header_dep_t(&msg->header);
  packed_size += (msg->n_obs * sbp_packed_size_sbp_packed_obs_content_dep_b_t(&msg->obs[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_obs_dep_b_t(u8 *buf, size_t len, const sbp_msg_obs_dep_b_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_obs_dep_b_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_observation_header_dep_t(buf + offset, len - offset, &msg->header);
  for (uint8_t i = 0; i < msg->n_obs; i++) 
  {
    offset += sbp_pack_sbp_packed_obs_content_dep_b_t(buf + offset, len - offset, &msg->obs[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_obs_dep_b_t(const uint8_t *buf, size_t len, sbp_msg_obs_dep_b_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_observation_header_dep_t(buf + offset, len - offset, &msg->header);
  msg->n_obs = (uint8_t)((len - offset) / sbp_packed_size_sbp_packed_obs_content_dep_b_t(&msg->obs[0]));
  for (uint8_t i = 0; i < msg->n_obs; i++)
  {
    offset += sbp_unpack_sbp_packed_obs_content_dep_b_t(buf + offset, len - offset, &msg->obs[i]);
  }
  return true;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_obs_dep_c_t(const sbp_msg_obs_dep_c_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_observation_header_dep_t(&msg->header);
  packed_size += (msg->n_obs * sbp_packed_size_sbp_packed_obs_content_dep_c_t(&msg->obs[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_obs_dep_c_t(u8 *buf, size_t len, const sbp_msg_obs_dep_c_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_obs_dep_c_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_observation_header_dep_t(buf + offset, len - offset, &msg->header);
  for (uint8_t i = 0; i < msg->n_obs; i++) 
  {
    offset += sbp_pack_sbp_packed_obs_content_dep_c_t(buf + offset, len - offset, &msg->obs[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_obs_dep_c_t(const uint8_t *buf, size_t len, sbp_msg_obs_dep_c_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_observation_header_dep_t(buf + offset, len - offset, &msg->header);
  msg->n_obs = (uint8_t)((len - offset) / sbp_packed_size_sbp_packed_obs_content_dep_c_t(&msg->obs[0]));
  for (uint8_t i = 0; i < msg->n_obs; i++)
  {
    offset += sbp_unpack_sbp_packed_obs_content_dep_c_t(buf + offset, len - offset, &msg->obs[i]);
  }
  return true;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_iono_t(const sbp_msg_iono_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->t_nmct);
  packed_size += sbp_packed_size_double(&msg->a0);
  packed_size += sbp_packed_size_double(&msg->a1);
  packed_size += sbp_packed_size_double(&msg->a2);
  packed_size += sbp_packed_size_double(&msg->a3);
  packed_size += sbp_packed_size_double(&msg->b0);
  packed_size += sbp_packed_size_double(&msg->b1);
  packed_size += sbp_packed_size_double(&msg->b2);
  packed_size += sbp_packed_size_double(&msg->b3);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_iono_t(u8 *buf, size_t len, const sbp_msg_iono_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_iono_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->t_nmct);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->a0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->a1);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->a2);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->a3);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->b0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->b1);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->b2);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->b3);
  return true;
}

static inline bool sbp_unpack_sbp_msg_iono_t(const uint8_t *buf, size_t len, sbp_msg_iono_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->t_nmct);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->a0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->a1);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->a2);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->a3);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->b0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->b1);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->b2);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->b3);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_sv_configuration_gps_dep_t(const sbp_msg_sv_configuration_gps_dep_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->t_nmct);
  packed_size += sbp_packed_size_u32(&msg->l2c_mask);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_sv_configuration_gps_dep_t(u8 *buf, size_t len, const sbp_msg_sv_configuration_gps_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_sv_configuration_gps_dep_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->t_nmct);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->l2c_mask);
  return true;
}

static inline bool sbp_unpack_sbp_msg_sv_configuration_gps_dep_t(const uint8_t *buf, size_t len, sbp_msg_sv_configuration_gps_dep_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->t_nmct);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->l2c_mask);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_gnss_capb_t(const sbp_gnss_capb_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u64(&msg->gps_active);
  packed_size += sbp_packed_size_u64(&msg->gps_l2c);
  packed_size += sbp_packed_size_u64(&msg->gps_l5);
  packed_size += sbp_packed_size_u32(&msg->glo_active);
  packed_size += sbp_packed_size_u32(&msg->glo_l2of);
  packed_size += sbp_packed_size_u32(&msg->glo_l3);
  packed_size += sbp_packed_size_u64(&msg->sbas_active);
  packed_size += sbp_packed_size_u64(&msg->sbas_l5);
  packed_size += sbp_packed_size_u64(&msg->bds_active);
  packed_size += sbp_packed_size_u64(&msg->bds_d2nav);
  packed_size += sbp_packed_size_u64(&msg->bds_b2);
  packed_size += sbp_packed_size_u64(&msg->bds_b2a);
  packed_size += sbp_packed_size_u32(&msg->qzss_active);
  packed_size += sbp_packed_size_u64(&msg->gal_active);
  packed_size += sbp_packed_size_u64(&msg->gal_e5);
  return packed_size;
}

static inline size_t sbp_pack_sbp_gnss_capb_t(u8 *buf, size_t len, const sbp_gnss_capb_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_gnss_capb_t(msg) > len) { return false; }
  offset += sbp_pack_u64(buf + offset, len - offset, &msg->gps_active);
  offset += sbp_pack_u64(buf + offset, len - offset, &msg->gps_l2c);
  offset += sbp_pack_u64(buf + offset, len - offset, &msg->gps_l5);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->glo_active);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->glo_l2of);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->glo_l3);
  offset += sbp_pack_u64(buf + offset, len - offset, &msg->sbas_active);
  offset += sbp_pack_u64(buf + offset, len - offset, &msg->sbas_l5);
  offset += sbp_pack_u64(buf + offset, len - offset, &msg->bds_active);
  offset += sbp_pack_u64(buf + offset, len - offset, &msg->bds_d2nav);
  offset += sbp_pack_u64(buf + offset, len - offset, &msg->bds_b2);
  offset += sbp_pack_u64(buf + offset, len - offset, &msg->bds_b2a);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->qzss_active);
  offset += sbp_pack_u64(buf + offset, len - offset, &msg->gal_active);
  offset += sbp_pack_u64(buf + offset, len - offset, &msg->gal_e5);
  return offset;
}

static inline size_t sbp_unpack_sbp_gnss_capb_t(const uint8_t *buf, size_t len, sbp_gnss_capb_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u64(buf + offset, len - offset, &msg->gps_active);
  offset += sbp_unpack_u64(buf + offset, len - offset, &msg->gps_l2c);
  offset += sbp_unpack_u64(buf + offset, len - offset, &msg->gps_l5);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->glo_active);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->glo_l2of);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->glo_l3);
  offset += sbp_unpack_u64(buf + offset, len - offset, &msg->sbas_active);
  offset += sbp_unpack_u64(buf + offset, len - offset, &msg->sbas_l5);
  offset += sbp_unpack_u64(buf + offset, len - offset, &msg->bds_active);
  offset += sbp_unpack_u64(buf + offset, len - offset, &msg->bds_d2nav);
  offset += sbp_unpack_u64(buf + offset, len - offset, &msg->bds_b2);
  offset += sbp_unpack_u64(buf + offset, len - offset, &msg->bds_b2a);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->qzss_active);
  offset += sbp_unpack_u64(buf + offset, len - offset, &msg->gal_active);
  offset += sbp_unpack_u64(buf + offset, len - offset, &msg->gal_e5);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_gnss_capb_t(const sbp_msg_gnss_capb_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->t_nmct);
  packed_size += sbp_packed_size_sbp_gnss_capb_t(&msg->gc);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_gnss_capb_t(u8 *buf, size_t len, const sbp_msg_gnss_capb_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_gnss_capb_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->t_nmct);
  offset += sbp_pack_sbp_gnss_capb_t(buf + offset, len - offset, &msg->gc);
  return true;
}

static inline bool sbp_unpack_sbp_msg_gnss_capb_t(const uint8_t *buf, size_t len, sbp_msg_gnss_capb_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->t_nmct);
  offset += sbp_unpack_sbp_gnss_capb_t(buf + offset, len - offset, &msg->gc);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_group_delay_dep_a_t(const sbp_msg_group_delay_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_gps_time_dep_t(&msg->t_op);
  packed_size += sbp_packed_size_u8(&msg->prn);
  packed_size += sbp_packed_size_u8(&msg->valid);
  packed_size += sbp_packed_size_s16(&msg->tgd);
  packed_size += sbp_packed_size_s16(&msg->isc_l1ca);
  packed_size += sbp_packed_size_s16(&msg->isc_l2c);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_group_delay_dep_a_t(u8 *buf, size_t len, const sbp_msg_group_delay_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_group_delay_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_gps_time_dep_t(buf + offset, len - offset, &msg->t_op);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->prn);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->valid);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->tgd);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->isc_l1ca);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->isc_l2c);
  return true;
}

static inline bool sbp_unpack_sbp_msg_group_delay_dep_a_t(const uint8_t *buf, size_t len, sbp_msg_group_delay_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_gps_time_dep_t(buf + offset, len - offset, &msg->t_op);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->prn);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->valid);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->tgd);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->isc_l1ca);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->isc_l2c);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_group_delay_dep_b_t(const sbp_msg_group_delay_dep_b_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->t_op);
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  packed_size += sbp_packed_size_u8(&msg->valid);
  packed_size += sbp_packed_size_s16(&msg->tgd);
  packed_size += sbp_packed_size_s16(&msg->isc_l1ca);
  packed_size += sbp_packed_size_s16(&msg->isc_l2c);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_group_delay_dep_b_t(u8 *buf, size_t len, const sbp_msg_group_delay_dep_b_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_group_delay_dep_b_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->t_op);
  offset += sbp_pack_sbp_gnss_signal_dep_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->valid);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->tgd);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->isc_l1ca);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->isc_l2c);
  return true;
}

static inline bool sbp_unpack_sbp_msg_group_delay_dep_b_t(const uint8_t *buf, size_t len, sbp_msg_group_delay_dep_b_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->t_op);
  offset += sbp_unpack_sbp_gnss_signal_dep_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->valid);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->tgd);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->isc_l1ca);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->isc_l2c);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_group_delay_t(const sbp_msg_group_delay_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->t_op);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_u8(&msg->valid);
  packed_size += sbp_packed_size_s16(&msg->tgd);
  packed_size += sbp_packed_size_s16(&msg->isc_l1ca);
  packed_size += sbp_packed_size_s16(&msg->isc_l2c);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_group_delay_t(u8 *buf, size_t len, const sbp_msg_group_delay_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_group_delay_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->t_op);
  offset += sbp_pack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->valid);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->tgd);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->isc_l1ca);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->isc_l2c);
  return true;
}

static inline bool sbp_unpack_sbp_msg_group_delay_t(const uint8_t *buf, size_t len, sbp_msg_group_delay_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->t_op);
  offset += sbp_unpack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->valid);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->tgd);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->isc_l1ca);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->isc_l2c);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_almanac_common_content_t(const sbp_almanac_common_content_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->toa);
  packed_size += sbp_packed_size_double(&msg->ura);
  packed_size += sbp_packed_size_u32(&msg->fit_interval);
  packed_size += sbp_packed_size_u8(&msg->valid);
  packed_size += sbp_packed_size_u8(&msg->health_bits);
  return packed_size;
}

static inline size_t sbp_pack_sbp_almanac_common_content_t(u8 *buf, size_t len, const sbp_almanac_common_content_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_almanac_common_content_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_pack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->toa);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->ura);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->fit_interval);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->valid);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->health_bits);
  return offset;
}

static inline size_t sbp_unpack_sbp_almanac_common_content_t(const uint8_t *buf, size_t len, sbp_almanac_common_content_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_unpack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->toa);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->ura);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->fit_interval);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->valid);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->health_bits);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_almanac_common_content_dep_t(const sbp_almanac_common_content_dep_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->toa);
  packed_size += sbp_packed_size_double(&msg->ura);
  packed_size += sbp_packed_size_u32(&msg->fit_interval);
  packed_size += sbp_packed_size_u8(&msg->valid);
  packed_size += sbp_packed_size_u8(&msg->health_bits);
  return packed_size;
}

static inline size_t sbp_pack_sbp_almanac_common_content_dep_t(u8 *buf, size_t len, const sbp_almanac_common_content_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_almanac_common_content_dep_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_gnss_signal_dep_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_pack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->toa);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->ura);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->fit_interval);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->valid);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->health_bits);
  return offset;
}

static inline size_t sbp_unpack_sbp_almanac_common_content_dep_t(const uint8_t *buf, size_t len, sbp_almanac_common_content_dep_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_gnss_signal_dep_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_unpack_sbp_gps_time_sec_t(buf + offset, len - offset, &msg->toa);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->ura);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->fit_interval);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->valid);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->health_bits);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_almanac_gps_dep_t(const sbp_msg_almanac_gps_dep_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_almanac_common_content_dep_t(&msg->common);
  packed_size += sbp_packed_size_double(&msg->m0);
  packed_size += sbp_packed_size_double(&msg->ecc);
  packed_size += sbp_packed_size_double(&msg->sqrta);
  packed_size += sbp_packed_size_double(&msg->omega0);
  packed_size += sbp_packed_size_double(&msg->omegadot);
  packed_size += sbp_packed_size_double(&msg->w);
  packed_size += sbp_packed_size_double(&msg->inc);
  packed_size += sbp_packed_size_double(&msg->af0);
  packed_size += sbp_packed_size_double(&msg->af1);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_almanac_gps_dep_t(u8 *buf, size_t len, const sbp_msg_almanac_gps_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_almanac_gps_dep_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_almanac_common_content_dep_t(buf + offset, len - offset, &msg->common);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->m0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->ecc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->sqrta);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->omega0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->omegadot);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->w);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->inc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->af0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->af1);
  return true;
}

static inline bool sbp_unpack_sbp_msg_almanac_gps_dep_t(const uint8_t *buf, size_t len, sbp_msg_almanac_gps_dep_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_almanac_common_content_dep_t(buf + offset, len - offset, &msg->common);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->m0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->ecc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->sqrta);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->omega0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->omegadot);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->w);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->inc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->af0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->af1);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_almanac_gps_t(const sbp_msg_almanac_gps_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_almanac_common_content_t(&msg->common);
  packed_size += sbp_packed_size_double(&msg->m0);
  packed_size += sbp_packed_size_double(&msg->ecc);
  packed_size += sbp_packed_size_double(&msg->sqrta);
  packed_size += sbp_packed_size_double(&msg->omega0);
  packed_size += sbp_packed_size_double(&msg->omegadot);
  packed_size += sbp_packed_size_double(&msg->w);
  packed_size += sbp_packed_size_double(&msg->inc);
  packed_size += sbp_packed_size_double(&msg->af0);
  packed_size += sbp_packed_size_double(&msg->af1);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_almanac_gps_t(u8 *buf, size_t len, const sbp_msg_almanac_gps_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_almanac_gps_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_almanac_common_content_t(buf + offset, len - offset, &msg->common);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->m0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->ecc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->sqrta);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->omega0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->omegadot);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->w);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->inc);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->af0);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->af1);
  return true;
}

static inline bool sbp_unpack_sbp_msg_almanac_gps_t(const uint8_t *buf, size_t len, sbp_msg_almanac_gps_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_almanac_common_content_t(buf + offset, len - offset, &msg->common);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->m0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->ecc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->sqrta);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->omega0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->omegadot);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->w);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->inc);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->af0);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->af1);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_almanac_glo_dep_t(const sbp_msg_almanac_glo_dep_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_almanac_common_content_dep_t(&msg->common);
  packed_size += sbp_packed_size_double(&msg->lambda_na);
  packed_size += sbp_packed_size_double(&msg->t_lambda_na);
  packed_size += sbp_packed_size_double(&msg->i);
  packed_size += sbp_packed_size_double(&msg->t);
  packed_size += sbp_packed_size_double(&msg->t_dot);
  packed_size += sbp_packed_size_double(&msg->epsilon);
  packed_size += sbp_packed_size_double(&msg->omega);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_almanac_glo_dep_t(u8 *buf, size_t len, const sbp_msg_almanac_glo_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_almanac_glo_dep_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_almanac_common_content_dep_t(buf + offset, len - offset, &msg->common);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->lambda_na);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->t_lambda_na);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->i);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->t);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->t_dot);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->epsilon);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->omega);
  return true;
}

static inline bool sbp_unpack_sbp_msg_almanac_glo_dep_t(const uint8_t *buf, size_t len, sbp_msg_almanac_glo_dep_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_almanac_common_content_dep_t(buf + offset, len - offset, &msg->common);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->lambda_na);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->t_lambda_na);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->i);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->t);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->t_dot);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->epsilon);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->omega);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_almanac_glo_t(const sbp_msg_almanac_glo_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_almanac_common_content_t(&msg->common);
  packed_size += sbp_packed_size_double(&msg->lambda_na);
  packed_size += sbp_packed_size_double(&msg->t_lambda_na);
  packed_size += sbp_packed_size_double(&msg->i);
  packed_size += sbp_packed_size_double(&msg->t);
  packed_size += sbp_packed_size_double(&msg->t_dot);
  packed_size += sbp_packed_size_double(&msg->epsilon);
  packed_size += sbp_packed_size_double(&msg->omega);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_almanac_glo_t(u8 *buf, size_t len, const sbp_msg_almanac_glo_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_almanac_glo_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_almanac_common_content_t(buf + offset, len - offset, &msg->common);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->lambda_na);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->t_lambda_na);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->i);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->t);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->t_dot);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->epsilon);
  offset += sbp_pack_double(buf + offset, len - offset, &msg->omega);
  return true;
}

static inline bool sbp_unpack_sbp_msg_almanac_glo_t(const uint8_t *buf, size_t len, sbp_msg_almanac_glo_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_almanac_common_content_t(buf + offset, len - offset, &msg->common);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->lambda_na);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->t_lambda_na);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->i);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->t);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->t_dot);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->epsilon);
  offset += sbp_unpack_double(buf + offset, len - offset, &msg->omega);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_glo_biases_t(const sbp_msg_glo_biases_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->mask);
  packed_size += sbp_packed_size_s16(&msg->l1ca_bias);
  packed_size += sbp_packed_size_s16(&msg->l1p_bias);
  packed_size += sbp_packed_size_s16(&msg->l2ca_bias);
  packed_size += sbp_packed_size_s16(&msg->l2p_bias);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_glo_biases_t(u8 *buf, size_t len, const sbp_msg_glo_biases_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_glo_biases_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->mask);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->l1ca_bias);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->l1p_bias);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->l2ca_bias);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->l2p_bias);
  return true;
}

static inline bool sbp_unpack_sbp_msg_glo_biases_t(const uint8_t *buf, size_t len, sbp_msg_glo_biases_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->mask);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->l1ca_bias);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->l1p_bias);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->l2ca_bias);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->l2p_bias);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_sv_az_el_t(const sbp_sv_az_el_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_u8(&msg->az);
  packed_size += sbp_packed_size_s8(&msg->el);
  return packed_size;
}

static inline size_t sbp_pack_sbp_sv_az_el_t(u8 *buf, size_t len, const sbp_sv_az_el_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_sv_az_el_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->az);
  offset += sbp_pack_s8(buf + offset, len - offset, &msg->el);
  return offset;
}

static inline size_t sbp_unpack_sbp_sv_az_el_t(const uint8_t *buf, size_t len, sbp_sv_az_el_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->az);
  offset += sbp_unpack_s8(buf + offset, len - offset, &msg->el);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_sv_az_el_t(const sbp_msg_sv_az_el_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += (msg->n_azel * sbp_packed_size_sbp_sv_az_el_t(&msg->azel[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_sv_az_el_t(u8 *buf, size_t len, const sbp_msg_sv_az_el_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_sv_az_el_t(msg) > len) { return false; }
  for (uint8_t i = 0; i < msg->n_azel; i++) 
  {
    offset += sbp_pack_sbp_sv_az_el_t(buf + offset, len - offset, &msg->azel[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_sv_az_el_t(const uint8_t *buf, size_t len, sbp_msg_sv_az_el_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  msg->n_azel = (uint8_t)((len - offset) / sbp_packed_size_sbp_sv_az_el_t(&msg->azel[0]));
  for (uint8_t i = 0; i < msg->n_azel; i++)
  {
    offset += sbp_unpack_sbp_sv_az_el_t(buf + offset, len - offset, &msg->azel[i]);
  }
  return true;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_osr_t(const sbp_msg_osr_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_observation_header_t(&msg->header);
  packed_size += (msg->n_obs * sbp_packed_size_sbp_packed_osr_content_t(&msg->obs[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_osr_t(u8 *buf, size_t len, const sbp_msg_osr_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_osr_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_observation_header_t(buf + offset, len - offset, &msg->header);
  for (uint8_t i = 0; i < msg->n_obs; i++) 
  {
    offset += sbp_pack_sbp_packed_osr_content_t(buf + offset, len - offset, &msg->obs[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_osr_t(const uint8_t *buf, size_t len, sbp_msg_osr_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_observation_header_t(buf + offset, len - offset, &msg->header);
  msg->n_obs = (uint8_t)((len - offset) / sbp_packed_size_sbp_packed_osr_content_t(&msg->obs[0]));
  for (uint8_t i = 0; i < msg->n_obs; i++)
  {
    offset += sbp_unpack_sbp_packed_osr_content_t(buf + offset, len - offset, &msg->obs[i]);
  }
  return true;
  return true;
}

#endif
