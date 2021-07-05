/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/observation.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <libsbp/internal/v4/common.h>
#include <libsbp/internal/v4/observation.h>
#include <libsbp/internal/v4/string/double_null_terminated.h>
#include <libsbp/internal/v4/string/multipart.h>
#include <libsbp/internal/v4/string/null_terminated.h>
#include <libsbp/internal/v4/string/unterminated.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/observation.h>

bool sbp_observation_header_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_observation_header_t *msg) {
  if (!sbp_v4_gps_time_encode_internal(ctx, &msg->t)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_obs)) {
    return false;
  }
  return true;
}

s8 sbp_observation_header_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_observation_header_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_observation_header_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_observation_header_decode_internal(sbp_decode_ctx_t *ctx,
                                            sbp_observation_header_t *msg) {
  if (!sbp_v4_gps_time_decode_internal(ctx, &msg->t)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_obs)) {
    return false;
  }
  return true;
}

s8 sbp_observation_header_decode(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read,
                                 sbp_observation_header_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_observation_header_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_observation_header_cmp(const sbp_observation_header_t *a,
                               const sbp_observation_header_t *b) {
  int ret = 0;

  ret = sbp_v4_gps_time_cmp(&a->t, &b->t);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_obs, &b->n_obs);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_doppler_encode_internal(sbp_encode_ctx_t *ctx,
                                 const sbp_doppler_t *msg) {
  if (!sbp_s16_encode(ctx, &msg->i)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->f)) {
    return false;
  }
  return true;
}

s8 sbp_doppler_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                      const sbp_doppler_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_doppler_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_doppler_decode_internal(sbp_decode_ctx_t *ctx, sbp_doppler_t *msg) {
  if (!sbp_s16_decode(ctx, &msg->i)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->f)) {
    return false;
  }
  return true;
}

s8 sbp_doppler_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                      sbp_doppler_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_doppler_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_doppler_cmp(const sbp_doppler_t *a, const sbp_doppler_t *b) {
  int ret = 0;

  ret = sbp_s16_cmp(&a->i, &b->i);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->f, &b->f);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_packed_obs_content_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_packed_obs_content_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->P)) {
    return false;
  }
  if (!sbp_carrier_phase_encode_internal(ctx, &msg->L)) {
    return false;
  }
  if (!sbp_doppler_encode_internal(ctx, &msg->D)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->cn0)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->lock)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  if (!sbp_v4_gnss_signal_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  return true;
}

s8 sbp_packed_obs_content_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_packed_obs_content_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_packed_obs_content_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_packed_obs_content_decode_internal(sbp_decode_ctx_t *ctx,
                                            sbp_packed_obs_content_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->P)) {
    return false;
  }
  if (!sbp_carrier_phase_decode_internal(ctx, &msg->L)) {
    return false;
  }
  if (!sbp_doppler_decode_internal(ctx, &msg->D)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->cn0)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->lock)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  if (!sbp_v4_gnss_signal_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  return true;
}

s8 sbp_packed_obs_content_decode(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read,
                                 sbp_packed_obs_content_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_packed_obs_content_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_packed_obs_content_cmp(const sbp_packed_obs_content_t *a,
                               const sbp_packed_obs_content_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->P, &b->P);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_carrier_phase_cmp(&a->L, &b->L);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_doppler_cmp(&a->D, &b->D);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->cn0, &b->cn0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->lock, &b->lock);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_v4_gnss_signal_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_packed_osr_content_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_packed_osr_content_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->P)) {
    return false;
  }
  if (!sbp_carrier_phase_encode_internal(ctx, &msg->L)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->lock)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  if (!sbp_v4_gnss_signal_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->iono_std)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->tropo_std)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->range_std)) {
    return false;
  }
  return true;
}

s8 sbp_packed_osr_content_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_packed_osr_content_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_packed_osr_content_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_packed_osr_content_decode_internal(sbp_decode_ctx_t *ctx,
                                            sbp_packed_osr_content_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->P)) {
    return false;
  }
  if (!sbp_carrier_phase_decode_internal(ctx, &msg->L)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->lock)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  if (!sbp_v4_gnss_signal_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->iono_std)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->tropo_std)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->range_std)) {
    return false;
  }
  return true;
}

s8 sbp_packed_osr_content_decode(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read,
                                 sbp_packed_osr_content_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_packed_osr_content_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_packed_osr_content_cmp(const sbp_packed_osr_content_t *a,
                               const sbp_packed_osr_content_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->P, &b->P);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_carrier_phase_cmp(&a->L, &b->L);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->lock, &b->lock);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_v4_gnss_signal_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->iono_std, &b->iono_std);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->tropo_std, &b->tropo_std);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->range_std, &b->range_std);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_obs_encode_internal(sbp_encode_ctx_t *ctx,
                                 const sbp_msg_obs_t *msg) {
  if (!sbp_observation_header_encode_internal(ctx, &msg->header)) {
    return false;
  }
  for (size_t i = 0; i < msg->n_obs; i++) {
    if (!sbp_packed_obs_content_encode_internal(ctx, &msg->obs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_obs_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                      const sbp_msg_obs_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_obs_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_obs_decode_internal(sbp_decode_ctx_t *ctx, sbp_msg_obs_t *msg) {
  if (!sbp_observation_header_decode_internal(ctx, &msg->header)) {
    return false;
  }
  msg->n_obs = (uint8_t)((ctx->buf_len - ctx->offset) /
                         SBP_PACKED_OBS_CONTENT_ENCODED_LEN);
  for (uint8_t i = 0; i < msg->n_obs; i++) {
    if (!sbp_packed_obs_content_decode_internal(ctx, &msg->obs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_obs_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                      sbp_msg_obs_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_obs_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_obs_send(sbp_state_t *s, u16 sender_id, const sbp_msg_obs_t *msg,
                    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_obs_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_OBS, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_obs_cmp(const sbp_msg_obs_t *a, const sbp_msg_obs_t *b) {
  int ret = 0;

  ret = sbp_observation_header_cmp(&a->header, &b->header);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_obs, &b->n_obs);
  for (uint8_t i = 0; ret == 0 && i < a->n_obs; i++) {
    ret = sbp_packed_obs_content_cmp(&a->obs[i], &b->obs[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_base_pos_llh_encode_internal(sbp_encode_ctx_t *ctx,
                                          const sbp_msg_base_pos_llh_t *msg) {
  if (!sbp_double_encode(ctx, &msg->lat)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->lon)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->height)) {
    return false;
  }
  return true;
}

s8 sbp_msg_base_pos_llh_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                               const sbp_msg_base_pos_llh_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_base_pos_llh_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_base_pos_llh_decode_internal(sbp_decode_ctx_t *ctx,
                                          sbp_msg_base_pos_llh_t *msg) {
  if (!sbp_double_decode(ctx, &msg->lat)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->lon)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->height)) {
    return false;
  }
  return true;
}

s8 sbp_msg_base_pos_llh_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                               sbp_msg_base_pos_llh_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_base_pos_llh_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_base_pos_llh_send(sbp_state_t *s, u16 sender_id,
                             const sbp_msg_base_pos_llh_t *msg,
                             sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_base_pos_llh_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_BASE_POS_LLH, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_base_pos_llh_cmp(const sbp_msg_base_pos_llh_t *a,
                             const sbp_msg_base_pos_llh_t *b) {
  int ret = 0;

  ret = sbp_double_cmp(&a->lat, &b->lat);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->lon, &b->lon);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->height, &b->height);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_base_pos_ecef_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_msg_base_pos_ecef_t *msg) {
  if (!sbp_double_encode(ctx, &msg->x)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->y)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->z)) {
    return false;
  }
  return true;
}

s8 sbp_msg_base_pos_ecef_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                const sbp_msg_base_pos_ecef_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_base_pos_ecef_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_base_pos_ecef_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_msg_base_pos_ecef_t *msg) {
  if (!sbp_double_decode(ctx, &msg->x)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->y)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->z)) {
    return false;
  }
  return true;
}

s8 sbp_msg_base_pos_ecef_decode(const uint8_t *buf, uint8_t len,
                                uint8_t *n_read, sbp_msg_base_pos_ecef_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_base_pos_ecef_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_base_pos_ecef_send(sbp_state_t *s, u16 sender_id,
                              const sbp_msg_base_pos_ecef_t *msg,
                              sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_base_pos_ecef_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_BASE_POS_ECEF, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_base_pos_ecef_cmp(const sbp_msg_base_pos_ecef_t *a,
                              const sbp_msg_base_pos_ecef_t *b) {
  int ret = 0;

  ret = sbp_double_cmp(&a->x, &b->x);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->y, &b->y);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->z, &b->z);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_ephemeris_common_content_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_ephemeris_common_content_t *msg) {
  if (!sbp_v4_gnss_signal_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_gps_time_sec_encode_internal(ctx, &msg->toe)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->ura)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->fit_interval)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->valid)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->health_bits)) {
    return false;
  }
  return true;
}

s8 sbp_ephemeris_common_content_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_ephemeris_common_content_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_ephemeris_common_content_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_ephemeris_common_content_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_ephemeris_common_content_t *msg) {
  if (!sbp_v4_gnss_signal_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_gps_time_sec_decode_internal(ctx, &msg->toe)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->ura)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->fit_interval)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->valid)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->health_bits)) {
    return false;
  }
  return true;
}

s8 sbp_ephemeris_common_content_decode(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_ephemeris_common_content_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_ephemeris_common_content_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_ephemeris_common_content_cmp(const sbp_ephemeris_common_content_t *a,
                                     const sbp_ephemeris_common_content_t *b) {
  int ret = 0;

  ret = sbp_v4_gnss_signal_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_gps_time_sec_cmp(&a->toe, &b->toe);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->ura, &b->ura);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->fit_interval, &b->fit_interval);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->valid, &b->valid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->health_bits, &b->health_bits);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_ephemeris_common_content_dep_b_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_ephemeris_common_content_dep_b_t *msg) {
  if (!sbp_v4_gnss_signal_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_gps_time_sec_encode_internal(ctx, &msg->toe)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->ura)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->fit_interval)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->valid)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->health_bits)) {
    return false;
  }
  return true;
}

s8 sbp_ephemeris_common_content_dep_b_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_ephemeris_common_content_dep_b_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_ephemeris_common_content_dep_b_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_ephemeris_common_content_dep_b_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_ephemeris_common_content_dep_b_t *msg) {
  if (!sbp_v4_gnss_signal_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_gps_time_sec_decode_internal(ctx, &msg->toe)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->ura)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->fit_interval)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->valid)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->health_bits)) {
    return false;
  }
  return true;
}

s8 sbp_ephemeris_common_content_dep_b_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_ephemeris_common_content_dep_b_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_ephemeris_common_content_dep_b_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_ephemeris_common_content_dep_b_cmp(
    const sbp_ephemeris_common_content_dep_b_t *a,
    const sbp_ephemeris_common_content_dep_b_t *b) {
  int ret = 0;

  ret = sbp_v4_gnss_signal_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_gps_time_sec_cmp(&a->toe, &b->toe);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->ura, &b->ura);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->fit_interval, &b->fit_interval);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->valid, &b->valid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->health_bits, &b->health_bits);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_ephemeris_common_content_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_ephemeris_common_content_dep_a_t *msg) {
  if (!sbp_gnss_signal_dep_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_gps_time_dep_encode_internal(ctx, &msg->toe)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->ura)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->fit_interval)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->valid)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->health_bits)) {
    return false;
  }
  return true;
}

s8 sbp_ephemeris_common_content_dep_a_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_ephemeris_common_content_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_ephemeris_common_content_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_ephemeris_common_content_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_ephemeris_common_content_dep_a_t *msg) {
  if (!sbp_gnss_signal_dep_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_gps_time_dep_decode_internal(ctx, &msg->toe)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->ura)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->fit_interval)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->valid)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->health_bits)) {
    return false;
  }
  return true;
}

