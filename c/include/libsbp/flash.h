#ifndef LIBSBP_FLASH_MESSAGES_H
#define LIBSBP_FLASH_MESSAGES_H

#include <endian.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
/** Program flash addresses
 *
 * The flash program message programs a set of addresses of either
 * the STM or M25 flash. The device replies with either a
 * MSG_FLASH_DONE message containing the return code FLASH_OK (0)
 * on success, or FLASH_INVALID_LEN (2) if the maximum write size
 * is exceeded. Note that the sector-containing addresses must be
 * erased before addresses can be programmed.
 */
#define SBP_MSG_FLASH_PROGRAM 0x00E6

#define SBP_FLASH_PROGRAM_TARGET_FLASH_TARGET_TO_READ_MASK (0x1)
#define SBP_FLASH_PROGRAM_TARGET_FLASH_TARGET_TO_READ_SHIFT (0u)
#define SBP_FLASH_PROGRAM_TARGET_FLASH_TARGET_TO_READ_GET(flags)      \
  (((flags) >> SBP_FLASH_PROGRAM_TARGET_FLASH_TARGET_TO_READ_SHIFT) & \
   SBP_FLASH_PROGRAM_TARGET_FLASH_TARGET_TO_READ_MASK)
#define SBP_FLASH_PROGRAM_TARGET_FLASH_TARGET_TO_READ_SET(flags, val) \
  do {                                                                \
    ((flags) |=                                                       \
     (((val) & (SBP_FLASH_PROGRAM_TARGET_FLASH_TARGET_TO_READ_MASK))  \
      << (SBP_FLASH_PROGRAM_TARGET_FLASH_TARGET_TO_READ_SHIFT)));     \
  } while (0)

#define SBP_FLASH_PROGRAM_TARGET_FLASH_TARGET_TO_READ_FLASH_STM (0)
#define SBP_FLASH_PROGRAM_TARGET_FLASH_TARGET_TO_READ_FLASH_M25 (1)
typedef struct {
  /**
   * Target flags
   */
  u8 target;
  /**
   * Starting address offset to program[bytes]
   */
  u8 addr_start[3];
  /**
   * Length of set of addresses to program, counting up from
   * starting address[bytes]
   */
  u8 addr_len;
  /**
   * Data to program addresses with, with length N=addr_len
   */
  u8 data[250];
  /**
   * Number of items in data
   */
  u8 n_data;
} sbp_msg_flash_program_t;

static inline size_t sbp_packed_size_sbp_msg_flash_program_t(
    const sbp_msg_flash_program_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->target) + (3 * sizeof(msg->addr_start[0])) +
         sizeof(msg->addr_len) + (msg->n_data * sizeof(msg->data[0]));
}

static inline bool sbp_pack_sbp_msg_flash_program_t(
    u8 *buf, size_t len, const sbp_msg_flash_program_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_flash_program_t(msg) > len) {
    return false;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgtarget = msg->target;
  memcpy(buf + offset, &msgtarget, 1);
  offset += 1;
  for (size_t msgaddr_start_idx = 0; msgaddr_start_idx < 3;
       msgaddr_start_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    u8 msgaddr_startmsgaddr_start_idx = msg->addr_start[msgaddr_start_idx];
    memcpy(buf + offset, &msgaddr_startmsgaddr_start_idx, 1);
    offset += 1;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgaddr_len = msg->addr_len;
  memcpy(buf + offset, &msgaddr_len, 1);
  offset += 1;
  for (size_t msgdata_idx = 0; msgdata_idx < (size_t)msg->n_data;
       msgdata_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    u8 msgdatamsgdata_idx = msg->data[msgdata_idx];
    memcpy(buf + offset, &msgdatamsgdata_idx, 1);
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_flash_program_t(
    const u8 *buf, size_t len, sbp_msg_flash_program_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->target, buf + offset, 1);
  offset += 1;
  for (size_t msgaddr_start_idx = 0; msgaddr_start_idx < 3;
       msgaddr_start_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->addr_start[msgaddr_start_idx], buf + offset, 1);
    offset += 1;
  }

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->addr_len, buf + offset, 1);
  offset += 1;
  msg->n_data = (u8)((len - offset) / 1);

  for (size_t msgdata_idx = 0; msgdata_idx < msg->n_data; msgdata_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->data[msgdata_idx], buf + offset, 1);
    offset += 1;
  }
  return true;
}
/** Flash response message (host <= device).
 *
 * This message defines success or failure codes for a variety of
 * flash memory requests from the host to the device. Flash read
 * and write messages, such as MSG_FLASH_READ_REQ, or
 * MSG_FLASH_PROGRAM, may return this message on failure.
 */
