#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <libsbp/internal/v4/string/null_terminated.h>
#include <libsbp/internal/v4/string/sbp_strnlen.h>
#include <libsbp/internal/v4/string/sbp_string.h>

static const sbp_string_params_t params = {
  .valid = sbp_null_terminated_string_valid,
  .init = sbp_null_terminated_string_init,
  .default_output = {0,},
  .default_output_len = 1,
  .inject_missing_terminator = true,
};

static void maybe_init(sbp_string_t *s, size_t max_encoded_len)
{
  if (!sbp_null_terminated_string_valid(s, max_encoded_len) || s->encoded_len == 0)
    sbp_null_terminated_string_init(s, max_encoded_len);
}

void sbp_null_terminated_string_init(sbp_string_t *s, size_t max_encoded_len)
{
  (void)max_encoded_len;
  memset(s, 0, sizeof(*s));
  s->encoded_len = 1;
}

bool sbp_null_terminated_string_valid(const sbp_string_t *s,
                                      size_t max_encoded_len)
{
  if (s->encoded_len == 0) return false;
  size_t n = sbp_strnlen(s->data, sizeof(s->data));
  if (n + 1 > max_encoded_len) return false;
  if (n + 1 != s->encoded_len) return false;
  return s->data[n] == 0;
}

int sbp_null_terminated_string_strcmp(const sbp_string_t *a,
                                      const sbp_string_t *b,
                                      size_t max_encoded_len)
{
  return sbp_string_cmp(a, b, max_encoded_len, &params);
}

size_t sbp_null_terminated_string_encoded_len(const sbp_string_t *s,
                                              size_t max_encoded_len)
{
  if (!sbp_null_terminated_string_valid(s, max_encoded_len)) return 1;
  return s->encoded_len;
}

size_t sbp_null_terminated_string_strlen(const sbp_string_t *s,
                                          size_t max_encoded_len)
{
  return sbp_null_terminated_string_encoded_len(s, max_encoded_len) - 1;
}

size_t sbp_null_terminated_string_space_remaining(const sbp_string_t *s,
                                                   size_t max_encoded_len)
{
  return max_encoded_len - sbp_null_terminated_string_encoded_len(s, max_encoded_len);
}

bool sbp_null_terminated_string_set(sbp_string_t *s,
                                    size_t max_encoded_len,
                                    const char *new_str)
{
  size_t copied;
  if (!sbp_string_copy_to_buf(s->data, &copied, max_encoded_len, new_str)) return false;
  s->encoded_len = copied;
  return true;
}

bool sbp_null_terminated_string_vprintf(sbp_string_t *s,
                                        size_t max_encoded_len,
                                        const char *fmt,
                                        va_list ap)
{
  size_t copied;
  if (!sbp_string_vprintf_to_buf(s->data, &copied, max_encoded_len, fmt, ap)) return false;
  s->encoded_len = copied;
  return true;
}

bool sbp_null_terminated_string_append(sbp_string_t *s,
                                       size_t max_encoded_len,
                                       const char *new_str)
{
  maybe_init(s, max_encoded_len);
  size_t copied;
  if (!sbp_string_copy_to_buf(s->data + s->encoded_len - 1, &copied, max_encoded_len - s->encoded_len + 1, new_str)) return false;
  s->encoded_len += copied - 1;
  return true;
}

bool sbp_null_terminated_string_append_vprintf(sbp_string_t *s,
                                               size_t max_encoded_len,
                                               const char *fmt,
                                               va_list ap)
{
  maybe_init(s, max_encoded_len);
  size_t copied;
  if (!sbp_string_vprintf_to_buf(s->data + s->encoded_len - 1, &copied, max_encoded_len - s->encoded_len + 1, fmt, ap)) return false;
  s->encoded_len += copied - 1;
  return true;
}

const char *sbp_null_terminated_string_get(const sbp_string_t *s,
                                           size_t max_encoded_len)
{
  if (!sbp_null_terminated_string_valid(s, max_encoded_len))
    return NULL;
  return s->data;
}

bool sbp_null_terminated_string_encode(const sbp_string_t *s,
                                     size_t max_encoded_len,
                                     sbp_encode_ctx_t *ctx)
{
  return sbp_string_encode(s, max_encoded_len, ctx, &params);
}

bool sbp_null_terminated_string_decode(sbp_string_t *s,
                                       size_t max_encoded_len,
                                       sbp_decode_ctx_t *ctx)
{
  // Find out if we have a valid string. The valid unpack cases are
  // - A NULL is found up to max_encoded_len into the incoming buffer
  // - The buffer contains less than max_encoded_len bytes and there is a NULL terminator in the final byte
  // - The buffer contains less than max_encoded_len bytes and there is no NULL terminator in the final byte
  size_t max_copy = max_encoded_len;
  size_t max_buf_copy = ctx->buf_len - ctx->offset;
  if (max_copy > max_buf_copy)
    max_copy = max_buf_copy;
  size_t i;
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
      s->encoded_len = 1;
      return false;
    }
    // Reached the end of the incoming buffer without finding a NULL. Make sure we have a NULL in the unpacked string
    // and call it success
    s->data[i] = 0;
    s->encoded_len = i + 1; // Append a NULL terminator
    ctx->offset += i;
    return true;
  }

  // Found a NULL terminator before the end of the incoming buffer. There must be more data to follow so just take what
  // we have and return success
  s->encoded_len = i + 1;
  ctx->offset += i + 1;
  return true;
}
