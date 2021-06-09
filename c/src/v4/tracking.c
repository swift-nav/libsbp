/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/tracking.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <libsbp/internal/v4/common.h>
#include <libsbp/internal/v4/string/double_null_terminated.h>
#include <libsbp/internal/v4/string/multipart.h>
#include <libsbp/internal/v4/string/null_terminated.h>
#include <libsbp/internal/v4/string/unterminated.h>
#include <libsbp/internal/v4/tracking.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/tracking.h>

size_t sbp_msg_tracking_state_detailed_dep_a_encoded_len(
    const sbp_msg_tracking_state_detailed_dep_a_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_u64_encoded_len(&msg->recv_time);
  encoded_len += sbp_sbp_gps_time_encoded_len(&msg->tot);
  encoded_len += sbp_u32_encoded_len(&msg->P);
  encoded_len += sbp_u16_encoded_len(&msg->P_std);
  encoded_len += sbp_carrier_phase_encoded_len(&msg->L);
  encoded_len += sbp_u8_encoded_len(&msg->cn0);
  encoded_len += sbp_u16_encoded_len(&msg->lock);
  encoded_len += sbp_sbp_gnss_signal_encoded_len(&msg->sid);
  encoded_len += sbp_s32_encoded_len(&msg->doppler);
  encoded_len += sbp_u16_encoded_len(&msg->doppler_std);
  encoded_len += sbp_u32_encoded_len(&msg->uptime);
  encoded_len += sbp_s16_encoded_len(&msg->clock_offset);
  encoded_len += sbp_s16_encoded_len(&msg->clock_drift);
  encoded_len += sbp_u16_encoded_len(&msg->corr_spacing);
  encoded_len += sbp_s8_encoded_len(&msg->acceleration);
  encoded_len += sbp_u8_encoded_len(&msg->sync_flags);
  encoded_len += sbp_u8_encoded_len(&msg->tow_flags);
  encoded_len += sbp_u8_encoded_len(&msg->track_flags);
  encoded_len += sbp_u8_encoded_len(&msg->nav_flags);
  encoded_len += sbp_u8_encoded_len(&msg->pset_flags);
  encoded_len += sbp_u8_encoded_len(&msg->misc_flags);
  return encoded_len;
}