s8 sbp_ephemeris_common_content_dep_a_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_ephemeris_common_content_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_ephemeris_common_content_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_ephemeris_common_content_dep_a_cmp(
    const sbp_ephemeris_common_content_dep_a_t *a,
    const sbp_ephemeris_common_content_dep_a_t *b) {
  int ret = 0;

  ret = sbp_gnss_signal_dep_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_gps_time_dep_cmp(&a->toe, &b->toe);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->ura, &b->ura);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->fit_interval, &b->fit_interval);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->valid, &b->valid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->health_bits, &b->health_bits);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ephemeris_gps_dep_e_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_gps_dep_e_t *msg) {
  if (!sbp_ephemeris_common_content_dep_a_encode_internal(ctx, &msg->common)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->tgd)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_rs)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_rc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_uc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_us)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_ic)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_is)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->dn)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->m0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->ecc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->sqrta)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->omega0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->omegadot)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->w)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->inc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->af0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->af1)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->af2)) {
    return false;
  }
  if (!sbp_gps_time_dep_encode_internal(ctx, &msg->toc)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->iode)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->iodc)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ephemeris_gps_dep_e_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ephemeris_gps_dep_e_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_gps_dep_e_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ephemeris_gps_dep_e_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ephemeris_gps_dep_e_t *msg) {
  if (!sbp_ephemeris_common_content_dep_a_decode_internal(ctx, &msg->common)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->tgd)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_rs)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_rc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_uc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_us)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_ic)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_is)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->dn)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->m0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->ecc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->sqrta)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->omega0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->omegadot)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->w)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->inc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->af0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->af1)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->af2)) {
    return false;
  }
  if (!sbp_gps_time_dep_decode_internal(ctx, &msg->toc)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->iode)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->iodc)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ephemeris_gps_dep_e_decode(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_ephemeris_gps_dep_e_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_gps_dep_e_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ephemeris_gps_dep_e_send(sbp_state_t *s, u16 sender_id,
                                    const sbp_msg_ephemeris_gps_dep_e_t *msg,
                                    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ephemeris_gps_dep_e_encode(payload, sizeof(payload),
                                              &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_GPS_DEP_E, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_ephemeris_gps_dep_e_cmp(const sbp_msg_ephemeris_gps_dep_e_t *a,
                                    const sbp_msg_ephemeris_gps_dep_e_t *b) {
  int ret = 0;

  ret = sbp_ephemeris_common_content_dep_a_cmp(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->tgd, &b->tgd);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_rs, &b->c_rs);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_rc, &b->c_rc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_uc, &b->c_uc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_us, &b->c_us);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_ic, &b->c_ic);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_is, &b->c_is);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->dn, &b->dn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->m0, &b->m0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->ecc, &b->ecc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->sqrta, &b->sqrta);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->omega0, &b->omega0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->omegadot, &b->omegadot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->w, &b->w);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->inc, &b->inc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->inc_dot, &b->inc_dot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->af0, &b->af0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->af1, &b->af1);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->af2, &b->af2);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_gps_time_dep_cmp(&a->toc, &b->toc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->iode, &b->iode);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->iodc, &b->iodc);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ephemeris_gps_dep_f_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_gps_dep_f_t *msg) {
  if (!sbp_ephemeris_common_content_dep_b_encode_internal(ctx, &msg->common)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->tgd)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_rs)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_rc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_uc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_us)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_ic)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_is)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->dn)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->m0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->ecc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->sqrta)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->omega0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->omegadot)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->w)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->inc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->af0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->af1)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->af2)) {
    return false;
  }
  if (!sbp_gps_time_sec_encode_internal(ctx, &msg->toc)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->iode)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->iodc)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ephemeris_gps_dep_f_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ephemeris_gps_dep_f_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_gps_dep_f_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ephemeris_gps_dep_f_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ephemeris_gps_dep_f_t *msg) {
  if (!sbp_ephemeris_common_content_dep_b_decode_internal(ctx, &msg->common)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->tgd)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_rs)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_rc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_uc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_us)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_ic)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_is)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->dn)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->m0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->ecc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->sqrta)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->omega0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->omegadot)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->w)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->inc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->af0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->af1)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->af2)) {
    return false;
  }
  if (!sbp_gps_time_sec_decode_internal(ctx, &msg->toc)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->iode)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->iodc)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ephemeris_gps_dep_f_decode(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_ephemeris_gps_dep_f_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_gps_dep_f_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ephemeris_gps_dep_f_send(sbp_state_t *s, u16 sender_id,
                                    const sbp_msg_ephemeris_gps_dep_f_t *msg,
                                    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ephemeris_gps_dep_f_encode(payload, sizeof(payload),
                                              &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_GPS_DEP_F, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_ephemeris_gps_dep_f_cmp(const sbp_msg_ephemeris_gps_dep_f_t *a,
                                    const sbp_msg_ephemeris_gps_dep_f_t *b) {
  int ret = 0;

  ret = sbp_ephemeris_common_content_dep_b_cmp(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->tgd, &b->tgd);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_rs, &b->c_rs);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_rc, &b->c_rc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_uc, &b->c_uc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_us, &b->c_us);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_ic, &b->c_ic);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_is, &b->c_is);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->dn, &b->dn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->m0, &b->m0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->ecc, &b->ecc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->sqrta, &b->sqrta);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->omega0, &b->omega0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->omegadot, &b->omegadot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->w, &b->w);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->inc, &b->inc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->inc_dot, &b->inc_dot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->af0, &b->af0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->af1, &b->af1);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->af2, &b->af2);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_gps_time_sec_cmp(&a->toc, &b->toc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->iode, &b->iode);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->iodc, &b->iodc);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ephemeris_gps_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_msg_ephemeris_gps_t *msg) {
  if (!sbp_ephemeris_common_content_encode_internal(ctx, &msg->common)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->tgd)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->c_rs)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->c_rc)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->c_uc)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->c_us)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->c_ic)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->c_is)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->dn)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->m0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->ecc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->sqrta)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->omega0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->omegadot)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->w)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->inc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->af0)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->af1)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->af2)) {
    return false;
  }
  if (!sbp_gps_time_sec_encode_internal(ctx, &msg->toc)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->iode)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->iodc)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ephemeris_gps_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                const sbp_msg_ephemeris_gps_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_gps_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ephemeris_gps_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_msg_ephemeris_gps_t *msg) {
  if (!sbp_ephemeris_common_content_decode_internal(ctx, &msg->common)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->tgd)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->c_rs)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->c_rc)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->c_uc)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->c_us)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->c_ic)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->c_is)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->dn)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->m0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->ecc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->sqrta)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->omega0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->omegadot)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->w)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->inc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->af0)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->af1)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->af2)) {
    return false;
  }
  if (!sbp_gps_time_sec_decode_internal(ctx, &msg->toc)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->iode)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->iodc)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ephemeris_gps_decode(const uint8_t *buf, uint8_t len,
                                uint8_t *n_read, sbp_msg_ephemeris_gps_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_gps_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ephemeris_gps_send(sbp_state_t *s, u16 sender_id,
                              const sbp_msg_ephemeris_gps_t *msg,
                              sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_ephemeris_gps_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_GPS, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_ephemeris_gps_cmp(const sbp_msg_ephemeris_gps_t *a,
                              const sbp_msg_ephemeris_gps_t *b) {
  int ret = 0;

  ret = sbp_ephemeris_common_content_cmp(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->tgd, &b->tgd);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->c_rs, &b->c_rs);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->c_rc, &b->c_rc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->c_uc, &b->c_uc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->c_us, &b->c_us);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->c_ic, &b->c_ic);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->c_is, &b->c_is);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->dn, &b->dn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->m0, &b->m0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->ecc, &b->ecc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->sqrta, &b->sqrta);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->omega0, &b->omega0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->omegadot, &b->omegadot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->w, &b->w);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->inc, &b->inc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->inc_dot, &b->inc_dot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->af0, &b->af0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->af1, &b->af1);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->af2, &b->af2);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_gps_time_sec_cmp(&a->toc, &b->toc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->iode, &b->iode);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->iodc, &b->iodc);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ephemeris_qzss_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_qzss_t *msg) {
  if (!sbp_ephemeris_common_content_encode_internal(ctx, &msg->common)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->tgd)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->c_rs)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->c_rc)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->c_uc)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->c_us)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->c_ic)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->c_is)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->dn)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->m0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->ecc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->sqrta)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->omega0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->omegadot)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->w)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->inc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->af0)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->af1)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->af2)) {
    return false;
  }
  if (!sbp_gps_time_sec_encode_internal(ctx, &msg->toc)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->iode)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->iodc)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ephemeris_qzss_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_msg_ephemeris_qzss_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_qzss_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ephemeris_qzss_decode_internal(sbp_decode_ctx_t *ctx,
                                            sbp_msg_ephemeris_qzss_t *msg) {
  if (!sbp_ephemeris_common_content_decode_internal(ctx, &msg->common)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->tgd)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->c_rs)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->c_rc)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->c_uc)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->c_us)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->c_ic)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->c_is)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->dn)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->m0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->ecc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->sqrta)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->omega0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->omegadot)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->w)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->inc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->af0)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->af1)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->af2)) {
    return false;
  }
  if (!sbp_gps_time_sec_decode_internal(ctx, &msg->toc)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->iode)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->iodc)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ephemeris_qzss_decode(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read,
                                 sbp_msg_ephemeris_qzss_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_qzss_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ephemeris_qzss_send(sbp_state_t *s, u16 sender_id,
                               const sbp_msg_ephemeris_qzss_t *msg,
                               sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ephemeris_qzss_encode(payload, sizeof(payload), &payload_len,
                                         msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_QZSS, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_ephemeris_qzss_cmp(const sbp_msg_ephemeris_qzss_t *a,
                               const sbp_msg_ephemeris_qzss_t *b) {
  int ret = 0;

  ret = sbp_ephemeris_common_content_cmp(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->tgd, &b->tgd);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->c_rs, &b->c_rs);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->c_rc, &b->c_rc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->c_uc, &b->c_uc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->c_us, &b->c_us);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->c_ic, &b->c_ic);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->c_is, &b->c_is);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->dn, &b->dn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->m0, &b->m0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->ecc, &b->ecc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->sqrta, &b->sqrta);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->omega0, &b->omega0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->omegadot, &b->omegadot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->w, &b->w);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->inc, &b->inc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->inc_dot, &b->inc_dot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->af0, &b->af0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->af1, &b->af1);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->af2, &b->af2);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_gps_time_sec_cmp(&a->toc, &b->toc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->iode, &b->iode);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->iodc, &b->iodc);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ephemeris_bds_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_msg_ephemeris_bds_t *msg) {
  if (!sbp_ephemeris_common_content_encode_internal(ctx, &msg->common)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->tgd1)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->tgd2)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->c_rs)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->c_rc)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->c_uc)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->c_us)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->c_ic)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->c_is)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->dn)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->m0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->ecc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->sqrta)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->omega0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->omegadot)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->w)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->inc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->af0)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->af1)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->af2)) {
    return false;
  }
  if (!sbp_gps_time_sec_encode_internal(ctx, &msg->toc)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->iode)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->iodc)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ephemeris_bds_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                const sbp_msg_ephemeris_bds_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_bds_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ephemeris_bds_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_msg_ephemeris_bds_t *msg) {
  if (!sbp_ephemeris_common_content_decode_internal(ctx, &msg->common)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->tgd1)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->tgd2)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->c_rs)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->c_rc)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->c_uc)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->c_us)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->c_ic)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->c_is)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->dn)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->m0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->ecc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->sqrta)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->omega0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->omegadot)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->w)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->inc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->af0)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->af1)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->af2)) {
    return false;
  }
  if (!sbp_gps_time_sec_decode_internal(ctx, &msg->toc)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->iode)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->iodc)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ephemeris_bds_decode(const uint8_t *buf, uint8_t len,
                                uint8_t *n_read, sbp_msg_ephemeris_bds_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_bds_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ephemeris_bds_send(sbp_state_t *s, u16 sender_id,
                              const sbp_msg_ephemeris_bds_t *msg,
                              sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_ephemeris_bds_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_BDS, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_ephemeris_bds_cmp(const sbp_msg_ephemeris_bds_t *a,
                              const sbp_msg_ephemeris_bds_t *b) {
  int ret = 0;

  ret = sbp_ephemeris_common_content_cmp(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->tgd1, &b->tgd1);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->tgd2, &b->tgd2);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->c_rs, &b->c_rs);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->c_rc, &b->c_rc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->c_uc, &b->c_uc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->c_us, &b->c_us);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->c_ic, &b->c_ic);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->c_is, &b->c_is);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->dn, &b->dn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->m0, &b->m0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->ecc, &b->ecc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->sqrta, &b->sqrta);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->omega0, &b->omega0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->omegadot, &b->omegadot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->w, &b->w);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->inc, &b->inc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->inc_dot, &b->inc_dot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->af0, &b->af0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->af1, &b->af1);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->af2, &b->af2);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_gps_time_sec_cmp(&a->toc, &b->toc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->iode, &b->iode);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->iodc, &b->iodc);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ephemeris_gal_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_gal_dep_a_t *msg) {
  if (!sbp_ephemeris_common_content_encode_internal(ctx, &msg->common)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->bgd_e1e5a)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->bgd_e1e5b)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->c_rs)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->c_rc)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->c_uc)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->c_us)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->c_ic)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->c_is)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->dn)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->m0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->ecc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->sqrta)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->omega0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->omegadot)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->w)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->inc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->af0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->af1)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->af2)) {
    return false;
  }
  if (!sbp_gps_time_sec_encode_internal(ctx, &msg->toc)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->iode)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->iodc)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ephemeris_gal_dep_a_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ephemeris_gal_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_gal_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ephemeris_gal_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ephemeris_gal_dep_a_t *msg) {
  if (!sbp_ephemeris_common_content_decode_internal(ctx, &msg->common)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->bgd_e1e5a)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->bgd_e1e5b)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->c_rs)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->c_rc)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->c_uc)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->c_us)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->c_ic)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->c_is)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->dn)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->m0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->ecc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->sqrta)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->omega0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->omegadot)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->w)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->inc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->af0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->af1)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->af2)) {
    return false;
  }
  if (!sbp_gps_time_sec_decode_internal(ctx, &msg->toc)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->iode)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->iodc)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ephemeris_gal_dep_a_decode(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_ephemeris_gal_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_gal_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ephemeris_gal_dep_a_send(sbp_state_t *s, u16 sender_id,
                                    const sbp_msg_ephemeris_gal_dep_a_t *msg,
                                    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ephemeris_gal_dep_a_encode(payload, sizeof(payload),
                                              &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_GAL_DEP_A, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_ephemeris_gal_dep_a_cmp(const sbp_msg_ephemeris_gal_dep_a_t *a,
                                    const sbp_msg_ephemeris_gal_dep_a_t *b) {
  int ret = 0;

  ret = sbp_ephemeris_common_content_cmp(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->bgd_e1e5a, &b->bgd_e1e5a);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->bgd_e1e5b, &b->bgd_e1e5b);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->c_rs, &b->c_rs);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->c_rc, &b->c_rc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->c_uc, &b->c_uc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->c_us, &b->c_us);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->c_ic, &b->c_ic);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->c_is, &b->c_is);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->dn, &b->dn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->m0, &b->m0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->ecc, &b->ecc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->sqrta, &b->sqrta);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->omega0, &b->omega0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->omegadot, &b->omegadot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->w, &b->w);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->inc, &b->inc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->inc_dot, &b->inc_dot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->af0, &b->af0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->af1, &b->af1);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->af2, &b->af2);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_gps_time_sec_cmp(&a->toc, &b->toc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->iode, &b->iode);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->iodc, &b->iodc);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ephemeris_gal_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_msg_ephemeris_gal_t *msg) {
  if (!sbp_ephemeris_common_content_encode_internal(ctx, &msg->common)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->bgd_e1e5a)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->bgd_e1e5b)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->c_rs)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->c_rc)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->c_uc)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->c_us)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->c_ic)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->c_is)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->dn)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->m0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->ecc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->sqrta)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->omega0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->omegadot)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->w)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->inc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->af0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->af1)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->af2)) {
    return false;
  }
  if (!sbp_gps_time_sec_encode_internal(ctx, &msg->toc)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->iode)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->iodc)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->source)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ephemeris_gal_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                const sbp_msg_ephemeris_gal_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_gal_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ephemeris_gal_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_msg_ephemeris_gal_t *msg) {
  if (!sbp_ephemeris_common_content_decode_internal(ctx, &msg->common)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->bgd_e1e5a)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->bgd_e1e5b)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->c_rs)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->c_rc)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->c_uc)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->c_us)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->c_ic)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->c_is)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->dn)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->m0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->ecc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->sqrta)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->omega0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->omegadot)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->w)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->inc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->af0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->af1)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->af2)) {
    return false;
  }
  if (!sbp_gps_time_sec_decode_internal(ctx, &msg->toc)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->iode)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->iodc)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->source)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ephemeris_gal_decode(const uint8_t *buf, uint8_t len,
                                uint8_t *n_read, sbp_msg_ephemeris_gal_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_gal_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ephemeris_gal_send(sbp_state_t *s, u16 sender_id,
                              const sbp_msg_ephemeris_gal_t *msg,
                              sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_ephemeris_gal_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_GAL, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_ephemeris_gal_cmp(const sbp_msg_ephemeris_gal_t *a,
                              const sbp_msg_ephemeris_gal_t *b) {
  int ret = 0;

  ret = sbp_ephemeris_common_content_cmp(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->bgd_e1e5a, &b->bgd_e1e5a);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->bgd_e1e5b, &b->bgd_e1e5b);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->c_rs, &b->c_rs);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->c_rc, &b->c_rc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->c_uc, &b->c_uc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->c_us, &b->c_us);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->c_ic, &b->c_ic);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->c_is, &b->c_is);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->dn, &b->dn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->m0, &b->m0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->ecc, &b->ecc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->sqrta, &b->sqrta);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->omega0, &b->omega0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->omegadot, &b->omegadot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->w, &b->w);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->inc, &b->inc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->inc_dot, &b->inc_dot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->af0, &b->af0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->af1, &b->af1);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->af2, &b->af2);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_gps_time_sec_cmp(&a->toc, &b->toc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->iode, &b->iode);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->iodc, &b->iodc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->source, &b->source);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ephemeris_sbas_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_sbas_dep_a_t *msg) {
  if (!sbp_ephemeris_common_content_dep_a_encode_internal(ctx, &msg->common)) {
    return false;
  }
  for (size_t i = 0; i < SBP_MSG_EPHEMERIS_SBAS_DEP_A_POS_MAX; i++) {
    if (!sbp_double_encode(ctx, &msg->pos[i])) {
      return false;
    }
  }
  for (size_t i = 0; i < SBP_MSG_EPHEMERIS_SBAS_DEP_A_VEL_MAX; i++) {
    if (!sbp_double_encode(ctx, &msg->vel[i])) {
      return false;
    }
  }
  for (size_t i = 0; i < SBP_MSG_EPHEMERIS_SBAS_DEP_A_ACC_MAX; i++) {
    if (!sbp_double_encode(ctx, &msg->acc[i])) {
      return false;
    }
  }
  if (!sbp_double_encode(ctx, &msg->a_gf0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->a_gf1)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ephemeris_sbas_dep_a_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ephemeris_sbas_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_sbas_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ephemeris_sbas_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ephemeris_sbas_dep_a_t *msg) {
  if (!sbp_ephemeris_common_content_dep_a_decode_internal(ctx, &msg->common)) {
    return false;
  }
  for (uint8_t i = 0; i < SBP_MSG_EPHEMERIS_SBAS_DEP_A_POS_MAX; i++) {
    if (!sbp_double_decode(ctx, &msg->pos[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < SBP_MSG_EPHEMERIS_SBAS_DEP_A_VEL_MAX; i++) {
    if (!sbp_double_decode(ctx, &msg->vel[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < SBP_MSG_EPHEMERIS_SBAS_DEP_A_ACC_MAX; i++) {
    if (!sbp_double_decode(ctx, &msg->acc[i])) {
      return false;
    }
  }
  if (!sbp_double_decode(ctx, &msg->a_gf0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->a_gf1)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ephemeris_sbas_dep_a_decode(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_msg_ephemeris_sbas_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_sbas_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ephemeris_sbas_dep_a_send(sbp_state_t *s, u16 sender_id,
                                     const sbp_msg_ephemeris_sbas_dep_a_t *msg,
                                     sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ephemeris_sbas_dep_a_encode(payload, sizeof(payload),
                                               &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_SBAS_DEP_A, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_ephemeris_sbas_dep_a_cmp(const sbp_msg_ephemeris_sbas_dep_a_t *a,
                                     const sbp_msg_ephemeris_sbas_dep_a_t *b) {
  int ret = 0;

  ret = sbp_ephemeris_common_content_dep_a_cmp(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_EPHEMERIS_SBAS_DEP_A_POS_MAX;
       i++) {
    ret = sbp_double_cmp(&a->pos[i], &b->pos[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_EPHEMERIS_SBAS_DEP_A_VEL_MAX;
       i++) {
    ret = sbp_double_cmp(&a->vel[i], &b->vel[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_EPHEMERIS_SBAS_DEP_A_ACC_MAX;
       i++) {
    ret = sbp_double_cmp(&a->acc[i], &b->acc[i]);
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->a_gf0, &b->a_gf0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->a_gf1, &b->a_gf1);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ephemeris_glo_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_glo_dep_a_t *msg) {
  if (!sbp_ephemeris_common_content_dep_a_encode_internal(ctx, &msg->common)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->gamma)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->tau)) {
    return false;
  }
  for (size_t i = 0; i < SBP_MSG_EPHEMERIS_GLO_DEP_A_POS_MAX; i++) {
    if (!sbp_double_encode(ctx, &msg->pos[i])) {
      return false;
    }
  }
  for (size_t i = 0; i < SBP_MSG_EPHEMERIS_GLO_DEP_A_VEL_MAX; i++) {
    if (!sbp_double_encode(ctx, &msg->vel[i])) {
      return false;
    }
  }
  for (size_t i = 0; i < SBP_MSG_EPHEMERIS_GLO_DEP_A_ACC_MAX; i++) {
    if (!sbp_double_encode(ctx, &msg->acc[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ephemeris_glo_dep_a_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ephemeris_glo_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_glo_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ephemeris_glo_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ephemeris_glo_dep_a_t *msg) {
  if (!sbp_ephemeris_common_content_dep_a_decode_internal(ctx, &msg->common)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->gamma)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->tau)) {
    return false;
  }
  for (uint8_t i = 0; i < SBP_MSG_EPHEMERIS_GLO_DEP_A_POS_MAX; i++) {
    if (!sbp_double_decode(ctx, &msg->pos[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < SBP_MSG_EPHEMERIS_GLO_DEP_A_VEL_MAX; i++) {
    if (!sbp_double_decode(ctx, &msg->vel[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < SBP_MSG_EPHEMERIS_GLO_DEP_A_ACC_MAX; i++) {
    if (!sbp_double_decode(ctx, &msg->acc[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ephemeris_glo_dep_a_decode(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_ephemeris_glo_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_glo_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ephemeris_glo_dep_a_send(sbp_state_t *s, u16 sender_id,
                                    const sbp_msg_ephemeris_glo_dep_a_t *msg,
                                    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ephemeris_glo_dep_a_encode(payload, sizeof(payload),
                                              &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_GLO_DEP_A, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_ephemeris_glo_dep_a_cmp(const sbp_msg_ephemeris_glo_dep_a_t *a,
                                    const sbp_msg_ephemeris_glo_dep_a_t *b) {
  int ret = 0;

  ret = sbp_ephemeris_common_content_dep_a_cmp(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->gamma, &b->gamma);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->tau, &b->tau);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_EPHEMERIS_GLO_DEP_A_POS_MAX;
       i++) {
    ret = sbp_double_cmp(&a->pos[i], &b->pos[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_EPHEMERIS_GLO_DEP_A_VEL_MAX;
       i++) {
    ret = sbp_double_cmp(&a->vel[i], &b->vel[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_EPHEMERIS_GLO_DEP_A_ACC_MAX;
       i++) {
    ret = sbp_double_cmp(&a->acc[i], &b->acc[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ephemeris_sbas_dep_b_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_sbas_dep_b_t *msg) {
  if (!sbp_ephemeris_common_content_dep_b_encode_internal(ctx, &msg->common)) {
    return false;
  }
  for (size_t i = 0; i < SBP_MSG_EPHEMERIS_SBAS_DEP_B_POS_MAX; i++) {
    if (!sbp_double_encode(ctx, &msg->pos[i])) {
      return false;
    }
  }
  for (size_t i = 0; i < SBP_MSG_EPHEMERIS_SBAS_DEP_B_VEL_MAX; i++) {
    if (!sbp_double_encode(ctx, &msg->vel[i])) {
      return false;
    }
  }
  for (size_t i = 0; i < SBP_MSG_EPHEMERIS_SBAS_DEP_B_ACC_MAX; i++) {
    if (!sbp_double_encode(ctx, &msg->acc[i])) {
      return false;
    }
  }
  if (!sbp_double_encode(ctx, &msg->a_gf0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->a_gf1)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ephemeris_sbas_dep_b_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ephemeris_sbas_dep_b_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_sbas_dep_b_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ephemeris_sbas_dep_b_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ephemeris_sbas_dep_b_t *msg) {
  if (!sbp_ephemeris_common_content_dep_b_decode_internal(ctx, &msg->common)) {
    return false;
  }
  for (uint8_t i = 0; i < SBP_MSG_EPHEMERIS_SBAS_DEP_B_POS_MAX; i++) {
    if (!sbp_double_decode(ctx, &msg->pos[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < SBP_MSG_EPHEMERIS_SBAS_DEP_B_VEL_MAX; i++) {
    if (!sbp_double_decode(ctx, &msg->vel[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < SBP_MSG_EPHEMERIS_SBAS_DEP_B_ACC_MAX; i++) {
    if (!sbp_double_decode(ctx, &msg->acc[i])) {
      return false;
    }
  }
  if (!sbp_double_decode(ctx, &msg->a_gf0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->a_gf1)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ephemeris_sbas_dep_b_decode(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_msg_ephemeris_sbas_dep_b_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_sbas_dep_b_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ephemeris_sbas_dep_b_send(sbp_state_t *s, u16 sender_id,
                                     const sbp_msg_ephemeris_sbas_dep_b_t *msg,
                                     sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ephemeris_sbas_dep_b_encode(payload, sizeof(payload),
                                               &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_SBAS_DEP_B, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_ephemeris_sbas_dep_b_cmp(const sbp_msg_ephemeris_sbas_dep_b_t *a,
                                     const sbp_msg_ephemeris_sbas_dep_b_t *b) {
  int ret = 0;

  ret = sbp_ephemeris_common_content_dep_b_cmp(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_EPHEMERIS_SBAS_DEP_B_POS_MAX;
       i++) {
    ret = sbp_double_cmp(&a->pos[i], &b->pos[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_EPHEMERIS_SBAS_DEP_B_VEL_MAX;
       i++) {
    ret = sbp_double_cmp(&a->vel[i], &b->vel[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_EPHEMERIS_SBAS_DEP_B_ACC_MAX;
       i++) {
    ret = sbp_double_cmp(&a->acc[i], &b->acc[i]);
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->a_gf0, &b->a_gf0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->a_gf1, &b->a_gf1);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ephemeris_sbas_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_sbas_t *msg) {
  if (!sbp_ephemeris_common_content_encode_internal(ctx, &msg->common)) {
    return false;
  }
  for (size_t i = 0; i < SBP_MSG_EPHEMERIS_SBAS_POS_MAX; i++) {
    if (!sbp_double_encode(ctx, &msg->pos[i])) {
      return false;
    }
  }
  for (size_t i = 0; i < SBP_MSG_EPHEMERIS_SBAS_VEL_MAX; i++) {
    if (!sbp_float_encode(ctx, &msg->vel[i])) {
      return false;
    }
  }
  for (size_t i = 0; i < SBP_MSG_EPHEMERIS_SBAS_ACC_MAX; i++) {
    if (!sbp_float_encode(ctx, &msg->acc[i])) {
      return false;
    }
  }
  if (!sbp_float_encode(ctx, &msg->a_gf0)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->a_gf1)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ephemeris_sbas_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_msg_ephemeris_sbas_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_sbas_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ephemeris_sbas_decode_internal(sbp_decode_ctx_t *ctx,
                                            sbp_msg_ephemeris_sbas_t *msg) {
  if (!sbp_ephemeris_common_content_decode_internal(ctx, &msg->common)) {
    return false;
  }
  for (uint8_t i = 0; i < SBP_MSG_EPHEMERIS_SBAS_POS_MAX; i++) {
    if (!sbp_double_decode(ctx, &msg->pos[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < SBP_MSG_EPHEMERIS_SBAS_VEL_MAX; i++) {
    if (!sbp_float_decode(ctx, &msg->vel[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < SBP_MSG_EPHEMERIS_SBAS_ACC_MAX; i++) {
    if (!sbp_float_decode(ctx, &msg->acc[i])) {
      return false;
    }
  }
  if (!sbp_float_decode(ctx, &msg->a_gf0)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->a_gf1)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ephemeris_sbas_decode(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read,
                                 sbp_msg_ephemeris_sbas_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_sbas_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ephemeris_sbas_send(sbp_state_t *s, u16 sender_id,
                               const sbp_msg_ephemeris_sbas_t *msg,
                               sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ephemeris_sbas_encode(payload, sizeof(payload), &payload_len,
                                         msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_SBAS, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_ephemeris_sbas_cmp(const sbp_msg_ephemeris_sbas_t *a,
                               const sbp_msg_ephemeris_sbas_t *b) {
  int ret = 0;

  ret = sbp_ephemeris_common_content_cmp(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_EPHEMERIS_SBAS_POS_MAX; i++) {
    ret = sbp_double_cmp(&a->pos[i], &b->pos[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_EPHEMERIS_SBAS_VEL_MAX; i++) {
    ret = sbp_float_cmp(&a->vel[i], &b->vel[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_EPHEMERIS_SBAS_ACC_MAX; i++) {
    ret = sbp_float_cmp(&a->acc[i], &b->acc[i]);
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->a_gf0, &b->a_gf0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->a_gf1, &b->a_gf1);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ephemeris_glo_dep_b_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_glo_dep_b_t *msg) {
  if (!sbp_ephemeris_common_content_dep_b_encode_internal(ctx, &msg->common)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->gamma)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->tau)) {
    return false;
  }
  for (size_t i = 0; i < SBP_MSG_EPHEMERIS_GLO_DEP_B_POS_MAX; i++) {
    if (!sbp_double_encode(ctx, &msg->pos[i])) {
      return false;
    }
  }
  for (size_t i = 0; i < SBP_MSG_EPHEMERIS_GLO_DEP_B_VEL_MAX; i++) {
    if (!sbp_double_encode(ctx, &msg->vel[i])) {
      return false;
    }
  }
  for (size_t i = 0; i < SBP_MSG_EPHEMERIS_GLO_DEP_B_ACC_MAX; i++) {
    if (!sbp_double_encode(ctx, &msg->acc[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ephemeris_glo_dep_b_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ephemeris_glo_dep_b_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_glo_dep_b_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ephemeris_glo_dep_b_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ephemeris_glo_dep_b_t *msg) {
  if (!sbp_ephemeris_common_content_dep_b_decode_internal(ctx, &msg->common)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->gamma)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->tau)) {
    return false;
  }
  for (uint8_t i = 0; i < SBP_MSG_EPHEMERIS_GLO_DEP_B_POS_MAX; i++) {
    if (!sbp_double_decode(ctx, &msg->pos[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < SBP_MSG_EPHEMERIS_GLO_DEP_B_VEL_MAX; i++) {
    if (!sbp_double_decode(ctx, &msg->vel[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < SBP_MSG_EPHEMERIS_GLO_DEP_B_ACC_MAX; i++) {
    if (!sbp_double_decode(ctx, &msg->acc[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_ephemeris_glo_dep_b_decode(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_ephemeris_glo_dep_b_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_glo_dep_b_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ephemeris_glo_dep_b_send(sbp_state_t *s, u16 sender_id,
                                    const sbp_msg_ephemeris_glo_dep_b_t *msg,
                                    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ephemeris_glo_dep_b_encode(payload, sizeof(payload),
                                              &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_GLO_DEP_B, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_ephemeris_glo_dep_b_cmp(const sbp_msg_ephemeris_glo_dep_b_t *a,
                                    const sbp_msg_ephemeris_glo_dep_b_t *b) {
  int ret = 0;

  ret = sbp_ephemeris_common_content_dep_b_cmp(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->gamma, &b->gamma);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->tau, &b->tau);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_EPHEMERIS_GLO_DEP_B_POS_MAX;
       i++) {
    ret = sbp_double_cmp(&a->pos[i], &b->pos[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_EPHEMERIS_GLO_DEP_B_VEL_MAX;
       i++) {
    ret = sbp_double_cmp(&a->vel[i], &b->vel[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_EPHEMERIS_GLO_DEP_B_ACC_MAX;
       i++) {
    ret = sbp_double_cmp(&a->acc[i], &b->acc[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ephemeris_glo_dep_c_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_glo_dep_c_t *msg) {
  if (!sbp_ephemeris_common_content_dep_b_encode_internal(ctx, &msg->common)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->gamma)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->tau)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->d_tau)) {
    return false;
  }
  for (size_t i = 0; i < SBP_MSG_EPHEMERIS_GLO_DEP_C_POS_MAX; i++) {
    if (!sbp_double_encode(ctx, &msg->pos[i])) {
      return false;
    }
  }
  for (size_t i = 0; i < SBP_MSG_EPHEMERIS_GLO_DEP_C_VEL_MAX; i++) {
    if (!sbp_double_encode(ctx, &msg->vel[i])) {
      return false;
    }
  }
  for (size_t i = 0; i < SBP_MSG_EPHEMERIS_GLO_DEP_C_ACC_MAX; i++) {
    if (!sbp_double_encode(ctx, &msg->acc[i])) {
      return false;
    }
  }
  if (!sbp_u8_encode(ctx, &msg->fcn)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ephemeris_glo_dep_c_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ephemeris_glo_dep_c_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_glo_dep_c_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ephemeris_glo_dep_c_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ephemeris_glo_dep_c_t *msg) {
  if (!sbp_ephemeris_common_content_dep_b_decode_internal(ctx, &msg->common)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->gamma)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->tau)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->d_tau)) {
    return false;
  }
  for (uint8_t i = 0; i < SBP_MSG_EPHEMERIS_GLO_DEP_C_POS_MAX; i++) {
    if (!sbp_double_decode(ctx, &msg->pos[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < SBP_MSG_EPHEMERIS_GLO_DEP_C_VEL_MAX; i++) {
    if (!sbp_double_decode(ctx, &msg->vel[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < SBP_MSG_EPHEMERIS_GLO_DEP_C_ACC_MAX; i++) {
    if (!sbp_double_decode(ctx, &msg->acc[i])) {
      return false;
    }
  }
  if (!sbp_u8_decode(ctx, &msg->fcn)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ephemeris_glo_dep_c_decode(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_ephemeris_glo_dep_c_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_glo_dep_c_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ephemeris_glo_dep_c_send(sbp_state_t *s, u16 sender_id,
                                    const sbp_msg_ephemeris_glo_dep_c_t *msg,
                                    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ephemeris_glo_dep_c_encode(payload, sizeof(payload),
                                              &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_GLO_DEP_C, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_ephemeris_glo_dep_c_cmp(const sbp_msg_ephemeris_glo_dep_c_t *a,
                                    const sbp_msg_ephemeris_glo_dep_c_t *b) {
  int ret = 0;

  ret = sbp_ephemeris_common_content_dep_b_cmp(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->gamma, &b->gamma);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->tau, &b->tau);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->d_tau, &b->d_tau);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_EPHEMERIS_GLO_DEP_C_POS_MAX;
       i++) {
    ret = sbp_double_cmp(&a->pos[i], &b->pos[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_EPHEMERIS_GLO_DEP_C_VEL_MAX;
       i++) {
    ret = sbp_double_cmp(&a->vel[i], &b->vel[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_EPHEMERIS_GLO_DEP_C_ACC_MAX;
       i++) {
    ret = sbp_double_cmp(&a->acc[i], &b->acc[i]);
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->fcn, &b->fcn);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ephemeris_glo_dep_d_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_glo_dep_d_t *msg) {
  if (!sbp_ephemeris_common_content_dep_b_encode_internal(ctx, &msg->common)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->gamma)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->tau)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->d_tau)) {
    return false;
  }
  for (size_t i = 0; i < SBP_MSG_EPHEMERIS_GLO_DEP_D_POS_MAX; i++) {
    if (!sbp_double_encode(ctx, &msg->pos[i])) {
      return false;
    }
  }
  for (size_t i = 0; i < SBP_MSG_EPHEMERIS_GLO_DEP_D_VEL_MAX; i++) {
    if (!sbp_double_encode(ctx, &msg->vel[i])) {
      return false;
    }
  }
  for (size_t i = 0; i < SBP_MSG_EPHEMERIS_GLO_DEP_D_ACC_MAX; i++) {
    if (!sbp_double_encode(ctx, &msg->acc[i])) {
      return false;
    }
  }
  if (!sbp_u8_encode(ctx, &msg->fcn)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->iod)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ephemeris_glo_dep_d_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_ephemeris_glo_dep_d_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_glo_dep_d_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ephemeris_glo_dep_d_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_ephemeris_glo_dep_d_t *msg) {
  if (!sbp_ephemeris_common_content_dep_b_decode_internal(ctx, &msg->common)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->gamma)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->tau)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->d_tau)) {
    return false;
  }
  for (uint8_t i = 0; i < SBP_MSG_EPHEMERIS_GLO_DEP_D_POS_MAX; i++) {
    if (!sbp_double_decode(ctx, &msg->pos[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < SBP_MSG_EPHEMERIS_GLO_DEP_D_VEL_MAX; i++) {
    if (!sbp_double_decode(ctx, &msg->vel[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < SBP_MSG_EPHEMERIS_GLO_DEP_D_ACC_MAX; i++) {
    if (!sbp_double_decode(ctx, &msg->acc[i])) {
      return false;
    }
  }
  if (!sbp_u8_decode(ctx, &msg->fcn)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->iod)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ephemeris_glo_dep_d_decode(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_ephemeris_glo_dep_d_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_glo_dep_d_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ephemeris_glo_dep_d_send(sbp_state_t *s, u16 sender_id,
                                    const sbp_msg_ephemeris_glo_dep_d_t *msg,
                                    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ephemeris_glo_dep_d_encode(payload, sizeof(payload),
                                              &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_GLO_DEP_D, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_ephemeris_glo_dep_d_cmp(const sbp_msg_ephemeris_glo_dep_d_t *a,
                                    const sbp_msg_ephemeris_glo_dep_d_t *b) {
  int ret = 0;

  ret = sbp_ephemeris_common_content_dep_b_cmp(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->gamma, &b->gamma);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->tau, &b->tau);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->d_tau, &b->d_tau);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_EPHEMERIS_GLO_DEP_D_POS_MAX;
       i++) {
    ret = sbp_double_cmp(&a->pos[i], &b->pos[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_EPHEMERIS_GLO_DEP_D_VEL_MAX;
       i++) {
    ret = sbp_double_cmp(&a->vel[i], &b->vel[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_EPHEMERIS_GLO_DEP_D_ACC_MAX;
       i++) {
    ret = sbp_double_cmp(&a->acc[i], &b->acc[i]);
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->fcn, &b->fcn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->iod, &b->iod);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ephemeris_glo_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_msg_ephemeris_glo_t *msg) {
  if (!sbp_ephemeris_common_content_encode_internal(ctx, &msg->common)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->gamma)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->tau)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->d_tau)) {
    return false;
  }
  for (size_t i = 0; i < SBP_MSG_EPHEMERIS_GLO_POS_MAX; i++) {
    if (!sbp_double_encode(ctx, &msg->pos[i])) {
      return false;
    }
  }
  for (size_t i = 0; i < SBP_MSG_EPHEMERIS_GLO_VEL_MAX; i++) {
    if (!sbp_double_encode(ctx, &msg->vel[i])) {
      return false;
    }
  }
  for (size_t i = 0; i < SBP_MSG_EPHEMERIS_GLO_ACC_MAX; i++) {
    if (!sbp_float_encode(ctx, &msg->acc[i])) {
      return false;
    }
  }
  if (!sbp_u8_encode(ctx, &msg->fcn)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->iod)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ephemeris_glo_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                const sbp_msg_ephemeris_glo_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_glo_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ephemeris_glo_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_msg_ephemeris_glo_t *msg) {
  if (!sbp_ephemeris_common_content_decode_internal(ctx, &msg->common)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->gamma)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->tau)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->d_tau)) {
    return false;
  }
  for (uint8_t i = 0; i < SBP_MSG_EPHEMERIS_GLO_POS_MAX; i++) {
    if (!sbp_double_decode(ctx, &msg->pos[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < SBP_MSG_EPHEMERIS_GLO_VEL_MAX; i++) {
    if (!sbp_double_decode(ctx, &msg->vel[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < SBP_MSG_EPHEMERIS_GLO_ACC_MAX; i++) {
    if (!sbp_float_decode(ctx, &msg->acc[i])) {
      return false;
    }
  }
  if (!sbp_u8_decode(ctx, &msg->fcn)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->iod)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ephemeris_glo_decode(const uint8_t *buf, uint8_t len,
                                uint8_t *n_read, sbp_msg_ephemeris_glo_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_glo_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ephemeris_glo_send(sbp_state_t *s, u16 sender_id,
                              const sbp_msg_ephemeris_glo_t *msg,
                              sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_ephemeris_glo_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_GLO, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_ephemeris_glo_cmp(const sbp_msg_ephemeris_glo_t *a,
                              const sbp_msg_ephemeris_glo_t *b) {
  int ret = 0;

  ret = sbp_ephemeris_common_content_cmp(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->gamma, &b->gamma);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->tau, &b->tau);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->d_tau, &b->d_tau);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_EPHEMERIS_GLO_POS_MAX; i++) {
    ret = sbp_double_cmp(&a->pos[i], &b->pos[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_EPHEMERIS_GLO_VEL_MAX; i++) {
    ret = sbp_double_cmp(&a->vel[i], &b->vel[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_EPHEMERIS_GLO_ACC_MAX; i++) {
    ret = sbp_float_cmp(&a->acc[i], &b->acc[i]);
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->fcn, &b->fcn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->iod, &b->iod);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ephemeris_dep_d_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_dep_d_t *msg) {
  if (!sbp_double_encode(ctx, &msg->tgd)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_rs)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_rc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_uc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_us)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_ic)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_is)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->dn)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->m0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->ecc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->sqrta)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->omega0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->omegadot)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->w)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->inc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->af0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->af1)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->af2)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->toe_tow)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->toe_wn)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->toc_tow)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->toc_wn)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->valid)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->healthy)) {
    return false;
  }
  if (!sbp_gnss_signal_dep_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->iode)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->iodc)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->reserved)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ephemeris_dep_d_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_ephemeris_dep_d_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_dep_d_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ephemeris_dep_d_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_msg_ephemeris_dep_d_t *msg) {
  if (!sbp_double_decode(ctx, &msg->tgd)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_rs)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_rc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_uc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_us)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_ic)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_is)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->dn)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->m0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->ecc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->sqrta)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->omega0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->omegadot)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->w)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->inc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->af0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->af1)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->af2)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->toe_tow)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->toe_wn)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->toc_tow)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->toc_wn)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->valid)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->healthy)) {
    return false;
  }
  if (!sbp_gnss_signal_dep_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->iode)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->iodc)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->reserved)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ephemeris_dep_d_decode(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read,
                                  sbp_msg_ephemeris_dep_d_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_dep_d_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ephemeris_dep_d_send(sbp_state_t *s, u16 sender_id,
                                const sbp_msg_ephemeris_dep_d_t *msg,
                                sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ephemeris_dep_d_encode(payload, sizeof(payload),
                                          &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_DEP_D, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_ephemeris_dep_d_cmp(const sbp_msg_ephemeris_dep_d_t *a,
                                const sbp_msg_ephemeris_dep_d_t *b) {
  int ret = 0;

  ret = sbp_double_cmp(&a->tgd, &b->tgd);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_rs, &b->c_rs);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_rc, &b->c_rc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_uc, &b->c_uc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_us, &b->c_us);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_ic, &b->c_ic);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_is, &b->c_is);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->dn, &b->dn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->m0, &b->m0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->ecc, &b->ecc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->sqrta, &b->sqrta);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->omega0, &b->omega0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->omegadot, &b->omegadot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->w, &b->w);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->inc, &b->inc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->inc_dot, &b->inc_dot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->af0, &b->af0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->af1, &b->af1);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->af2, &b->af2);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->toe_tow, &b->toe_tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->toe_wn, &b->toe_wn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->toc_tow, &b->toc_tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->toc_wn, &b->toc_wn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->valid, &b->valid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->healthy, &b->healthy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_gnss_signal_dep_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->iode, &b->iode);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->iodc, &b->iodc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->reserved, &b->reserved);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ephemeris_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_dep_a_t *msg) {
  if (!sbp_double_encode(ctx, &msg->tgd)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_rs)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_rc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_uc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_us)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_ic)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_is)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->dn)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->m0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->ecc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->sqrta)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->omega0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->omegadot)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->w)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->inc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->af0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->af1)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->af2)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->toe_tow)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->toe_wn)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->toc_tow)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->toc_wn)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->valid)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->healthy)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->prn)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ephemeris_dep_a_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_ephemeris_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ephemeris_dep_a_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_msg_ephemeris_dep_a_t *msg) {
  if (!sbp_double_decode(ctx, &msg->tgd)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_rs)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_rc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_uc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_us)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_ic)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_is)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->dn)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->m0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->ecc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->sqrta)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->omega0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->omegadot)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->w)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->inc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->af0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->af1)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->af2)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->toe_tow)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->toe_wn)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->toc_tow)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->toc_wn)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->valid)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->healthy)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->prn)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ephemeris_dep_a_decode(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read,
                                  sbp_msg_ephemeris_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ephemeris_dep_a_send(sbp_state_t *s, u16 sender_id,
                                const sbp_msg_ephemeris_dep_a_t *msg,
                                sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ephemeris_dep_a_encode(payload, sizeof(payload),
                                          &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_DEP_A, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_ephemeris_dep_a_cmp(const sbp_msg_ephemeris_dep_a_t *a,
                                const sbp_msg_ephemeris_dep_a_t *b) {
  int ret = 0;

  ret = sbp_double_cmp(&a->tgd, &b->tgd);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_rs, &b->c_rs);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_rc, &b->c_rc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_uc, &b->c_uc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_us, &b->c_us);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_ic, &b->c_ic);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_is, &b->c_is);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->dn, &b->dn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->m0, &b->m0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->ecc, &b->ecc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->sqrta, &b->sqrta);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->omega0, &b->omega0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->omegadot, &b->omegadot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->w, &b->w);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->inc, &b->inc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->inc_dot, &b->inc_dot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->af0, &b->af0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->af1, &b->af1);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->af2, &b->af2);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->toe_tow, &b->toe_tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->toe_wn, &b->toe_wn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->toc_tow, &b->toc_tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->toc_wn, &b->toc_wn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->valid, &b->valid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->healthy, &b->healthy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->prn, &b->prn);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ephemeris_dep_b_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_dep_b_t *msg) {
  if (!sbp_double_encode(ctx, &msg->tgd)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_rs)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_rc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_uc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_us)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_ic)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_is)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->dn)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->m0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->ecc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->sqrta)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->omega0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->omegadot)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->w)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->inc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->af0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->af1)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->af2)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->toe_tow)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->toe_wn)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->toc_tow)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->toc_wn)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->valid)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->healthy)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->prn)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->iode)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ephemeris_dep_b_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_ephemeris_dep_b_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_dep_b_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ephemeris_dep_b_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_msg_ephemeris_dep_b_t *msg) {
  if (!sbp_double_decode(ctx, &msg->tgd)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_rs)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_rc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_uc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_us)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_ic)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_is)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->dn)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->m0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->ecc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->sqrta)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->omega0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->omegadot)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->w)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->inc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->af0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->af1)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->af2)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->toe_tow)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->toe_wn)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->toc_tow)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->toc_wn)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->valid)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->healthy)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->prn)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->iode)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ephemeris_dep_b_decode(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read,
                                  sbp_msg_ephemeris_dep_b_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_dep_b_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ephemeris_dep_b_send(sbp_state_t *s, u16 sender_id,
                                const sbp_msg_ephemeris_dep_b_t *msg,
                                sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ephemeris_dep_b_encode(payload, sizeof(payload),
                                          &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_DEP_B, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_ephemeris_dep_b_cmp(const sbp_msg_ephemeris_dep_b_t *a,
                                const sbp_msg_ephemeris_dep_b_t *b) {
  int ret = 0;

  ret = sbp_double_cmp(&a->tgd, &b->tgd);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_rs, &b->c_rs);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_rc, &b->c_rc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_uc, &b->c_uc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_us, &b->c_us);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_ic, &b->c_ic);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_is, &b->c_is);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->dn, &b->dn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->m0, &b->m0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->ecc, &b->ecc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->sqrta, &b->sqrta);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->omega0, &b->omega0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->omegadot, &b->omegadot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->w, &b->w);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->inc, &b->inc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->inc_dot, &b->inc_dot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->af0, &b->af0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->af1, &b->af1);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->af2, &b->af2);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->toe_tow, &b->toe_tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->toe_wn, &b->toe_wn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->toc_tow, &b->toc_tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->toc_wn, &b->toc_wn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->valid, &b->valid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->healthy, &b->healthy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->prn, &b->prn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->iode, &b->iode);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_ephemeris_dep_c_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_ephemeris_dep_c_t *msg) {
  if (!sbp_double_encode(ctx, &msg->tgd)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_rs)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_rc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_uc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_us)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_ic)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->c_is)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->dn)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->m0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->ecc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->sqrta)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->omega0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->omegadot)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->w)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->inc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->af0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->af1)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->af2)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->toe_tow)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->toe_wn)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->toc_tow)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->toc_wn)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->valid)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->healthy)) {
    return false;
  }
  if (!sbp_gnss_signal_dep_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->iode)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->iodc)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->reserved)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ephemeris_dep_c_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_ephemeris_dep_c_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_dep_c_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ephemeris_dep_c_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_msg_ephemeris_dep_c_t *msg) {
  if (!sbp_double_decode(ctx, &msg->tgd)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_rs)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_rc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_uc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_us)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_ic)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->c_is)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->dn)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->m0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->ecc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->sqrta)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->omega0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->omegadot)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->w)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->inc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->inc_dot)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->af0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->af1)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->af2)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->toe_tow)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->toe_wn)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->toc_tow)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->toc_wn)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->valid)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->healthy)) {
    return false;
  }
  if (!sbp_gnss_signal_dep_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->iode)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->iodc)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->reserved)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ephemeris_dep_c_decode(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read,
                                  sbp_msg_ephemeris_dep_c_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ephemeris_dep_c_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ephemeris_dep_c_send(sbp_state_t *s, u16 sender_id,
                                const sbp_msg_ephemeris_dep_c_t *msg,
                                sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_ephemeris_dep_c_encode(payload, sizeof(payload),
                                          &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_EPHEMERIS_DEP_C, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_ephemeris_dep_c_cmp(const sbp_msg_ephemeris_dep_c_t *a,
                                const sbp_msg_ephemeris_dep_c_t *b) {
  int ret = 0;

  ret = sbp_double_cmp(&a->tgd, &b->tgd);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_rs, &b->c_rs);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_rc, &b->c_rc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_uc, &b->c_uc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_us, &b->c_us);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_ic, &b->c_ic);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->c_is, &b->c_is);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->dn, &b->dn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->m0, &b->m0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->ecc, &b->ecc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->sqrta, &b->sqrta);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->omega0, &b->omega0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->omegadot, &b->omegadot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->w, &b->w);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->inc, &b->inc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->inc_dot, &b->inc_dot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->af0, &b->af0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->af1, &b->af1);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->af2, &b->af2);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->toe_tow, &b->toe_tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->toe_wn, &b->toe_wn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->toc_tow, &b->toc_tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->toc_wn, &b->toc_wn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->valid, &b->valid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->healthy, &b->healthy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_gnss_signal_dep_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->iode, &b->iode);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->iodc, &b->iodc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->reserved, &b->reserved);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_observation_header_dep_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_observation_header_dep_t *msg) {
  if (!sbp_gps_time_dep_encode_internal(ctx, &msg->t)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_obs)) {
    return false;
  }
  return true;
}

