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
#include <libsbp/string.h>
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_tracking_state_detailed_dep_a_t(const sbp_msg_tracking_state_detailed_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
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

static inline bool sbp_pack_sbp_msg_tracking_state_detailed_dep_a_t(u8 *buf, size_t len, const sbp_msg_tracking_state_detailed_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_tracking_state_detailed_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_u64(buf + offset, len - offset, &msg->recv_time);
  offset += sbp_pack_sbp_sbp_gps_time_t(buf + offset, len - offset, &msg->tot);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->P);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->P_std);
  offset += sbp_pack_sbp_carrier_phase_t(buf + offset, len - offset, &msg->L);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->cn0);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->lock);
  offset += sbp_pack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->doppler);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->doppler_std);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->uptime);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->clock_offset);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->clock_drift);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->corr_spacing);
  offset += sbp_pack_s8(buf + offset, len - offset, &msg->acceleration);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->sync_flags);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->tow_flags);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->track_flags);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->nav_flags);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->pset_flags);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->misc_flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_tracking_state_detailed_dep_a_t(const uint8_t *buf, size_t len, sbp_msg_tracking_state_detailed_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u64(buf + offset, len - offset, &msg->recv_time);
  offset += sbp_unpack_sbp_sbp_gps_time_t(buf + offset, len - offset, &msg->tot);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->P);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->P_std);
  offset += sbp_unpack_sbp_carrier_phase_t(buf + offset, len - offset, &msg->L);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->cn0);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->lock);
  offset += sbp_unpack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->doppler);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->doppler_std);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->uptime);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->clock_offset);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->clock_drift);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->corr_spacing);
  offset += sbp_unpack_s8(buf + offset, len - offset, &msg->acceleration);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->sync_flags);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->tow_flags);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->track_flags);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->nav_flags);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->pset_flags);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->misc_flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_tracking_state_detailed_dep_t(const sbp_msg_tracking_state_detailed_dep_t *msg) {
  size_t packed_size = 0;
  (void)msg;
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

static inline bool sbp_pack_sbp_msg_tracking_state_detailed_dep_t(u8 *buf, size_t len, const sbp_msg_tracking_state_detailed_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_tracking_state_detailed_dep_t(msg) > len) { return false; }
  offset += sbp_pack_u64(buf + offset, len - offset, &msg->recv_time);
  offset += sbp_pack_sbp_gps_time_dep_t(buf + offset, len - offset, &msg->tot);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->P);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->P_std);
  offset += sbp_pack_sbp_carrier_phase_t(buf + offset, len - offset, &msg->L);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->cn0);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->lock);
  offset += sbp_pack_sbp_gnss_signal_dep_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->doppler);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->doppler_std);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->uptime);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->clock_offset);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->clock_drift);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->corr_spacing);
  offset += sbp_pack_s8(buf + offset, len - offset, &msg->acceleration);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->sync_flags);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->tow_flags);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->track_flags);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->nav_flags);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->pset_flags);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->misc_flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_tracking_state_detailed_dep_t(const uint8_t *buf, size_t len, sbp_msg_tracking_state_detailed_dep_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u64(buf + offset, len - offset, &msg->recv_time);
  offset += sbp_unpack_sbp_gps_time_dep_t(buf + offset, len - offset, &msg->tot);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->P);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->P_std);
  offset += sbp_unpack_sbp_carrier_phase_t(buf + offset, len - offset, &msg->L);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->cn0);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->lock);
  offset += sbp_unpack_sbp_gnss_signal_dep_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->doppler);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->doppler_std);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->uptime);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->clock_offset);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->clock_drift);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->corr_spacing);
  offset += sbp_unpack_s8(buf + offset, len - offset, &msg->acceleration);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->sync_flags);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->tow_flags);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->track_flags);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->nav_flags);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->pset_flags);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->misc_flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_tracking_channel_state_t(const sbp_tracking_channel_state_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_u8(&msg->fcn);
  packed_size += sbp_packed_size_u8(&msg->cn0);
  return packed_size;
}

static inline size_t sbp_pack_sbp_tracking_channel_state_t(u8 *buf, size_t len, const sbp_tracking_channel_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_tracking_channel_state_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->fcn);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->cn0);
  return offset;
}

