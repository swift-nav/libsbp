#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_navigation_330 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_utc_time_gnss_t>
{
public:
  Test_auto_check_sbp_navigation_330() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_utc_time_gnss_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_utc_time_gnss_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_utc_time_gnss_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_330, Test)     
{

    uint8_t encoded_frame[] = {85,5,1,21,3,16,1,24,229,233,29,229,7,4,9,19,24,9,0,8,175,47,177,33, };

    sbp_msg_utc_time_gnss_t test_unpacked_msg{};
    test_unpacked_msg.day = 9;
    test_unpacked_msg.flags = 1;
    test_unpacked_msg.hours = 19;
    test_unpacked_msg.minutes = 24;
    test_unpacked_msg.month = 4;
    test_unpacked_msg.ns = 800000000;
    test_unpacked_msg.seconds = 9;
    test_unpacked_msg.tow = 501867800;
    test_unpacked_msg.year = 2021;
                                                                              
    EXPECT_EQ(send_message( 789, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 789);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.day, 9);
    EXPECT_EQ(last_msg_.flags, 1);
    EXPECT_EQ(last_msg_.hours, 19);
    EXPECT_EQ(last_msg_.minutes, 24);
    EXPECT_EQ(last_msg_.month, 4);
    EXPECT_EQ(last_msg_.ns, 800000000);
    EXPECT_EQ(last_msg_.seconds, 9);
    EXPECT_EQ(last_msg_.tow, 501867800);
    EXPECT_EQ(last_msg_.year, 2021);
}