/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/acquisition.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <libsbp/internal/v4/acquisition.h>
#include <libsbp/internal/v4/common.h>
#include <libsbp/internal/v4/string/double_null_terminated.h>
#include <libsbp/internal/v4/string/multipart.h>
#include <libsbp/internal/v4/string/null_terminated.h>
#include <libsbp/internal/v4/string/unterminated.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/acquisition.h>

bool sbp_msg_acq_result_encode_internal(sbp_encode_ctx_t *ctx,
                                        const sbp_msg_acq_result_t *msg) {
  if (!sbp_float_encode(ctx, &msg->cn0)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cp)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cf)) {
    return false;
  }
  if (!sbp_v4_gnss_signal_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  return true;
}

s8 sbp_msg_acq_result_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                             const sbp_msg_acq_result_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_acq_result_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_acq_result_decode_internal(sbp_decode_ctx_t *ctx,
                                        sbp_msg_acq_result_t *msg) {
  if (!sbp_float_decode(ctx, &msg->cn0)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cp)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cf)) {
    return false;
  }
  if (!sbp_v4_gnss_signal_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  return true;
}

s8 sbp_msg_acq_result_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                             sbp_msg_acq_result_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_acq_result_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_acq_result_send(sbp_state_t *s, u16 sender_id,
                           const sbp_msg_acq_result_t *msg,
                           sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_acq_result_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_ACQ_RESULT, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_acq_result_cmp(const sbp_msg_acq_result_t *a,
                           const sbp_msg_acq_result_t *b) {
  int ret = 0;

  ret = sbp_float_cmp(&a->cn0, &b->cn0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cp, &b->cp);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cf, &b->cf);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_v4_gnss_signal_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_acq_result_dep_c_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_acq_result_dep_c_t *msg) {
  if (!sbp_float_encode(ctx, &msg->cn0)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cp)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cf)) {
    return false;
  }
  if (!sbp_gnss_signal_dep_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  return true;
}

s8 sbp_msg_acq_result_dep_c_encode(uint8_t *buf, uint8_t len,
                                   uint8_t *n_written,
                                   const sbp_msg_acq_result_dep_c_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_acq_result_dep_c_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_acq_result_dep_c_decode_internal(sbp_decode_ctx_t *ctx,
                                              sbp_msg_acq_result_dep_c_t *msg) {
  if (!sbp_float_decode(ctx, &msg->cn0)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cp)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cf)) {
    return false;
  }
  if (!sbp_gnss_signal_dep_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  return true;
}

s8 sbp_msg_acq_result_dep_c_decode(const uint8_t *buf, uint8_t len,
                                   uint8_t *n_read,
                                   sbp_msg_acq_result_dep_c_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_acq_result_dep_c_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_acq_result_dep_c_send(sbp_state_t *s, u16 sender_id,
                                 const sbp_msg_acq_result_dep_c_t *msg,
                                 sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_acq_result_dep_c_encode(payload, sizeof(payload),
                                           &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_ACQ_RESULT_DEP_C, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_acq_result_dep_c_cmp(const sbp_msg_acq_result_dep_c_t *a,
                                 const sbp_msg_acq_result_dep_c_t *b) {
  int ret = 0;

  ret = sbp_float_cmp(&a->cn0, &b->cn0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cp, &b->cp);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cf, &b->cf);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_gnss_signal_dep_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_acq_result_dep_b_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_acq_result_dep_b_t *msg) {
  if (!sbp_float_encode(ctx, &msg->snr)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cp)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cf)) {
    return false;
  }
  if (!sbp_gnss_signal_dep_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  return true;
}

s8 sbp_msg_acq_result_dep_b_encode(uint8_t *buf, uint8_t len,
                                   uint8_t *n_written,
                                   const sbp_msg_acq_result_dep_b_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_acq_result_dep_b_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_acq_result_dep_b_decode_internal(sbp_decode_ctx_t *ctx,
                                              sbp_msg_acq_result_dep_b_t *msg) {
  if (!sbp_float_decode(ctx, &msg->snr)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cp)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cf)) {
    return false;
  }
  if (!sbp_gnss_signal_dep_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  return true;
}

s8 sbp_msg_acq_result_dep_b_decode(const uint8_t *buf, uint8_t len,
                                   uint8_t *n_read,
                                   sbp_msg_acq_result_dep_b_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_acq_result_dep_b_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_acq_result_dep_b_send(sbp_state_t *s, u16 sender_id,
                                 const sbp_msg_acq_result_dep_b_t *msg,
                                 sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_acq_result_dep_b_encode(payload, sizeof(payload),
                                           &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_ACQ_RESULT_DEP_B, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_acq_result_dep_b_cmp(const sbp_msg_acq_result_dep_b_t *a,
                                 const sbp_msg_acq_result_dep_b_t *b) {
  int ret = 0;

  ret = sbp_float_cmp(&a->snr, &b->snr);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cp, &b->cp);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cf, &b->cf);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_gnss_signal_dep_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_acq_result_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_acq_result_dep_a_t *msg) {
  if (!sbp_float_encode(ctx, &msg->snr)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cp)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cf)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->prn)) {
    return false;
  }
  return true;
}

