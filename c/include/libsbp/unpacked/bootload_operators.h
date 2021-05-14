#ifndef LIBSBP_BOOTLOAD_OPERATORS_H
#define LIBSBP_BOOTLOAD_OPERATORS_H

#ifndef LIBSBP_BOOTLOAD_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/bootload.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#include <libsbp/common.h>
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_bootloader_handshake_req_t &a, const sbp_msg_bootloader_handshake_req_t &b) {
  (void)a;
  (void)b;
  

  return true;
}

static inline bool operator!=(const sbp_msg_bootloader_handshake_req_t &a, const sbp_msg_bootloader_handshake_req_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_bootloader_handshake_resp_t &a, const sbp_msg_bootloader_handshake_resp_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.flags != b.flags) { return false; }
    if (0 != sbp_unterminated_string_strcmp(&a.version, &b.version, 251)) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_bootloader_handshake_resp_t &a, const sbp_msg_bootloader_handshake_resp_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_bootloader_jump_to_app_t &a, const sbp_msg_bootloader_jump_to_app_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.jump != b.jump) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_bootloader_jump_to_app_t &a, const sbp_msg_bootloader_jump_to_app_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_nap_device_dna_req_t &a, const sbp_msg_nap_device_dna_req_t &b) {
  (void)a;
  (void)b;
  

  return true;
}

static inline bool operator!=(const sbp_msg_nap_device_dna_req_t &a, const sbp_msg_nap_device_dna_req_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_nap_device_dna_resp_t &a, const sbp_msg_nap_device_dna_resp_t &b) {
  (void)a;
  (void)b;
  
        for (size_t dna_idx = 0; dna_idx < 8; dna_idx++)
        {
            
    if (a.dna[dna_idx] != b.dna[dna_idx]) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_nap_device_dna_resp_t &a, const sbp_msg_nap_device_dna_resp_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_bootloader_handshake_dep_a_t &a, const sbp_msg_bootloader_handshake_dep_a_t &b) {
  (void)a;
  (void)b;
  
    if (0 != sbp_unterminated_string_strcmp(&a.handshake, &b.handshake, 255)) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_bootloader_handshake_dep_a_t &a, const sbp_msg_bootloader_handshake_dep_a_t &b) {
  return !(a == b);
}
#endif

#endif
