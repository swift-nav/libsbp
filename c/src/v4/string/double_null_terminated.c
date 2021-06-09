#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <libsbp/v4/string/double_null_terminated.h>
#include <libsbp/internal/v4/string/double_null_terminated.h>
#include <libsbp/internal/v4/string/sbp_strnlen.h>

static void maybe_init(sbp_double_null_terminated_string_t *s, const sbp_double_null_terminated_string_params_t *params)
{
  if (!sbp_double_null_terminated_string_valid(s, params))
    sbp_double_null_terminated_string_init(s, params);
}

void sbp_double_null_terminated_string_init(sbp_double_null_terminated_string_t *s, const sbp_double_null_terminated_string_params_t *params)
{
  (void)params;
  memset(s, 0, sizeof(*s));
  s->encoded_len = 2;
}

bool sbp_double_null_terminated_string_valid(const sbp_double_null_terminated_string_t *s, const sbp_double_null_terminated_string_params_t *params)
{
  if (s->encoded_len == 0) return true;
  if (s->encoded_len == 1) return false;
  if (s->encoded_len == 2 && s->data[0] == 0 && s->data[1] == 0) return true;
  if (s->encoded_len > params->max_encoded_len) return false;
  uint8_t offset = 0;
  for (uint8_t i = 0; i < s->n_sections; i++)
  {
    if (offset != s->offsets[i]) return false;
    offset = (uint8_t)(offset + s->lens[i]);
    if (s->data[offset] != 0) return false;
    offset++;
  }
  // the final byte must be the extra NULL terminator
    if (s->data[offset++] != 0)
      return false;
  if (offset != s->encoded_len) return false;
  return true;
}

int sbp_double_null_terminated_string_strcmp(const sbp_double_null_terminated_string_t *a,
                                const sbp_double_null_terminated_string_t *b,
                                const sbp_double_null_terminated_string_params_t *params)
{
  bool avalid = sbp_double_null_terminated_string_valid(a, params);
  bool bvalid = sbp_double_null_terminated_string_valid(b, params);
  if (!avalid) return bvalid ? -1 : 0;
  if (!bvalid) return avalid ? 1 : 0;
  uint8_t cmp_len = params->max_encoded_len;
  if (a->encoded_len < cmp_len) cmp_len = a->encoded_len;
  if (b->encoded_len < cmp_len) cmp_len = b->encoded_len;
  int ret = memcmp(a->data, b->data, cmp_len);
  if (ret != 0) return ret;
  if (a->encoded_len == b->encoded_len) return 0;
  return a->encoded_len > b->encoded_len ? 1 : -1;
}

uint8_t sbp_double_null_terminated_string_encoded_len(const sbp_double_null_terminated_string_t *s, const sbp_double_null_terminated_string_params_t *params)
{
  if (!sbp_double_null_terminated_string_valid(s, params)) return 2;
  if (s->encoded_len == 0) return 2;
  return s->encoded_len;
}

uint8_t sbp_double_null_terminated_string_space_remaining(const sbp_double_null_terminated_string_t *s,
                                             const sbp_double_null_terminated_string_params_t *params)
{
  if (!sbp_double_null_terminated_string_valid(s, params) || s->encoded_len == 0) return (uint8_t)(params->max_encoded_len - 2);
  return (uint8_t)(params->max_encoded_len - s->encoded_len);
}

uint8_t sbp_double_null_terminated_string_count_sections(const sbp_double_null_terminated_string_t *s,
                                            const sbp_double_null_terminated_string_params_t *params)
{
  if (!sbp_double_null_terminated_string_valid(s, params)) return 0;
  return s->n_sections;
}

uint8_t sbp_double_null_terminated_string_section_strlen(const sbp_double_null_terminated_string_t *s,
                                            const sbp_double_null_terminated_string_params_t *params,
                                            uint8_t section)
{
  if (!sbp_double_null_terminated_string_valid(s, params)) return 0;
  if (s->encoded_len == 0) return 0;
  if (section >= s->n_sections) return 0;
  return s->lens[section];
}


bool sbp_double_null_terminated_string_add_section(sbp_double_null_terminated_string_t *s,
                                      const sbp_double_null_terminated_string_params_t *params,
                                      const char *str)
{
  maybe_init(s, params);
  size_t new_str_len = sbp_strnlen(str, params->max_encoded_len);
  if (new_str_len == params->max_encoded_len) return false;
  size_t copy_len = new_str_len + 1; // Include NULL terminator
  // Calculate the length of the string buffer if the new section were to be accepted
  size_t final_len = s->encoded_len;
  if (s->n_sections == 0) final_len--; // Overwrite the NULL which currently exists in the first byte of the string
  final_len += copy_len;

  if (final_len > params->max_encoded_len) return false;

  size_t offset;
  if (s->n_sections == 0) offset = 0;
  else offset = (size_t)s->offsets[s->n_sections-1] + (size_t)s->lens[s->n_sections-1] + 1u;

  s->offsets[s->n_sections] = (uint8_t)offset;
  s->lens[s->n_sections] = (uint8_t)new_str_len;
  s->n_sections++;
  memcpy(s->data + offset, str, copy_len);

  // Replace the terminator
  s->data[final_len-1] = 0;
  s->encoded_len = (uint8_t)final_len;
  return true;
}

