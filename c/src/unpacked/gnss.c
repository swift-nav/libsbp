#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <libsbp/sbp.h>
#include <libsbp/internal/unpacked/common.h>
#include <libsbp/unpacked/gnss.h>
#include <libsbp/internal/unpacked/gnss.h>
#include <libsbp/internal/unpacked/string/multipart.h>
#include <libsbp/internal/unpacked/string/null_terminated.h>
#include <libsbp/internal/unpacked/string/sequence.h>
#include <libsbp/internal/unpacked/string/unterminated.h>
#include <libsbp/internal/unpacked/string/binary.h>
                                                                                                              
size_t sbp_packed_size_sbp_sbp_gnss_signal_t(const sbp_sbp_gnss_signal_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->sat);
  packed_size += sbp_packed_size_u8(&msg->code);
  return packed_size;
}

bool pack_sbp_sbp_gnss_signal_t(sbp_pack_ctx_t *ctx, const sbp_sbp_gnss_signal_t *msg)
{
  if (!pack_u8(ctx, &msg->sat)) { return false; }
  if (!pack_u8(ctx, &msg->code)) { return false; }
  return true;
}

s8 sbp_pack_sbp_sbp_gnss_signal_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_sbp_gnss_signal_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_sbp_gnss_signal_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_sbp_gnss_signal_t(sbp_unpack_ctx_t *ctx, sbp_sbp_gnss_signal_t *msg)
{
  if (!unpack_u8(ctx, &msg->sat)) { return false; }
  if (!unpack_u8(ctx, &msg->code)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_sbp_gnss_signal_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_sbp_gnss_signal_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_sbp_gnss_signal_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_sbp_gnss_signal_t(const sbp_sbp_gnss_signal_t *a, const sbp_sbp_gnss_signal_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->sat, &b->sat);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->code, &b->code);
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_sv_id_t(const sbp_sv_id_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->satId);
  packed_size += sbp_packed_size_u8(&msg->constellation);
  return packed_size;
}

bool pack_sbp_sv_id_t(sbp_pack_ctx_t *ctx, const sbp_sv_id_t *msg)
{
  if (!pack_u8(ctx, &msg->satId)) { return false; }
  if (!pack_u8(ctx, &msg->constellation)) { return false; }
  return true;
}

