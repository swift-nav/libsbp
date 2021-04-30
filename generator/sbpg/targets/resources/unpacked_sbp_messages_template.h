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
#include <libsbp/(((i)))>
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
  struct {
    (((gen_substruct(f.basetype) )))
  }
  ((*- endif *))
  (((f.name)))
  ((*- if f.order != "single" *))
    [(((f.max_items)))]
  ((*- endif *))
  ;
 
  ((*- if f.order == "variable-array" and not f.count *))
  /**
   * Number of items in (((f.name)))
   */
  u8 n_(((f.name)));
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
#define SBP_(((m.name.ljust(max_msgid_len)))) ((('0x%04X'|format(m.sbp_id))))
(((gen_bitfield_macros(m, m.name))))
typedef struct {
  ((*- if not m.fields *))
  char dummy_to_avoid_empty_struct___do_not_use;
  ((*- else *))
  ((( gen_substruct(m) )))
  ((*- endif *))
} (((m.name|convert_unpacked)));
                                                                                                              
((*- macro substruct_packed_size(substruct, path) *))                                                         
	0
  ((*- with *))                                                                                               
  ((*- for f in substruct.fields *))                                                                          
	  +
    ((*- if f.order == "fixed-string" *))                                                                     
      (((f.max_items)))                                                                                       
		((*- elif f.order == "variable-string" *))
      sbp_strlen( (((path)))(((f.name))), "(((f.termination)))" )
	  ((*- elif f.order == "single" *))
		  ((*- if f.basetype.is_primitive *))
				sizeof( ((( path + f.name ))) )
			((*- else *))
				( ((( substruct_packed_size(f.basetype, path + f.name + ".") ))) )
			((*- endif *))
		((*- elif f.order == "fixed-array" *))
		  ( (((f.max_items))) * 
		  ((*- if f.basetype.is_primitive *))
        sizeof( ((( path + f.name )))[0] )
			((*- else *))
				( ((( substruct_packed_size(f.basetype, path + f.name + "[0].") ))) )
			((*- endif *))
		)
		((*- else *))
	    (
	    ((*- if f.count *))
	      (((path)))(((f.count)))
	    ((*- else *))
			  (((path)))n_(((f.name)))
			((*- endif *))
			*
		  ((*- if f.basetype.is_primitive *))
        sizeof( (((path + f.name)))[0] )
			((*- else *))
				( ((( substruct_packed_size(f.basetype, path + f.name + "[0].") ))) )
			((*- endif *))
			)
	  ((*- endif *))
	((*- endfor *))
  ((*- endwith *))
((*- endmacro *))

static inline size_t sbp_packed_size_(((m.name|convert_unpacked)))(const (((m.name|convert_unpacked))) *msg) {                                
	(void)msg;
  return (((substruct_packed_size(m, "msg->") )));
}                                                                                                             
                                                                                                              
((*- macro pack_primitive(field, path) *))
  ((*- set tmp_name = (path)|sanitise_path *))
  if (offset + (((field.basetype.packed_size))) > len) { return false; }
  ((*- if field.basetype.name == "u16" *))
  u16 (((tmp_name))) = htole16( (((path))) );
  ((*- elif field.basetype.name == "u32" *))
  u32 (((tmp_name))) = htole32( (((path))) );
  ((*- elif field.basetype.name == "u64" *))
  u64 (((tmp_name))) = htole64( (((path))) );
  ((*- elif field.basetype.name == "s16" *))
  u16 (((tmp_name))) = htole16( *(const u16*)&(((path))) );
  ((*- elif field.basetype.name == "s32" *))
  u32 (((tmp_name))) = htole32( *(const u32*)&(((path))) );
  ((*- elif field.basetype.name == "s64" *))
  u64 (((tmp_name))) = htole64( *(const u64*)&(((path))) );
  ((*- else *))
  (((field.basetype.name))) (((tmp_name))) = (((path)));
  ((*- endif *))
  memcpy(buf + offset, & (((tmp_name))) , (((field.basetype.packed_size))));
  offset += (((field.basetype.packed_size)));
((*- endmacro *))

((*- macro pack_substruct(substruct, path) *))
	((*- for f in substruct.fields *))
	  ((*- with *))
	  ((*- set loop_idx = (path + f.name + "_idx")|sanitise_path *))
	  ((*- if f.order == "single" *))
		  ((*- if f.basetype.is_primitive *))
        (((pack_primitive(f, path + f.name))))
			((*- else *))
				(((pack_substruct(f.basetype, path + f.name + "."))))
			((*- endif *))
		((*- elif f.order == "fixed-string" *))
      if(offset + sizeof( (((path + f.name))) ) > len) { return false; }
			memcpy(buf + offset, (((path + f.name))), sizeof( (((path + f.name)))));
			offset += sizeof( (((path + f.name))));
		((*- elif f.order == "variable-string" *))
      if (offset + sbp_strlen( (((path + f.name))), "(((f.termination)))") > len) { return false; }
      offset += sbp_pack_string( buf + offset, (((path + f.name))), "(((f.termination)))");
		((*- elif f.order == "fixed-array" *))
		  for(size_t (((loop_idx))) = 0; (((loop_idx))) < (((f.max_items))); (((loop_idx)))++)
			{
				((*- if f.basetype.is_primitive *))
        (((pack_primitive(f, path + f.name + "[" + loop_idx + "]"))))
				((*- else *))
				(((pack_substruct(f.basetype, path + f.name + "[" + loop_idx + "]."))))
				((*- endif *))
			}
		((*- elif f.order == "variable-array" *))
			for(size_t (((loop_idx))) = 0; (((loop_idx))) < (size_t)((*- if f.count *))(((path + f.count)))((*- else *))(((path + "n_" + f.name )))((*- endif *)); (((loop_idx)))++)
			{
				((*- if f.basetype.is_primitive *))
          (((pack_primitive(f, path + f.name + "[" + loop_idx + "]"))))
				((*- else *))
					(((pack_substruct(f.basetype, path + f.name + "[" + loop_idx + "]."))))
				((*- endif *))
			}
		((*- endif *))
	  ((*- endwith *))
	((*- endfor *))