s8 sbp_observation_header_dep_encode(uint8_t *buf, uint8_t len,
                                     uint8_t *n_written,
                                     const sbp_observation_header_dep_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_observation_header_dep_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_observation_header_dep_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_observation_header_dep_t *msg) {
  if (!sbp_gps_time_dep_decode_internal(ctx, &msg->t)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_obs)) {
    return false;
  }
  return true;
}

s8 sbp_observation_header_dep_decode(const uint8_t *buf, uint8_t len,
                                     uint8_t *n_read,
                                     sbp_observation_header_dep_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_observation_header_dep_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_observation_header_dep_cmp(const sbp_observation_header_dep_t *a,
                                   const sbp_observation_header_dep_t *b) {
  int ret = 0;

  ret = sbp_gps_time_dep_cmp(&a->t, &b->t);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_obs, &b->n_obs);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_carrier_phase_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_carrier_phase_dep_a_t *msg) {
  if (!sbp_s32_encode(ctx, &msg->i)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->f)) {
    return false;
  }
  return true;
}

s8 sbp_carrier_phase_dep_a_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_carrier_phase_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_carrier_phase_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_carrier_phase_dep_a_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_carrier_phase_dep_a_t *msg) {
  if (!sbp_s32_decode(ctx, &msg->i)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->f)) {
    return false;
  }
  return true;
}

