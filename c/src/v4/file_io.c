/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/file_io.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <libsbp/internal/v4/common.h>
#include <libsbp/internal/v4/file_io.h>
#include <libsbp/internal/v4/string/double_null_terminated.h>
#include <libsbp/internal/v4/string/multipart.h>
#include <libsbp/internal/v4/string/null_terminated.h>
#include <libsbp/internal/v4/string/unterminated.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/file_io.h>
static const sbp_null_terminated_string_params_t
    sbp_msg_fileio_read_req_tfilename_params = {.max_encoded_len = 246};

void sbp_msg_fileio_read_req_filename_init(sbp_null_terminated_string_t *s) {
  sbp_null_terminated_string_init(s, &sbp_msg_fileio_read_req_tfilename_params);
}

bool sbp_msg_fileio_read_req_filename_valid(
    const sbp_null_terminated_string_t *s) {
  return sbp_null_terminated_string_valid(
      s, &sbp_msg_fileio_read_req_tfilename_params);
}

int sbp_msg_fileio_read_req_filename_strcmp(
    const sbp_null_terminated_string_t *a,
    const sbp_null_terminated_string_t *b) {
  return sbp_null_terminated_string_strcmp(
      a, b, &sbp_msg_fileio_read_req_tfilename_params);
}

uint8_t sbp_msg_fileio_read_req_filename_encoded_len(
    const sbp_null_terminated_string_t *s) {
  return sbp_null_terminated_string_encoded_len(
      s, &sbp_msg_fileio_read_req_tfilename_params);
}

uint8_t sbp_msg_fileio_read_req_filename_space_remaining(
    const sbp_null_terminated_string_t *s) {
  return sbp_null_terminated_string_space_remaining(
      s, &sbp_msg_fileio_read_req_tfilename_params);
}
bool sbp_msg_fileio_read_req_filename_set(sbp_null_terminated_string_t *s,
                                          const char *new_str) {
  return sbp_null_terminated_string_set(
      s, &sbp_msg_fileio_read_req_tfilename_params, new_str);
}

