#ifndef LIBSBP_FILE_IO_MESSAGES_H
#define LIBSBP_FILE_IO_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

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
#define SBP_MSG_FILEIO_READ_REQ      0x00A8

typedef struct {
  
  /**
* Read sequence number
   */
    u32
  sequence
  ;
  /**
* File offset[bytes]
   */
    u32
  offset
  ;
  /**
* Chunk size to read[bytes]
   */
    u8
  chunk_size
  ;
  /**
* Name of the file to read from
   */
  sbp_null_terminated_string_t
  filename
  ;
} sbp_msg_fileio_read_req_t;


#define sbp_msg_fileio_read_req_t_filename_init(f) sbp_null_terminated_string_init(f, 246)
#define sbp_msg_fileio_read_req_t_filename_valid(f) sbp_null_terminated_string_valid(f, 246)
#define sbp_msg_fileio_read_req_t_filename_set(f,s) sbp_null_terminated_string_set(f,s,246)
#define sbp_msg_fileio_read_req_t_filename_printf(f,...) sbp_null_terminated_string_printf(f,246,__VA_ARGS__)
#define sbp_msg_fileio_read_req_t_filename_packed_len(f) sbp_null_terminated_string_packed_len(f,246)
#define sbp_msg_fileio_read_req_t_filename_get(f) sbp_null_terminated_string_get(f,246)
#define sbp_msg_fileio_read_req_t_filename_len(f) ( sbp_msg_fileio_read_req_t_filename_packed_len(f) - 1)
#define sbp_msg_fileio_read_req_t_filename_strcmp(a,b) sbp_null_terminated_string_strcmp(a,b,246)
  /** File read from the file system (host <= device)
   *
 * The file read message reads a certain length (up to 255 bytes)
 * from a given offset into a file, and returns the data in a
 * message where the message length field indicates how many bytes
 * were succesfully read. The sequence number in the response is
 * preserved from the request.
   */
#define SBP_MSG_FILEIO_READ_RESP     0x00A3

typedef struct {
  
  /**
* Read sequence number
   */
    u32
  sequence
  ;
  /**
* Contents of read file
   */
    u8
  contents
    [251]
  ;
  /**
   * Number of items in contents
   */
  u8 contents_count;
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
#define SBP_MSG_FILEIO_READ_DIR_REQ  0x00A9

typedef struct {
  
  /**
* Read sequence number
   */
    u32
  sequence
  ;
  /**
 * The offset to skip the first n elements of the file list
   */
    u32
  offset
  ;
  /**
* Name of the directory to list
   */
  sbp_null_terminated_string_t
  dirname
  ;
} sbp_msg_fileio_read_dir_req_t;


#define sbp_msg_fileio_read_dir_req_t_dirname_init(f) sbp_null_terminated_string_init(f, 247)
#define sbp_msg_fileio_read_dir_req_t_dirname_valid(f) sbp_null_terminated_string_valid(f, 247)
#define sbp_msg_fileio_read_dir_req_t_dirname_set(f,s) sbp_null_terminated_string_set(f,s,247)
#define sbp_msg_fileio_read_dir_req_t_dirname_printf(f,...) sbp_null_terminated_string_printf(f,247,__VA_ARGS__)
#define sbp_msg_fileio_read_dir_req_t_dirname_packed_len(f) sbp_null_terminated_string_packed_len(f,247)
#define sbp_msg_fileio_read_dir_req_t_dirname_get(f) sbp_null_terminated_string_get(f,247)
#define sbp_msg_fileio_read_dir_req_t_dirname_len(f) ( sbp_msg_fileio_read_dir_req_t_dirname_packed_len(f) - 1)
#define sbp_msg_fileio_read_dir_req_t_dirname_strcmp(a,b) sbp_null_terminated_string_strcmp(a,b,247)
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
    u32
  sequence
  ;
  /**
* Contents of read directory
   */
  sbp_sequence_string_t
  contents
  ;
} sbp_msg_fileio_read_dir_resp_t;


#define sbp_msg_fileio_read_dir_resp_t_contents_init(f) sbp_sequence_string_init(f, 251, 255)
#define sbp_msg_fileio_read_dir_resp_t_contents_valid(f) sbp_sequence_string_valid(f, 251, 255)
#define sbp_msg_fileio_read_dir_resp_t_contents_packed_len(f) sbp_sequence_string_packed_len(f, 251, 255)
#define sbp_msg_fileio_read_dir_resp_t_contents_append(f,s) sbp_sequence_string_append(f, s, 251, 255)
#define sbp_msg_fileio_read_dir_resp_t_contents_append_printf(f, ...) sbp_sequence_string_append_printf(s, 251, 255, __VA_ARGS__)
#define sbp_msg_fileio_read_dir_resp_t_contents_count_sections(f) sbp_sequence_string_count_sections(f, 251, 255)
#define sbp_msg_fileio_read_dir_resp_t_contents_get_section(f,s) sbp_sequence_string_get_section(f,s,251, 255)
#define sbp_msg_fileio_read_dir_resp_t_contents_section_len(f,s) sbp_sequence_string_section_len(f,s,251, 255)
#define sbp_msg_fileio_read_dir_resp_t_contents_space_remaining(f) sbp_sequence_string_space_remaining(f,251, 255)
#define sbp_msg_fileio_read_dir_resp_t_contents_strcmp(a,b) sbp_sequence_string_strcmp(a,b,251, 255)
  /** Delete a file from the file system (host => device)
   *
 * The file remove message deletes a file from the file system.
 * If the message is invalid, a followup MSG_PRINT message will
 * print "Invalid fileio remove message". A device will only
 * process this message when it is received from sender ID 0x42.
   */