bool sbp_msg_tracking_state_detailed_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_tracking_state_detailed_dep_a_t *msg) {
  if (!sbp_u64_encode(ctx, &msg->recv_time)) {
    return false;
  }
  if (!sbp_sbp_gps_time_encode_internal(ctx, &msg->tot)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->P)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->P_std)) {
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
  if (!sbp_sbp_gnss_signal_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->doppler)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->doppler_std)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->uptime)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->clock_offset)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->clock_drift)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->corr_spacing)) {
    return false;
  }
  if (!sbp_s8_encode(ctx, &msg->acceleration)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->sync_flags)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->tow_flags)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->track_flags)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->nav_flags)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->pset_flags)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->misc_flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_tracking_state_detailed_dep_a_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_tracking_state_detailed_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_tracking_state_detailed_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_tracking_state_detailed_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_tracking_state_detailed_dep_a_t *msg) {
  if (!sbp_u64_decode(ctx, &msg->recv_time)) {
    return false;
  }
  if (!sbp_sbp_gps_time_decode_internal(ctx, &msg->tot)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->P)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->P_std)) {
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
  if (!sbp_sbp_gnss_signal_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->doppler)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->doppler_std)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->uptime)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->clock_offset)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->clock_drift)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->corr_spacing)) {
    return false;
  }
  if (!sbp_s8_decode(ctx, &msg->acceleration)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->sync_flags)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->tow_flags)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->track_flags)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->nav_flags)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->pset_flags)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->misc_flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_tracking_state_detailed_dep_a_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_tracking_state_detailed_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_tracking_state_detailed_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_tracking_state_detailed_dep_a_send(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_tracking_state_detailed_dep_a_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_tracking_state_detailed_dep_a_encode(
      payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_TRACKING_STATE_DETAILED_DEP_A, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_tracking_state_detailed_dep_a_cmp(
    const sbp_msg_tracking_state_detailed_dep_a_t *a,
    const sbp_msg_tracking_state_detailed_dep_a_t *b) {
  int ret = 0;

  ret = sbp_u64_cmp(&a->recv_time, &b->recv_time);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_sbp_gps_time_cmp(&a->tot, &b->tot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->P, &b->P);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->P_std, &b->P_std);
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

  ret = sbp_sbp_gnss_signal_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->doppler, &b->doppler);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->doppler_std, &b->doppler_std);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->uptime, &b->uptime);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->clock_offset, &b->clock_offset);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->clock_drift, &b->clock_drift);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->corr_spacing, &b->corr_spacing);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s8_cmp(&a->acceleration, &b->acceleration);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->sync_flags, &b->sync_flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->tow_flags, &b->tow_flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->track_flags, &b->track_flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->nav_flags, &b->nav_flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->pset_flags, &b->pset_flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->misc_flags, &b->misc_flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_msg_tracking_state_detailed_dep_encoded_len(
    const sbp_msg_tracking_state_detailed_dep_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_u64_encoded_len(&msg->recv_time);
  encoded_len += sbp_gps_time_dep_encoded_len(&msg->tot);
  encoded_len += sbp_u32_encoded_len(&msg->P);
  encoded_len += sbp_u16_encoded_len(&msg->P_std);
  encoded_len += sbp_carrier_phase_encoded_len(&msg->L);
  encoded_len += sbp_u8_encoded_len(&msg->cn0);
  encoded_len += sbp_u16_encoded_len(&msg->lock);
  encoded_len += sbp_gnss_signal_dep_encoded_len(&msg->sid);
  encoded_len += sbp_s32_encoded_len(&msg->doppler);
  encoded_len += sbp_u16_encoded_len(&msg->doppler_std);
  encoded_len += sbp_u32_encoded_len(&msg->uptime);
  encoded_len += sbp_s16_encoded_len(&msg->clock_offset);
  encoded_len += sbp_s16_encoded_len(&msg->clock_drift);
  encoded_len += sbp_u16_encoded_len(&msg->corr_spacing);
  encoded_len += sbp_s8_encoded_len(&msg->acceleration);
  encoded_len += sbp_u8_encoded_len(&msg->sync_flags);
  encoded_len += sbp_u8_encoded_len(&msg->tow_flags);
  encoded_len += sbp_u8_encoded_len(&msg->track_flags);
  encoded_len += sbp_u8_encoded_len(&msg->nav_flags);
  encoded_len += sbp_u8_encoded_len(&msg->pset_flags);
  encoded_len += sbp_u8_encoded_len(&msg->misc_flags);
  return encoded_len;
}