#define SBP_MSG_FLASH_DONE 0x00E0

#define SBP_FLASH_DONE_RESPONSE_RESPONSE_CODE_MASK (0x7)
#define SBP_FLASH_DONE_RESPONSE_RESPONSE_CODE_SHIFT (0u)
#define SBP_FLASH_DONE_RESPONSE_RESPONSE_CODE_GET(flags)      \
  (((flags) >> SBP_FLASH_DONE_RESPONSE_RESPONSE_CODE_SHIFT) & \
   SBP_FLASH_DONE_RESPONSE_RESPONSE_CODE_MASK)
#define SBP_FLASH_DONE_RESPONSE_RESPONSE_CODE_SET(flags, val)           \
  do {                                                                  \
    ((flags) |= (((val) & (SBP_FLASH_DONE_RESPONSE_RESPONSE_CODE_MASK)) \
                 << (SBP_FLASH_DONE_RESPONSE_RESPONSE_CODE_SHIFT)));    \
  } while (0)

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
  u8 response;
} sbp_msg_flash_done_t;

static inline size_t sbp_packed_size_sbp_msg_flash_done_t(
    const sbp_msg_flash_done_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->response);
}

static inline bool sbp_pack_sbp_msg_flash_done_t(
    u8 *buf, size_t len, const sbp_msg_flash_done_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_flash_done_t(msg) > len) {
    return false;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgresponse = msg->response;
  memcpy(buf + offset, &msgresponse, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_flash_done_t(const u8 *buf, size_t len,
                                                   sbp_msg_flash_done_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->response, buf + offset, 1);
  offset += 1;
  return true;
}
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
#define SBP_MSG_FLASH_READ_REQ 0x00E7

#define SBP_FLASH_READ_REQ_TARGET_FLASH_TARGET_TO_READ_MASK (0x1)
#define SBP_FLASH_READ_REQ_TARGET_FLASH_TARGET_TO_READ_SHIFT (0u)
#define SBP_FLASH_READ_REQ_TARGET_FLASH_TARGET_TO_READ_GET(flags)      \
  (((flags) >> SBP_FLASH_READ_REQ_TARGET_FLASH_TARGET_TO_READ_SHIFT) & \
   SBP_FLASH_READ_REQ_TARGET_FLASH_TARGET_TO_READ_MASK)
#define SBP_FLASH_READ_REQ_TARGET_FLASH_TARGET_TO_READ_SET(flags, val) \
  do {                                                                 \
    ((flags) |=                                                        \
     (((val) & (SBP_FLASH_READ_REQ_TARGET_FLASH_TARGET_TO_READ_MASK))  \
      << (SBP_FLASH_READ_REQ_TARGET_FLASH_TARGET_TO_READ_SHIFT)));     \
  } while (0)

#define SBP_FLASH_READ_REQ_TARGET_FLASH_TARGET_TO_READ_FLASH_STM (0)
#define SBP_FLASH_READ_REQ_TARGET_FLASH_TARGET_TO_READ_FLASH_M25 (1)
typedef struct {
  /**
   * Target flags
   */
  u8 target;
  /**
   * Starting address offset to read from[bytes]
   */
  u8 addr_start[3];
  /**
   * Length of set of addresses to read, counting up from
   * starting address[bytes]
   */
  u8 addr_len;
} sbp_msg_flash_read_req_t;

static inline size_t sbp_packed_size_sbp_msg_flash_read_req_t(
    const sbp_msg_flash_read_req_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->target) + (3 * sizeof(msg->addr_start[0])) +
         sizeof(msg->addr_len);
}