static inline size_t sbp_unpack_sbp_tracking_channel_state_t(const uint8_t *buf, size_t len, sbp_tracking_channel_state_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->fcn);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->cn0);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_tracking_state_t(const sbp_msg_tracking_state_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += (msg->n_states * sbp_packed_size_sbp_tracking_channel_state_t(&msg->states[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_tracking_state_t(u8 *buf, size_t len, const sbp_msg_tracking_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_tracking_state_t(msg) > len) { return false; }
  for (uint8_t i = 0; i < msg->n_states; i++) 
  {
    offset += sbp_pack_sbp_tracking_channel_state_t(buf + offset, len - offset, &msg->states[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_tracking_state_t(const uint8_t *buf, size_t len, sbp_msg_tracking_state_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  msg->n_states = (uint8_t)((len - offset) / sbp_packed_size_sbp_tracking_channel_state_t(&msg->states[0]));
  for (uint8_t i = 0; i < msg->n_states; i++)
  {
    offset += sbp_unpack_sbp_tracking_channel_state_t(buf + offset, len - offset, &msg->states[i]);
  }
  return true;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_measurement_state_t(const sbp_measurement_state_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->mesid);
  packed_size += sbp_packed_size_u8(&msg->cn0);
  return packed_size;
}

static inline size_t sbp_pack_sbp_measurement_state_t(u8 *buf, size_t len, const sbp_measurement_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_measurement_state_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->mesid);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->cn0);
  return offset;
}

static inline size_t sbp_unpack_sbp_measurement_state_t(const uint8_t *buf, size_t len, sbp_measurement_state_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->mesid);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->cn0);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_measurement_state_t(const sbp_msg_measurement_state_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += (msg->n_states * sbp_packed_size_sbp_measurement_state_t(&msg->states[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_measurement_state_t(u8 *buf, size_t len, const sbp_msg_measurement_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_measurement_state_t(msg) > len) { return false; }
  for (uint8_t i = 0; i < msg->n_states; i++) 
  {
    offset += sbp_pack_sbp_measurement_state_t(buf + offset, len - offset, &msg->states[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_measurement_state_t(const uint8_t *buf, size_t len, sbp_msg_measurement_state_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  msg->n_states = (uint8_t)((len - offset) / sbp_packed_size_sbp_measurement_state_t(&msg->states[0]));
  for (uint8_t i = 0; i < msg->n_states; i++)
  {
    offset += sbp_unpack_sbp_measurement_state_t(buf + offset, len - offset, &msg->states[i]);
  }
  return true;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_tracking_channel_correlation_t(const sbp_tracking_channel_correlation_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_s16(&msg->I);
  packed_size += sbp_packed_size_s16(&msg->Q);
  return packed_size;
}

static inline size_t sbp_pack_sbp_tracking_channel_correlation_t(u8 *buf, size_t len, const sbp_tracking_channel_correlation_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_tracking_channel_correlation_t(msg) > len) { return false; }
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->I);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->Q);
  return offset;
}

static inline size_t sbp_unpack_sbp_tracking_channel_correlation_t(const uint8_t *buf, size_t len, sbp_tracking_channel_correlation_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->I);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->Q);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_tracking_iq_t(const sbp_msg_tracking_iq_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->channel);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += ( 3 * sbp_packed_size_sbp_tracking_channel_correlation_t(&msg->corrs[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_tracking_iq_t(u8 *buf, size_t len, const sbp_msg_tracking_iq_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_tracking_iq_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->channel);
  offset += sbp_pack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  for (uint8_t i = 0; i < 3; i++) 
  {
    offset += sbp_pack_sbp_tracking_channel_correlation_t(buf + offset, len - offset, &msg->corrs[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_tracking_iq_t(const uint8_t *buf, size_t len, sbp_msg_tracking_iq_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->channel);
  offset += sbp_unpack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  for (uint8_t i = 0; i < 3; i++)
  {
    offset += sbp_unpack_sbp_tracking_channel_correlation_t(buf + offset, len - offset, &msg->corrs[i]);
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_tracking_channel_correlation_dep_t(const sbp_tracking_channel_correlation_dep_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_s32(&msg->I);
  packed_size += sbp_packed_size_s32(&msg->Q);
  return packed_size;
}

static inline size_t sbp_pack_sbp_tracking_channel_correlation_dep_t(u8 *buf, size_t len, const sbp_tracking_channel_correlation_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_tracking_channel_correlation_dep_t(msg) > len) { return false; }
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->I);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->Q);
  return offset;
}

static inline size_t sbp_unpack_sbp_tracking_channel_correlation_dep_t(const uint8_t *buf, size_t len, sbp_tracking_channel_correlation_dep_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->I);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->Q);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_tracking_iq_dep_b_t(const sbp_msg_tracking_iq_dep_b_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->channel);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += ( 3 * sbp_packed_size_sbp_tracking_channel_correlation_dep_t(&msg->corrs[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_tracking_iq_dep_b_t(u8 *buf, size_t len, const sbp_msg_tracking_iq_dep_b_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_tracking_iq_dep_b_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->channel);
  offset += sbp_pack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  for (uint8_t i = 0; i < 3; i++) 
  {
    offset += sbp_pack_sbp_tracking_channel_correlation_dep_t(buf + offset, len - offset, &msg->corrs[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_tracking_iq_dep_b_t(const uint8_t *buf, size_t len, sbp_msg_tracking_iq_dep_b_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->channel);
  offset += sbp_unpack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  for (uint8_t i = 0; i < 3; i++)
  {
    offset += sbp_unpack_sbp_tracking_channel_correlation_dep_t(buf + offset, len - offset, &msg->corrs[i]);
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_tracking_iq_dep_a_t(const sbp_msg_tracking_iq_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->channel);
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  packed_size += ( 3 * sbp_packed_size_sbp_tracking_channel_correlation_dep_t(&msg->corrs[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_tracking_iq_dep_a_t(u8 *buf, size_t len, const sbp_msg_tracking_iq_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_tracking_iq_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->channel);
  offset += sbp_pack_sbp_gnss_signal_dep_t(buf + offset, len - offset, &msg->sid);
  for (uint8_t i = 0; i < 3; i++) 
  {
    offset += sbp_pack_sbp_tracking_channel_correlation_dep_t(buf + offset, len - offset, &msg->corrs[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_tracking_iq_dep_a_t(const uint8_t *buf, size_t len, sbp_msg_tracking_iq_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->channel);
  offset += sbp_unpack_sbp_gnss_signal_dep_t(buf + offset, len - offset, &msg->sid);
  for (uint8_t i = 0; i < 3; i++)
  {
    offset += sbp_unpack_sbp_tracking_channel_correlation_dep_t(buf + offset, len - offset, &msg->corrs[i]);
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_tracking_channel_state_dep_a_t(const sbp_tracking_channel_state_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->state);
  packed_size += sbp_packed_size_u8(&msg->prn);
  packed_size += sbp_packed_size_float(&msg->cn0);
  return packed_size;
}

static inline size_t sbp_pack_sbp_tracking_channel_state_dep_a_t(u8 *buf, size_t len, const sbp_tracking_channel_state_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_tracking_channel_state_dep_a_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->state);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->prn);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cn0);
  return offset;
}

static inline size_t sbp_unpack_sbp_tracking_channel_state_dep_a_t(const uint8_t *buf, size_t len, sbp_tracking_channel_state_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->state);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->prn);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cn0);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_tracking_state_dep_a_t(const sbp_msg_tracking_state_dep_a_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += (msg->n_states * sbp_packed_size_sbp_tracking_channel_state_dep_a_t(&msg->states[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_tracking_state_dep_a_t(u8 *buf, size_t len, const sbp_msg_tracking_state_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_tracking_state_dep_a_t(msg) > len) { return false; }
  for (uint8_t i = 0; i < msg->n_states; i++) 
  {
    offset += sbp_pack_sbp_tracking_channel_state_dep_a_t(buf + offset, len - offset, &msg->states[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_tracking_state_dep_a_t(const uint8_t *buf, size_t len, sbp_msg_tracking_state_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  msg->n_states = (uint8_t)((len - offset) / sbp_packed_size_sbp_tracking_channel_state_dep_a_t(&msg->states[0]));
  for (uint8_t i = 0; i < msg->n_states; i++)
  {
    offset += sbp_unpack_sbp_tracking_channel_state_dep_a_t(buf + offset, len - offset, &msg->states[i]);
  }
  return true;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_tracking_channel_state_dep_b_t(const sbp_tracking_channel_state_dep_b_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->state);
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  packed_size += sbp_packed_size_float(&msg->cn0);
  return packed_size;
}

static inline size_t sbp_pack_sbp_tracking_channel_state_dep_b_t(u8 *buf, size_t len, const sbp_tracking_channel_state_dep_b_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_tracking_channel_state_dep_b_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->state);
  offset += sbp_pack_sbp_gnss_signal_dep_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->cn0);
  return offset;
}

static inline size_t sbp_unpack_sbp_tracking_channel_state_dep_b_t(const uint8_t *buf, size_t len, sbp_tracking_channel_state_dep_b_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->state);
  offset += sbp_unpack_sbp_gnss_signal_dep_t(buf + offset, len - offset, &msg->sid);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->cn0);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_tracking_state_dep_b_t(const sbp_msg_tracking_state_dep_b_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += (msg->n_states * sbp_packed_size_sbp_tracking_channel_state_dep_b_t(&msg->states[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_tracking_state_dep_b_t(u8 *buf, size_t len, const sbp_msg_tracking_state_dep_b_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_tracking_state_dep_b_t(msg) > len) { return false; }
  for (uint8_t i = 0; i < msg->n_states; i++) 
  {
    offset += sbp_pack_sbp_tracking_channel_state_dep_b_t(buf + offset, len - offset, &msg->states[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_tracking_state_dep_b_t(const uint8_t *buf, size_t len, sbp_msg_tracking_state_dep_b_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  msg->n_states = (uint8_t)((len - offset) / sbp_packed_size_sbp_tracking_channel_state_dep_b_t(&msg->states[0]));
  for (uint8_t i = 0; i < msg->n_states; i++)
  {
    offset += sbp_unpack_sbp_tracking_channel_state_dep_b_t(buf + offset, len - offset, &msg->states[i]);
  }
  return true;
  return true;
}

#endif
