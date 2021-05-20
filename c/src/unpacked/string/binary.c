#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <libsbp/unpacked/string/binary.h>
#include <libsbp/internal/unpacked/string/binary.h>

void sbp_binary_string_init(sbp_binary_string_t *s, const sbp_binary_string_params_t *params)
{
  (void)params;
  memset(s, 0, sizeof(*s));
}

bool sbp_binary_string_valid(const sbp_binary_string_t *s, const sbp_binary_string_params_t *params)
{
  return s->packed_len <= params->max_packed_len;
}

int sbp_binary_string_strcmp(const sbp_binary_string_t *a,
                             const sbp_binary_string_t *b,
                             const sbp_binary_string_params_t *params)
{
  bool avalid = sbp_binary_string_valid(a, params);
  bool bvalid = sbp_binary_string_valid(b, params);
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

uint8_t sbp_binary_string_packed_len(const sbp_binary_string_t *s, const sbp_binary_string_params_t *params)
{
  if (!sbp_binary_string_valid(s, params)) return 0;
  return s->packed_len;
}

uint8_t sbp_binary_string_space_remaining(const sbp_binary_string_t *s, const sbp_binary_string_params_t *params)
{
  return (uint8_t)(params->max_packed_len - sbp_binary_string_packed_len(s, params));
}

bool sbp_binary_string_set(sbp_binary_string_t *s,
                           const sbp_binary_string_params_t *params,
                           const char *new_str,
                           uint8_t new_str_len)
{
  if (new_str_len <= params->max_packed_len) return false;
  memcpy(s->data, new_str, new_str_len);
  s->packed_len = new_str_len;
  return true;
}

const char * sbp_binary_string_get(const sbp_binary_string_t *s, const sbp_binary_string_params_t *params, uint8_t *len)
{
  if (!sbp_binary_string_valid(s, params)) return false;
  if (len) *len = s->packed_len;
  return s->data;
}

bool sbp_binary_string_pack(const sbp_binary_string_t *s, const sbp_binary_string_params_t *params, sbp_pack_ctx_t *ctx)
{
  if ((ctx->buf_len - ctx->offset) < sbp_binary_string_packed_len(s, params))
    return false;
  if (!sbp_binary_string_valid(s, params) || s->packed_len == 0)
  {
    return true;
  }
  memcpy(&ctx->buf[ctx->offset], s->data, s->packed_len);
  ctx->offset += s->packed_len;
  return true;
}

bool sbp_binary_string_unpack(sbp_binary_string_t *s, const sbp_binary_string_params_t *params, sbp_unpack_ctx_t *ctx)
{
  uint8_t max_copy = params->max_packed_len;
  uint8_t max_buf_copy = (uint8_t)(ctx->buf_len - ctx->offset);
  if (max_copy < max_buf_copy)
  {
    // More data is available in the input than we can store
    s->packed_len = 0;
    return false;
  }
  if (max_buf_copy < max_copy) max_copy = max_buf_copy;
  memcpy(s->data, ctx->buf + ctx->offset, max_copy);
  ctx->offset += max_copy;
  s->packed_len = max_copy;
  return true;
}
