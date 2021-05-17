#ifndef LIBSBP_SETTINGS_MESSAGES_H
#define LIBSBP_SETTINGS_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>
/** Save settings to flash (host => device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_SETTINGS_SAVE               0x00A1
typedef struct {
  char DO_NOT_USE_dummy_field_to_prevent_empty_struct;
} sbp_msg_settings_save_t;


/** Write device configuration settings (host => device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_SETTINGS_WRITE              0x00A0
typedef struct {
  sbp_multipart_string_t setting;
} sbp_msg_settings_write_t;


#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_MASK (0x3)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_SHIFT (0u)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_GET(flags) \
                             (((flags) >> SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_SHIFT) \
                             & SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_MASK)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_MASK)) \
                             << (SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_SHIFT)));} while(0)
                             

#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_ACCEPTED_VALUE_UPDATED (0)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_REJECTED_VALUE_UNPARSABLE_OR_OUT_OF_RANGE (1)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_REJECTED_REQUESTED_SETTING_DOES_NOT_EXIST (2)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_REJECTED_SETTING_NAME_COULD_NOT_BE_PARSED (3)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_REJECTED_SETTING_IS_READ_ONLY (4)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_REJECTED_MODIFICATION_IS_TEMPORARILY_DISABLED (5)
#define SBP_SETTINGS_WRITE_RESP_WRITE_STATUS_REJECTED_UNSPECIFIED_ERROR (6)
/** Acknowledgement with status of MSG_SETTINGS_WRITE
 *
((m.desc|commentify)))
 */
#define SBP_MSG_SETTINGS_WRITE_RESP         0x00AF
typedef struct {
  u8 status;
  sbp_multipart_string_t setting;
} sbp_msg_settings_write_resp_t;


/** Read device configuration settings (host => device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_SETTINGS_READ_REQ           0x00A4
typedef struct {
  sbp_multipart_string_t setting;
} sbp_msg_settings_read_req_t;


/** Read device configuration settings (host <= device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_SETTINGS_READ_RESP          0x00A5
typedef struct {
  sbp_multipart_string_t setting;
} sbp_msg_settings_read_resp_t;


/** Read setting by direct index (host => device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_SETTINGS_READ_BY_INDEX_REQ  0x00A2
typedef struct {
  u16 index;
} sbp_msg_settings_read_by_index_req_t;


/** Read setting by direct index (host <= device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_SETTINGS_READ_BY_INDEX_RESP 0x00A7
typedef struct {
  u16 index;
  sbp_multipart_string_t setting;
} sbp_msg_settings_read_by_index_resp_t;


/** Finished reading settings (host <= device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_SETTINGS_READ_BY_INDEX_DONE 0x00A6
typedef struct {
  char DO_NOT_USE_dummy_field_to_prevent_empty_struct;
} sbp_msg_settings_read_by_index_done_t;


/** Register setting and default value (device => host)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_SETTINGS_REGISTER           0x00AE
typedef struct {
  sbp_multipart_string_t setting;
} sbp_msg_settings_register_t;


#define SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_MASK (0x3)
#define SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_SHIFT (0u)
#define SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_GET(flags) \
                             (((flags) >> SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_SHIFT) \
                             & SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_MASK)
#define SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_MASK)) \
                             << (SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_SHIFT)));} while(0)
                             

#define SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_ACCEPTED_REQUESTED_DEFAULT_VALUE_RETURNED (0)
#define SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_ACCEPTED_SETTING_FOUND_IN_PERMANENT_STORAGE_VALUE_FROM_STORAGE_RETURNED (1)
#define SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_REJECTED_SETTING_ALREADY_REGISTERED_VALUE_FROM_MEMORY_RETURNED (2)
#define SBP_SETTINGS_REGISTER_RESP_REGISTER_STATUS_REJECTED_MALFORMED_MESSAGE (3)
/** Register setting and default value (device <= host)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_SETTINGS_REGISTER_RESP      0x01AF
typedef struct {
  u8 status;
  sbp_multipart_string_t setting;
} sbp_msg_settings_register_resp_t;



#include <libsbp/unpacked/settings_operators.h>
#include <libsbp/unpacked/settings_packers.h>

#endif /* LIBSBP_SETTINGS_MESSAGES_H */
