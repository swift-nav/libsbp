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
#include <libsbp/string.h>

((*- for m in msgs *))
                                                                                                              
static inline size_t sbp_packed_size_(((m.name|convert_unpacked)))(const (((m.name|convert_unpacked))) *msg) {
  size_t packed_size = 0;
  (void)msg;
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
}

static inline ((* if m.is_real_message *))bool((* else *))size_t ((*- endif *)) sbp_pack_(((m.name|convert_unpacked)))(u8 *buf, size_t len, const (((m.name|convert_unpacked))) *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_(((m.name|convert_unpacked)))(msg) > len) { return false; }
  ((*- for f in m.fields *))
  ((*- if f.packing == "packed-string" *))
  offset += sbp_(((f.encoding)))_string_pack(&msg->(((f.name))), (((f.max_items))), 
      ((*- if f.encoding == "multipart" *))(((f.min_sections))), (((f.max_sections))),((*- endif *))
      ((*- if f.encoding == "sequence" *))(((f.terminator))),((*- endif *))
      buf + offset, (uint8_t)(len - offset));
  ((*- elif f.packing == "single" *))
  offset += sbp_pack_(((f.basetype|convert_unpacked)))(buf + offset, len - offset, &msg->(((f.name))));
  ((*- else *))
  for (uint8_t i = 0; i < ((* if f.packing == "fixed-array" *))(((f.max_items)))((* else *))msg->(((f.size_fn)))((*- endif *)); i++) 
  {
    offset += sbp_pack_(((f.basetype|convert_unpacked)))(buf + offset, len - offset, &msg->(((f.name)))[i]);
  }
  ((*- endif *))
  ((*- endfor *))
  return ((* if m.is_real_message *))true((* else *))offset((*endif*));
}

static inline ((* if m.is_real_message *))bool((* else *))size_t((*- endif *)) sbp_unpack_(((m.name|convert_unpacked)))(const uint8_t *buf, size_t len, (((m.name|convert_unpacked))) *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  ((*- for f in m.fields *))
  ((*- if f.packing == "packed-string" *))
  offset += sbp_(((f.encoding)))_string_unpack(&msg->(((f.name))), (((f.max_items))),
      ((*- if f.encoding == "multipart" *))(((f.min_sections))), (((f.max_sections))),((*- endif *))
      ((*- if f.encoding == "sequence" *))(((f.terminator))),((*- endif *))
      buf + offset, (uint8_t)(len - offset));
  ((*- elif f.packing == "single" *))
  offset += sbp_unpack_(((f.basetype|convert_unpacked)))(buf + offset, len - offset, &msg->(((f.name))));
  ((*- elif f.packing == "fixed-array" *))
  for (uint8_t i = 0; i < (((f.max_items))); i++)
  {
    offset += sbp_unpack_(((f.basetype|convert_unpacked)))(buf + offset, len - offset, &msg->(((f.name)))[i]);
  }
  ((*- elif f.packing == "variable-array" *))
  msg->(((f.size_fn))) = (uint8_t)((len - offset) / sbp_packed_size_(((f.basetype|convert_unpacked)))(&msg->(((f.name)))[0]));
  for (uint8_t i = 0; i < msg->(((f.size_fn))); i++)
  {
    offset += sbp_unpack_(((f.basetype|convert_unpacked)))(buf + offset, len - offset, &msg->(((f.name)))[i]);
  }
  return true;
  ((*- endif *))
  ((*- endfor *))
  return ((* if m.is_real_message *))true((* else *))offset((*endif*));
}

((*- endfor *))

#endif

