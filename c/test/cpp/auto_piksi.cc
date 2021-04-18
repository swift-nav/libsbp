/*
 * Copyright (C) 2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

// This file was auto-generated. Do not modify by hand!

#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <gtest/gtest.h>
#include <libsbp/piksi.h>
#include <libsbp/cpp/piksi.h>
#include <libsbp/piksi.h>
#include <libsbp/cpp/piksi.h>
#include <libsbp/piksi.h>
#include <libsbp/cpp/piksi.h>
#include <libsbp/piksi.h>
#include <libsbp/cpp/piksi.h>
#include <libsbp/piksi.h>
#include <libsbp/cpp/piksi.h>
#include <libsbp/piksi.h>
#include <libsbp/cpp/piksi.h>
#include <libsbp/piksi.h>
#include <libsbp/cpp/piksi.h>
#include <libsbp/piksi.h>
#include <libsbp/cpp/piksi.h>
#include <libsbp/piksi.h>
#include <libsbp/cpp/piksi.h>
#include <libsbp/piksi.h>
#include <libsbp/cpp/piksi.h>
#include <libsbp/piksi.h>
#include <libsbp/cpp/piksi.h>
#include <libsbp/piksi.h>
#include <libsbp/cpp/piksi.h>
#include <libsbp/piksi.h>
#include <libsbp/cpp/piksi.h>
#include <libsbp/piksi.h>
#include <libsbp/cpp/piksi.h>
#include <libsbp/piksi.h>
#include <libsbp/cpp/piksi.h>
#include <libsbp/piksi.h>
#include <libsbp/cpp/piksi.h>
#include <libsbp/piksi.h>
#include <libsbp/cpp/piksi.h>
#include <libsbp/piksi.h>
#include <libsbp/cpp/piksi.h>
#include <libsbp/piksi.h>
#include <libsbp/cpp/piksi.h>
#include <libsbp/piksi.h>
#include <libsbp/cpp/piksi.h>
#include <libsbp/piksi.h>
#include <libsbp/cpp/piksi.h>
#include <libsbp/piksi.h>
#include <libsbp/cpp/piksi.h>
#include <libsbp/piksi.h>
#include <libsbp/cpp/piksi.h>
#include <libsbp/piksi.h>
#include <libsbp/cpp/piksi.h>
#include <libsbp/piksi.h>
#include <libsbp/cpp/piksi.h>
#include <libsbp/piksi.h>
#include <libsbp/cpp/piksi.h>
#include <libsbp/piksi.h>
#include <libsbp/cpp/piksi.h>
#include <libsbp/piksi.h>
#include <libsbp/cpp/piksi.h>
#include <libsbp/piksi.h>
#include <libsbp/cpp/piksi.h>


TEST(test_msg_reset, default_construction) {
  sbp::MsgReset variable;
  (void) variable;
}

TEST(test_msg_reset, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgReset);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_reset_t *c_struct = reinterpret_cast<const msg_reset_t*>(buffer);
  const sbp::MsgReset *cpp_struct = reinterpret_cast<const sbp::MsgReset*>(buffer);

//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_reset_filters, default_construction) {
  sbp::MsgResetFilters variable;
  (void) variable;
}

TEST(test_msg_reset_filters, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgResetFilters);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_reset_filters_t *c_struct = reinterpret_cast<const msg_reset_filters_t*>(buffer);
  const sbp::MsgResetFilters *cpp_struct = reinterpret_cast<const sbp::MsgResetFilters*>(buffer);

//
//  EXPECT_EQ(c_struct->filter, cpp_struct->filter);
//
}

TEST(test_msg_thread_state, default_construction) {
  sbp::MsgThreadState variable;
  (void) variable;
}

TEST(test_msg_thread_state, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgThreadState);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_thread_state_t *c_struct = reinterpret_cast<const msg_thread_state_t*>(buffer);
  const sbp::MsgThreadState *cpp_struct = reinterpret_cast<const sbp::MsgThreadState*>(buffer);

//
//  EXPECT_EQ(c_struct->name, cpp_struct->name);
//
//  EXPECT_EQ(c_struct->cpu, cpp_struct->cpu);
//
//  EXPECT_EQ(c_struct->stack_free, cpp_struct->stack_free);
//
}

TEST(test_u_a_r_t_channel, default_construction) {
  sbp::UARTChannel variable;
  (void) variable;
}

TEST(test_u_a_r_t_channel, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::UARTChannel);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const uart_channel_t *c_struct = reinterpret_cast<const uart_channel_t*>(buffer);
  const sbp::UARTChannel *cpp_struct = reinterpret_cast<const sbp::UARTChannel*>(buffer);

//
//  EXPECT_EQ(c_struct->tx_throughput, cpp_struct->tx_throughput);
//
//  EXPECT_EQ(c_struct->rx_throughput, cpp_struct->rx_throughput);
//
//  EXPECT_EQ(c_struct->crc_error_count, cpp_struct->crc_error_count);
//
//  EXPECT_EQ(c_struct->io_error_count, cpp_struct->io_error_count);
//
//  EXPECT_EQ(c_struct->tx_buffer_level, cpp_struct->tx_buffer_level);
//
//  EXPECT_EQ(c_struct->rx_buffer_level, cpp_struct->rx_buffer_level);
//
}

TEST(test_period, default_construction) {
  sbp::Period variable;
  (void) variable;
}

TEST(test_period, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::Period);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const period_t *c_struct = reinterpret_cast<const period_t*>(buffer);
  const sbp::Period *cpp_struct = reinterpret_cast<const sbp::Period*>(buffer);

//
//  EXPECT_EQ(c_struct->avg, cpp_struct->avg);
//
//  EXPECT_EQ(c_struct->pmin, cpp_struct->pmin);
//
//  EXPECT_EQ(c_struct->pmax, cpp_struct->pmax);
//
//  EXPECT_EQ(c_struct->current, cpp_struct->current);
//
}

TEST(test_latency, default_construction) {
  sbp::Latency variable;
  (void) variable;
}

TEST(test_latency, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::Latency);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const latency_t *c_struct = reinterpret_cast<const latency_t*>(buffer);
  const sbp::Latency *cpp_struct = reinterpret_cast<const sbp::Latency*>(buffer);

//
//  EXPECT_EQ(c_struct->avg, cpp_struct->avg);
//
//  EXPECT_EQ(c_struct->lmin, cpp_struct->lmin);
//
//  EXPECT_EQ(c_struct->lmax, cpp_struct->lmax);
//
//  EXPECT_EQ(c_struct->current, cpp_struct->current);
//
}

TEST(test_msg_uart_state, default_construction) {
  sbp::MsgUartState variable;
  (void) variable;
}

TEST(test_msg_uart_state, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgUartState);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_uart_state_t *c_struct = reinterpret_cast<const msg_uart_state_t*>(buffer);
  const sbp::MsgUartState *cpp_struct = reinterpret_cast<const sbp::MsgUartState*>(buffer);

//
//  EXPECT_EQ(c_struct->uart_a, cpp_struct->uart_a);
//
//  EXPECT_EQ(c_struct->uart_b, cpp_struct->uart_b);
//
//  EXPECT_EQ(c_struct->uart_ftdi, cpp_struct->uart_ftdi);
//
//  EXPECT_EQ(c_struct->latency, cpp_struct->latency);
//
//  EXPECT_EQ(c_struct->obs_period, cpp_struct->obs_period);
//
}

TEST(test_msg_uart_state_depa, default_construction) {
  sbp::MsgUartStateDepa variable;
  (void) variable;
}

TEST(test_msg_uart_state_depa, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgUartStateDepa);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_uart_state_depa_t *c_struct = reinterpret_cast<const msg_uart_state_depa_t*>(buffer);
  const sbp::MsgUartStateDepa *cpp_struct = reinterpret_cast<const sbp::MsgUartStateDepa*>(buffer);

//
//  EXPECT_EQ(c_struct->uart_a, cpp_struct->uart_a);
//
//  EXPECT_EQ(c_struct->uart_b, cpp_struct->uart_b);
//
//  EXPECT_EQ(c_struct->uart_ftdi, cpp_struct->uart_ftdi);
//
//  EXPECT_EQ(c_struct->latency, cpp_struct->latency);
//
}

TEST(test_msg_iar_state, default_construction) {
  sbp::MsgIarState variable;
  (void) variable;
}

TEST(test_msg_iar_state, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgIarState);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_iar_state_t *c_struct = reinterpret_cast<const msg_iar_state_t*>(buffer);
  const sbp::MsgIarState *cpp_struct = reinterpret_cast<const sbp::MsgIarState*>(buffer);

//
//  EXPECT_EQ(c_struct->num_hyps, cpp_struct->num_hyps);
//
}

TEST(test_msg_mask_satellite, default_construction) {
  sbp::MsgMaskSatellite variable;
  (void) variable;
}

TEST(test_msg_mask_satellite, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgMaskSatellite);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_mask_satellite_t *c_struct = reinterpret_cast<const msg_mask_satellite_t*>(buffer);
  const sbp::MsgMaskSatellite *cpp_struct = reinterpret_cast<const sbp::MsgMaskSatellite*>(buffer);

//
//  EXPECT_EQ(c_struct->mask, cpp_struct->mask);
//
//  EXPECT_EQ(c_struct->sid, cpp_struct->sid);
//
}

TEST(test_msg_mask_satellite_dep, default_construction) {
  sbp::MsgMaskSatelliteDep variable;
  (void) variable;
}

TEST(test_msg_mask_satellite_dep, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgMaskSatelliteDep);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_mask_satellite_dep_t *c_struct = reinterpret_cast<const msg_mask_satellite_dep_t*>(buffer);
  const sbp::MsgMaskSatelliteDep *cpp_struct = reinterpret_cast<const sbp::MsgMaskSatelliteDep*>(buffer);

//
//  EXPECT_EQ(c_struct->mask, cpp_struct->mask);
//
//  EXPECT_EQ(c_struct->sid, cpp_struct->sid);
//
}

TEST(test_msg_device_monitor, default_construction) {
  sbp::MsgDeviceMonitor variable;
  (void) variable;
}

TEST(test_msg_device_monitor, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgDeviceMonitor);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_device_monitor_t *c_struct = reinterpret_cast<const msg_device_monitor_t*>(buffer);
  const sbp::MsgDeviceMonitor *cpp_struct = reinterpret_cast<const sbp::MsgDeviceMonitor*>(buffer);

//
//  EXPECT_EQ(c_struct->dev_vin, cpp_struct->dev_vin);
//
//  EXPECT_EQ(c_struct->cpu_vint, cpp_struct->cpu_vint);
//
//  EXPECT_EQ(c_struct->cpu_vaux, cpp_struct->cpu_vaux);
//
//  EXPECT_EQ(c_struct->cpu_temperature, cpp_struct->cpu_temperature);
//
//  EXPECT_EQ(c_struct->fe_temperature, cpp_struct->fe_temperature);
//
}

TEST(test_msg_command_req, default_construction) {
  sbp::MsgCommandReq<> variable;
  (void) variable;
}

TEST(test_msg_command_req, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgCommandReq<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_command_req_t *c_struct = reinterpret_cast<const msg_command_req_t*>(buffer);
  const sbp::MsgCommandReq<> *cpp_struct = reinterpret_cast<const sbp::MsgCommandReq<>*>(buffer);

//
//  EXPECT_EQ(c_struct->sequence, cpp_struct->sequence);
//
//  EXPECT_EQ(c_struct->command, cpp_struct->command);
//
}

TEST(test_msg_command_resp, default_construction) {
  sbp::MsgCommandResp variable;
  (void) variable;
}

TEST(test_msg_command_resp, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgCommandResp);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_command_resp_t *c_struct = reinterpret_cast<const msg_command_resp_t*>(buffer);
  const sbp::MsgCommandResp *cpp_struct = reinterpret_cast<const sbp::MsgCommandResp*>(buffer);

//
//  EXPECT_EQ(c_struct->sequence, cpp_struct->sequence);
//
//  EXPECT_EQ(c_struct->code, cpp_struct->code);
//
}

TEST(test_msg_command_output, default_construction) {
  sbp::MsgCommandOutput<> variable;
  (void) variable;
}

TEST(test_msg_command_output, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgCommandOutput<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_command_output_t *c_struct = reinterpret_cast<const msg_command_output_t*>(buffer);
  const sbp::MsgCommandOutput<> *cpp_struct = reinterpret_cast<const sbp::MsgCommandOutput<>*>(buffer);

//
//  EXPECT_EQ(c_struct->sequence, cpp_struct->sequence);
//
//  EXPECT_EQ(c_struct->line, cpp_struct->line);
//
}

TEST(test_msg_network_state_resp, default_construction) {
  sbp::MsgNetworkStateResp variable;
  (void) variable;
}

TEST(test_msg_network_state_resp, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgNetworkStateResp);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_network_state_resp_t *c_struct = reinterpret_cast<const msg_network_state_resp_t*>(buffer);
  const sbp::MsgNetworkStateResp *cpp_struct = reinterpret_cast<const sbp::MsgNetworkStateResp*>(buffer);

//
//  EXPECT_EQ(c_struct->ipv4_address, cpp_struct->ipv4_address);
//
//  EXPECT_EQ(c_struct->ipv4_mask_size, cpp_struct->ipv4_mask_size);
//
//  EXPECT_EQ(c_struct->ipv6_address, cpp_struct->ipv6_address);
//
//  EXPECT_EQ(c_struct->ipv6_mask_size, cpp_struct->ipv6_mask_size);
//
//  EXPECT_EQ(c_struct->rx_bytes, cpp_struct->rx_bytes);
//
//  EXPECT_EQ(c_struct->tx_bytes, cpp_struct->tx_bytes);
//
//  EXPECT_EQ(c_struct->interface_name, cpp_struct->interface_name);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_network_usage, default_construction) {
  sbp::NetworkUsage variable;
  (void) variable;
}

TEST(test_network_usage, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::NetworkUsage);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const network_usage_t *c_struct = reinterpret_cast<const network_usage_t*>(buffer);
  const sbp::NetworkUsage *cpp_struct = reinterpret_cast<const sbp::NetworkUsage*>(buffer);

//
//  EXPECT_EQ(c_struct->duration, cpp_struct->duration);
//
//  EXPECT_EQ(c_struct->total_bytes, cpp_struct->total_bytes);
//
//  EXPECT_EQ(c_struct->rx_bytes, cpp_struct->rx_bytes);
//
//  EXPECT_EQ(c_struct->tx_bytes, cpp_struct->tx_bytes);
//
//  EXPECT_EQ(c_struct->interface_name, cpp_struct->interface_name);
//
}

TEST(test_msg_network_bandwidth_usage, default_construction) {
  sbp::MsgNetworkBandwidthUsage<> variable;
  (void) variable;
}

TEST(test_msg_network_bandwidth_usage, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgNetworkBandwidthUsage<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_network_bandwidth_usage_t *c_struct = reinterpret_cast<const msg_network_bandwidth_usage_t*>(buffer);
  const sbp::MsgNetworkBandwidthUsage<> *cpp_struct = reinterpret_cast<const sbp::MsgNetworkBandwidthUsage<>*>(buffer);

//
//  EXPECT_EQ(c_struct->interfaces, cpp_struct->interfaces);
//
}

TEST(test_msg_cell_modem_status, default_construction) {
  sbp::MsgCellModemStatus<> variable;
  (void) variable;
}

TEST(test_msg_cell_modem_status, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgCellModemStatus<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_cell_modem_status_t *c_struct = reinterpret_cast<const msg_cell_modem_status_t*>(buffer);
  const sbp::MsgCellModemStatus<> *cpp_struct = reinterpret_cast<const sbp::MsgCellModemStatus<>*>(buffer);

//
//  EXPECT_EQ(c_struct->signal_strength, cpp_struct->signal_strength);
//
//  EXPECT_EQ(c_struct->signal_error_rate, cpp_struct->signal_error_rate);
//
//  EXPECT_EQ(c_struct->reserved, cpp_struct->reserved);
//
}

TEST(test_msg_specan_dep, default_construction) {
  sbp::MsgSpecanDep<> variable;
  (void) variable;
}

TEST(test_msg_specan_dep, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgSpecanDep<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_specan_dep_t *c_struct = reinterpret_cast<const msg_specan_dep_t*>(buffer);
  const sbp::MsgSpecanDep<> *cpp_struct = reinterpret_cast<const sbp::MsgSpecanDep<>*>(buffer);

//
//  EXPECT_EQ(c_struct->channel_tag, cpp_struct->channel_tag);
//
//  EXPECT_EQ(c_struct->t, cpp_struct->t);
//
//  EXPECT_EQ(c_struct->freq_ref, cpp_struct->freq_ref);
//
//  EXPECT_EQ(c_struct->freq_step, cpp_struct->freq_step);
//
//  EXPECT_EQ(c_struct->amplitude_ref, cpp_struct->amplitude_ref);
//
//  EXPECT_EQ(c_struct->amplitude_unit, cpp_struct->amplitude_unit);
//
//  EXPECT_EQ(c_struct->amplitude_value, cpp_struct->amplitude_value);
//
}

TEST(test_msg_specan, default_construction) {
  sbp::MsgSpecan<> variable;
  (void) variable;
}

TEST(test_msg_specan, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgSpecan<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_specan_t *c_struct = reinterpret_cast<const msg_specan_t*>(buffer);
  const sbp::MsgSpecan<> *cpp_struct = reinterpret_cast<const sbp::MsgSpecan<>*>(buffer);

//
//  EXPECT_EQ(c_struct->channel_tag, cpp_struct->channel_tag);
//
//  EXPECT_EQ(c_struct->t, cpp_struct->t);
//
//  EXPECT_EQ(c_struct->freq_ref, cpp_struct->freq_ref);
//
//  EXPECT_EQ(c_struct->freq_step, cpp_struct->freq_step);
//
//  EXPECT_EQ(c_struct->amplitude_ref, cpp_struct->amplitude_ref);
//
//  EXPECT_EQ(c_struct->amplitude_unit, cpp_struct->amplitude_unit);
//
//  EXPECT_EQ(c_struct->amplitude_value, cpp_struct->amplitude_value);
//
}

TEST(test_msg_front_end_gain, default_construction) {
  sbp::MsgFrontEndGain variable;
  (void) variable;
}

TEST(test_msg_front_end_gain, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgFrontEndGain);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_front_end_gain_t *c_struct = reinterpret_cast<const msg_front_end_gain_t*>(buffer);
  const sbp::MsgFrontEndGain *cpp_struct = reinterpret_cast<const sbp::MsgFrontEndGain*>(buffer);

//
//  EXPECT_EQ(c_struct->rf_gain, cpp_struct->rf_gain);
//
//  EXPECT_EQ(c_struct->if_gain, cpp_struct->if_gain);
//
}
