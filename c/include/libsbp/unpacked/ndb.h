#ifndef LIBSBP_NDB_MESSAGES_H
#define LIBSBP_NDB_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>
#include <libsbp/unpacked/gnss.h>
  /** Navigation DataBase Event
   *
 * This message is sent out when an object is stored into NDB. If needed
 * message could also be sent out when fetching an object from NDB.
   */
#define SBP_MSG_NDB_EVENT 0x0400

	#define SBP_NDB_EVENT_EVENT_EVENT_TYPE_MASK (0x3)
#define SBP_NDB_EVENT_EVENT_EVENT_TYPE_SHIFT (0u)
#define SBP_NDB_EVENT_EVENT_EVENT_TYPE_GET(flags) \
                             (((flags) >> SBP_NDB_EVENT_EVENT_EVENT_TYPE_SHIFT) \
                             & SBP_NDB_EVENT_EVENT_EVENT_TYPE_MASK)
#define SBP_NDB_EVENT_EVENT_EVENT_TYPE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NDB_EVENT_EVENT_EVENT_TYPE_MASK)) \
                             << (SBP_NDB_EVENT_EVENT_EVENT_TYPE_SHIFT)));} while(0)
                             

#define SBP_NDB_EVENT_EVENT_EVENT_TYPE_UNKNOWN (0)
#define SBP_NDB_EVENT_EVENT_EVENT_TYPE_STORE (1)
#define SBP_NDB_EVENT_EVENT_EVENT_TYPE_FETCH (2)
#define SBP_NDB_EVENT_EVENT_EVENT_TYPE_ERASE (3)
	#define SBP_NDB_EVENT_OBJECT_TYPE_EVENT_OBJECT_TYPE_MASK (0x7)
#define SBP_NDB_EVENT_OBJECT_TYPE_EVENT_OBJECT_TYPE_SHIFT (0u)
#define SBP_NDB_EVENT_OBJECT_TYPE_EVENT_OBJECT_TYPE_GET(flags) \
                             (((flags) >> SBP_NDB_EVENT_OBJECT_TYPE_EVENT_OBJECT_TYPE_SHIFT) \
                             & SBP_NDB_EVENT_OBJECT_TYPE_EVENT_OBJECT_TYPE_MASK)
#define SBP_NDB_EVENT_OBJECT_TYPE_EVENT_OBJECT_TYPE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NDB_EVENT_OBJECT_TYPE_EVENT_OBJECT_TYPE_MASK)) \
                             << (SBP_NDB_EVENT_OBJECT_TYPE_EVENT_OBJECT_TYPE_SHIFT)));} while(0)
                             

#define SBP_NDB_EVENT_OBJECT_TYPE_EVENT_OBJECT_TYPE_UNKNOWN (0)
#define SBP_NDB_EVENT_OBJECT_TYPE_EVENT_OBJECT_TYPE_EPHEMERIS (1)
#define SBP_NDB_EVENT_OBJECT_TYPE_EVENT_OBJECT_TYPE_ALMANAC (2)
#define SBP_NDB_EVENT_OBJECT_TYPE_EVENT_OBJECT_TYPE_ALMANAC_WN (3)
#define SBP_NDB_EVENT_OBJECT_TYPE_EVENT_OBJECT_TYPE_IONO (4)
#define SBP_NDB_EVENT_OBJECT_TYPE_EVENT_OBJECT_TYPE_L2C_CAP (5)
#define SBP_NDB_EVENT_OBJECT_TYPE_EVENT_OBJECT_TYPE_LGF (6)
	#define SBP_NDB_EVENT_RESULT_EVENT_RESULT_MASK (0xf)
#define SBP_NDB_EVENT_RESULT_EVENT_RESULT_SHIFT (0u)
#define SBP_NDB_EVENT_RESULT_EVENT_RESULT_GET(flags) \
                             (((flags) >> SBP_NDB_EVENT_RESULT_EVENT_RESULT_SHIFT) \
                             & SBP_NDB_EVENT_RESULT_EVENT_RESULT_MASK)
