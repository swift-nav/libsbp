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


/** Read file from the file system (host => device)
 *
 * The file read message reads a certain length (up to 255 bytes)
 * from a given offset into a file, and returns the data in a
 * MSG_FILEIO_READ_RESP message where the message length field
 * indicates how many bytes were succesfully read.The sequence
 * number in the request will be returned in the response.
 */
#define SBP_MSG_FILEIO_READ_REQ      0x00A8
typedef struct __attribute__((packed)) {
  u32 sequence;      /**< Read sequence number */
  u32 offset;        /**< File offset [bytes] */
  u8 chunk_size;    /**< Chunk size to read [bytes] */
  char filename[0];   /**< Name of the file to read from */
} msg_fileio_read_req_t;


/** File read from the file system (host <= device)
 *
 * The file read message reads a certain length (up to 255 bytes)
 * from a given offset into a file, and returns the data in a
 * message where the message length field indicates how many bytes
 * were succesfully read. The sequence number in the response is
 * preserved from the request.
 */
#define SBP_MSG_FILEIO_READ_RESP     0x00A3
typedef struct __attribute__((packed)) {
  u32 sequence;    /**< Read sequence number */
  u8 contents[0]; /**< Contents of read file */
} msg_fileio_read_resp_t;


/** List files in a directory (host => device)
 *
 * The read directory message lists the files in a directory on the
 * device's onboard flash file system.  The offset parameter can be
 * used to skip the first n elements of the file list. Returns a
 * MSG_FILEIO_READ_DIR_RESP message containing the directory
 * listings as a NULL delimited list. The listing is chunked over
 * multiple SBP packets. The sequence number in the request will be
 * returned in the response.
 */
#define SBP_MSG_FILEIO_READ_DIR_REQ  0x00A9
typedef struct __attribute__((packed)) {
  u32 sequence;    /**< Read sequence number */
  u32 offset;      /**< The offset to skip the first n elements of the file list
 */
  char dirname[0];  /**< Name of the directory to list */
} msg_fileio_read_dir_req_t;


/** Files listed in a directory (host <= device)
 *
 * The read directory message lists the files in a directory on the
 * device's onboard flash file system. Message contains the directory
 * listings as a NULL delimited list. The listing is chunked over
 * multiple SBP packets and the end of the list is identified by an
 * entry containing just the character 0xFF. The sequence number in
 * the response is preserved from the request.
 */
#define SBP_MSG_FILEIO_READ_DIR_RESP 0x00AA
typedef struct __attribute__((packed)) {
  u32 sequence;    /**< Read sequence number */
  u8 contents[0]; /**< Contents of read directory */
} msg_fileio_read_dir_resp_t;


/** Delete a file from the file system (host => device)
 *
 * The file remove message deletes a file from the file system.
 */
#define SBP_MSG_FILEIO_REMOVE        0x00AC
typedef struct __attribute__((packed)) {
  char filename[0]; /**< Name of the file to delete */
} msg_fileio_remove_t;


/** Write to file (host => device)
 *
 * The file write message writes a certain length (up to 255 bytes)
 * of data to a file at a given offset. Returns a copy of the
 * original MSG_FILEIO_WRITE_RESP message to check integrity of
 * the write. The sequence number in the request will be returned
 * in the response.
 */
#define SBP_MSG_FILEIO_WRITE_REQ     0x00AD
typedef struct __attribute__((packed)) {
  u32 sequence;    /**< Write sequence number */
  u32 offset;      /**< Offset into the file at which to start writing in bytes [bytes] */
  char filename[0]; /**< Name of the file to write to */
  u8 data[0];     /**< Variable-length array of data to write */
} msg_fileio_write_req_t;


/** File written to (host <= device)
 *
 * The file write message writes a certain length (up to 255 bytes)
 * of data to a file at a given offset. The message is a copy of the
 * original MSG_FILEIO_WRITE_REQ message to check integrity of the
 * write. The sequence number in the response is preserved from the
 * request.
 */
#define SBP_MSG_FILEIO_WRITE_RESP    0x00AB
typedef struct __attribute__((packed)) {
  u32 sequence;    /**< Write sequence number */
} msg_fileio_write_resp_t;


/** \} */

#endif /* LIBSBP_FILE_IO_MESSAGES_H */