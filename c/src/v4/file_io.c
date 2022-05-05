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

void sbp_msg_fileio_read_req_filename_init(sbp_msg_fileio_read_req_t *msg) {
  sbp_null_terminated_string_init(&msg->filename);
}

bool sbp_msg_fileio_read_req_filename_valid(
    const sbp_msg_fileio_read_req_t *msg) {
  return sbp_null_terminated_string_valid(&msg->filename,
                                          SBP_MSG_FILEIO_READ_REQ_FILENAME_MAX);
}

int sbp_msg_fileio_read_req_filename_strcmp(
    const sbp_msg_fileio_read_req_t *a, const sbp_msg_fileio_read_req_t *b) {
  return sbp_null_terminated_string_strcmp(
      &a->filename, &b->filename, SBP_MSG_FILEIO_READ_REQ_FILENAME_MAX);
}

size_t sbp_msg_fileio_read_req_filename_encoded_len(
    const sbp_msg_fileio_read_req_t *msg) {
  return sbp_null_terminated_string_encoded_len(
      &msg->filename, SBP_MSG_FILEIO_READ_REQ_FILENAME_MAX);
}

size_t sbp_msg_fileio_read_req_filename_space_remaining(
    const sbp_msg_fileio_read_req_t *msg) {
  return sbp_null_terminated_string_space_remaining(
      &msg->filename, SBP_MSG_FILEIO_READ_REQ_FILENAME_MAX);
}
bool sbp_msg_fileio_read_req_filename_set(sbp_msg_fileio_read_req_t *msg,
                                          const char *new_str,
                                          bool should_trunc,
                                          size_t *n_written) {
  return sbp_null_terminated_string_set(&msg->filename,
                                        SBP_MSG_FILEIO_READ_REQ_FILENAME_MAX,
                                        should_trunc, n_written, new_str);
}

bool sbp_msg_fileio_read_req_filename_set_raw(sbp_msg_fileio_read_req_t *msg,
                                              const char *new_buf,
                                              size_t new_buf_len,
                                              bool should_trunc,
                                              size_t *n_written) {
  return sbp_null_terminated_string_set_raw(
      &msg->filename, SBP_MSG_FILEIO_READ_REQ_FILENAME_MAX, should_trunc,
      n_written, new_buf, new_buf_len);
}

