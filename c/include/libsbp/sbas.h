#ifndef LIBSBP_SBAS_MESSAGES_H
#define LIBSBP_SBAS_MESSAGES_H

#include <endian.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/gnss.h>
/** Raw SBAS data
 *
 * This message is sent once per second per SBAS satellite. ME checks the
 * parity of the data block and sends only blocks that pass the check.
 */
#define SBP_MSG_SBAS_RAW 0x7777

#define SBP_SBAS_RAW_SID_CODE__MASK (0xff)
#define SBP_SBAS_RAW_SID_CODE__SHIFT (0u)
#define SBP_SBAS_RAW_SID_CODE__GET(flags) \
  (((flags) >> SBP_SBAS_RAW_SID_CODE__SHIFT) & SBP_SBAS_RAW_SID_CODE__MASK)
#define SBP_SBAS_RAW_SID_CODE__SET(flags, val)           \
  do {                                                   \
    ((flags) |= (((val) & (SBP_SBAS_RAW_SID_CODE__MASK)) \
                 << (SBP_SBAS_RAW_SID_CODE__SHIFT)));    \
  } while (0)

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
  struct {
    /**
     * Constellation-specific satellite identifier. This field for Glonass can
     * either be (100+FCN) where FCN is in [-7,+6] or
     * the Slot ID in [1,28]
     */
    u8 sat;
    /**
     * Signal constellation, band and code
     */
    u8 code;
  } sid;
  /**
   * GPS time-of-week at the start of the data block.[ms]
   */
  u32 tow;
  /**
   * SBAS message type (0-63)
   */
  u8 message_type;
  /**
   * Raw SBAS data field of 212 bits (last byte padded with zeros).
   */
  u8 data[27];
} sbp_msg_sbas_raw_t;

static inline size_t sbp_packed_size_sbp_msg_sbas_raw_t(
    const sbp_msg_sbas_raw_t *msg) {
  (void)msg;
  return 0 + (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code)) +
         sizeof(msg->tow) + sizeof(msg->message_type) +
         (27 * sizeof(msg->data));
}

static inline bool sbp_pack_sbp_msg_sbas_raw_t(u8 *buf, size_t len,
                                               const sbp_msg_sbas_raw_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_sbas_raw_t(msg) > len) {
    return false;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgsidsat = msg->sid.sat;
  memcpy(buf + offset, &msgsidsat, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgtow = msg->tow;
  msgtow = htole32(msgtow);
  memcpy(buf + offset, &msgtow, 4);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgmessage_type = msg->message_type;
  memcpy(buf + offset, &msgmessage_type, 1);
  offset += 1;
  for (size_t msgdata_idx = 0; msgdata_idx < 27; msgdata_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    u8 msgdatamsgdata_idx = msg->data[msgdata_idx];
    memcpy(buf + offset, &msgdatamsgdata_idx, 1);
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_sbas_raw_t(const u8 *buf, size_t len,
                                                 sbp_msg_sbas_raw_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->sid.sat, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->tow, buf + offset, 4);
  msg->tow = le32toh(msg->tow);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->message_type, buf + offset, 1);
  offset += 1;
  for (size_t msgdata_idx = 0; msgdata_idx < 27; msgdata_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->data[msgdata_idx], buf + offset, 1);
    offset += 1;
  }
  return true;
}

#endif /* LIBSBP_SBAS_MESSAGES_H */