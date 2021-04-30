#ifndef LIBSBP_USER_MESSAGES_H
#define LIBSBP_USER_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
/** User data
 *
 * This message can contain any application specific user data up to a
 * maximum length of 255 bytes per message.
 */
#define SBP_MSG_USER_DATA 0x0800

typedef struct
{

  /**
   * User data payload
   */
  u8 contents[255];
  /**
   * Number of items in contents
   */
  u8 n_contents;
} sbp_msg_user_data_t;

static inline size_t sbp_packed_size_sbp_msg_user_data_t(const sbp_msg_user_data_t *msg)
{
  (void)msg;
  return 0 + (msg->n_contents * sizeof(msg->contents[0]));
}

static inline bool sbp_pack_sbp_msg_user_data_t(u8 *buf, size_t len, const sbp_msg_user_data_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_user_data_t(msg) > len)
  {
    return false;
  }

  for (size_t msgcontents_idx = 0; msgcontents_idx < (size_t)msg->n_contents; msgcontents_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgcontentsmsgcontents_idx = msg->contents[msgcontents_idx];
    memcpy(buf + offset, &msgcontentsmsgcontents_idx, 1);
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_user_data_t(const u8 *buf, size_t len, sbp_msg_user_data_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  msg->n_contents = (u8)((len - offset) / 1);

  for (size_t msgcontents_idx = 0; msgcontents_idx < msg->n_contents; msgcontents_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->contents[msgcontents_idx], buf + offset, 1);
    offset += 1;
  }
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_user_data_t &a, const sbp_msg_user_data_t &b)
{
  (void)a;
  (void)b;

  if (a.n_contents != b.n_contents)
  {
    return false;
  }
  for (size_t contents_idx = 0; contents_idx < (size_t)a.n_contents; contents_idx++)
  {

    if (a.contents[contents_idx] != b.contents[contents_idx])
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_user_data_t &a, const sbp_msg_user_data_t &b)
{
  return !(a == b);
}
#endif

#endif /* LIBSBP_USER_MESSAGES_H */