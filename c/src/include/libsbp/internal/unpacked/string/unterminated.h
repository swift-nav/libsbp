#ifndef LIBSBP_INTERNAL_UNPACKED_STRING_UNTERMINATED_H
#define LIBSBP_INTERNAL_UNPACKED_STRING_UNTERMINATED_H

#include <libsbp/unpacked/string/unterminated.h>
#include <libsbp/internal/unpacked/common.h>

  bool sbp_unterminated_string_pack(const sbp_unterminated_string_t *s,
                                       uint8_t max_packed_len,
                                       sbp_pack_ctx_t *ctx);
  bool sbp_unterminated_string_unpack(sbp_unterminated_string_t *s,
                                         uint8_t max_packed_len,
                                         sbp_unpack_ctx_t *ctx);

#endif

