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
#define SBP_MSG_FILEIO_READ_REQ 0x00A8

typedef struct SBP_ATTR_PACKED {
  /**
   * Read sequence number
   */
  u32 sequence;
  /**
   * File offset[bytes]
   */
  u32 offset;
  /**
   * Chunk size to read[bytes]
   */
  u8 chunk_size;
  /**
   * Name of the file to read from
   */
  char filename[246];
} sbp_msg_fileio_read_req_t;
/** File read from the file system (host <= device)
 *
 * The file read message reads a certain length (up to 255 bytes)
 * from a given offset into a file, and returns the data in a
 * message where the message length field indicates how many bytes
 * were succesfully read. The sequence number in the response is
 * preserved from the request.
 */
#define SBP_MSG_FILEIO_READ_RESP 0x00A3

typedef struct SBP_ATTR_PACKED {
  /**
   * Read sequence number
   */
  u32 sequence;
  /**
   * Contents of read file
   */
  u8 contents[251];
} sbp_msg_fileio_read_resp_t;
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
#define SBP_MSG_FILEIO_READ_DIR_REQ 0x00A9

typedef struct SBP_ATTR_PACKED {
  /**
   * Read sequence number
   */
  u32 sequence;
  /**
   * The offset to skip the first n elements of the file list
   */
  u32 offset;
  /**
   * Name of the directory to list
   */
  char dirname[247];
} sbp_msg_fileio_read_dir_req_t;
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
  /**
   * Read sequence number
   */
  u32 sequence;
  /**
   * Contents of read directory
   */
  u8 contents[251];
} sbp_msg_fileio_read_dir_resp_t;
/** Delete a file from the file system (host => device)
 *
 * The file remove message deletes a file from the file system.
 * If the message is invalid, a followup MSG_PRINT message will
 * print "Invalid fileio remove message". A device will only
 * process this message when it is received from sender ID 0x42.
 */
#define SBP_MSG_FILEIO_REMOVE 0x00AC

typedef struct SBP_ATTR_PACKED {
  /**
   * Name of the file to delete
   */
  char filename[255];
} sbp_msg_fileio_remove_t;
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
#define SBP_MSG_FILEIO_WRITE_REQ 0x00AD

typedef struct SBP_ATTR_PACKED {
  /**
   * Write sequence number
   */
  u32 sequence;
  /**
   * Offset into the file at which to start writing in bytes[bytes]
   */
  u32 offset;
  /**
   * NULL terminated filename to write to followed by
   * variable-length array of data to write
   */
  u8 data[247];
} sbp_msg_fileio_write_req_t;
/** File written to (host <= device)
 *
 * The file write message writes a certain length (up to 255 bytes)
 * of data to a file at a given offset. The message is a copy of the
 * original MSG_FILEIO_WRITE_REQ message to check integrity of the
 * write. The sequence number in the response is preserved from the
 * request.
 */
#define SBP_MSG_FILEIO_WRITE_RESP 0x00AB

typedef struct SBP_ATTR_PACKED {
  /**
   * Write sequence number
   */
  u32 sequence;
} sbp_msg_fileio_write_resp_t;
/** Request advice on the optimal configuration for FileIO.
 *
 * Requests advice on the optimal configuration for a FileIO
 * transfer.  Newer version of FileIO can support greater
 * throughput by supporting a large window of FileIO data
 * that can be in-flight during read or write operations.
 */
#define SBP_MSG_FILEIO_CONFIG_REQ 0x1001

typedef struct SBP_ATTR_PACKED {
  /**
   * Advice sequence number
   */
  u32 sequence;
} sbp_msg_fileio_config_req_t;
/** Response with advice on the optimal configuration for FileIO.

 *
* The advice on the optimal configuration for a FileIO
* transfer.  Newer version of FileIO can support greater
* throughput by supporting a large window of FileIO data
* that can be in-flight during read or write operations.
 */
#define SBP_MSG_FILEIO_CONFIG_RESP 0x1002

typedef struct SBP_ATTR_PACKED {
  /**
   * Advice sequence number
   */
  u32 sequence;
  /**
   * The number of SBP packets in the data in-flight window
   */
  u32 window_size;
  /**
   * The number of SBP packets sent in one PDU
   */
  u32 batch_size;
  /**
   * The version of FileIO that is supported
   */
  u32 fileio_version;
} sbp_msg_fileio_config_resp_t;

SBP_PACK_END

#endif /* LIBSBP_FILE_IO_MESSAGES_H */