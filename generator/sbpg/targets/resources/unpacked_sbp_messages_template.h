#ifndef LIBSBP_(((pkg_name|upper)))_MESSAGES_H
#define LIBSBP_(((pkg_name|upper)))_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>

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
  ((*- if f.basetype.is_primitive *))
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
  ((*- if f.order != "single" *))
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

((*- endfor *))

#include <libsbp/unpacked/(((pkg_name)))_operators.h>
#include <libsbp/unpacked/(((pkg_name)))_packers.h>

#endif /* LIBSBP_(((pkg_name|upper)))_MESSAGES_H */

