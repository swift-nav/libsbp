#ifndef LIBSBP_UNPACKED_COMMON_H
#define LIBSBP_UNPACKED_COMMON_H

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SBP_CAN_UNPACK(ctx, type)                                              \
  (((ctx)->buf_len - (ctx)->offset) >= sizeof(type))
#define SBP_CAN_PACK(ctx, type)                                                \
  (((ctx)->buf_len - (ctx)->offset) >= sizeof(type))

typedef struct {
  const uint8_t *buf;
  size_t buf_len;
  size_t offset;
} sbp_decode_ctx_t;

typedef struct {
  uint8_t *buf;
  size_t buf_len;
  size_t offset;
} sbp_encode_ctx_t;

static inline bool sbp_u8_encode(sbp_encode_ctx_t *ctx, const u8 *v) {
  if (!SBP_CAN_PACK(ctx, u8)) {
    return false;
  }
  ctx->buf[ctx->offset++] = *v;
  return true;
}

static inline bool sbp_u16_encode(sbp_encode_ctx_t *ctx, const u16 *v) {
  if (!SBP_CAN_PACK(ctx, u16)) {
    return false;
  }
  ctx->buf[ctx->offset++] = (uint8_t)((*v & 0x00ff) >> (8U * 0U));
  ctx->buf[ctx->offset++] = (uint8_t)((*v & 0xff00) >> (8U * 1U));
  return true;
}

static inline size_t sbp_u32_encode(sbp_encode_ctx_t *ctx, const u32 *v) {
  if (!SBP_CAN_PACK(ctx, u32)) {
    return false;
  }
  ctx->buf[ctx->offset++] = (uint8_t)((*v & 0x000000ff) >> (8U * 0U));
  ctx->buf[ctx->offset++] = (uint8_t)((*v & 0x0000ff00) >> (8U * 1U));
  ctx->buf[ctx->offset++] = (uint8_t)((*v & 0x00ff0000) >> (8U * 2U));
  ctx->buf[ctx->offset++] = (uint8_t)((*v & 0xff000000) >> (8U * 3U));
  return true;
}

static inline size_t sbp_u64_encode(sbp_encode_ctx_t *ctx, const u64 *v) {
  if (!SBP_CAN_PACK(ctx, u64)) {
    return false;
  }
  ctx->buf[ctx->offset++] = (uint8_t)((*v & 0x00000000000000ff) >> (8U * 0U));
  ctx->buf[ctx->offset++] = (uint8_t)((*v & 0x000000000000ff00) >> (8U * 1U));
  ctx->buf[ctx->offset++] = (uint8_t)((*v & 0x0000000000ff0000) >> (8U * 2U));
  ctx->buf[ctx->offset++] = (uint8_t)((*v & 0x00000000ff000000) >> (8U * 3U));
  ctx->buf[ctx->offset++] = (uint8_t)((*v & 0x000000ff00000000) >> (8U * 4U));
  ctx->buf[ctx->offset++] = (uint8_t)((*v & 0x0000ff0000000000) >> (8U * 5U));
  ctx->buf[ctx->offset++] = (uint8_t)((*v & 0x00ff000000000000) >> (8U * 6U));
  ctx->buf[ctx->offset++] = (uint8_t)((*v & 0xff00000000000000) >> (8U * 7U));
  return true;
}

static inline size_t sbp_u8_decode(sbp_decode_ctx_t *ctx, u8 *v) {
  if (!SBP_CAN_UNPACK(ctx, u8)) {
    return false;
  }
  *v = ctx->buf[ctx->offset++];
  return true;
}

static inline size_t sbp_u16_decode(sbp_decode_ctx_t *ctx, u16 *v) {
  if (!SBP_CAN_UNPACK(ctx, u16)) {
    return false;
  }
  *v = 0;
  *v = (uint16_t)(*v | ((uint16_t)ctx->buf[ctx->offset++] << (8U * 0U)));
  *v = (uint16_t)(*v | ((uint16_t)ctx->buf[ctx->offset++] << (8U * 1U)));
  return true;
}