bool sbp_msg_fileio_read_req_filename_printf(sbp_null_terminated_string_t *s,
                                             const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_null_terminated_string_vprintf(
      s, &sbp_msg_fileio_read_req_tfilename_params, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_fileio_read_req_filename_vprintf(sbp_null_terminated_string_t *s,
                                              const char *fmt, va_list ap) {
  return sbp_null_terminated_string_vprintf(
      s, &sbp_msg_fileio_read_req_tfilename_params, fmt, ap);
}

bool sbp_msg_fileio_read_req_filename_append_printf(
    sbp_null_terminated_string_t *s, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_null_terminated_string_append_vprintf(
      s, &sbp_msg_fileio_read_req_tfilename_params, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_fileio_read_req_filename_append_vprintf(
    sbp_null_terminated_string_t *s, const char *fmt, va_list ap) {
  return sbp_null_terminated_string_append_vprintf(
      s, &sbp_msg_fileio_read_req_tfilename_params, fmt, ap);
}

const char *sbp_msg_fileio_read_req_filename_get(
    const sbp_null_terminated_string_t *s) {
  return sbp_null_terminated_string_get(
      s, &sbp_msg_fileio_read_req_tfilename_params);
}

size_t sbp_msg_fileio_read_req_encoded_len(
    const sbp_msg_fileio_read_req_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_u32_encoded_len(&msg->sequence);
  encoded_len += sbp_u32_encoded_len(&msg->offset);
  encoded_len += sbp_u8_encoded_len(&msg->chunk_size);
  encoded_len += sbp_null_terminated_string_encoded_len(
      &msg->filename, &sbp_msg_fileio_read_req_tfilename_params);
  return encoded_len;
}

bool sbp_msg_fileio_read_req_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_fileio_read_req_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->sequence)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->offset)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->chunk_size)) {
    return false;
  }
  if (!sbp_null_terminated_string_pack(
          &msg->filename, &sbp_msg_fileio_read_req_tfilename_params, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_fileio_read_req_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_fileio_read_req_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_fileio_read_req_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_fileio_read_req_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_msg_fileio_read_req_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->sequence)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->offset)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->chunk_size)) {
    return false;
  }
  if (!sbp_null_terminated_string_unpack(
          &msg->filename, &sbp_msg_fileio_read_req_tfilename_params, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_fileio_read_req_decode(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read,
                                  sbp_msg_fileio_read_req_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_fileio_read_req_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_fileio_read_req_send(struct sbp_state *s, u16 sender_id,
                                const sbp_msg_fileio_read_req_t *msg,
                                sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_fileio_read_req_encode(payload, sizeof(payload),
                                          &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_FILEIO_READ_REQ, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_fileio_read_req_cmp(const sbp_msg_fileio_read_req_t *a,
                                const sbp_msg_fileio_read_req_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->sequence, &b->sequence);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->offset, &b->offset);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->chunk_size, &b->chunk_size);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_msg_fileio_read_req_filename_strcmp(&a->filename, &b->filename);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_msg_fileio_read_resp_encoded_len(
    const sbp_msg_fileio_read_resp_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_u32_encoded_len(&msg->sequence);
  encoded_len += (msg->n_contents * sbp_u8_encoded_len(&msg->contents[0]));
  return encoded_len;
}

bool sbp_msg_fileio_read_resp_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_fileio_read_resp_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->sequence)) {
    return false;
  }
  for (uint8_t i = 0; i < msg->n_contents; i++) {
    if (!sbp_u8_encode(ctx, &msg->contents[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_fileio_read_resp_encode(uint8_t *buf, uint8_t len,
                                   uint8_t *n_written,
                                   const sbp_msg_fileio_read_resp_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_fileio_read_resp_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_fileio_read_resp_decode_internal(sbp_decode_ctx_t *ctx,
                                              sbp_msg_fileio_read_resp_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->sequence)) {
    return false;
  }
  msg->n_contents = (uint8_t)((ctx->buf_len - ctx->offset) /
                              sbp_u8_encoded_len(&msg->contents[0]));
  for (uint8_t i = 0; i < msg->n_contents; i++) {
    if (!sbp_u8_decode(ctx, &msg->contents[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_fileio_read_resp_decode(const uint8_t *buf, uint8_t len,
                                   uint8_t *n_read,
                                   sbp_msg_fileio_read_resp_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_fileio_read_resp_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_fileio_read_resp_send(struct sbp_state *s, u16 sender_id,
                                 const sbp_msg_fileio_read_resp_t *msg,
                                 sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_fileio_read_resp_encode(payload, sizeof(payload),
                                           &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_FILEIO_READ_RESP, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_fileio_read_resp_cmp(const sbp_msg_fileio_read_resp_t *a,
                                 const sbp_msg_fileio_read_resp_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->sequence, &b->sequence);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_contents, &b->n_contents);
  for (uint8_t i = 0; ret == 0 && i < a->n_contents; i++) {
    ret = sbp_u8_cmp(&a->contents[i], &b->contents[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}
static const sbp_null_terminated_string_params_t
    sbp_msg_fileio_read_dir_req_tdirname_params = {.max_encoded_len = 247};

void sbp_msg_fileio_read_dir_req_dirname_init(sbp_null_terminated_string_t *s) {
  sbp_null_terminated_string_init(s,
                                  &sbp_msg_fileio_read_dir_req_tdirname_params);
}

bool sbp_msg_fileio_read_dir_req_dirname_valid(
    const sbp_null_terminated_string_t *s) {
  return sbp_null_terminated_string_valid(
      s, &sbp_msg_fileio_read_dir_req_tdirname_params);
}

int sbp_msg_fileio_read_dir_req_dirname_strcmp(
    const sbp_null_terminated_string_t *a,
    const sbp_null_terminated_string_t *b) {
  return sbp_null_terminated_string_strcmp(
      a, b, &sbp_msg_fileio_read_dir_req_tdirname_params);
}

uint8_t sbp_msg_fileio_read_dir_req_dirname_encoded_len(
    const sbp_null_terminated_string_t *s) {
  return sbp_null_terminated_string_encoded_len(
      s, &sbp_msg_fileio_read_dir_req_tdirname_params);
}

uint8_t sbp_msg_fileio_read_dir_req_dirname_space_remaining(
    const sbp_null_terminated_string_t *s) {
  return sbp_null_terminated_string_space_remaining(
      s, &sbp_msg_fileio_read_dir_req_tdirname_params);
}
bool sbp_msg_fileio_read_dir_req_dirname_set(sbp_null_terminated_string_t *s,
                                             const char *new_str) {
  return sbp_null_terminated_string_set(
      s, &sbp_msg_fileio_read_dir_req_tdirname_params, new_str);
}

bool sbp_msg_fileio_read_dir_req_dirname_printf(sbp_null_terminated_string_t *s,
                                                const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_null_terminated_string_vprintf(
      s, &sbp_msg_fileio_read_dir_req_tdirname_params, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_fileio_read_dir_req_dirname_vprintf(
    sbp_null_terminated_string_t *s, const char *fmt, va_list ap) {
  return sbp_null_terminated_string_vprintf(
      s, &sbp_msg_fileio_read_dir_req_tdirname_params, fmt, ap);
}

bool sbp_msg_fileio_read_dir_req_dirname_append_printf(
    sbp_null_terminated_string_t *s, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_null_terminated_string_append_vprintf(
      s, &sbp_msg_fileio_read_dir_req_tdirname_params, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_fileio_read_dir_req_dirname_append_vprintf(
    sbp_null_terminated_string_t *s, const char *fmt, va_list ap) {
  return sbp_null_terminated_string_append_vprintf(
      s, &sbp_msg_fileio_read_dir_req_tdirname_params, fmt, ap);
}

const char *sbp_msg_fileio_read_dir_req_dirname_get(
    const sbp_null_terminated_string_t *s) {
  return sbp_null_terminated_string_get(
      s, &sbp_msg_fileio_read_dir_req_tdirname_params);
}

size_t sbp_msg_fileio_read_dir_req_encoded_len(
    const sbp_msg_fileio_read_dir_req_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_u32_encoded_len(&msg->sequence);
  encoded_len += sbp_u32_encoded_len(&msg->offset);
  encoded_len += sbp_null_terminated_string_encoded_len(
      &msg->dirname, &sbp_msg_fileio_read_dir_req_tdirname_params);
  return encoded_len;
}

bool sbp_msg_fileio_read_dir_req_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_fileio_read_dir_req_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->sequence)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->offset)) {
    return false;
  }
  if (!sbp_null_terminated_string_pack(
          &msg->dirname, &sbp_msg_fileio_read_dir_req_tdirname_params, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_fileio_read_dir_req_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_fileio_read_dir_req_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_fileio_read_dir_req_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_fileio_read_dir_req_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_fileio_read_dir_req_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->sequence)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->offset)) {
    return false;
  }
  if (!sbp_null_terminated_string_unpack(
          &msg->dirname, &sbp_msg_fileio_read_dir_req_tdirname_params, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_fileio_read_dir_req_decode(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_fileio_read_dir_req_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_fileio_read_dir_req_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_fileio_read_dir_req_send(struct sbp_state *s, u16 sender_id,
                                    const sbp_msg_fileio_read_dir_req_t *msg,
                                    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_fileio_read_dir_req_encode(payload, sizeof(payload),
                                              &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_FILEIO_READ_DIR_REQ, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_fileio_read_dir_req_cmp(const sbp_msg_fileio_read_dir_req_t *a,
                                    const sbp_msg_fileio_read_dir_req_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->sequence, &b->sequence);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->offset, &b->offset);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_msg_fileio_read_dir_req_dirname_strcmp(&a->dirname, &b->dirname);
  if (ret != 0) {
    return ret;
  }
  return ret;
}
static const sbp_multipart_string_params_t
    sbp_msg_fileio_read_dir_resp_tcontents_params = {.max_encoded_len = 251};

void sbp_msg_fileio_read_dir_resp_contents_init(sbp_multipart_string_t *s) {
  sbp_multipart_string_init(s, &sbp_msg_fileio_read_dir_resp_tcontents_params);
}

bool sbp_msg_fileio_read_dir_resp_contents_valid(
    const sbp_multipart_string_t *s) {
  return sbp_multipart_string_valid(
      s, &sbp_msg_fileio_read_dir_resp_tcontents_params);
}

int sbp_msg_fileio_read_dir_resp_contents_strcmp(
    const sbp_multipart_string_t *a, const sbp_multipart_string_t *b) {
  return sbp_multipart_string_strcmp(
      a, b, &sbp_msg_fileio_read_dir_resp_tcontents_params);
}

uint8_t sbp_msg_fileio_read_dir_resp_contents_encoded_len(
    const sbp_multipart_string_t *s) {
  return sbp_multipart_string_encoded_len(
      s, &sbp_msg_fileio_read_dir_resp_tcontents_params);
}

uint8_t sbp_msg_fileio_read_dir_resp_contents_space_remaining(
    const sbp_multipart_string_t *s) {
  return sbp_multipart_string_space_remaining(
      s, &sbp_msg_fileio_read_dir_resp_tcontents_params);
}
uint8_t sbp_msg_fileio_read_dir_resp_contents_count_sections(
    const sbp_multipart_string_t *s) {
  return sbp_multipart_string_count_sections(
      s, &sbp_msg_fileio_read_dir_resp_tcontents_params);
}

bool sbp_msg_fileio_read_dir_resp_contents_add_section(
    sbp_multipart_string_t *s, const char *new_str) {
  return sbp_multipart_string_add_section(
      s, &sbp_msg_fileio_read_dir_resp_tcontents_params, new_str);
}

bool sbp_msg_fileio_read_dir_resp_contents_add_section_printf(
    sbp_multipart_string_t *s, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_multipart_string_add_section_vprintf(
      s, &sbp_msg_fileio_read_dir_resp_tcontents_params, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_fileio_read_dir_resp_contents_add_section_vprintf(
    sbp_multipart_string_t *s, const char *fmt, va_list ap) {
  return sbp_multipart_string_add_section_vprintf(
      s, &sbp_msg_fileio_read_dir_resp_tcontents_params, fmt, ap);
}

bool sbp_msg_fileio_read_dir_resp_contents_append(sbp_multipart_string_t *s,
                                                  const char *str) {
  return sbp_multipart_string_append(
      s, &sbp_msg_fileio_read_dir_resp_tcontents_params, str);
}

bool sbp_msg_fileio_read_dir_resp_contents_append_printf(
    sbp_multipart_string_t *s, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_multipart_string_append_vprintf(
      s, &sbp_msg_fileio_read_dir_resp_tcontents_params, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_fileio_read_dir_resp_contents_append_vprintf(
    sbp_multipart_string_t *s, const char *fmt, va_list ap) {
  return sbp_multipart_string_append_vprintf(
      s, &sbp_msg_fileio_read_dir_resp_tcontents_params, fmt, ap);
}

const char *sbp_msg_fileio_read_dir_resp_contents_get_section(
    const sbp_multipart_string_t *s, uint8_t section) {
  return sbp_multipart_string_get_section(
      s, &sbp_msg_fileio_read_dir_resp_tcontents_params, section);
}

uint8_t sbp_msg_fileio_read_dir_resp_contents_section_strlen(
    const sbp_multipart_string_t *s, uint8_t section) {
  return sbp_multipart_string_section_strlen(
      s, &sbp_msg_fileio_read_dir_resp_tcontents_params, section);
}

size_t sbp_msg_fileio_read_dir_resp_encoded_len(
    const sbp_msg_fileio_read_dir_resp_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_u32_encoded_len(&msg->sequence);
  encoded_len += sbp_multipart_string_encoded_len(
      &msg->contents, &sbp_msg_fileio_read_dir_resp_tcontents_params);
  return encoded_len;
}

bool sbp_msg_fileio_read_dir_resp_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_fileio_read_dir_resp_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->sequence)) {
    return false;
  }
  if (!sbp_multipart_string_pack(&msg->contents,
                                 &sbp_msg_fileio_read_dir_resp_tcontents_params,
                                 ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_fileio_read_dir_resp_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_fileio_read_dir_resp_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_fileio_read_dir_resp_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_fileio_read_dir_resp_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_fileio_read_dir_resp_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->sequence)) {
    return false;
  }
  if (!sbp_multipart_string_unpack(
          &msg->contents, &sbp_msg_fileio_read_dir_resp_tcontents_params,
          ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_fileio_read_dir_resp_decode(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_msg_fileio_read_dir_resp_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_fileio_read_dir_resp_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_fileio_read_dir_resp_send(struct sbp_state *s, u16 sender_id,
                                     const sbp_msg_fileio_read_dir_resp_t *msg,
                                     sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_fileio_read_dir_resp_encode(payload, sizeof(payload),
                                               &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_FILEIO_READ_DIR_RESP, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_fileio_read_dir_resp_cmp(const sbp_msg_fileio_read_dir_resp_t *a,
                                     const sbp_msg_fileio_read_dir_resp_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->sequence, &b->sequence);
  if (ret != 0) {
    return ret;
  }

  ret =
      sbp_msg_fileio_read_dir_resp_contents_strcmp(&a->contents, &b->contents);
  if (ret != 0) {
    return ret;
  }
  return ret;
}
static const sbp_null_terminated_string_params_t
    sbp_msg_fileio_remove_tfilename_params = {.max_encoded_len = 255};

void sbp_msg_fileio_remove_filename_init(sbp_null_terminated_string_t *s) {
  sbp_null_terminated_string_init(s, &sbp_msg_fileio_remove_tfilename_params);
}

bool sbp_msg_fileio_remove_filename_valid(
    const sbp_null_terminated_string_t *s) {
  return sbp_null_terminated_string_valid(
      s, &sbp_msg_fileio_remove_tfilename_params);
}

int sbp_msg_fileio_remove_filename_strcmp(
    const sbp_null_terminated_string_t *a,
    const sbp_null_terminated_string_t *b) {
  return sbp_null_terminated_string_strcmp(
      a, b, &sbp_msg_fileio_remove_tfilename_params);
}

uint8_t sbp_msg_fileio_remove_filename_encoded_len(
    const sbp_null_terminated_string_t *s) {
  return sbp_null_terminated_string_encoded_len(
      s, &sbp_msg_fileio_remove_tfilename_params);
}

uint8_t sbp_msg_fileio_remove_filename_space_remaining(
    const sbp_null_terminated_string_t *s) {
  return sbp_null_terminated_string_space_remaining(
      s, &sbp_msg_fileio_remove_tfilename_params);
}
bool sbp_msg_fileio_remove_filename_set(sbp_null_terminated_string_t *s,
                                        const char *new_str) {
  return sbp_null_terminated_string_set(
      s, &sbp_msg_fileio_remove_tfilename_params, new_str);
}

bool sbp_msg_fileio_remove_filename_printf(sbp_null_terminated_string_t *s,
                                           const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_null_terminated_string_vprintf(
      s, &sbp_msg_fileio_remove_tfilename_params, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_fileio_remove_filename_vprintf(sbp_null_terminated_string_t *s,
                                            const char *fmt, va_list ap) {
  return sbp_null_terminated_string_vprintf(
      s, &sbp_msg_fileio_remove_tfilename_params, fmt, ap);
}

bool sbp_msg_fileio_remove_filename_append_printf(
    sbp_null_terminated_string_t *s, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_null_terminated_string_append_vprintf(
      s, &sbp_msg_fileio_remove_tfilename_params, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_fileio_remove_filename_append_vprintf(
    sbp_null_terminated_string_t *s, const char *fmt, va_list ap) {
  return sbp_null_terminated_string_append_vprintf(
      s, &sbp_msg_fileio_remove_tfilename_params, fmt, ap);
}

const char *sbp_msg_fileio_remove_filename_get(
    const sbp_null_terminated_string_t *s) {
  return sbp_null_terminated_string_get(
      s, &sbp_msg_fileio_remove_tfilename_params);
}

size_t sbp_msg_fileio_remove_encoded_len(const sbp_msg_fileio_remove_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_null_terminated_string_encoded_len(
      &msg->filename, &sbp_msg_fileio_remove_tfilename_params);
  return encoded_len;
}

bool sbp_msg_fileio_remove_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_msg_fileio_remove_t *msg) {
  if (!sbp_null_terminated_string_pack(
          &msg->filename, &sbp_msg_fileio_remove_tfilename_params, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_fileio_remove_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                const sbp_msg_fileio_remove_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_fileio_remove_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_fileio_remove_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_msg_fileio_remove_t *msg) {
  if (!sbp_null_terminated_string_unpack(
          &msg->filename, &sbp_msg_fileio_remove_tfilename_params, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_fileio_remove_decode(const uint8_t *buf, uint8_t len,
                                uint8_t *n_read, sbp_msg_fileio_remove_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_fileio_remove_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_fileio_remove_send(struct sbp_state *s, u16 sender_id,
                              const sbp_msg_fileio_remove_t *msg,
                              sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_fileio_remove_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_FILEIO_REMOVE, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_fileio_remove_cmp(const sbp_msg_fileio_remove_t *a,
                              const sbp_msg_fileio_remove_t *b) {
  int ret = 0;

  ret = sbp_msg_fileio_remove_filename_strcmp(&a->filename, &b->filename);
  if (ret != 0) {
    return ret;
  }
  return ret;
}
static const sbp_null_terminated_string_params_t
    sbp_msg_fileio_write_req_tfilename_params = {.max_encoded_len = 247};

void sbp_msg_fileio_write_req_filename_init(sbp_null_terminated_string_t *s) {
  sbp_null_terminated_string_init(s,
                                  &sbp_msg_fileio_write_req_tfilename_params);
}

bool sbp_msg_fileio_write_req_filename_valid(
    const sbp_null_terminated_string_t *s) {
  return sbp_null_terminated_string_valid(
      s, &sbp_msg_fileio_write_req_tfilename_params);
}

int sbp_msg_fileio_write_req_filename_strcmp(
    const sbp_null_terminated_string_t *a,
    const sbp_null_terminated_string_t *b) {
  return sbp_null_terminated_string_strcmp(
      a, b, &sbp_msg_fileio_write_req_tfilename_params);
}

uint8_t sbp_msg_fileio_write_req_filename_encoded_len(
    const sbp_null_terminated_string_t *s) {
  return sbp_null_terminated_string_encoded_len(
      s, &sbp_msg_fileio_write_req_tfilename_params);
}

uint8_t sbp_msg_fileio_write_req_filename_space_remaining(
    const sbp_null_terminated_string_t *s) {
  return sbp_null_terminated_string_space_remaining(
      s, &sbp_msg_fileio_write_req_tfilename_params);
}
bool sbp_msg_fileio_write_req_filename_set(sbp_null_terminated_string_t *s,
                                           const char *new_str) {
  return sbp_null_terminated_string_set(
      s, &sbp_msg_fileio_write_req_tfilename_params, new_str);
}

bool sbp_msg_fileio_write_req_filename_printf(sbp_null_terminated_string_t *s,
                                              const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_null_terminated_string_vprintf(
      s, &sbp_msg_fileio_write_req_tfilename_params, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_fileio_write_req_filename_vprintf(sbp_null_terminated_string_t *s,
                                               const char *fmt, va_list ap) {
  return sbp_null_terminated_string_vprintf(
      s, &sbp_msg_fileio_write_req_tfilename_params, fmt, ap);
}

bool sbp_msg_fileio_write_req_filename_append_printf(
    sbp_null_terminated_string_t *s, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_null_terminated_string_append_vprintf(
      s, &sbp_msg_fileio_write_req_tfilename_params, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_fileio_write_req_filename_append_vprintf(
    sbp_null_terminated_string_t *s, const char *fmt, va_list ap) {
  return sbp_null_terminated_string_append_vprintf(
      s, &sbp_msg_fileio_write_req_tfilename_params, fmt, ap);
}

const char *sbp_msg_fileio_write_req_filename_get(
    const sbp_null_terminated_string_t *s) {
  return sbp_null_terminated_string_get(
      s, &sbp_msg_fileio_write_req_tfilename_params);
}

size_t sbp_msg_fileio_write_req_encoded_len(
    const sbp_msg_fileio_write_req_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_u32_encoded_len(&msg->sequence);
  encoded_len += sbp_u32_encoded_len(&msg->offset);
  encoded_len += sbp_null_terminated_string_encoded_len(
      &msg->filename, &sbp_msg_fileio_write_req_tfilename_params);
  encoded_len += (msg->n_data * sbp_u8_encoded_len(&msg->data[0]));
  return encoded_len;
}

bool sbp_msg_fileio_write_req_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_fileio_write_req_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->sequence)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->offset)) {
    return false;
  }
  if (!sbp_null_terminated_string_pack(
          &msg->filename, &sbp_msg_fileio_write_req_tfilename_params, ctx)) {
    return false;
  }
  for (uint8_t i = 0; i < msg->n_data; i++) {
    if (!sbp_u8_encode(ctx, &msg->data[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_fileio_write_req_encode(uint8_t *buf, uint8_t len,
                                   uint8_t *n_written,
                                   const sbp_msg_fileio_write_req_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_fileio_write_req_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_fileio_write_req_decode_internal(sbp_decode_ctx_t *ctx,
                                              sbp_msg_fileio_write_req_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->sequence)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->offset)) {
    return false;
  }
  if (!sbp_null_terminated_string_unpack(
          &msg->filename, &sbp_msg_fileio_write_req_tfilename_params, ctx)) {
    return false;
  }
  msg->n_data = (uint8_t)((ctx->buf_len - ctx->offset) /
                          sbp_u8_encoded_len(&msg->data[0]));
  for (uint8_t i = 0; i < msg->n_data; i++) {
    if (!sbp_u8_decode(ctx, &msg->data[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_fileio_write_req_decode(const uint8_t *buf, uint8_t len,
                                   uint8_t *n_read,
                                   sbp_msg_fileio_write_req_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_fileio_write_req_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_fileio_write_req_send(struct sbp_state *s, u16 sender_id,
                                 const sbp_msg_fileio_write_req_t *msg,
                                 sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_fileio_write_req_encode(payload, sizeof(payload),
                                           &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_FILEIO_WRITE_REQ, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_fileio_write_req_cmp(const sbp_msg_fileio_write_req_t *a,
                                 const sbp_msg_fileio_write_req_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->sequence, &b->sequence);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->offset, &b->offset);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_msg_fileio_write_req_filename_strcmp(&a->filename, &b->filename);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_data, &b->n_data);
  for (uint8_t i = 0; ret == 0 && i < a->n_data; i++) {
    ret = sbp_u8_cmp(&a->data[i], &b->data[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_msg_fileio_write_resp_encoded_len(
    const sbp_msg_fileio_write_resp_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_u32_encoded_len(&msg->sequence);
  return encoded_len;
}

bool sbp_msg_fileio_write_resp_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_fileio_write_resp_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->sequence)) {
    return false;
  }
  return true;
}

s8 sbp_msg_fileio_write_resp_encode(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_msg_fileio_write_resp_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_fileio_write_resp_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_fileio_write_resp_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_fileio_write_resp_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->sequence)) {
    return false;
  }
  return true;
}

s8 sbp_msg_fileio_write_resp_decode(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_msg_fileio_write_resp_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_fileio_write_resp_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_fileio_write_resp_send(struct sbp_state *s, u16 sender_id,
                                  const sbp_msg_fileio_write_resp_t *msg,
                                  sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_fileio_write_resp_encode(payload, sizeof(payload),
                                            &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_FILEIO_WRITE_RESP, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_fileio_write_resp_cmp(const sbp_msg_fileio_write_resp_t *a,
                                  const sbp_msg_fileio_write_resp_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->sequence, &b->sequence);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_msg_fileio_config_req_encoded_len(
    const sbp_msg_fileio_config_req_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_u32_encoded_len(&msg->sequence);
  return encoded_len;
}

bool sbp_msg_fileio_config_req_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_fileio_config_req_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->sequence)) {
    return false;
  }
  return true;
}

s8 sbp_msg_fileio_config_req_encode(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_msg_fileio_config_req_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_fileio_config_req_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_fileio_config_req_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_fileio_config_req_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->sequence)) {
    return false;
  }
  return true;
}

s8 sbp_msg_fileio_config_req_decode(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_msg_fileio_config_req_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_fileio_config_req_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_fileio_config_req_send(struct sbp_state *s, u16 sender_id,
                                  const sbp_msg_fileio_config_req_t *msg,
                                  sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_fileio_config_req_encode(payload, sizeof(payload),
                                            &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_FILEIO_CONFIG_REQ, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_fileio_config_req_cmp(const sbp_msg_fileio_config_req_t *a,
                                  const sbp_msg_fileio_config_req_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->sequence, &b->sequence);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_msg_fileio_config_resp_encoded_len(
    const sbp_msg_fileio_config_resp_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_u32_encoded_len(&msg->sequence);
  encoded_len += sbp_u32_encoded_len(&msg->window_size);
  encoded_len += sbp_u32_encoded_len(&msg->batch_size);
  encoded_len += sbp_u32_encoded_len(&msg->fileio_version);
  return encoded_len;
}

bool sbp_msg_fileio_config_resp_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_fileio_config_resp_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->sequence)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->window_size)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->batch_size)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->fileio_version)) {
    return false;
  }
  return true;
}

s8 sbp_msg_fileio_config_resp_encode(uint8_t *buf, uint8_t len,
                                     uint8_t *n_written,
                                     const sbp_msg_fileio_config_resp_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_fileio_config_resp_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_fileio_config_resp_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_fileio_config_resp_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->sequence)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->window_size)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->batch_size)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->fileio_version)) {
    return false;
  }
  return true;
}

s8 sbp_msg_fileio_config_resp_decode(const uint8_t *buf, uint8_t len,
                                     uint8_t *n_read,
                                     sbp_msg_fileio_config_resp_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_fileio_config_resp_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_fileio_config_resp_send(struct sbp_state *s, u16 sender_id,
                                   const sbp_msg_fileio_config_resp_t *msg,
                                   sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_fileio_config_resp_encode(payload, sizeof(payload),
                                             &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_FILEIO_CONFIG_RESP, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_fileio_config_resp_cmp(const sbp_msg_fileio_config_resp_t *a,
                                   const sbp_msg_fileio_config_resp_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->sequence, &b->sequence);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->window_size, &b->window_size);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->batch_size, &b->batch_size);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->fileio_version, &b->fileio_version);
  if (ret != 0) {
    return ret;
  }
  return ret;
}