s8 sbp_msg_acq_result_dep_a_encode(uint8_t *buf, uint8_t len,
                                   uint8_t *n_written,
                                   const sbp_msg_acq_result_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_acq_result_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_acq_result_dep_a_decode_internal(sbp_decode_ctx_t *ctx,
                                              sbp_msg_acq_result_dep_a_t *msg) {
  if (!sbp_float_decode(ctx, &msg->snr)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cp)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cf)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->prn)) {
    return false;
  }
  return true;
}

s8 sbp_msg_acq_result_dep_a_decode(const uint8_t *buf, uint8_t len,
                                   uint8_t *n_read,
                                   sbp_msg_acq_result_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_acq_result_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_acq_result_dep_a_send(sbp_state_t *s, u16 sender_id,
                                 const sbp_msg_acq_result_dep_a_t *msg,
                                 sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_acq_result_dep_a_encode(payload, sizeof(payload),
                                           &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_ACQ_RESULT_DEP_A, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_acq_result_dep_a_cmp(const sbp_msg_acq_result_dep_a_t *a,
                                 const sbp_msg_acq_result_dep_a_t *b) {
  int ret = 0;

  ret = sbp_float_cmp(&a->snr, &b->snr);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cp, &b->cp);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cf, &b->cf);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->prn, &b->prn);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_acq_sv_profile_encode_internal(sbp_encode_ctx_t *ctx,
                                        const sbp_acq_sv_profile_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->job_type)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->status)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->cn0)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->int_time)) {
    return false;
  }
  if (!sbp_v4_gnss_signal_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->bin_width)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->timestamp)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->time_spent)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->cf_min)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->cf_max)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->cf)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->cp)) {
    return false;
  }
  return true;
}

s8 sbp_acq_sv_profile_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                             const sbp_acq_sv_profile_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_acq_sv_profile_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_acq_sv_profile_decode_internal(sbp_decode_ctx_t *ctx,
                                        sbp_acq_sv_profile_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->job_type)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->status)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->cn0)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->int_time)) {
    return false;
  }
  if (!sbp_v4_gnss_signal_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->bin_width)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->timestamp)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->time_spent)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->cf_min)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->cf_max)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->cf)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->cp)) {
    return false;
  }
  return true;
}

s8 sbp_acq_sv_profile_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                             sbp_acq_sv_profile_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_acq_sv_profile_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_acq_sv_profile_cmp(const sbp_acq_sv_profile_t *a,
                           const sbp_acq_sv_profile_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->job_type, &b->job_type);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->status, &b->status);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->cn0, &b->cn0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->int_time, &b->int_time);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_v4_gnss_signal_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->bin_width, &b->bin_width);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->timestamp, &b->timestamp);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->time_spent, &b->time_spent);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->cf_min, &b->cf_min);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->cf_max, &b->cf_max);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->cf, &b->cf);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->cp, &b->cp);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_acq_sv_profile_dep_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_acq_sv_profile_dep_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->job_type)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->status)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->cn0)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->int_time)) {
    return false;
  }
  if (!sbp_gnss_signal_dep_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->bin_width)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->timestamp)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->time_spent)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->cf_min)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->cf_max)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->cf)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->cp)) {
    return false;
  }
  return true;
}

s8 sbp_acq_sv_profile_dep_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_acq_sv_profile_dep_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_acq_sv_profile_dep_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_acq_sv_profile_dep_decode_internal(sbp_decode_ctx_t *ctx,
                                            sbp_acq_sv_profile_dep_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->job_type)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->status)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->cn0)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->int_time)) {
    return false;
  }
  if (!sbp_gnss_signal_dep_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->bin_width)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->timestamp)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->time_spent)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->cf_min)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->cf_max)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->cf)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->cp)) {
    return false;
  }
  return true;
}