bool sbp_msg_tracking_state_detailed_dep_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_tracking_state_detailed_dep_t *msg) {
  if (!sbp_u64_encode(ctx, &msg->recv_time)) {
    return false;
  }
  if (!sbp_gps_time_dep_encode_internal(ctx, &msg->tot)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->P)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->P_std)) {
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
  if (!sbp_s32_encode(ctx, &msg->doppler)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->doppler_std)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->uptime)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->clock_offset)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->clock_drift)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->corr_spacing)) {
    return false;
  }
  if (!sbp_s8_encode(ctx, &msg->acceleration)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->sync_flags)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->tow_flags)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->track_flags)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->nav_flags)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->pset_flags)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->misc_flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_tracking_state_detailed_dep_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_tracking_state_detailed_dep_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_tracking_state_detailed_dep_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_tracking_state_detailed_dep_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_tracking_state_detailed_dep_t *msg) {
  if (!sbp_u64_decode(ctx, &msg->recv_time)) {
    return false;
  }
  if (!sbp_gps_time_dep_decode_internal(ctx, &msg->tot)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->P)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->P_std)) {
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
  if (!sbp_s32_decode(ctx, &msg->doppler)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->doppler_std)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->uptime)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->clock_offset)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->clock_drift)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->corr_spacing)) {
    return false;
  }
  if (!sbp_s8_decode(ctx, &msg->acceleration)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->sync_flags)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->tow_flags)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->track_flags)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->nav_flags)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->pset_flags)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->misc_flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_tracking_state_detailed_dep_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_tracking_state_detailed_dep_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_tracking_state_detailed_dep_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_tracking_state_detailed_dep_send(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_tracking_state_detailed_dep_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_tracking_state_detailed_dep_encode(payload, sizeof(payload),
                                                      &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_TRACKING_STATE_DETAILED_DEP, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_tracking_state_detailed_dep_cmp(
    const sbp_msg_tracking_state_detailed_dep_t *a,
    const sbp_msg_tracking_state_detailed_dep_t *b) {
  int ret = 0;

  ret = sbp_u64_cmp(&a->recv_time, &b->recv_time);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_gps_time_dep_cmp(&a->tot, &b->tot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->P, &b->P);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->P_std, &b->P_std);
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

  ret = sbp_s32_cmp(&a->doppler, &b->doppler);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->doppler_std, &b->doppler_std);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->uptime, &b->uptime);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->clock_offset, &b->clock_offset);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->clock_drift, &b->clock_drift);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->corr_spacing, &b->corr_spacing);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s8_cmp(&a->acceleration, &b->acceleration);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->sync_flags, &b->sync_flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->tow_flags, &b->tow_flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->track_flags, &b->track_flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->nav_flags, &b->nav_flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->pset_flags, &b->pset_flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->misc_flags, &b->misc_flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_tracking_channel_state_encoded_len(
    const sbp_tracking_channel_state_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_sbp_gnss_signal_encoded_len(&msg->sid);
  encoded_len += sbp_u8_encoded_len(&msg->fcn);
  encoded_len += sbp_u8_encoded_len(&msg->cn0);
  return encoded_len;
}

bool sbp_tracking_channel_state_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_tracking_channel_state_t *msg) {
  if (!sbp_sbp_gnss_signal_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->fcn)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->cn0)) {
    return false;
  }
  return true;
}

s8 sbp_tracking_channel_state_encode(uint8_t *buf, uint8_t len,
                                     uint8_t *n_written,
                                     const sbp_tracking_channel_state_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_tracking_channel_state_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_tracking_channel_state_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_tracking_channel_state_t *msg) {
  if (!sbp_sbp_gnss_signal_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->fcn)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->cn0)) {
    return false;
  }
  return true;
}

