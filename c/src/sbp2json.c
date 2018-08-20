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
#include "../include/libsbp/acquisition.h"
#include "../include/libsbp/bootload.h"
#include "../include/libsbp/ext_events.h"
#include "../include/libsbp/file_io.h"
#include "../include/libsbp/flash.h"
#include "../include/libsbp/gnss.h"
#include "../include/libsbp/imu.h"
#include "../include/libsbp/logging.h"
#include "../include/libsbp/mag.h"
#include "../include/libsbp/navigation.h"
#include "../include/libsbp/ndb.h"
#include "../include/libsbp/observation.h"
#include "../include/libsbp/orientation.h"
#include "../include/libsbp/piksi.h"
#include "../include/libsbp/sbas.h"
#include "../include/libsbp/settings.h"
#include "../include/libsbp/ssr.h"
#include "../include/libsbp/system.h"
#include "../include/libsbp/tracking.h"
#include "../include/libsbp/user.h"
#include "../include/libsbp/vehicle.h"

/*****************************************************************************
 * Automatically generated from acquisition.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 * * Satellite acquisition messages from the device.
 * \{ */


 #define MSG_002F_TO_JSON msg_acq_result_t_to_json_str


int msg_acq_result_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_acq_result_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"cn0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->cn0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"cp\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->cp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"cf\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->cf);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sid\": ");json_bufp += sbp_gnss_signal_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_001F_TO_JSON msg_acq_result_dep_c_t_to_json_str


int msg_acq_result_dep_c_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_acq_result_dep_c_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"cn0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->cn0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"cp\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->cp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"cf\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->cf);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sid\": ");json_bufp += gnss_signal_dep_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0014_TO_JSON msg_acq_result_dep_b_t_to_json_str


int msg_acq_result_dep_b_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_acq_result_dep_b_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"snr\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->snr);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"cp\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->cp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"cf\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->cf);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sid\": ");json_bufp += gnss_signal_dep_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0015_TO_JSON msg_acq_result_dep_a_t_to_json_str


int msg_acq_result_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_acq_result_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"snr\": %f, \"cp\": %f, \"cf\": %f, \"prn\": %hhu}", msg_type, sender_id, msg_len, in->snr, in->cp, in->cf, in->prn);}
 
int acq_sv_profile_t_to_json_str( acq_sv_profile_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;json_bufp += snprintf(out_str, json_end - json_bufp, "{");

  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"job_type\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->job_type);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"status\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->status);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"cn0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hu", in->cn0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"int_time\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->int_time);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sid\": ");json_bufp += sbp_gnss_signal_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"bin_width\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hu", in->bin_width);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"timestamp\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->timestamp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"time_spent\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->time_spent);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"cf_min\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%d", in->cf_min);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"cf_max\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%d", in->cf_max);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"cf\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%d", in->cf);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"cp\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->cp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 
int acq_sv_profile_dep_t_to_json_str( acq_sv_profile_dep_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;json_bufp += snprintf(out_str, json_end - json_bufp, "{");

  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"job_type\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->job_type);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"status\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->status);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"cn0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hu", in->cn0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"int_time\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->int_time);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sid\": ");json_bufp += gnss_signal_dep_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"bin_width\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hu", in->bin_width);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"timestamp\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->timestamp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"time_spent\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->time_spent);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"cf_min\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%d", in->cf_min);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"cf_max\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%d", in->cf_max);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"cf\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%d", in->cf);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"cp\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->cp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_002E_TO_JSON msg_acq_sv_profile_t_to_json_str


int msg_acq_sv_profile_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_acq_sv_profile_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"acq_sv_profile\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");
  uint8_t msg_array_offset = (uint8_t *)&(in->acq_sv_profile) - (uint8_t *)in;
  uint8_t msg_array_size = msg_len - msg_array_offset;
  uint8_t msg_array_count = msg_array_size / sizeof( acq_sv_profile_t );
  for (int i=0; i < msg_array_count; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += acq_sv_profile_t_to_json_str(&(in->acq_sv_profile)[i], json_end - json_bufp, json_bufp);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_001E_TO_JSON msg_acq_sv_profile_dep_t_to_json_str


int msg_acq_sv_profile_dep_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_acq_sv_profile_dep_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"acq_sv_profile\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");
  uint8_t msg_array_offset = (uint8_t *)&(in->acq_sv_profile) - (uint8_t *)in;
  uint8_t msg_array_size = msg_len - msg_array_offset;
  uint8_t msg_array_count = msg_array_size / sizeof( acq_sv_profile_dep_t );
  for (int i=0; i < msg_array_count; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += acq_sv_profile_dep_t_to_json_str(&(in->acq_sv_profile)[i], json_end - json_bufp, json_bufp);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}




/*****************************************************************************
 * Automatically generated from bootload.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 *  * Messages for the bootloading configuration of a Piksi 2.3.1.  This message
 * group does not apply to Piksi Multi.
 * 
 * Note that some of these messages share the same message type ID for both the
 * host request and the device response.
 * \{ */


 #define MSG_00B3_TO_JSON msg_bootloader_handshake_req_t_to_json_str


int msg_bootloader_handshake_req_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, void * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_00B4_TO_JSON msg_bootloader_handshake_resp_t_to_json_str


int msg_bootloader_handshake_resp_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_bootloader_handshake_resp_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"flags\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->flags);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"version\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");
  for (int i=0; i < (uint8_t *) in + msg_len - (uint8_t *) &(in->version); i++) {
    unsigned char c = in->version[i];
    if (isprint(c) && c != '\\') {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "%c", c);
    }
    else {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "\\\\u00%02x", c);
    }
  }
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_00B1_TO_JSON msg_bootloader_jump_to_app_t_to_json_str


int msg_bootloader_jump_to_app_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_bootloader_jump_to_app_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"jump\": %hhu}", msg_type, sender_id, msg_len, in->jump);}
 #define MSG_00DE_TO_JSON msg_nap_device_dna_req_t_to_json_str


int msg_nap_device_dna_req_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, void * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_00DD_TO_JSON msg_nap_device_dna_resp_t_to_json_str


int msg_nap_device_dna_resp_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_nap_device_dna_resp_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"dna\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 8; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->dna[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_00B0_TO_JSON msg_bootloader_handshake_dep_a_t_to_json_str


int msg_bootloader_handshake_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_bootloader_handshake_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"handshake\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");
  uint8_t msg_array_offset = (uint8_t *)&(in->handshake) - (uint8_t *)in;
  uint8_t msg_array_size = msg_len - msg_array_offset;
  uint8_t msg_array_count = msg_array_size / sizeof( u8 );
  for (int i=0; i < msg_array_count; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->handshake[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}




/*****************************************************************************
 * Automatically generated from ext_events.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 *  * Messages reporting accurately-timestamped external events,
 * e.g. camera shutter time.
 * \{ */


 #define MSG_0101_TO_JSON msg_ext_event_t_to_json_str


int msg_ext_event_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ext_event_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"wn\": %hu, \"tow\": %u, \"ns_residual\": %d, \"flags\": %hhu, \"pin\": %hhu}", msg_type, sender_id, msg_len, in->wn, in->tow, in->ns_residual, in->flags, in->pin);}




/*****************************************************************************
 * Automatically generated from file_io.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 *  * Messages for using device's onboard flash filesystem
 * functionality. This allows data to be stored persistently in the
 * device's program flash with wear-levelling using a simple filesystem
 * interface. The file system interface (CFS) defines an abstract API
 * for reading directories and for reading and writing files.
 * 
 * Note that some of these messages share the same message type ID for both the
 * host request and the device response.
 * \{ */


 #define MSG_00A8_TO_JSON msg_fileio_read_req_t_to_json_str


int msg_fileio_read_req_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_fileio_read_req_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sequence\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->sequence);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"offset\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->offset);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"chunk_size\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->chunk_size);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"filename\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");
  for (int i=0; i < (uint8_t *) in + msg_len - (uint8_t *) &(in->filename); i++) {
    unsigned char c = in->filename[i];
    if (isprint(c) && c != '\\') {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "%c", c);
    }
    else {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "\\\\u00%02x", c);
    }
  }
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_00A3_TO_JSON msg_fileio_read_resp_t_to_json_str


int msg_fileio_read_resp_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_fileio_read_resp_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sequence\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->sequence);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"contents\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");
  uint8_t msg_array_offset = (uint8_t *)&(in->contents) - (uint8_t *)in;
  uint8_t msg_array_size = msg_len - msg_array_offset;
  uint8_t msg_array_count = msg_array_size / sizeof( u8 );
  for (int i=0; i < msg_array_count; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->contents[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_00A9_TO_JSON msg_fileio_read_dir_req_t_to_json_str


int msg_fileio_read_dir_req_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_fileio_read_dir_req_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sequence\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->sequence);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"offset\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->offset);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"dirname\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");
  for (int i=0; i < (uint8_t *) in + msg_len - (uint8_t *) &(in->dirname); i++) {
    unsigned char c = in->dirname[i];
    if (isprint(c) && c != '\\') {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "%c", c);
    }
    else {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "\\\\u00%02x", c);
    }
  }
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_00AA_TO_JSON msg_fileio_read_dir_resp_t_to_json_str


int msg_fileio_read_dir_resp_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_fileio_read_dir_resp_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sequence\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->sequence);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"contents\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");
  uint8_t msg_array_offset = (uint8_t *)&(in->contents) - (uint8_t *)in;
  uint8_t msg_array_size = msg_len - msg_array_offset;
  uint8_t msg_array_count = msg_array_size / sizeof( u8 );
  for (int i=0; i < msg_array_count; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->contents[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_00AC_TO_JSON msg_fileio_remove_t_to_json_str


int msg_fileio_remove_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_fileio_remove_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"filename\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");
  for (int i=0; i < (uint8_t *) in + msg_len - (uint8_t *) &(in->filename); i++) {
    unsigned char c = in->filename[i];
    if (isprint(c) && c != '\\') {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "%c", c);
    }
    else {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "\\\\u00%02x", c);
    }
  }
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_00AD_TO_JSON msg_fileio_write_req_t_to_json_str


int msg_fileio_write_req_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_fileio_write_req_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sequence\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->sequence);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"offset\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->offset);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"filename\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");
  for (int i=0; i < (uint8_t *) in + msg_len - (uint8_t *) &(in->filename); i++) {
    unsigned char c = in->filename[i];
    if (isprint(c) && c != '\\') {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "%c", c);
    }
    else {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "\\\\u00%02x", c);
    }
  }
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"data\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");
  uint8_t msg_array_offset = (uint8_t *)&(in->data) - (uint8_t *)in;
  uint8_t msg_array_size = msg_len - msg_array_offset;
  uint8_t msg_array_count = msg_array_size / sizeof( u8 );
  for (int i=0; i < msg_array_count; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->data[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_00AB_TO_JSON msg_fileio_write_resp_t_to_json_str


int msg_fileio_write_resp_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_fileio_write_resp_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"sequence\": %u}", msg_type, sender_id, msg_len, in->sequence);}




/*****************************************************************************
 * Automatically generated from flash.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 *  * Messages for reading/writing the device's onboard flash memory. Many
 * of these messages target specific flash memory peripherals used in
 * Swift Navigation devices: the STM32 flash and the M25Pxx FPGA
 * configuration flash from Piksi 2.3.1.  This module does not apply 
 * to Piksi Multi.
 * \{ */


 #define MSG_00E6_TO_JSON msg_flash_program_t_to_json_str


int msg_flash_program_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_flash_program_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"target\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->target);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"addr_start\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 3; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->addr_start[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"addr_len\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->addr_len);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"data\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");
  uint8_t msg_array_offset = (uint8_t *)&(in->data) - (uint8_t *)in;
  uint8_t msg_array_size = msg_len - msg_array_offset;
  uint8_t msg_array_count = msg_array_size / sizeof( u8 );
  for (int i=0; i < msg_array_count; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->data[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_00E0_TO_JSON msg_flash_done_t_to_json_str


int msg_flash_done_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_flash_done_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"response\": %hhu}", msg_type, sender_id, msg_len, in->response);}
 #define MSG_00E7_TO_JSON msg_flash_read_req_t_to_json_str


int msg_flash_read_req_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_flash_read_req_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"target\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->target);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"addr_start\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 3; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->addr_start[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"addr_len\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->addr_len);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_00E1_TO_JSON msg_flash_read_resp_t_to_json_str


int msg_flash_read_resp_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_flash_read_resp_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"target\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->target);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"addr_start\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 3; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->addr_start[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"addr_len\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->addr_len);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_00E2_TO_JSON msg_flash_erase_t_to_json_str


int msg_flash_erase_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_flash_erase_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"target\": %hhu, \"sector_num\": %u}", msg_type, sender_id, msg_len, in->target, in->sector_num);}
 #define MSG_00E3_TO_JSON msg_stm_flash_lock_sector_t_to_json_str


int msg_stm_flash_lock_sector_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_stm_flash_lock_sector_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"sector\": %u}", msg_type, sender_id, msg_len, in->sector);}
 #define MSG_00E4_TO_JSON msg_stm_flash_unlock_sector_t_to_json_str


int msg_stm_flash_unlock_sector_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_stm_flash_unlock_sector_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"sector\": %u}", msg_type, sender_id, msg_len, in->sector);}
 #define MSG_00E8_TO_JSON msg_stm_unique_id_req_t_to_json_str


