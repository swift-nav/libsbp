#ifndef LIBSBP_UNPACKED_OBSERVATION_PRIVATE_H
#define LIBSBP_UNPACKED_OBSERVATION_PRIVATE_H

#include <stdbool.h>

#include <libsbp/unpacked/observation.h>
#include <libsbp/internal/unpacked/common.h>
#include <libsbp/internal/unpacked/gnss.h>

#ifdef __cplusplus
  extern "C" {
#endif

bool pack_sbp_observation_header_t(sbp_pack_ctx_t *ctx, const sbp_observation_header_t *msg);
bool unpack_sbp_observation_header_t(sbp_unpack_ctx_t *ctx, sbp_observation_header_t *msg);

bool pack_sbp_doppler_t(sbp_pack_ctx_t *ctx, const sbp_doppler_t *msg);
bool unpack_sbp_doppler_t(sbp_unpack_ctx_t *ctx, sbp_doppler_t *msg);

bool pack_sbp_packed_obs_content_t(sbp_pack_ctx_t *ctx, const sbp_packed_obs_content_t *msg);
bool unpack_sbp_packed_obs_content_t(sbp_unpack_ctx_t *ctx, sbp_packed_obs_content_t *msg);

bool pack_sbp_packed_osr_content_t(sbp_pack_ctx_t *ctx, const sbp_packed_osr_content_t *msg);
bool unpack_sbp_packed_osr_content_t(sbp_unpack_ctx_t *ctx, sbp_packed_osr_content_t *msg);

bool pack_sbp_msg_obs_t(sbp_pack_ctx_t *ctx, const sbp_msg_obs_t *msg);
bool unpack_sbp_msg_obs_t(sbp_unpack_ctx_t *ctx, sbp_msg_obs_t *msg);

bool pack_sbp_msg_base_pos_llh_t(sbp_pack_ctx_t *ctx, const sbp_msg_base_pos_llh_t *msg);
bool unpack_sbp_msg_base_pos_llh_t(sbp_unpack_ctx_t *ctx, sbp_msg_base_pos_llh_t *msg);

bool pack_sbp_msg_base_pos_ecef_t(sbp_pack_ctx_t *ctx, const sbp_msg_base_pos_ecef_t *msg);
bool unpack_sbp_msg_base_pos_ecef_t(sbp_unpack_ctx_t *ctx, sbp_msg_base_pos_ecef_t *msg);

bool pack_sbp_ephemeris_common_content_t(sbp_pack_ctx_t *ctx, const sbp_ephemeris_common_content_t *msg);
bool unpack_sbp_ephemeris_common_content_t(sbp_unpack_ctx_t *ctx, sbp_ephemeris_common_content_t *msg);

bool pack_sbp_ephemeris_common_content_dep_b_t(sbp_pack_ctx_t *ctx, const sbp_ephemeris_common_content_dep_b_t *msg);
bool unpack_sbp_ephemeris_common_content_dep_b_t(sbp_unpack_ctx_t *ctx, sbp_ephemeris_common_content_dep_b_t *msg);

bool pack_sbp_ephemeris_common_content_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_ephemeris_common_content_dep_a_t *msg);
bool unpack_sbp_ephemeris_common_content_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_ephemeris_common_content_dep_a_t *msg);

bool pack_sbp_msg_ephemeris_gps_dep_e_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_gps_dep_e_t *msg);
bool unpack_sbp_msg_ephemeris_gps_dep_e_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_gps_dep_e_t *msg);

bool pack_sbp_msg_ephemeris_gps_dep_f_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_gps_dep_f_t *msg);
bool unpack_sbp_msg_ephemeris_gps_dep_f_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_gps_dep_f_t *msg);

bool pack_sbp_msg_ephemeris_gps_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_gps_t *msg);
bool unpack_sbp_msg_ephemeris_gps_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_gps_t *msg);

bool pack_sbp_msg_ephemeris_qzss_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_qzss_t *msg);
bool unpack_sbp_msg_ephemeris_qzss_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_qzss_t *msg);

bool pack_sbp_msg_ephemeris_bds_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_bds_t *msg);
bool unpack_sbp_msg_ephemeris_bds_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_bds_t *msg);

bool pack_sbp_msg_ephemeris_gal_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_gal_dep_a_t *msg);
bool unpack_sbp_msg_ephemeris_gal_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_gal_dep_a_t *msg);

bool pack_sbp_msg_ephemeris_gal_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_gal_t *msg);
bool unpack_sbp_msg_ephemeris_gal_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_gal_t *msg);

bool pack_sbp_msg_ephemeris_sbas_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_sbas_dep_a_t *msg);
bool unpack_sbp_msg_ephemeris_sbas_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_sbas_dep_a_t *msg);

