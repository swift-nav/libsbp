#ifndef LIBSBP_OBSERVATION_OPERATORS_H
#define LIBSBP_OBSERVATION_OPERATORS_H

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
#ifdef __cplusplus
static inline bool operator== ( const sbp_observation_header_t &a, const sbp_observation_header_t &b) {
  (void)a;
  (void)b;
  
        
        
    if (a.t.tow != b.t.tow) { return false; }
        
    if (a.t.ns_residual != b.t.ns_residual) { return false; }
        
    if (a.t.wn != b.t.wn) { return false; }
        
    if (a.n_obs != b.n_obs) { return false; }

  return true;
}

static inline bool operator!=(const sbp_observation_header_t &a, const sbp_observation_header_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_doppler_t &a, const sbp_doppler_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.i != b.i) { return false; }
        
    if (a.f != b.f) { return false; }

  return true;
}

static inline bool operator!=(const sbp_doppler_t &a, const sbp_doppler_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_packed_obs_content_t &a, const sbp_packed_obs_content_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.P != b.P) { return false; }
        
        
    if (a.L.i != b.L.i) { return false; }
        
    if (a.L.f != b.L.f) { return false; }
        
        
    if (a.D.i != b.D.i) { return false; }
        
    if (a.D.f != b.D.f) { return false; }
        
    if (a.cn0 != b.cn0) { return false; }
        
    if (a.lock != b.lock) { return false; }
        
    if (a.flags != b.flags) { return false; }
        
        
    if (a.sid.sat != b.sid.sat) { return false; }
        
    if (a.sid.code != b.sid.code) { return false; }

  return true;
}

static inline bool operator!=(const sbp_packed_obs_content_t &a, const sbp_packed_obs_content_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_packed_osr_content_t &a, const sbp_packed_osr_content_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.P != b.P) { return false; }
        
        
    if (a.L.i != b.L.i) { return false; }
        
    if (a.L.f != b.L.f) { return false; }
        
    if (a.lock != b.lock) { return false; }
        
    if (a.flags != b.flags) { return false; }
        
        
    if (a.sid.sat != b.sid.sat) { return false; }
        
    if (a.sid.code != b.sid.code) { return false; }
        
    if (a.iono_std != b.iono_std) { return false; }
        
    if (a.tropo_std != b.tropo_std) { return false; }
        
    if (a.range_std != b.range_std) { return false; }

  return true;
}

