#ifndef LIBSBP_INTERNAL_UNPACKED_STRING_UNTERMINATED_H
#define LIBSBP_INTERNAL_UNPACKED_STRING_UNTERMINATED_H

#include <libsbp/internal/new/common.h>
#include <libsbp/new/string/unterminated.h>

#ifdef __cplusplus
extern "C" {
#endif

bool sbp_unterminated_string_pack(const sbp_unterminated_string_t *s,
                                  const sbp_unterminated_string_params_t *params,
                                  sbp_pack_ctx_t *ctx);
bool sbp_unterminated_string_unpack(sbp_unterminated_string_t *s,
                                    const sbp_unterminated_string_params_t *params,
                                    sbp_unpack_ctx_t *ctx);

#ifdef __cplusplus
}
#endif

#endif
