#ifndef _TEST_UTILS_H_
#define _TEST_UTILS_H_

#include <sbp.h>

namespace utils {

extern const void* DUMMY_MEMORY_FOR_CALLBACKS;
extern const void* DUMMY_MEMORY_FOR_IO;

namespace io {

extern u32 dummy_wr;
extern u32 dummy_rd;
extern u8 dummy_buff[1024];
extern void* last_io_context;

void dummy_reset(void);
s32 dummy_write(u8* buff, u32 n, void* context);
s32 dummy_read(u8* buff, u32 n, void* context);
s32 dummy_read_single_byte(u8* buff, u32 n, void* context);
s32 dummy_write_single_byte(u8* buff, u32 n, void* context);

}  // namespace io

namespace logging {

struct msg_t {
  u32 n_callbacks_logged;
  u16 sender_id;
  sbp_msg_type_t msg_type;
  sbp_msg_t msg;
  void* context;
};

extern msg_t last_msg;

void logging_reset();
void logging_callback(u16 sender_id, sbp_msg_type_t msg_type,
                      const sbp_msg_t* msg, void* context);

}  // namespace logging

}  // namespace utils

#endif /* _TEST_UTILS_H_ */