int msg_stm_unique_id_req_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, void * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_00E5_TO_JSON msg_stm_unique_id_resp_t_to_json_str


int msg_stm_unique_id_resp_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_stm_unique_id_resp_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"stm_id\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 12; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->stm_id[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_00F3_TO_JSON msg_m25_flash_write_status_t_to_json_str


int msg_m25_flash_write_status_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_m25_flash_write_status_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"status\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 1; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->status[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}




/*****************************************************************************
 * Automatically generated from gnss.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 * * Various structs shared between modules
 * \{ */


 
int sbp_gnss_signal_t_to_json_str( sbp_gnss_signal_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"sat\": %hhu, \"code\": %hhu}", in->sat, in->code);}
 
int gnss_signal_dep_t_to_json_str( gnss_signal_dep_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"sat\": %hu, \"code\": %hhu, \"reserved\": %hhu}", in->sat, in->code, in->reserved);}
 
int gps_time_dep_t_to_json_str( gps_time_dep_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"tow\": %u, \"wn\": %hu}", in->tow, in->wn);}
 
int gps_time_sec_t_to_json_str( gps_time_sec_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"tow\": %u, \"wn\": %hu}", in->tow, in->wn);}
 
int sbp_gps_time_t_to_json_str( sbp_gps_time_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"tow\": %u, \"ns_residual\": %d, \"wn\": %hu}", in->tow, in->ns_residual, in->wn);}
 
int carrier_phase_t_to_json_str( carrier_phase_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"i\": %d, \"f\": %hhu}", in->i, in->f);}




/*****************************************************************************
 * Automatically generated from imu.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 * * Inertial Measurement Unit (IMU) messages.
 * \{ */


 #define MSG_0900_TO_JSON msg_imu_raw_t_to_json_str


int msg_imu_raw_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_imu_raw_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"tow_f\": %hhu, \"acc_x\": %hd, \"acc_y\": %hd, \"acc_z\": %hd, \"gyr_x\": %hd, \"gyr_y\": %hd, \"gyr_z\": %hd}", msg_type, sender_id, msg_len, in->tow, in->tow_f, in->acc_x, in->acc_y, in->acc_z, in->gyr_x, in->gyr_y, in->gyr_z);}
 #define MSG_0901_TO_JSON msg_imu_aux_t_to_json_str


int msg_imu_aux_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_imu_aux_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"imu_type\": %hhu, \"temp\": %hd, \"imu_conf\": %hhu}", msg_type, sender_id, msg_len, in->imu_type, in->temp, in->imu_conf);}




/*****************************************************************************
 * Automatically generated from logging.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 *  * Logging and debugging messages from the device.
 * \{ */


 #define MSG_0401_TO_JSON msg_log_t_to_json_str


int msg_log_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_log_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"level\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->level);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"text\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");
  for (int i=0; i < (uint8_t *) in + msg_len - (uint8_t *) &(in->text); i++) {
    unsigned char c = in->text[i];
    if (isprint(c) && c != '\\') {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "%c", c);
    }
    else {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "\\\\u00%02x", c);
    }
  }
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0402_TO_JSON msg_fwd_t_to_json_str


int msg_fwd_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_fwd_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"source\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->source);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"protocol\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->protocol);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"fwd_payload\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");
  for (int i=0; i < (uint8_t *) in + msg_len - (uint8_t *) &(in->fwd_payload); i++) {
    unsigned char c = in->fwd_payload[i];
    if (isprint(c) && c != '\\') {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "%c", c);
    }
    else {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "\\\\u00%02x", c);
    }
  }
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0012_TO_JSON msg_tweet_t_to_json_str


int msg_tweet_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_tweet_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"tweet\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");
  for (int i=0; i < 140; i++) {
    unsigned char c = in->tweet[i];
    if (isprint(c) && c != '\\') {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "%c", c);
    }
    else {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "\\\\u00%02x", c);
    }
  }
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0010_TO_JSON msg_print_dep_t_to_json_str


int msg_print_dep_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_print_dep_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"text\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");
  for (int i=0; i < (uint8_t *) in + msg_len - (uint8_t *) &(in->text); i++) {
    unsigned char c = in->text[i];
    if (isprint(c) && c != '\\') {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "%c", c);
    }
    else {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "\\\\u00%02x", c);
    }
  }
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}




/*****************************************************************************
 * Automatically generated from mag.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 * * Magnetometer (mag) messages.
 * \{ */


 #define MSG_0902_TO_JSON msg_mag_raw_t_to_json_str


int msg_mag_raw_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_mag_raw_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"tow_f\": %hhu, \"mag_x\": %hd, \"mag_y\": %hd, \"mag_z\": %hd}", msg_type, sender_id, msg_len, in->tow, in->tow_f, in->mag_x, in->mag_y, in->mag_z);}




/*****************************************************************************
 * Automatically generated from navigation.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 *  * Geodetic navigation messages reporting GPS time, position, velocity,
 * and baseline position solutions. For position solutions, these
 * messages define several different position solutions: single-point
 * (SPP), RTK, and pseudo-absolute position solutions.
 * 
 * The SPP is the standalone, absolute GPS position solution using only
 * a single receiver. The RTK solution is the differential GPS
 * solution, which can use either a fixed/integer or floating carrier
 * phase ambiguity. The pseudo-absolute position solution uses a
 * user-provided, well-surveyed base station position (if available)
 * and the RTK solution in tandem.
 * 
 * When the inertial navigation mode indicates that the IMU is used,
 * all messages are reported in the vehicle body frame as defined by
 * device settings.  By default, the vehicle body frame is configured to be
 * coincident with the antenna phase center.  When there is no inertial
 * navigation, the solution will be reported at the phase center of the antenna.
 * \{ */


 #define MSG_0102_TO_JSON msg_gps_time_t_to_json_str


int msg_gps_time_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_gps_time_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"wn\": %hu, \"tow\": %u, \"ns_residual\": %d, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->wn, in->tow, in->ns_residual, in->flags);}
 #define MSG_0103_TO_JSON msg_utc_time_t_to_json_str


int msg_utc_time_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_utc_time_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"flags\": %hhu, \"tow\": %u, \"year\": %hu, \"month\": %hhu, \"day\": %hhu, \"hours\": %hhu, \"minutes\": %hhu, \"seconds\": %hhu, \"ns\": %u}", msg_type, sender_id, msg_len, in->flags, in->tow, in->year, in->month, in->day, in->hours, in->minutes, in->seconds, in->ns);}
 #define MSG_0208_TO_JSON msg_dops_t_to_json_str


int msg_dops_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_dops_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"gdop\": %hu, \"pdop\": %hu, \"tdop\": %hu, \"hdop\": %hu, \"vdop\": %hu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->gdop, in->pdop, in->tdop, in->hdop, in->vdop, in->flags);}
 #define MSG_0209_TO_JSON msg_pos_ecef_t_to_json_str


int msg_pos_ecef_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_pos_ecef_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"x\": %f, \"y\": %f, \"z\": %f, \"accuracy\": %hu, \"n_sats\": %hhu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->x, in->y, in->z, in->accuracy, in->n_sats, in->flags);}
 #define MSG_0214_TO_JSON msg_pos_ecef_cov_t_to_json_str


int msg_pos_ecef_cov_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_pos_ecef_cov_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"x\": %f, \"y\": %f, \"z\": %f, \"cov_x_x\": %f, \"cov_x_y\": %f, \"cov_x_z\": %f, \"cov_y_y\": %f, \"cov_y_z\": %f, \"cov_z_z\": %f, \"n_sats\": %hhu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->x, in->y, in->z, in->cov_x_x, in->cov_x_y, in->cov_x_z, in->cov_y_y, in->cov_y_z, in->cov_z_z, in->n_sats, in->flags);}
 #define MSG_020A_TO_JSON msg_pos_llh_t_to_json_str


int msg_pos_llh_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_pos_llh_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"lat\": %f, \"lon\": %f, \"height\": %f, \"h_accuracy\": %hu, \"v_accuracy\": %hu, \"n_sats\": %hhu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->lat, in->lon, in->height, in->h_accuracy, in->v_accuracy, in->n_sats, in->flags);}
 #define MSG_0211_TO_JSON msg_pos_llh_cov_t_to_json_str


int msg_pos_llh_cov_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_pos_llh_cov_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"lat\": %f, \"lon\": %f, \"height\": %f, \"cov_n_n\": %f, \"cov_n_e\": %f, \"cov_n_d\": %f, \"cov_e_e\": %f, \"cov_e_d\": %f, \"cov_d_d\": %f, \"n_sats\": %hhu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->lat, in->lon, in->height, in->cov_n_n, in->cov_n_e, in->cov_n_d, in->cov_e_e, in->cov_e_d, in->cov_d_d, in->n_sats, in->flags);}
 #define MSG_020B_TO_JSON msg_baseline_ecef_t_to_json_str


int msg_baseline_ecef_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_baseline_ecef_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"x\": %d, \"y\": %d, \"z\": %d, \"accuracy\": %hu, \"n_sats\": %hhu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->x, in->y, in->z, in->accuracy, in->n_sats, in->flags);}
 #define MSG_020C_TO_JSON msg_baseline_ned_t_to_json_str


int msg_baseline_ned_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_baseline_ned_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"n\": %d, \"e\": %d, \"d\": %d, \"h_accuracy\": %hu, \"v_accuracy\": %hu, \"n_sats\": %hhu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->n, in->e, in->d, in->h_accuracy, in->v_accuracy, in->n_sats, in->flags);}
 #define MSG_020D_TO_JSON msg_vel_ecef_t_to_json_str


int msg_vel_ecef_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_vel_ecef_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"x\": %d, \"y\": %d, \"z\": %d, \"accuracy\": %hu, \"n_sats\": %hhu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->x, in->y, in->z, in->accuracy, in->n_sats, in->flags);}
 #define MSG_0215_TO_JSON msg_vel_ecef_cov_t_to_json_str


int msg_vel_ecef_cov_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_vel_ecef_cov_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"x\": %d, \"y\": %d, \"z\": %d, \"cov_x_x\": %f, \"cov_x_y\": %f, \"cov_x_z\": %f, \"cov_y_y\": %f, \"cov_y_z\": %f, \"cov_z_z\": %f, \"n_sats\": %hhu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->x, in->y, in->z, in->cov_x_x, in->cov_x_y, in->cov_x_z, in->cov_y_y, in->cov_y_z, in->cov_z_z, in->n_sats, in->flags);}
 #define MSG_020E_TO_JSON msg_vel_ned_t_to_json_str


int msg_vel_ned_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_vel_ned_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"n\": %d, \"e\": %d, \"d\": %d, \"h_accuracy\": %hu, \"v_accuracy\": %hu, \"n_sats\": %hhu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->n, in->e, in->d, in->h_accuracy, in->v_accuracy, in->n_sats, in->flags);}
 #define MSG_0212_TO_JSON msg_vel_ned_cov_t_to_json_str


int msg_vel_ned_cov_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_vel_ned_cov_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"n\": %d, \"e\": %d, \"d\": %d, \"cov_n_n\": %f, \"cov_n_e\": %f, \"cov_n_d\": %f, \"cov_e_e\": %f, \"cov_e_d\": %f, \"cov_d_d\": %f, \"n_sats\": %hhu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->n, in->e, in->d, in->cov_n_n, in->cov_n_e, in->cov_n_d, in->cov_e_e, in->cov_e_d, in->cov_d_d, in->n_sats, in->flags);}
 #define MSG_0213_TO_JSON msg_vel_body_t_to_json_str


int msg_vel_body_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_vel_body_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"x\": %d, \"y\": %d, \"z\": %d, \"cov_x_x\": %f, \"cov_x_y\": %f, \"cov_x_z\": %f, \"cov_y_y\": %f, \"cov_y_z\": %f, \"cov_z_z\": %f, \"n_sats\": %hhu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->x, in->y, in->z, in->cov_x_x, in->cov_x_y, in->cov_x_z, in->cov_y_y, in->cov_y_z, in->cov_z_z, in->n_sats, in->flags);}
 #define MSG_0210_TO_JSON msg_age_corrections_t_to_json_str


int msg_age_corrections_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_age_corrections_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"age\": %hu}", msg_type, sender_id, msg_len, in->tow, in->age);}
 #define MSG_0100_TO_JSON msg_gps_time_dep_a_t_to_json_str


int msg_gps_time_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_gps_time_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"wn\": %hu, \"tow\": %u, \"ns_residual\": %d, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->wn, in->tow, in->ns_residual, in->flags);}
 #define MSG_0206_TO_JSON msg_dops_dep_a_t_to_json_str


int msg_dops_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_dops_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"gdop\": %hu, \"pdop\": %hu, \"tdop\": %hu, \"hdop\": %hu, \"vdop\": %hu}", msg_type, sender_id, msg_len, in->tow, in->gdop, in->pdop, in->tdop, in->hdop, in->vdop);}
 #define MSG_0200_TO_JSON msg_pos_ecef_dep_a_t_to_json_str


int msg_pos_ecef_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_pos_ecef_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"x\": %f, \"y\": %f, \"z\": %f, \"accuracy\": %hu, \"n_sats\": %hhu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->x, in->y, in->z, in->accuracy, in->n_sats, in->flags);}
 #define MSG_0201_TO_JSON msg_pos_llh_dep_a_t_to_json_str


