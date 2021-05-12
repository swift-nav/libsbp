#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_logging_80 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_fwd_t>
{
public:
  Test_auto_check_sbp_logging_80() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_fwd_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
  {
    set_reader(this);
    set_writer(this);
  }

  s32 read(uint8_t *buf, const uint32_t n) override {
    uint32_t real_n = n;
    memcpy(buf, io_buf_ + rd_, real_n);
    rd_ += real_n;
    return (s32)real_n;
  }

  s32 write(const uint8_t *buf, uint32_t n) override {
    uint32_t real_n = n;
    memcpy(io_buf_ + wr_, buf, real_n);
    wr_ += real_n;
    return (s32)real_n;
  }


protected:

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_fwd_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_fwd_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_logging_80, Test)     
{

    uint8_t encoded_frame[] = {85,2,4,66,0,18,0,0,86,81,68,47,81,103,65,69,65,65,65,65,65,69,97,103,125,95, };

    sbp_msg_fwd_t test_unpacked_msg{};
    {
      const char assign_string[] = { (char)86,(char)81,(char)68,(char)47,(char)81,(char)103,(char)65,(char)69,(char)65,(char)65,(char)65,(char)65,(char)65,(char)69,(char)97,(char)103 };
      memcpy(test_unpacked_msg.fwd_payload, assign_string, sizeof(assign_string));
    }
    test_unpacked_msg.protocol = 0;
    test_unpacked_msg.source = 0;
    test_unpacked_msg.fwd_payload_count = 16;
                                                                              
    EXPECT_EQ(send_message( 66, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 66);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    {
      const char check_string[] = { (char)86,(char)81,(char)68,(char)47,(char)81,(char)103,(char)65,(char)69,(char)65,(char)65,(char)65,(char)65,(char)65,(char)69,(char)97,(char)103 };
      EXPECT_EQ(memcmp(last_msg_.fwd_payload, check_string, sizeof(check_string)), 0);
    }
    EXPECT_EQ(last_msg_.protocol, 0);
    EXPECT_EQ(last_msg_.source, 0);
    EXPECT_EQ(last_msg_.fwd_payload_count, 16);
}