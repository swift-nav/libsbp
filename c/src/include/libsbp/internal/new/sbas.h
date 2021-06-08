#ifndef LIBSBP_UNPACKED_SBAS_PRIVATE_H
#define LIBSBP_UNPACKED_SBAS_PRIVATE_H

#include <stdbool.h>

#include <libsbp/new/sbas.h>
#include <libsbp/internal/new/common.h>
#include <libsbp/internal/new/gnss.h>

#ifdef __cplusplus
  extern "C" {
#endif

bool encode_sbp_msg_sbas_raw_t(sbp_encode_ctx_t *ctx, const sbp_msg_sbas_raw_t *msg);
bool decode_sbp_msg_sbas_raw_t(sbp_decode_ctx_t *ctx, sbp_msg_sbas_raw_t *msg);

#ifdef __cplusplus
  }
#endif

#endif
