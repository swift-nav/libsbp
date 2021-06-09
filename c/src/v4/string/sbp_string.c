#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

#include <libsbp/v4/string/sbp_string.h>
#include <libsbp/internal/v4/string/sbp_string.h>
#include <libsbp/internal/v4/string/sbp_strnlen.h>
#include <libsbp/internal/v4/common.h>

int sbp_string_cmp(const sbp_string_t *a, const sbp_string_t *b, size_t max_encoded_len, const sbp_string_params_t *params)
{
  bool avalid = params->valid(a, max_encoded_len);
  bool bvalid = params->valid(b, max_encoded_len);
  if (!avalid) return bvalid ? -1 : 0;
  if (!bvalid) return avalid ? 1 : 0;
  size_t cmp_len = max_encoded_len;
  if (a->encoded_len < cmp_len)
    cmp_len = a->encoded_len;
  if (b->encoded_len < cmp_len)
    cmp_len = b->encoded_len;
  int ret = memcmp(a->data, b->data, cmp_len);
  if (ret != 0) return ret;
  if (a->encoded_len == b->encoded_len) return 0;
  return a->encoded_len > b->encoded_len ? 1 : -1;
}

static bool copy_str(char *buf, size_t *copied, size_t max, const char *str, size_t str_len)
{
  if (str_len >= max) return false;
  memcpy(buf, str, str_len + 1);
  *copied = str_len + 1;
  return true;
}

bool sbp_string_copy_to_buf(char *buf, size_t *copied, size_t max, const char *str)
{
  return copy_str(buf, copied, max, str, sbp_strnlen(str, max));
}

bool sbp_string_vprintf_to_buf(char *buf, size_t *copied, size_t max, const char *fmt, va_list ap)
{
  char tmp[256];
  int n = vsnprintf(tmp, sizeof(tmp), fmt, ap);
  if (n < 0) return false;
  return copy_str(buf, copied, max, tmp, (size_t)n);
}

bool sbp_string_encode(const sbp_string_t *s, size_t max_encoded_len, sbp_encode_ctx_t *ctx, const sbp_string_params_t *params)
{
  const char *src;
  size_t copy_len;
  if (params->valid(s, max_encoded_len))
  {
    src = s->data;
    copy_len = s->encoded_len;
  } else {
    src = params->default_output;
    copy_len = params->default_output_len;
  }
  if ((ctx->buf_len - ctx->offset) < copy_len) return false;
  memcpy(&ctx->buf[ctx->offset], src, copy_len);
  ctx->offset += copy_len;
  return true;
}

bool sbp_string_decode(sbp_string_t *s, size_t max_encoded_len, sbp_decode_ctx_t *ctx, const sbp_string_params_t *params)
{
  params->init(s, max_encoded_len);
  size_t available = ctx->buf_len - ctx->offset;
  // Take everything or nothing
  if (available > max_encoded_len) return false;
  memcpy(s->data, ctx->buf + ctx->offset, available);
  s->encoded_len = available;
  if (!params->valid(s, max_encoded_len)) { params->init(s, max_encoded_len); return false; }
  ctx->offset += available;
  return true;
}
