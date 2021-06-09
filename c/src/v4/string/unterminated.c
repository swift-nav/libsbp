#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <libsbp/internal/v4/string/unterminated.h>
#include <libsbp/v4/string/unterminated.h>
#include <libsbp/internal/v4/string/sbp_strnlen.h>

static void maybe_init(sbp_unterminated_string_t *s, const sbp_unterminated_string_params_t *params)
{
  if (!sbp_unterminated_string_valid(s, params))
    sbp_unterminated_string_init(s, params);
}

void sbp_unterminated_string_init(sbp_unterminated_string_t *s, const sbp_unterminated_string_params_t *params)
{
  (void)params;
  memset(s, 0, sizeof(*s));
}

bool sbp_unterminated_string_valid(const sbp_unterminated_string_t *s,
                                      const sbp_unterminated_string_params_t *params)
{
  if (s->encoded_len > params->max_encoded_len)
  {
    return false;
  }
  // for this string to be valid there must be a NULL terminated immediately after the unpacked representation
  return s->data[s->encoded_len] == 0;
}

int sbp_unterminated_string_strcmp(const sbp_unterminated_string_t *a,
                                      const sbp_unterminated_string_t *b,
                                      const sbp_unterminated_string_params_t *params)
{
  bool avalid = sbp_unterminated_string_valid(a, params);
  bool bvalid = sbp_unterminated_string_valid(b, params);
  if (!avalid)
    return bvalid ? -1 : 0;
  if (!bvalid)
    return avalid ? 1 : 0;
  uint8_t cmp_len = params->max_encoded_len;
  if (a->encoded_len < cmp_len)
    cmp_len = a->encoded_len;
  if (b->encoded_len < cmp_len)
    cmp_len = b->encoded_len;
  int ret = memcmp(a->data, b->data, cmp_len);
  if (ret != 0)
    return ret;
  if (a->encoded_len == b->encoded_len)
    return 0;
  return a->encoded_len > b->encoded_len ? 1 : -1;
}

uint8_t sbp_unterminated_string_encoded_len(const sbp_unterminated_string_t *s,
                                              const sbp_unterminated_string_params_t *params)
{
  if (!sbp_unterminated_string_valid(s, params))
    return 0;
  return s->encoded_len;
}

uint8_t sbp_unterminated_string_strlen(const sbp_unterminated_string_t *s,
                                          const sbp_unterminated_string_params_t *params)
{
  return (uint8_t)(sbp_unterminated_string_encoded_len(s, params));
}

uint8_t sbp_unterminated_string_space_remaining(const sbp_unterminated_string_t *s,
                                                   const sbp_unterminated_string_params_t *params)
{
  return (uint8_t)(params->max_encoded_len - sbp_unterminated_string_encoded_len(s, params));
}

bool sbp_unterminated_string_set(sbp_unterminated_string_t *s,
                                    const sbp_unterminated_string_params_t *params,
                                    const char *new_str)
{
  size_t new_str_len = sbp_strnlen(new_str, params->max_encoded_len + 1u);
  if (new_str_len == params->max_encoded_len + 1u)
    return false;
  strncpy(s->data, new_str, new_str_len);
  s->encoded_len = (uint8_t)(new_str_len);
  s->data[s->encoded_len] = 0;
  return true;
}

bool sbp_unterminated_string_vprintf(sbp_unterminated_string_t *s,
                                        const sbp_unterminated_string_params_t *params,
                                        const char *fmt,
                                        va_list ap)
{
  size_t max_write = params->max_encoded_len;

  int n = vsnprintf(s->data, max_write, fmt, ap);

  if (n >= 0 && n < (int)max_write)
  {
    s->encoded_len = (uint8_t)(n);
    return true;
  }

  // Not great, invalidates the string since vsnprintf probably wrote at least something and destroyed whatever was
  // already there
  s->data[0] = 0;
  s->encoded_len = 0;
  return false;
}

bool sbp_unterminated_string_append(sbp_unterminated_string_t *s,
                                       const sbp_unterminated_string_params_t *params,
                                       const char *new_str)
{
  maybe_init(s, params);
  size_t new_str_len = sbp_strnlen(new_str, params->max_encoded_len);
  if (new_str_len == params->max_encoded_len)
    return false;
  uint8_t max_copy = sbp_unterminated_string_space_remaining(s, params);
  if (new_str_len  > max_copy)
    return false;
  if (new_str_len  < max_copy)
    max_copy = (uint8_t)(new_str_len);
  uint8_t offset = (uint8_t)(s->encoded_len);
  memcpy(s->data + offset, new_str, max_copy);
  s->encoded_len = (uint8_t)(s->encoded_len + max_copy);
  s->data[s->encoded_len] = 0;
  return true;
}

bool sbp_unterminated_string_append_vprintf(sbp_unterminated_string_t *s,
                                               const sbp_unterminated_string_params_t *params,
                                               const char *fmt,
                                               va_list ap)
{
  maybe_init(s, params);
  size_t max_write = sbp_unterminated_string_space_remaining(s, params);
  if (max_write == 0)
    return false;
  size_t offset = params->max_encoded_len - max_write;
  max_write++; // Overwrite terminating null

  int n = vsnprintf(s->data + offset, max_write, fmt, ap);

  if (n >= 0 && n < (int)max_write)
  {
    s->encoded_len = (uint8_t)(s->encoded_len + n);
    return true;
  }

  // Print was going to overrun the buffer. Insert a NULL back in to the right place to "undo" what it did
  s->data[s->encoded_len] = 0;
  return false;
}

const char *sbp_unterminated_string_get(const sbp_unterminated_string_t *s,
                                           const sbp_unterminated_string_params_t *params)
{
  if (!sbp_unterminated_string_valid(s, params))
    return "";
  return s->data;
}

bool sbp_unterminated_string_pack(const sbp_unterminated_string_t *s,
                                     const sbp_unterminated_string_params_t *params,
                                     sbp_encode_ctx_t *ctx)
{
  if ((ctx->buf_len - ctx->offset) < sbp_unterminated_string_encoded_len(s, params))
    return false;
  if (!sbp_unterminated_string_valid(s, params) || s->encoded_len == 0)
  {
    return true;
  }
  memcpy(&ctx->buf[ctx->offset], s->data, s->encoded_len);
  ctx->offset += s->encoded_len;
  return true;
}

bool sbp_unterminated_string_unpack(sbp_unterminated_string_t *s,
                                       const sbp_unterminated_string_params_t *params,
                                       sbp_decode_ctx_t *ctx)
{
  // Unterminated string simply take all the available input data, so long as it fits in the string object
  uint8_t max_copy = params->max_encoded_len;
  uint8_t max_buf_copy = (uint8_t)(ctx->buf_len - ctx->offset);
  if (max_copy < max_buf_copy)
  {
    // More data is available in the input than we can store
    s->data[0] = 0;
    s->encoded_len = 0;
    return false;
  }
  if (max_buf_copy < max_copy)
    max_copy = max_buf_copy; // less data is available in the input that we can store, truncate
  memcpy(s->data, ctx->buf + ctx->offset, max_copy);
  ctx->offset += max_copy;
  s->encoded_len = max_copy;
  s->data[max_copy] = 0;
  return true;
}

