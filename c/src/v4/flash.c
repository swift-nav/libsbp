/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/flash.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <libsbp/internal/v4/common.h>
#include <libsbp/internal/v4/flash.h>
#include <libsbp/internal/v4/string/double_null_terminated.h>
#include <libsbp/internal/v4/string/multipart.h>
#include <libsbp/internal/v4/string/null_terminated.h>
#include <libsbp/internal/v4/string/unterminated.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/flash.h>

bool sbp_msg_flash_program_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_msg_flash_program_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->target)) {
    return false;
  }
  for (size_t i = 0; i < SBP_MSG_FLASH_PROGRAM_ADDR_START_MAX; i++) {
    if (!sbp_u8_encode(ctx, &msg->addr_start[i])) {
      return false;
    }
  }
  if (!sbp_u8_encode(ctx, &msg->addr_len)) {
    return false;
  }
  for (size_t i = 0; i < msg->addr_len; i++) {
    if (!sbp_u8_encode(ctx, &msg->data[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_flash_program_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                const sbp_msg_flash_program_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_flash_program_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_flash_program_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_msg_flash_program_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->target)) {
    return false;
  }
  for (uint8_t i = 0; i < SBP_MSG_FLASH_PROGRAM_ADDR_START_MAX; i++) {
    if (!sbp_u8_decode(ctx, &msg->addr_start[i])) {
      return false;
    }
  }
  if (!sbp_u8_decode(ctx, &msg->addr_len)) {
    return false;
  }
  msg->addr_len = (uint8_t)((ctx->buf_len - ctx->offset) / SBP_ENCODED_LEN_U8);
  for (uint8_t i = 0; i < msg->addr_len; i++) {
    if (!sbp_u8_decode(ctx, &msg->data[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_flash_program_decode(const uint8_t *buf, uint8_t len,
                                uint8_t *n_read, sbp_msg_flash_program_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_flash_program_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_flash_program_send(sbp_state_t *s, u16 sender_id,
                              const sbp_msg_flash_program_t *msg,
                              sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_flash_program_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_FLASH_PROGRAM, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_flash_program_cmp(const sbp_msg_flash_program_t *a,
                              const sbp_msg_flash_program_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->target, &b->target);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_FLASH_PROGRAM_ADDR_START_MAX;
       i++) {
    ret = sbp_u8_cmp(&a->addr_start[i], &b->addr_start[i]);
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->addr_len, &b->addr_len);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->addr_len, &b->addr_len);
  for (uint8_t i = 0; ret == 0 && i < a->addr_len; i++) {
    ret = sbp_u8_cmp(&a->data[i], &b->data[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_flash_done_encode_internal(sbp_encode_ctx_t *ctx,
                                        const sbp_msg_flash_done_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->response)) {
    return false;
  }
  return true;
}

s8 sbp_msg_flash_done_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                             const sbp_msg_flash_done_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_flash_done_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_flash_done_decode_internal(sbp_decode_ctx_t *ctx,
                                        sbp_msg_flash_done_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->response)) {
    return false;
  }
  return true;
}

s8 sbp_msg_flash_done_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                             sbp_msg_flash_done_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_flash_done_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_flash_done_send(sbp_state_t *s, u16 sender_id,
                           const sbp_msg_flash_done_t *msg,
                           sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_flash_done_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_FLASH_DONE, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_flash_done_cmp(const sbp_msg_flash_done_t *a,
                           const sbp_msg_flash_done_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->response, &b->response);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_flash_read_req_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_flash_read_req_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->target)) {
    return false;
  }
  for (size_t i = 0; i < SBP_MSG_FLASH_READ_REQ_ADDR_START_MAX; i++) {
    if (!sbp_u8_encode(ctx, &msg->addr_start[i])) {
      return false;
    }
  }
  if (!sbp_u8_encode(ctx, &msg->addr_len)) {
    return false;
  }
  return true;
}

s8 sbp_msg_flash_read_req_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_msg_flash_read_req_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_flash_read_req_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_flash_read_req_decode_internal(sbp_decode_ctx_t *ctx,
                                            sbp_msg_flash_read_req_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->target)) {
    return false;
  }
  for (uint8_t i = 0; i < SBP_MSG_FLASH_READ_REQ_ADDR_START_MAX; i++) {
    if (!sbp_u8_decode(ctx, &msg->addr_start[i])) {
      return false;
    }
  }
  if (!sbp_u8_decode(ctx, &msg->addr_len)) {
    return false;
  }
  return true;
}

s8 sbp_msg_flash_read_req_decode(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read,
                                 sbp_msg_flash_read_req_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_flash_read_req_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_flash_read_req_send(sbp_state_t *s, u16 sender_id,
                               const sbp_msg_flash_read_req_t *msg,
                               sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_flash_read_req_encode(payload, sizeof(payload), &payload_len,
                                         msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_FLASH_READ_REQ, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_flash_read_req_cmp(const sbp_msg_flash_read_req_t *a,
                               const sbp_msg_flash_read_req_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->target, &b->target);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_FLASH_READ_REQ_ADDR_START_MAX;
       i++) {
    ret = sbp_u8_cmp(&a->addr_start[i], &b->addr_start[i]);
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->addr_len, &b->addr_len);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_flash_read_resp_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_flash_read_resp_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->target)) {
    return false;
  }
  for (size_t i = 0; i < SBP_MSG_FLASH_READ_RESP_ADDR_START_MAX; i++) {
    if (!sbp_u8_encode(ctx, &msg->addr_start[i])) {
      return false;
    }
  }
  if (!sbp_u8_encode(ctx, &msg->addr_len)) {
    return false;
  }
  return true;
}

