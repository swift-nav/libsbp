/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/tracking.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <libsbp/internal/new/common.h>
#include <libsbp/internal/new/string/double_null_terminated.h>
#include <libsbp/internal/new/string/multipart.h>
#include <libsbp/internal/new/string/null_terminated.h>
#include <libsbp/internal/new/string/unterminated.h>
#include <libsbp/internal/new/tracking.h>
#include <libsbp/new/tracking.h>
#include <libsbp/sbp.h>

size_t sbp_packed_size_sbp_msg_tracking_state_detailed_dep_a_t(
    const sbp_msg_tracking_state_detailed_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u64(&msg->recv_time);
  packed_size += sbp_packed_size_sbp_sbp_gps_time_t(&msg->tot);
  packed_size += sbp_packed_size_u32(&msg->P);
  packed_size += sbp_packed_size_u16(&msg->P_std);
  packed_size += sbp_packed_size_sbp_carrier_phase_t(&msg->L);
  packed_size += sbp_packed_size_u8(&msg->cn0);
  packed_size += sbp_packed_size_u16(&msg->lock);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_s32(&msg->doppler);
  packed_size += sbp_packed_size_u16(&msg->doppler_std);
  packed_size += sbp_packed_size_u32(&msg->uptime);
  packed_size += sbp_packed_size_s16(&msg->clock_offset);
  packed_size += sbp_packed_size_s16(&msg->clock_drift);
  packed_size += sbp_packed_size_u16(&msg->corr_spacing);
  packed_size += sbp_packed_size_s8(&msg->acceleration);
  packed_size += sbp_packed_size_u8(&msg->sync_flags);
  packed_size += sbp_packed_size_u8(&msg->tow_flags);
  packed_size += sbp_packed_size_u8(&msg->track_flags);
  packed_size += sbp_packed_size_u8(&msg->nav_flags);
  packed_size += sbp_packed_size_u8(&msg->pset_flags);
  packed_size += sbp_packed_size_u8(&msg->misc_flags);
  return packed_size;
}

bool encode_sbp_msg_tracking_state_detailed_dep_a_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_tracking_state_detailed_dep_a_t *msg) {
  if (!encode_u64(ctx, &msg->recv_time)) {
    return false;
  }
  if (!encode_sbp_sbp_gps_time_t(ctx, &msg->tot)) {
    return false;
  }
  if (!encode_u32(ctx, &msg->P)) {
    return false;
  }
  if (!encode_u16(ctx, &msg->P_std)) {
    return false;
  }
  if (!encode_sbp_carrier_phase_t(ctx, &msg->L)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->cn0)) {
    return false;
  }
  if (!encode_u16(ctx, &msg->lock)) {
    return false;
  }
  if (!encode_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) {
    return false;
  }
  if (!encode_s32(ctx, &msg->doppler)) {
    return false;
  }
  if (!encode_u16(ctx, &msg->doppler_std)) {
    return false;
  }
  if (!encode_u32(ctx, &msg->uptime)) {
    return false;
  }
  if (!encode_s16(ctx, &msg->clock_offset)) {
    return false;
  }
  if (!encode_s16(ctx, &msg->clock_drift)) {
    return false;
  }
  if (!encode_u16(ctx, &msg->corr_spacing)) {
    return false;
  }
  if (!encode_s8(ctx, &msg->acceleration)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->sync_flags)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->tow_flags)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->track_flags)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->nav_flags)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->pset_flags)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->misc_flags)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_tracking_state_detailed_dep_a_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_tracking_state_detailed_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_tracking_state_detailed_dep_a_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_tracking_state_detailed_dep_a_t(
    sbp_decode_ctx_t *ctx, sbp_msg_tracking_state_detailed_dep_a_t *msg) {
  if (!decode_u64(ctx, &msg->recv_time)) {
    return false;
  }
  if (!decode_sbp_sbp_gps_time_t(ctx, &msg->tot)) {
    return false;
  }
  if (!decode_u32(ctx, &msg->P)) {
    return false;
  }
  if (!decode_u16(ctx, &msg->P_std)) {
    return false;
  }
  if (!decode_sbp_carrier_phase_t(ctx, &msg->L)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->cn0)) {
    return false;
  }
  if (!decode_u16(ctx, &msg->lock)) {
    return false;
  }
  if (!decode_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) {
    return false;
  }
  if (!decode_s32(ctx, &msg->doppler)) {
    return false;
  }
  if (!decode_u16(ctx, &msg->doppler_std)) {
    return false;
  }
  if (!decode_u32(ctx, &msg->uptime)) {
    return false;
  }
  if (!decode_s16(ctx, &msg->clock_offset)) {
    return false;
  }
  if (!decode_s16(ctx, &msg->clock_drift)) {
    return false;
  }
  if (!decode_u16(ctx, &msg->corr_spacing)) {
    return false;
  }
  if (!decode_s8(ctx, &msg->acceleration)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->sync_flags)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->tow_flags)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->track_flags)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->nav_flags)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->pset_flags)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->misc_flags)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_tracking_state_detailed_dep_a_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_tracking_state_detailed_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_tracking_state_detailed_dep_a_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_send_sbp_msg_tracking_state_detailed_dep_a_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_tracking_state_detailed_dep_a_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_tracking_state_detailed_dep_a_t(
      payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_TRACKING_STATE_DETAILED_DEP_A, sender_id,
                          payload_len, payload, write);
}

