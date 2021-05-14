#ifndef LIBSBP_FLASH_MESSAGES_H
#define LIBSBP_FLASH_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>
  /** Program flash addresses
   *
 * The flash program message programs a set of addresses of either
 * the STM or M25 flash. The device replies with either a
 * MSG_FLASH_DONE message containing the return code FLASH_OK (0)
 * on success, or FLASH_INVALID_LEN (2) if the maximum write size
 * is exceeded. Note that the sector-containing addresses must be
 * erased before addresses can be programmed.
   */
#define SBP_MSG_FLASH_PROGRAM           0x00E6

	#define SBP_FLASH_PROGRAM_TARGET_FLASH_TARGET_TO_READ_MASK (0x1)
#define SBP_FLASH_PROGRAM_TARGET_FLASH_TARGET_TO_READ_SHIFT (0u)
#define SBP_FLASH_PROGRAM_TARGET_FLASH_TARGET_TO_READ_GET(flags) \
                             (((flags) >> SBP_FLASH_PROGRAM_TARGET_FLASH_TARGET_TO_READ_SHIFT) \
                             & SBP_FLASH_PROGRAM_TARGET_FLASH_TARGET_TO_READ_MASK)
#define SBP_FLASH_PROGRAM_TARGET_FLASH_TARGET_TO_READ_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_FLASH_PROGRAM_TARGET_FLASH_TARGET_TO_READ_MASK)) \
                             << (SBP_FLASH_PROGRAM_TARGET_FLASH_TARGET_TO_READ_SHIFT)));} while(0)
                             

#define SBP_FLASH_PROGRAM_TARGET_FLASH_TARGET_TO_READ_FLASH_STM (0)
#define SBP_FLASH_PROGRAM_TARGET_FLASH_TARGET_TO_READ_FLASH_M25 (1)
typedef struct {
  
  /**
* Target flags
   */
    u8
  target
  ;
  /**
* Starting address offset to program[bytes]
   */
    u8
  addr_start
    [3]
  ;
  /**
 * Length of set of addresses to program, counting up from
 * starting address[bytes]
   */
    u8
  addr_len
  ;
  /**
* Data to program addresses with, with length N=addr_len
   */
    u8
  data
    [250]
  ;
} sbp_msg_flash_program_t;


  /** Flash response message (host <= device).
   *
 * This message defines success or failure codes for a variety of
 * flash memory requests from the host to the device. Flash read
 * and write messages, such as MSG_FLASH_READ_REQ, or
 * MSG_FLASH_PROGRAM, may return this message on failure.
   */
#define SBP_MSG_FLASH_DONE              0x00E0

	#define SBP_FLASH_DONE_RESPONSE_RESPONSE_CODE_MASK (0x7)
#define SBP_FLASH_DONE_RESPONSE_RESPONSE_CODE_SHIFT (0u)
#define SBP_FLASH_DONE_RESPONSE_RESPONSE_CODE_GET(flags) \
                             (((flags) >> SBP_FLASH_DONE_RESPONSE_RESPONSE_CODE_SHIFT) \
                             & SBP_FLASH_DONE_RESPONSE_RESPONSE_CODE_MASK)
#define SBP_FLASH_DONE_RESPONSE_RESPONSE_CODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_FLASH_DONE_RESPONSE_RESPONSE_CODE_MASK)) \
                             << (SBP_FLASH_DONE_RESPONSE_RESPONSE_CODE_SHIFT)));} while(0)
                             

#define SBP_FLASH_DONE_RESPONSE_RESPONSE_CODE_FLASH_OK (0)
#define SBP_FLASH_DONE_RESPONSE_RESPONSE_CODE_FLASH_INVALID_FLASH (1)
#define SBP_FLASH_DONE_RESPONSE_RESPONSE_CODE_FLASH_INVALID_LEN (2)
#define SBP_FLASH_DONE_RESPONSE_RESPONSE_CODE_FLASH_INVALID_ADDR (3)
#define SBP_FLASH_DONE_RESPONSE_RESPONSE_CODE_FLASH_INVALID_RANGE (4)
#define SBP_FLASH_DONE_RESPONSE_RESPONSE_CODE_FLASH_INVALID_SECTOR (5)
typedef struct {
  
  /**
* Response flags
   */
    u8
  response
  ;
} sbp_msg_flash_done_t;


  /** Read STM or M25 flash address request (host => device).
   *
 * The flash read message reads a set of addresses of either the
 * STM or M25 onboard flash. The device replies with a
 * MSG_FLASH_READ_RESP message containing either the read data on
 * success or a MSG_FLASH_DONE message containing the return code
 * FLASH_INVALID_LEN (2) if the maximum read size is exceeded or
 * FLASH_INVALID_ADDR (3) if the address is outside of the allowed
 * range.
   */
