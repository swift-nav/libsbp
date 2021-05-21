#ifndef LIBSBP_INTERNAL_UNPACKED_STRING_BINARY_H
#define LIBSBP_INTERNAL_UNPACKED_STRING_BINARY_H

#include <libsbp/internal/unpacked/common.h>
#include <libsbp/unpacked/string/binary.h>

#ifdef __cplusplus
extern "C" {
#endif

bool sbp_binary_string_pack(const sbp_binary_string_t *s,
                            const sbp_binary_string_params_t *params,
                            sbp_pack_ctx_t *ctx);
bool sbp_binary_string_unpack(sbp_binary_string_t *s, const sbp_binary_string_params_t *params, sbp_unpack_ctx_t *ctx);

#ifdef __cplusplus
}
#endif

#endif