int msg_pos_llh_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_pos_llh_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"lat\": %f, \"lon\": %f, \"height\": %f, \"h_accuracy\": %hu, \"v_accuracy\": %hu, \"n_sats\": %hhu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->lat, in->lon, in->height, in->h_accuracy, in->v_accuracy, in->n_sats, in->flags);}
 #define MSG_0202_TO_JSON msg_baseline_ecef_dep_a_t_to_json_str


int msg_baseline_ecef_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_baseline_ecef_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"x\": %d, \"y\": %d, \"z\": %d, \"accuracy\": %hu, \"n_sats\": %hhu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->x, in->y, in->z, in->accuracy, in->n_sats, in->flags);}
 #define MSG_0203_TO_JSON msg_baseline_ned_dep_a_t_to_json_str


int msg_baseline_ned_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_baseline_ned_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"n\": %d, \"e\": %d, \"d\": %d, \"h_accuracy\": %hu, \"v_accuracy\": %hu, \"n_sats\": %hhu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->n, in->e, in->d, in->h_accuracy, in->v_accuracy, in->n_sats, in->flags);}
 #define MSG_0204_TO_JSON msg_vel_ecef_dep_a_t_to_json_str


int msg_vel_ecef_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_vel_ecef_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"x\": %d, \"y\": %d, \"z\": %d, \"accuracy\": %hu, \"n_sats\": %hhu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->x, in->y, in->z, in->accuracy, in->n_sats, in->flags);}
 #define MSG_0205_TO_JSON msg_vel_ned_dep_a_t_to_json_str


int msg_vel_ned_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_vel_ned_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"n\": %d, \"e\": %d, \"d\": %d, \"h_accuracy\": %hu, \"v_accuracy\": %hu, \"n_sats\": %hhu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->n, in->e, in->d, in->h_accuracy, in->v_accuracy, in->n_sats, in->flags);}
 #define MSG_0207_TO_JSON msg_baseline_heading_dep_a_t_to_json_str


int msg_baseline_heading_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_baseline_heading_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"heading\": %u, \"n_sats\": %hhu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->heading, in->n_sats, in->flags);}




/*****************************************************************************
 * Automatically generated from ndb.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 *  * Messages for logging NDB events.
 * \{ */


 #define MSG_0400_TO_JSON msg_ndb_event_t_to_json_str


int msg_ndb_event_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ndb_event_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"recv_time\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%lu", in->recv_time);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"event\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->event);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"object_type\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->object_type);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"result\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->result);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"data_source\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->data_source);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"object_sid\": ");json_bufp += sbp_gnss_signal_t_to_json_str(&in->object_sid, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"src_sid\": ");json_bufp += sbp_gnss_signal_t_to_json_str(&in->src_sid, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"original_sender\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hu", in->original_sender);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}




/*****************************************************************************
 * Automatically generated from observation.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 * * Satellite observation messages from the device.
 * \{ */


 
int observation_header_t_to_json_str( observation_header_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;json_bufp += snprintf(out_str, json_end - json_bufp, "{");

  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"t\": ");json_bufp += sbp_gps_time_t_to_json_str(&in->t, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"n_obs\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->n_obs);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 
int doppler_t_to_json_str( doppler_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"i\": %hd, \"f\": %hhu}", in->i, in->f);}
 
int packed_obs_content_t_to_json_str( packed_obs_content_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;json_bufp += snprintf(out_str, json_end - json_bufp, "{");

  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"P\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->P);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"L\": ");json_bufp += carrier_phase_t_to_json_str(&in->L, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"D\": ");json_bufp += doppler_t_to_json_str(&in->D, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"cn0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->cn0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"lock\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->lock);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"flags\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->flags);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sid\": ");json_bufp += sbp_gnss_signal_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_004A_TO_JSON msg_obs_t_to_json_str


int msg_obs_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_obs_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"header\": ");json_bufp += observation_header_t_to_json_str(&in->header, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"obs\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");
  uint8_t msg_array_offset = (uint8_t *)&(in->obs) - (uint8_t *)in;
  uint8_t msg_array_size = msg_len - msg_array_offset;
  uint8_t msg_array_count = msg_array_size / sizeof( packed_obs_content_t );
  for (int i=0; i < msg_array_count; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += packed_obs_content_t_to_json_str(&(in->obs)[i], json_end - json_bufp, json_bufp);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0044_TO_JSON msg_base_pos_llh_t_to_json_str


int msg_base_pos_llh_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_base_pos_llh_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"lat\": %f, \"lon\": %f, \"height\": %f}", msg_type, sender_id, msg_len, in->lat, in->lon, in->height);}
 #define MSG_0048_TO_JSON msg_base_pos_ecef_t_to_json_str


int msg_base_pos_ecef_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_base_pos_ecef_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"x\": %f, \"y\": %f, \"z\": %f}", msg_type, sender_id, msg_len, in->x, in->y, in->z);}
 
int ephemeris_common_content_t_to_json_str( ephemeris_common_content_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;json_bufp += snprintf(out_str, json_end - json_bufp, "{");

  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sid\": ");json_bufp += sbp_gnss_signal_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"toe\": ");json_bufp += gps_time_sec_t_to_json_str(&in->toe, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"ura\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->ura);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"fit_interval\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->fit_interval);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"valid\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->valid);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"health_bits\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->health_bits);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 
int ephemeris_common_content_dep_b_t_to_json_str( ephemeris_common_content_dep_b_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;json_bufp += snprintf(out_str, json_end - json_bufp, "{");

  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sid\": ");json_bufp += sbp_gnss_signal_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"toe\": ");json_bufp += gps_time_sec_t_to_json_str(&in->toe, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"ura\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->ura);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"fit_interval\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->fit_interval);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"valid\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->valid);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"health_bits\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->health_bits);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 
int ephemeris_common_content_dep_a_t_to_json_str( ephemeris_common_content_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;json_bufp += snprintf(out_str, json_end - json_bufp, "{");

  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sid\": ");json_bufp += gnss_signal_dep_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"toe\": ");json_bufp += gps_time_dep_t_to_json_str(&in->toe, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"ura\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->ura);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"fit_interval\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->fit_interval);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"valid\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->valid);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"health_bits\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->health_bits);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0081_TO_JSON msg_ephemeris_gps_dep_e_t_to_json_str


int msg_ephemeris_gps_dep_e_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ephemeris_gps_dep_e_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"common\": ");json_bufp += ephemeris_common_content_dep_a_t_to_json_str(&in->common, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"tgd\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->tgd);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_rs\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_rs);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_rc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_rc);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_uc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_uc);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_us\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_us);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_ic\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_ic);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_is\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_is);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"dn\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->dn);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"m0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->m0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"ecc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->ecc);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sqrta\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->sqrta);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"omega0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->omega0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"omegadot\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->omegadot);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"w\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->w);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"inc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->inc);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"inc_dot\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->inc_dot);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"af0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->af0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"af1\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->af1);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"af2\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->af2);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"toc\": ");json_bufp += gps_time_dep_t_to_json_str(&in->toc, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"iode\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->iode);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"iodc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hu", in->iodc);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0086_TO_JSON msg_ephemeris_gps_dep_f_t_to_json_str


int msg_ephemeris_gps_dep_f_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ephemeris_gps_dep_f_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"common\": ");json_bufp += ephemeris_common_content_dep_b_t_to_json_str(&in->common, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"tgd\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->tgd);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_rs\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_rs);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_rc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_rc);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_uc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_uc);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_us\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_us);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_ic\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_ic);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_is\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_is);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"dn\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->dn);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"m0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->m0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"ecc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->ecc);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sqrta\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->sqrta);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"omega0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->omega0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"omegadot\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->omegadot);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"w\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->w);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"inc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->inc);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"inc_dot\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->inc_dot);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"af0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->af0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"af1\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->af1);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"af2\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->af2);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"toc\": ");json_bufp += gps_time_sec_t_to_json_str(&in->toc, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"iode\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->iode);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"iodc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hu", in->iodc);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_008A_TO_JSON msg_ephemeris_gps_t_to_json_str


int msg_ephemeris_gps_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ephemeris_gps_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"common\": ");json_bufp += ephemeris_common_content_t_to_json_str(&in->common, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"tgd\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->tgd);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_rs\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_rs);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_rc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_rc);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_uc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_uc);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_us\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_us);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_ic\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_ic);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_is\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_is);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"dn\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->dn);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"m0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->m0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"ecc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->ecc);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sqrta\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->sqrta);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"omega0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->omega0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"omegadot\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->omegadot);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"w\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->w);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"inc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->inc);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"inc_dot\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->inc_dot);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"af0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->af0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"af1\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->af1);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"af2\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->af2);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"toc\": ");json_bufp += gps_time_sec_t_to_json_str(&in->toc, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"iode\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->iode);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"iodc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hu", in->iodc);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0089_TO_JSON msg_ephemeris_bds_t_to_json_str


int msg_ephemeris_bds_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ephemeris_bds_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"common\": ");json_bufp += ephemeris_common_content_t_to_json_str(&in->common, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"tgd1\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->tgd1);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"tgd2\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->tgd2);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_rs\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_rs);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_rc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_rc);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_uc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_uc);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_us\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_us);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_ic\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_ic);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_is\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_is);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"dn\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->dn);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"m0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->m0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"ecc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->ecc);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sqrta\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->sqrta);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"omega0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->omega0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"omegadot\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->omegadot);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"w\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->w);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"inc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->inc);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"inc_dot\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->inc_dot);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"af0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->af0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"af1\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->af1);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"af2\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->af2);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"toc\": ");json_bufp += gps_time_sec_t_to_json_str(&in->toc, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"iode\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->iode);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"iodc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hu", in->iodc);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0095_TO_JSON msg_ephemeris_gal_t_to_json_str


int msg_ephemeris_gal_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ephemeris_gal_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"common\": ");json_bufp += ephemeris_common_content_t_to_json_str(&in->common, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"bgd_e1e5a\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->bgd_e1e5a);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"bgd_e1e5b\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->bgd_e1e5b);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_rs\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_rs);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_rc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_rc);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_uc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_uc);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_us\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_us);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_ic\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_ic);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_is\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_is);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"dn\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->dn);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"m0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->m0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"ecc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->ecc);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sqrta\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->sqrta);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"omega0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->omega0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"omegadot\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->omegadot);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"w\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->w);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"inc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->inc);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"inc_dot\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->inc_dot);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"af0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->af0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"af1\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->af1);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"af2\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->af2);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"toc\": ");json_bufp += gps_time_sec_t_to_json_str(&in->toc, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"iode\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hu", in->iode);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"iodc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hu", in->iodc);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0082_TO_JSON msg_ephemeris_sbas_dep_a_t_to_json_str


int msg_ephemeris_sbas_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ephemeris_sbas_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"common\": ");json_bufp += ephemeris_common_content_dep_a_t_to_json_str(&in->common, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"pos\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 3; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->pos[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"vel\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 3; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->vel[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"acc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 3; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->acc[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"a_gf0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->a_gf0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"a_gf1\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->a_gf1);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0083_TO_JSON msg_ephemeris_glo_dep_a_t_to_json_str


int msg_ephemeris_glo_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ephemeris_glo_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"common\": ");json_bufp += ephemeris_common_content_dep_a_t_to_json_str(&in->common, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"gamma\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->gamma);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"tau\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->tau);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"pos\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 3; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->pos[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"vel\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 3; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->vel[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"acc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 3; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->acc[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0084_TO_JSON msg_ephemeris_sbas_dep_b_t_to_json_str


int msg_ephemeris_sbas_dep_b_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ephemeris_sbas_dep_b_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"common\": ");json_bufp += ephemeris_common_content_dep_b_t_to_json_str(&in->common, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"pos\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 3; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->pos[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"vel\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 3; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->vel[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"acc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 3; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->acc[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"a_gf0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->a_gf0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"a_gf1\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->a_gf1);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_008C_TO_JSON msg_ephemeris_sbas_t_to_json_str


int msg_ephemeris_sbas_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ephemeris_sbas_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"common\": ");json_bufp += ephemeris_common_content_t_to_json_str(&in->common, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"pos\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 3; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->pos[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"vel\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 3; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->vel[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"acc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 3; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->acc[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"a_gf0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->a_gf0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"a_gf1\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->a_gf1);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0085_TO_JSON msg_ephemeris_glo_dep_b_t_to_json_str


int msg_ephemeris_glo_dep_b_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ephemeris_glo_dep_b_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"common\": ");json_bufp += ephemeris_common_content_dep_b_t_to_json_str(&in->common, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"gamma\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->gamma);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"tau\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->tau);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"pos\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 3; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->pos[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"vel\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 3; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->vel[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"acc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 3; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->acc[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0087_TO_JSON msg_ephemeris_glo_dep_c_t_to_json_str


int msg_ephemeris_glo_dep_c_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ephemeris_glo_dep_c_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"common\": ");json_bufp += ephemeris_common_content_dep_b_t_to_json_str(&in->common, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"gamma\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->gamma);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"tau\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->tau);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"d_tau\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->d_tau);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"pos\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 3; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->pos[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"vel\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 3; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->vel[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"acc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 3; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->acc[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"fcn\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->fcn);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0088_TO_JSON msg_ephemeris_glo_dep_d_t_to_json_str


int msg_ephemeris_glo_dep_d_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ephemeris_glo_dep_d_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"common\": ");json_bufp += ephemeris_common_content_dep_b_t_to_json_str(&in->common, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"gamma\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->gamma);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"tau\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->tau);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"d_tau\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->d_tau);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"pos\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 3; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->pos[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"vel\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 3; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->vel[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"acc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 3; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->acc[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"fcn\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->fcn);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"iod\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->iod);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_008B_TO_JSON msg_ephemeris_glo_t_to_json_str


int msg_ephemeris_glo_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ephemeris_glo_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"common\": ");json_bufp += ephemeris_common_content_t_to_json_str(&in->common, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"gamma\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->gamma);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"tau\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->tau);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"d_tau\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->d_tau);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"pos\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 3; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->pos[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"vel\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 3; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->vel[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"acc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 3; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->acc[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"fcn\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->fcn);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"iod\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->iod);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0080_TO_JSON msg_ephemeris_dep_d_t_to_json_str


int msg_ephemeris_dep_d_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ephemeris_dep_d_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"tgd\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->tgd);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_rs\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_rs);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_rc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_rc);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_uc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_uc);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_us\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_us);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_ic\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_ic);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_is\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_is);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"dn\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->dn);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"m0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->m0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"ecc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->ecc);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sqrta\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->sqrta);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"omega0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->omega0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"omegadot\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->omegadot);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"w\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->w);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"inc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->inc);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"inc_dot\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->inc_dot);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"af0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->af0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"af1\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->af1);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"af2\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->af2);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"toe_tow\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->toe_tow);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"toe_wn\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hu", in->toe_wn);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"toc_tow\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->toc_tow);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"toc_wn\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hu", in->toc_wn);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"valid\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->valid);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"healthy\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->healthy);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sid\": ");json_bufp += gnss_signal_dep_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"iode\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->iode);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"iodc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hu", in->iodc);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"reserved\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->reserved);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_001A_TO_JSON msg_ephemeris_dep_a_t_to_json_str


