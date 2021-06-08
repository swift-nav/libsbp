#ifndef LIBSBP_INTERNAL_UNPACKED_STRING_DOUBLE_NULL_TERMINATED_H
#define LIBSBP_INTERNAL_UNPACKED_STRING_DOUBLE_NULL_TERMINATED_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <libsbp/internal/new/common.h>
#include <libsbp/new/string/double_null_terminated.h>

bool sbp_double_null_terminated_string_pack(const sbp_double_null_terminated_string_t *s,
                              const sbp_double_null_terminated_string_params_t *params,
                              sbp_encode_ctx_t *ctx);
bool sbp_double_null_terminated_string_unpack(sbp_double_null_terminated_string_t *s,
                                const sbp_double_null_terminated_string_params_t *params,
                                sbp_decode_ctx_t *ctx);

#ifdef __cplusplus
}
#endif

#endif
