#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <libsbp/sbp.h>
#include <libsbp/internal/unpacked/common.h>
#include <libsbp/unpacked/flash.h>
#include <libsbp/internal/unpacked/flash.h>
#include <libsbp/internal/unpacked/string/multipart.h>
#include <libsbp/internal/unpacked/string/null_terminated.h>
#include <libsbp/internal/unpacked/string/double_null_terminated.h>
#include <libsbp/internal/unpacked/string/unterminated.h>
#include <libsbp/internal/unpacked/string/binary.h>

size_t sbp_packed_size_sbp_msg_flash_program_t(const sbp_msg_flash_program_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->target);
  packed_size += ( 3 * sbp_packed_size_u8(&msg->addr_start[0]));
  packed_size += sbp_packed_size_u8(&msg->addr_len);
  packed_size += (msg->addr_len * sbp_packed_size_u8(&msg->data[0]));
  return packed_size;
}

bool pack_sbp_msg_flash_program_t(sbp_pack_ctx_t *ctx, const sbp_msg_flash_program_t *msg)
{
  if (!pack_u8(ctx, &msg->target)) { return false; }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!pack_u8(ctx, &msg->addr_start[i])) { return false; }
  }
  if (!pack_u8(ctx, &msg->addr_len)) { return false; }
  for (uint8_t i = 0; i < msg->addr_len; i++)
  {
    if (!pack_u8(ctx, &msg->data[i])) { return false; }
  }
  return true;
}

s8 sbp_pack_sbp_msg_flash_program_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_flash_program_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_flash_program_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_flash_program_t(sbp_unpack_ctx_t *ctx, sbp_msg_flash_program_t *msg)
{
  if (!unpack_u8(ctx, &msg->target)) { return false; }
  for (uint8_t i = 0; i < 3; i++) {
    if (!unpack_u8(ctx, &msg->addr_start[i])) { return false; }
  }
  if (!unpack_u8(ctx, &msg->addr_len)) { return false; }
    msg->addr_len = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_u8(&msg->data[0]));
  for (uint8_t i = 0; i < msg->addr_len; i++) {
    if (!unpack_u8(ctx, &msg->data[i])) { return false; }
  }
  return true;
}

