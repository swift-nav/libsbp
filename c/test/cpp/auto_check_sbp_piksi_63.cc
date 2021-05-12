#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_piksi_630 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_uart_state_depa_t>
{
public:
  Test_auto_check_sbp_piksi_630() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_uart_state_depa_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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
                                                                              
TEST_F(Test_auto_check_sbp_piksi_630, Test)     
{

    uint8_t encoded_frame[] = {85,24,0,246,215,58,26,191,93,63,0,0,0,0,0,0,0,0,24,0,123,50,62,64,0,0,0,0,0,0,0,0,40,0,54,7,162,64,177,57,16,61,0,0,0,0,81,1,255,255,255,255,0,0,0,0,0,0,0,0,255,255,255,255,71,124, };

    sbp_msg_uart_state_depa_t test_unpacked_msg{};
    
    test_unpacked_msg.latency.avg = -1;
    
    test_unpacked_msg.latency.current = -1;
    
    test_unpacked_msg.latency.lmax = 0;
    
    test_unpacked_msg.latency.lmin = 0;
    
    test_unpacked_msg.uart_a.crc_error_count = 0;
    
    test_unpacked_msg.uart_a.io_error_count = 0;
    
    test_unpacked_msg.uart_a.rx_buffer_level = 0;
    
    test_unpacked_msg.uart_a.rx_throughput = 0.0;
    
    test_unpacked_msg.uart_a.tx_buffer_level = 24;
    
    test_unpacked_msg.uart_a.tx_throughput = 0.8661972284317017;
    
    test_unpacked_msg.uart_b.crc_error_count = 0;
    
    test_unpacked_msg.uart_b.io_error_count = 0;
    
    test_unpacked_msg.uart_b.rx_buffer_level = 0;
    
    test_unpacked_msg.uart_b.rx_throughput = 0.0;
    
    test_unpacked_msg.uart_b.tx_buffer_level = 40;
    
    test_unpacked_msg.uart_b.tx_throughput = 2.9718310832977295;
    
    test_unpacked_msg.uart_ftdi.crc_error_count = 0;
    
    test_unpacked_msg.uart_ftdi.io_error_count = 0;
    
    test_unpacked_msg.uart_ftdi.rx_buffer_level = 1;
    
    test_unpacked_msg.uart_ftdi.rx_throughput = 0.035211268812417984;
    
    test_unpacked_msg.uart_ftdi.tx_buffer_level = 81;
    
    test_unpacked_msg.uart_ftdi.tx_throughput = 5.063380241394043;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_EQ(last_msg_.latency.avg, -1);
    
    EXPECT_EQ(last_msg_.latency.current, -1);
    
    EXPECT_EQ(last_msg_.latency.lmax, 0);
    
    EXPECT_EQ(last_msg_.latency.lmin, 0);
    
    EXPECT_EQ(last_msg_.uart_a.crc_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_a.io_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_a.rx_buffer_level, 0);
    
    EXPECT_LT((last_msg_.uart_a.rx_throughput*100 - 0.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_a.tx_buffer_level, 24);
    
    EXPECT_LT((last_msg_.uart_a.tx_throughput*100 - 0.866197228432*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_b.crc_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_b.io_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_b.rx_buffer_level, 0);
    
    EXPECT_LT((last_msg_.uart_b.rx_throughput*100 - 0.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_b.tx_buffer_level, 40);
    
    EXPECT_LT((last_msg_.uart_b.tx_throughput*100 - 2.9718310833*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_ftdi.crc_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_ftdi.io_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_ftdi.rx_buffer_level, 1);
    
    EXPECT_LT((last_msg_.uart_ftdi.rx_throughput*100 - 0.0352112688124*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_ftdi.tx_buffer_level, 81);
    
    EXPECT_LT((last_msg_.uart_ftdi.tx_throughput*100 - 5.06338024139*100), 0.05);
}                                                     
class Test_auto_check_sbp_piksi_631 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_uart_state_depa_t>
{
public:
  Test_auto_check_sbp_piksi_631() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_uart_state_depa_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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
                                                                              
TEST_F(Test_auto_check_sbp_piksi_631, Test)     
{

    uint8_t encoded_frame[] = {85,24,0,246,215,58,237,232,95,63,0,0,0,0,0,0,0,0,24,0,198,186,63,64,0,0,0,0,0,0,0,0,40,0,214,72,217,64,29,72,180,62,0,0,0,0,85,1,255,255,255,255,0,0,0,0,0,0,0,0,255,255,255,255,153,248, };

    sbp_msg_uart_state_depa_t test_unpacked_msg{};
    
    test_unpacked_msg.latency.avg = -1;
    
    test_unpacked_msg.latency.current = -1;
    
    test_unpacked_msg.latency.lmax = 0;
    
    test_unpacked_msg.latency.lmin = 0;
    
    test_unpacked_msg.uart_a.crc_error_count = 0;
    
    test_unpacked_msg.uart_a.io_error_count = 0;
    
    test_unpacked_msg.uart_a.rx_buffer_level = 0;
    
    test_unpacked_msg.uart_a.rx_throughput = 0.0;
    
    test_unpacked_msg.uart_a.tx_buffer_level = 24;
    
    test_unpacked_msg.uart_a.tx_throughput = 0.8746479153633118;
    
    test_unpacked_msg.uart_b.crc_error_count = 0;
    
    test_unpacked_msg.uart_b.io_error_count = 0;
    
    test_unpacked_msg.uart_b.rx_buffer_level = 0;
    
    test_unpacked_msg.uart_b.rx_throughput = 0.0;
    
    test_unpacked_msg.uart_b.tx_buffer_level = 40;
    
    test_unpacked_msg.uart_b.tx_throughput = 2.995774745941162;
    
    test_unpacked_msg.uart_ftdi.crc_error_count = 0;
    
    test_unpacked_msg.uart_ftdi.io_error_count = 0;
    
    test_unpacked_msg.uart_ftdi.rx_buffer_level = 1;
    
    test_unpacked_msg.uart_ftdi.rx_throughput = 0.35211268067359924;
    
    test_unpacked_msg.uart_ftdi.tx_buffer_level = 85;
    
    test_unpacked_msg.uart_ftdi.tx_throughput = 6.7901411056518555;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_EQ(last_msg_.latency.avg, -1);
    
    EXPECT_EQ(last_msg_.latency.current, -1);
    
    EXPECT_EQ(last_msg_.latency.lmax, 0);
    
    EXPECT_EQ(last_msg_.latency.lmin, 0);
    
    EXPECT_EQ(last_msg_.uart_a.crc_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_a.io_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_a.rx_buffer_level, 0);
    
    EXPECT_LT((last_msg_.uart_a.rx_throughput*100 - 0.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_a.tx_buffer_level, 24);
    
    EXPECT_LT((last_msg_.uart_a.tx_throughput*100 - 0.874647915363*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_b.crc_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_b.io_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_b.rx_buffer_level, 0);
    
    EXPECT_LT((last_msg_.uart_b.rx_throughput*100 - 0.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_b.tx_buffer_level, 40);
    
    EXPECT_LT((last_msg_.uart_b.tx_throughput*100 - 2.99577474594*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_ftdi.crc_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_ftdi.io_error_count, 0);
    
    EXPECT_EQ(last_msg_.uart_ftdi.rx_buffer_level, 1);
    
    EXPECT_LT((last_msg_.uart_ftdi.rx_throughput*100 - 0.352112680674*100), 0.05);
    
    EXPECT_EQ(last_msg_.uart_ftdi.tx_buffer_level, 85);
    
    EXPECT_LT((last_msg_.uart_ftdi.tx_throughput*100 - 6.79014110565*100), 0.05);
}