s8 sbp_msg_flash_read_resp_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_flash_read_resp_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_flash_read_resp_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_flash_read_resp_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_msg_flash_read_resp_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->target)) {
    return false;
  }
  for (uint8_t i = 0; i < SBP_MSG_FLASH_READ_RESP_ADDR_START_MAX; i++) {
    if (!sbp_u8_decode(ctx, &msg->addr_start[i])) {
      return false;
    }
  }
  if (!sbp_u8_decode(ctx, &msg->addr_len)) {
    return false;
  }
  return true;
}

s8 sbp_msg_flash_read_resp_decode(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read,
                                  sbp_msg_flash_read_resp_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_flash_read_resp_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_flash_read_resp_send(sbp_state_t *s, u16 sender_id,
                                const sbp_msg_flash_read_resp_t *msg,
                                sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_flash_read_resp_encode(payload, sizeof(payload),
                                          &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_FLASH_READ_RESP, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_flash_read_resp_cmp(const sbp_msg_flash_read_resp_t *a,
                                const sbp_msg_flash_read_resp_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->target, &b->target);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_FLASH_READ_RESP_ADDR_START_MAX;
       i++) {
    ret = sbp_u8_cmp(&a->addr_start[i], &b->addr_start[i]);
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->addr_len, &b->addr_len);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_flash_erase_encode_internal(sbp_encode_ctx_t *ctx,
                                         const sbp_msg_flash_erase_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->target)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->sector_num)) {
    return false;
  }
  return true;
}

s8 sbp_msg_flash_erase_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                              const sbp_msg_flash_erase_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_flash_erase_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_flash_erase_decode_internal(sbp_decode_ctx_t *ctx,
                                         sbp_msg_flash_erase_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->target)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->sector_num)) {
    return false;
  }
  return true;
}

s8 sbp_msg_flash_erase_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                              sbp_msg_flash_erase_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_flash_erase_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_flash_erase_send(sbp_state_t *s, u16 sender_id,
                            const sbp_msg_flash_erase_t *msg,
                            sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_flash_erase_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_FLASH_ERASE, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_flash_erase_cmp(const sbp_msg_flash_erase_t *a,
                            const sbp_msg_flash_erase_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->target, &b->target);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->sector_num, &b->sector_num);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_stm_flash_lock_sector_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_stm_flash_lock_sector_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->sector)) {
    return false;
  }
  return true;
}

s8 sbp_msg_stm_flash_lock_sector_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_stm_flash_lock_sector_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_stm_flash_lock_sector_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_stm_flash_lock_sector_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_stm_flash_lock_sector_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->sector)) {
    return false;
  }
  return true;
}

s8 sbp_msg_stm_flash_lock_sector_decode(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_stm_flash_lock_sector_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_stm_flash_lock_sector_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_stm_flash_lock_sector_send(
    sbp_state_t *s, u16 sender_id, const sbp_msg_stm_flash_lock_sector_t *msg,
    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_stm_flash_lock_sector_encode(payload, sizeof(payload),
                                                &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_STM_FLASH_LOCK_SECTOR, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_stm_flash_lock_sector_cmp(
    const sbp_msg_stm_flash_lock_sector_t *a,
    const sbp_msg_stm_flash_lock_sector_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->sector, &b->sector);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_stm_flash_unlock_sector_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_stm_flash_unlock_sector_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->sector)) {
    return false;
  }
  return true;
}

s8 sbp_msg_stm_flash_unlock_sector_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_stm_flash_unlock_sector_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_stm_flash_unlock_sector_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_stm_flash_unlock_sector_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_stm_flash_unlock_sector_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->sector)) {
    return false;
  }
  return true;
}