#define SBP_NDB_EVENT_RESULT_EVENT_RESULT_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NDB_EVENT_RESULT_EVENT_RESULT_MASK)) \
                             << (SBP_NDB_EVENT_RESULT_EVENT_RESULT_SHIFT)));} while(0)
                             

#define SBP_NDB_EVENT_RESULT_EVENT_RESULT_NDB_ERR_NONE (0)
#define SBP_NDB_EVENT_RESULT_EVENT_RESULT_NDB_ERR_MISSING_IE (1)
#define SBP_NDB_EVENT_RESULT_EVENT_RESULT_NDB_ERR_UNSUPPORTED (2)
#define SBP_NDB_EVENT_RESULT_EVENT_RESULT_NDB_ERR_FILE_IO (3)
#define SBP_NDB_EVENT_RESULT_EVENT_RESULT_NDB_ERR_INIT_DONE (4)
#define SBP_NDB_EVENT_RESULT_EVENT_RESULT_NDB_ERR_BAD_PARAM (5)
#define SBP_NDB_EVENT_RESULT_EVENT_RESULT_NDB_ERR_UNRELIABLE_DATA (6)
#define SBP_NDB_EVENT_RESULT_EVENT_RESULT_NDB_ERR_ALGORITHM_ERROR (7)
#define SBP_NDB_EVENT_RESULT_EVENT_RESULT_NDB_ERR_NO_DATA (8)
#define SBP_NDB_EVENT_RESULT_EVENT_RESULT_NDB_ERR_NO_CHANGE (9)
#define SBP_NDB_EVENT_RESULT_EVENT_RESULT_NDB_ERR_OLDER_DATA (10)
	#define SBP_NDB_EVENT_DATA_SOURCE_DATA_SOURCE_MASK (0x3)
#define SBP_NDB_EVENT_DATA_SOURCE_DATA_SOURCE_SHIFT (0u)
#define SBP_NDB_EVENT_DATA_SOURCE_DATA_SOURCE_GET(flags) \
                             (((flags) >> SBP_NDB_EVENT_DATA_SOURCE_DATA_SOURCE_SHIFT) \
                             & SBP_NDB_EVENT_DATA_SOURCE_DATA_SOURCE_MASK)
#define SBP_NDB_EVENT_DATA_SOURCE_DATA_SOURCE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NDB_EVENT_DATA_SOURCE_DATA_SOURCE_MASK)) \
                             << (SBP_NDB_EVENT_DATA_SOURCE_DATA_SOURCE_SHIFT)));} while(0)
                             

#define SBP_NDB_EVENT_DATA_SOURCE_DATA_SOURCE_NDB_DS_UNDEFINED (0)
#define SBP_NDB_EVENT_DATA_SOURCE_DATA_SOURCE_NDB_DS_INIT (1)
#define SBP_NDB_EVENT_DATA_SOURCE_DATA_SOURCE_NDB_DS_RECEIVER (2)
#define SBP_NDB_EVENT_DATA_SOURCE_DATA_SOURCE_NDB_DS_SBP (3)
	
	#define SBP_NDB_EVENT_OBJECT_SID_CODE__MASK (0xff)
#define SBP_NDB_EVENT_OBJECT_SID_CODE__SHIFT (0u)
#define SBP_NDB_EVENT_OBJECT_SID_CODE__GET(flags) \
                             (((flags) >> SBP_NDB_EVENT_OBJECT_SID_CODE__SHIFT) \
                             & SBP_NDB_EVENT_OBJECT_SID_CODE__MASK)
