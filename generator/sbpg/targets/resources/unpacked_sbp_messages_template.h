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
  ((*- for f in substruct.fields *))
  ((*- if f.order == "packed-string" *))
  ((*- if f.encoding == "unterminated" or f.encoding == "null_terminated" *))
#define (((path)))_(((f.name)))_init(f) sbp_(((f.encoding)))_string_init(f, (((f.max_items))))
#define (((path)))_(((f.name)))_set(f,s) sbp_(((f.encoding)))_string_set(f,s,(((f.max_items))))
#define (((path)))_(((f.name)))_printf(f,...) sbp_(((f.encoding)))_string_printf(f,(((f.max_items))),__VA_ARGS__)
#define (((path)))_(((f.name)))_packed_len(f) sbp_(((f.encoding)))_string_packed_len(f,(((f.max_items))))
#define (((path)))_(((f.name)))_get(f) sbp_(((f.encoding)))_string_get(f,(((f.max_items))))
  ((*- elif f.encoding == "multipart" or f.encoding == "sequence" *))
  ((*- if f.encoding == "multipart" *))((*- set common_args = f.max_items|string + ", " + f.min_sections|string + ", " + f.max_sections|string *))
  ((*- else *))((*- set common_args = f.max_items|string + ", " + f.terminator|string *))((*- endif *))
#define (((path)))_(((f.name)))_init(f), sbp_(((f.encoding)))_string_init(f, (((common_args))))
#define (((path)))_(((f.name)))_packed_len(f) sbp_(((f.encoding)))_string_packed_len(f, (((common_args))))
#define (((path)))_(((f.name)))_append(f,s) sbp_(((f.encoding)))_string_append(f, s, (((common_args))))
#define (((path)))_(((f.name)))_append_printf(f, ...) sbp_(((f.encoding)))_string_append_printf(s, (((common_args))), __VA_ARGS__)
#define (((path)))_(((f.name)))_count_sections(f) sbp_(((f.encoding)))_string_count_sections(f, (((common_args))))
#define (((path)))_(((f.name)))_get_section(f,s) sbp_(((f.encoding)))_string_get_section(f,s,(((common_args))))
#define (((path)))_(((f.name)))_section_len(f,s) sbp_(((f.encoding)))_string_section_len(f,s,(((common_args))))
#define (((path)))_(((f.name)))_space_remaining(f) sbp_(((f.encoding)))_string_space_remaining(f,(((common_args))))
  ((*- else *))
  bad string encoding (((f.encoding)))
  ((*- endif *))
  ((*- endif *))
  ((*- endfor *))

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

