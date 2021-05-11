#ifndef LIBSBP_(((pkg_name|upper)))_PACKERS_H
#define LIBSBP_(((pkg_name|upper)))_PACKERS_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string2.h>
//#include <libsbp/unpacked/(((pkg_name))).h>

((*- for i in include *))
//#include <libsbp/unpacked/(((i)))>
((*- endfor *))

((*- for m in msgs *))
                                                                                                              
((*- macro substruct_packed_size(substruct, path, string_path) *))                                                         
	0
  ((*- with *))                                                                                               
  ((*- for f in substruct.fields *))                                                                          
	  +
    ((*- if f.order == "packed-string" *))
    ((*- if f.encoding == "unterminated" *))
      sbp_unterminated_string_packed_len(&(((path + f.name))), (((f.max_items))))
    ((*- elif f.encoding == "null_terminated" *))
      sbp_null_terminated_string_packed_len(&(((path + f.name))), (((f.max_items))))
    ((*- elif f.encoding == "multipart" *))
      sbp_multipart_string_packed_len(&(((path + f.name))), (((f.max_items))), (((f.min_sections))), (((f.max_sections))))
    ((*- else *))
      sbp_sequence_string_packed_len(&(((path + f.name))), (((f.max_items))), (((f.terminator))))
    ((*- endif *))
    ((*- elif f.order == "fixed-string" *))                                                                     
      (((f.max_items)))                                                                                       
	  ((*- elif f.order == "single" *))
		  ((*- if f.basetype.is_primitive *))
				sizeof( ((( path + f.name ))) )
			((*- else *))
				( ((( substruct_packed_size(f.basetype, path + f.name + ".", path + f.name + "_") ))) )
			((*- endif *))
		((*- elif f.order == "fixed-array" *))
		  ( (((f.max_items))) * 
		  ((*- if f.basetype.is_primitive *))
        sizeof( ((( path + f.name )))[0] )
			((*- else *))
				( ((( substruct_packed_size(f.basetype, path + f.name + "[0].", path + f.name + "_") ))) )
			((*- endif *))
		)
		((*- else *))
	    (
	    ((*- if f.size_fn *))
	      (((path)))(((f.size_fn)))
	    ((*- else *))
			  (((path)))(((f.name)))_count
			((*- endif *))
			*
		  ((*- if f.basetype.is_primitive *))
        sizeof( (((path + f.name)))[0] )
			((*- else *))
				( ((( substruct_packed_size(f.basetype, path + f.name + "[0].", path + f.name + "_") ))) )
			((*- endif *))
			)
	  ((*- endif *))
	((*- endfor *))
  ((*- endwith *))
((*- endmacro *))

