#ifndef LIBSBP_FILE_IO_MESSAGES_H
#define LIBSBP_FILE_IO_MESSAGES_H

#include <endian.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
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

typedef struct {
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

static inline size_t sbp_packed_size_sbp_msg_fileio_read_req_t(
    const sbp_msg_fileio_read_req_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->sequence) + sizeof(msg->offset) +
         sizeof(msg->chunk_size) + (strlen(msg->filename) + 1);
}

static inline bool sbp_pack_sbp_msg_fileio_read_req_t(
    u8 *buf, size_t len, const sbp_msg_fileio_read_req_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_fileio_read_req_t(msg) > len) {
    return false;
  }

  if (offset + 4 > len) {
    return false;
  }
  u32 msgsequence = msg->sequence;
  msgsequence = htole32(msgsequence);
  memcpy(buf + offset, &msgsequence, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgoffset = msg->offset;
  msgoffset = htole32(msgoffset);
  memcpy(buf + offset, &msgoffset, 4);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgchunk_size = msg->chunk_size;
  memcpy(buf + offset, &msgchunk_size, 1);
  offset += 1;
  strcpy((char *)(buf + offset), msg->filename);
  offset += strlen(msg->filename) + 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_read_req_t(
    const u8 *buf, size_t len, sbp_msg_fileio_read_req_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->sequence, buf + offset, 4);
  msg->sequence = le32toh(msg->sequence);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->offset, buf + offset, 4);
  msg->offset = le32toh(msg->offset);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->chunk_size, buf + offset, 1);
  offset += 1;
  strcpy(msg->filename, (const char *)buf + offset);
  offset += strlen(msg->filename) + 1;
  return true;
}
/** File read from the file system (host <= device)
 *
 * The file read message reads a certain length (up to 255 bytes)
 * from a given offset into a file, and returns the data in a
 * message where the message length field indicates how many bytes
 * were succesfully read. The sequence number in the response is
 * preserved from the request.
 */
#define SBP_MSG_FILEIO_READ_RESP 0x00A3

typedef struct {
  /**
   * Read sequence number
   */
  u32 sequence;
  /**
   * Contents of read file
   */
  u8 contents[251];
  /**
   * Number of items in contents
   */
  u8 n_contents;
} sbp_msg_fileio_read_resp_t;

static inline size_t sbp_packed_size_sbp_msg_fileio_read_resp_t(
    const sbp_msg_fileio_read_resp_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->sequence) + (msg->n_contents * sizeof(msg->contents));
}

static inline bool sbp_pack_sbp_msg_fileio_read_resp_t(
    u8 *buf, size_t len, const sbp_msg_fileio_read_resp_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_fileio_read_resp_t(msg) > len) {
    return false;
  }

  if (offset + 4 > len) {
    return false;
  }
  u32 msgsequence = msg->sequence;
  msgsequence = htole32(msgsequence);
  memcpy(buf + offset, &msgsequence, 4);
  offset += 4;
  for (size_t msgcontents_idx = 0; msgcontents_idx < (size_t)msg->n_contents;
       msgcontents_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    u8 msgcontentsmsgcontents_idx = msg->contents[msgcontents_idx];
    memcpy(buf + offset, &msgcontentsmsgcontents_idx, 1);
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_read_resp_t(
    const u8 *buf, size_t len, sbp_msg_fileio_read_resp_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->sequence, buf + offset, 4);
  msg->sequence = le32toh(msg->sequence);
  offset += 4;
  msg->n_contents = (u8)((len - offset) / 1);

  for (size_t msgcontents_idx = 0; msgcontents_idx < msg->n_contents;
       msgcontents_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->contents[msgcontents_idx], buf + offset, 1);
    offset += 1;
  }
  return true;
}
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

typedef struct {
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

static inline size_t sbp_packed_size_sbp_msg_fileio_read_dir_req_t(
    const sbp_msg_fileio_read_dir_req_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->sequence) + sizeof(msg->offset) +
         (strlen(msg->dirname) + 1);
}

static inline bool sbp_pack_sbp_msg_fileio_read_dir_req_t(
    u8 *buf, size_t len, const sbp_msg_fileio_read_dir_req_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_fileio_read_dir_req_t(msg) > len) {
    return false;
  }

  if (offset + 4 > len) {
    return false;
  }
  u32 msgsequence = msg->sequence;
  msgsequence = htole32(msgsequence);
  memcpy(buf + offset, &msgsequence, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgoffset = msg->offset;
  msgoffset = htole32(msgoffset);
  memcpy(buf + offset, &msgoffset, 4);
  offset += 4;
  strcpy((char *)(buf + offset), msg->dirname);
  offset += strlen(msg->dirname) + 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_read_dir_req_t(
    const u8 *buf, size_t len, sbp_msg_fileio_read_dir_req_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->sequence, buf + offset, 4);
  msg->sequence = le32toh(msg->sequence);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->offset, buf + offset, 4);
  msg->offset = le32toh(msg->offset);
  offset += 4;
  strcpy(msg->dirname, (const char *)buf + offset);
  offset += strlen(msg->dirname) + 1;
  return true;
}
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