s8 sbp_carrier_phase_dep_a_decode(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read,
                                  sbp_carrier_phase_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_carrier_phase_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_carrier_phase_dep_a_cmp(const sbp_carrier_phase_dep_a_t *a,
                                const sbp_carrier_phase_dep_a_t *b) {
  int ret = 0;

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

bool sbp_packed_obs_content_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_packed_obs_content_dep_a_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->P)) {
    return false;
  }
  if (!sbp_carrier_phase_dep_a_encode_internal(ctx, &msg->L)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->cn0)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->lock)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->prn)) {
    return false;
  }
  return true;
}

s8 sbp_packed_obs_content_dep_a_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_packed_obs_content_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_packed_obs_content_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_packed_obs_content_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_packed_obs_content_dep_a_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->P)) {
    return false;
  }
  if (!sbp_carrier_phase_dep_a_decode_internal(ctx, &msg->L)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->cn0)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->lock)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->prn)) {
    return false;
  }
  return true;
}

s8 sbp_packed_obs_content_dep_a_decode(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_packed_obs_content_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_packed_obs_content_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_packed_obs_content_dep_a_cmp(const sbp_packed_obs_content_dep_a_t *a,
                                     const sbp_packed_obs_content_dep_a_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->P, &b->P);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_carrier_phase_dep_a_cmp(&a->L, &b->L);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->cn0, &b->cn0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->lock, &b->lock);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->prn, &b->prn);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_packed_obs_content_dep_b_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_packed_obs_content_dep_b_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->P)) {
    return false;
  }
  if (!sbp_carrier_phase_dep_a_encode_internal(ctx, &msg->L)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->cn0)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->lock)) {
    return false;
  }
  if (!sbp_gnss_signal_dep_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  return true;
}