int msg_ephemeris_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ephemeris_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tgd\": %f, \"c_rs\": %f, \"c_rc\": %f, \"c_uc\": %f, \"c_us\": %f, \"c_ic\": %f, \"c_is\": %f, \"dn\": %f, \"m0\": %f, \"ecc\": %f, \"sqrta\": %f, \"omega0\": %f, \"omegadot\": %f, \"w\": %f, \"inc\": %f, \"inc_dot\": %f, \"af0\": %f, \"af1\": %f, \"af2\": %f, \"toe_tow\": %f, \"toe_wn\": %hu, \"toc_tow\": %f, \"toc_wn\": %hu, \"valid\": %hhu, \"healthy\": %hhu, \"prn\": %hhu}", msg_type, sender_id, msg_len, in->tgd, in->c_rs, in->c_rc, in->c_uc, in->c_us, in->c_ic, in->c_is, in->dn, in->m0, in->ecc, in->sqrta, in->omega0, in->omegadot, in->w, in->inc, in->inc_dot, in->af0, in->af1, in->af2, in->toe_tow, in->toe_wn, in->toc_tow, in->toc_wn, in->valid, in->healthy, in->prn);}
 #define MSG_0046_TO_JSON msg_ephemeris_dep_b_t_to_json_str


int msg_ephemeris_dep_b_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ephemeris_dep_b_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tgd\": %f, \"c_rs\": %f, \"c_rc\": %f, \"c_uc\": %f, \"c_us\": %f, \"c_ic\": %f, \"c_is\": %f, \"dn\": %f, \"m0\": %f, \"ecc\": %f, \"sqrta\": %f, \"omega0\": %f, \"omegadot\": %f, \"w\": %f, \"inc\": %f, \"inc_dot\": %f, \"af0\": %f, \"af1\": %f, \"af2\": %f, \"toe_tow\": %f, \"toe_wn\": %hu, \"toc_tow\": %f, \"toc_wn\": %hu, \"valid\": %hhu, \"healthy\": %hhu, \"prn\": %hhu, \"iode\": %hhu}", msg_type, sender_id, msg_len, in->tgd, in->c_rs, in->c_rc, in->c_uc, in->c_us, in->c_ic, in->c_is, in->dn, in->m0, in->ecc, in->sqrta, in->omega0, in->omegadot, in->w, in->inc, in->inc_dot, in->af0, in->af1, in->af2, in->toe_tow, in->toe_wn, in->toc_tow, in->toc_wn, in->valid, in->healthy, in->prn, in->iode);}
 #define MSG_0047_TO_JSON msg_ephemeris_dep_c_t_to_json_str


int msg_ephemeris_dep_c_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ephemeris_dep_c_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"tgd\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->tgd);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_rs\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_rs);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_rc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_rc);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_uc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_uc);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_us\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_us);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_ic\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_ic);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c_is\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->c_is);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"dn\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->dn);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"m0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->m0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"ecc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->ecc);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sqrta\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->sqrta);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"omega0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->omega0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"omegadot\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->omegadot);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"w\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->w);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"inc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->inc);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"inc_dot\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->inc_dot);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"af0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->af0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"af1\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->af1);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"af2\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->af2);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"toe_tow\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->toe_tow);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"toe_wn\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hu", in->toe_wn);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"toc_tow\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->toc_tow);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"toc_wn\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hu", in->toc_wn);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"valid\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->valid);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"healthy\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->healthy);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sid\": ");json_bufp += gnss_signal_dep_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"iode\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->iode);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"iodc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hu", in->iodc);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"reserved\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->reserved);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 
int observation_header_dep_t_to_json_str( observation_header_dep_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;json_bufp += snprintf(out_str, json_end - json_bufp, "{");

  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"t\": ");json_bufp += gps_time_dep_t_to_json_str(&in->t, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"n_obs\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->n_obs);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 
int carrier_phase_dep_a_t_to_json_str( carrier_phase_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"i\": %d, \"f\": %hhu}", in->i, in->f);}
 
int packed_obs_content_dep_a_t_to_json_str( packed_obs_content_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;json_bufp += snprintf(out_str, json_end - json_bufp, "{");

  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"P\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->P);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"L\": ");json_bufp += carrier_phase_dep_a_t_to_json_str(&in->L, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"cn0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->cn0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"lock\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hu", in->lock);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"prn\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->prn);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 
int packed_obs_content_dep_b_t_to_json_str( packed_obs_content_dep_b_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;json_bufp += snprintf(out_str, json_end - json_bufp, "{");

  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"P\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->P);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"L\": ");json_bufp += carrier_phase_dep_a_t_to_json_str(&in->L, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"cn0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->cn0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"lock\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hu", in->lock);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sid\": ");json_bufp += gnss_signal_dep_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 
int packed_obs_content_dep_c_t_to_json_str( packed_obs_content_dep_c_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;json_bufp += snprintf(out_str, json_end - json_bufp, "{");

  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"P\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->P);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"L\": ");json_bufp += carrier_phase_t_to_json_str(&in->L, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"cn0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->cn0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"lock\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hu", in->lock);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sid\": ");json_bufp += gnss_signal_dep_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0045_TO_JSON msg_obs_dep_a_t_to_json_str


int msg_obs_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_obs_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"header\": ");json_bufp += observation_header_dep_t_to_json_str(&in->header, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"obs\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");
  uint8_t msg_array_offset = (uint8_t *)&(in->obs) - (uint8_t *)in;
  uint8_t msg_array_size = msg_len - msg_array_offset;
  uint8_t msg_array_count = msg_array_size / sizeof( packed_obs_content_dep_a_t );
  for (int i=0; i < msg_array_count; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += packed_obs_content_dep_a_t_to_json_str(&(in->obs)[i], json_end - json_bufp, json_bufp);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0043_TO_JSON msg_obs_dep_b_t_to_json_str


int msg_obs_dep_b_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_obs_dep_b_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"header\": ");json_bufp += observation_header_dep_t_to_json_str(&in->header, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"obs\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");
  uint8_t msg_array_offset = (uint8_t *)&(in->obs) - (uint8_t *)in;
  uint8_t msg_array_size = msg_len - msg_array_offset;
  uint8_t msg_array_count = msg_array_size / sizeof( packed_obs_content_dep_b_t );
  for (int i=0; i < msg_array_count; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += packed_obs_content_dep_b_t_to_json_str(&(in->obs)[i], json_end - json_bufp, json_bufp);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0049_TO_JSON msg_obs_dep_c_t_to_json_str


int msg_obs_dep_c_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_obs_dep_c_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"header\": ");json_bufp += observation_header_dep_t_to_json_str(&in->header, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"obs\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");
  uint8_t msg_array_offset = (uint8_t *)&(in->obs) - (uint8_t *)in;
  uint8_t msg_array_size = msg_len - msg_array_offset;
  uint8_t msg_array_count = msg_array_size / sizeof( packed_obs_content_dep_c_t );
  for (int i=0; i < msg_array_count; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += packed_obs_content_dep_c_t_to_json_str(&(in->obs)[i], json_end - json_bufp, json_bufp);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0090_TO_JSON msg_iono_t_to_json_str


int msg_iono_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_iono_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"t_nmct\": ");json_bufp += gps_time_sec_t_to_json_str(&in->t_nmct, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"a0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->a0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"a1\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->a1);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"a2\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->a2);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"a3\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->a3);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"b0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->b0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"b1\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->b1);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"b2\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->b2);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"b3\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->b3);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0091_TO_JSON msg_sv_configuration_gps_t_to_json_str


int msg_sv_configuration_gps_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_sv_configuration_gps_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"t_nmct\": ");json_bufp += gps_time_sec_t_to_json_str(&in->t_nmct, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"l2c_mask\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->l2c_mask);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0092_TO_JSON msg_group_delay_dep_a_t_to_json_str


int msg_group_delay_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_group_delay_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"t_op\": ");json_bufp += gps_time_dep_t_to_json_str(&in->t_op, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"prn\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->prn);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"valid\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->valid);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"tgd\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hd", in->tgd);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"isc_l1ca\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hd", in->isc_l1ca);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"isc_l2c\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hd", in->isc_l2c);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0093_TO_JSON msg_group_delay_dep_b_t_to_json_str


int msg_group_delay_dep_b_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_group_delay_dep_b_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"t_op\": ");json_bufp += gps_time_sec_t_to_json_str(&in->t_op, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sid\": ");json_bufp += gnss_signal_dep_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"valid\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->valid);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"tgd\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hd", in->tgd);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"isc_l1ca\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hd", in->isc_l1ca);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"isc_l2c\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hd", in->isc_l2c);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0094_TO_JSON msg_group_delay_t_to_json_str


int msg_group_delay_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_group_delay_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"t_op\": ");json_bufp += gps_time_sec_t_to_json_str(&in->t_op, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sid\": ");json_bufp += sbp_gnss_signal_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"valid\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->valid);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"tgd\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hd", in->tgd);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"isc_l1ca\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hd", in->isc_l1ca);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"isc_l2c\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hd", in->isc_l2c);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 
int almanac_common_content_t_to_json_str( almanac_common_content_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;json_bufp += snprintf(out_str, json_end - json_bufp, "{");

  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sid\": ");json_bufp += sbp_gnss_signal_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"toa\": ");json_bufp += gps_time_sec_t_to_json_str(&in->toa, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"ura\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->ura);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"fit_interval\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->fit_interval);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"valid\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->valid);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"health_bits\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->health_bits);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 
int almanac_common_content_dep_t_to_json_str( almanac_common_content_dep_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;json_bufp += snprintf(out_str, json_end - json_bufp, "{");

  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sid\": ");json_bufp += gnss_signal_dep_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"toa\": ");json_bufp += gps_time_sec_t_to_json_str(&in->toa, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"ura\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->ura);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"fit_interval\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->fit_interval);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"valid\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->valid);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"health_bits\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->health_bits);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0070_TO_JSON msg_almanac_gps_dep_t_to_json_str


int msg_almanac_gps_dep_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_almanac_gps_dep_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"common\": ");json_bufp += almanac_common_content_dep_t_to_json_str(&in->common, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"m0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->m0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"ecc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->ecc);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sqrta\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->sqrta);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"omega0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->omega0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"omegadot\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->omegadot);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"w\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->w);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"inc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->inc);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"af0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->af0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"af1\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->af1);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0072_TO_JSON msg_almanac_gps_t_to_json_str


int msg_almanac_gps_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_almanac_gps_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"common\": ");json_bufp += almanac_common_content_t_to_json_str(&in->common, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"m0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->m0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"ecc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->ecc);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sqrta\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->sqrta);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"omega0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->omega0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"omegadot\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->omegadot);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"w\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->w);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"inc\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->inc);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"af0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->af0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"af1\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->af1);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0071_TO_JSON msg_almanac_glo_dep_t_to_json_str


int msg_almanac_glo_dep_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_almanac_glo_dep_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"common\": ");json_bufp += almanac_common_content_dep_t_to_json_str(&in->common, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"lambda_na\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->lambda_na);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"t_lambda_na\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->t_lambda_na);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"i\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->i);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"t\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->t);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"t_dot\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->t_dot);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"epsilon\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->epsilon);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"omega\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->omega);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0073_TO_JSON msg_almanac_glo_t_to_json_str