typedef struct {
  /**
   * Read sequence number
   */
  u32 sequence;
  /**
   * Contents of read directory
   */
  u8 contents[251];
  /**
   * Number of items in contents
   */
  u8 n_contents;
} sbp_msg_fileio_read_dir_resp_t;

static inline size_t sbp_packed_size_sbp_msg_fileio_read_dir_resp_t(
    const sbp_msg_fileio_read_dir_resp_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->sequence) + (msg->n_contents * sizeof(msg->contents));
}

static inline bool sbp_pack_sbp_msg_fileio_read_dir_resp_t(
    u8 *buf, size_t len, const sbp_msg_fileio_read_dir_resp_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_fileio_read_dir_resp_t(msg) > len) {
    return false;
  }

  if (offset + 4 > len) {
    return false;
  }
  u32 msgsequence = msg->sequence;
  msgsequence = htole32(msgsequence);
  memcpy(buf + offset, &msgsequence, 4);
  offset += 4;
  for (size_t msgcontents_idx = 0; msgcontents_idx < (size_t)msg->n_contents;
       msgcontents_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    u8 msgcontentsmsgcontents_idx = msg->contents[msgcontents_idx];
    memcpy(buf + offset, &msgcontentsmsgcontents_idx, 1);
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_read_dir_resp_t(
    const u8 *buf, size_t len, sbp_msg_fileio_read_dir_resp_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->sequence, buf + offset, 4);
  msg->sequence = le32toh(msg->sequence);
  offset += 4;
  msg->n_contents = (u8)((len - offset) / 1);

  for (size_t msgcontents_idx = 0; msgcontents_idx < msg->n_contents;
       msgcontents_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->contents[msgcontents_idx], buf + offset, 1);
    offset += 1;
  }
  return true;
}
/** Delete a file from the file system (host => device)
 *
 * The file remove message deletes a file from the file system.
 * If the message is invalid, a followup MSG_PRINT message will
 * print "Invalid fileio remove message". A device will only
 * process this message when it is received from sender ID 0x42.
 */
#define SBP_MSG_FILEIO_REMOVE 0x00AC

typedef struct {
  /**
   * Name of the file to delete
   */
  char filename[255];
} sbp_msg_fileio_remove_t;

static inline size_t sbp_packed_size_sbp_msg_fileio_remove_t(
    const sbp_msg_fileio_remove_t *msg) {
  (void)msg;
  return 0 + (strlen(msg->filename) + 1);
}

static inline bool sbp_pack_sbp_msg_fileio_remove_t(
    u8 *buf, size_t len, const sbp_msg_fileio_remove_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_fileio_remove_t(msg) > len) {
    return false;
  }

  strcpy((char *)(buf + offset), msg->filename);
  offset += strlen(msg->filename) + 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_remove_t(
    const u8 *buf, size_t len, sbp_msg_fileio_remove_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  strcpy(msg->filename, (const char *)buf + offset);
  offset += strlen(msg->filename) + 1;
  return true;
}
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

typedef struct {
  /**
   * Write sequence number
   */
  u32 sequence;
  /**
   * Offset into the file at which to start writing in bytes[bytes]
   */
  u32 offset;
  /**
   * Name of the file to write to
   */
  char filename[247];
  /**
   * Variable-length array of data to write
   */
  u8 data[246];
  /**
   * Number of items in data
   */
  u8 n_data;
} sbp_msg_fileio_write_req_t;

static inline size_t sbp_packed_size_sbp_msg_fileio_write_req_t(
    const sbp_msg_fileio_write_req_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->sequence) + sizeof(msg->offset) +
         (strlen(msg->filename) + 1) + (msg->n_data * sizeof(msg->data));
}

static inline bool sbp_pack_sbp_msg_fileio_write_req_t(
    u8 *buf, size_t len, const sbp_msg_fileio_write_req_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_fileio_write_req_t(msg) > len) {
    return false;
  }

  if (offset + 4 > len) {
    return false;
  }
  u32 msgsequence = msg->sequence;
  msgsequence = htole32(msgsequence);
  memcpy(buf + offset, &msgsequence, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgoffset = msg->offset;
  msgoffset = htole32(msgoffset);
  memcpy(buf + offset, &msgoffset, 4);
  offset += 4;
  strcpy((char *)(buf + offset), msg->filename);
  offset += strlen(msg->filename) + 1;
  for (size_t msgdata_idx = 0; msgdata_idx < (size_t)msg->n_data;
       msgdata_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    u8 msgdatamsgdata_idx = msg->data[msgdata_idx];
    memcpy(buf + offset, &msgdatamsgdata_idx, 1);
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_write_req_t(
    const u8 *buf, size_t len, sbp_msg_fileio_write_req_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->sequence, buf + offset, 4);
  msg->sequence = le32toh(msg->sequence);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->offset, buf + offset, 4);
  msg->offset = le32toh(msg->offset);
  offset += 4;
  strcpy(msg->filename, (const char *)buf + offset);
  offset += strlen(msg->filename) + 1;
  msg->n_data = (u8)((len - offset) / 1);

  for (size_t msgdata_idx = 0; msgdata_idx < msg->n_data; msgdata_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->data[msgdata_idx], buf + offset, 1);
    offset += 1;
  }
  return true;
}
/** File written to (host <= device)
 *
 * The file write message writes a certain length (up to 255 bytes)
 * of data to a file at a given offset. The message is a copy of the
 * original MSG_FILEIO_WRITE_REQ message to check integrity of the
 * write. The sequence number in the response is preserved from the
 * request.
 */