static inline bool operator!=(const sbp_packed_osr_content_t &a, const sbp_packed_osr_content_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_obs_t &a, const sbp_msg_obs_t &b) {
  (void)a;
  (void)b;
  
        
        
        
    if (a.header.t.tow != b.header.t.tow) { return false; }
        
    if (a.header.t.ns_residual != b.header.t.ns_residual) { return false; }
        
    if (a.header.t.wn != b.header.t.wn) { return false; }
        
    if (a.header.n_obs != b.header.n_obs) { return false; }
          if (a.n_obs != b.n_obs) { return false; }
        for (size_t obs_idx = 0; obs_idx < (size_t)a.n_obs; obs_idx++)
        {
            
        
    if (a.obs[obs_idx].P != b.obs[obs_idx].P) { return false; }
        
        
    if (a.obs[obs_idx].L.i != b.obs[obs_idx].L.i) { return false; }
        
    if (a.obs[obs_idx].L.f != b.obs[obs_idx].L.f) { return false; }
        
        
    if (a.obs[obs_idx].D.i != b.obs[obs_idx].D.i) { return false; }
        
    if (a.obs[obs_idx].D.f != b.obs[obs_idx].D.f) { return false; }
        
    if (a.obs[obs_idx].cn0 != b.obs[obs_idx].cn0) { return false; }
        
    if (a.obs[obs_idx].lock != b.obs[obs_idx].lock) { return false; }
        
    if (a.obs[obs_idx].flags != b.obs[obs_idx].flags) { return false; }
        
        
    if (a.obs[obs_idx].sid.sat != b.obs[obs_idx].sid.sat) { return false; }
        
    if (a.obs[obs_idx].sid.code != b.obs[obs_idx].sid.code) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_obs_t &a, const sbp_msg_obs_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_base_pos_llh_t &a, const sbp_msg_base_pos_llh_t &b) {
  (void)a;
  (void)b;
  
        
    if (fabs( a.lat - b.lat ) > 0.001) { return false; }
        
    if (fabs( a.lon - b.lon ) > 0.001) { return false; }
        
    if (fabs( a.height - b.height ) > 0.001) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_base_pos_llh_t &a, const sbp_msg_base_pos_llh_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_base_pos_ecef_t &a, const sbp_msg_base_pos_ecef_t &b) {
  (void)a;
  (void)b;
  
        
    if (fabs( a.x - b.x ) > 0.001) { return false; }
        
    if (fabs( a.y - b.y ) > 0.001) { return false; }
        
    if (fabs( a.z - b.z ) > 0.001) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_base_pos_ecef_t &a, const sbp_msg_base_pos_ecef_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_ephemeris_common_content_t &a, const sbp_ephemeris_common_content_t &b) {
  (void)a;
  (void)b;
  
        
        
    if (a.sid.sat != b.sid.sat) { return false; }
        
    if (a.sid.code != b.sid.code) { return false; }
        
        
    if (a.toe.tow != b.toe.tow) { return false; }
        
    if (a.toe.wn != b.toe.wn) { return false; }
        
    if (fabs( a.ura - b.ura ) > 0.001) { return false; }
        
    if (a.fit_interval != b.fit_interval) { return false; }
        
    if (a.valid != b.valid) { return false; }
        
    if (a.health_bits != b.health_bits) { return false; }

  return true;
}

static inline bool operator!=(const sbp_ephemeris_common_content_t &a, const sbp_ephemeris_common_content_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_ephemeris_common_content_dep_b_t &a, const sbp_ephemeris_common_content_dep_b_t &b) {
  (void)a;
  (void)b;
  
        
        
    if (a.sid.sat != b.sid.sat) { return false; }
        
    if (a.sid.code != b.sid.code) { return false; }
        
        
    if (a.toe.tow != b.toe.tow) { return false; }
        
    if (a.toe.wn != b.toe.wn) { return false; }
        
    if (fabs( a.ura - b.ura ) > 0.001) { return false; }
        
    if (a.fit_interval != b.fit_interval) { return false; }
        
    if (a.valid != b.valid) { return false; }
        
    if (a.health_bits != b.health_bits) { return false; }

  return true;
}

static inline bool operator!=(const sbp_ephemeris_common_content_dep_b_t &a, const sbp_ephemeris_common_content_dep_b_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_ephemeris_common_content_dep_a_t &a, const sbp_ephemeris_common_content_dep_a_t &b) {
  (void)a;
  (void)b;
  
        
        
    if (a.sid.sat != b.sid.sat) { return false; }
        
    if (a.sid.code != b.sid.code) { return false; }
        
    if (a.sid.reserved != b.sid.reserved) { return false; }
        
        
    if (a.toe.tow != b.toe.tow) { return false; }
        
    if (a.toe.wn != b.toe.wn) { return false; }
        
    if (fabs( a.ura - b.ura ) > 0.001) { return false; }
        
    if (a.fit_interval != b.fit_interval) { return false; }
        
    if (a.valid != b.valid) { return false; }
        
    if (a.health_bits != b.health_bits) { return false; }

  return true;
}

static inline bool operator!=(const sbp_ephemeris_common_content_dep_a_t &a, const sbp_ephemeris_common_content_dep_a_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_ephemeris_gps_dep_e_t &a, const sbp_msg_ephemeris_gps_dep_e_t &b) {
  (void)a;
  (void)b;
  
        
        
        
    if (a.common.sid.sat != b.common.sid.sat) { return false; }
        
    if (a.common.sid.code != b.common.sid.code) { return false; }
        
    if (a.common.sid.reserved != b.common.sid.reserved) { return false; }
        
        
    if (a.common.toe.tow != b.common.toe.tow) { return false; }
        
    if (a.common.toe.wn != b.common.toe.wn) { return false; }
        
    if (fabs( a.common.ura - b.common.ura ) > 0.001) { return false; }
        
    if (a.common.fit_interval != b.common.fit_interval) { return false; }
        
    if (a.common.valid != b.common.valid) { return false; }
        
    if (a.common.health_bits != b.common.health_bits) { return false; }
        
    if (fabs( a.tgd - b.tgd ) > 0.001) { return false; }
        
    if (fabs( a.c_rs - b.c_rs ) > 0.001) { return false; }
        
    if (fabs( a.c_rc - b.c_rc ) > 0.001) { return false; }
        
    if (fabs( a.c_uc - b.c_uc ) > 0.001) { return false; }
        
    if (fabs( a.c_us - b.c_us ) > 0.001) { return false; }
        
    if (fabs( a.c_ic - b.c_ic ) > 0.001) { return false; }
        
    if (fabs( a.c_is - b.c_is ) > 0.001) { return false; }
        
    if (fabs( a.dn - b.dn ) > 0.001) { return false; }
        
    if (fabs( a.m0 - b.m0 ) > 0.001) { return false; }
        
    if (fabs( a.ecc - b.ecc ) > 0.001) { return false; }
        
    if (fabs( a.sqrta - b.sqrta ) > 0.001) { return false; }
        
    if (fabs( a.omega0 - b.omega0 ) > 0.001) { return false; }
        
    if (fabs( a.omegadot - b.omegadot ) > 0.001) { return false; }
        
    if (fabs( a.w - b.w ) > 0.001) { return false; }
        
    if (fabs( a.inc - b.inc ) > 0.001) { return false; }
        
    if (fabs( a.inc_dot - b.inc_dot ) > 0.001) { return false; }
        
    if (fabs( a.af0 - b.af0 ) > 0.001) { return false; }
        
    if (fabs( a.af1 - b.af1 ) > 0.001) { return false; }
        
    if (fabs( a.af2 - b.af2 ) > 0.001) { return false; }
        
        
    if (a.toc.tow != b.toc.tow) { return false; }
        
    if (a.toc.wn != b.toc.wn) { return false; }
        
    if (a.iode != b.iode) { return false; }
        
    if (a.iodc != b.iodc) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_ephemeris_gps_dep_e_t &a, const sbp_msg_ephemeris_gps_dep_e_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_ephemeris_gps_dep_f_t &a, const sbp_msg_ephemeris_gps_dep_f_t &b) {
  (void)a;
  (void)b;
  
        
        
        
    if (a.common.sid.sat != b.common.sid.sat) { return false; }
        
    if (a.common.sid.code != b.common.sid.code) { return false; }
        
        
    if (a.common.toe.tow != b.common.toe.tow) { return false; }
        
    if (a.common.toe.wn != b.common.toe.wn) { return false; }
        
    if (fabs( a.common.ura - b.common.ura ) > 0.001) { return false; }
        
    if (a.common.fit_interval != b.common.fit_interval) { return false; }
        
    if (a.common.valid != b.common.valid) { return false; }
        
    if (a.common.health_bits != b.common.health_bits) { return false; }
        
    if (fabs( a.tgd - b.tgd ) > 0.001) { return false; }
        
    if (fabs( a.c_rs - b.c_rs ) > 0.001) { return false; }
        
    if (fabs( a.c_rc - b.c_rc ) > 0.001) { return false; }
        
    if (fabs( a.c_uc - b.c_uc ) > 0.001) { return false; }
        
    if (fabs( a.c_us - b.c_us ) > 0.001) { return false; }
        
    if (fabs( a.c_ic - b.c_ic ) > 0.001) { return false; }
        
    if (fabs( a.c_is - b.c_is ) > 0.001) { return false; }
        
    if (fabs( a.dn - b.dn ) > 0.001) { return false; }
        
    if (fabs( a.m0 - b.m0 ) > 0.001) { return false; }
        
    if (fabs( a.ecc - b.ecc ) > 0.001) { return false; }
        
    if (fabs( a.sqrta - b.sqrta ) > 0.001) { return false; }
        
    if (fabs( a.omega0 - b.omega0 ) > 0.001) { return false; }
        
    if (fabs( a.omegadot - b.omegadot ) > 0.001) { return false; }
        
    if (fabs( a.w - b.w ) > 0.001) { return false; }
        
    if (fabs( a.inc - b.inc ) > 0.001) { return false; }
        
    if (fabs( a.inc_dot - b.inc_dot ) > 0.001) { return false; }
        
    if (fabs( a.af0 - b.af0 ) > 0.001) { return false; }
        
    if (fabs( a.af1 - b.af1 ) > 0.001) { return false; }
        
    if (fabs( a.af2 - b.af2 ) > 0.001) { return false; }
        
        
    if (a.toc.tow != b.toc.tow) { return false; }
        
    if (a.toc.wn != b.toc.wn) { return false; }
        
    if (a.iode != b.iode) { return false; }
        
    if (a.iodc != b.iodc) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_ephemeris_gps_dep_f_t &a, const sbp_msg_ephemeris_gps_dep_f_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_ephemeris_gps_t &a, const sbp_msg_ephemeris_gps_t &b) {
  (void)a;
  (void)b;
  
        
        
        
    if (a.common.sid.sat != b.common.sid.sat) { return false; }
        
    if (a.common.sid.code != b.common.sid.code) { return false; }
        
        
    if (a.common.toe.tow != b.common.toe.tow) { return false; }
        
    if (a.common.toe.wn != b.common.toe.wn) { return false; }
        
    if (fabs( a.common.ura - b.common.ura ) > 0.001) { return false; }
        
    if (a.common.fit_interval != b.common.fit_interval) { return false; }
        
    if (a.common.valid != b.common.valid) { return false; }
        
    if (a.common.health_bits != b.common.health_bits) { return false; }
        
    if (fabs( a.tgd - b.tgd ) > 0.001) { return false; }
        
    if (fabs( a.c_rs - b.c_rs ) > 0.001) { return false; }
        
    if (fabs( a.c_rc - b.c_rc ) > 0.001) { return false; }
        
    if (fabs( a.c_uc - b.c_uc ) > 0.001) { return false; }
        
    if (fabs( a.c_us - b.c_us ) > 0.001) { return false; }
        
    if (fabs( a.c_ic - b.c_ic ) > 0.001) { return false; }
        
    if (fabs( a.c_is - b.c_is ) > 0.001) { return false; }
        
    if (fabs( a.dn - b.dn ) > 0.001) { return false; }
        
    if (fabs( a.m0 - b.m0 ) > 0.001) { return false; }
        
    if (fabs( a.ecc - b.ecc ) > 0.001) { return false; }
        
    if (fabs( a.sqrta - b.sqrta ) > 0.001) { return false; }
        
    if (fabs( a.omega0 - b.omega0 ) > 0.001) { return false; }
        
    if (fabs( a.omegadot - b.omegadot ) > 0.001) { return false; }
        
    if (fabs( a.w - b.w ) > 0.001) { return false; }
        
    if (fabs( a.inc - b.inc ) > 0.001) { return false; }
        
    if (fabs( a.inc_dot - b.inc_dot ) > 0.001) { return false; }
        
    if (fabs( a.af0 - b.af0 ) > 0.001) { return false; }
        
    if (fabs( a.af1 - b.af1 ) > 0.001) { return false; }
        
    if (fabs( a.af2 - b.af2 ) > 0.001) { return false; }
        
        
    if (a.toc.tow != b.toc.tow) { return false; }
        
    if (a.toc.wn != b.toc.wn) { return false; }
        
    if (a.iode != b.iode) { return false; }
        
    if (a.iodc != b.iodc) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_ephemeris_gps_t &a, const sbp_msg_ephemeris_gps_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_ephemeris_qzss_t &a, const sbp_msg_ephemeris_qzss_t &b) {
  (void)a;
  (void)b;
  
        
        
        
    if (a.common.sid.sat != b.common.sid.sat) { return false; }
        
    if (a.common.sid.code != b.common.sid.code) { return false; }
        
        
    if (a.common.toe.tow != b.common.toe.tow) { return false; }
        
    if (a.common.toe.wn != b.common.toe.wn) { return false; }
        
    if (fabs( a.common.ura - b.common.ura ) > 0.001) { return false; }
        
    if (a.common.fit_interval != b.common.fit_interval) { return false; }
        
    if (a.common.valid != b.common.valid) { return false; }
        
    if (a.common.health_bits != b.common.health_bits) { return false; }
        
    if (fabs( a.tgd - b.tgd ) > 0.001) { return false; }
        
    if (fabs( a.c_rs - b.c_rs ) > 0.001) { return false; }
        
    if (fabs( a.c_rc - b.c_rc ) > 0.001) { return false; }
        
    if (fabs( a.c_uc - b.c_uc ) > 0.001) { return false; }
        
    if (fabs( a.c_us - b.c_us ) > 0.001) { return false; }
        
    if (fabs( a.c_ic - b.c_ic ) > 0.001) { return false; }
        
    if (fabs( a.c_is - b.c_is ) > 0.001) { return false; }
        
    if (fabs( a.dn - b.dn ) > 0.001) { return false; }
        
    if (fabs( a.m0 - b.m0 ) > 0.001) { return false; }
        
    if (fabs( a.ecc - b.ecc ) > 0.001) { return false; }
        
    if (fabs( a.sqrta - b.sqrta ) > 0.001) { return false; }
        
    if (fabs( a.omega0 - b.omega0 ) > 0.001) { return false; }
        
    if (fabs( a.omegadot - b.omegadot ) > 0.001) { return false; }
        
    if (fabs( a.w - b.w ) > 0.001) { return false; }
        
    if (fabs( a.inc - b.inc ) > 0.001) { return false; }
        
    if (fabs( a.inc_dot - b.inc_dot ) > 0.001) { return false; }
        
    if (fabs( a.af0 - b.af0 ) > 0.001) { return false; }
        
    if (fabs( a.af1 - b.af1 ) > 0.001) { return false; }
        
    if (fabs( a.af2 - b.af2 ) > 0.001) { return false; }
        
        
    if (a.toc.tow != b.toc.tow) { return false; }
        
    if (a.toc.wn != b.toc.wn) { return false; }
        
    if (a.iode != b.iode) { return false; }
        
    if (a.iodc != b.iodc) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_ephemeris_qzss_t &a, const sbp_msg_ephemeris_qzss_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_ephemeris_bds_t &a, const sbp_msg_ephemeris_bds_t &b) {
  (void)a;
  (void)b;
  
        
        
        
    if (a.common.sid.sat != b.common.sid.sat) { return false; }
        
    if (a.common.sid.code != b.common.sid.code) { return false; }
        
        
    if (a.common.toe.tow != b.common.toe.tow) { return false; }
        
    if (a.common.toe.wn != b.common.toe.wn) { return false; }
        
    if (fabs( a.common.ura - b.common.ura ) > 0.001) { return false; }
        
    if (a.common.fit_interval != b.common.fit_interval) { return false; }
        
    if (a.common.valid != b.common.valid) { return false; }
        
    if (a.common.health_bits != b.common.health_bits) { return false; }
        
    if (fabs( a.tgd1 - b.tgd1 ) > 0.001) { return false; }
        
    if (fabs( a.tgd2 - b.tgd2 ) > 0.001) { return false; }
        
    if (fabs( a.c_rs - b.c_rs ) > 0.001) { return false; }
        
    if (fabs( a.c_rc - b.c_rc ) > 0.001) { return false; }
        
    if (fabs( a.c_uc - b.c_uc ) > 0.001) { return false; }
        
    if (fabs( a.c_us - b.c_us ) > 0.001) { return false; }
        
    if (fabs( a.c_ic - b.c_ic ) > 0.001) { return false; }
        
    if (fabs( a.c_is - b.c_is ) > 0.001) { return false; }
        
    if (fabs( a.dn - b.dn ) > 0.001) { return false; }
        
    if (fabs( a.m0 - b.m0 ) > 0.001) { return false; }
        
    if (fabs( a.ecc - b.ecc ) > 0.001) { return false; }
        
    if (fabs( a.sqrta - b.sqrta ) > 0.001) { return false; }
        
    if (fabs( a.omega0 - b.omega0 ) > 0.001) { return false; }
        
    if (fabs( a.omegadot - b.omegadot ) > 0.001) { return false; }
        
    if (fabs( a.w - b.w ) > 0.001) { return false; }
        
    if (fabs( a.inc - b.inc ) > 0.001) { return false; }
        
    if (fabs( a.inc_dot - b.inc_dot ) > 0.001) { return false; }
        
    if (fabs( a.af0 - b.af0 ) > 0.001) { return false; }
        
    if (fabs( a.af1 - b.af1 ) > 0.001) { return false; }
        
    if (fabs( a.af2 - b.af2 ) > 0.001) { return false; }
        
        
    if (a.toc.tow != b.toc.tow) { return false; }
        
    if (a.toc.wn != b.toc.wn) { return false; }
        
    if (a.iode != b.iode) { return false; }
        
    if (a.iodc != b.iodc) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_ephemeris_bds_t &a, const sbp_msg_ephemeris_bds_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_ephemeris_gal_dep_a_t &a, const sbp_msg_ephemeris_gal_dep_a_t &b) {
  (void)a;
  (void)b;
  
        
        
        
    if (a.common.sid.sat != b.common.sid.sat) { return false; }
        
    if (a.common.sid.code != b.common.sid.code) { return false; }
        
        
    if (a.common.toe.tow != b.common.toe.tow) { return false; }
        
    if (a.common.toe.wn != b.common.toe.wn) { return false; }
        
    if (fabs( a.common.ura - b.common.ura ) > 0.001) { return false; }
        
    if (a.common.fit_interval != b.common.fit_interval) { return false; }
        
    if (a.common.valid != b.common.valid) { return false; }
        
    if (a.common.health_bits != b.common.health_bits) { return false; }
        
    if (fabs( a.bgd_e1e5a - b.bgd_e1e5a ) > 0.001) { return false; }
        
    if (fabs( a.bgd_e1e5b - b.bgd_e1e5b ) > 0.001) { return false; }
        
    if (fabs( a.c_rs - b.c_rs ) > 0.001) { return false; }
        
    if (fabs( a.c_rc - b.c_rc ) > 0.001) { return false; }
        
    if (fabs( a.c_uc - b.c_uc ) > 0.001) { return false; }
        
    if (fabs( a.c_us - b.c_us ) > 0.001) { return false; }
        
    if (fabs( a.c_ic - b.c_ic ) > 0.001) { return false; }
        
    if (fabs( a.c_is - b.c_is ) > 0.001) { return false; }
        
    if (fabs( a.dn - b.dn ) > 0.001) { return false; }
        
    if (fabs( a.m0 - b.m0 ) > 0.001) { return false; }
        
    if (fabs( a.ecc - b.ecc ) > 0.001) { return false; }
        
    if (fabs( a.sqrta - b.sqrta ) > 0.001) { return false; }
        
    if (fabs( a.omega0 - b.omega0 ) > 0.001) { return false; }
        
    if (fabs( a.omegadot - b.omegadot ) > 0.001) { return false; }
        
    if (fabs( a.w - b.w ) > 0.001) { return false; }
        
    if (fabs( a.inc - b.inc ) > 0.001) { return false; }
        
    if (fabs( a.inc_dot - b.inc_dot ) > 0.001) { return false; }
        
    if (fabs( a.af0 - b.af0 ) > 0.001) { return false; }
        
    if (fabs( a.af1 - b.af1 ) > 0.001) { return false; }
        
    if (fabs( a.af2 - b.af2 ) > 0.001) { return false; }
        
        
    if (a.toc.tow != b.toc.tow) { return false; }
        
    if (a.toc.wn != b.toc.wn) { return false; }
        
    if (a.iode != b.iode) { return false; }
        
    if (a.iodc != b.iodc) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_ephemeris_gal_dep_a_t &a, const sbp_msg_ephemeris_gal_dep_a_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_ephemeris_gal_t &a, const sbp_msg_ephemeris_gal_t &b) {
  (void)a;
  (void)b;
  
        
        
        
    if (a.common.sid.sat != b.common.sid.sat) { return false; }
        
    if (a.common.sid.code != b.common.sid.code) { return false; }
        
        
    if (a.common.toe.tow != b.common.toe.tow) { return false; }
        
    if (a.common.toe.wn != b.common.toe.wn) { return false; }
        
    if (fabs( a.common.ura - b.common.ura ) > 0.001) { return false; }
        
    if (a.common.fit_interval != b.common.fit_interval) { return false; }
        
    if (a.common.valid != b.common.valid) { return false; }
        
    if (a.common.health_bits != b.common.health_bits) { return false; }
        
    if (fabs( a.bgd_e1e5a - b.bgd_e1e5a ) > 0.001) { return false; }
        
    if (fabs( a.bgd_e1e5b - b.bgd_e1e5b ) > 0.001) { return false; }
        
    if (fabs( a.c_rs - b.c_rs ) > 0.001) { return false; }
        
    if (fabs( a.c_rc - b.c_rc ) > 0.001) { return false; }
        
    if (fabs( a.c_uc - b.c_uc ) > 0.001) { return false; }
        
    if (fabs( a.c_us - b.c_us ) > 0.001) { return false; }
        
    if (fabs( a.c_ic - b.c_ic ) > 0.001) { return false; }
        
    if (fabs( a.c_is - b.c_is ) > 0.001) { return false; }
        
    if (fabs( a.dn - b.dn ) > 0.001) { return false; }
        
    if (fabs( a.m0 - b.m0 ) > 0.001) { return false; }
        
    if (fabs( a.ecc - b.ecc ) > 0.001) { return false; }
        
    if (fabs( a.sqrta - b.sqrta ) > 0.001) { return false; }
        
    if (fabs( a.omega0 - b.omega0 ) > 0.001) { return false; }
        
    if (fabs( a.omegadot - b.omegadot ) > 0.001) { return false; }
        
    if (fabs( a.w - b.w ) > 0.001) { return false; }
        
    if (fabs( a.inc - b.inc ) > 0.001) { return false; }
        
    if (fabs( a.inc_dot - b.inc_dot ) > 0.001) { return false; }
        
    if (fabs( a.af0 - b.af0 ) > 0.001) { return false; }
        
    if (fabs( a.af1 - b.af1 ) > 0.001) { return false; }
        
    if (fabs( a.af2 - b.af2 ) > 0.001) { return false; }
        
        
    if (a.toc.tow != b.toc.tow) { return false; }
        
    if (a.toc.wn != b.toc.wn) { return false; }
        
    if (a.iode != b.iode) { return false; }
        
    if (a.iodc != b.iodc) { return false; }
        
    if (a.source != b.source) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_ephemeris_gal_t &a, const sbp_msg_ephemeris_gal_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_ephemeris_sbas_dep_a_t &a, const sbp_msg_ephemeris_sbas_dep_a_t &b) {
  (void)a;
  (void)b;
  
        
        
        
    if (a.common.sid.sat != b.common.sid.sat) { return false; }
        
    if (a.common.sid.code != b.common.sid.code) { return false; }
        
    if (a.common.sid.reserved != b.common.sid.reserved) { return false; }
        
        
    if (a.common.toe.tow != b.common.toe.tow) { return false; }
        
    if (a.common.toe.wn != b.common.toe.wn) { return false; }
        
    if (fabs( a.common.ura - b.common.ura ) > 0.001) { return false; }
        
    if (a.common.fit_interval != b.common.fit_interval) { return false; }
        
    if (a.common.valid != b.common.valid) { return false; }
        
    if (a.common.health_bits != b.common.health_bits) { return false; }
        for (size_t pos_idx = 0; pos_idx < 3; pos_idx++)
        {
            
    if (fabs( a.pos[pos_idx] - b.pos[pos_idx] ) > 0.001) { return false; }
        }
        for (size_t vel_idx = 0; vel_idx < 3; vel_idx++)
        {
            
    if (fabs( a.vel[vel_idx] - b.vel[vel_idx] ) > 0.001) { return false; }
        }
        for (size_t acc_idx = 0; acc_idx < 3; acc_idx++)
        {
            
    if (fabs( a.acc[acc_idx] - b.acc[acc_idx] ) > 0.001) { return false; }
        }
        
    if (fabs( a.a_gf0 - b.a_gf0 ) > 0.001) { return false; }
        
    if (fabs( a.a_gf1 - b.a_gf1 ) > 0.001) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_ephemeris_sbas_dep_a_t &a, const sbp_msg_ephemeris_sbas_dep_a_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_ephemeris_glo_dep_a_t &a, const sbp_msg_ephemeris_glo_dep_a_t &b) {
  (void)a;
  (void)b;
  
        
        
        
    if (a.common.sid.sat != b.common.sid.sat) { return false; }
        
    if (a.common.sid.code != b.common.sid.code) { return false; }
        
    if (a.common.sid.reserved != b.common.sid.reserved) { return false; }
        
        
    if (a.common.toe.tow != b.common.toe.tow) { return false; }
        
    if (a.common.toe.wn != b.common.toe.wn) { return false; }
        
    if (fabs( a.common.ura - b.common.ura ) > 0.001) { return false; }
        
    if (a.common.fit_interval != b.common.fit_interval) { return false; }
        
    if (a.common.valid != b.common.valid) { return false; }
        
    if (a.common.health_bits != b.common.health_bits) { return false; }
        
    if (fabs( a.gamma - b.gamma ) > 0.001) { return false; }
        
    if (fabs( a.tau - b.tau ) > 0.001) { return false; }
        for (size_t pos_idx = 0; pos_idx < 3; pos_idx++)
        {
            
    if (fabs( a.pos[pos_idx] - b.pos[pos_idx] ) > 0.001) { return false; }
        }
        for (size_t vel_idx = 0; vel_idx < 3; vel_idx++)
        {
            
    if (fabs( a.vel[vel_idx] - b.vel[vel_idx] ) > 0.001) { return false; }
        }
        for (size_t acc_idx = 0; acc_idx < 3; acc_idx++)
        {
            
    if (fabs( a.acc[acc_idx] - b.acc[acc_idx] ) > 0.001) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_ephemeris_glo_dep_a_t &a, const sbp_msg_ephemeris_glo_dep_a_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_ephemeris_sbas_dep_b_t &a, const sbp_msg_ephemeris_sbas_dep_b_t &b) {
  (void)a;
  (void)b;
  
        
        
        
    if (a.common.sid.sat != b.common.sid.sat) { return false; }
        
    if (a.common.sid.code != b.common.sid.code) { return false; }
        
        
    if (a.common.toe.tow != b.common.toe.tow) { return false; }
        
    if (a.common.toe.wn != b.common.toe.wn) { return false; }
        
    if (fabs( a.common.ura - b.common.ura ) > 0.001) { return false; }
        
    if (a.common.fit_interval != b.common.fit_interval) { return false; }
        
    if (a.common.valid != b.common.valid) { return false; }
        
    if (a.common.health_bits != b.common.health_bits) { return false; }
        for (size_t pos_idx = 0; pos_idx < 3; pos_idx++)
        {
            
    if (fabs( a.pos[pos_idx] - b.pos[pos_idx] ) > 0.001) { return false; }
        }
        for (size_t vel_idx = 0; vel_idx < 3; vel_idx++)
        {
            
    if (fabs( a.vel[vel_idx] - b.vel[vel_idx] ) > 0.001) { return false; }
        }
        for (size_t acc_idx = 0; acc_idx < 3; acc_idx++)
        {
            
    if (fabs( a.acc[acc_idx] - b.acc[acc_idx] ) > 0.001) { return false; }
        }
        
    if (fabs( a.a_gf0 - b.a_gf0 ) > 0.001) { return false; }
        
    if (fabs( a.a_gf1 - b.a_gf1 ) > 0.001) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_ephemeris_sbas_dep_b_t &a, const sbp_msg_ephemeris_sbas_dep_b_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_ephemeris_sbas_t &a, const sbp_msg_ephemeris_sbas_t &b) {
  (void)a;
  (void)b;
  
        
        
        
    if (a.common.sid.sat != b.common.sid.sat) { return false; }
        
    if (a.common.sid.code != b.common.sid.code) { return false; }
        
        
    if (a.common.toe.tow != b.common.toe.tow) { return false; }
        
    if (a.common.toe.wn != b.common.toe.wn) { return false; }
        
    if (fabs( a.common.ura - b.common.ura ) > 0.001) { return false; }
        
    if (a.common.fit_interval != b.common.fit_interval) { return false; }
        
    if (a.common.valid != b.common.valid) { return false; }
        
    if (a.common.health_bits != b.common.health_bits) { return false; }
        for (size_t pos_idx = 0; pos_idx < 3; pos_idx++)
        {
            
    if (fabs( a.pos[pos_idx] - b.pos[pos_idx] ) > 0.001) { return false; }
        }
        for (size_t vel_idx = 0; vel_idx < 3; vel_idx++)
        {
            
    if (fabs( a.vel[vel_idx] - b.vel[vel_idx] ) > 0.001) { return false; }
        }
        for (size_t acc_idx = 0; acc_idx < 3; acc_idx++)
        {
            
    if (fabs( a.acc[acc_idx] - b.acc[acc_idx] ) > 0.001) { return false; }
        }
        
    if (fabs( a.a_gf0 - b.a_gf0 ) > 0.001) { return false; }
        
    if (fabs( a.a_gf1 - b.a_gf1 ) > 0.001) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_ephemeris_sbas_t &a, const sbp_msg_ephemeris_sbas_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_ephemeris_glo_dep_b_t &a, const sbp_msg_ephemeris_glo_dep_b_t &b) {
  (void)a;
  (void)b;
  
        
        
        
    if (a.common.sid.sat != b.common.sid.sat) { return false; }
        
    if (a.common.sid.code != b.common.sid.code) { return false; }
        
        
    if (a.common.toe.tow != b.common.toe.tow) { return false; }
        
    if (a.common.toe.wn != b.common.toe.wn) { return false; }
        
    if (fabs( a.common.ura - b.common.ura ) > 0.001) { return false; }
        
    if (a.common.fit_interval != b.common.fit_interval) { return false; }
        
    if (a.common.valid != b.common.valid) { return false; }
        
    if (a.common.health_bits != b.common.health_bits) { return false; }
        
    if (fabs( a.gamma - b.gamma ) > 0.001) { return false; }
        
    if (fabs( a.tau - b.tau ) > 0.001) { return false; }
        for (size_t pos_idx = 0; pos_idx < 3; pos_idx++)
        {
            
    if (fabs( a.pos[pos_idx] - b.pos[pos_idx] ) > 0.001) { return false; }
        }
        for (size_t vel_idx = 0; vel_idx < 3; vel_idx++)
        {
            
    if (fabs( a.vel[vel_idx] - b.vel[vel_idx] ) > 0.001) { return false; }
        }
        for (size_t acc_idx = 0; acc_idx < 3; acc_idx++)
        {
            
    if (fabs( a.acc[acc_idx] - b.acc[acc_idx] ) > 0.001) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_ephemeris_glo_dep_b_t &a, const sbp_msg_ephemeris_glo_dep_b_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_ephemeris_glo_dep_c_t &a, const sbp_msg_ephemeris_glo_dep_c_t &b) {
  (void)a;
  (void)b;
  
        
        
        
    if (a.common.sid.sat != b.common.sid.sat) { return false; }
        
    if (a.common.sid.code != b.common.sid.code) { return false; }
        
        
    if (a.common.toe.tow != b.common.toe.tow) { return false; }
        
    if (a.common.toe.wn != b.common.toe.wn) { return false; }
        
    if (fabs( a.common.ura - b.common.ura ) > 0.001) { return false; }
        
    if (a.common.fit_interval != b.common.fit_interval) { return false; }
        
    if (a.common.valid != b.common.valid) { return false; }
        
    if (a.common.health_bits != b.common.health_bits) { return false; }
        
    if (fabs( a.gamma - b.gamma ) > 0.001) { return false; }
        
    if (fabs( a.tau - b.tau ) > 0.001) { return false; }
        
    if (fabs( a.d_tau - b.d_tau ) > 0.001) { return false; }
        for (size_t pos_idx = 0; pos_idx < 3; pos_idx++)
        {
            
    if (fabs( a.pos[pos_idx] - b.pos[pos_idx] ) > 0.001) { return false; }
        }
        for (size_t vel_idx = 0; vel_idx < 3; vel_idx++)
        {
            
    if (fabs( a.vel[vel_idx] - b.vel[vel_idx] ) > 0.001) { return false; }
        }
        for (size_t acc_idx = 0; acc_idx < 3; acc_idx++)
        {
            
    if (fabs( a.acc[acc_idx] - b.acc[acc_idx] ) > 0.001) { return false; }
        }
        
    if (a.fcn != b.fcn) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_ephemeris_glo_dep_c_t &a, const sbp_msg_ephemeris_glo_dep_c_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_ephemeris_glo_dep_d_t &a, const sbp_msg_ephemeris_glo_dep_d_t &b) {
  (void)a;
  (void)b;
  
        
        
        
    if (a.common.sid.sat != b.common.sid.sat) { return false; }
        
    if (a.common.sid.code != b.common.sid.code) { return false; }
        
        
    if (a.common.toe.tow != b.common.toe.tow) { return false; }
        
    if (a.common.toe.wn != b.common.toe.wn) { return false; }
        
    if (fabs( a.common.ura - b.common.ura ) > 0.001) { return false; }
        
    if (a.common.fit_interval != b.common.fit_interval) { return false; }
        
    if (a.common.valid != b.common.valid) { return false; }
        
    if (a.common.health_bits != b.common.health_bits) { return false; }
        
    if (fabs( a.gamma - b.gamma ) > 0.001) { return false; }
        
    if (fabs( a.tau - b.tau ) > 0.001) { return false; }
        
    if (fabs( a.d_tau - b.d_tau ) > 0.001) { return false; }
        for (size_t pos_idx = 0; pos_idx < 3; pos_idx++)
        {
            
    if (fabs( a.pos[pos_idx] - b.pos[pos_idx] ) > 0.001) { return false; }
        }
        for (size_t vel_idx = 0; vel_idx < 3; vel_idx++)
        {
            
    if (fabs( a.vel[vel_idx] - b.vel[vel_idx] ) > 0.001) { return false; }
        }
        for (size_t acc_idx = 0; acc_idx < 3; acc_idx++)
        {
            
    if (fabs( a.acc[acc_idx] - b.acc[acc_idx] ) > 0.001) { return false; }
        }
        
    if (a.fcn != b.fcn) { return false; }
        
    if (a.iod != b.iod) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_ephemeris_glo_dep_d_t &a, const sbp_msg_ephemeris_glo_dep_d_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_ephemeris_glo_t &a, const sbp_msg_ephemeris_glo_t &b) {
  (void)a;
  (void)b;
  
        
        
        
    if (a.common.sid.sat != b.common.sid.sat) { return false; }
        
    if (a.common.sid.code != b.common.sid.code) { return false; }
        
        
    if (a.common.toe.tow != b.common.toe.tow) { return false; }
        
    if (a.common.toe.wn != b.common.toe.wn) { return false; }
        
    if (fabs( a.common.ura - b.common.ura ) > 0.001) { return false; }
        
    if (a.common.fit_interval != b.common.fit_interval) { return false; }
        
    if (a.common.valid != b.common.valid) { return false; }
        
    if (a.common.health_bits != b.common.health_bits) { return false; }
        
    if (fabs( a.gamma - b.gamma ) > 0.001) { return false; }
        
    if (fabs( a.tau - b.tau ) > 0.001) { return false; }
        
    if (fabs( a.d_tau - b.d_tau ) > 0.001) { return false; }
        for (size_t pos_idx = 0; pos_idx < 3; pos_idx++)
        {
            
    if (fabs( a.pos[pos_idx] - b.pos[pos_idx] ) > 0.001) { return false; }
        }
        for (size_t vel_idx = 0; vel_idx < 3; vel_idx++)
        {
            
    if (fabs( a.vel[vel_idx] - b.vel[vel_idx] ) > 0.001) { return false; }
        }
        for (size_t acc_idx = 0; acc_idx < 3; acc_idx++)
        {
            
    if (fabs( a.acc[acc_idx] - b.acc[acc_idx] ) > 0.001) { return false; }
        }
        
    if (a.fcn != b.fcn) { return false; }
        
    if (a.iod != b.iod) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_ephemeris_glo_t &a, const sbp_msg_ephemeris_glo_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_ephemeris_dep_d_t &a, const sbp_msg_ephemeris_dep_d_t &b) {
  (void)a;
  (void)b;
  
        
    if (fabs( a.tgd - b.tgd ) > 0.001) { return false; }
        
    if (fabs( a.c_rs - b.c_rs ) > 0.001) { return false; }
        
    if (fabs( a.c_rc - b.c_rc ) > 0.001) { return false; }
        
    if (fabs( a.c_uc - b.c_uc ) > 0.001) { return false; }
        
    if (fabs( a.c_us - b.c_us ) > 0.001) { return false; }
        
    if (fabs( a.c_ic - b.c_ic ) > 0.001) { return false; }
        
    if (fabs( a.c_is - b.c_is ) > 0.001) { return false; }
        
    if (fabs( a.dn - b.dn ) > 0.001) { return false; }
        
    if (fabs( a.m0 - b.m0 ) > 0.001) { return false; }
        
    if (fabs( a.ecc - b.ecc ) > 0.001) { return false; }
        
    if (fabs( a.sqrta - b.sqrta ) > 0.001) { return false; }
        
    if (fabs( a.omega0 - b.omega0 ) > 0.001) { return false; }
        
    if (fabs( a.omegadot - b.omegadot ) > 0.001) { return false; }
        
    if (fabs( a.w - b.w ) > 0.001) { return false; }
        
    if (fabs( a.inc - b.inc ) > 0.001) { return false; }
        
    if (fabs( a.inc_dot - b.inc_dot ) > 0.001) { return false; }
        
    if (fabs( a.af0 - b.af0 ) > 0.001) { return false; }
        
    if (fabs( a.af1 - b.af1 ) > 0.001) { return false; }
        
    if (fabs( a.af2 - b.af2 ) > 0.001) { return false; }
        
    if (fabs( a.toe_tow - b.toe_tow ) > 0.001) { return false; }
        
    if (a.toe_wn != b.toe_wn) { return false; }
        
    if (fabs( a.toc_tow - b.toc_tow ) > 0.001) { return false; }
        
    if (a.toc_wn != b.toc_wn) { return false; }
        
    if (a.valid != b.valid) { return false; }
        
    if (a.healthy != b.healthy) { return false; }
        
        
    if (a.sid.sat != b.sid.sat) { return false; }
        
    if (a.sid.code != b.sid.code) { return false; }
        
    if (a.sid.reserved != b.sid.reserved) { return false; }
        
    if (a.iode != b.iode) { return false; }
        
    if (a.iodc != b.iodc) { return false; }
        
    if (a.reserved != b.reserved) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_ephemeris_dep_d_t &a, const sbp_msg_ephemeris_dep_d_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_ephemeris_dep_a_t &a, const sbp_msg_ephemeris_dep_a_t &b) {
  (void)a;
  (void)b;
  
        
    if (fabs( a.tgd - b.tgd ) > 0.001) { return false; }
        
    if (fabs( a.c_rs - b.c_rs ) > 0.001) { return false; }
        
    if (fabs( a.c_rc - b.c_rc ) > 0.001) { return false; }
        
    if (fabs( a.c_uc - b.c_uc ) > 0.001) { return false; }
        
    if (fabs( a.c_us - b.c_us ) > 0.001) { return false; }
        
    if (fabs( a.c_ic - b.c_ic ) > 0.001) { return false; }
        
    if (fabs( a.c_is - b.c_is ) > 0.001) { return false; }
        
    if (fabs( a.dn - b.dn ) > 0.001) { return false; }
        
    if (fabs( a.m0 - b.m0 ) > 0.001) { return false; }
        
    if (fabs( a.ecc - b.ecc ) > 0.001) { return false; }
        
    if (fabs( a.sqrta - b.sqrta ) > 0.001) { return false; }
        
    if (fabs( a.omega0 - b.omega0 ) > 0.001) { return false; }
        
    if (fabs( a.omegadot - b.omegadot ) > 0.001) { return false; }
        
    if (fabs( a.w - b.w ) > 0.001) { return false; }
        
    if (fabs( a.inc - b.inc ) > 0.001) { return false; }
        
    if (fabs( a.inc_dot - b.inc_dot ) > 0.001) { return false; }
        
    if (fabs( a.af0 - b.af0 ) > 0.001) { return false; }
        
    if (fabs( a.af1 - b.af1 ) > 0.001) { return false; }
        
    if (fabs( a.af2 - b.af2 ) > 0.001) { return false; }
        
    if (fabs( a.toe_tow - b.toe_tow ) > 0.001) { return false; }
        
    if (a.toe_wn != b.toe_wn) { return false; }
        
    if (fabs( a.toc_tow - b.toc_tow ) > 0.001) { return false; }
        
    if (a.toc_wn != b.toc_wn) { return false; }
        
    if (a.valid != b.valid) { return false; }
        
    if (a.healthy != b.healthy) { return false; }
        
    if (a.prn != b.prn) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_ephemeris_dep_a_t &a, const sbp_msg_ephemeris_dep_a_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_ephemeris_dep_b_t &a, const sbp_msg_ephemeris_dep_b_t &b) {
  (void)a;
  (void)b;
  
        
    if (fabs( a.tgd - b.tgd ) > 0.001) { return false; }
        
    if (fabs( a.c_rs - b.c_rs ) > 0.001) { return false; }
        
    if (fabs( a.c_rc - b.c_rc ) > 0.001) { return false; }
        
    if (fabs( a.c_uc - b.c_uc ) > 0.001) { return false; }
        
    if (fabs( a.c_us - b.c_us ) > 0.001) { return false; }
        
    if (fabs( a.c_ic - b.c_ic ) > 0.001) { return false; }
        
    if (fabs( a.c_is - b.c_is ) > 0.001) { return false; }
        
    if (fabs( a.dn - b.dn ) > 0.001) { return false; }
        
    if (fabs( a.m0 - b.m0 ) > 0.001) { return false; }
        
    if (fabs( a.ecc - b.ecc ) > 0.001) { return false; }
        
    if (fabs( a.sqrta - b.sqrta ) > 0.001) { return false; }
        
    if (fabs( a.omega0 - b.omega0 ) > 0.001) { return false; }
        
    if (fabs( a.omegadot - b.omegadot ) > 0.001) { return false; }
        
    if (fabs( a.w - b.w ) > 0.001) { return false; }
        
    if (fabs( a.inc - b.inc ) > 0.001) { return false; }
        
    if (fabs( a.inc_dot - b.inc_dot ) > 0.001) { return false; }
        
    if (fabs( a.af0 - b.af0 ) > 0.001) { return false; }
        
    if (fabs( a.af1 - b.af1 ) > 0.001) { return false; }
        
    if (fabs( a.af2 - b.af2 ) > 0.001) { return false; }
        
    if (fabs( a.toe_tow - b.toe_tow ) > 0.001) { return false; }
        
    if (a.toe_wn != b.toe_wn) { return false; }
        
    if (fabs( a.toc_tow - b.toc_tow ) > 0.001) { return false; }
        
    if (a.toc_wn != b.toc_wn) { return false; }
        
    if (a.valid != b.valid) { return false; }
        
    if (a.healthy != b.healthy) { return false; }
        
    if (a.prn != b.prn) { return false; }
        
    if (a.iode != b.iode) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_ephemeris_dep_b_t &a, const sbp_msg_ephemeris_dep_b_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_ephemeris_dep_c_t &a, const sbp_msg_ephemeris_dep_c_t &b) {
  (void)a;
  (void)b;
  
        
    if (fabs( a.tgd - b.tgd ) > 0.001) { return false; }
        
    if (fabs( a.c_rs - b.c_rs ) > 0.001) { return false; }
        
    if (fabs( a.c_rc - b.c_rc ) > 0.001) { return false; }
        
    if (fabs( a.c_uc - b.c_uc ) > 0.001) { return false; }
        
    if (fabs( a.c_us - b.c_us ) > 0.001) { return false; }
        
    if (fabs( a.c_ic - b.c_ic ) > 0.001) { return false; }
        
    if (fabs( a.c_is - b.c_is ) > 0.001) { return false; }
        
    if (fabs( a.dn - b.dn ) > 0.001) { return false; }
        
    if (fabs( a.m0 - b.m0 ) > 0.001) { return false; }
        
    if (fabs( a.ecc - b.ecc ) > 0.001) { return false; }
        
    if (fabs( a.sqrta - b.sqrta ) > 0.001) { return false; }
        
    if (fabs( a.omega0 - b.omega0 ) > 0.001) { return false; }
        
    if (fabs( a.omegadot - b.omegadot ) > 0.001) { return false; }
        
    if (fabs( a.w - b.w ) > 0.001) { return false; }
        
    if (fabs( a.inc - b.inc ) > 0.001) { return false; }
        
    if (fabs( a.inc_dot - b.inc_dot ) > 0.001) { return false; }
        
    if (fabs( a.af0 - b.af0 ) > 0.001) { return false; }
        
    if (fabs( a.af1 - b.af1 ) > 0.001) { return false; }
        
    if (fabs( a.af2 - b.af2 ) > 0.001) { return false; }
        
    if (fabs( a.toe_tow - b.toe_tow ) > 0.001) { return false; }
        
    if (a.toe_wn != b.toe_wn) { return false; }
        
    if (fabs( a.toc_tow - b.toc_tow ) > 0.001) { return false; }
        
    if (a.toc_wn != b.toc_wn) { return false; }
        
    if (a.valid != b.valid) { return false; }
        
    if (a.healthy != b.healthy) { return false; }
        
        
    if (a.sid.sat != b.sid.sat) { return false; }
        
    if (a.sid.code != b.sid.code) { return false; }
        
    if (a.sid.reserved != b.sid.reserved) { return false; }
        
    if (a.iode != b.iode) { return false; }
        
    if (a.iodc != b.iodc) { return false; }
        
    if (a.reserved != b.reserved) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_ephemeris_dep_c_t &a, const sbp_msg_ephemeris_dep_c_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_observation_header_dep_t &a, const sbp_observation_header_dep_t &b) {
  (void)a;
  (void)b;
  
        
        
    if (a.t.tow != b.t.tow) { return false; }
        
    if (a.t.wn != b.t.wn) { return false; }
        
    if (a.n_obs != b.n_obs) { return false; }

  return true;
}

static inline bool operator!=(const sbp_observation_header_dep_t &a, const sbp_observation_header_dep_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_carrier_phase_dep_a_t &a, const sbp_carrier_phase_dep_a_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.i != b.i) { return false; }
        
    if (a.f != b.f) { return false; }

  return true;
}

static inline bool operator!=(const sbp_carrier_phase_dep_a_t &a, const sbp_carrier_phase_dep_a_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_packed_obs_content_dep_a_t &a, const sbp_packed_obs_content_dep_a_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.P != b.P) { return false; }
        
        
    if (a.L.i != b.L.i) { return false; }
        
    if (a.L.f != b.L.f) { return false; }
        
    if (a.cn0 != b.cn0) { return false; }
        
    if (a.lock != b.lock) { return false; }
        
    if (a.prn != b.prn) { return false; }

  return true;
}

static inline bool operator!=(const sbp_packed_obs_content_dep_a_t &a, const sbp_packed_obs_content_dep_a_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_packed_obs_content_dep_b_t &a, const sbp_packed_obs_content_dep_b_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.P != b.P) { return false; }
        
        
    if (a.L.i != b.L.i) { return false; }
        
    if (a.L.f != b.L.f) { return false; }
        
    if (a.cn0 != b.cn0) { return false; }
        
    if (a.lock != b.lock) { return false; }
        
        
    if (a.sid.sat != b.sid.sat) { return false; }
        
    if (a.sid.code != b.sid.code) { return false; }
        
    if (a.sid.reserved != b.sid.reserved) { return false; }

  return true;
}

