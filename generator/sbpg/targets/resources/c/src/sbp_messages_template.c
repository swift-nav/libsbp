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
((*- set msg_type = m.name|convert_unpacked *))
                                                                                                              
((*- for f in m.fields *))
((*- if f.packing == "packed-string" *))
((*- set params = m.name|convert_unpacked + f.name + "_params" *))
((*- set string_prefix = "sbp_" + f.encoding + "_string" *))
((*- set string_type = string_prefix + "_t" *))
((*- set field_prefix = msg_type + "_" + f.name *))
static const (((string_prefix)))_params_t (((params))) = 
{
  .max_packed_len = (((f.max_items)))
};

void (((field_prefix)))_init( (((-string_type))) *s)
{
  (((string_prefix)))_init(s, &(((params))));
}

bool (((field_prefix)))_valid(const (((string_type))) *s)
{
  return (((string_prefix)))_valid(s, &(((params))));
}

int (((field_prefix)))_strcmp(const (((string_type))) *a, const (((string_type))) *b)
{
  return (((string_prefix)))_strcmp(a, b, &(((params))));
}

uint8_t (((field_prefix)))_packed_len(const (((string_type))) *s)
{
  return (((string_prefix)))_packed_len(s, &(((params))));
}

uint8_t (((field_prefix)))_space_remaining(const (((string_type))) *s)
{
  return (((string_prefix)))_space_remaining(s, &(((params))));
}

((*- if f.encoding == "unterminated" or f.encoding == "null_terminated" *))
 bool (((field_prefix)))_set( (((-string_type))) *s, const char *new_str)
{
  return (((string_prefix)))_set(s, &(((params))), new_str);
}

bool (((field_prefix)))_printf( (((-string_type))) *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = (((string_prefix)))_vprintf(s, &(((params))), fmt, ap);
  va_end(ap);
  return ret;
}

 bool (((field_prefix)))_vprintf( (((-string_type))) *s, const char *fmt, va_list ap)
{
  return (((string_prefix)))_vprintf(s, &(((params))), fmt, ap);
}

bool (((field_prefix)))_append_printf( (((-string_type))) *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = (((string_prefix)))_append_vprintf(s, &(((params))), fmt, ap);
  va_end(ap);
  return ret;
}

  bool (((field_prefix)))_append_vprintf( (((-string_type))) *s, const char *fmt, va_list ap)
{
  return (((string_prefix)))_append_vprintf(s, &(((params))), fmt, ap);
}

const char *(((field_prefix)))_get(const (((string_type))) *s)
{
  return (((string_prefix)))_get(s, &(((params))));
}

((*- elif f.encoding == "multipart" or f.encoding == "double_null_terminated" *))
uint8_t (((field_prefix)))_count_sections(const (((string_type))) *s)
{
  return (((string_prefix)))_count_sections(s, &(((params))));
}

bool (((field_prefix)))_add_section( (((-string_type))) *s, const char *new_str)
{
  return (((string_prefix)))_add_section(s, &(((params))), new_str);
}

bool (((field_prefix)))_add_section_printf( (((-string_type))) *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = (((string_prefix)))_add_section_vprintf(s, &(((params))), fmt, ap);
  va_end(ap);
  return ret;
}

bool (((field_prefix)))_add_section_vprintf( (((-string_type))) *s, const char *fmt, va_list ap)
{
  return (((string_prefix)))_add_section_vprintf(s, &(((params))), fmt, ap);
}

bool (((field_prefix)))_append( (((-string_type))) *s, const char *str)
{
  return (((string_prefix)))_append(s, &(((params))), str);
}

bool (((field_prefix)))_append_printf( (((-string_type))) *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = (((string_prefix)))_append_vprintf(s, &(((params))), fmt, ap);
  va_end(ap);
  return ret;
}

bool (((field_prefix)))_append_vprintf( (((-string_type))) *s, const char *fmt, va_list ap)
{
  return (((string_prefix)))_append_vprintf(s, &(((params))), fmt, ap);
}

const char *(((field_prefix)))_get_section(const (((string_type))) *s, uint8_t section)
{
  return (((string_prefix)))_get_section(s, &(((params))), section);
}

uint8_t (((field_prefix)))_section_strlen(const (((string_type))) *s, uint8_t section)
{
  return (((string_prefix)))_section_strlen(s, &(((params))), section);
}

((*- else *))
  **** INVALID STRING ENCODING : (((f.encoding))) ****
((* endif *))
((*- endif *))
((*- endfor *))

size_t sbp_packed_size_(((msg_type)))(const (((msg_type))) *msg) {
  ((*- if not m.fields *))
  (void)msg;
  return 0;
  ((*- else *))
  size_t packed_size = 0;
  ((*- for f in m.fields *))
  ((*- set basetype = f.basetype|convert_unpacked *))
  ((*- set field = "msg->" + f.name *))
  ((*- if f.packing == "packed-string" *))
  packed_size += sbp_(((f.encoding)))_string_packed_len(&(((field))), &(((msg_type)))(((f.name)))_params);
  ((*- elif f.packing == "single" *))
  packed_size += sbp_packed_size_(((basetype)))(&(((field))));
  ((*- elif f.packing == "fixed-array" *))
  packed_size += ( (((f.max_items))) * sbp_packed_size_(((basetype)))(&(((field)))[0]));
  ((*- else *))
  packed_size += (msg->(((f.size_fn))) * sbp_packed_size_(((basetype)))(&(((field)))[0]));
  ((*- endif *))
  ((*- endfor *))
  return packed_size;
  ((*- endif *))
}

