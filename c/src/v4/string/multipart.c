#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <libsbp/internal/v4/string/multipart.h>
#include <libsbp/internal/v4/string/sbp_strnlen.h>
#include <libsbp/internal/v4/string/sbp_string.h>

static const sbp_string_params_t params = {
  .valid = sbp_multipart_string_valid,
  .init = sbp_multipart_string_init,
  .default_output = {0,},
  .default_output_len = 0,
  .inject_missing_terminator = true,
};

static void maybe_init(sbp_string_t *s, size_t max_encoded_len)
{
  if (!sbp_multipart_string_valid(s, max_encoded_len))
    sbp_multipart_string_init(s, max_encoded_len);
}

void sbp_multipart_string_init(sbp_string_t *s, size_t max_encoded_len)
{
  (void)max_encoded_len;
  memset(s, 0, sizeof(*s));
}

bool sbp_multipart_string_valid(const sbp_string_t *s, size_t max_encoded_len)
{
  if (s->encoded_len == 0) return true;
  if (s->encoded_len > max_encoded_len) return false;
  return s->data[s->encoded_len-1] == 0;
}

int sbp_multipart_string_strcmp(const sbp_string_t *a,
                                const sbp_string_t *b,
                                size_t max_encoded_len)
{
  return sbp_string_cmp(a, b, max_encoded_len, &params);
}

size_t sbp_multipart_string_encoded_len(const sbp_string_t *s, size_t max_encoded_len)
{
  if (!sbp_multipart_string_valid(s, max_encoded_len)) return 0;
  return s->encoded_len;
}

size_t sbp_multipart_string_space_remaining(const sbp_string_t *s,
                                             size_t max_encoded_len)
{
  return max_encoded_len - sbp_multipart_string_encoded_len(s, max_encoded_len);
}

size_t sbp_multipart_string_count_sections(const sbp_string_t *s,
                                            size_t max_encoded_len)
{
  if (!sbp_multipart_string_valid(s, max_encoded_len)) return 0;
  if (s->encoded_len == 0) return 0;
  // Simple count of NULL terminators
  size_t sections = 0;
  for (size_t i = 0; i < s->encoded_len; i++) {
    if (s->data[i] == 0) {
      sections++;
    }
  }
  return sections;
}

static size_t section_offset(const sbp_string_t *s, size_t section)
{
  size_t n_section = 0;
  for (size_t i = 0; i < s->encoded_len; i++) {
    if (n_section == section) {
      return i;
    }
    if (s->data[i] == 0) {
      n_section++;
    }
  }
  return SIZE_MAX;
}

size_t sbp_multipart_string_section_strlen(const sbp_string_t *s,
                                            size_t max_encoded_len,
                                            size_t section)
{
  if (!sbp_multipart_string_valid(s, max_encoded_len)) return 0;
  if (s->encoded_len == 0) return 0;
  size_t offset = section_offset(s, section);
  if (offset == SIZE_MAX) return 0;
  return sbp_strnlen(s->data + offset, s->encoded_len - offset);
}

bool sbp_multipart_string_add_section(sbp_string_t *s,
                                      size_t max_encoded_len,
                                      const char *str)
{
  maybe_init(s, max_encoded_len);
  size_t copied;
  if (!sbp_string_copy_to_buf(s->data + s->encoded_len, &copied, max_encoded_len - s->encoded_len, str)) return false;
  s->encoded_len += copied;
  return true;
}

bool sbp_multipart_string_add_section_vprintf(sbp_string_t *s,
                                              size_t max_encoded_len,
                                              const char *fmt,
                                              va_list ap)
{
  maybe_init(s, max_encoded_len);
  size_t copied;
  if (!sbp_string_vprintf_to_buf(s->data + s->encoded_len, &copied, max_encoded_len - s->encoded_len, fmt, ap)) return false;
  s->encoded_len += copied;
  return true;
}


bool sbp_multipart_string_append(sbp_string_t *s,
                                 size_t max_encoded_len,
                                 const char *new_str)
{
  maybe_init(s, max_encoded_len);
  if (s->encoded_len == 0) return sbp_multipart_string_add_section(s, max_encoded_len, new_str);
  size_t copied;
  if (!sbp_string_copy_to_buf(s->data + s->encoded_len - 1, &copied, max_encoded_len - s->encoded_len + 1, new_str)) return false;
  s->encoded_len += copied - 1;
  return true;
}

bool sbp_multipart_string_append_vprintf(sbp_string_t *s,
                                         size_t max_encoded_len,
                                         const char *fmt,
                                         va_list ap)
{
  maybe_init(s, max_encoded_len);
  if (s->encoded_len == 0) return sbp_multipart_string_add_section_vprintf(s, max_encoded_len, fmt, ap);
  size_t copied;
  if (!sbp_string_vprintf_to_buf(s->data + s->encoded_len - 1, &copied, max_encoded_len - s->encoded_len + 1, fmt, ap)) return false;
  s->encoded_len += copied - 1;
  return true;
}

const char *sbp_multipart_string_get_section(const sbp_string_t *s,
                                             size_t max_encoded_len,
                                             size_t section)
{
  if (!sbp_multipart_string_valid(s, max_encoded_len)) return NULL;
  size_t offset = section_offset(s, section);
  if (offset == SIZE_MAX) return NULL;
  return s->data + offset;
}

bool sbp_multipart_string_encode(const sbp_string_t *s, size_t max_encoded_len, sbp_encode_ctx_t *ctx)
{
  return sbp_string_encode(s, max_encoded_len, ctx, &params);
}

bool sbp_multipart_string_decode(sbp_string_t *s, size_t max_encoded_len, sbp_decode_ctx_t *ctx)
{
  return sbp_string_decode(s, max_encoded_len, ctx, &params);
}
