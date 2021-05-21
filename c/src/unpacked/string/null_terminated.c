#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <libsbp/internal/unpacked/string/null_terminated.h>
#include <libsbp/unpacked/string/null_terminated.h>

static void maybe_init(sbp_null_terminated_string_t *s, const sbp_null_terminated_string_params_t *params)
{
  if (!sbp_null_terminated_string_valid(s, params) || s->packed_len == 0)
    sbp_null_terminated_string_init(s, params);
}

void sbp_null_terminated_string_init(sbp_null_terminated_string_t *s, const sbp_null_terminated_string_params_t *params)
{
  (void)params;
  memset(s, 0, sizeof(*s));
  s->packed_len = 1;
}

bool sbp_null_terminated_string_valid(const sbp_null_terminated_string_t *s,
                                      const sbp_null_terminated_string_params_t *params)
{
  if (s->packed_len == 0)
  {
    return true;
  }
  if (s->packed_len > params->max_packed_len)
  {
    return false;
  }
  return s->data[s->packed_len - 1] == 0;
}

int sbp_null_terminated_string_strcmp(const sbp_null_terminated_string_t *a,
                                      const sbp_null_terminated_string_t *b,
                                      const sbp_null_terminated_string_params_t *params)
{
  bool avalid = sbp_null_terminated_string_valid(a, params);
  bool bvalid = sbp_null_terminated_string_valid(b, params);
  if (!avalid)
    return bvalid ? -1 : 0;
  if (!bvalid)
    return avalid ? 1 : 0;
  uint8_t cmp_len = params->max_packed_len;
  if (a->packed_len < cmp_len)
    cmp_len = a->packed_len;
  if (b->packed_len < cmp_len)
    cmp_len = b->packed_len;
  int ret = memcmp(a->data, b->data, cmp_len);
  if (ret != 0)
    return ret;
  if (a->packed_len == b->packed_len)
    return 0;
  return a->packed_len > b->packed_len ? 1 : -1;
}

uint8_t sbp_null_terminated_string_packed_len(const sbp_null_terminated_string_t *s,
                                              const sbp_null_terminated_string_params_t *params)
{
  if (!sbp_null_terminated_string_valid(s, params))
    return 1;
  if (s->packed_len == 0)
    return 1;
  return s->packed_len;
}

uint8_t sbp_null_terminated_string_strlen(const sbp_null_terminated_string_t *s,
                                          const sbp_null_terminated_string_params_t *params)
{
  return (uint8_t)(sbp_null_terminated_string_packed_len(s, params) - 1);
}

uint8_t sbp_null_terminated_string_space_remaining(const sbp_null_terminated_string_t *s,
                                                   const sbp_null_terminated_string_params_t *params)
{
  return (uint8_t)(params->max_packed_len - sbp_null_terminated_string_packed_len(s, params));
}

bool sbp_null_terminated_string_set(sbp_null_terminated_string_t *s,
                                    const sbp_null_terminated_string_params_t *params,
                                    const char *new_str)
{
  size_t new_str_len = strnlen(new_str, params->max_packed_len);
  if (new_str_len == params->max_packed_len)
    return false;
  strncpy(s->data, new_str, new_str_len);
  s->packed_len = (uint8_t)(new_str_len + 1);
  s->data[s->packed_len - 1] = 0;
  return true;
}

bool sbp_null_terminated_string_vprintf(sbp_null_terminated_string_t *s,
                                        const sbp_null_terminated_string_params_t *params,
                                        const char *fmt,
                                        va_list ap)
{
  size_t max_write = params->max_packed_len;

  int n = vsnprintf(s->data, max_write, fmt, ap);

  if (n >= 0 && n < (int)max_write)
  {
    s->packed_len = (uint8_t)(n + 1);
    return true;
  }

  // Not great, invalidates the string since vsnprintf probably wrote at least something and destroyed whatever was
  // already there
  s->data[0] = 0;
  s->packed_len = 1;
  return false;
}