s8 sbp_unpack_sbp_msg_flash_program_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_flash_program_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_flash_program_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_flash_program_t(struct sbp_state *s, u16 sender_id, const sbp_msg_flash_program_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_flash_program_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_message(s, SBP_MSG_FLASH_PROGRAM, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_flash_program_t(const sbp_msg_flash_program_t *a, const sbp_msg_flash_program_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->target, &b->target);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 3 && ret == 0; i++)
  {
    ret = sbp_cmp_u8(&a->addr_start[i], &b->addr_start[i]);
  }
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->addr_len, &b->addr_len);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->addr_len, &b->addr_len);
  for (uint8_t i = 0; i < a->addr_len && ret == 0; i++)
  {
    ret = sbp_cmp_u8(&a->data[i], &b->data[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_flash_done_t(const sbp_msg_flash_done_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->response);
  return packed_size;
}

bool pack_sbp_msg_flash_done_t(sbp_pack_ctx_t *ctx, const sbp_msg_flash_done_t *msg)
{
  if (!pack_u8(ctx, &msg->response)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_flash_done_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_flash_done_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_flash_done_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_flash_done_t(sbp_unpack_ctx_t *ctx, sbp_msg_flash_done_t *msg)
{
  if (!unpack_u8(ctx, &msg->response)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_flash_done_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_flash_done_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_flash_done_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_flash_done_t(struct sbp_state *s, u16 sender_id, const sbp_msg_flash_done_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_flash_done_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_message(s, SBP_MSG_FLASH_DONE, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_flash_done_t(const sbp_msg_flash_done_t *a, const sbp_msg_flash_done_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->response, &b->response);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_flash_read_req_t(const sbp_msg_flash_read_req_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->target);
  packed_size += ( 3 * sbp_packed_size_u8(&msg->addr_start[0]));
  packed_size += sbp_packed_size_u8(&msg->addr_len);
  return packed_size;
}

bool pack_sbp_msg_flash_read_req_t(sbp_pack_ctx_t *ctx, const sbp_msg_flash_read_req_t *msg)
{
  if (!pack_u8(ctx, &msg->target)) { return false; }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!pack_u8(ctx, &msg->addr_start[i])) { return false; }
  }
  if (!pack_u8(ctx, &msg->addr_len)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_flash_read_req_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_flash_read_req_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_flash_read_req_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_flash_read_req_t(sbp_unpack_ctx_t *ctx, sbp_msg_flash_read_req_t *msg)
{
  if (!unpack_u8(ctx, &msg->target)) { return false; }
  for (uint8_t i = 0; i < 3; i++) {
    if (!unpack_u8(ctx, &msg->addr_start[i])) { return false; }
  }
  if (!unpack_u8(ctx, &msg->addr_len)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_flash_read_req_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_flash_read_req_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_flash_read_req_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_flash_read_req_t(struct sbp_state *s, u16 sender_id, const sbp_msg_flash_read_req_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_flash_read_req_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_message(s, SBP_MSG_FLASH_READ_REQ, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_flash_read_req_t(const sbp_msg_flash_read_req_t *a, const sbp_msg_flash_read_req_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->target, &b->target);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 3 && ret == 0; i++)
  {
    ret = sbp_cmp_u8(&a->addr_start[i], &b->addr_start[i]);
  }
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->addr_len, &b->addr_len);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_flash_read_resp_t(const sbp_msg_flash_read_resp_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->target);
  packed_size += ( 3 * sbp_packed_size_u8(&msg->addr_start[0]));
  packed_size += sbp_packed_size_u8(&msg->addr_len);
  return packed_size;
}

bool pack_sbp_msg_flash_read_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_flash_read_resp_t *msg)
{
  if (!pack_u8(ctx, &msg->target)) { return false; }
  for (uint8_t i = 0; i < 3; i++)
  {
    if (!pack_u8(ctx, &msg->addr_start[i])) { return false; }
  }
  if (!pack_u8(ctx, &msg->addr_len)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_flash_read_resp_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_flash_read_resp_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_flash_read_resp_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_flash_read_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_flash_read_resp_t *msg)
{
  if (!unpack_u8(ctx, &msg->target)) { return false; }
  for (uint8_t i = 0; i < 3; i++) {
    if (!unpack_u8(ctx, &msg->addr_start[i])) { return false; }
  }
  if (!unpack_u8(ctx, &msg->addr_len)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_flash_read_resp_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_flash_read_resp_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_flash_read_resp_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_flash_read_resp_t(struct sbp_state *s, u16 sender_id, const sbp_msg_flash_read_resp_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_flash_read_resp_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_message(s, SBP_MSG_FLASH_READ_RESP, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_flash_read_resp_t(const sbp_msg_flash_read_resp_t *a, const sbp_msg_flash_read_resp_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->target, &b->target);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 3 && ret == 0; i++)
  {
    ret = sbp_cmp_u8(&a->addr_start[i], &b->addr_start[i]);
  }
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->addr_len, &b->addr_len);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_flash_erase_t(const sbp_msg_flash_erase_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->target);
  packed_size += sbp_packed_size_u32(&msg->sector_num);
  return packed_size;
}

bool pack_sbp_msg_flash_erase_t(sbp_pack_ctx_t *ctx, const sbp_msg_flash_erase_t *msg)
{
  if (!pack_u8(ctx, &msg->target)) { return false; }
  if (!pack_u32(ctx, &msg->sector_num)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_flash_erase_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_flash_erase_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_flash_erase_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_flash_erase_t(sbp_unpack_ctx_t *ctx, sbp_msg_flash_erase_t *msg)
{
  if (!unpack_u8(ctx, &msg->target)) { return false; }
  if (!unpack_u32(ctx, &msg->sector_num)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_flash_erase_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_flash_erase_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_flash_erase_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_flash_erase_t(struct sbp_state *s, u16 sender_id, const sbp_msg_flash_erase_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_flash_erase_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_message(s, SBP_MSG_FLASH_ERASE, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_flash_erase_t(const sbp_msg_flash_erase_t *a, const sbp_msg_flash_erase_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->target, &b->target);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->sector_num, &b->sector_num);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_stm_flash_lock_sector_t(const sbp_msg_stm_flash_lock_sector_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->sector);
  return packed_size;
}

bool pack_sbp_msg_stm_flash_lock_sector_t(sbp_pack_ctx_t *ctx, const sbp_msg_stm_flash_lock_sector_t *msg)
{
  if (!pack_u32(ctx, &msg->sector)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_stm_flash_lock_sector_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_stm_flash_lock_sector_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_stm_flash_lock_sector_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_stm_flash_lock_sector_t(sbp_unpack_ctx_t *ctx, sbp_msg_stm_flash_lock_sector_t *msg)
{
  if (!unpack_u32(ctx, &msg->sector)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_stm_flash_lock_sector_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_stm_flash_lock_sector_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_stm_flash_lock_sector_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_stm_flash_lock_sector_t(struct sbp_state *s, u16 sender_id, const sbp_msg_stm_flash_lock_sector_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_stm_flash_lock_sector_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_message(s, SBP_MSG_STM_FLASH_LOCK_SECTOR, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_stm_flash_lock_sector_t(const sbp_msg_stm_flash_lock_sector_t *a, const sbp_msg_stm_flash_lock_sector_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->sector, &b->sector);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_stm_flash_unlock_sector_t(const sbp_msg_stm_flash_unlock_sector_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->sector);
  return packed_size;
}

bool pack_sbp_msg_stm_flash_unlock_sector_t(sbp_pack_ctx_t *ctx, const sbp_msg_stm_flash_unlock_sector_t *msg)
{
  if (!pack_u32(ctx, &msg->sector)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_stm_flash_unlock_sector_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_stm_flash_unlock_sector_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_stm_flash_unlock_sector_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_stm_flash_unlock_sector_t(sbp_unpack_ctx_t *ctx, sbp_msg_stm_flash_unlock_sector_t *msg)
{
  if (!unpack_u32(ctx, &msg->sector)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_stm_flash_unlock_sector_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_stm_flash_unlock_sector_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_stm_flash_unlock_sector_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_stm_flash_unlock_sector_t(struct sbp_state *s, u16 sender_id, const sbp_msg_stm_flash_unlock_sector_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_stm_flash_unlock_sector_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_message(s, SBP_MSG_STM_FLASH_UNLOCK_SECTOR, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_stm_flash_unlock_sector_t(const sbp_msg_stm_flash_unlock_sector_t *a, const sbp_msg_stm_flash_unlock_sector_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->sector, &b->sector);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_stm_unique_id_req_t(const sbp_msg_stm_unique_id_req_t *msg) {
  (void)msg;
  return 0;
}

bool pack_sbp_msg_stm_unique_id_req_t(sbp_pack_ctx_t *ctx, const sbp_msg_stm_unique_id_req_t *msg)
{
  (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_pack_sbp_msg_stm_unique_id_req_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_stm_unique_id_req_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_stm_unique_id_req_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_stm_unique_id_req_t(sbp_unpack_ctx_t *ctx, sbp_msg_stm_unique_id_req_t *msg)
{
    (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_unpack_sbp_msg_stm_unique_id_req_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_stm_unique_id_req_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_stm_unique_id_req_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_stm_unique_id_req_t(struct sbp_state *s, u16 sender_id, const sbp_msg_stm_unique_id_req_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_stm_unique_id_req_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_message(s, SBP_MSG_STM_UNIQUE_ID_REQ, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_stm_unique_id_req_t(const sbp_msg_stm_unique_id_req_t *a, const sbp_msg_stm_unique_id_req_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}

size_t sbp_packed_size_sbp_msg_stm_unique_id_resp_t(const sbp_msg_stm_unique_id_resp_t *msg) {
  size_t packed_size = 0;
  packed_size += ( 12 * sbp_packed_size_u8(&msg->stm_id[0]));
  return packed_size;
}

bool pack_sbp_msg_stm_unique_id_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_stm_unique_id_resp_t *msg)
{
  for (uint8_t i = 0; i < 12; i++)
  {
    if (!pack_u8(ctx, &msg->stm_id[i])) { return false; }
  }
  return true;
}

s8 sbp_pack_sbp_msg_stm_unique_id_resp_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_stm_unique_id_resp_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_stm_unique_id_resp_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_stm_unique_id_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_stm_unique_id_resp_t *msg)
{
  for (uint8_t i = 0; i < 12; i++) {
    if (!unpack_u8(ctx, &msg->stm_id[i])) { return false; }
  }
  return true;
}

s8 sbp_unpack_sbp_msg_stm_unique_id_resp_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_stm_unique_id_resp_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_stm_unique_id_resp_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_stm_unique_id_resp_t(struct sbp_state *s, u16 sender_id, const sbp_msg_stm_unique_id_resp_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_stm_unique_id_resp_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_message(s, SBP_MSG_STM_UNIQUE_ID_RESP, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_stm_unique_id_resp_t(const sbp_msg_stm_unique_id_resp_t *a, const sbp_msg_stm_unique_id_resp_t *b) {
  int ret = 0;
  
  for (uint8_t i = 0; i < 12 && ret == 0; i++)
  {
    ret = sbp_cmp_u8(&a->stm_id[i], &b->stm_id[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_m25_flash_write_status_t(const sbp_msg_m25_flash_write_status_t *msg) {
  size_t packed_size = 0;
  packed_size += ( 1 * sbp_packed_size_u8(&msg->status[0]));
  return packed_size;
}

bool pack_sbp_msg_m25_flash_write_status_t(sbp_pack_ctx_t *ctx, const sbp_msg_m25_flash_write_status_t *msg)
{
  for (uint8_t i = 0; i < 1; i++)
  {
    if (!pack_u8(ctx, &msg->status[i])) { return false; }
  }
  return true;
}

s8 sbp_pack_sbp_msg_m25_flash_write_status_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_m25_flash_write_status_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_m25_flash_write_status_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_m25_flash_write_status_t(sbp_unpack_ctx_t *ctx, sbp_msg_m25_flash_write_status_t *msg)
{
  for (uint8_t i = 0; i < 1; i++) {
    if (!unpack_u8(ctx, &msg->status[i])) { return false; }
  }
  return true;
}

s8 sbp_unpack_sbp_msg_m25_flash_write_status_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_m25_flash_write_status_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_m25_flash_write_status_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_m25_flash_write_status_t(struct sbp_state *s, u16 sender_id, const sbp_msg_m25_flash_write_status_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_m25_flash_write_status_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_message(s, SBP_MSG_M25_FLASH_WRITE_STATUS, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_m25_flash_write_status_t(const sbp_msg_m25_flash_write_status_t *a, const sbp_msg_m25_flash_write_status_t *b) {
  int ret = 0;
  
  for (uint8_t i = 0; i < 1 && ret == 0; i++)
  {
    ret = sbp_cmp_u8(&a->status[i], &b->status[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}
