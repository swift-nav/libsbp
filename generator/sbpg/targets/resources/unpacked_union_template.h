#ifndef NEW_MESSAGES_UNION_H
#define NEW_MESSAGES_UNION_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

((*- for i in include *))
#include <libsbp/(((i)))>
((*- endfor *))

typedef struct {
  u16 type;
  union {
((*- for m in msgs *))
  (((m|convert_unpacked))) (((m)));
((*- endfor *))
  };
} sbp_msg_t;

static inline bool sbp_pack_msg(uint8_t *buf, size_t len, const sbp_msg_t *msg) {
  switch(msg->type) {
((*- for m in msgs *))
    case SBP_(((m.ljust(max_msgid_len)))):
      return sbp_pack_(((m|convert_unpacked)))(buf, len, &msg->(((m))));
((*- endfor *))
    default:
      break;
  }
  return false;
}

static inline bool sbp_unpack_msg(const uint8_t *buf, size_t len, sbp_msg_t *msg) {
  switch(msg->type) {
((*- for m in msgs *))
    case SBP_(((m.ljust(max_msgid_len)))):
      return sbp_unpack_(((m|convert_unpacked)))(buf, len, &msg->(((m))));
((*- endfor *))
    default:
      break;
  }
  return false;
}

static inline size_t sbp_packed_size(const sbp_msg_t *msg) {
  switch(msg->type) {
((*- for m in msgs *))
    case SBP_(((m.ljust(max_msgid_len)))):
      return sbp_packed_size_(((m|convert_unpacked)))(&msg->(((m))));
((*- endfor *))
    default:
      break;
  }
  return 0;
}

#endif

