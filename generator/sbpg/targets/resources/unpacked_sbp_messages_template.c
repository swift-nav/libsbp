#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <libsbp/sbp.h>
#include <libsbp/internal/unpacked/common.h>
#include <libsbp/unpacked/(((pkg_name))).h>
#include <libsbp/internal/unpacked/(((pkg_name))).h>
#include <libsbp/internal/unpacked/string/multipart.h>
#include <libsbp/internal/unpacked/string/null_terminated.h>
#include <libsbp/internal/unpacked/string/double_null_terminated.h>
#include <libsbp/internal/unpacked/string/unterminated.h>
#include <libsbp/internal/unpacked/string/binary.h>

((*- for m in msgs *))
                                                                                                              
((*- for f in m.fields *))
((*- if f.packing == "packed-string" *))
((*- set params = m.name|convert_unpacked + f.name + "_params" *))
static const sbp_(((f.encoding)))_string_params_t (((params))) = 
{
  .max_packed_len = (((f.max_items)))
};

  void (((m.name|convert_unpacked)))_(((f.name)))_init(sbp_(((f.encoding)))_string_t *s)
{
  sbp_(((f.encoding)))_string_init(s, &(((params))));
}

  bool (((m.name|convert_unpacked)))_(((f.name)))_valid(const sbp_(((f.encoding)))_string_t *s)
{
  return sbp_(((f.encoding)))_string_valid(s, &(((params))));
}

  int (((m.name|convert_unpacked)))_(((f.name)))_strcmp(const sbp_(((f.encoding)))_string_t *a, const sbp_(((f.encoding)))_string_t *b)
{
  return sbp_(((f.encoding)))_string_strcmp(a, b, &(((params))));
}

  uint8_t (((m.name|convert_unpacked)))_(((f.name)))_packed_len(const sbp_(((f.encoding)))_string_t *s)
{
  return sbp_(((f.encoding)))_string_packed_len(s, &(((params))));
}

  uint8_t (((m.name|convert_unpacked)))_(((f.name)))_space_remaining(const sbp_(((f.encoding)))_string_t *s)
{
  return sbp_(((f.encoding)))_string_space_remaining(s, &(((params))));
      }

  ((*- if f.encoding == "unterminated" or f.encoding == "null_terminated" *))
  bool (((m.name|convert_unpacked)))_(((f.name)))_set(sbp_(((f.encoding)))_string_t *s, const char *new_str)
  {
  return sbp_(((f.encoding)))_string_set(s, &(((params))), new_str);
  }

  bool (((m.name|convert_unpacked)))_(((f.name)))_printf(sbp_(((f.encoding)))_string_t *s, const char *fmt, ...) 
  {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_(((f.encoding)))_string_vprintf(s, &(((params))), fmt, ap);
  va_end(ap);
  return ret;
  }

  bool (((m.name|convert_unpacked)))_(((f.name)))_vprintf(sbp_(((f.encoding)))_string_t *s, const char *fmt, va_list ap)
  {
  return sbp_(((f.encoding)))_string_vprintf(s, &(((params))), fmt, ap);
  }

  bool (((m.name|convert_unpacked)))_(((f.name)))_append_printf(sbp_(((f.encoding)))_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_(((f.encoding)))_string_append_vprintf(s, &(((params))), fmt, ap);
  va_end(ap);
  return ret;
}

  bool (((m.name|convert_unpacked)))_(((f.name)))_append_vprintf(sbp_(((f.encoding)))_string_t *s, const char *fmt, va_list ap)
{
  return sbp_(((f.encoding)))_string_append_vprintf(s, &(((params))), fmt, ap);
}

  const char *(((m.name|convert_unpacked)))_(((f.name)))_get(const sbp_(((f.encoding)))_string_t *s)
{
  return sbp_(((f.encoding)))_string_get(s, &(((params))));
}

  ((*- elif f.encoding == "binary" *))
  bool (((m.name|convert_unpacked)))_(((f.name)))_set(sbp_binary_string_t *s, const char *new_str, uint8_t new_str_len)
{
  return sbp_binary_string_set(s, &(((params))), new_str, new_str_len);
}

  bool (((m.name|convert_unpacked)))_(((f.name)))_get(const sbp_binary_string_t *s, uint8_t *str_len)
{
  return sbp_binary_string_get(s, &(((params))), str_len);
}

  ((*- elif f.encoding == "multipart" or f.encoding == "double_null_terminated" *))
  uint8_t (((m.name|convert_unpacked)))_(((f.name)))_count_sections(const sbp_(((f.encoding)))_string_t *s)
{
  return sbp_(((f.encoding)))_string_count_sections(s, &(((params))));
}

  bool (((m.name|convert_unpacked)))_(((f.name)))_add_section(sbp_(((f.encoding)))_string_t *s, const char *new_str)
{
  return sbp_(((f.encoding)))_string_add_section(s, &(((params))), new_str);
}

  bool (((m.name|convert_unpacked)))_(((f.name)))_add_section_printf(sbp_(((f.encoding)))_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_(((f.encoding)))_string_add_section_vprintf(s, &(((params))), fmt, ap);
  va_end(ap);
  return ret;
}

  bool (((m.name|convert_unpacked)))_(((f.name)))_add_section_vprintf(sbp_(((f.encoding)))_string_t *s, const char *fmt, va_list ap)
{
  return sbp_(((f.encoding)))_string_add_section_vprintf(s, &(((params))), fmt, ap);
}

  bool (((m.name|convert_unpacked)))_(((f.name)))_append(sbp_(((f.encoding)))_string_t *s, const char *str)
{
  return sbp_(((f.encoding)))_string_append(s, &(((params))), str);
}

  bool (((m.name|convert_unpacked)))_(((f.name)))_append_printf(sbp_(((f.encoding)))_string_t *s, const char *fmt, ...) 
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_(((f.encoding)))_string_append_vprintf(s, &(((params))), fmt, ap);
  va_end(ap);
  return ret;
}

  bool (((m.name|convert_unpacked)))_(((f.name)))_append_vprintf(sbp_(((f.encoding)))_string_t *s, const char *fmt, va_list ap)
{
  return sbp_(((f.encoding)))_string_append_vprintf(s, &(((params))), fmt, ap);
}

  const char *(((m.name|convert_unpacked)))_(((f.name)))_get_section(sbp_(((f.encoding)))_string_t *s, uint8_t section)
{
  return sbp_(((f.encoding)))_string_get_section(s, &(((params))), section);
}

  uint8_t (((m.name|convert_unpacked)))_(((f.name)))_section_strlen(sbp_(((f.encoding)))_string_t *s, uint8_t section)
{
  return sbp_(((f.encoding)))_string_section_strlen(s, &(((params))), section);
}

  ((*- else *))
  **** INVALID STRING ENCODING : (((f.encoding))) ****
  ((* endif *))
