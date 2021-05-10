#ifndef LIBSBP_FILE_IO_MESSAGES_H
#define LIBSBP_FILE_IO_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/string2.h>
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

typedef struct
{

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
  sbp_null_terminated_string_t filename;
} sbp_msg_fileio_read_req_t;

#if 0
  static const sbp_null_terminated_string_format_t sbp_msg_fileio_read_req_t_filename_format = {
    /* .encoding = */ SBP_STRING_NULL_TERMINATED,
    /* .min_sections = */0u,
    /* .max_sections = */0u,
    /* .terminator = */0u,
    /* .max_encoded_len = */ 246u
  };
  static inline void sbp_msg_fileio_read_req_t_filename_init(sbp_null_terminated_string_t s) { sbp_null_terminated_string_init(s, &sbp_msg_fileio_read_req_t_filename_format); }
  static inline uint8_t sbp_msg_fileio_read_req_t_filename_packed_len(const sbp_null_terminated_string_t s) { return sbp_null_terminated_string_packed_len(s, &sbp_msg_fileio_read_req_t_filename_format); }
  static inline uint8_t sbp_msg_fileio_read_req_t_filename_pack(const sbp_null_terminated_string_t s, uint8_t *buf, uint8_t buf_len) { return sbp_null_terminated_string_pack(s, &sbp_msg_fileio_read_req_t_filename_format, buf, buf_len); }
  static inline uint8_t sbp_msg_fileio_read_req_t_filename_unpack(sbp_null_terminated_string_t s, const uint8_t *buf, uint8_t buf_len) { return sbp_null_terminated_string_unpack(s, &sbp_msg_fileio_read_req_t_filename_format, buf, buf_len); }
  static inline uint8_t sbp_msg_fileio_read_req_t_filename_space_remaining(const sbp_null_terminated_string_t s) { return sbp_null_terminated_string_space_remaining(s, &sbp_msg_fileio_read_req_t_filename_format); }
  static inline uint8_t sbp_msg_fileio_read_req_t_filename_count_sections(const sbp_null_terminated_string_t s) { return sbp_null_terminated_string_count_sections(s, &sbp_msg_fileio_read_req_t_filename_format); }
  static inline const char *sbp_msg_fileio_read_req_t_filename_get_section(const sbp_null_terminated_string_t s, uint8_t section) { return sbp_null_terminated_string_get_section(s, &sbp_msg_fileio_read_req_t_filename_format, section); }
  static inline bool sbp_msg_fileio_read_req_t_filename_append_section(sbp_null_terminated_string_t s, const char *new_str) { return sbp_null_terminated_string_append_section(s, &sbp_msg_fileio_read_req_t_filename_format, new_str); }
#endif
/** File read from the file system (host <= device)
 *
 * The file read message reads a certain length (up to 255 bytes)
 * from a given offset into a file, and returns the data in a
 * message where the message length field indicates how many bytes
 * were succesfully read. The sequence number in the response is
 * preserved from the request.
 */
#define SBP_MSG_FILEIO_READ_RESP 0x00A3

typedef struct
{

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
  u8 contents_count;
} sbp_msg_fileio_read_resp_t;

#if 0
#endif
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

typedef struct
{

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
  sbp_null_terminated_string_t dirname;
} sbp_msg_fileio_read_dir_req_t;

