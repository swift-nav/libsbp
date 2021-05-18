#ifndef LIBSBP_INTERNAL_UNPACKED_STRING_SEQUENCE_H
#define LIBSBP_INTERNAL_UNPACKED_STRING_SEQUENCE_H

#include <stdint.h>
#include <stdbool.h>

#include <libsbp/unpacked/string/sequence.h>
#include <libsbp/internal/unpacked/common.h>

  bool sbp_sequence_string_pack(const sbp_sequence_string_t *s,
                                   uint8_t max_packed_len,
                                   uint8_t terminator,
                                   sbp_pack_ctx_t *ctx);
  bool sbp_sequence_string_unpack(sbp_sequence_string_t *s,
                                     uint8_t max_packed_len,
                                     uint8_t terminator,
                                     sbp_unpack_ctx_t *ctx);

#endif