static inline size_t sbp_u32_decode(sbp_decode_ctx_t *ctx, u32 *v) {
  if (!SBP_CAN_UNPACK(ctx, u32)) {
    return false;
  }
  *v = 0;
  *v |= ((uint32_t)ctx->buf[ctx->offset++] << (8U * 0U));
  *v |= ((uint32_t)ctx->buf[ctx->offset++] << (8U * 1U));
  *v |= ((uint32_t)ctx->buf[ctx->offset++] << (8U * 2U));
  *v |= ((uint32_t)ctx->buf[ctx->offset++] << (8U * 3U));
  return true;
}

static inline size_t sbp_u64_decode(sbp_decode_ctx_t *ctx, u64 *v) {
  if (!SBP_CAN_UNPACK(ctx, u64)) {
    return false;
  }
  *v = 0;
  *v |= ((uint64_t)ctx->buf[ctx->offset++] << (8U * 0U));
  *v |= ((uint64_t)ctx->buf[ctx->offset++] << (8U * 1U));
  *v |= ((uint64_t)ctx->buf[ctx->offset++] << (8U * 2U));
  *v |= ((uint64_t)ctx->buf[ctx->offset++] << (8U * 3U));
  *v |= ((uint64_t)ctx->buf[ctx->offset++] << (8U * 4U));
  *v |= ((uint64_t)ctx->buf[ctx->offset++] << (8U * 5U));
  *v |= ((uint64_t)ctx->buf[ctx->offset++] << (8U * 6U));
  *v |= ((uint64_t)ctx->buf[ctx->offset++] << (8U * 7U));
  return true;
}

static inline size_t sbp_s8_encode(sbp_encode_ctx_t *ctx, const s8 *v) {
  uint8_t tmp;
  memcpy(&tmp, v, sizeof(tmp));
  return sbp_u8_encode(ctx, &tmp);
}

static inline size_t sbp_s8_decode(sbp_decode_ctx_t *ctx, s8 *v) {
  uint8_t tmp = 0;
  size_t result = sbp_u8_decode(ctx, &tmp);
  memcpy(v, &tmp, sizeof(tmp));
  return result;
}

static inline size_t sbp_s16_encode(sbp_encode_ctx_t *ctx, const s16 *v) {
  uint16_t tmp;
  memcpy(&tmp, v, sizeof(tmp));
  return sbp_u16_encode(ctx, &tmp);
}

static inline size_t sbp_s16_decode(sbp_decode_ctx_t *ctx, s16 *v) {
  uint16_t tmp = 0;
  size_t result = sbp_u16_decode(ctx, &tmp);
  memcpy(v, &tmp, sizeof(tmp));
  return result;
}

static inline size_t sbp_s32_encode(sbp_encode_ctx_t *ctx, const s32 *v) {
  uint32_t tmp;
  memcpy(&tmp, v, sizeof(tmp));
  return sbp_u32_encode(ctx, &tmp);
}

static inline size_t sbp_s32_decode(sbp_decode_ctx_t *ctx, s32 *v) {
  uint32_t tmp = 0;
  size_t result = sbp_u32_decode(ctx, &tmp);
  memcpy(v, &tmp, sizeof(tmp));
  return result;
}

static inline size_t sbp_s64_encode(sbp_encode_ctx_t *ctx, const s64 *v) {
  uint64_t tmp;
  memcpy(&tmp, v, sizeof(tmp));
  return sbp_u64_encode(ctx, &tmp);
}

static inline size_t sbp_s64_decode(sbp_decode_ctx_t *ctx, s64 *v) {
  uint64_t tmp = 0;
  size_t result = sbp_u64_decode(ctx, &tmp);
  memcpy(v, &tmp, sizeof(tmp));
  return result;
}

