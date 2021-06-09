/*****************************************************************************
 * Automatically generated from yaml/(((filepath)))
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <libsbp/sbp.h>
#include <libsbp/internal/v4/common.h>
#include <libsbp/v4/(((pkg_name))).h>
#include <libsbp/internal/v4/(((pkg_name))).h>
#include <libsbp/internal/v4/string/multipart.h>
#include <libsbp/internal/v4/string/null_terminated.h>
#include <libsbp/internal/v4/string/double_null_terminated.h>
#include <libsbp/internal/v4/string/unterminated.h>

((*- for m in msgs *))
                                                                                                              
((*- for f in m.fields *))
((*- if f.packing == "packed-string" *))
((*- set params = m.name|convert_unpacked + f.name + "_params" *))
((*- set string_prefix = "sbp_" + f.encoding + "_string" *))
((*- set field_prefix = m.prefix + "_" + f.name *))
static const (((string_prefix)))_params_t (((params))) = 
{
  .max_encoded_len = (((f.max_items)))
};

void (((field_prefix)))_init( (((-m.type_name))) *msg)
{
  (((string_prefix)))_init(&msg->(((f.name))), &(((params))));
}

bool (((field_prefix)))_valid(const (((m.type_name))) *msg)
{
  return (((string_prefix)))_valid(&msg->(((f.name))), &(((params))));
}

int (((field_prefix)))_strcmp(const (((m.type_name))) *a, const (((m.type_name))) *b)
{
  return (((string_prefix)))_strcmp(&a->(((f.name))), &b->(((f.name))), &(((params))));
}

uint8_t (((field_prefix)))_encoded_len(const (((m.type_name))) *msg)
{
  return (((string_prefix)))_encoded_len(&msg->(((f.name))), &(((params))));
}

uint8_t (((field_prefix)))_space_remaining(const (((m.type_name))) *msg)
{
  return (((string_prefix)))_space_remaining(&msg->(((f.name))), &(((params))));
}

((*- if f.encoding == "unterminated" or f.encoding == "null_terminated" *))
 bool (((field_prefix)))_set( (((-m.type_name))) *msg, const char *new_str)
{
  return (((string_prefix)))_set(&msg->(((f.name))), &(((params))), new_str);
}

bool (((field_prefix)))_printf( (((-m.type_name))) *msg, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = (((string_prefix)))_vprintf(&msg->(((f.name))), &(((params))), fmt, ap);
  va_end(ap);
  return ret;
}

 bool (((field_prefix)))_vprintf( (((-m.type_name))) *msg, const char *fmt, va_list ap)
{
  return (((string_prefix)))_vprintf(&msg->(((f.name))), &(((params))), fmt, ap);
}

bool (((field_prefix)))_append_printf( (((-m.type_name))) *msg, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = (((string_prefix)))_append_vprintf(&msg->(((f.name))), &(((params))), fmt, ap);
  va_end(ap);
  return ret;
}

  bool (((field_prefix)))_append_vprintf( (((-m.type_name))) *msg, const char *fmt, va_list ap)
{
  return (((string_prefix)))_append_vprintf(&msg->(((f.name))), &(((params))), fmt, ap);
}

const char *(((field_prefix)))_get(const (((m.type_name))) *msg)
{
  return (((string_prefix)))_get(&msg->(((f.name))), &(((params))));
}

((*- elif f.encoding == "multipart" or f.encoding == "double_null_terminated" *))
uint8_t (((field_prefix)))_count_sections(const (((m.type_name))) *msg)
{
  return (((string_prefix)))_count_sections(&msg->(((f.name))), &(((params))));
}

bool (((field_prefix)))_add_section( (((-m.type_name))) *msg, const char *new_str)
{
  return (((string_prefix)))_add_section(&msg->(((f.name))), &(((params))), new_str);
}

bool (((field_prefix)))_add_section_printf( (((-m.type_name))) *msg, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = (((string_prefix)))_add_section_vprintf(&msg->(((f.name))), &(((params))), fmt, ap);
  va_end(ap);
  return ret;
}

bool (((field_prefix)))_add_section_vprintf( (((-m.type_name))) *msg, const char *fmt, va_list ap)
{
  return (((string_prefix)))_add_section_vprintf(&msg->(((f.name))), &(((params))), fmt, ap);
}

bool (((field_prefix)))_append( (((-m.type_name))) *msg, const char *str)
{
  return (((string_prefix)))_append(&msg->(((f.name))), &(((params))), str);
}

bool (((field_prefix)))_append_printf( (((-m.type_name))) *msg, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = (((string_prefix)))_append_vprintf(&msg->(((f.name))), &(((params))), fmt, ap);
  va_end(ap);
  return ret;
}

bool (((field_prefix)))_append_vprintf( (((-m.type_name))) *msg, const char *fmt, va_list ap)
{
  return (((string_prefix)))_append_vprintf(&msg->(((f.name))), &(((params))), fmt, ap);
}

const char *(((field_prefix)))_get_section(const (((m.type_name))) *msg, uint8_t section)
{
  return (((string_prefix)))_get_section(&msg->(((f.name))), &(((params))), section);
}

uint8_t (((field_prefix)))_section_strlen(const (((m.type_name))) *msg, uint8_t section)
{
  return (((string_prefix)))_section_strlen(&msg->(((f.name))), &(((params))), section);
}

((*- else *))
  **** INVALID STRING ENCODING : (((f.encoding))) ****
((* endif *))
((*- endif *))
((*- endfor *))

size_t (((m.prefix)))_encoded_len(const (((m.type_name))) *msg) {
  ((*- if not m.fields *))
  (void)msg;
  return 0;
  ((*- else *))
  size_t encoded_len = 0;
  ((*- for f in m.fields *))
  ((*- set field = "msg->" + f.name *))
  ((*- if f.packing == "packed-string" *))
  encoded_len += sbp_(((f.encoding)))_string_encoded_len(&(((field))), &(((m.type_name)))(((f.name)))_params);
  ((*- elif f.packing == "single" *))
  encoded_len += (((f.basetype_encoded_len)))(&(((field))));
  ((*- elif f.packing == "fixed-array" *))
  encoded_len += ( (((-f.max_items))) * (((f.basetype_encoded_len)))(&(((field)))[0]));
  ((*- else *))
  encoded_len += (msg->(((f.size_fn))) * (((f.basetype_encoded_len)))(&(((field)))[0]));
  ((*- endif *))
  ((*- endfor *))
  return encoded_len;
  ((*- endif *))
}

bool (((m.prefix)))_encode_internal(sbp_encode_ctx_t *ctx, const (((m.type_name))) *msg)
{
  ((*- if not m.fields *))
  (void)ctx;
  (void)msg;
  return true;
  ((*- else *))
  ((*- for f in m.fields *))
  ((*- set field = "msg->" + f.name *))
  ((*- if f.packing == "packed-string" *))
  if (!sbp_(((f.encoding)))_string_pack(&(((field))), &(((m.type_name)))(((f.name)))_params, ctx)) { return false; }
  ((*- elif f.packing == "single" *))
  if (!(((f.basetype_encode)))(ctx, &(((field))))) { return false; }
  ((*- else *))
  ((*- if f.packing == "fixed-array" *))
  ((*- set max_loop = f.max_items *))
  ((*- else *))
  ((*- set max_loop = "msg->" + f.size_fn *))
  ((*- endif *))
  for (uint8_t i = 0; i < (((max_loop))); i++)
  {
    if (!(((f.basetype_encode)))(ctx, &(((field)))[i])) { return false; }
  }
  ((*- endif *))
  ((*- endfor *))
  return true;
  ((*- endif *))
}

s8 (((m.prefix)))_encode(uint8_t *buf, uint8_t len, uint8_t *n_written, const (((m.type_name))) *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!(((m.prefix)))_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool (((m.prefix)))_decode_internal(sbp_decode_ctx_t *ctx, (((m.type_name))) *msg)
{
  ((*- if not m.fields *))
    (void)ctx;
  (void)msg;
  return true;
  ((*- else *))
  ((*- for f in m.fields *))
  ((*- set field = "msg->" + f.name *))
  ((*- if f.packing == "packed-string" *))
  if (!sbp_(((f.encoding)))_string_unpack(&(((field))), &(((m.type_name)))(((f.name)))_params, ctx)) { return false; }
  ((*- elif f.packing == "single" *))
  if (!(((f.basetype_decode)))(ctx, &(((field))))) { return false; }
  ((*- elif f.packing == "fixed-array" *))
  for (uint8_t i = 0; i < (((f.max_items))); i++) {
    if (!(((f.basetype_decode)))(ctx, &(((field)))[i])) { return false; }
  }
  ((*- elif f.packing == "variable-array" *))
    msg->(((f.size_fn))) = (uint8_t)((ctx->buf_len - ctx->offset) / (((f.basetype_encoded_len)))(&(((field)))[0]));
  for (uint8_t i = 0; i < msg->(((f.size_fn))); i++) {
    if (!(((f.basetype_decode)))(ctx, &(((field)))[i])) { return false; }
  }
  ((*- endif *))
  ((*- endfor *))
  return true;
  ((*- endif *))
}

s8 (((m.prefix)))_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read, (((m.type_name))) *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!(((m.prefix)))_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

((* if m.is_real_message *))
s8 (((m.prefix)))_send(struct sbp_state *s, u16 sender_id, const (((m.type_name))) *msg, sbp_write_fn_t write)
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = (((m.prefix)))_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_payload_send(s, SBP_(((m.name))), sender_id, payload_len, payload, write);
}
((*- endif *))

int (((m.prefix)))_cmp(const (((m.type_name))) *a, const (((m.type_name))) *b) {
  ((*- if not m.fields *))
  (void)a;
  (void)b;
  ((*- endif *))
  int ret = 0;
  ((*- for f in m.fields *))
  ((*- set basetype = f.basetype|convert_unpacked *))
  ((* if f.packing == "packed-string" *))
  ret = (((m.prefix)))_(((f.name)))_strcmp(a, b);
  ((*- elif f.packing == "single" *))
  ret = (((f.basetype_cmp)))(&a->(((f.name))), &b->(((f.name))));
  ((*- else *))
  ((*- if f.packing == "variable-array" *))
  ret = sbp_u8_cmp(&a->(((f.size_fn))), &b->(((f.size_fn))));
  ((*- endif *))
  ((*- if f.packing == "fixed-array" *))
  ((*- set max_loop = f.max_items *))
  ((*- else *))
  ((*- set max_loop = "a->" + f.size_fn *))
  ((*- endif *))
  for (uint8_t i = 0; ret == 0 && i < (((max_loop))); i++)
  {
    ret = (((f.basetype_cmp)))(&a->(((f.name)))[i], &b->(((f.name)))[i]);
  }
  ((*- endif *))
  if (ret != 0) { return ret; }
  ((*- endfor *))
  return ret;
}
((*- endfor *))

