#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <libsbp/sbp.h>
#include <libsbp/internal/unpacked/common.h>
#include <libsbp/unpacked/file_io.h>
#include <libsbp/internal/unpacked/file_io.h>
#include <libsbp/internal/unpacked/string/multipart.h>
#include <libsbp/internal/unpacked/string/null_terminated.h>
#include <libsbp/internal/unpacked/string/double_null_terminated.h>
#include <libsbp/internal/unpacked/string/unterminated.h>
#include <libsbp/internal/unpacked/string/binary.h>
static const sbp_null_terminated_string_params_t sbp_msg_fileio_read_req_tfilename_params = 
{
  .max_packed_len = 246
};

  void sbp_msg_fileio_read_req_t_filename_init(sbp_null_terminated_string_t *s)
{
  sbp_null_terminated_string_init(s, &sbp_msg_fileio_read_req_tfilename_params);
}

  bool sbp_msg_fileio_read_req_t_filename_valid(const sbp_null_terminated_string_t *s)
{
  return sbp_null_terminated_string_valid(s, &sbp_msg_fileio_read_req_tfilename_params);
}

  int sbp_msg_fileio_read_req_t_filename_strcmp(const sbp_null_terminated_string_t *a, const sbp_null_terminated_string_t *b)
{
  return sbp_null_terminated_string_strcmp(a, b, &sbp_msg_fileio_read_req_tfilename_params);
}

  uint8_t sbp_msg_fileio_read_req_t_filename_packed_len(const sbp_null_terminated_string_t *s)
{
  return sbp_null_terminated_string_packed_len(s, &sbp_msg_fileio_read_req_tfilename_params);
}

  uint8_t sbp_msg_fileio_read_req_t_filename_space_remaining(const sbp_null_terminated_string_t *s)
{
  return sbp_null_terminated_string_space_remaining(s, &sbp_msg_fileio_read_req_tfilename_params);
      }
  bool sbp_msg_fileio_read_req_t_filename_set(sbp_null_terminated_string_t *s, const char *new_str)
  {
  return sbp_null_terminated_string_set(s, &sbp_msg_fileio_read_req_tfilename_params, new_str);
  }

  bool sbp_msg_fileio_read_req_t_filename_printf(sbp_null_terminated_string_t *s, const char *fmt, ...) 
  {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_null_terminated_string_vprintf(s, &sbp_msg_fileio_read_req_tfilename_params, fmt, ap);
  va_end(ap);
  return ret;
  }

  bool sbp_msg_fileio_read_req_t_filename_vprintf(sbp_null_terminated_string_t *s, const char *fmt, va_list ap)
  {
  return sbp_null_terminated_string_vprintf(s, &sbp_msg_fileio_read_req_tfilename_params, fmt, ap);
  }

  bool sbp_msg_fileio_read_req_t_filename_append_printf(sbp_null_terminated_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_null_terminated_string_append_vprintf(s, &sbp_msg_fileio_read_req_tfilename_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_fileio_read_req_t_filename_append_vprintf(sbp_null_terminated_string_t *s, const char *fmt, va_list ap)
{
  return sbp_null_terminated_string_append_vprintf(s, &sbp_msg_fileio_read_req_tfilename_params, fmt, ap);
}

  const char *sbp_msg_fileio_read_req_t_filename_get(const sbp_null_terminated_string_t *s)
{
  return sbp_null_terminated_string_get(s, &sbp_msg_fileio_read_req_tfilename_params);
}

size_t sbp_packed_size_sbp_msg_fileio_read_req_t(const sbp_msg_fileio_read_req_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->sequence);
  packed_size += sbp_packed_size_u32(&msg->offset);
  packed_size += sbp_packed_size_u8(&msg->chunk_size);
  packed_size += sbp_null_terminated_string_packed_len(&msg->filename, &sbp_msg_fileio_read_req_tfilename_params);
  return packed_size;
}

bool pack_sbp_msg_fileio_read_req_t(sbp_pack_ctx_t *ctx, const sbp_msg_fileio_read_req_t *msg)
{
  if (!pack_u32(ctx, &msg->sequence)) { return false; }
  if (!pack_u32(ctx, &msg->offset)) { return false; }
  if (!pack_u8(ctx, &msg->chunk_size)) { return false; }
  if (!sbp_null_terminated_string_pack(&msg->filename, &sbp_msg_fileio_read_req_tfilename_params, ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_fileio_read_req_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_fileio_read_req_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_fileio_read_req_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_fileio_read_req_t(sbp_unpack_ctx_t *ctx, sbp_msg_fileio_read_req_t *msg)
{
  if (!unpack_u32(ctx, &msg->sequence)) { return false; }
  if (!unpack_u32(ctx, &msg->offset)) { return false; }
  if (!unpack_u8(ctx, &msg->chunk_size)) { return false; }
  if (!sbp_null_terminated_string_unpack(&msg->filename, &sbp_msg_fileio_read_req_tfilename_params, ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_fileio_read_req_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_fileio_read_req_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_fileio_read_req_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_fileio_read_req_t(const sbp_msg_fileio_read_req_t *a, const sbp_msg_fileio_read_req_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->sequence, &b->sequence);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->offset, &b->offset);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->chunk_size, &b->chunk_size);
  if (ret != 0) { return ret; }
  
  ret = sbp_null_terminated_string_strcmp(&a->filename, &b->filename, &sbp_msg_fileio_read_req_tfilename_params);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_fileio_read_resp_t(const sbp_msg_fileio_read_resp_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->sequence);
  packed_size += (msg->n_contents * sbp_packed_size_u8(&msg->contents[0]));
  return packed_size;
}

bool pack_sbp_msg_fileio_read_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_fileio_read_resp_t *msg)
{
  if (!pack_u32(ctx, &msg->sequence)) { return false; }
  for (uint8_t i = 0; i < msg->n_contents; i++)
  {
    if (!pack_u8(ctx, &msg->contents[i])) { return false; }
  }
  return true;
}

s8 sbp_pack_sbp_msg_fileio_read_resp_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_fileio_read_resp_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_fileio_read_resp_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_fileio_read_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_fileio_read_resp_t *msg)
{
  if (!unpack_u32(ctx, &msg->sequence)) { return false; }
    msg->n_contents = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_u8(&msg->contents[0]));
  for (uint8_t i = 0; i < msg->n_contents; i++) {
    if (!unpack_u8(ctx, &msg->contents[i])) { return false; }
  }
  return true;
}

s8 sbp_unpack_sbp_msg_fileio_read_resp_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_fileio_read_resp_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_fileio_read_resp_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_fileio_read_resp_t(const sbp_msg_fileio_read_resp_t *a, const sbp_msg_fileio_read_resp_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->sequence, &b->sequence);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_contents, &b->n_contents);
  for (uint8_t i = 0; i < a->n_contents && ret == 0; i++)
  {
    ret = sbp_cmp_u8(&a->contents[i], &b->contents[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}
static const sbp_null_terminated_string_params_t sbp_msg_fileio_read_dir_req_tdirname_params = 
{
  .max_packed_len = 247
};

  void sbp_msg_fileio_read_dir_req_t_dirname_init(sbp_null_terminated_string_t *s)
{
  sbp_null_terminated_string_init(s, &sbp_msg_fileio_read_dir_req_tdirname_params);
}

  bool sbp_msg_fileio_read_dir_req_t_dirname_valid(const sbp_null_terminated_string_t *s)
{
  return sbp_null_terminated_string_valid(s, &sbp_msg_fileio_read_dir_req_tdirname_params);
}

  int sbp_msg_fileio_read_dir_req_t_dirname_strcmp(const sbp_null_terminated_string_t *a, const sbp_null_terminated_string_t *b)
{
  return sbp_null_terminated_string_strcmp(a, b, &sbp_msg_fileio_read_dir_req_tdirname_params);
}

  uint8_t sbp_msg_fileio_read_dir_req_t_dirname_packed_len(const sbp_null_terminated_string_t *s)
{
  return sbp_null_terminated_string_packed_len(s, &sbp_msg_fileio_read_dir_req_tdirname_params);
}

  uint8_t sbp_msg_fileio_read_dir_req_t_dirname_space_remaining(const sbp_null_terminated_string_t *s)
{
  return sbp_null_terminated_string_space_remaining(s, &sbp_msg_fileio_read_dir_req_tdirname_params);
      }
  bool sbp_msg_fileio_read_dir_req_t_dirname_set(sbp_null_terminated_string_t *s, const char *new_str)
  {
  return sbp_null_terminated_string_set(s, &sbp_msg_fileio_read_dir_req_tdirname_params, new_str);
  }

  bool sbp_msg_fileio_read_dir_req_t_dirname_printf(sbp_null_terminated_string_t *s, const char *fmt, ...) 
  {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_null_terminated_string_vprintf(s, &sbp_msg_fileio_read_dir_req_tdirname_params, fmt, ap);
  va_end(ap);
  return ret;
  }

  bool sbp_msg_fileio_read_dir_req_t_dirname_vprintf(sbp_null_terminated_string_t *s, const char *fmt, va_list ap)
  {
  return sbp_null_terminated_string_vprintf(s, &sbp_msg_fileio_read_dir_req_tdirname_params, fmt, ap);
  }

  bool sbp_msg_fileio_read_dir_req_t_dirname_append_printf(sbp_null_terminated_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_null_terminated_string_append_vprintf(s, &sbp_msg_fileio_read_dir_req_tdirname_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_fileio_read_dir_req_t_dirname_append_vprintf(sbp_null_terminated_string_t *s, const char *fmt, va_list ap)
{
  return sbp_null_terminated_string_append_vprintf(s, &sbp_msg_fileio_read_dir_req_tdirname_params, fmt, ap);
}

  const char *sbp_msg_fileio_read_dir_req_t_dirname_get(const sbp_null_terminated_string_t *s)
{
  return sbp_null_terminated_string_get(s, &sbp_msg_fileio_read_dir_req_tdirname_params);
}

size_t sbp_packed_size_sbp_msg_fileio_read_dir_req_t(const sbp_msg_fileio_read_dir_req_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->sequence);
  packed_size += sbp_packed_size_u32(&msg->offset);
  packed_size += sbp_null_terminated_string_packed_len(&msg->dirname, &sbp_msg_fileio_read_dir_req_tdirname_params);
  return packed_size;
}

bool pack_sbp_msg_fileio_read_dir_req_t(sbp_pack_ctx_t *ctx, const sbp_msg_fileio_read_dir_req_t *msg)
{
  if (!pack_u32(ctx, &msg->sequence)) { return false; }
  if (!pack_u32(ctx, &msg->offset)) { return false; }
  if (!sbp_null_terminated_string_pack(&msg->dirname, &sbp_msg_fileio_read_dir_req_tdirname_params, ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_fileio_read_dir_req_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_fileio_read_dir_req_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_fileio_read_dir_req_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_fileio_read_dir_req_t(sbp_unpack_ctx_t *ctx, sbp_msg_fileio_read_dir_req_t *msg)
{
  if (!unpack_u32(ctx, &msg->sequence)) { return false; }
  if (!unpack_u32(ctx, &msg->offset)) { return false; }
  if (!sbp_null_terminated_string_unpack(&msg->dirname, &sbp_msg_fileio_read_dir_req_tdirname_params, ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_fileio_read_dir_req_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_fileio_read_dir_req_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_fileio_read_dir_req_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_fileio_read_dir_req_t(const sbp_msg_fileio_read_dir_req_t *a, const sbp_msg_fileio_read_dir_req_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->sequence, &b->sequence);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->offset, &b->offset);
  if (ret != 0) { return ret; }
  
  ret = sbp_null_terminated_string_strcmp(&a->dirname, &b->dirname, &sbp_msg_fileio_read_dir_req_tdirname_params);
  if (ret != 0) { return ret; }
  return ret;
}
static const sbp_multipart_string_params_t sbp_msg_fileio_read_dir_resp_tcontents_params = 
{
  .max_packed_len = 251
};

  void sbp_msg_fileio_read_dir_resp_t_contents_init(sbp_multipart_string_t *s)
{
  sbp_multipart_string_init(s, &sbp_msg_fileio_read_dir_resp_tcontents_params);
}

  bool sbp_msg_fileio_read_dir_resp_t_contents_valid(const sbp_multipart_string_t *s)
{
  return sbp_multipart_string_valid(s, &sbp_msg_fileio_read_dir_resp_tcontents_params);
}

  int sbp_msg_fileio_read_dir_resp_t_contents_strcmp(const sbp_multipart_string_t *a, const sbp_multipart_string_t *b)
{
  return sbp_multipart_string_strcmp(a, b, &sbp_msg_fileio_read_dir_resp_tcontents_params);
}

  uint8_t sbp_msg_fileio_read_dir_resp_t_contents_packed_len(const sbp_multipart_string_t *s)
{
  return sbp_multipart_string_packed_len(s, &sbp_msg_fileio_read_dir_resp_tcontents_params);
}

  uint8_t sbp_msg_fileio_read_dir_resp_t_contents_space_remaining(const sbp_multipart_string_t *s)
{
  return sbp_multipart_string_space_remaining(s, &sbp_msg_fileio_read_dir_resp_tcontents_params);
      }
  uint8_t sbp_msg_fileio_read_dir_resp_t_contents_count_sections(const sbp_multipart_string_t *s)
{
  return sbp_multipart_string_count_sections(s, &sbp_msg_fileio_read_dir_resp_tcontents_params);
}

  bool sbp_msg_fileio_read_dir_resp_t_contents_add_section(sbp_multipart_string_t *s, const char *new_str)
{
  return sbp_multipart_string_add_section(s, &sbp_msg_fileio_read_dir_resp_tcontents_params, new_str);
}

  bool sbp_msg_fileio_read_dir_resp_t_contents_add_section_printf(sbp_multipart_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_multipart_string_add_section_vprintf(s, &sbp_msg_fileio_read_dir_resp_tcontents_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_fileio_read_dir_resp_t_contents_add_section_vprintf(sbp_multipart_string_t *s, const char *fmt, va_list ap)
{
  return sbp_multipart_string_add_section_vprintf(s, &sbp_msg_fileio_read_dir_resp_tcontents_params, fmt, ap);
}

  bool sbp_msg_fileio_read_dir_resp_t_contents_append(sbp_multipart_string_t *s, const char *str)
{
  return sbp_multipart_string_append(s, &sbp_msg_fileio_read_dir_resp_tcontents_params, str);
}

  bool sbp_msg_fileio_read_dir_resp_t_contents_append_printf(sbp_multipart_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_multipart_string_append_vprintf(s, &sbp_msg_fileio_read_dir_resp_tcontents_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_fileio_read_dir_resp_t_contents_append_vprintf(sbp_multipart_string_t *s, const char *fmt, va_list ap)
{
  return sbp_multipart_string_append_vprintf(s, &sbp_msg_fileio_read_dir_resp_tcontents_params, fmt, ap);
}

  const char *sbp_msg_fileio_read_dir_resp_t_contents_get_section(const sbp_multipart_string_t *s, uint8_t section)
{
  return sbp_multipart_string_get_section(s, &sbp_msg_fileio_read_dir_resp_tcontents_params, section);
}

  uint8_t sbp_msg_fileio_read_dir_resp_t_contents_section_strlen(const sbp_multipart_string_t *s, uint8_t section)
{
  return sbp_multipart_string_section_strlen(s, &sbp_msg_fileio_read_dir_resp_tcontents_params, section);
}

size_t sbp_packed_size_sbp_msg_fileio_read_dir_resp_t(const sbp_msg_fileio_read_dir_resp_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->sequence);
  packed_size += sbp_multipart_string_packed_len(&msg->contents, &sbp_msg_fileio_read_dir_resp_tcontents_params);
  return packed_size;
}

bool pack_sbp_msg_fileio_read_dir_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_fileio_read_dir_resp_t *msg)
{
  if (!pack_u32(ctx, &msg->sequence)) { return false; }
  if (!sbp_multipart_string_pack(&msg->contents, &sbp_msg_fileio_read_dir_resp_tcontents_params, ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_fileio_read_dir_resp_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_fileio_read_dir_resp_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_fileio_read_dir_resp_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_fileio_read_dir_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_fileio_read_dir_resp_t *msg)
{
  if (!unpack_u32(ctx, &msg->sequence)) { return false; }
  if (!sbp_multipart_string_unpack(&msg->contents, &sbp_msg_fileio_read_dir_resp_tcontents_params, ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_fileio_read_dir_resp_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_fileio_read_dir_resp_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_fileio_read_dir_resp_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_fileio_read_dir_resp_t(const sbp_msg_fileio_read_dir_resp_t *a, const sbp_msg_fileio_read_dir_resp_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->sequence, &b->sequence);
  if (ret != 0) { return ret; }
  
  ret = sbp_multipart_string_strcmp(&a->contents, &b->contents, &sbp_msg_fileio_read_dir_resp_tcontents_params);
  if (ret != 0) { return ret; }
  return ret;
}
static const sbp_null_terminated_string_params_t sbp_msg_fileio_remove_tfilename_params = 
{
  .max_packed_len = 255
};

  void sbp_msg_fileio_remove_t_filename_init(sbp_null_terminated_string_t *s)
{
  sbp_null_terminated_string_init(s, &sbp_msg_fileio_remove_tfilename_params);
}

  bool sbp_msg_fileio_remove_t_filename_valid(const sbp_null_terminated_string_t *s)
{
  return sbp_null_terminated_string_valid(s, &sbp_msg_fileio_remove_tfilename_params);
}

  int sbp_msg_fileio_remove_t_filename_strcmp(const sbp_null_terminated_string_t *a, const sbp_null_terminated_string_t *b)
{
  return sbp_null_terminated_string_strcmp(a, b, &sbp_msg_fileio_remove_tfilename_params);
}

  uint8_t sbp_msg_fileio_remove_t_filename_packed_len(const sbp_null_terminated_string_t *s)
{
  return sbp_null_terminated_string_packed_len(s, &sbp_msg_fileio_remove_tfilename_params);
}

  uint8_t sbp_msg_fileio_remove_t_filename_space_remaining(const sbp_null_terminated_string_t *s)
{
  return sbp_null_terminated_string_space_remaining(s, &sbp_msg_fileio_remove_tfilename_params);
      }
  bool sbp_msg_fileio_remove_t_filename_set(sbp_null_terminated_string_t *s, const char *new_str)
  {
  return sbp_null_terminated_string_set(s, &sbp_msg_fileio_remove_tfilename_params, new_str);
  }

  bool sbp_msg_fileio_remove_t_filename_printf(sbp_null_terminated_string_t *s, const char *fmt, ...) 
  {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_null_terminated_string_vprintf(s, &sbp_msg_fileio_remove_tfilename_params, fmt, ap);
  va_end(ap);
  return ret;
  }

  bool sbp_msg_fileio_remove_t_filename_vprintf(sbp_null_terminated_string_t *s, const char *fmt, va_list ap)
  {
  return sbp_null_terminated_string_vprintf(s, &sbp_msg_fileio_remove_tfilename_params, fmt, ap);
  }

  bool sbp_msg_fileio_remove_t_filename_append_printf(sbp_null_terminated_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_null_terminated_string_append_vprintf(s, &sbp_msg_fileio_remove_tfilename_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_fileio_remove_t_filename_append_vprintf(sbp_null_terminated_string_t *s, const char *fmt, va_list ap)
{
  return sbp_null_terminated_string_append_vprintf(s, &sbp_msg_fileio_remove_tfilename_params, fmt, ap);
}

  const char *sbp_msg_fileio_remove_t_filename_get(const sbp_null_terminated_string_t *s)
{
  return sbp_null_terminated_string_get(s, &sbp_msg_fileio_remove_tfilename_params);
}

size_t sbp_packed_size_sbp_msg_fileio_remove_t(const sbp_msg_fileio_remove_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_null_terminated_string_packed_len(&msg->filename, &sbp_msg_fileio_remove_tfilename_params);
  return packed_size;
}

bool pack_sbp_msg_fileio_remove_t(sbp_pack_ctx_t *ctx, const sbp_msg_fileio_remove_t *msg)
{
  if (!sbp_null_terminated_string_pack(&msg->filename, &sbp_msg_fileio_remove_tfilename_params, ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_fileio_remove_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_fileio_remove_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_fileio_remove_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_fileio_remove_t(sbp_unpack_ctx_t *ctx, sbp_msg_fileio_remove_t *msg)
{
  if (!sbp_null_terminated_string_unpack(&msg->filename, &sbp_msg_fileio_remove_tfilename_params, ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_fileio_remove_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_fileio_remove_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_fileio_remove_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_fileio_remove_t(const sbp_msg_fileio_remove_t *a, const sbp_msg_fileio_remove_t *b) {
  int ret = 0;
  
  ret = sbp_null_terminated_string_strcmp(&a->filename, &b->filename, &sbp_msg_fileio_remove_tfilename_params);
  if (ret != 0) { return ret; }
  return ret;
}
static const sbp_null_terminated_string_params_t sbp_msg_fileio_write_req_tfilename_params = 
{
  .max_packed_len = 247
};

  void sbp_msg_fileio_write_req_t_filename_init(sbp_null_terminated_string_t *s)
{
  sbp_null_terminated_string_init(s, &sbp_msg_fileio_write_req_tfilename_params);
}

  bool sbp_msg_fileio_write_req_t_filename_valid(const sbp_null_terminated_string_t *s)
{
  return sbp_null_terminated_string_valid(s, &sbp_msg_fileio_write_req_tfilename_params);
}

  int sbp_msg_fileio_write_req_t_filename_strcmp(const sbp_null_terminated_string_t *a, const sbp_null_terminated_string_t *b)
{
  return sbp_null_terminated_string_strcmp(a, b, &sbp_msg_fileio_write_req_tfilename_params);
}

  uint8_t sbp_msg_fileio_write_req_t_filename_packed_len(const sbp_null_terminated_string_t *s)
{
  return sbp_null_terminated_string_packed_len(s, &sbp_msg_fileio_write_req_tfilename_params);
}

  uint8_t sbp_msg_fileio_write_req_t_filename_space_remaining(const sbp_null_terminated_string_t *s)
{
  return sbp_null_terminated_string_space_remaining(s, &sbp_msg_fileio_write_req_tfilename_params);
      }
  bool sbp_msg_fileio_write_req_t_filename_set(sbp_null_terminated_string_t *s, const char *new_str)
  {
  return sbp_null_terminated_string_set(s, &sbp_msg_fileio_write_req_tfilename_params, new_str);
  }

  bool sbp_msg_fileio_write_req_t_filename_printf(sbp_null_terminated_string_t *s, const char *fmt, ...) 
  {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_null_terminated_string_vprintf(s, &sbp_msg_fileio_write_req_tfilename_params, fmt, ap);
  va_end(ap);
  return ret;
  }

  bool sbp_msg_fileio_write_req_t_filename_vprintf(sbp_null_terminated_string_t *s, const char *fmt, va_list ap)
  {
  return sbp_null_terminated_string_vprintf(s, &sbp_msg_fileio_write_req_tfilename_params, fmt, ap);
  }

  bool sbp_msg_fileio_write_req_t_filename_append_printf(sbp_null_terminated_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_null_terminated_string_append_vprintf(s, &sbp_msg_fileio_write_req_tfilename_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_fileio_write_req_t_filename_append_vprintf(sbp_null_terminated_string_t *s, const char *fmt, va_list ap)
{
  return sbp_null_terminated_string_append_vprintf(s, &sbp_msg_fileio_write_req_tfilename_params, fmt, ap);
}

  const char *sbp_msg_fileio_write_req_t_filename_get(const sbp_null_terminated_string_t *s)
{
  return sbp_null_terminated_string_get(s, &sbp_msg_fileio_write_req_tfilename_params);
}

size_t sbp_packed_size_sbp_msg_fileio_write_req_t(const sbp_msg_fileio_write_req_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->sequence);
  packed_size += sbp_packed_size_u32(&msg->offset);
  packed_size += sbp_null_terminated_string_packed_len(&msg->filename, &sbp_msg_fileio_write_req_tfilename_params);
  packed_size += (msg->n_data * sbp_packed_size_u8(&msg->data[0]));
  return packed_size;
}

bool pack_sbp_msg_fileio_write_req_t(sbp_pack_ctx_t *ctx, const sbp_msg_fileio_write_req_t *msg)
{
  if (!pack_u32(ctx, &msg->sequence)) { return false; }
  if (!pack_u32(ctx, &msg->offset)) { return false; }
  if (!sbp_null_terminated_string_pack(&msg->filename, &sbp_msg_fileio_write_req_tfilename_params, ctx)) { return false; }
  for (uint8_t i = 0; i < msg->n_data; i++)
  {
    if (!pack_u8(ctx, &msg->data[i])) { return false; }
  }
  return true;
}

s8 sbp_pack_sbp_msg_fileio_write_req_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_fileio_write_req_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_fileio_write_req_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_fileio_write_req_t(sbp_unpack_ctx_t *ctx, sbp_msg_fileio_write_req_t *msg)
{
  if (!unpack_u32(ctx, &msg->sequence)) { return false; }
  if (!unpack_u32(ctx, &msg->offset)) { return false; }
  if (!sbp_null_terminated_string_unpack(&msg->filename, &sbp_msg_fileio_write_req_tfilename_params, ctx)) { return false; }
    msg->n_data = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_u8(&msg->data[0]));
  for (uint8_t i = 0; i < msg->n_data; i++) {
    if (!unpack_u8(ctx, &msg->data[i])) { return false; }
  }
  return true;
}

s8 sbp_unpack_sbp_msg_fileio_write_req_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_fileio_write_req_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_fileio_write_req_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_fileio_write_req_t(const sbp_msg_fileio_write_req_t *a, const sbp_msg_fileio_write_req_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->sequence, &b->sequence);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->offset, &b->offset);
  if (ret != 0) { return ret; }
  
  ret = sbp_null_terminated_string_strcmp(&a->filename, &b->filename, &sbp_msg_fileio_write_req_tfilename_params);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_data, &b->n_data);
  for (uint8_t i = 0; i < a->n_data && ret == 0; i++)
  {
    ret = sbp_cmp_u8(&a->data[i], &b->data[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_fileio_write_resp_t(const sbp_msg_fileio_write_resp_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->sequence);
  return packed_size;
}

bool pack_sbp_msg_fileio_write_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_fileio_write_resp_t *msg)
{
  if (!pack_u32(ctx, &msg->sequence)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_fileio_write_resp_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_fileio_write_resp_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_fileio_write_resp_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_fileio_write_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_fileio_write_resp_t *msg)
{
  if (!unpack_u32(ctx, &msg->sequence)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_fileio_write_resp_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_fileio_write_resp_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_fileio_write_resp_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_fileio_write_resp_t(const sbp_msg_fileio_write_resp_t *a, const sbp_msg_fileio_write_resp_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->sequence, &b->sequence);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_fileio_config_req_t(const sbp_msg_fileio_config_req_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->sequence);
  return packed_size;
}

bool pack_sbp_msg_fileio_config_req_t(sbp_pack_ctx_t *ctx, const sbp_msg_fileio_config_req_t *msg)
{
  if (!pack_u32(ctx, &msg->sequence)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_fileio_config_req_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_fileio_config_req_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_fileio_config_req_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_fileio_config_req_t(sbp_unpack_ctx_t *ctx, sbp_msg_fileio_config_req_t *msg)
{
  if (!unpack_u32(ctx, &msg->sequence)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_fileio_config_req_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_fileio_config_req_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_fileio_config_req_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_fileio_config_req_t(const sbp_msg_fileio_config_req_t *a, const sbp_msg_fileio_config_req_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->sequence, &b->sequence);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_fileio_config_resp_t(const sbp_msg_fileio_config_resp_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->sequence);
  packed_size += sbp_packed_size_u32(&msg->window_size);
  packed_size += sbp_packed_size_u32(&msg->batch_size);
  packed_size += sbp_packed_size_u32(&msg->fileio_version);
  return packed_size;
}

bool pack_sbp_msg_fileio_config_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_fileio_config_resp_t *msg)
{
  if (!pack_u32(ctx, &msg->sequence)) { return false; }
  if (!pack_u32(ctx, &msg->window_size)) { return false; }
  if (!pack_u32(ctx, &msg->batch_size)) { return false; }
  if (!pack_u32(ctx, &msg->fileio_version)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_fileio_config_resp_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_fileio_config_resp_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_fileio_config_resp_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_fileio_config_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_fileio_config_resp_t *msg)
{
  if (!unpack_u32(ctx, &msg->sequence)) { return false; }
  if (!unpack_u32(ctx, &msg->window_size)) { return false; }
  if (!unpack_u32(ctx, &msg->batch_size)) { return false; }
  if (!unpack_u32(ctx, &msg->fileio_version)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_fileio_config_resp_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_fileio_config_resp_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_fileio_config_resp_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_fileio_config_resp_t(const sbp_msg_fileio_config_resp_t *a, const sbp_msg_fileio_config_resp_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->sequence, &b->sequence);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->window_size, &b->window_size);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->batch_size, &b->batch_size);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->fileio_version, &b->fileio_version);
  if (ret != 0) { return ret; }
  return ret;
}
