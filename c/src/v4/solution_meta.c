/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/solution_meta.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <libsbp/internal/v4/common.h>
#include <libsbp/internal/v4/solution_meta.h>
#include <libsbp/internal/v4/string/double_null_terminated.h>
#include <libsbp/internal/v4/string/multipart.h>
#include <libsbp/internal/v4/string/null_terminated.h>
#include <libsbp/internal/v4/string/unterminated.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/solution_meta.h>

bool sbp_solution_input_type_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_solution_input_type_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->sensor_type)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_solution_input_type_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_solution_input_type_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_solution_input_type_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_solution_input_type_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_solution_input_type_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->sensor_type)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_solution_input_type_decode(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read,
                                  sbp_solution_input_type_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_solution_input_type_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_solution_input_type_cmp(const sbp_solution_input_type_t *a,
                                const sbp_solution_input_type_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->sensor_type, &b->sensor_type);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_soln_meta_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_soln_meta_dep_a_t *msg) {
  if (!sbp_u16_encode(ctx, &msg->pdop)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->hdop)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->vdop)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->age_corrections)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->alignment_status)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->last_used_gnss_pos_tow)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->last_used_gnss_vel_tow)) {
    return false;
  }
  for (size_t i = 0; i < msg->n_sol_in; i++) {
    if (!sbp_solution_input_type_encode_internal(ctx, &msg->sol_in[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_soln_meta_dep_a_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_soln_meta_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_soln_meta_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_soln_meta_dep_a_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_msg_soln_meta_dep_a_t *msg) {
  if (!sbp_u16_decode(ctx, &msg->pdop)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->hdop)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->vdop)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->age_corrections)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->alignment_status)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->last_used_gnss_pos_tow)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->last_used_gnss_vel_tow)) {
    return false;
  }
  msg->n_sol_in = (uint8_t)((ctx->buf_len - ctx->offset) /
                            SBP_SOLUTION_INPUT_TYPE_ENCODED_LEN);
  for (uint8_t i = 0; i < msg->n_sol_in; i++) {
    if (!sbp_solution_input_type_decode_internal(ctx, &msg->sol_in[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_soln_meta_dep_a_decode(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read,
                                  sbp_msg_soln_meta_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_soln_meta_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_soln_meta_dep_a_send(sbp_state_t *s, u16 sender_id,
                                const sbp_msg_soln_meta_dep_a_t *msg,
                                sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_soln_meta_dep_a_encode(payload, sizeof(payload),
                                          &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SOLN_META_DEP_A, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_soln_meta_dep_a_cmp(const sbp_msg_soln_meta_dep_a_t *a,
                                const sbp_msg_soln_meta_dep_a_t *b) {
  int ret = 0;

  ret = sbp_u16_cmp(&a->pdop, &b->pdop);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->hdop, &b->hdop);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->vdop, &b->vdop);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_sats, &b->n_sats);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->age_corrections, &b->age_corrections);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->alignment_status, &b->alignment_status);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->last_used_gnss_pos_tow, &b->last_used_gnss_pos_tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->last_used_gnss_vel_tow, &b->last_used_gnss_vel_tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_sol_in, &b->n_sol_in);
  for (uint8_t i = 0; ret == 0 && i < a->n_sol_in; i++) {
    ret = sbp_solution_input_type_cmp(&a->sol_in[i], &b->sol_in[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_soln_meta_encode_internal(sbp_encode_ctx_t *ctx,
                                       const sbp_msg_soln_meta_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->pdop)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->hdop)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->vdop)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->age_corrections)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->age_gnss)) {
    return false;
  }
  for (size_t i = 0; i < msg->n_sol_in; i++) {
    if (!sbp_solution_input_type_encode_internal(ctx, &msg->sol_in[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_soln_meta_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                            const sbp_msg_soln_meta_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_soln_meta_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_soln_meta_decode_internal(sbp_decode_ctx_t *ctx,
                                       sbp_msg_soln_meta_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->pdop)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->hdop)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->vdop)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->age_corrections)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->age_gnss)) {
    return false;
  }
  msg->n_sol_in = (uint8_t)((ctx->buf_len - ctx->offset) /
                            SBP_SOLUTION_INPUT_TYPE_ENCODED_LEN);
  for (uint8_t i = 0; i < msg->n_sol_in; i++) {
    if (!sbp_solution_input_type_decode_internal(ctx, &msg->sol_in[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_soln_meta_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                            sbp_msg_soln_meta_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_soln_meta_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_soln_meta_send(sbp_state_t *s, u16 sender_id,
                          const sbp_msg_soln_meta_t *msg,
                          sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_soln_meta_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SOLN_META, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_soln_meta_cmp(const sbp_msg_soln_meta_t *a,
                          const sbp_msg_soln_meta_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->pdop, &b->pdop);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->hdop, &b->hdop);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->vdop, &b->vdop);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->age_corrections, &b->age_corrections);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->age_gnss, &b->age_gnss);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_sol_in, &b->n_sol_in);
  for (uint8_t i = 0; ret == 0 && i < a->n_sol_in; i++) {
    ret = sbp_solution_input_type_cmp(&a->sol_in[i], &b->sol_in[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_gnss_input_type_encode_internal(sbp_encode_ctx_t *ctx,
                                         const sbp_gnss_input_type_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_gnss_input_type_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                              const sbp_gnss_input_type_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_gnss_input_type_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_gnss_input_type_decode_internal(sbp_decode_ctx_t *ctx,
                                         sbp_gnss_input_type_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_gnss_input_type_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                              sbp_gnss_input_type_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_gnss_input_type_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_gnss_input_type_cmp(const sbp_gnss_input_type_t *a,
                            const sbp_gnss_input_type_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_imu_input_type_encode_internal(sbp_encode_ctx_t *ctx,
                                        const sbp_imu_input_type_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_imu_input_type_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                             const sbp_imu_input_type_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_imu_input_type_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_imu_input_type_decode_internal(sbp_decode_ctx_t *ctx,
                                        sbp_imu_input_type_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_imu_input_type_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                             sbp_imu_input_type_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_imu_input_type_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_imu_input_type_cmp(const sbp_imu_input_type_t *a,
                           const sbp_imu_input_type_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_odo_input_type_encode_internal(sbp_encode_ctx_t *ctx,
                                        const sbp_odo_input_type_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_odo_input_type_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                             const sbp_odo_input_type_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_odo_input_type_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_odo_input_type_decode_internal(sbp_decode_ctx_t *ctx,
                                        sbp_odo_input_type_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_odo_input_type_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                             sbp_odo_input_type_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_odo_input_type_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_odo_input_type_cmp(const sbp_odo_input_type_t *a,
                           const sbp_odo_input_type_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}
