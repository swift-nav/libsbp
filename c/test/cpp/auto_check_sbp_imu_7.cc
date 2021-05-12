#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_imu_70 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_imu_raw_t>
{
public:
  Test_auto_check_sbp_imu_70() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_imu_raw_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_imu_raw_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_imu_raw_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_imu_70, Test)     
{

    uint8_t encoded_frame[] = {85,0,9,52,18,17,26,1,0,192,206,96,0,223,255,44,16,60,0,208,254,238,255,70,135, };

    sbp_msg_imu_raw_t test_unpacked_msg{};
    test_unpacked_msg.acc_x = 96;
    test_unpacked_msg.acc_y = -33;
    test_unpacked_msg.acc_z = 4140;
    test_unpacked_msg.gyr_x = 60;
    test_unpacked_msg.gyr_y = -304;
    test_unpacked_msg.gyr_z = -18;
    test_unpacked_msg.tow = 3221225754;
    test_unpacked_msg.tow_f = 206;
                                                                              
    EXPECT_EQ(send_message( 4660, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 4660);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.acc_x, 96);
    EXPECT_EQ(last_msg_.acc_y, -33);
    EXPECT_EQ(last_msg_.acc_z, 4140);
    EXPECT_EQ(last_msg_.gyr_x, 60);
    EXPECT_EQ(last_msg_.gyr_y, -304);
    EXPECT_EQ(last_msg_.gyr_z, -18);
    EXPECT_EQ(last_msg_.tow, 3221225754);
    EXPECT_EQ(last_msg_.tow_f, 206);
}