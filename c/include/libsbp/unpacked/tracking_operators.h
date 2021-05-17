#ifndef LIBSBP_TRACKING_OPERATORS_H
#define LIBSBP_TRACKING_OPERATORS_H

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
#include <libsbp/string.h>
#include <libsbp/unpacked/base.h>
static inline int sbp_cmp_sbp_msg_tracking_state_detailed_dep_a_t(const sbp_msg_tracking_state_detailed_dep_a_t *a, const sbp_msg_tracking_state_detailed_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u64(&a->recv_time, &b->recv_time);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_sbp_gps_time_t(&a->tot, &b->tot);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->P, &b->P);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->P_std, &b->P_std);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_carrier_phase_t(&a->L, &b->L);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->cn0, &b->cn0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->lock, &b->lock);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->doppler, &b->doppler);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->doppler_std, &b->doppler_std);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->uptime, &b->uptime);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->clock_offset, &b->clock_offset);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->clock_drift, &b->clock_drift);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->corr_spacing, &b->corr_spacing);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s8(&a->acceleration, &b->acceleration);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->sync_flags, &b->sync_flags);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->tow_flags, &b->tow_flags);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->track_flags, &b->track_flags);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->nav_flags, &b->nav_flags);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->pset_flags, &b->pset_flags);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->misc_flags, &b->misc_flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_tracking_state_detailed_dep_a_t &a, const sbp_msg_tracking_state_detailed_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_detailed_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_tracking_state_detailed_dep_a_t &a, const sbp_msg_tracking_state_detailed_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_detailed_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_tracking_state_detailed_dep_a_t &a, const sbp_msg_tracking_state_detailed_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_detailed_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_tracking_state_detailed_dep_a_t &a, const sbp_msg_tracking_state_detailed_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_detailed_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_tracking_state_detailed_dep_a_t &a, const sbp_msg_tracking_state_detailed_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_detailed_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_tracking_state_detailed_dep_a_t &a, const sbp_msg_tracking_state_detailed_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_detailed_dep_a_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_tracking_state_detailed_dep_t(const sbp_msg_tracking_state_detailed_dep_t *a, const sbp_msg_tracking_state_detailed_dep_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u64(&a->recv_time, &b->recv_time);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_gps_time_dep_t(&a->tot, &b->tot);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->P, &b->P);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->P_std, &b->P_std);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_carrier_phase_t(&a->L, &b->L);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->cn0, &b->cn0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->lock, &b->lock);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_gnss_signal_dep_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->doppler, &b->doppler);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->doppler_std, &b->doppler_std);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->uptime, &b->uptime);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->clock_offset, &b->clock_offset);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->clock_drift, &b->clock_drift);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->corr_spacing, &b->corr_spacing);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s8(&a->acceleration, &b->acceleration);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->sync_flags, &b->sync_flags);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->tow_flags, &b->tow_flags);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->track_flags, &b->track_flags);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->nav_flags, &b->nav_flags);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->pset_flags, &b->pset_flags);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->misc_flags, &b->misc_flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_tracking_state_detailed_dep_t &a, const sbp_msg_tracking_state_detailed_dep_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_detailed_dep_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_tracking_state_detailed_dep_t &a, const sbp_msg_tracking_state_detailed_dep_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_detailed_dep_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_tracking_state_detailed_dep_t &a, const sbp_msg_tracking_state_detailed_dep_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_detailed_dep_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_tracking_state_detailed_dep_t &a, const sbp_msg_tracking_state_detailed_dep_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_detailed_dep_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_tracking_state_detailed_dep_t &a, const sbp_msg_tracking_state_detailed_dep_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_detailed_dep_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_tracking_state_detailed_dep_t &a, const sbp_msg_tracking_state_detailed_dep_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_detailed_dep_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_tracking_channel_state_t(const sbp_tracking_channel_state_t *a, const sbp_tracking_channel_state_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->fcn, &b->fcn);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->cn0, &b->cn0);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_tracking_channel_state_t &a, const sbp_tracking_channel_state_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_tracking_channel_state_t &a, const sbp_tracking_channel_state_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_tracking_channel_state_t &a, const sbp_tracking_channel_state_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_tracking_channel_state_t &a, const sbp_tracking_channel_state_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_tracking_channel_state_t &a, const sbp_tracking_channel_state_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_tracking_channel_state_t &a, const sbp_tracking_channel_state_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_tracking_state_t(const sbp_msg_tracking_state_t *a, const sbp_msg_tracking_state_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->n_states, &b->n_states);
  for (uint8_t i = 0; i < a->n_states && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_tracking_channel_state_t(&a->states[i], &b->states[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_tracking_state_t &a, const sbp_msg_tracking_state_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_tracking_state_t &a, const sbp_msg_tracking_state_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_tracking_state_t &a, const sbp_msg_tracking_state_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_tracking_state_t &a, const sbp_msg_tracking_state_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_tracking_state_t &a, const sbp_msg_tracking_state_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_tracking_state_t &a, const sbp_msg_tracking_state_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_measurement_state_t(const sbp_measurement_state_t *a, const sbp_measurement_state_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->mesid, &b->mesid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->cn0, &b->cn0);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_measurement_state_t &a, const sbp_measurement_state_t &b) {
  return sbp_cmp_sbp_measurement_state_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_measurement_state_t &a, const sbp_measurement_state_t &b) {
  return sbp_cmp_sbp_measurement_state_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_measurement_state_t &a, const sbp_measurement_state_t &b) {
  return sbp_cmp_sbp_measurement_state_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_measurement_state_t &a, const sbp_measurement_state_t &b) {
  return sbp_cmp_sbp_measurement_state_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_measurement_state_t &a, const sbp_measurement_state_t &b) {
  return sbp_cmp_sbp_measurement_state_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_measurement_state_t &a, const sbp_measurement_state_t &b) {
  return sbp_cmp_sbp_measurement_state_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_measurement_state_t(const sbp_msg_measurement_state_t *a, const sbp_msg_measurement_state_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->n_states, &b->n_states);
  for (uint8_t i = 0; i < a->n_states && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_measurement_state_t(&a->states[i], &b->states[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_measurement_state_t &a, const sbp_msg_measurement_state_t &b) {
  return sbp_cmp_sbp_msg_measurement_state_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_measurement_state_t &a, const sbp_msg_measurement_state_t &b) {
  return sbp_cmp_sbp_msg_measurement_state_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_measurement_state_t &a, const sbp_msg_measurement_state_t &b) {
  return sbp_cmp_sbp_msg_measurement_state_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_measurement_state_t &a, const sbp_msg_measurement_state_t &b) {
  return sbp_cmp_sbp_msg_measurement_state_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_measurement_state_t &a, const sbp_msg_measurement_state_t &b) {
  return sbp_cmp_sbp_msg_measurement_state_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_measurement_state_t &a, const sbp_msg_measurement_state_t &b) {
  return sbp_cmp_sbp_msg_measurement_state_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_tracking_channel_correlation_t(const sbp_tracking_channel_correlation_t *a, const sbp_tracking_channel_correlation_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_s16(&a->I, &b->I);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->Q, &b->Q);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_tracking_channel_correlation_t &a, const sbp_tracking_channel_correlation_t &b) {
  return sbp_cmp_sbp_tracking_channel_correlation_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_tracking_channel_correlation_t &a, const sbp_tracking_channel_correlation_t &b) {
  return sbp_cmp_sbp_tracking_channel_correlation_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_tracking_channel_correlation_t &a, const sbp_tracking_channel_correlation_t &b) {
  return sbp_cmp_sbp_tracking_channel_correlation_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_tracking_channel_correlation_t &a, const sbp_tracking_channel_correlation_t &b) {
  return sbp_cmp_sbp_tracking_channel_correlation_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_tracking_channel_correlation_t &a, const sbp_tracking_channel_correlation_t &b) {
  return sbp_cmp_sbp_tracking_channel_correlation_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_tracking_channel_correlation_t &a, const sbp_tracking_channel_correlation_t &b) {
  return sbp_cmp_sbp_tracking_channel_correlation_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_tracking_iq_t(const sbp_msg_tracking_iq_t *a, const sbp_msg_tracking_iq_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->channel, &b->channel);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 3 && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_tracking_channel_correlation_t(&a->corrs[i], &b->corrs[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_tracking_iq_t &a, const sbp_msg_tracking_iq_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_tracking_iq_t &a, const sbp_msg_tracking_iq_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_tracking_iq_t &a, const sbp_msg_tracking_iq_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_tracking_iq_t &a, const sbp_msg_tracking_iq_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_tracking_iq_t &a, const sbp_msg_tracking_iq_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_tracking_iq_t &a, const sbp_msg_tracking_iq_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_tracking_channel_correlation_dep_t(const sbp_tracking_channel_correlation_dep_t *a, const sbp_tracking_channel_correlation_dep_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_s32(&a->I, &b->I);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->Q, &b->Q);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_tracking_channel_correlation_dep_t &a, const sbp_tracking_channel_correlation_dep_t &b) {
  return sbp_cmp_sbp_tracking_channel_correlation_dep_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_tracking_channel_correlation_dep_t &a, const sbp_tracking_channel_correlation_dep_t &b) {
  return sbp_cmp_sbp_tracking_channel_correlation_dep_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_tracking_channel_correlation_dep_t &a, const sbp_tracking_channel_correlation_dep_t &b) {
  return sbp_cmp_sbp_tracking_channel_correlation_dep_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_tracking_channel_correlation_dep_t &a, const sbp_tracking_channel_correlation_dep_t &b) {
  return sbp_cmp_sbp_tracking_channel_correlation_dep_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_tracking_channel_correlation_dep_t &a, const sbp_tracking_channel_correlation_dep_t &b) {
  return sbp_cmp_sbp_tracking_channel_correlation_dep_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_tracking_channel_correlation_dep_t &a, const sbp_tracking_channel_correlation_dep_t &b) {
  return sbp_cmp_sbp_tracking_channel_correlation_dep_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_tracking_iq_dep_b_t(const sbp_msg_tracking_iq_dep_b_t *a, const sbp_msg_tracking_iq_dep_b_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->channel, &b->channel);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 3 && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_tracking_channel_correlation_dep_t(&a->corrs[i], &b->corrs[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_tracking_iq_dep_b_t &a, const sbp_msg_tracking_iq_dep_b_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_dep_b_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_tracking_iq_dep_b_t &a, const sbp_msg_tracking_iq_dep_b_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_dep_b_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_tracking_iq_dep_b_t &a, const sbp_msg_tracking_iq_dep_b_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_dep_b_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_tracking_iq_dep_b_t &a, const sbp_msg_tracking_iq_dep_b_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_dep_b_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_tracking_iq_dep_b_t &a, const sbp_msg_tracking_iq_dep_b_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_dep_b_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_tracking_iq_dep_b_t &a, const sbp_msg_tracking_iq_dep_b_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_dep_b_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_tracking_iq_dep_a_t(const sbp_msg_tracking_iq_dep_a_t *a, const sbp_msg_tracking_iq_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->channel, &b->channel);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_gnss_signal_dep_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 3 && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_tracking_channel_correlation_dep_t(&a->corrs[i], &b->corrs[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_tracking_iq_dep_a_t &a, const sbp_msg_tracking_iq_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_tracking_iq_dep_a_t &a, const sbp_msg_tracking_iq_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_tracking_iq_dep_a_t &a, const sbp_msg_tracking_iq_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_tracking_iq_dep_a_t &a, const sbp_msg_tracking_iq_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_tracking_iq_dep_a_t &a, const sbp_msg_tracking_iq_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_tracking_iq_dep_a_t &a, const sbp_msg_tracking_iq_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_dep_a_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_tracking_channel_state_dep_a_t(const sbp_tracking_channel_state_dep_a_t *a, const sbp_tracking_channel_state_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->state, &b->state);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->prn, &b->prn);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cn0, &b->cn0);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_tracking_channel_state_dep_a_t &a, const sbp_tracking_channel_state_dep_a_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_tracking_channel_state_dep_a_t &a, const sbp_tracking_channel_state_dep_a_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_tracking_channel_state_dep_a_t &a, const sbp_tracking_channel_state_dep_a_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_tracking_channel_state_dep_a_t &a, const sbp_tracking_channel_state_dep_a_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_tracking_channel_state_dep_a_t &a, const sbp_tracking_channel_state_dep_a_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_tracking_channel_state_dep_a_t &a, const sbp_tracking_channel_state_dep_a_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_dep_a_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_tracking_state_dep_a_t(const sbp_msg_tracking_state_dep_a_t *a, const sbp_msg_tracking_state_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->n_states, &b->n_states);
  for (uint8_t i = 0; i < a->n_states && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_tracking_channel_state_dep_a_t(&a->states[i], &b->states[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_tracking_state_dep_a_t &a, const sbp_msg_tracking_state_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_tracking_state_dep_a_t &a, const sbp_msg_tracking_state_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_tracking_state_dep_a_t &a, const sbp_msg_tracking_state_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_tracking_state_dep_a_t &a, const sbp_msg_tracking_state_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_tracking_state_dep_a_t &a, const sbp_msg_tracking_state_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_tracking_state_dep_a_t &a, const sbp_msg_tracking_state_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_dep_a_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_tracking_channel_state_dep_b_t(const sbp_tracking_channel_state_dep_b_t *a, const sbp_tracking_channel_state_dep_b_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->state, &b->state);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_gnss_signal_dep_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cn0, &b->cn0);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_tracking_channel_state_dep_b_t &a, const sbp_tracking_channel_state_dep_b_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_dep_b_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_tracking_channel_state_dep_b_t &a, const sbp_tracking_channel_state_dep_b_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_dep_b_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_tracking_channel_state_dep_b_t &a, const sbp_tracking_channel_state_dep_b_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_dep_b_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_tracking_channel_state_dep_b_t &a, const sbp_tracking_channel_state_dep_b_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_dep_b_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_tracking_channel_state_dep_b_t &a, const sbp_tracking_channel_state_dep_b_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_dep_b_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_tracking_channel_state_dep_b_t &a, const sbp_tracking_channel_state_dep_b_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_dep_b_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_tracking_state_dep_b_t(const sbp_msg_tracking_state_dep_b_t *a, const sbp_msg_tracking_state_dep_b_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->n_states, &b->n_states);
  for (uint8_t i = 0; i < a->n_states && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_tracking_channel_state_dep_b_t(&a->states[i], &b->states[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_tracking_state_dep_b_t &a, const sbp_msg_tracking_state_dep_b_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_dep_b_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_tracking_state_dep_b_t &a, const sbp_msg_tracking_state_dep_b_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_dep_b_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_tracking_state_dep_b_t &a, const sbp_msg_tracking_state_dep_b_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_dep_b_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_tracking_state_dep_b_t &a, const sbp_msg_tracking_state_dep_b_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_dep_b_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_tracking_state_dep_b_t &a, const sbp_msg_tracking_state_dep_b_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_dep_b_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_tracking_state_dep_b_t &a, const sbp_msg_tracking_state_dep_b_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_dep_b_t(&a, &b) >= 0;
}
#endif

#endif
