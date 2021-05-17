#ifndef LIBSBP_(((pkg_name|upper)))_OPERATORS_H
#define LIBSBP_(((pkg_name|upper)))_OPERATORS_H

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
#include <libsbp/unpacked/string/unterminated.h>
#include <libsbp/unpacked/string/multipart.h>
#include <libsbp/unpacked/string/sequence.h>
#include <libsbp/unpacked/string/null_terminated.h>
#include <libsbp/unpacked/base.h>

((*- for m in msgs *))
static inline int sbp_cmp_(((m.name|convert_unpacked)))(const (((m.name|convert_unpacked))) *a, const (((m.name|convert_unpacked))) *b) {
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

#ifdef __cplusplus
static inline bool operator==(const (((m.name|convert_unpacked))) &a, const (((m.name|convert_unpacked))) &b) {
  return sbp_cmp_(((m.name|convert_unpacked)))(&a, &b) == 0;
}

static inline bool operator!=(const (((m.name|convert_unpacked))) &a, const (((m.name|convert_unpacked))) &b) {
  return sbp_cmp_(((m.name|convert_unpacked)))(&a, &b) != 0;
}

static inline bool operator<(const (((m.name|convert_unpacked))) &a, const (((m.name|convert_unpacked))) &b) {
  return sbp_cmp_(((m.name|convert_unpacked)))(&a, &b) < 0;
}

static inline bool operator<=(const (((m.name|convert_unpacked))) &a, const (((m.name|convert_unpacked))) &b) {
  return sbp_cmp_(((m.name|convert_unpacked)))(&a, &b) <= 0;
}

static inline bool operator>(const (((m.name|convert_unpacked))) &a, const (((m.name|convert_unpacked))) &b) {
  return sbp_cmp_(((m.name|convert_unpacked)))(&a, &b) > 0;
}

static inline bool operator>=(const (((m.name|convert_unpacked))) &a, const (((m.name|convert_unpacked))) &b) {
  return sbp_cmp_(((m.name|convert_unpacked)))(&a, &b) >= 0;
}
#endif

((*- endfor *))

#endif

