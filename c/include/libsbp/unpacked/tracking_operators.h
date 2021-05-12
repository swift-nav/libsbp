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
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_tracking_state_detailed_dep_a_t &a, const sbp_msg_tracking_state_detailed_dep_a_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.recv_time != b.recv_time) { return false; }
        
        
    if (a.tot.tow != b.tot.tow) { return false; }
        
    if (a.tot.ns_residual != b.tot.ns_residual) { return false; }
        
    if (a.tot.wn != b.tot.wn) { return false; }
        
    if (a.P != b.P) { return false; }
        
    if (a.P_std != b.P_std) { return false; }
        
        
    if (a.L.i != b.L.i) { return false; }
        
    if (a.L.f != b.L.f) { return false; }
        
    if (a.cn0 != b.cn0) { return false; }
        
    if (a.lock != b.lock) { return false; }
        
        
    if (a.sid.sat != b.sid.sat) { return false; }
        
    if (a.sid.code != b.sid.code) { return false; }
        
    if (a.doppler != b.doppler) { return false; }
        
    if (a.doppler_std != b.doppler_std) { return false; }
        
    if (a.uptime != b.uptime) { return false; }
        
    if (a.clock_offset != b.clock_offset) { return false; }
        
    if (a.clock_drift != b.clock_drift) { return false; }
        
    if (a.corr_spacing != b.corr_spacing) { return false; }
        
    if (a.acceleration != b.acceleration) { return false; }
        
    if (a.sync_flags != b.sync_flags) { return false; }
        
    if (a.tow_flags != b.tow_flags) { return false; }
        
    if (a.track_flags != b.track_flags) { return false; }
        
    if (a.nav_flags != b.nav_flags) { return false; }
        
    if (a.pset_flags != b.pset_flags) { return false; }
        
    if (a.misc_flags != b.misc_flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_tracking_state_detailed_dep_a_t &a, const sbp_msg_tracking_state_detailed_dep_a_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_tracking_state_detailed_dep_t &a, const sbp_msg_tracking_state_detailed_dep_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.recv_time != b.recv_time) { return false; }
        
        
    if (a.tot.tow != b.tot.tow) { return false; }
        
    if (a.tot.wn != b.tot.wn) { return false; }
        
    if (a.P != b.P) { return false; }
        
    if (a.P_std != b.P_std) { return false; }
        
        
    if (a.L.i != b.L.i) { return false; }
        
    if (a.L.f != b.L.f) { return false; }
        
    if (a.cn0 != b.cn0) { return false; }
        
    if (a.lock != b.lock) { return false; }
        
        
    if (a.sid.sat != b.sid.sat) { return false; }
        
    if (a.sid.code != b.sid.code) { return false; }
        
    if (a.sid.reserved != b.sid.reserved) { return false; }
        
    if (a.doppler != b.doppler) { return false; }
        
    if (a.doppler_std != b.doppler_std) { return false; }
        
    if (a.uptime != b.uptime) { return false; }
        
    if (a.clock_offset != b.clock_offset) { return false; }
        
    if (a.clock_drift != b.clock_drift) { return false; }
        
    if (a.corr_spacing != b.corr_spacing) { return false; }
        
    if (a.acceleration != b.acceleration) { return false; }
        
    if (a.sync_flags != b.sync_flags) { return false; }
        
    if (a.tow_flags != b.tow_flags) { return false; }
        
    if (a.track_flags != b.track_flags) { return false; }
        
    if (a.nav_flags != b.nav_flags) { return false; }
        
    if (a.pset_flags != b.pset_flags) { return false; }
        
    if (a.misc_flags != b.misc_flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_tracking_state_detailed_dep_t &a, const sbp_msg_tracking_state_detailed_dep_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_tracking_channel_state_t &a, const sbp_tracking_channel_state_t &b) {
  (void)a;
  (void)b;
  
        
        
    if (a.sid.sat != b.sid.sat) { return false; }
        
    if (a.sid.code != b.sid.code) { return false; }
        
    if (a.fcn != b.fcn) { return false; }
        
    if (a.cn0 != b.cn0) { return false; }

  return true;
}

static inline bool operator!=(const sbp_tracking_channel_state_t &a, const sbp_tracking_channel_state_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_tracking_state_t &a, const sbp_msg_tracking_state_t &b) {
  (void)a;
  (void)b;
  
          if (a.states_count != b.states_count) { return false; }
        for (size_t states_idx = 0; states_idx < (size_t)a.states_count; states_idx++)
        {
            
        
        
    if (a.states[states_idx].sid.sat != b.states[states_idx].sid.sat) { return false; }
        
    if (a.states[states_idx].sid.code != b.states[states_idx].sid.code) { return false; }
        
    if (a.states[states_idx].fcn != b.states[states_idx].fcn) { return false; }
        
    if (a.states[states_idx].cn0 != b.states[states_idx].cn0) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_tracking_state_t &a, const sbp_msg_tracking_state_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_measurement_state_t &a, const sbp_measurement_state_t &b) {
  (void)a;
  (void)b;
  
        
        
    if (a.mesid.sat != b.mesid.sat) { return false; }
        
    if (a.mesid.code != b.mesid.code) { return false; }
        
    if (a.cn0 != b.cn0) { return false; }

  return true;
}

static inline bool operator!=(const sbp_measurement_state_t &a, const sbp_measurement_state_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_measurement_state_t &a, const sbp_msg_measurement_state_t &b) {
  (void)a;
  (void)b;
  
          if (a.states_count != b.states_count) { return false; }
        for (size_t states_idx = 0; states_idx < (size_t)a.states_count; states_idx++)
        {
            
        
        
    if (a.states[states_idx].mesid.sat != b.states[states_idx].mesid.sat) { return false; }
        
    if (a.states[states_idx].mesid.code != b.states[states_idx].mesid.code) { return false; }
        
    if (a.states[states_idx].cn0 != b.states[states_idx].cn0) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_measurement_state_t &a, const sbp_msg_measurement_state_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_tracking_channel_correlation_t &a, const sbp_tracking_channel_correlation_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.I != b.I) { return false; }
        
    if (a.Q != b.Q) { return false; }

  return true;
}

static inline bool operator!=(const sbp_tracking_channel_correlation_t &a, const sbp_tracking_channel_correlation_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_tracking_iq_t &a, const sbp_msg_tracking_iq_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.channel != b.channel) { return false; }
        
        
    if (a.sid.sat != b.sid.sat) { return false; }
        
    if (a.sid.code != b.sid.code) { return false; }
        for (size_t corrs_idx = 0; corrs_idx < 3; corrs_idx++)
        {
            
        
    if (a.corrs[corrs_idx].I != b.corrs[corrs_idx].I) { return false; }
        
    if (a.corrs[corrs_idx].Q != b.corrs[corrs_idx].Q) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_tracking_iq_t &a, const sbp_msg_tracking_iq_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_tracking_channel_correlation_dep_t &a, const sbp_tracking_channel_correlation_dep_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.I != b.I) { return false; }
        
    if (a.Q != b.Q) { return false; }

  return true;
}