int sbp_cmp_sbp_msg_tracking_state_detailed_dep_a_t(
    const sbp_msg_tracking_state_detailed_dep_a_t *a,
    const sbp_msg_tracking_state_detailed_dep_a_t *b) {
  int ret = 0;

  ret = sbp_cmp_u64(&a->recv_time, &b->recv_time);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_sbp_gps_time_t(&a->tot, &b->tot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u32(&a->P, &b->P);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u16(&a->P_std, &b->P_std);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_carrier_phase_t(&a->L, &b->L);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->cn0, &b->cn0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u16(&a->lock, &b->lock);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_s32(&a->doppler, &b->doppler);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u16(&a->doppler_std, &b->doppler_std);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u32(&a->uptime, &b->uptime);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_s16(&a->clock_offset, &b->clock_offset);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_s16(&a->clock_drift, &b->clock_drift);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u16(&a->corr_spacing, &b->corr_spacing);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_s8(&a->acceleration, &b->acceleration);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->sync_flags, &b->sync_flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->tow_flags, &b->tow_flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->track_flags, &b->track_flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->nav_flags, &b->nav_flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->pset_flags, &b->pset_flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->misc_flags, &b->misc_flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_tracking_state_detailed_dep_t(
    const sbp_msg_tracking_state_detailed_dep_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u64(&msg->recv_time);
  packed_size += sbp_packed_size_sbp_gps_time_dep_t(&msg->tot);
  packed_size += sbp_packed_size_u32(&msg->P);
  packed_size += sbp_packed_size_u16(&msg->P_std);
  packed_size += sbp_packed_size_sbp_carrier_phase_t(&msg->L);
  packed_size += sbp_packed_size_u8(&msg->cn0);
  packed_size += sbp_packed_size_u16(&msg->lock);
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  packed_size += sbp_packed_size_s32(&msg->doppler);
  packed_size += sbp_packed_size_u16(&msg->doppler_std);
  packed_size += sbp_packed_size_u32(&msg->uptime);
  packed_size += sbp_packed_size_s16(&msg->clock_offset);
  packed_size += sbp_packed_size_s16(&msg->clock_drift);
  packed_size += sbp_packed_size_u16(&msg->corr_spacing);
  packed_size += sbp_packed_size_s8(&msg->acceleration);
  packed_size += sbp_packed_size_u8(&msg->sync_flags);
  packed_size += sbp_packed_size_u8(&msg->tow_flags);
  packed_size += sbp_packed_size_u8(&msg->track_flags);
  packed_size += sbp_packed_size_u8(&msg->nav_flags);
  packed_size += sbp_packed_size_u8(&msg->pset_flags);
  packed_size += sbp_packed_size_u8(&msg->misc_flags);
  return packed_size;
}

bool encode_sbp_msg_tracking_state_detailed_dep_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_tracking_state_detailed_dep_t *msg) {
  if (!encode_u64(ctx, &msg->recv_time)) {
    return false;
  }
  if (!encode_sbp_gps_time_dep_t(ctx, &msg->tot)) {
    return false;
  }
  if (!encode_u32(ctx, &msg->P)) {
    return false;
  }
  if (!encode_u16(ctx, &msg->P_std)) {
    return false;
  }
  if (!encode_sbp_carrier_phase_t(ctx, &msg->L)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->cn0)) {
    return false;
  }
  if (!encode_u16(ctx, &msg->lock)) {
    return false;
  }
  if (!encode_sbp_gnss_signal_dep_t(ctx, &msg->sid)) {
    return false;
  }
  if (!encode_s32(ctx, &msg->doppler)) {
    return false;
  }
  if (!encode_u16(ctx, &msg->doppler_std)) {
    return false;
  }
  if (!encode_u32(ctx, &msg->uptime)) {
    return false;
  }
  if (!encode_s16(ctx, &msg->clock_offset)) {
    return false;
  }
  if (!encode_s16(ctx, &msg->clock_drift)) {
    return false;
  }
  if (!encode_u16(ctx, &msg->corr_spacing)) {
    return false;
  }
  if (!encode_s8(ctx, &msg->acceleration)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->sync_flags)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->tow_flags)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->track_flags)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->nav_flags)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->pset_flags)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->misc_flags)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_tracking_state_detailed_dep_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_tracking_state_detailed_dep_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_tracking_state_detailed_dep_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_tracking_state_detailed_dep_t(
    sbp_decode_ctx_t *ctx, sbp_msg_tracking_state_detailed_dep_t *msg) {
  if (!decode_u64(ctx, &msg->recv_time)) {
    return false;
  }
  if (!decode_sbp_gps_time_dep_t(ctx, &msg->tot)) {
    return false;
  }
  if (!decode_u32(ctx, &msg->P)) {
    return false;
  }
  if (!decode_u16(ctx, &msg->P_std)) {
    return false;
  }
  if (!decode_sbp_carrier_phase_t(ctx, &msg->L)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->cn0)) {
    return false;
  }
  if (!decode_u16(ctx, &msg->lock)) {
    return false;
  }
  if (!decode_sbp_gnss_signal_dep_t(ctx, &msg->sid)) {
    return false;
  }
  if (!decode_s32(ctx, &msg->doppler)) {
    return false;
  }
  if (!decode_u16(ctx, &msg->doppler_std)) {
    return false;
  }
  if (!decode_u32(ctx, &msg->uptime)) {
    return false;
  }
  if (!decode_s16(ctx, &msg->clock_offset)) {
    return false;
  }
  if (!decode_s16(ctx, &msg->clock_drift)) {
    return false;
  }
  if (!decode_u16(ctx, &msg->corr_spacing)) {
    return false;
  }
  if (!decode_s8(ctx, &msg->acceleration)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->sync_flags)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->tow_flags)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->track_flags)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->nav_flags)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->pset_flags)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->misc_flags)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_tracking_state_detailed_dep_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_tracking_state_detailed_dep_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_tracking_state_detailed_dep_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_send_sbp_msg_tracking_state_detailed_dep_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_tracking_state_detailed_dep_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_tracking_state_detailed_dep_t(
      payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_TRACKING_STATE_DETAILED_DEP, sender_id,
                          payload_len, payload, write);
}

