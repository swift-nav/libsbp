#ifndef LIBSBP_(((pkg_name|upper)))_MESSAGES_H
#define LIBSBP_(((pkg_name|upper)))_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/string/multipart.h>
#include <libsbp/unpacked/string/sequence.h>
#include <libsbp/unpacked/string/unterminated.h>
#include <libsbp/unpacked/string/null_terminated.h>
#include <libsbp/unpacked/string/binary.h>

((*- for i in include *))
#include <libsbp/unpacked/(((i)))>
((*- endfor *))

#ifdef __cplusplus
  extern "C" {
#endif

((*- for m in msgs *))
((*- if m.fields *))
((*- for f in m.fields *))
((*- if f.options.fields *))
(((f|create_bitfield_macros(m.name))))
((*- endif *))
((*- endfor *))
((*- endif *))
((*- if m.desc *))
/** (((m.short_desc)))
 *
((m.desc|commentify)))
 */
((*- endif *))
((*- if m.is_real_message *))
#define SBP_(((m.name.ljust(max_msgid_len)))) ((('0x%04X'|format(m.sbp_id))))
((*- endif *))
typedef struct {
  ((*- if m.fields *))
  ((*- for f in m.fields *))
  ((*- if f.packing == "packed-string" *))
  sbp_(((f.options.encoding.value)))_string_t (((f.name)));
  ((*- elif f.packing == "single" *))
  (((f.basetype|convert_unpacked))) (((f.name)));
  ((*- else *))
  (((f.basetype|convert_unpacked))) (((f.name)))[(((f.max_items)))];
  ((*- if f.generate_size_fn *))
  u8 (((f.size_fn)));
  ((*- endif *))
  ((*- endif *))
  ((*- endfor *))
  ((*- else *))
  char DO_NOT_USE_dummy_field_to_prevent_empty_struct;
  ((*- endif *))
} (((m.name|convert_unpacked)));

((*- for f in m.fields *))
  ((*- if f.packing == "packed-string" *))
  ((*- if f.encoding == "unterminated" or f.encoding == "null_terminated" *))
#define (((m.name|convert_unpacked)))_(((f.name)))_init(f) sbp_(((f.encoding)))_string_init(f, (((f.max_items))))
#define (((m.name|convert_unpacked)))_(((f.name)))_valid(f) sbp_(((f.encoding)))_string_valid(f, (((f.max_items))))
#define (((m.name|convert_unpacked)))_(((f.name)))_set(f,s) sbp_(((f.encoding)))_string_set(f,s,(((f.max_items))))
#define (((m.name|convert_unpacked)))_(((f.name)))_printf(f,...) sbp_(((f.encoding)))_string_printf(f,(((f.max_items))),__VA_ARGS__)
#define (((m.name|convert_unpacked)))_(((f.name)))_vprintf(f,fmt,ap) sbp_(((f.encoding)))_string_vprintf(f,(((f.max_items))),fmt,ap)
#define (((m.name|convert_unpacked)))_(((f.name)))_packed_len(f) sbp_(((f.encoding)))_string_packed_len(f,(((f.max_items))))
#define (((m.name|convert_unpacked)))_(((f.name)))_get(f) sbp_(((f.encoding)))_string_get(f,(((f.max_items))))
#define (((m.name|convert_unpacked)))_(((f.name)))_len(f) ( (((m.name|convert_unpacked)))_(((f.name)))_packed_len(f) ((*- if f.encoding == "null_terminated" *)) - 1((*- endif *)))
#define (((m.name|convert_unpacked)))_(((f.name)))_strcmp(a,b) sbp_(((f.encoding)))_string_strcmp(a,b,(((f.max_items))))
  ((*- elif f.encoding == "binary" *))
#define (((m.name|convert_unpacked)))_(((f.name)))_init(f) sbp_binary_string_init(f, (((f.max_items))))
#define (((m.name|convert_unpacked)))_(((f.name)))_valid(f) sbp_binary_string_valid(f, (((f.max_items))))
#define (((m.name|convert_unpacked)))_(((f.name)))_set(f,s,n) sbp_binary_string_set(f, s, n, (((f.max_items))))
#define (((m.name|convert_unpacked)))_(((f.name)))_get(f,n) sbp_binary_string_get(f,n,(((f.max_items))))
#define (((m.name|convert_unpacked)))_(((f.name)))_strcmp(a,v) sbp_binary_string_strcmp(a,b,(((f.max_items))))
  ((*- elif f.encoding == "multipart" or f.encoding == "sequence" *))
  ((*- if f.encoding == "multipart" *))((*- set common_args = f.max_items|string + ", " + f.min_sections|string + ", " + f.max_sections|string *))
  ((*- else *))((*- set common_args = f.max_items|string + ", " + f.terminator|string *))((*- endif *))
#define (((m.name|convert_unpacked)))_(((f.name)))_init(f) sbp_(((f.encoding)))_string_init(f, (((common_args))))
#define (((m.name|convert_unpacked)))_(((f.name)))_valid(f) sbp_(((f.encoding)))_string_valid(f, (((common_args))))
#define (((m.name|convert_unpacked)))_(((f.name)))_packed_len(f) sbp_(((f.encoding)))_string_packed_len(f, (((common_args))))
#define (((m.name|convert_unpacked)))_(((f.name)))_append(f,s) sbp_(((f.encoding)))_string_append(f, s, (((common_args))))
#define (((m.name|convert_unpacked)))_(((f.name)))_append_printf(f, ...) sbp_(((f.encoding)))_string_append_printf(s, (((common_args))), __VA_ARGS__)
#define (((m.name|convert_unpacked)))_(((f.name)))_append_vprintf(f, fmt,ap) sbp_(((f.encoding)))_string_append_vprintf(s, (((common_args))), fmt, ap)
#define (((m.name|convert_unpacked)))_(((f.name)))_count_sections(f) sbp_(((f.encoding)))_string_count_sections(f, (((common_args))))
#define (((m.name|convert_unpacked)))_(((f.name)))_get_section(f,s) sbp_(((f.encoding)))_string_get_section(f,s,(((common_args))))
#define (((m.name|convert_unpacked)))_(((f.name)))_section_len(f,s) sbp_(((f.encoding)))_string_section_len(f,s,(((common_args))))
#define (((m.name|convert_unpacked)))_(((f.name)))_space_remaining(f) sbp_(((f.encoding)))_string_space_remaining(f,(((common_args))))
#define (((m.name|convert_unpacked)))_(((f.name)))_strcmp(a,b) sbp_(((f.encoding)))_string_strcmp(a,b,(((common_args))))
  ((*- else *))
  bad string encoding (((f.encoding)))
  ((*- endif *))
  ((*- endif *))
((*- endfor *))

size_t sbp_packed_size_(((m.name|convert_unpacked)))(const (((m.name|convert_unpacked))) *msg);
s8 sbp_pack_(((m.name|convert_unpacked)))(uint8_t *buf, uint8_t len, uint8_t *n_written, const (((m.name|convert_unpacked))) *msg);
s8 sbp_unpack_(((m.name|convert_unpacked)))(const uint8_t *buf, uint8_t len, uint8_t *n_read, (((m.name|convert_unpacked))) *msg);

int sbp_cmp_(((m.name|convert_unpacked)))(const (((m.name|convert_unpacked))) *a, const (((m.name|convert_unpacked))) *b);

((* endfor *))

#ifdef __cplusplus
  }

((*- for m in msgs *))
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
((*- endfor *))

#endif

#endif /* LIBSBP_(((pkg_name|upper)))_MESSAGES_H */

