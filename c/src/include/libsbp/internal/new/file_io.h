#ifndef LIBSBP_UNPACKED_FILE_IO_PRIVATE_H
#define LIBSBP_UNPACKED_FILE_IO_PRIVATE_H

#include <stdbool.h>

#include <libsbp/new/file_io.h>
#include <libsbp/internal/new/common.h>

#ifdef __cplusplus
  extern "C" {
#endif

bool pack_sbp_msg_fileio_read_req_t(sbp_pack_ctx_t *ctx, const sbp_msg_fileio_read_req_t *msg);
bool unpack_sbp_msg_fileio_read_req_t(sbp_unpack_ctx_t *ctx, sbp_msg_fileio_read_req_t *msg);

bool pack_sbp_msg_fileio_read_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_fileio_read_resp_t *msg);
bool unpack_sbp_msg_fileio_read_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_fileio_read_resp_t *msg);

bool pack_sbp_msg_fileio_read_dir_req_t(sbp_pack_ctx_t *ctx, const sbp_msg_fileio_read_dir_req_t *msg);
bool unpack_sbp_msg_fileio_read_dir_req_t(sbp_unpack_ctx_t *ctx, sbp_msg_fileio_read_dir_req_t *msg);

bool pack_sbp_msg_fileio_read_dir_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_fileio_read_dir_resp_t *msg);
bool unpack_sbp_msg_fileio_read_dir_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_fileio_read_dir_resp_t *msg);

bool pack_sbp_msg_fileio_remove_t(sbp_pack_ctx_t *ctx, const sbp_msg_fileio_remove_t *msg);
bool unpack_sbp_msg_fileio_remove_t(sbp_unpack_ctx_t *ctx, sbp_msg_fileio_remove_t *msg);

bool pack_sbp_msg_fileio_write_req_t(sbp_pack_ctx_t *ctx, const sbp_msg_fileio_write_req_t *msg);
bool unpack_sbp_msg_fileio_write_req_t(sbp_unpack_ctx_t *ctx, sbp_msg_fileio_write_req_t *msg);

bool pack_sbp_msg_fileio_write_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_fileio_write_resp_t *msg);
bool unpack_sbp_msg_fileio_write_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_fileio_write_resp_t *msg);

bool pack_sbp_msg_fileio_config_req_t(sbp_pack_ctx_t *ctx, const sbp_msg_fileio_config_req_t *msg);
bool unpack_sbp_msg_fileio_config_req_t(sbp_unpack_ctx_t *ctx, sbp_msg_fileio_config_req_t *msg);

bool pack_sbp_msg_fileio_config_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_fileio_config_resp_t *msg);
bool unpack_sbp_msg_fileio_config_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_fileio_config_resp_t *msg);

#ifdef __cplusplus
  }
#endif

#endif
