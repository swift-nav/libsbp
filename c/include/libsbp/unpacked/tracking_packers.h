#ifndef LIBSBP_TRACKING_PACKERS_H
#define LIBSBP_TRACKING_PACKERS_H

#ifndef LIBSBP_TRACKING_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/tracking.h instead"
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
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_tracking_state_detailed_dep_a_t(const sbp_msg_tracking_state_detailed_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u64(&msg->recv_time);
  packed_size += sbp_packed_size_sbp_sbp_gps_time_t(&msg->tot);
  packed_size += sbp_packed_size_u32(&msg->P);
  packed_size += sbp_packed_size_u16(&msg->P_std);
  packed_size += sbp_packed_size_sbp_carrier_phase_t(&msg->L);
  packed_size += sbp_packed_size_u8(&msg->cn0);
  packed_size += sbp_packed_size_u16(&msg->lock);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_s32(&msg->doppler);
  packed_size += sbp_packed_size_u16(&msg->doppler_std);
  packed_size += sbp_packed_size_u32(&msg->uptime);
  packed_size += sbp_packed_size_s16(&msg->clock_offset);
  packed_size += sbp_packed_size_s16(&msg->clock_drift);
  packed_size += sbp_packed_size_u16(&msg->corr_spacing);
  packed_size += sbp_packed_size_s8(&msg->acceleration);
  packed_size += sbp_packed_size_u8(&msg->sync_flags);
  packed_size += sbp_packed_size_u8(&msg->tow_flags);
  packed_size += sbp_packed_size_u8(&msg->track_flags);
  packed_size += sbp_packed_size_u8(&msg->nav_flags);
  packed_size += sbp_packed_size_u8(&msg->pset_flags);
  packed_size += sbp_packed_size_u8(&msg->misc_flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_tracking_state_detailed_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_tracking_state_detailed_dep_a_t *msg)
{
  if (!sbp_pack_u64(ctx, &msg->recv_time)) { return false; }
  if (!sbp_pack_sbp_sbp_gps_time_t(ctx, &msg->tot)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->P)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->P_std)) { return false; }
  if (!sbp_pack_sbp_carrier_phase_t(ctx, &msg->L)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->cn0)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->lock)) { return false; }
  if (!sbp_pack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->doppler)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->doppler_std)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->uptime)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->clock_offset)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->clock_drift)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->corr_spacing)) { return false; }
  if (!sbp_pack_s8(ctx, &msg->acceleration)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->sync_flags)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->tow_flags)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->track_flags)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->nav_flags)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->pset_flags)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->misc_flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_tracking_state_detailed_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_tracking_state_detailed_dep_a_t *msg)
{
  if (!sbp_unpack_u64(ctx, &msg->recv_time)) { return false; }
  if (!sbp_unpack_sbp_sbp_gps_time_t(ctx, &msg->tot)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->P)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->P_std)) { return false; }
  if (!sbp_unpack_sbp_carrier_phase_t(ctx, &msg->L)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->cn0)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->lock)) { return false; }
  if (!sbp_unpack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->doppler)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->doppler_std)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->uptime)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->clock_offset)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->clock_drift)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->corr_spacing)) { return false; }
  if (!sbp_unpack_s8(ctx, &msg->acceleration)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->sync_flags)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->tow_flags)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->track_flags)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->nav_flags)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->pset_flags)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->misc_flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_tracking_state_detailed_dep_t(const sbp_msg_tracking_state_detailed_dep_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u64(&msg->recv_time);
  packed_size += sbp_packed_size_sbp_gps_time_dep_t(&msg->tot);
  packed_size += sbp_packed_size_u32(&msg->P);
  packed_size += sbp_packed_size_u16(&msg->P_std);
  packed_size += sbp_packed_size_sbp_carrier_phase_t(&msg->L);
  packed_size += sbp_packed_size_u8(&msg->cn0);
  packed_size += sbp_packed_size_u16(&msg->lock);
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  packed_size += sbp_packed_size_s32(&msg->doppler);
  packed_size += sbp_packed_size_u16(&msg->doppler_std);
  packed_size += sbp_packed_size_u32(&msg->uptime);
  packed_size += sbp_packed_size_s16(&msg->clock_offset);
  packed_size += sbp_packed_size_s16(&msg->clock_drift);
  packed_size += sbp_packed_size_u16(&msg->corr_spacing);
  packed_size += sbp_packed_size_s8(&msg->acceleration);
  packed_size += sbp_packed_size_u8(&msg->sync_flags);
  packed_size += sbp_packed_size_u8(&msg->tow_flags);
  packed_size += sbp_packed_size_u8(&msg->track_flags);
  packed_size += sbp_packed_size_u8(&msg->nav_flags);
  packed_size += sbp_packed_size_u8(&msg->pset_flags);
  packed_size += sbp_packed_size_u8(&msg->misc_flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_tracking_state_detailed_dep_t(sbp_pack_ctx_t *ctx, const sbp_msg_tracking_state_detailed_dep_t *msg)
{
  if (!sbp_pack_u64(ctx, &msg->recv_time)) { return false; }
  if (!sbp_pack_sbp_gps_time_dep_t(ctx, &msg->tot)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->P)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->P_std)) { return false; }
  if (!sbp_pack_sbp_carrier_phase_t(ctx, &msg->L)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->cn0)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->lock)) { return false; }
  if (!sbp_pack_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->doppler)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->doppler_std)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->uptime)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->clock_offset)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->clock_drift)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->corr_spacing)) { return false; }
  if (!sbp_pack_s8(ctx, &msg->acceleration)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->sync_flags)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->tow_flags)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->track_flags)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->nav_flags)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->pset_flags)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->misc_flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_tracking_state_detailed_dep_t(sbp_unpack_ctx_t *ctx, sbp_msg_tracking_state_detailed_dep_t *msg)
{
  if (!sbp_unpack_u64(ctx, &msg->recv_time)) { return false; }
  if (!sbp_unpack_sbp_gps_time_dep_t(ctx, &msg->tot)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->P)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->P_std)) { return false; }
  if (!sbp_unpack_sbp_carrier_phase_t(ctx, &msg->L)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->cn0)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->lock)) { return false; }
  if (!sbp_unpack_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->doppler)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->doppler_std)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->uptime)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->clock_offset)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->clock_drift)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->corr_spacing)) { return false; }
  if (!sbp_unpack_s8(ctx, &msg->acceleration)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->sync_flags)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->tow_flags)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->track_flags)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->nav_flags)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->pset_flags)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->misc_flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_tracking_channel_state_t(const sbp_tracking_channel_state_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_u8(&msg->fcn);
  packed_size += sbp_packed_size_u8(&msg->cn0);
  return packed_size;
}

