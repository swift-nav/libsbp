#ifndef LIBSBP_USER_MESSAGES_H
#define LIBSBP_USER_MESSAGES_H

#include "common.h"

SBP_PACK_START
/** User data
 *
 * This message can contain any application specific user data up to a
 * maximum length of 255 bytes per message.
 */
#define SBP_MSG_USER_DATA 0x0800

typedef struct SBP_ATTR_PACKED {
  /**
   * User data payload
   */
  u8 contents[255];
} sbp_msg_user_data_t;

SBP_PACK_END

#endif /* LIBSBP_USER_MESSAGES_H */