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

#include "libsbp/edc.h"
#include "libsbp/sbp.h"

#define SBP_PREAMBLE 0x55

/** \addtogroup io Input / Output
 * \{ */

/** \defgroup sbp SBP
 * Send and receive messages using Swift Binary Protocol.
 *
 * Examples
 * ========
 *
 * Receiving
 * ---------
 *
 * First setup a callback for the message you will be receiving. Our callback
 * function must have type #sbp_msg_callback_t or #sbp_msg_frame_callback_t,
 * i.e. it must be of the form:
 *
 * ~~~
 * void my_callback(u16 sender_id, u8 len, u8 msg[], void *context)
 * {
 *   // Process msg.
 * }
 * ~~~
 * or
 * ~~~
 * void my_frame_callback(u16 sender_id, u16 msg_type, u8 payload_len,
 *                         u8 payload[], u16 frame_len, u8 frame[], void *context)
 * {
 *   // Process msg.
 * }
 * ~~~
 *
 * You must also statically allocate a #sbp_msg_callbacks_node_t that will be
 * used to keep track of the callback function. You do not need to initialize
 * it as this will be done by sbp_register_callback().
 *
 * ~~~
 * static sbp_msg_callbacks_node_t my_callback_node;
 * ~~~
 *
 * Now register your callback function with the SBP library as follows:
 *
 * ~~~
 * sbp_register_callback(&sbp_state, SBP_MY_MSG_TYPE, &my_callback, &context, &my_callback_node);
 * ~~~
 * or
 * ~~~
 * sbp_register_frame_callback(&sbp_state, SBP_MY_MSG_TYPE, &my_frame_callback,
 *                             &context, &my_callback_node);
 * ~~~
 *
 * where `SBP_MY_MSG_TYPE` is the numerical identifier of your message type.
 *
 * You must now call sbp_process() periodically whenever you have received SBP
 * data to be processed, e.g. from the serial port. Remember sbp_process() may
 * not use all available data so keep calling sbp_process() until all the
 * received serial data has been consumed.
 *
 * sbp_process() stores its internal state in an #sbp_state_t struct which must
 * be initialized by calling sbp_state_init() before its first use.
 *
 * Here is an example based on reading from a typical UART interface:
 *
 * ~~~
 * u32 my_read(u8 *buff, u32 n, void *context)
 * {
 *   for (u32 i=0; i<n; i++) {
 *     if (uart_has_data())
 *       buff[i] = uart_read_char();
 *     else
 *       break;
 *   }
 *   return i;
 * }
 *
 * int main()
 * {
 *   ...
 *
 *   sbp_state_t s;
 *   sbp_state_init(&s);
 *
 *   while(uart_has_data()) {
 *     sbp_process(&s, &my_read);
 *   }
 *
 *   ...
 * }
 * ~~~
 *
 * If you're writing C++ code that wants to reference a pointer to
 * an object in the my_read function, you can use the context set
 * by calling sbp_state_set_io_context()
 *
 *
 * Sending
 * -------
 *
 * To send an SBP message simply call the sbp_send_message() function,
 * providing a `write` function that writes data to your output.
 *
 * Often the data to be sent will simply be a struct cast to a `u8` buffer. As
 * a convenience you may want to define a macro that automatically includes
 * your write function and calculates the size of the item to be sent.
 *
 * ~~~
 * // Convenience macro for sending an SBP message.
 * #define SBP_MSG(sbp_state, msg_type, item) \
 *   sbp_send_message(&sbp_state, msg_type, MY_SENDER_ID, \
 *       sizeof(item), (u8 *)&(item), &my_write)
 *
 * typedef struct {
 *   u8 x, y;
 * } my_awesome_struct;
 *
 * u32 my_write(u8 *buff, u32 n, void *context)
 * {
 *   for (u32 i=0; i<n; i++) {
 *     if (uart_write_char(buff[i]) == ERROR)
 *       break;
 *   }
 *   return i;
 * }
 *
 * int main()
 * {
 *   ...
 *
 *   sbp_state_t s;
 *   sbp_state_init(&s);
 *
 *   my_awesome_struct payload = { 0x22, 0x33 };
 *
 *   sbp_send_message(&s, SBP_MY_MSG_TYPE, MY_SENDER_ID,
 *                    sizeof(payload), (u8*)&payload, &my_write);
 *
 *   // or
 *
 *   SBP_MSG(s, SBP_MY_MSG_TYPE, payload);
 *
 *   ...
 * }
 * ~~~
 *
 *
 * \{ */

