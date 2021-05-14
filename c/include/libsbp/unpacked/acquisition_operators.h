#ifndef LIBSBP_ACQUISITION_OPERATORS_H
#define LIBSBP_ACQUISITION_OPERATORS_H

#ifndef LIBSBP_ACQUISITION_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/acquisition.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#include <libsbp/common.h>
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_acq_result_t &a, const sbp_msg_acq_result_t &b) {
  (void)a;
  (void)b;
  
        
    if (fabs( a.cn0 - b.cn0 ) > 0.001) { return false; }
        
    if (fabs( a.cp - b.cp ) > 0.001) { return false; }
        
    if (fabs( a.cf - b.cf ) > 0.001) { return false; }
        
        
    if (a.sid.sat != b.sid.sat) { return false; }
        
    if (a.sid.code != b.sid.code) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_acq_result_t &a, const sbp_msg_acq_result_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_acq_result_dep_c_t &a, const sbp_msg_acq_result_dep_c_t &b) {
  (void)a;
  (void)b;
  
        
    if (fabs( a.cn0 - b.cn0 ) > 0.001) { return false; }
        
    if (fabs( a.cp - b.cp ) > 0.001) { return false; }
        
    if (fabs( a.cf - b.cf ) > 0.001) { return false; }
        
        
    if (a.sid.sat != b.sid.sat) { return false; }
        
    if (a.sid.code != b.sid.code) { return false; }
        
    if (a.sid.reserved != b.sid.reserved) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_acq_result_dep_c_t &a, const sbp_msg_acq_result_dep_c_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_acq_result_dep_b_t &a, const sbp_msg_acq_result_dep_b_t &b) {
  (void)a;
  (void)b;
  
        
    if (fabs( a.snr - b.snr ) > 0.001) { return false; }
        
    if (fabs( a.cp - b.cp ) > 0.001) { return false; }
        
    if (fabs( a.cf - b.cf ) > 0.001) { return false; }
        
        
    if (a.sid.sat != b.sid.sat) { return false; }
        
    if (a.sid.code != b.sid.code) { return false; }
        
    if (a.sid.reserved != b.sid.reserved) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_acq_result_dep_b_t &a, const sbp_msg_acq_result_dep_b_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_acq_result_dep_a_t &a, const sbp_msg_acq_result_dep_a_t &b) {
  (void)a;
  (void)b;
  
        
    if (fabs( a.snr - b.snr ) > 0.001) { return false; }
        
    if (fabs( a.cp - b.cp ) > 0.001) { return false; }
        
    if (fabs( a.cf - b.cf ) > 0.001) { return false; }
        
    if (a.prn != b.prn) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_acq_result_dep_a_t &a, const sbp_msg_acq_result_dep_a_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_acq_sv_profile_t &a, const sbp_acq_sv_profile_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.job_type != b.job_type) { return false; }
        
    if (a.status != b.status) { return false; }
        
    if (a.cn0 != b.cn0) { return false; }
        
    if (a.int_time != b.int_time) { return false; }
        
        
    if (a.sid.sat != b.sid.sat) { return false; }
        
    if (a.sid.code != b.sid.code) { return false; }
        
    if (a.bin_width != b.bin_width) { return false; }
        
    if (a.timestamp != b.timestamp) { return false; }
        
    if (a.time_spent != b.time_spent) { return false; }
        
    if (a.cf_min != b.cf_min) { return false; }
        
    if (a.cf_max != b.cf_max) { return false; }
        
    if (a.cf != b.cf) { return false; }
        
    if (a.cp != b.cp) { return false; }

  return true;
}

static inline bool operator!=(const sbp_acq_sv_profile_t &a, const sbp_acq_sv_profile_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_acq_sv_profile_dep_t &a, const sbp_acq_sv_profile_dep_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.job_type != b.job_type) { return false; }
        
    if (a.status != b.status) { return false; }
        
    if (a.cn0 != b.cn0) { return false; }
        
    if (a.int_time != b.int_time) { return false; }
        
        
    if (a.sid.sat != b.sid.sat) { return false; }
        
    if (a.sid.code != b.sid.code) { return false; }
        
    if (a.sid.reserved != b.sid.reserved) { return false; }
        
    if (a.bin_width != b.bin_width) { return false; }
        
    if (a.timestamp != b.timestamp) { return false; }
        
    if (a.time_spent != b.time_spent) { return false; }
        
    if (a.cf_min != b.cf_min) { return false; }
        
    if (a.cf_max != b.cf_max) { return false; }
        
    if (a.cf != b.cf) { return false; }
        
    if (a.cp != b.cp) { return false; }

  return true;
}

