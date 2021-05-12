#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_acquisition_20 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_acq_result_dep_b_t>
{
public:
  Test_auto_check_sbp_acquisition_20() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_acq_result_dep_b_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_acq_result_dep_b_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_acq_result_dep_b_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_acquisition_20, Test)     
{

    uint8_t encoded_frame[] = {85,20,0,246,215,16,137,167,18,66,0,0,161,67,240,24,156,69,9,0,0,0,80,195, };

    sbp_msg_acq_result_dep_b_t test_unpacked_msg{};
    test_unpacked_msg.cf = 4995.1171875;
    test_unpacked_msg.cp = 322.0;
    
    test_unpacked_msg.sid.code = 0;
    
    test_unpacked_msg.sid.reserved = 0;
    
    test_unpacked_msg.sid.sat = 9;
    test_unpacked_msg.snr = 36.66360855102539;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_LT((last_msg_.cf*100 - 4995.1171875*100), 0.05);
    EXPECT_LT((last_msg_.cp*100 - 322.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.sid.code, 0);
    
    EXPECT_EQ(last_msg_.sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.sid.sat, 9);
    EXPECT_LT((last_msg_.snr*100 - 36.663608551*100), 0.05);
}                                                     
class Test_auto_check_sbp_acquisition_21 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_acq_result_dep_b_t>
{
public:
  Test_auto_check_sbp_acquisition_21() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_acq_result_dep_b_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_acq_result_dep_b_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_acq_result_dep_b_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_acquisition_21, Test)     
{

    uint8_t encoded_frame[] = {85,20,0,246,215,16,206,172,16,66,0,192,82,68,198,199,0,198,3,0,0,0,149,143, };

    sbp_msg_acq_result_dep_b_t test_unpacked_msg{};
    test_unpacked_msg.cf = -8241.943359375;
    test_unpacked_msg.cp = 843.0;
    
    test_unpacked_msg.sid.code = 0;
    
    test_unpacked_msg.sid.reserved = 0;
    
    test_unpacked_msg.sid.sat = 3;
    test_unpacked_msg.snr = 36.16875457763672;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_LT((last_msg_.cf*100 - -8241.94335938*100), 0.05);
    EXPECT_LT((last_msg_.cp*100 - 843.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.sid.code, 0);
    
    EXPECT_EQ(last_msg_.sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.sid.sat, 3);
    EXPECT_LT((last_msg_.snr*100 - 36.1687545776*100), 0.05);
}                                                     
class Test_auto_check_sbp_acquisition_22 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_acq_result_dep_b_t>
{
public:
  Test_auto_check_sbp_acquisition_22() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_acq_result_dep_b_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_acq_result_dep_b_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_acq_result_dep_b_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_acquisition_22, Test)     
{

    uint8_t encoded_frame[] = {85,20,0,246,215,16,228,27,15,66,0,128,70,68,228,74,148,69,18,0,0,0,179,155, };

    sbp_msg_acq_result_dep_b_t test_unpacked_msg{};
    test_unpacked_msg.cf = 4745.361328125;
    test_unpacked_msg.cp = 794.0;
    
    test_unpacked_msg.sid.code = 0;
    
    test_unpacked_msg.sid.reserved = 0;
    
    test_unpacked_msg.sid.sat = 18;
    test_unpacked_msg.snr = 35.77723693847656;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_LT((last_msg_.cf*100 - 4745.36132812*100), 0.05);
    EXPECT_LT((last_msg_.cp*100 - 794.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.sid.code, 0);
    
    EXPECT_EQ(last_msg_.sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.sid.sat, 18);
    EXPECT_LT((last_msg_.snr*100 - 35.7772369385*100), 0.05);
}                                                     
class Test_auto_check_sbp_acquisition_23 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_acq_result_dep_b_t>
{
public:
  Test_auto_check_sbp_acquisition_23() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_acq_result_dep_b_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_acq_result_dep_b_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_acq_result_dep_b_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_acquisition_23, Test)     
{

    uint8_t encoded_frame[] = {85,20,0,246,215,16,46,199,14,66,0,64,129,67,240,24,28,69,17,0,0,0,18,181, };

    sbp_msg_acq_result_dep_b_t test_unpacked_msg{};
    test_unpacked_msg.cf = 2497.55859375;
    test_unpacked_msg.cp = 258.5;
    
    test_unpacked_msg.sid.code = 0;
    
    test_unpacked_msg.sid.reserved = 0;
    
    test_unpacked_msg.sid.sat = 17;
    test_unpacked_msg.snr = 35.69451141357422;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_LT((last_msg_.cf*100 - 2497.55859375*100), 0.05);
    EXPECT_LT((last_msg_.cp*100 - 258.5*100), 0.05);
    
    EXPECT_EQ(last_msg_.sid.code, 0);
    
    EXPECT_EQ(last_msg_.sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.sid.sat, 17);
    EXPECT_LT((last_msg_.snr*100 - 35.6945114136*100), 0.05);
}                                                     
class Test_auto_check_sbp_acquisition_24 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_acq_result_dep_b_t>
{
public:
  Test_auto_check_sbp_acquisition_24() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_acq_result_dep_b_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_acq_result_dep_b_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_acq_result_dep_b_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_acquisition_24, Test)     
{

    uint8_t encoded_frame[] = {85,20,0,246,215,16,194,24,14,66,0,128,2,68,129,193,249,195,5,0,0,0,35,203, };

    sbp_msg_acq_result_dep_b_t test_unpacked_msg{};
    test_unpacked_msg.cf = -499.5117492675781;
    test_unpacked_msg.cp = 522.0;
    
    test_unpacked_msg.sid.code = 0;
    
    test_unpacked_msg.sid.reserved = 0;
    
    test_unpacked_msg.sid.sat = 5;
    test_unpacked_msg.snr = 35.52417755126953;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_LT((last_msg_.cf*100 - -499.511749268*100), 0.05);
    EXPECT_LT((last_msg_.cp*100 - 522.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.sid.code, 0);
    
    EXPECT_EQ(last_msg_.sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.sid.sat, 5);
    EXPECT_LT((last_msg_.snr*100 - 35.5241775513*100), 0.05);
}