#ifndef LIBSBP_SSR_OPERATORS_H
#define LIBSBP_SSR_OPERATORS_H

#ifndef LIBSBP_SSR_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/ssr.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#ifdef __cplusplus
static inline bool operator== ( const sbp_code_biases_content_t &a, const sbp_code_biases_content_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.code != b.code) { return false; }
        
    if (a.value != b.value) { return false; }

  return true;
}

static inline bool operator!=(const sbp_code_biases_content_t &a, const sbp_code_biases_content_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_phase_biases_content_t &a, const sbp_phase_biases_content_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.code != b.code) { return false; }
        
    if (a.integer_indicator != b.integer_indicator) { return false; }
        
    if (a.widelane_integer_indicator != b.widelane_integer_indicator) { return false; }
        
    if (a.discontinuity_counter != b.discontinuity_counter) { return false; }
        
    if (a.bias != b.bias) { return false; }

  return true;
}

static inline bool operator!=(const sbp_phase_biases_content_t &a, const sbp_phase_biases_content_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_stec_header_t &a, const sbp_stec_header_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tile_set_id != b.tile_set_id) { return false; }
        
    if (a.tile_id != b.tile_id) { return false; }
        
        
    if (a.time.tow != b.time.tow) { return false; }
        
    if (a.time.wn != b.time.wn) { return false; }
        
    if (a.num_msgs != b.num_msgs) { return false; }
        
    if (a.seq_num != b.seq_num) { return false; }
        
    if (a.update_interval != b.update_interval) { return false; }
        
    if (a.iod_atmo != b.iod_atmo) { return false; }

  return true;
}

static inline bool operator!=(const sbp_stec_header_t &a, const sbp_stec_header_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_gridded_correction_header_t &a, const sbp_gridded_correction_header_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tile_set_id != b.tile_set_id) { return false; }
        
    if (a.tile_id != b.tile_id) { return false; }
        
        
    if (a.time.tow != b.time.tow) { return false; }
        
    if (a.time.wn != b.time.wn) { return false; }
        
    if (a.num_msgs != b.num_msgs) { return false; }
        
    if (a.seq_num != b.seq_num) { return false; }
        
    if (a.update_interval != b.update_interval) { return false; }
        
    if (a.iod_atmo != b.iod_atmo) { return false; }
        
    if (a.tropo_quality_indicator != b.tropo_quality_indicator) { return false; }

  return true;
}

static inline bool operator!=(const sbp_gridded_correction_header_t &a, const sbp_gridded_correction_header_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_stec_sat_element_t &a, const sbp_stec_sat_element_t &b) {
  (void)a;
  (void)b;
  
        
        
    if (a.sv_id.satId != b.sv_id.satId) { return false; }
        
    if (a.sv_id.constellation != b.sv_id.constellation) { return false; }
        
    if (a.stec_quality_indicator != b.stec_quality_indicator) { return false; }
        for (size_t stec_coeff_idx = 0; stec_coeff_idx < 4; stec_coeff_idx++)
        {
            
    if (a.stec_coeff[stec_coeff_idx] != b.stec_coeff[stec_coeff_idx]) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_stec_sat_element_t &a, const sbp_stec_sat_element_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_tropospheric_delay_correction_no_std_t &a, const sbp_tropospheric_delay_correction_no_std_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.hydro != b.hydro) { return false; }
        
    if (a.wet != b.wet) { return false; }

  return true;
}

static inline bool operator!=(const sbp_tropospheric_delay_correction_no_std_t &a, const sbp_tropospheric_delay_correction_no_std_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_tropospheric_delay_correction_t &a, const sbp_tropospheric_delay_correction_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.hydro != b.hydro) { return false; }
        
    if (a.wet != b.wet) { return false; }
        
    if (a.stddev != b.stddev) { return false; }

  return true;
}

static inline bool operator!=(const sbp_tropospheric_delay_correction_t &a, const sbp_tropospheric_delay_correction_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_stec_residual_no_std_t &a, const sbp_stec_residual_no_std_t &b) {
  (void)a;
  (void)b;
  
        
        
    if (a.sv_id.satId != b.sv_id.satId) { return false; }
        
    if (a.sv_id.constellation != b.sv_id.constellation) { return false; }
        
    if (a.residual != b.residual) { return false; }

  return true;
}

