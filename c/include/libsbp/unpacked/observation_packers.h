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
#include <libsbp/unpacked/common.h>
#include <libsbp/unpacked/string/unterminated.h>
#include <libsbp/unpacked/string/multipart.h>
#include <libsbp/unpacked/string/sequence.h>
#include <libsbp/unpacked/string/null_terminated.h>
                                                                                                              
static inline size_t sbp_packed_size_sbp_observation_header_t(const sbp_observation_header_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_sbp_gps_time_t(&msg->t);
  packed_size += sbp_packed_size_u8(&msg->n_obs);
  return packed_size;
}

static inline bool sbp_pack_sbp_observation_header_t(sbp_pack_ctx_t *ctx, const sbp_observation_header_t *msg)
{
  if (!sbp_pack_sbp_sbp_gps_time_t(ctx, &msg->t)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->n_obs)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_observation_header_t(sbp_unpack_ctx_t *ctx, sbp_observation_header_t *msg)
{
  if (!sbp_unpack_sbp_sbp_gps_time_t(ctx, &msg->t)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->n_obs)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_doppler_t(const sbp_doppler_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_s16(&msg->i);
  packed_size += sbp_packed_size_u8(&msg->f);
  return packed_size;
}

static inline bool sbp_pack_sbp_doppler_t(sbp_pack_ctx_t *ctx, const sbp_doppler_t *msg)
{
  if (!sbp_pack_s16(ctx, &msg->i)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->f)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_doppler_t(sbp_unpack_ctx_t *ctx, sbp_doppler_t *msg)
{
  if (!sbp_unpack_s16(ctx, &msg->i)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->f)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_packed_obs_content_t(const sbp_packed_obs_content_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->P);
  packed_size += sbp_packed_size_sbp_carrier_phase_t(&msg->L);
  packed_size += sbp_packed_size_sbp_doppler_t(&msg->D);
  packed_size += sbp_packed_size_u8(&msg->cn0);
  packed_size += sbp_packed_size_u8(&msg->lock);
  packed_size += sbp_packed_size_u8(&msg->flags);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  return packed_size;
}

static inline bool sbp_pack_sbp_packed_obs_content_t(sbp_pack_ctx_t *ctx, const sbp_packed_obs_content_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->P)) { return false; }
  if (!sbp_pack_sbp_carrier_phase_t(ctx, &msg->L)) { return false; }
  if (!sbp_pack_sbp_doppler_t(ctx, &msg->D)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->cn0)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->lock)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  if (!sbp_pack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_packed_obs_content_t(sbp_unpack_ctx_t *ctx, sbp_packed_obs_content_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->P)) { return false; }
  if (!sbp_unpack_sbp_carrier_phase_t(ctx, &msg->L)) { return false; }
  if (!sbp_unpack_sbp_doppler_t(ctx, &msg->D)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->cn0)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->lock)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  if (!sbp_unpack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_packed_osr_content_t(const sbp_packed_osr_content_t *msg) {
  size_t packed_size = 0;
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

static inline bool sbp_pack_sbp_packed_osr_content_t(sbp_pack_ctx_t *ctx, const sbp_packed_osr_content_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->P)) { return false; }
  if (!sbp_pack_sbp_carrier_phase_t(ctx, &msg->L)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->lock)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  if (!sbp_pack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->iono_std)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->tropo_std)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->range_std)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_packed_osr_content_t(sbp_unpack_ctx_t *ctx, sbp_packed_osr_content_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->P)) { return false; }
  if (!sbp_unpack_sbp_carrier_phase_t(ctx, &msg->L)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->lock)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  if (!sbp_unpack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->iono_std)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->tropo_std)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->range_std)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_obs_t(const sbp_msg_obs_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_observation_header_t(&msg->header);
  packed_size += (msg->n_obs * sbp_packed_size_sbp_packed_obs_content_t(&msg->obs[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_obs_t(sbp_pack_ctx_t *ctx, const sbp_msg_obs_t *msg)
{
  if (!sbp_pack_sbp_observation_header_t(ctx, &msg->header)) { return false; }
  for (uint8_t i = 0; i < msg->n_obs; i++)
  {
    if (!sbp_pack_sbp_packed_obs_content_t(ctx, &msg->obs[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_obs_t(sbp_unpack_ctx_t *ctx, sbp_msg_obs_t *msg)
{
  if (!sbp_unpack_sbp_observation_header_t(ctx, &msg->header)) { return false; }
    msg->n_obs = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_packed_obs_content_t(&msg->obs[0]));
  for (uint8_t i = 0; i < msg->n_obs; i++) {
    if (!sbp_unpack_sbp_packed_obs_content_t(ctx, &msg->obs[i])) { return false; }
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_base_pos_llh_t(const sbp_msg_base_pos_llh_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_double(&msg->lat);
  packed_size += sbp_packed_size_double(&msg->lon);
  packed_size += sbp_packed_size_double(&msg->height);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_base_pos_llh_t(sbp_pack_ctx_t *ctx, const sbp_msg_base_pos_llh_t *msg)
{
  if (!sbp_pack_double(ctx, &msg->lat)) { return false; }
  if (!sbp_pack_double(ctx, &msg->lon)) { return false; }
  if (!sbp_pack_double(ctx, &msg->height)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_base_pos_llh_t(sbp_unpack_ctx_t *ctx, sbp_msg_base_pos_llh_t *msg)
{
  if (!sbp_unpack_double(ctx, &msg->lat)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->lon)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->height)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_base_pos_ecef_t(const sbp_msg_base_pos_ecef_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_double(&msg->x);
  packed_size += sbp_packed_size_double(&msg->y);
  packed_size += sbp_packed_size_double(&msg->z);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_base_pos_ecef_t(sbp_pack_ctx_t *ctx, const sbp_msg_base_pos_ecef_t *msg)
{
  if (!sbp_pack_double(ctx, &msg->x)) { return false; }
  if (!sbp_pack_double(ctx, &msg->y)) { return false; }
  if (!sbp_pack_double(ctx, &msg->z)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_base_pos_ecef_t(sbp_unpack_ctx_t *ctx, sbp_msg_base_pos_ecef_t *msg)
{
  if (!sbp_unpack_double(ctx, &msg->x)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->y)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->z)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_ephemeris_common_content_t(const sbp_ephemeris_common_content_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->toe);
  packed_size += sbp_packed_size_float(&msg->ura);
  packed_size += sbp_packed_size_u32(&msg->fit_interval);
  packed_size += sbp_packed_size_u8(&msg->valid);
  packed_size += sbp_packed_size_u8(&msg->health_bits);
  return packed_size;
}

static inline bool sbp_pack_sbp_ephemeris_common_content_t(sbp_pack_ctx_t *ctx, const sbp_ephemeris_common_content_t *msg)
{
  if (!sbp_pack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!sbp_pack_sbp_gps_time_sec_t(ctx, &msg->toe)) { return false; }
  if (!sbp_pack_float(ctx, &msg->ura)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->fit_interval)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->valid)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->health_bits)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_ephemeris_common_content_t(sbp_unpack_ctx_t *ctx, sbp_ephemeris_common_content_t *msg)
{
  if (!sbp_unpack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!sbp_unpack_sbp_gps_time_sec_t(ctx, &msg->toe)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->ura)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->fit_interval)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->valid)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->health_bits)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_ephemeris_common_content_dep_b_t(const sbp_ephemeris_common_content_dep_b_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->toe);
  packed_size += sbp_packed_size_double(&msg->ura);
  packed_size += sbp_packed_size_u32(&msg->fit_interval);
  packed_size += sbp_packed_size_u8(&msg->valid);
  packed_size += sbp_packed_size_u8(&msg->health_bits);
  return packed_size;
}

static inline bool sbp_pack_sbp_ephemeris_common_content_dep_b_t(sbp_pack_ctx_t *ctx, const sbp_ephemeris_common_content_dep_b_t *msg)
{
  if (!sbp_pack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!sbp_pack_sbp_gps_time_sec_t(ctx, &msg->toe)) { return false; }
  if (!sbp_pack_double(ctx, &msg->ura)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->fit_interval)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->valid)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->health_bits)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_ephemeris_common_content_dep_b_t(sbp_unpack_ctx_t *ctx, sbp_ephemeris_common_content_dep_b_t *msg)
{
  if (!sbp_unpack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!sbp_unpack_sbp_gps_time_sec_t(ctx, &msg->toe)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->ura)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->fit_interval)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->valid)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->health_bits)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_ephemeris_common_content_dep_a_t(const sbp_ephemeris_common_content_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  packed_size += sbp_packed_size_sbp_gps_time_dep_t(&msg->toe);
  packed_size += sbp_packed_size_double(&msg->ura);
  packed_size += sbp_packed_size_u32(&msg->fit_interval);
  packed_size += sbp_packed_size_u8(&msg->valid);
  packed_size += sbp_packed_size_u8(&msg->health_bits);
  return packed_size;
}

static inline bool sbp_pack_sbp_ephemeris_common_content_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_ephemeris_common_content_dep_a_t *msg)
{
  if (!sbp_pack_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  if (!sbp_pack_sbp_gps_time_dep_t(ctx, &msg->toe)) { return false; }
  if (!sbp_pack_double(ctx, &msg->ura)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->fit_interval)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->valid)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->health_bits)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_ephemeris_common_content_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_ephemeris_common_content_dep_a_t *msg)
{
  if (!sbp_unpack_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  if (!sbp_unpack_sbp_gps_time_dep_t(ctx, &msg->toe)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->ura)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->fit_interval)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->valid)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->health_bits)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_gps_dep_e_t(const sbp_msg_ephemeris_gps_dep_e_t *msg) {
  size_t packed_size = 0;
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

static inline bool sbp_pack_sbp_msg_ephemeris_gps_dep_e_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_gps_dep_e_t *msg)
{
  if (!sbp_pack_sbp_ephemeris_common_content_dep_a_t(ctx, &msg->common)) { return false; }
  if (!sbp_pack_double(ctx, &msg->tgd)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_rs)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_rc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_uc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_us)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_ic)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_is)) { return false; }
  if (!sbp_pack_double(ctx, &msg->dn)) { return false; }
  if (!sbp_pack_double(ctx, &msg->m0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->ecc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->sqrta)) { return false; }
  if (!sbp_pack_double(ctx, &msg->omega0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->omegadot)) { return false; }
  if (!sbp_pack_double(ctx, &msg->w)) { return false; }
  if (!sbp_pack_double(ctx, &msg->inc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->inc_dot)) { return false; }
  if (!sbp_pack_double(ctx, &msg->af0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->af1)) { return false; }
  if (!sbp_pack_double(ctx, &msg->af2)) { return false; }
  if (!sbp_pack_sbp_gps_time_dep_t(ctx, &msg->toc)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->iode)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->iodc)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_gps_dep_e_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_gps_dep_e_t *msg)
{
  if (!sbp_unpack_sbp_ephemeris_common_content_dep_a_t(ctx, &msg->common)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->tgd)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_rs)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_rc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_uc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_us)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_ic)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_is)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->dn)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->m0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->ecc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->sqrta)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->omega0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->omegadot)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->w)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->inc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->inc_dot)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->af0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->af1)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->af2)) { return false; }
  if (!sbp_unpack_sbp_gps_time_dep_t(ctx, &msg->toc)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->iode)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->iodc)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_gps_dep_f_t(const sbp_msg_ephemeris_gps_dep_f_t *msg) {
  size_t packed_size = 0;
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

static inline bool sbp_pack_sbp_msg_ephemeris_gps_dep_f_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_gps_dep_f_t *msg)
{
  if (!sbp_pack_sbp_ephemeris_common_content_dep_b_t(ctx, &msg->common)) { return false; }
  if (!sbp_pack_double(ctx, &msg->tgd)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_rs)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_rc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_uc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_us)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_ic)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_is)) { return false; }
  if (!sbp_pack_double(ctx, &msg->dn)) { return false; }
  if (!sbp_pack_double(ctx, &msg->m0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->ecc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->sqrta)) { return false; }
  if (!sbp_pack_double(ctx, &msg->omega0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->omegadot)) { return false; }
  if (!sbp_pack_double(ctx, &msg->w)) { return false; }
  if (!sbp_pack_double(ctx, &msg->inc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->inc_dot)) { return false; }
  if (!sbp_pack_double(ctx, &msg->af0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->af1)) { return false; }
  if (!sbp_pack_double(ctx, &msg->af2)) { return false; }
  if (!sbp_pack_sbp_gps_time_sec_t(ctx, &msg->toc)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->iode)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->iodc)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_gps_dep_f_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_gps_dep_f_t *msg)
{
  if (!sbp_unpack_sbp_ephemeris_common_content_dep_b_t(ctx, &msg->common)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->tgd)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_rs)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_rc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_uc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_us)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_ic)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_is)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->dn)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->m0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->ecc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->sqrta)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->omega0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->omegadot)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->w)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->inc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->inc_dot)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->af0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->af1)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->af2)) { return false; }
  if (!sbp_unpack_sbp_gps_time_sec_t(ctx, &msg->toc)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->iode)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->iodc)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_gps_t(const sbp_msg_ephemeris_gps_t *msg) {
  size_t packed_size = 0;
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

static inline bool sbp_pack_sbp_msg_ephemeris_gps_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_gps_t *msg)
{
  if (!sbp_pack_sbp_ephemeris_common_content_t(ctx, &msg->common)) { return false; }
  if (!sbp_pack_float(ctx, &msg->tgd)) { return false; }
  if (!sbp_pack_float(ctx, &msg->c_rs)) { return false; }
  if (!sbp_pack_float(ctx, &msg->c_rc)) { return false; }
  if (!sbp_pack_float(ctx, &msg->c_uc)) { return false; }
  if (!sbp_pack_float(ctx, &msg->c_us)) { return false; }
  if (!sbp_pack_float(ctx, &msg->c_ic)) { return false; }
  if (!sbp_pack_float(ctx, &msg->c_is)) { return false; }
  if (!sbp_pack_double(ctx, &msg->dn)) { return false; }
  if (!sbp_pack_double(ctx, &msg->m0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->ecc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->sqrta)) { return false; }
  if (!sbp_pack_double(ctx, &msg->omega0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->omegadot)) { return false; }
  if (!sbp_pack_double(ctx, &msg->w)) { return false; }
  if (!sbp_pack_double(ctx, &msg->inc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->inc_dot)) { return false; }
  if (!sbp_pack_float(ctx, &msg->af0)) { return false; }
  if (!sbp_pack_float(ctx, &msg->af1)) { return false; }
  if (!sbp_pack_float(ctx, &msg->af2)) { return false; }
  if (!sbp_pack_sbp_gps_time_sec_t(ctx, &msg->toc)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->iode)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->iodc)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_gps_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_gps_t *msg)
{
  if (!sbp_unpack_sbp_ephemeris_common_content_t(ctx, &msg->common)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->tgd)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->c_rs)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->c_rc)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->c_uc)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->c_us)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->c_ic)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->c_is)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->dn)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->m0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->ecc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->sqrta)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->omega0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->omegadot)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->w)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->inc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->inc_dot)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->af0)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->af1)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->af2)) { return false; }
  if (!sbp_unpack_sbp_gps_time_sec_t(ctx, &msg->toc)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->iode)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->iodc)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_qzss_t(const sbp_msg_ephemeris_qzss_t *msg) {
  size_t packed_size = 0;
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

static inline bool sbp_pack_sbp_msg_ephemeris_qzss_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_qzss_t *msg)
{
  if (!sbp_pack_sbp_ephemeris_common_content_t(ctx, &msg->common)) { return false; }
  if (!sbp_pack_float(ctx, &msg->tgd)) { return false; }
  if (!sbp_pack_float(ctx, &msg->c_rs)) { return false; }
  if (!sbp_pack_float(ctx, &msg->c_rc)) { return false; }
  if (!sbp_pack_float(ctx, &msg->c_uc)) { return false; }
  if (!sbp_pack_float(ctx, &msg->c_us)) { return false; }
  if (!sbp_pack_float(ctx, &msg->c_ic)) { return false; }
  if (!sbp_pack_float(ctx, &msg->c_is)) { return false; }
  if (!sbp_pack_double(ctx, &msg->dn)) { return false; }
  if (!sbp_pack_double(ctx, &msg->m0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->ecc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->sqrta)) { return false; }
  if (!sbp_pack_double(ctx, &msg->omega0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->omegadot)) { return false; }
  if (!sbp_pack_double(ctx, &msg->w)) { return false; }
  if (!sbp_pack_double(ctx, &msg->inc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->inc_dot)) { return false; }
  if (!sbp_pack_float(ctx, &msg->af0)) { return false; }
  if (!sbp_pack_float(ctx, &msg->af1)) { return false; }
  if (!sbp_pack_float(ctx, &msg->af2)) { return false; }
  if (!sbp_pack_sbp_gps_time_sec_t(ctx, &msg->toc)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->iode)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->iodc)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_qzss_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_qzss_t *msg)
{
  if (!sbp_unpack_sbp_ephemeris_common_content_t(ctx, &msg->common)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->tgd)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->c_rs)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->c_rc)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->c_uc)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->c_us)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->c_ic)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->c_is)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->dn)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->m0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->ecc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->sqrta)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->omega0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->omegadot)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->w)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->inc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->inc_dot)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->af0)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->af1)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->af2)) { return false; }
  if (!sbp_unpack_sbp_gps_time_sec_t(ctx, &msg->toc)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->iode)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->iodc)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_bds_t(const sbp_msg_ephemeris_bds_t *msg) {
  size_t packed_size = 0;
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

static inline bool sbp_pack_sbp_msg_ephemeris_bds_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_bds_t *msg)
{
  if (!sbp_pack_sbp_ephemeris_common_content_t(ctx, &msg->common)) { return false; }
  if (!sbp_pack_float(ctx, &msg->tgd1)) { return false; }
  if (!sbp_pack_float(ctx, &msg->tgd2)) { return false; }
  if (!sbp_pack_float(ctx, &msg->c_rs)) { return false; }
  if (!sbp_pack_float(ctx, &msg->c_rc)) { return false; }
  if (!sbp_pack_float(ctx, &msg->c_uc)) { return false; }
  if (!sbp_pack_float(ctx, &msg->c_us)) { return false; }
  if (!sbp_pack_float(ctx, &msg->c_ic)) { return false; }
  if (!sbp_pack_float(ctx, &msg->c_is)) { return false; }
  if (!sbp_pack_double(ctx, &msg->dn)) { return false; }
  if (!sbp_pack_double(ctx, &msg->m0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->ecc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->sqrta)) { return false; }
  if (!sbp_pack_double(ctx, &msg->omega0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->omegadot)) { return false; }
  if (!sbp_pack_double(ctx, &msg->w)) { return false; }
  if (!sbp_pack_double(ctx, &msg->inc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->inc_dot)) { return false; }
  if (!sbp_pack_double(ctx, &msg->af0)) { return false; }
  if (!sbp_pack_float(ctx, &msg->af1)) { return false; }
  if (!sbp_pack_float(ctx, &msg->af2)) { return false; }
  if (!sbp_pack_sbp_gps_time_sec_t(ctx, &msg->toc)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->iode)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->iodc)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_bds_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_bds_t *msg)
{
  if (!sbp_unpack_sbp_ephemeris_common_content_t(ctx, &msg->common)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->tgd1)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->tgd2)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->c_rs)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->c_rc)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->c_uc)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->c_us)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->c_ic)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->c_is)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->dn)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->m0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->ecc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->sqrta)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->omega0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->omegadot)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->w)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->inc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->inc_dot)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->af0)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->af1)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->af2)) { return false; }
  if (!sbp_unpack_sbp_gps_time_sec_t(ctx, &msg->toc)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->iode)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->iodc)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_gal_dep_a_t(const sbp_msg_ephemeris_gal_dep_a_t *msg) {
  size_t packed_size = 0;
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

static inline bool sbp_pack_sbp_msg_ephemeris_gal_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_gal_dep_a_t *msg)
{
  if (!sbp_pack_sbp_ephemeris_common_content_t(ctx, &msg->common)) { return false; }
  if (!sbp_pack_float(ctx, &msg->bgd_e1e5a)) { return false; }
  if (!sbp_pack_float(ctx, &msg->bgd_e1e5b)) { return false; }
  if (!sbp_pack_float(ctx, &msg->c_rs)) { return false; }
  if (!sbp_pack_float(ctx, &msg->c_rc)) { return false; }
  if (!sbp_pack_float(ctx, &msg->c_uc)) { return false; }
  if (!sbp_pack_float(ctx, &msg->c_us)) { return false; }
  if (!sbp_pack_float(ctx, &msg->c_ic)) { return false; }
  if (!sbp_pack_float(ctx, &msg->c_is)) { return false; }
  if (!sbp_pack_double(ctx, &msg->dn)) { return false; }
  if (!sbp_pack_double(ctx, &msg->m0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->ecc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->sqrta)) { return false; }
  if (!sbp_pack_double(ctx, &msg->omega0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->omegadot)) { return false; }
  if (!sbp_pack_double(ctx, &msg->w)) { return false; }
  if (!sbp_pack_double(ctx, &msg->inc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->inc_dot)) { return false; }
  if (!sbp_pack_double(ctx, &msg->af0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->af1)) { return false; }
  if (!sbp_pack_float(ctx, &msg->af2)) { return false; }
  if (!sbp_pack_sbp_gps_time_sec_t(ctx, &msg->toc)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->iode)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->iodc)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_gal_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_gal_dep_a_t *msg)
{
  if (!sbp_unpack_sbp_ephemeris_common_content_t(ctx, &msg->common)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->bgd_e1e5a)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->bgd_e1e5b)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->c_rs)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->c_rc)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->c_uc)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->c_us)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->c_ic)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->c_is)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->dn)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->m0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->ecc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->sqrta)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->omega0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->omegadot)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->w)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->inc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->inc_dot)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->af0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->af1)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->af2)) { return false; }
  if (!sbp_unpack_sbp_gps_time_sec_t(ctx, &msg->toc)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->iode)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->iodc)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_gal_t(const sbp_msg_ephemeris_gal_t *msg) {
  size_t packed_size = 0;
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

static inline bool sbp_pack_sbp_msg_ephemeris_gal_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_gal_t *msg)
{
  if (!sbp_pack_sbp_ephemeris_common_content_t(ctx, &msg->common)) { return false; }
  if (!sbp_pack_float(ctx, &msg->bgd_e1e5a)) { return false; }
  if (!sbp_pack_float(ctx, &msg->bgd_e1e5b)) { return false; }
  if (!sbp_pack_float(ctx, &msg->c_rs)) { return false; }
  if (!sbp_pack_float(ctx, &msg->c_rc)) { return false; }
  if (!sbp_pack_float(ctx, &msg->c_uc)) { return false; }
  if (!sbp_pack_float(ctx, &msg->c_us)) { return false; }
  if (!sbp_pack_float(ctx, &msg->c_ic)) { return false; }
  if (!sbp_pack_float(ctx, &msg->c_is)) { return false; }
  if (!sbp_pack_double(ctx, &msg->dn)) { return false; }
  if (!sbp_pack_double(ctx, &msg->m0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->ecc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->sqrta)) { return false; }
  if (!sbp_pack_double(ctx, &msg->omega0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->omegadot)) { return false; }
  if (!sbp_pack_double(ctx, &msg->w)) { return false; }
  if (!sbp_pack_double(ctx, &msg->inc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->inc_dot)) { return false; }
  if (!sbp_pack_double(ctx, &msg->af0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->af1)) { return false; }
  if (!sbp_pack_float(ctx, &msg->af2)) { return false; }
  if (!sbp_pack_sbp_gps_time_sec_t(ctx, &msg->toc)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->iode)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->iodc)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->source)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_gal_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_gal_t *msg)
{
  if (!sbp_unpack_sbp_ephemeris_common_content_t(ctx, &msg->common)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->bgd_e1e5a)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->bgd_e1e5b)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->c_rs)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->c_rc)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->c_uc)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->c_us)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->c_ic)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->c_is)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->dn)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->m0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->ecc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->sqrta)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->omega0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->omegadot)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->w)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->inc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->inc_dot)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->af0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->af1)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->af2)) { return false; }
  if (!sbp_unpack_sbp_gps_time_sec_t(ctx, &msg->toc)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->iode)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->iodc)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->source)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_sbas_dep_a_t(const sbp_msg_ephemeris_sbas_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_ephemeris_common_content_dep_a_t(&msg->common);
  packed_size += ( 3 * sbp_packed_size_double(&msg->pos[0]));
  packed_size += ( 3 * sbp_packed_size_double(&msg->vel[0]));
  packed_size += ( 3 * sbp_packed_size_double(&msg->acc[0]));
  packed_size += sbp_packed_size_double(&msg->a_gf0);
  packed_size += sbp_packed_size_double(&msg->a_gf1);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ephemeris_sbas_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_sbas_dep_a_t *msg)
{
  if (!sbp_pack_sbp_ephemeris_common_content_dep_a_t(ctx, &msg->common)) { return false; }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!sbp_pack_double(ctx, &msg->pos[i])) { return false; }
  }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!sbp_pack_double(ctx, &msg->vel[i])) { return false; }
  }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!sbp_pack_double(ctx, &msg->acc[i])) { return false; }
  }
  if (!sbp_pack_double(ctx, &msg->a_gf0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->a_gf1)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_sbas_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_sbas_dep_a_t *msg)
{
  if (!sbp_unpack_sbp_ephemeris_common_content_dep_a_t(ctx, &msg->common)) { return false; }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_unpack_double(ctx, &msg->pos[i])) { return false; }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_unpack_double(ctx, &msg->vel[i])) { return false; }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_unpack_double(ctx, &msg->acc[i])) { return false; }
  }
  if (!sbp_unpack_double(ctx, &msg->a_gf0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->a_gf1)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_glo_dep_a_t(const sbp_msg_ephemeris_glo_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_ephemeris_common_content_dep_a_t(&msg->common);
  packed_size += sbp_packed_size_double(&msg->gamma);
  packed_size += sbp_packed_size_double(&msg->tau);
  packed_size += ( 3 * sbp_packed_size_double(&msg->pos[0]));
  packed_size += ( 3 * sbp_packed_size_double(&msg->vel[0]));
  packed_size += ( 3 * sbp_packed_size_double(&msg->acc[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ephemeris_glo_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_glo_dep_a_t *msg)
{
  if (!sbp_pack_sbp_ephemeris_common_content_dep_a_t(ctx, &msg->common)) { return false; }
  if (!sbp_pack_double(ctx, &msg->gamma)) { return false; }
  if (!sbp_pack_double(ctx, &msg->tau)) { return false; }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!sbp_pack_double(ctx, &msg->pos[i])) { return false; }
  }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!sbp_pack_double(ctx, &msg->vel[i])) { return false; }
  }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!sbp_pack_double(ctx, &msg->acc[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_glo_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_glo_dep_a_t *msg)
{
  if (!sbp_unpack_sbp_ephemeris_common_content_dep_a_t(ctx, &msg->common)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->gamma)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->tau)) { return false; }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_unpack_double(ctx, &msg->pos[i])) { return false; }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_unpack_double(ctx, &msg->vel[i])) { return false; }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_unpack_double(ctx, &msg->acc[i])) { return false; }
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_sbas_dep_b_t(const sbp_msg_ephemeris_sbas_dep_b_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_ephemeris_common_content_dep_b_t(&msg->common);
  packed_size += ( 3 * sbp_packed_size_double(&msg->pos[0]));
  packed_size += ( 3 * sbp_packed_size_double(&msg->vel[0]));
  packed_size += ( 3 * sbp_packed_size_double(&msg->acc[0]));
  packed_size += sbp_packed_size_double(&msg->a_gf0);
  packed_size += sbp_packed_size_double(&msg->a_gf1);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ephemeris_sbas_dep_b_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_sbas_dep_b_t *msg)
{
  if (!sbp_pack_sbp_ephemeris_common_content_dep_b_t(ctx, &msg->common)) { return false; }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!sbp_pack_double(ctx, &msg->pos[i])) { return false; }
  }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!sbp_pack_double(ctx, &msg->vel[i])) { return false; }
  }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!sbp_pack_double(ctx, &msg->acc[i])) { return false; }
  }
  if (!sbp_pack_double(ctx, &msg->a_gf0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->a_gf1)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_sbas_dep_b_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_sbas_dep_b_t *msg)
{
  if (!sbp_unpack_sbp_ephemeris_common_content_dep_b_t(ctx, &msg->common)) { return false; }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_unpack_double(ctx, &msg->pos[i])) { return false; }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_unpack_double(ctx, &msg->vel[i])) { return false; }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_unpack_double(ctx, &msg->acc[i])) { return false; }
  }
  if (!sbp_unpack_double(ctx, &msg->a_gf0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->a_gf1)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_sbas_t(const sbp_msg_ephemeris_sbas_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_ephemeris_common_content_t(&msg->common);
  packed_size += ( 3 * sbp_packed_size_double(&msg->pos[0]));
  packed_size += ( 3 * sbp_packed_size_float(&msg->vel[0]));
  packed_size += ( 3 * sbp_packed_size_float(&msg->acc[0]));
  packed_size += sbp_packed_size_float(&msg->a_gf0);
  packed_size += sbp_packed_size_float(&msg->a_gf1);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ephemeris_sbas_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_sbas_t *msg)
{
  if (!sbp_pack_sbp_ephemeris_common_content_t(ctx, &msg->common)) { return false; }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!sbp_pack_double(ctx, &msg->pos[i])) { return false; }
  }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!sbp_pack_float(ctx, &msg->vel[i])) { return false; }
  }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!sbp_pack_float(ctx, &msg->acc[i])) { return false; }
  }
  if (!sbp_pack_float(ctx, &msg->a_gf0)) { return false; }
  if (!sbp_pack_float(ctx, &msg->a_gf1)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_sbas_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_sbas_t *msg)
{
  if (!sbp_unpack_sbp_ephemeris_common_content_t(ctx, &msg->common)) { return false; }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_unpack_double(ctx, &msg->pos[i])) { return false; }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_unpack_float(ctx, &msg->vel[i])) { return false; }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_unpack_float(ctx, &msg->acc[i])) { return false; }
  }
  if (!sbp_unpack_float(ctx, &msg->a_gf0)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->a_gf1)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_glo_dep_b_t(const sbp_msg_ephemeris_glo_dep_b_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_ephemeris_common_content_dep_b_t(&msg->common);
  packed_size += sbp_packed_size_double(&msg->gamma);
  packed_size += sbp_packed_size_double(&msg->tau);
  packed_size += ( 3 * sbp_packed_size_double(&msg->pos[0]));
  packed_size += ( 3 * sbp_packed_size_double(&msg->vel[0]));
  packed_size += ( 3 * sbp_packed_size_double(&msg->acc[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ephemeris_glo_dep_b_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_glo_dep_b_t *msg)
{
  if (!sbp_pack_sbp_ephemeris_common_content_dep_b_t(ctx, &msg->common)) { return false; }
  if (!sbp_pack_double(ctx, &msg->gamma)) { return false; }
  if (!sbp_pack_double(ctx, &msg->tau)) { return false; }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!sbp_pack_double(ctx, &msg->pos[i])) { return false; }
  }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!sbp_pack_double(ctx, &msg->vel[i])) { return false; }
  }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!sbp_pack_double(ctx, &msg->acc[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_glo_dep_b_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_glo_dep_b_t *msg)
{
  if (!sbp_unpack_sbp_ephemeris_common_content_dep_b_t(ctx, &msg->common)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->gamma)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->tau)) { return false; }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_unpack_double(ctx, &msg->pos[i])) { return false; }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_unpack_double(ctx, &msg->vel[i])) { return false; }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_unpack_double(ctx, &msg->acc[i])) { return false; }
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_glo_dep_c_t(const sbp_msg_ephemeris_glo_dep_c_t *msg) {
  size_t packed_size = 0;
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

static inline bool sbp_pack_sbp_msg_ephemeris_glo_dep_c_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_glo_dep_c_t *msg)
{
  if (!sbp_pack_sbp_ephemeris_common_content_dep_b_t(ctx, &msg->common)) { return false; }
  if (!sbp_pack_double(ctx, &msg->gamma)) { return false; }
  if (!sbp_pack_double(ctx, &msg->tau)) { return false; }
  if (!sbp_pack_double(ctx, &msg->d_tau)) { return false; }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!sbp_pack_double(ctx, &msg->pos[i])) { return false; }
  }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!sbp_pack_double(ctx, &msg->vel[i])) { return false; }
  }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!sbp_pack_double(ctx, &msg->acc[i])) { return false; }
  }
  if (!sbp_pack_u8(ctx, &msg->fcn)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_glo_dep_c_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_glo_dep_c_t *msg)
{
  if (!sbp_unpack_sbp_ephemeris_common_content_dep_b_t(ctx, &msg->common)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->gamma)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->tau)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->d_tau)) { return false; }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_unpack_double(ctx, &msg->pos[i])) { return false; }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_unpack_double(ctx, &msg->vel[i])) { return false; }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_unpack_double(ctx, &msg->acc[i])) { return false; }
  }
  if (!sbp_unpack_u8(ctx, &msg->fcn)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_glo_dep_d_t(const sbp_msg_ephemeris_glo_dep_d_t *msg) {
  size_t packed_size = 0;
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

static inline bool sbp_pack_sbp_msg_ephemeris_glo_dep_d_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_glo_dep_d_t *msg)
{
  if (!sbp_pack_sbp_ephemeris_common_content_dep_b_t(ctx, &msg->common)) { return false; }
  if (!sbp_pack_double(ctx, &msg->gamma)) { return false; }
  if (!sbp_pack_double(ctx, &msg->tau)) { return false; }
  if (!sbp_pack_double(ctx, &msg->d_tau)) { return false; }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!sbp_pack_double(ctx, &msg->pos[i])) { return false; }
  }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!sbp_pack_double(ctx, &msg->vel[i])) { return false; }
  }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!sbp_pack_double(ctx, &msg->acc[i])) { return false; }
  }
  if (!sbp_pack_u8(ctx, &msg->fcn)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->iod)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_glo_dep_d_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_glo_dep_d_t *msg)
{
  if (!sbp_unpack_sbp_ephemeris_common_content_dep_b_t(ctx, &msg->common)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->gamma)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->tau)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->d_tau)) { return false; }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_unpack_double(ctx, &msg->pos[i])) { return false; }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_unpack_double(ctx, &msg->vel[i])) { return false; }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_unpack_double(ctx, &msg->acc[i])) { return false; }
  }
  if (!sbp_unpack_u8(ctx, &msg->fcn)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->iod)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_glo_t(const sbp_msg_ephemeris_glo_t *msg) {
  size_t packed_size = 0;
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

static inline bool sbp_pack_sbp_msg_ephemeris_glo_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_glo_t *msg)
{
  if (!sbp_pack_sbp_ephemeris_common_content_t(ctx, &msg->common)) { return false; }
  if (!sbp_pack_float(ctx, &msg->gamma)) { return false; }
  if (!sbp_pack_float(ctx, &msg->tau)) { return false; }
  if (!sbp_pack_float(ctx, &msg->d_tau)) { return false; }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!sbp_pack_double(ctx, &msg->pos[i])) { return false; }
  }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!sbp_pack_double(ctx, &msg->vel[i])) { return false; }
  }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!sbp_pack_float(ctx, &msg->acc[i])) { return false; }
  }
  if (!sbp_pack_u8(ctx, &msg->fcn)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->iod)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_glo_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_glo_t *msg)
{
  if (!sbp_unpack_sbp_ephemeris_common_content_t(ctx, &msg->common)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->gamma)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->tau)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->d_tau)) { return false; }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_unpack_double(ctx, &msg->pos[i])) { return false; }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_unpack_double(ctx, &msg->vel[i])) { return false; }
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_unpack_float(ctx, &msg->acc[i])) { return false; }
  }
  if (!sbp_unpack_u8(ctx, &msg->fcn)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->iod)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_dep_d_t(const sbp_msg_ephemeris_dep_d_t *msg) {
  size_t packed_size = 0;
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

static inline bool sbp_pack_sbp_msg_ephemeris_dep_d_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_dep_d_t *msg)
{
  if (!sbp_pack_double(ctx, &msg->tgd)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_rs)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_rc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_uc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_us)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_ic)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_is)) { return false; }
  if (!sbp_pack_double(ctx, &msg->dn)) { return false; }
  if (!sbp_pack_double(ctx, &msg->m0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->ecc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->sqrta)) { return false; }
  if (!sbp_pack_double(ctx, &msg->omega0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->omegadot)) { return false; }
  if (!sbp_pack_double(ctx, &msg->w)) { return false; }
  if (!sbp_pack_double(ctx, &msg->inc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->inc_dot)) { return false; }
  if (!sbp_pack_double(ctx, &msg->af0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->af1)) { return false; }
  if (!sbp_pack_double(ctx, &msg->af2)) { return false; }
  if (!sbp_pack_double(ctx, &msg->toe_tow)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->toe_wn)) { return false; }
  if (!sbp_pack_double(ctx, &msg->toc_tow)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->toc_wn)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->valid)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->healthy)) { return false; }
  if (!sbp_pack_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->iode)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->iodc)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->reserved)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_dep_d_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_dep_d_t *msg)
{
  if (!sbp_unpack_double(ctx, &msg->tgd)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_rs)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_rc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_uc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_us)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_ic)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_is)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->dn)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->m0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->ecc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->sqrta)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->omega0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->omegadot)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->w)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->inc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->inc_dot)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->af0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->af1)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->af2)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->toe_tow)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->toe_wn)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->toc_tow)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->toc_wn)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->valid)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->healthy)) { return false; }
  if (!sbp_unpack_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->iode)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->iodc)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->reserved)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_dep_a_t(const sbp_msg_ephemeris_dep_a_t *msg) {
  size_t packed_size = 0;
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

static inline bool sbp_pack_sbp_msg_ephemeris_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_dep_a_t *msg)
{
  if (!sbp_pack_double(ctx, &msg->tgd)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_rs)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_rc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_uc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_us)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_ic)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_is)) { return false; }
  if (!sbp_pack_double(ctx, &msg->dn)) { return false; }
  if (!sbp_pack_double(ctx, &msg->m0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->ecc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->sqrta)) { return false; }
  if (!sbp_pack_double(ctx, &msg->omega0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->omegadot)) { return false; }
  if (!sbp_pack_double(ctx, &msg->w)) { return false; }
  if (!sbp_pack_double(ctx, &msg->inc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->inc_dot)) { return false; }
  if (!sbp_pack_double(ctx, &msg->af0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->af1)) { return false; }
  if (!sbp_pack_double(ctx, &msg->af2)) { return false; }
  if (!sbp_pack_double(ctx, &msg->toe_tow)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->toe_wn)) { return false; }
  if (!sbp_pack_double(ctx, &msg->toc_tow)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->toc_wn)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->valid)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->healthy)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->prn)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_dep_a_t *msg)
{
  if (!sbp_unpack_double(ctx, &msg->tgd)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_rs)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_rc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_uc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_us)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_ic)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_is)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->dn)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->m0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->ecc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->sqrta)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->omega0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->omegadot)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->w)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->inc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->inc_dot)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->af0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->af1)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->af2)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->toe_tow)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->toe_wn)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->toc_tow)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->toc_wn)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->valid)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->healthy)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->prn)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_dep_b_t(const sbp_msg_ephemeris_dep_b_t *msg) {
  size_t packed_size = 0;
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

static inline bool sbp_pack_sbp_msg_ephemeris_dep_b_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_dep_b_t *msg)
{
  if (!sbp_pack_double(ctx, &msg->tgd)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_rs)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_rc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_uc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_us)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_ic)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_is)) { return false; }
  if (!sbp_pack_double(ctx, &msg->dn)) { return false; }
  if (!sbp_pack_double(ctx, &msg->m0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->ecc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->sqrta)) { return false; }
  if (!sbp_pack_double(ctx, &msg->omega0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->omegadot)) { return false; }
  if (!sbp_pack_double(ctx, &msg->w)) { return false; }
  if (!sbp_pack_double(ctx, &msg->inc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->inc_dot)) { return false; }
  if (!sbp_pack_double(ctx, &msg->af0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->af1)) { return false; }
  if (!sbp_pack_double(ctx, &msg->af2)) { return false; }
  if (!sbp_pack_double(ctx, &msg->toe_tow)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->toe_wn)) { return false; }
  if (!sbp_pack_double(ctx, &msg->toc_tow)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->toc_wn)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->valid)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->healthy)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->prn)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->iode)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_dep_b_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_dep_b_t *msg)
{
  if (!sbp_unpack_double(ctx, &msg->tgd)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_rs)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_rc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_uc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_us)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_ic)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_is)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->dn)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->m0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->ecc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->sqrta)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->omega0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->omegadot)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->w)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->inc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->inc_dot)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->af0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->af1)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->af2)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->toe_tow)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->toe_wn)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->toc_tow)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->toc_wn)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->valid)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->healthy)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->prn)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->iode)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ephemeris_dep_c_t(const sbp_msg_ephemeris_dep_c_t *msg) {
  size_t packed_size = 0;
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

static inline bool sbp_pack_sbp_msg_ephemeris_dep_c_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_dep_c_t *msg)
{
  if (!sbp_pack_double(ctx, &msg->tgd)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_rs)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_rc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_uc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_us)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_ic)) { return false; }
  if (!sbp_pack_double(ctx, &msg->c_is)) { return false; }
  if (!sbp_pack_double(ctx, &msg->dn)) { return false; }
  if (!sbp_pack_double(ctx, &msg->m0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->ecc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->sqrta)) { return false; }
  if (!sbp_pack_double(ctx, &msg->omega0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->omegadot)) { return false; }
  if (!sbp_pack_double(ctx, &msg->w)) { return false; }
  if (!sbp_pack_double(ctx, &msg->inc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->inc_dot)) { return false; }
  if (!sbp_pack_double(ctx, &msg->af0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->af1)) { return false; }
  if (!sbp_pack_double(ctx, &msg->af2)) { return false; }
  if (!sbp_pack_double(ctx, &msg->toe_tow)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->toe_wn)) { return false; }
  if (!sbp_pack_double(ctx, &msg->toc_tow)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->toc_wn)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->valid)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->healthy)) { return false; }
  if (!sbp_pack_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->iode)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->iodc)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->reserved)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_dep_c_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_dep_c_t *msg)
{
  if (!sbp_unpack_double(ctx, &msg->tgd)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_rs)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_rc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_uc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_us)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_ic)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->c_is)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->dn)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->m0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->ecc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->sqrta)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->omega0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->omegadot)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->w)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->inc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->inc_dot)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->af0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->af1)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->af2)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->toe_tow)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->toe_wn)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->toc_tow)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->toc_wn)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->valid)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->healthy)) { return false; }
  if (!sbp_unpack_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->iode)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->iodc)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->reserved)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_observation_header_dep_t(const sbp_observation_header_dep_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_gps_time_dep_t(&msg->t);
  packed_size += sbp_packed_size_u8(&msg->n_obs);
  return packed_size;
}