s8 sbp_packed_obs_content_dep_b_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_packed_obs_content_dep_b_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_packed_obs_content_dep_b_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_packed_obs_content_dep_b_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_packed_obs_content_dep_b_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->P)) {
    return false;
  }
  if (!sbp_carrier_phase_dep_a_decode_internal(ctx, &msg->L)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->cn0)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->lock)) {
    return false;
  }
  if (!sbp_gnss_signal_dep_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  return true;
}

s8 sbp_packed_obs_content_dep_b_decode(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_packed_obs_content_dep_b_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_packed_obs_content_dep_b_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_packed_obs_content_dep_b_cmp(const sbp_packed_obs_content_dep_b_t *a,
                                     const sbp_packed_obs_content_dep_b_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->P, &b->P);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_carrier_phase_dep_a_cmp(&a->L, &b->L);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->cn0, &b->cn0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->lock, &b->lock);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_gnss_signal_dep_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_packed_obs_content_dep_c_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_packed_obs_content_dep_c_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->P)) {
    return false;
  }
  if (!sbp_carrier_phase_encode_internal(ctx, &msg->L)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->cn0)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->lock)) {
    return false;
  }
  if (!sbp_gnss_signal_dep_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  return true;
}

s8 sbp_packed_obs_content_dep_c_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_packed_obs_content_dep_c_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_packed_obs_content_dep_c_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_packed_obs_content_dep_c_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_packed_obs_content_dep_c_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->P)) {
    return false;
  }
  if (!sbp_carrier_phase_decode_internal(ctx, &msg->L)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->cn0)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->lock)) {
    return false;
  }
  if (!sbp_gnss_signal_dep_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  return true;
}

