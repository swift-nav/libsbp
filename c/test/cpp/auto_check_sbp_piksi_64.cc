#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_piksi_640 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_uart_state_depa_t>
{
public:
  Test_auto_check_sbp_piksi_640() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_uart_state_depa_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_uart_state_depa_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_uart_state_depa_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_piksi_640, Test)     
{

    uint8_t encoded_frame[] = {85,24,0,195,4,58,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,154,153,57,65,0,0,0,0,0,0,0,0,15,0,255,255,255,255,0,0,0,0,0,0,0,0,255,255,255,255,247,5, };

    sbp_msg_uart_state_depa_t test_unpacked_msg{};
    
    test_unpacked_msg.latency.avg = -1;
    
    test_unpacked_msg.latency.current = -1;
    
    test_unpacked_msg.latency.lmax = 0;
    
    test_unpacked_msg.latency.lmin = 0;
    
    test_unpacked_msg.uart_a.crc_error_count = 0;
    
    test_unpacked_msg.uart_a.io_error_count = 0;
    
    test_unpacked_msg.uart_a.rx_buffer_level = 0;
    
    test_unpacked_msg.uart_a.rx_throughput = 0.0;
    
    test_unpacked_msg.uart_a.tx_buffer_level = 0;
    
    test_unpacked_msg.uart_a.tx_throughput = 0.0;
    
    test_unpacked_msg.uart_b.crc_error_count = 0;
    
    test_unpacked_msg.uart_b.io_error_count = 0;
    
    test_unpacked_msg.uart_b.rx_buffer_level = 0;
    
    test_unpacked_msg.uart_b.rx_throughput = 0.0;
    
    test_unpacked_msg.uart_b.tx_buffer_level = 0;
    
    test_unpacked_msg.uart_b.tx_throughput = 0.0;
    
    test_unpacked_msg.uart_ftdi.crc_error_count = 0;
    
    test_unpacked_msg.uart_ftdi.io_error_count = 0;
    
    test_unpacked_msg.uart_ftdi.rx_buffer_level = 0;
    
    test_unpacked_msg.uart_ftdi.rx_throughput = 0.0;
    
    test_unpacked_msg.uart_ftdi.tx_buffer_level = 15;
    
    test_unpacked_msg.uart_ftdi.tx_throughput = 11.600000381469727;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_EQ(last_msg_.latency.avg, -1);
    
    EXPECT_EQ(last_msg_.latency.current, -1);
    
    EXPECT_EQ(last_msg_.latency.lmax, 0);
    
    EXPECT_EQ(last_msg_.latency.lmin, 0);
    
    EXPECT_EQ(last_msg_.uart_a.crc_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_a.io_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_a.rx_buffer_level, 0);
    
    EXPECT_LT((last_msg_.uart_a.rx_throughput*100 - 0.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_a.tx_buffer_level, 0);
    
    EXPECT_LT((last_msg_.uart_a.tx_throughput*100 - 0.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_b.crc_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_b.io_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_b.rx_buffer_level, 0);
    
    EXPECT_LT((last_msg_.uart_b.rx_throughput*100 - 0.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_b.tx_buffer_level, 0);
    
    EXPECT_LT((last_msg_.uart_b.tx_throughput*100 - 0.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_ftdi.crc_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_ftdi.io_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_ftdi.rx_buffer_level, 0);
    
    EXPECT_LT((last_msg_.uart_ftdi.rx_throughput*100 - 0.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_ftdi.tx_buffer_level, 15);
    
    EXPECT_LT((last_msg_.uart_ftdi.tx_throughput*100 - 11.6000003815*100), 0.05);
}                                                     
class Test_auto_check_sbp_piksi_641 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_uart_state_depa_t>
{
public:
  Test_auto_check_sbp_piksi_641() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_uart_state_depa_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_uart_state_depa_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_uart_state_depa_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_piksi_641, Test)     
{

    uint8_t encoded_frame[] = {85,24,0,195,4,58,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,43,135,61,0,0,0,0,0,0,0,0,0,0,255,255,255,255,0,0,0,0,0,0,0,0,255,255,255,255,65,110, };

    sbp_msg_uart_state_depa_t test_unpacked_msg{};
    
    test_unpacked_msg.latency.avg = -1;
    
    test_unpacked_msg.latency.current = -1;
    
    test_unpacked_msg.latency.lmax = 0;
    
    test_unpacked_msg.latency.lmin = 0;
    
    test_unpacked_msg.uart_a.crc_error_count = 0;
    
    test_unpacked_msg.uart_a.io_error_count = 0;
    
    test_unpacked_msg.uart_a.rx_buffer_level = 0;
    
    test_unpacked_msg.uart_a.rx_throughput = 0.0;
    
    test_unpacked_msg.uart_a.tx_buffer_level = 0;
    
    test_unpacked_msg.uart_a.tx_throughput = 0.0;
    
    test_unpacked_msg.uart_b.crc_error_count = 0;
    
    test_unpacked_msg.uart_b.io_error_count = 0;
    
    test_unpacked_msg.uart_b.rx_buffer_level = 0;
    
    test_unpacked_msg.uart_b.rx_throughput = 0.0;
    
    test_unpacked_msg.uart_b.tx_buffer_level = 0;
    
    test_unpacked_msg.uart_b.tx_throughput = 0.0;
    
    test_unpacked_msg.uart_ftdi.crc_error_count = 0;
    
    test_unpacked_msg.uart_ftdi.io_error_count = 0;
    
    test_unpacked_msg.uart_ftdi.rx_buffer_level = 0;
    
    test_unpacked_msg.uart_ftdi.rx_throughput = 0.0;
    
    test_unpacked_msg.uart_ftdi.tx_buffer_level = 0;
    
    test_unpacked_msg.uart_ftdi.tx_throughput = 0.06599999964237213;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_EQ(last_msg_.latency.avg, -1);
    
    EXPECT_EQ(last_msg_.latency.current, -1);
    
    EXPECT_EQ(last_msg_.latency.lmax, 0);
    
    EXPECT_EQ(last_msg_.latency.lmin, 0);
    
    EXPECT_EQ(last_msg_.uart_a.crc_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_a.io_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_a.rx_buffer_level, 0);
    
    EXPECT_LT((last_msg_.uart_a.rx_throughput*100 - 0.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_a.tx_buffer_level, 0);
    
    EXPECT_LT((last_msg_.uart_a.tx_throughput*100 - 0.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_b.crc_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_b.io_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_b.rx_buffer_level, 0);
    
    EXPECT_LT((last_msg_.uart_b.rx_throughput*100 - 0.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_b.tx_buffer_level, 0);
    
    EXPECT_LT((last_msg_.uart_b.tx_throughput*100 - 0.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_ftdi.crc_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_ftdi.io_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_ftdi.rx_buffer_level, 0);
    
    EXPECT_LT((last_msg_.uart_ftdi.rx_throughput*100 - 0.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_ftdi.tx_buffer_level, 0);
    
    EXPECT_LT((last_msg_.uart_ftdi.tx_throughput*100 - 0.0659999996424*100), 0.05);
}                                                     
class Test_auto_check_sbp_piksi_642 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_uart_state_depa_t>
{
public:
  Test_auto_check_sbp_piksi_642() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_uart_state_depa_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_uart_state_depa_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_uart_state_depa_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_piksi_642, Test)     
{

    uint8_t encoded_frame[] = {85,24,0,195,4,58,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,86,14,62,0,0,0,0,0,0,0,0,10,0,255,255,255,255,0,0,0,0,0,0,0,0,255,255,255,255,198,36, };

    sbp_msg_uart_state_depa_t test_unpacked_msg{};
    
    test_unpacked_msg.latency.avg = -1;
    
    test_unpacked_msg.latency.current = -1;
    
    test_unpacked_msg.latency.lmax = 0;
    
    test_unpacked_msg.latency.lmin = 0;
    
    test_unpacked_msg.uart_a.crc_error_count = 0;
    
    test_unpacked_msg.uart_a.io_error_count = 0;
    
    test_unpacked_msg.uart_a.rx_buffer_level = 0;
    
    test_unpacked_msg.uart_a.rx_throughput = 0.0;
    
    test_unpacked_msg.uart_a.tx_buffer_level = 0;
    
    test_unpacked_msg.uart_a.tx_throughput = 0.0;
    
    test_unpacked_msg.uart_b.crc_error_count = 0;
    
    test_unpacked_msg.uart_b.io_error_count = 0;
    
    test_unpacked_msg.uart_b.rx_buffer_level = 0;
    
    test_unpacked_msg.uart_b.rx_throughput = 0.0;
    
    test_unpacked_msg.uart_b.tx_buffer_level = 0;
    
    test_unpacked_msg.uart_b.tx_throughput = 0.0;
    
    test_unpacked_msg.uart_ftdi.crc_error_count = 0;
    
    test_unpacked_msg.uart_ftdi.io_error_count = 0;
    
    test_unpacked_msg.uart_ftdi.rx_buffer_level = 0;
    
    test_unpacked_msg.uart_ftdi.rx_throughput = 0.0;
    
    test_unpacked_msg.uart_ftdi.tx_buffer_level = 10;
    
    test_unpacked_msg.uart_ftdi.tx_throughput = 0.13899999856948853;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_EQ(last_msg_.latency.avg, -1);
    
    EXPECT_EQ(last_msg_.latency.current, -1);
    
    EXPECT_EQ(last_msg_.latency.lmax, 0);
    
    EXPECT_EQ(last_msg_.latency.lmin, 0);
    
    EXPECT_EQ(last_msg_.uart_a.crc_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_a.io_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_a.rx_buffer_level, 0);
    
    EXPECT_LT((last_msg_.uart_a.rx_throughput*100 - 0.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_a.tx_buffer_level, 0);
    
    EXPECT_LT((last_msg_.uart_a.tx_throughput*100 - 0.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_b.crc_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_b.io_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_b.rx_buffer_level, 0);
    
    EXPECT_LT((last_msg_.uart_b.rx_throughput*100 - 0.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_b.tx_buffer_level, 0);
    
    EXPECT_LT((last_msg_.uart_b.tx_throughput*100 - 0.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_ftdi.crc_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_ftdi.io_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_ftdi.rx_buffer_level, 0);
    
    EXPECT_LT((last_msg_.uart_ftdi.rx_throughput*100 - 0.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_ftdi.tx_buffer_level, 10);
    
    EXPECT_LT((last_msg_.uart_ftdi.tx_throughput*100 - 0.138999998569*100), 0.05);
}                                                     
class Test_auto_check_sbp_piksi_643 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_uart_state_depa_t>
{
public:
  Test_auto_check_sbp_piksi_643() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_uart_state_depa_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_uart_state_depa_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_uart_state_depa_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_piksi_643, Test)     
{

    uint8_t encoded_frame[] = {85,24,0,195,4,58,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,43,135,61,0,0,0,0,0,0,0,0,0,0,255,255,255,255,0,0,0,0,0,0,0,0,255,255,255,255,65,110, };

    sbp_msg_uart_state_depa_t test_unpacked_msg{};
    
    test_unpacked_msg.latency.avg = -1;
    
    test_unpacked_msg.latency.current = -1;
    
    test_unpacked_msg.latency.lmax = 0;
    
    test_unpacked_msg.latency.lmin = 0;
    
    test_unpacked_msg.uart_a.crc_error_count = 0;
    
    test_unpacked_msg.uart_a.io_error_count = 0;
    
    test_unpacked_msg.uart_a.rx_buffer_level = 0;
    
    test_unpacked_msg.uart_a.rx_throughput = 0.0;
    
    test_unpacked_msg.uart_a.tx_buffer_level = 0;
    
    test_unpacked_msg.uart_a.tx_throughput = 0.0;
    
    test_unpacked_msg.uart_b.crc_error_count = 0;
    
    test_unpacked_msg.uart_b.io_error_count = 0;
    
    test_unpacked_msg.uart_b.rx_buffer_level = 0;
    
    test_unpacked_msg.uart_b.rx_throughput = 0.0;
    
    test_unpacked_msg.uart_b.tx_buffer_level = 0;
    
    test_unpacked_msg.uart_b.tx_throughput = 0.0;
    
    test_unpacked_msg.uart_ftdi.crc_error_count = 0;
    
    test_unpacked_msg.uart_ftdi.io_error_count = 0;
    
    test_unpacked_msg.uart_ftdi.rx_buffer_level = 0;
    
    test_unpacked_msg.uart_ftdi.rx_throughput = 0.0;
    
    test_unpacked_msg.uart_ftdi.tx_buffer_level = 0;
    
    test_unpacked_msg.uart_ftdi.tx_throughput = 0.06599999964237213;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_EQ(last_msg_.latency.avg, -1);
    
    EXPECT_EQ(last_msg_.latency.current, -1);
    
    EXPECT_EQ(last_msg_.latency.lmax, 0);
    
    EXPECT_EQ(last_msg_.latency.lmin, 0);
    
    EXPECT_EQ(last_msg_.uart_a.crc_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_a.io_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_a.rx_buffer_level, 0);
    
    EXPECT_LT((last_msg_.uart_a.rx_throughput*100 - 0.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_a.tx_buffer_level, 0);
    
    EXPECT_LT((last_msg_.uart_a.tx_throughput*100 - 0.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_b.crc_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_b.io_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_b.rx_buffer_level, 0);
    
    EXPECT_LT((last_msg_.uart_b.rx_throughput*100 - 0.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_b.tx_buffer_level, 0);
    
    EXPECT_LT((last_msg_.uart_b.tx_throughput*100 - 0.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_ftdi.crc_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_ftdi.io_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_ftdi.rx_buffer_level, 0);
    
    EXPECT_LT((last_msg_.uart_ftdi.rx_throughput*100 - 0.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_ftdi.tx_buffer_level, 0);
    
    EXPECT_LT((last_msg_.uart_ftdi.tx_throughput*100 - 0.0659999996424*100), 0.05);
}                                                     
class Test_auto_check_sbp_piksi_644 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_uart_state_depa_t>
{
public:
  Test_auto_check_sbp_piksi_644() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_uart_state_depa_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_uart_state_depa_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_uart_state_depa_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_piksi_644, Test)     
{

    uint8_t encoded_frame[] = {85,24,0,195,4,58,0,0,0,0,138,75,6,60,0,0,0,0,0,0,80,113,201,61,0,0,0,0,0,0,0,0,2,0,145,237,252,62,0,0,0,0,0,0,0,0,38,0,255,255,255,255,0,0,0,0,0,0,0,0,255,255,255,255,112,111, };

    sbp_msg_uart_state_depa_t test_unpacked_msg{};
    
    test_unpacked_msg.latency.avg = -1;
    
    test_unpacked_msg.latency.current = -1;
    
    test_unpacked_msg.latency.lmax = 0;
    
    test_unpacked_msg.latency.lmin = 0;
    
    test_unpacked_msg.uart_a.crc_error_count = 0;
    
    test_unpacked_msg.uart_a.io_error_count = 0;
    
    test_unpacked_msg.uart_a.rx_buffer_level = 0;
    
    test_unpacked_msg.uart_a.rx_throughput = 0.008196720853447914;
    
    test_unpacked_msg.uart_a.tx_buffer_level = 0;
    
    test_unpacked_msg.uart_a.tx_throughput = 0.0;
    
    test_unpacked_msg.uart_b.crc_error_count = 0;
    
    test_unpacked_msg.uart_b.io_error_count = 0;
    
    test_unpacked_msg.uart_b.rx_buffer_level = 0;
    
    test_unpacked_msg.uart_b.rx_throughput = 0.0;
    
    test_unpacked_msg.uart_b.tx_buffer_level = 2;
    
    test_unpacked_msg.uart_b.tx_throughput = 0.09836065769195557;
    
    test_unpacked_msg.uart_ftdi.crc_error_count = 0;
    
    test_unpacked_msg.uart_ftdi.io_error_count = 0;
    
    test_unpacked_msg.uart_ftdi.rx_buffer_level = 0;
    
    test_unpacked_msg.uart_ftdi.rx_throughput = 0.0;
    
    test_unpacked_msg.uart_ftdi.tx_buffer_level = 38;
    
    test_unpacked_msg.uart_ftdi.tx_throughput = 0.49399998784065247;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_EQ(last_msg_.latency.avg, -1);
    
    EXPECT_EQ(last_msg_.latency.current, -1);
    
    EXPECT_EQ(last_msg_.latency.lmax, 0);
    
    EXPECT_EQ(last_msg_.latency.lmin, 0);
    
    EXPECT_EQ(last_msg_.uart_a.crc_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_a.io_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_a.rx_buffer_level, 0);
    
    EXPECT_LT((last_msg_.uart_a.rx_throughput*100 - 0.00819672085345*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_a.tx_buffer_level, 0);
    
    EXPECT_LT((last_msg_.uart_a.tx_throughput*100 - 0.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_b.crc_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_b.io_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_b.rx_buffer_level, 0);
    
    EXPECT_LT((last_msg_.uart_b.rx_throughput*100 - 0.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_b.tx_buffer_level, 2);
    
    EXPECT_LT((last_msg_.uart_b.tx_throughput*100 - 0.098360657692*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_ftdi.crc_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_ftdi.io_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_ftdi.rx_buffer_level, 0);
    
    EXPECT_LT((last_msg_.uart_ftdi.rx_throughput*100 - 0.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_ftdi.tx_buffer_level, 38);
    
    EXPECT_LT((last_msg_.uart_ftdi.tx_throughput*100 - 0.493999987841*100), 0.05);
}                                                     
class Test_auto_check_sbp_piksi_645 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_uart_state_depa_t>
{
public:
  Test_auto_check_sbp_piksi_645() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_uart_state_depa_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_uart_state_depa_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_uart_state_depa_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_piksi_645, Test)     
{

    uint8_t encoded_frame[] = {85,24,0,195,4,58,166,155,68,60,0,0,0,0,0,0,0,0,2,0,166,155,68,60,0,0,0,0,0,0,0,0,2,0,236,81,168,63,0,0,0,0,0,0,0,0,50,0,255,255,255,255,0,0,0,0,0,0,0,0,255,255,255,255,22,72, };

    sbp_msg_uart_state_depa_t test_unpacked_msg{};
    
    test_unpacked_msg.latency.avg = -1;
    
    test_unpacked_msg.latency.current = -1;
    
    test_unpacked_msg.latency.lmax = 0;
    
    test_unpacked_msg.latency.lmin = 0;
    
    test_unpacked_msg.uart_a.crc_error_count = 0;
    
    test_unpacked_msg.uart_a.io_error_count = 0;
    
    test_unpacked_msg.uart_a.rx_buffer_level = 0;
    
    test_unpacked_msg.uart_a.rx_throughput = 0.0;
    
    test_unpacked_msg.uart_a.tx_buffer_level = 2;
    
    test_unpacked_msg.uart_a.tx_throughput = 0.012000000104308128;
    
    test_unpacked_msg.uart_b.crc_error_count = 0;
    
    test_unpacked_msg.uart_b.io_error_count = 0;
    
    test_unpacked_msg.uart_b.rx_buffer_level = 0;
    
    test_unpacked_msg.uart_b.rx_throughput = 0.0;
    
    test_unpacked_msg.uart_b.tx_buffer_level = 2;
    
    test_unpacked_msg.uart_b.tx_throughput = 0.012000000104308128;
    
    test_unpacked_msg.uart_ftdi.crc_error_count = 0;
    
    test_unpacked_msg.uart_ftdi.io_error_count = 0;
    
    test_unpacked_msg.uart_ftdi.rx_buffer_level = 0;
    
    test_unpacked_msg.uart_ftdi.rx_throughput = 0.0;
    
    test_unpacked_msg.uart_ftdi.tx_buffer_level = 50;
    
    test_unpacked_msg.uart_ftdi.tx_throughput = 1.315000057220459;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_EQ(last_msg_.latency.avg, -1);
    
    EXPECT_EQ(last_msg_.latency.current, -1);
    
    EXPECT_EQ(last_msg_.latency.lmax, 0);
    
    EXPECT_EQ(last_msg_.latency.lmin, 0);
    
    EXPECT_EQ(last_msg_.uart_a.crc_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_a.io_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_a.rx_buffer_level, 0);
    
    EXPECT_LT((last_msg_.uart_a.rx_throughput*100 - 0.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_a.tx_buffer_level, 2);
    
    EXPECT_LT((last_msg_.uart_a.tx_throughput*100 - 0.0120000001043*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_b.crc_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_b.io_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_b.rx_buffer_level, 0);
    
    EXPECT_LT((last_msg_.uart_b.rx_throughput*100 - 0.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_b.tx_buffer_level, 2);
    
    EXPECT_LT((last_msg_.uart_b.tx_throughput*100 - 0.0120000001043*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_ftdi.crc_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_ftdi.io_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_ftdi.rx_buffer_level, 0);
    
    EXPECT_LT((last_msg_.uart_ftdi.rx_throughput*100 - 0.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_ftdi.tx_buffer_level, 50);
    
    EXPECT_LT((last_msg_.uart_ftdi.tx_throughput*100 - 1.31500005722*100), 0.05);
}