/** Register a callback for a particular msg_type, specifying the cb_type.
 *
 * \param s        Pointer to sbp_state
 * \param msg_type Message type on which to fire callback.
 *                 SBP_MSG_ALL will fire for every message, but only
 *                 for callbacks of type SBP_FRAME_CALLBACK.
 * \param cb       Pointer to message callback function
 * \param cb_type  sbp_cb_type indicating what kind of cb is in use.
 *                 (e.g SBP_PAYLOAD_CALLBACK or SBP_FRAME_CALLBACK)
 * \param context  Pointer to context for callback function
 * \param node     Statically allocated #sbp_msg_callbacks_node_t struct
 * \return `SBP_OK` (0) if successful, `SBP_NULL_ERROR` on usage errors,
 *         `SBP_CALLBACK_ERROR` if the if callback was already
 *         registered for that message type.
 */
static s8 sbp_register_callback_generic(sbp_state_t *s, u16 msg_type,
                                        void* cb, sbp_cb_type cb_type,
                                        void *context,
                                        sbp_msg_callbacks_node_t *node) {
  /* Check our callback function pointer isn't NULL. */
  if (cb == 0)
    return SBP_NULL_ERROR;

  /* Check our callback node pointer isn't NULL. */
  if (node == 0)
    return SBP_NULL_ERROR;

  for (sbp_msg_callbacks_node_t *n = s->sbp_msg_callbacks_head; n; n = n->next)
    if ((n == node) ||
        ((n->cb == cb) && (n->msg_type == msg_type) &&
         (n->context == context) && n->cb_type == cb_type))
      return SBP_CALLBACK_ERROR;

  /* Fill in our new sbp_msg_callback_node_t. */
  node->msg_type = msg_type;
  node->cb = cb;
  node->context = context;
  node->cb_type = cb_type;
  /* The next pointer is set to NULL, i.e. this
   * will be the new end of the linked list.
   */
  node->next = 0;

  /* If our linked list is empty then just
   * add the new node to the start.
   */
  if (s->sbp_msg_callbacks_head == 0) {
    s->sbp_msg_callbacks_head = node;
    return SBP_OK;
  }

  /* Find the tail of our linked list and
   * add our new node to the end.
   */
  sbp_msg_callbacks_node_t *p = s->sbp_msg_callbacks_head;
  while (p->next)
    p = p->next;

  p->next = node;

  return SBP_OK;
}

/** Remove a registered callback.
 *
 * \param node     #sbp_msg_callbacks_node_t struct of callback to remove.
 * \return `SBP_OK` (0) if successful, `SBP_CALLBACK_ERROR` if no callback was
 *         registered for that message type.
 */
s8 sbp_remove_callback(sbp_state_t *s, sbp_msg_callbacks_node_t *node)
{
  sbp_msg_callbacks_node_t *n;

  if (s->sbp_msg_callbacks_head == node) {
    s->sbp_msg_callbacks_head = node->next;
    return SBP_OK;
  } else {
    for (n = s->sbp_msg_callbacks_head; n; n = n->next) {
      if (n->next == node) {
        n->next = node->next;
        return SBP_OK;
      }
    }
  }
  return SBP_CALLBACK_ERROR;
}

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
s8 sbp_register_frame_callback(sbp_state_t *s, u16 msg_type,
                               sbp_frame_callback_t cb, void *context,
                               sbp_msg_callbacks_node_t *node) {
  return sbp_register_callback_generic(s, msg_type, cb, SBP_FRAME_CALLBACK, context, node);
}

/** Register a frame callback for ANY message.
 *
 * \param s        Pointer to sbp_state
 * \param cb       Pointer to message callback function
 * \param context  Pointer to context for callback function
 * \param node     Statically allocated #sbp_msg_callbacks_node_t struct
 * \return `SBP_OK` (0) if successful, `SBP_NULL_ERROR` if a usage error,
 *         `SBP_CALLBACK_ERROR` if the node already exists
 */