#define SBP_MSG_FLASH_READ_REQ          0x00E7

	#define SBP_FLASH_READ_REQ_TARGET_FLASH_TARGET_TO_READ_MASK (0x1)
#define SBP_FLASH_READ_REQ_TARGET_FLASH_TARGET_TO_READ_SHIFT (0u)
#define SBP_FLASH_READ_REQ_TARGET_FLASH_TARGET_TO_READ_GET(flags) \
                             (((flags) >> SBP_FLASH_READ_REQ_TARGET_FLASH_TARGET_TO_READ_SHIFT) \
                             & SBP_FLASH_READ_REQ_TARGET_FLASH_TARGET_TO_READ_MASK)
#define SBP_FLASH_READ_REQ_TARGET_FLASH_TARGET_TO_READ_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_FLASH_READ_REQ_TARGET_FLASH_TARGET_TO_READ_MASK)) \
                             << (SBP_FLASH_READ_REQ_TARGET_FLASH_TARGET_TO_READ_SHIFT)));} while(0)
                             

#define SBP_FLASH_READ_REQ_TARGET_FLASH_TARGET_TO_READ_FLASH_STM (0)
#define SBP_FLASH_READ_REQ_TARGET_FLASH_TARGET_TO_READ_FLASH_M25 (1)
typedef struct {
  
  /**
* Target flags
   */
    u8
  target
  ;
  /**
* Starting address offset to read from[bytes]
   */
    u8
  addr_start
    [3]
  ;
  /**
 * Length of set of addresses to read, counting up from
 * starting address[bytes]
   */
    u8
  addr_len
  ;
} sbp_msg_flash_read_req_t;


  /** Read STM or M25 flash address response (host <= device).
   *
 * The flash read message reads a set of addresses of either the
 * STM or M25 onboard flash. The device replies with a
 * MSG_FLASH_READ_RESP message containing either the read data on
 * success or a MSG_FLASH_DONE message containing the return code
 * FLASH_INVALID_LEN (2) if the maximum read size is exceeded or
 * FLASH_INVALID_ADDR (3) if the address is outside of the allowed
 * range.
   */
#define SBP_MSG_FLASH_READ_RESP         0x00E1

	#define SBP_FLASH_READ_RESP_TARGET_FLASH_TARGET_TO_READ_MASK (0x1)
#define SBP_FLASH_READ_RESP_TARGET_FLASH_TARGET_TO_READ_SHIFT (0u)
#define SBP_FLASH_READ_RESP_TARGET_FLASH_TARGET_TO_READ_GET(flags) \
                             (((flags) >> SBP_FLASH_READ_RESP_TARGET_FLASH_TARGET_TO_READ_SHIFT) \
                             & SBP_FLASH_READ_RESP_TARGET_FLASH_TARGET_TO_READ_MASK)
#define SBP_FLASH_READ_RESP_TARGET_FLASH_TARGET_TO_READ_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_FLASH_READ_RESP_TARGET_FLASH_TARGET_TO_READ_MASK)) \
                             << (SBP_FLASH_READ_RESP_TARGET_FLASH_TARGET_TO_READ_SHIFT)));} while(0)
                             

#define SBP_FLASH_READ_RESP_TARGET_FLASH_TARGET_TO_READ_FLASH_STM (0)
#define SBP_FLASH_READ_RESP_TARGET_FLASH_TARGET_TO_READ_FLASH_M25 (1)
typedef struct {
  
  /**
* Target flags
   */
    u8
  target
  ;
  /**
* Starting address offset to read from[bytes]
   */
    u8
  addr_start
    [3]
  ;
  /**
 * Length of set of addresses to read, counting up from
 * starting address[bytes]
   */
    u8
  addr_len
  ;
} sbp_msg_flash_read_resp_t;


  /** Erase sector of device flash memory (host => device).
   *
 * The flash erase message from the host erases a sector of either
 * the STM or M25 onboard flash memory. The device will reply with a
 * MSG_FLASH_DONE message containing the return code - FLASH_OK (0)
 * on success or FLASH_INVALID_FLASH (1) if the flash specified is
 * invalid.
   */