#if 0
  static const sbp_null_terminated_string_format_t sbp_msg_fileio_read_dir_req_t_dirname_format = {
    /* .encoding = */ SBP_STRING_NULL_TERMINATED,
    /* .min_sections = */0u,
    /* .max_sections = */0u,
    /* .terminator = */0u,
    /* .max_encoded_len = */ 247u
  };
  static inline void sbp_msg_fileio_read_dir_req_t_dirname_init(sbp_null_terminated_string_t s) { sbp_null_terminated_string_init(s, &sbp_msg_fileio_read_dir_req_t_dirname_format); }
  static inline uint8_t sbp_msg_fileio_read_dir_req_t_dirname_packed_len(const sbp_null_terminated_string_t s) { return sbp_null_terminated_string_packed_len(s, &sbp_msg_fileio_read_dir_req_t_dirname_format); }
  static inline uint8_t sbp_msg_fileio_read_dir_req_t_dirname_pack(const sbp_null_terminated_string_t s, uint8_t *buf, uint8_t buf_len) { return sbp_null_terminated_string_pack(s, &sbp_msg_fileio_read_dir_req_t_dirname_format, buf, buf_len); }
  static inline uint8_t sbp_msg_fileio_read_dir_req_t_dirname_unpack(sbp_null_terminated_string_t s, const uint8_t *buf, uint8_t buf_len) { return sbp_null_terminated_string_unpack(s, &sbp_msg_fileio_read_dir_req_t_dirname_format, buf, buf_len); }
  static inline uint8_t sbp_msg_fileio_read_dir_req_t_dirname_space_remaining(const sbp_null_terminated_string_t s) { return sbp_null_terminated_string_space_remaining(s, &sbp_msg_fileio_read_dir_req_t_dirname_format); }
  static inline uint8_t sbp_msg_fileio_read_dir_req_t_dirname_count_sections(const sbp_null_terminated_string_t s) { return sbp_null_terminated_string_count_sections(s, &sbp_msg_fileio_read_dir_req_t_dirname_format); }
  static inline const char *sbp_msg_fileio_read_dir_req_t_dirname_get_section(const sbp_null_terminated_string_t s, uint8_t section) { return sbp_null_terminated_string_get_section(s, &sbp_msg_fileio_read_dir_req_t_dirname_format, section); }
  static inline bool sbp_msg_fileio_read_dir_req_t_dirname_append_section(sbp_null_terminated_string_t s, const char *new_str) { return sbp_null_terminated_string_append_section(s, &sbp_msg_fileio_read_dir_req_t_dirname_format, new_str); }
#endif
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

typedef struct
{

  /**
   * Read sequence number
   */
  u32 sequence;
  /**
   * Contents of read directory
   */
  sbp_sequence_string_t contents;
} sbp_msg_fileio_read_dir_resp_t;

#if 0
  static const sbp_sequence_string_format_t sbp_msg_fileio_read_dir_resp_t_contents_format = {
    /* .encoding = */ SBP_STRING_SEQUENCE,
    /* .min_sections = */0u,
    /* .max_sections = */0u,
    /* .terminator = */255u,
    /* .max_encoded_len = */ 251u
  };
  static inline void sbp_msg_fileio_read_dir_resp_t_contents_init(sbp_sequence_string_t s) { sbp_sequence_string_init(s, &sbp_msg_fileio_read_dir_resp_t_contents_format); }
  static inline uint8_t sbp_msg_fileio_read_dir_resp_t_contents_packed_len(const sbp_sequence_string_t s) { return sbp_sequence_string_packed_len(s, &sbp_msg_fileio_read_dir_resp_t_contents_format); }
  static inline uint8_t sbp_msg_fileio_read_dir_resp_t_contents_pack(const sbp_sequence_string_t s, uint8_t *buf, uint8_t buf_len) { return sbp_sequence_string_pack(s, &sbp_msg_fileio_read_dir_resp_t_contents_format, buf, buf_len); }
  static inline uint8_t sbp_msg_fileio_read_dir_resp_t_contents_unpack(sbp_sequence_string_t s, const uint8_t *buf, uint8_t buf_len) { return sbp_sequence_string_unpack(s, &sbp_msg_fileio_read_dir_resp_t_contents_format, buf, buf_len); }
  static inline uint8_t sbp_msg_fileio_read_dir_resp_t_contents_space_remaining(const sbp_sequence_string_t s) { return sbp_sequence_string_space_remaining(s, &sbp_msg_fileio_read_dir_resp_t_contents_format); }
  static inline uint8_t sbp_msg_fileio_read_dir_resp_t_contents_count_sections(const sbp_sequence_string_t s) { return sbp_sequence_string_count_sections(s, &sbp_msg_fileio_read_dir_resp_t_contents_format); }
  static inline const char *sbp_msg_fileio_read_dir_resp_t_contents_get_section(const sbp_sequence_string_t s, uint8_t section) { return sbp_sequence_string_get_section(s, &sbp_msg_fileio_read_dir_resp_t_contents_format, section); }
  static inline bool sbp_msg_fileio_read_dir_resp_t_contents_append_section(sbp_sequence_string_t s, const char *new_str) { return sbp_sequence_string_append_section(s, &sbp_msg_fileio_read_dir_resp_t_contents_format, new_str); }
