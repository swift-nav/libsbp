#ifndef LIBSBP_FLASH_MESSAGES_H
#define LIBSBP_FLASH_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>
#define SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_MASK (0x1)
#define SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_SHIFT (0u)
#define SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_GET(flags) \
                             (((flags) >> SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_SHIFT) \
                             & SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_MASK)
#define SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_MASK)) \
                             << (SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_SHIFT)));} while(0)
                             

#define SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_FLASH_STM (0)
#define SBP_FLASH_PROGRAM_FLASH_TARGET_TO_READ_FLASH_M25 (1)
/** Program flash addresses
 *
((m.desc|commentify)))
 */
#define SBP_MSG_FLASH_PROGRAM           0x00E6
typedef struct {
  u8 target;
  u8 addr_start[3];
  u8 addr_len;
  u8 data[250];
} sbp_msg_flash_program_t;



#define SBP_FLASH_DONE_RESPONSE_CODE_MASK (0x7)
#define SBP_FLASH_DONE_RESPONSE_CODE_SHIFT (0u)
#define SBP_FLASH_DONE_RESPONSE_CODE_GET(flags) \
                             (((flags) >> SBP_FLASH_DONE_RESPONSE_CODE_SHIFT) \
                             & SBP_FLASH_DONE_RESPONSE_CODE_MASK)
#define SBP_FLASH_DONE_RESPONSE_CODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_FLASH_DONE_RESPONSE_CODE_MASK)) \
                             << (SBP_FLASH_DONE_RESPONSE_CODE_SHIFT)));} while(0)
                             

#define SBP_FLASH_DONE_RESPONSE_CODE_FLASH_OK (0)
#define SBP_FLASH_DONE_RESPONSE_CODE_FLASH_INVALID_FLASH (1)
#define SBP_FLASH_DONE_RESPONSE_CODE_FLASH_INVALID_LEN (2)
#define SBP_FLASH_DONE_RESPONSE_CODE_FLASH_INVALID_ADDR (3)
#define SBP_FLASH_DONE_RESPONSE_CODE_FLASH_INVALID_RANGE (4)
#define SBP_FLASH_DONE_RESPONSE_CODE_FLASH_INVALID_SECTOR (5)
/** Flash response message (host <= device).
 *
((m.desc|commentify)))
 */
#define SBP_MSG_FLASH_DONE              0x00E0
typedef struct {
  u8 response;
} sbp_msg_flash_done_t;



#define SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_MASK (0x1)
#define SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_SHIFT (0u)
#define SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_GET(flags) \
                             (((flags) >> SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_SHIFT) \
                             & SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_MASK)
#define SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_MASK)) \
                             << (SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_SHIFT)));} while(0)
                             

#define SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_FLASH_STM (0)
#define SBP_FLASH_READ_REQ_FLASH_TARGET_TO_READ_FLASH_M25 (1)
/** Read STM or M25 flash address request (host => device).
 *
((m.desc|commentify)))
 */
#define SBP_MSG_FLASH_READ_REQ          0x00E7
typedef struct {
  u8 target;
  u8 addr_start[3];
  u8 addr_len;
} sbp_msg_flash_read_req_t;



#define SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_MASK (0x1)
#define SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_SHIFT (0u)
#define SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_GET(flags) \
                             (((flags) >> SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_SHIFT) \
                             & SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_MASK)
#define SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_MASK)) \
                             << (SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_SHIFT)));} while(0)
                             

#define SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_FLASH_STM (0)
#define SBP_FLASH_READ_RESP_FLASH_TARGET_TO_READ_FLASH_M25 (1)
/** Read STM or M25 flash address response (host <= device).
 *
((m.desc|commentify)))
 */
#define SBP_MSG_FLASH_READ_RESP         0x00E1
typedef struct {
  u8 target;
  u8 addr_start[3];
  u8 addr_len;
} sbp_msg_flash_read_resp_t;



#define SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_MASK (0x1)
#define SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_SHIFT (0u)
#define SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_GET(flags) \
                             (((flags) >> SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_SHIFT) \
                             & SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_MASK)
#define SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_MASK)) \
                             << (SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_SHIFT)));} while(0)
                             

#define SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_FLASH_STM (0)
#define SBP_FLASH_ERASE_FLASH_TARGET_TO_READ_FLASH_M25 (1)
/** Erase sector of device flash memory (host => device).
 *
((m.desc|commentify)))
 */
#define SBP_MSG_FLASH_ERASE             0x00E2
typedef struct {
  u8 target;
  u32 sector_num;
} sbp_msg_flash_erase_t;



/** Lock sector of STM flash memory (host => device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_STM_FLASH_LOCK_SECTOR   0x00E3
typedef struct {
  u32 sector;
} sbp_msg_stm_flash_lock_sector_t;



/** Unlock sector of STM flash memory (host => device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_STM_FLASH_UNLOCK_SECTOR 0x00E4
typedef struct {
  u32 sector;
} sbp_msg_stm_flash_unlock_sector_t;



/** Read device's hardcoded unique ID request (host => device)

 *
((m.desc|commentify)))
 */
#define SBP_MSG_STM_UNIQUE_ID_REQ       0x00E8
typedef struct {
  char DO_NOT_USE_dummy_field_to_prevent_empty_struct;
} sbp_msg_stm_unique_id_req_t;



/** Read device's hardcoded unique ID response (host <= device)

 *
((m.desc|commentify)))
 */
#define SBP_MSG_STM_UNIQUE_ID_RESP      0x00E5
typedef struct {
  u8 stm_id[12];
} sbp_msg_stm_unique_id_resp_t;



/** Write M25 flash status register (host => device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_M25_FLASH_WRITE_STATUS  0x00F3
typedef struct {
  u8 status[1];
} sbp_msg_m25_flash_write_status_t;




#include <libsbp/unpacked/flash_operators.h>
#include <libsbp/unpacked/flash_packers.h>

#endif /* LIBSBP_FLASH_MESSAGES_H */
