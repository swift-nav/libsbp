/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/bootload.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <libsbp/internal/new/bootload.h>
#include <libsbp/internal/new/common.h>
#include <libsbp/internal/new/string/double_null_terminated.h>
#include <libsbp/internal/new/string/multipart.h>
#include <libsbp/internal/new/string/null_terminated.h>
#include <libsbp/internal/new/string/unterminated.h>
#include <libsbp/new/bootload.h>
#include <libsbp/sbp.h>

size_t sbp_packed_size_sbp_msg_bootloader_handshake_req_t(
    const sbp_msg_bootloader_handshake_req_t *msg) {
  (void)msg;
  return 0;
}

bool encode_sbp_msg_bootloader_handshake_req_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_bootloader_handshake_req_t *msg) {
  (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_encode_sbp_msg_bootloader_handshake_req_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_bootloader_handshake_req_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_bootloader_handshake_req_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_bootloader_handshake_req_t(
    sbp_decode_ctx_t *ctx, sbp_msg_bootloader_handshake_req_t *msg) {
  (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_decode_sbp_msg_bootloader_handshake_req_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_bootloader_handshake_req_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_bootloader_handshake_req_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_send_sbp_msg_bootloader_handshake_req_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_bootloader_handshake_req_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_bootloader_handshake_req_t(
      payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_BOOTLOADER_HANDSHAKE_REQ, sender_id,
                          payload_len, payload, write);
}

int sbp_cmp_sbp_msg_bootloader_handshake_req_t(
    const sbp_msg_bootloader_handshake_req_t *a,
    const sbp_msg_bootloader_handshake_req_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}
static const sbp_unterminated_string_params_t
    sbp_msg_bootloader_handshake_resp_tversion_params = {.max_packed_len = 251};

void sbp_msg_bootloader_handshake_resp_t_version_init(
    sbp_unterminated_string_t *s) {
  sbp_unterminated_string_init(
      s, &sbp_msg_bootloader_handshake_resp_tversion_params);
}

bool sbp_msg_bootloader_handshake_resp_t_version_valid(
    const sbp_unterminated_string_t *s) {
  return sbp_unterminated_string_valid(
      s, &sbp_msg_bootloader_handshake_resp_tversion_params);
}

int sbp_msg_bootloader_handshake_resp_t_version_strcmp(
    const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b) {
  return sbp_unterminated_string_strcmp(
      a, b, &sbp_msg_bootloader_handshake_resp_tversion_params);
}

uint8_t sbp_msg_bootloader_handshake_resp_t_version_packed_len(
    const sbp_unterminated_string_t *s) {
  return sbp_unterminated_string_packed_len(
      s, &sbp_msg_bootloader_handshake_resp_tversion_params);
}

uint8_t sbp_msg_bootloader_handshake_resp_t_version_space_remaining(
    const sbp_unterminated_string_t *s) {
  return sbp_unterminated_string_space_remaining(
      s, &sbp_msg_bootloader_handshake_resp_tversion_params);
}
bool sbp_msg_bootloader_handshake_resp_t_version_set(
    sbp_unterminated_string_t *s, const char *new_str) {
  return sbp_unterminated_string_set(
      s, &sbp_msg_bootloader_handshake_resp_tversion_params, new_str);
}

bool sbp_msg_bootloader_handshake_resp_t_version_printf(
    sbp_unterminated_string_t *s, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_vprintf(
      s, &sbp_msg_bootloader_handshake_resp_tversion_params, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_bootloader_handshake_resp_t_version_vprintf(
    sbp_unterminated_string_t *s, const char *fmt, va_list ap) {
  return sbp_unterminated_string_vprintf(
      s, &sbp_msg_bootloader_handshake_resp_tversion_params, fmt, ap);
}

bool sbp_msg_bootloader_handshake_resp_t_version_append_printf(
    sbp_unterminated_string_t *s, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_append_vprintf(
      s, &sbp_msg_bootloader_handshake_resp_tversion_params, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_bootloader_handshake_resp_t_version_append_vprintf(
    sbp_unterminated_string_t *s, const char *fmt, va_list ap) {
  return sbp_unterminated_string_append_vprintf(
      s, &sbp_msg_bootloader_handshake_resp_tversion_params, fmt, ap);
}

const char *sbp_msg_bootloader_handshake_resp_t_version_get(
    const sbp_unterminated_string_t *s) {
  return sbp_unterminated_string_get(
      s, &sbp_msg_bootloader_handshake_resp_tversion_params);
}

size_t sbp_packed_size_sbp_msg_bootloader_handshake_resp_t(
    const sbp_msg_bootloader_handshake_resp_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->flags);
  packed_size += sbp_unterminated_string_packed_len(
      &msg->version, &sbp_msg_bootloader_handshake_resp_tversion_params);
  return packed_size;
}

bool encode_sbp_msg_bootloader_handshake_resp_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_bootloader_handshake_resp_t *msg) {
  if (!encode_u32(ctx, &msg->flags)) {
    return false;
  }
  if (!sbp_unterminated_string_pack(
          &msg->version, &sbp_msg_bootloader_handshake_resp_tversion_params,
          ctx)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_bootloader_handshake_resp_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_bootloader_handshake_resp_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_bootloader_handshake_resp_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_bootloader_handshake_resp_t(
    sbp_decode_ctx_t *ctx, sbp_msg_bootloader_handshake_resp_t *msg) {
  if (!decode_u32(ctx, &msg->flags)) {
    return false;
  }
  if (!sbp_unterminated_string_unpack(
          &msg->version, &sbp_msg_bootloader_handshake_resp_tversion_params,
          ctx)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_bootloader_handshake_resp_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_bootloader_handshake_resp_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_bootloader_handshake_resp_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_send_sbp_msg_bootloader_handshake_resp_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_bootloader_handshake_resp_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_bootloader_handshake_resp_t(
      payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_BOOTLOADER_HANDSHAKE_RESP, sender_id,
                          payload_len, payload, write);
}

int sbp_cmp_sbp_msg_bootloader_handshake_resp_t(
    const sbp_msg_bootloader_handshake_resp_t *a,
    const sbp_msg_bootloader_handshake_resp_t *b) {
  int ret = 0;

  ret = sbp_cmp_u32(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_msg_bootloader_handshake_resp_t_version_strcmp(&a->version,
                                                           &b->version);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_bootloader_jump_to_app_t(
    const sbp_msg_bootloader_jump_to_app_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->jump);
  return packed_size;
}

bool encode_sbp_msg_bootloader_jump_to_app_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_bootloader_jump_to_app_t *msg) {
  if (!encode_u8(ctx, &msg->jump)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_bootloader_jump_to_app_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_bootloader_jump_to_app_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_bootloader_jump_to_app_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_bootloader_jump_to_app_t(
    sbp_decode_ctx_t *ctx, sbp_msg_bootloader_jump_to_app_t *msg) {
  if (!decode_u8(ctx, &msg->jump)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_bootloader_jump_to_app_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_bootloader_jump_to_app_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_bootloader_jump_to_app_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_send_sbp_msg_bootloader_jump_to_app_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_bootloader_jump_to_app_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_bootloader_jump_to_app_t(payload, sizeof(payload),
                                                       &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_BOOTLOADER_JUMP_TO_APP, sender_id,
                          payload_len, payload, write);
}

int sbp_cmp_sbp_msg_bootloader_jump_to_app_t(
    const sbp_msg_bootloader_jump_to_app_t *a,
    const sbp_msg_bootloader_jump_to_app_t *b) {
  int ret = 0;

  ret = sbp_cmp_u8(&a->jump, &b->jump);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_packed_size_sbp_msg_nap_device_dna_req_t(
    const sbp_msg_nap_device_dna_req_t *msg) {
  (void)msg;
  return 0;
}

bool encode_sbp_msg_nap_device_dna_req_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_nap_device_dna_req_t *msg) {
  (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_encode_sbp_msg_nap_device_dna_req_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_nap_device_dna_req_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_nap_device_dna_req_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_nap_device_dna_req_t(sbp_decode_ctx_t *ctx,
                                         sbp_msg_nap_device_dna_req_t *msg) {
  (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_decode_sbp_msg_nap_device_dna_req_t(const uint8_t *buf, uint8_t len,
                                           uint8_t *n_read,
                                           sbp_msg_nap_device_dna_req_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_nap_device_dna_req_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_send_sbp_msg_nap_device_dna_req_t(
    struct sbp_state *s, u16 sender_id, const sbp_msg_nap_device_dna_req_t *msg,
    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_nap_device_dna_req_t(payload, sizeof(payload),
                                                   &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_NAP_DEVICE_DNA_REQ, sender_id, payload_len,
                          payload, write);
}

int sbp_cmp_sbp_msg_nap_device_dna_req_t(
    const sbp_msg_nap_device_dna_req_t *a,
    const sbp_msg_nap_device_dna_req_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}

size_t sbp_packed_size_sbp_msg_nap_device_dna_resp_t(
    const sbp_msg_nap_device_dna_resp_t *msg) {
  size_t packed_size = 0;
  packed_size += (8 * sbp_packed_size_u8(&msg->dna[0]));
  return packed_size;
}

bool encode_sbp_msg_nap_device_dna_resp_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_nap_device_dna_resp_t *msg) {
  for (uint8_t i = 0; i < 8; i++) {
    if (!encode_u8(ctx, &msg->dna[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_encode_sbp_msg_nap_device_dna_resp_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_nap_device_dna_resp_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_nap_device_dna_resp_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_nap_device_dna_resp_t(sbp_decode_ctx_t *ctx,
                                          sbp_msg_nap_device_dna_resp_t *msg) {
  for (uint8_t i = 0; i < 8; i++) {
    if (!decode_u8(ctx, &msg->dna[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_decode_sbp_msg_nap_device_dna_resp_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_nap_device_dna_resp_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_nap_device_dna_resp_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_send_sbp_msg_nap_device_dna_resp_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_nap_device_dna_resp_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_nap_device_dna_resp_t(payload, sizeof(payload),
                                                    &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_NAP_DEVICE_DNA_RESP, sender_id,
                          payload_len, payload, write);
}

int sbp_cmp_sbp_msg_nap_device_dna_resp_t(
    const sbp_msg_nap_device_dna_resp_t *a,
    const sbp_msg_nap_device_dna_resp_t *b) {
  int ret = 0;

  for (uint8_t i = 0; ret == 0 && i < 8; i++) {
    ret = sbp_cmp_u8(&a->dna[i], &b->dna[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}
static const sbp_unterminated_string_params_t
    sbp_msg_bootloader_handshake_dep_a_thandshake_params = {.max_packed_len =
                                                                255};

void sbp_msg_bootloader_handshake_dep_a_t_handshake_init(
    sbp_unterminated_string_t *s) {
  sbp_unterminated_string_init(
      s, &sbp_msg_bootloader_handshake_dep_a_thandshake_params);
}

bool sbp_msg_bootloader_handshake_dep_a_t_handshake_valid(
    const sbp_unterminated_string_t *s) {
  return sbp_unterminated_string_valid(
      s, &sbp_msg_bootloader_handshake_dep_a_thandshake_params);
}

int sbp_msg_bootloader_handshake_dep_a_t_handshake_strcmp(
    const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b) {
  return sbp_unterminated_string_strcmp(
      a, b, &sbp_msg_bootloader_handshake_dep_a_thandshake_params);
}

uint8_t sbp_msg_bootloader_handshake_dep_a_t_handshake_packed_len(
    const sbp_unterminated_string_t *s) {
  return sbp_unterminated_string_packed_len(
      s, &sbp_msg_bootloader_handshake_dep_a_thandshake_params);
}

uint8_t sbp_msg_bootloader_handshake_dep_a_t_handshake_space_remaining(
    const sbp_unterminated_string_t *s) {
  return sbp_unterminated_string_space_remaining(
      s, &sbp_msg_bootloader_handshake_dep_a_thandshake_params);
}
bool sbp_msg_bootloader_handshake_dep_a_t_handshake_set(
    sbp_unterminated_string_t *s, const char *new_str) {
  return sbp_unterminated_string_set(
      s, &sbp_msg_bootloader_handshake_dep_a_thandshake_params, new_str);
}

bool sbp_msg_bootloader_handshake_dep_a_t_handshake_printf(
    sbp_unterminated_string_t *s, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_vprintf(
      s, &sbp_msg_bootloader_handshake_dep_a_thandshake_params, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_bootloader_handshake_dep_a_t_handshake_vprintf(
    sbp_unterminated_string_t *s, const char *fmt, va_list ap) {
  return sbp_unterminated_string_vprintf(
      s, &sbp_msg_bootloader_handshake_dep_a_thandshake_params, fmt, ap);
}

bool sbp_msg_bootloader_handshake_dep_a_t_handshake_append_printf(
    sbp_unterminated_string_t *s, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_append_vprintf(
      s, &sbp_msg_bootloader_handshake_dep_a_thandshake_params, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_bootloader_handshake_dep_a_t_handshake_append_vprintf(
    sbp_unterminated_string_t *s, const char *fmt, va_list ap) {
  return sbp_unterminated_string_append_vprintf(
      s, &sbp_msg_bootloader_handshake_dep_a_thandshake_params, fmt, ap);
}

const char *sbp_msg_bootloader_handshake_dep_a_t_handshake_get(
    const sbp_unterminated_string_t *s) {
  return sbp_unterminated_string_get(
      s, &sbp_msg_bootloader_handshake_dep_a_thandshake_params);
}

size_t sbp_packed_size_sbp_msg_bootloader_handshake_dep_a_t(
    const sbp_msg_bootloader_handshake_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_unterminated_string_packed_len(
      &msg->handshake, &sbp_msg_bootloader_handshake_dep_a_thandshake_params);
  return packed_size;
}

bool encode_sbp_msg_bootloader_handshake_dep_a_t(
    sbp_encode_ctx_t *ctx, const sbp_msg_bootloader_handshake_dep_a_t *msg) {
  if (!sbp_unterminated_string_pack(
          &msg->handshake,
          &sbp_msg_bootloader_handshake_dep_a_thandshake_params, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_encode_sbp_msg_bootloader_handshake_dep_a_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_bootloader_handshake_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_bootloader_handshake_dep_a_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_bootloader_handshake_dep_a_t(
    sbp_decode_ctx_t *ctx, sbp_msg_bootloader_handshake_dep_a_t *msg) {
  if (!sbp_unterminated_string_unpack(
          &msg->handshake,
          &sbp_msg_bootloader_handshake_dep_a_thandshake_params, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_decode_sbp_msg_bootloader_handshake_dep_a_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_bootloader_handshake_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_bootloader_handshake_dep_a_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_send_sbp_msg_bootloader_handshake_dep_a_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_bootloader_handshake_dep_a_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_bootloader_handshake_dep_a_t(
      payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_BOOTLOADER_HANDSHAKE_DEP_A, sender_id,
                          payload_len, payload, write);
}

int sbp_cmp_sbp_msg_bootloader_handshake_dep_a_t(
    const sbp_msg_bootloader_handshake_dep_a_t *a,
    const sbp_msg_bootloader_handshake_dep_a_t *b) {
  int ret = 0;

  ret = sbp_msg_bootloader_handshake_dep_a_t_handshake_strcmp(&a->handshake,
                                                              &b->handshake);
  if (ret != 0) {
    return ret;
  }
  return ret;
}
