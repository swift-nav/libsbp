#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <libsbp/unpacked/string/binary.h>
#include <libsbp/internal/unpacked/string/binary.h>

void sbp_binary_string_init(sbp_binary_string_t *s, uint8_t max_packed_len)
{
  (void)max_packed_len;
  memset(s->data, 0, sizeof(s->data));
  s->len = 0;
}

bool sbp_binary_string_valid(const sbp_binary_string_t *s, uint8_t max_packed_len)
{
  return s->len <= max_packed_len;
}

uint8_t sbp_binary_string_packed_len(const sbp_binary_string_t *s, uint8_t max_packed_len)
{
  if (!sbp_binary_string_valid(s, max_packed_len))
    return 0;
  return s->len;
}

bool sbp_binary_string_set(sbp_binary_string_t *s, const char *new_str, uint8_t new_str_len, uint8_t max_packed_len)
{
  if (new_str_len > max_packed_len)
  {
    return false;
  }
  memcpy(s->data, new_str, new_str_len);
  s->len = new_str_len;
  return true;
}

const char * sbp_binary_string_get(const sbp_binary_string_t *s, uint8_t *len, uint8_t max_packed_len)
{
  if (!sbp_binary_string_valid(s, max_packed_len))
      {
      return NULL;
      }
  if (len != NULL) {
    *len = s->len;
  }
  return s->data;
}

int sbp_binary_string_strcmp(const sbp_binary_string_t *a, const sbp_binary_string_t *b, uint8_t max_packed_len)
{
  bool avalid = sbp_binary_string_valid(a, max_packed_len);
  bool bvalid = sbp_binary_string_valid(b, max_packed_len);
  if (!avalid)
    return bvalid ? 1 : 0;
  if (!bvalid)
    return avalid ? -1 : 0;
  uint8_t cmp_len = max_packed_len;
  if (a->len < cmp_len)
    cmp_len = a->len;
  if (b->len < cmp_len)
    cmp_len = b->len;
  if (memcmp(a->data, b->data, cmp_len) == 0)
    return 0;
  return (int)b->len - (int)a->len;
}

bool sbp_binary_string_pack(const sbp_binary_string_t *s, uint8_t max_packed_len, sbp_pack_ctx_t *ctx)
{
  if (!sbp_binary_string_valid(s, max_packed_len))
  {
    return false;
  }
  if ((ctx->buf_len - ctx->offset) < s->len)
  {
    return false;
  }
  memcpy(&ctx->buf[ctx->offset], s->data, s->len);
  ctx->offset += s->len;
  return true;
}

bool sbp_binary_string_unpack(sbp_binary_string_t *s, uint8_t max_packed_len, sbp_unpack_ctx_t *ctx)
{
  uint8_t copy_len = (uint8_t)(ctx->buf_len - ctx->offset);
  if (copy_len > max_packed_len)
    copy_len = max_packed_len;
  memcpy(s->data, &ctx->buf[ctx->offset], copy_len);
  s->data[copy_len] = 0;
  s->len = copy_len;
  ctx->offset += copy_len;
  return true;
}