((*- endif *))
((*- endfor *))

size_t sbp_packed_size_(((m.name|convert_unpacked)))(const (((m.name|convert_unpacked))) *msg) {
  ((*- if not m.fields *))
  (void)msg;
  return 0;
  ((*- else *))
  size_t packed_size = 0;
  ((*- for f in m.fields *))
  ((*- if f.packing == "packed-string" *))
  packed_size += sbp_(((f.encoding)))_string_packed_len(&msg->(((f.name))), &(((m.name|convert_unpacked)))(((f.name)))_params);
  ((*- elif f.packing == "single" *))
  packed_size += sbp_packed_size_(((f.basetype|convert_unpacked)))(&msg->(((f.name))));
  ((*- elif f.packing == "fixed-array" *))
  packed_size += ( (((f.max_items))) * sbp_packed_size_(((f.basetype|convert_unpacked)))(&msg->(((f.name)))[0]));
  ((*- else *))
  packed_size += (msg->(((f.size_fn))) * sbp_packed_size_(((f.basetype|convert_unpacked)))(&msg->(((f.name)))[0]));
  ((*- endif *))
  ((*- endfor *))
  return packed_size;
  ((*- endif *))
}

bool pack_(((m.name|convert_unpacked)))(sbp_pack_ctx_t *ctx, const (((m.name|convert_unpacked))) *msg)
{
  ((*- if not m.fields *))
  (void)ctx;
  (void)msg;
  return true;
  ((*- else *))
  ((*- for f in m.fields *))
  ((*- if f.packing == "packed-string" *))
  if (!sbp_(((f.encoding)))_string_pack(&msg->(((f.name))), &(((m.name|convert_unpacked)))(((f.name)))_params, ctx)) { return false; }
  ((*- elif f.packing == "single" *))
  if (!pack_(((f.basetype|convert_unpacked)))(ctx, &msg->(((f.name))))) { return false; }
  ((*- else *))
  for (uint8_t i = 0; i < ((* if f.packing == "fixed-array" *))(((f.max_items)))((* else *))msg->(((f.size_fn)))((*- endif *)); i++)
  {
    if (!pack_(((f.basetype|convert_unpacked)))(ctx, &msg->(((f.name)))[i])) { return false; }
  }
  ((*- endif *))
  ((*- endfor *))
  return true;
  ((*- endif *))
}