bool sbp_double_null_terminated_string_add_section_vprintf(sbp_double_null_terminated_string_t *s,
                                              const sbp_double_null_terminated_string_params_t *params,
                                              const char *fmt,
                                              va_list ap)
{
  maybe_init(s, params);

  size_t offset;
  if (s->n_sections == 0) offset = 0;
  else offset = (size_t)s->offsets[s->n_sections-1] + (size_t)s->lens[s->n_sections-1] + 1u;
  size_t max_write = (size_t)params->max_encoded_len - (size_t)s->encoded_len;
  max_write++; // Reuse existing first NULL terminator in empty double NULL terminated sequences

  int n = vsnprintf(s->data + offset, max_write, fmt, ap);

  if (n < 0 || n >= (int)max_write) {
    if (s->n_sections == 0)
    {
      sbp_double_null_terminated_string_init(s, params);
    }
    else
    {
      s->data[s->encoded_len-1] = 0;
    }
    return false;
  }

  s->encoded_len = (uint8_t)(s->encoded_len + n);
  if (s->n_sections != 0) s->encoded_len++;
  s->offsets[s->n_sections] = (uint8_t)offset;
  s->lens[s->n_sections] = (uint8_t)n;
  s->n_sections++;

  s->data[s->encoded_len-1] = 0;
  return true;
}


bool sbp_double_null_terminated_string_append(sbp_double_null_terminated_string_t *s,
                                 const sbp_double_null_terminated_string_params_t *params,
                                 const char *new_str)
{
  maybe_init(s, params);
  if (s->n_sections == 0) return sbp_double_null_terminated_string_add_section(s, params, new_str);
  size_t max_copy_len = (size_t)(params->max_encoded_len - s->encoded_len + 1);
  size_t new_str_len = sbp_strnlen(new_str, max_copy_len);
  size_t copy_len = new_str_len + 1;
  if (copy_len > max_copy_len) return false;

  size_t offset = s->encoded_len - 2u;
  s->lens[s->n_sections-1] = (uint8_t)(s->lens[s->n_sections-1] + new_str_len);
  memcpy(s->data + offset, new_str, copy_len);

  s->encoded_len = (uint8_t)(s->encoded_len + new_str_len);
  s->data[s->encoded_len-1] = 0;
  return true;
}

bool sbp_double_null_terminated_string_append_vprintf(sbp_double_null_terminated_string_t *s,
                                         const sbp_double_null_terminated_string_params_t *params,
                                         const char *fmt,
                                         va_list ap)
{
  maybe_init(s, params);
  if (s->n_sections == 0) return sbp_double_null_terminated_string_add_section_vprintf(s, params, fmt, ap);

  size_t max_write = (size_t)(params->max_encoded_len - s->encoded_len + 1);
  size_t max_buf_len = (size_t)(params->max_encoded_len - s->encoded_len + 1);
  int n = vsnprintf(s->data + s->encoded_len - 2, max_write, fmt, ap);
  if (n < 0 || n >= (int)max_buf_len) {
    s->data[s->offsets[s->n_sections-1] + s->lens[s->n_sections-1]] = 0;
    s->data[s->encoded_len-1] = 0;
    return false;
  }
  s->lens[s->n_sections-1] = (uint8_t)(s->lens[s->n_sections-1] + n);
  s->encoded_len = (uint8_t)(s->encoded_len + n);
  s->data[s->encoded_len-1] = 0;
  return true;
}

const char *sbp_double_null_terminated_string_get_section(const sbp_double_null_terminated_string_t *s,
                                             const sbp_double_null_terminated_string_params_t *params,
                                             uint8_t section)
{
  if (!sbp_double_null_terminated_string_valid(s, params)) return "";
  if (section >= s->n_sections) return "";
  return s->data + s->offsets[section];
}

bool sbp_double_null_terminated_string_pack(const sbp_double_null_terminated_string_t *s, const sbp_double_null_terminated_string_params_t *params, sbp_encode_ctx_t *ctx)
{
  if (!sbp_double_null_terminated_string_valid(s, params)) return false;
  if (s->encoded_len > (ctx->buf_len - ctx->offset)) return false;
  memcpy(&ctx->buf[ctx->offset], s->data, s->encoded_len);
  ctx->offset += s->encoded_len;
  return true;
}

bool sbp_double_null_terminated_string_unpack(sbp_double_null_terminated_string_t *s, const sbp_double_null_terminated_string_params_t *params, sbp_decode_ctx_t *ctx)
{
  size_t copy_len = ctx->buf_len - ctx->offset;
  // Take the entire incoming buffer of nothing at all, double_null_terminated strings can only occur at the end of a message
  if (copy_len > params->max_encoded_len) return false;
  memset(s, 0, sizeof(*s));
  if (copy_len == 0) return true;
  memcpy(s->data, ctx->buf + ctx->offset, copy_len);
  s->encoded_len = (uint8_t)copy_len;
  if (s->data[s->encoded_len - 1] != 0) s->encoded_len++; // Copy with missing final NULL terminator

  if (s->encoded_len == 2) {
    if (s->data[0] == 0 && s->data[1] == 0)
    {
      ctx->offset = ctx->buf_len;
      return true;
    }
  }

  uint8_t i;
  for (i = 0; i < s->encoded_len && s->n_sections < SBP_DOUBLE_NULL_TERMINATED_STRING_MAX_SECTIONS; i++)
  {
    if (s->data[i] == 0)
    {
      if (i > 0) {
        if (s->data[i-1] == 0)
        {
          i++;
          break;
        }
      }

      s->lens[s->n_sections] = (uint8_t)(i - s->offsets[s->n_sections]);
      s->n_sections++;
      if (s->n_sections < SBP_DOUBLE_NULL_TERMINATED_STRING_MAX_SECTIONS)
        s->offsets[s->n_sections] = (uint8_t)(i + 1);
    }
  }
  if (i != s->encoded_len) 
  {
    sbp_double_null_terminated_string_init(s, params);
    return false; // Too many sections
  }
  if (!sbp_double_null_terminated_string_valid(s, params)) return false;
  ctx->offset = ctx->buf_len;
  return true;
}
