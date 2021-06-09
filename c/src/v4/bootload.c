/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/bootload.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <libsbp/internal/v4/bootload.h>
#include <libsbp/internal/v4/common.h>
#include <libsbp/internal/v4/string/double_null_terminated.h>
#include <libsbp/internal/v4/string/multipart.h>
#include <libsbp/internal/v4/string/null_terminated.h>
#include <libsbp/internal/v4/string/unterminated.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/bootload.h>

size_t sbp_msg_bootloader_handshake_req_encoded_len(
    const sbp_msg_bootloader_handshake_req_t *msg) {
  (void)msg;
  return 0;
}

bool sbp_msg_bootloader_handshake_req_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_bootloader_handshake_req_t *msg) {
  (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_msg_bootloader_handshake_req_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_bootloader_handshake_req_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_bootloader_handshake_req_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_bootloader_handshake_req_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_bootloader_handshake_req_t *msg) {
  (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_msg_bootloader_handshake_req_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_bootloader_handshake_req_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_bootloader_handshake_req_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_bootloader_handshake_req_send(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_bootloader_handshake_req_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_bootloader_handshake_req_encode(payload, sizeof(payload),
                                                   &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_BOOTLOADER_HANDSHAKE_REQ, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_bootloader_handshake_req_cmp(
    const sbp_msg_bootloader_handshake_req_t *a,
    const sbp_msg_bootloader_handshake_req_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}
static const sbp_unterminated_string_params_t
    sbp_msg_bootloader_handshake_resp_tversion_params = {.max_encoded_len =
                                                             251};

void sbp_msg_bootloader_handshake_resp_version_init(
    sbp_msg_bootloader_handshake_resp_t *msg) {
  sbp_unterminated_string_init(
      &msg->version, &sbp_msg_bootloader_handshake_resp_tversion_params);
}

bool sbp_msg_bootloader_handshake_resp_version_valid(
    const sbp_msg_bootloader_handshake_resp_t *msg) {
  return sbp_unterminated_string_valid(
      &msg->version, &sbp_msg_bootloader_handshake_resp_tversion_params);
}

int sbp_msg_bootloader_handshake_resp_version_strcmp(
    const sbp_msg_bootloader_handshake_resp_t *a,
    const sbp_msg_bootloader_handshake_resp_t *b) {
  return sbp_unterminated_string_strcmp(
      &a->version, &b->version,
      &sbp_msg_bootloader_handshake_resp_tversion_params);
}

uint8_t sbp_msg_bootloader_handshake_resp_version_encoded_len(
    const sbp_msg_bootloader_handshake_resp_t *msg) {
  return sbp_unterminated_string_encoded_len(
      &msg->version, &sbp_msg_bootloader_handshake_resp_tversion_params);
}

uint8_t sbp_msg_bootloader_handshake_resp_version_space_remaining(
    const sbp_msg_bootloader_handshake_resp_t *msg) {
  return sbp_unterminated_string_space_remaining(
      &msg->version, &sbp_msg_bootloader_handshake_resp_tversion_params);
}
bool sbp_msg_bootloader_handshake_resp_version_set(
    sbp_msg_bootloader_handshake_resp_t *msg, const char *new_str) {
  return sbp_unterminated_string_set(
      &msg->version, &sbp_msg_bootloader_handshake_resp_tversion_params,
      new_str);
}

bool sbp_msg_bootloader_handshake_resp_version_printf(
    sbp_msg_bootloader_handshake_resp_t *msg, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_vprintf(
      &msg->version, &sbp_msg_bootloader_handshake_resp_tversion_params, fmt,
      ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_bootloader_handshake_resp_version_vprintf(
    sbp_msg_bootloader_handshake_resp_t *msg, const char *fmt, va_list ap) {
  return sbp_unterminated_string_vprintf(
      &msg->version, &sbp_msg_bootloader_handshake_resp_tversion_params, fmt,
      ap);
}

bool sbp_msg_bootloader_handshake_resp_version_append_printf(
    sbp_msg_bootloader_handshake_resp_t *msg, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_append_vprintf(
      &msg->version, &sbp_msg_bootloader_handshake_resp_tversion_params, fmt,
      ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_bootloader_handshake_resp_version_append_vprintf(
    sbp_msg_bootloader_handshake_resp_t *msg, const char *fmt, va_list ap) {
  return sbp_unterminated_string_append_vprintf(
      &msg->version, &sbp_msg_bootloader_handshake_resp_tversion_params, fmt,
      ap);
}

const char *sbp_msg_bootloader_handshake_resp_version_get(
    const sbp_msg_bootloader_handshake_resp_t *msg) {
  return sbp_unterminated_string_get(
      &msg->version, &sbp_msg_bootloader_handshake_resp_tversion_params);
}

size_t sbp_msg_bootloader_handshake_resp_encoded_len(
    const sbp_msg_bootloader_handshake_resp_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_u32_encoded_len(&msg->flags);
  encoded_len += sbp_unterminated_string_encoded_len(
      &msg->version, &sbp_msg_bootloader_handshake_resp_tversion_params);
  return encoded_len;
}

bool sbp_msg_bootloader_handshake_resp_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_bootloader_handshake_resp_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->flags)) {
    return false;
  }
  if (!sbp_unterminated_string_pack(
          &msg->version, &sbp_msg_bootloader_handshake_resp_tversion_params,
          ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_bootloader_handshake_resp_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_bootloader_handshake_resp_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_bootloader_handshake_resp_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_bootloader_handshake_resp_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_bootloader_handshake_resp_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->flags)) {
    return false;
  }
  if (!sbp_unterminated_string_unpack(
          &msg->version, &sbp_msg_bootloader_handshake_resp_tversion_params,
          ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_bootloader_handshake_resp_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_bootloader_handshake_resp_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_bootloader_handshake_resp_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_bootloader_handshake_resp_send(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_bootloader_handshake_resp_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_bootloader_handshake_resp_encode(payload, sizeof(payload),
                                                    &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_BOOTLOADER_HANDSHAKE_RESP, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_bootloader_handshake_resp_cmp(
    const sbp_msg_bootloader_handshake_resp_t *a,
    const sbp_msg_bootloader_handshake_resp_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_msg_bootloader_handshake_resp_version_strcmp(a, b);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_msg_bootloader_jump_to_app_encoded_len(
    const sbp_msg_bootloader_jump_to_app_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_u8_encoded_len(&msg->jump);
  return encoded_len;
}

bool sbp_msg_bootloader_jump_to_app_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_bootloader_jump_to_app_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->jump)) {
    return false;
  }
  return true;
}

s8 sbp_msg_bootloader_jump_to_app_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_bootloader_jump_to_app_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_bootloader_jump_to_app_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_bootloader_jump_to_app_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_bootloader_jump_to_app_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->jump)) {
    return false;
  }
  return true;
}

s8 sbp_msg_bootloader_jump_to_app_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_bootloader_jump_to_app_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_bootloader_jump_to_app_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_bootloader_jump_to_app_send(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_bootloader_jump_to_app_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_bootloader_jump_to_app_encode(payload, sizeof(payload),
                                                 &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_BOOTLOADER_JUMP_TO_APP, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_bootloader_jump_to_app_cmp(
    const sbp_msg_bootloader_jump_to_app_t *a,
    const sbp_msg_bootloader_jump_to_app_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->jump, &b->jump);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_msg_nap_device_dna_req_encoded_len(
    const sbp_msg_nap_device_dna_req_t *msg) {
  (void)msg;
  return 0;
}

bool sbp_msg_nap_device_dna_req_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_nap_device_dna_req_t *msg) {
  (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_msg_nap_device_dna_req_encode(uint8_t *buf, uint8_t len,
                                     uint8_t *n_written,
                                     const sbp_msg_nap_device_dna_req_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_nap_device_dna_req_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_nap_device_dna_req_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_nap_device_dna_req_t *msg) {
  (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_msg_nap_device_dna_req_decode(const uint8_t *buf, uint8_t len,
                                     uint8_t *n_read,
                                     sbp_msg_nap_device_dna_req_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_nap_device_dna_req_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_nap_device_dna_req_send(struct sbp_state *s, u16 sender_id,
                                   const sbp_msg_nap_device_dna_req_t *msg,
                                   sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_nap_device_dna_req_encode(payload, sizeof(payload),
                                             &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_NAP_DEVICE_DNA_REQ, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_nap_device_dna_req_cmp(const sbp_msg_nap_device_dna_req_t *a,
                                   const sbp_msg_nap_device_dna_req_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}

size_t sbp_msg_nap_device_dna_resp_encoded_len(
    const sbp_msg_nap_device_dna_resp_t *msg) {
  size_t encoded_len = 0;
  encoded_len += (8 * sbp_u8_encoded_len(&msg->dna[0]));
  return encoded_len;
}

bool sbp_msg_nap_device_dna_resp_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_nap_device_dna_resp_t *msg) {
  for (uint8_t i = 0; i < 8; i++) {
    if (!sbp_u8_encode(ctx, &msg->dna[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_nap_device_dna_resp_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_nap_device_dna_resp_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_nap_device_dna_resp_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_nap_device_dna_resp_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_nap_device_dna_resp_t *msg) {
  for (uint8_t i = 0; i < 8; i++) {
    if (!sbp_u8_decode(ctx, &msg->dna[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_nap_device_dna_resp_decode(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_nap_device_dna_resp_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_nap_device_dna_resp_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_nap_device_dna_resp_send(struct sbp_state *s, u16 sender_id,
                                    const sbp_msg_nap_device_dna_resp_t *msg,
                                    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_nap_device_dna_resp_encode(payload, sizeof(payload),
                                              &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_NAP_DEVICE_DNA_RESP, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_nap_device_dna_resp_cmp(const sbp_msg_nap_device_dna_resp_t *a,
                                    const sbp_msg_nap_device_dna_resp_t *b) {
  int ret = 0;

  for (uint8_t i = 0; ret == 0 && i < 8; i++) {
    ret = sbp_u8_cmp(&a->dna[i], &b->dna[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}
static const sbp_unterminated_string_params_t
    sbp_msg_bootloader_handshake_dep_a_thandshake_params = {.max_encoded_len =
                                                                255};

void sbp_msg_bootloader_handshake_dep_a_handshake_init(
    sbp_msg_bootloader_handshake_dep_a_t *msg) {
  sbp_unterminated_string_init(
      &msg->handshake, &sbp_msg_bootloader_handshake_dep_a_thandshake_params);
}

bool sbp_msg_bootloader_handshake_dep_a_handshake_valid(
    const sbp_msg_bootloader_handshake_dep_a_t *msg) {
  return sbp_unterminated_string_valid(
      &msg->handshake, &sbp_msg_bootloader_handshake_dep_a_thandshake_params);
}

int sbp_msg_bootloader_handshake_dep_a_handshake_strcmp(
    const sbp_msg_bootloader_handshake_dep_a_t *a,
    const sbp_msg_bootloader_handshake_dep_a_t *b) {
  return sbp_unterminated_string_strcmp(
      &a->handshake, &b->handshake,
      &sbp_msg_bootloader_handshake_dep_a_thandshake_params);
}

uint8_t sbp_msg_bootloader_handshake_dep_a_handshake_encoded_len(
    const sbp_msg_bootloader_handshake_dep_a_t *msg) {
  return sbp_unterminated_string_encoded_len(
      &msg->handshake, &sbp_msg_bootloader_handshake_dep_a_thandshake_params);
}

uint8_t sbp_msg_bootloader_handshake_dep_a_handshake_space_remaining(
    const sbp_msg_bootloader_handshake_dep_a_t *msg) {
  return sbp_unterminated_string_space_remaining(
      &msg->handshake, &sbp_msg_bootloader_handshake_dep_a_thandshake_params);
}
bool sbp_msg_bootloader_handshake_dep_a_handshake_set(
    sbp_msg_bootloader_handshake_dep_a_t *msg, const char *new_str) {
  return sbp_unterminated_string_set(
      &msg->handshake, &sbp_msg_bootloader_handshake_dep_a_thandshake_params,
      new_str);
}

bool sbp_msg_bootloader_handshake_dep_a_handshake_printf(
    sbp_msg_bootloader_handshake_dep_a_t *msg, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_vprintf(
      &msg->handshake, &sbp_msg_bootloader_handshake_dep_a_thandshake_params,
      fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_bootloader_handshake_dep_a_handshake_vprintf(
    sbp_msg_bootloader_handshake_dep_a_t *msg, const char *fmt, va_list ap) {
  return sbp_unterminated_string_vprintf(
      &msg->handshake, &sbp_msg_bootloader_handshake_dep_a_thandshake_params,
      fmt, ap);
}

bool sbp_msg_bootloader_handshake_dep_a_handshake_append_printf(
    sbp_msg_bootloader_handshake_dep_a_t *msg, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_append_vprintf(
      &msg->handshake, &sbp_msg_bootloader_handshake_dep_a_thandshake_params,
      fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_bootloader_handshake_dep_a_handshake_append_vprintf(
    sbp_msg_bootloader_handshake_dep_a_t *msg, const char *fmt, va_list ap) {
  return sbp_unterminated_string_append_vprintf(
      &msg->handshake, &sbp_msg_bootloader_handshake_dep_a_thandshake_params,
      fmt, ap);
}

const char *sbp_msg_bootloader_handshake_dep_a_handshake_get(
    const sbp_msg_bootloader_handshake_dep_a_t *msg) {
  return sbp_unterminated_string_get(
      &msg->handshake, &sbp_msg_bootloader_handshake_dep_a_thandshake_params);
}

size_t sbp_msg_bootloader_handshake_dep_a_encoded_len(
    const sbp_msg_bootloader_handshake_dep_a_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_unterminated_string_encoded_len(
      &msg->handshake, &sbp_msg_bootloader_handshake_dep_a_thandshake_params);
  return encoded_len;
}

bool sbp_msg_bootloader_handshake_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_bootloader_handshake_dep_a_t *msg) {
  if (!sbp_unterminated_string_pack(
          &msg->handshake,
          &sbp_msg_bootloader_handshake_dep_a_thandshake_params, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_bootloader_handshake_dep_a_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_bootloader_handshake_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_bootloader_handshake_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_bootloader_handshake_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_bootloader_handshake_dep_a_t *msg) {
  if (!sbp_unterminated_string_unpack(
          &msg->handshake,
          &sbp_msg_bootloader_handshake_dep_a_thandshake_params, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_bootloader_handshake_dep_a_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_bootloader_handshake_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_bootloader_handshake_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_bootloader_handshake_dep_a_send(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_bootloader_handshake_dep_a_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_bootloader_handshake_dep_a_encode(payload, sizeof(payload),
                                                     &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_BOOTLOADER_HANDSHAKE_DEP_A, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_bootloader_handshake_dep_a_cmp(
    const sbp_msg_bootloader_handshake_dep_a_t *a,
    const sbp_msg_bootloader_handshake_dep_a_t *b) {
  int ret = 0;

  ret = sbp_msg_bootloader_handshake_dep_a_handshake_strcmp(a, b);
  if (ret != 0) {
    return ret;
  }
  return ret;
}
