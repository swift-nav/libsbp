#ifndef LIBSBP_UNPACKED_BASE_H
#define LIBSBP_UNPACKED_BASE_H

#include <libsbp/common.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

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

static inline size_t sbp_pack_u8(uint8_t *buf, size_t len, const u8 *v) {
  (void)len;
  buf[0] = *v;
  return 1;
}

static inline size_t sbp_pack_u16(uint8_t *buf, size_t len, const u16 *v) {
  (void)len;
  buf[0] = (uint8_t)((*v & 0x00ff) >> 0);
  buf[1] = (uint8_t)((*v & 0xff00) >> 8);
  return 2;
}

static inline size_t sbp_pack_u32(uint8_t *buf, size_t len, const u32 *v) {
  (void)len;
  buf[0] = (uint8_t)((*v & 0x000000ff) >> 0);
  buf[1] = (uint8_t)((*v & 0x0000ff00) >> 8);
  buf[2] = (uint8_t)((*v & 0x00ff0000) >> 16);
  buf[3] = (uint8_t)((*v & 0xff000000) >> 24);
  return 4;
}

static inline size_t sbp_pack_u64(uint8_t *buf, size_t len, const u64 *v) {
  (void)len;
  buf[0] = (uint8_t)((*v & 0x00000000000000ff) >> 0);
  buf[1] = (uint8_t)((*v & 0x000000000000ff00) >> 8);
  buf[2] = (uint8_t)((*v & 0x0000000000ff0000) >> 16);
  buf[3] = (uint8_t)((*v & 0x00000000ff000000) >> 24);
  buf[4] = (uint8_t)((*v & 0x000000ff00000000) >> 32);
  buf[5] = (uint8_t)((*v & 0x0000ff0000000000) >> 40);
  buf[6] = (uint8_t)((*v & 0x00ff000000000000) >> 48);
  buf[7] = (uint8_t)((*v & 0xff00000000000000) >> 56);
  return 8;
}

static inline size_t sbp_unpack_u8(const uint8_t *buf, size_t len, u8 *v) {
  (void)len;
  uint8_t v_ = buf[0];
  *v = v_;
  return 1;
}

static inline size_t sbp_unpack_u16(const uint8_t *buf, size_t len, u16 *v) {
  (void)len;
  uint16_t v_ = buf[1];
  v_ = (uint16_t)(v_ << 8);
  v_ = (uint16_t)(v_ | buf[0]);
  *v = v_;
  return 2;
}

static inline size_t sbp_unpack_u32(const uint8_t *buf, size_t len, u32 *v) {
  (void)len;
  uint32_t v_ = buf[3];
  v_ <<= 8;
  v_ |= buf[2];
  v_ <<= 8;
  v_ |= buf[1];
  v_ <<= 8;
  v_ |= buf[0];
  *v = v_;
  return 4;
}

static inline size_t sbp_unpack_u64(const uint8_t *buf, size_t len, u64 *v) {
  (void)len;
  uint64_t v_ = buf[7];
  v_ <<= 8;
  v_ |= buf[6];
  v_ <<= 8;
  v_ |= buf[5];
  v_ <<= 8;
  v_ |= buf[4];
  v_ <<= 8;
  v_ |= buf[3];
  v_ <<= 8;
  v_ |= buf[2];
  v_ <<= 8;
  v_ |= buf[1];
  v_ <<= 8;
  v_ |= buf[0];
  *v = v_;
  return 8;
}

static inline size_t sbp_packed_size_s8(const s8 *v) {
  (void)v;
  return 8 / 8;
}

static inline size_t sbp_pack_s8(uint8_t *buf, size_t len, const s8 *v) {
  return sbp_pack_u8(buf, len, (const u8 *)v);
}

static inline size_t sbp_unpack_s8(const uint8_t *buf, size_t len, s8 *v) {
  return sbp_unpack_u8(buf, len, (u8 *)v);
}

static inline size_t sbp_packed_size_s16(const s16 *v) {
  (void)v;
  return 16 / 8;
}

static inline size_t sbp_pack_s16(uint8_t *buf, size_t len, const s16 *v) {
  return sbp_pack_u16(buf, len, (const u16 *)v);
}

static inline size_t sbp_unpack_s16(const uint8_t *buf, size_t len, s16 *v) {
  return sbp_unpack_u16(buf, len, (u16 *)v);
}

static inline size_t sbp_packed_size_s32(const s32 *v) {
  (void)v;
  return 32 / 8;
}

static inline size_t sbp_pack_s32(uint8_t *buf, size_t len, const s32 *v) {
  return sbp_pack_u32(buf, len, (const u32 *)v);
}

static inline size_t sbp_unpack_s32(const uint8_t *buf, size_t len, s32 *v) {
  return sbp_unpack_u32(buf, len, (u32 *)v);
}

static inline size_t sbp_packed_size_s64(const s64 *v) {
  (void)v;
  return 64 / 8;
}

static inline size_t sbp_pack_s64(uint8_t *buf, size_t len, const s64 *v) {
  return sbp_pack_u64(buf, len, (const u64 *)v);
}

static inline size_t sbp_unpack_s64(const uint8_t *buf, size_t len, s64 *v) {
  return sbp_unpack_u64(buf, len, (u64 *)v);
}

static inline size_t sbp_packed_size_char(const char *v) {
  (void)v;
  return 1;
}

static inline size_t sbp_pack_char(uint8_t *buf, size_t len, const char *v) {
  return sbp_pack_u8(buf, len, (const uint8_t *)v);
}

static inline size_t sbp_unpack_char(const uint8_t *buf, size_t len, char *v) {
  return sbp_unpack_u8(buf, len, (uint8_t *)v);
}

static inline size_t sbp_packed_size_float(const float *v) {
  (void)v;
  return 4;
}

static inline size_t sbp_pack_float(uint8_t *buf, size_t len, const float *v) {
  (void)len;
  memcpy(buf, v, 4);
  return 4;
}

static inline size_t sbp_unpack_float(const uint8_t *buf, size_t len,
                                      float *v) {
  (void)len;
  memcpy(v, buf, 4);
  return 4;
}

static inline size_t sbp_packed_size_double(const double *v) {
  (void)v;
  return 8;
}

static inline size_t sbp_pack_double(uint8_t *buf, size_t len,
                                     const double *v) {
  (void)len;
  memcpy(buf, v, 8);
  return 8;
}

static inline size_t sbp_unpack_double(const uint8_t *buf, size_t len,
                                       double *v) {
  (void)len;
  memcpy(v, buf, 8);
  return 8;
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

#endif
