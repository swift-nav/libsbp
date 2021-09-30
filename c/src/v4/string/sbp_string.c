#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include <libsbp/internal/v4/common.h>
#include <libsbp/internal/v4/string/sbp_string.h>
#include <libsbp/internal/v4/string/sbp_strnlen.h>
#include <libsbp/v4/string/sbp_string.h>

int sbp_string_cmp(const sbp_string_t *a, const sbp_string_t *b,
                   size_t maxlen, const sbp_string_params_t *params) {
  bool avalid = params->valid(a, maxlen);
  bool bvalid = params->valid(b, maxlen);
  if (!avalid) {
    return bvalid ? -1 : 0;
  }
  if (!bvalid) {
    return avalid ? 1 : 0;
  }
  size_t cmp_len = maxlen;
  if (a->encoded_len < cmp_len) {
    cmp_len = a->encoded_len;
  }
  if (b->encoded_len < cmp_len) {
    cmp_len = b->encoded_len;
  }
  int ret = memcmp(a->data, b->data, cmp_len);
  if (ret != 0) {
    return ret;
  }
  if (a->encoded_len == b->encoded_len) {
    return 0;
  }
  return a->encoded_len > b->encoded_len ? 1 : -1;
}

static bool copy_str(char *buf, size_t *copied, size_t max, const char *str,
                     size_t str_len) {
  if (str_len >= max) {
    return false;
  }
  memcpy(buf, str, str_len);
  buf[str_len] = '\0';
  *copied = str_len + 1;
  return true;
}

bool sbp_string_copy_to_buf(char *buf, size_t *copied, size_t max,
                            const char *str, size_t n) {
  return copy_str(buf, copied, max, str, n);
}

bool sbp_string_vprintf_to_buf(char *buf, size_t *copied, size_t max, bool should_trunc,
                               const char *fmt, va_list ap) {
  char tmp[256];
  int n = vsnprintf(tmp, sizeof(tmp), fmt, ap);
  if (n < 0) {
    return false;
  }
  size_t trunc_len = (max - 1) < (size_t)n ? (max - 1) : (size_t)n;
  size_t len = should_trunc ? trunc_len : (size_t)n;
  return copy_str(buf, copied, max, tmp, len);
}

bool sbp_string_encode(const sbp_string_t *s, size_t maxlen,
                       sbp_encode_ctx_t *ctx,
                       const sbp_string_params_t *params) {
  const char *src;
  size_t copy_len;
  if (params->valid(s, maxlen)) {
    src = s->data;
    copy_len = s->encoded_len;
  } else {
    src = params->default_output;
    copy_len = params->default_output_len;
  }
  if ((ctx->buf_len - ctx->offset) < copy_len) {
    return false;
  }
  memcpy(&ctx->buf[ctx->offset], src, copy_len);
  ctx->offset += copy_len;
  return true;
}

bool sbp_string_decode(sbp_string_t *s, size_t maxlen,
                       sbp_decode_ctx_t *ctx,
                       const sbp_string_params_t *params) {
  params->init(s);
  size_t available = ctx->buf_len - ctx->offset;
  // Take everything or nothing
  if (available > maxlen) {
    return false;
  }
  if (params->inject_missing_terminator && available == 0) {
    return false;
  }
  memcpy(s->data, ctx->buf + ctx->offset, available);
  s->encoded_len = available;
  if (params->inject_missing_terminator) {
    if (s->data[s->encoded_len - 1] != 0) {
      s->encoded_len++;
      s->data[s->encoded_len - 1] = 0;
    }
  }
  if (!params->valid(s, maxlen)) {
    params->init(s);
    return false;
  }
  ctx->offset += available;
  return true;
}
