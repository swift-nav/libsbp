#include <stdio.h>
#include <stdlib.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/api.h>

struct Context {
  FILE *input_file;
  FILE *output_file;
  sbp_state_t input_state;
  sbp_state_t output_state;
  sbp_msg_callbacks_node_t message_callback;
};

static s32 input_file_reader(u8 *buffer, u32 buffer_size, void *context) {
  struct Context *ctx = (struct Context *) context;
  if (feof(ctx->input_file)) {
    return -1;
  }
  size_t count = fread(buffer, 1, buffer_size, ctx->input_file);
  return (s32) count;
}

static s32 output_file_writer(u8 *buffer, u32 buffer_size, void *context) {
  struct Context *ctx = (struct Context *) context;
  if (feof(ctx->output_file)) {
    return -1;
  }
  size_t count = fwrite(buffer, 1, buffer_size, ctx->output_file);
  return (s32) count;
}

static void
input_file_payload_handler(u16 sender_id, sbp_msg_type_t message_type, const sbp_msg_t *message, void *context) {
  struct Context *ctx = (struct Context *) context;
  sbp_message_send(&ctx->output_state, message_type, sender_id, message, output_file_writer);
}

int main() {
  int exit_code = EXIT_SUCCESS;
  struct Context context = {0};

  context.input_file = fopen(SBP_FILE, "r");
  if (!context.input_file) {
    fprintf(stderr, "Unable to open up input file\n");
    exit_code = EXIT_FAILURE;
    goto bail;
  }

  context.output_file = tmpfile();
  if (!context.output_file) {
    fprintf(stderr, "Unable to open up output file\n");
    exit_code = EXIT_FAILURE;
    goto bail;
  }

  sbp_state_init(&context.input_state);
  sbp_state_set_io_context(&context.input_state, &context);
  sbp_all_message_callback_register(&context.input_state, input_file_payload_handler, &context,
                                    &context.message_callback);

  sbp_state_init(&context.output_state);
  sbp_state_set_io_context(&context.output_state, &context);

  s8 ret = 0;
  do {
    ret = sbp_process(&context.input_state, input_file_reader);
  } while (ret >= 0);

  rewind(context.input_file);
  rewind(context.output_file);

  int input_char = 0;
  int output_char = 0;

  do {
    input_char = getc(context.input_file);
    output_char = getc(context.output_file);
  } while (input_char != EOF && output_char != EOF);

  if (input_char != output_char) {
    fprintf(stderr, "File mismatch\n");
    exit_code = EXIT_FAILURE;
    goto bail;
  }

  bail:
  fclose(context.input_file);
  fclose(context.output_file);

  return exit_code;
}