#ifndef LIBSBP_USER_MESSAGES_H
#define LIBSBP_USER_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>
/** User data
 *
((m.desc|commentify)))
 */
#define SBP_MSG_USER_DATA 0x0800
typedef struct {
  u8 contents[255];
  u8 n_contents;
} sbp_msg_user_data_t;



#include <libsbp/unpacked/user_operators.h>
#include <libsbp/unpacked/user_packers.h>

#endif /* LIBSBP_USER_MESSAGES_H */