s8 sbp_packed_obs_content_dep_c_decode(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_packed_obs_content_dep_c_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_packed_obs_content_dep_c_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_packed_obs_content_dep_c_cmp(const sbp_packed_obs_content_dep_c_t *a,
                                     const sbp_packed_obs_content_dep_c_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->P, &b->P);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_carrier_phase_cmp(&a->L, &b->L);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->cn0, &b->cn0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->lock, &b->lock);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_gnss_signal_dep_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_obs_dep_a_encode_internal(sbp_encode_ctx_t *ctx,
                                       const sbp_msg_obs_dep_a_t *msg) {
  if (!sbp_observation_header_dep_encode_internal(ctx, &msg->header)) {
    return false;
  }
  for (size_t i = 0; i < msg->n_obs; i++) {
    if (!sbp_packed_obs_content_dep_a_encode_internal(ctx, &msg->obs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_obs_dep_a_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                            const sbp_msg_obs_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_obs_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_obs_dep_a_decode_internal(sbp_decode_ctx_t *ctx,
                                       sbp_msg_obs_dep_a_t *msg) {
  if (!sbp_observation_header_dep_decode_internal(ctx, &msg->header)) {
    return false;
  }
  msg->n_obs = (uint8_t)((ctx->buf_len - ctx->offset) /
                         SBP_PACKED_OBS_CONTENT_DEP_A_ENCODED_LEN);
  for (uint8_t i = 0; i < msg->n_obs; i++) {
    if (!sbp_packed_obs_content_dep_a_decode_internal(ctx, &msg->obs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_obs_dep_a_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                            sbp_msg_obs_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_obs_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_obs_dep_a_send(sbp_state_t *s, u16 sender_id,
                          const sbp_msg_obs_dep_a_t *msg,
                          sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_obs_dep_a_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_OBS_DEP_A, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_obs_dep_a_cmp(const sbp_msg_obs_dep_a_t *a,
                          const sbp_msg_obs_dep_a_t *b) {
  int ret = 0;

  ret = sbp_observation_header_dep_cmp(&a->header, &b->header);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_obs, &b->n_obs);
  for (uint8_t i = 0; ret == 0 && i < a->n_obs; i++) {
    ret = sbp_packed_obs_content_dep_a_cmp(&a->obs[i], &b->obs[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_obs_dep_b_encode_internal(sbp_encode_ctx_t *ctx,
                                       const sbp_msg_obs_dep_b_t *msg) {
  if (!sbp_observation_header_dep_encode_internal(ctx, &msg->header)) {
    return false;
  }
  for (size_t i = 0; i < msg->n_obs; i++) {
    if (!sbp_packed_obs_content_dep_b_encode_internal(ctx, &msg->obs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_obs_dep_b_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                            const sbp_msg_obs_dep_b_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_obs_dep_b_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_obs_dep_b_decode_internal(sbp_decode_ctx_t *ctx,
                                       sbp_msg_obs_dep_b_t *msg) {
  if (!sbp_observation_header_dep_decode_internal(ctx, &msg->header)) {
    return false;
  }
  msg->n_obs = (uint8_t)((ctx->buf_len - ctx->offset) /
                         SBP_PACKED_OBS_CONTENT_DEP_B_ENCODED_LEN);
  for (uint8_t i = 0; i < msg->n_obs; i++) {
    if (!sbp_packed_obs_content_dep_b_decode_internal(ctx, &msg->obs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_obs_dep_b_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                            sbp_msg_obs_dep_b_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_obs_dep_b_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_obs_dep_b_send(sbp_state_t *s, u16 sender_id,
                          const sbp_msg_obs_dep_b_t *msg,
                          sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_obs_dep_b_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_OBS_DEP_B, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_obs_dep_b_cmp(const sbp_msg_obs_dep_b_t *a,
                          const sbp_msg_obs_dep_b_t *b) {
  int ret = 0;

  ret = sbp_observation_header_dep_cmp(&a->header, &b->header);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_obs, &b->n_obs);
  for (uint8_t i = 0; ret == 0 && i < a->n_obs; i++) {
    ret = sbp_packed_obs_content_dep_b_cmp(&a->obs[i], &b->obs[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_obs_dep_c_encode_internal(sbp_encode_ctx_t *ctx,
                                       const sbp_msg_obs_dep_c_t *msg) {
  if (!sbp_observation_header_dep_encode_internal(ctx, &msg->header)) {
    return false;
  }
  for (size_t i = 0; i < msg->n_obs; i++) {
    if (!sbp_packed_obs_content_dep_c_encode_internal(ctx, &msg->obs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_obs_dep_c_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                            const sbp_msg_obs_dep_c_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_obs_dep_c_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_obs_dep_c_decode_internal(sbp_decode_ctx_t *ctx,
                                       sbp_msg_obs_dep_c_t *msg) {
  if (!sbp_observation_header_dep_decode_internal(ctx, &msg->header)) {
    return false;
  }
  msg->n_obs = (uint8_t)((ctx->buf_len - ctx->offset) /
                         SBP_PACKED_OBS_CONTENT_DEP_C_ENCODED_LEN);
  for (uint8_t i = 0; i < msg->n_obs; i++) {
    if (!sbp_packed_obs_content_dep_c_decode_internal(ctx, &msg->obs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_obs_dep_c_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                            sbp_msg_obs_dep_c_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_obs_dep_c_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_obs_dep_c_send(sbp_state_t *s, u16 sender_id,
                          const sbp_msg_obs_dep_c_t *msg,
                          sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_obs_dep_c_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_OBS_DEP_C, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_obs_dep_c_cmp(const sbp_msg_obs_dep_c_t *a,
                          const sbp_msg_obs_dep_c_t *b) {
  int ret = 0;

  ret = sbp_observation_header_dep_cmp(&a->header, &b->header);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_obs, &b->n_obs);
  for (uint8_t i = 0; ret == 0 && i < a->n_obs; i++) {
    ret = sbp_packed_obs_content_dep_c_cmp(&a->obs[i], &b->obs[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_iono_encode_internal(sbp_encode_ctx_t *ctx,
                                  const sbp_msg_iono_t *msg) {
  if (!sbp_gps_time_sec_encode_internal(ctx, &msg->t_nmct)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->a0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->a1)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->a2)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->a3)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->b0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->b1)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->b2)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->b3)) {
    return false;
  }
  return true;
}

s8 sbp_msg_iono_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                       const sbp_msg_iono_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_iono_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_iono_decode_internal(sbp_decode_ctx_t *ctx, sbp_msg_iono_t *msg) {
  if (!sbp_gps_time_sec_decode_internal(ctx, &msg->t_nmct)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->a0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->a1)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->a2)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->a3)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->b0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->b1)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->b2)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->b3)) {
    return false;
  }
  return true;
}

s8 sbp_msg_iono_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                       sbp_msg_iono_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_iono_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_iono_send(sbp_state_t *s, u16 sender_id, const sbp_msg_iono_t *msg,
                     sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_iono_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_IONO, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_iono_cmp(const sbp_msg_iono_t *a, const sbp_msg_iono_t *b) {
  int ret = 0;

  ret = sbp_gps_time_sec_cmp(&a->t_nmct, &b->t_nmct);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->a0, &b->a0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->a1, &b->a1);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->a2, &b->a2);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->a3, &b->a3);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->b0, &b->b0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->b1, &b->b1);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->b2, &b->b2);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->b3, &b->b3);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_sv_configuration_gps_dep_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_sv_configuration_gps_dep_t *msg) {
  if (!sbp_gps_time_sec_encode_internal(ctx, &msg->t_nmct)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->l2c_mask)) {
    return false;
  }
  return true;
}

s8 sbp_msg_sv_configuration_gps_dep_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_sv_configuration_gps_dep_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_sv_configuration_gps_dep_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_sv_configuration_gps_dep_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_sv_configuration_gps_dep_t *msg) {
  if (!sbp_gps_time_sec_decode_internal(ctx, &msg->t_nmct)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->l2c_mask)) {
    return false;
  }
  return true;
}

s8 sbp_msg_sv_configuration_gps_dep_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_sv_configuration_gps_dep_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_sv_configuration_gps_dep_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_sv_configuration_gps_dep_send(
    sbp_state_t *s, u16 sender_id,
    const sbp_msg_sv_configuration_gps_dep_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_sv_configuration_gps_dep_encode(payload, sizeof(payload),
                                                   &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SV_CONFIGURATION_GPS_DEP, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_sv_configuration_gps_dep_cmp(
    const sbp_msg_sv_configuration_gps_dep_t *a,
    const sbp_msg_sv_configuration_gps_dep_t *b) {
  int ret = 0;

  ret = sbp_gps_time_sec_cmp(&a->t_nmct, &b->t_nmct);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->l2c_mask, &b->l2c_mask);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_gnss_capb_encode_internal(sbp_encode_ctx_t *ctx,
                                   const sbp_gnss_capb_t *msg) {
  if (!sbp_u64_encode(ctx, &msg->gps_active)) {
    return false;
  }
  if (!sbp_u64_encode(ctx, &msg->gps_l2c)) {
    return false;
  }
  if (!sbp_u64_encode(ctx, &msg->gps_l5)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->glo_active)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->glo_l2of)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->glo_l3)) {
    return false;
  }
  if (!sbp_u64_encode(ctx, &msg->sbas_active)) {
    return false;
  }
  if (!sbp_u64_encode(ctx, &msg->sbas_l5)) {
    return false;
  }
  if (!sbp_u64_encode(ctx, &msg->bds_active)) {
    return false;
  }
  if (!sbp_u64_encode(ctx, &msg->bds_d2nav)) {
    return false;
  }
  if (!sbp_u64_encode(ctx, &msg->bds_b2)) {
    return false;
  }
  if (!sbp_u64_encode(ctx, &msg->bds_b2a)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->qzss_active)) {
    return false;
  }
  if (!sbp_u64_encode(ctx, &msg->gal_active)) {
    return false;
  }
  if (!sbp_u64_encode(ctx, &msg->gal_e5)) {
    return false;
  }
  return true;
}

s8 sbp_gnss_capb_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                        const sbp_gnss_capb_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_gnss_capb_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_gnss_capb_decode_internal(sbp_decode_ctx_t *ctx,
                                   sbp_gnss_capb_t *msg) {
  if (!sbp_u64_decode(ctx, &msg->gps_active)) {
    return false;
  }
  if (!sbp_u64_decode(ctx, &msg->gps_l2c)) {
    return false;
  }
  if (!sbp_u64_decode(ctx, &msg->gps_l5)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->glo_active)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->glo_l2of)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->glo_l3)) {
    return false;
  }
  if (!sbp_u64_decode(ctx, &msg->sbas_active)) {
    return false;
  }
  if (!sbp_u64_decode(ctx, &msg->sbas_l5)) {
    return false;
  }
  if (!sbp_u64_decode(ctx, &msg->bds_active)) {
    return false;
  }
  if (!sbp_u64_decode(ctx, &msg->bds_d2nav)) {
    return false;
  }
  if (!sbp_u64_decode(ctx, &msg->bds_b2)) {
    return false;
  }
  if (!sbp_u64_decode(ctx, &msg->bds_b2a)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->qzss_active)) {
    return false;
  }
  if (!sbp_u64_decode(ctx, &msg->gal_active)) {
    return false;
  }
  if (!sbp_u64_decode(ctx, &msg->gal_e5)) {
    return false;
  }
  return true;
}

s8 sbp_gnss_capb_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                        sbp_gnss_capb_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_gnss_capb_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_gnss_capb_cmp(const sbp_gnss_capb_t *a, const sbp_gnss_capb_t *b) {
  int ret = 0;

  ret = sbp_u64_cmp(&a->gps_active, &b->gps_active);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u64_cmp(&a->gps_l2c, &b->gps_l2c);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u64_cmp(&a->gps_l5, &b->gps_l5);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->glo_active, &b->glo_active);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->glo_l2of, &b->glo_l2of);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->glo_l3, &b->glo_l3);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u64_cmp(&a->sbas_active, &b->sbas_active);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u64_cmp(&a->sbas_l5, &b->sbas_l5);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u64_cmp(&a->bds_active, &b->bds_active);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u64_cmp(&a->bds_d2nav, &b->bds_d2nav);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u64_cmp(&a->bds_b2, &b->bds_b2);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u64_cmp(&a->bds_b2a, &b->bds_b2a);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->qzss_active, &b->qzss_active);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u64_cmp(&a->gal_active, &b->gal_active);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u64_cmp(&a->gal_e5, &b->gal_e5);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_gnss_capb_encode_internal(sbp_encode_ctx_t *ctx,
                                       const sbp_msg_gnss_capb_t *msg) {
  if (!sbp_gps_time_sec_encode_internal(ctx, &msg->t_nmct)) {
    return false;
  }
  if (!sbp_gnss_capb_encode_internal(ctx, &msg->gc)) {
    return false;
  }
  return true;
}

s8 sbp_msg_gnss_capb_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                            const sbp_msg_gnss_capb_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_gnss_capb_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_gnss_capb_decode_internal(sbp_decode_ctx_t *ctx,
                                       sbp_msg_gnss_capb_t *msg) {
  if (!sbp_gps_time_sec_decode_internal(ctx, &msg->t_nmct)) {
    return false;
  }
  if (!sbp_gnss_capb_decode_internal(ctx, &msg->gc)) {
    return false;
  }
  return true;
}

s8 sbp_msg_gnss_capb_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                            sbp_msg_gnss_capb_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_gnss_capb_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_gnss_capb_send(sbp_state_t *s, u16 sender_id,
                          const sbp_msg_gnss_capb_t *msg,
                          sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_gnss_capb_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_GNSS_CAPB, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_gnss_capb_cmp(const sbp_msg_gnss_capb_t *a,
                          const sbp_msg_gnss_capb_t *b) {
  int ret = 0;

  ret = sbp_gps_time_sec_cmp(&a->t_nmct, &b->t_nmct);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_gnss_capb_cmp(&a->gc, &b->gc);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_group_delay_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_group_delay_dep_a_t *msg) {
  if (!sbp_gps_time_dep_encode_internal(ctx, &msg->t_op)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->prn)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->valid)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->tgd)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->isc_l1ca)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->isc_l2c)) {
    return false;
  }
  return true;
}

s8 sbp_msg_group_delay_dep_a_encode(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_msg_group_delay_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_group_delay_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_group_delay_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_group_delay_dep_a_t *msg) {
  if (!sbp_gps_time_dep_decode_internal(ctx, &msg->t_op)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->prn)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->valid)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->tgd)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->isc_l1ca)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->isc_l2c)) {
    return false;
  }
  return true;
}

