#ifndef LIBSBP_INTERNAL_UNPACKED_STRING_UNTERMINATED_H
#define LIBSBP_INTERNAL_UNPACKED_STRING_UNTERMINATED_H

#include <stdarg.h>
#include <stddef.h>
#include <stdbool.h>

#include <libsbp/common.h>
#include <libsbp/internal/v4/common.h>
#include <libsbp/v4/string/sbp_string.h>

#ifdef __cplusplus
extern "C" {
#endif

void sbp_unterminated_string_init(sbp_string_t *s,
                                     size_t max_encoded_len);
bool sbp_unterminated_string_valid(const sbp_string_t *s,
                                      size_t max_encoded_len);
int sbp_unterminated_string_strcmp(const sbp_string_t *a,
                                      const sbp_string_t *b,
                                      size_t max_encoded_len);
size_t sbp_unterminated_string_encoded_len(const sbp_string_t *s,
                                              size_t max_encoded_len);
size_t sbp_unterminated_string_space_remaining(const sbp_string_t *s, size_t max_encoded_len);
size_t sbp_unterminated_string_strlen(const sbp_string_t *s, size_t max_encoded_len);

bool sbp_unterminated_string_set(sbp_string_t *s,
                                    size_t max_encoded_len,
                                    const char *new_str);
bool sbp_unterminated_string_vprintf(sbp_string_t *s,
                                        size_t max_encoded_len,
                                        const char *fmt,
                                        va_list);
bool sbp_unterminated_string_append(sbp_string_t *s,
                                       size_t max_encoded_len,
                                       const char *new_str);
bool sbp_unterminated_string_append_vprintf(sbp_string_t *s,
                                        size_t max_encoded_len,
                                        const char *fmt,
                                        va_list);
const char *sbp_unterminated_string_get(const sbp_string_t *s,
                                           size_t max_encoded_len);
bool sbp_unterminated_string_encode(const sbp_string_t *s,
                                  size_t max_encoded_len,
                                  sbp_encode_ctx_t *ctx);
bool sbp_unterminated_string_decode(sbp_string_t *s,
                                    size_t max_encoded_len,
                                    sbp_decode_ctx_t *ctx);

#ifdef __cplusplus
}
#endif

#endif
