/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Fergus Noble <fergus@swift-nav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
#include <stdio.h>
#include <ctype.h>
#include "../include/libsbp/common.h"
((*- for i in includes *))
#include "../include/libsbp/(((i)))"
((*- endfor *))

((*- for spec in package_specs *))
((= set some helpful variables for each package =))
((*- with *))
((*- set msgs = spec.definitions *))
((*- set name = spec.filepath[1] *))
((*- set description = spec.description *))
/*****************************************************************************
 * Automatically generated from (((name))).yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup (((pkg_name))) (((pkg_name|capitalize)))
 *
 * (((description|commentify)))
 * \{ */


((* for m in msgs *)) ((= Iterate over each message =))

((*- if m.fields *))
((*- set in_ptr_type=(((m.identifier|convert))) *))
((*- else *))
((*- set in_ptr_type="void" *))
((*- endif *))

((*- if m.sbp_id -*))
#define MSG_((('%04X'|format(m.sbp_id))))_TO_JSON (((m.identifier|convert)))_to_json_str

((= The ID determines for me whether this is an SBP message or a sub structure =))
int (((m.identifier|convert)))_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, (((in_ptr_type))) * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
((*- else -*)) ((= if not a message I dont have any of the framing types =))
int (((m.identifier|convert)))_to_json_str( (((in_ptr_type))) * in, uint64_t max_len, char* out_str) {
((*- endif -*)) ((= end if m.sbp_id  =))
  (void) in;
  (void) out_str;
  (void) max_len;
  ((= Simple type processing (done for brevity)  =))
  ((*- if (m|entirely_simple) and m.sbp_id *))
  return sprintf(out_str, (((m|mk_str_format_msg))), (((m|mk_arg_list_msg))));
  ((*- elif (m|entirely_simple) *))
  return sprintf(out_str, (((m|mk_str_format))), (((m|mk_arg_list))));
  ((*- else *))   ((= No Simple type=))
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;

  ((*- if m.sbp_id -*)) ((= If message print out framing items=))
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);
  ((*- else -*))
  json_bufp += snprintf(out_str, json_end - json_bufp, "{");
  ((*- endif *))

  ((= Separate Print for each field=))
  ((*- for field in m.fields -*))
  ((= simple type field =))
  ((*- if (m.sbp_id or field != m.fields[0] ) -*))  ((= comma in between every field except first=))
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
  ((*- endif -*))
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"(((field.identifier)))\": ");
  ((*- if (field.type_id|is_simple) -*))
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "(((field|get_format_str)))", in->(((field.identifier))));
  ((= Nested type field =))
  ((*- elif (field.type_id != "array" and not field.type_id|is_string) -*))
  json_bufp += (((field.type_id|convert)))_to_json_str(&in->(((field.identifier))), json_end - json_bufp, json_bufp);
  ((= fixed legth string (special type of fixed size array in our case) =))
  ((*- elif (field|mk_id|is_string) and (field.options.get('size', None)) -*))
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");
  for (int i=0; i < (((field.options.get('size').value))); i++) {
    unsigned char c = in->(((field.identifier)))[i];
    if (isprint(c) && c != '\\') {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "%c", c);
    }
    else {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "\\\\u00%02x", c);
    }
  }
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");
  ((*- elif (field|mk_id|is_string and not (field.options.get('size', None))) -*))
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");
  for (int i=0; i < (uint8_t *) in + msg_len - (uint8_t *) &(in->(((field.identifier)))); i++) {
    unsigned char c = in->(((field.identifier)))[i];
    if (isprint(c) && c != '\\') {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "%c", c);
    }
    else {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "\\\\u00%02x", c);
    }
  }
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");
  ((*- elif (field.type_id == "array" ) -*))
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");
  ((*- if field.options.get('size', None) -*))
  ((=loop over fixed size array =))

  for (int i=0; i < (((field.options.get('size').value))); i++) {

  ((*- elif field == m.fields[-1] -*))  ((= variablelength array only at end =))
  uint8_t msg_array_offset = (uint8_t *)&(in->(((field.identifier)))) - (uint8_t *)in;
  uint8_t msg_array_size = msg_len - msg_array_offset;
  uint8_t msg_array_count = msg_array_size / sizeof( (((field|mk_id))) );
  for (int i=0; i < msg_array_count; i++) {
  ((*- endif -*))  ((= variable vs fixed =))
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }
  ((*- if (field|mk_id|is_simple) -*))
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "(((field|get_format_str)))", in->(((field.identifier)))[i]);
  ((*- else -*))
    json_bufp += (((field|mk_id)))_to_json_str(&(in->(((field.identifier))))[i], json_end - json_bufp, json_bufp);
  ((*- endif -*))
  }
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");
  ((*- endif -*))
  ((*- endfor -*))
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;
  ((*- endif -*))
}
((* endfor *))
((* endwith *))
((* endfor *))

int sbp2json(u16 sender_id, u16 msg_type, u8 msg_len,
                       u8 payload[], uint64_t max_len, char* out_str) {
switch(msg_type) {
((*- for spec in package_specs *))
((*- with *))
((*- set msgs = spec.definitions *))
((*- set name = spec.filepath[1] *))
((*- set description = spec.description *))
((*-for m in msgs *))
((*- if m.fields *))
((*- set in_ptr_type=(((m.identifier|convert))) *))
((*- else *))
((*- set in_ptr_type="void" *))
((*- endif *))
  ((*- if m.sbp_id *))
  case (((m.sbp_id))):
    return (((m.identifier|convert)))_to_json_str(sender_id, msg_type, msg_len, ( (((in_ptr_type))) *) payload,
           max_len, out_str);
((*- endif *))
((*- endfor *))
((*- endwith *))
((*- endfor *))
  default:
    return 0;
  }
}