static inline bool operator!=(const sbp_tracking_channel_correlation_dep_t &a, const sbp_tracking_channel_correlation_dep_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_tracking_iq_dep_b_t &a, const sbp_msg_tracking_iq_dep_b_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.channel != b.channel) { return false; }
        
        
    if (a.sid.sat != b.sid.sat) { return false; }
        
    if (a.sid.code != b.sid.code) { return false; }
        for (size_t corrs_idx = 0; corrs_idx < 3; corrs_idx++)
        {
            
        
    if (a.corrs[corrs_idx].I != b.corrs[corrs_idx].I) { return false; }
        
    if (a.corrs[corrs_idx].Q != b.corrs[corrs_idx].Q) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_tracking_iq_dep_b_t &a, const sbp_msg_tracking_iq_dep_b_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_tracking_iq_dep_a_t &a, const sbp_msg_tracking_iq_dep_a_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.channel != b.channel) { return false; }
        
        
    if (a.sid.sat != b.sid.sat) { return false; }
        
    if (a.sid.code != b.sid.code) { return false; }
        
    if (a.sid.reserved != b.sid.reserved) { return false; }
        for (size_t corrs_idx = 0; corrs_idx < 3; corrs_idx++)
        {
            
        
    if (a.corrs[corrs_idx].I != b.corrs[corrs_idx].I) { return false; }
        
    if (a.corrs[corrs_idx].Q != b.corrs[corrs_idx].Q) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_tracking_iq_dep_a_t &a, const sbp_msg_tracking_iq_dep_a_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_tracking_channel_state_dep_a_t &a, const sbp_tracking_channel_state_dep_a_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.state != b.state) { return false; }
        
    if (a.prn != b.prn) { return false; }
        
    if (fabs( a.cn0 - b.cn0 ) > 0.001) { return false; }

  return true;
}

static inline bool operator!=(const sbp_tracking_channel_state_dep_a_t &a, const sbp_tracking_channel_state_dep_a_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_tracking_state_dep_a_t &a, const sbp_msg_tracking_state_dep_a_t &b) {
  (void)a;
  (void)b;
  
          if (a.states_count != b.states_count) { return false; }
        for (size_t states_idx = 0; states_idx < (size_t)a.states_count; states_idx++)
        {
            
        
    if (a.states[states_idx].state != b.states[states_idx].state) { return false; }
        
    if (a.states[states_idx].prn != b.states[states_idx].prn) { return false; }
        
    if (fabs( a.states[states_idx].cn0 - b.states[states_idx].cn0 ) > 0.001) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_tracking_state_dep_a_t &a, const sbp_msg_tracking_state_dep_a_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_tracking_channel_state_dep_b_t &a, const sbp_tracking_channel_state_dep_b_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.state != b.state) { return false; }
        
        
    if (a.sid.sat != b.sid.sat) { return false; }
        
    if (a.sid.code != b.sid.code) { return false; }
        
    if (a.sid.reserved != b.sid.reserved) { return false; }
        
    if (fabs( a.cn0 - b.cn0 ) > 0.001) { return false; }

  return true;
}

static inline bool operator!=(const sbp_tracking_channel_state_dep_b_t &a, const sbp_tracking_channel_state_dep_b_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_tracking_state_dep_b_t &a, const sbp_msg_tracking_state_dep_b_t &b) {
  (void)a;
  (void)b;
  
          if (a.states_count != b.states_count) { return false; }
        for (size_t states_idx = 0; states_idx < (size_t)a.states_count; states_idx++)
        {
            
        
    if (a.states[states_idx].state != b.states[states_idx].state) { return false; }
        
        
    if (a.states[states_idx].sid.sat != b.states[states_idx].sid.sat) { return false; }
        
    if (a.states[states_idx].sid.code != b.states[states_idx].sid.code) { return false; }
        
    if (a.states[states_idx].sid.reserved != b.states[states_idx].sid.reserved) { return false; }
        
    if (fabs( a.states[states_idx].cn0 - b.states[states_idx].cn0 ) > 0.001) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_tracking_state_dep_b_t &a, const sbp_msg_tracking_state_dep_b_t &b) {
  return !(a == b);
}
#endif

#endif
