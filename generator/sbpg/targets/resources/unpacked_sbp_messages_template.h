#ifndef LIBSBP_(((pkg_name|upper)))_MESSAGES_H
#define LIBSBP_(((pkg_name|upper)))_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string2.h>

((*- for i in include *))
#include <libsbp/unpacked/(((i)))>
((*- endfor *))

((*- macro gen_substruct(substruct) *))
 ((*- for f in substruct.fields *))
  ((*- if f.desc *))
  /**
(((f.desc|commentify))) ((*- if f.units *))[(((f.units)))] ((*- endif *))
   */
  ((*- endif *))
  ((*- if f.order == "packed-string" *))
  sbp_(((f.encoding)))_string_t 
  ((*- elif f.basetype.is_primitive *))
    (((f.basetype.name)))
  ((*- else *))
  ((*- if f.basetype.generate_as_nested *))
  struct {
    (((gen_substruct(f.basetype) )))
  }
  ((*- else *))
  (((f.basetype.name|convert_unpacked))) 
  ((*- endif *))
  ((*- endif *))
  (((f.name)))
  ((*- if f.order != "single" and f.order != "packed-string" *))
    [(((f.max_items)))]
  ((*- endif *))
  ;
 
  ((*- if f.order == "variable-array" and not f.size_fn *))
  /**
   * Number of items in (((f.name)))
   */
  u8 (((f.name)))_count;
  ((*- endif *))

 ((*- endfor *))
((*- endmacro *))

((*- macro gen_bitfield_macros(substruct, path) *))
	((*- for f in substruct.fields *))
	((*- if not f.basetype.is_primitive *))
	(((gen_bitfield_macros(f.basetype, path + "_" + f.name))))
	((*- elif f.options.fields *))
	(((f|create_bitfield_macros(path + "_" + f.name))))
	((*- endif *))
	((*- endfor *))
((*- endmacro *))

((*- macro gen_string_formats(substruct, path) *))
#if 0
  ((*- for f in substruct.fields *))
  ((*- if f.order == "packed-string" *))
  static const sbp_(((f.encoding)))_string_format_t (((path)))_(((f.name)))_format = {
    /* .encoding = */ SBP_STRING_(((f.encoding|upper))),
    /* .min_sections = */ ((*-if f.encoding == "multipart"*))(((f.min_sections)))((*- else *))0((*- endif *))u,
    /* .max_sections = */ ((*-if f.encoding == "multipart"*))(((f.max_sections)))((*- else *))0((*- endif *))u,
    /* .terminator = */ ((*- if f.encoding == "sequence"*))(((f.terminator)))((*- else *))0((*- endif *))u,
    /* .max_encoded_len = */ (((f.max_items)))u
  };
  static inline void (((path)))_(((f.name)))_init(sbp_(((f.encoding)))_string_t s) { sbp_(((f.encoding)))_string_init(s, &(((path)))_(((f.name)))_format); }
  static inline uint8_t (((path)))_(((f.name)))_packed_len(const sbp_(((f.encoding)))_string_t s) { return sbp_(((f.encoding)))_string_packed_len(s, &(((path)))_(((f.name)))_format); }
  static inline uint8_t (((path)))_(((f.name)))_pack(const sbp_(((f.encoding)))_string_t s, uint8_t *buf, uint8_t buf_len) { return sbp_(((f.encoding)))_string_pack(s, &(((path)))_(((f.name)))_format, buf, buf_len); }
  static inline uint8_t (((path)))_(((f.name)))_unpack(sbp_(((f.encoding)))_string_t s, const uint8_t *buf, uint8_t buf_len) { return sbp_(((f.encoding)))_string_unpack(s, &(((path)))_(((f.name)))_format, buf, buf_len); }
  static inline uint8_t (((path)))_(((f.name)))_space_remaining(const sbp_(((f.encoding)))_string_t s) { return sbp_(((f.encoding)))_string_space_remaining(s, &(((path)))_(((f.name)))_format); }
  ((*- if f.encoding == "unterminated" or f.encoding == "null-terminated" *))
  static inline const char *(((path)))_(((f.name)))_get(sbp_(((f.encoding)))_string_t s) { return sbp_(((f.encoding)))_string_get_section(s, &(((path)))_(((f.name)))_format, 0); }
  static inline bool (((path)))_(((f.name)))_set(sbp_(((f.encoding)))_string_t s, const char *new_str) { return sbp_(((f.encoding)))_string_set(s, &(((path)))_(((f.name)))_format, new_str); }
  ((*- elif f.encoding == "multipart" *))
  static inline uint8_t (((path)))_(((f.name)))_count_sections(const sbp_(((f.encoding)))_string_t s) { return sbp_(((f.encoding)))_string_count_sections(s, &(((path)))_(((f.name)))_format); }
  static inline const char *(((path)))_(((f.name)))_get_section(const sbp_(((f.encoding)))_string_t s, uint8_t section) { return sbp_(((f.encoding)))_string_get_section(s, &(((path)))_(((f.name)))_format, section); }
  static inline bool (((path)))_(((f.name)))_set_section(sbp_(((f.encoding)))_string_t s, uint8_t section, const char *new_str) { return sbp_(((f.encoding)))_string_set_section(s, &(((path)))_(((f.name)))_format, section, new_str); }
  ((*- else *))
  static inline uint8_t (((path)))_(((f.name)))_count_sections(const sbp_(((f.encoding)))_string_t s) { return sbp_(((f.encoding)))_string_count_sections(s, &(((path)))_(((f.name)))_format); }
  static inline const char *(((path)))_(((f.name)))_get_section(const sbp_(((f.encoding)))_string_t s, uint8_t section) { return sbp_(((f.encoding)))_string_get_section(s, &(((path)))_(((f.name)))_format, section); }
  static inline bool (((path)))_(((f.name)))_append_section(sbp_(((f.encoding)))_string_t s, const char *new_str) { return sbp_(((f.encoding)))_string_append_section(s, &(((path)))_(((f.name)))_format, new_str); }
  ((*- endif *))
  ((*- else *))
  ((*- if not f.basetype.is_primitive *))
  (((gen_string_formats(f.basetype, path + "_" + f.name))))
  ((*- endif *))
  ((*- endif *))
  ((*- endfor *))
#endif
((*- endmacro *))

((*- for m in msgs *))
((*- if m.desc *))
  /** (((m.short_desc)))
   *
(((m.desc|commentify)))
   */
((*- endif *))
((*- if m.is_real_message *))
#define SBP_(((m.name.ljust(max_msgid_len)))) ((('0x%04X'|format(m.sbp_id))))
((*- endif *))
(((gen_bitfield_macros(m, m.name))))
typedef struct {
  ((*- if not m.fields *))
  char dummy_to_avoid_empty_struct___do_not_use;
  ((*- else *))
  ((( gen_substruct(m) )))
  ((*- endif *))
} (((m.name|convert_unpacked)));

(((gen_string_formats(m, m.name|convert_unpacked))))

((*- endfor *))

#include <libsbp/unpacked/(((pkg_name)))_operators.h>
#include <libsbp/unpacked/(((pkg_name)))_packers.h>

#endif /* LIBSBP_(((pkg_name|upper)))_MESSAGES_H */

