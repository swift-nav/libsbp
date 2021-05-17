#ifndef LIBSBP_MAG_MESSAGES_H
#define LIBSBP_MAG_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/string/multipart.h>
#include <libsbp/unpacked/string/sequence.h>
#include <libsbp/unpacked/string/unterminated.h>
#include <libsbp/unpacked/string/null_terminated.h>
/** Raw magnetometer data
 *
((m.desc|commentify)))
 */
#define SBP_MSG_MAG_RAW 0x0902
typedef struct {
  u32 tow;
  u8 tow_f;
  s16 mag_x;
  s16 mag_y;
  s16 mag_z;
} sbp_msg_mag_raw_t;




#include <libsbp/unpacked/mag_operators.h>
#include <libsbp/unpacked/mag_packers.h>

#endif /* LIBSBP_MAG_MESSAGES_H */
