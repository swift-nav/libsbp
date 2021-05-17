#ifndef LIBSBP_(((pkg_name|upper)))_PACKERS_H
#define LIBSBP_(((pkg_name|upper)))_PACKERS_H

#ifndef LIBSBP_(((pkg_name|upper)))_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/(((pkg_name))).h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/base.h>
#include <libsbp/unpacked/common.h>
#include <libsbp/unpacked/string/unterminated.h>
#include <libsbp/unpacked/string/multipart.h>
#include <libsbp/unpacked/string/sequence.h>
#include <libsbp/unpacked/string/null_terminated.h>

((*- for m in msgs *))
                                                                                                              
static inline size_t sbp_packed_size_(((m.name|convert_unpacked)))(const (((m.name|convert_unpacked))) *msg) {
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

static inline bool sbp_pack_(((m.name|convert_unpacked)))(sbp_pack_ctx_t *ctx, const (((m.name|convert_unpacked))) *msg)
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
  if (!sbp_pack_(((f.basetype|convert_unpacked)))(ctx, &msg->(((f.name))))) { return false; }
  ((*- else *))
  for (uint8_t i = 0; i < ((* if f.packing == "fixed-array" *))(((f.max_items)))((* else *))msg->(((f.size_fn)))((*- endif *)); i++)
  {
    if (!sbp_pack_(((f.basetype|convert_unpacked)))(ctx, &msg->(((f.name)))[i])) { return false; }
  }
  ((*- endif *))
  ((*- endfor *))
  ((*- endif *))
  return true;
}

static inline bool sbp_unpack_(((m.name|convert_unpacked)))(sbp_unpack_ctx_t *ctx, (((m.name|convert_unpacked))) *msg)
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
  if (!sbp_unpack_(((f.basetype|convert_unpacked)))(ctx, &msg->(((f.name))))) { return false; }
  ((*- elif f.packing == "fixed-array" *))
  for (uint8_t i = 0; i < (((f.max_items))); i++) {
    if (!sbp_unpack_(((f.basetype|convert_unpacked)))(ctx, &msg->(((f.name)))[i])) { return false; }
  }
  ((*- elif f.packing == "variable-array" *))
    msg->(((f.size_fn))) = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_(((f.basetype|convert_unpacked)))(&msg->(((f.name)))[0]));
  for (uint8_t i = 0; i < msg->(((f.size_fn))); i++) {
    if (!sbp_unpack_(((f.basetype|convert_unpacked)))(ctx, &msg->(((f.name)))[i])) { return false; }
  }
  ((*- endif *))
  ((*- endfor *))
  return true;
  ((*- endif *))
}

((*- endfor *))

#endif