#define SBP_NDB_EVENT_OBJECT_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NDB_EVENT_OBJECT_SID_CODE__MASK)) \
                             << (SBP_NDB_EVENT_OBJECT_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_NDB_EVENT_OBJECT_SID_CODE__GPS_L1CA (0)
#define SBP_NDB_EVENT_OBJECT_SID_CODE__GPS_L2CM (1)
#define SBP_NDB_EVENT_OBJECT_SID_CODE__SBAS_L1CA (2)
#define SBP_NDB_EVENT_OBJECT_SID_CODE__GLO_L1CA (3)
#define SBP_NDB_EVENT_OBJECT_SID_CODE__GLO_L2CA (4)
#define SBP_NDB_EVENT_OBJECT_SID_CODE__GPS_L1P (5)
#define SBP_NDB_EVENT_OBJECT_SID_CODE__GPS_L2P (6)
#define SBP_NDB_EVENT_OBJECT_SID_CODE__BDS2_B1 (12)
#define SBP_NDB_EVENT_OBJECT_SID_CODE__BDS2_B2 (13)
#define SBP_NDB_EVENT_OBJECT_SID_CODE__GAL_E1B (14)
#define SBP_NDB_EVENT_OBJECT_SID_CODE__GAL_E7I (20)
#define SBP_NDB_EVENT_OBJECT_SID_CODE__BDS3_B2A (47)
	
	#define SBP_NDB_EVENT_SRC_SID_CODE__MASK (0xff)
#define SBP_NDB_EVENT_SRC_SID_CODE__SHIFT (0u)
#define SBP_NDB_EVENT_SRC_SID_CODE__GET(flags) \
                             (((flags) >> SBP_NDB_EVENT_SRC_SID_CODE__SHIFT) \
                             & SBP_NDB_EVENT_SRC_SID_CODE__MASK)
#define SBP_NDB_EVENT_SRC_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NDB_EVENT_SRC_SID_CODE__MASK)) \
                             << (SBP_NDB_EVENT_SRC_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_NDB_EVENT_SRC_SID_CODE__GPS_L1CA (0)
#define SBP_NDB_EVENT_SRC_SID_CODE__GPS_L2CM (1)
#define SBP_NDB_EVENT_SRC_SID_CODE__SBAS_L1CA (2)
#define SBP_NDB_EVENT_SRC_SID_CODE__GLO_L1CA (3)
#define SBP_NDB_EVENT_SRC_SID_CODE__GLO_L2CA (4)
#define SBP_NDB_EVENT_SRC_SID_CODE__GPS_L1P (5)
#define SBP_NDB_EVENT_SRC_SID_CODE__GPS_L2P (6)
#define SBP_NDB_EVENT_SRC_SID_CODE__BDS2_B1 (12)
#define SBP_NDB_EVENT_SRC_SID_CODE__BDS2_B2 (13)
#define SBP_NDB_EVENT_SRC_SID_CODE__GAL_E1B (14)
#define SBP_NDB_EVENT_SRC_SID_CODE__GAL_E7I (20)
#define SBP_NDB_EVENT_SRC_SID_CODE__BDS3_B2A (47)
typedef struct {
  
  /**
* HW time in milliseconds.[ms]
   */
    u64
  recv_time
  ;
  /**
* Event type.
   */
    u8
  event
  ;
  /**
* Event object type.
   */
    u8
  object_type
  ;
  /**
* Event result.
   */
    u8
  result
  ;
  /**
* Data source for STORE event, reserved for other events.
   */
    u8
  data_source
  ;
  /**
 * GNSS signal identifier,
 * If object_type is Ephemeris OR Almanac, sid indicates for which
 * signal the object belongs to. Reserved in other cases.
   */
  sbp_sbp_gnss_signal_t
  object_sid
  ;
  /**
 * GNSS signal identifier,
 * If object_type is Almanac, Almanac WN, Iono OR L2C capabilities
 * AND data_source is NDB_DS_RECEIVER sid indicates from which SV
 * data was decoded. Reserved in other cases.
   */
  sbp_sbp_gnss_signal_t
  src_sid
  ;
  /**
 * A unique identifier of the sending hardware. For v1.0,
 * set to the 2 least significant bytes of the device serial
 * number, valid only if data_source is NDB_DS_SBP. Reserved in case
 * of other data_source.
   */
    u16
  original_sender
  ;
} sbp_msg_ndb_event_t;



#include <libsbp/unpacked/ndb_operators.h>
#include <libsbp/unpacked/ndb_packers.h>

#endif /* LIBSBP_NDB_MESSAGES_H */
