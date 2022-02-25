/*
 * Copyright (C) 2011-2021 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swift-nav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef LIBSBP_SBP_H
#define LIBSBP_SBP_H

#include <libsbp/common.h>
#include <libsbp/legacy/api.h>
#include <libsbp/legacy/compat.h>
#include <libsbp/v4/api.h>
#include <libsbp/sbp_msg_type.h>

#ifdef __cplusplus
extern "C" {
#endif

/** \addtogroup sbp
 * \{ */

/** Return value indicating success. */
#define SBP_OK                    0
/** Return value indicating message decoded and callback executed by sbp_process. */
#define SBP_OK_CALLBACK_EXECUTED  1
/** Return value indicating message decoded with no associated callback in sbp_process. */
#define SBP_OK_CALLBACK_UNDEFINED 2
/** Return value indicating an error with the callback (function defined). */
#define SBP_CALLBACK_ERROR       (-1)
/** Return value indicating a CRC error. */
#define SBP_CRC_ERROR            (-2)
/** Return value indicating an error occured whilst sending an SBP message. */
#define SBP_SEND_ERROR           (-3)
/** Return value indicating an error occured because an argument was NULL. */
#define SBP_NULL_ERROR           (-4)
/** Return value indicating an error occured in the write() operation. */
#define SBP_WRITE_ERROR          (-5)
/** Return value indicating an error occured in the read() operation. */
#define SBP_READ_ERROR           (-6)
/** Return value indicating an error while encoding an SBP message to the wire format */
#define SBP_ENCODE_ERROR (-7)
/** Return value indicating an error while decoding an SBP message from wire format */
#define SBP_DECODE_ERROR (-8)

/** Default sender ID. Intended for messages sent from the host to the device. */
#define SBP_SENDER_ID 0x42
/** Header length in bytes. */
#define SBP_HEADER_LEN 6
/** CRC length in bytes. */
#define SBP_CRC_LEN 2
/** Max payload length in bytes. */
#define SBP_MAX_PAYLOAD_LEN (UINT8_MAX)
/** Max frame length in bytes. */
#define SBP_MAX_FRAME_LEN (SBP_HEADER_LEN + SBP_MAX_PAYLOAD_LEN + SBP_CRC_LEN)

/** Frame offset for the preamble. */
#define SBP_FRAME_OFFSET_PREAMBLE (0u)
/** Frame offset for the preamble. */
#define SBP_FRAME_OFFSET_MSGTYPE (SBP_FRAME_OFFSET_PREAMBLE + sizeof(u8))
/** Frame offset for the preamble. */
#define SBP_FRAME_OFFSET_SENDERID (SBP_FRAME_OFFSET_MSGTYPE + sizeof(u16))
/** Frame offset for the preamble. */
#define SBP_FRAME_OFFSET_MSGLEN (SBP_FRAME_OFFSET_SENDERID + sizeof(u16))
/** Frame offset for the preamble. */
#define SBP_FRAME_OFFSET_MSG (SBP_FRAME_OFFSET_MSGLEN + sizeof(u8))
/** Frame offset for the CRC is a function of msg length. */
#define SBP_FRAME_OFFSET_CRC(msg_len) (SBP_FRAME_OFFSET_MSG + (msg_len))
#define SBP_FRAME_CALC_LEN(msg_len) (SBP_HEADER_LEN + (msg_len) + SBP_CRC_LEN)

/** Get message payload pointer from frame */
#define SBP_FRAME_MSG_PAYLOAD(frame_ptr) (&((frame_ptr)[SBP_FRAME_OFFSET_MSG]))

/** SBP callback function prototype definitions. */
typedef union {
  sbp_msg_callback_t msg;
  sbp_frame_callback_t frame;
  sbp_decoded_callback_t decoded;
} sbp_callback_t;

/** SBP callback type enum:
 * SBP_PAYLOAD_CALLBACK are the original callbacks in libsbp without framing args
 * SBP_FRAME_CALLBACK are raw frame callbacks that include framing data as args.
 * SBP_DECODED_CALLBACK are callbacks which receive decoded (ie, not raw) messages
 *
 * This enum is stored on each sbp_msg_callback_node struct to identify how
 * to cast the callback function pointer stored within.
 *
 * SBP_PAYLOAD_CALLBACK and SBP_FRAME_CALLBACK are part of the legacy libsbp API. They
 * are both deprecated and should not be used in new code. SBP_DECODED_CALLBACK should
 * be used for all new development.
 */
enum sbp_cb_type {
  SBP_MSG_CALLBACK = 0,
  SBP_FRAME_CALLBACK = 1,
  SBP_DECODED_CALLBACK = 2,
  SBP_CALLBACK_TYPE_COUNT = 3,
};

#define SBP_CALLBACK_FLAG(cb_type) (1u << (cb_type))
#define SBP_CALLBACK_ALL_MASK \
  ((SBP_CALLBACK_FLAG(SBP_CALLBACK_TYPE_COUNT)) - 1)

typedef enum sbp_cb_type sbp_cb_type;
/** SBP callback node.
 * Forms a linked list of callbacks.
 * \note Must be statically allocated for use with sbp_register_callback()
 *       and sbp_register_frame_callback().
 */
struct sbp_msg_callbacks_node {
  sbp_msg_type_t msg_type;      /**< Message ID associated with callback. */
  sbp_callback_t cb; /**< Pointer to callback function. */
  void *context;     /**< Pointer to a context */
  struct sbp_msg_callbacks_node *next; /**< Pointer to next node in list. */
  sbp_cb_type cb_type;                 /**< Enum that holds the type of callback. */
};

/** State structure for processing SBP messages. */
struct sbp_state {
  enum {
    SBP_WAITING = 0,
    SBP_GET_TYPE,
    SBP_GET_SENDER,
    SBP_GET_LEN,
    SBP_GET_MSG,
    SBP_GET_CRC
  } state;
  sbp_msg_type_t msg_type;
  u16 sender_id;
  u16 crc;
  u8 msg_len;
  u16 frame_len;
  u8 n_read;
  u8 frame_buff[SBP_MAX_FRAME_LEN];
  u8* msg_buff;
  void* io_context;
  sbp_msg_callbacks_node_t* sbp_msg_callbacks_head;
};

/** \} */

SBP_EXPORT s8 sbp_remove_callback(sbp_state_t *s, sbp_msg_callbacks_node_t *node);
SBP_EXPORT void sbp_clear_callbacks(sbp_state_t* s);
SBP_EXPORT void sbp_state_init(sbp_state_t *s);
SBP_EXPORT void sbp_state_set_io_context(sbp_state_t *s, void* context);
SBP_EXPORT s8 sbp_process(sbp_state_t *s, sbp_read_fn_t read);

#ifdef __cplusplus
}
#endif

#endif /* LIBSBP_SBP_H */