int msg_almanac_glo_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_almanac_glo_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"common\": ");json_bufp += almanac_common_content_t_to_json_str(&in->common, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"lambda_na\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->lambda_na);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"t_lambda_na\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->t_lambda_na);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"i\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->i);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"t\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->t);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"t_dot\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->t_dot);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"epsilon\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->epsilon);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"omega\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->omega);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0075_TO_JSON msg_glo_biases_t_to_json_str


int msg_glo_biases_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_glo_biases_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"mask\": %hhu, \"l1ca_bias\": %hd, \"l1p_bias\": %hd, \"l2ca_bias\": %hd, \"l2p_bias\": %hd}", msg_type, sender_id, msg_len, in->mask, in->l1ca_bias, in->l1p_bias, in->l2ca_bias, in->l2p_bias);}




/*****************************************************************************
 * Automatically generated from orientation.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 * * Orientation Messages
 * \{ */


 #define MSG_020F_TO_JSON msg_baseline_heading_t_to_json_str


int msg_baseline_heading_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_baseline_heading_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"heading\": %u, \"n_sats\": %hhu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->heading, in->n_sats, in->flags);}
 #define MSG_0220_TO_JSON msg_orient_quat_t_to_json_str


int msg_orient_quat_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_orient_quat_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"w\": %d, \"x\": %d, \"y\": %d, \"z\": %d, \"w_accuracy\": %f, \"x_accuracy\": %f, \"y_accuracy\": %f, \"z_accuracy\": %f, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->w, in->x, in->y, in->z, in->w_accuracy, in->x_accuracy, in->y_accuracy, in->z_accuracy, in->flags);}
 #define MSG_0221_TO_JSON msg_orient_euler_t_to_json_str


int msg_orient_euler_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_orient_euler_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"roll\": %d, \"pitch\": %d, \"yaw\": %d, \"roll_accuracy\": %f, \"pitch_accuracy\": %f, \"yaw_accuracy\": %f, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->roll, in->pitch, in->yaw, in->roll_accuracy, in->pitch_accuracy, in->yaw_accuracy, in->flags);}
 #define MSG_0222_TO_JSON msg_angular_rate_t_to_json_str


int msg_angular_rate_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_angular_rate_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"x\": %d, \"y\": %d, \"z\": %d, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->x, in->y, in->z, in->flags);}




/*****************************************************************************
 * Automatically generated from piksi.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 *  * System health, configuration, and diagnostic messages specific to
 * the Piksi L1 receiver, including a variety of legacy messages that
 * may no longer be used.
 * \{ */


 #define MSG_0069_TO_JSON msg_almanac_t_to_json_str


int msg_almanac_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, void * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0068_TO_JSON msg_set_time_t_to_json_str


int msg_set_time_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, void * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_00B6_TO_JSON msg_reset_t_to_json_str


int msg_reset_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_reset_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"flags\": %u}", msg_type, sender_id, msg_len, in->flags);}
 #define MSG_00B2_TO_JSON msg_reset_dep_t_to_json_str


int msg_reset_dep_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, void * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_00C0_TO_JSON msg_cw_results_t_to_json_str


int msg_cw_results_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, void * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_00C1_TO_JSON msg_cw_start_t_to_json_str


int msg_cw_start_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, void * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0022_TO_JSON msg_reset_filters_t_to_json_str


int msg_reset_filters_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_reset_filters_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"filter\": %hhu}", msg_type, sender_id, msg_len, in->filter);}
 #define MSG_0023_TO_JSON msg_init_base_t_to_json_str


int msg_init_base_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, void * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0017_TO_JSON msg_thread_state_t_to_json_str


int msg_thread_state_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_thread_state_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"name\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");
  for (int i=0; i < 20; i++) {
    unsigned char c = in->name[i];
    if (isprint(c) && c != '\\') {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "%c", c);
    }
    else {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "\\\\u00%02x", c);
    }
  }
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"cpu\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hu", in->cpu);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"stack_free\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->stack_free);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 
int uart_channel_t_to_json_str( uart_channel_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"tx_throughput\": %f, \"rx_throughput\": %f, \"crc_error_count\": %hu, \"io_error_count\": %hu, \"tx_buffer_level\": %hhu, \"rx_buffer_level\": %hhu}", in->tx_throughput, in->rx_throughput, in->crc_error_count, in->io_error_count, in->tx_buffer_level, in->rx_buffer_level);}
 
int period_t_to_json_str( period_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"avg\": %d, \"pmin\": %d, \"pmax\": %d, \"current\": %d}", in->avg, in->pmin, in->pmax, in->current);}
 
int latency_t_to_json_str( latency_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"avg\": %d, \"lmin\": %d, \"lmax\": %d, \"current\": %d}", in->avg, in->lmin, in->lmax, in->current);}
 #define MSG_001D_TO_JSON msg_uart_state_t_to_json_str


int msg_uart_state_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_uart_state_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"uart_a\": ");json_bufp += uart_channel_t_to_json_str(&in->uart_a, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"uart_b\": ");json_bufp += uart_channel_t_to_json_str(&in->uart_b, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"uart_ftdi\": ");json_bufp += uart_channel_t_to_json_str(&in->uart_ftdi, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"latency\": ");json_bufp += latency_t_to_json_str(&in->latency, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"obs_period\": ");json_bufp += period_t_to_json_str(&in->obs_period, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0018_TO_JSON msg_uart_state_depa_t_to_json_str


int msg_uart_state_depa_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_uart_state_depa_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"uart_a\": ");json_bufp += uart_channel_t_to_json_str(&in->uart_a, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"uart_b\": ");json_bufp += uart_channel_t_to_json_str(&in->uart_b, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"uart_ftdi\": ");json_bufp += uart_channel_t_to_json_str(&in->uart_ftdi, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"latency\": ");json_bufp += latency_t_to_json_str(&in->latency, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0019_TO_JSON msg_iar_state_t_to_json_str


int msg_iar_state_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_iar_state_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"num_hyps\": %u}", msg_type, sender_id, msg_len, in->num_hyps);}
 #define MSG_002B_TO_JSON msg_mask_satellite_t_to_json_str


int msg_mask_satellite_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_mask_satellite_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"mask\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->mask);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sid\": ");json_bufp += sbp_gnss_signal_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_001B_TO_JSON msg_mask_satellite_dep_t_to_json_str


int msg_mask_satellite_dep_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_mask_satellite_dep_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"mask\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->mask);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sid\": ");json_bufp += gnss_signal_dep_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_00B5_TO_JSON msg_device_monitor_t_to_json_str


int msg_device_monitor_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_device_monitor_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"dev_vin\": %hd, \"cpu_vint\": %hd, \"cpu_vaux\": %hd, \"cpu_temperature\": %hd, \"fe_temperature\": %hd}", msg_type, sender_id, msg_len, in->dev_vin, in->cpu_vint, in->cpu_vaux, in->cpu_temperature, in->fe_temperature);}
 #define MSG_00B8_TO_JSON msg_command_req_t_to_json_str


int msg_command_req_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_command_req_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sequence\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->sequence);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"command\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");
  for (int i=0; i < (uint8_t *) in + msg_len - (uint8_t *) &(in->command); i++) {
    unsigned char c = in->command[i];
    if (isprint(c) && c != '\\') {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "%c", c);
    }
    else {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "\\\\u00%02x", c);
    }
  }
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_00B9_TO_JSON msg_command_resp_t_to_json_str


int msg_command_resp_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_command_resp_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"sequence\": %u, \"code\": %d}", msg_type, sender_id, msg_len, in->sequence, in->code);}
 #define MSG_00BC_TO_JSON msg_command_output_t_to_json_str


int msg_command_output_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_command_output_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sequence\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->sequence);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"line\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");
  for (int i=0; i < (uint8_t *) in + msg_len - (uint8_t *) &(in->line); i++) {
    unsigned char c = in->line[i];
    if (isprint(c) && c != '\\') {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "%c", c);
    }
    else {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "\\\\u00%02x", c);
    }
  }
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_00BA_TO_JSON msg_network_state_req_t_to_json_str


int msg_network_state_req_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, void * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_00BB_TO_JSON msg_network_state_resp_t_to_json_str


int msg_network_state_resp_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_network_state_resp_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"ipv4_address\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 4; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->ipv4_address[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"ipv4_mask_size\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->ipv4_mask_size);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"ipv6_address\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 16; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->ipv6_address[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"ipv6_mask_size\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->ipv6_mask_size);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"rx_bytes\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->rx_bytes);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"tx_bytes\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->tx_bytes);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"interface_name\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");
  for (int i=0; i < 16; i++) {
    unsigned char c = in->interface_name[i];
    if (isprint(c) && c != '\\') {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "%c", c);
    }
    else {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "\\\\u00%02x", c);
    }
  }
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"flags\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->flags);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 
int network_usage_t_to_json_str( network_usage_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;json_bufp += snprintf(out_str, json_end - json_bufp, "{");

  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"duration\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%lu", in->duration);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"total_bytes\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%lu", in->total_bytes);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"rx_bytes\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->rx_bytes);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"tx_bytes\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->tx_bytes);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"interface_name\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");
  for (int i=0; i < 16; i++) {
    unsigned char c = in->interface_name[i];
    if (isprint(c) && c != '\\') {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "%c", c);
    }
    else {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "\\\\u00%02x", c);
    }
  }
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_00BD_TO_JSON msg_network_bandwidth_usage_t_to_json_str


int msg_network_bandwidth_usage_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_network_bandwidth_usage_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"interfaces\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");
  uint8_t msg_array_offset = (uint8_t *)&(in->interfaces) - (uint8_t *)in;
  uint8_t msg_array_size = msg_len - msg_array_offset;
  uint8_t msg_array_count = msg_array_size / sizeof( network_usage_t );
  for (int i=0; i < msg_array_count; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += network_usage_t_to_json_str(&(in->interfaces)[i], json_end - json_bufp, json_bufp);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_00BE_TO_JSON msg_cell_modem_status_t_to_json_str


int msg_cell_modem_status_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_cell_modem_status_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"signal_strength\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhd", in->signal_strength);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"signal_error_rate\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->signal_error_rate);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"reserved\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");
  uint8_t msg_array_offset = (uint8_t *)&(in->reserved) - (uint8_t *)in;
  uint8_t msg_array_size = msg_len - msg_array_offset;
  uint8_t msg_array_count = msg_array_size / sizeof( u8 );
  for (int i=0; i < msg_array_count; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->reserved[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0050_TO_JSON msg_specan_dep_t_to_json_str


int msg_specan_dep_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_specan_dep_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"channel_tag\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hu", in->channel_tag);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"t\": ");json_bufp += gps_time_dep_t_to_json_str(&in->t, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"freq_ref\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->freq_ref);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"freq_step\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->freq_step);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"amplitude_ref\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->amplitude_ref);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"amplitude_unit\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->amplitude_unit);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"amplitude_value\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");
  uint8_t msg_array_offset = (uint8_t *)&(in->amplitude_value) - (uint8_t *)in;
  uint8_t msg_array_size = msg_len - msg_array_offset;
  uint8_t msg_array_count = msg_array_size / sizeof( u8 );
  for (int i=0; i < msg_array_count; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->amplitude_value[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0051_TO_JSON msg_specan_t_to_json_str


int msg_specan_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_specan_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"channel_tag\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hu", in->channel_tag);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"t\": ");json_bufp += sbp_gps_time_t_to_json_str(&in->t, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"freq_ref\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->freq_ref);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"freq_step\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->freq_step);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"amplitude_ref\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->amplitude_ref);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"amplitude_unit\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->amplitude_unit);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"amplitude_value\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");
  uint8_t msg_array_offset = (uint8_t *)&(in->amplitude_value) - (uint8_t *)in;
  uint8_t msg_array_size = msg_len - msg_array_offset;
  uint8_t msg_array_count = msg_array_size / sizeof( u8 );
  for (int i=0; i < msg_array_count; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->amplitude_value[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}




/*****************************************************************************
 * Automatically generated from sbas.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 * * SBAS data
 * \{ */


 #define MSG_7777_TO_JSON msg_sbas_raw_t_to_json_str


int msg_sbas_raw_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_sbas_raw_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sid\": ");json_bufp += sbp_gnss_signal_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"tow\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->tow);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"message_type\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->message_type);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"data\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 27; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->data[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}




/*****************************************************************************
 * Automatically generated from settings.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 *  * 
 * Messages for reading, writing, and discovering device settings. Settings
 * with a "string" field have multiple values in this field delimited with a
 * null character (the c style null terminator).  For instance, when querying
 * the 'firmware_version' setting in the 'system_info' section, the following
 * array of characters needs to be sent for the string field in
 * MSG_SETTINGS_READ: "system_info\0firmware_version\0", where the delimiting 
 * null characters are specified with the escape sequence '\0' and all
 * quotation marks should be omitted. 
 * 
 * 
 * In the message descriptions below, the generic strings SECTION_SETTING and
 * SETTING are used to refer to the two strings that comprise the identifier
 * of an individual setting.In firmware_version example above, SECTION_SETTING
 * is the 'system_info', and the SETTING portion is 'firmware_version'. 
 * 
 * See the "Software Settings Manual" on support.swiftnav.com for detailed
 * documentation about all settings and sections available for each Swift
 * firmware version. Settings manuals are available for each firmware version
 * at the following link: https://support.swiftnav.com/customer/en/portal/articles/2628580-piksi-multi-specifications#settings.
 * The latest settings document is also available at the following link: 
 * http://swiftnav.com/latest/piksi-multi-settings .
 * See lastly https://github.com/swift-nav/piksi_tools/blob/master/piksi_tools/settings.py , 
 * the open source python command line utility for reading, writing, and
 * saving settings in the piksi_tools repository on github as a helpful
 * reference and example.
 * \{ */


 #define MSG_00A1_TO_JSON msg_settings_save_t_to_json_str