static inline bool operator!=(const sbp_stec_residual_no_std_t &a, const sbp_stec_residual_no_std_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_stec_residual_t &a, const sbp_stec_residual_t &b) {
  (void)a;
  (void)b;
  
        
        
    if (a.sv_id.satId != b.sv_id.satId) { return false; }
        
    if (a.sv_id.constellation != b.sv_id.constellation) { return false; }
        
    if (a.residual != b.residual) { return false; }
        
    if (a.stddev != b.stddev) { return false; }

  return true;
}

static inline bool operator!=(const sbp_stec_residual_t &a, const sbp_stec_residual_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_grid_element_no_std_t &a, const sbp_grid_element_no_std_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.index != b.index) { return false; }
        
        
    if (a.tropo_delay_correction.hydro != b.tropo_delay_correction.hydro) { return false; }
        
    if (a.tropo_delay_correction.wet != b.tropo_delay_correction.wet) { return false; }
          if (a.n_stec_residuals != b.n_stec_residuals) { return false; }
        for (size_t stec_residuals_idx = 0; stec_residuals_idx < (size_t)a.n_stec_residuals; stec_residuals_idx++)
        {
            
        
        
    if (a.stec_residuals[stec_residuals_idx].sv_id.satId != b.stec_residuals[stec_residuals_idx].sv_id.satId) { return false; }
        
    if (a.stec_residuals[stec_residuals_idx].sv_id.constellation != b.stec_residuals[stec_residuals_idx].sv_id.constellation) { return false; }
        
    if (a.stec_residuals[stec_residuals_idx].residual != b.stec_residuals[stec_residuals_idx].residual) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_grid_element_no_std_t &a, const sbp_grid_element_no_std_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_grid_element_t &a, const sbp_grid_element_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.index != b.index) { return false; }
        
        
    if (a.tropo_delay_correction.hydro != b.tropo_delay_correction.hydro) { return false; }
        
    if (a.tropo_delay_correction.wet != b.tropo_delay_correction.wet) { return false; }
        
    if (a.tropo_delay_correction.stddev != b.tropo_delay_correction.stddev) { return false; }
          if (a.n_stec_residuals != b.n_stec_residuals) { return false; }
        for (size_t stec_residuals_idx = 0; stec_residuals_idx < (size_t)a.n_stec_residuals; stec_residuals_idx++)
        {
            
        
        
    if (a.stec_residuals[stec_residuals_idx].sv_id.satId != b.stec_residuals[stec_residuals_idx].sv_id.satId) { return false; }
        
    if (a.stec_residuals[stec_residuals_idx].sv_id.constellation != b.stec_residuals[stec_residuals_idx].sv_id.constellation) { return false; }
        
    if (a.stec_residuals[stec_residuals_idx].residual != b.stec_residuals[stec_residuals_idx].residual) { return false; }
        
    if (a.stec_residuals[stec_residuals_idx].stddev != b.stec_residuals[stec_residuals_idx].stddev) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_grid_element_t &a, const sbp_grid_element_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_ssr_orbit_clock_t &a, const sbp_msg_ssr_orbit_clock_t &b) {
  (void)a;
  (void)b;
  
        
        
    if (a.time.tow != b.time.tow) { return false; }
        
    if (a.time.wn != b.time.wn) { return false; }
        
        
    if (a.sid.sat != b.sid.sat) { return false; }
        
    if (a.sid.code != b.sid.code) { return false; }
        
    if (a.update_interval != b.update_interval) { return false; }
        
    if (a.iod_ssr != b.iod_ssr) { return false; }
        
    if (a.iod != b.iod) { return false; }
        
    if (a.radial != b.radial) { return false; }
        
    if (a.along != b.along) { return false; }
        
    if (a.cross != b.cross) { return false; }
        
    if (a.dot_radial != b.dot_radial) { return false; }
        
    if (a.dot_along != b.dot_along) { return false; }
        
    if (a.dot_cross != b.dot_cross) { return false; }
        
    if (a.c0 != b.c0) { return false; }
        
    if (a.c1 != b.c1) { return false; }
        
    if (a.c2 != b.c2) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_ssr_orbit_clock_t &a, const sbp_msg_ssr_orbit_clock_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_ssr_code_biases_t &a, const sbp_msg_ssr_code_biases_t &b) {
  (void)a;
  (void)b;
  
        
        
    if (a.time.tow != b.time.tow) { return false; }
        
    if (a.time.wn != b.time.wn) { return false; }
        
        
    if (a.sid.sat != b.sid.sat) { return false; }
        
    if (a.sid.code != b.sid.code) { return false; }
        
    if (a.update_interval != b.update_interval) { return false; }
        
    if (a.iod_ssr != b.iod_ssr) { return false; }
          if (a.n_biases != b.n_biases) { return false; }
        for (size_t biases_idx = 0; biases_idx < (size_t)a.n_biases; biases_idx++)
        {
            
        
    if (a.biases[biases_idx].code != b.biases[biases_idx].code) { return false; }
        
    if (a.biases[biases_idx].value != b.biases[biases_idx].value) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_ssr_code_biases_t &a, const sbp_msg_ssr_code_biases_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_ssr_phase_biases_t &a, const sbp_msg_ssr_phase_biases_t &b) {
  (void)a;
  (void)b;
  
        
        
    if (a.time.tow != b.time.tow) { return false; }
        
    if (a.time.wn != b.time.wn) { return false; }
        
        
    if (a.sid.sat != b.sid.sat) { return false; }
        
    if (a.sid.code != b.sid.code) { return false; }
        
    if (a.update_interval != b.update_interval) { return false; }
        
    if (a.iod_ssr != b.iod_ssr) { return false; }
        
    if (a.dispersive_bias != b.dispersive_bias) { return false; }
        
    if (a.mw_consistency != b.mw_consistency) { return false; }
        
    if (a.yaw != b.yaw) { return false; }
        
    if (a.yaw_rate != b.yaw_rate) { return false; }
          if (a.n_biases != b.n_biases) { return false; }
        for (size_t biases_idx = 0; biases_idx < (size_t)a.n_biases; biases_idx++)
        {
            
        
    if (a.biases[biases_idx].code != b.biases[biases_idx].code) { return false; }
        
    if (a.biases[biases_idx].integer_indicator != b.biases[biases_idx].integer_indicator) { return false; }
        
    if (a.biases[biases_idx].widelane_integer_indicator != b.biases[biases_idx].widelane_integer_indicator) { return false; }
        
    if (a.biases[biases_idx].discontinuity_counter != b.biases[biases_idx].discontinuity_counter) { return false; }
        
    if (a.biases[biases_idx].bias != b.biases[biases_idx].bias) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_ssr_phase_biases_t &a, const sbp_msg_ssr_phase_biases_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_ssr_stec_correction_t &a, const sbp_msg_ssr_stec_correction_t &b) {
  (void)a;
  (void)b;
  
        
        
    if (a.header.tile_set_id != b.header.tile_set_id) { return false; }
        
    if (a.header.tile_id != b.header.tile_id) { return false; }
        
        
    if (a.header.time.tow != b.header.time.tow) { return false; }
        
    if (a.header.time.wn != b.header.time.wn) { return false; }
        
    if (a.header.num_msgs != b.header.num_msgs) { return false; }
        
    if (a.header.seq_num != b.header.seq_num) { return false; }
        
    if (a.header.update_interval != b.header.update_interval) { return false; }
        
    if (a.header.iod_atmo != b.header.iod_atmo) { return false; }
          if (a.n_stec_sat_list != b.n_stec_sat_list) { return false; }
        for (size_t stec_sat_list_idx = 0; stec_sat_list_idx < (size_t)a.n_stec_sat_list; stec_sat_list_idx++)
        {
            
        
        
    if (a.stec_sat_list[stec_sat_list_idx].sv_id.satId != b.stec_sat_list[stec_sat_list_idx].sv_id.satId) { return false; }
        
    if (a.stec_sat_list[stec_sat_list_idx].sv_id.constellation != b.stec_sat_list[stec_sat_list_idx].sv_id.constellation) { return false; }
        
    if (a.stec_sat_list[stec_sat_list_idx].stec_quality_indicator != b.stec_sat_list[stec_sat_list_idx].stec_quality_indicator) { return false; }
        for (size_t stec_sat_liststec_sat_list_idxstec_coeff_idx = 0; stec_sat_liststec_sat_list_idxstec_coeff_idx < 4; stec_sat_liststec_sat_list_idxstec_coeff_idx++)
        {
            
    if (a.stec_sat_list[stec_sat_list_idx].stec_coeff[stec_sat_liststec_sat_list_idxstec_coeff_idx] != b.stec_sat_list[stec_sat_list_idx].stec_coeff[stec_sat_liststec_sat_list_idxstec_coeff_idx]) { return false; }
        }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_ssr_stec_correction_t &a, const sbp_msg_ssr_stec_correction_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_ssr_gridded_correction_t &a, const sbp_msg_ssr_gridded_correction_t &b) {
  (void)a;
  (void)b;
  
        
        
    if (a.header.tile_set_id != b.header.tile_set_id) { return false; }
        
    if (a.header.tile_id != b.header.tile_id) { return false; }
        
        
    if (a.header.time.tow != b.header.time.tow) { return false; }
        
    if (a.header.time.wn != b.header.time.wn) { return false; }
        
    if (a.header.num_msgs != b.header.num_msgs) { return false; }
        
    if (a.header.seq_num != b.header.seq_num) { return false; }
        
    if (a.header.update_interval != b.header.update_interval) { return false; }
        
    if (a.header.iod_atmo != b.header.iod_atmo) { return false; }
        
    if (a.header.tropo_quality_indicator != b.header.tropo_quality_indicator) { return false; }
        
        
    if (a.element.index != b.element.index) { return false; }
        
        
    if (a.element.tropo_delay_correction.hydro != b.element.tropo_delay_correction.hydro) { return false; }
        
    if (a.element.tropo_delay_correction.wet != b.element.tropo_delay_correction.wet) { return false; }
        
    if (a.element.tropo_delay_correction.stddev != b.element.tropo_delay_correction.stddev) { return false; }
          if (a.element.n_stec_residuals != b.element.n_stec_residuals) { return false; }
        for (size_t elementstec_residuals_idx = 0; elementstec_residuals_idx < (size_t)a.element.n_stec_residuals; elementstec_residuals_idx++)
        {
            
        
        
    if (a.element.stec_residuals[elementstec_residuals_idx].sv_id.satId != b.element.stec_residuals[elementstec_residuals_idx].sv_id.satId) { return false; }
        
    if (a.element.stec_residuals[elementstec_residuals_idx].sv_id.constellation != b.element.stec_residuals[elementstec_residuals_idx].sv_id.constellation) { return false; }
        
    if (a.element.stec_residuals[elementstec_residuals_idx].residual != b.element.stec_residuals[elementstec_residuals_idx].residual) { return false; }
        
    if (a.element.stec_residuals[elementstec_residuals_idx].stddev != b.element.stec_residuals[elementstec_residuals_idx].stddev) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_ssr_gridded_correction_t &a, const sbp_msg_ssr_gridded_correction_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_ssr_tile_definition_t &a, const sbp_msg_ssr_tile_definition_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tile_set_id != b.tile_set_id) { return false; }
        
    if (a.tile_id != b.tile_id) { return false; }
        
    if (a.corner_nw_lat != b.corner_nw_lat) { return false; }
        
    if (a.corner_nw_lon != b.corner_nw_lon) { return false; }
        
    if (a.spacing_lat != b.spacing_lat) { return false; }
        
    if (a.spacing_lon != b.spacing_lon) { return false; }
        
    if (a.rows != b.rows) { return false; }
        
    if (a.cols != b.cols) { return false; }
        
    if (a.bitmask != b.bitmask) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_ssr_tile_definition_t &a, const sbp_msg_ssr_tile_definition_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_satellite_apc_t &a, const sbp_satellite_apc_t &b) {
  (void)a;
  (void)b;
  
        
        
    if (a.sid.sat != b.sid.sat) { return false; }
        
    if (a.sid.code != b.sid.code) { return false; }
        
    if (a.sat_info != b.sat_info) { return false; }
        
    if (a.svn != b.svn) { return false; }
        for (size_t pco_idx = 0; pco_idx < 3; pco_idx++)
        {
            
    if (a.pco[pco_idx] != b.pco[pco_idx]) { return false; }
        }
        for (size_t pcv_idx = 0; pcv_idx < 21; pcv_idx++)
        {
            
    if (a.pcv[pcv_idx] != b.pcv[pcv_idx]) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_satellite_apc_t &a, const sbp_satellite_apc_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_ssr_satellite_apc_t &a, const sbp_msg_ssr_satellite_apc_t &b) {
  (void)a;
  (void)b;
  
          if (a.n_apc != b.n_apc) { return false; }
        for (size_t apc_idx = 0; apc_idx < (size_t)a.n_apc; apc_idx++)
        {
            
        
        
    if (a.apc[apc_idx].sid.sat != b.apc[apc_idx].sid.sat) { return false; }
        
    if (a.apc[apc_idx].sid.code != b.apc[apc_idx].sid.code) { return false; }
        
    if (a.apc[apc_idx].sat_info != b.apc[apc_idx].sat_info) { return false; }
        
    if (a.apc[apc_idx].svn != b.apc[apc_idx].svn) { return false; }
        for (size_t apcapc_idxpco_idx = 0; apcapc_idxpco_idx < 3; apcapc_idxpco_idx++)
        {
            
    if (a.apc[apc_idx].pco[apcapc_idxpco_idx] != b.apc[apc_idx].pco[apcapc_idxpco_idx]) { return false; }
        }
        for (size_t apcapc_idxpcv_idx = 0; apcapc_idxpcv_idx < 21; apcapc_idxpcv_idx++)
        {
            
    if (a.apc[apc_idx].pcv[apcapc_idxpcv_idx] != b.apc[apc_idx].pcv[apcapc_idxpcv_idx]) { return false; }
        }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_ssr_satellite_apc_t &a, const sbp_msg_ssr_satellite_apc_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_ssr_orbit_clock_dep_a_t &a, const sbp_msg_ssr_orbit_clock_dep_a_t &b) {
  (void)a;
  (void)b;
  
        
        
    if (a.time.tow != b.time.tow) { return false; }
        
    if (a.time.wn != b.time.wn) { return false; }
        
        
    if (a.sid.sat != b.sid.sat) { return false; }
        
    if (a.sid.code != b.sid.code) { return false; }
        
    if (a.update_interval != b.update_interval) { return false; }
        
    if (a.iod_ssr != b.iod_ssr) { return false; }
        
    if (a.iod != b.iod) { return false; }
        
    if (a.radial != b.radial) { return false; }
        
    if (a.along != b.along) { return false; }
        
    if (a.cross != b.cross) { return false; }
        
    if (a.dot_radial != b.dot_radial) { return false; }
        
    if (a.dot_along != b.dot_along) { return false; }
        
    if (a.dot_cross != b.dot_cross) { return false; }
        
    if (a.c0 != b.c0) { return false; }
        
    if (a.c1 != b.c1) { return false; }
        
    if (a.c2 != b.c2) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_ssr_orbit_clock_dep_a_t &a, const sbp_msg_ssr_orbit_clock_dep_a_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_stec_header_dep_a_t &a, const sbp_stec_header_dep_a_t &b) {
  (void)a;
  (void)b;
  
        
        
    if (a.time.tow != b.time.tow) { return false; }
        
    if (a.time.wn != b.time.wn) { return false; }
        
    if (a.num_msgs != b.num_msgs) { return false; }
        
    if (a.seq_num != b.seq_num) { return false; }
        
    if (a.update_interval != b.update_interval) { return false; }
        
    if (a.iod_atmo != b.iod_atmo) { return false; }

  return true;
}

static inline bool operator!=(const sbp_stec_header_dep_a_t &a, const sbp_stec_header_dep_a_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_gridded_correction_header_dep_a_t &a, const sbp_gridded_correction_header_dep_a_t &b) {
  (void)a;
  (void)b;
  
        
        
    if (a.time.tow != b.time.tow) { return false; }
        
    if (a.time.wn != b.time.wn) { return false; }
        
    if (a.num_msgs != b.num_msgs) { return false; }
        
    if (a.seq_num != b.seq_num) { return false; }
        
    if (a.update_interval != b.update_interval) { return false; }
        
    if (a.iod_atmo != b.iod_atmo) { return false; }
        
    if (a.tropo_quality_indicator != b.tropo_quality_indicator) { return false; }

  return true;
}

static inline bool operator!=(const sbp_gridded_correction_header_dep_a_t &a, const sbp_gridded_correction_header_dep_a_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_grid_definition_header_dep_a_t &a, const sbp_grid_definition_header_dep_a_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.region_size_inverse != b.region_size_inverse) { return false; }
        
    if (a.area_width != b.area_width) { return false; }
        
    if (a.lat_nw_corner_enc != b.lat_nw_corner_enc) { return false; }
        
    if (a.lon_nw_corner_enc != b.lon_nw_corner_enc) { return false; }
        
    if (a.num_msgs != b.num_msgs) { return false; }
        
    if (a.seq_num != b.seq_num) { return false; }

  return true;
}

static inline bool operator!=(const sbp_grid_definition_header_dep_a_t &a, const sbp_grid_definition_header_dep_a_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_ssr_stec_correction_dep_a_t &a, const sbp_msg_ssr_stec_correction_dep_a_t &b) {
  (void)a;
  (void)b;
  
        
        
        
    if (a.header.time.tow != b.header.time.tow) { return false; }
        
    if (a.header.time.wn != b.header.time.wn) { return false; }
        
    if (a.header.num_msgs != b.header.num_msgs) { return false; }
        
    if (a.header.seq_num != b.header.seq_num) { return false; }
        
    if (a.header.update_interval != b.header.update_interval) { return false; }
        
    if (a.header.iod_atmo != b.header.iod_atmo) { return false; }
          if (a.n_stec_sat_list != b.n_stec_sat_list) { return false; }
        for (size_t stec_sat_list_idx = 0; stec_sat_list_idx < (size_t)a.n_stec_sat_list; stec_sat_list_idx++)
        {
            
        
        
    if (a.stec_sat_list[stec_sat_list_idx].sv_id.satId != b.stec_sat_list[stec_sat_list_idx].sv_id.satId) { return false; }
        
    if (a.stec_sat_list[stec_sat_list_idx].sv_id.constellation != b.stec_sat_list[stec_sat_list_idx].sv_id.constellation) { return false; }
        
    if (a.stec_sat_list[stec_sat_list_idx].stec_quality_indicator != b.stec_sat_list[stec_sat_list_idx].stec_quality_indicator) { return false; }
        for (size_t stec_sat_liststec_sat_list_idxstec_coeff_idx = 0; stec_sat_liststec_sat_list_idxstec_coeff_idx < 4; stec_sat_liststec_sat_list_idxstec_coeff_idx++)
        {
            
    if (a.stec_sat_list[stec_sat_list_idx].stec_coeff[stec_sat_liststec_sat_list_idxstec_coeff_idx] != b.stec_sat_list[stec_sat_list_idx].stec_coeff[stec_sat_liststec_sat_list_idxstec_coeff_idx]) { return false; }
        }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_ssr_stec_correction_dep_a_t &a, const sbp_msg_ssr_stec_correction_dep_a_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &a, const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &b) {
  (void)a;
  (void)b;
  
        
        
        
    if (a.header.time.tow != b.header.time.tow) { return false; }
        
    if (a.header.time.wn != b.header.time.wn) { return false; }
        
    if (a.header.num_msgs != b.header.num_msgs) { return false; }
        
    if (a.header.seq_num != b.header.seq_num) { return false; }
        
    if (a.header.update_interval != b.header.update_interval) { return false; }
        
    if (a.header.iod_atmo != b.header.iod_atmo) { return false; }
        
    if (a.header.tropo_quality_indicator != b.header.tropo_quality_indicator) { return false; }
        
        
    if (a.element.index != b.element.index) { return false; }
        
        
    if (a.element.tropo_delay_correction.hydro != b.element.tropo_delay_correction.hydro) { return false; }
        
    if (a.element.tropo_delay_correction.wet != b.element.tropo_delay_correction.wet) { return false; }
          if (a.element.n_stec_residuals != b.element.n_stec_residuals) { return false; }
        for (size_t elementstec_residuals_idx = 0; elementstec_residuals_idx < (size_t)a.element.n_stec_residuals; elementstec_residuals_idx++)
        {
            
        
        
    if (a.element.stec_residuals[elementstec_residuals_idx].sv_id.satId != b.element.stec_residuals[elementstec_residuals_idx].sv_id.satId) { return false; }
        
    if (a.element.stec_residuals[elementstec_residuals_idx].sv_id.constellation != b.element.stec_residuals[elementstec_residuals_idx].sv_id.constellation) { return false; }
        
    if (a.element.stec_residuals[elementstec_residuals_idx].residual != b.element.stec_residuals[elementstec_residuals_idx].residual) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &a, const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_ssr_gridded_correction_dep_a_t &a, const sbp_msg_ssr_gridded_correction_dep_a_t &b) {
  (void)a;
  (void)b;
  
        
        
        
    if (a.header.time.tow != b.header.time.tow) { return false; }
        
    if (a.header.time.wn != b.header.time.wn) { return false; }
        
    if (a.header.num_msgs != b.header.num_msgs) { return false; }
        
    if (a.header.seq_num != b.header.seq_num) { return false; }
        
    if (a.header.update_interval != b.header.update_interval) { return false; }
        
    if (a.header.iod_atmo != b.header.iod_atmo) { return false; }
        
    if (a.header.tropo_quality_indicator != b.header.tropo_quality_indicator) { return false; }
        
        
    if (a.element.index != b.element.index) { return false; }
        
        
    if (a.element.tropo_delay_correction.hydro != b.element.tropo_delay_correction.hydro) { return false; }
        
    if (a.element.tropo_delay_correction.wet != b.element.tropo_delay_correction.wet) { return false; }
        
    if (a.element.tropo_delay_correction.stddev != b.element.tropo_delay_correction.stddev) { return false; }
          if (a.element.n_stec_residuals != b.element.n_stec_residuals) { return false; }
        for (size_t elementstec_residuals_idx = 0; elementstec_residuals_idx < (size_t)a.element.n_stec_residuals; elementstec_residuals_idx++)
        {
            
        
        
    if (a.element.stec_residuals[elementstec_residuals_idx].sv_id.satId != b.element.stec_residuals[elementstec_residuals_idx].sv_id.satId) { return false; }
        
    if (a.element.stec_residuals[elementstec_residuals_idx].sv_id.constellation != b.element.stec_residuals[elementstec_residuals_idx].sv_id.constellation) { return false; }
        
    if (a.element.stec_residuals[elementstec_residuals_idx].residual != b.element.stec_residuals[elementstec_residuals_idx].residual) { return false; }
        
    if (a.element.stec_residuals[elementstec_residuals_idx].stddev != b.element.stec_residuals[elementstec_residuals_idx].stddev) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_ssr_gridded_correction_dep_a_t &a, const sbp_msg_ssr_gridded_correction_dep_a_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_ssr_grid_definition_dep_a_t &a, const sbp_msg_ssr_grid_definition_dep_a_t &b) {
  (void)a;
  (void)b;
  
        
        
    if (a.header.region_size_inverse != b.header.region_size_inverse) { return false; }
        
    if (a.header.area_width != b.header.area_width) { return false; }
        
    if (a.header.lat_nw_corner_enc != b.header.lat_nw_corner_enc) { return false; }
        
    if (a.header.lon_nw_corner_enc != b.header.lon_nw_corner_enc) { return false; }
        
    if (a.header.num_msgs != b.header.num_msgs) { return false; }
        
    if (a.header.seq_num != b.header.seq_num) { return false; }
          if (a.n_rle_list != b.n_rle_list) { return false; }
        for (size_t rle_list_idx = 0; rle_list_idx < (size_t)a.n_rle_list; rle_list_idx++)
        {
            
    if (a.rle_list[rle_list_idx] != b.rle_list[rle_list_idx]) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_ssr_grid_definition_dep_a_t &a, const sbp_msg_ssr_grid_definition_dep_a_t &b) {
  return !(a == b);
}
#endif

#endif
