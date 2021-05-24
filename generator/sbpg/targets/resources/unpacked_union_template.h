#ifndef NEW_MESSAGES_UNION_H
#define NEW_MESSAGES_UNION_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

((*- for i in include *))
#include <libsbp/unpacked/(((i)))>
((*- endfor *))

#ifdef __cplusplus
  extern "C" {
#endif

struct sbp_state;

typedef union {
((*- for m in msgs *))
  (((m|convert_unpacked))) (((m|convert_unpacked_union)));
((*- endfor *))
} sbp_msg_t;

static inline s8 sbp_pack_msg(uint8_t *buf, uint8_t len, uint8_t *n_written, uint16_t msg_type, const sbp_msg_t *msg) {
  switch(msg_type) {
((*- for m in msgs *))
    case SBP_(((m))):
      return sbp_pack_(((m|convert_unpacked)))(buf, len, n_written, &msg->(((m|convert_unpacked_union))));
((*- endfor *))
    default:
      break;
  }
  return false;
}

static inline s8 sbp_unpack_msg(const uint8_t *buf, uint8_t len, uint8_t *n_read, uint16_t msg_type, sbp_msg_t *msg) {
  switch(msg_type) {
((*- for m in msgs *))
    case SBP_(((m))):
      return sbp_unpack_(((m|convert_unpacked)))(buf, len, n_read, &msg->(((m|convert_unpacked_union))));
((*- endfor *))
    default:
      break;
  }
  return false;
}

static inline size_t sbp_packed_size(uint16_t msg_type, const sbp_msg_t *msg) {
  switch(msg_type) {
((*- for m in msgs *))
    case SBP_(((m))):
      return sbp_packed_size_(((m|convert_unpacked)))(&msg->(((m|convert_unpacked_union))));
((*- endfor *))
    default:
      break;
  }
  return 0;
}

static inline int sbp_msg_cmp(uint16_t msg_type, const sbp_msg_t *a, const sbp_msg_t *b) {
  switch(msg_type) {
    ((*- for m in msgs *))
    case SBP_(((m))):
      return sbp_cmp_(((m|convert_unpacked)))(&a->(((m|convert_unpacked_union))), &b->(((m|convert_unpacked_union))));
    ((*- endfor *))
    default:
      break;
  }
  return false;
}

s8 sbp_pack_and_send_message(struct sbp_state *s, u16 msg_type, u16 sender_id, const sbp_msg_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

#ifdef __cplusplus
}
#endif

#endif