static inline bool operator!=(const sbp_packed_obs_content_dep_b_t &a, const sbp_packed_obs_content_dep_b_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_packed_obs_content_dep_c_t &a, const sbp_packed_obs_content_dep_c_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.P != b.P) { return false; }
        
        
    if (a.L.i != b.L.i) { return false; }
        
    if (a.L.f != b.L.f) { return false; }
        
    if (a.cn0 != b.cn0) { return false; }
        
    if (a.lock != b.lock) { return false; }
        
        
    if (a.sid.sat != b.sid.sat) { return false; }
        
    if (a.sid.code != b.sid.code) { return false; }
        
    if (a.sid.reserved != b.sid.reserved) { return false; }

  return true;
}

static inline bool operator!=(const sbp_packed_obs_content_dep_c_t &a, const sbp_packed_obs_content_dep_c_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_obs_dep_a_t &a, const sbp_msg_obs_dep_a_t &b) {
  (void)a;
  (void)b;
  
        
        
        
    if (a.header.t.tow != b.header.t.tow) { return false; }
        
    if (a.header.t.wn != b.header.t.wn) { return false; }
        
    if (a.header.n_obs != b.header.n_obs) { return false; }
          if (a.n_obs != b.n_obs) { return false; }
        for (size_t obs_idx = 0; obs_idx < (size_t)a.n_obs; obs_idx++)
        {
            
        
    if (a.obs[obs_idx].P != b.obs[obs_idx].P) { return false; }
        
        
    if (a.obs[obs_idx].L.i != b.obs[obs_idx].L.i) { return false; }
        
    if (a.obs[obs_idx].L.f != b.obs[obs_idx].L.f) { return false; }
        
    if (a.obs[obs_idx].cn0 != b.obs[obs_idx].cn0) { return false; }
        
    if (a.obs[obs_idx].lock != b.obs[obs_idx].lock) { return false; }
        
    if (a.obs[obs_idx].prn != b.obs[obs_idx].prn) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_obs_dep_a_t &a, const sbp_msg_obs_dep_a_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_obs_dep_b_t &a, const sbp_msg_obs_dep_b_t &b) {
  (void)a;
  (void)b;
  
        
        
        
    if (a.header.t.tow != b.header.t.tow) { return false; }
        
    if (a.header.t.wn != b.header.t.wn) { return false; }
        
    if (a.header.n_obs != b.header.n_obs) { return false; }
          if (a.n_obs != b.n_obs) { return false; }
        for (size_t obs_idx = 0; obs_idx < (size_t)a.n_obs; obs_idx++)
        {
            
        
    if (a.obs[obs_idx].P != b.obs[obs_idx].P) { return false; }
        
        
    if (a.obs[obs_idx].L.i != b.obs[obs_idx].L.i) { return false; }
        
    if (a.obs[obs_idx].L.f != b.obs[obs_idx].L.f) { return false; }
        
    if (a.obs[obs_idx].cn0 != b.obs[obs_idx].cn0) { return false; }
        
    if (a.obs[obs_idx].lock != b.obs[obs_idx].lock) { return false; }
        
        
    if (a.obs[obs_idx].sid.sat != b.obs[obs_idx].sid.sat) { return false; }
        
    if (a.obs[obs_idx].sid.code != b.obs[obs_idx].sid.code) { return false; }
        
    if (a.obs[obs_idx].sid.reserved != b.obs[obs_idx].sid.reserved) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_obs_dep_b_t &a, const sbp_msg_obs_dep_b_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_obs_dep_c_t &a, const sbp_msg_obs_dep_c_t &b) {
  (void)a;
  (void)b;
  
        
        
        
    if (a.header.t.tow != b.header.t.tow) { return false; }
        
    if (a.header.t.wn != b.header.t.wn) { return false; }
        
    if (a.header.n_obs != b.header.n_obs) { return false; }
          if (a.n_obs != b.n_obs) { return false; }
        for (size_t obs_idx = 0; obs_idx < (size_t)a.n_obs; obs_idx++)
        {
            
        
    if (a.obs[obs_idx].P != b.obs[obs_idx].P) { return false; }
        
        
    if (a.obs[obs_idx].L.i != b.obs[obs_idx].L.i) { return false; }
        
    if (a.obs[obs_idx].L.f != b.obs[obs_idx].L.f) { return false; }
        
    if (a.obs[obs_idx].cn0 != b.obs[obs_idx].cn0) { return false; }
        
    if (a.obs[obs_idx].lock != b.obs[obs_idx].lock) { return false; }
        
        
    if (a.obs[obs_idx].sid.sat != b.obs[obs_idx].sid.sat) { return false; }
        
    if (a.obs[obs_idx].sid.code != b.obs[obs_idx].sid.code) { return false; }
        
    if (a.obs[obs_idx].sid.reserved != b.obs[obs_idx].sid.reserved) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_obs_dep_c_t &a, const sbp_msg_obs_dep_c_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_iono_t &a, const sbp_msg_iono_t &b) {
  (void)a;
  (void)b;
  
        
        
    if (a.t_nmct.tow != b.t_nmct.tow) { return false; }
        
    if (a.t_nmct.wn != b.t_nmct.wn) { return false; }
        
    if (fabs( a.a0 - b.a0 ) > 0.001) { return false; }
        
    if (fabs( a.a1 - b.a1 ) > 0.001) { return false; }
        
    if (fabs( a.a2 - b.a2 ) > 0.001) { return false; }
        
    if (fabs( a.a3 - b.a3 ) > 0.001) { return false; }
        
    if (fabs( a.b0 - b.b0 ) > 0.001) { return false; }
        
    if (fabs( a.b1 - b.b1 ) > 0.001) { return false; }
        
    if (fabs( a.b2 - b.b2 ) > 0.001) { return false; }
        
    if (fabs( a.b3 - b.b3 ) > 0.001) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_iono_t &a, const sbp_msg_iono_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_sv_configuration_gps_dep_t &a, const sbp_msg_sv_configuration_gps_dep_t &b) {
  (void)a;
  (void)b;
  
        
        
    if (a.t_nmct.tow != b.t_nmct.tow) { return false; }
        
    if (a.t_nmct.wn != b.t_nmct.wn) { return false; }
        
    if (a.l2c_mask != b.l2c_mask) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_sv_configuration_gps_dep_t &a, const sbp_msg_sv_configuration_gps_dep_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_gnss_capb_t &a, const sbp_gnss_capb_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.gps_active != b.gps_active) { return false; }
        
    if (a.gps_l2c != b.gps_l2c) { return false; }
        
    if (a.gps_l5 != b.gps_l5) { return false; }
        
    if (a.glo_active != b.glo_active) { return false; }
        
    if (a.glo_l2of != b.glo_l2of) { return false; }
        
    if (a.glo_l3 != b.glo_l3) { return false; }
        
    if (a.sbas_active != b.sbas_active) { return false; }
        
    if (a.sbas_l5 != b.sbas_l5) { return false; }
        
    if (a.bds_active != b.bds_active) { return false; }
        
    if (a.bds_d2nav != b.bds_d2nav) { return false; }
        
    if (a.bds_b2 != b.bds_b2) { return false; }
        
    if (a.bds_b2a != b.bds_b2a) { return false; }
        
    if (a.qzss_active != b.qzss_active) { return false; }
        
    if (a.gal_active != b.gal_active) { return false; }
        
    if (a.gal_e5 != b.gal_e5) { return false; }

  return true;
}

static inline bool operator!=(const sbp_gnss_capb_t &a, const sbp_gnss_capb_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_gnss_capb_t &a, const sbp_msg_gnss_capb_t &b) {
  (void)a;
  (void)b;
  
        
        
    if (a.t_nmct.tow != b.t_nmct.tow) { return false; }
        
    if (a.t_nmct.wn != b.t_nmct.wn) { return false; }
        
        
    if (a.gc.gps_active != b.gc.gps_active) { return false; }
        
    if (a.gc.gps_l2c != b.gc.gps_l2c) { return false; }
        
    if (a.gc.gps_l5 != b.gc.gps_l5) { return false; }
        
    if (a.gc.glo_active != b.gc.glo_active) { return false; }
        
    if (a.gc.glo_l2of != b.gc.glo_l2of) { return false; }
        
    if (a.gc.glo_l3 != b.gc.glo_l3) { return false; }
        
    if (a.gc.sbas_active != b.gc.sbas_active) { return false; }
        
    if (a.gc.sbas_l5 != b.gc.sbas_l5) { return false; }
        
    if (a.gc.bds_active != b.gc.bds_active) { return false; }
        
    if (a.gc.bds_d2nav != b.gc.bds_d2nav) { return false; }
        
    if (a.gc.bds_b2 != b.gc.bds_b2) { return false; }
        
    if (a.gc.bds_b2a != b.gc.bds_b2a) { return false; }
        
    if (a.gc.qzss_active != b.gc.qzss_active) { return false; }
        
    if (a.gc.gal_active != b.gc.gal_active) { return false; }
        
    if (a.gc.gal_e5 != b.gc.gal_e5) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_gnss_capb_t &a, const sbp_msg_gnss_capb_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_group_delay_dep_a_t &a, const sbp_msg_group_delay_dep_a_t &b) {
  (void)a;
  (void)b;
  
        
        
    if (a.t_op.tow != b.t_op.tow) { return false; }
        
    if (a.t_op.wn != b.t_op.wn) { return false; }
        
    if (a.prn != b.prn) { return false; }
        
    if (a.valid != b.valid) { return false; }
        
    if (a.tgd != b.tgd) { return false; }
        
    if (a.isc_l1ca != b.isc_l1ca) { return false; }
        
    if (a.isc_l2c != b.isc_l2c) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_group_delay_dep_a_t &a, const sbp_msg_group_delay_dep_a_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_group_delay_dep_b_t &a, const sbp_msg_group_delay_dep_b_t &b) {
  (void)a;
  (void)b;
  
        
        
    if (a.t_op.tow != b.t_op.tow) { return false; }
        
    if (a.t_op.wn != b.t_op.wn) { return false; }
        
        
    if (a.sid.sat != b.sid.sat) { return false; }
        
    if (a.sid.code != b.sid.code) { return false; }
        
    if (a.sid.reserved != b.sid.reserved) { return false; }
        
    if (a.valid != b.valid) { return false; }
        
    if (a.tgd != b.tgd) { return false; }
        
    if (a.isc_l1ca != b.isc_l1ca) { return false; }
        
    if (a.isc_l2c != b.isc_l2c) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_group_delay_dep_b_t &a, const sbp_msg_group_delay_dep_b_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_group_delay_t &a, const sbp_msg_group_delay_t &b) {
  (void)a;
  (void)b;
  
        
        
    if (a.t_op.tow != b.t_op.tow) { return false; }
        
    if (a.t_op.wn != b.t_op.wn) { return false; }
        
        
    if (a.sid.sat != b.sid.sat) { return false; }
        
    if (a.sid.code != b.sid.code) { return false; }
        
    if (a.valid != b.valid) { return false; }
        
    if (a.tgd != b.tgd) { return false; }
        
    if (a.isc_l1ca != b.isc_l1ca) { return false; }
        
    if (a.isc_l2c != b.isc_l2c) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_group_delay_t &a, const sbp_msg_group_delay_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_almanac_common_content_t &a, const sbp_almanac_common_content_t &b) {
  (void)a;
  (void)b;
  
        
        
    if (a.sid.sat != b.sid.sat) { return false; }
        
    if (a.sid.code != b.sid.code) { return false; }
        
        
    if (a.toa.tow != b.toa.tow) { return false; }
        
    if (a.toa.wn != b.toa.wn) { return false; }
        
    if (fabs( a.ura - b.ura ) > 0.001) { return false; }
        
    if (a.fit_interval != b.fit_interval) { return false; }
        
    if (a.valid != b.valid) { return false; }
        
    if (a.health_bits != b.health_bits) { return false; }

  return true;
}

static inline bool operator!=(const sbp_almanac_common_content_t &a, const sbp_almanac_common_content_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_almanac_common_content_dep_t &a, const sbp_almanac_common_content_dep_t &b) {
  (void)a;
  (void)b;
  
        
        
    if (a.sid.sat != b.sid.sat) { return false; }
        
    if (a.sid.code != b.sid.code) { return false; }
        
    if (a.sid.reserved != b.sid.reserved) { return false; }
        
        
    if (a.toa.tow != b.toa.tow) { return false; }
        
    if (a.toa.wn != b.toa.wn) { return false; }
        
    if (fabs( a.ura - b.ura ) > 0.001) { return false; }
        
    if (a.fit_interval != b.fit_interval) { return false; }
        
    if (a.valid != b.valid) { return false; }
        
    if (a.health_bits != b.health_bits) { return false; }

  return true;
}

static inline bool operator!=(const sbp_almanac_common_content_dep_t &a, const sbp_almanac_common_content_dep_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_almanac_gps_dep_t &a, const sbp_msg_almanac_gps_dep_t &b) {
  (void)a;
  (void)b;
  
        
        
        
    if (a.common.sid.sat != b.common.sid.sat) { return false; }
        
    if (a.common.sid.code != b.common.sid.code) { return false; }
        
    if (a.common.sid.reserved != b.common.sid.reserved) { return false; }
        
        
    if (a.common.toa.tow != b.common.toa.tow) { return false; }
        
    if (a.common.toa.wn != b.common.toa.wn) { return false; }
        
    if (fabs( a.common.ura - b.common.ura ) > 0.001) { return false; }
        
    if (a.common.fit_interval != b.common.fit_interval) { return false; }
        
    if (a.common.valid != b.common.valid) { return false; }
        
    if (a.common.health_bits != b.common.health_bits) { return false; }
        
    if (fabs( a.m0 - b.m0 ) > 0.001) { return false; }
        
    if (fabs( a.ecc - b.ecc ) > 0.001) { return false; }
        
    if (fabs( a.sqrta - b.sqrta ) > 0.001) { return false; }
        
    if (fabs( a.omega0 - b.omega0 ) > 0.001) { return false; }
        
    if (fabs( a.omegadot - b.omegadot ) > 0.001) { return false; }
        
    if (fabs( a.w - b.w ) > 0.001) { return false; }
        
    if (fabs( a.inc - b.inc ) > 0.001) { return false; }
        
    if (fabs( a.af0 - b.af0 ) > 0.001) { return false; }
        
    if (fabs( a.af1 - b.af1 ) > 0.001) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_almanac_gps_dep_t &a, const sbp_msg_almanac_gps_dep_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_almanac_gps_t &a, const sbp_msg_almanac_gps_t &b) {
  (void)a;
  (void)b;
  
        
        
        
    if (a.common.sid.sat != b.common.sid.sat) { return false; }
        
    if (a.common.sid.code != b.common.sid.code) { return false; }
        
        
    if (a.common.toa.tow != b.common.toa.tow) { return false; }
        
    if (a.common.toa.wn != b.common.toa.wn) { return false; }
        
    if (fabs( a.common.ura - b.common.ura ) > 0.001) { return false; }
        
    if (a.common.fit_interval != b.common.fit_interval) { return false; }
        
    if (a.common.valid != b.common.valid) { return false; }
        
    if (a.common.health_bits != b.common.health_bits) { return false; }
        
    if (fabs( a.m0 - b.m0 ) > 0.001) { return false; }
        
    if (fabs( a.ecc - b.ecc ) > 0.001) { return false; }
        
    if (fabs( a.sqrta - b.sqrta ) > 0.001) { return false; }
        
    if (fabs( a.omega0 - b.omega0 ) > 0.001) { return false; }
        
    if (fabs( a.omegadot - b.omegadot ) > 0.001) { return false; }
        
    if (fabs( a.w - b.w ) > 0.001) { return false; }
        
    if (fabs( a.inc - b.inc ) > 0.001) { return false; }
        
    if (fabs( a.af0 - b.af0 ) > 0.001) { return false; }
        
    if (fabs( a.af1 - b.af1 ) > 0.001) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_almanac_gps_t &a, const sbp_msg_almanac_gps_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_almanac_glo_dep_t &a, const sbp_msg_almanac_glo_dep_t &b) {
  (void)a;
  (void)b;
  
        
        
        
    if (a.common.sid.sat != b.common.sid.sat) { return false; }
        
    if (a.common.sid.code != b.common.sid.code) { return false; }
        
    if (a.common.sid.reserved != b.common.sid.reserved) { return false; }
        
        
    if (a.common.toa.tow != b.common.toa.tow) { return false; }
        
    if (a.common.toa.wn != b.common.toa.wn) { return false; }
        
    if (fabs( a.common.ura - b.common.ura ) > 0.001) { return false; }
        
    if (a.common.fit_interval != b.common.fit_interval) { return false; }
        
    if (a.common.valid != b.common.valid) { return false; }
        
    if (a.common.health_bits != b.common.health_bits) { return false; }
        
    if (fabs( a.lambda_na - b.lambda_na ) > 0.001) { return false; }
        
    if (fabs( a.t_lambda_na - b.t_lambda_na ) > 0.001) { return false; }
        
    if (fabs( a.i - b.i ) > 0.001) { return false; }
        
    if (fabs( a.t - b.t ) > 0.001) { return false; }
        
    if (fabs( a.t_dot - b.t_dot ) > 0.001) { return false; }
        
    if (fabs( a.epsilon - b.epsilon ) > 0.001) { return false; }
        
    if (fabs( a.omega - b.omega ) > 0.001) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_almanac_glo_dep_t &a, const sbp_msg_almanac_glo_dep_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_almanac_glo_t &a, const sbp_msg_almanac_glo_t &b) {
  (void)a;
  (void)b;
  
        
        
        
    if (a.common.sid.sat != b.common.sid.sat) { return false; }
        
    if (a.common.sid.code != b.common.sid.code) { return false; }
        
        
    if (a.common.toa.tow != b.common.toa.tow) { return false; }
        
    if (a.common.toa.wn != b.common.toa.wn) { return false; }
        
    if (fabs( a.common.ura - b.common.ura ) > 0.001) { return false; }
        
    if (a.common.fit_interval != b.common.fit_interval) { return false; }
        
    if (a.common.valid != b.common.valid) { return false; }
        
    if (a.common.health_bits != b.common.health_bits) { return false; }
        
    if (fabs( a.lambda_na - b.lambda_na ) > 0.001) { return false; }
        
    if (fabs( a.t_lambda_na - b.t_lambda_na ) > 0.001) { return false; }
        
    if (fabs( a.i - b.i ) > 0.001) { return false; }
        
    if (fabs( a.t - b.t ) > 0.001) { return false; }
        
    if (fabs( a.t_dot - b.t_dot ) > 0.001) { return false; }
        
    if (fabs( a.epsilon - b.epsilon ) > 0.001) { return false; }
        
    if (fabs( a.omega - b.omega ) > 0.001) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_almanac_glo_t &a, const sbp_msg_almanac_glo_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_glo_biases_t &a, const sbp_msg_glo_biases_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.mask != b.mask) { return false; }
        
    if (a.l1ca_bias != b.l1ca_bias) { return false; }
        
    if (a.l1p_bias != b.l1p_bias) { return false; }
        
    if (a.l2ca_bias != b.l2ca_bias) { return false; }
        
    if (a.l2p_bias != b.l2p_bias) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_glo_biases_t &a, const sbp_msg_glo_biases_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_sv_az_el_t &a, const sbp_sv_az_el_t &b) {
  (void)a;
  (void)b;
  
        
        
    if (a.sid.sat != b.sid.sat) { return false; }
        
    if (a.sid.code != b.sid.code) { return false; }
        
    if (a.az != b.az) { return false; }
        
    if (a.el != b.el) { return false; }

  return true;
}

static inline bool operator!=(const sbp_sv_az_el_t &a, const sbp_sv_az_el_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_sv_az_el_t &a, const sbp_msg_sv_az_el_t &b) {
  (void)a;
  (void)b;
  
          if (a.n_azel != b.n_azel) { return false; }
        for (size_t azel_idx = 0; azel_idx < (size_t)a.n_azel; azel_idx++)
        {
            
        
        
    if (a.azel[azel_idx].sid.sat != b.azel[azel_idx].sid.sat) { return false; }
        
    if (a.azel[azel_idx].sid.code != b.azel[azel_idx].sid.code) { return false; }
        
    if (a.azel[azel_idx].az != b.azel[azel_idx].az) { return false; }
        
    if (a.azel[azel_idx].el != b.azel[azel_idx].el) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_sv_az_el_t &a, const sbp_msg_sv_az_el_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_osr_t &a, const sbp_msg_osr_t &b) {
  (void)a;
  (void)b;
  
        
        
        
    if (a.header.t.tow != b.header.t.tow) { return false; }
        
    if (a.header.t.ns_residual != b.header.t.ns_residual) { return false; }
        
    if (a.header.t.wn != b.header.t.wn) { return false; }
        
    if (a.header.n_obs != b.header.n_obs) { return false; }
          if (a.n_obs != b.n_obs) { return false; }
        for (size_t obs_idx = 0; obs_idx < (size_t)a.n_obs; obs_idx++)
        {
            
        
    if (a.obs[obs_idx].P != b.obs[obs_idx].P) { return false; }
        
        
    if (a.obs[obs_idx].L.i != b.obs[obs_idx].L.i) { return false; }
        
    if (a.obs[obs_idx].L.f != b.obs[obs_idx].L.f) { return false; }
        
    if (a.obs[obs_idx].lock != b.obs[obs_idx].lock) { return false; }
        
    if (a.obs[obs_idx].flags != b.obs[obs_idx].flags) { return false; }
        
        
    if (a.obs[obs_idx].sid.sat != b.obs[obs_idx].sid.sat) { return false; }
        
    if (a.obs[obs_idx].sid.code != b.obs[obs_idx].sid.code) { return false; }
        
    if (a.obs[obs_idx].iono_std != b.obs[obs_idx].iono_std) { return false; }
        
    if (a.obs[obs_idx].tropo_std != b.obs[obs_idx].tropo_std) { return false; }
        
    if (a.obs[obs_idx].range_std != b.obs[obs_idx].range_std) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_osr_t &a, const sbp_msg_osr_t &b) {
  return !(a == b);
}
#endif

#endif