static inline size_t sbp_char_encode(sbp_encode_ctx_t *ctx, const char *v) {
  uint8_t tmp;
  memcpy(&tmp, v, sizeof(tmp));
  return sbp_u8_encode(ctx, &tmp);
}

static inline size_t sbp_char_decode(sbp_decode_ctx_t *ctx, char *v) {
  uint8_t tmp = 0;
  size_t result = sbp_u8_decode(ctx, &tmp);
  memcpy(v, &tmp, sizeof(tmp));
  return result;
}

static inline size_t sbp_float_encode(sbp_encode_ctx_t *ctx, const float *v) {
  uint32_t tmp;
  memcpy(&tmp, v, sizeof(tmp));
  return sbp_u32_encode(ctx, &tmp);
}

static inline size_t sbp_float_decode(sbp_decode_ctx_t *ctx, float *v) {
  uint32_t tmp = 0;
  size_t result = sbp_u32_decode(ctx, &tmp);
  memcpy(v, &tmp, sizeof(tmp));
  return result;
}

static inline size_t sbp_double_encode(sbp_encode_ctx_t *ctx, const double *v) {
  uint64_t tmp;
  memcpy(&tmp, v, sizeof(tmp));
  return sbp_u64_encode(ctx, &tmp);
}

static inline size_t sbp_double_decode(sbp_decode_ctx_t *ctx, double *v) {
  uint64_t tmp = 0;
  size_t result = sbp_u64_decode(ctx, &tmp);
  memcpy(v, &tmp, sizeof(tmp));
  return result;
}

static inline int sbp_u8_cmp(const uint8_t *a, const uint8_t *b) {
  if (*a < *b) {
    return -1;
  }
  if (*a > *b) {
    return 1;
  }
  return 0;
}

static inline int sbp_u16_cmp(const uint16_t *a, const uint16_t *b) {
  assert(a && b);
  if (*a < *b) {
    return -1;
  }
  if (*a > *b) {
    return 1;
  }
  return 0;
}

static inline int sbp_u32_cmp(const uint32_t *a, const uint32_t *b) {
  assert(a && b);
  if (*a < *b) {
    return -1;
  }
  if (*a > *b) {
    return 1;
  }
  return 0;
}

static inline int sbp_u64_cmp(const uint64_t *a, const uint64_t *b) {
  assert(a && b);
  if (*a < *b) {
    return -1;
  }
  if (*a > *b) {
    return 1;
  }
  return 0;
}

static inline int sbp_s8_cmp(const int8_t *a, const int8_t *b) {
  assert(a && b);
  if (*a < *b) {
    return -1;
  }
  if (*a > *b) {
    return 1;
  }
  return 0;
}

static inline int sbp_s16_cmp(const int16_t *a, const int16_t *b) {
  assert(a && b);
  if (*a < *b) {
    return -1;
  }
  if (*a > *b) {
    return 1;
  }
  return 0;
}

static inline int sbp_s32_cmp(const int32_t *a, const int32_t *b) {
  assert(a && b);
  if (*a < *b) {
    return -1;
  }
  if (*a > *b) {
    return 1;
  }
  return 0;
}

static inline int sbp_s64_cmp(const int64_t *a, const int64_t *b) {
  assert(a && b);
  if (*a < *b) {
    return -1;
  }
  if (*a > *b) {
    return 1;
  }
  return 0;
}

static inline int sbp_char_cmp(const char *a, const char *b) {
  assert(a && b);
  if (*a < *b) {
    return -1;
  }
  if (*a > *b) {
    return 1;
  }
  return 0;
}

static inline int sbp_float_cmp(const float *a, const float *b) {
  assert(a && b);
  if (*a < *b) {
    return -1;
  }
  if (*a > *b) {
    return 1;
  }
  return 0;
}

static inline int sbp_double_cmp(const double *a, const double *b) {
  assert(a && b);
  if (*a < *b) {
    return -1;
  }
  if (*a > *b) {
    return 1;
  }
  return 0;
}

#ifdef __cplusplus
}
#endif

#endif