static inline bool sbp_pack_sbp_observation_header_dep_t(sbp_pack_ctx_t *ctx, const sbp_observation_header_dep_t *msg)
{
  if (!sbp_pack_sbp_gps_time_dep_t(ctx, &msg->t)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->n_obs)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_observation_header_dep_t(sbp_unpack_ctx_t *ctx, sbp_observation_header_dep_t *msg)
{
  if (!sbp_unpack_sbp_gps_time_dep_t(ctx, &msg->t)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->n_obs)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_carrier_phase_dep_a_t(const sbp_carrier_phase_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_s32(&msg->i);
  packed_size += sbp_packed_size_u8(&msg->f);
  return packed_size;
}

static inline bool sbp_pack_sbp_carrier_phase_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_carrier_phase_dep_a_t *msg)
{
  if (!sbp_pack_s32(ctx, &msg->i)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->f)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_carrier_phase_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_carrier_phase_dep_a_t *msg)
{
  if (!sbp_unpack_s32(ctx, &msg->i)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->f)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_packed_obs_content_dep_a_t(const sbp_packed_obs_content_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->P);
  packed_size += sbp_packed_size_sbp_carrier_phase_dep_a_t(&msg->L);
  packed_size += sbp_packed_size_u8(&msg->cn0);
  packed_size += sbp_packed_size_u16(&msg->lock);
  packed_size += sbp_packed_size_u8(&msg->prn);
  return packed_size;
}

static inline bool sbp_pack_sbp_packed_obs_content_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_packed_obs_content_dep_a_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->P)) { return false; }
  if (!sbp_pack_sbp_carrier_phase_dep_a_t(ctx, &msg->L)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->cn0)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->lock)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->prn)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_packed_obs_content_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_packed_obs_content_dep_a_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->P)) { return false; }
  if (!sbp_unpack_sbp_carrier_phase_dep_a_t(ctx, &msg->L)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->cn0)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->lock)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->prn)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_packed_obs_content_dep_b_t(const sbp_packed_obs_content_dep_b_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->P);
  packed_size += sbp_packed_size_sbp_carrier_phase_dep_a_t(&msg->L);
  packed_size += sbp_packed_size_u8(&msg->cn0);
  packed_size += sbp_packed_size_u16(&msg->lock);
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  return packed_size;
}