static inline bool sbp_pack_sbp_msg_flash_read_req_t(
    u8 *buf, size_t len, const sbp_msg_flash_read_req_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_flash_read_req_t(msg) > len) {
    return false;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgtarget = msg->target;
  memcpy(buf + offset, &msgtarget, 1);
  offset += 1;
  for (size_t msgaddr_start_idx = 0; msgaddr_start_idx < 3;
       msgaddr_start_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    u8 msgaddr_startmsgaddr_start_idx = msg->addr_start[msgaddr_start_idx];
    memcpy(buf + offset, &msgaddr_startmsgaddr_start_idx, 1);
    offset += 1;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgaddr_len = msg->addr_len;
  memcpy(buf + offset, &msgaddr_len, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_flash_read_req_t(
    const u8 *buf, size_t len, sbp_msg_flash_read_req_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->target, buf + offset, 1);
  offset += 1;
  for (size_t msgaddr_start_idx = 0; msgaddr_start_idx < 3;
       msgaddr_start_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->addr_start[msgaddr_start_idx], buf + offset, 1);
    offset += 1;
  }

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->addr_len, buf + offset, 1);
  offset += 1;
  return true;
}
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
#define SBP_MSG_FLASH_READ_RESP 0x00E1

#define SBP_FLASH_READ_RESP_TARGET_FLASH_TARGET_TO_READ_MASK (0x1)
#define SBP_FLASH_READ_RESP_TARGET_FLASH_TARGET_TO_READ_SHIFT (0u)
#define SBP_FLASH_READ_RESP_TARGET_FLASH_TARGET_TO_READ_GET(flags)      \
  (((flags) >> SBP_FLASH_READ_RESP_TARGET_FLASH_TARGET_TO_READ_SHIFT) & \
   SBP_FLASH_READ_RESP_TARGET_FLASH_TARGET_TO_READ_MASK)
#define SBP_FLASH_READ_RESP_TARGET_FLASH_TARGET_TO_READ_SET(flags, val) \
  do {                                                                  \
    ((flags) |=                                                         \
     (((val) & (SBP_FLASH_READ_RESP_TARGET_FLASH_TARGET_TO_READ_MASK))  \
      << (SBP_FLASH_READ_RESP_TARGET_FLASH_TARGET_TO_READ_SHIFT)));     \
  } while (0)

#define SBP_FLASH_READ_RESP_TARGET_FLASH_TARGET_TO_READ_FLASH_STM (0)
#define SBP_FLASH_READ_RESP_TARGET_FLASH_TARGET_TO_READ_FLASH_M25 (1)
typedef struct {
  /**
   * Target flags
   */
  u8 target;
  /**
   * Starting address offset to read from[bytes]
   */
  u8 addr_start[3];
  /**
   * Length of set of addresses to read, counting up from
   * starting address[bytes]
   */
  u8 addr_len;
} sbp_msg_flash_read_resp_t;

static inline size_t sbp_packed_size_sbp_msg_flash_read_resp_t(
    const sbp_msg_flash_read_resp_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->target) + (3 * sizeof(msg->addr_start[0])) +
         sizeof(msg->addr_len);
}

static inline bool sbp_pack_sbp_msg_flash_read_resp_t(
    u8 *buf, size_t len, const sbp_msg_flash_read_resp_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_flash_read_resp_t(msg) > len) {
    return false;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgtarget = msg->target;
  memcpy(buf + offset, &msgtarget, 1);
  offset += 1;
  for (size_t msgaddr_start_idx = 0; msgaddr_start_idx < 3;
       msgaddr_start_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    u8 msgaddr_startmsgaddr_start_idx = msg->addr_start[msgaddr_start_idx];
    memcpy(buf + offset, &msgaddr_startmsgaddr_start_idx, 1);
    offset += 1;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgaddr_len = msg->addr_len;
  memcpy(buf + offset, &msgaddr_len, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_flash_read_resp_t(
    const u8 *buf, size_t len, sbp_msg_flash_read_resp_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->target, buf + offset, 1);
  offset += 1;
  for (size_t msgaddr_start_idx = 0; msgaddr_start_idx < 3;
       msgaddr_start_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->addr_start[msgaddr_start_idx], buf + offset, 1);
    offset += 1;
  }

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->addr_len, buf + offset, 1);
  offset += 1;
  return true;
}
/** Erase sector of device flash memory (host => device).
 *
 * The flash erase message from the host erases a sector of either
 * the STM or M25 onboard flash memory. The device will reply with a
 * MSG_FLASH_DONE message containing the return code - FLASH_OK (0)
 * on success or FLASH_INVALID_FLASH (1) if the flash specified is
 * invalid.
 */
#define SBP_MSG_FLASH_ERASE 0x00E2

