#ifndef LIBSBP_UNPACKED_OBSERVATION_PRIVATE_H
#define LIBSBP_UNPACKED_OBSERVATION_PRIVATE_H

#include <stdbool.h>

#include <libsbp/new/observation.h>
#include <libsbp/internal/new/common.h>
#include <libsbp/internal/new/gnss.h>

#ifdef __cplusplus
  extern "C" {
#endif

bool encode_sbp_observation_header_t(sbp_encode_ctx_t *ctx, const sbp_observation_header_t *msg);
bool decode_sbp_observation_header_t(sbp_decode_ctx_t *ctx, sbp_observation_header_t *msg);

bool encode_sbp_doppler_t(sbp_encode_ctx_t *ctx, const sbp_doppler_t *msg);
bool decode_sbp_doppler_t(sbp_decode_ctx_t *ctx, sbp_doppler_t *msg);

bool encode_sbp_packed_obs_content_t(sbp_encode_ctx_t *ctx, const sbp_packed_obs_content_t *msg);
bool decode_sbp_packed_obs_content_t(sbp_decode_ctx_t *ctx, sbp_packed_obs_content_t *msg);

bool encode_sbp_msg_obs_t(sbp_encode_ctx_t *ctx, const sbp_msg_obs_t *msg);
bool decode_sbp_msg_obs_t(sbp_decode_ctx_t *ctx, sbp_msg_obs_t *msg);

bool encode_sbp_sv_az_el_t(sbp_encode_ctx_t *ctx, const sbp_sv_az_el_t *msg);
bool decode_sbp_sv_az_el_t(sbp_decode_ctx_t *ctx, sbp_sv_az_el_t *msg);

bool encode_sbp_msg_sv_az_el_t(sbp_encode_ctx_t *ctx, const sbp_msg_sv_az_el_t *msg);
bool decode_sbp_msg_sv_az_el_t(sbp_decode_ctx_t *ctx, sbp_msg_sv_az_el_t *msg);

#ifdef __cplusplus
  }
#endif

#endif
