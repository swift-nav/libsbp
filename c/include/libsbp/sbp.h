/*
 * Copyright (C) 2011-2014 Swift Navigation Inc.
 * Contact: Fergus Noble <fergus@swift-nav.com>
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

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

/** \addtogroup sbp
 * \{ */

/** Return value indicating success. */
#define SBP_OK                    0
/** Return value indicating message decoded and callback executed by sbp_process. */
#define SBP_OK_CALLBACK_EXECUTED  1
/** Return value indicating message decoded with no associated callback in sbp_process. */
#define SBP_OK_CALLBACK_UNDEFINED 2
/** Return value indicating an error with the callback (function defined). */
#define SBP_CALLBACK_ERROR       -1
/** Return value indicating a CRC error. */
#define SBP_CRC_ERROR            -2
/** Return value indicating an error occured whilst sending an SBP message. */
#define SBP_SEND_ERROR           -3
/** Return value indicating an error occured because an argument was NULL. */
#define SBP_NULL_ERROR           -4
/** Return value indicating an error occured in the write() operation. */
#define SBP_WRITE_ERROR          -5
/** Return value indicating an error occured in the read() operation. */
#define SBP_READ_ERROR           -6

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
#define SBP_FRAME_OFFSET_CRC(msg_len) (SBP_FRAME_OFFSET_MSG + msg_len)
#define SBP_FRAME_CALC_LEN(msg_len) (SBP_HEADER_LEN + msg_len + SBP_CRC_LEN)

/** Get message payload pointer from frame */
#define SBP_FRAME_MSG_PAYLOAD(frame_ptr) (&(frame_ptr[SBP_FRAME_OFFSET_MSG]))

/** SBP_MSG_ID to use to register frame callback for ALL messages. */
#define SBP_MSG_ALL 0

/** SBP callback function prototype definitions. */
typedef void (*sbp_msg_callback_t)(u16 sender_id, u8 len, u8 msg[], void *context);
typedef void (*sbp_frame_callback_t)(u16 sender_id, u16 msg_type,
                                     u8 payload_len, u8 payload[],
                                     u16 frame_len, u8 frame[], void *context);

/** SBP callback type enum:
 * SBP_PAYLOAD_CALLBACK are the original callbacks in libsbp without framing args
 * SBP_FRAME_CALLBACK are raw frame callbacks that include framing data as args.
 * This enum is stored on each sbp_msg_callback_node struct to identify how
 * to cast the callback function pointer stored within.
 */
enum sbp_cb_type {
  SBP_PAYLOAD_CALLBACK = 0,
  SBP_FRAME_CALLBACK = 1,
  SBP_CALLBACK_TYPE_COUNT = 2,
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
typedef struct sbp_msg_callbacks_node {
  u16 msg_type;                        /**< Message ID associated with callback. */
  void* cb;                            /**< Pointer to callback function. */
  void *context;                       /**< Pointer to a context */
  struct sbp_msg_callbacks_node *next; /**< Pointer to next node in list. */
  sbp_cb_type cb_type;                 /**< Enum that holds the type of callback. */
} sbp_msg_callbacks_node_t;

/** State structure for processing SBP messages. */
typedef struct {
  enum {
    WAITING = 0,
    GET_TYPE,
    GET_SENDER,
    GET_LEN,
    GET_MSG,
    GET_CRC
  } state;
  u16 msg_type;
  u16 sender_id;
  u16 crc;
  u8 msg_len;
  u16 frame_len;
  u8 n_read;
  u8 frame_buff[SBP_MAX_FRAME_LEN];
  u8* msg_buff;
  void* io_context;
  sbp_msg_callbacks_node_t* sbp_msg_callbacks_head;
} sbp_state_t;

/** \} */

s8 sbp_register_callback(sbp_state_t* s, u16 msg_type, sbp_msg_callback_t cb, void* context,
                         sbp_msg_callbacks_node_t *node);
s8 sbp_register_frame_callback(sbp_state_t* s, u16 msg_type,
                               sbp_frame_callback_t cb, void* context,
                               sbp_msg_callbacks_node_t *node);
s8 sbp_register_all_msg_callback(sbp_state_t *s, sbp_frame_callback_t cb,
                                 void *context, sbp_msg_callbacks_node_t *node);
s8 sbp_remove_callback(sbp_state_t *s, sbp_msg_callbacks_node_t *node);
void sbp_clear_callbacks(sbp_state_t* s);
void sbp_state_init(sbp_state_t *s);
void sbp_state_set_io_context(sbp_state_t *s, void* context);
s8 sbp_process(sbp_state_t *s, s32 (*read)(u8 *buff, u32 n, void* context));
s8 sbp_process_payload(sbp_state_t *s, u16 sender_id, u16 msg_type, u8 msg_len,
    u8 payload[]);
s8 sbp_process_frame(sbp_state_t *s, u16 sender_id, u16 msg_type,
                     u8 payload_len, u8 payload[], u16 frame_len, u8 frame[], u8 cb_mask);
s8 sbp_send_message(sbp_state_t *s, u16 msg_type, u16 sender_id, u8 len, u8 *payload,
                    s32 (*write)(u8 *buff, u32 n, void* context));

#ifdef __cplusplus
}
#endif

#endif /* LIBSBP_SBP_H */

