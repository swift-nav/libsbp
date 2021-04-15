/*
 * Copyright (C) 2021 Swift Navigation Inc.
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

#ifndef LIBSBP_CPP_FILE_IO_MESSAGES_H
#define LIBSBP_CPP_FILE_IO_MESSAGES_H

#include <cstddef>
#include <libsbp/common.h>
#include <libsbp/sbp.h>

namespace sbp {
  
  /**
   * Read file from the file system (host => device)
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
  constexpr u16 MSG_FILEIO_READ_REQ = 0x00A8;

  template<size_t FILENAME_COUNT = (SBP_MAX_PAYLOAD_LEN - sizeof(u32) + sizeof(u32) + sizeof(u8) + 0) / sizeof(char)>
  struct SBP_ATTR_PACKED MsgFileioReadReq {
    u32 sequence; /** Read sequence number */
    u32 offset; /** File offset [bytes] */
    u8 chunk_size; /** Chunk size to read [bytes] */
    char filename[FILENAME_COUNT]; /** Name of the file to read from */
  };

  
  /**
   * File read from the file system (host <= device)
   *
   * The file read message reads a certain length (up to 255 bytes)
   * from a given offset into a file, and returns the data in a
   * message where the message length field indicates how many bytes
   * were succesfully read. The sequence number in the response is
   * preserved from the request.
   */
  constexpr u16 MSG_FILEIO_READ_RESP = 0x00A3;

  template<size_t CONTENTS_COUNT = (SBP_MAX_PAYLOAD_LEN - sizeof(u32) + 0) / sizeof(u8)>
  struct SBP_ATTR_PACKED MsgFileioReadResp {
    u32 sequence; /** Read sequence number */
    u8 contents[CONTENTS_COUNT]; /** Contents of read file */
  };

  
  /**
   * List files in a directory (host => device)
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
  constexpr u16 MSG_FILEIO_READ_DIR_REQ = 0x00A9;

  template<size_t DIRNAME_COUNT = (SBP_MAX_PAYLOAD_LEN - sizeof(u32) + sizeof(u32) + 0) / sizeof(char)>
  struct SBP_ATTR_PACKED MsgFileioReadDirReq {
    u32 sequence; /** Read sequence number */
    u32 offset; /** The offset to skip the first n elements of the file list
 */
    char dirname[DIRNAME_COUNT]; /** Name of the directory to list */
  };

  
  /**
   * Files listed in a directory (host <= device)
   *
   * The read directory message lists the files in a directory on the
   * device's onboard flash file system. Message contains the directory
   * listings as a NULL delimited list. The listing is chunked over
   * multiple SBP packets and the end of the list is identified by an
   * entry containing just the character 0xFF. The sequence number in
   * the response is preserved from the request.
   */
  constexpr u16 MSG_FILEIO_READ_DIR_RESP = 0x00AA;

  template<size_t CONTENTS_COUNT = (SBP_MAX_PAYLOAD_LEN - sizeof(u32) + 0) / sizeof(u8)>
  struct SBP_ATTR_PACKED MsgFileioReadDirResp {
    u32 sequence; /** Read sequence number */
    u8 contents[CONTENTS_COUNT]; /** Contents of read directory */
  };

  
  /**
   * Delete a file from the file system (host => device)
   *
   * The file remove message deletes a file from the file system.
   * If the message is invalid, a followup MSG_PRINT message will
   * print "Invalid fileio remove message". A device will only
   * process this message when it is received from sender ID 0x42.
   */
  constexpr u16 MSG_FILEIO_REMOVE = 0x00AC;

  template<size_t FILENAME_COUNT = (SBP_MAX_PAYLOAD_LEN - 0) / sizeof(char)>
  struct SBP_ATTR_PACKED MsgFileioRemove {
    char filename[FILENAME_COUNT]; /** Name of the file to delete */
  };

  
  /**
   * File written to (host <= device)
   *
   * The file write message writes a certain length (up to 255 bytes)
   * of data to a file at a given offset. The message is a copy of the
   * original MSG_FILEIO_WRITE_REQ message to check integrity of the
   * write. The sequence number in the response is preserved from the
   * request.
   */
  constexpr u16 MSG_FILEIO_WRITE_RESP = 0x00AB;

  
  struct SBP_ATTR_PACKED MsgFileioWriteResp {
    u32 sequence; /** Write sequence number */
  };

  
  /**
   * Request advice on the optimal configuration for FileIO.
   *
   * Requests advice on the optimal configuration for a FileIO 
   * transfer.  Newer version of FileIO can support greater
   * throughput by supporting a large window of FileIO data
   * that can be in-flight during read or write operations.
   */
  constexpr u16 MSG_FILEIO_CONFIG_REQ = 0x1001;

  
  struct SBP_ATTR_PACKED MsgFileioConfigReq {
    u32 sequence; /** Advice sequence number */
  };

  
  /**
   * Response with advice on the optimal configuration for FileIO.

   *
   * The advice on the optimal configuration for a FileIO
   * transfer.  Newer version of FileIO can support greater
   * throughput by supporting a large window of FileIO data
   * that can be in-flight during read or write operations.
   */
  constexpr u16 MSG_FILEIO_CONFIG_RESP = 0x1002;

  
  struct SBP_ATTR_PACKED MsgFileioConfigResp {
    u32 sequence; /** Advice sequence number */
    u32 window_size; /** The number of SBP packets in the data in-flight window */
    u32 batch_size; /** The number of SBP packets sent in one PDU */
    u32 fileio_version; /** The version of FileIO that is supported */
  };

  

}  // namespace sbp

#endif /* LIBSBP_CPP_FILE_IO_MESSAGES_H */