#ifndef LIBSBP_UNPACKED_SOLUTION_META_PRIVATE_H
#define LIBSBP_UNPACKED_SOLUTION_META_PRIVATE_H

#include <stdbool.h>

#include <libsbp/new/solution_meta.h>
#include <libsbp/internal/new/common.h>

#ifdef __cplusplus
  extern "C" {
#endif

bool encode_sbp_solution_input_type_t(sbp_encode_ctx_t *ctx, const sbp_solution_input_type_t *msg);
bool decode_sbp_solution_input_type_t(sbp_decode_ctx_t *ctx, sbp_solution_input_type_t *msg);

bool encode_sbp_msg_soln_meta_dep_a_t(sbp_encode_ctx_t *ctx, const sbp_msg_soln_meta_dep_a_t *msg);
bool decode_sbp_msg_soln_meta_dep_a_t(sbp_decode_ctx_t *ctx, sbp_msg_soln_meta_dep_a_t *msg);

bool encode_sbp_msg_soln_meta_t(sbp_encode_ctx_t *ctx, const sbp_msg_soln_meta_t *msg);
bool decode_sbp_msg_soln_meta_t(sbp_decode_ctx_t *ctx, sbp_msg_soln_meta_t *msg);

bool encode_sbp_gnss_input_type_t(sbp_encode_ctx_t *ctx, const sbp_gnss_input_type_t *msg);
bool decode_sbp_gnss_input_type_t(sbp_decode_ctx_t *ctx, sbp_gnss_input_type_t *msg);

bool encode_sbp_imu_input_type_t(sbp_encode_ctx_t *ctx, const sbp_imu_input_type_t *msg);
bool decode_sbp_imu_input_type_t(sbp_decode_ctx_t *ctx, sbp_imu_input_type_t *msg);

bool encode_sbp_odo_input_type_t(sbp_encode_ctx_t *ctx, const sbp_odo_input_type_t *msg);
bool decode_sbp_odo_input_type_t(sbp_decode_ctx_t *ctx, sbp_odo_input_type_t *msg);

#ifdef __cplusplus
  }
#endif

#endif
