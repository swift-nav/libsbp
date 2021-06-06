#ifndef LIBSBP_INTERNAL_UNPACKED_STRING_NULL_TERMINATED_H
#define LIBSBP_INTERNAL_UNPACKED_STRING_NULL_TERMINATED_H

#include <libsbp/internal/new/common.h>
#include <libsbp/new/string/null_terminated.h>

#ifdef __cplusplus
extern "C" {
#endif

bool sbp_null_terminated_string_pack(const sbp_null_terminated_string_t *s,
                                     const sbp_null_terminated_string_params_t *params,
                                     sbp_pack_ctx_t *ctx);
bool sbp_null_terminated_string_unpack(sbp_null_terminated_string_t *s,
                                       const sbp_null_terminated_string_params_t *params,
                                       sbp_unpack_ctx_t *ctx);

#ifdef __cplusplus
}
#endif

#endif
