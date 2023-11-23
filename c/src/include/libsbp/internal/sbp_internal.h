#ifndef LIBSBP_INTERNAL_SBP_INTERNAL_H
#define LIBSBP_INTERNAL_SBP_INTERNAL_H

#include <libsbp/sbp.h>

#ifdef __cplusplus
extern "C" {
#endif

s8 sbp_internal_forward_payload(sbp_state_t *s, sbp_msg_type_t msg_type,
                                u16 sender_id, u8 len, u8 *payload,
                                sbp_write_fn_t write);

#ifdef __cplusplus
}
#endif

#endif
