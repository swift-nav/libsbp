/*****************************************************************************
 * Automatically generated from yaml/(((package.filepath)))
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <libsbp/sbp.h>
#include <libsbp/internal/v4/common.h>
#include <libsbp/v4/(((package.name))).h>
#include <libsbp/internal/v4/(((package.name))).h>
#include <libsbp/internal/v4/string/multipart.h>
#include <libsbp/internal/v4/string/null_terminated.h>
#include <libsbp/internal/v4/string/double_null_terminated.h>
#include <libsbp/internal/v4/string/unterminated.h>

((*- for m in package.msgs *))
                                                                                                              
((*- for f in m.fields *))
((*- if f.packing == "packed-string" *))
((*- set string_prefix = "sbp_" + f.encoding + "_string" *))

void (((f.fn_prefix)))_init( (((-m.type_name))) *msg)
{
  (((string_prefix)))_init(&msg->(((f.name))));
}

bool (((f.fn_prefix)))_valid(const (((m.type_name))) *msg)
{
  return (((string_prefix)))_valid(&msg->(((f.name))), (((f.max_items_macro))));
}

int (((f.fn_prefix)))_strcmp(const (((m.type_name))) *a, const (((m.type_name))) *b)
{
  return (((string_prefix)))_strcmp(&a->(((f.name))), &b->(((f.name))), (((f.max_items_macro))));
}

size_t (((f.fn_prefix)))_encoded_len(const (((m.type_name))) *msg)
{
  return (((string_prefix)))_encoded_len(&msg->(((f.name))), (((f.max_items_macro))));
}

size_t (((f.fn_prefix)))_space_remaining(const (((m.type_name))) *msg)
{
  return (((string_prefix)))_space_remaining(&msg->(((f.name))), (((f.max_items_macro))));
}

((*- if f.encoding == "unterminated" or f.encoding == "null_terminated" *))
 bool (((f.fn_prefix)))_set( (((-m.type_name))) *msg, const char *new_str, bool should_trunc, size_t *n_written)
{
  return (((string_prefix)))_set(&msg->(((f.name))), (((f.max_items_macro))), should_trunc, n_written, new_str);
}

 bool (((f.fn_prefix)))_set_raw( (((-m.type_name))) *msg, const char *new_buf, size_t new_buf_len, bool should_trunc, size_t *n_written)
{
  return (((string_prefix)))_set_raw(&msg->(((f.name))), (((f.max_items_macro))), should_trunc, n_written, new_buf, new_buf_len);
}


bool (((f.fn_prefix)))_printf( (((-m.type_name))) *msg, bool should_trunc, size_t *n_written, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = (((string_prefix)))_vprintf(&msg->(((f.name))), (((f.max_items_macro))), should_trunc, n_written, fmt, ap);
  va_end(ap);
  return ret;
}

 bool (((f.fn_prefix)))_vprintf( (((-m.type_name))) *msg, bool should_trunc, size_t *n_written, const char *fmt, va_list ap)
{
  return (((string_prefix)))_vprintf(&msg->(((f.name))), (((f.max_items_macro))), should_trunc, n_written, fmt, ap);
}

bool (((f.fn_prefix)))_append_printf( (((-m.type_name))) *msg, bool should_trunc, size_t *n_written, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = (((string_prefix)))_append_vprintf(&msg->(((f.name))), (((f.max_items_macro))), should_trunc, n_written, fmt, ap);
  va_end(ap);
  return ret;
}

  bool (((f.fn_prefix)))_append_vprintf( (((-m.type_name))) *msg,  bool should_trunc, size_t *n_written, const char *fmt, va_list ap)
{
  return (((string_prefix)))_append_vprintf(&msg->(((f.name))), (((f.max_items_macro))), should_trunc, n_written, fmt, ap);
}

const char *(((f.fn_prefix)))_get(const (((m.type_name))) *msg)
{
  return (((string_prefix)))_get(&msg->(((f.name))), (((f.max_items_macro))));
}

size_t (((f.fn_prefix)))_strlen(const (((m.type_name))) *msg)
{
  return (((string_prefix)))_strlen(&msg->(((f.name))), (((f.max_items_macro))));
}

((*- elif f.encoding == "multipart" or f.encoding == "double_null_terminated" *))
size_t (((f.fn_prefix)))_count_sections(const (((m.type_name))) *msg)
{
  return (((string_prefix)))_count_sections(&msg->(((f.name))), (((f.max_items_macro))));
}

bool (((f.fn_prefix)))_add_section( (((-m.type_name))) *msg, const char *new_str)
{
  return (((string_prefix)))_add_section(&msg->(((f.name))), (((f.max_items_macro))), new_str);
}

bool (((f.fn_prefix)))_add_section_printf( (((-m.type_name))) *msg, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = (((string_prefix)))_add_section_vprintf(&msg->(((f.name))), (((f.max_items_macro))), fmt, ap);
  va_end(ap);
  return ret;
}

bool (((f.fn_prefix)))_add_section_vprintf( (((-m.type_name))) *msg, const char *fmt, va_list ap)
{
  return (((string_prefix)))_add_section_vprintf(&msg->(((f.name))), (((f.max_items_macro))), fmt, ap);
}

bool (((f.fn_prefix)))_append( (((-m.type_name))) *msg, const char *str)
{
  return (((string_prefix)))_append(&msg->(((f.name))), (((f.max_items_macro))), str);
}

bool (((f.fn_prefix)))_append_printf( (((-m.type_name))) *msg, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = (((string_prefix)))_append_vprintf(&msg->(((f.name))), (((f.max_items_macro))), fmt, ap);
  va_end(ap);
  return ret;
}

bool (((f.fn_prefix)))_append_vprintf( (((-m.type_name))) *msg, const char *fmt, va_list ap)
{
  return (((string_prefix)))_append_vprintf(&msg->(((f.name))), (((f.max_items_macro))), fmt, ap);
}

const char *(((f.fn_prefix)))_get_section(const (((m.type_name))) *msg, size_t section)
{
  return (((string_prefix)))_get_section(&msg->(((f.name))), (((f.max_items_macro))), section);
}

size_t (((f.fn_prefix)))_section_strlen(const (((m.type_name))) *msg, size_t section)
{
  return (((string_prefix)))_section_strlen(&msg->(((f.name))), (((f.max_items_macro))), section);
}

((*- else *))
  **** INVALID STRING ENCODING : (((f.encoding))) ****
((* endif *))
((*- endif *))
((*- endfor *))

bool (((m.internal_encode_fn)))(sbp_encode_ctx_t *ctx, const (((m.type_name))) *msg)
{
  ((*- if not m.fields *))
  (void)ctx;
  (void)msg;
  return true;
  ((*- else *))
  ((*- for f in m.fields *))
  ((*- set field = "msg->" + f.name *))
  ((*- if f.packing == "packed-string" *))
  if (!sbp_(((f.encoding)))_string_encode(&(((field))), (((f.max_items_macro))), ctx)) { return false; }
  ((*- elif f.packing == "single" *))
  if (!(((f.encode_fn)))(ctx, &(((field))))) { return false; }
  ((*- else *))
  ((*- if f.packing == "fixed-array" *))
  ((*- set max_loop = f.max_items_macro *))
  ((*- else *))
  ((*- set max_loop = "msg->" + f.size_fn *))
  ((*- endif *))
  for (size_t i = 0; i < (((max_loop))); i++)
  {
    if (!(((f.encode_fn)))(ctx, &(((field)))[i])) { return false; }
  }
  ((*- endif *))
  ((*- endfor *))
  return true;
  ((*- endif *))
}

s8 (((m.public_encode_fn)))(uint8_t *buf, uint8_t len, uint8_t *n_written, const (((m.type_name))) *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!(((m.internal_encode_fn)))(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool (((m.internal_decode_fn)))(sbp_decode_ctx_t *ctx, (((m.type_name))) *msg)
{
  ((*- if not m.fields *))
    (void)ctx;
  (void)msg;
  return true;
  ((*- else *))
  ((*- for f in m.fields *))
  ((*- set field = "msg->" + f.name *))
  ((*- if f.packing == "packed-string" *))
  if (!sbp_(((f.encoding)))_string_decode(&(((field))), (((f.max_items_macro))), ctx)) { return false; }
  ((*- elif f.packing == "single" *))
  if (!(((f.decode_fn)))(ctx, &(((field))))) { return false; }
  ((*- elif f.packing == "fixed-array" *))
  for (uint8_t i = 0; i < (((f.max_items_macro))); i++) {
    if (!(((f.decode_fn)))(ctx, &(((field)))[i])) { return false; }
  }
  ((*- elif f.packing == "variable-array" *))
    msg->(((f.size_fn))) = (uint8_t)((ctx->buf_len - ctx->offset) / (((f.encoded_len_macro))));
  for (uint8_t i = 0; i < msg->(((f.size_fn))); i++) {
    if (!(((f.decode_fn)))(ctx, &(((field)))[i])) { return false; }
  }
  ((*- endif *))
  ((*- endfor *))
  return true;
  ((*- endif *))
}

s8 (((m.public_decode_fn)))(const uint8_t *buf, uint8_t len, uint8_t *n_read, (((m.type_name))) *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!(((m.internal_decode_fn)))(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

((* if m.is_real_message *))
s8 (((m.send_fn)))(sbp_state_t *s, u16 sender_id, const (((m.type_name))) *msg, sbp_write_fn_t write)
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = (((m.public_encode_fn)))(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_payload_send(s, (((m.legacy_msg_type))), sender_id, payload_len, payload, write);
}
((*- endif *))

int (((m.cmp_fn)))(const (((m.type_name))) *a, const (((m.type_name))) *b) {
  ((*- if not m.fields *))
  (void)a;
  (void)b;
  ((*- endif *))
  int ret = 0;
  ((*- for f in m.fields *))
  ((* if f.packing == "packed-string" *))
  ret = (((f.fn_prefix)))_strcmp(a, b);
  ((*- elif f.packing == "single" *))
  ret = (((f.cmp_fn)))(&a->(((f.name))), &b->(((f.name))));
  ((*- else *))
  ((*- if f.packing == "variable-array" *))
  ret = sbp_u8_cmp(&a->(((f.size_fn))), &b->(((f.size_fn))));
  ((*- endif *))
  ((*- if f.packing == "fixed-array" *))
  ((*- set max_loop = f.max_items_macro *))
  ((*- else *))
  ((*- set max_loop = "a->" + f.size_fn *))
  ((*- endif *))
  for (uint8_t i = 0; ret == 0 && i < (((max_loop))); i++)
  {
    ret = (((f.cmp_fn)))(&a->(((f.name)))[i], &b->(((f.name)))[i]);
  }
  ((*- endif *))
  if (ret != 0) { return ret; }
  ((*- endfor *))
  return ret;
}
((*- endfor *))