#define SBP_MSG_FILEIO_WRITE_RESP 0x00AB

typedef struct {
  /**
   * Write sequence number
   */
  u32 sequence;
} sbp_msg_fileio_write_resp_t;

static inline size_t sbp_packed_size_sbp_msg_fileio_write_resp_t(
    const sbp_msg_fileio_write_resp_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->sequence);
}

static inline bool sbp_pack_sbp_msg_fileio_write_resp_t(
    u8 *buf, size_t len, const sbp_msg_fileio_write_resp_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_fileio_write_resp_t(msg) > len) {
    return false;
  }

  if (offset + 4 > len) {
    return false;
  }
  u32 msgsequence = msg->sequence;
  msgsequence = htole32(msgsequence);
  memcpy(buf + offset, &msgsequence, 4);
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_write_resp_t(
    const u8 *buf, size_t len, sbp_msg_fileio_write_resp_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->sequence, buf + offset, 4);
  msg->sequence = le32toh(msg->sequence);
  offset += 4;
  return true;
}
/** Request advice on the optimal configuration for FileIO.
 *
 * Requests advice on the optimal configuration for a FileIO
 * transfer.  Newer version of FileIO can support greater
 * throughput by supporting a large window of FileIO data
 * that can be in-flight during read or write operations.
 */
#define SBP_MSG_FILEIO_CONFIG_REQ 0x1001

typedef struct {
  /**
   * Advice sequence number
   */
  u32 sequence;
} sbp_msg_fileio_config_req_t;

static inline size_t sbp_packed_size_sbp_msg_fileio_config_req_t(
    const sbp_msg_fileio_config_req_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->sequence);
}

static inline bool sbp_pack_sbp_msg_fileio_config_req_t(
    u8 *buf, size_t len, const sbp_msg_fileio_config_req_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_fileio_config_req_t(msg) > len) {
    return false;
  }

  if (offset + 4 > len) {
    return false;
  }
  u32 msgsequence = msg->sequence;
  msgsequence = htole32(msgsequence);
  memcpy(buf + offset, &msgsequence, 4);
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_config_req_t(
    const u8 *buf, size_t len, sbp_msg_fileio_config_req_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->sequence, buf + offset, 4);
  msg->sequence = le32toh(msg->sequence);
  offset += 4;
  return true;
}
/** Response with advice on the optimal configuration for FileIO.

 *
* The advice on the optimal configuration for a FileIO
* transfer.  Newer version of FileIO can support greater
* throughput by supporting a large window of FileIO data
* that can be in-flight during read or write operations.
 */
#define SBP_MSG_FILEIO_CONFIG_RESP 0x1002

typedef struct {
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

static inline size_t sbp_packed_size_sbp_msg_fileio_config_resp_t(
    const sbp_msg_fileio_config_resp_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->sequence) + sizeof(msg->window_size) +
         sizeof(msg->batch_size) + sizeof(msg->fileio_version);
}

static inline bool sbp_pack_sbp_msg_fileio_config_resp_t(
    u8 *buf, size_t len, const sbp_msg_fileio_config_resp_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_fileio_config_resp_t(msg) > len) {
    return false;
  }

  if (offset + 4 > len) {
    return false;
  }
  u32 msgsequence = msg->sequence;
  msgsequence = htole32(msgsequence);
  memcpy(buf + offset, &msgsequence, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgwindow_size = msg->window_size;
  msgwindow_size = htole32(msgwindow_size);
  memcpy(buf + offset, &msgwindow_size, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgbatch_size = msg->batch_size;
  msgbatch_size = htole32(msgbatch_size);
  memcpy(buf + offset, &msgbatch_size, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgfileio_version = msg->fileio_version;
  msgfileio_version = htole32(msgfileio_version);
  memcpy(buf + offset, &msgfileio_version, 4);
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_config_resp_t(
    const u8 *buf, size_t len, sbp_msg_fileio_config_resp_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->sequence, buf + offset, 4);
  msg->sequence = le32toh(msg->sequence);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->window_size, buf + offset, 4);
  msg->window_size = le32toh(msg->window_size);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->batch_size, buf + offset, 4);
  msg->batch_size = le32toh(msg->batch_size);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->fileio_version, buf + offset, 4);
  msg->fileio_version = le32toh(msg->fileio_version);
  offset += 4;
  return true;
}

#endif /* LIBSBP_FILE_IO_MESSAGES_H */