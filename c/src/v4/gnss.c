/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/gnss.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stddef.h>
#include <stdint.h>

#include <libsbp/internal/v4/common.h>
#include <libsbp/internal/v4/gnss.h>
#include <libsbp/internal/v4/string/double_null_terminated.h>
#include <libsbp/internal/v4/string/multipart.h>
#include <libsbp/internal/v4/string/null_terminated.h>
#include <libsbp/internal/v4/string/unterminated.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/gnss.h>

size_t sbp_v4_gnss_signal_encoded_len(const sbp_v4_gnss_signal_t *msg) {
  (void)msg;
  return SBP_V4_GNSS_SIGNAL_ENCODED_LEN;
}

SBP_BOOL sbp_v4_gnss_signal_encode_internal(sbp_encode_ctx_t *ctx,
                                            const sbp_v4_gnss_signal_t *msg) {
  size_t i;
  (void)i;
  if (!sbp_u8_encode(ctx, &msg->sat)) {
    return SBP_FALSE;
  }
  if (!sbp_u8_encode(ctx, &msg->code)) {
    return SBP_FALSE;
  }
  return SBP_TRUE;
}

s8 sbp_v4_gnss_signal_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                             const sbp_v4_gnss_signal_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_v4_gnss_signal_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

SBP_BOOL sbp_v4_gnss_signal_decode_internal(sbp_decode_ctx_t *ctx,
                                            sbp_v4_gnss_signal_t *msg) {
  uint8_t i;
  (void)i;
  if (!sbp_u8_decode(ctx, &msg->sat)) {
    return SBP_FALSE;
  }
  if (!sbp_u8_decode(ctx, &msg->code)) {
    return SBP_FALSE;
  }
  return SBP_TRUE;
}

s8 sbp_v4_gnss_signal_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                             sbp_v4_gnss_signal_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_v4_gnss_signal_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_v4_gnss_signal_cmp(const sbp_v4_gnss_signal_t *a,
                           const sbp_v4_gnss_signal_t *b) {
  int ret = 0;
  uint8_t i;
  (void)i;

  ret = sbp_u8_cmp(&a->sat, &b->sat);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->code, &b->code);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_sv_id_encoded_len(const sbp_sv_id_t *msg) {
  (void)msg;
  return SBP_SV_ID_ENCODED_LEN;
}

SBP_BOOL sbp_sv_id_encode_internal(sbp_encode_ctx_t *ctx,
                                   const sbp_sv_id_t *msg) {
  size_t i;
  (void)i;
  if (!sbp_u8_encode(ctx, &msg->satId)) {
    return SBP_FALSE;
  }
  if (!sbp_u8_encode(ctx, &msg->constellation)) {
    return SBP_FALSE;
  }
  return SBP_TRUE;
}

s8 sbp_sv_id_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                    const sbp_sv_id_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_sv_id_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

SBP_BOOL sbp_sv_id_decode_internal(sbp_decode_ctx_t *ctx, sbp_sv_id_t *msg) {
  uint8_t i;
  (void)i;
  if (!sbp_u8_decode(ctx, &msg->satId)) {
    return SBP_FALSE;
  }
  if (!sbp_u8_decode(ctx, &msg->constellation)) {
    return SBP_FALSE;
  }
  return SBP_TRUE;
}

s8 sbp_sv_id_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                    sbp_sv_id_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_sv_id_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_sv_id_cmp(const sbp_sv_id_t *a, const sbp_sv_id_t *b) {
  int ret = 0;
  uint8_t i;
  (void)i;

  ret = sbp_u8_cmp(&a->satId, &b->satId);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->constellation, &b->constellation);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_gnss_signal_dep_encoded_len(const sbp_gnss_signal_dep_t *msg) {
  (void)msg;
  return SBP_GNSS_SIGNAL_DEP_ENCODED_LEN;
}

SBP_BOOL sbp_gnss_signal_dep_encode_internal(sbp_encode_ctx_t *ctx,
                                             const sbp_gnss_signal_dep_t *msg) {
  size_t i;
  (void)i;
  if (!sbp_u16_encode(ctx, &msg->sat)) {
    return SBP_FALSE;
  }
  if (!sbp_u8_encode(ctx, &msg->code)) {
    return SBP_FALSE;
  }
  if (!sbp_u8_encode(ctx, &msg->reserved)) {
    return SBP_FALSE;
  }
  return SBP_TRUE;
}

s8 sbp_gnss_signal_dep_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                              const sbp_gnss_signal_dep_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_gnss_signal_dep_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

SBP_BOOL sbp_gnss_signal_dep_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_gnss_signal_dep_t *msg) {
  uint8_t i;
  (void)i;
  if (!sbp_u16_decode(ctx, &msg->sat)) {
    return SBP_FALSE;
  }
  if (!sbp_u8_decode(ctx, &msg->code)) {
    return SBP_FALSE;
  }
  if (!sbp_u8_decode(ctx, &msg->reserved)) {
    return SBP_FALSE;
  }
  return SBP_TRUE;
}

s8 sbp_gnss_signal_dep_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                              sbp_gnss_signal_dep_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_gnss_signal_dep_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_gnss_signal_dep_cmp(const sbp_gnss_signal_dep_t *a,
                            const sbp_gnss_signal_dep_t *b) {
  int ret = 0;
  uint8_t i;
  (void)i;

  ret = sbp_u16_cmp(&a->sat, &b->sat);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->code, &b->code);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->reserved, &b->reserved);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_gps_time_dep_encoded_len(const sbp_gps_time_dep_t *msg) {
  (void)msg;
  return SBP_GPS_TIME_DEP_ENCODED_LEN;
}

