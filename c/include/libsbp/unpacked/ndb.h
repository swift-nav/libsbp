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
#define SBP_NDB_EVENT_EVENT_TYPE_MASK (0x3)
#define SBP_NDB_EVENT_EVENT_TYPE_SHIFT (0u)
#define SBP_NDB_EVENT_EVENT_TYPE_GET(flags) \
                             (((flags) >> SBP_NDB_EVENT_EVENT_TYPE_SHIFT) \
                             & SBP_NDB_EVENT_EVENT_TYPE_MASK)
#define SBP_NDB_EVENT_EVENT_TYPE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NDB_EVENT_EVENT_TYPE_MASK)) \
                             << (SBP_NDB_EVENT_EVENT_TYPE_SHIFT)));} while(0)
                             

#define SBP_NDB_EVENT_EVENT_TYPE_UNKNOWN (0)
#define SBP_NDB_EVENT_EVENT_TYPE_STORE (1)
#define SBP_NDB_EVENT_EVENT_TYPE_FETCH (2)
#define SBP_NDB_EVENT_EVENT_TYPE_ERASE (3)
#define SBP_NDB_EVENT_EVENT_OBJECT_TYPE_MASK (0x7)
#define SBP_NDB_EVENT_EVENT_OBJECT_TYPE_SHIFT (0u)
#define SBP_NDB_EVENT_EVENT_OBJECT_TYPE_GET(flags) \
                             (((flags) >> SBP_NDB_EVENT_EVENT_OBJECT_TYPE_SHIFT) \
                             & SBP_NDB_EVENT_EVENT_OBJECT_TYPE_MASK)
#define SBP_NDB_EVENT_EVENT_OBJECT_TYPE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NDB_EVENT_EVENT_OBJECT_TYPE_MASK)) \
                             << (SBP_NDB_EVENT_EVENT_OBJECT_TYPE_SHIFT)));} while(0)
                             

#define SBP_NDB_EVENT_EVENT_OBJECT_TYPE_UNKNOWN (0)
#define SBP_NDB_EVENT_EVENT_OBJECT_TYPE_EPHEMERIS (1)
#define SBP_NDB_EVENT_EVENT_OBJECT_TYPE_ALMANAC (2)
#define SBP_NDB_EVENT_EVENT_OBJECT_TYPE_ALMANAC_WN (3)
#define SBP_NDB_EVENT_EVENT_OBJECT_TYPE_IONO (4)
#define SBP_NDB_EVENT_EVENT_OBJECT_TYPE_L2C_CAP (5)
#define SBP_NDB_EVENT_EVENT_OBJECT_TYPE_LGF (6)
#define SBP_NDB_EVENT_EVENT_RESULT_MASK (0xf)
#define SBP_NDB_EVENT_EVENT_RESULT_SHIFT (0u)
#define SBP_NDB_EVENT_EVENT_RESULT_GET(flags) \
                             (((flags) >> SBP_NDB_EVENT_EVENT_RESULT_SHIFT) \
                             & SBP_NDB_EVENT_EVENT_RESULT_MASK)
#define SBP_NDB_EVENT_EVENT_RESULT_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NDB_EVENT_EVENT_RESULT_MASK)) \
                             << (SBP_NDB_EVENT_EVENT_RESULT_SHIFT)));} while(0)
                             

#define SBP_NDB_EVENT_EVENT_RESULT_NDB_ERR_NONE (0)
#define SBP_NDB_EVENT_EVENT_RESULT_NDB_ERR_MISSING_IE (1)
#define SBP_NDB_EVENT_EVENT_RESULT_NDB_ERR_UNSUPPORTED (2)
#define SBP_NDB_EVENT_EVENT_RESULT_NDB_ERR_FILE_IO (3)
#define SBP_NDB_EVENT_EVENT_RESULT_NDB_ERR_INIT_DONE (4)
#define SBP_NDB_EVENT_EVENT_RESULT_NDB_ERR_BAD_PARAM (5)
#define SBP_NDB_EVENT_EVENT_RESULT_NDB_ERR_UNRELIABLE_DATA (6)
#define SBP_NDB_EVENT_EVENT_RESULT_NDB_ERR_ALGORITHM_ERROR (7)
#define SBP_NDB_EVENT_EVENT_RESULT_NDB_ERR_NO_DATA (8)
#define SBP_NDB_EVENT_EVENT_RESULT_NDB_ERR_NO_CHANGE (9)
#define SBP_NDB_EVENT_EVENT_RESULT_NDB_ERR_OLDER_DATA (10)
#define SBP_NDB_EVENT_DATA_SOURCE_MASK (0x3)
#define SBP_NDB_EVENT_DATA_SOURCE_SHIFT (0u)
#define SBP_NDB_EVENT_DATA_SOURCE_GET(flags) \
                             (((flags) >> SBP_NDB_EVENT_DATA_SOURCE_SHIFT) \
                             & SBP_NDB_EVENT_DATA_SOURCE_MASK)
#define SBP_NDB_EVENT_DATA_SOURCE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NDB_EVENT_DATA_SOURCE_MASK)) \
                             << (SBP_NDB_EVENT_DATA_SOURCE_SHIFT)));} while(0)
                             

#define SBP_NDB_EVENT_DATA_SOURCE_NDB_DS_UNDEFINED (0)
#define SBP_NDB_EVENT_DATA_SOURCE_NDB_DS_INIT (1)
#define SBP_NDB_EVENT_DATA_SOURCE_NDB_DS_RECEIVER (2)
#define SBP_NDB_EVENT_DATA_SOURCE_NDB_DS_SBP (3)
/** Navigation DataBase Event
 *
((m.desc|commentify)))
 */
#define SBP_MSG_NDB_EVENT 0x0400
typedef struct {
  u64 recv_time;
  u8 event;
  u8 object_type;
  u8 result;
  u8 data_source;
  sbp_sbp_gnss_signal_t object_sid;
  sbp_sbp_gnss_signal_t src_sid;
  u16 original_sender;
} sbp_msg_ndb_event_t;



#include <libsbp/unpacked/ndb_operators.h>
#include <libsbp/unpacked/ndb_packers.h>

#endif /* LIBSBP_NDB_MESSAGES_H */
