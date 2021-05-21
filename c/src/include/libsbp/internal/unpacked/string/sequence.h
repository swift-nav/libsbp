#ifndef LIBSBP_INTERNAL_UNPACKED_STRING_SEQUENCE_H
#define LIBSBP_INTERNAL_UNPACKED_STRING_SEQUENCE_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <libsbp/internal/unpacked/common.h>
#include <libsbp/unpacked/string/sequence.h>

bool sbp_sequence_string_pack(const sbp_sequence_string_t *s,
                              const sbp_sequence_string_params_t *params,
                              sbp_pack_ctx_t *ctx);
bool sbp_sequence_string_unpack(sbp_sequence_string_t *s,
                                const sbp_sequence_string_params_t *params,
                                sbp_unpack_ctx_t *ctx);

#ifdef __cplusplus
}
#endif

#endif