static inline bool sbp_pack_sbp_tracking_channel_state_t(sbp_pack_ctx_t *ctx, const sbp_tracking_channel_state_t *msg)
{
  if (!sbp_pack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->fcn)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->cn0)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_tracking_channel_state_t(sbp_unpack_ctx_t *ctx, sbp_tracking_channel_state_t *msg)
{
  if (!sbp_unpack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->fcn)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->cn0)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_tracking_state_t(const sbp_msg_tracking_state_t *msg) {
  size_t packed_size = 0;
  packed_size += (msg->n_states * sbp_packed_size_sbp_tracking_channel_state_t(&msg->states[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_tracking_state_t(sbp_pack_ctx_t *ctx, const sbp_msg_tracking_state_t *msg)
{
  for (uint8_t i = 0; i < msg->n_states; i++)
  {
    if (!sbp_pack_sbp_tracking_channel_state_t(ctx, &msg->states[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_tracking_state_t(sbp_unpack_ctx_t *ctx, sbp_msg_tracking_state_t *msg)
{
    msg->n_states = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_tracking_channel_state_t(&msg->states[0]));
  for (uint8_t i = 0; i < msg->n_states; i++) {
    if (!sbp_unpack_sbp_tracking_channel_state_t(ctx, &msg->states[i])) { return false; }
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_measurement_state_t(const sbp_measurement_state_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->mesid);
  packed_size += sbp_packed_size_u8(&msg->cn0);
  return packed_size;
}

static inline bool sbp_pack_sbp_measurement_state_t(sbp_pack_ctx_t *ctx, const sbp_measurement_state_t *msg)
{
  if (!sbp_pack_sbp_sbp_gnss_signal_t(ctx, &msg->mesid)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->cn0)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_measurement_state_t(sbp_unpack_ctx_t *ctx, sbp_measurement_state_t *msg)
{
  if (!sbp_unpack_sbp_sbp_gnss_signal_t(ctx, &msg->mesid)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->cn0)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_measurement_state_t(const sbp_msg_measurement_state_t *msg) {
  size_t packed_size = 0;
  packed_size += (msg->n_states * sbp_packed_size_sbp_measurement_state_t(&msg->states[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_measurement_state_t(sbp_pack_ctx_t *ctx, const sbp_msg_measurement_state_t *msg)
{
  for (uint8_t i = 0; i < msg->n_states; i++)
  {
    if (!sbp_pack_sbp_measurement_state_t(ctx, &msg->states[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_measurement_state_t(sbp_unpack_ctx_t *ctx, sbp_msg_measurement_state_t *msg)
{
    msg->n_states = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_measurement_state_t(&msg->states[0]));
  for (uint8_t i = 0; i < msg->n_states; i++) {
    if (!sbp_unpack_sbp_measurement_state_t(ctx, &msg->states[i])) { return false; }
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_tracking_channel_correlation_t(const sbp_tracking_channel_correlation_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_s16(&msg->I);
  packed_size += sbp_packed_size_s16(&msg->Q);
  return packed_size;
}

static inline bool sbp_pack_sbp_tracking_channel_correlation_t(sbp_pack_ctx_t *ctx, const sbp_tracking_channel_correlation_t *msg)
{
  if (!sbp_pack_s16(ctx, &msg->I)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->Q)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_tracking_channel_correlation_t(sbp_unpack_ctx_t *ctx, sbp_tracking_channel_correlation_t *msg)
{
  if (!sbp_unpack_s16(ctx, &msg->I)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->Q)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_tracking_iq_t(const sbp_msg_tracking_iq_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->channel);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += ( 3 * sbp_packed_size_sbp_tracking_channel_correlation_t(&msg->corrs[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_tracking_iq_t(sbp_pack_ctx_t *ctx, const sbp_msg_tracking_iq_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->channel)) { return false; }
  if (!sbp_pack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!sbp_pack_sbp_tracking_channel_correlation_t(ctx, &msg->corrs[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_tracking_iq_t(sbp_unpack_ctx_t *ctx, sbp_msg_tracking_iq_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->channel)) { return false; }
  if (!sbp_unpack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_unpack_sbp_tracking_channel_correlation_t(ctx, &msg->corrs[i])) { return false; }
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_tracking_channel_correlation_dep_t(const sbp_tracking_channel_correlation_dep_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_s32(&msg->I);
  packed_size += sbp_packed_size_s32(&msg->Q);
  return packed_size;
}

static inline bool sbp_pack_sbp_tracking_channel_correlation_dep_t(sbp_pack_ctx_t *ctx, const sbp_tracking_channel_correlation_dep_t *msg)
{
  if (!sbp_pack_s32(ctx, &msg->I)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->Q)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_tracking_channel_correlation_dep_t(sbp_unpack_ctx_t *ctx, sbp_tracking_channel_correlation_dep_t *msg)
{
  if (!sbp_unpack_s32(ctx, &msg->I)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->Q)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_tracking_iq_dep_b_t(const sbp_msg_tracking_iq_dep_b_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->channel);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += ( 3 * sbp_packed_size_sbp_tracking_channel_correlation_dep_t(&msg->corrs[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_tracking_iq_dep_b_t(sbp_pack_ctx_t *ctx, const sbp_msg_tracking_iq_dep_b_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->channel)) { return false; }
  if (!sbp_pack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!sbp_pack_sbp_tracking_channel_correlation_dep_t(ctx, &msg->corrs[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_tracking_iq_dep_b_t(sbp_unpack_ctx_t *ctx, sbp_msg_tracking_iq_dep_b_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->channel)) { return false; }
  if (!sbp_unpack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_unpack_sbp_tracking_channel_correlation_dep_t(ctx, &msg->corrs[i])) { return false; }
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_tracking_iq_dep_a_t(const sbp_msg_tracking_iq_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->channel);
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  packed_size += ( 3 * sbp_packed_size_sbp_tracking_channel_correlation_dep_t(&msg->corrs[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_tracking_iq_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_tracking_iq_dep_a_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->channel)) { return false; }
  if (!sbp_pack_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!sbp_pack_sbp_tracking_channel_correlation_dep_t(ctx, &msg->corrs[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_tracking_iq_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_tracking_iq_dep_a_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->channel)) { return false; }
  if (!sbp_unpack_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_unpack_sbp_tracking_channel_correlation_dep_t(ctx, &msg->corrs[i])) { return false; }
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_tracking_channel_state_dep_a_t(const sbp_tracking_channel_state_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->state);
  packed_size += sbp_packed_size_u8(&msg->prn);
  packed_size += sbp_packed_size_float(&msg->cn0);
  return packed_size;
}

static inline bool sbp_pack_sbp_tracking_channel_state_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_tracking_channel_state_dep_a_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->state)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->prn)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cn0)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_tracking_channel_state_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_tracking_channel_state_dep_a_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->state)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->prn)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cn0)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_tracking_state_dep_a_t(const sbp_msg_tracking_state_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += (msg->n_states * sbp_packed_size_sbp_tracking_channel_state_dep_a_t(&msg->states[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_tracking_state_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_tracking_state_dep_a_t *msg)
{
  for (uint8_t i = 0; i < msg->n_states; i++)
  {
    if (!sbp_pack_sbp_tracking_channel_state_dep_a_t(ctx, &msg->states[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_tracking_state_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_tracking_state_dep_a_t *msg)
{
    msg->n_states = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_tracking_channel_state_dep_a_t(&msg->states[0]));
  for (uint8_t i = 0; i < msg->n_states; i++) {
    if (!sbp_unpack_sbp_tracking_channel_state_dep_a_t(ctx, &msg->states[i])) { return false; }
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_tracking_channel_state_dep_b_t(const sbp_tracking_channel_state_dep_b_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->state);
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  packed_size += sbp_packed_size_float(&msg->cn0);
  return packed_size;
}

static inline bool sbp_pack_sbp_tracking_channel_state_dep_b_t(sbp_pack_ctx_t *ctx, const sbp_tracking_channel_state_dep_b_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->state)) { return false; }
  if (!sbp_pack_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cn0)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_tracking_channel_state_dep_b_t(sbp_unpack_ctx_t *ctx, sbp_tracking_channel_state_dep_b_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->state)) { return false; }
  if (!sbp_unpack_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cn0)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_tracking_state_dep_b_t(const sbp_msg_tracking_state_dep_b_t *msg) {
  size_t packed_size = 0;
  packed_size += (msg->n_states * sbp_packed_size_sbp_tracking_channel_state_dep_b_t(&msg->states[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_tracking_state_dep_b_t(sbp_pack_ctx_t *ctx, const sbp_msg_tracking_state_dep_b_t *msg)
{
  for (uint8_t i = 0; i < msg->n_states; i++)
  {
    if (!sbp_pack_sbp_tracking_channel_state_dep_b_t(ctx, &msg->states[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_tracking_state_dep_b_t(sbp_unpack_ctx_t *ctx, sbp_msg_tracking_state_dep_b_t *msg)
{
    msg->n_states = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_tracking_channel_state_dep_b_t(&msg->states[0]));
  for (uint8_t i = 0; i < msg->n_states; i++) {
    if (!sbp_unpack_sbp_tracking_channel_state_dep_b_t(ctx, &msg->states[i])) { return false; }
  }
  return true;
}

#endif