s8 sbp_register_all_msg_callback(sbp_state_t *s, sbp_frame_callback_t cb,
                                 void *context,
                                 sbp_msg_callbacks_node_t *node) {
  return sbp_register_frame_callback(s, SBP_MSG_ALL, cb, context, node);
}

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
s8 sbp_register_callback(sbp_state_t *s, u16 msg_type, sbp_msg_callback_t cb, void *context,
                         sbp_msg_callbacks_node_t *node) {
  return sbp_register_callback_generic(s, msg_type, cb, SBP_PAYLOAD_CALLBACK, context, node);
}

/** Clear all registered callbacks.
 * This is probably only useful for testing but who knows!
 */
void sbp_clear_callbacks(sbp_state_t *s)
{
  /* Reset the head of the callbacks list to NULL. */
  s->sbp_msg_callbacks_head = 0;
}

/** Initialize an #sbp_state_t struct before use.
 * This resets the entire state, including all callbacks.
 * Remember to use this function to initialize the state before calling
 * sbp_process() for the first time.
 *
 * \param s State structure
 */
void sbp_state_init(sbp_state_t *s)
{
  s->state = WAITING;

  /* Set the IO context pointer, passed to read and write functions, to NULL. */
  s->io_context = 0;
  s->msg_buff = SBP_FRAME_MSG_PAYLOAD(s->frame_buff);

  /* Clear the callbacks, if any, currently in s */
  sbp_clear_callbacks(s);
}


/** Set a context to pass to all function pointer calls made by sbp functions
 * This helper function sets a void* context pointer in sbp_state.
 * Whenever `sbp_process` calls the `read` function pointer, it passes this context.
 * Whenever `sbp_send_message` calls the `write` function pointer, it passes this context.
 * This allows C++ code to get a pointer to an object inside these functions.
 */
void sbp_state_set_io_context(sbp_state_t *s, void *context)
{
  s->io_context = context;
}

/** Helper function to fill frame buffer. Uses the `read` function and its
 * context to read into the `frame_buff` stored on the sbp_state.
 * Increments the n_read counter (number of bytes read for current read
 * operation) and the `frame_len` counter (total number of  bytes read into
 * frame_buff), both stored on the sbp_state.
 * \param s       State structure
 * \param *read   Function pointer to a function that reads `n` bytes from the
 *                input source into `buff` and returns the number of bytes
 *                successfully read.
 * \param to_read number of bytes to read.
 * \return `SBP_OK` (0) if successful,
 *         `SBP_READ_ERROR` (-6) if no bytes could be read or read function
 *         returned error code.
 */
static s8 sbp_state_read_to_frame_buffer(sbp_state_t *s,
                                         s32 (*read)(u8 *buff, u32 n, void *context),
                                         u8 to_read)
{
    s32 rd = (*read)(s->frame_buff + s->frame_len, to_read, s->io_context);
    if (0 > rd) return SBP_READ_ERROR;
    s->frame_len += rd;
    s->n_read += rd;
    return SBP_OK;
}

/** Reset frame buffer on the sbp_state to zeros and reset frame length counter.
 */
static void sbp_state_frame_buffer_clear(sbp_state_t *s)
{
    /* Note, library functions are not used to avoid more dependencies. */
    for (u32 i = 0; i < sizeof(s->frame_buff); i++) {
        s->frame_buff[i] = 0;
    }
    s->frame_len = 0;
}


/** Helper to convert a array of 2 bytes in network byte order
 *  to the platform's representation of a u16 without
 *  needing to use the word endian
 */
static u16 sbp_u8_array_to_u16(u8 *array_start)
{
  return (u16) array_start[0] + ((u16) array_start[1] << 8);
}

/** Read and process SBP messages.
 * Reads bytes from an input source using the provided `read` function, decodes
 * the SBP framing and performs a CRC check on the message.
 *
 * When an SBP message is successfully received then the list of callbacks is
 * searched for a callback corresponding to the received message type. If a
 * callback is found then it is called with its respective arguments depending
 * on its cb_type.
 *
 * \note sbp_process will always call `read` with n > 0
 *       (aka it will attempt to always read something)
 *
 * The supplied `read` function must have the prototype:
 *
 * ~~~
 * u32 read(u8 *buff, u32 n, void* context)
 * ~~~
 *
 * where `n` is the number of bytes requested and `buff` is the buffer into
 * which to write the received data, and `context` is the arbitrary pointer
 * set by `sbp_state_set_io_context`.
 * The function should return the number of
 * bytes successfully written into `buff` which may be between 0 and `n`
 * inclusive, but must never be greater than `n`.
 *
 * Note that `sbp_process` may not read all available bytes from the `read`
 * function so the caller should loop until all bytes available from the input
 * source have been consumed.
 *
 * \param s    State structure
 * \param read Function pointer to a function that reads `n` bytes from the
 *             input source into `buff` and returns the number of bytes
 *             successfully read.
 * \return `SBP_OK` (0) if successful but no complete message yet,
 *         `SBP_OK_CALLBACK_EXECUTED` (1) if message decoded and callback executed,
 *         `SBP_OK_CALLBACK_UNDEFINED` (2) if message decoded with no associated
 *         callback, and `SBP_CRC_ERROR` (-2) if a CRC error
 *         has occurred. Thus can check for >0 to ensure good processing.
 */