static inline bool sbp_pack_sbp_packed_obs_content_dep_b_t(sbp_pack_ctx_t *ctx, const sbp_packed_obs_content_dep_b_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->P)) { return false; }
  if (!sbp_pack_sbp_carrier_phase_dep_a_t(ctx, &msg->L)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->cn0)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->lock)) { return false; }
  if (!sbp_pack_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_packed_obs_content_dep_b_t(sbp_unpack_ctx_t *ctx, sbp_packed_obs_content_dep_b_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->P)) { return false; }
  if (!sbp_unpack_sbp_carrier_phase_dep_a_t(ctx, &msg->L)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->cn0)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->lock)) { return false; }
  if (!sbp_unpack_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_packed_obs_content_dep_c_t(const sbp_packed_obs_content_dep_c_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->P);
  packed_size += sbp_packed_size_sbp_carrier_phase_t(&msg->L);
  packed_size += sbp_packed_size_u8(&msg->cn0);
  packed_size += sbp_packed_size_u16(&msg->lock);
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  return packed_size;
}

static inline bool sbp_pack_sbp_packed_obs_content_dep_c_t(sbp_pack_ctx_t *ctx, const sbp_packed_obs_content_dep_c_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->P)) { return false; }
  if (!sbp_pack_sbp_carrier_phase_t(ctx, &msg->L)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->cn0)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->lock)) { return false; }
  if (!sbp_pack_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_packed_obs_content_dep_c_t(sbp_unpack_ctx_t *ctx, sbp_packed_obs_content_dep_c_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->P)) { return false; }
  if (!sbp_unpack_sbp_carrier_phase_t(ctx, &msg->L)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->cn0)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->lock)) { return false; }
  if (!sbp_unpack_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_obs_dep_a_t(const sbp_msg_obs_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_observation_header_dep_t(&msg->header);
  packed_size += (msg->n_obs * sbp_packed_size_sbp_packed_obs_content_dep_a_t(&msg->obs[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_obs_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_obs_dep_a_t *msg)
{
  if (!sbp_pack_sbp_observation_header_dep_t(ctx, &msg->header)) { return false; }
  for (uint8_t i = 0; i < msg->n_obs; i++)
  {
    if (!sbp_pack_sbp_packed_obs_content_dep_a_t(ctx, &msg->obs[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_obs_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_obs_dep_a_t *msg)
{
  if (!sbp_unpack_sbp_observation_header_dep_t(ctx, &msg->header)) { return false; }
    msg->n_obs = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_packed_obs_content_dep_a_t(&msg->obs[0]));
  for (uint8_t i = 0; i < msg->n_obs; i++) {
    if (!sbp_unpack_sbp_packed_obs_content_dep_a_t(ctx, &msg->obs[i])) { return false; }
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_obs_dep_b_t(const sbp_msg_obs_dep_b_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_observation_header_dep_t(&msg->header);
  packed_size += (msg->n_obs * sbp_packed_size_sbp_packed_obs_content_dep_b_t(&msg->obs[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_obs_dep_b_t(sbp_pack_ctx_t *ctx, const sbp_msg_obs_dep_b_t *msg)
{
  if (!sbp_pack_sbp_observation_header_dep_t(ctx, &msg->header)) { return false; }
  for (uint8_t i = 0; i < msg->n_obs; i++)
  {
    if (!sbp_pack_sbp_packed_obs_content_dep_b_t(ctx, &msg->obs[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_obs_dep_b_t(sbp_unpack_ctx_t *ctx, sbp_msg_obs_dep_b_t *msg)
{
  if (!sbp_unpack_sbp_observation_header_dep_t(ctx, &msg->header)) { return false; }
    msg->n_obs = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_packed_obs_content_dep_b_t(&msg->obs[0]));
  for (uint8_t i = 0; i < msg->n_obs; i++) {
    if (!sbp_unpack_sbp_packed_obs_content_dep_b_t(ctx, &msg->obs[i])) { return false; }
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_obs_dep_c_t(const sbp_msg_obs_dep_c_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_observation_header_dep_t(&msg->header);
  packed_size += (msg->n_obs * sbp_packed_size_sbp_packed_obs_content_dep_c_t(&msg->obs[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_obs_dep_c_t(sbp_pack_ctx_t *ctx, const sbp_msg_obs_dep_c_t *msg)
{
  if (!sbp_pack_sbp_observation_header_dep_t(ctx, &msg->header)) { return false; }
  for (uint8_t i = 0; i < msg->n_obs; i++)
  {
    if (!sbp_pack_sbp_packed_obs_content_dep_c_t(ctx, &msg->obs[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_obs_dep_c_t(sbp_unpack_ctx_t *ctx, sbp_msg_obs_dep_c_t *msg)
{
  if (!sbp_unpack_sbp_observation_header_dep_t(ctx, &msg->header)) { return false; }
    msg->n_obs = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_packed_obs_content_dep_c_t(&msg->obs[0]));
  for (uint8_t i = 0; i < msg->n_obs; i++) {
    if (!sbp_unpack_sbp_packed_obs_content_dep_c_t(ctx, &msg->obs[i])) { return false; }
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_iono_t(const sbp_msg_iono_t *msg) {
  size_t packed_size = 0;
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

static inline bool sbp_pack_sbp_msg_iono_t(sbp_pack_ctx_t *ctx, const sbp_msg_iono_t *msg)
{
  if (!sbp_pack_sbp_gps_time_sec_t(ctx, &msg->t_nmct)) { return false; }
  if (!sbp_pack_double(ctx, &msg->a0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->a1)) { return false; }
  if (!sbp_pack_double(ctx, &msg->a2)) { return false; }
  if (!sbp_pack_double(ctx, &msg->a3)) { return false; }
  if (!sbp_pack_double(ctx, &msg->b0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->b1)) { return false; }
  if (!sbp_pack_double(ctx, &msg->b2)) { return false; }
  if (!sbp_pack_double(ctx, &msg->b3)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_iono_t(sbp_unpack_ctx_t *ctx, sbp_msg_iono_t *msg)
{
  if (!sbp_unpack_sbp_gps_time_sec_t(ctx, &msg->t_nmct)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->a0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->a1)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->a2)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->a3)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->b0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->b1)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->b2)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->b3)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_sv_configuration_gps_dep_t(const sbp_msg_sv_configuration_gps_dep_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->t_nmct);
  packed_size += sbp_packed_size_u32(&msg->l2c_mask);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_sv_configuration_gps_dep_t(sbp_pack_ctx_t *ctx, const sbp_msg_sv_configuration_gps_dep_t *msg)
{
  if (!sbp_pack_sbp_gps_time_sec_t(ctx, &msg->t_nmct)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->l2c_mask)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_sv_configuration_gps_dep_t(sbp_unpack_ctx_t *ctx, sbp_msg_sv_configuration_gps_dep_t *msg)
{
  if (!sbp_unpack_sbp_gps_time_sec_t(ctx, &msg->t_nmct)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->l2c_mask)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_gnss_capb_t(const sbp_gnss_capb_t *msg) {
  size_t packed_size = 0;
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

static inline bool sbp_pack_sbp_gnss_capb_t(sbp_pack_ctx_t *ctx, const sbp_gnss_capb_t *msg)
{
  if (!sbp_pack_u64(ctx, &msg->gps_active)) { return false; }
  if (!sbp_pack_u64(ctx, &msg->gps_l2c)) { return false; }
  if (!sbp_pack_u64(ctx, &msg->gps_l5)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->glo_active)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->glo_l2of)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->glo_l3)) { return false; }
  if (!sbp_pack_u64(ctx, &msg->sbas_active)) { return false; }
  if (!sbp_pack_u64(ctx, &msg->sbas_l5)) { return false; }
  if (!sbp_pack_u64(ctx, &msg->bds_active)) { return false; }
  if (!sbp_pack_u64(ctx, &msg->bds_d2nav)) { return false; }
  if (!sbp_pack_u64(ctx, &msg->bds_b2)) { return false; }
  if (!sbp_pack_u64(ctx, &msg->bds_b2a)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->qzss_active)) { return false; }
  if (!sbp_pack_u64(ctx, &msg->gal_active)) { return false; }
  if (!sbp_pack_u64(ctx, &msg->gal_e5)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_gnss_capb_t(sbp_unpack_ctx_t *ctx, sbp_gnss_capb_t *msg)
{
  if (!sbp_unpack_u64(ctx, &msg->gps_active)) { return false; }
  if (!sbp_unpack_u64(ctx, &msg->gps_l2c)) { return false; }
  if (!sbp_unpack_u64(ctx, &msg->gps_l5)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->glo_active)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->glo_l2of)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->glo_l3)) { return false; }
  if (!sbp_unpack_u64(ctx, &msg->sbas_active)) { return false; }
  if (!sbp_unpack_u64(ctx, &msg->sbas_l5)) { return false; }
  if (!sbp_unpack_u64(ctx, &msg->bds_active)) { return false; }
  if (!sbp_unpack_u64(ctx, &msg->bds_d2nav)) { return false; }
  if (!sbp_unpack_u64(ctx, &msg->bds_b2)) { return false; }
  if (!sbp_unpack_u64(ctx, &msg->bds_b2a)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->qzss_active)) { return false; }
  if (!sbp_unpack_u64(ctx, &msg->gal_active)) { return false; }
  if (!sbp_unpack_u64(ctx, &msg->gal_e5)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_gnss_capb_t(const sbp_msg_gnss_capb_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->t_nmct);
  packed_size += sbp_packed_size_sbp_gnss_capb_t(&msg->gc);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_gnss_capb_t(sbp_pack_ctx_t *ctx, const sbp_msg_gnss_capb_t *msg)
{
  if (!sbp_pack_sbp_gps_time_sec_t(ctx, &msg->t_nmct)) { return false; }
  if (!sbp_pack_sbp_gnss_capb_t(ctx, &msg->gc)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_gnss_capb_t(sbp_unpack_ctx_t *ctx, sbp_msg_gnss_capb_t *msg)
{
  if (!sbp_unpack_sbp_gps_time_sec_t(ctx, &msg->t_nmct)) { return false; }
  if (!sbp_unpack_sbp_gnss_capb_t(ctx, &msg->gc)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_group_delay_dep_a_t(const sbp_msg_group_delay_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_gps_time_dep_t(&msg->t_op);
  packed_size += sbp_packed_size_u8(&msg->prn);
  packed_size += sbp_packed_size_u8(&msg->valid);
  packed_size += sbp_packed_size_s16(&msg->tgd);
  packed_size += sbp_packed_size_s16(&msg->isc_l1ca);
  packed_size += sbp_packed_size_s16(&msg->isc_l2c);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_group_delay_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_group_delay_dep_a_t *msg)
{
  if (!sbp_pack_sbp_gps_time_dep_t(ctx, &msg->t_op)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->prn)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->valid)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->tgd)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->isc_l1ca)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->isc_l2c)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_group_delay_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_group_delay_dep_a_t *msg)
{
  if (!sbp_unpack_sbp_gps_time_dep_t(ctx, &msg->t_op)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->prn)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->valid)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->tgd)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->isc_l1ca)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->isc_l2c)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_group_delay_dep_b_t(const sbp_msg_group_delay_dep_b_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->t_op);
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  packed_size += sbp_packed_size_u8(&msg->valid);
  packed_size += sbp_packed_size_s16(&msg->tgd);
  packed_size += sbp_packed_size_s16(&msg->isc_l1ca);
  packed_size += sbp_packed_size_s16(&msg->isc_l2c);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_group_delay_dep_b_t(sbp_pack_ctx_t *ctx, const sbp_msg_group_delay_dep_b_t *msg)
{
  if (!sbp_pack_sbp_gps_time_sec_t(ctx, &msg->t_op)) { return false; }
  if (!sbp_pack_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->valid)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->tgd)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->isc_l1ca)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->isc_l2c)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_group_delay_dep_b_t(sbp_unpack_ctx_t *ctx, sbp_msg_group_delay_dep_b_t *msg)
{
  if (!sbp_unpack_sbp_gps_time_sec_t(ctx, &msg->t_op)) { return false; }
  if (!sbp_unpack_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->valid)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->tgd)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->isc_l1ca)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->isc_l2c)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_group_delay_t(const sbp_msg_group_delay_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->t_op);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_u8(&msg->valid);
  packed_size += sbp_packed_size_s16(&msg->tgd);
  packed_size += sbp_packed_size_s16(&msg->isc_l1ca);
  packed_size += sbp_packed_size_s16(&msg->isc_l2c);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_group_delay_t(sbp_pack_ctx_t *ctx, const sbp_msg_group_delay_t *msg)
{
  if (!sbp_pack_sbp_gps_time_sec_t(ctx, &msg->t_op)) { return false; }
  if (!sbp_pack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->valid)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->tgd)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->isc_l1ca)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->isc_l2c)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_group_delay_t(sbp_unpack_ctx_t *ctx, sbp_msg_group_delay_t *msg)
{
  if (!sbp_unpack_sbp_gps_time_sec_t(ctx, &msg->t_op)) { return false; }
  if (!sbp_unpack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->valid)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->tgd)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->isc_l1ca)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->isc_l2c)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_almanac_common_content_t(const sbp_almanac_common_content_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->toa);
  packed_size += sbp_packed_size_double(&msg->ura);
  packed_size += sbp_packed_size_u32(&msg->fit_interval);
  packed_size += sbp_packed_size_u8(&msg->valid);
  packed_size += sbp_packed_size_u8(&msg->health_bits);
  return packed_size;
}

static inline bool sbp_pack_sbp_almanac_common_content_t(sbp_pack_ctx_t *ctx, const sbp_almanac_common_content_t *msg)
{
  if (!sbp_pack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!sbp_pack_sbp_gps_time_sec_t(ctx, &msg->toa)) { return false; }
  if (!sbp_pack_double(ctx, &msg->ura)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->fit_interval)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->valid)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->health_bits)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_almanac_common_content_t(sbp_unpack_ctx_t *ctx, sbp_almanac_common_content_t *msg)
{
  if (!sbp_unpack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!sbp_unpack_sbp_gps_time_sec_t(ctx, &msg->toa)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->ura)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->fit_interval)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->valid)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->health_bits)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_almanac_common_content_dep_t(const sbp_almanac_common_content_dep_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  packed_size += sbp_packed_size_sbp_gps_time_sec_t(&msg->toa);
  packed_size += sbp_packed_size_double(&msg->ura);
  packed_size += sbp_packed_size_u32(&msg->fit_interval);
  packed_size += sbp_packed_size_u8(&msg->valid);
  packed_size += sbp_packed_size_u8(&msg->health_bits);
  return packed_size;
}

static inline bool sbp_pack_sbp_almanac_common_content_dep_t(sbp_pack_ctx_t *ctx, const sbp_almanac_common_content_dep_t *msg)
{
  if (!sbp_pack_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  if (!sbp_pack_sbp_gps_time_sec_t(ctx, &msg->toa)) { return false; }
  if (!sbp_pack_double(ctx, &msg->ura)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->fit_interval)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->valid)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->health_bits)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_almanac_common_content_dep_t(sbp_unpack_ctx_t *ctx, sbp_almanac_common_content_dep_t *msg)
{
  if (!sbp_unpack_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  if (!sbp_unpack_sbp_gps_time_sec_t(ctx, &msg->toa)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->ura)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->fit_interval)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->valid)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->health_bits)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_almanac_gps_dep_t(const sbp_msg_almanac_gps_dep_t *msg) {
  size_t packed_size = 0;
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

static inline bool sbp_pack_sbp_msg_almanac_gps_dep_t(sbp_pack_ctx_t *ctx, const sbp_msg_almanac_gps_dep_t *msg)
{
  if (!sbp_pack_sbp_almanac_common_content_dep_t(ctx, &msg->common)) { return false; }
  if (!sbp_pack_double(ctx, &msg->m0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->ecc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->sqrta)) { return false; }
  if (!sbp_pack_double(ctx, &msg->omega0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->omegadot)) { return false; }
  if (!sbp_pack_double(ctx, &msg->w)) { return false; }
  if (!sbp_pack_double(ctx, &msg->inc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->af0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->af1)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_almanac_gps_dep_t(sbp_unpack_ctx_t *ctx, sbp_msg_almanac_gps_dep_t *msg)
{
  if (!sbp_unpack_sbp_almanac_common_content_dep_t(ctx, &msg->common)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->m0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->ecc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->sqrta)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->omega0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->omegadot)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->w)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->inc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->af0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->af1)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_almanac_gps_t(const sbp_msg_almanac_gps_t *msg) {
  size_t packed_size = 0;
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

static inline bool sbp_pack_sbp_msg_almanac_gps_t(sbp_pack_ctx_t *ctx, const sbp_msg_almanac_gps_t *msg)
{
  if (!sbp_pack_sbp_almanac_common_content_t(ctx, &msg->common)) { return false; }
  if (!sbp_pack_double(ctx, &msg->m0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->ecc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->sqrta)) { return false; }
  if (!sbp_pack_double(ctx, &msg->omega0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->omegadot)) { return false; }
  if (!sbp_pack_double(ctx, &msg->w)) { return false; }
  if (!sbp_pack_double(ctx, &msg->inc)) { return false; }
  if (!sbp_pack_double(ctx, &msg->af0)) { return false; }
  if (!sbp_pack_double(ctx, &msg->af1)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_almanac_gps_t(sbp_unpack_ctx_t *ctx, sbp_msg_almanac_gps_t *msg)
{
  if (!sbp_unpack_sbp_almanac_common_content_t(ctx, &msg->common)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->m0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->ecc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->sqrta)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->omega0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->omegadot)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->w)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->inc)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->af0)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->af1)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_almanac_glo_dep_t(const sbp_msg_almanac_glo_dep_t *msg) {
  size_t packed_size = 0;
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

static inline bool sbp_pack_sbp_msg_almanac_glo_dep_t(sbp_pack_ctx_t *ctx, const sbp_msg_almanac_glo_dep_t *msg)
{
  if (!sbp_pack_sbp_almanac_common_content_dep_t(ctx, &msg->common)) { return false; }
  if (!sbp_pack_double(ctx, &msg->lambda_na)) { return false; }
  if (!sbp_pack_double(ctx, &msg->t_lambda_na)) { return false; }
  if (!sbp_pack_double(ctx, &msg->i)) { return false; }
  if (!sbp_pack_double(ctx, &msg->t)) { return false; }
  if (!sbp_pack_double(ctx, &msg->t_dot)) { return false; }
  if (!sbp_pack_double(ctx, &msg->epsilon)) { return false; }
  if (!sbp_pack_double(ctx, &msg->omega)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_almanac_glo_dep_t(sbp_unpack_ctx_t *ctx, sbp_msg_almanac_glo_dep_t *msg)
{
  if (!sbp_unpack_sbp_almanac_common_content_dep_t(ctx, &msg->common)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->lambda_na)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->t_lambda_na)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->i)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->t)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->t_dot)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->epsilon)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->omega)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_almanac_glo_t(const sbp_msg_almanac_glo_t *msg) {
  size_t packed_size = 0;
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

static inline bool sbp_pack_sbp_msg_almanac_glo_t(sbp_pack_ctx_t *ctx, const sbp_msg_almanac_glo_t *msg)
{
  if (!sbp_pack_sbp_almanac_common_content_t(ctx, &msg->common)) { return false; }
  if (!sbp_pack_double(ctx, &msg->lambda_na)) { return false; }
  if (!sbp_pack_double(ctx, &msg->t_lambda_na)) { return false; }
  if (!sbp_pack_double(ctx, &msg->i)) { return false; }
  if (!sbp_pack_double(ctx, &msg->t)) { return false; }
  if (!sbp_pack_double(ctx, &msg->t_dot)) { return false; }
  if (!sbp_pack_double(ctx, &msg->epsilon)) { return false; }
  if (!sbp_pack_double(ctx, &msg->omega)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_almanac_glo_t(sbp_unpack_ctx_t *ctx, sbp_msg_almanac_glo_t *msg)
{
  if (!sbp_unpack_sbp_almanac_common_content_t(ctx, &msg->common)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->lambda_na)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->t_lambda_na)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->i)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->t)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->t_dot)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->epsilon)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->omega)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_glo_biases_t(const sbp_msg_glo_biases_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->mask);
  packed_size += sbp_packed_size_s16(&msg->l1ca_bias);
  packed_size += sbp_packed_size_s16(&msg->l1p_bias);
  packed_size += sbp_packed_size_s16(&msg->l2ca_bias);
  packed_size += sbp_packed_size_s16(&msg->l2p_bias);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_glo_biases_t(sbp_pack_ctx_t *ctx, const sbp_msg_glo_biases_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->mask)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->l1ca_bias)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->l1p_bias)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->l2ca_bias)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->l2p_bias)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_glo_biases_t(sbp_unpack_ctx_t *ctx, sbp_msg_glo_biases_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->mask)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->l1ca_bias)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->l1p_bias)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->l2ca_bias)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->l2p_bias)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_sv_az_el_t(const sbp_sv_az_el_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_u8(&msg->az);
  packed_size += sbp_packed_size_s8(&msg->el);
  return packed_size;
}

