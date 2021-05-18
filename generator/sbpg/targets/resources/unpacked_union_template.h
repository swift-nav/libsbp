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

typedef union {
((*- for m in msgs *))
  (((m|convert_unpacked))) (((m)));
((*- endfor *))
} sbp_msg_t;

static inline s8 sbp_pack_msg(uint8_t *buf, uint8_t len, uint8_t *n_written, uint16_t msg_type, const sbp_msg_t *msg) {
  switch(msg_type) {
((*- for m in msgs *))
    case SBP_(((m.ljust(max_msgid_len)))):
      return sbp_pack_(((m|convert_unpacked)))(buf, len, n_written, &msg->(((m))));
((*- endfor *))
    default:
      break;
  }
  return false;
}

static inline s8 sbp_unpack_msg(const uint8_t *buf, uint8_t len, uint8_t *n_read, uint16_t msg_type, sbp_msg_t *msg) {
  switch(msg_type) {
((*- for m in msgs *))
    case SBP_(((m.ljust(max_msgid_len)))):
      return sbp_unpack_(((m|convert_unpacked)))(buf, len, n_read, &msg->(((m))));
((*- endfor *))
    default:
      break;
  }
  return false;
}

static inline size_t sbp_packed_size(uint16_t msg_type, const sbp_msg_t *msg) {
  switch(msg_type) {
((*- for m in msgs *))
    case SBP_(((m.ljust(max_msgid_len)))):
      return sbp_packed_size_(((m|convert_unpacked)))(&msg->(((m))));
((*- endfor *))
    default:
      break;
  }
  return 0;
}

static inline int sbp_msg_cmp(uint16_t msg_type, const sbp_msg_t *a, const sbp_msg_t *b) {
  switch(msg_type) {
    ((*- for m in msgs *))
    case SBP_(((m.ljust(max_msgid_len)))):
      return sbp_cmp_(((m|convert_unpacked)))(&a->(((m))), &b->(((m))));
    ((*- endfor *))
    default:
      break;
  }
  return false;
}

#ifdef __cplusplus
}
#endif

#endif

