#ifndef LIBSBP_UNPACKED_SSR_PRIVATE_H
#define LIBSBP_UNPACKED_SSR_PRIVATE_H

#include <stdbool.h>

#include <libsbp/new/ssr.h>
#include <libsbp/internal/new/common.h>
#include <libsbp/internal/new/gnss.h>

#ifdef __cplusplus
  extern "C" {
#endif

bool pack_sbp_code_biases_content_t(sbp_pack_ctx_t *ctx, const sbp_code_biases_content_t *msg);
bool unpack_sbp_code_biases_content_t(sbp_unpack_ctx_t *ctx, sbp_code_biases_content_t *msg);

bool pack_sbp_phase_biases_content_t(sbp_pack_ctx_t *ctx, const sbp_phase_biases_content_t *msg);
bool unpack_sbp_phase_biases_content_t(sbp_unpack_ctx_t *ctx, sbp_phase_biases_content_t *msg);

bool pack_sbp_stec_header_t(sbp_pack_ctx_t *ctx, const sbp_stec_header_t *msg);
bool unpack_sbp_stec_header_t(sbp_unpack_ctx_t *ctx, sbp_stec_header_t *msg);

bool pack_sbp_gridded_correction_header_t(sbp_pack_ctx_t *ctx, const sbp_gridded_correction_header_t *msg);
bool unpack_sbp_gridded_correction_header_t(sbp_unpack_ctx_t *ctx, sbp_gridded_correction_header_t *msg);

bool pack_sbp_stec_sat_element_t(sbp_pack_ctx_t *ctx, const sbp_stec_sat_element_t *msg);
bool unpack_sbp_stec_sat_element_t(sbp_unpack_ctx_t *ctx, sbp_stec_sat_element_t *msg);

bool pack_sbp_tropospheric_delay_correction_no_std_t(sbp_pack_ctx_t *ctx, const sbp_tropospheric_delay_correction_no_std_t *msg);
bool unpack_sbp_tropospheric_delay_correction_no_std_t(sbp_unpack_ctx_t *ctx, sbp_tropospheric_delay_correction_no_std_t *msg);

bool pack_sbp_tropospheric_delay_correction_t(sbp_pack_ctx_t *ctx, const sbp_tropospheric_delay_correction_t *msg);
bool unpack_sbp_tropospheric_delay_correction_t(sbp_unpack_ctx_t *ctx, sbp_tropospheric_delay_correction_t *msg);

bool pack_sbp_stec_residual_no_std_t(sbp_pack_ctx_t *ctx, const sbp_stec_residual_no_std_t *msg);
bool unpack_sbp_stec_residual_no_std_t(sbp_unpack_ctx_t *ctx, sbp_stec_residual_no_std_t *msg);

bool pack_sbp_stec_residual_t(sbp_pack_ctx_t *ctx, const sbp_stec_residual_t *msg);
bool unpack_sbp_stec_residual_t(sbp_unpack_ctx_t *ctx, sbp_stec_residual_t *msg);

bool pack_sbp_msg_ssr_orbit_clock_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_orbit_clock_t *msg);
bool unpack_sbp_msg_ssr_orbit_clock_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_orbit_clock_t *msg);

bool pack_sbp_msg_ssr_code_biases_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_code_biases_t *msg);
bool unpack_sbp_msg_ssr_code_biases_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_code_biases_t *msg);

bool pack_sbp_msg_ssr_phase_biases_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_phase_biases_t *msg);
bool unpack_sbp_msg_ssr_phase_biases_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_phase_biases_t *msg);

bool pack_sbp_msg_ssr_stec_correction_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_stec_correction_t *msg);
bool unpack_sbp_msg_ssr_stec_correction_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_stec_correction_t *msg);

bool pack_sbp_msg_ssr_gridded_correction_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_gridded_correction_t *msg);
bool unpack_sbp_msg_ssr_gridded_correction_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_gridded_correction_t *msg);

bool pack_sbp_msg_ssr_tile_definition_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_tile_definition_t *msg);
bool unpack_sbp_msg_ssr_tile_definition_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_tile_definition_t *msg);

bool pack_sbp_satellite_apc_t(sbp_pack_ctx_t *ctx, const sbp_satellite_apc_t *msg);
bool unpack_sbp_satellite_apc_t(sbp_unpack_ctx_t *ctx, sbp_satellite_apc_t *msg);

bool pack_sbp_msg_ssr_satellite_apc_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_satellite_apc_t *msg);
bool unpack_sbp_msg_ssr_satellite_apc_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_satellite_apc_t *msg);

bool pack_sbp_msg_ssr_orbit_clock_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_orbit_clock_dep_a_t *msg);
bool unpack_sbp_msg_ssr_orbit_clock_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_orbit_clock_dep_a_t *msg);

bool pack_sbp_stec_header_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_stec_header_dep_a_t *msg);
bool unpack_sbp_stec_header_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_stec_header_dep_a_t *msg);

bool pack_sbp_gridded_correction_header_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_gridded_correction_header_dep_a_t *msg);
bool unpack_sbp_gridded_correction_header_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_gridded_correction_header_dep_a_t *msg);

bool pack_sbp_grid_definition_header_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_grid_definition_header_dep_a_t *msg);
bool unpack_sbp_grid_definition_header_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_grid_definition_header_dep_a_t *msg);

bool pack_sbp_msg_ssr_stec_correction_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_stec_correction_dep_a_t *msg);
bool unpack_sbp_msg_ssr_stec_correction_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_stec_correction_dep_a_t *msg);

bool pack_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg);
bool unpack_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg);

bool pack_sbp_msg_ssr_gridded_correction_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_gridded_correction_dep_a_t *msg);
bool unpack_sbp_msg_ssr_gridded_correction_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_gridded_correction_dep_a_t *msg);

bool pack_sbp_msg_ssr_grid_definition_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_ssr_grid_definition_dep_a_t *msg);
bool unpack_sbp_msg_ssr_grid_definition_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_ssr_grid_definition_dep_a_t *msg);

#ifdef __cplusplus
  }
#endif

#endif
