#ifndef LIBSBP_UNPACKED_MAG_PRIVATE_H
#define LIBSBP_UNPACKED_MAG_PRIVATE_H

#include <stdbool.h>

#include <libsbp/new/mag.h>
#include <libsbp/internal/new/common.h>

#ifdef __cplusplus
  extern "C" {
#endif

bool encode_sbp_msg_mag_raw_t(sbp_encode_ctx_t *ctx, const sbp_msg_mag_raw_t *msg);
bool decode_sbp_msg_mag_raw_t(sbp_decode_ctx_t *ctx, sbp_msg_mag_raw_t *msg);

#ifdef __cplusplus
  }
#endif

#endif
