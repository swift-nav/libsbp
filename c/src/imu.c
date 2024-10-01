/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/imu.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <libsbp/imu.h>
#include <libsbp/internal/common.h>
#include <libsbp/internal/imu.h>
#include <libsbp/internal/sbp_internal.h>
#include <libsbp/internal/string/double_null_terminated.h>
#include <libsbp/internal/string/multipart.h>
#include <libsbp/internal/string/null_terminated.h>
#include <libsbp/internal/string/unterminated.h>
#include <libsbp/sbp.h>

bool sbp_msg_imu_raw_encode_internal(sbp_encode_ctx_t *ctx,
                                     const sbp_msg_imu_raw_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->tow_f)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->acc_x)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->acc_y)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->acc_z)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->gyr_x)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->gyr_y)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->gyr_z)) {
    return false;
  }
  return true;
}

s8 sbp_msg_imu_raw_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                          const sbp_msg_imu_raw_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_imu_raw_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_imu_raw_decode_internal(sbp_decode_ctx_t *ctx,
                                     sbp_msg_imu_raw_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->tow_f)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->acc_x)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->acc_y)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->acc_z)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->gyr_x)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->gyr_y)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->gyr_z)) {
    return false;
  }
  return true;
}

s8 sbp_msg_imu_raw_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                          sbp_msg_imu_raw_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_imu_raw_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_imu_raw_send(sbp_state_t *s, u16 sender_id,
                        const sbp_msg_imu_raw_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_imu_raw_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_internal_forward_payload(s, SbpMsgImuRaw, sender_id, payload_len,
                                      payload, write);
}

int sbp_msg_imu_raw_cmp(const sbp_msg_imu_raw_t *a,
                        const sbp_msg_imu_raw_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->tow_f, &b->tow_f);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->acc_x, &b->acc_x);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->acc_y, &b->acc_y);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->acc_z, &b->acc_z);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->gyr_x, &b->gyr_x);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->gyr_y, &b->gyr_y);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->gyr_z, &b->gyr_z);
  return ret;
}

bool sbp_msg_imu_aux_encode_internal(sbp_encode_ctx_t *ctx,
                                     const sbp_msg_imu_aux_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->imu_type)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->temp)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->imu_conf)) {
    return false;
  }
  return true;
}

s8 sbp_msg_imu_aux_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                          const sbp_msg_imu_aux_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_imu_aux_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_imu_aux_decode_internal(sbp_decode_ctx_t *ctx,
                                     sbp_msg_imu_aux_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->imu_type)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->temp)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->imu_conf)) {
    return false;
  }
  return true;
}

s8 sbp_msg_imu_aux_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                          sbp_msg_imu_aux_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_imu_aux_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_imu_aux_send(sbp_state_t *s, u16 sender_id,
                        const sbp_msg_imu_aux_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_imu_aux_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_internal_forward_payload(s, SbpMsgImuAux, sender_id, payload_len,
                                      payload, write);
}

int sbp_msg_imu_aux_cmp(const sbp_msg_imu_aux_t *a,
                        const sbp_msg_imu_aux_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->imu_type, &b->imu_type);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->temp, &b->temp);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->imu_conf, &b->imu_conf);
  return ret;
}

bool sbp_msg_imu_comp_encode_internal(sbp_encode_ctx_t *ctx,
                                      const sbp_msg_imu_comp_t *msg) {
  if (!sbp_u64_encode(ctx, &msg->time)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->flags)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->acc_comp_x)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->acc_comp_y)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->acc_comp_z)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->gyr_comp_x)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->gyr_comp_y)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->gyr_comp_z)) {
    return false;
  }
  return true;
}

s8 sbp_msg_imu_comp_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                           const sbp_msg_imu_comp_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_imu_comp_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_imu_comp_decode_internal(sbp_decode_ctx_t *ctx,
                                      sbp_msg_imu_comp_t *msg) {
  if (!sbp_u64_decode(ctx, &msg->time)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->flags)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->acc_comp_x)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->acc_comp_y)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->acc_comp_z)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->gyr_comp_x)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->gyr_comp_y)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->gyr_comp_z)) {
    return false;
  }
  return true;
}

s8 sbp_msg_imu_comp_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                           sbp_msg_imu_comp_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_imu_comp_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_imu_comp_send(sbp_state_t *s, u16 sender_id,
                         const sbp_msg_imu_comp_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_imu_comp_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_internal_forward_payload(s, SbpMsgImuComp, sender_id, payload_len,
                                      payload, write);
}

int sbp_msg_imu_comp_cmp(const sbp_msg_imu_comp_t *a,
                         const sbp_msg_imu_comp_t *b) {
  int ret = 0;

  ret = sbp_u64_cmp(&a->time, &b->time);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->acc_comp_x, &b->acc_comp_x);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->acc_comp_y, &b->acc_comp_y);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->acc_comp_z, &b->acc_comp_z);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->gyr_comp_x, &b->gyr_comp_x);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->gyr_comp_y, &b->gyr_comp_y);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->gyr_comp_z, &b->gyr_comp_z);
  return ret;
}