#define SBP_FLASH_ERASE_TARGET_FLASH_TARGET_TO_READ_MASK (0x1)
#define SBP_FLASH_ERASE_TARGET_FLASH_TARGET_TO_READ_SHIFT (0u)
#define SBP_FLASH_ERASE_TARGET_FLASH_TARGET_TO_READ_GET(flags)      \
  (((flags) >> SBP_FLASH_ERASE_TARGET_FLASH_TARGET_TO_READ_SHIFT) & \
   SBP_FLASH_ERASE_TARGET_FLASH_TARGET_TO_READ_MASK)
#define SBP_FLASH_ERASE_TARGET_FLASH_TARGET_TO_READ_SET(flags, val)           \
  do {                                                                        \
    ((flags) |= (((val) & (SBP_FLASH_ERASE_TARGET_FLASH_TARGET_TO_READ_MASK)) \
                 << (SBP_FLASH_ERASE_TARGET_FLASH_TARGET_TO_READ_SHIFT)));    \
  } while (0)

#define SBP_FLASH_ERASE_TARGET_FLASH_TARGET_TO_READ_FLASH_STM (0)
#define SBP_FLASH_ERASE_TARGET_FLASH_TARGET_TO_READ_FLASH_M25 (1)
typedef struct {
  /**
   * Target flags
   */
  u8 target;
  /**
   * Flash sector number to erase (0-11 for the STM, 0-15 for
   * the M25)
   */
  u32 sector_num;
} sbp_msg_flash_erase_t;

static inline size_t sbp_packed_size_sbp_msg_flash_erase_t(
    const sbp_msg_flash_erase_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->target) + sizeof(msg->sector_num);
}

static inline bool sbp_pack_sbp_msg_flash_erase_t(
    u8 *buf, size_t len, const sbp_msg_flash_erase_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_flash_erase_t(msg) > len) {
    return false;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgtarget = msg->target;
  memcpy(buf + offset, &msgtarget, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgsector_num = msg->sector_num;
  msgsector_num = htole32(msgsector_num);
  memcpy(buf + offset, &msgsector_num, 4);
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_flash_erase_t(
    const u8 *buf, size_t len, sbp_msg_flash_erase_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->target, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->sector_num, buf + offset, 4);
  msg->sector_num = le32toh(msg->sector_num);
  offset += 4;
  return true;
}
/** Lock sector of STM flash memory (host => device)
 *
 * The flash lock message locks a sector of the STM flash
 * memory. The device replies with a MSG_FLASH_DONE message.
 */
#define SBP_MSG_STM_FLASH_LOCK_SECTOR 0x00E3

typedef struct {
  /**
   * Flash sector number to lock
   */
  u32 sector;
} sbp_msg_stm_flash_lock_sector_t;

static inline size_t sbp_packed_size_sbp_msg_stm_flash_lock_sector_t(
    const sbp_msg_stm_flash_lock_sector_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->sector);
}

static inline bool sbp_pack_sbp_msg_stm_flash_lock_sector_t(
    u8 *buf, size_t len, const sbp_msg_stm_flash_lock_sector_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_stm_flash_lock_sector_t(msg) > len) {
    return false;
  }

  if (offset + 4 > len) {
    return false;
  }
  u32 msgsector = msg->sector;
  msgsector = htole32(msgsector);
  memcpy(buf + offset, &msgsector, 4);
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_stm_flash_lock_sector_t(
    const u8 *buf, size_t len, sbp_msg_stm_flash_lock_sector_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->sector, buf + offset, 4);
  msg->sector = le32toh(msg->sector);
  offset += 4;
  return true;
}
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
  u32 sector;
} sbp_msg_stm_flash_unlock_sector_t;

static inline size_t sbp_packed_size_sbp_msg_stm_flash_unlock_sector_t(
    const sbp_msg_stm_flash_unlock_sector_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->sector);
}

static inline bool sbp_pack_sbp_msg_stm_flash_unlock_sector_t(
    u8 *buf, size_t len, const sbp_msg_stm_flash_unlock_sector_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_stm_flash_unlock_sector_t(msg) > len) {
    return false;
  }

  if (offset + 4 > len) {
    return false;
  }
  u32 msgsector = msg->sector;
  msgsector = htole32(msgsector);
  memcpy(buf + offset, &msgsector, 4);
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_stm_flash_unlock_sector_t(
    const u8 *buf, size_t len, sbp_msg_stm_flash_unlock_sector_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->sector, buf + offset, 4);
  msg->sector = le32toh(msg->sector);
  offset += 4;
  return true;
}
/** Read device's hardcoded unique ID request (host => device)

 *
* This message reads the device's hardcoded unique ID. The host
* requests the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device
* responds with a MSG_STM_UNIQUE_ID_RESP with the 12-byte unique
* ID in the payload.
 */