bool encode_(((msg_type)))(sbp_encode_ctx_t *ctx, const (((msg_type))) *msg)
{
  ((*- if not m.fields *))
  (void)ctx;
  (void)msg;
  return true;
  ((*- else *))
  ((*- for f in m.fields *))
  ((*- set basetype = f.basetype|convert_unpacked *))
  ((*- set field = "msg->" + f.name *))
  ((*- if f.packing == "packed-string" *))
  if (!sbp_(((f.encoding)))_string_pack(&(((field))), &(((msg_type)))(((f.name)))_params, ctx)) { return false; }
  ((*- elif f.packing == "single" *))
  if (!encode_(((basetype)))(ctx, &(((field))))) { return false; }
  ((*- else *))
  ((*- if f.packing == "fixed-array" *))
  ((*- set max_loop = f.max_items *))
  ((*- else *))
  ((*- set max_loop = "msg->" + f.size_fn *))
  ((*- endif *))
  for (uint8_t i = 0; i < (((max_loop))); i++)
  {
    if (!encode_(((basetype)))(ctx, &(((field)))[i])) { return false; }
  }
  ((*- endif *))
  ((*- endfor *))
  return true;
  ((*- endif *))
}

s8 sbp_encode_(((msg_type)))(uint8_t *buf, uint8_t len, uint8_t *n_written, const (((msg_type))) *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_(((msg_type)))(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_(((msg_type)))(sbp_decode_ctx_t *ctx, (((msg_type))) *msg)
{
  ((*- if not m.fields *))
    (void)ctx;
  (void)msg;
  return true;
  ((*- else *))
  ((*- for f in m.fields *))
  ((*- set basetype = f.basetype|convert_unpacked *))
  ((*- set field = "msg->" + f.name *))
  ((*- if f.packing == "packed-string" *))
  if (!sbp_(((f.encoding)))_string_unpack(&(((field))), &(((msg_type)))(((f.name)))_params, ctx)) { return false; }
  ((*- elif f.packing == "single" *))
  if (!decode_(((basetype)))(ctx, &(((field))))) { return false; }
  ((*- elif f.packing == "fixed-array" *))
  for (uint8_t i = 0; i < (((f.max_items))); i++) {
    if (!decode_(((basetype)))(ctx, &(((field)))[i])) { return false; }
  }
  ((*- elif f.packing == "variable-array" *))
    msg->(((f.size_fn))) = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_(((basetype)))(&(((field)))[0]));
  for (uint8_t i = 0; i < msg->(((f.size_fn))); i++) {
    if (!decode_(((basetype)))(ctx, &(((field)))[i])) { return false; }
  }
  ((*- endif *))
  ((*- endfor *))
  return true;
  ((*- endif *))
}

s8 sbp_decode_(((msg_type)))(const uint8_t *buf, uint8_t len, uint8_t *n_read, (((msg_type))) *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_(((msg_type)))(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

((* if m.is_real_message *))
s8 sbp_send_(((msg_type)))(struct sbp_state *s, u16 sender_id, const (((msg_type))) *msg, sbp_write_fn_t write)
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_(((msg_type)))(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_payload_send(s, SBP_(((m.name))), sender_id, payload_len, payload, write);
}
((*- endif *))

int sbp_cmp_(((msg_type)))(const (((msg_type))) *a, const (((msg_type))) *b) {
  ((*- if not m.fields *))
  (void)a;
  (void)b;
  ((*- endif *))
  int ret = 0;
  ((*- for f in m.fields *))
  ((*- set basetype = f.basetype|convert_unpacked *))
  ((* if f.packing == "packed-string" *))
  ret = (((msg_type)))_(((f.name)))_strcmp(&a->(((f.name))), &b->(((f.name))));
  ((*- elif f.packing == "single" *))
  ret = sbp_cmp_(((basetype)))(&a->(((f.name))), &b->(((f.name))));
  ((*- else *))
  ((*- if f.packing == "variable-array" *))
  ret = sbp_cmp_u8(&a->(((f.size_fn))), &b->(((f.size_fn))));
  ((*- endif *))
  ((*- if f.packing == "fixed-array" *))
  ((*- set max_loop = f.max_items *))
  ((*- else *))
  ((*- set max_loop = "a->" + f.size_fn *))
  ((*- endif *))
  for (uint8_t i = 0; ret == 0 && i < (((max_loop))); i++)
  {
    ret = sbp_cmp_(((basetype)))(&a->(((f.name)))[i], &b->(((f.name)))[i]);
  }
  ((*- endif *))
  if (ret != 0) { return ret; }
  ((*- endfor *))
  return ret;
}
((*- endfor *))

