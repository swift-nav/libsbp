#ifndef LIBSBP_UNPACKED_SBAS_PRIVATE_H
#define LIBSBP_UNPACKED_SBAS_PRIVATE_H

#include <stdbool.h>

#include <libsbp/unpacked/sbas.h>
#include <libsbp/internal/unpacked/common.h>
#include <libsbp/internal/unpacked/gnss.h>

#ifdef __cplusplus
  extern "C" {
#endif

bool pack_sbp_msg_sbas_raw_t(sbp_pack_ctx_t *ctx, const sbp_msg_sbas_raw_t *msg);
bool unpack_sbp_msg_sbas_raw_t(sbp_unpack_ctx_t *ctx, sbp_msg_sbas_raw_t *msg);

#ifdef __cplusplus
  }
#endif

#endif