static inline bool operator!=(const sbp_acq_sv_profile_dep_t &a, const sbp_acq_sv_profile_dep_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_acq_sv_profile_t &a, const sbp_msg_acq_sv_profile_t &b) {
  (void)a;
  (void)b;
  
          if (a.n_acq_sv_profile != b.n_acq_sv_profile) { return false; }
        for (size_t acq_sv_profile_idx = 0; acq_sv_profile_idx < (size_t)a.n_acq_sv_profile; acq_sv_profile_idx++)
        {
            
        
    if (a.acq_sv_profile[acq_sv_profile_idx].job_type != b.acq_sv_profile[acq_sv_profile_idx].job_type) { return false; }
        
    if (a.acq_sv_profile[acq_sv_profile_idx].status != b.acq_sv_profile[acq_sv_profile_idx].status) { return false; }
        
    if (a.acq_sv_profile[acq_sv_profile_idx].cn0 != b.acq_sv_profile[acq_sv_profile_idx].cn0) { return false; }
        
    if (a.acq_sv_profile[acq_sv_profile_idx].int_time != b.acq_sv_profile[acq_sv_profile_idx].int_time) { return false; }
        
        
    if (a.acq_sv_profile[acq_sv_profile_idx].sid.sat != b.acq_sv_profile[acq_sv_profile_idx].sid.sat) { return false; }
        
    if (a.acq_sv_profile[acq_sv_profile_idx].sid.code != b.acq_sv_profile[acq_sv_profile_idx].sid.code) { return false; }
        
    if (a.acq_sv_profile[acq_sv_profile_idx].bin_width != b.acq_sv_profile[acq_sv_profile_idx].bin_width) { return false; }
        
    if (a.acq_sv_profile[acq_sv_profile_idx].timestamp != b.acq_sv_profile[acq_sv_profile_idx].timestamp) { return false; }
        
    if (a.acq_sv_profile[acq_sv_profile_idx].time_spent != b.acq_sv_profile[acq_sv_profile_idx].time_spent) { return false; }
        
    if (a.acq_sv_profile[acq_sv_profile_idx].cf_min != b.acq_sv_profile[acq_sv_profile_idx].cf_min) { return false; }
        
    if (a.acq_sv_profile[acq_sv_profile_idx].cf_max != b.acq_sv_profile[acq_sv_profile_idx].cf_max) { return false; }
        
    if (a.acq_sv_profile[acq_sv_profile_idx].cf != b.acq_sv_profile[acq_sv_profile_idx].cf) { return false; }
        
    if (a.acq_sv_profile[acq_sv_profile_idx].cp != b.acq_sv_profile[acq_sv_profile_idx].cp) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_acq_sv_profile_t &a, const sbp_msg_acq_sv_profile_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_acq_sv_profile_dep_t &a, const sbp_msg_acq_sv_profile_dep_t &b) {
  (void)a;
  (void)b;
  
          if (a.n_acq_sv_profile != b.n_acq_sv_profile) { return false; }
        for (size_t acq_sv_profile_idx = 0; acq_sv_profile_idx < (size_t)a.n_acq_sv_profile; acq_sv_profile_idx++)
        {
            
        
    if (a.acq_sv_profile[acq_sv_profile_idx].job_type != b.acq_sv_profile[acq_sv_profile_idx].job_type) { return false; }
        
    if (a.acq_sv_profile[acq_sv_profile_idx].status != b.acq_sv_profile[acq_sv_profile_idx].status) { return false; }
        
    if (a.acq_sv_profile[acq_sv_profile_idx].cn0 != b.acq_sv_profile[acq_sv_profile_idx].cn0) { return false; }
        
    if (a.acq_sv_profile[acq_sv_profile_idx].int_time != b.acq_sv_profile[acq_sv_profile_idx].int_time) { return false; }
        
        
    if (a.acq_sv_profile[acq_sv_profile_idx].sid.sat != b.acq_sv_profile[acq_sv_profile_idx].sid.sat) { return false; }
        
    if (a.acq_sv_profile[acq_sv_profile_idx].sid.code != b.acq_sv_profile[acq_sv_profile_idx].sid.code) { return false; }
        
    if (a.acq_sv_profile[acq_sv_profile_idx].sid.reserved != b.acq_sv_profile[acq_sv_profile_idx].sid.reserved) { return false; }
        
    if (a.acq_sv_profile[acq_sv_profile_idx].bin_width != b.acq_sv_profile[acq_sv_profile_idx].bin_width) { return false; }
        
    if (a.acq_sv_profile[acq_sv_profile_idx].timestamp != b.acq_sv_profile[acq_sv_profile_idx].timestamp) { return false; }
        
    if (a.acq_sv_profile[acq_sv_profile_idx].time_spent != b.acq_sv_profile[acq_sv_profile_idx].time_spent) { return false; }
        
    if (a.acq_sv_profile[acq_sv_profile_idx].cf_min != b.acq_sv_profile[acq_sv_profile_idx].cf_min) { return false; }
        
    if (a.acq_sv_profile[acq_sv_profile_idx].cf_max != b.acq_sv_profile[acq_sv_profile_idx].cf_max) { return false; }
        
    if (a.acq_sv_profile[acq_sv_profile_idx].cf != b.acq_sv_profile[acq_sv_profile_idx].cf) { return false; }
        
    if (a.acq_sv_profile[acq_sv_profile_idx].cp != b.acq_sv_profile[acq_sv_profile_idx].cp) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_acq_sv_profile_dep_t &a, const sbp_msg_acq_sv_profile_dep_t &b) {
  return !(a == b);
}
#endif

#endif
