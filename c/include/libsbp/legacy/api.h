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

#ifndef LIBSBP_LEGACY_API_H
#define LIBSBP_LEGACY_API_H

#include <libsbp/common.h>

#ifdef __cplusplus
extern "C" {
#endif

/** SBP callback function prototype definitions. */
typedef void (*sbp_msg_callback_t)(u16 sender_id, u8 len, u8 msg[], void *context);
typedef void (*sbp_frame_callback_t)(u16 sender_id, u16 msg_type,
                                     u8 payload_len, u8 payload[],
                                     u16 frame_len, u8 frame[], void *context);

/** Register a payload callback for a message type.
 *
 * Register a payload callback that is called when a message
 * with type msg_type is received. Note, this might better
 * be called sbp_register_payload_callback, but is left
 * as sbp_register_callback for backwards compatibility.
 *
 * \param s        Pointer to sbp_state
 * \param msg_type Message type associated with callback
 * \param cb       Pointer to message callback function
 * \param context  Pointer to context for callback function
 * \param node     Statically allocated #sbp_msg_callbacks_node_t struct
 * \return `SBP_OK` (0) if successful, `SBP_NULL_ERROR` on usage errors,
 *         `SBP_CALLBACK_ERROR` if the callback was already
 *         registered for that message type.
 */
SBP_EXPORT s8 sbp_payload_callback_register(sbp_state_t* s, u16 msg_type, sbp_msg_callback_t cb, void* context,
                         sbp_msg_callbacks_node_t *node);

 /** Register a frame callback for a msg_type.
 *
 * \param s        Pointer to sbp_state
 * \param cb       Pointer to message callback function
 * \param msg_type Message type on which to fire frame callback,
 *                 SBP_MSG_ALL will fire for every message
 * \param context  Pointer to context for callback function
 * \param node     Statically allocated #sbp_msg_callbacks_node_t struct
 * \return `SBP_OK` (0) if successful, `SBP_NULL_ERROR` on usage errors,
 *         `SBP_CALLBACK_ERROR` if the if callback was already
 *         registered for that message type.
 */
SBP_EXPORT s8 sbp_frame_callback_register(sbp_state_t* s, u16 msg_type,
                               sbp_frame_callback_t cb, void* context,
                               sbp_msg_callbacks_node_t *node);

/** Register a frame callback for ANY message.
 *
 * \param s        Pointer to sbp_state
 * \param cb       Pointer to message callback function
 * \param context  Pointer to context for callback function
 * \param node     Statically allocated #sbp_msg_callbacks_node_t struct
 * \return `SBP_OK` (0) if successful, `SBP_NULL_ERROR` if a usage error,
 *         `SBP_CALLBACK_ERROR` if the node already exists
 */
SBP_EXPORT s8 sbp_all_payload_callback_register(sbp_state_t *s, sbp_frame_callback_t cb,
                                 void *context, sbp_msg_callbacks_node_t *node);

/** Directly process an SBP frame.
 * Use this function to directly process the entire SBP frame after
 * it is succesfully deframed and the CRC has passed. It will fire any
 * callbacks registered for the message which match the cb_mask.
 *
 * \param s           State structure
 * \param sender_id   SBP message sender id
 * \param msg_type    SBP message type. Type SBP_MSG_ALL will fire for all messages.
 * \param payload_len SBP message length
 * \param payload     SBP Message payload
 * \param frame_len   Length of ENTIRE frame (from header to CRC).  Max of 263.
 * \param frame       Pointer to the entire SBP frame (stored on state struct)
 * \param cb_mask     Bitmask defining which callbacks to include/exclude from
 *                    processing. Use SBP_CALLBACK_ALL_MASK for all callback
 *                    types or construct custom mask using
 *                    SBP_CALLBACK_FLAG(cb_type).
 * \return `SBP_OK_CALLBACK_EXECUTED` (1) if message decoded and callback executed
 *          SBP_OK_CALLBACK_UNDEFINED` (2) if message decoded with no
 *          associated callback.
 */
SBP_EXPORT s8 sbp_frame_process(sbp_state_t *s, u16 sender_id, u16 msg_type,
                     u8 payload_len, u8 payload[], u16 frame_len, u8 frame[], u8 cb_mask);

/** Directly process an SBP message.
 * If a SBP message has already been decoded (for example, from a binary
 * stream or from a JSON log file) use this function to directly process it.
 *
 * \param s         State structure
 * \param sender_id SBP message sender id
 * \param msg_type  SBP message type
 * \param msg_len   SBP message length
 * \param payload   SBP message payload
 * \return `SBP_OK_CALLBACK_EXECUTED` (1) if message decoded and callback executed,
 *         `SBP_OK_CALLBACK_UNDEFINED` (2) if message decoded with no associated
 *         callback.
 */
SBP_EXPORT s8 sbp_payload_process(sbp_state_t *s, u16 sender_id, u16 msg_type, u8 msg_len,
    u8 payload[]);

/** Send SBP messages.
 * Takes an SBP message payload, type and sender ID then writes a message to
 * the output stream using the supplied `write` function with the correct
 * framing and CRC.
 *
 * The supplied `write` function must have the prototype:
 *
 * ~~~
 * u32 write(u8 *buff, u32 n, void* context)
 * ~~~
 *
 * where `n` is the number of bytes to be written and `buff` is the buffer from
 * which to read the data to be written, and `context` is the arbitrary pointer
 * set by `sbp_state_set_io_context`. The function should return the number
 * of bytes successfully written which may be between 0 and `n`. Currently, if
 * the number of bytes written is different from `n` then `sbp_payload_send`
 * will immediately return with an error.
 *
 * Note that `sbp_payload_send` makes multiple calls to write and therefore if
 * a `write` call fails then this may result in a partial message being written
 * to the output. This should be caught by the CRC check on the receiving end
 * but will result in lost messages.
 *
 * \param write Function pointer to a function that writes `n` bytes from
 *              `buff` to the output stream  and returns the number of bytes
 *              successfully written.
 * \return `SBP_OK` (0) if successful, `SBP_WRITE_ERROR` if the message could
 *         not be sent or was only partially sent.
 */
SBP_EXPORT s8 sbp_payload_send(sbp_state_t *s, u16 msg_type, u16 sender_id, u8 len, u8 *payload,
                    sbp_write_fn_t write);

#ifdef __cplusplus
}
#endif

#endif /* LIBSBP_LEGACY_API_H */

