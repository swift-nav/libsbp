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


/** Files listed in a directory (host <= device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_FILEIO_READ_DIR_RESP 0x00AA
typedef struct {
  u32 sequence;
  sbp_sequence_string_t contents;
} sbp_msg_fileio_read_dir_resp_t;


/** Delete a file from the file system (host => device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_FILEIO_REMOVE        0x00AC
typedef struct {
  sbp_null_terminated_string_t filename;
} sbp_msg_fileio_remove_t;


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
