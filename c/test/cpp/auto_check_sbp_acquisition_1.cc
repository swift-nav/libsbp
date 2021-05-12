#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_acquisition_10 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_acq_result_dep_a_t>
{
public:
  Test_auto_check_sbp_acquisition_10() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_acq_result_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_acq_result_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_acq_result_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_acquisition_10, Test)     
{

    uint8_t encoded_frame[] = {85,21,0,195,4,13,0,0,104,65,0,192,53,68,198,199,0,70,8,2,68, };

    sbp_msg_acq_result_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.cf = 8241.943359375;
    test_unpacked_msg.cp = 727.0;
    test_unpacked_msg.prn = 8;
    test_unpacked_msg.snr = 14.5;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_LT((last_msg_.cf*100 - 8241.94335938*100), 0.05);
    EXPECT_LT((last_msg_.cp*100 - 727.0*100), 0.05);
    EXPECT_EQ(last_msg_.prn, 8);
    EXPECT_LT((last_msg_.snr*100 - 14.5*100), 0.05);
}                                                     
class Test_auto_check_sbp_acquisition_11 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_acq_result_dep_a_t>
{
public:
  Test_auto_check_sbp_acquisition_11() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_acq_result_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_acq_result_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_acq_result_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_acquisition_11, Test)     
{

    uint8_t encoded_frame[] = {85,21,0,195,4,13,205,204,116,65,0,192,179,67,33,81,59,68,9,219,27, };

    sbp_msg_acq_result_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.cf = 749.2676391601562;
    test_unpacked_msg.cp = 359.5;
    test_unpacked_msg.prn = 9;
    test_unpacked_msg.snr = 15.300000190734863;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_LT((last_msg_.cf*100 - 749.26763916*100), 0.05);
    EXPECT_LT((last_msg_.cp*100 - 359.5*100), 0.05);
    EXPECT_EQ(last_msg_.prn, 9);
    EXPECT_LT((last_msg_.snr*100 - 15.3000001907*100), 0.05);
}                                                     
class Test_auto_check_sbp_acquisition_12 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_acq_result_dep_a_t>
{
public:
  Test_auto_check_sbp_acquisition_12() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_acq_result_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_acq_result_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_acq_result_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_acquisition_12, Test)     
{

    uint8_t encoded_frame[] = {85,21,0,195,4,13,205,204,144,65,0,0,34,66,57,237,202,197,11,150,35, };

    sbp_msg_acq_result_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.cf = -6493.65283203125;
    test_unpacked_msg.cp = 40.5;
    test_unpacked_msg.prn = 11;
    test_unpacked_msg.snr = 18.100000381469727;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_LT((last_msg_.cf*100 - -6493.65283203*100), 0.05);
    EXPECT_LT((last_msg_.cp*100 - 40.5*100), 0.05);
    EXPECT_EQ(last_msg_.prn, 11);
    EXPECT_LT((last_msg_.snr*100 - 18.1000003815*100), 0.05);
}                                                     
class Test_auto_check_sbp_acquisition_13 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_acq_result_dep_a_t>
{
public:
  Test_auto_check_sbp_acquisition_13() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_acq_result_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_acq_result_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_acq_result_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_acquisition_13, Test)     
{

    uint8_t encoded_frame[] = {85,21,0,195,4,13,205,204,116,65,0,32,9,68,129,193,121,196,12,146,118, };

    sbp_msg_acq_result_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.cf = -999.0234985351562;
    test_unpacked_msg.cp = 548.5;
    test_unpacked_msg.prn = 12;
    test_unpacked_msg.snr = 15.300000190734863;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_LT((last_msg_.cf*100 - -999.023498535*100), 0.05);
    EXPECT_LT((last_msg_.cp*100 - 548.5*100), 0.05);
    EXPECT_EQ(last_msg_.prn, 12);
    EXPECT_LT((last_msg_.snr*100 - 15.3000001907*100), 0.05);
}                                                     
class Test_auto_check_sbp_acquisition_14 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_acq_result_dep_a_t>
{
public:
  Test_auto_check_sbp_acquisition_14() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_acq_result_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_acq_result_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_acq_result_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_acquisition_14, Test)     
{

    uint8_t encoded_frame[] = {85,21,0,195,4,13,205,204,116,65,0,32,67,68,228,74,148,69,14,23,75, };

    sbp_msg_acq_result_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.cf = 4745.361328125;
    test_unpacked_msg.cp = 780.5;
    test_unpacked_msg.prn = 14;
    test_unpacked_msg.snr = 15.300000190734863;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_LT((last_msg_.cf*100 - 4745.36132812*100), 0.05);
    EXPECT_LT((last_msg_.cp*100 - 780.5*100), 0.05);
    EXPECT_EQ(last_msg_.prn, 14);
    EXPECT_LT((last_msg_.snr*100 - 15.3000001907*100), 0.05);
}                                                     
class Test_auto_check_sbp_acquisition_15 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_acq_result_dep_a_t>
{
public:
  Test_auto_check_sbp_acquisition_15() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_acq_result_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_acq_result_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_acq_result_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_acquisition_15, Test)     
{

    uint8_t encoded_frame[] = {85,21,0,195,4,13,228,56,35,67,0,32,18,68,129,193,249,195,0,204,207, };

    sbp_msg_acq_result_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.cf = -499.5117492675781;
    test_unpacked_msg.cp = 584.5;
    test_unpacked_msg.prn = 0;
    test_unpacked_msg.snr = 163.22222900390625;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_LT((last_msg_.cf*100 - -499.511749268*100), 0.05);
    EXPECT_LT((last_msg_.cp*100 - 584.5*100), 0.05);
    EXPECT_EQ(last_msg_.prn, 0);
    EXPECT_LT((last_msg_.snr*100 - 163.222229004*100), 0.05);
}