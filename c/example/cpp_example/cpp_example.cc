#include <iostream>
#include <fstream>

#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/frame_handler.h>

void usage(char *prog_name) {
  fprintf(stderr, "usage: %s [filename]\n", prog_name);
}

class SbpFileReader : public sbp::IReader {
 public:
  SbpFileReader(const char *file_path) : file_stream_(file_path, std::ios::binary | std::ios_base::in) { }

  bool is_open() const { return file_stream_.is_open(); }
  bool eof() const { return file_stream_.eof(); }

  s32 read(u8 *buffer, u32 buffer_length) override {
    auto start_index = file_stream_.tellg();
    if (start_index == -1) {
      return -1;
    }
    file_stream_.read(reinterpret_cast<char *>(buffer), buffer_length);
    auto end_index = file_stream_.tellg();
    if (end_index == -1 || file_stream_.fail()) {
      return -1;
    }

    return static_cast<s32>(end_index - start_index);
  }

 private:
  std::ifstream file_stream_;
};

class ECEFHandler : private sbp::MessageHandler<msg_gps_time_t, msg_pos_ecef_t> {
  public:
    ECEFHandler(sbp::State *state) : sbp::MessageHandler<msg_gps_time_t, msg_pos_ecef_t>(state) {
    }

    void handle_sbp_msg(uint16_t sender_id, uint8_t message_length, const msg_gps_time_t& msg) {
      (void)sender_id;
      (void)message_length;
      std::cout << "Received new GPS_TME message with WN = " << msg.wn << ", TOW = " << msg.tow << "\n";
    }

    void handle_sbp_msg(uint16_t sender_id, uint8_t message_length, const msg_pos_ecef_t& msg) {
      (void)sender_id;
      (void)message_length;
      std::cout << "Received new POS_ECEF message with TOW = " << msg.tow;
      std::cout << ", (X,Y,Z) = (" << msg.x << "," << msg.y << "," << msg.z << ")\n";
    }
};

class LLHFrameHandler : private sbp::FrameHandler<msg_gps_time_t, msg_pos_llh_t> {
  public:
    LLHFrameHandler(sbp::State *state) : sbp::FrameHandler<msg_gps_time_t, msg_pos_llh_t>(state) {
    }

    void handle_sbp_frame(uint16_t sender_id, uint16_t msg_type,
                                     uint8_t payload_len, uint8_t payload[],
                                     uint16_t frame_len, uint8_t frame[]) {
      (void)sender_id;
      (void)payload;
      (void)frame;
      if (msg_type == SBP_MSG_POS_LLH) {
        std::cout << "Received new POS_LLH frame, payload length " << (int)payload_len << ", frame length " << frame_len << "\n";
      } else if (msg_type == SBP_MSG_GPS_TIME) {
        std::cout << "Received new GPS_TIME frame, payload length " << (int)payload_len << ", frame length " << frame_len << "\n";
      }
    }
};

class EverythingHandler : private sbp::AllFrameHandler {
  public:
    EverythingHandler(sbp::State *state) : sbp::AllFrameHandler(state) {
    }

    void handle_sbp_frame(uint16_t sender_id, uint16_t msg_type,
                                     uint8_t payload_len, uint8_t payload[],
                                     uint16_t frame_len, uint8_t frame[]) {
      (void)sender_id;
      (void)payload;
      (void)frame;
      std::cout << "Received new frame, message type " << msg_type << ", payload length " << (int)payload_len << ", frame length " << frame_len << "\n";
    }
};

int main(int argc, char **argv)
{
  if (argc <= 1) {
    usage(argv[0]);
    exit(EXIT_FAILURE);
  }

  const char *file_path = argv[1];

  SbpFileReader reader(file_path);
  if (!reader.is_open()) {
    usage(argv[0]);
    exit(EXIT_FAILURE);
  }

  sbp::State s;
  ECEFHandler ecef_handler(&s);
  LLHFrameHandler llh_handler(&s);
  EverythingHandler everything_handler(&s);

  s.set_reader(&reader);

  while(!reader.eof()) {
    s.process();
  }

  return 0;
}