int msg_settings_save_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, void * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_00A0_TO_JSON msg_settings_write_t_to_json_str


int msg_settings_write_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_settings_write_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"setting\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");
  for (int i=0; i < (uint8_t *) in + msg_len - (uint8_t *) &(in->setting); i++) {
    unsigned char c = in->setting[i];
    if (isprint(c) && c != '\\') {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "%c", c);
    }
    else {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "\\\\u00%02x", c);
    }
  }
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_00AF_TO_JSON msg_settings_write_resp_t_to_json_str


int msg_settings_write_resp_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_settings_write_resp_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"status\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->status);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"setting\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");
  for (int i=0; i < (uint8_t *) in + msg_len - (uint8_t *) &(in->setting); i++) {
    unsigned char c = in->setting[i];
    if (isprint(c) && c != '\\') {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "%c", c);
    }
    else {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "\\\\u00%02x", c);
    }
  }
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_00A4_TO_JSON msg_settings_read_req_t_to_json_str


int msg_settings_read_req_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_settings_read_req_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"setting\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");
  for (int i=0; i < (uint8_t *) in + msg_len - (uint8_t *) &(in->setting); i++) {
    unsigned char c = in->setting[i];
    if (isprint(c) && c != '\\') {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "%c", c);
    }
    else {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "\\\\u00%02x", c);
    }
  }
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_00A5_TO_JSON msg_settings_read_resp_t_to_json_str


int msg_settings_read_resp_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_settings_read_resp_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"setting\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");
  for (int i=0; i < (uint8_t *) in + msg_len - (uint8_t *) &(in->setting); i++) {
    unsigned char c = in->setting[i];
    if (isprint(c) && c != '\\') {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "%c", c);
    }
    else {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "\\\\u00%02x", c);
    }
  }
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_00A2_TO_JSON msg_settings_read_by_index_req_t_to_json_str


int msg_settings_read_by_index_req_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_settings_read_by_index_req_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"index\": %hu}", msg_type, sender_id, msg_len, in->index);}
 #define MSG_00A7_TO_JSON msg_settings_read_by_index_resp_t_to_json_str


int msg_settings_read_by_index_resp_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_settings_read_by_index_resp_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"index\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hu", in->index);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"setting\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");
  for (int i=0; i < (uint8_t *) in + msg_len - (uint8_t *) &(in->setting); i++) {
    unsigned char c = in->setting[i];
    if (isprint(c) && c != '\\') {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "%c", c);
    }
    else {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "\\\\u00%02x", c);
    }
  }
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_00A6_TO_JSON msg_settings_read_by_index_done_t_to_json_str


int msg_settings_read_by_index_done_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, void * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_00AE_TO_JSON msg_settings_register_t_to_json_str


int msg_settings_register_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_settings_register_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"setting\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");
  for (int i=0; i < (uint8_t *) in + msg_len - (uint8_t *) &(in->setting); i++) {
    unsigned char c = in->setting[i];
    if (isprint(c) && c != '\\') {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "%c", c);
    }
    else {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "\\\\u00%02x", c);
    }
  }
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}




/*****************************************************************************
 * Automatically generated from ssr.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 * * Precise State Space Representation (SSR) corrections format
 * \{ */


 
int code_biases_content_t_to_json_str( code_biases_content_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"code\": %hhu, \"value\": %hd}", in->code, in->value);}
 
int phase_biases_content_t_to_json_str( phase_biases_content_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"code\": %hhu, \"integer_indicator\": %hhu, \"widelane_integer_indicator\": %hhu, \"discontinuity_counter\": %hhu, \"bias\": %d}", in->code, in->integer_indicator, in->widelane_integer_indicator, in->discontinuity_counter, in->bias);}
 #define MSG_05DC_TO_JSON msg_ssr_orbit_clock_t_to_json_str


int msg_ssr_orbit_clock_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ssr_orbit_clock_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"time\": ");json_bufp += gps_time_sec_t_to_json_str(&in->time, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sid\": ");json_bufp += sbp_gnss_signal_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"update_interval\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->update_interval);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"iod_ssr\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->iod_ssr);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"iod\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->iod);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"radial\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%d", in->radial);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"along\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%d", in->along);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"cross\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%d", in->cross);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"dot_radial\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%d", in->dot_radial);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"dot_along\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%d", in->dot_along);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"dot_cross\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%d", in->dot_cross);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%d", in->c0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c1\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%d", in->c1);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"c2\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%d", in->c2);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_05E1_TO_JSON msg_ssr_code_biases_t_to_json_str


int msg_ssr_code_biases_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ssr_code_biases_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"time\": ");json_bufp += gps_time_sec_t_to_json_str(&in->time, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sid\": ");json_bufp += sbp_gnss_signal_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"update_interval\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->update_interval);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"iod_ssr\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->iod_ssr);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"biases\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");
  uint8_t msg_array_offset = (uint8_t *)&(in->biases) - (uint8_t *)in;
  uint8_t msg_array_size = msg_len - msg_array_offset;
  uint8_t msg_array_count = msg_array_size / sizeof( code_biases_content_t );
  for (int i=0; i < msg_array_count; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += code_biases_content_t_to_json_str(&(in->biases)[i], json_end - json_bufp, json_bufp);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_05E6_TO_JSON msg_ssr_phase_biases_t_to_json_str


int msg_ssr_phase_biases_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ssr_phase_biases_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"time\": ");json_bufp += gps_time_sec_t_to_json_str(&in->time, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sid\": ");json_bufp += sbp_gnss_signal_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"update_interval\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->update_interval);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"iod_ssr\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->iod_ssr);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"dispersive_bias\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->dispersive_bias);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"mw_consistency\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->mw_consistency);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"yaw\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hu", in->yaw);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"yaw_rate\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhd", in->yaw_rate);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"biases\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");
  uint8_t msg_array_offset = (uint8_t *)&(in->biases) - (uint8_t *)in;
  uint8_t msg_array_size = msg_len - msg_array_offset;
  uint8_t msg_array_count = msg_array_size / sizeof( phase_biases_content_t );
  for (int i=0; i < msg_array_count; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += phase_biases_content_t_to_json_str(&(in->biases)[i], json_end - json_bufp, json_bufp);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}




/*****************************************************************************
 * Automatically generated from system.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 * * Standardized system messages from Swift Navigation devices.
 * \{ */


 #define MSG_FF00_TO_JSON msg_startup_t_to_json_str


int msg_startup_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_startup_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"cause\": %hhu, \"startup_type\": %hhu, \"reserved\": %hu}", msg_type, sender_id, msg_len, in->cause, in->startup_type, in->reserved);}
 #define MSG_FF02_TO_JSON msg_dgnss_status_t_to_json_str


int msg_dgnss_status_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_dgnss_status_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"flags\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->flags);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"latency\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hu", in->latency);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"num_signals\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->num_signals);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"source\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");
  for (int i=0; i < (uint8_t *) in + msg_len - (uint8_t *) &(in->source); i++) {
    unsigned char c = in->source[i];
    if (isprint(c) && c != '\\') {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "%c", c);
    }
    else {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "\\\\u00%02x", c);
    }
  }
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_FFFF_TO_JSON msg_heartbeat_t_to_json_str


int msg_heartbeat_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_heartbeat_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"flags\": %u}", msg_type, sender_id, msg_len, in->flags);}
 #define MSG_FF03_TO_JSON msg_ins_status_t_to_json_str


int msg_ins_status_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ins_status_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"flags\": %u}", msg_type, sender_id, msg_len, in->flags);}




/*****************************************************************************
 * Automatically generated from tracking.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 *  * Satellite code and carrier-phase tracking messages from the device.
 * \{ */


 #define MSG_0021_TO_JSON msg_tracking_state_detailed_dep_a_t_to_json_str


int msg_tracking_state_detailed_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_tracking_state_detailed_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"recv_time\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%lu", in->recv_time);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"tot\": ");json_bufp += sbp_gps_time_t_to_json_str(&in->tot, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"P\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->P);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"P_std\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hu", in->P_std);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"L\": ");json_bufp += carrier_phase_t_to_json_str(&in->L, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"cn0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->cn0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"lock\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hu", in->lock);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sid\": ");json_bufp += sbp_gnss_signal_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"doppler\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%d", in->doppler);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"doppler_std\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hu", in->doppler_std);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"uptime\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->uptime);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"clock_offset\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hd", in->clock_offset);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"clock_drift\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hd", in->clock_drift);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"corr_spacing\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hu", in->corr_spacing);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"acceleration\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhd", in->acceleration);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sync_flags\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->sync_flags);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"tow_flags\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->tow_flags);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"track_flags\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->track_flags);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"nav_flags\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->nav_flags);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"pset_flags\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->pset_flags);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"misc_flags\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->misc_flags);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0011_TO_JSON msg_tracking_state_detailed_dep_t_to_json_str


int msg_tracking_state_detailed_dep_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_tracking_state_detailed_dep_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"recv_time\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%lu", in->recv_time);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"tot\": ");json_bufp += gps_time_dep_t_to_json_str(&in->tot, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"P\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->P);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"P_std\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hu", in->P_std);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"L\": ");json_bufp += carrier_phase_t_to_json_str(&in->L, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"cn0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->cn0);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"lock\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hu", in->lock);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sid\": ");json_bufp += gnss_signal_dep_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"doppler\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%d", in->doppler);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"doppler_std\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hu", in->doppler_std);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"uptime\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%u", in->uptime);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"clock_offset\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hd", in->clock_offset);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"clock_drift\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hd", in->clock_drift);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"corr_spacing\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hu", in->corr_spacing);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"acceleration\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhd", in->acceleration);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sync_flags\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->sync_flags);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"tow_flags\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->tow_flags);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"track_flags\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->track_flags);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"nav_flags\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->nav_flags);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"pset_flags\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->pset_flags);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"misc_flags\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->misc_flags);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 
int tracking_channel_state_t_to_json_str( tracking_channel_state_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;json_bufp += snprintf(out_str, json_end - json_bufp, "{");

  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sid\": ");json_bufp += sbp_gnss_signal_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"fcn\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->fcn);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"cn0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->cn0);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0041_TO_JSON msg_tracking_state_t_to_json_str


int msg_tracking_state_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_tracking_state_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"states\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");
  uint8_t msg_array_offset = (uint8_t *)&(in->states) - (uint8_t *)in;
  uint8_t msg_array_size = msg_len - msg_array_offset;
  uint8_t msg_array_count = msg_array_size / sizeof( tracking_channel_state_t );
  for (int i=0; i < msg_array_count; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += tracking_channel_state_t_to_json_str(&(in->states)[i], json_end - json_bufp, json_bufp);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 
int measurement_state_t_to_json_str( measurement_state_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;json_bufp += snprintf(out_str, json_end - json_bufp, "{");

  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"mesid\": ");json_bufp += sbp_gnss_signal_t_to_json_str(&in->mesid, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"cn0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->cn0);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0061_TO_JSON msg_measurement_state_t_to_json_str


int msg_measurement_state_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_measurement_state_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"states\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");
  uint8_t msg_array_offset = (uint8_t *)&(in->states) - (uint8_t *)in;
  uint8_t msg_array_size = msg_len - msg_array_offset;
  uint8_t msg_array_count = msg_array_size / sizeof( measurement_state_t );
  for (int i=0; i < msg_array_count; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += measurement_state_t_to_json_str(&(in->states)[i], json_end - json_bufp, json_bufp);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 
int tracking_channel_correlation_t_to_json_str( tracking_channel_correlation_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"I\": %d, \"Q\": %d}", in->I, in->Q);}
 #define MSG_002C_TO_JSON msg_tracking_iq_t_to_json_str


int msg_tracking_iq_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_tracking_iq_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"channel\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->channel);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sid\": ");json_bufp += sbp_gnss_signal_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"corrs\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 3; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += tracking_channel_correlation_t_to_json_str(&(in->corrs)[i], json_end - json_bufp, json_bufp);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_001C_TO_JSON msg_tracking_iq_dep_t_to_json_str


int msg_tracking_iq_dep_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_tracking_iq_dep_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"channel\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->channel);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sid\": ");json_bufp += gnss_signal_dep_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"corrs\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");

  for (int i=0; i < 3; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += tracking_channel_correlation_t_to_json_str(&(in->corrs)[i], json_end - json_bufp, json_bufp);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 
int tracking_channel_state_dep_a_t_to_json_str( tracking_channel_state_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"state\": %hhu, \"prn\": %hhu, \"cn0\": %f}", in->state, in->prn, in->cn0);}
 #define MSG_0016_TO_JSON msg_tracking_state_dep_a_t_to_json_str


