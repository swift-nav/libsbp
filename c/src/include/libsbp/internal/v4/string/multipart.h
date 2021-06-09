#ifndef LIBSBP_INTERNAL_STRING_MULTIPART_H
#define LIBSBP_INTERNAL_STRING_MULTIPART_H

#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>

#include <libsbp/common.h>
#include <libsbp/internal/v4/common.h>
#include <libsbp/v4/string/sbp_string.h>

#ifdef __cplusplus
extern "C" {
#endif

void sbp_multipart_string_init(sbp_string_t *s, size_t max_encoded_len);
bool sbp_multipart_string_valid(const sbp_string_t *s, size_t max_encoded_len);
int sbp_multipart_string_strcmp(const sbp_string_t *a, const sbp_string_t *b,
                                size_t max_encoded_len);
size_t sbp_multipart_string_encoded_len(const sbp_string_t *s,
                                        size_t max_encoded_len);
size_t sbp_multipart_string_space_remaining(const sbp_string_t *s,
                                            size_t max_encoded_len);
size_t sbp_multipart_string_count_sections(const sbp_string_t *s,
                                           size_t max_encoded_len);
size_t sbp_multipart_string_section_strlen(const sbp_string_t *s,
                                           size_t max_encoded_len,
                                           size_t section);

bool sbp_multipart_string_add_section(sbp_string_t *s, size_t max_encoded_len,
                                      const char *str);
bool sbp_multipart_string_add_section_vprintf(sbp_string_t *s,
                                              size_t max_encoded_len,
                                              const char *fmt, va_list ap);

bool sbp_multipart_string_append(sbp_string_t *s, size_t max_encoded_len,
                                 const char *new_str);
bool sbp_multipart_string_append_vprintf(sbp_string_t *s,
                                         size_t max_encoded_len,
                                         const char *fmt, va_list ap);
const char *sbp_multipart_string_get_section(const sbp_string_t *s,
                                             size_t max_encoded_len,
                                             size_t section);
bool sbp_multipart_string_encode(const sbp_string_t *s, size_t max_encoded_len,
                                 sbp_encode_ctx_t *ctx);
bool sbp_multipart_string_decode(sbp_string_t *s, size_t max_encoded_len,
                                 sbp_decode_ctx_t *ctx);

#ifdef __cplusplus
}
#endif

#endif
