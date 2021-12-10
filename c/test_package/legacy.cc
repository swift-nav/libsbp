#include <cstdio>
#include <iostream>

#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/frame_handler.h>

struct FileBase {
  explicit FileBase(FILE *file) : file_(file) {}

  ~FileBase() { fclose(file_); }

  operator bool() const {
    return file_;
  }

  void rewind() {
    ::rewind(file_);
  }

  int getc() {
    return ::getc(file_);
  }

  FILE *const file_;
};

class FileReader : public FileBase, public sbp::IReader {
public:
  explicit FileReader(FILE *file) : FileBase(file), sbp::IReader() {}

  s32 read(u8 *buffer, u32 buffer_length) override {
    if (feof(file_)) {
      return -1;
    }
    size_t count = fread(buffer, 1, buffer_length, file_);
    return (s32) count;
  }
};

class FileWriter : public FileBase, public sbp::IWriter {
public:
  explicit FileWriter(FILE *file) : FileBase(file), sbp::IWriter() {}

  s32 write(const u8 *buffer, u32 buffer_length) override {
    if (feof(file_)) {
      return -1;
    }
    size_t count = fwrite(buffer, 1, buffer_length, file_);
    return (s32) count;
  }
};

class MessageHandler : public sbp::AllFrameHandler {
public:
  MessageHandler(sbp::State *input_state, sbp::State *output_state) : AllFrameHandler(input_state),
                                                                      output_state_(output_state) {}

  void handle_sbp_frame(uint16_t sender_id, uint16_t message_type, uint8_t payload_length, uint8_t *payload,
                        uint16_t frame_length, uint8_t *frame) override {
    (void) frame_length;
    (void) frame;

    output_state_->send_message(message_type, sender_id, payload_length, payload);
  }

private:
  sbp::State *const output_state_;
};

int main() {
  FileReader input_file(fopen(SBP_FILE, "r"));
  FileWriter output_file(tmpfile());

  if (!input_file) {
    std::cerr << "Unable to open up input file\n";
    return EXIT_FAILURE;
  }

  if (!output_file) {
    std::cerr << "Unable to open up output file\n";
    return EXIT_FAILURE;
  }

  sbp::State input_state(&input_file, nullptr);
  sbp::State output_state(nullptr, &output_file);
  MessageHandler message_handler(&input_state, &output_state);

  s8 ret = 0;
  do {
    ret = input_state.process();
  } while (ret >= 0);

  input_file.rewind();
  output_file.rewind();

  int input_char = 0;
  int output_char = 0;

  do {
    input_char = input_file.getc();
    output_char = output_file.getc();
  } while (input_char != EOF && output_char != EOF);

  if (input_char != output_char) {
    std::cerr << "File mismatch\n";
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}