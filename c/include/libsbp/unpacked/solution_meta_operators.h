#ifndef LIBSBP_SOLUTION_META_OPERATORS_H
#define LIBSBP_SOLUTION_META_OPERATORS_H

#ifndef LIBSBP_SOLUTION_META_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/solution_meta.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#ifdef __cplusplus
static inline bool operator== ( const sbp_solution_input_type_t &a, const sbp_solution_input_type_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.sensor_type != b.sensor_type) { return false; }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_solution_input_type_t &a, const sbp_solution_input_type_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_soln_meta_dep_a_t &a, const sbp_msg_soln_meta_dep_a_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.pdop != b.pdop) { return false; }
        
    if (a.hdop != b.hdop) { return false; }
        
    if (a.vdop != b.vdop) { return false; }
        
    if (a.n_sats != b.n_sats) { return false; }
        
    if (a.age_corrections != b.age_corrections) { return false; }
        
    if (a.alignment_status != b.alignment_status) { return false; }
        
    if (a.last_used_gnss_pos_tow != b.last_used_gnss_pos_tow) { return false; }
        
    if (a.last_used_gnss_vel_tow != b.last_used_gnss_vel_tow) { return false; }
          if (a.sol_in_count != b.sol_in_count) { return false; }
        for (size_t sol_in_idx = 0; sol_in_idx < (size_t)a.sol_in_count; sol_in_idx++)
        {
            
        
    if (a.sol_in[sol_in_idx].sensor_type != b.sol_in[sol_in_idx].sensor_type) { return false; }
        
    if (a.sol_in[sol_in_idx].flags != b.sol_in[sol_in_idx].flags) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_soln_meta_dep_a_t &a, const sbp_msg_soln_meta_dep_a_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_soln_meta_t &a, const sbp_msg_soln_meta_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tow != b.tow) { return false; }
        
    if (a.pdop != b.pdop) { return false; }
        
    if (a.hdop != b.hdop) { return false; }
        
    if (a.vdop != b.vdop) { return false; }
        
    if (a.age_corrections != b.age_corrections) { return false; }
        
    if (a.age_gnss != b.age_gnss) { return false; }
          if (a.sol_in_count != b.sol_in_count) { return false; }
        for (size_t sol_in_idx = 0; sol_in_idx < (size_t)a.sol_in_count; sol_in_idx++)
        {
            
        
    if (a.sol_in[sol_in_idx].sensor_type != b.sol_in[sol_in_idx].sensor_type) { return false; }
        
    if (a.sol_in[sol_in_idx].flags != b.sol_in[sol_in_idx].flags) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_soln_meta_t &a, const sbp_msg_soln_meta_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_gnss_input_type_t &a, const sbp_gnss_input_type_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_gnss_input_type_t &a, const sbp_gnss_input_type_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_imu_input_type_t &a, const sbp_imu_input_type_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_imu_input_type_t &a, const sbp_imu_input_type_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_odo_input_type_t &a, const sbp_odo_input_type_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_odo_input_type_t &a, const sbp_odo_input_type_t &b) {
  return !(a == b);
}
#endif

#endif
