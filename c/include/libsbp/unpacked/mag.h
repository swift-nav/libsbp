#ifndef LIBSBP_MAG_MESSAGES_H
#define LIBSBP_MAG_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
/** Raw magnetometer data
 *
 * Raw data from the magnetometer.
 */
#define SBP_MSG_MAG_RAW 0x0902

typedef struct
{

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

#include <libsbp/unpacked/mag_operators.h>
#include <libsbp/unpacked/mag_packers.h>

#endif /* LIBSBP_MAG_MESSAGES_H */