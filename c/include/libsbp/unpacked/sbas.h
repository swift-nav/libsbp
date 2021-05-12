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
 * This message is sent once per second per SBAS satellite. ME checks the
 * parity of the data block and sends only blocks that pass the check.
   */
#define SBP_MSG_SBAS_RAW 0x7777

	
	#define SBP_SBAS_RAW_SID_CODE__MASK (0xff)
#define SBP_SBAS_RAW_SID_CODE__SHIFT (0u)
#define SBP_SBAS_RAW_SID_CODE__GET(flags) \
                             (((flags) >> SBP_SBAS_RAW_SID_CODE__SHIFT) \
                             & SBP_SBAS_RAW_SID_CODE__MASK)
#define SBP_SBAS_RAW_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_SBAS_RAW_SID_CODE__MASK)) \
                             << (SBP_SBAS_RAW_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_SBAS_RAW_SID_CODE__GPS_L1CA (0)
#define SBP_SBAS_RAW_SID_CODE__GPS_L2CM (1)
#define SBP_SBAS_RAW_SID_CODE__SBAS_L1CA (2)
#define SBP_SBAS_RAW_SID_CODE__GLO_L1CA (3)
#define SBP_SBAS_RAW_SID_CODE__GLO_L2CA (4)
#define SBP_SBAS_RAW_SID_CODE__GPS_L1P (5)
#define SBP_SBAS_RAW_SID_CODE__GPS_L2P (6)
#define SBP_SBAS_RAW_SID_CODE__BDS2_B1 (12)
#define SBP_SBAS_RAW_SID_CODE__BDS2_B2 (13)
#define SBP_SBAS_RAW_SID_CODE__GAL_E1B (14)
#define SBP_SBAS_RAW_SID_CODE__GAL_E7I (20)
#define SBP_SBAS_RAW_SID_CODE__BDS3_B2A (47)
typedef struct {
  
  /**
* GNSS signal identifier.
   */
  sbp_sbp_gnss_signal_t
  sid
  ;
  /**
* GPS time-of-week at the start of the data block.[ms]
   */
    u32
  tow
  ;
  /**
* SBAS message type (0-63)
   */
    u8
  message_type
  ;
  /**
* Raw SBAS data field of 212 bits (last byte padded with zeros).
   */
    u8
  data
    [27]
  ;
} sbp_msg_sbas_raw_t;



#include <libsbp/unpacked/sbas_operators.h>
#include <libsbp/unpacked/sbas_packers.h>

#endif /* LIBSBP_SBAS_MESSAGES_H */