s8 sbp_msg_group_delay_dep_a_decode(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_msg_group_delay_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_group_delay_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_group_delay_dep_a_send(sbp_state_t *s, u16 sender_id,
                                  const sbp_msg_group_delay_dep_a_t *msg,
                                  sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_group_delay_dep_a_encode(payload, sizeof(payload),
                                            &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_GROUP_DELAY_DEP_A, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_group_delay_dep_a_cmp(const sbp_msg_group_delay_dep_a_t *a,
                                  const sbp_msg_group_delay_dep_a_t *b) {
  int ret = 0;

  ret = sbp_gps_time_dep_cmp(&a->t_op, &b->t_op);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->prn, &b->prn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->valid, &b->valid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->tgd, &b->tgd);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->isc_l1ca, &b->isc_l1ca);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->isc_l2c, &b->isc_l2c);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_group_delay_dep_b_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_group_delay_dep_b_t *msg) {
  if (!sbp_gps_time_sec_encode_internal(ctx, &msg->t_op)) {
    return false;
  }
  if (!sbp_gnss_signal_dep_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->valid)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->tgd)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->isc_l1ca)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->isc_l2c)) {
    return false;
  }
  return true;
}

s8 sbp_msg_group_delay_dep_b_encode(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_msg_group_delay_dep_b_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_group_delay_dep_b_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_group_delay_dep_b_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_group_delay_dep_b_t *msg) {
  if (!sbp_gps_time_sec_decode_internal(ctx, &msg->t_op)) {
    return false;
  }
  if (!sbp_gnss_signal_dep_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->valid)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->tgd)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->isc_l1ca)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->isc_l2c)) {
    return false;
  }
  return true;
}

s8 sbp_msg_group_delay_dep_b_decode(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_msg_group_delay_dep_b_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_group_delay_dep_b_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_group_delay_dep_b_send(sbp_state_t *s, u16 sender_id,
                                  const sbp_msg_group_delay_dep_b_t *msg,
                                  sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_group_delay_dep_b_encode(payload, sizeof(payload),
                                            &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_GROUP_DELAY_DEP_B, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_group_delay_dep_b_cmp(const sbp_msg_group_delay_dep_b_t *a,
                                  const sbp_msg_group_delay_dep_b_t *b) {
  int ret = 0;

  ret = sbp_gps_time_sec_cmp(&a->t_op, &b->t_op);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_gnss_signal_dep_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->valid, &b->valid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->tgd, &b->tgd);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->isc_l1ca, &b->isc_l1ca);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->isc_l2c, &b->isc_l2c);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_group_delay_encode_internal(sbp_encode_ctx_t *ctx,
                                         const sbp_msg_group_delay_t *msg) {
  if (!sbp_gps_time_sec_encode_internal(ctx, &msg->t_op)) {
    return false;
  }
  if (!sbp_v4_gnss_signal_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->valid)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->tgd)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->isc_l1ca)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->isc_l2c)) {
    return false;
  }
  return true;
}

s8 sbp_msg_group_delay_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                              const sbp_msg_group_delay_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_group_delay_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_group_delay_decode_internal(sbp_decode_ctx_t *ctx,
                                         sbp_msg_group_delay_t *msg) {
  if (!sbp_gps_time_sec_decode_internal(ctx, &msg->t_op)) {
    return false;
  }
  if (!sbp_v4_gnss_signal_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->valid)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->tgd)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->isc_l1ca)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->isc_l2c)) {
    return false;
  }
  return true;
}

s8 sbp_msg_group_delay_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                              sbp_msg_group_delay_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_group_delay_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_group_delay_send(sbp_state_t *s, u16 sender_id,
                            const sbp_msg_group_delay_t *msg,
                            sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_group_delay_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_GROUP_DELAY, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_group_delay_cmp(const sbp_msg_group_delay_t *a,
                            const sbp_msg_group_delay_t *b) {
  int ret = 0;

  ret = sbp_gps_time_sec_cmp(&a->t_op, &b->t_op);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_v4_gnss_signal_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->valid, &b->valid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->tgd, &b->tgd);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->isc_l1ca, &b->isc_l1ca);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->isc_l2c, &b->isc_l2c);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_almanac_common_content_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_almanac_common_content_t *msg) {
  if (!sbp_v4_gnss_signal_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_gps_time_sec_encode_internal(ctx, &msg->toa)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->ura)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->fit_interval)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->valid)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->health_bits)) {
    return false;
  }
  return true;
}

s8 sbp_almanac_common_content_encode(uint8_t *buf, uint8_t len,
                                     uint8_t *n_written,
                                     const sbp_almanac_common_content_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_almanac_common_content_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_almanac_common_content_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_almanac_common_content_t *msg) {
  if (!sbp_v4_gnss_signal_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_gps_time_sec_decode_internal(ctx, &msg->toa)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->ura)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->fit_interval)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->valid)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->health_bits)) {
    return false;
  }
  return true;
}

s8 sbp_almanac_common_content_decode(const uint8_t *buf, uint8_t len,
                                     uint8_t *n_read,
                                     sbp_almanac_common_content_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_almanac_common_content_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_almanac_common_content_cmp(const sbp_almanac_common_content_t *a,
                                   const sbp_almanac_common_content_t *b) {
  int ret = 0;

  ret = sbp_v4_gnss_signal_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_gps_time_sec_cmp(&a->toa, &b->toa);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->ura, &b->ura);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->fit_interval, &b->fit_interval);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->valid, &b->valid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->health_bits, &b->health_bits);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_almanac_common_content_dep_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_almanac_common_content_dep_t *msg) {
  if (!sbp_gnss_signal_dep_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_gps_time_sec_encode_internal(ctx, &msg->toa)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->ura)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->fit_interval)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->valid)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->health_bits)) {
    return false;
  }
  return true;
}

