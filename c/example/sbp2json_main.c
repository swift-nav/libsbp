#include <stdio.h>
#include <unistd.h>
#include <libsbp/sbp.h>
#include "libsbp/edc.h"
#include "libsbp/sbp.h"

#define SBP_PREAMBLE 0x55

u32 read_json(u8 *buff, u32 n, void* context) {
(void) context;
return read(0, buff, n);
}




s8 sbp_process_json(sbp_state_t *s, u32 (*read)(u8 *buff, u32 n, void* context ))
{
  u8 temp;
  u16 crc;

  switch (s->state) {
  case WAITING:
    if ((*read)(&temp, 1, s->io_context) == 1)
      if (temp == SBP_PREAMBLE) {
        s->n_read = 0;
        s->state = GET_TYPE;
      }
    break;

  case GET_TYPE:
    s->n_read += (*read)((u8*)&(s->msg_type) + s->n_read,
                         2-s->n_read, s->io_context);
    if (s->n_read >= 2) {
      /* Swap bytes to little endian. */
      s->n_read = 0;
      s->state = GET_SENDER;
    }
    break;

  case GET_SENDER:
    s->n_read += (*read)((u8*)&(s->sender_id) + s->n_read,
                         2-s->n_read, s->io_context);
    if (s->n_read >= 2) {
      /* Swap bytes to little endian. */
      s->state = GET_LEN;
    }
    break;

  case GET_LEN:
    if ((*read)(&(s->msg_len), 1, s->io_context) == 1) {
      s->n_read = 0;
      s->state = GET_MSG;
    }
    break;

  case GET_MSG:
    /* Not received whole message yet, try and read some more. */
    s->n_read += (*read)(
      &(s->msg_buff[s->n_read]),
      s->msg_len - s->n_read,
      s->io_context
    );
    if (s->msg_len - s->n_read <= 0) {
      s->n_read = 0;
      s->state = GET_CRC;
    }
    break;

  case GET_CRC:
    s->n_read += (*read)((u8*)&(s->crc) + s->n_read,
                         2-s->n_read, s->io_context);
    if (s->n_read >= 2) {
      s->state = WAITING;

      /* Swap bytes to little endian. */
      crc = crc16_ccitt((u8*)&(s->msg_type), 2, 0);
      crc = crc16_ccitt((u8*)&(s->sender_id), 2, crc);
      crc = crc16_ccitt(&(s->msg_len), 1, crc);
      crc = crc16_ccitt(s->msg_buff, s->msg_len, crc);
      if (s->crc == crc) {

        /* Message complete, process it. */
        char out_str[4096];
        s8 ret = sbp2json(s->sender_id, s->msg_type, s->msg_len,
                                     s->msg_buff, 4096, out_str);
        printf("%s\n", out_str);
        return ret;
      } else {
        return SBP_CRC_ERROR;
      }
    }
    break;

  default:
    s->state = WAITING;
    break;
  }

  return SBP_OK;
}

int main(int argc, char **argv)
{
  int opt;
  int result = 0;

  sbp_state_t s;

  sbp_state_init(&s);

  while(1) {
    sbp_process_json(&s, &read_json);
  }

  return 0;
}
