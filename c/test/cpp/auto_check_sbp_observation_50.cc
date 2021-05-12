#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_observation_500 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_glo_biases_t>
{
public:
  Test_auto_check_sbp_observation_500() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_glo_biases_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_glo_biases_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_glo_biases_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_observation_500, Test)     
{

    uint8_t encoded_frame[] = {85,117,0,0,0,9,0,0,0,0,0,0,0,0,0,77,211, };

    sbp_msg_glo_biases_t test_unpacked_msg{};
    test_unpacked_msg.l1ca_bias = 0;
    test_unpacked_msg.l1p_bias = 0;
    test_unpacked_msg.l2ca_bias = 0;
    test_unpacked_msg.l2p_bias = 0;
    test_unpacked_msg.mask = 0;
                                                                              
    EXPECT_EQ(send_message( 0, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 0);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.l1ca_bias, 0);
    EXPECT_EQ(last_msg_.l1p_bias, 0);
    EXPECT_EQ(last_msg_.l2ca_bias, 0);
    EXPECT_EQ(last_msg_.l2p_bias, 0);
    EXPECT_EQ(last_msg_.mask, 0);
}