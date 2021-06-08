#ifndef LIBSBP_UNPACKED_SETTINGS_PRIVATE_H
#define LIBSBP_UNPACKED_SETTINGS_PRIVATE_H

#include <stdbool.h>

#include <libsbp/new/settings.h>
#include <libsbp/internal/new/common.h>

#ifdef __cplusplus
  extern "C" {
#endif

bool encode_sbp_msg_settings_read_by_index_resp_t(sbp_encode_ctx_t *ctx, const sbp_msg_settings_read_by_index_resp_t *msg);
bool decode_sbp_msg_settings_read_by_index_resp_t(sbp_decode_ctx_t *ctx, sbp_msg_settings_read_by_index_resp_t *msg);

bool encode_sbp_msg_settings_read_by_index_done_t(sbp_encode_ctx_t *ctx, const sbp_msg_settings_read_by_index_done_t *msg);
bool decode_sbp_msg_settings_read_by_index_done_t(sbp_decode_ctx_t *ctx, sbp_msg_settings_read_by_index_done_t *msg);

#ifdef __cplusplus
  }
#endif

#endif
