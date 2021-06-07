/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/flash.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_NEW_FLASH_MESSAGES_H
#define LIBSBP_NEW_FLASH_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/flash_macros.h>
#include <libsbp/new/string/double_null_terminated.h>
#include <libsbp/new/string/multipart.h>
#include <libsbp/new/string/null_terminated.h>
#include <libsbp/new/string/unterminated.h>

#ifdef __cplusplus
extern "C" {
#endif

struct sbp_state;

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_FLASH_PROGRAM
 *
 *****************************************************************************/
/** Program flash addresses
 *
 * The flash program message programs a set of addresses of either the STM or
 * M25 flash. The device replies with either a MSG_FLASH_DONE message containing
 * the return code FLASH_OK (0) on success, or FLASH_INVALID_LEN (2) if the
 * maximum write size is exceeded. Note that the sector-containing addresses
 * must be erased before addresses can be programmed.
 */
typedef struct {
  /**
   * Target flags
   */
  u8 target;

  /**
   * Starting address offset to program [bytes]
   */
  u8 addr_start[3];

  /**
   * Length of set of addresses to program, counting up from starting address
   * [bytes]
   */
  u8 addr_len;

  /**
   * Data to program addresses with, with length N=addr_len
   */
  u8 data[250];
} sbp_msg_flash_program_t;

/**
 * Get encoded size of an instance of sbp_msg_flash_program_t
 *
 * @param msg sbp_msg_flash_program_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_flash_program_t(
    const sbp_msg_flash_program_t *msg);

/**
 * Encode an instance of sbp_msg_flash_program_t to wire representation
 *
 * This function encodes the given instance in to the user provided buffer. The
 * buffer provided to this function must be large enough to store the encoded
 * message otherwise it will return SBP_ENCODE_ERROR without writing anything to
 * the buffer.
 *
 * Specify the length of the destination buffer in the \p len parameter. If
 * non-null the number of bytes written to the buffer will be returned in \p
 * n_written.
 *
 * @param buf Destination buffer
 * @param len Length of \p buf
 * @param n_written If not null, on success will be set to the number of bytes
 * written to \p buf
 * @param msg Instance of sbp_msg_flash_program_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_flash_program_t(uint8_t *buf, uint8_t len,
                                      uint8_t *n_written,
                                      const sbp_msg_flash_program_t *msg);

/**
 * Decode an instance of sbp_msg_flash_program_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_flash_program_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_flash_program_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_flash_program_t(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_flash_program_t *msg);
/**
 * Send an instance of sbp_msg_flash_program_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_flash_program_t
 *
 * The given message will be encoded to wire representation and passed in to the
 * given write function callback. The write callback will be called several
 * times for each invocation of this function.
 *
 * @param s SBP state
 * @param sender_id SBP sender id
 * @param msg Message to send
 * @param write Write function
 * @param SBP_OK on success, or other libsbp error code
 */
s8 sbp_send_sbp_msg_flash_program_t(struct sbp_state *s, u16 sender_id,
                                    const sbp_msg_flash_program_t *msg,
                                    s32 (*write)(u8 *buff, u32 n,
                                                 void *context));

/**
 * Compare two instances of sbp_msg_flash_program_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_flash_program_t instance
 * @param b sbp_msg_flash_program_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_flash_program_t(const sbp_msg_flash_program_t *a,
                                    const sbp_msg_flash_program_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_FLASH_DONE
 *
 *****************************************************************************/
/** Flash response message (host <= device)
 *
 * This message defines success or failure codes for a variety of flash memory
 * requests from the host to the device. Flash read and write messages, such as
 * MSG_FLASH_READ_REQ, or MSG_FLASH_PROGRAM, may return this message on failure.
 */
typedef struct {
  /**
   * Response flags
   */
  u8 response;
} sbp_msg_flash_done_t;

/**
 * Get encoded size of an instance of sbp_msg_flash_done_t
 *
 * @param msg sbp_msg_flash_done_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_flash_done_t(const sbp_msg_flash_done_t *msg);

/**
 * Encode an instance of sbp_msg_flash_done_t to wire representation
 *
 * This function encodes the given instance in to the user provided buffer. The
 * buffer provided to this function must be large enough to store the encoded
 * message otherwise it will return SBP_ENCODE_ERROR without writing anything to
 * the buffer.
 *
 * Specify the length of the destination buffer in the \p len parameter. If
 * non-null the number of bytes written to the buffer will be returned in \p
 * n_written.
 *
 * @param buf Destination buffer
 * @param len Length of \p buf
 * @param n_written If not null, on success will be set to the number of bytes
 * written to \p buf
 * @param msg Instance of sbp_msg_flash_done_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_flash_done_t(uint8_t *buf, uint8_t len,
                                   uint8_t *n_written,
                                   const sbp_msg_flash_done_t *msg);

/**
 * Decode an instance of sbp_msg_flash_done_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_flash_done_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_flash_done_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_flash_done_t(const uint8_t *buf, uint8_t len,
                                   uint8_t *n_read, sbp_msg_flash_done_t *msg);
/**
 * Send an instance of sbp_msg_flash_done_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_flash_done_t
 *
 * The given message will be encoded to wire representation and passed in to the
 * given write function callback. The write callback will be called several
 * times for each invocation of this function.
 *
 * @param s SBP state
 * @param sender_id SBP sender id
 * @param msg Message to send
 * @param write Write function
 * @param SBP_OK on success, or other libsbp error code
 */
s8 sbp_send_sbp_msg_flash_done_t(struct sbp_state *s, u16 sender_id,
                                 const sbp_msg_flash_done_t *msg,
                                 s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_flash_done_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_flash_done_t instance
 * @param b sbp_msg_flash_done_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_flash_done_t(const sbp_msg_flash_done_t *a,
                                 const sbp_msg_flash_done_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_FLASH_READ_REQ
 *
 *****************************************************************************/
/** Read STM or M25 flash address request (host => device)
 *
 * The flash read message reads a set of addresses of either the STM or M25
 * onboard flash. The device replies with a MSG_FLASH_READ_RESP message
 * containing either the read data on success or a MSG_FLASH_DONE message
 * containing the return code FLASH_INVALID_LEN (2) if the maximum read size is
 * exceeded or FLASH_INVALID_ADDR (3) if the address is outside of the allowed
 * range.
 */
typedef struct {
  /**
   * Target flags
   */
  u8 target;

  /**
   * Starting address offset to read from [bytes]
   */
  u8 addr_start[3];

  /**
   * Length of set of addresses to read, counting up from starting address
   * [bytes]
   */
  u8 addr_len;
} sbp_msg_flash_read_req_t;

/**
 * Get encoded size of an instance of sbp_msg_flash_read_req_t
 *
 * @param msg sbp_msg_flash_read_req_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_flash_read_req_t(
    const sbp_msg_flash_read_req_t *msg);

/**
 * Encode an instance of sbp_msg_flash_read_req_t to wire representation
 *
 * This function encodes the given instance in to the user provided buffer. The
 * buffer provided to this function must be large enough to store the encoded
 * message otherwise it will return SBP_ENCODE_ERROR without writing anything to
 * the buffer.
 *
 * Specify the length of the destination buffer in the \p len parameter. If
 * non-null the number of bytes written to the buffer will be returned in \p
 * n_written.
 *
 * @param buf Destination buffer
 * @param len Length of \p buf
 * @param n_written If not null, on success will be set to the number of bytes
 * written to \p buf
 * @param msg Instance of sbp_msg_flash_read_req_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_flash_read_req_t(uint8_t *buf, uint8_t len,
                                       uint8_t *n_written,
                                       const sbp_msg_flash_read_req_t *msg);

/**
 * Decode an instance of sbp_msg_flash_read_req_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_flash_read_req_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_flash_read_req_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_flash_read_req_t(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_msg_flash_read_req_t *msg);
/**
 * Send an instance of sbp_msg_flash_read_req_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_flash_read_req_t
 *
 * The given message will be encoded to wire representation and passed in to the
 * given write function callback. The write callback will be called several
 * times for each invocation of this function.
 *
 * @param s SBP state
 * @param sender_id SBP sender id
 * @param msg Message to send
 * @param write Write function
 * @param SBP_OK on success, or other libsbp error code
 */
s8 sbp_send_sbp_msg_flash_read_req_t(struct sbp_state *s, u16 sender_id,
                                     const sbp_msg_flash_read_req_t *msg,
                                     s32 (*write)(u8 *buff, u32 n,
                                                  void *context));

/**
 * Compare two instances of sbp_msg_flash_read_req_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_flash_read_req_t instance
 * @param b sbp_msg_flash_read_req_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_flash_read_req_t(const sbp_msg_flash_read_req_t *a,
                                     const sbp_msg_flash_read_req_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_FLASH_READ_RESP
 *
 *****************************************************************************/
/** Read STM or M25 flash address response (host <= device)
 *
 * The flash read message reads a set of addresses of either the STM or M25
 * onboard flash. The device replies with a MSG_FLASH_READ_RESP message
 * containing either the read data on success or a MSG_FLASH_DONE message
 * containing the return code FLASH_INVALID_LEN (2) if the maximum read size is
 * exceeded or FLASH_INVALID_ADDR (3) if the address is outside of the allowed
 * range.
 */
typedef struct {
  /**
   * Target flags
   */
  u8 target;

  /**
   * Starting address offset to read from [bytes]
   */
  u8 addr_start[3];

  /**
   * Length of set of addresses to read, counting up from starting address
   * [bytes]
   */
  u8 addr_len;
} sbp_msg_flash_read_resp_t;

/**
 * Get encoded size of an instance of sbp_msg_flash_read_resp_t
 *
 * @param msg sbp_msg_flash_read_resp_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_flash_read_resp_t(
    const sbp_msg_flash_read_resp_t *msg);

/**
 * Encode an instance of sbp_msg_flash_read_resp_t to wire representation
 *
 * This function encodes the given instance in to the user provided buffer. The
 * buffer provided to this function must be large enough to store the encoded
 * message otherwise it will return SBP_ENCODE_ERROR without writing anything to
 * the buffer.
 *
 * Specify the length of the destination buffer in the \p len parameter. If
 * non-null the number of bytes written to the buffer will be returned in \p
 * n_written.
 *
 * @param buf Destination buffer
 * @param len Length of \p buf
 * @param n_written If not null, on success will be set to the number of bytes
 * written to \p buf
 * @param msg Instance of sbp_msg_flash_read_resp_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_flash_read_resp_t(uint8_t *buf, uint8_t len,
                                        uint8_t *n_written,
                                        const sbp_msg_flash_read_resp_t *msg);

/**
 * Decode an instance of sbp_msg_flash_read_resp_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_flash_read_resp_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_flash_read_resp_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_flash_read_resp_t(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_flash_read_resp_t *msg);
/**
 * Send an instance of sbp_msg_flash_read_resp_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_flash_read_resp_t
 *
 * The given message will be encoded to wire representation and passed in to the
 * given write function callback. The write callback will be called several
 * times for each invocation of this function.
 *
 * @param s SBP state
 * @param sender_id SBP sender id
 * @param msg Message to send
 * @param write Write function
 * @param SBP_OK on success, or other libsbp error code
 */
s8 sbp_send_sbp_msg_flash_read_resp_t(struct sbp_state *s, u16 sender_id,
                                      const sbp_msg_flash_read_resp_t *msg,
                                      s32 (*write)(u8 *buff, u32 n,
                                                   void *context));

/**
 * Compare two instances of sbp_msg_flash_read_resp_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_flash_read_resp_t instance
 * @param b sbp_msg_flash_read_resp_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_flash_read_resp_t(const sbp_msg_flash_read_resp_t *a,
                                      const sbp_msg_flash_read_resp_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_FLASH_ERASE
 *
 *****************************************************************************/
/** Erase sector of device flash memory (host => device)
 *
 * The flash erase message from the host erases a sector of either the STM or
 * M25 onboard flash memory. The device will reply with a MSG_FLASH_DONE message
 * containing the return code - FLASH_OK (0) on success or FLASH_INVALID_FLASH
 * (1) if the flash specified is invalid.
 */
typedef struct {
  /**
   * Target flags
   */
  u8 target;

  /**
   * Flash sector number to erase (0-11 for the STM, 0-15 for the M25)
   */
  u32 sector_num;
} sbp_msg_flash_erase_t;

/**
 * Get encoded size of an instance of sbp_msg_flash_erase_t
 *
 * @param msg sbp_msg_flash_erase_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_flash_erase_t(const sbp_msg_flash_erase_t *msg);

/**
 * Encode an instance of sbp_msg_flash_erase_t to wire representation
 *
 * This function encodes the given instance in to the user provided buffer. The
 * buffer provided to this function must be large enough to store the encoded
 * message otherwise it will return SBP_ENCODE_ERROR without writing anything to
 * the buffer.
 *
 * Specify the length of the destination buffer in the \p len parameter. If
 * non-null the number of bytes written to the buffer will be returned in \p
 * n_written.
 *
 * @param buf Destination buffer
 * @param len Length of \p buf
 * @param n_written If not null, on success will be set to the number of bytes
 * written to \p buf
 * @param msg Instance of sbp_msg_flash_erase_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_flash_erase_t(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_msg_flash_erase_t *msg);

/**
 * Decode an instance of sbp_msg_flash_erase_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_flash_erase_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_flash_erase_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_flash_erase_t(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_msg_flash_erase_t *msg);
/**
 * Send an instance of sbp_msg_flash_erase_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_flash_erase_t
 *
 * The given message will be encoded to wire representation and passed in to the
 * given write function callback. The write callback will be called several
 * times for each invocation of this function.
 *
 * @param s SBP state
 * @param sender_id SBP sender id
 * @param msg Message to send
 * @param write Write function
 * @param SBP_OK on success, or other libsbp error code
 */
s8 sbp_send_sbp_msg_flash_erase_t(struct sbp_state *s, u16 sender_id,
                                  const sbp_msg_flash_erase_t *msg,
                                  s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_flash_erase_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_flash_erase_t instance
 * @param b sbp_msg_flash_erase_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_flash_erase_t(const sbp_msg_flash_erase_t *a,
                                  const sbp_msg_flash_erase_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_STM_FLASH_LOCK_SECTOR
 *
 *****************************************************************************/
/** Lock sector of STM flash memory (host => device)
 *
 * The flash lock message locks a sector of the STM flash memory. The device
 * replies with a MSG_FLASH_DONE message.
 */
typedef struct {
  /**
   * Flash sector number to lock
   */
  u32 sector;
} sbp_msg_stm_flash_lock_sector_t;

/**
 * Get encoded size of an instance of sbp_msg_stm_flash_lock_sector_t
 *
 * @param msg sbp_msg_stm_flash_lock_sector_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_stm_flash_lock_sector_t(
    const sbp_msg_stm_flash_lock_sector_t *msg);

/**
 * Encode an instance of sbp_msg_stm_flash_lock_sector_t to wire representation
 *
 * This function encodes the given instance in to the user provided buffer. The
 * buffer provided to this function must be large enough to store the encoded
 * message otherwise it will return SBP_ENCODE_ERROR without writing anything to
 * the buffer.
 *
 * Specify the length of the destination buffer in the \p len parameter. If
 * non-null the number of bytes written to the buffer will be returned in \p
 * n_written.
 *
 * @param buf Destination buffer
 * @param len Length of \p buf
 * @param n_written If not null, on success will be set to the number of bytes
 * written to \p buf
 * @param msg Instance of sbp_msg_stm_flash_lock_sector_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_stm_flash_lock_sector_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_stm_flash_lock_sector_t *msg);

/**
 * Decode an instance of sbp_msg_stm_flash_lock_sector_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_stm_flash_lock_sector_t message to the given instance. The caller
 * must specify the length of the buffer in the \p len parameter. If non-null
 * the number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_stm_flash_lock_sector_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_stm_flash_lock_sector_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_stm_flash_lock_sector_t *msg);
/**
 * Send an instance of sbp_msg_stm_flash_lock_sector_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_stm_flash_lock_sector_t
 *
 * The given message will be encoded to wire representation and passed in to the
 * given write function callback. The write callback will be called several
 * times for each invocation of this function.
 *
 * @param s SBP state
 * @param sender_id SBP sender id
 * @param msg Message to send
 * @param write Write function
 * @param SBP_OK on success, or other libsbp error code
 */
s8 sbp_send_sbp_msg_stm_flash_lock_sector_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_stm_flash_lock_sector_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_stm_flash_lock_sector_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_stm_flash_lock_sector_t instance
 * @param b sbp_msg_stm_flash_lock_sector_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_stm_flash_lock_sector_t(
    const sbp_msg_stm_flash_lock_sector_t *a,
    const sbp_msg_stm_flash_lock_sector_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_STM_FLASH_UNLOCK_SECTOR
 *
 *****************************************************************************/
/** Unlock sector of STM flash memory (host => device)
 *
 * The flash unlock message unlocks a sector of the STM flash memory. The device
 * replies with a MSG_FLASH_DONE message.
 */
typedef struct {
  /**
   * Flash sector number to unlock
   */
  u32 sector;
} sbp_msg_stm_flash_unlock_sector_t;

/**
 * Get encoded size of an instance of sbp_msg_stm_flash_unlock_sector_t
 *
 * @param msg sbp_msg_stm_flash_unlock_sector_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_stm_flash_unlock_sector_t(
    const sbp_msg_stm_flash_unlock_sector_t *msg);

/**
 * Encode an instance of sbp_msg_stm_flash_unlock_sector_t to wire
 * representation
 *
 * This function encodes the given instance in to the user provided buffer. The
 * buffer provided to this function must be large enough to store the encoded
 * message otherwise it will return SBP_ENCODE_ERROR without writing anything to
 * the buffer.
 *
 * Specify the length of the destination buffer in the \p len parameter. If
 * non-null the number of bytes written to the buffer will be returned in \p
 * n_written.
 *
 * @param buf Destination buffer
 * @param len Length of \p buf
 * @param n_written If not null, on success will be set to the number of bytes
 * written to \p buf
 * @param msg Instance of sbp_msg_stm_flash_unlock_sector_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_stm_flash_unlock_sector_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_stm_flash_unlock_sector_t *msg);

/**
 * Decode an instance of sbp_msg_stm_flash_unlock_sector_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_stm_flash_unlock_sector_t message to the given instance. The caller
 * must specify the length of the buffer in the \p len parameter. If non-null
 * the number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_stm_flash_unlock_sector_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_stm_flash_unlock_sector_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_stm_flash_unlock_sector_t *msg);
/**
 * Send an instance of sbp_msg_stm_flash_unlock_sector_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_stm_flash_unlock_sector_t
 *
 * The given message will be encoded to wire representation and passed in to the
 * given write function callback. The write callback will be called several
 * times for each invocation of this function.
 *
 * @param s SBP state
 * @param sender_id SBP sender id
 * @param msg Message to send
 * @param write Write function
 * @param SBP_OK on success, or other libsbp error code
 */
s8 sbp_send_sbp_msg_stm_flash_unlock_sector_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_stm_flash_unlock_sector_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_stm_flash_unlock_sector_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_stm_flash_unlock_sector_t instance
 * @param b sbp_msg_stm_flash_unlock_sector_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_stm_flash_unlock_sector_t(
    const sbp_msg_stm_flash_unlock_sector_t *a,
    const sbp_msg_stm_flash_unlock_sector_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_STM_UNIQUE_ID_REQ
 *
 *****************************************************************************/
/** Read device's hardcoded unique ID request (host => device)

 *
* This message reads the device's hardcoded unique ID. The host requests the ID
by sending a MSG_STM_UNIQUE_ID_REQ. The device responds with a
MSG_STM_UNIQUE_ID_RESP with the 12-byte unique ID in the payload.
 */
typedef struct {
  /**
   * Do not use this field, it exists only to prevent illegal C syntax. Any
   * value written to this field will be ignored
   */
  char DO_NOT_USE_dummy_field_to_prevent_empty_struct;
} sbp_msg_stm_unique_id_req_t;

/**
 * Get encoded size of an instance of sbp_msg_stm_unique_id_req_t
 *
 * @param msg sbp_msg_stm_unique_id_req_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_stm_unique_id_req_t(
    const sbp_msg_stm_unique_id_req_t *msg);

/**
 * Encode an instance of sbp_msg_stm_unique_id_req_t to wire representation
 *
 * This function encodes the given instance in to the user provided buffer. The
 * buffer provided to this function must be large enough to store the encoded
 * message otherwise it will return SBP_ENCODE_ERROR without writing anything to
 * the buffer.
 *
 * Specify the length of the destination buffer in the \p len parameter. If
 * non-null the number of bytes written to the buffer will be returned in \p
 * n_written.
 *
 * @param buf Destination buffer
 * @param len Length of \p buf
 * @param n_written If not null, on success will be set to the number of bytes
 * written to \p buf
 * @param msg Instance of sbp_msg_stm_unique_id_req_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_stm_unique_id_req_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_stm_unique_id_req_t *msg);

/**
 * Decode an instance of sbp_msg_stm_unique_id_req_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_stm_unique_id_req_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_stm_unique_id_req_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_stm_unique_id_req_t(const uint8_t *buf, uint8_t len,
                                          uint8_t *n_read,
                                          sbp_msg_stm_unique_id_req_t *msg);
/**
 * Send an instance of sbp_msg_stm_unique_id_req_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_stm_unique_id_req_t
 *
 * The given message will be encoded to wire representation and passed in to the
 * given write function callback. The write callback will be called several
 * times for each invocation of this function.
 *
 * @param s SBP state
 * @param sender_id SBP sender id
 * @param msg Message to send
 * @param write Write function
 * @param SBP_OK on success, or other libsbp error code
 */
s8 sbp_send_sbp_msg_stm_unique_id_req_t(struct sbp_state *s, u16 sender_id,
                                        const sbp_msg_stm_unique_id_req_t *msg,
                                        s32 (*write)(u8 *buff, u32 n,
                                                     void *context));

/**
 * Compare two instances of sbp_msg_stm_unique_id_req_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_stm_unique_id_req_t instance
 * @param b sbp_msg_stm_unique_id_req_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_stm_unique_id_req_t(const sbp_msg_stm_unique_id_req_t *a,
                                        const sbp_msg_stm_unique_id_req_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_STM_UNIQUE_ID_RESP
 *
 *****************************************************************************/
/** Read device's hardcoded unique ID response (host <= device)

 *
* This message reads the device's hardcoded unique ID. The host requests the ID
by sending a MSG_STM_UNIQUE_ID_REQ. The device responds with a
MSG_STM_UNIQUE_ID_RESP with the 12-byte unique ID in the payload.
 */
typedef struct {
  /**
   * Device unique ID
   */
  u8 stm_id[12];
} sbp_msg_stm_unique_id_resp_t;

/**
 * Get encoded size of an instance of sbp_msg_stm_unique_id_resp_t
 *
 * @param msg sbp_msg_stm_unique_id_resp_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_stm_unique_id_resp_t(
    const sbp_msg_stm_unique_id_resp_t *msg);

/**
 * Encode an instance of sbp_msg_stm_unique_id_resp_t to wire representation
 *
 * This function encodes the given instance in to the user provided buffer. The
 * buffer provided to this function must be large enough to store the encoded
 * message otherwise it will return SBP_ENCODE_ERROR without writing anything to
 * the buffer.
 *
 * Specify the length of the destination buffer in the \p len parameter. If
 * non-null the number of bytes written to the buffer will be returned in \p
 * n_written.
 *
 * @param buf Destination buffer
 * @param len Length of \p buf
 * @param n_written If not null, on success will be set to the number of bytes
 * written to \p buf
 * @param msg Instance of sbp_msg_stm_unique_id_resp_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_stm_unique_id_resp_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_stm_unique_id_resp_t *msg);

/**
 * Decode an instance of sbp_msg_stm_unique_id_resp_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_stm_unique_id_resp_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_stm_unique_id_resp_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_stm_unique_id_resp_t(const uint8_t *buf, uint8_t len,
                                           uint8_t *n_read,
                                           sbp_msg_stm_unique_id_resp_t *msg);
/**
 * Send an instance of sbp_msg_stm_unique_id_resp_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_stm_unique_id_resp_t
 *
 * The given message will be encoded to wire representation and passed in to the
 * given write function callback. The write callback will be called several
 * times for each invocation of this function.
 *
 * @param s SBP state
 * @param sender_id SBP sender id
 * @param msg Message to send
 * @param write Write function
 * @param SBP_OK on success, or other libsbp error code
 */
s8 sbp_send_sbp_msg_stm_unique_id_resp_t(
    struct sbp_state *s, u16 sender_id, const sbp_msg_stm_unique_id_resp_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_stm_unique_id_resp_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_stm_unique_id_resp_t instance
 * @param b sbp_msg_stm_unique_id_resp_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_stm_unique_id_resp_t(const sbp_msg_stm_unique_id_resp_t *a,
                                         const sbp_msg_stm_unique_id_resp_t *b);

/*
 *
 *
 *
 ******************************************************************************
 *
 * SBP_MSG_M25_FLASH_WRITE_STATUS
 *
 *****************************************************************************/
/** Write M25 flash status register (host => device)
 *
 * The flash status message writes to the 8-bit M25 flash status register. The
 * device replies with a MSG_FLASH_DONE message.
 */
typedef struct {
  /**
   * Byte to write to the M25 flash status register
   */
  u8 status[1];
} sbp_msg_m25_flash_write_status_t;

/**
 * Get encoded size of an instance of sbp_msg_m25_flash_write_status_t
 *
 * @param msg sbp_msg_m25_flash_write_status_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_m25_flash_write_status_t(
    const sbp_msg_m25_flash_write_status_t *msg);

/**
 * Encode an instance of sbp_msg_m25_flash_write_status_t to wire representation
 *
 * This function encodes the given instance in to the user provided buffer. The
 * buffer provided to this function must be large enough to store the encoded
 * message otherwise it will return SBP_ENCODE_ERROR without writing anything to
 * the buffer.
 *
 * Specify the length of the destination buffer in the \p len parameter. If
 * non-null the number of bytes written to the buffer will be returned in \p
 * n_written.
 *
 * @param buf Destination buffer
 * @param len Length of \p buf
 * @param n_written If not null, on success will be set to the number of bytes
 * written to \p buf
 * @param msg Instance of sbp_msg_m25_flash_write_status_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_m25_flash_write_status_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_m25_flash_write_status_t *msg);

/**
 * Decode an instance of sbp_msg_m25_flash_write_status_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_m25_flash_write_status_t message to the given instance. The caller
 * must specify the length of the buffer in the \p len parameter. If non-null
 * the number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_m25_flash_write_status_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_m25_flash_write_status_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_m25_flash_write_status_t *msg);
/**
 * Send an instance of sbp_msg_m25_flash_write_status_t with the given write
 * function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_m25_flash_write_status_t
 *
 * The given message will be encoded to wire representation and passed in to the
 * given write function callback. The write callback will be called several
 * times for each invocation of this function.
 *
 * @param s SBP state
 * @param sender_id SBP sender id
 * @param msg Message to send
 * @param write Write function
 * @param SBP_OK on success, or other libsbp error code
 */
s8 sbp_send_sbp_msg_m25_flash_write_status_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_m25_flash_write_status_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_m25_flash_write_status_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_m25_flash_write_status_t instance
 * @param b sbp_msg_m25_flash_write_status_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_m25_flash_write_status_t(
    const sbp_msg_m25_flash_write_status_t *a,
    const sbp_msg_m25_flash_write_status_t *b);

#ifdef __cplusplus
}
static inline bool operator==(const sbp_msg_flash_program_t &lhs,
                              const sbp_msg_flash_program_t &rhs) {
  return sbp_cmp_sbp_msg_flash_program_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_flash_program_t &lhs,
                              const sbp_msg_flash_program_t &rhs) {
  return sbp_cmp_sbp_msg_flash_program_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_flash_program_t &lhs,
                             const sbp_msg_flash_program_t &rhs) {
  return sbp_cmp_sbp_msg_flash_program_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_flash_program_t &lhs,
                              const sbp_msg_flash_program_t &rhs) {
  return sbp_cmp_sbp_msg_flash_program_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_flash_program_t &lhs,
                             const sbp_msg_flash_program_t &rhs) {
  return sbp_cmp_sbp_msg_flash_program_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_flash_program_t &lhs,
                              const sbp_msg_flash_program_t &rhs) {
  return sbp_cmp_sbp_msg_flash_program_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_flash_done_t &lhs,
                              const sbp_msg_flash_done_t &rhs) {
  return sbp_cmp_sbp_msg_flash_done_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_flash_done_t &lhs,
                              const sbp_msg_flash_done_t &rhs) {
  return sbp_cmp_sbp_msg_flash_done_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_flash_done_t &lhs,
                             const sbp_msg_flash_done_t &rhs) {
  return sbp_cmp_sbp_msg_flash_done_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_flash_done_t &lhs,
                              const sbp_msg_flash_done_t &rhs) {
  return sbp_cmp_sbp_msg_flash_done_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_flash_done_t &lhs,
                             const sbp_msg_flash_done_t &rhs) {
  return sbp_cmp_sbp_msg_flash_done_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_flash_done_t &lhs,
                              const sbp_msg_flash_done_t &rhs) {
  return sbp_cmp_sbp_msg_flash_done_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_flash_read_req_t &lhs,
                              const sbp_msg_flash_read_req_t &rhs) {
  return sbp_cmp_sbp_msg_flash_read_req_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_flash_read_req_t &lhs,
                              const sbp_msg_flash_read_req_t &rhs) {
  return sbp_cmp_sbp_msg_flash_read_req_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_flash_read_req_t &lhs,
                             const sbp_msg_flash_read_req_t &rhs) {
  return sbp_cmp_sbp_msg_flash_read_req_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_flash_read_req_t &lhs,
                              const sbp_msg_flash_read_req_t &rhs) {
  return sbp_cmp_sbp_msg_flash_read_req_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_flash_read_req_t &lhs,
                             const sbp_msg_flash_read_req_t &rhs) {
  return sbp_cmp_sbp_msg_flash_read_req_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_flash_read_req_t &lhs,
                              const sbp_msg_flash_read_req_t &rhs) {
  return sbp_cmp_sbp_msg_flash_read_req_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_flash_read_resp_t &lhs,
                              const sbp_msg_flash_read_resp_t &rhs) {
  return sbp_cmp_sbp_msg_flash_read_resp_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_flash_read_resp_t &lhs,
                              const sbp_msg_flash_read_resp_t &rhs) {
  return sbp_cmp_sbp_msg_flash_read_resp_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_flash_read_resp_t &lhs,
                             const sbp_msg_flash_read_resp_t &rhs) {
  return sbp_cmp_sbp_msg_flash_read_resp_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_flash_read_resp_t &lhs,
                              const sbp_msg_flash_read_resp_t &rhs) {
  return sbp_cmp_sbp_msg_flash_read_resp_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_flash_read_resp_t &lhs,
                             const sbp_msg_flash_read_resp_t &rhs) {
  return sbp_cmp_sbp_msg_flash_read_resp_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_flash_read_resp_t &lhs,
                              const sbp_msg_flash_read_resp_t &rhs) {
  return sbp_cmp_sbp_msg_flash_read_resp_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_flash_erase_t &lhs,
                              const sbp_msg_flash_erase_t &rhs) {
  return sbp_cmp_sbp_msg_flash_erase_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_flash_erase_t &lhs,
                              const sbp_msg_flash_erase_t &rhs) {
  return sbp_cmp_sbp_msg_flash_erase_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_flash_erase_t &lhs,
                             const sbp_msg_flash_erase_t &rhs) {
  return sbp_cmp_sbp_msg_flash_erase_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_flash_erase_t &lhs,
                              const sbp_msg_flash_erase_t &rhs) {
  return sbp_cmp_sbp_msg_flash_erase_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_flash_erase_t &lhs,
                             const sbp_msg_flash_erase_t &rhs) {
  return sbp_cmp_sbp_msg_flash_erase_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_flash_erase_t &lhs,
                              const sbp_msg_flash_erase_t &rhs) {
  return sbp_cmp_sbp_msg_flash_erase_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_stm_flash_lock_sector_t &lhs,
                              const sbp_msg_stm_flash_lock_sector_t &rhs) {
  return sbp_cmp_sbp_msg_stm_flash_lock_sector_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_stm_flash_lock_sector_t &lhs,
                              const sbp_msg_stm_flash_lock_sector_t &rhs) {
  return sbp_cmp_sbp_msg_stm_flash_lock_sector_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_stm_flash_lock_sector_t &lhs,
                             const sbp_msg_stm_flash_lock_sector_t &rhs) {
  return sbp_cmp_sbp_msg_stm_flash_lock_sector_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_stm_flash_lock_sector_t &lhs,
                              const sbp_msg_stm_flash_lock_sector_t &rhs) {
  return sbp_cmp_sbp_msg_stm_flash_lock_sector_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_stm_flash_lock_sector_t &lhs,
                             const sbp_msg_stm_flash_lock_sector_t &rhs) {
  return sbp_cmp_sbp_msg_stm_flash_lock_sector_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_stm_flash_lock_sector_t &lhs,
                              const sbp_msg_stm_flash_lock_sector_t &rhs) {
  return sbp_cmp_sbp_msg_stm_flash_lock_sector_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_stm_flash_unlock_sector_t &lhs,
                              const sbp_msg_stm_flash_unlock_sector_t &rhs) {
  return sbp_cmp_sbp_msg_stm_flash_unlock_sector_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_stm_flash_unlock_sector_t &lhs,
                              const sbp_msg_stm_flash_unlock_sector_t &rhs) {
  return sbp_cmp_sbp_msg_stm_flash_unlock_sector_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_stm_flash_unlock_sector_t &lhs,
                             const sbp_msg_stm_flash_unlock_sector_t &rhs) {
  return sbp_cmp_sbp_msg_stm_flash_unlock_sector_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_stm_flash_unlock_sector_t &lhs,
                              const sbp_msg_stm_flash_unlock_sector_t &rhs) {
  return sbp_cmp_sbp_msg_stm_flash_unlock_sector_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_stm_flash_unlock_sector_t &lhs,
                             const sbp_msg_stm_flash_unlock_sector_t &rhs) {
  return sbp_cmp_sbp_msg_stm_flash_unlock_sector_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_stm_flash_unlock_sector_t &lhs,
                              const sbp_msg_stm_flash_unlock_sector_t &rhs) {
  return sbp_cmp_sbp_msg_stm_flash_unlock_sector_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_stm_unique_id_req_t &lhs,
                              const sbp_msg_stm_unique_id_req_t &rhs) {
  return sbp_cmp_sbp_msg_stm_unique_id_req_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_stm_unique_id_req_t &lhs,
                              const sbp_msg_stm_unique_id_req_t &rhs) {
  return sbp_cmp_sbp_msg_stm_unique_id_req_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_stm_unique_id_req_t &lhs,
                             const sbp_msg_stm_unique_id_req_t &rhs) {
  return sbp_cmp_sbp_msg_stm_unique_id_req_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_stm_unique_id_req_t &lhs,
                              const sbp_msg_stm_unique_id_req_t &rhs) {
  return sbp_cmp_sbp_msg_stm_unique_id_req_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_stm_unique_id_req_t &lhs,
                             const sbp_msg_stm_unique_id_req_t &rhs) {
  return sbp_cmp_sbp_msg_stm_unique_id_req_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_stm_unique_id_req_t &lhs,
                              const sbp_msg_stm_unique_id_req_t &rhs) {
  return sbp_cmp_sbp_msg_stm_unique_id_req_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_stm_unique_id_resp_t &lhs,
                              const sbp_msg_stm_unique_id_resp_t &rhs) {
  return sbp_cmp_sbp_msg_stm_unique_id_resp_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_stm_unique_id_resp_t &lhs,
                              const sbp_msg_stm_unique_id_resp_t &rhs) {
  return sbp_cmp_sbp_msg_stm_unique_id_resp_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_stm_unique_id_resp_t &lhs,
                             const sbp_msg_stm_unique_id_resp_t &rhs) {
  return sbp_cmp_sbp_msg_stm_unique_id_resp_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_stm_unique_id_resp_t &lhs,
                              const sbp_msg_stm_unique_id_resp_t &rhs) {
  return sbp_cmp_sbp_msg_stm_unique_id_resp_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_stm_unique_id_resp_t &lhs,
                             const sbp_msg_stm_unique_id_resp_t &rhs) {
  return sbp_cmp_sbp_msg_stm_unique_id_resp_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_stm_unique_id_resp_t &lhs,
                              const sbp_msg_stm_unique_id_resp_t &rhs) {
  return sbp_cmp_sbp_msg_stm_unique_id_resp_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_m25_flash_write_status_t &lhs,
                              const sbp_msg_m25_flash_write_status_t &rhs) {
  return sbp_cmp_sbp_msg_m25_flash_write_status_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_m25_flash_write_status_t &lhs,
                              const sbp_msg_m25_flash_write_status_t &rhs) {
  return sbp_cmp_sbp_msg_m25_flash_write_status_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_m25_flash_write_status_t &lhs,
                             const sbp_msg_m25_flash_write_status_t &rhs) {
  return sbp_cmp_sbp_msg_m25_flash_write_status_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_m25_flash_write_status_t &lhs,
                              const sbp_msg_m25_flash_write_status_t &rhs) {
  return sbp_cmp_sbp_msg_m25_flash_write_status_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_m25_flash_write_status_t &lhs,
                             const sbp_msg_m25_flash_write_status_t &rhs) {
  return sbp_cmp_sbp_msg_m25_flash_write_status_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_m25_flash_write_status_t &lhs,
                              const sbp_msg_m25_flash_write_status_t &rhs) {
  return sbp_cmp_sbp_msg_m25_flash_write_status_t(&lhs, &rhs) >= 0;
}

#endif

#endif /* LIBSBP_NEW_FLASH_MESSAGES_H */
