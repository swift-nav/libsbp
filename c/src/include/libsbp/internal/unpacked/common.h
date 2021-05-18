#ifndef LIBSBP_UNPACKED_COMMON_H
#define LIBSBP_UNPACKED_COMMON_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SBP_CAN_UNPACK(ctx,type) (((ctx)->buf_len - (ctx)->offset) >= sizeof(type))
#define SBP_CAN_PACK(ctx,type) (((ctx)->buf_len - (ctx)->offset) >= sizeof(type))

typedef struct {
  const uint8_t *buf;
  size_t buf_len;
  size_t offset;
} sbp_unpack_ctx_t;

typedef struct {
  uint8_t *buf;
  size_t buf_len;
  size_t offset;
} sbp_pack_ctx_t;

#ifdef __cplusplus
}
#endif

#endif