#endif
/** Delete a file from the file system (host => device)
 *
 * The file remove message deletes a file from the file system.
 * If the message is invalid, a followup MSG_PRINT message will
 * print "Invalid fileio remove message". A device will only
 * process this message when it is received from sender ID 0x42.
 */
#define SBP_MSG_FILEIO_REMOVE 0x00AC

typedef struct
{

  /**
   * Name of the file to delete
   */
  sbp_null_terminated_string_t filename;
} sbp_msg_fileio_remove_t;

#if 0
  static const sbp_null_terminated_string_format_t sbp_msg_fileio_remove_t_filename_format = {
    /* .encoding = */ SBP_STRING_NULL_TERMINATED,
    /* .min_sections = */0u,
    /* .max_sections = */0u,
    /* .terminator = */0u,
    /* .max_encoded_len = */ 255u
  };
  static inline void sbp_msg_fileio_remove_t_filename_init(sbp_null_terminated_string_t s) { sbp_null_terminated_string_init(s, &sbp_msg_fileio_remove_t_filename_format); }
  static inline uint8_t sbp_msg_fileio_remove_t_filename_packed_len(const sbp_null_terminated_string_t s) { return sbp_null_terminated_string_packed_len(s, &sbp_msg_fileio_remove_t_filename_format); }
  static inline uint8_t sbp_msg_fileio_remove_t_filename_pack(const sbp_null_terminated_string_t s, uint8_t *buf, uint8_t buf_len) { return sbp_null_terminated_string_pack(s, &sbp_msg_fileio_remove_t_filename_format, buf, buf_len); }
  static inline uint8_t sbp_msg_fileio_remove_t_filename_unpack(sbp_null_terminated_string_t s, const uint8_t *buf, uint8_t buf_len) { return sbp_null_terminated_string_unpack(s, &sbp_msg_fileio_remove_t_filename_format, buf, buf_len); }
  static inline uint8_t sbp_msg_fileio_remove_t_filename_space_remaining(const sbp_null_terminated_string_t s) { return sbp_null_terminated_string_space_remaining(s, &sbp_msg_fileio_remove_t_filename_format); }
  static inline uint8_t sbp_msg_fileio_remove_t_filename_count_sections(const sbp_null_terminated_string_t s) { return sbp_null_terminated_string_count_sections(s, &sbp_msg_fileio_remove_t_filename_format); }
  static inline const char *sbp_msg_fileio_remove_t_filename_get_section(const sbp_null_terminated_string_t s, uint8_t section) { return sbp_null_terminated_string_get_section(s, &sbp_msg_fileio_remove_t_filename_format, section); }
  static inline bool sbp_msg_fileio_remove_t_filename_append_section(sbp_null_terminated_string_t s, const char *new_str) { return sbp_null_terminated_string_append_section(s, &sbp_msg_fileio_remove_t_filename_format, new_str); }
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
#define SBP_MSG_FILEIO_WRITE_REQ 0x00AD

typedef struct
{

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
  sbp_null_terminated_string_t filename;
  /**
   * Variable-length array of data to write
   */
  u8 data[247];
  /**
   * Number of items in data
   */
  u8 data_count;
} sbp_msg_fileio_write_req_t;