s8 sbp_tracking_channel_state_decode(const uint8_t *buf, uint8_t len,
                                     uint8_t *n_read,
                                     sbp_tracking_channel_state_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_tracking_channel_state_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_tracking_channel_state_cmp(const sbp_tracking_channel_state_t *a,
                                   const sbp_tracking_channel_state_t *b) {
  int ret = 0;

  ret = sbp_sbp_gnss_signal_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->fcn, &b->fcn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->cn0, &b->cn0);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_msg_tracking_state_encoded_len(const sbp_msg_tracking_state_t *msg) {
  size_t encoded_len = 0;
  encoded_len +=
      (msg->n_states * sbp_tracking_channel_state_encoded_len(&msg->states[0]));
  return encoded_len;
}

bool sbp_msg_tracking_state_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_tracking_state_t *msg) {
  for (uint8_t i = 0; i < msg->n_states; i++) {
    if (!sbp_tracking_channel_state_encode_internal(ctx, &msg->states[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_tracking_state_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_msg_tracking_state_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_tracking_state_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_tracking_state_decode_internal(sbp_decode_ctx_t *ctx,
                                            sbp_msg_tracking_state_t *msg) {
  msg->n_states =
      (uint8_t)((ctx->buf_len - ctx->offset) /
                sbp_tracking_channel_state_encoded_len(&msg->states[0]));
  for (uint8_t i = 0; i < msg->n_states; i++) {
    if (!sbp_tracking_channel_state_decode_internal(ctx, &msg->states[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_tracking_state_decode(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read,
                                 sbp_msg_tracking_state_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_tracking_state_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_tracking_state_send(struct sbp_state *s, u16 sender_id,
                               const sbp_msg_tracking_state_t *msg,
                               sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_tracking_state_encode(payload, sizeof(payload), &payload_len,
                                         msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_TRACKING_STATE, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_tracking_state_cmp(const sbp_msg_tracking_state_t *a,
                               const sbp_msg_tracking_state_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->n_states, &b->n_states);
  for (uint8_t i = 0; ret == 0 && i < a->n_states; i++) {
    ret = sbp_tracking_channel_state_cmp(&a->states[i], &b->states[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_measurement_state_encoded_len(const sbp_measurement_state_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_sbp_gnss_signal_encoded_len(&msg->mesid);
  encoded_len += sbp_u8_encoded_len(&msg->cn0);
  return encoded_len;
}

bool sbp_measurement_state_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_measurement_state_t *msg) {
  if (!sbp_sbp_gnss_signal_encode_internal(ctx, &msg->mesid)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->cn0)) {
    return false;
  }
  return true;
}

s8 sbp_measurement_state_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                const sbp_measurement_state_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_measurement_state_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_measurement_state_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_measurement_state_t *msg) {
  if (!sbp_sbp_gnss_signal_decode_internal(ctx, &msg->mesid)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->cn0)) {
    return false;
  }
  return true;
}

s8 sbp_measurement_state_decode(const uint8_t *buf, uint8_t len,
                                uint8_t *n_read, sbp_measurement_state_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_measurement_state_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_measurement_state_cmp(const sbp_measurement_state_t *a,
                              const sbp_measurement_state_t *b) {
  int ret = 0;

  ret = sbp_sbp_gnss_signal_cmp(&a->mesid, &b->mesid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->cn0, &b->cn0);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_msg_measurement_state_encoded_len(
    const sbp_msg_measurement_state_t *msg) {
  size_t encoded_len = 0;
  encoded_len +=
      (msg->n_states * sbp_measurement_state_encoded_len(&msg->states[0]));
  return encoded_len;
}

bool sbp_msg_measurement_state_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_measurement_state_t *msg) {
  for (uint8_t i = 0; i < msg->n_states; i++) {
    if (!sbp_measurement_state_encode_internal(ctx, &msg->states[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_measurement_state_encode(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_msg_measurement_state_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_measurement_state_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_measurement_state_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_measurement_state_t *msg) {
  msg->n_states = (uint8_t)((ctx->buf_len - ctx->offset) /
                            sbp_measurement_state_encoded_len(&msg->states[0]));
  for (uint8_t i = 0; i < msg->n_states; i++) {
    if (!sbp_measurement_state_decode_internal(ctx, &msg->states[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_measurement_state_decode(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_msg_measurement_state_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_measurement_state_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_measurement_state_send(struct sbp_state *s, u16 sender_id,
                                  const sbp_msg_measurement_state_t *msg,
                                  sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_measurement_state_encode(payload, sizeof(payload),
                                            &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_MEASUREMENT_STATE, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_measurement_state_cmp(const sbp_msg_measurement_state_t *a,
                                  const sbp_msg_measurement_state_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->n_states, &b->n_states);
  for (uint8_t i = 0; ret == 0 && i < a->n_states; i++) {
    ret = sbp_measurement_state_cmp(&a->states[i], &b->states[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_tracking_channel_correlation_encoded_len(
    const sbp_tracking_channel_correlation_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_s16_encoded_len(&msg->I);
  encoded_len += sbp_s16_encoded_len(&msg->Q);
  return encoded_len;
}

bool sbp_tracking_channel_correlation_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_tracking_channel_correlation_t *msg) {
  if (!sbp_s16_encode(ctx, &msg->I)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->Q)) {
    return false;
  }
  return true;
}

s8 sbp_tracking_channel_correlation_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_tracking_channel_correlation_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_tracking_channel_correlation_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_tracking_channel_correlation_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_tracking_channel_correlation_t *msg) {
  if (!sbp_s16_decode(ctx, &msg->I)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->Q)) {
    return false;
  }
  return true;
}

s8 sbp_tracking_channel_correlation_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_tracking_channel_correlation_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_tracking_channel_correlation_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_tracking_channel_correlation_cmp(
    const sbp_tracking_channel_correlation_t *a,
    const sbp_tracking_channel_correlation_t *b) {
  int ret = 0;

  ret = sbp_s16_cmp(&a->I, &b->I);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->Q, &b->Q);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_msg_tracking_iq_encoded_len(const sbp_msg_tracking_iq_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_u8_encoded_len(&msg->channel);
  encoded_len += sbp_sbp_gnss_signal_encoded_len(&msg->sid);
  encoded_len +=
      (3 * sbp_tracking_channel_correlation_encoded_len(&msg->corrs[0]));
  return encoded_len;
}

bool sbp_msg_tracking_iq_encode_internal(sbp_encode_ctx_t *ctx,
                                         const sbp_msg_tracking_iq_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->channel)) {
    return false;
  }
  if (!sbp_sbp_gnss_signal_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_tracking_channel_correlation_encode_internal(ctx,
                                                          &msg->corrs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_tracking_iq_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                              const sbp_msg_tracking_iq_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_tracking_iq_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_tracking_iq_decode_internal(sbp_decode_ctx_t *ctx,
                                         sbp_msg_tracking_iq_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->channel)) {
    return false;
  }
  if (!sbp_sbp_gnss_signal_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_tracking_channel_correlation_decode_internal(ctx,
                                                          &msg->corrs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_tracking_iq_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                              sbp_msg_tracking_iq_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_tracking_iq_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_tracking_iq_send(struct sbp_state *s, u16 sender_id,
                            const sbp_msg_tracking_iq_t *msg,
                            sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_tracking_iq_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_TRACKING_IQ, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_tracking_iq_cmp(const sbp_msg_tracking_iq_t *a,
                            const sbp_msg_tracking_iq_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->channel, &b->channel);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_sbp_gnss_signal_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < 3; i++) {
    ret = sbp_tracking_channel_correlation_cmp(&a->corrs[i], &b->corrs[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_tracking_channel_correlation_dep_encoded_len(
    const sbp_tracking_channel_correlation_dep_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_s32_encoded_len(&msg->I);
  encoded_len += sbp_s32_encoded_len(&msg->Q);
  return encoded_len;
}

bool sbp_tracking_channel_correlation_dep_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_tracking_channel_correlation_dep_t *msg) {
  if (!sbp_s32_encode(ctx, &msg->I)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->Q)) {
    return false;
  }
  return true;
}

s8 sbp_tracking_channel_correlation_dep_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_tracking_channel_correlation_dep_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_tracking_channel_correlation_dep_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_tracking_channel_correlation_dep_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_tracking_channel_correlation_dep_t *msg) {
  if (!sbp_s32_decode(ctx, &msg->I)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->Q)) {
    return false;
  }
  return true;
}

s8 sbp_tracking_channel_correlation_dep_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_tracking_channel_correlation_dep_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_tracking_channel_correlation_dep_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_tracking_channel_correlation_dep_cmp(
    const sbp_tracking_channel_correlation_dep_t *a,
    const sbp_tracking_channel_correlation_dep_t *b) {
  int ret = 0;

  ret = sbp_s32_cmp(&a->I, &b->I);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->Q, &b->Q);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_msg_tracking_iq_dep_b_encoded_len(
    const sbp_msg_tracking_iq_dep_b_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_u8_encoded_len(&msg->channel);
  encoded_len += sbp_sbp_gnss_signal_encoded_len(&msg->sid);
  encoded_len +=
      (3 * sbp_tracking_channel_correlation_dep_encoded_len(&msg->corrs[0]));
  return encoded_len;
}

bool sbp_msg_tracking_iq_dep_b_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_tracking_iq_dep_b_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->channel)) {
    return false;
  }
  if (!sbp_sbp_gnss_signal_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_tracking_channel_correlation_dep_encode_internal(ctx,
                                                              &msg->corrs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_tracking_iq_dep_b_encode(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_msg_tracking_iq_dep_b_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_tracking_iq_dep_b_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_tracking_iq_dep_b_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_tracking_iq_dep_b_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->channel)) {
    return false;
  }
  if (!sbp_sbp_gnss_signal_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_tracking_channel_correlation_dep_decode_internal(ctx,
                                                              &msg->corrs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_tracking_iq_dep_b_decode(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_msg_tracking_iq_dep_b_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_tracking_iq_dep_b_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_tracking_iq_dep_b_send(struct sbp_state *s, u16 sender_id,
                                  const sbp_msg_tracking_iq_dep_b_t *msg,
                                  sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_tracking_iq_dep_b_encode(payload, sizeof(payload),
                                            &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_TRACKING_IQ_DEP_B, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_tracking_iq_dep_b_cmp(const sbp_msg_tracking_iq_dep_b_t *a,
                                  const sbp_msg_tracking_iq_dep_b_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->channel, &b->channel);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_sbp_gnss_signal_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < 3; i++) {
    ret = sbp_tracking_channel_correlation_dep_cmp(&a->corrs[i], &b->corrs[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_msg_tracking_iq_dep_a_encoded_len(
    const sbp_msg_tracking_iq_dep_a_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_u8_encoded_len(&msg->channel);
  encoded_len += sbp_gnss_signal_dep_encoded_len(&msg->sid);
  encoded_len +=
      (3 * sbp_tracking_channel_correlation_dep_encoded_len(&msg->corrs[0]));
  return encoded_len;
}

bool sbp_msg_tracking_iq_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_tracking_iq_dep_a_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->channel)) {
    return false;
  }
  if (!sbp_gnss_signal_dep_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_tracking_channel_correlation_dep_encode_internal(ctx,
                                                              &msg->corrs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_tracking_iq_dep_a_encode(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_msg_tracking_iq_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_tracking_iq_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_tracking_iq_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_tracking_iq_dep_a_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->channel)) {
    return false;
  }
  if (!sbp_gnss_signal_dep_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_tracking_channel_correlation_dep_decode_internal(ctx,
                                                              &msg->corrs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_tracking_iq_dep_a_decode(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_msg_tracking_iq_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_tracking_iq_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_tracking_iq_dep_a_send(struct sbp_state *s, u16 sender_id,
                                  const sbp_msg_tracking_iq_dep_a_t *msg,
                                  sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_tracking_iq_dep_a_encode(payload, sizeof(payload),
                                            &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_TRACKING_IQ_DEP_A, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_tracking_iq_dep_a_cmp(const sbp_msg_tracking_iq_dep_a_t *a,
                                  const sbp_msg_tracking_iq_dep_a_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->channel, &b->channel);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_gnss_signal_dep_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < 3; i++) {
    ret = sbp_tracking_channel_correlation_dep_cmp(&a->corrs[i], &b->corrs[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_tracking_channel_state_dep_a_encoded_len(
    const sbp_tracking_channel_state_dep_a_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_u8_encoded_len(&msg->state);
  encoded_len += sbp_u8_encoded_len(&msg->prn);
  encoded_len += sbp_float_encoded_len(&msg->cn0);
  return encoded_len;
}

bool sbp_tracking_channel_state_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_tracking_channel_state_dep_a_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->state)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->prn)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cn0)) {
    return false;
  }
  return true;
}

s8 sbp_tracking_channel_state_dep_a_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_tracking_channel_state_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_tracking_channel_state_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_tracking_channel_state_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_tracking_channel_state_dep_a_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->state)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->prn)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cn0)) {
    return false;
  }
  return true;
}

s8 sbp_tracking_channel_state_dep_a_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_tracking_channel_state_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_tracking_channel_state_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_tracking_channel_state_dep_a_cmp(
    const sbp_tracking_channel_state_dep_a_t *a,
    const sbp_tracking_channel_state_dep_a_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->state, &b->state);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->prn, &b->prn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cn0, &b->cn0);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_msg_tracking_state_dep_a_encoded_len(
    const sbp_msg_tracking_state_dep_a_t *msg) {
  size_t encoded_len = 0;
  encoded_len += (msg->n_states * sbp_tracking_channel_state_dep_a_encoded_len(
                                      &msg->states[0]));
  return encoded_len;
}

bool sbp_msg_tracking_state_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_tracking_state_dep_a_t *msg) {
  for (uint8_t i = 0; i < msg->n_states; i++) {
    if (!sbp_tracking_channel_state_dep_a_encode_internal(ctx,
                                                          &msg->states[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_tracking_state_dep_a_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_tracking_state_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_tracking_state_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_tracking_state_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_tracking_state_dep_a_t *msg) {
  msg->n_states =
      (uint8_t)((ctx->buf_len - ctx->offset) /
                sbp_tracking_channel_state_dep_a_encoded_len(&msg->states[0]));
  for (uint8_t i = 0; i < msg->n_states; i++) {
    if (!sbp_tracking_channel_state_dep_a_decode_internal(ctx,
                                                          &msg->states[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_tracking_state_dep_a_decode(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_msg_tracking_state_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_tracking_state_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_tracking_state_dep_a_send(struct sbp_state *s, u16 sender_id,
                                     const sbp_msg_tracking_state_dep_a_t *msg,
                                     sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_tracking_state_dep_a_encode(payload, sizeof(payload),
                                               &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_TRACKING_STATE_DEP_A, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_tracking_state_dep_a_cmp(const sbp_msg_tracking_state_dep_a_t *a,
                                     const sbp_msg_tracking_state_dep_a_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->n_states, &b->n_states);
  for (uint8_t i = 0; ret == 0 && i < a->n_states; i++) {
    ret = sbp_tracking_channel_state_dep_a_cmp(&a->states[i], &b->states[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_tracking_channel_state_dep_b_encoded_len(
    const sbp_tracking_channel_state_dep_b_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_u8_encoded_len(&msg->state);
  encoded_len += sbp_gnss_signal_dep_encoded_len(&msg->sid);
  encoded_len += sbp_float_encoded_len(&msg->cn0);
  return encoded_len;
}

bool sbp_tracking_channel_state_dep_b_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_tracking_channel_state_dep_b_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->state)) {
    return false;
  }
  if (!sbp_gnss_signal_dep_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cn0)) {
    return false;
  }
  return true;
}

s8 sbp_tracking_channel_state_dep_b_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_tracking_channel_state_dep_b_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_tracking_channel_state_dep_b_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_tracking_channel_state_dep_b_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_tracking_channel_state_dep_b_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->state)) {
    return false;
  }
  if (!sbp_gnss_signal_dep_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cn0)) {
    return false;
  }
  return true;
}

s8 sbp_tracking_channel_state_dep_b_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_tracking_channel_state_dep_b_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_tracking_channel_state_dep_b_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_tracking_channel_state_dep_b_cmp(
    const sbp_tracking_channel_state_dep_b_t *a,
    const sbp_tracking_channel_state_dep_b_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->state, &b->state);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_gnss_signal_dep_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cn0, &b->cn0);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_msg_tracking_state_dep_b_encoded_len(
    const sbp_msg_tracking_state_dep_b_t *msg) {
  size_t encoded_len = 0;
  encoded_len += (msg->n_states * sbp_tracking_channel_state_dep_b_encoded_len(
                                      &msg->states[0]));
  return encoded_len;
}

bool sbp_msg_tracking_state_dep_b_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_tracking_state_dep_b_t *msg) {
  for (uint8_t i = 0; i < msg->n_states; i++) {
    if (!sbp_tracking_channel_state_dep_b_encode_internal(ctx,
                                                          &msg->states[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_tracking_state_dep_b_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_tracking_state_dep_b_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_tracking_state_dep_b_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_tracking_state_dep_b_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_tracking_state_dep_b_t *msg) {
  msg->n_states =
      (uint8_t)((ctx->buf_len - ctx->offset) /
                sbp_tracking_channel_state_dep_b_encoded_len(&msg->states[0]));
  for (uint8_t i = 0; i < msg->n_states; i++) {
    if (!sbp_tracking_channel_state_dep_b_decode_internal(ctx,
                                                          &msg->states[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_tracking_state_dep_b_decode(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_msg_tracking_state_dep_b_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_tracking_state_dep_b_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_tracking_state_dep_b_send(struct sbp_state *s, u16 sender_id,
                                     const sbp_msg_tracking_state_dep_b_t *msg,
                                     sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_tracking_state_dep_b_encode(payload, sizeof(payload),
                                               &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_TRACKING_STATE_DEP_B, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_tracking_state_dep_b_cmp(const sbp_msg_tracking_state_dep_b_t *a,
                                     const sbp_msg_tracking_state_dep_b_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->n_states, &b->n_states);
  for (uint8_t i = 0; ret == 0 && i < a->n_states; i++) {
    ret = sbp_tracking_channel_state_dep_b_cmp(&a->states[i], &b->states[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}