s8 sbp_msg_stm_flash_unlock_sector_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_stm_flash_unlock_sector_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_stm_flash_unlock_sector_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_stm_flash_unlock_sector_send(
    sbp_state_t *s, u16 sender_id, const sbp_msg_stm_flash_unlock_sector_t *msg,
    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_stm_flash_unlock_sector_encode(payload, sizeof(payload),
                                                  &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_STM_FLASH_UNLOCK_SECTOR, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_stm_flash_unlock_sector_cmp(
    const sbp_msg_stm_flash_unlock_sector_t *a,
    const sbp_msg_stm_flash_unlock_sector_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->sector, &b->sector);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_stm_unique_id_req_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_stm_unique_id_req_t *msg) {
  (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_msg_stm_unique_id_req_encode(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_msg_stm_unique_id_req_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_stm_unique_id_req_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_stm_unique_id_req_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_stm_unique_id_req_t *msg) {
  (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_msg_stm_unique_id_req_decode(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_msg_stm_unique_id_req_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_stm_unique_id_req_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_stm_unique_id_req_send(sbp_state_t *s, u16 sender_id,
                                  const sbp_msg_stm_unique_id_req_t *msg,
                                  sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_stm_unique_id_req_encode(payload, sizeof(payload),
                                            &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_STM_UNIQUE_ID_REQ, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_stm_unique_id_req_cmp(const sbp_msg_stm_unique_id_req_t *a,
                                  const sbp_msg_stm_unique_id_req_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}

bool sbp_msg_stm_unique_id_resp_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_stm_unique_id_resp_t *msg) {
  for (size_t i = 0; i < SBP_MSG_STM_UNIQUE_ID_RESP_STM_ID_MAX; i++) {
    if (!sbp_u8_encode(ctx, &msg->stm_id[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_stm_unique_id_resp_encode(uint8_t *buf, uint8_t len,
                                     uint8_t *n_written,
                                     const sbp_msg_stm_unique_id_resp_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_stm_unique_id_resp_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_stm_unique_id_resp_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_stm_unique_id_resp_t *msg) {
  for (uint8_t i = 0; i < SBP_MSG_STM_UNIQUE_ID_RESP_STM_ID_MAX; i++) {
    if (!sbp_u8_decode(ctx, &msg->stm_id[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_stm_unique_id_resp_decode(const uint8_t *buf, uint8_t len,
                                     uint8_t *n_read,
                                     sbp_msg_stm_unique_id_resp_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_stm_unique_id_resp_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_stm_unique_id_resp_send(sbp_state_t *s, u16 sender_id,
                                   const sbp_msg_stm_unique_id_resp_t *msg,
                                   sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_stm_unique_id_resp_encode(payload, sizeof(payload),
                                             &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_STM_UNIQUE_ID_RESP, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_stm_unique_id_resp_cmp(const sbp_msg_stm_unique_id_resp_t *a,
                                   const sbp_msg_stm_unique_id_resp_t *b) {
  int ret = 0;

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_STM_UNIQUE_ID_RESP_STM_ID_MAX;
       i++) {
    ret = sbp_u8_cmp(&a->stm_id[i], &b->stm_id[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_m25_flash_write_status_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_m25_flash_write_status_t *msg) {
  for (size_t i = 0; i < SBP_MSG_M25_FLASH_WRITE_STATUS_STATUS_MAX; i++) {
    if (!sbp_u8_encode(ctx, &msg->status[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_m25_flash_write_status_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_m25_flash_write_status_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_m25_flash_write_status_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_m25_flash_write_status_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_m25_flash_write_status_t *msg) {
  for (uint8_t i = 0; i < SBP_MSG_M25_FLASH_WRITE_STATUS_STATUS_MAX; i++) {
    if (!sbp_u8_decode(ctx, &msg->status[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_m25_flash_write_status_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_m25_flash_write_status_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_m25_flash_write_status_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_m25_flash_write_status_send(
    sbp_state_t *s, u16 sender_id, const sbp_msg_m25_flash_write_status_t *msg,
    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_m25_flash_write_status_encode(payload, sizeof(payload),
                                                 &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_M25_FLASH_WRITE_STATUS, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_m25_flash_write_status_cmp(
    const sbp_msg_m25_flash_write_status_t *a,
    const sbp_msg_m25_flash_write_status_t *b) {
  int ret = 0;

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_M25_FLASH_WRITE_STATUS_STATUS_MAX;
       i++) {
    ret = sbp_u8_cmp(&a->status[i], &b->status[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}