SBP_BOOL sbp_gps_time_dep_encode_internal(sbp_encode_ctx_t *ctx,
                                          const sbp_gps_time_dep_t *msg) {
  size_t i;
  (void)i;
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return SBP_FALSE;
  }
  if (!sbp_u16_encode(ctx, &msg->wn)) {
    return SBP_FALSE;
  }
  return SBP_TRUE;
}

s8 sbp_gps_time_dep_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                           const sbp_gps_time_dep_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_gps_time_dep_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

SBP_BOOL sbp_gps_time_dep_decode_internal(sbp_decode_ctx_t *ctx,
                                          sbp_gps_time_dep_t *msg) {
  uint8_t i;
  (void)i;
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return SBP_FALSE;
  }
  if (!sbp_u16_decode(ctx, &msg->wn)) {
    return SBP_FALSE;
  }
  return SBP_TRUE;
}

s8 sbp_gps_time_dep_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                           sbp_gps_time_dep_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_gps_time_dep_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_gps_time_dep_cmp(const sbp_gps_time_dep_t *a,
                         const sbp_gps_time_dep_t *b) {
  int ret = 0;
  uint8_t i;
  (void)i;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->wn, &b->wn);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_gps_time_sec_encoded_len(const sbp_gps_time_sec_t *msg) {
  (void)msg;
  return SBP_GPS_TIME_SEC_ENCODED_LEN;
}

SBP_BOOL sbp_gps_time_sec_encode_internal(sbp_encode_ctx_t *ctx,
                                          const sbp_gps_time_sec_t *msg) {
  size_t i;
  (void)i;
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return SBP_FALSE;
  }
  if (!sbp_u16_encode(ctx, &msg->wn)) {
    return SBP_FALSE;
  }
  return SBP_TRUE;
}

s8 sbp_gps_time_sec_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                           const sbp_gps_time_sec_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_gps_time_sec_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

SBP_BOOL sbp_gps_time_sec_decode_internal(sbp_decode_ctx_t *ctx,
                                          sbp_gps_time_sec_t *msg) {
  uint8_t i;
  (void)i;
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return SBP_FALSE;
  }
  if (!sbp_u16_decode(ctx, &msg->wn)) {
    return SBP_FALSE;
  }
  return SBP_TRUE;
}

s8 sbp_gps_time_sec_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                           sbp_gps_time_sec_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_gps_time_sec_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_gps_time_sec_cmp(const sbp_gps_time_sec_t *a,
                         const sbp_gps_time_sec_t *b) {
  int ret = 0;
  uint8_t i;
  (void)i;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->wn, &b->wn);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_v4_gps_time_encoded_len(const sbp_v4_gps_time_t *msg) {
  (void)msg;
  return SBP_V4_GPS_TIME_ENCODED_LEN;
}

SBP_BOOL sbp_v4_gps_time_encode_internal(sbp_encode_ctx_t *ctx,
                                         const sbp_v4_gps_time_t *msg) {
  size_t i;
  (void)i;
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return SBP_FALSE;
  }
  if (!sbp_s32_encode(ctx, &msg->ns_residual)) {
    return SBP_FALSE;
  }
  if (!sbp_u16_encode(ctx, &msg->wn)) {
    return SBP_FALSE;
  }
  return SBP_TRUE;
}

s8 sbp_v4_gps_time_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                          const sbp_v4_gps_time_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_v4_gps_time_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

SBP_BOOL sbp_v4_gps_time_decode_internal(sbp_decode_ctx_t *ctx,
                                         sbp_v4_gps_time_t *msg) {
  uint8_t i;
  (void)i;
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return SBP_FALSE;
  }
  if (!sbp_s32_decode(ctx, &msg->ns_residual)) {
    return SBP_FALSE;
  }
  if (!sbp_u16_decode(ctx, &msg->wn)) {
    return SBP_FALSE;
  }
  return SBP_TRUE;
}

s8 sbp_v4_gps_time_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                          sbp_v4_gps_time_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_v4_gps_time_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_v4_gps_time_cmp(const sbp_v4_gps_time_t *a,
                        const sbp_v4_gps_time_t *b) {
  int ret = 0;
  uint8_t i;
  (void)i;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->ns_residual, &b->ns_residual);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->wn, &b->wn);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_carrier_phase_encoded_len(const sbp_carrier_phase_t *msg) {
  (void)msg;
  return SBP_CARRIER_PHASE_ENCODED_LEN;
}

SBP_BOOL sbp_carrier_phase_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_carrier_phase_t *msg) {
  size_t i;
  (void)i;
  if (!sbp_s32_encode(ctx, &msg->i)) {
    return SBP_FALSE;
  }
  if (!sbp_u8_encode(ctx, &msg->f)) {
    return SBP_FALSE;
  }
  return SBP_TRUE;
}

s8 sbp_carrier_phase_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                            const sbp_carrier_phase_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_carrier_phase_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

SBP_BOOL sbp_carrier_phase_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_carrier_phase_t *msg) {
  uint8_t i;
  (void)i;
  if (!sbp_s32_decode(ctx, &msg->i)) {
    return SBP_FALSE;
  }
  if (!sbp_u8_decode(ctx, &msg->f)) {
    return SBP_FALSE;
  }
  return SBP_TRUE;
}

s8 sbp_carrier_phase_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                            sbp_carrier_phase_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_carrier_phase_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_carrier_phase_cmp(const sbp_carrier_phase_t *a,
                          const sbp_carrier_phase_t *b) {
  int ret = 0;
  uint8_t i;
  (void)i;

  ret = sbp_s32_cmp(&a->i, &b->i);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->f, &b->f);
  if (ret != 0) {
    return ret;
  }
  return ret;
}
