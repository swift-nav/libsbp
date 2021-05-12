#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_navigation_280 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_280() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_pos_llh_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_llh_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_280, Test)     
{

    uint8_t encoded_frame[] = {85,1,2,246,215,34,20,46,39,0,250,29,226,186,235,182,66,64,19,203,51,196,24,139,94,192,31,157,160,232,122,115,81,64,0,0,0,0,9,0,236,139, };

    sbp_msg_pos_llh_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.height = 69.80437675175607;
    test_unpacked_msg.lat = 37.42906890908121;
    test_unpacked_msg.lon = -122.17338662202773;
    test_unpacked_msg.n_sats = 9;
    test_unpacked_msg.tow = 2567700;
    test_unpacked_msg.v_accuracy = 0;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_LT((last_msg_.height*100 - 69.8043767518*100), 0.05);
    EXPECT_LT((last_msg_.lat*100 - 37.4290689091*100), 0.05);
    EXPECT_LT((last_msg_.lon*100 - -122.173386622*100), 0.05);
    EXPECT_EQ(last_msg_.n_sats, 9);
    EXPECT_EQ(last_msg_.tow, 2567700);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_281 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_281() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_pos_llh_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_llh_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_281, Test)     
{

    uint8_t encoded_frame[] = {85,1,2,246,215,34,20,46,39,0,161,51,75,148,235,182,66,64,36,41,246,30,25,139,94,192,254,218,49,127,10,108,81,64,0,0,0,0,9,1,25,117, };

    sbp_msg_pos_llh_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.flags = 1;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.height = 69.68814067715354;
    test_unpacked_msg.lat = 37.42906430885274;
    test_unpacked_msg.lon = -122.17340826071865;
    test_unpacked_msg.n_sats = 9;
    test_unpacked_msg.tow = 2567700;
    test_unpacked_msg.v_accuracy = 0;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.flags, 1);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_LT((last_msg_.height*100 - 69.6881406772*100), 0.05);
    EXPECT_LT((last_msg_.lat*100 - 37.4290643089*100), 0.05);
    EXPECT_LT((last_msg_.lon*100 - -122.173408261*100), 0.05);
    EXPECT_EQ(last_msg_.n_sats, 9);
    EXPECT_EQ(last_msg_.tow, 2567700);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_282 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_282() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_pos_llh_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_llh_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_282, Test)     
{

    uint8_t encoded_frame[] = {85,1,2,246,215,34,120,46,39,0,56,214,210,65,235,182,66,64,13,46,132,80,25,139,94,192,22,143,46,234,191,95,81,64,0,0,0,0,9,0,174,105, };

    sbp_msg_pos_llh_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.height = 69.49608854815264;
    test_unpacked_msg.lat = 37.42905447764173;
    test_unpacked_msg.lon = -122.17342007549469;
    test_unpacked_msg.n_sats = 9;
    test_unpacked_msg.tow = 2567800;
    test_unpacked_msg.v_accuracy = 0;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_LT((last_msg_.height*100 - 69.4960885482*100), 0.05);
    EXPECT_LT((last_msg_.lat*100 - 37.4290544776*100), 0.05);
    EXPECT_LT((last_msg_.lon*100 - -122.173420075*100), 0.05);
    EXPECT_EQ(last_msg_.n_sats, 9);
    EXPECT_EQ(last_msg_.tow, 2567800);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_283 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_283() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_pos_llh_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_llh_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_283, Test)     
{

    uint8_t encoded_frame[] = {85,1,2,246,215,34,120,46,39,0,251,117,115,140,235,182,66,64,152,134,167,12,25,139,94,192,160,22,137,253,4,108,81,64,0,0,0,0,9,1,122,127, };

    sbp_msg_pos_llh_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.flags = 1;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.height = 69.68780458819901;
    test_unpacked_msg.lat = 37.429063373925565;
    test_unpacked_msg.lon = -122.17340389594972;
    test_unpacked_msg.n_sats = 9;
    test_unpacked_msg.tow = 2567800;
    test_unpacked_msg.v_accuracy = 0;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.flags, 1);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_LT((last_msg_.height*100 - 69.6878045882*100), 0.05);
    EXPECT_LT((last_msg_.lat*100 - 37.4290633739*100), 0.05);
    EXPECT_LT((last_msg_.lon*100 - -122.173403896*100), 0.05);
    EXPECT_EQ(last_msg_.n_sats, 9);
    EXPECT_EQ(last_msg_.tow, 2567800);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_284 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_284() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_pos_llh_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_llh_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_284, Test)     
{

    uint8_t encoded_frame[] = {85,1,2,246,215,34,220,46,39,0,51,124,88,251,235,182,66,64,153,5,250,16,25,139,94,192,146,60,187,219,152,161,81,64,0,0,0,0,9,0,194,158, };

    sbp_msg_pos_llh_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.height = 70.5249547317965;
    test_unpacked_msg.lat = 37.42907659359516;
    test_unpacked_msg.lon = -122.17340492645452;
    test_unpacked_msg.n_sats = 9;
    test_unpacked_msg.tow = 2567900;
    test_unpacked_msg.v_accuracy = 0;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_LT((last_msg_.height*100 - 70.5249547318*100), 0.05);
    EXPECT_LT((last_msg_.lat*100 - 37.4290765936*100), 0.05);
    EXPECT_LT((last_msg_.lon*100 - -122.173404926*100), 0.05);
    EXPECT_EQ(last_msg_.n_sats, 9);
    EXPECT_EQ(last_msg_.tow, 2567900);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_285 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_285() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_pos_llh_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_llh_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_285, Test)     
{

    uint8_t encoded_frame[] = {85,1,2,195,4,34,212,157,67,24,8,23,228,8,151,225,66,64,156,174,42,194,230,152,94,192,153,23,72,47,196,40,16,64,0,0,0,0,8,0,237,169, };

    sbp_msg_pos_llh_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.height = 4.039810885214956;
    test_unpacked_msg.lat = 37.76242171418386;
    test_unpacked_msg.lon = -122.38908437889262;
    test_unpacked_msg.n_sats = 8;
    test_unpacked_msg.tow = 407084500;
    test_unpacked_msg.v_accuracy = 0;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_LT((last_msg_.height*100 - 4.03981088521*100), 0.05);
    EXPECT_LT((last_msg_.lat*100 - 37.7624217142*100), 0.05);
    EXPECT_LT((last_msg_.lon*100 - -122.389084379*100), 0.05);
    EXPECT_EQ(last_msg_.n_sats, 8);
    EXPECT_EQ(last_msg_.tow, 407084500);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_286 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_286() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_pos_llh_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_llh_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_286, Test)     
{

    uint8_t encoded_frame[] = {85,1,2,195,4,34,56,158,67,24,220,109,212,24,151,225,66,64,159,231,254,219,230,152,94,192,128,151,67,19,233,105,7,64,0,0,0,0,8,0,152,11, };

    sbp_msg_pos_llh_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.height = 2.926714087009657;
    test_unpacked_msg.lat = 37.76242361423985;
    test_unpacked_msg.lon = -122.38909053700489;
    test_unpacked_msg.n_sats = 8;
    test_unpacked_msg.tow = 407084600;
    test_unpacked_msg.v_accuracy = 0;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_LT((last_msg_.height*100 - 2.92671408701*100), 0.05);
    EXPECT_LT((last_msg_.lat*100 - 37.7624236142*100), 0.05);
    EXPECT_LT((last_msg_.lon*100 - -122.389090537*100), 0.05);
    EXPECT_EQ(last_msg_.n_sats, 8);
    EXPECT_EQ(last_msg_.tow, 407084600);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_287 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_287() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_pos_llh_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_llh_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_287, Test)     
{

    uint8_t encoded_frame[] = {85,1,2,195,4,34,156,158,67,24,13,91,237,11,151,225,66,64,75,113,210,220,230,152,94,192,37,6,145,188,89,112,238,63,0,0,0,0,8,0,221,155, };

    sbp_msg_pos_llh_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.height = 0.9512146647395566;
    test_unpacked_msg.lat = 37.762422076126406;
    test_unpacked_msg.lon = -122.3890907340148;
    test_unpacked_msg.n_sats = 8;
    test_unpacked_msg.tow = 407084700;
    test_unpacked_msg.v_accuracy = 0;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_LT((last_msg_.height*100 - 0.95121466474*100), 0.05);
    EXPECT_LT((last_msg_.lat*100 - 37.7624220761*100), 0.05);
    EXPECT_LT((last_msg_.lon*100 - -122.389090734*100), 0.05);
    EXPECT_EQ(last_msg_.n_sats, 8);
    EXPECT_EQ(last_msg_.tow, 407084700);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_288 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_288() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_pos_llh_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_llh_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_288, Test)     
{

    uint8_t encoded_frame[] = {85,1,2,195,4,34,0,159,67,24,51,183,5,8,151,225,66,64,13,226,148,253,230,152,94,192,187,27,11,32,69,213,2,64,0,0,0,0,8,0,82,94, };

    sbp_msg_pos_llh_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.height = 2.354135752047538;
    test_unpacked_msg.lat = 37.762421610632735;
    test_unpacked_msg.lon = -122.38909854449612;
    test_unpacked_msg.n_sats = 8;
    test_unpacked_msg.tow = 407084800;
    test_unpacked_msg.v_accuracy = 0;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_LT((last_msg_.height*100 - 2.35413575205*100), 0.05);
    EXPECT_LT((last_msg_.lat*100 - 37.7624216106*100), 0.05);
    EXPECT_LT((last_msg_.lon*100 - -122.389098544*100), 0.05);
    EXPECT_EQ(last_msg_.n_sats, 8);
    EXPECT_EQ(last_msg_.tow, 407084800);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_289 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_289() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_pos_llh_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_llh_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_289, Test)     
{

    uint8_t encoded_frame[] = {85,1,2,195,4,34,100,159,67,24,22,77,146,22,151,225,66,64,64,134,105,227,230,152,94,192,37,99,114,72,31,103,241,63,0,0,0,0,8,0,70,60, };

    sbp_msg_pos_llh_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.height = 1.0876763181642641;
    test_unpacked_msg.lat = 37.76242334502801;
    test_unpacked_msg.lon = -122.38909230523223;
    test_unpacked_msg.n_sats = 8;
    test_unpacked_msg.tow = 407084900;
    test_unpacked_msg.v_accuracy = 0;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_LT((last_msg_.height*100 - 1.08767631816*100), 0.05);
    EXPECT_LT((last_msg_.lat*100 - 37.762423345*100), 0.05);
    EXPECT_LT((last_msg_.lon*100 - -122.389092305*100), 0.05);
    EXPECT_EQ(last_msg_.n_sats, 8);
    EXPECT_EQ(last_msg_.tow, 407084900);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_2810 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_2810() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_pos_llh_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_llh_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_2810, Test)     
{

    uint8_t encoded_frame[] = {85,1,2,195,4,34,46,162,68,24,124,245,46,169,151,225,66,64,135,149,234,187,230,152,94,192,194,201,115,145,166,175,20,64,0,0,0,0,5,0,212,121, };

    sbp_msg_pos_llh_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.height = 5.171533844654222;
    test_unpacked_msg.lat = 37.76244082253376;
    test_unpacked_msg.lon = -122.38908288868525;
    test_unpacked_msg.n_sats = 5;
    test_unpacked_msg.tow = 407151150;
    test_unpacked_msg.v_accuracy = 0;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_LT((last_msg_.height*100 - 5.17153384465*100), 0.05);
    EXPECT_LT((last_msg_.lat*100 - 37.7624408225*100), 0.05);
    EXPECT_LT((last_msg_.lon*100 - -122.389082889*100), 0.05);
    EXPECT_EQ(last_msg_.n_sats, 5);
    EXPECT_EQ(last_msg_.tow, 407151150);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}