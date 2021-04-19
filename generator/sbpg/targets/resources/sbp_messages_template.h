#ifndef LIBSBP_(((pkg_name|upper)))_MESSAGES_H
#define LIBSBP_(((pkg_name|upper)))_MESSAGES_H

#include "common.h"

((*- for i in include *))
#include "(((i)))"
((*- endfor *))

SBP_PACK_START

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
  struct SBP_ATTR_PACKED {
    (((gen_substruct(f.basetype) )))
  }
  ((*- endif *))
  (((f.name)))
  ((*- if f.order != "single" *))
    [(((f.max_items)))]
  ((*- endif *))
  ;
 
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
#define SBP_(((m.name.ljust(max_msgid_len)))) ((('0x%04X'|format(m.sbp_id))))
(((gen_bitfield_macros(m, m.name))))
typedef struct SBP_ATTR_PACKED {
  ((( gen_substruct(m) )))
} (((m.name|convert)));
((*- endfor *))
                                                                                                              
SBP_PACK_END

#endif /* LIBSBP_(((pkg_name|upper)))_MESSAGES_H */