bool sbp_null_terminated_string_append(sbp_null_terminated_string_t *s,
                                       const sbp_null_terminated_string_params_t *params,
                                       const char *new_str)
{
  maybe_init(s, params);
  size_t new_str_len = strnlen(new_str, params->max_packed_len);
  if (new_str_len == params->max_packed_len)
    return false;
  uint8_t max_copy = sbp_null_terminated_string_space_remaining(s, params);
  if (new_str_len + 1 > max_copy)
    return false;
  if (new_str_len + 1 < max_copy)
    max_copy = (uint8_t)(new_str_len + 1);
  uint8_t offset = (uint8_t)(s->packed_len - 1);
  strncpy(s->data + offset, new_str, max_copy);
  s->packed_len = (uint8_t)(s->packed_len + max_copy - 1);
  return true;
}

bool sbp_null_terminated_string_append_vprintf(sbp_null_terminated_string_t *s,
                                               const sbp_null_terminated_string_params_t *params,
                                               const char *fmt,
                                               va_list ap)
{
  maybe_init(s, params);
  size_t max_write = sbp_null_terminated_string_space_remaining(s, params);
  if (max_write == 0)
    return false;
  max_write++; // Overwrite terminating null
  size_t offset = params->max_packed_len - max_write;

  int n = vsnprintf(s->data + offset, max_write, fmt, ap);

  if (n >= 0 && n < (int)max_write)
  {
    s->packed_len = (uint8_t)(s->packed_len + n);
    return true;
  }

  // Print was going to overrun the buffer. Insert a NULL back in to the right place to "undo" what it did
  s->data[s->packed_len-1] = 0;
  return false;
}

const char *sbp_null_terminated_string_get(const sbp_null_terminated_string_t *s,
                                           const sbp_null_terminated_string_params_t *params)
{
  if (!sbp_null_terminated_string_valid(s, params))
    return "";
  return s->data;
}

bool sbp_null_terminated_string_pack(const sbp_null_terminated_string_t *s,
                                     const sbp_null_terminated_string_params_t *params,
                                     sbp_pack_ctx_t *ctx)
{
  if ((ctx->buf_len - ctx->offset) < sbp_null_terminated_string_packed_len(s, params))
    return false;
  if (!sbp_null_terminated_string_valid(s, params) || s->packed_len == 0)
  {
    // Always need to write something. This string instance isn't valid so write a single NULL terminator and call it
    // done
    ctx->buf[ctx->offset++] = 0;
    return true;
  }
  memcpy(&ctx->buf[ctx->offset], s->data, s->packed_len);
  ctx->offset += s->packed_len;
  return true;
}

bool sbp_null_terminated_string_unpack(sbp_null_terminated_string_t *s,
                                       const sbp_null_terminated_string_params_t *params,
                                       sbp_unpack_ctx_t *ctx)
{
  // Find out if we have a valid string. The valid unpack cases are
  // - A NULL is found up to params->max_packed_len into the incoming buffer
  // - The buffer contains less than params->max_packed_len bytes and there is a NULL terminator in the final byte
  // - The buffer contains less than params->max_packed_len bytes and there is no NULL terminator in the final byte
  uint8_t max_copy = params->max_packed_len;
  uint8_t max_buf_copy = (uint8_t)(ctx->buf_len - ctx->offset);
  if (max_copy > max_buf_copy)
    max_copy = max_buf_copy;
  uint8_t i;
  for (i = 0; i < max_copy; i++)
  {
    s->data[i] = (char)ctx->buf[ctx->offset + i];
    if (s->data[i] == 0)
      break;
  }

  if (i == max_copy)
  {
    // No NULL terminator found
    if (i < max_buf_copy)
    {
      // the incoming buffer continues on with more data. We can't be certain we have actually read a proper string so
      // invalidate everything and return an error
      s->data[0] = 0;
      s->packed_len = 1;
      return false;
    }
    // Reached the end of the incoming buffer without finding a NULL. Make sure we have a NULL in the unpacked string
    // and call it success
    s->data[i] = 0;
    s->packed_len = (uint8_t)(i + 1); // Append a NULL terminator
    ctx->offset += i;
    return true;
  }

  // Found a NULL terminator before the end of the incoming buffer. There must be more data to follow so just take what
  // we have and return success
  s->packed_len = (uint8_t)(i + 1);
  ctx->offset += (uint8_t)(i + 1);
  return true;
}