s8 sbp_acq_sv_profile_dep_decode(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read,
                                 sbp_acq_sv_profile_dep_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_acq_sv_profile_dep_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_acq_sv_profile_dep_cmp(const sbp_acq_sv_profile_dep_t *a,
                               const sbp_acq_sv_profile_dep_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->job_type, &b->job_type);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->status, &b->status);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->cn0, &b->cn0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->int_time, &b->int_time);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_gnss_signal_dep_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->bin_width, &b->bin_width);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->timestamp, &b->timestamp);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->time_spent, &b->time_spent);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->cf_min, &b->cf_min);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->cf_max, &b->cf_max);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->cf, &b->cf);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->cp, &b->cp);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_acq_sv_profile_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_acq_sv_profile_t *msg) {
  for (size_t i = 0; i < msg->n_acq_sv_profile; i++) {
    if (!sbp_acq_sv_profile_encode_internal(ctx, &msg->acq_sv_profile[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_acq_sv_profile_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_msg_acq_sv_profile_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_acq_sv_profile_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_acq_sv_profile_decode_internal(sbp_decode_ctx_t *ctx,
                                            sbp_msg_acq_sv_profile_t *msg) {
  msg->n_acq_sv_profile =
      (uint8_t)((ctx->buf_len - ctx->offset) / SBP_ACQ_SV_PROFILE_ENCODED_LEN);
  for (uint8_t i = 0; i < msg->n_acq_sv_profile; i++) {
    if (!sbp_acq_sv_profile_decode_internal(ctx, &msg->acq_sv_profile[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_acq_sv_profile_decode(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read,
                                 sbp_msg_acq_sv_profile_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_acq_sv_profile_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_acq_sv_profile_send(sbp_state_t *s, u16 sender_id,
                               const sbp_msg_acq_sv_profile_t *msg,
                               sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_acq_sv_profile_encode(payload, sizeof(payload), &payload_len,
                                         msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_ACQ_SV_PROFILE, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_acq_sv_profile_cmp(const sbp_msg_acq_sv_profile_t *a,
                               const sbp_msg_acq_sv_profile_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->n_acq_sv_profile, &b->n_acq_sv_profile);
  for (uint8_t i = 0; ret == 0 && i < a->n_acq_sv_profile; i++) {
    ret = sbp_acq_sv_profile_cmp(&a->acq_sv_profile[i], &b->acq_sv_profile[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_acq_sv_profile_dep_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_acq_sv_profile_dep_t *msg) {
  for (size_t i = 0; i < msg->n_acq_sv_profile; i++) {
    if (!sbp_acq_sv_profile_dep_encode_internal(ctx, &msg->acq_sv_profile[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_acq_sv_profile_dep_encode(uint8_t *buf, uint8_t len,
                                     uint8_t *n_written,
                                     const sbp_msg_acq_sv_profile_dep_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_acq_sv_profile_dep_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_acq_sv_profile_dep_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_acq_sv_profile_dep_t *msg) {
  msg->n_acq_sv_profile = (uint8_t)((ctx->buf_len - ctx->offset) /
                                    SBP_ACQ_SV_PROFILE_DEP_ENCODED_LEN);
  for (uint8_t i = 0; i < msg->n_acq_sv_profile; i++) {
    if (!sbp_acq_sv_profile_dep_decode_internal(ctx, &msg->acq_sv_profile[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_acq_sv_profile_dep_decode(const uint8_t *buf, uint8_t len,
                                     uint8_t *n_read,
                                     sbp_msg_acq_sv_profile_dep_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_acq_sv_profile_dep_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_acq_sv_profile_dep_send(sbp_state_t *s, u16 sender_id,
                                   const sbp_msg_acq_sv_profile_dep_t *msg,
                                   sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_acq_sv_profile_dep_encode(payload, sizeof(payload),
                                             &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_ACQ_SV_PROFILE_DEP, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_acq_sv_profile_dep_cmp(const sbp_msg_acq_sv_profile_dep_t *a,
                                   const sbp_msg_acq_sv_profile_dep_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->n_acq_sv_profile, &b->n_acq_sv_profile);
  for (uint8_t i = 0; ret == 0 && i < a->n_acq_sv_profile; i++) {
    ret = sbp_acq_sv_profile_dep_cmp(&a->acq_sv_profile[i],
                                     &b->acq_sv_profile[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}
