#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_navigation_130 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_baseline_ecef_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_130() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_baseline_ecef_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_baseline_ecef_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ecef_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_130, Test)     
{

    uint8_t encoded_frame[] = {85,2,2,246,215,20,20,46,39,0,21,48,255,255,52,117,255,255,216,211,254,255,0,0,9,1,50,137, };

    sbp_msg_baseline_ecef_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.accuracy = 0;
    test_unpacked_msg.flags = 1;
    test_unpacked_msg.n_sats = 9;
    test_unpacked_msg.tow = 2567700;
    test_unpacked_msg.x = -53227;
    test_unpacked_msg.y = -35532;
    test_unpacked_msg.z = -76840;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.accuracy, 0);
    EXPECT_EQ(last_msg_.flags, 1);
    EXPECT_EQ(last_msg_.n_sats, 9);
    EXPECT_EQ(last_msg_.tow, 2567700);
    EXPECT_EQ(last_msg_.x, -53227);
    EXPECT_EQ(last_msg_.y, -35532);
    EXPECT_EQ(last_msg_.z, -76840);
}                                                     
class Test_auto_check_sbp_navigation_131 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_baseline_ecef_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_131() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_baseline_ecef_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_baseline_ecef_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ecef_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_131, Test)     
{

    uint8_t encoded_frame[] = {85,2,2,246,215,20,120,46,39,0,58,49,255,255,49,116,255,255,134,211,254,255,0,0,9,1,227,155, };

    sbp_msg_baseline_ecef_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.accuracy = 0;
    test_unpacked_msg.flags = 1;
    test_unpacked_msg.n_sats = 9;
    test_unpacked_msg.tow = 2567800;
    test_unpacked_msg.x = -52934;
    test_unpacked_msg.y = -35791;
    test_unpacked_msg.z = -76922;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.accuracy, 0);
    EXPECT_EQ(last_msg_.flags, 1);
    EXPECT_EQ(last_msg_.n_sats, 9);
    EXPECT_EQ(last_msg_.tow, 2567800);
    EXPECT_EQ(last_msg_.x, -52934);
    EXPECT_EQ(last_msg_.y, -35791);
    EXPECT_EQ(last_msg_.z, -76922);
}                                                     
class Test_auto_check_sbp_navigation_132 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_baseline_ecef_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_132() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_baseline_ecef_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_baseline_ecef_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ecef_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_132, Test)     
{

    uint8_t encoded_frame[] = {85,2,2,246,215,20,220,46,39,0,97,50,255,255,47,115,255,255,52,211,254,255,0,0,9,1,61,126, };

    sbp_msg_baseline_ecef_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.accuracy = 0;
    test_unpacked_msg.flags = 1;
    test_unpacked_msg.n_sats = 9;
    test_unpacked_msg.tow = 2567900;
    test_unpacked_msg.x = -52639;
    test_unpacked_msg.y = -36049;
    test_unpacked_msg.z = -77004;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.accuracy, 0);
    EXPECT_EQ(last_msg_.flags, 1);
    EXPECT_EQ(last_msg_.n_sats, 9);
    EXPECT_EQ(last_msg_.tow, 2567900);
    EXPECT_EQ(last_msg_.x, -52639);
    EXPECT_EQ(last_msg_.y, -36049);
    EXPECT_EQ(last_msg_.z, -77004);
}                                                     
class Test_auto_check_sbp_navigation_133 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_baseline_ecef_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_133() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_baseline_ecef_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_baseline_ecef_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ecef_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_133, Test)     
{

    uint8_t encoded_frame[] = {85,2,2,246,215,20,64,47,39,0,136,51,255,255,45,114,255,255,228,210,254,255,0,0,9,1,200,79, };

    sbp_msg_baseline_ecef_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.accuracy = 0;
    test_unpacked_msg.flags = 1;
    test_unpacked_msg.n_sats = 9;
    test_unpacked_msg.tow = 2568000;
    test_unpacked_msg.x = -52344;
    test_unpacked_msg.y = -36307;
    test_unpacked_msg.z = -77084;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.accuracy, 0);
    EXPECT_EQ(last_msg_.flags, 1);
    EXPECT_EQ(last_msg_.n_sats, 9);
    EXPECT_EQ(last_msg_.tow, 2568000);
    EXPECT_EQ(last_msg_.x, -52344);
    EXPECT_EQ(last_msg_.y, -36307);
    EXPECT_EQ(last_msg_.z, -77084);
}                                                     
class Test_auto_check_sbp_navigation_134 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_baseline_ecef_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_134() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_baseline_ecef_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_baseline_ecef_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ecef_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_134, Test)     
{

    uint8_t encoded_frame[] = {85,2,2,246,215,20,164,47,39,0,176,52,255,255,44,113,255,255,149,210,254,255,0,0,9,1,104,24, };

    sbp_msg_baseline_ecef_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.accuracy = 0;
    test_unpacked_msg.flags = 1;
    test_unpacked_msg.n_sats = 9;
    test_unpacked_msg.tow = 2568100;
    test_unpacked_msg.x = -52048;
    test_unpacked_msg.y = -36564;
    test_unpacked_msg.z = -77163;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.accuracy, 0);
    EXPECT_EQ(last_msg_.flags, 1);
    EXPECT_EQ(last_msg_.n_sats, 9);
    EXPECT_EQ(last_msg_.tow, 2568100);
    EXPECT_EQ(last_msg_.x, -52048);
    EXPECT_EQ(last_msg_.y, -36564);
    EXPECT_EQ(last_msg_.z, -77163);
}                                                     
class Test_auto_check_sbp_navigation_135 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_baseline_ecef_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_135() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_baseline_ecef_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_baseline_ecef_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ecef_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_135, Test)     
{

