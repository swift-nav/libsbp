#ifndef LIBSBP_(((pkg_name|upper)))_PACKERS_H
#define LIBSBP_(((pkg_name|upper)))_PACKERS_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/(((pkg_name))).h>

((*- for i in include *))
#include <libsbp/unpacked/(((i)))>
((*- endfor *))

((*- for m in msgs *))
                                                                                                              
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
  // NOLINTNEXTLINE
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
      // NOLINTNEXTLINE
			offset += sizeof( (((path + f.name))));
		((*- elif f.order == "variable-string" *))
      if (offset + sbp_strlen( (((path + f.name))), "(((f.termination)))") > len) { return false; }
      // NOLINTNEXTLINE
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
  // NOLINTNEXTLINE
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
    // NOLINTNEXTLINE
		offset += sizeof( (((path + f.name))) );
	((*- elif f.order == "variable-string" *))
  // NOLINTNEXTLINE
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
 
((*- endfor *))

#endif
