#include "test_utils.h"

namespace utils {

const void* DUMMY_MEMORY_FOR_CALLBACKS = reinterpret_cast<void*>(0xdeadbeef);
const void* DUMMY_MEMORY_FOR_IO = reinterpret_cast<void*>(0xdead0000);

namespace io {

u32 dummy_wr = 0u;
u32 dummy_rd = 0u;
u8 dummy_buff[1024];
void* last_io_context = nullptr;

void dummy_reset(void) {
  dummy_rd = dummy_wr = 0;
  memset(dummy_buff, 0, sizeof(dummy_buff));
}

s32 dummy_write(u8* buff, u32 n, void* context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(dummy_buff + dummy_wr, buff, real_n);
  dummy_wr += real_n;
  return (s32)real_n;
}

s32 dummy_read(u8* buff, u32 n, void* context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(buff, dummy_buff + dummy_rd, real_n);
  dummy_rd += real_n;
  return (s32)real_n;
}

s32 dummy_read_single_byte(u8* buff, u32 n, void* context) {
  (void)n;
  last_io_context = context;
  memcpy(buff, dummy_buff + dummy_rd, 1);
  dummy_rd += 1;
  return 1;
}

s32 dummy_write_single_byte(u8* buff, u32 n, void* context) {
  (void)n;
  last_io_context = context;
  memcpy(dummy_buff + dummy_wr, buff, 1);
  dummy_wr += 1;
  return 1;
}

}  // namespace io

namespace logging {

struct msg_t last_msg = {};

void logging_reset() { memset(&last_msg, 0, sizeof(last_msg)); }

void logging_callback(u16 sender_id, sbp_msg_type_t msg_type,
                      const sbp_msg_t* msg, void* context) {
  last_msg.n_callbacks_logged++;
  last_msg.sender_id = sender_id;
  last_msg.msg_type = msg_type;
  last_msg.msg = *msg;
  last_msg.context = context;
}

}  // namespace logging

}  // namespace utils