bool pack_sbp_msg_ephemeris_glo_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_glo_dep_a_t *msg);
bool unpack_sbp_msg_ephemeris_glo_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_glo_dep_a_t *msg);

bool pack_sbp_msg_ephemeris_sbas_dep_b_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_sbas_dep_b_t *msg);
bool unpack_sbp_msg_ephemeris_sbas_dep_b_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_sbas_dep_b_t *msg);

bool pack_sbp_msg_ephemeris_sbas_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_sbas_t *msg);
bool unpack_sbp_msg_ephemeris_sbas_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_sbas_t *msg);

bool pack_sbp_msg_ephemeris_glo_dep_b_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_glo_dep_b_t *msg);
bool unpack_sbp_msg_ephemeris_glo_dep_b_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_glo_dep_b_t *msg);

bool pack_sbp_msg_ephemeris_glo_dep_c_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_glo_dep_c_t *msg);
bool unpack_sbp_msg_ephemeris_glo_dep_c_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_glo_dep_c_t *msg);

bool pack_sbp_msg_ephemeris_glo_dep_d_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_glo_dep_d_t *msg);
bool unpack_sbp_msg_ephemeris_glo_dep_d_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_glo_dep_d_t *msg);

bool pack_sbp_msg_ephemeris_glo_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_glo_t *msg);
bool unpack_sbp_msg_ephemeris_glo_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_glo_t *msg);

bool pack_sbp_msg_ephemeris_dep_d_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_dep_d_t *msg);
bool unpack_sbp_msg_ephemeris_dep_d_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_dep_d_t *msg);

bool pack_sbp_msg_ephemeris_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_dep_a_t *msg);
bool unpack_sbp_msg_ephemeris_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_dep_a_t *msg);

bool pack_sbp_msg_ephemeris_dep_b_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_dep_b_t *msg);
bool unpack_sbp_msg_ephemeris_dep_b_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_dep_b_t *msg);

bool pack_sbp_msg_ephemeris_dep_c_t(sbp_pack_ctx_t *ctx, const sbp_msg_ephemeris_dep_c_t *msg);
bool unpack_sbp_msg_ephemeris_dep_c_t(sbp_unpack_ctx_t *ctx, sbp_msg_ephemeris_dep_c_t *msg);

bool pack_sbp_observation_header_dep_t(sbp_pack_ctx_t *ctx, const sbp_observation_header_dep_t *msg);
bool unpack_sbp_observation_header_dep_t(sbp_unpack_ctx_t *ctx, sbp_observation_header_dep_t *msg);

bool pack_sbp_carrier_phase_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_carrier_phase_dep_a_t *msg);
bool unpack_sbp_carrier_phase_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_carrier_phase_dep_a_t *msg);

bool pack_sbp_packed_obs_content_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_packed_obs_content_dep_a_t *msg);
bool unpack_sbp_packed_obs_content_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_packed_obs_content_dep_a_t *msg);

bool pack_sbp_packed_obs_content_dep_b_t(sbp_pack_ctx_t *ctx, const sbp_packed_obs_content_dep_b_t *msg);
bool unpack_sbp_packed_obs_content_dep_b_t(sbp_unpack_ctx_t *ctx, sbp_packed_obs_content_dep_b_t *msg);

bool pack_sbp_packed_obs_content_dep_c_t(sbp_pack_ctx_t *ctx, const sbp_packed_obs_content_dep_c_t *msg);
bool unpack_sbp_packed_obs_content_dep_c_t(sbp_unpack_ctx_t *ctx, sbp_packed_obs_content_dep_c_t *msg);

bool pack_sbp_msg_obs_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_obs_dep_a_t *msg);
bool unpack_sbp_msg_obs_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_obs_dep_a_t *msg);

bool pack_sbp_msg_obs_dep_b_t(sbp_pack_ctx_t *ctx, const sbp_msg_obs_dep_b_t *msg);
bool unpack_sbp_msg_obs_dep_b_t(sbp_unpack_ctx_t *ctx, sbp_msg_obs_dep_b_t *msg);

bool pack_sbp_msg_obs_dep_c_t(sbp_pack_ctx_t *ctx, const sbp_msg_obs_dep_c_t *msg);
bool unpack_sbp_msg_obs_dep_c_t(sbp_unpack_ctx_t *ctx, sbp_msg_obs_dep_c_t *msg);

bool pack_sbp_msg_iono_t(sbp_pack_ctx_t *ctx, const sbp_msg_iono_t *msg);
bool unpack_sbp_msg_iono_t(sbp_unpack_ctx_t *ctx, sbp_msg_iono_t *msg);