#define SBP_MSG_FLASH_ERASE             0x00E2

	#define SBP_FLASH_ERASE_TARGET_FLASH_TARGET_TO_READ_MASK (0x1)
#define SBP_FLASH_ERASE_TARGET_FLASH_TARGET_TO_READ_SHIFT (0u)
#define SBP_FLASH_ERASE_TARGET_FLASH_TARGET_TO_READ_GET(flags) \
                             (((flags) >> SBP_FLASH_ERASE_TARGET_FLASH_TARGET_TO_READ_SHIFT) \
                             & SBP_FLASH_ERASE_TARGET_FLASH_TARGET_TO_READ_MASK)
#define SBP_FLASH_ERASE_TARGET_FLASH_TARGET_TO_READ_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_FLASH_ERASE_TARGET_FLASH_TARGET_TO_READ_MASK)) \
                             << (SBP_FLASH_ERASE_TARGET_FLASH_TARGET_TO_READ_SHIFT)));} while(0)
                             

#define SBP_FLASH_ERASE_TARGET_FLASH_TARGET_TO_READ_FLASH_STM (0)
#define SBP_FLASH_ERASE_TARGET_FLASH_TARGET_TO_READ_FLASH_M25 (1)
typedef struct {
  
  /**
* Target flags
   */
    u8
  target
  ;
  /**
 * Flash sector number to erase (0-11 for the STM, 0-15 for
 * the M25)
   */
    u32
  sector_num
  ;
} sbp_msg_flash_erase_t;


  /** Lock sector of STM flash memory (host => device)
   *
 * The flash lock message locks a sector of the STM flash
 * memory. The device replies with a MSG_FLASH_DONE message.
   */
#define SBP_MSG_STM_FLASH_LOCK_SECTOR   0x00E3

typedef struct {
  
  /**
* Flash sector number to lock
   */
    u32
  sector
  ;
} sbp_msg_stm_flash_lock_sector_t;


  /** Unlock sector of STM flash memory (host => device)
   *
 * The flash unlock message unlocks a sector of the STM flash
 * memory. The device replies with a MSG_FLASH_DONE message.
   */
#define SBP_MSG_STM_FLASH_UNLOCK_SECTOR 0x00E4

typedef struct {
  
  /**
* Flash sector number to unlock
   */
    u32
  sector
  ;
} sbp_msg_stm_flash_unlock_sector_t;


  /** Read device's hardcoded unique ID request (host => device)

   *
 * This message reads the device's hardcoded unique ID. The host
 * requests the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device
 * responds with a MSG_STM_UNIQUE_ID_RESP with the 12-byte unique
 * ID in the payload.
   */
#define SBP_MSG_STM_UNIQUE_ID_REQ       0x00E8

typedef struct {
  char dummy_to_avoid_empty_struct___do_not_use;
} sbp_msg_stm_unique_id_req_t;


  /** Read device's hardcoded unique ID response (host <= device)

   *
 * This message reads the device's hardcoded unique ID. The host
 * requests the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device
 * responds with a MSG_STM_UNIQUE_ID_RESP with the 12-byte unique
 * ID in the payload..
   */
#define SBP_MSG_STM_UNIQUE_ID_RESP      0x00E5

typedef struct {
  
  /**
* Device unique ID
   */
    u8
  stm_id
    [12]
  ;
} sbp_msg_stm_unique_id_resp_t;


  /** Write M25 flash status register (host => device)
   *
 * The flash status message writes to the 8-bit M25 flash status
 * register. The device replies with a MSG_FLASH_DONE message.
   */
#define SBP_MSG_M25_FLASH_WRITE_STATUS  0x00F3

typedef struct {
  
  /**
* Byte to write to the M25 flash status register
   */
    u8
  status
    [1]
  ;
} sbp_msg_m25_flash_write_status_t;



#include <libsbp/unpacked/flash_operators.h>
#include <libsbp/unpacked/flash_packers.h>

#endif /* LIBSBP_FLASH_MESSAGES_H */
