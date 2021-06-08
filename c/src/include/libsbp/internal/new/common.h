#ifndef LIBSBP_UNPACKED_COMMON_H
#define LIBSBP_UNPACKED_COMMON_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <libsbp/common.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SBP_CAN_UNPACK(ctx,type) (((ctx)->buf_len - (ctx)->offset) >= sizeof(type))
#define SBP_CAN_PACK(ctx,type) (((ctx)->buf_len - (ctx)->offset) >= sizeof(type))

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

static inline size_t sbp_packed_size_u8(const uint8_t *v) {
  (void)v;
  return 1;
}

static inline size_t sbp_packed_size_u16(const uint16_t *v) {
  (void)v;
  return 2;
}

static inline size_t sbp_packed_size_u32(const uint32_t *v) {
  (void)v;
  return 4;
}

static inline size_t sbp_packed_size_u64(const uint64_t *v) {
  (void)v;
  return 8;
}

static inline bool encode_u8(sbp_encode_ctx_t *ctx, const u8 *v) {
  if (!SBP_CAN_PACK(ctx, u8)) { return false; }
  ctx->buf[ctx->offset++] = *v;
  return true;
}

static inline bool encode_u16(sbp_encode_ctx_t *ctx, const u16 *v) {
  if (!SBP_CAN_PACK(ctx, u16)) { return false; }
  ctx->buf[ctx->offset++] = (uint8_t)((*v & 0x00ff) >> 0);
  ctx->buf[ctx->offset++] = (uint8_t)((*v & 0xff00) >> 8);
  return true;
}

static inline size_t encode_u32(sbp_encode_ctx_t *ctx, const u32 *v) {
  if (!SBP_CAN_PACK(ctx, u32)) { return false; }
  ctx->buf[ctx->offset++] = (uint8_t)((*v & 0x000000ff) >> 0);
  ctx->buf[ctx->offset++] = (uint8_t)((*v & 0x0000ff00) >> 8);
  ctx->buf[ctx->offset++] = (uint8_t)((*v & 0x00ff0000) >> 16);
  ctx->buf[ctx->offset++] = (uint8_t)((*v & 0xff000000) >> 24);
  return true;
}

static inline size_t encode_u64(sbp_encode_ctx_t *ctx, const u64 *v) {
  if (!SBP_CAN_PACK(ctx, u64)) { return false; }
  ctx->buf[ctx->offset++] = (uint8_t)((*v & 0x00000000000000ff) >> 0);
  ctx->buf[ctx->offset++] = (uint8_t)((*v & 0x000000000000ff00) >> 8);
  ctx->buf[ctx->offset++] = (uint8_t)((*v & 0x0000000000ff0000) >> 16);
  ctx->buf[ctx->offset++] = (uint8_t)((*v & 0x00000000ff000000) >> 24);
  ctx->buf[ctx->offset++] = (uint8_t)((*v & 0x000000ff00000000) >> 32);
  ctx->buf[ctx->offset++] = (uint8_t)((*v & 0x0000ff0000000000) >> 40);
  ctx->buf[ctx->offset++] = (uint8_t)((*v & 0x00ff000000000000) >> 48);
  ctx->buf[ctx->offset++] = (uint8_t)((*v & 0xff00000000000000) >> 56);
  return true;
}

static inline size_t decode_u8(sbp_decode_ctx_t *ctx, u8 *v) {
  if (!SBP_CAN_UNPACK(ctx, u8)) { return false; }
  *v = ctx->buf[ctx->offset++];
  return true;
}

static inline size_t decode_u16(sbp_decode_ctx_t *ctx, u16 *v) {
  if (!SBP_CAN_UNPACK(ctx, u16)) { return false; }
  *v = 0;
  *v = (uint16_t)(*v | ((uint16_t)ctx->buf[ctx->offset++] << 0U));
  *v = (uint16_t)(*v | ((uint16_t)ctx->buf[ctx->offset++] << 8U));
  return true;
}

static inline size_t decode_u32(sbp_decode_ctx_t *ctx, u32 *v) {
  if (!SBP_CAN_UNPACK(ctx, u32)) { return false; }
  *v = 0;
  *v |= (uint32_t)((uint32_t)ctx->buf[ctx->offset++] << 0);
  *v |= (uint32_t)((uint32_t)ctx->buf[ctx->offset++] << 8);
  *v |= (uint32_t)((uint32_t)ctx->buf[ctx->offset++] << 16);
  *v |= (uint32_t)((uint32_t)ctx->buf[ctx->offset++] << 24);
  return true;
}

static inline size_t decode_u64(sbp_decode_ctx_t *ctx, u64 *v) {
  if (!SBP_CAN_UNPACK(ctx, u64)) { return false; }
  *v = 0;
  *v |= (uint64_t)((uint64_t)ctx->buf[ctx->offset++] << 0);
  *v |= (uint64_t)((uint64_t)ctx->buf[ctx->offset++] << 8);
  *v |= (uint64_t)((uint64_t)ctx->buf[ctx->offset++] << 16);
  *v |= (uint64_t)((uint64_t)ctx->buf[ctx->offset++] << 24);
  *v |= (uint64_t)((uint64_t)ctx->buf[ctx->offset++] << 32);
  *v |= (uint64_t)((uint64_t)ctx->buf[ctx->offset++] << 40);
  *v |= (uint64_t)((uint64_t)ctx->buf[ctx->offset++] << 48);
  *v |= (uint64_t)((uint64_t)ctx->buf[ctx->offset++] << 56);
  return true;
}