    uint8_t encoded_frame[] = {85,2,2,195,4,20,156,21,69,24,169,231,255,255,102,208,255,255,251,28,0,0,0,0,6,0,146,168, };

    sbp_msg_baseline_ecef_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.accuracy = 0;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.n_sats = 6;
    test_unpacked_msg.tow = 407180700;
    test_unpacked_msg.x = -6231;
    test_unpacked_msg.y = -12186;
    test_unpacked_msg.z = 7419;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.accuracy, 0);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.n_sats, 6);
    EXPECT_EQ(last_msg_.tow, 407180700);
    EXPECT_EQ(last_msg_.x, -6231);
    EXPECT_EQ(last_msg_.y, -12186);
    EXPECT_EQ(last_msg_.z, 7419);
}                                                     
class Test_auto_check_sbp_navigation_136 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_baseline_ecef_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_136() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_baseline_ecef_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_baseline_ecef_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ecef_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_136, Test)     
{

    uint8_t encoded_frame[] = {85,2,2,195,4,20,0,22,69,24,169,231,255,255,103,208,255,255,252,28,0,0,0,0,6,0,34,116, };

    sbp_msg_baseline_ecef_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.accuracy = 0;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.n_sats = 6;
    test_unpacked_msg.tow = 407180800;
    test_unpacked_msg.x = -6231;
    test_unpacked_msg.y = -12185;
    test_unpacked_msg.z = 7420;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.accuracy, 0);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.n_sats, 6);
    EXPECT_EQ(last_msg_.tow, 407180800);
    EXPECT_EQ(last_msg_.x, -6231);
    EXPECT_EQ(last_msg_.y, -12185);
    EXPECT_EQ(last_msg_.z, 7420);
}                                                     
class Test_auto_check_sbp_navigation_137 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_baseline_ecef_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_137() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_baseline_ecef_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_baseline_ecef_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ecef_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_137, Test)     
{

    uint8_t encoded_frame[] = {85,2,2,195,4,20,100,22,69,24,30,224,255,255,192,183,255,255,239,53,0,0,0,0,6,0,225,15, };

    sbp_msg_baseline_ecef_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.accuracy = 0;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.n_sats = 6;
    test_unpacked_msg.tow = 407180900;
    test_unpacked_msg.x = -8162;
    test_unpacked_msg.y = -18496;
    test_unpacked_msg.z = 13807;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.accuracy, 0);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.n_sats, 6);
    EXPECT_EQ(last_msg_.tow, 407180900);
    EXPECT_EQ(last_msg_.x, -8162);
    EXPECT_EQ(last_msg_.y, -18496);
    EXPECT_EQ(last_msg_.z, 13807);
}                                                     
class Test_auto_check_sbp_navigation_138 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_baseline_ecef_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_138() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_baseline_ecef_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_baseline_ecef_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ecef_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_138, Test)     
{

    uint8_t encoded_frame[] = {85,2,2,195,4,20,200,22,69,24,28,224,255,255,191,183,255,255,242,53,0,0,0,0,6,0,35,100, };

    sbp_msg_baseline_ecef_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.accuracy = 0;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.n_sats = 6;
    test_unpacked_msg.tow = 407181000;
    test_unpacked_msg.x = -8164;
    test_unpacked_msg.y = -18497;
    test_unpacked_msg.z = 13810;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.accuracy, 0);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.n_sats, 6);
    EXPECT_EQ(last_msg_.tow, 407181000);
    EXPECT_EQ(last_msg_.x, -8164);
    EXPECT_EQ(last_msg_.y, -18497);
    EXPECT_EQ(last_msg_.z, 13810);
}                                                     
class Test_auto_check_sbp_navigation_139 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_baseline_ecef_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_139() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_baseline_ecef_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_baseline_ecef_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ecef_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_139, Test)     
{

    uint8_t encoded_frame[] = {85,2,2,195,4,20,44,23,69,24,24,227,255,255,25,195,255,255,153,59,0,0,0,0,6,0,66,66, };

    sbp_msg_baseline_ecef_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.accuracy = 0;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.n_sats = 6;
    test_unpacked_msg.tow = 407181100;
    test_unpacked_msg.x = -7400;
    test_unpacked_msg.y = -15591;
    test_unpacked_msg.z = 15257;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.accuracy, 0);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.n_sats, 6);
    EXPECT_EQ(last_msg_.tow, 407181100);
    EXPECT_EQ(last_msg_.x, -7400);
    EXPECT_EQ(last_msg_.y, -15591);
    EXPECT_EQ(last_msg_.z, 15257);
}                                                     
class Test_auto_check_sbp_navigation_1310 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_baseline_ecef_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_1310() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_baseline_ecef_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_baseline_ecef_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ecef_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_1310, Test)     
{

    uint8_t encoded_frame[] = {85,2,2,195,4,20,144,23,69,24,23,227,255,255,25,195,255,255,153,59,0,0,0,0,6,0,35,135, };

    sbp_msg_baseline_ecef_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.accuracy = 0;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.n_sats = 6;
    test_unpacked_msg.tow = 407181200;
    test_unpacked_msg.x = -7401;
    test_unpacked_msg.y = -15591;
    test_unpacked_msg.z = 15257;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.accuracy, 0);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.n_sats, 6);
    EXPECT_EQ(last_msg_.tow, 407181200);
    EXPECT_EQ(last_msg_.x, -7401);
    EXPECT_EQ(last_msg_.y, -15591);
    EXPECT_EQ(last_msg_.z, 15257);
}