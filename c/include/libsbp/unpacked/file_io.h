#ifndef LIBSBP_FILE_IO_MESSAGES_H
#define LIBSBP_FILE_IO_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>
/** Read file from the file system (host => device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_FILEIO_READ_REQ      0x00A8
typedef struct {
  u32 sequence;
  u32 offset;
  u8 chunk_size;
  sbp_null_terminated_string_t filename;
} sbp_msg_fileio_read_req_t;
#define sbp_msg_fileio_read_req_t_filename_init(f) sbp_null_terminated_string_init(f, 246)
#define sbp_msg_fileio_read_req_t_filename_valid(f) sbp_null_terminated_string_valid(f, 246)
#define sbp_msg_fileio_read_req_t_filename_set(f,s) sbp_null_terminated_string_set(f,s,246)
#define sbp_msg_fileio_read_req_t_filename_printf(f,...) sbp_null_terminated_string_printf(f,246,__VA_ARGS__)
#define sbp_msg_fileio_read_req_t_filename_vprintf(f,fmt,ap) sbp_null_terminated_string_vprintf(f,246,fmt,ap)
#define sbp_msg_fileio_read_req_t_filename_packed_len(f) sbp_null_terminated_string_packed_len(f,246)
#define sbp_msg_fileio_read_req_t_filename_get(f) sbp_null_terminated_string_get(f,246)
#define sbp_msg_fileio_read_req_t_filename_len(f) ( sbp_msg_fileio_read_req_t_filename_packed_len(f) - 1)
#define sbp_msg_fileio_read_req_t_filename_strcmp(a,b) sbp_null_terminated_string_strcmp(a,b,246)



/** File read from the file system (host <= device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_FILEIO_READ_RESP     0x00A3
typedef struct {
  u32 sequence;
  u8 contents[251];
  u8 n_contents;
} sbp_msg_fileio_read_resp_t;



/** List files in a directory (host => device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_FILEIO_READ_DIR_REQ  0x00A9
typedef struct {
  u32 sequence;
  u32 offset;
  sbp_null_terminated_string_t dirname;
} sbp_msg_fileio_read_dir_req_t;
#define sbp_msg_fileio_read_dir_req_t_dirname_init(f) sbp_null_terminated_string_init(f, 247)
#define sbp_msg_fileio_read_dir_req_t_dirname_valid(f) sbp_null_terminated_string_valid(f, 247)
#define sbp_msg_fileio_read_dir_req_t_dirname_set(f,s) sbp_null_terminated_string_set(f,s,247)
#define sbp_msg_fileio_read_dir_req_t_dirname_printf(f,...) sbp_null_terminated_string_printf(f,247,__VA_ARGS__)
#define sbp_msg_fileio_read_dir_req_t_dirname_vprintf(f,fmt,ap) sbp_null_terminated_string_vprintf(f,247,fmt,ap)
#define sbp_msg_fileio_read_dir_req_t_dirname_packed_len(f) sbp_null_terminated_string_packed_len(f,247)
#define sbp_msg_fileio_read_dir_req_t_dirname_get(f) sbp_null_terminated_string_get(f,247)
#define sbp_msg_fileio_read_dir_req_t_dirname_len(f) ( sbp_msg_fileio_read_dir_req_t_dirname_packed_len(f) - 1)
#define sbp_msg_fileio_read_dir_req_t_dirname_strcmp(a,b) sbp_null_terminated_string_strcmp(a,b,247)



/** Files listed in a directory (host <= device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_FILEIO_READ_DIR_RESP 0x00AA
typedef struct {
  u32 sequence;
  sbp_sequence_string_t contents;
} sbp_msg_fileio_read_dir_resp_t;
#define sbp_msg_fileio_read_dir_resp_t_contents_init(f) sbp_sequence_string_init(f, 251, 255)
#define sbp_msg_fileio_read_dir_resp_t_contents_valid(f) sbp_sequence_string_valid(f, 251, 255)
#define sbp_msg_fileio_read_dir_resp_t_contents_packed_len(f) sbp_sequence_string_packed_len(f, 251, 255)
#define sbp_msg_fileio_read_dir_resp_t_contents_append(f,s) sbp_sequence_string_append(f, s, 251, 255)
#define sbp_msg_fileio_read_dir_resp_t_contents_append_printf(f, ...) sbp_sequence_string_append_printf(s, 251, 255, __VA_ARGS__)
#define sbp_msg_fileio_read_dir_resp_t_contents_append_vprintf(f, fmt,ap) sbp_sequence_string_append_vprintf(s, 251, 255, fmt, ap)
#define sbp_msg_fileio_read_dir_resp_t_contents_count_sections(f) sbp_sequence_string_count_sections(f, 251, 255)
#define sbp_msg_fileio_read_dir_resp_t_contents_get_section(f,s) sbp_sequence_string_get_section(f,s,251, 255)
#define sbp_msg_fileio_read_dir_resp_t_contents_section_len(f,s) sbp_sequence_string_section_len(f,s,251, 255)
#define sbp_msg_fileio_read_dir_resp_t_contents_space_remaining(f) sbp_sequence_string_space_remaining(f,251, 255)
#define sbp_msg_fileio_read_dir_resp_t_contents_strcmp(a,b) sbp_sequence_string_strcmp(a,b,251, 255)



/** Delete a file from the file system (host => device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_FILEIO_REMOVE        0x00AC
typedef struct {
  sbp_null_terminated_string_t filename;
} sbp_msg_fileio_remove_t;
#define sbp_msg_fileio_remove_t_filename_init(f) sbp_null_terminated_string_init(f, 255)
#define sbp_msg_fileio_remove_t_filename_valid(f) sbp_null_terminated_string_valid(f, 255)
#define sbp_msg_fileio_remove_t_filename_set(f,s) sbp_null_terminated_string_set(f,s,255)
#define sbp_msg_fileio_remove_t_filename_printf(f,...) sbp_null_terminated_string_printf(f,255,__VA_ARGS__)
#define sbp_msg_fileio_remove_t_filename_vprintf(f,fmt,ap) sbp_null_terminated_string_vprintf(f,255,fmt,ap)
#define sbp_msg_fileio_remove_t_filename_packed_len(f) sbp_null_terminated_string_packed_len(f,255)
#define sbp_msg_fileio_remove_t_filename_get(f) sbp_null_terminated_string_get(f,255)
#define sbp_msg_fileio_remove_t_filename_len(f) ( sbp_msg_fileio_remove_t_filename_packed_len(f) - 1)
#define sbp_msg_fileio_remove_t_filename_strcmp(a,b) sbp_null_terminated_string_strcmp(a,b,255)



/** Write to file (host => device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_FILEIO_WRITE_REQ     0x00AD
typedef struct {
  u32 sequence;
  u32 offset;
  sbp_null_terminated_string_t filename;
  u8 data[247];
  u8 n_data;
} sbp_msg_fileio_write_req_t;
#define sbp_msg_fileio_write_req_t_filename_init(f) sbp_null_terminated_string_init(f, 247)
#define sbp_msg_fileio_write_req_t_filename_valid(f) sbp_null_terminated_string_valid(f, 247)
#define sbp_msg_fileio_write_req_t_filename_set(f,s) sbp_null_terminated_string_set(f,s,247)
#define sbp_msg_fileio_write_req_t_filename_printf(f,...) sbp_null_terminated_string_printf(f,247,__VA_ARGS__)
#define sbp_msg_fileio_write_req_t_filename_vprintf(f,fmt,ap) sbp_null_terminated_string_vprintf(f,247,fmt,ap)
#define sbp_msg_fileio_write_req_t_filename_packed_len(f) sbp_null_terminated_string_packed_len(f,247)
#define sbp_msg_fileio_write_req_t_filename_get(f) sbp_null_terminated_string_get(f,247)
#define sbp_msg_fileio_write_req_t_filename_len(f) ( sbp_msg_fileio_write_req_t_filename_packed_len(f) - 1)
#define sbp_msg_fileio_write_req_t_filename_strcmp(a,b) sbp_null_terminated_string_strcmp(a,b,247)



/** File written to (host <= device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_FILEIO_WRITE_RESP    0x00AB
typedef struct {
  u32 sequence;
} sbp_msg_fileio_write_resp_t;



/** Request advice on the optimal configuration for FileIO.
 *
((m.desc|commentify)))
 */
#define SBP_MSG_FILEIO_CONFIG_REQ    0x1001
typedef struct {
  u32 sequence;
} sbp_msg_fileio_config_req_t;



/** Response with advice on the optimal configuration for FileIO.

 *
((m.desc|commentify)))
 */
#define SBP_MSG_FILEIO_CONFIG_RESP   0x1002
typedef struct {
  u32 sequence;
  u32 window_size;
  u32 batch_size;
  u32 fileio_version;
} sbp_msg_fileio_config_resp_t;




#include <libsbp/unpacked/file_io_operators.h>
#include <libsbp/unpacked/file_io_packers.h>

#endif /* LIBSBP_FILE_IO_MESSAGES_H */
