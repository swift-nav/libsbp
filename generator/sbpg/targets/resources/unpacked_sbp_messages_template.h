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
  void (((m.name|convert_unpacked)))_(((f.name)))_init(sbp_(((f.encoding)))_string_t *s);
  bool (((m.name|convert_unpacked)))_(((f.name)))_valid(const sbp_(((f.encoding)))_string_t *s);
  int (((m.name|convert_unpacked)))_(((f.name)))_strcmp(const sbp_(((f.encoding)))_string_t *a, const sbp_(((f.encoding)))_string_t *b);
  uint8_t (((m.name|convert_unpacked)))_(((f.name)))_packed_len(const sbp_(((f.encoding)))_string_t *s);
  uint8_t (((m.name|convert_unpacked)))_(((f.name)))_space_remaining(const sbp_(((f.encoding)))_string_t *s);

  ((*- if f.encoding == "unterminated" or f.encoding == "null_terminated" *))
  bool (((m.name|convert_unpacked)))_(((f.name)))_set(sbp_(((f.encoding)))_string_t *s, const char *new_str);
  bool (((m.name|convert_unpacked)))_(((f.name)))_printf(sbp_(((f.encoding)))_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool (((m.name|convert_unpacked)))_(((f.name)))_vprintf(sbp_(((f.encoding)))_string_t *s, const char *fmt, va_list ap);
  bool (((m.name|convert_unpacked)))_(((f.name)))_append_printf(sbp_(((f.encoding)))_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool (((m.name|convert_unpacked)))_(((f.name)))_append_vprintf(sbp_(((f.encoding)))_string_t *s, const char *fmt, va_list ap);
  const char *(((m.name|convert_unpacked)))_(((f.name)))_get(const sbp_(((f.encoding)))_string_t *s);
  ((*- elif f.encoding == "binary" *))
  bool (((m.name|convert_unpacked)))_(((f.name)))_set(sbp_binary_string_t *s, const char *new_str, uint8_t new_str_len);
  bool (((m.name|convert_unpacked)))_(((f.name)))_get(const sbp_binary_string_t *s, uint8_t *str_len);
  ((*- elif f.encoding == "multipart" or f.encoding == "sequence" *))
  uint8_t (((m.name|convert_unpacked)))_(((f.name)))_count_sections(const sbp_(((f.encoding)))_string_t *s);
  bool (((m.name|convert_unpacked)))_(((f.name)))_add_section(sbp_(((f.encoding)))_string_t *s, const char *new_str);
  bool (((m.name|convert_unpacked)))_(((f.name)))_add_section_printf(sbp_(((f.encoding)))_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool (((m.name|convert_unpacked)))_(((f.name)))_add_section_vprintf(sbp_(((f.encoding)))_string_t *s, const char *fmt, va_list ap);
  bool (((m.name|convert_unpacked)))_(((f.name)))_append(sbp_(((f.encoding)))_string_t *s, const char *str);
  bool (((m.name|convert_unpacked)))_(((f.name)))_append_printf(sbp_(((f.encoding)))_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool (((m.name|convert_unpacked)))_(((f.name)))_append_vprintf(sbp_(((f.encoding)))_string_t *s, const char *fmt, va_list ap);
  const char *(((m.name|convert_unpacked)))_(((f.name)))_get_section(sbp_(((f.encoding)))_string_t *s, uint8_t section);
  uint8_t (((m.name|convert_unpacked)))_(((f.name)))_section_strlen(sbp_(((f.encoding)))_string_t *s, uint8_t section);
  ((*- else *))
  **** INVALID STRING ENCODING : (((f.encoding))) ****
  ((* endif *))
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

