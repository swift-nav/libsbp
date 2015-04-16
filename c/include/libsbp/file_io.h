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
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup file_io File_io
 *
 *  * Messages for using device's onboard flash filesystem
 * functionality. This allows data to be stored persistently in the
 * device's program flash with wear-levelling using a simple filesystem
 * interface. The file system interface (CFS) defines an abstract API
 * for reading directories and for reading and writing files.
 * 
 * These are in the implementation-defined range (0x0000-0x00FF), and
 * intended for internal-use only. Note that some of these messages
 * share the same message type ID for both the host request and the
 * device response.
 * \{ */

#ifndef LIBSBP_FILE_IO_MESSAGES_H
#define LIBSBP_FILE_IO_MESSAGES_H

#include "common.h"


/** Read file from the file system (host <=> device)
 *
 * The file read message reads a certain length (up to 255 bytes)
 * from a given offset into a file, and returns the data in a
 * MSG_FILEIO_READ message where the message length field indicates
 * how many bytes were succesfully read. If the message is invalid,
 * a followup MSG_PRINT message will print "Invalid fileio read
 * message".
 */
#define SBP_MSG_FILEIO_READ     0x00A8
typedef struct __attribute__((packed)) {
  u32 offset;        /**< File offset [bytes] */
  u8 chunk_size;    /**< Chunk size to read [bytes] */
  char filename[20];  /**< Name of the file to read from (NULL padded) */
} msg_fileio_read_t;


/** List files in a directory (host <=> device)
 *
 * The read directory message lists the files in a directory on the
 * device's onboard flash file system.  The offset parameter can be
 * used to skip the first n elements of the file list. Returns a
 * MSG_FILEIO_READ_DIR message containing the directory listings as
 * a NULL delimited list. The listing is chunked over multiple SBP
 * packets and the end of the list is identified by an entry
 * containing just the character 0xFF. If message is invalid, a
 * followup MSG_PRINT message will print "Invalid fileio read
 * message".
 */
#define SBP_MSG_FILEIO_READ_DIR 0x00A9
typedef struct __attribute__((packed)) {
  u32 offset;     /**< The offset to skip the first n elements of the file list
 */
  char dirname[20]; /**< Name of the directory to list (NULL padded) */
} msg_fileio_read_dir_t;


/** Delete a file from the file system (host => device)
 *
 * The file remove message deletes a file from the file system. If
 * message is invalid, a followup MSG_PRINT message will print
 * "Invalid fileio remove message".
 */
#define SBP_MSG_FILEIO_REMOVE   0x00AC
typedef struct __attribute__((packed)) {
  char filename[20]; /**< Name of the file to delete (NULL padded) */
} msg_fileio_remove_t;


/** Write to file (host <=> device)
 *
 * The file write message writes a certain length (up to 255 bytes)
 * of data to a file at a given offset. Returns a copy of the
 * original MSG_FILEIO_WRITE message to check integrity of the
 * write. If message is invalid, a followup MSG_PRINT message will
 * print "Invalid fileio write message".
 */
#define SBP_MSG_FILEIO_WRITE    0x00AD
typedef struct __attribute__((packed)) {
  char filename[20]; /**< Name of the file to write to (NULL padded) */
  u32 offset;      /**< Offset into the file at which to start writing in bytes [bytes] */
  u8 data[0];     /**< Variable-length array of data to write */
} msg_fileio_write_t;


/** \} */

#endif /* LIBSBP_FILE_IO_MESSAGES_H */