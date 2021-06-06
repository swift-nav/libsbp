#ifndef LIBSBP_UNPACKED_FLASH_PRIVATE_H
#define LIBSBP_UNPACKED_FLASH_PRIVATE_H

#include <stdbool.h>

#include <libsbp/new/flash.h>
#include <libsbp/internal/new/common.h>

#ifdef __cplusplus
  extern "C" {
#endif

bool pack_sbp_msg_flash_program_t(sbp_pack_ctx_t *ctx, const sbp_msg_flash_program_t *msg);
bool unpack_sbp_msg_flash_program_t(sbp_unpack_ctx_t *ctx, sbp_msg_flash_program_t *msg);

bool pack_sbp_msg_flash_done_t(sbp_pack_ctx_t *ctx, const sbp_msg_flash_done_t *msg);
bool unpack_sbp_msg_flash_done_t(sbp_unpack_ctx_t *ctx, sbp_msg_flash_done_t *msg);

bool pack_sbp_msg_flash_read_req_t(sbp_pack_ctx_t *ctx, const sbp_msg_flash_read_req_t *msg);
bool unpack_sbp_msg_flash_read_req_t(sbp_unpack_ctx_t *ctx, sbp_msg_flash_read_req_t *msg);

bool pack_sbp_msg_flash_read_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_flash_read_resp_t *msg);
bool unpack_sbp_msg_flash_read_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_flash_read_resp_t *msg);

bool pack_sbp_msg_flash_erase_t(sbp_pack_ctx_t *ctx, const sbp_msg_flash_erase_t *msg);
bool unpack_sbp_msg_flash_erase_t(sbp_unpack_ctx_t *ctx, sbp_msg_flash_erase_t *msg);

bool pack_sbp_msg_stm_flash_lock_sector_t(sbp_pack_ctx_t *ctx, const sbp_msg_stm_flash_lock_sector_t *msg);
bool unpack_sbp_msg_stm_flash_lock_sector_t(sbp_unpack_ctx_t *ctx, sbp_msg_stm_flash_lock_sector_t *msg);

bool pack_sbp_msg_stm_flash_unlock_sector_t(sbp_pack_ctx_t *ctx, const sbp_msg_stm_flash_unlock_sector_t *msg);
bool unpack_sbp_msg_stm_flash_unlock_sector_t(sbp_unpack_ctx_t *ctx, sbp_msg_stm_flash_unlock_sector_t *msg);

bool pack_sbp_msg_stm_unique_id_req_t(sbp_pack_ctx_t *ctx, const sbp_msg_stm_unique_id_req_t *msg);
bool unpack_sbp_msg_stm_unique_id_req_t(sbp_unpack_ctx_t *ctx, sbp_msg_stm_unique_id_req_t *msg);

bool pack_sbp_msg_stm_unique_id_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_stm_unique_id_resp_t *msg);
bool unpack_sbp_msg_stm_unique_id_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_stm_unique_id_resp_t *msg);

bool pack_sbp_msg_m25_flash_write_status_t(sbp_pack_ctx_t *ctx, const sbp_msg_m25_flash_write_status_t *msg);
bool unpack_sbp_msg_m25_flash_write_status_t(sbp_unpack_ctx_t *ctx, sbp_msg_m25_flash_write_status_t *msg);

#ifdef __cplusplus
  }
#endif

#endif
