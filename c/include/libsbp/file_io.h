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
 * Note that some of these messages share the same message type ID for both the
 * host request and the device response.
 * \{ */

#ifndef LIBSBP_FILE_IO_MESSAGES_H
#define LIBSBP_FILE_IO_MESSAGES_H

#include "common.h"

SBP_PACK_START


/** Read file from the file system (host => device)
 *
 * The file read message reads a certain length (up to 255 bytes)
 * from a given offset into a file, and returns the data in a
 * MSG_FILEIO_READ_RESP message where the message length field
 * indicates how many bytes were succesfully read.The sequence
 * number in the request will be returned in the response.
 * If the message is invalid, a followup MSG_PRINT message will
 * print "Invalid fileio read message". A device will only respond
 * to this message when it is received from sender ID 0x42.
 */
#define SBP_MSG_FILEIO_READ_REQ      0x00A8

typedef struct SBP_ATTR_PACKED {
  u32 sequence;      /**< Read sequence number */
  u32 offset;        /**< File offset [bytes] */
  u8 chunk_size;    /**< Chunk size to read [bytes] */
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  char filename[0];   /**< Name of the file to read from */
#endif
} msg_fileio_read_req_t;
#define MSG_FILEIO_READ_REQ_T_GET_FILENAME_PTR(msg) (( char *)(msg+1))
#define MSG_FILEIO_READ_REQ_T_GET_FILENAME_CPTR(msg) ((const char *)(msg+1))
 

/** File read from the file system (host <= device)
 *
 * The file read message reads a certain length (up to 255 bytes)
 * from a given offset into a file, and returns the data in a
 * message where the message length field indicates how many bytes
 * were succesfully read. The sequence number in the response is
 * preserved from the request.
 */
#define SBP_MSG_FILEIO_READ_RESP     0x00A3

typedef struct SBP_ATTR_PACKED {
  u32 sequence;    /**< Read sequence number */
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  u8 contents[0]; /**< Contents of read file */
#endif
} msg_fileio_read_resp_t;
#define MSG_FILEIO_READ_RESP_T_GET_CONTENTS_PTR(msg) (( u8 *)(msg+1))
#define MSG_FILEIO_READ_RESP_T_GET_CONTENTS_CPTR(msg) ((const u8 *)(msg+1))
 

/** List files in a directory (host => device)
 *
 * The read directory message lists the files in a directory on the
 * device's onboard flash file system.  The offset parameter can be
 * used to skip the first n elements of the file list. Returns a
 * MSG_FILEIO_READ_DIR_RESP message containing the directory
 * listings as a NULL delimited list. The listing is chunked over
 * multiple SBP packets. The sequence number in the request will be
 * returned in the response.  If message is invalid, a followup
 * MSG_PRINT message will print "Invalid fileio read message".
 * A device will only respond to this message when it is received
 * from sender ID 0x42.
 */
#define SBP_MSG_FILEIO_READ_DIR_REQ  0x00A9

typedef struct SBP_ATTR_PACKED {
  u32 sequence;    /**< Read sequence number */
  u32 offset;      /**< The offset to skip the first n elements of the file list
 */
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  char dirname[0];  /**< Name of the directory to list */
#endif
} msg_fileio_read_dir_req_t;
#define MSG_FILEIO_READ_DIR_REQ_T_GET_DIRNAME_PTR(msg) (( char *)(msg+1))
#define MSG_FILEIO_READ_DIR_REQ_T_GET_DIRNAME_CPTR(msg) ((const char *)(msg+1))
 

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

typedef struct SBP_ATTR_PACKED {
  u32 sequence;    /**< Read sequence number */
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  u8 contents[0]; /**< Contents of read directory */
#endif
} msg_fileio_read_dir_resp_t;
#define MSG_FILEIO_READ_DIR_RESP_T_GET_CONTENTS_PTR(msg) (( u8 *)(msg+1))
#define MSG_FILEIO_READ_DIR_RESP_T_GET_CONTENTS_CPTR(msg) ((const u8 *)(msg+1))
 

/** Delete a file from the file system (host => device)
 *
 * The file remove message deletes a file from the file system.
 * If the message is invalid, a followup MSG_PRINT message will
 * print "Invalid fileio remove message". A device will only
 * process this message when it is received from sender ID 0x42.
 */
#define SBP_MSG_FILEIO_REMOVE        0x00AC
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS

typedef struct SBP_ATTR_PACKED {
  char filename[0]; /**< Name of the file to delete */
} msg_fileio_remove_t;
#endif
 

/** Write to file (host => device)
 *
 * The file write message writes a certain length (up to 255 bytes)
 * of data to a file at a given offset. Returns a copy of the
 * original MSG_FILEIO_WRITE_RESP message to check integrity of
 * the write. The sequence number in the request will be returned
 * in the response. If message is invalid, a followup MSG_PRINT
 * message will print "Invalid fileio write message". A device will
 * only  process this message when it is received from sender ID
 * 0x42.
 */
#define SBP_MSG_FILEIO_WRITE_REQ     0x00AD

typedef struct SBP_ATTR_PACKED {
  u32 sequence;    /**< Write sequence number */
  u32 offset;      /**< Offset into the file at which to start writing in bytes [bytes] */
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  char filename[0]; /**< Name of the file to write to */
#endif
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  u8 data[0];     /**< Variable-length array of data to write */
#endif
} msg_fileio_write_req_t;
#define MSG_FILEIO_WRITE_REQ_T_GET_FILENAME_PTR(msg) (( char *)(msg+1))
#define MSG_FILEIO_WRITE_REQ_T_GET_FILENAME_CPTR(msg) ((const char *)(msg+1))
#define MSG_FILEIO_WRITE_REQ_T_GET_DATA_PTR(msg) (( u8 *)(msg+1))
#define MSG_FILEIO_WRITE_REQ_T_GET_DATA_CPTR(msg) ((const u8 *)(msg+1))
 

/** File written to (host <= device)
 *
 * The file write message writes a certain length (up to 255 bytes)
 * of data to a file at a given offset. The message is a copy of the
 * original MSG_FILEIO_WRITE_REQ message to check integrity of the
 * write. The sequence number in the response is preserved from the
 * request.
 */
#define SBP_MSG_FILEIO_WRITE_RESP    0x00AB

typedef struct SBP_ATTR_PACKED {
  u32 sequence;    /**< Write sequence number */
} msg_fileio_write_resp_t;
 

/** Request advice on the optimal configuration for FileIO.
 *
 * Requests advice on the optimal configuration for a FileIO 
 * transfer.  Newer version of FileIO can support greater
 * throughput by supporting a large window of FileIO data
 * that can be in-flight during read or write operations.
 */
#define SBP_MSG_FILEIO_CONFIG_REQ    0x1001

typedef struct SBP_ATTR_PACKED {
  u32 sequence;    /**< Advice sequence number */
} msg_fileio_config_req_t;
 

/** Response with advice on the optimal configuration for FileIO.

 *
 * The advice on the optimal configuration for a FileIO
 * transfer.  Newer version of FileIO can support greater
 * throughput by supporting a large window of FileIO data
 * that can be in-flight during read or write operations.
 */
#define SBP_MSG_FILEIO_CONFIG_RESP   0x1002

typedef struct SBP_ATTR_PACKED {
  u32 sequence;          /**< Advice sequence number */
  u32 window_size;       /**< The number of SBP packets in the data in-flight window */
  u32 batch_size;        /**< The number of SBP packets sent in one PDU */
  u32 fileio_version;    /**< The version of FileIO that is supported */
} msg_fileio_config_resp_t;
 

/** \} */
static inline void static_asserts_for_module_MSG_FILEIO_READ_REQ(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_fileio_read_req_t, sequence ) == 0, "Offset of sequence in msg_fileio_read_req_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_fileio_read_req_t, sequence ) == 0, offset_of_sequence_in_msg_fileio_read_req_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_fileio_read_req_t, offset ) == 0 + sizeof(u32), "Offset of offset in msg_fileio_read_req_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_fileio_read_req_t, offset ) == 0 + sizeof(u32), offset_of_offset_in_msg_fileio_read_req_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_fileio_read_req_t, chunk_size ) == 0 + sizeof(u32) + sizeof(u32), "Offset of chunk_size in msg_fileio_read_req_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_fileio_read_req_t, chunk_size ) == 0 + sizeof(u32) + sizeof(u32), offset_of_chunk_size_in_msg_fileio_read_req_t_is_incorrect)
#endif
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_fileio_read_req_t, filename ) == 0 + sizeof(u32) + sizeof(u32) + sizeof(u8), "Offset of filename in msg_fileio_read_req_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_fileio_read_req_t, filename ) == 0 + sizeof(u32) + sizeof(u32) + sizeof(u8), offset_of_filename_in_msg_fileio_read_req_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_MSG_FILEIO_READ_RESP(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_fileio_read_resp_t, sequence ) == 0, "Offset of sequence in msg_fileio_read_resp_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_fileio_read_resp_t, sequence ) == 0, offset_of_sequence_in_msg_fileio_read_resp_t_is_incorrect)
#endif
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_fileio_read_resp_t, contents ) == 0 + sizeof(u32), "Offset of contents in msg_fileio_read_resp_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_fileio_read_resp_t, contents ) == 0 + sizeof(u32), offset_of_contents_in_msg_fileio_read_resp_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_MSG_FILEIO_READ_DIR_REQ(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_fileio_read_dir_req_t, sequence ) == 0, "Offset of sequence in msg_fileio_read_dir_req_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_fileio_read_dir_req_t, sequence ) == 0, offset_of_sequence_in_msg_fileio_read_dir_req_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_fileio_read_dir_req_t, offset ) == 0 + sizeof(u32), "Offset of offset in msg_fileio_read_dir_req_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_fileio_read_dir_req_t, offset ) == 0 + sizeof(u32), offset_of_offset_in_msg_fileio_read_dir_req_t_is_incorrect)
#endif
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_fileio_read_dir_req_t, dirname ) == 0 + sizeof(u32) + sizeof(u32), "Offset of dirname in msg_fileio_read_dir_req_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_fileio_read_dir_req_t, dirname ) == 0 + sizeof(u32) + sizeof(u32), offset_of_dirname_in_msg_fileio_read_dir_req_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_MSG_FILEIO_READ_DIR_RESP(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_fileio_read_dir_resp_t, sequence ) == 0, "Offset of sequence in msg_fileio_read_dir_resp_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_fileio_read_dir_resp_t, sequence ) == 0, offset_of_sequence_in_msg_fileio_read_dir_resp_t_is_incorrect)
#endif
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_fileio_read_dir_resp_t, contents ) == 0 + sizeof(u32), "Offset of contents in msg_fileio_read_dir_resp_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_fileio_read_dir_resp_t, contents ) == 0 + sizeof(u32), offset_of_contents_in_msg_fileio_read_dir_resp_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_MSG_FILEIO_REMOVE(void) {
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_fileio_remove_t, filename ) == 0, "Offset of filename in msg_fileio_remove_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_fileio_remove_t, filename ) == 0, offset_of_filename_in_msg_fileio_remove_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_MSG_FILEIO_WRITE_REQ(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_fileio_write_req_t, sequence ) == 0, "Offset of sequence in msg_fileio_write_req_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_fileio_write_req_t, sequence ) == 0, offset_of_sequence_in_msg_fileio_write_req_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_fileio_write_req_t, offset ) == 0 + sizeof(u32), "Offset of offset in msg_fileio_write_req_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_fileio_write_req_t, offset ) == 0 + sizeof(u32), offset_of_offset_in_msg_fileio_write_req_t_is_incorrect)
#endif
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_fileio_write_req_t, filename ) == 0 + sizeof(u32) + sizeof(u32), "Offset of filename in msg_fileio_write_req_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_fileio_write_req_t, filename ) == 0 + sizeof(u32) + sizeof(u32), offset_of_filename_in_msg_fileio_write_req_t_is_incorrect)
#endif
#endif
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
#ifdef __cplusplus
static_assert(offsetof(msg_fileio_write_req_t, data ) == 0 + sizeof(u32) + sizeof(u32), "Offset of data in msg_fileio_write_req_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_fileio_write_req_t, data ) == 0 + sizeof(u32) + sizeof(u32), offset_of_data_in_msg_fileio_write_req_t_is_incorrect)
#endif
#endif
}

