#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <libsbp/sbp.h>
#include <libsbp/internal/new/common.h>
#include <libsbp/new/logging.h>
#include <libsbp/internal/new/logging.h>
#include <libsbp/internal/new/string/multipart.h>
#include <libsbp/internal/new/string/null_terminated.h>
#include <libsbp/internal/new/string/double_null_terminated.h>
#include <libsbp/internal/new/string/unterminated.h>
static const sbp_unterminated_string_params_t sbp_msg_log_ttext_params = 
{
  .max_packed_len = 254
};

  void sbp_msg_log_t_text_init(sbp_unterminated_string_t *s)
{
  sbp_unterminated_string_init(s, &sbp_msg_log_ttext_params);
}

  bool sbp_msg_log_t_text_valid(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_valid(s, &sbp_msg_log_ttext_params);
}

  int sbp_msg_log_t_text_strcmp(const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b)
{
  return sbp_unterminated_string_strcmp(a, b, &sbp_msg_log_ttext_params);
}

  uint8_t sbp_msg_log_t_text_packed_len(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_packed_len(s, &sbp_msg_log_ttext_params);
}

  uint8_t sbp_msg_log_t_text_space_remaining(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_space_remaining(s, &sbp_msg_log_ttext_params);
      }
  bool sbp_msg_log_t_text_set(sbp_unterminated_string_t *s, const char *new_str)
  {
  return sbp_unterminated_string_set(s, &sbp_msg_log_ttext_params, new_str);
  }

  bool sbp_msg_log_t_text_printf(sbp_unterminated_string_t *s, const char *fmt, ...) 
  {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_vprintf(s, &sbp_msg_log_ttext_params, fmt, ap);
  va_end(ap);
  return ret;
  }

  bool sbp_msg_log_t_text_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap)
  {
  return sbp_unterminated_string_vprintf(s, &sbp_msg_log_ttext_params, fmt, ap);
  }

  bool sbp_msg_log_t_text_append_printf(sbp_unterminated_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_append_vprintf(s, &sbp_msg_log_ttext_params, fmt, ap);
  va_end(ap);
  return ret;
}

  bool sbp_msg_log_t_text_append_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap)
{
  return sbp_unterminated_string_append_vprintf(s, &sbp_msg_log_ttext_params, fmt, ap);
}

  const char *sbp_msg_log_t_text_get(const sbp_unterminated_string_t *s)
{
  return sbp_unterminated_string_get(s, &sbp_msg_log_ttext_params);
}

size_t sbp_packed_size_sbp_msg_log_t(const sbp_msg_log_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->level);
  packed_size += sbp_unterminated_string_packed_len(&msg->text, &sbp_msg_log_ttext_params);
  return packed_size;
}

bool encode_sbp_msg_log_t(sbp_encode_ctx_t *ctx, const sbp_msg_log_t *msg)
{
  if (!encode_u8(ctx, &msg->level)) { return false; }
  if (!sbp_unterminated_string_pack(&msg->text, &sbp_msg_log_ttext_params, ctx)) { return false; }
  return true;
}

s8 sbp_encode_sbp_msg_log_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_log_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_log_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_log_t(sbp_decode_ctx_t *ctx, sbp_msg_log_t *msg)
{
  if (!decode_u8(ctx, &msg->level)) { return false; }
  if (!sbp_unterminated_string_unpack(&msg->text, &sbp_msg_log_ttext_params, ctx)) { return false; }
  return true;
}

s8 sbp_decode_sbp_msg_log_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_log_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_log_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_log_t(struct sbp_state *s, u16 sender_id, const sbp_msg_log_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_log_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_payload_send(s, SBP_MSG_LOG, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_log_t(const sbp_msg_log_t *a, const sbp_msg_log_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->level, &b->level);
  if (ret != 0) { return ret; }
  
  ret = sbp_unterminated_string_strcmp(&a->text, &b->text, &sbp_msg_log_ttext_params);
  if (ret != 0) { return ret; }
  return ret;
}
