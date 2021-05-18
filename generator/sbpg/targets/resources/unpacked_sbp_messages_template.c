#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <libsbp/sbp.h>
#include <libsbp/internal/unpacked/common.h>
#include <libsbp/unpacked/(((pkg_name))).h>
#include <libsbp/internal/unpacked/(((pkg_name))).h>
#include <libsbp/internal/unpacked/string/multipart.h>
#include <libsbp/internal/unpacked/string/null_terminated.h>
#include <libsbp/internal/unpacked/string/sequence.h>
#include <libsbp/internal/unpacked/string/unterminated.h>
#include <libsbp/internal/unpacked/string/binary.h>

((*- for m in msgs *))
                                                                                                              
size_t sbp_packed_size_(((m.name|convert_unpacked)))(const (((m.name|convert_unpacked))) *msg) {
  ((*- if not m.fields *))
  (void)msg;
  return 0;
  ((*- else *))
  size_t packed_size = 0;
  ((*- for f in m.fields *))
  ((*- if f.packing == "packed-string" *))
  packed_size += sbp_(((f.encoding)))_string_packed_len(&msg->(((f.name))), (((f.max_items)))
      ((*- if f.encoding == "multipart" *))
      , (((f.min_sections))), (((f.max_sections)))
      ((*- elif f.encoding == "sequence" *))
      , (((f.terminator)))
      ((*- endif *))
      );
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
  if (!sbp_(((f.encoding)))_string_pack(&msg->(((f.name))), (((f.max_items))),
      ((*- if f.encoding == "multipart" *))(((f.min_sections))), (((f.max_sections))),((*- endif *))
      ((*- if f.encoding == "sequence" *))(((f.terminator))),((*- endif *))
      ctx)) { return false; }
  ((*- elif f.packing == "single" *))
  if (!pack_(((f.basetype|convert_unpacked)))(ctx, &msg->(((f.name))))) { return false; }
  ((*- else *))
  for (uint8_t i = 0; i < ((* if f.packing == "fixed-array" *))(((f.max_items)))((* else *))msg->(((f.size_fn)))((*- endif *)); i++)
  {
    if (!pack_(((f.basetype|convert_unpacked)))(ctx, &msg->(((f.name)))[i])) { return false; }
  }
  ((*- endif *))
  ((*- endfor *))
  ((*- endif *))
  return true;
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
  if (!sbp_(((f.encoding)))_string_unpack(&msg->(((f.name))), (((f.max_items))),
      ((*- if f.encoding == "multipart" *))(((f.min_sections))), (((f.max_sections))),((*- endif *))
      ((*- if f.encoding == "sequence" *))(((f.terminator))),((*- endif *))
      ctx)) { return false; }
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
  ret = sbp_(((f.encoding)))_string_strcmp(&a->(((f.name))), &b->(((f.name))), (((f.max_items)))
    ((*- if f.encoding == "multipart" *)),(((f.min_sections))),(((f.max_sections)))((*- endif *))
    ((*- if f.encoding == "sequence" *)),(((f.terminator)))((*- endif *))
    );
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

