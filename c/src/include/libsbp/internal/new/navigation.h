#ifndef LIBSBP_UNPACKED_NAVIGATION_PRIVATE_H
#define LIBSBP_UNPACKED_NAVIGATION_PRIVATE_H

#include <stdbool.h>

#include <libsbp/new/navigation.h>
#include <libsbp/internal/new/common.h>

#ifdef __cplusplus
  extern "C" {
#endif

bool encode_sbp_msg_gps_time_t(sbp_encode_ctx_t *ctx, const sbp_msg_gps_time_t *msg);
bool decode_sbp_msg_gps_time_t(sbp_decode_ctx_t *ctx, sbp_msg_gps_time_t *msg);

bool encode_sbp_msg_gps_time_gnss_t(sbp_encode_ctx_t *ctx, const sbp_msg_gps_time_gnss_t *msg);
bool decode_sbp_msg_gps_time_gnss_t(sbp_decode_ctx_t *ctx, sbp_msg_gps_time_gnss_t *msg);

bool encode_sbp_msg_utc_time_t(sbp_encode_ctx_t *ctx, const sbp_msg_utc_time_t *msg);
bool decode_sbp_msg_utc_time_t(sbp_decode_ctx_t *ctx, sbp_msg_utc_time_t *msg);

bool encode_sbp_msg_utc_time_gnss_t(sbp_encode_ctx_t *ctx, const sbp_msg_utc_time_gnss_t *msg);
bool decode_sbp_msg_utc_time_gnss_t(sbp_decode_ctx_t *ctx, sbp_msg_utc_time_gnss_t *msg);

bool encode_sbp_msg_dops_t(sbp_encode_ctx_t *ctx, const sbp_msg_dops_t *msg);
bool decode_sbp_msg_dops_t(sbp_decode_ctx_t *ctx, sbp_msg_dops_t *msg);

bool encode_sbp_msg_pos_ecef_t(sbp_encode_ctx_t *ctx, const sbp_msg_pos_ecef_t *msg);
bool decode_sbp_msg_pos_ecef_t(sbp_decode_ctx_t *ctx, sbp_msg_pos_ecef_t *msg);

bool encode_sbp_msg_pos_ecef_cov_t(sbp_encode_ctx_t *ctx, const sbp_msg_pos_ecef_cov_t *msg);
bool decode_sbp_msg_pos_ecef_cov_t(sbp_decode_ctx_t *ctx, sbp_msg_pos_ecef_cov_t *msg);

bool encode_sbp_msg_pos_llh_t(sbp_encode_ctx_t *ctx, const sbp_msg_pos_llh_t *msg);
bool decode_sbp_msg_pos_llh_t(sbp_decode_ctx_t *ctx, sbp_msg_pos_llh_t *msg);

bool encode_sbp_msg_pos_llh_cov_t(sbp_encode_ctx_t *ctx, const sbp_msg_pos_llh_cov_t *msg);
bool decode_sbp_msg_pos_llh_cov_t(sbp_decode_ctx_t *ctx, sbp_msg_pos_llh_cov_t *msg);

bool encode_sbp_msg_baseline_ecef_t(sbp_encode_ctx_t *ctx, const sbp_msg_baseline_ecef_t *msg);
bool decode_sbp_msg_baseline_ecef_t(sbp_decode_ctx_t *ctx, sbp_msg_baseline_ecef_t *msg);

bool encode_sbp_msg_baseline_ned_t(sbp_encode_ctx_t *ctx, const sbp_msg_baseline_ned_t *msg);
bool decode_sbp_msg_baseline_ned_t(sbp_decode_ctx_t *ctx, sbp_msg_baseline_ned_t *msg);

bool encode_sbp_msg_vel_ecef_t(sbp_encode_ctx_t *ctx, const sbp_msg_vel_ecef_t *msg);
bool decode_sbp_msg_vel_ecef_t(sbp_decode_ctx_t *ctx, sbp_msg_vel_ecef_t *msg);

bool encode_sbp_msg_vel_ecef_cov_t(sbp_encode_ctx_t *ctx, const sbp_msg_vel_ecef_cov_t *msg);
bool decode_sbp_msg_vel_ecef_cov_t(sbp_decode_ctx_t *ctx, sbp_msg_vel_ecef_cov_t *msg);

bool encode_sbp_msg_vel_ned_t(sbp_encode_ctx_t *ctx, const sbp_msg_vel_ned_t *msg);
bool decode_sbp_msg_vel_ned_t(sbp_decode_ctx_t *ctx, sbp_msg_vel_ned_t *msg);

bool encode_sbp_msg_vel_ned_cov_t(sbp_encode_ctx_t *ctx, const sbp_msg_vel_ned_cov_t *msg);
bool decode_sbp_msg_vel_ned_cov_t(sbp_decode_ctx_t *ctx, sbp_msg_vel_ned_cov_t *msg);

bool encode_sbp_msg_pos_ecef_gnss_t(sbp_encode_ctx_t *ctx, const sbp_msg_pos_ecef_gnss_t *msg);
bool decode_sbp_msg_pos_ecef_gnss_t(sbp_decode_ctx_t *ctx, sbp_msg_pos_ecef_gnss_t *msg);

bool encode_sbp_msg_pos_ecef_cov_gnss_t(sbp_encode_ctx_t *ctx, const sbp_msg_pos_ecef_cov_gnss_t *msg);
bool decode_sbp_msg_pos_ecef_cov_gnss_t(sbp_decode_ctx_t *ctx, sbp_msg_pos_ecef_cov_gnss_t *msg);

bool encode_sbp_msg_pos_llh_gnss_t(sbp_encode_ctx_t *ctx, const sbp_msg_pos_llh_gnss_t *msg);
bool decode_sbp_msg_pos_llh_gnss_t(sbp_decode_ctx_t *ctx, sbp_msg_pos_llh_gnss_t *msg);

bool encode_sbp_msg_pos_llh_cov_gnss_t(sbp_encode_ctx_t *ctx, const sbp_msg_pos_llh_cov_gnss_t *msg);
bool decode_sbp_msg_pos_llh_cov_gnss_t(sbp_decode_ctx_t *ctx, sbp_msg_pos_llh_cov_gnss_t *msg);

bool encode_sbp_msg_vel_ecef_gnss_t(sbp_encode_ctx_t *ctx, const sbp_msg_vel_ecef_gnss_t *msg);
bool decode_sbp_msg_vel_ecef_gnss_t(sbp_decode_ctx_t *ctx, sbp_msg_vel_ecef_gnss_t *msg);

bool encode_sbp_msg_vel_ecef_cov_gnss_t(sbp_encode_ctx_t *ctx, const sbp_msg_vel_ecef_cov_gnss_t *msg);
bool decode_sbp_msg_vel_ecef_cov_gnss_t(sbp_decode_ctx_t *ctx, sbp_msg_vel_ecef_cov_gnss_t *msg);

bool encode_sbp_msg_vel_ned_gnss_t(sbp_encode_ctx_t *ctx, const sbp_msg_vel_ned_gnss_t *msg);
bool decode_sbp_msg_vel_ned_gnss_t(sbp_decode_ctx_t *ctx, sbp_msg_vel_ned_gnss_t *msg);

bool encode_sbp_msg_vel_ned_cov_gnss_t(sbp_encode_ctx_t *ctx, const sbp_msg_vel_ned_cov_gnss_t *msg);
bool decode_sbp_msg_vel_ned_cov_gnss_t(sbp_decode_ctx_t *ctx, sbp_msg_vel_ned_cov_gnss_t *msg);

bool encode_sbp_msg_vel_body_t(sbp_encode_ctx_t *ctx, const sbp_msg_vel_body_t *msg);
bool decode_sbp_msg_vel_body_t(sbp_decode_ctx_t *ctx, sbp_msg_vel_body_t *msg);

bool encode_sbp_msg_age_corrections_t(sbp_encode_ctx_t *ctx, const sbp_msg_age_corrections_t *msg);
bool decode_sbp_msg_age_corrections_t(sbp_decode_ctx_t *ctx, sbp_msg_age_corrections_t *msg);

bool encode_sbp_msg_gps_time_dep_a_t(sbp_encode_ctx_t *ctx, const sbp_msg_gps_time_dep_a_t *msg);
bool decode_sbp_msg_gps_time_dep_a_t(sbp_decode_ctx_t *ctx, sbp_msg_gps_time_dep_a_t *msg);

bool encode_sbp_msg_dops_dep_a_t(sbp_encode_ctx_t *ctx, const sbp_msg_dops_dep_a_t *msg);
bool decode_sbp_msg_dops_dep_a_t(sbp_decode_ctx_t *ctx, sbp_msg_dops_dep_a_t *msg);

bool encode_sbp_msg_pos_ecef_dep_a_t(sbp_encode_ctx_t *ctx, const sbp_msg_pos_ecef_dep_a_t *msg);
bool decode_sbp_msg_pos_ecef_dep_a_t(sbp_decode_ctx_t *ctx, sbp_msg_pos_ecef_dep_a_t *msg);

bool encode_sbp_msg_pos_llh_dep_a_t(sbp_encode_ctx_t *ctx, const sbp_msg_pos_llh_dep_a_t *msg);
bool decode_sbp_msg_pos_llh_dep_a_t(sbp_decode_ctx_t *ctx, sbp_msg_pos_llh_dep_a_t *msg);

bool encode_sbp_msg_baseline_ecef_dep_a_t(sbp_encode_ctx_t *ctx, const sbp_msg_baseline_ecef_dep_a_t *msg);
bool decode_sbp_msg_baseline_ecef_dep_a_t(sbp_decode_ctx_t *ctx, sbp_msg_baseline_ecef_dep_a_t *msg);

bool encode_sbp_msg_baseline_ned_dep_a_t(sbp_encode_ctx_t *ctx, const sbp_msg_baseline_ned_dep_a_t *msg);
bool decode_sbp_msg_baseline_ned_dep_a_t(sbp_decode_ctx_t *ctx, sbp_msg_baseline_ned_dep_a_t *msg);

bool encode_sbp_msg_vel_ecef_dep_a_t(sbp_encode_ctx_t *ctx, const sbp_msg_vel_ecef_dep_a_t *msg);
bool decode_sbp_msg_vel_ecef_dep_a_t(sbp_decode_ctx_t *ctx, sbp_msg_vel_ecef_dep_a_t *msg);

bool encode_sbp_msg_vel_ned_dep_a_t(sbp_encode_ctx_t *ctx, const sbp_msg_vel_ned_dep_a_t *msg);
bool decode_sbp_msg_vel_ned_dep_a_t(sbp_decode_ctx_t *ctx, sbp_msg_vel_ned_dep_a_t *msg);

bool encode_sbp_msg_baseline_heading_dep_a_t(sbp_encode_ctx_t *ctx, const sbp_msg_baseline_heading_dep_a_t *msg);
bool decode_sbp_msg_baseline_heading_dep_a_t(sbp_decode_ctx_t *ctx, sbp_msg_baseline_heading_dep_a_t *msg);

bool encode_sbp_msg_protection_level_dep_a_t(sbp_encode_ctx_t *ctx, const sbp_msg_protection_level_dep_a_t *msg);
bool decode_sbp_msg_protection_level_dep_a_t(sbp_decode_ctx_t *ctx, sbp_msg_protection_level_dep_a_t *msg);

bool encode_sbp_msg_protection_level_t(sbp_encode_ctx_t *ctx, const sbp_msg_protection_level_t *msg);
bool decode_sbp_msg_protection_level_t(sbp_decode_ctx_t *ctx, sbp_msg_protection_level_t *msg);

#ifdef __cplusplus
  }
#endif

#endif