static inline bool sbp_pack_sbp_sv_az_el_t(sbp_pack_ctx_t *ctx, const sbp_sv_az_el_t *msg)
{
  if (!sbp_pack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->az)) { return false; }
  if (!sbp_pack_s8(ctx, &msg->el)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_sv_az_el_t(sbp_unpack_ctx_t *ctx, sbp_sv_az_el_t *msg)
{
  if (!sbp_unpack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->az)) { return false; }
  if (!sbp_unpack_s8(ctx, &msg->el)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_sv_az_el_t(const sbp_msg_sv_az_el_t *msg) {
  size_t packed_size = 0;
  packed_size += (msg->n_azel * sbp_packed_size_sbp_sv_az_el_t(&msg->azel[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_sv_az_el_t(sbp_pack_ctx_t *ctx, const sbp_msg_sv_az_el_t *msg)
{
  for (uint8_t i = 0; i < msg->n_azel; i++)
  {
    if (!sbp_pack_sbp_sv_az_el_t(ctx, &msg->azel[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_sv_az_el_t(sbp_unpack_ctx_t *ctx, sbp_msg_sv_az_el_t *msg)
{
    msg->n_azel = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_sv_az_el_t(&msg->azel[0]));
  for (uint8_t i = 0; i < msg->n_azel; i++) {
    if (!sbp_unpack_sbp_sv_az_el_t(ctx, &msg->azel[i])) { return false; }
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_osr_t(const sbp_msg_osr_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_observation_header_t(&msg->header);
  packed_size += (msg->n_obs * sbp_packed_size_sbp_packed_osr_content_t(&msg->obs[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_osr_t(sbp_pack_ctx_t *ctx, const sbp_msg_osr_t *msg)
{
  if (!sbp_pack_sbp_observation_header_t(ctx, &msg->header)) { return false; }
  for (uint8_t i = 0; i < msg->n_obs; i++)
  {
    if (!sbp_pack_sbp_packed_osr_content_t(ctx, &msg->obs[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_osr_t(sbp_unpack_ctx_t *ctx, sbp_msg_osr_t *msg)
{
  if (!sbp_unpack_sbp_observation_header_t(ctx, &msg->header)) { return false; }
    msg->n_obs = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_packed_osr_content_t(&msg->obs[0]));
  for (uint8_t i = 0; i < msg->n_obs; i++) {
    if (!sbp_unpack_sbp_packed_osr_content_t(ctx, &msg->obs[i])) { return false; }
  }
  return true;
}

#endif
