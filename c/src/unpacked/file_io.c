#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <libsbp/sbp.h>
#include <libsbp/internal/unpacked/common.h>
#include <libsbp/unpacked/file_io.h>
#include <libsbp/internal/unpacked/file_io.h>
#include <libsbp/internal/unpacked/string/multipart.h>
#include <libsbp/internal/unpacked/string/null_terminated.h>
#include <libsbp/internal/unpacked/string/sequence.h>
#include <libsbp/internal/unpacked/string/unterminated.h>
#include <libsbp/internal/unpacked/string/binary.h>
                                                                                                              
size_t sbp_packed_size_sbp_msg_fileio_read_req_t(const sbp_msg_fileio_read_req_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->sequence);
  packed_size += sbp_packed_size_u32(&msg->offset);
  packed_size += sbp_packed_size_u8(&msg->chunk_size);
  packed_size += sbp_null_terminated_string_packed_len(&msg->filename, 246
      );
  return packed_size;
}

bool pack_sbp_msg_fileio_read_req_t(sbp_pack_ctx_t *ctx, const sbp_msg_fileio_read_req_t *msg)
{
  if (!pack_u32(ctx, &msg->sequence)) { return false; }
  if (!pack_u32(ctx, &msg->offset)) { return false; }
  if (!pack_u8(ctx, &msg->chunk_size)) { return false; }
  if (!sbp_null_terminated_string_pack(&msg->filename, 246,
      ctx)) { return false; }
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
  if (!sbp_null_terminated_string_unpack(&msg->filename, 246,
      ctx)) { return false; }
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
  
  ret = sbp_null_terminated_string_strcmp(&a->filename, &b->filename, 246
    );
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
                                                                                                              
size_t sbp_packed_size_sbp_msg_fileio_read_dir_req_t(const sbp_msg_fileio_read_dir_req_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->sequence);
  packed_size += sbp_packed_size_u32(&msg->offset);
  packed_size += sbp_null_terminated_string_packed_len(&msg->dirname, 247
      );
  return packed_size;
}

bool pack_sbp_msg_fileio_read_dir_req_t(sbp_pack_ctx_t *ctx, const sbp_msg_fileio_read_dir_req_t *msg)
{
  if (!pack_u32(ctx, &msg->sequence)) { return false; }
  if (!pack_u32(ctx, &msg->offset)) { return false; }
  if (!sbp_null_terminated_string_pack(&msg->dirname, 247,
      ctx)) { return false; }
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
  if (!sbp_null_terminated_string_unpack(&msg->dirname, 247,
      ctx)) { return false; }
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
  
  ret = sbp_null_terminated_string_strcmp(&a->dirname, &b->dirname, 247
    );
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_fileio_read_dir_resp_t(const sbp_msg_fileio_read_dir_resp_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->sequence);
  packed_size += sbp_sequence_string_packed_len(&msg->contents, 251
      , 255
      );
  return packed_size;
}

bool pack_sbp_msg_fileio_read_dir_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_fileio_read_dir_resp_t *msg)
{
  if (!pack_u32(ctx, &msg->sequence)) { return false; }
  if (!sbp_sequence_string_pack(&msg->contents, 251,255,
      ctx)) { return false; }
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
  if (!sbp_sequence_string_unpack(&msg->contents, 251,255,
      ctx)) { return false; }
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
  
  ret = sbp_sequence_string_strcmp(&a->contents, &b->contents, 251,255
    );
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_fileio_remove_t(const sbp_msg_fileio_remove_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_null_terminated_string_packed_len(&msg->filename, 255
      );
  return packed_size;
}

bool pack_sbp_msg_fileio_remove_t(sbp_pack_ctx_t *ctx, const sbp_msg_fileio_remove_t *msg)
{
  if (!sbp_null_terminated_string_pack(&msg->filename, 255,
      ctx)) { return false; }
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
  if (!sbp_null_terminated_string_unpack(&msg->filename, 255,
      ctx)) { return false; }
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
  
  ret = sbp_null_terminated_string_strcmp(&a->filename, &b->filename, 255
    );
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_fileio_write_req_t(const sbp_msg_fileio_write_req_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->sequence);
  packed_size += sbp_packed_size_u32(&msg->offset);
  packed_size += sbp_null_terminated_string_packed_len(&msg->filename, 247
      );
  packed_size += (msg->n_data * sbp_packed_size_u8(&msg->data[0]));
  return packed_size;
}

bool pack_sbp_msg_fileio_write_req_t(sbp_pack_ctx_t *ctx, const sbp_msg_fileio_write_req_t *msg)
{
  if (!pack_u32(ctx, &msg->sequence)) { return false; }
  if (!pack_u32(ctx, &msg->offset)) { return false; }
  if (!sbp_null_terminated_string_pack(&msg->filename, 247,
      ctx)) { return false; }
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
  if (!sbp_null_terminated_string_unpack(&msg->filename, 247,
      ctx)) { return false; }
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
  
  ret = sbp_null_terminated_string_strcmp(&a->filename, &b->filename, 247
    );
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
