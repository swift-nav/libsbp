#ifndef LIBSBP_UNPACKED_ACQUISITION_PRIVATE_H
#define LIBSBP_UNPACKED_ACQUISITION_PRIVATE_H

#include <stdbool.h>

#include <libsbp/new/acquisition.h>
#include <libsbp/internal/new/common.h>
#include <libsbp/internal/new/gnss.h>

#ifdef __cplusplus
  extern "C" {
#endif

bool encode_sbp_msg_acq_result_t(sbp_encode_ctx_t *ctx, const sbp_msg_acq_result_t *msg);
bool decode_sbp_msg_acq_result_t(sbp_decode_ctx_t *ctx, sbp_msg_acq_result_t *msg);

bool encode_sbp_msg_acq_result_dep_c_t(sbp_encode_ctx_t *ctx, const sbp_msg_acq_result_dep_c_t *msg);
bool decode_sbp_msg_acq_result_dep_c_t(sbp_decode_ctx_t *ctx, sbp_msg_acq_result_dep_c_t *msg);

bool encode_sbp_msg_acq_result_dep_b_t(sbp_encode_ctx_t *ctx, const sbp_msg_acq_result_dep_b_t *msg);
bool decode_sbp_msg_acq_result_dep_b_t(sbp_decode_ctx_t *ctx, sbp_msg_acq_result_dep_b_t *msg);

bool encode_sbp_msg_acq_result_dep_a_t(sbp_encode_ctx_t *ctx, const sbp_msg_acq_result_dep_a_t *msg);
bool decode_sbp_msg_acq_result_dep_a_t(sbp_decode_ctx_t *ctx, sbp_msg_acq_result_dep_a_t *msg);

bool encode_sbp_acq_sv_profile_t(sbp_encode_ctx_t *ctx, const sbp_acq_sv_profile_t *msg);
bool decode_sbp_acq_sv_profile_t(sbp_decode_ctx_t *ctx, sbp_acq_sv_profile_t *msg);

bool encode_sbp_acq_sv_profile_dep_t(sbp_encode_ctx_t *ctx, const sbp_acq_sv_profile_dep_t *msg);
bool decode_sbp_acq_sv_profile_dep_t(sbp_decode_ctx_t *ctx, sbp_acq_sv_profile_dep_t *msg);

bool encode_sbp_msg_acq_sv_profile_t(sbp_encode_ctx_t *ctx, const sbp_msg_acq_sv_profile_t *msg);
bool decode_sbp_msg_acq_sv_profile_t(sbp_decode_ctx_t *ctx, sbp_msg_acq_sv_profile_t *msg);

bool encode_sbp_msg_acq_sv_profile_dep_t(sbp_encode_ctx_t *ctx, const sbp_msg_acq_sv_profile_dep_t *msg);
bool decode_sbp_msg_acq_sv_profile_dep_t(sbp_decode_ctx_t *ctx, sbp_msg_acq_sv_profile_dep_t *msg);

#ifdef __cplusplus
  }
#endif

#endif