((*- endmacro *))

static inline bool sbp_pack_(((m.name|convert_unpacked)))(u8 *buf, size_t len, const (((m.name|convert_unpacked))) *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_(((m.name|convert_unpacked)))(msg) > len) { return false; }
  (((pack_substruct(m, "msg->"))))
  return true;
}

((*- macro unpack_primitive(field, path) *))
  if (offset + (((field.basetype.packed_size))) > len) { return false; }
  memcpy(&(((path))), buf + offset, (((field.basetype.packed_size))));
  ((*- if field.basetype.name == "u16" *))
  (((path))) = le16toh( (((path))) );
  ((*- elif field.basetype.name == "u32" *))
  (((path))) = le32toh( (((path))) );
  ((*- elif field.basetype.name == "u64" *))
  (((path))) = le64toh( (((path))) );
  ((*- elif field.basetype.name == "s16" or field.basetype.name == "s32" or field.basetype.name == "s64" *))
  ((*- set tmp_name = (path)|sanitise_path *))
  ((*- if field.basetype.name == "s16" *))
  u16 (((tmp_name))) = *(const u16*)&(((path)));
  (((tmp_name))) = le16toh( (((tmp_name))) );
  ((*- elif field.basetype.name == "s32" *))
  u32 (((tmp_name))) = *(const u32*)&(((path)));
  (((tmp_name))) = le32toh( (((tmp_name))) );
  ((*- elif field.basetype.name == "s64" *))
  u64 (((tmp_name))) = *(const u64*)&(((path)));
  (((tmp_name))) = le64toh( (((tmp_name))) );
  ((*- endif *))
  (((path))) = *(const (((field.basetype.name)))*)&(((tmp_name)));
  ((*- endif *))
  offset += (((field.basetype.packed_size)));
((*- endmacro *))

((*- macro unpack_substruct(substruct, path) *))
((*- for f in substruct.fields *))
	((*- with *))
	((*- set loop_idx = (path + f.name + "_idx")|sanitise_path *))
	((*- if f.order == "single" *))
		((*- if f.basetype.is_primitive *))
      (((unpack_primitive(f, path + f.name))))
		((*- else *))
			(((unpack_substruct(f.basetype, path + f.name + "."))))
		((*- endif *))
	((*- elif f.order == "fixed-string" *))
    if (offset + sizeof( (((path + f.name))) ) > len) { return false; }
		memcpy( (((path + f.name))), buf + offset, sizeof( (((path + f.name))) ) );
		offset += sizeof( (((path + f.name))) );
	((*- elif f.order == "variable-string" *))
    offset += sbp_unpack_string((const char *)buf + offset, len - offset, (((path + f.name))), "(((f.termination)))");
	((*- elif f.order == "fixed-array" *))
		for (size_t (((loop_idx))) = 0; (((loop_idx))) < (((f.max_items))); (((loop_idx)))++)
		{
			((*- if f.basetype.is_primitive *))
        (((unpack_primitive(f, path + f.name + "[" + loop_idx + "]"))))
			((*- else *))
				(((unpack_substruct(f.basetype, path + f.name + "[" + loop_idx + "]."))))
			((*- endif *))
		}
  ((*- elif f.order == "variable-array" *))
    ((*- if not f.count *))
      (((path + "n_" + f.name))) = (u8)((len - offset) / (((f.basetype.packed_size))));
    ((*- endif *))

	  for (size_t (((loop_idx))) = 0; (((loop_idx))) < 
				((*- if f.count *))
				(((path + f.count)))
				((*- else *))
				(((path + "n_" + f.name)))
				((*- endif *));
				(((loop_idx)))++) 
		{
			((*- if f.basetype.is_primitive *))
        (((unpack_primitive(f, path + f.name + "[" + loop_idx + "]"))))
			((*- else *))
				(((unpack_substruct(f.basetype, path + f.name + "[" + loop_idx + "]."))))
			((*- endif *))
		}
	((*- endif *))
	((*- endwith *))
((*- endfor *))
((*- endmacro *))

static inline bool sbp_unpack_(((m.name|convert_unpacked)))(const u8 *buf, size_t len, (((m.name|convert_unpacked))) *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  (((unpack_substruct(m, "msg->"))))
  return true;
}
 
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
      ((*- elif f.order == "variable-string" *))
        if (sbp_strcmp(a.(((path + f.name))), b.(((path + f.name))), "(((f.termination)))") != 0) { return false; }
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
        ((*- if f.count *))
          if (a.(((path + f.count))) != b.(((path + f.count)))) { return false; }
        ((*- else *))
          if (a.(((path + "n_" + f.name))) != b.(((path + "n_" + f.name)))) { return false; }
        ((*- endif *))
        for (size_t (((loop_idx))) = 0; (((loop_idx))) < (size_t)a.((*- if f.count *))(((path + f.count)))((*- else *))(((path + "n_" + f.name)))((*- endif *)); (((loop_idx)))++)
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


#endif /* LIBSBP_(((pkg_name|upper)))_MESSAGES_H */