s8 sbp_almanac_common_content_dep_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_almanac_common_content_dep_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_almanac_common_content_dep_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_almanac_common_content_dep_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_almanac_common_content_dep_t *msg) {
  if (!sbp_gnss_signal_dep_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_gps_time_sec_decode_internal(ctx, &msg->toa)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->ura)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->fit_interval)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->valid)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->health_bits)) {
    return false;
  }
  return true;
}

s8 sbp_almanac_common_content_dep_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_almanac_common_content_dep_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_almanac_common_content_dep_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_almanac_common_content_dep_cmp(
    const sbp_almanac_common_content_dep_t *a,
    const sbp_almanac_common_content_dep_t *b) {
  int ret = 0;

  ret = sbp_gnss_signal_dep_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_gps_time_sec_cmp(&a->toa, &b->toa);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->ura, &b->ura);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->fit_interval, &b->fit_interval);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->valid, &b->valid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->health_bits, &b->health_bits);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_almanac_gps_dep_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_almanac_gps_dep_t *msg) {
  if (!sbp_almanac_common_content_dep_encode_internal(ctx, &msg->common)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->m0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->ecc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->sqrta)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->omega0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->omegadot)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->w)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->inc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->af0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->af1)) {
    return false;
  }
  return true;
}

s8 sbp_msg_almanac_gps_dep_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_almanac_gps_dep_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_almanac_gps_dep_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_almanac_gps_dep_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_msg_almanac_gps_dep_t *msg) {
  if (!sbp_almanac_common_content_dep_decode_internal(ctx, &msg->common)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->m0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->ecc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->sqrta)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->omega0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->omegadot)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->w)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->inc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->af0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->af1)) {
    return false;
  }
  return true;
}

s8 sbp_msg_almanac_gps_dep_decode(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read,
                                  sbp_msg_almanac_gps_dep_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_almanac_gps_dep_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_almanac_gps_dep_send(sbp_state_t *s, u16 sender_id,
                                const sbp_msg_almanac_gps_dep_t *msg,
                                sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_almanac_gps_dep_encode(payload, sizeof(payload),
                                          &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_ALMANAC_GPS_DEP, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_almanac_gps_dep_cmp(const sbp_msg_almanac_gps_dep_t *a,
                                const sbp_msg_almanac_gps_dep_t *b) {
  int ret = 0;

  ret = sbp_almanac_common_content_dep_cmp(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->m0, &b->m0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->ecc, &b->ecc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->sqrta, &b->sqrta);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->omega0, &b->omega0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->omegadot, &b->omegadot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->w, &b->w);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->inc, &b->inc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->af0, &b->af0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->af1, &b->af1);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_almanac_gps_encode_internal(sbp_encode_ctx_t *ctx,
                                         const sbp_msg_almanac_gps_t *msg) {
  if (!sbp_almanac_common_content_encode_internal(ctx, &msg->common)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->m0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->ecc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->sqrta)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->omega0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->omegadot)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->w)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->inc)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->af0)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->af1)) {
    return false;
  }
  return true;
}

s8 sbp_msg_almanac_gps_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                              const sbp_msg_almanac_gps_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_almanac_gps_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_almanac_gps_decode_internal(sbp_decode_ctx_t *ctx,
                                         sbp_msg_almanac_gps_t *msg) {
  if (!sbp_almanac_common_content_decode_internal(ctx, &msg->common)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->m0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->ecc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->sqrta)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->omega0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->omegadot)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->w)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->inc)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->af0)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->af1)) {
    return false;
  }
  return true;
}

s8 sbp_msg_almanac_gps_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                              sbp_msg_almanac_gps_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_almanac_gps_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_almanac_gps_send(sbp_state_t *s, u16 sender_id,
                            const sbp_msg_almanac_gps_t *msg,
                            sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_almanac_gps_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_ALMANAC_GPS, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_almanac_gps_cmp(const sbp_msg_almanac_gps_t *a,
                            const sbp_msg_almanac_gps_t *b) {
  int ret = 0;

  ret = sbp_almanac_common_content_cmp(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->m0, &b->m0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->ecc, &b->ecc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->sqrta, &b->sqrta);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->omega0, &b->omega0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->omegadot, &b->omegadot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->w, &b->w);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->inc, &b->inc);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->af0, &b->af0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->af1, &b->af1);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_almanac_glo_dep_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_almanac_glo_dep_t *msg) {
  if (!sbp_almanac_common_content_dep_encode_internal(ctx, &msg->common)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->lambda_na)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->t_lambda_na)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->i)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->t)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->t_dot)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->epsilon)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->omega)) {
    return false;
  }
  return true;
}

s8 sbp_msg_almanac_glo_dep_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_almanac_glo_dep_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_almanac_glo_dep_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_almanac_glo_dep_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_msg_almanac_glo_dep_t *msg) {
  if (!sbp_almanac_common_content_dep_decode_internal(ctx, &msg->common)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->lambda_na)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->t_lambda_na)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->i)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->t)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->t_dot)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->epsilon)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->omega)) {
    return false;
  }
  return true;
}

s8 sbp_msg_almanac_glo_dep_decode(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read,
                                  sbp_msg_almanac_glo_dep_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_almanac_glo_dep_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_almanac_glo_dep_send(sbp_state_t *s, u16 sender_id,
                                const sbp_msg_almanac_glo_dep_t *msg,
                                sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_almanac_glo_dep_encode(payload, sizeof(payload),
                                          &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_ALMANAC_GLO_DEP, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_almanac_glo_dep_cmp(const sbp_msg_almanac_glo_dep_t *a,
                                const sbp_msg_almanac_glo_dep_t *b) {
  int ret = 0;

  ret = sbp_almanac_common_content_dep_cmp(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->lambda_na, &b->lambda_na);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->t_lambda_na, &b->t_lambda_na);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->i, &b->i);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->t, &b->t);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->t_dot, &b->t_dot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->epsilon, &b->epsilon);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->omega, &b->omega);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_almanac_glo_encode_internal(sbp_encode_ctx_t *ctx,
                                         const sbp_msg_almanac_glo_t *msg) {
  if (!sbp_almanac_common_content_encode_internal(ctx, &msg->common)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->lambda_na)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->t_lambda_na)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->i)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->t)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->t_dot)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->epsilon)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->omega)) {
    return false;
  }
  return true;
}

s8 sbp_msg_almanac_glo_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                              const sbp_msg_almanac_glo_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_almanac_glo_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_almanac_glo_decode_internal(sbp_decode_ctx_t *ctx,
                                         sbp_msg_almanac_glo_t *msg) {
  if (!sbp_almanac_common_content_decode_internal(ctx, &msg->common)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->lambda_na)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->t_lambda_na)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->i)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->t)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->t_dot)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->epsilon)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->omega)) {
    return false;
  }
  return true;
}

s8 sbp_msg_almanac_glo_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                              sbp_msg_almanac_glo_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_almanac_glo_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_almanac_glo_send(sbp_state_t *s, u16 sender_id,
                            const sbp_msg_almanac_glo_t *msg,
                            sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_almanac_glo_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_ALMANAC_GLO, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_almanac_glo_cmp(const sbp_msg_almanac_glo_t *a,
                            const sbp_msg_almanac_glo_t *b) {
  int ret = 0;

  ret = sbp_almanac_common_content_cmp(&a->common, &b->common);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->lambda_na, &b->lambda_na);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->t_lambda_na, &b->t_lambda_na);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->i, &b->i);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->t, &b->t);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->t_dot, &b->t_dot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->epsilon, &b->epsilon);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->omega, &b->omega);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_glo_biases_encode_internal(sbp_encode_ctx_t *ctx,
                                        const sbp_msg_glo_biases_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->mask)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->l1ca_bias)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->l1p_bias)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->l2ca_bias)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->l2p_bias)) {
    return false;
  }
  return true;
}

s8 sbp_msg_glo_biases_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                             const sbp_msg_glo_biases_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_glo_biases_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_glo_biases_decode_internal(sbp_decode_ctx_t *ctx,
                                        sbp_msg_glo_biases_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->mask)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->l1ca_bias)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->l1p_bias)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->l2ca_bias)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->l2p_bias)) {
    return false;
  }
  return true;
}

s8 sbp_msg_glo_biases_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                             sbp_msg_glo_biases_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_glo_biases_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_glo_biases_send(sbp_state_t *s, u16 sender_id,
                           const sbp_msg_glo_biases_t *msg,
                           sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_glo_biases_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_GLO_BIASES, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_glo_biases_cmp(const sbp_msg_glo_biases_t *a,
                           const sbp_msg_glo_biases_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->mask, &b->mask);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->l1ca_bias, &b->l1ca_bias);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->l1p_bias, &b->l1p_bias);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->l2ca_bias, &b->l2ca_bias);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->l2p_bias, &b->l2p_bias);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_sv_az_el_encode_internal(sbp_encode_ctx_t *ctx,
                                  const sbp_sv_az_el_t *msg) {
  if (!sbp_v4_gnss_signal_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->az)) {
    return false;
  }
  if (!sbp_s8_encode(ctx, &msg->el)) {
    return false;
  }
  return true;
}

s8 sbp_sv_az_el_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                       const sbp_sv_az_el_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_sv_az_el_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_sv_az_el_decode_internal(sbp_decode_ctx_t *ctx, sbp_sv_az_el_t *msg) {
  if (!sbp_v4_gnss_signal_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->az)) {
    return false;
  }
  if (!sbp_s8_decode(ctx, &msg->el)) {
    return false;
  }
  return true;
}

s8 sbp_sv_az_el_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                       sbp_sv_az_el_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_sv_az_el_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_sv_az_el_cmp(const sbp_sv_az_el_t *a, const sbp_sv_az_el_t *b) {
  int ret = 0;

  ret = sbp_v4_gnss_signal_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->az, &b->az);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s8_cmp(&a->el, &b->el);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_sv_az_el_encode_internal(sbp_encode_ctx_t *ctx,
                                      const sbp_msg_sv_az_el_t *msg) {
  for (size_t i = 0; i < msg->n_azel; i++) {
    if (!sbp_sv_az_el_encode_internal(ctx, &msg->azel[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_sv_az_el_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                           const sbp_msg_sv_az_el_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_sv_az_el_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_sv_az_el_decode_internal(sbp_decode_ctx_t *ctx,
                                      sbp_msg_sv_az_el_t *msg) {
  msg->n_azel =
      (uint8_t)((ctx->buf_len - ctx->offset) / SBP_SV_AZ_EL_ENCODED_LEN);
  for (uint8_t i = 0; i < msg->n_azel; i++) {
    if (!sbp_sv_az_el_decode_internal(ctx, &msg->azel[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_sv_az_el_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                           sbp_msg_sv_az_el_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_sv_az_el_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_sv_az_el_send(sbp_state_t *s, u16 sender_id,
                         const sbp_msg_sv_az_el_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_sv_az_el_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SV_AZ_EL, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_sv_az_el_cmp(const sbp_msg_sv_az_el_t *a,
                         const sbp_msg_sv_az_el_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->n_azel, &b->n_azel);
  for (uint8_t i = 0; ret == 0 && i < a->n_azel; i++) {
    ret = sbp_sv_az_el_cmp(&a->azel[i], &b->azel[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_osr_encode_internal(sbp_encode_ctx_t *ctx,
                                 const sbp_msg_osr_t *msg) {
  if (!sbp_observation_header_encode_internal(ctx, &msg->header)) {
    return false;
  }
  for (size_t i = 0; i < msg->n_obs; i++) {
    if (!sbp_packed_osr_content_encode_internal(ctx, &msg->obs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_osr_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                      const sbp_msg_osr_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_osr_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_osr_decode_internal(sbp_decode_ctx_t *ctx, sbp_msg_osr_t *msg) {
  if (!sbp_observation_header_decode_internal(ctx, &msg->header)) {
    return false;
  }
  msg->n_obs = (uint8_t)((ctx->buf_len - ctx->offset) /
                         SBP_PACKED_OSR_CONTENT_ENCODED_LEN);
  for (uint8_t i = 0; i < msg->n_obs; i++) {
    if (!sbp_packed_osr_content_decode_internal(ctx, &msg->obs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_osr_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                      sbp_msg_osr_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_osr_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_osr_send(sbp_state_t *s, u16 sender_id, const sbp_msg_osr_t *msg,
                    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_osr_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_OSR, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_osr_cmp(const sbp_msg_osr_t *a, const sbp_msg_osr_t *b) {
  int ret = 0;

  ret = sbp_observation_header_cmp(&a->header, &b->header);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_obs, &b->n_obs);
  for (uint8_t i = 0; ret == 0 && i < a->n_obs; i++) {
    ret = sbp_packed_osr_content_cmp(&a->obs[i], &b->obs[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}
