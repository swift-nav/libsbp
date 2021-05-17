#ifndef LIBSBP_SBAS_MESSAGES_H
#define LIBSBP_SBAS_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>
#include <libsbp/unpacked/gnss.h>
/** Raw SBAS data
 *
((m.desc|commentify)))
 */
#define SBP_MSG_SBAS_RAW 0x7777
typedef struct {
  sbp_sbp_gnss_signal_t sid;
  u32 tow;
  u8 message_type;
  u8 data[27];
} sbp_msg_sbas_raw_t;




#include <libsbp/unpacked/sbas_operators.h>
#include <libsbp/unpacked/sbas_packers.h>

#endif /* LIBSBP_SBAS_MESSAGES_H */
