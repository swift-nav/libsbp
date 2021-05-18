#ifndef LIBSBP_INTERNAL_UNPACKED_STRING_BINARY_H
#define LIBSBP_INTERNAL_UNPACKED_STRING_BINARY_H

#include <libsbp/unpacked/string/binary.h>
#include <libsbp/internal/unpacked/common.h>

  bool sbp_binary_string_pack(const sbp_binary_string_t *s,
                                       uint8_t max_packed_len,
                                       sbp_pack_ctx_t *ctx);
  bool sbp_binary_string_unpack(sbp_binary_string_t *s,
                                         uint8_t max_packed_len,
                                         sbp_unpack_ctx_t *ctx);

#endif


