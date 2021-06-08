#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <libsbp/sbp.h>
#include <libsbp/internal/new/common.h>
#include <libsbp/new/observation.h>
#include <libsbp/internal/new/observation.h>
#include <libsbp/internal/new/string/multipart.h>
#include <libsbp/internal/new/string/null_terminated.h>
#include <libsbp/internal/new/string/double_null_terminated.h>
#include <libsbp/internal/new/string/unterminated.h>

size_t sbp_packed_size_sbp_observation_header_t(const sbp_observation_header_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_sbp_gps_time_t(&msg->t);
  packed_size += sbp_packed_size_u8(&msg->n_obs);
  return packed_size;
}

bool encode_sbp_observation_header_t(sbp_encode_ctx_t *ctx, const sbp_observation_header_t *msg)
{
  if (!encode_sbp_sbp_gps_time_t(ctx, &msg->t)) { return false; }
  if (!encode_u8(ctx, &msg->n_obs)) { return false; }
  return true;
}

s8 sbp_encode_sbp_observation_header_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_observation_header_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_observation_header_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_observation_header_t(sbp_decode_ctx_t *ctx, sbp_observation_header_t *msg)
{
  if (!decode_sbp_sbp_gps_time_t(ctx, &msg->t)) { return false; }
  if (!decode_u8(ctx, &msg->n_obs)) { return false; }
  return true;
}

s8 sbp_decode_sbp_observation_header_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_observation_header_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_observation_header_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_observation_header_t(const sbp_observation_header_t *a, const sbp_observation_header_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_sbp_gps_time_t(&a->t, &b->t);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_obs, &b->n_obs);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_doppler_t(const sbp_doppler_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_s16(&msg->i);
  packed_size += sbp_packed_size_u8(&msg->f);
  return packed_size;
}

bool encode_sbp_doppler_t(sbp_encode_ctx_t *ctx, const sbp_doppler_t *msg)
{
  if (!encode_s16(ctx, &msg->i)) { return false; }
  if (!encode_u8(ctx, &msg->f)) { return false; }
  return true;
}

s8 sbp_encode_sbp_doppler_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_doppler_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_doppler_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_doppler_t(sbp_decode_ctx_t *ctx, sbp_doppler_t *msg)
{
  if (!decode_s16(ctx, &msg->i)) { return false; }
  if (!decode_u8(ctx, &msg->f)) { return false; }
  return true;
}

s8 sbp_decode_sbp_doppler_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_doppler_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_doppler_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_doppler_t(const sbp_doppler_t *a, const sbp_doppler_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_s16(&a->i, &b->i);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->f, &b->f);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_packed_obs_content_t(const sbp_packed_obs_content_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->P);
  packed_size += sbp_packed_size_sbp_carrier_phase_t(&msg->L);
  packed_size += sbp_packed_size_sbp_doppler_t(&msg->D);
  packed_size += sbp_packed_size_u8(&msg->cn0);
  packed_size += sbp_packed_size_u8(&msg->lock);
  packed_size += sbp_packed_size_u8(&msg->flags);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  return packed_size;
}

bool encode_sbp_packed_obs_content_t(sbp_encode_ctx_t *ctx, const sbp_packed_obs_content_t *msg)
{
  if (!encode_u32(ctx, &msg->P)) { return false; }
  if (!encode_sbp_carrier_phase_t(ctx, &msg->L)) { return false; }
  if (!encode_sbp_doppler_t(ctx, &msg->D)) { return false; }
  if (!encode_u8(ctx, &msg->cn0)) { return false; }
  if (!encode_u8(ctx, &msg->lock)) { return false; }
  if (!encode_u8(ctx, &msg->flags)) { return false; }
  if (!encode_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  return true;
}

s8 sbp_encode_sbp_packed_obs_content_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_packed_obs_content_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_packed_obs_content_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_packed_obs_content_t(sbp_decode_ctx_t *ctx, sbp_packed_obs_content_t *msg)
{
  if (!decode_u32(ctx, &msg->P)) { return false; }
  if (!decode_sbp_carrier_phase_t(ctx, &msg->L)) { return false; }
  if (!decode_sbp_doppler_t(ctx, &msg->D)) { return false; }
  if (!decode_u8(ctx, &msg->cn0)) { return false; }
  if (!decode_u8(ctx, &msg->lock)) { return false; }
  if (!decode_u8(ctx, &msg->flags)) { return false; }
  if (!decode_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  return true;
}

s8 sbp_decode_sbp_packed_obs_content_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_packed_obs_content_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_packed_obs_content_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_packed_obs_content_t(const sbp_packed_obs_content_t *a, const sbp_packed_obs_content_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->P, &b->P);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_carrier_phase_t(&a->L, &b->L);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_doppler_t(&a->D, &b->D);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->cn0, &b->cn0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->lock, &b->lock);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_obs_t(const sbp_msg_obs_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_observation_header_t(&msg->header);
  packed_size += (msg->n_obs * sbp_packed_size_sbp_packed_obs_content_t(&msg->obs[0]));
  return packed_size;
}

bool encode_sbp_msg_obs_t(sbp_encode_ctx_t *ctx, const sbp_msg_obs_t *msg)
{
  if (!encode_sbp_observation_header_t(ctx, &msg->header)) { return false; }
  for (uint8_t i = 0; i < msg->n_obs; i++)
  {
    if (!encode_sbp_packed_obs_content_t(ctx, &msg->obs[i])) { return false; }
  }
  return true;
}

s8 sbp_encode_sbp_msg_obs_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_obs_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_obs_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_obs_t(sbp_decode_ctx_t *ctx, sbp_msg_obs_t *msg)
{
  if (!decode_sbp_observation_header_t(ctx, &msg->header)) { return false; }
    msg->n_obs = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_packed_obs_content_t(&msg->obs[0]));
  for (uint8_t i = 0; i < msg->n_obs; i++) {
    if (!decode_sbp_packed_obs_content_t(ctx, &msg->obs[i])) { return false; }
  }
  return true;
}

