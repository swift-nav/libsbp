#ifndef LIBSBP_(((pkg_name|upper)))_MESSAGES_H
#define LIBSBP_(((pkg_name|upper)))_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>

((*- for i in include *))
#include <libsbp/unpacked/(((i)))>
((*- endfor *))

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

((* endfor *))

#include <libsbp/unpacked/(((pkg_name)))_operators.h>
#include <libsbp/unpacked/(((pkg_name)))_packers.h>

#endif /* LIBSBP_(((pkg_name|upper)))_MESSAGES_H */

