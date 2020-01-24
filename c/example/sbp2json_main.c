#include <stdio.h>
#include <unistd.h>
#include "libsbp/edc.h"
#include "libsbp/sbp.h"
#include "libsbp/sbp2json.h"

#define SBP_PREAMBLE 0x55

/* Build with the following command: 
 * gcc sbp2json_main.c ../src/sbp.c ../src/sbp2json.c ../src/edc.c -I ../include
 * from this directory */

static s32 read_json_stdin(u8 *buff, u32 n, void* context) {
(void) context;
return read(0, buff, n);
}

static void sbp2json_frame_callback(u16 sender_id, u16 msg_type, u8 payload_len,
                                    u8 payload[], u16 frame_len, u8 frame[], void *context)
{
  static char out[2056];
  sbp2json(sender_id, msg_type, payload_len, payload, 2056, out);
  printf("%s\n", out);

}

int main(int argc, char **argv)
{
  int opt;
  int result = 0;
  static sbp_msg_callbacks_node_t node;
  sbp_state_t s;

  sbp_state_init(&s);

  sbp_register_all_msg_callback(&s, sbp2json_frame_callback, NULL, &node);

  while(1) {
    sbp_process(&s, &read_json_stdin);
  }

  return 0;
}