static inline void static_asserts_for_module_MSG_FILEIO_WRITE_RESP(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_fileio_write_resp_t, sequence ) == 0, "Offset of sequence in msg_fileio_write_resp_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_fileio_write_resp_t, sequence ) == 0, offset_of_sequence_in_msg_fileio_write_resp_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_FILEIO_CONFIG_REQ(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_fileio_config_req_t, sequence ) == 0, "Offset of sequence in msg_fileio_config_req_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_fileio_config_req_t, sequence ) == 0, offset_of_sequence_in_msg_fileio_config_req_t_is_incorrect)
#endif
}

static inline void static_asserts_for_module_MSG_FILEIO_CONFIG_RESP(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_fileio_config_resp_t, sequence ) == 0, "Offset of sequence in msg_fileio_config_resp_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_fileio_config_resp_t, sequence ) == 0, offset_of_sequence_in_msg_fileio_config_resp_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_fileio_config_resp_t, window_size ) == 0 + sizeof(u32), "Offset of window_size in msg_fileio_config_resp_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_fileio_config_resp_t, window_size ) == 0 + sizeof(u32), offset_of_window_size_in_msg_fileio_config_resp_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_fileio_config_resp_t, batch_size ) == 0 + sizeof(u32) + sizeof(u32), "Offset of batch_size in msg_fileio_config_resp_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_fileio_config_resp_t, batch_size ) == 0 + sizeof(u32) + sizeof(u32), offset_of_batch_size_in_msg_fileio_config_resp_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_fileio_config_resp_t, fileio_version ) == 0 + sizeof(u32) + sizeof(u32) + sizeof(u32), "Offset of fileio_version in msg_fileio_config_resp_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_fileio_config_resp_t, fileio_version ) == 0 + sizeof(u32) + sizeof(u32) + sizeof(u32), offset_of_fileio_version_in_msg_fileio_config_resp_t_is_incorrect)
#endif
}


SBP_PACK_END

#endif /* LIBSBP_FILE_IO_MESSAGES_H */