static inline size_t sbp_packed_size_s8(const s8 *v) {
  (void)v;
  return 1;
}

static inline size_t encode_s8(sbp_encode_ctx_t *ctx, const s8 *v) {
  return encode_u8(ctx, (const u8 *)v);
}

static inline size_t decode_s8(sbp_decode_ctx_t *ctx, s8 *v) {
  return decode_u8(ctx, (u8 *)v);
}

static inline size_t sbp_packed_size_s16(const s16 *v) {
  (void)v;
  return 2;
}

static inline size_t encode_s16(sbp_encode_ctx_t *ctx, const s16 *v) {
  return encode_u16(ctx, (const u16 *)v);
}

static inline size_t decode_s16(sbp_decode_ctx_t *ctx, s16 *v) {
  return decode_u16(ctx, (u16 *)v);
}

static inline size_t sbp_packed_size_s32(const s32 *v) {
  (void)v;
  return 4;
}

static inline size_t encode_s32(sbp_encode_ctx_t *ctx, const s32 *v) {
  return encode_u32(ctx, (const u32 *)v);
}

static inline size_t decode_s32(sbp_decode_ctx_t *ctx, s32 *v) {
  return decode_u32(ctx, (u32 *)v);
}

static inline size_t sbp_packed_size_s64(const s64 *v) {
  (void)v;
  return 8;
}

static inline size_t encode_s64(sbp_encode_ctx_t *ctx, const s64 *v) {
  return encode_u64(ctx, (const u64 *)v);
}

static inline size_t decode_s64(sbp_decode_ctx_t *ctx, s64 *v) {
  return decode_u64(ctx, (u64 *)v);
}

static inline size_t sbp_packed_size_char(const char *v) {
  (void)v;
  return 1;
}

static inline size_t encode_char(sbp_encode_ctx_t *ctx, const char *v) {
  return encode_u8(ctx, (const uint8_t *)v);
}

static inline size_t decode_char(sbp_decode_ctx_t *ctx, char *v) {
  return decode_u8(ctx, (uint8_t *)v);
}

static inline size_t sbp_packed_size_float(const float *v) {
  (void)v;
  return 4;
}

static inline size_t encode_float(sbp_encode_ctx_t *ctx, const float *v) {
  if (!SBP_CAN_PACK(ctx, float)) { return false; }

  union {
    const uint32_t *i;
    const float *f;
  } u;

  u.f = v;

  if (!(encode_u32(ctx, u.i))) { return false; }

  return true;
}

static inline size_t decode_float(sbp_decode_ctx_t *ctx,
                                      float *v) {
  if (!SBP_CAN_UNPACK(ctx, float)) { return false; }

  union {
    uint32_t *i;
    float *f;
  } u;

  u.f = v;

  if (!(decode_u32(ctx, u.i))) { return false; }

  return true;
}

static inline size_t sbp_packed_size_double(const double *v) {
  (void)v;
  return 8;
}

static inline size_t encode_double(sbp_encode_ctx_t *ctx,
                                     const double *v) {
  if (!SBP_CAN_PACK(ctx, double)) { return false; }

  union {
    const uint64_t *i;
    const double *d;
  } u;

  u.d = v;

  if (!(encode_u64(ctx, u.i))) { return false; }

  return true;
}

static inline size_t decode_double(sbp_decode_ctx_t *ctx,
                                       double *v) {
  if (!SBP_CAN_UNPACK(ctx, double)) { return false; }

  union {
    uint64_t *i;
    double *d;
  } u;

  u.d = v;

  if (!(decode_u64(ctx, u.i))) { return false; }

  return true;
}

static inline int sbp_cmp_u8(const uint8_t *a, const uint8_t *b) {
  if (*a < *b) return -1;
  if (*a > *b) return 1;
  return 0;
}

static inline int sbp_cmp_u16(const uint16_t *a, const uint16_t *b) {
  if (*a < *b) return -1;
  if (*a > *b) return 1;
  return 0;
}

static inline int sbp_cmp_u32(const uint32_t *a, const uint32_t *b) {
  if (*a < *b) return -1;
  if (*a > *b) return 1;
  return 0;
}

static inline int sbp_cmp_u64(const uint64_t *a, const uint64_t *b) {
  if (*a < *b) return -1;
  if (*a > *b) return 1;
  return 0;
}

static inline int sbp_cmp_s8(const int8_t *a, const int8_t *b) {
  if (*a < *b) return -1;
  if (*a > *b) return 1;
  return 0;
}

static inline int sbp_cmp_s16(const int16_t *a, const int16_t *b) {
  if (*a < *b) return -1;
  if (*a > *b) return 1;
  return 0;
}

static inline int sbp_cmp_s32(const int32_t *a, const int32_t *b) {
  if (*a < *b) return -1;
  if (*a > *b) return 1;
  return 0;
}

static inline int sbp_cmp_s64(const int64_t *a, const int64_t *b) {
  if (*a < *b) return -1;
  if (*a > *b) return 1;
  return 0;
}

static inline int sbp_cmp_char(const char *a, const char *b) {
  if (*a < *b) return -1;
  if (*a > *b) return 1;
  return 0;
}

static inline int sbp_cmp_float(const float *a, const float *b) {
  if (*a < *b) return -1;
  if (*a > *b) return 1;
  return 0;
}

static inline int sbp_cmp_double(const double *a, const double *b) {
  if (*a < *b) return -1;
  if (*a > *b) return 1;
  return 0;
}

#ifdef __cplusplus
}
#endif

#endif
