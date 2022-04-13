#ifndef LIBSBP_UNPACKED_COMMON_H
#define LIBSBP_UNPACKED_COMMON_H

#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>

#ifdef __cplusplus
extern "C" {
#endif

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

SBP_BOOL sbp_u8_encode(sbp_encode_ctx_t *ctx, const u8 *v);

SBP_BOOL sbp_u16_encode(sbp_encode_ctx_t *ctx, const u16 *v);

SBP_BOOL sbp_u32_encode(sbp_encode_ctx_t *ctx, const u32 *v);

SBP_BOOL sbp_u64_encode(sbp_encode_ctx_t *ctx, const u64 *v);

SBP_BOOL sbp_u8_decode(sbp_decode_ctx_t *ctx, u8 *v);

SBP_BOOL sbp_u16_decode(sbp_decode_ctx_t *ctx, u16 *v);

SBP_BOOL sbp_u32_decode(sbp_decode_ctx_t *ctx, u32 *v);

SBP_BOOL sbp_u64_decode(sbp_decode_ctx_t *ctx, u64 *v);

SBP_BOOL sbp_s8_encode(sbp_encode_ctx_t *ctx, const s8 *v);

SBP_BOOL sbp_s8_decode(sbp_decode_ctx_t *ctx, s8 *v);

SBP_BOOL sbp_s16_encode(sbp_encode_ctx_t *ctx, const s16 *v);

SBP_BOOL sbp_s16_decode(sbp_decode_ctx_t *ctx, s16 *v);

SBP_BOOL sbp_s32_encode(sbp_encode_ctx_t *ctx, const s32 *v);

SBP_BOOL sbp_s32_decode(sbp_decode_ctx_t *ctx, s32 *v);

SBP_BOOL sbp_s64_encode(sbp_encode_ctx_t *ctx, const s64 *v);

SBP_BOOL sbp_s64_decode(sbp_decode_ctx_t *ctx, s64 *v);

SBP_BOOL sbp_char_encode(sbp_encode_ctx_t *ctx, const char *v);

SBP_BOOL sbp_char_decode(sbp_decode_ctx_t *ctx, char *v);

SBP_BOOL sbp_float_encode(sbp_encode_ctx_t *ctx, const float *v);

SBP_BOOL sbp_float_decode(sbp_decode_ctx_t *ctx, float *v);

SBP_BOOL sbp_double_encode(sbp_encode_ctx_t *ctx, const double *v);

SBP_BOOL sbp_double_decode(sbp_decode_ctx_t *ctx, double *v);

int sbp_u8_cmp(const uint8_t *a, const uint8_t *b);

int sbp_u16_cmp(const uint16_t *a, const uint16_t *b);

int sbp_u32_cmp(const uint32_t *a, const uint32_t *b);

int sbp_u64_cmp(const uint64_t *a, const uint64_t *b);

int sbp_s8_cmp(const int8_t *a, const int8_t *b);

int sbp_s16_cmp(const int16_t *a, const int16_t *b);

int sbp_s32_cmp(const int32_t *a, const int32_t *b);

int sbp_s64_cmp(const int64_t *a, const int64_t *b);

int sbp_char_cmp(const char *a, const char *b);

int sbp_float_cmp(const float *a, const float *b);

int sbp_double_cmp(const double *a, const double *b);

#ifdef __cplusplus
}
#endif

#endif
