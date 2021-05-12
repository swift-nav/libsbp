#ifndef LIBSBP_NAVIGATION_OPERATORS_H
#define LIBSBP_NAVIGATION_OPERATORS_H

#ifndef LIBSBP_NAVIGATION_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/navigation.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_gps_time_t &a, const sbp_msg_gps_time_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.wn != b.wn) { return false; }
        
    if (a.tow != b.tow) { return false; }
        
    if (a.ns_residual != b.ns_residual) { return false; }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_gps_time_t &a, const sbp_msg_gps_time_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_gps_time_gnss_t &a, const sbp_msg_gps_time_gnss_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.wn != b.wn) { return false; }
        
    if (a.tow != b.tow) { return false; }
        
    if (a.ns_residual != b.ns_residual) { return false; }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_gps_time_gnss_t &a, const sbp_msg_gps_time_gnss_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_utc_time_t &a, const sbp_msg_utc_time_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.flags != b.flags) { return false; }
        
    if (a.tow != b.tow) { return false; }
        
    if (a.year != b.year) { return false; }
        
    if (a.month != b.month) { return false; }
        
    if (a.day != b.day) { return false; }
        
    if (a.hours != b.hours) { return false; }
        
    if (a.minutes != b.minutes) { return false; }
        
    if (a.seconds != b.seconds) { return false; }
        
    if (a.ns != b.ns) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_utc_time_t &a, const sbp_msg_utc_time_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_utc_time_gnss_t &a, const sbp_msg_utc_time_gnss_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.flags != b.flags) { return false; }
        
    if (a.tow != b.tow) { return false; }
        
    if (a.year != b.year) { return false; }
        
    if (a.month != b.month) { return false; }
        
    if (a.day != b.day) { return false; }
        
    if (a.hours != b.hours) { return false; }
        
    if (a.minutes != b.minutes) { return false; }
        
    if (a.seconds != b.seconds) { return false; }
        
    if (a.ns != b.ns) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_utc_time_gnss_t &a, const sbp_msg_utc_time_gnss_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_dops_t &a, const sbp_msg_dops_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tow != b.tow) { return false; }
        
    if (a.gdop != b.gdop) { return false; }
        
    if (a.pdop != b.pdop) { return false; }
        
    if (a.tdop != b.tdop) { return false; }
        
    if (a.hdop != b.hdop) { return false; }
        
    if (a.vdop != b.vdop) { return false; }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_dops_t &a, const sbp_msg_dops_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_pos_ecef_t &a, const sbp_msg_pos_ecef_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tow != b.tow) { return false; }
        
    if (fabs( a.x - b.x ) > 0.001) { return false; }
        
    if (fabs( a.y - b.y ) > 0.001) { return false; }
        
    if (fabs( a.z - b.z ) > 0.001) { return false; }
        
    if (a.accuracy != b.accuracy) { return false; }
        
    if (a.n_sats != b.n_sats) { return false; }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_pos_ecef_t &a, const sbp_msg_pos_ecef_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_pos_ecef_cov_t &a, const sbp_msg_pos_ecef_cov_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tow != b.tow) { return false; }
        
    if (fabs( a.x - b.x ) > 0.001) { return false; }
        
    if (fabs( a.y - b.y ) > 0.001) { return false; }
        
    if (fabs( a.z - b.z ) > 0.001) { return false; }
        
    if (fabs( a.cov_x_x - b.cov_x_x ) > 0.001) { return false; }
        
    if (fabs( a.cov_x_y - b.cov_x_y ) > 0.001) { return false; }
        
    if (fabs( a.cov_x_z - b.cov_x_z ) > 0.001) { return false; }
        
    if (fabs( a.cov_y_y - b.cov_y_y ) > 0.001) { return false; }
        
    if (fabs( a.cov_y_z - b.cov_y_z ) > 0.001) { return false; }
        
    if (fabs( a.cov_z_z - b.cov_z_z ) > 0.001) { return false; }
        
    if (a.n_sats != b.n_sats) { return false; }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_pos_ecef_cov_t &a, const sbp_msg_pos_ecef_cov_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_pos_llh_t &a, const sbp_msg_pos_llh_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tow != b.tow) { return false; }
        
    if (fabs( a.lat - b.lat ) > 0.001) { return false; }
        
    if (fabs( a.lon - b.lon ) > 0.001) { return false; }
        
    if (fabs( a.height - b.height ) > 0.001) { return false; }
        
    if (a.h_accuracy != b.h_accuracy) { return false; }
        
    if (a.v_accuracy != b.v_accuracy) { return false; }
        
    if (a.n_sats != b.n_sats) { return false; }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_pos_llh_t &a, const sbp_msg_pos_llh_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_pos_llh_cov_t &a, const sbp_msg_pos_llh_cov_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tow != b.tow) { return false; }
        
    if (fabs( a.lat - b.lat ) > 0.001) { return false; }
        
    if (fabs( a.lon - b.lon ) > 0.001) { return false; }
        
    if (fabs( a.height - b.height ) > 0.001) { return false; }
        
    if (fabs( a.cov_n_n - b.cov_n_n ) > 0.001) { return false; }
        
    if (fabs( a.cov_n_e - b.cov_n_e ) > 0.001) { return false; }
        
    if (fabs( a.cov_n_d - b.cov_n_d ) > 0.001) { return false; }
        
    if (fabs( a.cov_e_e - b.cov_e_e ) > 0.001) { return false; }
        
    if (fabs( a.cov_e_d - b.cov_e_d ) > 0.001) { return false; }
        
    if (fabs( a.cov_d_d - b.cov_d_d ) > 0.001) { return false; }
        
    if (a.n_sats != b.n_sats) { return false; }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_pos_llh_cov_t &a, const sbp_msg_pos_llh_cov_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_baseline_ecef_t &a, const sbp_msg_baseline_ecef_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tow != b.tow) { return false; }
        
    if (a.x != b.x) { return false; }
        
    if (a.y != b.y) { return false; }
        
    if (a.z != b.z) { return false; }
        
    if (a.accuracy != b.accuracy) { return false; }
        
    if (a.n_sats != b.n_sats) { return false; }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_baseline_ecef_t &a, const sbp_msg_baseline_ecef_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_baseline_ned_t &a, const sbp_msg_baseline_ned_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tow != b.tow) { return false; }
        
    if (a.n != b.n) { return false; }
        
    if (a.e != b.e) { return false; }
        
    if (a.d != b.d) { return false; }
        
    if (a.h_accuracy != b.h_accuracy) { return false; }
        
    if (a.v_accuracy != b.v_accuracy) { return false; }
        
    if (a.n_sats != b.n_sats) { return false; }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_baseline_ned_t &a, const sbp_msg_baseline_ned_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_vel_ecef_t &a, const sbp_msg_vel_ecef_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tow != b.tow) { return false; }
        
    if (a.x != b.x) { return false; }
        
    if (a.y != b.y) { return false; }
        
    if (a.z != b.z) { return false; }
        
    if (a.accuracy != b.accuracy) { return false; }
        
    if (a.n_sats != b.n_sats) { return false; }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_vel_ecef_t &a, const sbp_msg_vel_ecef_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_vel_ecef_cov_t &a, const sbp_msg_vel_ecef_cov_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tow != b.tow) { return false; }
        
    if (a.x != b.x) { return false; }
        
    if (a.y != b.y) { return false; }
        
    if (a.z != b.z) { return false; }
        
    if (fabs( a.cov_x_x - b.cov_x_x ) > 0.001) { return false; }
        
    if (fabs( a.cov_x_y - b.cov_x_y ) > 0.001) { return false; }
        
    if (fabs( a.cov_x_z - b.cov_x_z ) > 0.001) { return false; }
        
    if (fabs( a.cov_y_y - b.cov_y_y ) > 0.001) { return false; }
        
    if (fabs( a.cov_y_z - b.cov_y_z ) > 0.001) { return false; }
        
    if (fabs( a.cov_z_z - b.cov_z_z ) > 0.001) { return false; }
        
    if (a.n_sats != b.n_sats) { return false; }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_vel_ecef_cov_t &a, const sbp_msg_vel_ecef_cov_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_vel_ned_t &a, const sbp_msg_vel_ned_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tow != b.tow) { return false; }
        
    if (a.n != b.n) { return false; }
        
    if (a.e != b.e) { return false; }
        
    if (a.d != b.d) { return false; }
        
    if (a.h_accuracy != b.h_accuracy) { return false; }
        
    if (a.v_accuracy != b.v_accuracy) { return false; }
        
    if (a.n_sats != b.n_sats) { return false; }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_vel_ned_t &a, const sbp_msg_vel_ned_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_vel_ned_cov_t &a, const sbp_msg_vel_ned_cov_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tow != b.tow) { return false; }
        
    if (a.n != b.n) { return false; }
        
    if (a.e != b.e) { return false; }
        
    if (a.d != b.d) { return false; }
        
    if (fabs( a.cov_n_n - b.cov_n_n ) > 0.001) { return false; }
        
    if (fabs( a.cov_n_e - b.cov_n_e ) > 0.001) { return false; }
        
    if (fabs( a.cov_n_d - b.cov_n_d ) > 0.001) { return false; }
        
    if (fabs( a.cov_e_e - b.cov_e_e ) > 0.001) { return false; }
        
    if (fabs( a.cov_e_d - b.cov_e_d ) > 0.001) { return false; }
        
    if (fabs( a.cov_d_d - b.cov_d_d ) > 0.001) { return false; }
        
    if (a.n_sats != b.n_sats) { return false; }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_vel_ned_cov_t &a, const sbp_msg_vel_ned_cov_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_pos_ecef_gnss_t &a, const sbp_msg_pos_ecef_gnss_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tow != b.tow) { return false; }
        
    if (fabs( a.x - b.x ) > 0.001) { return false; }
        
    if (fabs( a.y - b.y ) > 0.001) { return false; }
        
    if (fabs( a.z - b.z ) > 0.001) { return false; }
        
    if (a.accuracy != b.accuracy) { return false; }
        
    if (a.n_sats != b.n_sats) { return false; }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_pos_ecef_gnss_t &a, const sbp_msg_pos_ecef_gnss_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_pos_ecef_cov_gnss_t &a, const sbp_msg_pos_ecef_cov_gnss_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tow != b.tow) { return false; }
        
    if (fabs( a.x - b.x ) > 0.001) { return false; }
        
    if (fabs( a.y - b.y ) > 0.001) { return false; }
        
    if (fabs( a.z - b.z ) > 0.001) { return false; }
        
    if (fabs( a.cov_x_x - b.cov_x_x ) > 0.001) { return false; }
        
    if (fabs( a.cov_x_y - b.cov_x_y ) > 0.001) { return false; }
        
    if (fabs( a.cov_x_z - b.cov_x_z ) > 0.001) { return false; }
        
    if (fabs( a.cov_y_y - b.cov_y_y ) > 0.001) { return false; }
        
    if (fabs( a.cov_y_z - b.cov_y_z ) > 0.001) { return false; }
        
    if (fabs( a.cov_z_z - b.cov_z_z ) > 0.001) { return false; }
        
    if (a.n_sats != b.n_sats) { return false; }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_pos_ecef_cov_gnss_t &a, const sbp_msg_pos_ecef_cov_gnss_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_pos_llh_gnss_t &a, const sbp_msg_pos_llh_gnss_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tow != b.tow) { return false; }
        
    if (fabs( a.lat - b.lat ) > 0.001) { return false; }
        
    if (fabs( a.lon - b.lon ) > 0.001) { return false; }
        
    if (fabs( a.height - b.height ) > 0.001) { return false; }
        
    if (a.h_accuracy != b.h_accuracy) { return false; }
        
    if (a.v_accuracy != b.v_accuracy) { return false; }
        
    if (a.n_sats != b.n_sats) { return false; }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_pos_llh_gnss_t &a, const sbp_msg_pos_llh_gnss_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_pos_llh_cov_gnss_t &a, const sbp_msg_pos_llh_cov_gnss_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tow != b.tow) { return false; }
        
    if (fabs( a.lat - b.lat ) > 0.001) { return false; }
        
    if (fabs( a.lon - b.lon ) > 0.001) { return false; }
        
    if (fabs( a.height - b.height ) > 0.001) { return false; }
        
    if (fabs( a.cov_n_n - b.cov_n_n ) > 0.001) { return false; }
        
    if (fabs( a.cov_n_e - b.cov_n_e ) > 0.001) { return false; }
        
    if (fabs( a.cov_n_d - b.cov_n_d ) > 0.001) { return false; }
        
    if (fabs( a.cov_e_e - b.cov_e_e ) > 0.001) { return false; }
        
    if (fabs( a.cov_e_d - b.cov_e_d ) > 0.001) { return false; }
        
    if (fabs( a.cov_d_d - b.cov_d_d ) > 0.001) { return false; }
        
    if (a.n_sats != b.n_sats) { return false; }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_pos_llh_cov_gnss_t &a, const sbp_msg_pos_llh_cov_gnss_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_vel_ecef_gnss_t &a, const sbp_msg_vel_ecef_gnss_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tow != b.tow) { return false; }
        
    if (a.x != b.x) { return false; }
        
    if (a.y != b.y) { return false; }
        
    if (a.z != b.z) { return false; }
        
    if (a.accuracy != b.accuracy) { return false; }
        
    if (a.n_sats != b.n_sats) { return false; }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_vel_ecef_gnss_t &a, const sbp_msg_vel_ecef_gnss_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_vel_ecef_cov_gnss_t &a, const sbp_msg_vel_ecef_cov_gnss_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tow != b.tow) { return false; }
        
    if (a.x != b.x) { return false; }
        
    if (a.y != b.y) { return false; }
        
    if (a.z != b.z) { return false; }
        
    if (fabs( a.cov_x_x - b.cov_x_x ) > 0.001) { return false; }
        
    if (fabs( a.cov_x_y - b.cov_x_y ) > 0.001) { return false; }
        
    if (fabs( a.cov_x_z - b.cov_x_z ) > 0.001) { return false; }
        
    if (fabs( a.cov_y_y - b.cov_y_y ) > 0.001) { return false; }
        
    if (fabs( a.cov_y_z - b.cov_y_z ) > 0.001) { return false; }
        
    if (fabs( a.cov_z_z - b.cov_z_z ) > 0.001) { return false; }
        
    if (a.n_sats != b.n_sats) { return false; }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_vel_ecef_cov_gnss_t &a, const sbp_msg_vel_ecef_cov_gnss_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_vel_ned_gnss_t &a, const sbp_msg_vel_ned_gnss_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tow != b.tow) { return false; }
        
    if (a.n != b.n) { return false; }
        
    if (a.e != b.e) { return false; }
        
    if (a.d != b.d) { return false; }
        
    if (a.h_accuracy != b.h_accuracy) { return false; }
        
    if (a.v_accuracy != b.v_accuracy) { return false; }
        
    if (a.n_sats != b.n_sats) { return false; }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_vel_ned_gnss_t &a, const sbp_msg_vel_ned_gnss_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_vel_ned_cov_gnss_t &a, const sbp_msg_vel_ned_cov_gnss_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tow != b.tow) { return false; }
        
    if (a.n != b.n) { return false; }
        
    if (a.e != b.e) { return false; }
        
    if (a.d != b.d) { return false; }
        
    if (fabs( a.cov_n_n - b.cov_n_n ) > 0.001) { return false; }
        
    if (fabs( a.cov_n_e - b.cov_n_e ) > 0.001) { return false; }
        
    if (fabs( a.cov_n_d - b.cov_n_d ) > 0.001) { return false; }
        
    if (fabs( a.cov_e_e - b.cov_e_e ) > 0.001) { return false; }
        
    if (fabs( a.cov_e_d - b.cov_e_d ) > 0.001) { return false; }
        
    if (fabs( a.cov_d_d - b.cov_d_d ) > 0.001) { return false; }
        
    if (a.n_sats != b.n_sats) { return false; }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_vel_ned_cov_gnss_t &a, const sbp_msg_vel_ned_cov_gnss_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_vel_body_t &a, const sbp_msg_vel_body_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tow != b.tow) { return false; }
        
    if (a.x != b.x) { return false; }
        
    if (a.y != b.y) { return false; }
        
    if (a.z != b.z) { return false; }
        
    if (fabs( a.cov_x_x - b.cov_x_x ) > 0.001) { return false; }
        
    if (fabs( a.cov_x_y - b.cov_x_y ) > 0.001) { return false; }
        
    if (fabs( a.cov_x_z - b.cov_x_z ) > 0.001) { return false; }
        
    if (fabs( a.cov_y_y - b.cov_y_y ) > 0.001) { return false; }
        
    if (fabs( a.cov_y_z - b.cov_y_z ) > 0.001) { return false; }
        
    if (fabs( a.cov_z_z - b.cov_z_z ) > 0.001) { return false; }
        
    if (a.n_sats != b.n_sats) { return false; }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_vel_body_t &a, const sbp_msg_vel_body_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_age_corrections_t &a, const sbp_msg_age_corrections_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tow != b.tow) { return false; }
        
    if (a.age != b.age) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_age_corrections_t &a, const sbp_msg_age_corrections_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_gps_time_dep_a_t &a, const sbp_msg_gps_time_dep_a_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.wn != b.wn) { return false; }
        
    if (a.tow != b.tow) { return false; }
        
    if (a.ns_residual != b.ns_residual) { return false; }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_gps_time_dep_a_t &a, const sbp_msg_gps_time_dep_a_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_dops_dep_a_t &a, const sbp_msg_dops_dep_a_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tow != b.tow) { return false; }
        
    if (a.gdop != b.gdop) { return false; }
        
    if (a.pdop != b.pdop) { return false; }
        
    if (a.tdop != b.tdop) { return false; }
        
    if (a.hdop != b.hdop) { return false; }
        
    if (a.vdop != b.vdop) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_dops_dep_a_t &a, const sbp_msg_dops_dep_a_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_pos_ecef_dep_a_t &a, const sbp_msg_pos_ecef_dep_a_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tow != b.tow) { return false; }
        
    if (fabs( a.x - b.x ) > 0.001) { return false; }
        
    if (fabs( a.y - b.y ) > 0.001) { return false; }
        
    if (fabs( a.z - b.z ) > 0.001) { return false; }
        
    if (a.accuracy != b.accuracy) { return false; }
        
    if (a.n_sats != b.n_sats) { return false; }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_pos_ecef_dep_a_t &a, const sbp_msg_pos_ecef_dep_a_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_pos_llh_dep_a_t &a, const sbp_msg_pos_llh_dep_a_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tow != b.tow) { return false; }
        
    if (fabs( a.lat - b.lat ) > 0.001) { return false; }
        
    if (fabs( a.lon - b.lon ) > 0.001) { return false; }
        
    if (fabs( a.height - b.height ) > 0.001) { return false; }
        
    if (a.h_accuracy != b.h_accuracy) { return false; }
        
    if (a.v_accuracy != b.v_accuracy) { return false; }
        
    if (a.n_sats != b.n_sats) { return false; }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_pos_llh_dep_a_t &a, const sbp_msg_pos_llh_dep_a_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_baseline_ecef_dep_a_t &a, const sbp_msg_baseline_ecef_dep_a_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tow != b.tow) { return false; }
        
    if (a.x != b.x) { return false; }
        
    if (a.y != b.y) { return false; }
        
    if (a.z != b.z) { return false; }
        
    if (a.accuracy != b.accuracy) { return false; }
        
    if (a.n_sats != b.n_sats) { return false; }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_baseline_ecef_dep_a_t &a, const sbp_msg_baseline_ecef_dep_a_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_baseline_ned_dep_a_t &a, const sbp_msg_baseline_ned_dep_a_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tow != b.tow) { return false; }
        
    if (a.n != b.n) { return false; }
        
    if (a.e != b.e) { return false; }
        
    if (a.d != b.d) { return false; }
        
    if (a.h_accuracy != b.h_accuracy) { return false; }
        
    if (a.v_accuracy != b.v_accuracy) { return false; }
        
    if (a.n_sats != b.n_sats) { return false; }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_baseline_ned_dep_a_t &a, const sbp_msg_baseline_ned_dep_a_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_vel_ecef_dep_a_t &a, const sbp_msg_vel_ecef_dep_a_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tow != b.tow) { return false; }
        
    if (a.x != b.x) { return false; }
        
    if (a.y != b.y) { return false; }
        
    if (a.z != b.z) { return false; }
        
    if (a.accuracy != b.accuracy) { return false; }
        
    if (a.n_sats != b.n_sats) { return false; }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_vel_ecef_dep_a_t &a, const sbp_msg_vel_ecef_dep_a_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_vel_ned_dep_a_t &a, const sbp_msg_vel_ned_dep_a_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tow != b.tow) { return false; }
        
    if (a.n != b.n) { return false; }
        
    if (a.e != b.e) { return false; }
        
    if (a.d != b.d) { return false; }
        
    if (a.h_accuracy != b.h_accuracy) { return false; }
        
    if (a.v_accuracy != b.v_accuracy) { return false; }
        
    if (a.n_sats != b.n_sats) { return false; }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_vel_ned_dep_a_t &a, const sbp_msg_vel_ned_dep_a_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_baseline_heading_dep_a_t &a, const sbp_msg_baseline_heading_dep_a_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tow != b.tow) { return false; }
        
    if (a.heading != b.heading) { return false; }
        
    if (a.n_sats != b.n_sats) { return false; }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_baseline_heading_dep_a_t &a, const sbp_msg_baseline_heading_dep_a_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_protection_level_dep_a_t &a, const sbp_msg_protection_level_dep_a_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tow != b.tow) { return false; }
        
    if (a.vpl != b.vpl) { return false; }
        
    if (a.hpl != b.hpl) { return false; }
        
    if (fabs( a.lat - b.lat ) > 0.001) { return false; }
        
    if (fabs( a.lon - b.lon ) > 0.001) { return false; }
        
    if (fabs( a.height - b.height ) > 0.001) { return false; }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_protection_level_dep_a_t &a, const sbp_msg_protection_level_dep_a_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_protection_level_t &a, const sbp_msg_protection_level_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tow != b.tow) { return false; }
        
    if (a.wn != b.wn) { return false; }
        
    if (a.hpl != b.hpl) { return false; }
        
    if (a.vpl != b.vpl) { return false; }
        
    if (a.atpl != b.atpl) { return false; }
        
    if (a.ctpl != b.ctpl) { return false; }
        
    if (a.hvpl != b.hvpl) { return false; }
        
    if (a.vvpl != b.vvpl) { return false; }
        
    if (a.hopl != b.hopl) { return false; }
        
    if (a.popl != b.popl) { return false; }
        
    if (a.ropl != b.ropl) { return false; }
        
    if (fabs( a.lat - b.lat ) > 0.001) { return false; }
        
    if (fabs( a.lon - b.lon ) > 0.001) { return false; }
        
    if (fabs( a.height - b.height ) > 0.001) { return false; }
        
    if (a.v_x != b.v_x) { return false; }
        
    if (a.v_y != b.v_y) { return false; }
        
    if (a.v_z != b.v_z) { return false; }
        
    if (a.roll != b.roll) { return false; }
        
    if (a.pitch != b.pitch) { return false; }
        
    if (a.heading != b.heading) { return false; }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_protection_level_t &a, const sbp_msg_protection_level_t &b) {
  return !(a == b);
}
#endif

#endif