static inline size_t sbp_packed_size_(((m.name|convert_unpacked)))(const (((m.name|convert_unpacked))) *msg) {                                
	(void)msg;
  return (((substruct_packed_size(m, "msg->", (((m.name|convert_unpacked))) + "_") )));
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

((*- macro pack_substruct(substruct, path, string_path) *))
	((*- for f in substruct.fields *))
	  ((*- with *))
	  ((*- set loop_idx = (path + f.name + "_idx")|sanitise_path *))
    ((*- if f.order == "packed-string" *))
      ((*- if f.encoding == "unterminated" *))
        offset += sbp_unterminated_string_pack(&(((path + f.name))), (((f.max_items))), buf + offset, (uint8_t)(len - offset));
      ((*- elif f.encoding == "null_terminated" *))
        offset += sbp_null_terminated_string_pack(&(((path + f.name))), (((f.max_items))), buf + offset, (uint8_t)(len - offset));
      ((*- elif f.encoding == "multipart" *))
        offset += sbp_multipart_string_pack(&(((path + f.name))), (((f.max_items))), (((f.min_sections))), (((f.max_sections))), buf + offset, (uint8_t)(len - offset));
      ((*- else *))
        offset += sbp_sequence_string_pack(&(((path + f.name))), (((f.max_items))), (((f.terminator))), buf + offset, (uint8_t)(len - offset));
      ((*- endif *))
	  ((*- elif f.order == "single" *))
		  ((*- if f.basetype.is_primitive *))
        (((pack_primitive(f, path + f.name))))
			((*- else *))
				(((pack_substruct(f.basetype, path + f.name + ".", path + f.name + "_"))))
			((*- endif *))
		((*- elif f.order == "fixed-string" *))
      if(offset + sizeof( (((path + f.name))) ) > len) { return false; }
			memcpy(buf + offset, (((path + f.name))), sizeof( (((path + f.name)))));
      // NOLINTNEXTLINE
			offset += sizeof( (((path + f.name))));
		((*- elif f.order == "fixed-array" *))
		  for(size_t (((loop_idx))) = 0; (((loop_idx))) < (((f.max_items))); (((loop_idx)))++)
			{
				((*- if f.basetype.is_primitive *))
        (((pack_primitive(f, path + f.name + "[" + loop_idx + "]"))))
				((*- else *))
				(((pack_substruct(f.basetype, path + f.name + "[" + loop_idx + "].", path + f.name + "_"))))
				((*- endif *))
			}
		((*- elif f.order == "variable-array" *))
			for(size_t (((loop_idx))) = 0; (((loop_idx))) < (size_t)((*- if f.size_fn *))(((path + f.size_fn)))((*- else *))(((path  + f.name + "_count" )))((*- endif *)); (((loop_idx)))++)
			{
				((*- if f.basetype.is_primitive *))
          (((pack_primitive(f, path + f.name + "[" + loop_idx + "]"))))
				((*- else *))
					(((pack_substruct(f.basetype, path + f.name + "[" + loop_idx + "].", path + f.name + "_"))))
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
  (((pack_substruct(m, "msg->", (((m.name|convert_unpacked))) + "_"))))
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

((*- macro unpack_substruct(substruct, path, string_path) *))
((*- for f in substruct.fields *))
	((*- with *))
	((*- set loop_idx = (path + f.name + "_idx")|sanitise_path *))
  ((*- if f.order == "packed-string" *))
    ((*- if f.encoding == "unterminated" *))
      offset += sbp_unterminated_string_unpack(&(((path + f.name))), (((f.max_items))), buf + offset, (uint8_t)(len - offset));
    ((*- elif f.encoding == "null_terminated" *))
      offset += sbp_null_terminated_string_unpack(&(((path + f.name))), (((f.max_items))), buf + offset, (uint8_t)(len - offset));
    ((*- elif f.encoding == "multipart" *))
      offset += sbp_multipart_string_unpack(&(((path + f.name))), (((f.max_items))), (((f.min_sections))), (((f.max_sections))), buf + offset, (uint8_t)(len - offset));
    ((*- else *))
      offset += sbp_sequence_string_unpack(&(((path + f.name))), (((f.max_items))), (((f.terminator))), buf + offset, (uint8_t)(len - offset));
    ((*- endif *))
	((*- elif f.order == "single" *))
		((*- if f.basetype.is_primitive *))
      (((unpack_primitive(f, path + f.name))))
		((*- else *))
			(((unpack_substruct(f.basetype, path + f.name + ".", path + f.name + "_"))))
		((*- endif *))
	((*- elif f.order == "fixed-string" *))
    if (offset + sizeof( (((path + f.name))) ) > len) { return false; }
		memcpy( (((path + f.name))), buf + offset, sizeof( (((path + f.name))) ) );
    // NOLINTNEXTLINE
		offset += sizeof( (((path + f.name))) );
	((*- elif f.order == "fixed-array" *))
		for (size_t (((loop_idx))) = 0; (((loop_idx))) < (((f.max_items))); (((loop_idx)))++)
		{
			((*- if f.basetype.is_primitive *))
        (((unpack_primitive(f, path + f.name + "[" + loop_idx + "]"))))
			((*- else *))
				(((unpack_substruct(f.basetype, path + f.name + "[" + loop_idx + "].", path + f.name + "_"))))
			((*- endif *))
		}
  ((*- elif f.order == "variable-array" *))
    ((*- if not f.size_fn *))
      (((path + f.name + "_count"))) = (u8)((len - offset) / (((f.basetype.packed_size))));
    ((*- endif *))

	  for (size_t (((loop_idx))) = 0; (((loop_idx))) < 
				((*- if f.size_fn *))
				(((path + f.size_fn)))
				((*- else *))
				(((path + f.name + "_count")))
				((*- endif *));
				(((loop_idx)))++) 
		{
			((*- if f.basetype.is_primitive *))
        (((unpack_primitive(f, path + f.name + "[" + loop_idx + "]"))))
			((*- else *))
				(((unpack_substruct(f.basetype, path + f.name + "[" + loop_idx + "].", path + f.name + "_"))))
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
  (((unpack_substruct(m, "msg->", (((m.name|convert_unpacked))) + "_"))))
  return true;
}
 
((*- endfor *))

#endif