bool pack_sbp_msg_sv_configuration_gps_dep_t(sbp_pack_ctx_t *ctx, const sbp_msg_sv_configuration_gps_dep_t *msg);
bool unpack_sbp_msg_sv_configuration_gps_dep_t(sbp_unpack_ctx_t *ctx, sbp_msg_sv_configuration_gps_dep_t *msg);

bool pack_sbp_gnss_capb_t(sbp_pack_ctx_t *ctx, const sbp_gnss_capb_t *msg);
bool unpack_sbp_gnss_capb_t(sbp_unpack_ctx_t *ctx, sbp_gnss_capb_t *msg);

bool pack_sbp_msg_gnss_capb_t(sbp_pack_ctx_t *ctx, const sbp_msg_gnss_capb_t *msg);
bool unpack_sbp_msg_gnss_capb_t(sbp_unpack_ctx_t *ctx, sbp_msg_gnss_capb_t *msg);

bool pack_sbp_msg_group_delay_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_group_delay_dep_a_t *msg);
bool unpack_sbp_msg_group_delay_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_group_delay_dep_a_t *msg);

bool pack_sbp_msg_group_delay_dep_b_t(sbp_pack_ctx_t *ctx, const sbp_msg_group_delay_dep_b_t *msg);
bool unpack_sbp_msg_group_delay_dep_b_t(sbp_unpack_ctx_t *ctx, sbp_msg_group_delay_dep_b_t *msg);

bool pack_sbp_msg_group_delay_t(sbp_pack_ctx_t *ctx, const sbp_msg_group_delay_t *msg);
bool unpack_sbp_msg_group_delay_t(sbp_unpack_ctx_t *ctx, sbp_msg_group_delay_t *msg);

bool pack_sbp_almanac_common_content_t(sbp_pack_ctx_t *ctx, const sbp_almanac_common_content_t *msg);
bool unpack_sbp_almanac_common_content_t(sbp_unpack_ctx_t *ctx, sbp_almanac_common_content_t *msg);

bool pack_sbp_almanac_common_content_dep_t(sbp_pack_ctx_t *ctx, const sbp_almanac_common_content_dep_t *msg);
bool unpack_sbp_almanac_common_content_dep_t(sbp_unpack_ctx_t *ctx, sbp_almanac_common_content_dep_t *msg);

bool pack_sbp_msg_almanac_gps_dep_t(sbp_pack_ctx_t *ctx, const sbp_msg_almanac_gps_dep_t *msg);
bool unpack_sbp_msg_almanac_gps_dep_t(sbp_unpack_ctx_t *ctx, sbp_msg_almanac_gps_dep_t *msg);

bool pack_sbp_msg_almanac_gps_t(sbp_pack_ctx_t *ctx, const sbp_msg_almanac_gps_t *msg);
bool unpack_sbp_msg_almanac_gps_t(sbp_unpack_ctx_t *ctx, sbp_msg_almanac_gps_t *msg);

bool pack_sbp_msg_almanac_glo_dep_t(sbp_pack_ctx_t *ctx, const sbp_msg_almanac_glo_dep_t *msg);
bool unpack_sbp_msg_almanac_glo_dep_t(sbp_unpack_ctx_t *ctx, sbp_msg_almanac_glo_dep_t *msg);

bool pack_sbp_msg_almanac_glo_t(sbp_pack_ctx_t *ctx, const sbp_msg_almanac_glo_t *msg);
bool unpack_sbp_msg_almanac_glo_t(sbp_unpack_ctx_t *ctx, sbp_msg_almanac_glo_t *msg);

bool pack_sbp_msg_glo_biases_t(sbp_pack_ctx_t *ctx, const sbp_msg_glo_biases_t *msg);
bool unpack_sbp_msg_glo_biases_t(sbp_unpack_ctx_t *ctx, sbp_msg_glo_biases_t *msg);

bool pack_sbp_sv_az_el_t(sbp_pack_ctx_t *ctx, const sbp_sv_az_el_t *msg);
bool unpack_sbp_sv_az_el_t(sbp_unpack_ctx_t *ctx, sbp_sv_az_el_t *msg);

bool pack_sbp_msg_sv_az_el_t(sbp_pack_ctx_t *ctx, const sbp_msg_sv_az_el_t *msg);
bool unpack_sbp_msg_sv_az_el_t(sbp_unpack_ctx_t *ctx, sbp_msg_sv_az_el_t *msg);

bool pack_sbp_msg_osr_t(sbp_pack_ctx_t *ctx, const sbp_msg_osr_t *msg);
bool unpack_sbp_msg_osr_t(sbp_unpack_ctx_t *ctx, sbp_msg_osr_t *msg);

#ifdef __cplusplus
  }
#endif

#endif
