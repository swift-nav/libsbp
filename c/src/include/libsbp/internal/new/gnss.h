#ifndef LIBSBP_UNPACKED_GNSS_PRIVATE_H
#define LIBSBP_UNPACKED_GNSS_PRIVATE_H

#include <stdbool.h>

#include <libsbp/new/gnss.h>
#include <libsbp/internal/new/common.h>

#ifdef __cplusplus
  extern "C" {
#endif

bool encode_sbp_sbp_gnss_signal_t(sbp_encode_ctx_t *ctx, const sbp_sbp_gnss_signal_t *msg);
bool decode_sbp_sbp_gnss_signal_t(sbp_decode_ctx_t *ctx, sbp_sbp_gnss_signal_t *msg);

bool encode_sbp_sbp_gps_time_t(sbp_encode_ctx_t *ctx, const sbp_sbp_gps_time_t *msg);
bool decode_sbp_sbp_gps_time_t(sbp_decode_ctx_t *ctx, sbp_sbp_gps_time_t *msg);

bool encode_sbp_carrier_phase_t(sbp_encode_ctx_t *ctx, const sbp_carrier_phase_t *msg);
bool decode_sbp_carrier_phase_t(sbp_decode_ctx_t *ctx, sbp_carrier_phase_t *msg);

#ifdef __cplusplus
  }
#endif

#endif