#define SBP_MSG_STM_UNIQUE_ID_REQ 0x00E8

typedef struct {
  char dummy_to_avoid_empty_struct___do_not_use;
} sbp_msg_stm_unique_id_req_t;

static inline size_t sbp_packed_size_sbp_msg_stm_unique_id_req_t(
    const sbp_msg_stm_unique_id_req_t *msg) {
  (void)msg;
  return 0;
}

static inline bool sbp_pack_sbp_msg_stm_unique_id_req_t(
    u8 *buf, size_t len, const sbp_msg_stm_unique_id_req_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_stm_unique_id_req_t(msg) > len) {
    return false;
  }

  return true;
}

static inline bool sbp_unpack_sbp_msg_stm_unique_id_req_t(
    const u8 *buf, size_t len, sbp_msg_stm_unique_id_req_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  return true;
}
/** Read device's hardcoded unique ID response (host <= device)

 *
* This message reads the device's hardcoded unique ID. The host
* requests the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device
* responds with a MSG_STM_UNIQUE_ID_RESP with the 12-byte unique
* ID in the payload..
 */
#define SBP_MSG_STM_UNIQUE_ID_RESP 0x00E5

typedef struct {
  /**
   * Device unique ID
   */
  u8 stm_id[12];
} sbp_msg_stm_unique_id_resp_t;

static inline size_t sbp_packed_size_sbp_msg_stm_unique_id_resp_t(
    const sbp_msg_stm_unique_id_resp_t *msg) {
  (void)msg;
  return 0 + (12 * sizeof(msg->stm_id[0]));
}

static inline bool sbp_pack_sbp_msg_stm_unique_id_resp_t(
    u8 *buf, size_t len, const sbp_msg_stm_unique_id_resp_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_stm_unique_id_resp_t(msg) > len) {
    return false;
  }

  for (size_t msgstm_id_idx = 0; msgstm_id_idx < 12; msgstm_id_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    u8 msgstm_idmsgstm_id_idx = msg->stm_id[msgstm_id_idx];
    memcpy(buf + offset, &msgstm_idmsgstm_id_idx, 1);
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_stm_unique_id_resp_t(
    const u8 *buf, size_t len, sbp_msg_stm_unique_id_resp_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  for (size_t msgstm_id_idx = 0; msgstm_id_idx < 12; msgstm_id_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->stm_id[msgstm_id_idx], buf + offset, 1);
    offset += 1;
  }
  return true;
}
/** Write M25 flash status register (host => device)
 *
 * The flash status message writes to the 8-bit M25 flash status
 * register. The device replies with a MSG_FLASH_DONE message.
 */
#define SBP_MSG_M25_FLASH_WRITE_STATUS 0x00F3

typedef struct {
  /**
   * Byte to write to the M25 flash status register
   */
  u8 status[1];
} sbp_msg_m25_flash_write_status_t;

static inline size_t sbp_packed_size_sbp_msg_m25_flash_write_status_t(
    const sbp_msg_m25_flash_write_status_t *msg) {
  (void)msg;
  return 0 + (1 * sizeof(msg->status[0]));
}

static inline bool sbp_pack_sbp_msg_m25_flash_write_status_t(
    u8 *buf, size_t len, const sbp_msg_m25_flash_write_status_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_m25_flash_write_status_t(msg) > len) {
    return false;
  }

  for (size_t msgstatus_idx = 0; msgstatus_idx < 1; msgstatus_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    u8 msgstatusmsgstatus_idx = msg->status[msgstatus_idx];
    memcpy(buf + offset, &msgstatusmsgstatus_idx, 1);
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_m25_flash_write_status_t(
    const u8 *buf, size_t len, sbp_msg_m25_flash_write_status_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  for (size_t msgstatus_idx = 0; msgstatus_idx < 1; msgstatus_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->status[msgstatus_idx], buf + offset, 1);
    offset += 1;
  }
  return true;
}

#endif /* LIBSBP_FLASH_MESSAGES_H */