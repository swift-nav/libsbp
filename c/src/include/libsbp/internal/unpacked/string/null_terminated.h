#ifndef LIBSBP_INTERNAL_UNPACKED_STRING_NULL_TERMINATED_H
#define LIBSBP_INTERNAL_UNPACKED_STRING_NULL_TERMINATED_H

#include <libsbp/unpacked/string/null_terminated.h>
#include <libsbp/internal/unpacked/common.h>

  bool sbp_null_terminated_string_pack(const sbp_null_terminated_string_t *s,
                                          uint8_t max_packed_len,
                                          sbp_pack_ctx_t *ctx);
  bool sbp_null_terminated_string_unpack(sbp_null_terminated_string_t *s,
                                            uint8_t max_packed_len,
                                            sbp_unpack_ctx_t *ctx);

#endif

