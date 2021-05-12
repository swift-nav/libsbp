#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_logging_90 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_log_t>
{
public:
  Test_auto_check_sbp_logging_90() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_log_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_log_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_log_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_logging_90, Test)     
{

    uint8_t encoded_frame[] = {85,1,4,10,9,44,6,70,105,108,116,101,114,101,100,32,97,108,108,32,111,98,115,32,102,114,111,109,32,50,51,49,52,32,97,116,32,116,111,119,32,56,51,46,53,51,57,48,49,57,177,163, };

    sbp_msg_log_t test_unpacked_msg{};
    test_unpacked_msg.level = 6;
    
    {
      const char assign_string[] = { (char)70,(char)105,(char)108,(char)116,(char)101,(char)114,(char)101,(char)100,(char)32,(char)97,(char)108,(char)108,(char)32,(char)111,(char)98,(char)115,(char)32,(char)102,(char)114,(char)111,(char)109,(char)32,(char)50,(char)51,(char)49,(char)52,(char)32,(char)97,(char)116,(char)32,(char)116,(char)111,(char)119,(char)32,(char)56,(char)51,(char)46,(char)53,(char)51,(char)57,(char)48,(char)49,(char)57 };
      memcpy(test_unpacked_msg.text.data, assign_string, sizeof(assign_string));
    }
    
    test_unpacked_msg.text.len = 43;
                                                                              
    EXPECT_EQ(send_message( 2314, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 2314);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.level, 6);
    
    {
      const char check_string[] = { (char)70,(char)105,(char)108,(char)116,(char)101,(char)114,(char)101,(char)100,(char)32,(char)97,(char)108,(char)108,(char)32,(char)111,(char)98,(char)115,(char)32,(char)102,(char)114,(char)111,(char)109,(char)32,(char)50,(char)51,(char)49,(char)52,(char)32,(char)97,(char)116,(char)32,(char)116,(char)111,(char)119,(char)32,(char)56,(char)51,(char)46,(char)53,(char)51,(char)57,(char)48,(char)49,(char)57 };
      EXPECT_EQ(memcmp(last_msg_.text.data, check_string, sizeof(check_string)), 0);
    }
    
    EXPECT_EQ(last_msg_.text.len, 43);
}