#define SBP_MSG_FILEIO_REMOVE        0x00AC

typedef struct {
  
  /**
* Name of the file to delete
   */
  sbp_null_terminated_string_t
  filename
  ;
} sbp_msg_fileio_remove_t;


#define sbp_msg_fileio_remove_t_filename_init(f) sbp_null_terminated_string_init(f, 255)
#define sbp_msg_fileio_remove_t_filename_valid(f) sbp_null_terminated_string_valid(f, 255)
#define sbp_msg_fileio_remove_t_filename_set(f,s) sbp_null_terminated_string_set(f,s,255)
#define sbp_msg_fileio_remove_t_filename_printf(f,...) sbp_null_terminated_string_printf(f,255,__VA_ARGS__)
#define sbp_msg_fileio_remove_t_filename_packed_len(f) sbp_null_terminated_string_packed_len(f,255)
#define sbp_msg_fileio_remove_t_filename_get(f) sbp_null_terminated_string_get(f,255)
#define sbp_msg_fileio_remove_t_filename_len(f) ( sbp_msg_fileio_remove_t_filename_packed_len(f) - 1)
#define sbp_msg_fileio_remove_t_filename_strcmp(a,b) sbp_null_terminated_string_strcmp(a,b,255)
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

typedef struct {
  
  /**
* Write sequence number
   */
    u32
  sequence
  ;
  /**
* Offset into the file at which to start writing in bytes[bytes]
   */
    u32
  offset
  ;
  /**
* Name of the file to write to
   */
  sbp_null_terminated_string_t
  filename
  ;
  /**
* Variable-length array of data to write
   */
    u8
  data
    [247]
  ;
  /**
   * Number of items in data
   */
  u8 data_count;
} sbp_msg_fileio_write_req_t;


#define sbp_msg_fileio_write_req_t_filename_init(f) sbp_null_terminated_string_init(f, 247)
#define sbp_msg_fileio_write_req_t_filename_valid(f) sbp_null_terminated_string_valid(f, 247)
#define sbp_msg_fileio_write_req_t_filename_set(f,s) sbp_null_terminated_string_set(f,s,247)
#define sbp_msg_fileio_write_req_t_filename_printf(f,...) sbp_null_terminated_string_printf(f,247,__VA_ARGS__)
#define sbp_msg_fileio_write_req_t_filename_packed_len(f) sbp_null_terminated_string_packed_len(f,247)
#define sbp_msg_fileio_write_req_t_filename_get(f) sbp_null_terminated_string_get(f,247)
#define sbp_msg_fileio_write_req_t_filename_len(f) ( sbp_msg_fileio_write_req_t_filename_packed_len(f) - 1)
#define sbp_msg_fileio_write_req_t_filename_strcmp(a,b) sbp_null_terminated_string_strcmp(a,b,247)
  /** File written to (host <= device)
   *
 * The file write message writes a certain length (up to 255 bytes)
 * of data to a file at a given offset. The message is a copy of the
 * original MSG_FILEIO_WRITE_REQ message to check integrity of the
 * write. The sequence number in the response is preserved from the
 * request.
   */
#define SBP_MSG_FILEIO_WRITE_RESP    0x00AB

typedef struct {
  
  /**
* Write sequence number
   */
    u32
  sequence
  ;
} sbp_msg_fileio_write_resp_t;


  /** Request advice on the optimal configuration for FileIO.
   *
 * Requests advice on the optimal configuration for a FileIO 
 * transfer.  Newer version of FileIO can support greater
 * throughput by supporting a large window of FileIO data
 * that can be in-flight during read or write operations.
   */
#define SBP_MSG_FILEIO_CONFIG_REQ    0x1001

typedef struct {
  
  /**
* Advice sequence number
   */
    u32
  sequence
  ;
} sbp_msg_fileio_config_req_t;


  /** Response with advice on the optimal configuration for FileIO.

   *
 * The advice on the optimal configuration for a FileIO
 * transfer.  Newer version of FileIO can support greater
 * throughput by supporting a large window of FileIO data
 * that can be in-flight during read or write operations.
   */
#define SBP_MSG_FILEIO_CONFIG_RESP   0x1002

typedef struct {
  
  /**
* Advice sequence number
   */
    u32
  sequence
  ;
  /**
* The number of SBP packets in the data in-flight window
   */
    u32
  window_size
  ;
  /**
* The number of SBP packets sent in one PDU
   */
    u32
  batch_size
  ;
  /**
* The version of FileIO that is supported
   */
    u32
  fileio_version
  ;
} sbp_msg_fileio_config_resp_t;



#include <libsbp/unpacked/file_io_operators.h>
#include <libsbp/unpacked/file_io_packers.h>

#endif /* LIBSBP_FILE_IO_MESSAGES_H */
