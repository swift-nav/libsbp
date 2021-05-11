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

((*- macro compare_primitive(field, path) *))
  ((*- if field.basetype.name == "double" or field.basetype.name == "float" *))
    if (fabs( a.(((path))) - b.(((path))) ) > 0.001) { return false; }
  ((*- else *))
    if (a.(((path))) != b.(((path)))) { return false; }
  ((*- endif *))
((*- endmacro *))

((*- macro compare_substruct(substruct, path) *))
  ((*- for f in substruct.fields *))
    ((*- with *))
    ((*- set loop_idx = (path + f.name + "_idx")|sanitise_path *))
    ((*- if f.order == "single" *))
      ((*- if f.basetype.is_primitive *))
        (((compare_primitive(f, path + f.name))))
      ((*- else *))
        (((compare_substruct(f.basetype, path + f.name + "."))))
      ((*- endif *))
      ((*- elif f.order == "fixed-string" *))
        if (strncmp(a.(((path))), b.(((path))), sizeof(a.(((path))))) != 0) { return false; }
      ((*- elif f.order == "fixed-array" *))
        for (size_t (((loop_idx))) = 0; (((loop_idx))) < (((f.max_items))); (((loop_idx)))++)
        {
          ((*- if f.basetype.is_primitive *))
            (((compare_primitive(f, path + f.name + "[" + loop_idx + "]"))))
          ((*- else *))
            (((compare_substruct(f.basetype, path + f.name + "[" + loop_idx + "]."))))
          ((*- endif *))
        }
      ((*- elif f.order == "variable-array" *))
        ((*- if f.size_fn *))
          if (a.(((path + f.size_fn))) != b.(((path + f.size_fn)))) { return false; }
        ((*- else *))
          if (a.(((path + f.name + "_count"))) != b.(((path + f.name + "_count")))) { return false; }
        ((*- endif *))
        for (size_t (((loop_idx))) = 0; (((loop_idx))) < (size_t)a.((*- if f.size_fn *))(((path + f.size_fn)))((*- else *))(((path + f.name + "_count")))((*- endif *)); (((loop_idx)))++)
        {
          ((*- if f.basetype.is_primitive *))
            (((compare_primitive(f, path + f.name + "[" + loop_idx + "]"))))
          ((*- else *))
            (((compare_substruct(f.basetype, path + f.name + "[" + loop_idx + "]."))))
          ((*- endif *))
        }
      ((*- endif *))
    ((*- endwith *))
  ((*- endfor *))
((*- endmacro *))


((*- for m in msgs *))
#ifdef __cplusplus
static inline bool operator== ( const (((m.name|convert_unpacked))) &a, const (((m.name|convert_unpacked))) &b) {
  (void)a;
  (void)b;
  (((compare_substruct(m, ""))))

  return true;
}

static inline bool operator!=(const (((m.name|convert_unpacked))) &a, const (((m.name|convert_unpacked))) &b) {
  return !(a == b);
}
#endif
((*- endfor *))

#endif
