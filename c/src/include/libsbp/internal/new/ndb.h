#ifndef LIBSBP_UNPACKED_NDB_PRIVATE_H
#define LIBSBP_UNPACKED_NDB_PRIVATE_H

#include <stdbool.h>

#include <libsbp/new/ndb.h>
#include <libsbp/internal/new/common.h>
#include <libsbp/internal/new/gnss.h>

#ifdef __cplusplus
  extern "C" {
#endif

bool pack_sbp_msg_ndb_event_t(sbp_pack_ctx_t *ctx, const sbp_msg_ndb_event_t *msg);
bool unpack_sbp_msg_ndb_event_t(sbp_unpack_ctx_t *ctx, sbp_msg_ndb_event_t *msg);

#ifdef __cplusplus
  }
#endif

#endif
