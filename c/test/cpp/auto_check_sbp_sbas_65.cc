#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_sbas_650 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_sbas_raw_t>
{
public:
  Test_auto_check_sbp_sbas_650() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_sbas_raw_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_sbas_raw_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_sbas_raw_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_sbas_650, Test)     
{

    uint8_t encoded_frame[] = {85,119,119,28,200,34,131,2,201,228,233,29,4,23,255,0,23,255,0,23,255,127,240,2,255,192,3,127,247,255,127,247,255,229,229,238,170,175,255,240,167,14, };

    sbp_msg_sbas_raw_t test_unpacked_msg{};
    
    test_unpacked_msg.data[0] = 23;
    
    test_unpacked_msg.data[1] = 255;
    
    test_unpacked_msg.data[2] = 0;
    
    test_unpacked_msg.data[3] = 23;
    
    test_unpacked_msg.data[4] = 255;
    
    test_unpacked_msg.data[5] = 0;
    
    test_unpacked_msg.data[6] = 23;
    
    test_unpacked_msg.data[7] = 255;
    
    test_unpacked_msg.data[8] = 127;
    
    test_unpacked_msg.data[9] = 240;
    
    test_unpacked_msg.data[10] = 2;
    
    test_unpacked_msg.data[11] = 255;
    
    test_unpacked_msg.data[12] = 192;
    
    test_unpacked_msg.data[13] = 3;
    
    test_unpacked_msg.data[14] = 127;
    
    test_unpacked_msg.data[15] = 247;
    
    test_unpacked_msg.data[16] = 255;
    
    test_unpacked_msg.data[17] = 127;
    
    test_unpacked_msg.data[18] = 247;
    
    test_unpacked_msg.data[19] = 255;
    
    test_unpacked_msg.data[20] = 229;
    
    test_unpacked_msg.data[21] = 229;
    
    test_unpacked_msg.data[22] = 238;
    
    test_unpacked_msg.data[23] = 170;
    
    test_unpacked_msg.data[24] = 175;
    
    test_unpacked_msg.data[25] = 255;
    
    test_unpacked_msg.data[26] = 240;
    test_unpacked_msg.message_type = 4;
    
    test_unpacked_msg.sid.code = 2;
    
    test_unpacked_msg.sid.sat = 131;
    test_unpacked_msg.tow = 501867721;
                                                                              
    EXPECT_EQ(send_message( 51228, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 51228);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.data[0], 23);
    EXPECT_EQ(last_msg_.data[1], 255);
    EXPECT_EQ(last_msg_.data[2], 0);
    EXPECT_EQ(last_msg_.data[3], 23);
    EXPECT_EQ(last_msg_.data[4], 255);
    EXPECT_EQ(last_msg_.data[5], 0);
    EXPECT_EQ(last_msg_.data[6], 23);
    EXPECT_EQ(last_msg_.data[7], 255);
    EXPECT_EQ(last_msg_.data[8], 127);
    EXPECT_EQ(last_msg_.data[9], 240);
    EXPECT_EQ(last_msg_.data[10], 2);
    EXPECT_EQ(last_msg_.data[11], 255);
    EXPECT_EQ(last_msg_.data[12], 192);
    EXPECT_EQ(last_msg_.data[13], 3);
    EXPECT_EQ(last_msg_.data[14], 127);
    EXPECT_EQ(last_msg_.data[15], 247);
    EXPECT_EQ(last_msg_.data[16], 255);
    EXPECT_EQ(last_msg_.data[17], 127);
    EXPECT_EQ(last_msg_.data[18], 247);
    EXPECT_EQ(last_msg_.data[19], 255);
    EXPECT_EQ(last_msg_.data[20], 229);
    EXPECT_EQ(last_msg_.data[21], 229);
    EXPECT_EQ(last_msg_.data[22], 238);
    EXPECT_EQ(last_msg_.data[23], 170);
    EXPECT_EQ(last_msg_.data[24], 175);
    EXPECT_EQ(last_msg_.data[25], 255);
    EXPECT_EQ(last_msg_.data[26], 240);
    EXPECT_EQ(last_msg_.message_type, 4);
    
    EXPECT_EQ(last_msg_.sid.code, 2);
    
    EXPECT_EQ(last_msg_.sid.sat, 131);
    EXPECT_EQ(last_msg_.tow, 501867721);
}