s8 sbp_pack_(((m.name|convert_unpacked)))(uint8_t *buf, uint8_t len, uint8_t *n_written, const (((m.name|convert_unpacked))) *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_(((m.name|convert_unpacked)))(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_(((m.name|convert_unpacked)))(sbp_unpack_ctx_t *ctx, (((m.name|convert_unpacked))) *msg)
{
  ((*- if not m.fields *))
    (void)ctx;
  (void)msg;
  return true;
  ((*- else *))
  ((*- for f in m.fields *))

  ((*- if f.packing == "packed-string" *))
  if (!sbp_(((f.encoding)))_string_unpack(&msg->(((f.name))), &(((m.name|convert_unpacked)))(((f.name)))_params, ctx)) { return false; }
  ((*- elif f.packing == "single" *))
  if (!unpack_(((f.basetype|convert_unpacked)))(ctx, &msg->(((f.name))))) { return false; }
  ((*- elif f.packing == "fixed-array" *))
  for (uint8_t i = 0; i < (((f.max_items))); i++) {
    if (!unpack_(((f.basetype|convert_unpacked)))(ctx, &msg->(((f.name)))[i])) { return false; }
  }
  ((*- elif f.packing == "variable-array" *))
    msg->(((f.size_fn))) = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_(((f.basetype|convert_unpacked)))(&msg->(((f.name)))[0]));
  for (uint8_t i = 0; i < msg->(((f.size_fn))); i++) {
    if (!unpack_(((f.basetype|convert_unpacked)))(ctx, &msg->(((f.name)))[i])) { return false; }
  }
  ((*- endif *))
  ((*- endfor *))
  return true;
  ((*- endif *))
}

s8 sbp_unpack_(((m.name|convert_unpacked)))(const uint8_t *buf, uint8_t len, uint8_t *n_read, (((m.name|convert_unpacked))) *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_(((m.name|convert_unpacked)))(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_(((m.name|convert_unpacked)))(const (((m.name|convert_unpacked))) *a, const (((m.name|convert_unpacked))) *b) {
  ((*- if not m.fields *))
  (void)a;
  (void)b;
  ((*- endif *))
  int ret = 0;
  ((*- for f in m.fields *))
  ((* if f.packing == "packed-string" *))
  ret = sbp_(((f.encoding)))_string_strcmp(&a->(((f.name))), &b->(((f.name))), &(((m.name|convert_unpacked)))(((f.name)))_params);
  ((*- elif f.packing == "single" *))
  ret = sbp_cmp_(((f.basetype|convert_unpacked)))(&a->(((f.name))), &b->(((f.name))));
  ((*- else *))
  ((*- if f.packing == "variable-array" *))
  ret = sbp_cmp_u8(&a->(((f.size_fn))), &b->(((f.size_fn))));
  ((*- endif *))
  for (uint8_t i = 0; i < ((* if f.packing == "fixed-array" *))(((f.max_items)))((* else *))a->(((f.size_fn)))((* endif *)) && ret == 0; i++)
  {
    ret = sbp_cmp_(((f.basetype|convert_unpacked)))(&a->(((f.name)))[i], &b->(((f.name)))[i]);
  }
  ((*- endif *))
  if (ret != 0) { return ret; }
  ((*- endfor *))
  return ret;
}
((*- endfor *))

