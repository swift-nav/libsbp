#ifndef LIBSBP_MAG_MESSAGES_H
#define LIBSBP_MAG_MESSAGES_H

#include "common.h"

SBP_PACK_START
/** Raw magnetometer data
 *
 * Raw data from the magnetometer.
 */
#define SBP_MSG_MAG_RAW 0x0902

typedef struct SBP_ATTR_PACKED {
  /**
   * Milliseconds since start of GPS week. If the high bit is set, the
   * time is unknown or invalid.[ms]
   */
  u32 tow;
  /**
   * Milliseconds since start of GPS week, fractional part[ms / 256]
   */
  u8 tow_f;
  /**
   * Magnetic field in the body frame X axis[microteslas]
   */
  s16 mag_x;
  /**
   * Magnetic field in the body frame Y axis[microteslas]
   */
  s16 mag_y;
  /**
   * Magnetic field in the body frame Z axis[microteslas]
   */
  s16 mag_z;
} sbp_msg_mag_raw_t;

SBP_PACK_END

#endif /* LIBSBP_MAG_MESSAGES_H */