#ifndef LIBSBP_FLASH_PACKERS_H
#define LIBSBP_FLASH_PACKERS_H

#ifndef LIBSBP_FLASH_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/flash.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/base.h>
#include <libsbp/unpacked/common.h>
#include <libsbp/unpacked/string/unterminated.h>
#include <libsbp/unpacked/string/multipart.h>
#include <libsbp/unpacked/string/sequence.h>
#include <libsbp/unpacked/string/null_terminated.h>
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_flash_program_t(const sbp_msg_flash_program_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->target);
  packed_size += ( 3 * sbp_packed_size_u8(&msg->addr_start[0]));
  packed_size += sbp_packed_size_u8(&msg->addr_len);
  packed_size += (msg->addr_len * sbp_packed_size_u8(&msg->data[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_flash_program_t(sbp_pack_ctx_t *ctx, const sbp_msg_flash_program_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->target)) { return false; }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!sbp_pack_u8(ctx, &msg->addr_start[i])) { return false; }
  }
  if (!sbp_pack_u8(ctx, &msg->addr_len)) { return false; }
  for (uint8_t i = 0; i < msg->addr_len; i++)
  {
    if (!sbp_pack_u8(ctx, &msg->data[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_flash_program_t(sbp_unpack_ctx_t *ctx, sbp_msg_flash_program_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->target)) { return false; }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_unpack_u8(ctx, &msg->addr_start[i])) { return false; }
  }
  if (!sbp_unpack_u8(ctx, &msg->addr_len)) { return false; }
    msg->addr_len = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_u8(&msg->data[0]));
  for (uint8_t i = 0; i < msg->addr_len; i++) {
    if (!sbp_unpack_u8(ctx, &msg->data[i])) { return false; }
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_flash_done_t(const sbp_msg_flash_done_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->response);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_flash_done_t(sbp_pack_ctx_t *ctx, const sbp_msg_flash_done_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->response)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_flash_done_t(sbp_unpack_ctx_t *ctx, sbp_msg_flash_done_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->response)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_flash_read_req_t(const sbp_msg_flash_read_req_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->target);
  packed_size += ( 3 * sbp_packed_size_u8(&msg->addr_start[0]));
  packed_size += sbp_packed_size_u8(&msg->addr_len);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_flash_read_req_t(sbp_pack_ctx_t *ctx, const sbp_msg_flash_read_req_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->target)) { return false; }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!sbp_pack_u8(ctx, &msg->addr_start[i])) { return false; }
  }
  if (!sbp_pack_u8(ctx, &msg->addr_len)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_flash_read_req_t(sbp_unpack_ctx_t *ctx, sbp_msg_flash_read_req_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->target)) { return false; }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_unpack_u8(ctx, &msg->addr_start[i])) { return false; }
  }
  if (!sbp_unpack_u8(ctx, &msg->addr_len)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_flash_read_resp_t(const sbp_msg_flash_read_resp_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->target);
  packed_size += ( 3 * sbp_packed_size_u8(&msg->addr_start[0]));
  packed_size += sbp_packed_size_u8(&msg->addr_len);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_flash_read_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_flash_read_resp_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->target)) { return false; }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!sbp_pack_u8(ctx, &msg->addr_start[i])) { return false; }
  }
  if (!sbp_pack_u8(ctx, &msg->addr_len)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_flash_read_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_flash_read_resp_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->target)) { return false; }
  for (uint8_t i = 0; i < 3; i++) {
    if (!sbp_unpack_u8(ctx, &msg->addr_start[i])) { return false; }
  }
  if (!sbp_unpack_u8(ctx, &msg->addr_len)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_flash_erase_t(const sbp_msg_flash_erase_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->target);
  packed_size += sbp_packed_size_u32(&msg->sector_num);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_flash_erase_t(sbp_pack_ctx_t *ctx, const sbp_msg_flash_erase_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->target)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->sector_num)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_flash_erase_t(sbp_unpack_ctx_t *ctx, sbp_msg_flash_erase_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->target)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->sector_num)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_stm_flash_lock_sector_t(const sbp_msg_stm_flash_lock_sector_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->sector);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_stm_flash_lock_sector_t(sbp_pack_ctx_t *ctx, const sbp_msg_stm_flash_lock_sector_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->sector)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_stm_flash_lock_sector_t(sbp_unpack_ctx_t *ctx, sbp_msg_stm_flash_lock_sector_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->sector)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_stm_flash_unlock_sector_t(const sbp_msg_stm_flash_unlock_sector_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->sector);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_stm_flash_unlock_sector_t(sbp_pack_ctx_t *ctx, const sbp_msg_stm_flash_unlock_sector_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->sector)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_stm_flash_unlock_sector_t(sbp_unpack_ctx_t *ctx, sbp_msg_stm_flash_unlock_sector_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->sector)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_stm_unique_id_req_t(const sbp_msg_stm_unique_id_req_t *msg) {
  (void)msg;
  return 0;
}

static inline bool sbp_pack_sbp_msg_stm_unique_id_req_t(sbp_pack_ctx_t *ctx, const sbp_msg_stm_unique_id_req_t *msg)
{
  (void)ctx;
  (void)msg;
  return true;
  return true;
}

static inline bool sbp_unpack_sbp_msg_stm_unique_id_req_t(sbp_unpack_ctx_t *ctx, sbp_msg_stm_unique_id_req_t *msg)
{
    (void)ctx;
  (void)msg;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_stm_unique_id_resp_t(const sbp_msg_stm_unique_id_resp_t *msg) {
  size_t packed_size = 0;
  packed_size += ( 12 * sbp_packed_size_u8(&msg->stm_id[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_stm_unique_id_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_stm_unique_id_resp_t *msg)
{
  for (uint8_t i = 0; i < 12; i++)
  {
    if (!sbp_pack_u8(ctx, &msg->stm_id[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_stm_unique_id_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_stm_unique_id_resp_t *msg)
{
  for (uint8_t i = 0; i < 12; i++) {
    if (!sbp_unpack_u8(ctx, &msg->stm_id[i])) { return false; }
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_m25_flash_write_status_t(const sbp_msg_m25_flash_write_status_t *msg) {
  size_t packed_size = 0;
  packed_size += ( 1 * sbp_packed_size_u8(&msg->status[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_m25_flash_write_status_t(sbp_pack_ctx_t *ctx, const sbp_msg_m25_flash_write_status_t *msg)
{
  for (uint8_t i = 0; i < 1; i++)
  {
    if (!sbp_pack_u8(ctx, &msg->status[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_m25_flash_write_status_t(sbp_unpack_ctx_t *ctx, sbp_msg_m25_flash_write_status_t *msg)
{
  for (uint8_t i = 0; i < 1; i++) {
    if (!sbp_unpack_u8(ctx, &msg->status[i])) { return false; }
  }
  return true;
}

#endif
