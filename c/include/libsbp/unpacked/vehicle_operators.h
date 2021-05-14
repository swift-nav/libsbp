#ifndef LIBSBP_VEHICLE_OPERATORS_H
#define LIBSBP_VEHICLE_OPERATORS_H

#ifndef LIBSBP_VEHICLE_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/vehicle.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#include <libsbp/common.h>
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_odometry_t &a, const sbp_msg_odometry_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tow != b.tow) { return false; }
        
    if (a.velocity != b.velocity) { return false; }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_odometry_t &a, const sbp_msg_odometry_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_wheeltick_t &a, const sbp_msg_wheeltick_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.time != b.time) { return false; }
        
    if (a.flags != b.flags) { return false; }
        
    if (a.source != b.source) { return false; }
        
    if (a.ticks != b.ticks) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_wheeltick_t &a, const sbp_msg_wheeltick_t &b) {
  return !(a == b);
}
#endif

#endif
