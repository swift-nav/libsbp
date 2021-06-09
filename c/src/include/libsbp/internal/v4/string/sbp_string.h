#ifndef LIBSBP_INTERNAL_V4_STRING_SBP_STRING_H
#define LIBSBP_INTERNAL_V4_STRING_SBP_STRING_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>

#include <libsbp/common.h>
#include <libsbp/v4/string/sbp_string.h>
#include <libsbp/internal/v4/common.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  bool (*valid)(const sbp_string_t *s, size_t max_encoded_len);
  void (*init)(sbp_string_t *s, size_t max_encoded_len);
  const char default_output[2];
  size_t default_output_len;
  bool inject_missing_terminator;
} sbp_string_params_t;

int sbp_string_cmp(const sbp_string_t *a, const sbp_string_t *b, size_t max_encoded_len, const sbp_string_params_t *params);

bool sbp_string_copy_to_buf(char *buf, size_t *copied, size_t max, const char *str);
bool sbp_string_vprintf_to_buf(char *buf, size_t *copied, size_t max, const char *fmt, va_list ap);
bool sbp_string_encode(const sbp_string_t *s, size_t max_encoded_len, sbp_encode_ctx_t *ctx, const sbp_string_params_t *params);
bool sbp_string_decode(sbp_string_t *s, size_t max_encoded_len, sbp_decode_ctx_t *ctx, const sbp_string_params_t *params);

#ifdef __cplusplus
}
#endif

#endif /* LIBSBP_INTERNAL_V4_STRING_SBP_STRING_H */