s8 sbp_decode_sbp_msg_obs_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_obs_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_obs_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_obs_t(struct sbp_state *s, u16 sender_id, const sbp_msg_obs_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_obs_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_payload_send(s, SBP_MSG_OBS, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_obs_t(const sbp_msg_obs_t *a, const sbp_msg_obs_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_observation_header_t(&a->header, &b->header);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_obs, &b->n_obs);
  for (uint8_t i = 0; i < a->n_obs && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_packed_obs_content_t(&a->obs[i], &b->obs[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_sv_az_el_t(const sbp_sv_az_el_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_u8(&msg->az);
  packed_size += sbp_packed_size_s8(&msg->el);
  return packed_size;
}

bool encode_sbp_sv_az_el_t(sbp_encode_ctx_t *ctx, const sbp_sv_az_el_t *msg)
{
  if (!encode_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!encode_u8(ctx, &msg->az)) { return false; }
  if (!encode_s8(ctx, &msg->el)) { return false; }
  return true;
}

s8 sbp_encode_sbp_sv_az_el_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_sv_az_el_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_sv_az_el_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_sv_az_el_t(sbp_decode_ctx_t *ctx, sbp_sv_az_el_t *msg)
{
  if (!decode_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!decode_u8(ctx, &msg->az)) { return false; }
  if (!decode_s8(ctx, &msg->el)) { return false; }
  return true;
}

s8 sbp_decode_sbp_sv_az_el_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_sv_az_el_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_sv_az_el_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_sv_az_el_t(const sbp_sv_az_el_t *a, const sbp_sv_az_el_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->az, &b->az);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s8(&a->el, &b->el);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_sv_az_el_t(const sbp_msg_sv_az_el_t *msg) {
  size_t packed_size = 0;
  packed_size += (msg->n_azel * sbp_packed_size_sbp_sv_az_el_t(&msg->azel[0]));
  return packed_size;
}

bool encode_sbp_msg_sv_az_el_t(sbp_encode_ctx_t *ctx, const sbp_msg_sv_az_el_t *msg)
{
  for (uint8_t i = 0; i < msg->n_azel; i++)
  {
    if (!encode_sbp_sv_az_el_t(ctx, &msg->azel[i])) { return false; }
  }
  return true;
}

s8 sbp_encode_sbp_msg_sv_az_el_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_sv_az_el_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_sv_az_el_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_sv_az_el_t(sbp_decode_ctx_t *ctx, sbp_msg_sv_az_el_t *msg)
{
    msg->n_azel = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_sv_az_el_t(&msg->azel[0]));
  for (uint8_t i = 0; i < msg->n_azel; i++) {
    if (!decode_sbp_sv_az_el_t(ctx, &msg->azel[i])) { return false; }
  }
  return true;
}

s8 sbp_decode_sbp_msg_sv_az_el_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_sv_az_el_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_sv_az_el_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_sv_az_el_t(struct sbp_state *s, u16 sender_id, const sbp_msg_sv_az_el_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_sv_az_el_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_payload_send(s, SBP_MSG_SV_AZ_EL, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_sv_az_el_t(const sbp_msg_sv_az_el_t *a, const sbp_msg_sv_az_el_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->n_azel, &b->n_azel);
  for (uint8_t i = 0; i < a->n_azel && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_sv_az_el_t(&a->azel[i], &b->azel[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}
