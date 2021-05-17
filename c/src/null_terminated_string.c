#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <libsbp/unpacked/string/null_terminated.h>

void sbp_null_terminated_string_init(sbp_null_terminated_string_t *s, uint8_t max_packed_len)
{
  (void)max_packed_len;
  memset(s->data, 0, sizeof(s->data));
  s->len = 0;
}

bool sbp_null_terminated_string_valid(const sbp_null_terminated_string_t *s, uint8_t max_packed_len)
{
  return s->len < max_packed_len;
}

uint8_t sbp_null_terminated_string_packed_len(const sbp_null_terminated_string_t *s, uint8_t max_packed_len)
{
  if (!sbp_null_terminated_string_valid(s, max_packed_len))
    return 0;
  return (uint8_t)(s->len + 1);
}

bool sbp_null_terminated_string_set(sbp_null_terminated_string_t *s, const char *new_str, uint8_t max_packed_len)
{
  size_t new_len = strlen(new_str);
  if (new_len >= max_packed_len)
    return false;
  strncpy(s->data, new_str, sizeof(s->data));
  s->len = (uint8_t)new_len;
  return true;
}

bool sbp_null_terminated_string_printf(sbp_null_terminated_string_t *s, uint8_t max_packed_len, const char *fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_null_terminated_string_vprintf(s, max_packed_len, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_null_terminated_string_vprintf(sbp_null_terminated_string_t *s, uint8_t max_packed_len, const char *fmt, va_list ap)
{
  char new_str[256];
  int len = vsnprintf(new_str, max_packed_len, fmt, ap);

  if ((size_t)len >= max_packed_len)
    return false;
  memcpy(s->data, new_str, (size_t)len + 1);
  s->len = (uint8_t)len;
  return true;
}

const char *sbp_null_terminated_string_get(const sbp_null_terminated_string_t *s, uint8_t max_packed_len)
{
  if (!sbp_null_terminated_string_valid(s, max_packed_len))
    return NULL;
  return s->data;
}

bool sbp_null_terminated_string_pack(const sbp_null_terminated_string_t *s,
                                        uint8_t max_packed_len,
                                        sbp_pack_ctx_t *ctx)
{
  if (!sbp_null_terminated_string_valid(s, max_packed_len))
    return false;
  if ((ctx->buf_len - ctx->offset) < (s->len + 1u))
    return false;
  memcpy(&ctx->buf[ctx->offset], s->data, (size_t)(s->len + 1u));
  ctx->offset += s->len + 1U;
  return true;
}

bool sbp_null_terminated_string_unpack(sbp_null_terminated_string_t *s,
                                          uint8_t max_packed_len,
                                          sbp_unpack_ctx_t *ctx)
{
  (void)max_packed_len;
  size_t buf_len = ctx->buf_len - ctx->offset; 
  size_t copy_len = strnlen((const char *)&ctx->buf[ctx->offset], buf_len);
  copy_len++;
  if (copy_len > buf_len)
    copy_len = buf_len;
  if (!copy_len)
  {
    sbp_null_terminated_string_init(s, max_packed_len);
    return 0;
  }
  memcpy(s->data, &ctx->buf[ctx->offset], copy_len);
  s->len = (uint8_t)(copy_len - 1u);
  ctx->offset += copy_len;
  return true;
}

int sbp_null_terminated_string_strcmp(const sbp_null_terminated_string_t *a,
                                      const sbp_null_terminated_string_t *b,
                                      uint8_t max_packed_len)
{
  bool avalid = sbp_null_terminated_string_valid(a, max_packed_len);
  bool bvalid = sbp_null_terminated_string_valid(b, max_packed_len);
  if (!avalid)
    return bvalid ? 1 : 0;
  if (!bvalid)
    return avalid ? -1 : 0;
  uint8_t cmp_len = max_packed_len;
  if (a->len < cmp_len)
    cmp_len = a->len;
  if (b->len < cmp_len)
    cmp_len = b->len;
  cmp_len++;
  if (memcmp(a->data, b->data, cmp_len) == 0)
    return 0;
  return (int)b->len - (int)a->len;
}