#if 0
  static const sbp_null_terminated_string_format_t sbp_msg_fileio_write_req_t_filename_format = {
    /* .encoding = */ SBP_STRING_NULL_TERMINATED,
    /* .min_sections = */0u,
    /* .max_sections = */0u,
    /* .terminator = */0u,
    /* .max_encoded_len = */ 247u
  };
  static inline void sbp_msg_fileio_write_req_t_filename_init(sbp_null_terminated_string_t s) { sbp_null_terminated_string_init(s, &sbp_msg_fileio_write_req_t_filename_format); }
  static inline uint8_t sbp_msg_fileio_write_req_t_filename_packed_len(const sbp_null_terminated_string_t s) { return sbp_null_terminated_string_packed_len(s, &sbp_msg_fileio_write_req_t_filename_format); }
  static inline uint8_t sbp_msg_fileio_write_req_t_filename_pack(const sbp_null_terminated_string_t s, uint8_t *buf, uint8_t buf_len) { return sbp_null_terminated_string_pack(s, &sbp_msg_fileio_write_req_t_filename_format, buf, buf_len); }
  static inline uint8_t sbp_msg_fileio_write_req_t_filename_unpack(sbp_null_terminated_string_t s, const uint8_t *buf, uint8_t buf_len) { return sbp_null_terminated_string_unpack(s, &sbp_msg_fileio_write_req_t_filename_format, buf, buf_len); }
  static inline uint8_t sbp_msg_fileio_write_req_t_filename_space_remaining(const sbp_null_terminated_string_t s) { return sbp_null_terminated_string_space_remaining(s, &sbp_msg_fileio_write_req_t_filename_format); }
  static inline uint8_t sbp_msg_fileio_write_req_t_filename_count_sections(const sbp_null_terminated_string_t s) { return sbp_null_terminated_string_count_sections(s, &sbp_msg_fileio_write_req_t_filename_format); }
  static inline const char *sbp_msg_fileio_write_req_t_filename_get_section(const sbp_null_terminated_string_t s, uint8_t section) { return sbp_null_terminated_string_get_section(s, &sbp_msg_fileio_write_req_t_filename_format, section); }
  static inline bool sbp_msg_fileio_write_req_t_filename_append_section(sbp_null_terminated_string_t s, const char *new_str) { return sbp_null_terminated_string_append_section(s, &sbp_msg_fileio_write_req_t_filename_format, new_str); }
#endif
/** File written to (host <= device)
 *
 * The file write message writes a certain length (up to 255 bytes)
 * of data to a file at a given offset. The message is a copy of the
 * original MSG_FILEIO_WRITE_REQ message to check integrity of the
 * write. The sequence number in the response is preserved from the
 * request.
 */
#define SBP_MSG_FILEIO_WRITE_RESP 0x00AB

typedef struct
{

  /**
   * Write sequence number
   */
  u32 sequence;
} sbp_msg_fileio_write_resp_t;

#if 0
#endif
/** Request advice on the optimal configuration for FileIO.
 *
 * Requests advice on the optimal configuration for a FileIO
 * transfer.  Newer version of FileIO can support greater
 * throughput by supporting a large window of FileIO data
 * that can be in-flight during read or write operations.
 */
#define SBP_MSG_FILEIO_CONFIG_REQ 0x1001

typedef struct
{

  /**
   * Advice sequence number
   */
  u32 sequence;
} sbp_msg_fileio_config_req_t;

#if 0
#endif
/** Response with advice on the optimal configuration for FileIO.

 *
* The advice on the optimal configuration for a FileIO
* transfer.  Newer version of FileIO can support greater
* throughput by supporting a large window of FileIO data
* that can be in-flight during read or write operations.
 */
#define SBP_MSG_FILEIO_CONFIG_RESP 0x1002

typedef struct
{

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

#if 0
#endif

#include <libsbp/unpacked/file_io_operators.h>
#include <libsbp/unpacked/file_io_packers.h>

#endif /* LIBSBP_FILE_IO_MESSAGES_H */