int msg_tracking_state_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_tracking_state_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"states\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");
  uint8_t msg_array_offset = (uint8_t *)&(in->states) - (uint8_t *)in;
  uint8_t msg_array_size = msg_len - msg_array_offset;
  uint8_t msg_array_count = msg_array_size / sizeof( tracking_channel_state_dep_a_t );
  for (int i=0; i < msg_array_count; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += tracking_channel_state_dep_a_t_to_json_str(&(in->states)[i], json_end - json_bufp, json_bufp);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 
int tracking_channel_state_dep_b_t_to_json_str( tracking_channel_state_dep_b_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;json_bufp += snprintf(out_str, json_end - json_bufp, "{");

  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"state\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->state);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"sid\": ");json_bufp += gnss_signal_dep_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"cn0\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->cn0);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}
 #define MSG_0013_TO_JSON msg_tracking_state_dep_b_t_to_json_str


int msg_tracking_state_dep_b_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_tracking_state_dep_b_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"states\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");
  uint8_t msg_array_offset = (uint8_t *)&(in->states) - (uint8_t *)in;
  uint8_t msg_array_size = msg_len - msg_array_offset;
  uint8_t msg_array_count = msg_array_size / sizeof( tracking_channel_state_dep_b_t );
  for (int i=0; i < msg_array_count; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += tracking_channel_state_dep_b_t_to_json_str(&(in->states)[i], json_end - json_bufp, json_bufp);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}




/*****************************************************************************
 * Automatically generated from user.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 *  * Messages reserved for use by the user.
 * \{ */


 #define MSG_0800_TO_JSON msg_user_data_t_to_json_str


int msg_user_data_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_user_data_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len;
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u", msg_type, sender_id, msg_len);

  
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"contents\": ");json_bufp += snprintf(json_bufp, json_end - json_bufp, "[");
  uint8_t msg_array_offset = (uint8_t *)&(in->contents) - (uint8_t *)in;
  uint8_t msg_array_size = msg_len - msg_array_offset;
  uint8_t msg_array_count = msg_array_size / sizeof( u8 );
  for (int i=0; i < msg_array_count; i++) {
    if (i != 0){
      json_bufp += snprintf(json_bufp, json_end - json_bufp, ", ");
    }json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->contents[i]);}
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "]");json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;}




/*****************************************************************************
 * Automatically generated from vehicle.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 * * Messages from a vehicle.
 * \{ */


 #define MSG_0903_TO_JSON msg_odometry_t_to_json_str


int msg_odometry_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_odometry_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"velocity\": %d, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->velocity, in->flags);}