int sbp_cmp_sbp_msg_tracking_state_detailed_dep_t(
    const sbp_msg_tracking_state_detailed_dep_t *a,
    const sbp_msg_tracking_state_detailed_dep_t *b) {
  int ret = 0;

  ret = sbp_cmp_u64(&a->recv_time, &b->recv_time);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_gps_time_dep_t(&a->tot, &b->tot);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u32(&a->P, &b->P);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u16(&a->P_std, &b->P_std);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_carrier_phase_t(&a->L, &b->L);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->cn0, &b->cn0);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u16(&a->lock, &b->lock);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_gnss_signal_dep_t(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_s32(&a->doppler, &b->doppler);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u16(&a->doppler_std, &b->doppler_std);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u32(&a->uptime, &b->uptime);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_s16(&a->clock_offset, &b->clock_offset);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_s16(&a->clock_drift, &b->clock_drift);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u16(&a->corr_spacing, &b->corr_spacing);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_s8(&a->acceleration, &b->acceleration);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->sync_flags, &b->sync_flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->tow_flags, &b->tow_flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->track_flags, &b->track_flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->nav_flags, &b->nav_flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->pset_flags, &b->pset_flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->misc_flags, &b->misc_flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_tracking_channel_state_t(
    const sbp_tracking_channel_state_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_u8(&msg->fcn);
  packed_size += sbp_packed_size_u8(&msg->cn0);
  return packed_size;
}

bool encode_sbp_tracking_channel_state_t(
    sbp_encode_ctx_t *ctx, const sbp_tracking_channel_state_t *msg) {
  if (!encode_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->fcn)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->cn0)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_tracking_channel_state_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_tracking_channel_state_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_tracking_channel_state_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_tracking_channel_state_t(sbp_decode_ctx_t *ctx,
                                         sbp_tracking_channel_state_t *msg) {
  if (!decode_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->fcn)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->cn0)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_tracking_channel_state_t(const uint8_t *buf, uint8_t len,
                                           uint8_t *n_read,
                                           sbp_tracking_channel_state_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_tracking_channel_state_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_tracking_channel_state_t(
    const sbp_tracking_channel_state_t *a,
    const sbp_tracking_channel_state_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->fcn, &b->fcn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->cn0, &b->cn0);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_tracking_state_t(
    const sbp_msg_tracking_state_t *msg) {
  size_t packed_size = 0;
  packed_size += (msg->n_states * sbp_packed_size_sbp_tracking_channel_state_t(
                                      &msg->states[0]));
  return packed_size;
}

bool encode_sbp_msg_tracking_state_t(sbp_encode_ctx_t *ctx,
                                     const sbp_msg_tracking_state_t *msg) {
  for (uint8_t i = 0; ret == 0 && i < msg->n_states; i++) {
    if (!encode_sbp_tracking_channel_state_t(ctx, &msg->states[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_encode_sbp_msg_tracking_state_t(uint8_t *buf, uint8_t len,
                                       uint8_t *n_written,
                                       const sbp_msg_tracking_state_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_tracking_state_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_tracking_state_t(sbp_decode_ctx_t *ctx,
                                     sbp_msg_tracking_state_t *msg) {
  msg->n_states =
      (uint8_t)((ctx->buf_len - ctx->offset) /
                sbp_packed_size_sbp_tracking_channel_state_t(&msg->states[0]));
  for (uint8_t i = 0; i < msg->n_states; i++) {
    if (!decode_sbp_tracking_channel_state_t(ctx, &msg->states[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_decode_sbp_msg_tracking_state_t(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_msg_tracking_state_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_tracking_state_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_send_sbp_msg_tracking_state_t(struct sbp_state *s, u16 sender_id,
                                     const sbp_msg_tracking_state_t *msg,
                                     sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_tracking_state_t(payload, sizeof(payload),
                                               &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_TRACKING_STATE, sender_id, payload_len,
                          payload, write);
}

int sbp_cmp_sbp_msg_tracking_state_t(const sbp_msg_tracking_state_t *a,
                                     const sbp_msg_tracking_state_t *b) {
  int ret = 0;

  ret = sbp_cmp_u8(&a->n_states, &b->n_states);
  for (uint8_t i = 0; ret == 0 && i < a->n_states; i++) {
    ret = sbp_cmp_sbp_tracking_channel_state_t(&a->states[i], &b->states[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_measurement_state_t(
    const sbp_measurement_state_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->mesid);
  packed_size += sbp_packed_size_u8(&msg->cn0);
  return packed_size;
}

bool encode_sbp_measurement_state_t(sbp_encode_ctx_t *ctx,
                                    const sbp_measurement_state_t *msg) {
  if (!encode_sbp_sbp_gnss_signal_t(ctx, &msg->mesid)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->cn0)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_measurement_state_t(uint8_t *buf, uint8_t len,
                                      uint8_t *n_written,
                                      const sbp_measurement_state_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_measurement_state_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_measurement_state_t(sbp_decode_ctx_t *ctx,
                                    sbp_measurement_state_t *msg) {
  if (!decode_sbp_sbp_gnss_signal_t(ctx, &msg->mesid)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->cn0)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_measurement_state_t(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_measurement_state_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_measurement_state_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_measurement_state_t(const sbp_measurement_state_t *a,
                                    const sbp_measurement_state_t *b) {
  int ret = 0;

  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->mesid, &b->mesid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->cn0, &b->cn0);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_measurement_state_t(
    const sbp_msg_measurement_state_t *msg) {
  size_t packed_size = 0;
  packed_size += (msg->n_states *
                  sbp_packed_size_sbp_measurement_state_t(&msg->states[0]));
  return packed_size;
}

bool encode_sbp_msg_measurement_state_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_measurement_state_t *msg) {
  for (uint8_t i = 0; ret == 0 && i < msg->n_states; i++) {
    if (!encode_sbp_measurement_state_t(ctx, &msg->states[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_encode_sbp_msg_measurement_state_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_measurement_state_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_measurement_state_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_measurement_state_t(sbp_decode_ctx_t *ctx,
                                        sbp_msg_measurement_state_t *msg) {
  msg->n_states =
      (uint8_t)((ctx->buf_len - ctx->offset) /
                sbp_packed_size_sbp_measurement_state_t(&msg->states[0]));
  for (uint8_t i = 0; i < msg->n_states; i++) {
    if (!decode_sbp_measurement_state_t(ctx, &msg->states[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_decode_sbp_msg_measurement_state_t(const uint8_t *buf, uint8_t len,
                                          uint8_t *n_read,
                                          sbp_msg_measurement_state_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_measurement_state_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_send_sbp_msg_measurement_state_t(struct sbp_state *s, u16 sender_id,
                                        const sbp_msg_measurement_state_t *msg,
                                        sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_measurement_state_t(payload, sizeof(payload),
                                                  &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_MEASUREMENT_STATE, sender_id, payload_len,
                          payload, write);
}

int sbp_cmp_sbp_msg_measurement_state_t(const sbp_msg_measurement_state_t *a,
                                        const sbp_msg_measurement_state_t *b) {
  int ret = 0;

  ret = sbp_cmp_u8(&a->n_states, &b->n_states);
  for (uint8_t i = 0; ret == 0 && i < a->n_states; i++) {
    ret = sbp_cmp_sbp_measurement_state_t(&a->states[i], &b->states[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_tracking_channel_correlation_t(
    const sbp_tracking_channel_correlation_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_s16(&msg->I);
  packed_size += sbp_packed_size_s16(&msg->Q);
  return packed_size;
}

bool encode_sbp_tracking_channel_correlation_t(
    sbp_encode_ctx_t *ctx, const sbp_tracking_channel_correlation_t *msg) {
  if (!encode_s16(ctx, &msg->I)) {
    return false;
  }
  if (!encode_s16(ctx, &msg->Q)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_tracking_channel_correlation_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_tracking_channel_correlation_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_tracking_channel_correlation_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_tracking_channel_correlation_t(
    sbp_decode_ctx_t *ctx, sbp_tracking_channel_correlation_t *msg) {
  if (!decode_s16(ctx, &msg->I)) {
    return false;
  }
  if (!decode_s16(ctx, &msg->Q)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_tracking_channel_correlation_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_tracking_channel_correlation_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_tracking_channel_correlation_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_tracking_channel_correlation_t(
    const sbp_tracking_channel_correlation_t *a,
    const sbp_tracking_channel_correlation_t *b) {
  int ret = 0;

  ret = sbp_cmp_s16(&a->I, &b->I);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_s16(&a->Q, &b->Q);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_tracking_iq_t(const sbp_msg_tracking_iq_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->channel);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size +=
      (3 * sbp_packed_size_sbp_tracking_channel_correlation_t(&msg->corrs[0]));
  return packed_size;
}

bool encode_sbp_msg_tracking_iq_t(sbp_encode_ctx_t *ctx,
                                  const sbp_msg_tracking_iq_t *msg) {
  if (!encode_u8(ctx, &msg->channel)) {
    return false;
  }
  if (!encode_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) {
    return false;
  }
  for (uint8_t i = 0; ret == 0 && i < 3; i++) {
    if (!encode_sbp_tracking_channel_correlation_t(ctx, &msg->corrs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_encode_sbp_msg_tracking_iq_t(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_msg_tracking_iq_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_tracking_iq_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_tracking_iq_t(sbp_decode_ctx_t *ctx,
                                  sbp_msg_tracking_iq_t *msg) {
  if (!decode_u8(ctx, &msg->channel)) {
    return false;
  }
  if (!decode_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) {
    return false;
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!decode_sbp_tracking_channel_correlation_t(ctx, &msg->corrs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_decode_sbp_msg_tracking_iq_t(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_msg_tracking_iq_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_tracking_iq_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_send_sbp_msg_tracking_iq_t(struct sbp_state *s, u16 sender_id,
                                  const sbp_msg_tracking_iq_t *msg,
                                  sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_tracking_iq_t(payload, sizeof(payload),
                                            &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_TRACKING_IQ, sender_id, payload_len,
                          payload, write);
}

int sbp_cmp_sbp_msg_tracking_iq_t(const sbp_msg_tracking_iq_t *a,
                                  const sbp_msg_tracking_iq_t *b) {
  int ret = 0;

  ret = sbp_cmp_u8(&a->channel, &b->channel);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < 3; i++) {
    ret =
        sbp_cmp_sbp_tracking_channel_correlation_t(&a->corrs[i], &b->corrs[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_tracking_channel_correlation_dep_t(
    const sbp_tracking_channel_correlation_dep_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_s32(&msg->I);
  packed_size += sbp_packed_size_s32(&msg->Q);
  return packed_size;
}

bool encode_sbp_tracking_channel_correlation_dep_t(
    sbp_encode_ctx_t *ctx, const sbp_tracking_channel_correlation_dep_t *msg) {
  if (!encode_s32(ctx, &msg->I)) {
    return false;
  }
  if (!encode_s32(ctx, &msg->Q)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_tracking_channel_correlation_dep_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_tracking_channel_correlation_dep_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_tracking_channel_correlation_dep_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_tracking_channel_correlation_dep_t(
    sbp_decode_ctx_t *ctx, sbp_tracking_channel_correlation_dep_t *msg) {
  if (!decode_s32(ctx, &msg->I)) {
    return false;
  }
  if (!decode_s32(ctx, &msg->Q)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_tracking_channel_correlation_dep_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_tracking_channel_correlation_dep_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_tracking_channel_correlation_dep_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_tracking_channel_correlation_dep_t(
    const sbp_tracking_channel_correlation_dep_t *a,
    const sbp_tracking_channel_correlation_dep_t *b) {
  int ret = 0;

  ret = sbp_cmp_s32(&a->I, &b->I);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_s32(&a->Q, &b->Q);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_tracking_iq_dep_b_t(
    const sbp_msg_tracking_iq_dep_b_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->channel);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += (3 * sbp_packed_size_sbp_tracking_channel_correlation_dep_t(
                          &msg->corrs[0]));
  return packed_size;
}

bool encode_sbp_msg_tracking_iq_dep_b_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_tracking_iq_dep_b_t *msg) {
  if (!encode_u8(ctx, &msg->channel)) {
    return false;
  }
  if (!encode_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) {
    return false;
  }
  for (uint8_t i = 0; ret == 0 && i < 3; i++) {
    if (!encode_sbp_tracking_channel_correlation_dep_t(ctx, &msg->corrs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_encode_sbp_msg_tracking_iq_dep_b_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_tracking_iq_dep_b_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_tracking_iq_dep_b_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_tracking_iq_dep_b_t(sbp_decode_ctx_t *ctx,
                                        sbp_msg_tracking_iq_dep_b_t *msg) {
  if (!decode_u8(ctx, &msg->channel)) {
    return false;
  }
  if (!decode_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) {
    return false;
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!decode_sbp_tracking_channel_correlation_dep_t(ctx, &msg->corrs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_decode_sbp_msg_tracking_iq_dep_b_t(const uint8_t *buf, uint8_t len,
                                          uint8_t *n_read,
                                          sbp_msg_tracking_iq_dep_b_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_tracking_iq_dep_b_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_send_sbp_msg_tracking_iq_dep_b_t(struct sbp_state *s, u16 sender_id,
                                        const sbp_msg_tracking_iq_dep_b_t *msg,
                                        sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_tracking_iq_dep_b_t(payload, sizeof(payload),
                                                  &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_TRACKING_IQ_DEP_B, sender_id, payload_len,
                          payload, write);
}

int sbp_cmp_sbp_msg_tracking_iq_dep_b_t(const sbp_msg_tracking_iq_dep_b_t *a,
                                        const sbp_msg_tracking_iq_dep_b_t *b) {
  int ret = 0;

  ret = sbp_cmp_u8(&a->channel, &b->channel);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < 3; i++) {
    ret = sbp_cmp_sbp_tracking_channel_correlation_dep_t(&a->corrs[i],
                                                         &b->corrs[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_tracking_iq_dep_a_t(
    const sbp_msg_tracking_iq_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->channel);
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  packed_size += (3 * sbp_packed_size_sbp_tracking_channel_correlation_dep_t(
                          &msg->corrs[0]));
  return packed_size;
}

bool encode_sbp_msg_tracking_iq_dep_a_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_tracking_iq_dep_a_t *msg) {
  if (!encode_u8(ctx, &msg->channel)) {
    return false;
  }
  if (!encode_sbp_gnss_signal_dep_t(ctx, &msg->sid)) {
    return false;
  }
  for (uint8_t i = 0; ret == 0 && i < 3; i++) {
    if (!encode_sbp_tracking_channel_correlation_dep_t(ctx, &msg->corrs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_encode_sbp_msg_tracking_iq_dep_a_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_tracking_iq_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_tracking_iq_dep_a_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_tracking_iq_dep_a_t(sbp_decode_ctx_t *ctx,
                                        sbp_msg_tracking_iq_dep_a_t *msg) {
  if (!decode_u8(ctx, &msg->channel)) {
    return false;
  }
  if (!decode_sbp_gnss_signal_dep_t(ctx, &msg->sid)) {
    return false;
  }
  for (uint8_t i = 0; i < 3; i++) {
    if (!decode_sbp_tracking_channel_correlation_dep_t(ctx, &msg->corrs[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_decode_sbp_msg_tracking_iq_dep_a_t(const uint8_t *buf, uint8_t len,
                                          uint8_t *n_read,
                                          sbp_msg_tracking_iq_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_tracking_iq_dep_a_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_send_sbp_msg_tracking_iq_dep_a_t(struct sbp_state *s, u16 sender_id,
                                        const sbp_msg_tracking_iq_dep_a_t *msg,
                                        sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_tracking_iq_dep_a_t(payload, sizeof(payload),
                                                  &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_TRACKING_IQ_DEP_A, sender_id, payload_len,
                          payload, write);
}

int sbp_cmp_sbp_msg_tracking_iq_dep_a_t(const sbp_msg_tracking_iq_dep_a_t *a,
                                        const sbp_msg_tracking_iq_dep_a_t *b) {
  int ret = 0;

  ret = sbp_cmp_u8(&a->channel, &b->channel);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_gnss_signal_dep_t(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < 3; i++) {
    ret = sbp_cmp_sbp_tracking_channel_correlation_dep_t(&a->corrs[i],
                                                         &b->corrs[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_tracking_channel_state_dep_a_t(
    const sbp_tracking_channel_state_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->state);
  packed_size += sbp_packed_size_u8(&msg->prn);
  packed_size += sbp_packed_size_float(&msg->cn0);
  return packed_size;
}

bool encode_sbp_tracking_channel_state_dep_a_t(
    sbp_encode_ctx_t *ctx, const sbp_tracking_channel_state_dep_a_t *msg) {
  if (!encode_u8(ctx, &msg->state)) {
    return false;
  }
  if (!encode_u8(ctx, &msg->prn)) {
    return false;
  }
  if (!encode_float(ctx, &msg->cn0)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_tracking_channel_state_dep_a_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_tracking_channel_state_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_tracking_channel_state_dep_a_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_tracking_channel_state_dep_a_t(
    sbp_decode_ctx_t *ctx, sbp_tracking_channel_state_dep_a_t *msg) {
  if (!decode_u8(ctx, &msg->state)) {
    return false;
  }
  if (!decode_u8(ctx, &msg->prn)) {
    return false;
  }
  if (!decode_float(ctx, &msg->cn0)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_tracking_channel_state_dep_a_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_tracking_channel_state_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_tracking_channel_state_dep_a_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_tracking_channel_state_dep_a_t(
    const sbp_tracking_channel_state_dep_a_t *a,
    const sbp_tracking_channel_state_dep_a_t *b) {
  int ret = 0;

  ret = sbp_cmp_u8(&a->state, &b->state);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_u8(&a->prn, &b->prn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->cn0, &b->cn0);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_tracking_state_dep_a_t(
    const sbp_msg_tracking_state_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size +=
      (msg->n_states *
       sbp_packed_size_sbp_tracking_channel_state_dep_a_t(&msg->states[0]));
  return packed_size;
}

bool encode_sbp_msg_tracking_state_dep_a_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_tracking_state_dep_a_t *msg) {
  for (uint8_t i = 0; ret == 0 && i < msg->n_states; i++) {
    if (!encode_sbp_tracking_channel_state_dep_a_t(ctx, &msg->states[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_encode_sbp_msg_tracking_state_dep_a_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_tracking_state_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_tracking_state_dep_a_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_tracking_state_dep_a_t(
    sbp_decode_ctx_t *ctx, sbp_msg_tracking_state_dep_a_t *msg) {
  msg->n_states = (uint8_t)(
      (ctx->buf_len - ctx->offset) /
      sbp_packed_size_sbp_tracking_channel_state_dep_a_t(&msg->states[0]));
  for (uint8_t i = 0; i < msg->n_states; i++) {
    if (!decode_sbp_tracking_channel_state_dep_a_t(ctx, &msg->states[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_decode_sbp_msg_tracking_state_dep_a_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_tracking_state_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_tracking_state_dep_a_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_send_sbp_msg_tracking_state_dep_a_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_tracking_state_dep_a_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_tracking_state_dep_a_t(payload, sizeof(payload),
                                                     &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_TRACKING_STATE_DEP_A, sender_id,
                          payload_len, payload, write);
}

int sbp_cmp_sbp_msg_tracking_state_dep_a_t(
    const sbp_msg_tracking_state_dep_a_t *a,
    const sbp_msg_tracking_state_dep_a_t *b) {
  int ret = 0;

  ret = sbp_cmp_u8(&a->n_states, &b->n_states);
  for (uint8_t i = 0; ret == 0 && i < a->n_states; i++) {
    ret = sbp_cmp_sbp_tracking_channel_state_dep_a_t(&a->states[i],
                                                     &b->states[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_tracking_channel_state_dep_b_t(
    const sbp_tracking_channel_state_dep_b_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->state);
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  packed_size += sbp_packed_size_float(&msg->cn0);
  return packed_size;
}

bool encode_sbp_tracking_channel_state_dep_b_t(
    sbp_encode_ctx_t *ctx, const sbp_tracking_channel_state_dep_b_t *msg) {
  if (!encode_u8(ctx, &msg->state)) {
    return false;
  }
  if (!encode_sbp_gnss_signal_dep_t(ctx, &msg->sid)) {
    return false;
  }
  if (!encode_float(ctx, &msg->cn0)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_tracking_channel_state_dep_b_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_tracking_channel_state_dep_b_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_tracking_channel_state_dep_b_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_tracking_channel_state_dep_b_t(
    sbp_decode_ctx_t *ctx, sbp_tracking_channel_state_dep_b_t *msg) {
  if (!decode_u8(ctx, &msg->state)) {
    return false;
  }
  if (!decode_sbp_gnss_signal_dep_t(ctx, &msg->sid)) {
    return false;
  }
  if (!decode_float(ctx, &msg->cn0)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_tracking_channel_state_dep_b_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_tracking_channel_state_dep_b_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_tracking_channel_state_dep_b_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_tracking_channel_state_dep_b_t(
    const sbp_tracking_channel_state_dep_b_t *a,
    const sbp_tracking_channel_state_dep_b_t *b) {
  int ret = 0;

  ret = sbp_cmp_u8(&a->state, &b->state);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_sbp_gnss_signal_dep_t(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_cmp_float(&a->cn0, &b->cn0);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_tracking_state_dep_b_t(
    const sbp_msg_tracking_state_dep_b_t *msg) {
  size_t packed_size = 0;
  packed_size +=
      (msg->n_states *
       sbp_packed_size_sbp_tracking_channel_state_dep_b_t(&msg->states[0]));
  return packed_size;
}

bool encode_sbp_msg_tracking_state_dep_b_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_tracking_state_dep_b_t *msg) {
  for (uint8_t i = 0; ret == 0 && i < msg->n_states; i++) {
    if (!encode_sbp_tracking_channel_state_dep_b_t(ctx, &msg->states[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_encode_sbp_msg_tracking_state_dep_b_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_tracking_state_dep_b_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_tracking_state_dep_b_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_tracking_state_dep_b_t(
    sbp_decode_ctx_t *ctx, sbp_msg_tracking_state_dep_b_t *msg) {
  msg->n_states = (uint8_t)(
      (ctx->buf_len - ctx->offset) /
      sbp_packed_size_sbp_tracking_channel_state_dep_b_t(&msg->states[0]));
  for (uint8_t i = 0; i < msg->n_states; i++) {
    if (!decode_sbp_tracking_channel_state_dep_b_t(ctx, &msg->states[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_decode_sbp_msg_tracking_state_dep_b_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_tracking_state_dep_b_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_tracking_state_dep_b_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_send_sbp_msg_tracking_state_dep_b_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_tracking_state_dep_b_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_tracking_state_dep_b_t(payload, sizeof(payload),
                                                     &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_TRACKING_STATE_DEP_B, sender_id,
                          payload_len, payload, write);
}

int sbp_cmp_sbp_msg_tracking_state_dep_b_t(
    const sbp_msg_tracking_state_dep_b_t *a,
    const sbp_msg_tracking_state_dep_b_t *b) {
  int ret = 0;

  ret = sbp_cmp_u8(&a->n_states, &b->n_states);
  for (uint8_t i = 0; ret == 0 && i < a->n_states; i++) {
    ret = sbp_cmp_sbp_tracking_channel_state_dep_b_t(&a->states[i],
                                                     &b->states[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}
