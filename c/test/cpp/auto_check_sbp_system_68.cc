#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_system_680 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_dgnss_status_t>
{
public:
  Test_auto_check_sbp_system_680() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_dgnss_status_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_dgnss_status_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_dgnss_status_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_system_680, Test)     
{

    uint8_t encoded_frame[] = {85,2,255,66,0,11,0,50,0,12,83,107,121,108,97,114,107,202,1, };

    sbp_msg_dgnss_status_t test_unpacked_msg{};
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.latency = 50;
    test_unpacked_msg.num_signals = 12;
    
    {
      const char assign_string[] = { (char)83,(char)107,(char)121,(char)108,(char)97,(char)114,(char)107 };
      memcpy(test_unpacked_msg.source.data, assign_string, sizeof(assign_string));
    }
    
    test_unpacked_msg.source.len = 7;
                                                                              
    EXPECT_EQ(send_message( 66, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 66);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.latency, 50);
    EXPECT_EQ(last_msg_.num_signals, 12);
    
    {
      const char check_string[] = { (char)83,(char)107,(char)121,(char)108,(char)97,(char)114,(char)107 };
      EXPECT_EQ(memcmp(last_msg_.source.data, check_string, sizeof(check_string)), 0);
    }
    
    EXPECT_EQ(last_msg_.source.len, 7);
}