bool sbp_msg_fileio_read_req_filename_printf(sbp_msg_fileio_read_req_t *msg,
                                             bool should_trunc,
                                             size_t *n_written, const char *fmt,
                                             ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_null_terminated_string_vprintf(
      &msg->filename, SBP_MSG_FILEIO_READ_REQ_FILENAME_MAX, should_trunc,
      n_written, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_fileio_read_req_filename_vprintf(sbp_msg_fileio_read_req_t *msg,
                                              bool should_trunc,
                                              size_t *n_written,
                                              const char *fmt, va_list ap) {
  return sbp_null_terminated_string_vprintf(
      &msg->filename, SBP_MSG_FILEIO_READ_REQ_FILENAME_MAX, should_trunc,
      n_written, fmt, ap);
}

bool sbp_msg_fileio_read_req_filename_append_printf(
    sbp_msg_fileio_read_req_t *msg, bool should_trunc, size_t *n_written,
    const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_null_terminated_string_append_vprintf(
      &msg->filename, SBP_MSG_FILEIO_READ_REQ_FILENAME_MAX, should_trunc,
      n_written, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_fileio_read_req_filename_append_vprintf(
    sbp_msg_fileio_read_req_t *msg, bool should_trunc, size_t *n_written,
    const char *fmt, va_list ap) {
  return sbp_null_terminated_string_append_vprintf(
      &msg->filename, SBP_MSG_FILEIO_READ_REQ_FILENAME_MAX, should_trunc,
      n_written, fmt, ap);
}

const char *sbp_msg_fileio_read_req_filename_get(
    const sbp_msg_fileio_read_req_t *msg) {
  return sbp_null_terminated_string_get(&msg->filename,
                                        SBP_MSG_FILEIO_READ_REQ_FILENAME_MAX);
}

size_t sbp_msg_fileio_read_req_filename_strlen(
    const sbp_msg_fileio_read_req_t *msg) {
  return sbp_null_terminated_string_strlen(
      &msg->filename, SBP_MSG_FILEIO_READ_REQ_FILENAME_MAX);
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
  if (!sbp_null_terminated_string_encode(
          &msg->filename, SBP_MSG_FILEIO_READ_REQ_FILENAME_MAX, ctx)) {
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
  if (!sbp_null_terminated_string_decode(
          &msg->filename, SBP_MSG_FILEIO_READ_REQ_FILENAME_MAX, ctx)) {
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

s8 sbp_msg_fileio_read_req_send(sbp_state_t *s, u16 sender_id,
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

  ret = sbp_msg_fileio_read_req_filename_strcmp(a, b);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_fileio_read_resp_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_fileio_read_resp_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->sequence)) {
    return false;
  }
  for (size_t i = 0; i < msg->n_contents; i++) {
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
  msg->n_contents =
      (uint8_t)((ctx->buf_len - ctx->offset) / SBP_ENCODED_LEN_U8);
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

s8 sbp_msg_fileio_read_resp_send(sbp_state_t *s, u16 sender_id,
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

void sbp_msg_fileio_read_dir_req_dirname_init(
    sbp_msg_fileio_read_dir_req_t *msg) {
  sbp_null_terminated_string_init(&msg->dirname);
}

bool sbp_msg_fileio_read_dir_req_dirname_valid(
    const sbp_msg_fileio_read_dir_req_t *msg) {
  return sbp_null_terminated_string_valid(
      &msg->dirname, SBP_MSG_FILEIO_READ_DIR_REQ_DIRNAME_MAX);
}

int sbp_msg_fileio_read_dir_req_dirname_strcmp(
    const sbp_msg_fileio_read_dir_req_t *a,
    const sbp_msg_fileio_read_dir_req_t *b) {
  return sbp_null_terminated_string_strcmp(
      &a->dirname, &b->dirname, SBP_MSG_FILEIO_READ_DIR_REQ_DIRNAME_MAX);
}

size_t sbp_msg_fileio_read_dir_req_dirname_encoded_len(
    const sbp_msg_fileio_read_dir_req_t *msg) {
  return sbp_null_terminated_string_encoded_len(
      &msg->dirname, SBP_MSG_FILEIO_READ_DIR_REQ_DIRNAME_MAX);
}

size_t sbp_msg_fileio_read_dir_req_dirname_space_remaining(
    const sbp_msg_fileio_read_dir_req_t *msg) {
  return sbp_null_terminated_string_space_remaining(
      &msg->dirname, SBP_MSG_FILEIO_READ_DIR_REQ_DIRNAME_MAX);
}
bool sbp_msg_fileio_read_dir_req_dirname_set(sbp_msg_fileio_read_dir_req_t *msg,
                                             const char *new_str,
                                             bool should_trunc,
                                             size_t *n_written) {
  return sbp_null_terminated_string_set(&msg->dirname,
                                        SBP_MSG_FILEIO_READ_DIR_REQ_DIRNAME_MAX,
                                        should_trunc, n_written, new_str);
}

bool sbp_msg_fileio_read_dir_req_dirname_set_raw(
    sbp_msg_fileio_read_dir_req_t *msg, const char *new_buf, size_t new_buf_len,
    bool should_trunc, size_t *n_written) {
  return sbp_null_terminated_string_set_raw(
      &msg->dirname, SBP_MSG_FILEIO_READ_DIR_REQ_DIRNAME_MAX, should_trunc,
      n_written, new_buf, new_buf_len);
}

bool sbp_msg_fileio_read_dir_req_dirname_printf(
    sbp_msg_fileio_read_dir_req_t *msg, bool should_trunc, size_t *n_written,
    const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_null_terminated_string_vprintf(
      &msg->dirname, SBP_MSG_FILEIO_READ_DIR_REQ_DIRNAME_MAX, should_trunc,
      n_written, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_fileio_read_dir_req_dirname_vprintf(
    sbp_msg_fileio_read_dir_req_t *msg, bool should_trunc, size_t *n_written,
    const char *fmt, va_list ap) {
  return sbp_null_terminated_string_vprintf(
      &msg->dirname, SBP_MSG_FILEIO_READ_DIR_REQ_DIRNAME_MAX, should_trunc,
      n_written, fmt, ap);
}

bool sbp_msg_fileio_read_dir_req_dirname_append_printf(
    sbp_msg_fileio_read_dir_req_t *msg, bool should_trunc, size_t *n_written,
    const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_null_terminated_string_append_vprintf(
      &msg->dirname, SBP_MSG_FILEIO_READ_DIR_REQ_DIRNAME_MAX, should_trunc,
      n_written, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_fileio_read_dir_req_dirname_append_vprintf(
    sbp_msg_fileio_read_dir_req_t *msg, bool should_trunc, size_t *n_written,
    const char *fmt, va_list ap) {
  return sbp_null_terminated_string_append_vprintf(
      &msg->dirname, SBP_MSG_FILEIO_READ_DIR_REQ_DIRNAME_MAX, should_trunc,
      n_written, fmt, ap);
}

const char *sbp_msg_fileio_read_dir_req_dirname_get(
    const sbp_msg_fileio_read_dir_req_t *msg) {
  return sbp_null_terminated_string_get(
      &msg->dirname, SBP_MSG_FILEIO_READ_DIR_REQ_DIRNAME_MAX);
}

size_t sbp_msg_fileio_read_dir_req_dirname_strlen(
    const sbp_msg_fileio_read_dir_req_t *msg) {
  return sbp_null_terminated_string_strlen(
      &msg->dirname, SBP_MSG_FILEIO_READ_DIR_REQ_DIRNAME_MAX);
}

bool sbp_msg_fileio_read_dir_req_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_fileio_read_dir_req_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->sequence)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->offset)) {
    return false;
  }
  if (!sbp_null_terminated_string_encode(
          &msg->dirname, SBP_MSG_FILEIO_READ_DIR_REQ_DIRNAME_MAX, ctx)) {
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
  if (!sbp_null_terminated_string_decode(
          &msg->dirname, SBP_MSG_FILEIO_READ_DIR_REQ_DIRNAME_MAX, ctx)) {
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

s8 sbp_msg_fileio_read_dir_req_send(sbp_state_t *s, u16 sender_id,
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

  ret = sbp_msg_fileio_read_dir_req_dirname_strcmp(a, b);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

void sbp_msg_fileio_read_dir_resp_contents_init(
    sbp_msg_fileio_read_dir_resp_t *msg) {
  sbp_multipart_string_init(&msg->contents);
}

bool sbp_msg_fileio_read_dir_resp_contents_valid(
    const sbp_msg_fileio_read_dir_resp_t *msg) {
  return sbp_multipart_string_valid(&msg->contents,
                                    SBP_MSG_FILEIO_READ_DIR_RESP_CONTENTS_MAX);
}

int sbp_msg_fileio_read_dir_resp_contents_strcmp(
    const sbp_msg_fileio_read_dir_resp_t *a,
    const sbp_msg_fileio_read_dir_resp_t *b) {
  return sbp_multipart_string_strcmp(&a->contents, &b->contents,
                                     SBP_MSG_FILEIO_READ_DIR_RESP_CONTENTS_MAX);
}

size_t sbp_msg_fileio_read_dir_resp_contents_encoded_len(
    const sbp_msg_fileio_read_dir_resp_t *msg) {
  return sbp_multipart_string_encoded_len(
      &msg->contents, SBP_MSG_FILEIO_READ_DIR_RESP_CONTENTS_MAX);
}

size_t sbp_msg_fileio_read_dir_resp_contents_space_remaining(
    const sbp_msg_fileio_read_dir_resp_t *msg) {
  return sbp_multipart_string_space_remaining(
      &msg->contents, SBP_MSG_FILEIO_READ_DIR_RESP_CONTENTS_MAX);
}
size_t sbp_msg_fileio_read_dir_resp_contents_count_sections(
    const sbp_msg_fileio_read_dir_resp_t *msg) {
  return sbp_multipart_string_count_sections(
      &msg->contents, SBP_MSG_FILEIO_READ_DIR_RESP_CONTENTS_MAX);
}

bool sbp_msg_fileio_read_dir_resp_contents_add_section(
    sbp_msg_fileio_read_dir_resp_t *msg, const char *new_str) {
  return sbp_multipart_string_add_section(
      &msg->contents, SBP_MSG_FILEIO_READ_DIR_RESP_CONTENTS_MAX, new_str);
}

bool sbp_msg_fileio_read_dir_resp_contents_add_section_printf(
    sbp_msg_fileio_read_dir_resp_t *msg, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_multipart_string_add_section_vprintf(
      &msg->contents, SBP_MSG_FILEIO_READ_DIR_RESP_CONTENTS_MAX, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_fileio_read_dir_resp_contents_add_section_vprintf(
    sbp_msg_fileio_read_dir_resp_t *msg, const char *fmt, va_list ap) {
  return sbp_multipart_string_add_section_vprintf(
      &msg->contents, SBP_MSG_FILEIO_READ_DIR_RESP_CONTENTS_MAX, fmt, ap);
}

bool sbp_msg_fileio_read_dir_resp_contents_append(
    sbp_msg_fileio_read_dir_resp_t *msg, const char *str) {
  return sbp_multipart_string_append(
      &msg->contents, SBP_MSG_FILEIO_READ_DIR_RESP_CONTENTS_MAX, str);
}

bool sbp_msg_fileio_read_dir_resp_contents_append_printf(
    sbp_msg_fileio_read_dir_resp_t *msg, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_multipart_string_append_vprintf(
      &msg->contents, SBP_MSG_FILEIO_READ_DIR_RESP_CONTENTS_MAX, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_fileio_read_dir_resp_contents_append_vprintf(
    sbp_msg_fileio_read_dir_resp_t *msg, const char *fmt, va_list ap) {
  return sbp_multipart_string_append_vprintf(
      &msg->contents, SBP_MSG_FILEIO_READ_DIR_RESP_CONTENTS_MAX, fmt, ap);
}

const char *sbp_msg_fileio_read_dir_resp_contents_get_section(
    const sbp_msg_fileio_read_dir_resp_t *msg, size_t section) {
  return sbp_multipart_string_get_section(
      &msg->contents, SBP_MSG_FILEIO_READ_DIR_RESP_CONTENTS_MAX, section);
}

size_t sbp_msg_fileio_read_dir_resp_contents_section_strlen(
    const sbp_msg_fileio_read_dir_resp_t *msg, size_t section) {
  return sbp_multipart_string_section_strlen(
      &msg->contents, SBP_MSG_FILEIO_READ_DIR_RESP_CONTENTS_MAX, section);
}

bool sbp_msg_fileio_read_dir_resp_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_fileio_read_dir_resp_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->sequence)) {
    return false;
  }
  if (!sbp_multipart_string_encode(
          &msg->contents, SBP_MSG_FILEIO_READ_DIR_RESP_CONTENTS_MAX, ctx)) {
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
  if (!sbp_multipart_string_decode(
          &msg->contents, SBP_MSG_FILEIO_READ_DIR_RESP_CONTENTS_MAX, ctx)) {
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

s8 sbp_msg_fileio_read_dir_resp_send(sbp_state_t *s, u16 sender_id,
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

  ret = sbp_msg_fileio_read_dir_resp_contents_strcmp(a, b);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

void sbp_msg_fileio_remove_filename_init(sbp_msg_fileio_remove_t *msg) {
  sbp_null_terminated_string_init(&msg->filename);
}

bool sbp_msg_fileio_remove_filename_valid(const sbp_msg_fileio_remove_t *msg) {
  return sbp_null_terminated_string_valid(&msg->filename,
                                          SBP_MSG_FILEIO_REMOVE_FILENAME_MAX);
}

int sbp_msg_fileio_remove_filename_strcmp(const sbp_msg_fileio_remove_t *a,
                                          const sbp_msg_fileio_remove_t *b) {
  return sbp_null_terminated_string_strcmp(&a->filename, &b->filename,
                                           SBP_MSG_FILEIO_REMOVE_FILENAME_MAX);
}

size_t sbp_msg_fileio_remove_filename_encoded_len(
    const sbp_msg_fileio_remove_t *msg) {
  return sbp_null_terminated_string_encoded_len(
      &msg->filename, SBP_MSG_FILEIO_REMOVE_FILENAME_MAX);
}

size_t sbp_msg_fileio_remove_filename_space_remaining(
    const sbp_msg_fileio_remove_t *msg) {
  return sbp_null_terminated_string_space_remaining(
      &msg->filename, SBP_MSG_FILEIO_REMOVE_FILENAME_MAX);
}
bool sbp_msg_fileio_remove_filename_set(sbp_msg_fileio_remove_t *msg,
                                        const char *new_str, bool should_trunc,
                                        size_t *n_written) {
  return sbp_null_terminated_string_set(&msg->filename,
                                        SBP_MSG_FILEIO_REMOVE_FILENAME_MAX,
                                        should_trunc, n_written, new_str);
}

bool sbp_msg_fileio_remove_filename_set_raw(sbp_msg_fileio_remove_t *msg,
                                            const char *new_buf,
                                            size_t new_buf_len,
                                            bool should_trunc,
                                            size_t *n_written) {
  return sbp_null_terminated_string_set_raw(
      &msg->filename, SBP_MSG_FILEIO_REMOVE_FILENAME_MAX, should_trunc,
      n_written, new_buf, new_buf_len);
}

bool sbp_msg_fileio_remove_filename_printf(sbp_msg_fileio_remove_t *msg,
                                           bool should_trunc, size_t *n_written,
                                           const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_null_terminated_string_vprintf(
      &msg->filename, SBP_MSG_FILEIO_REMOVE_FILENAME_MAX, should_trunc,
      n_written, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_fileio_remove_filename_vprintf(sbp_msg_fileio_remove_t *msg,
                                            bool should_trunc,
                                            size_t *n_written, const char *fmt,
                                            va_list ap) {
  return sbp_null_terminated_string_vprintf(&msg->filename,
                                            SBP_MSG_FILEIO_REMOVE_FILENAME_MAX,
                                            should_trunc, n_written, fmt, ap);
}

bool sbp_msg_fileio_remove_filename_append_printf(sbp_msg_fileio_remove_t *msg,
                                                  bool should_trunc,
                                                  size_t *n_written,
                                                  const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_null_terminated_string_append_vprintf(
      &msg->filename, SBP_MSG_FILEIO_REMOVE_FILENAME_MAX, should_trunc,
      n_written, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_fileio_remove_filename_append_vprintf(sbp_msg_fileio_remove_t *msg,
                                                   bool should_trunc,
                                                   size_t *n_written,
                                                   const char *fmt,
                                                   va_list ap) {
  return sbp_null_terminated_string_append_vprintf(
      &msg->filename, SBP_MSG_FILEIO_REMOVE_FILENAME_MAX, should_trunc,
      n_written, fmt, ap);
}

const char *sbp_msg_fileio_remove_filename_get(
    const sbp_msg_fileio_remove_t *msg) {
  return sbp_null_terminated_string_get(&msg->filename,
                                        SBP_MSG_FILEIO_REMOVE_FILENAME_MAX);
}

size_t sbp_msg_fileio_remove_filename_strlen(
    const sbp_msg_fileio_remove_t *msg) {
  return sbp_null_terminated_string_strlen(&msg->filename,
                                           SBP_MSG_FILEIO_REMOVE_FILENAME_MAX);
}

bool sbp_msg_fileio_remove_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_msg_fileio_remove_t *msg) {
  if (!sbp_null_terminated_string_encode(
          &msg->filename, SBP_MSG_FILEIO_REMOVE_FILENAME_MAX, ctx)) {
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
  if (!sbp_null_terminated_string_decode(
          &msg->filename, SBP_MSG_FILEIO_REMOVE_FILENAME_MAX, ctx)) {
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

s8 sbp_msg_fileio_remove_send(sbp_state_t *s, u16 sender_id,
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

  ret = sbp_msg_fileio_remove_filename_strcmp(a, b);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

void sbp_msg_fileio_write_req_filename_init(sbp_msg_fileio_write_req_t *msg) {
  sbp_null_terminated_string_init(&msg->filename);
}

bool sbp_msg_fileio_write_req_filename_valid(
    const sbp_msg_fileio_write_req_t *msg) {
  return sbp_null_terminated_string_valid(
      &msg->filename, SBP_MSG_FILEIO_WRITE_REQ_FILENAME_MAX);
}

int sbp_msg_fileio_write_req_filename_strcmp(
    const sbp_msg_fileio_write_req_t *a, const sbp_msg_fileio_write_req_t *b) {
  return sbp_null_terminated_string_strcmp(
      &a->filename, &b->filename, SBP_MSG_FILEIO_WRITE_REQ_FILENAME_MAX);
}

size_t sbp_msg_fileio_write_req_filename_encoded_len(
    const sbp_msg_fileio_write_req_t *msg) {
  return sbp_null_terminated_string_encoded_len(
      &msg->filename, SBP_MSG_FILEIO_WRITE_REQ_FILENAME_MAX);
}

size_t sbp_msg_fileio_write_req_filename_space_remaining(
    const sbp_msg_fileio_write_req_t *msg) {
  return sbp_null_terminated_string_space_remaining(
      &msg->filename, SBP_MSG_FILEIO_WRITE_REQ_FILENAME_MAX);
}
bool sbp_msg_fileio_write_req_filename_set(sbp_msg_fileio_write_req_t *msg,
                                           const char *new_str,
                                           bool should_trunc,
                                           size_t *n_written) {
  return sbp_null_terminated_string_set(&msg->filename,
                                        SBP_MSG_FILEIO_WRITE_REQ_FILENAME_MAX,
                                        should_trunc, n_written, new_str);
}

bool sbp_msg_fileio_write_req_filename_set_raw(sbp_msg_fileio_write_req_t *msg,
                                               const char *new_buf,
                                               size_t new_buf_len,
                                               bool should_trunc,
                                               size_t *n_written) {
  return sbp_null_terminated_string_set_raw(
      &msg->filename, SBP_MSG_FILEIO_WRITE_REQ_FILENAME_MAX, should_trunc,
      n_written, new_buf, new_buf_len);
}

bool sbp_msg_fileio_write_req_filename_printf(sbp_msg_fileio_write_req_t *msg,
                                              bool should_trunc,
                                              size_t *n_written,
                                              const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_null_terminated_string_vprintf(
      &msg->filename, SBP_MSG_FILEIO_WRITE_REQ_FILENAME_MAX, should_trunc,
      n_written, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_fileio_write_req_filename_vprintf(sbp_msg_fileio_write_req_t *msg,
                                               bool should_trunc,
                                               size_t *n_written,
                                               const char *fmt, va_list ap) {
  return sbp_null_terminated_string_vprintf(
      &msg->filename, SBP_MSG_FILEIO_WRITE_REQ_FILENAME_MAX, should_trunc,
      n_written, fmt, ap);
}

bool sbp_msg_fileio_write_req_filename_append_printf(
    sbp_msg_fileio_write_req_t *msg, bool should_trunc, size_t *n_written,
    const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_null_terminated_string_append_vprintf(
      &msg->filename, SBP_MSG_FILEIO_WRITE_REQ_FILENAME_MAX, should_trunc,
      n_written, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_fileio_write_req_filename_append_vprintf(
    sbp_msg_fileio_write_req_t *msg, bool should_trunc, size_t *n_written,
    const char *fmt, va_list ap) {
  return sbp_null_terminated_string_append_vprintf(
      &msg->filename, SBP_MSG_FILEIO_WRITE_REQ_FILENAME_MAX, should_trunc,
      n_written, fmt, ap);
}

const char *sbp_msg_fileio_write_req_filename_get(
    const sbp_msg_fileio_write_req_t *msg) {
  return sbp_null_terminated_string_get(&msg->filename,
                                        SBP_MSG_FILEIO_WRITE_REQ_FILENAME_MAX);
}

size_t sbp_msg_fileio_write_req_filename_strlen(
    const sbp_msg_fileio_write_req_t *msg) {
  return sbp_null_terminated_string_strlen(
      &msg->filename, SBP_MSG_FILEIO_WRITE_REQ_FILENAME_MAX);
}

bool sbp_msg_fileio_write_req_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_fileio_write_req_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->sequence)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->offset)) {
    return false;
  }
  if (!sbp_null_terminated_string_encode(
          &msg->filename, SBP_MSG_FILEIO_WRITE_REQ_FILENAME_MAX, ctx)) {
    return false;
  }
  for (size_t i = 0; i < msg->n_data; i++) {
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
  if (!sbp_null_terminated_string_decode(
          &msg->filename, SBP_MSG_FILEIO_WRITE_REQ_FILENAME_MAX, ctx)) {
    return false;
  }
  msg->n_data = (uint8_t)((ctx->buf_len - ctx->offset) / SBP_ENCODED_LEN_U8);
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

s8 sbp_msg_fileio_write_req_send(sbp_state_t *s, u16 sender_id,
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

  ret = sbp_msg_fileio_write_req_filename_strcmp(a, b);
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

s8 sbp_msg_fileio_write_resp_send(sbp_state_t *s, u16 sender_id,
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

s8 sbp_msg_fileio_config_req_send(sbp_state_t *s, u16 sender_id,
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

s8 sbp_msg_fileio_config_resp_send(sbp_state_t *s, u16 sender_id,
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