s8 sbp_pack_sbp_sv_id_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_sv_id_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_sv_id_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_sv_id_t(sbp_unpack_ctx_t *ctx, sbp_sv_id_t *msg)
{
  if (!unpack_u8(ctx, &msg->satId)) { return false; }
  if (!unpack_u8(ctx, &msg->constellation)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_sv_id_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_sv_id_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_sv_id_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_sv_id_t(const sbp_sv_id_t *a, const sbp_sv_id_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->satId, &b->satId);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->constellation, &b->constellation);
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_gnss_signal_dep_t(const sbp_gnss_signal_dep_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u16(&msg->sat);
  packed_size += sbp_packed_size_u8(&msg->code);
  packed_size += sbp_packed_size_u8(&msg->reserved);
  return packed_size;
}

bool pack_sbp_gnss_signal_dep_t(sbp_pack_ctx_t *ctx, const sbp_gnss_signal_dep_t *msg)
{
  if (!pack_u16(ctx, &msg->sat)) { return false; }
  if (!pack_u8(ctx, &msg->code)) { return false; }
  if (!pack_u8(ctx, &msg->reserved)) { return false; }
  return true;
}

s8 sbp_pack_sbp_gnss_signal_dep_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_gnss_signal_dep_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_gnss_signal_dep_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_gnss_signal_dep_t(sbp_unpack_ctx_t *ctx, sbp_gnss_signal_dep_t *msg)
{
  if (!unpack_u16(ctx, &msg->sat)) { return false; }
  if (!unpack_u8(ctx, &msg->code)) { return false; }
  if (!unpack_u8(ctx, &msg->reserved)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_gnss_signal_dep_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_gnss_signal_dep_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_gnss_signal_dep_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_gnss_signal_dep_t(const sbp_gnss_signal_dep_t *a, const sbp_gnss_signal_dep_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u16(&a->sat, &b->sat);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->code, &b->code);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->reserved, &b->reserved);
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_gps_time_dep_t(const sbp_gps_time_dep_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u16(&msg->wn);
  return packed_size;
}

bool pack_sbp_gps_time_dep_t(sbp_pack_ctx_t *ctx, const sbp_gps_time_dep_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_u16(ctx, &msg->wn)) { return false; }
  return true;
}

s8 sbp_pack_sbp_gps_time_dep_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_gps_time_dep_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_gps_time_dep_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_gps_time_dep_t(sbp_unpack_ctx_t *ctx, sbp_gps_time_dep_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_u16(ctx, &msg->wn)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_gps_time_dep_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_gps_time_dep_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_gps_time_dep_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_gps_time_dep_t(const sbp_gps_time_dep_t *a, const sbp_gps_time_dep_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->wn, &b->wn);
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_gps_time_sec_t(const sbp_gps_time_sec_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u16(&msg->wn);
  return packed_size;
}

bool pack_sbp_gps_time_sec_t(sbp_pack_ctx_t *ctx, const sbp_gps_time_sec_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_u16(ctx, &msg->wn)) { return false; }
  return true;
}

s8 sbp_pack_sbp_gps_time_sec_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_gps_time_sec_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_gps_time_sec_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_gps_time_sec_t(sbp_unpack_ctx_t *ctx, sbp_gps_time_sec_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_u16(ctx, &msg->wn)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_gps_time_sec_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_gps_time_sec_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_gps_time_sec_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_gps_time_sec_t(const sbp_gps_time_sec_t *a, const sbp_gps_time_sec_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->wn, &b->wn);
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_sbp_gps_time_t(const sbp_sbp_gps_time_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->ns_residual);
  packed_size += sbp_packed_size_u16(&msg->wn);
  return packed_size;
}

bool pack_sbp_sbp_gps_time_t(sbp_pack_ctx_t *ctx, const sbp_sbp_gps_time_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_s32(ctx, &msg->ns_residual)) { return false; }
  if (!pack_u16(ctx, &msg->wn)) { return false; }
  return true;
}

s8 sbp_pack_sbp_sbp_gps_time_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_sbp_gps_time_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_sbp_gps_time_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_sbp_gps_time_t(sbp_unpack_ctx_t *ctx, sbp_sbp_gps_time_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_s32(ctx, &msg->ns_residual)) { return false; }
  if (!unpack_u16(ctx, &msg->wn)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_sbp_gps_time_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_sbp_gps_time_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_sbp_gps_time_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_sbp_gps_time_t(const sbp_sbp_gps_time_t *a, const sbp_sbp_gps_time_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->ns_residual, &b->ns_residual);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->wn, &b->wn);
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_carrier_phase_t(const sbp_carrier_phase_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_s32(&msg->i);
  packed_size += sbp_packed_size_u8(&msg->f);
  return packed_size;
}

bool pack_sbp_carrier_phase_t(sbp_pack_ctx_t *ctx, const sbp_carrier_phase_t *msg)
{
  if (!pack_s32(ctx, &msg->i)) { return false; }
  if (!pack_u8(ctx, &msg->f)) { return false; }
  return true;
}

s8 sbp_pack_sbp_carrier_phase_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_carrier_phase_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_carrier_phase_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_carrier_phase_t(sbp_unpack_ctx_t *ctx, sbp_carrier_phase_t *msg)
{
  if (!unpack_s32(ctx, &msg->i)) { return false; }
  if (!unpack_u8(ctx, &msg->f)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_carrier_phase_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_carrier_phase_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_carrier_phase_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_carrier_phase_t(const sbp_carrier_phase_t *a, const sbp_carrier_phase_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_s32(&a->i, &b->i);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->f, &b->f);
  if (ret != 0) { return ret; }
  return ret;
}