int sbp2json(u16 sender_id, u16 msg_type, u8 msg_len,
                       u8 payload[], uint64_t max_len, char* out_str) {
switch(msg_type) {
  case 47:
    return msg_acq_result_t_to_json_str(sender_id, msg_type, msg_len, ( msg_acq_result_t *) payload,
           max_len, out_str);
  case 31:
    return msg_acq_result_dep_c_t_to_json_str(sender_id, msg_type, msg_len, ( msg_acq_result_dep_c_t *) payload,
           max_len, out_str);
  case 20:
    return msg_acq_result_dep_b_t_to_json_str(sender_id, msg_type, msg_len, ( msg_acq_result_dep_b_t *) payload,
           max_len, out_str);
  case 21:
    return msg_acq_result_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_acq_result_dep_a_t *) payload,
           max_len, out_str);
  case 46:
    return msg_acq_sv_profile_t_to_json_str(sender_id, msg_type, msg_len, ( msg_acq_sv_profile_t *) payload,
           max_len, out_str);
  case 30:
    return msg_acq_sv_profile_dep_t_to_json_str(sender_id, msg_type, msg_len, ( msg_acq_sv_profile_dep_t *) payload,
           max_len, out_str);
  case 179:
    return msg_bootloader_handshake_req_t_to_json_str(sender_id, msg_type, msg_len, ( void *) payload,
           max_len, out_str);
  case 180:
    return msg_bootloader_handshake_resp_t_to_json_str(sender_id, msg_type, msg_len, ( msg_bootloader_handshake_resp_t *) payload,
           max_len, out_str);
  case 177:
    return msg_bootloader_jump_to_app_t_to_json_str(sender_id, msg_type, msg_len, ( msg_bootloader_jump_to_app_t *) payload,
           max_len, out_str);
  case 222:
    return msg_nap_device_dna_req_t_to_json_str(sender_id, msg_type, msg_len, ( void *) payload,
           max_len, out_str);
  case 221:
    return msg_nap_device_dna_resp_t_to_json_str(sender_id, msg_type, msg_len, ( msg_nap_device_dna_resp_t *) payload,
           max_len, out_str);
  case 176:
    return msg_bootloader_handshake_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_bootloader_handshake_dep_a_t *) payload,
           max_len, out_str);
  case 257:
    return msg_ext_event_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ext_event_t *) payload,
           max_len, out_str);
  case 168:
    return msg_fileio_read_req_t_to_json_str(sender_id, msg_type, msg_len, ( msg_fileio_read_req_t *) payload,
           max_len, out_str);
  case 163:
    return msg_fileio_read_resp_t_to_json_str(sender_id, msg_type, msg_len, ( msg_fileio_read_resp_t *) payload,
           max_len, out_str);
  case 169:
    return msg_fileio_read_dir_req_t_to_json_str(sender_id, msg_type, msg_len, ( msg_fileio_read_dir_req_t *) payload,
           max_len, out_str);
  case 170:
    return msg_fileio_read_dir_resp_t_to_json_str(sender_id, msg_type, msg_len, ( msg_fileio_read_dir_resp_t *) payload,
           max_len, out_str);
  case 172:
    return msg_fileio_remove_t_to_json_str(sender_id, msg_type, msg_len, ( msg_fileio_remove_t *) payload,
           max_len, out_str);
  case 173:
    return msg_fileio_write_req_t_to_json_str(sender_id, msg_type, msg_len, ( msg_fileio_write_req_t *) payload,
           max_len, out_str);
  case 171:
    return msg_fileio_write_resp_t_to_json_str(sender_id, msg_type, msg_len, ( msg_fileio_write_resp_t *) payload,
           max_len, out_str);
  case 230:
    return msg_flash_program_t_to_json_str(sender_id, msg_type, msg_len, ( msg_flash_program_t *) payload,
           max_len, out_str);
  case 224:
    return msg_flash_done_t_to_json_str(sender_id, msg_type, msg_len, ( msg_flash_done_t *) payload,
           max_len, out_str);
  case 231:
    return msg_flash_read_req_t_to_json_str(sender_id, msg_type, msg_len, ( msg_flash_read_req_t *) payload,
           max_len, out_str);
  case 225:
    return msg_flash_read_resp_t_to_json_str(sender_id, msg_type, msg_len, ( msg_flash_read_resp_t *) payload,
           max_len, out_str);
  case 226:
    return msg_flash_erase_t_to_json_str(sender_id, msg_type, msg_len, ( msg_flash_erase_t *) payload,
           max_len, out_str);
  case 227:
    return msg_stm_flash_lock_sector_t_to_json_str(sender_id, msg_type, msg_len, ( msg_stm_flash_lock_sector_t *) payload,
           max_len, out_str);
  case 228:
    return msg_stm_flash_unlock_sector_t_to_json_str(sender_id, msg_type, msg_len, ( msg_stm_flash_unlock_sector_t *) payload,
           max_len, out_str);
  case 232:
    return msg_stm_unique_id_req_t_to_json_str(sender_id, msg_type, msg_len, ( void *) payload,
           max_len, out_str);
  case 229:
    return msg_stm_unique_id_resp_t_to_json_str(sender_id, msg_type, msg_len, ( msg_stm_unique_id_resp_t *) payload,
           max_len, out_str);
  case 243:
    return msg_m25_flash_write_status_t_to_json_str(sender_id, msg_type, msg_len, ( msg_m25_flash_write_status_t *) payload,
           max_len, out_str);
  case 2304:
    return msg_imu_raw_t_to_json_str(sender_id, msg_type, msg_len, ( msg_imu_raw_t *) payload,
           max_len, out_str);
  case 2305:
    return msg_imu_aux_t_to_json_str(sender_id, msg_type, msg_len, ( msg_imu_aux_t *) payload,
           max_len, out_str);
  case 1025:
    return msg_log_t_to_json_str(sender_id, msg_type, msg_len, ( msg_log_t *) payload,
           max_len, out_str);
  case 1026:
    return msg_fwd_t_to_json_str(sender_id, msg_type, msg_len, ( msg_fwd_t *) payload,
           max_len, out_str);
  case 18:
    return msg_tweet_t_to_json_str(sender_id, msg_type, msg_len, ( msg_tweet_t *) payload,
           max_len, out_str);
  case 16:
    return msg_print_dep_t_to_json_str(sender_id, msg_type, msg_len, ( msg_print_dep_t *) payload,
           max_len, out_str);
  case 2306:
    return msg_mag_raw_t_to_json_str(sender_id, msg_type, msg_len, ( msg_mag_raw_t *) payload,
           max_len, out_str);
  case 258:
    return msg_gps_time_t_to_json_str(sender_id, msg_type, msg_len, ( msg_gps_time_t *) payload,
           max_len, out_str);
  case 259:
    return msg_utc_time_t_to_json_str(sender_id, msg_type, msg_len, ( msg_utc_time_t *) payload,
           max_len, out_str);
  case 520:
    return msg_dops_t_to_json_str(sender_id, msg_type, msg_len, ( msg_dops_t *) payload,
           max_len, out_str);
  case 521:
    return msg_pos_ecef_t_to_json_str(sender_id, msg_type, msg_len, ( msg_pos_ecef_t *) payload,
           max_len, out_str);
  case 532:
    return msg_pos_ecef_cov_t_to_json_str(sender_id, msg_type, msg_len, ( msg_pos_ecef_cov_t *) payload,
           max_len, out_str);
  case 522:
    return msg_pos_llh_t_to_json_str(sender_id, msg_type, msg_len, ( msg_pos_llh_t *) payload,
           max_len, out_str);
  case 529:
    return msg_pos_llh_cov_t_to_json_str(sender_id, msg_type, msg_len, ( msg_pos_llh_cov_t *) payload,
           max_len, out_str);
  case 523:
    return msg_baseline_ecef_t_to_json_str(sender_id, msg_type, msg_len, ( msg_baseline_ecef_t *) payload,
           max_len, out_str);
  case 524:
    return msg_baseline_ned_t_to_json_str(sender_id, msg_type, msg_len, ( msg_baseline_ned_t *) payload,
           max_len, out_str);
  case 525:
    return msg_vel_ecef_t_to_json_str(sender_id, msg_type, msg_len, ( msg_vel_ecef_t *) payload,
           max_len, out_str);
  case 533:
    return msg_vel_ecef_cov_t_to_json_str(sender_id, msg_type, msg_len, ( msg_vel_ecef_cov_t *) payload,
           max_len, out_str);
  case 526:
    return msg_vel_ned_t_to_json_str(sender_id, msg_type, msg_len, ( msg_vel_ned_t *) payload,
           max_len, out_str);
  case 530:
    return msg_vel_ned_cov_t_to_json_str(sender_id, msg_type, msg_len, ( msg_vel_ned_cov_t *) payload,
           max_len, out_str);
  case 531:
    return msg_vel_body_t_to_json_str(sender_id, msg_type, msg_len, ( msg_vel_body_t *) payload,
           max_len, out_str);
  case 528:
    return msg_age_corrections_t_to_json_str(sender_id, msg_type, msg_len, ( msg_age_corrections_t *) payload,
           max_len, out_str);
  case 256:
    return msg_gps_time_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_gps_time_dep_a_t *) payload,
           max_len, out_str);
  case 518:
    return msg_dops_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_dops_dep_a_t *) payload,
           max_len, out_str);
  case 512:
    return msg_pos_ecef_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_pos_ecef_dep_a_t *) payload,
           max_len, out_str);
  case 513:
    return msg_pos_llh_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_pos_llh_dep_a_t *) payload,
           max_len, out_str);
  case 514:
    return msg_baseline_ecef_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_baseline_ecef_dep_a_t *) payload,
           max_len, out_str);
  case 515:
    return msg_baseline_ned_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_baseline_ned_dep_a_t *) payload,
           max_len, out_str);
  case 516:
    return msg_vel_ecef_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_vel_ecef_dep_a_t *) payload,
           max_len, out_str);
  case 517:
    return msg_vel_ned_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_vel_ned_dep_a_t *) payload,
           max_len, out_str);
  case 519:
    return msg_baseline_heading_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_baseline_heading_dep_a_t *) payload,
           max_len, out_str);
  case 1024:
    return msg_ndb_event_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ndb_event_t *) payload,
           max_len, out_str);
  case 74:
    return msg_obs_t_to_json_str(sender_id, msg_type, msg_len, ( msg_obs_t *) payload,
           max_len, out_str);
  case 68:
    return msg_base_pos_llh_t_to_json_str(sender_id, msg_type, msg_len, ( msg_base_pos_llh_t *) payload,
           max_len, out_str);
  case 72:
    return msg_base_pos_ecef_t_to_json_str(sender_id, msg_type, msg_len, ( msg_base_pos_ecef_t *) payload,
           max_len, out_str);
  case 129:
    return msg_ephemeris_gps_dep_e_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ephemeris_gps_dep_e_t *) payload,
           max_len, out_str);
  case 134:
    return msg_ephemeris_gps_dep_f_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ephemeris_gps_dep_f_t *) payload,
           max_len, out_str);
  case 138:
    return msg_ephemeris_gps_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ephemeris_gps_t *) payload,
           max_len, out_str);
  case 137:
    return msg_ephemeris_bds_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ephemeris_bds_t *) payload,
           max_len, out_str);
  case 149:
    return msg_ephemeris_gal_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ephemeris_gal_t *) payload,
           max_len, out_str);
  case 130:
    return msg_ephemeris_sbas_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ephemeris_sbas_dep_a_t *) payload,
           max_len, out_str);
  case 131:
    return msg_ephemeris_glo_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ephemeris_glo_dep_a_t *) payload,
           max_len, out_str);
  case 132:
    return msg_ephemeris_sbas_dep_b_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ephemeris_sbas_dep_b_t *) payload,
           max_len, out_str);
  case 140:
    return msg_ephemeris_sbas_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ephemeris_sbas_t *) payload,
           max_len, out_str);
  case 133:
    return msg_ephemeris_glo_dep_b_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ephemeris_glo_dep_b_t *) payload,
           max_len, out_str);
  case 135:
    return msg_ephemeris_glo_dep_c_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ephemeris_glo_dep_c_t *) payload,
           max_len, out_str);
  case 136:
    return msg_ephemeris_glo_dep_d_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ephemeris_glo_dep_d_t *) payload,
           max_len, out_str);
  case 139:
    return msg_ephemeris_glo_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ephemeris_glo_t *) payload,
           max_len, out_str);
  case 128:
    return msg_ephemeris_dep_d_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ephemeris_dep_d_t *) payload,
           max_len, out_str);
  case 26:
    return msg_ephemeris_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ephemeris_dep_a_t *) payload,
           max_len, out_str);
  case 70:
    return msg_ephemeris_dep_b_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ephemeris_dep_b_t *) payload,
           max_len, out_str);
  case 71:
    return msg_ephemeris_dep_c_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ephemeris_dep_c_t *) payload,
           max_len, out_str);
  case 69:
    return msg_obs_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_obs_dep_a_t *) payload,
           max_len, out_str);
  case 67:
    return msg_obs_dep_b_t_to_json_str(sender_id, msg_type, msg_len, ( msg_obs_dep_b_t *) payload,
           max_len, out_str);
  case 73:
    return msg_obs_dep_c_t_to_json_str(sender_id, msg_type, msg_len, ( msg_obs_dep_c_t *) payload,
           max_len, out_str);
  case 144:
    return msg_iono_t_to_json_str(sender_id, msg_type, msg_len, ( msg_iono_t *) payload,
           max_len, out_str);
  case 145:
    return msg_sv_configuration_gps_t_to_json_str(sender_id, msg_type, msg_len, ( msg_sv_configuration_gps_t *) payload,
           max_len, out_str);
  case 146:
    return msg_group_delay_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_group_delay_dep_a_t *) payload,
           max_len, out_str);
  case 147:
    return msg_group_delay_dep_b_t_to_json_str(sender_id, msg_type, msg_len, ( msg_group_delay_dep_b_t *) payload,
           max_len, out_str);
  case 148:
    return msg_group_delay_t_to_json_str(sender_id, msg_type, msg_len, ( msg_group_delay_t *) payload,
           max_len, out_str);
  case 112:
    return msg_almanac_gps_dep_t_to_json_str(sender_id, msg_type, msg_len, ( msg_almanac_gps_dep_t *) payload,
           max_len, out_str);
  case 114:
    return msg_almanac_gps_t_to_json_str(sender_id, msg_type, msg_len, ( msg_almanac_gps_t *) payload,
           max_len, out_str);
  case 113:
    return msg_almanac_glo_dep_t_to_json_str(sender_id, msg_type, msg_len, ( msg_almanac_glo_dep_t *) payload,
           max_len, out_str);
  case 115:
    return msg_almanac_glo_t_to_json_str(sender_id, msg_type, msg_len, ( msg_almanac_glo_t *) payload,
           max_len, out_str);
  case 117:
    return msg_glo_biases_t_to_json_str(sender_id, msg_type, msg_len, ( msg_glo_biases_t *) payload,
           max_len, out_str);
  case 527:
    return msg_baseline_heading_t_to_json_str(sender_id, msg_type, msg_len, ( msg_baseline_heading_t *) payload,
           max_len, out_str);
  case 544:
    return msg_orient_quat_t_to_json_str(sender_id, msg_type, msg_len, ( msg_orient_quat_t *) payload,
           max_len, out_str);
  case 545:
    return msg_orient_euler_t_to_json_str(sender_id, msg_type, msg_len, ( msg_orient_euler_t *) payload,
           max_len, out_str);
  case 546:
    return msg_angular_rate_t_to_json_str(sender_id, msg_type, msg_len, ( msg_angular_rate_t *) payload,
           max_len, out_str);
  case 105:
    return msg_almanac_t_to_json_str(sender_id, msg_type, msg_len, ( void *) payload,
           max_len, out_str);
  case 104:
    return msg_set_time_t_to_json_str(sender_id, msg_type, msg_len, ( void *) payload,
           max_len, out_str);
  case 182:
    return msg_reset_t_to_json_str(sender_id, msg_type, msg_len, ( msg_reset_t *) payload,
           max_len, out_str);
  case 178:
    return msg_reset_dep_t_to_json_str(sender_id, msg_type, msg_len, ( void *) payload,
           max_len, out_str);
  case 192:
    return msg_cw_results_t_to_json_str(sender_id, msg_type, msg_len, ( void *) payload,
           max_len, out_str);
  case 193:
    return msg_cw_start_t_to_json_str(sender_id, msg_type, msg_len, ( void *) payload,
           max_len, out_str);
  case 34:
    return msg_reset_filters_t_to_json_str(sender_id, msg_type, msg_len, ( msg_reset_filters_t *) payload,
           max_len, out_str);
  case 35:
    return msg_init_base_t_to_json_str(sender_id, msg_type, msg_len, ( void *) payload,
           max_len, out_str);
  case 23:
    return msg_thread_state_t_to_json_str(sender_id, msg_type, msg_len, ( msg_thread_state_t *) payload,
           max_len, out_str);
  case 29:
    return msg_uart_state_t_to_json_str(sender_id, msg_type, msg_len, ( msg_uart_state_t *) payload,
           max_len, out_str);
  case 24:
    return msg_uart_state_depa_t_to_json_str(sender_id, msg_type, msg_len, ( msg_uart_state_depa_t *) payload,
           max_len, out_str);
  case 25:
    return msg_iar_state_t_to_json_str(sender_id, msg_type, msg_len, ( msg_iar_state_t *) payload,
           max_len, out_str);
  case 43:
    return msg_mask_satellite_t_to_json_str(sender_id, msg_type, msg_len, ( msg_mask_satellite_t *) payload,
           max_len, out_str);
  case 27:
    return msg_mask_satellite_dep_t_to_json_str(sender_id, msg_type, msg_len, ( msg_mask_satellite_dep_t *) payload,
           max_len, out_str);
  case 181:
    return msg_device_monitor_t_to_json_str(sender_id, msg_type, msg_len, ( msg_device_monitor_t *) payload,
           max_len, out_str);
  case 184:
    return msg_command_req_t_to_json_str(sender_id, msg_type, msg_len, ( msg_command_req_t *) payload,
           max_len, out_str);
  case 185:
    return msg_command_resp_t_to_json_str(sender_id, msg_type, msg_len, ( msg_command_resp_t *) payload,
           max_len, out_str);
  case 188:
    return msg_command_output_t_to_json_str(sender_id, msg_type, msg_len, ( msg_command_output_t *) payload,
           max_len, out_str);
  case 186:
    return msg_network_state_req_t_to_json_str(sender_id, msg_type, msg_len, ( void *) payload,
           max_len, out_str);
  case 187:
    return msg_network_state_resp_t_to_json_str(sender_id, msg_type, msg_len, ( msg_network_state_resp_t *) payload,
           max_len, out_str);
  case 189:
    return msg_network_bandwidth_usage_t_to_json_str(sender_id, msg_type, msg_len, ( msg_network_bandwidth_usage_t *) payload,
           max_len, out_str);
  case 190:
    return msg_cell_modem_status_t_to_json_str(sender_id, msg_type, msg_len, ( msg_cell_modem_status_t *) payload,
           max_len, out_str);
  case 80:
    return msg_specan_dep_t_to_json_str(sender_id, msg_type, msg_len, ( msg_specan_dep_t *) payload,
           max_len, out_str);
  case 81:
    return msg_specan_t_to_json_str(sender_id, msg_type, msg_len, ( msg_specan_t *) payload,
           max_len, out_str);
  case 30583:
    return msg_sbas_raw_t_to_json_str(sender_id, msg_type, msg_len, ( msg_sbas_raw_t *) payload,
           max_len, out_str);
  case 161:
    return msg_settings_save_t_to_json_str(sender_id, msg_type, msg_len, ( void *) payload,
           max_len, out_str);
  case 160:
    return msg_settings_write_t_to_json_str(sender_id, msg_type, msg_len, ( msg_settings_write_t *) payload,
           max_len, out_str);
  case 175:
    return msg_settings_write_resp_t_to_json_str(sender_id, msg_type, msg_len, ( msg_settings_write_resp_t *) payload,
           max_len, out_str);
  case 164:
    return msg_settings_read_req_t_to_json_str(sender_id, msg_type, msg_len, ( msg_settings_read_req_t *) payload,
           max_len, out_str);
  case 165:
    return msg_settings_read_resp_t_to_json_str(sender_id, msg_type, msg_len, ( msg_settings_read_resp_t *) payload,
           max_len, out_str);
  case 162:
    return msg_settings_read_by_index_req_t_to_json_str(sender_id, msg_type, msg_len, ( msg_settings_read_by_index_req_t *) payload,
           max_len, out_str);
  case 167:
    return msg_settings_read_by_index_resp_t_to_json_str(sender_id, msg_type, msg_len, ( msg_settings_read_by_index_resp_t *) payload,
           max_len, out_str);
  case 166:
    return msg_settings_read_by_index_done_t_to_json_str(sender_id, msg_type, msg_len, ( void *) payload,
           max_len, out_str);
  case 174:
    return msg_settings_register_t_to_json_str(sender_id, msg_type, msg_len, ( msg_settings_register_t *) payload,
           max_len, out_str);
  case 1500:
    return msg_ssr_orbit_clock_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ssr_orbit_clock_t *) payload,
           max_len, out_str);
  case 1505:
    return msg_ssr_code_biases_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ssr_code_biases_t *) payload,
           max_len, out_str);
  case 1510:
    return msg_ssr_phase_biases_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ssr_phase_biases_t *) payload,
           max_len, out_str);
  case 65280:
    return msg_startup_t_to_json_str(sender_id, msg_type, msg_len, ( msg_startup_t *) payload,
           max_len, out_str);
  case 65282:
    return msg_dgnss_status_t_to_json_str(sender_id, msg_type, msg_len, ( msg_dgnss_status_t *) payload,
           max_len, out_str);
  case 65535:
    return msg_heartbeat_t_to_json_str(sender_id, msg_type, msg_len, ( msg_heartbeat_t *) payload,
           max_len, out_str);
  case 65283:
    return msg_ins_status_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ins_status_t *) payload,
           max_len, out_str);
  case 33:
    return msg_tracking_state_detailed_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_tracking_state_detailed_dep_a_t *) payload,
           max_len, out_str);
  case 17:
    return msg_tracking_state_detailed_dep_t_to_json_str(sender_id, msg_type, msg_len, ( msg_tracking_state_detailed_dep_t *) payload,
           max_len, out_str);
  case 65:
    return msg_tracking_state_t_to_json_str(sender_id, msg_type, msg_len, ( msg_tracking_state_t *) payload,
           max_len, out_str);
  case 97:
    return msg_measurement_state_t_to_json_str(sender_id, msg_type, msg_len, ( msg_measurement_state_t *) payload,
           max_len, out_str);
  case 44:
    return msg_tracking_iq_t_to_json_str(sender_id, msg_type, msg_len, ( msg_tracking_iq_t *) payload,
           max_len, out_str);
  case 28:
    return msg_tracking_iq_dep_t_to_json_str(sender_id, msg_type, msg_len, ( msg_tracking_iq_dep_t *) payload,
           max_len, out_str);
  case 22:
    return msg_tracking_state_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_tracking_state_dep_a_t *) payload,
           max_len, out_str);
  case 19:
    return msg_tracking_state_dep_b_t_to_json_str(sender_id, msg_type, msg_len, ( msg_tracking_state_dep_b_t *) payload,
           max_len, out_str);
  case 2048:
    return msg_user_data_t_to_json_str(sender_id, msg_type, msg_len, ( msg_user_data_t *) payload,
           max_len, out_str);
  case 2307:
    return msg_odometry_t_to_json_str(sender_id, msg_type, msg_len, ( msg_odometry_t *) payload,
           max_len, out_str);
  default:
    return 0;
  }
}