s8 sbp_process(sbp_state_t *s, s32 (*read)(u8 *buff, u32 n, void *context))
{
  /* Sanity checks */
  if ((0 == s) || (0 == read)) {
    return SBP_NULL_ERROR;
  }

  u8 temp;
  u16 crc;
  s32 rd = 0;
  s8 ret = SBP_OK;

  switch (s->state) {
  case WAITING:
    rd = (*read)(&temp, sizeof(temp), s->io_context);
    if (0 > rd) return SBP_READ_ERROR;
    if (sizeof(temp) == rd)
      if (temp == SBP_PREAMBLE) {
        /* set frame_buff and n_read to 0 after each preamble. */
        sbp_state_frame_buffer_clear(s);
        s->frame_buff[s->frame_len++] = temp;
        s->n_read = 0;
        s->state = GET_TYPE;
      }
    break;

  case GET_TYPE:
    ret = sbp_state_read_to_frame_buffer(s, read, sizeof(s->msg_type)-s->n_read);
    if (ret != SBP_OK) return ret;
    if (s->n_read >= sizeof(s->msg_type)) {
      s->msg_type =  sbp_u8_array_to_u16(&(s->frame_buff[SBP_FRAME_OFFSET_MSGTYPE]));
      s->n_read = 0;
      s->state = GET_SENDER;
    }
    break;

  case GET_SENDER:
    ret = sbp_state_read_to_frame_buffer(s, read, sizeof(s->sender_id)-s->n_read);
    if (ret != SBP_OK) return ret;
    if (s->n_read >= sizeof(s->sender_id)) {
      s->sender_id = sbp_u8_array_to_u16(&(s->frame_buff[SBP_FRAME_OFFSET_SENDERID]));
      s->n_read = 0;
      s->state = GET_LEN;
    }
    break;

  case GET_LEN:
    ret = sbp_state_read_to_frame_buffer(s, read, sizeof(s->msg_len)-s->n_read);
    if (ret != SBP_OK) return ret;
    if (s->n_read == sizeof(s->msg_len)) {
      s->msg_len = s->frame_buff[SBP_FRAME_OFFSET_MSGLEN];
      s->n_read = 0;
      s->state = GET_MSG;
    }
    break;

  case GET_MSG:
    /* Not received whole message yet, try and read some more. */
    ret = sbp_state_read_to_frame_buffer(s, read, s->msg_len - s->n_read);
    if (ret != SBP_OK) return ret;
    if (s->msg_len - s->n_read <= 0) {
      s->n_read = 0;
      s->state = GET_CRC;
    }
    break;

  case GET_CRC:
    ret = sbp_state_read_to_frame_buffer(s, read, SBP_CRC_LEN - s->n_read);
    if (ret != SBP_OK) return ret;
    if (s->n_read >= SBP_CRC_LEN) {
      s->state = WAITING;
      s->crc = sbp_u8_array_to_u16(&(s->frame_buff[SBP_FRAME_OFFSET_CRC(s->msg_len)]));
      crc = crc16_ccitt((u8*)&(s->msg_type), sizeof(s->msg_type), 0);
      crc = crc16_ccitt((u8*)&(s->sender_id), sizeof(s->sender_id), crc);
      crc = crc16_ccitt(&(s->msg_len), sizeof(s->msg_len), crc);
      crc = crc16_ccitt(SBP_FRAME_MSG_PAYLOAD(s->frame_buff), s->msg_len, crc);
      if (s->crc == crc) {
        /* Message complete, process frame callbacks and payload callbacks. */
        ret = sbp_process_frame(s, s->sender_id, s->msg_type,
                                s->msg_len, SBP_FRAME_MSG_PAYLOAD(s->frame_buff),
                                s->frame_len, s->frame_buff, SBP_CALLBACK_ALL_MASK);
        return ret;
      } else {
        return SBP_CRC_ERROR;
      }
    }
    break;

  default:
    s->state = WAITING;
    break;
  }

  return SBP_OK;
}

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
s8 sbp_process_payload(sbp_state_t *s, u16 sender_id, u16 msg_type, u8 msg_len,
                       u8 payload[]) {
  return sbp_process_frame(s, sender_id, msg_type, msg_len, payload,
                          0, 0, SBP_CALLBACK_FLAG(SBP_PAYLOAD_CALLBACK));
}


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
s8 sbp_process_frame(sbp_state_t *s, u16 sender_id, u16 msg_type,
                     u8 payload_len, u8 payload[],
                     u16 frame_len, u8 frame[],
                     u8 cb_mask) {
  s8 ret = SBP_OK_CALLBACK_UNDEFINED;
  sbp_msg_callbacks_node_t *node;
  for (node = s->sbp_msg_callbacks_head; node; node = node->next) {
    if ((SBP_CALLBACK_FLAG(node->cb_type) & cb_mask) &&
        ((node->msg_type == msg_type) || (node->msg_type == SBP_MSG_ALL))) {
        switch (node->cb_type) {
        case SBP_FRAME_CALLBACK:
        {
            ((sbp_frame_callback_t)(node->cb))(sender_id, msg_type, payload_len,
            payload, frame_len, frame,
            node->context);
            ret = SBP_OK_CALLBACK_EXECUTED;
        } break;
        case SBP_PAYLOAD_CALLBACK:
        {
            ((sbp_msg_callback_t)(node->cb))(sender_id, payload_len, payload,
            node->context);
            ret = SBP_OK_CALLBACK_EXECUTED;
        } break;
        case SBP_CALLBACK_TYPE_COUNT:
        default:
        {
            // NOP
        };
        }
    }
  }
  return ret;
}


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
 * the number of bytes written is different from `n` then `sbp_send_message`
 * will immediately return with an error.
 *
 * Note that `sbp_send_message` makes multiple calls to write and therefore if
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
s8 sbp_send_message(sbp_state_t *s, u16 msg_type, u16 sender_id, u8 len, u8 *payload,
                    s32 (*write)(u8 *buff, u32 n, void *context))
{
  /* Check our payload data pointer isn't NULL unless len = 0. */
  if (len != 0 && payload == 0)
    return SBP_NULL_ERROR;

  /* Check our write function pointer isn't NULL. */
  if ((0 == s) || (0 == write))
    return SBP_NULL_ERROR;

  u16 crc;
  s32 wr = 0;

  u8 preamble = SBP_PREAMBLE;
  wr = (*write)(&preamble, 1, s->io_context);
  if (0 > wr) return SBP_WRITE_ERROR;
  if (wr != 1) return SBP_SEND_ERROR;

  wr = (*write)((u8*)&msg_type, 2, s->io_context);
  if (0 > wr) return SBP_WRITE_ERROR;
  if (wr != 2) return SBP_SEND_ERROR;

  wr = (*write)((u8*)&sender_id, 2, s->io_context);
  if (0 > wr) return SBP_WRITE_ERROR;
  if (wr != 2) return SBP_SEND_ERROR;

  wr = (*write)(&len, 1, s->io_context);
  if (0 > wr) return SBP_WRITE_ERROR;
  if (wr != 1) return SBP_SEND_ERROR;

  if (len > 0) {
    wr = (*write)(payload, len, s->io_context);
    if (0 > wr) return SBP_WRITE_ERROR;
    if (wr != len) return SBP_SEND_ERROR;
  }

  crc = crc16_ccitt((u8*)&(msg_type), 2, 0);
  crc = crc16_ccitt((u8*)&(sender_id), 2, crc);
  crc = crc16_ccitt(&(len), 1, crc);
  crc = crc16_ccitt(payload, len, crc);

  wr = (*write)((u8*)&crc, 2, s->io_context);
  if (0 > wr) return SBP_WRITE_ERROR;
  if (wr != 2) return SBP_SEND_ERROR;

  return SBP_OK;
}

/** \} */
/** \} */
