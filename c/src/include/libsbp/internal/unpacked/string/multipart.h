#ifndef LIBSBP_INTERNAL_STRING_MULTIPART_H
#define LIBSBP_INTERNAL_STRING_MULTIPART_H

#include <libsbp/unpacked/string/multipart.h>
#include <libsbp/internal/unpacked/common.h>

  bool sbp_multipart_string_pack(const sbp_multipart_string_t *s,
                                    uint8_t max_packed_len,
                                    uint8_t min_sections,
                                    uint8_t max_sections,
                                    sbp_pack_ctx_t *ctx);
  bool sbp_multipart_string_unpack(sbp_multipart_string_t *s,
                                      uint8_t max_packed_len,
                                      uint8_t min_sections,
                                      uint8_t max_sections,
                                      sbp_unpack_ctx_t *ctx);
#endif
