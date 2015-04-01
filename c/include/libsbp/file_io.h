/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Fergus Noble <fergus@swift-nav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/file_io.yaml
 * with generate.py at 2015-04-02 12:08:48.473141. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_FILE_IO_MESSAGES_H
#define LIBSBP_FILE_IO_MESSAGES_H

#include "common.h"


/** Read file from the file system (Host <=> Piksi).
 *
 * The file read message reads a certain length (up to 255 bytes)
 * from a given offset into a file, and returns the data in a
 * MSG_FILEIO_READ message where the message length field indicates
 * how many bytes were succesfully read. If the message is invalid,
 * a followup MsgPrint message will print "Invalid fileio read
 * message".
 */
#define SBP_MSG_FILEIO_READ     0x00A8
typedef struct __attribute__((packed)) {
  u32 offset;        /**< File offset. [bytes] */
  u8 chunk_size;    /**< Chunk size to read. [bytes] */
  char filename[20];  /**< Name of the file to read from (NULL terminated). */
} msg_fileio_read_t;


/** List files in a directory (Host <=> Piksi).
 *
 * The read directory message lists the files in a directory on the
 * Piksi's onboard flash file system.  The offset parameter can be
 * used to skip the first n elements of the file list. Returns a
 * MSG_FILEIO_READ_DIR message containing the directory listings as
 * a NULL delimited list. The listing is chunked over multiple SBP
 * packets and the end of the list is identified by an entry
 * containing just the character 0xFF. If message is invalid, a
 * followup MsgPrint message will print "Invalid fileio read
 * message".
 */
#define SBP_MSG_FILEIO_READ_DIR 0x00A9
typedef struct __attribute__((packed)) {
  u32 offset;     /**< The offset to skip the first n elements of the file list.
 */
  char dirname[20]; /**< Name of the directory to list. */
} msg_fileio_read_dir_t;


/** Delete a file from the file system (Host => Piksi).
 *
 * The file remove message deletes a file from the file system. If
 * message is invalid, a followup MsgPrint message will print
 * "Invalid fileio remove message".
 */
#define SBP_MSG_FILEIO_REMOVE   0x00AC
typedef struct __attribute__((packed)) {
  char filename[20]; /**< Name of the file to delete (NULL terminated) */
} msg_fileio_remove_t;


/** Write to file (Host <=> Piksi)
 *
 * The file write message writes a certain length (up to 255 bytes)
 * of data to a file at a given offset. Returns a copy of the
 * original MSG_FILEIO_WRITE message to check integrity of the
 * write. If message is invalid, a followup MsgPrint message will
 * print "Invalid fileio write message".
 */
#define SBP_MSG_FILEIO_WRITE    0x00AD
typedef struct __attribute__((packed)) {
  char filename[20]; /**< Name of the file to write to (NULL terminated) */
  u32 offset;      /**< Offset into the file at which to start writing in bytes [bytes] */
  u8 data[0];     /**< Data to write */
} msg_fileio_write_t;


#endif /* LIBSBP_FILE_IO_MESSAGES_H */