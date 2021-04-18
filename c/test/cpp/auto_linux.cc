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
#include <libsbp/linux.h>
#include <libsbp/cpp/linux.h>
#include <libsbp/linux.h>
#include <libsbp/cpp/linux.h>
#include <libsbp/linux.h>
#include <libsbp/cpp/linux.h>
#include <libsbp/linux.h>
#include <libsbp/cpp/linux.h>
#include <libsbp/linux.h>
#include <libsbp/cpp/linux.h>
#include <libsbp/linux.h>
#include <libsbp/cpp/linux.h>
#include <libsbp/linux.h>
#include <libsbp/cpp/linux.h>
#include <libsbp/linux.h>
#include <libsbp/cpp/linux.h>
#include <libsbp/linux.h>
#include <libsbp/cpp/linux.h>
#include <libsbp/linux.h>
#include <libsbp/cpp/linux.h>
#include <libsbp/linux.h>
#include <libsbp/cpp/linux.h>


TEST(test_msg_linux_cpu_state_dep_a, default_construction) {
  sbp::MsgLinuxCpuStateDepA<> variable;
  (void) variable;
}

TEST(test_msg_linux_cpu_state_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgLinuxCpuStateDepA<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_linux_cpu_state_dep_a_t *c_struct = reinterpret_cast<const msg_linux_cpu_state_dep_a_t*>(buffer);
  const sbp::MsgLinuxCpuStateDepA<> *cpp_struct = reinterpret_cast<const sbp::MsgLinuxCpuStateDepA<>*>(buffer);

//
//  EXPECT_EQ(c_struct->index, cpp_struct->index);
//
//  EXPECT_EQ(c_struct->pid, cpp_struct->pid);
//
//  EXPECT_EQ(c_struct->pcpu, cpp_struct->pcpu);
//
//  EXPECT_EQ(c_struct->tname, cpp_struct->tname);
//
//  EXPECT_EQ(c_struct->cmdline, cpp_struct->cmdline);
//
}

TEST(test_msg_linux_mem_state_dep_a, default_construction) {
  sbp::MsgLinuxMemStateDepA<> variable;
  (void) variable;
}

TEST(test_msg_linux_mem_state_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgLinuxMemStateDepA<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_linux_mem_state_dep_a_t *c_struct = reinterpret_cast<const msg_linux_mem_state_dep_a_t*>(buffer);
  const sbp::MsgLinuxMemStateDepA<> *cpp_struct = reinterpret_cast<const sbp::MsgLinuxMemStateDepA<>*>(buffer);

//
//  EXPECT_EQ(c_struct->index, cpp_struct->index);
//
//  EXPECT_EQ(c_struct->pid, cpp_struct->pid);
//
//  EXPECT_EQ(c_struct->pmem, cpp_struct->pmem);
//
//  EXPECT_EQ(c_struct->tname, cpp_struct->tname);
//
//  EXPECT_EQ(c_struct->cmdline, cpp_struct->cmdline);
//
}

TEST(test_msg_linux_sys_state_dep_a, default_construction) {
  sbp::MsgLinuxSysStateDepA variable;
  (void) variable;
}

TEST(test_msg_linux_sys_state_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgLinuxSysStateDepA);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_linux_sys_state_dep_a_t *c_struct = reinterpret_cast<const msg_linux_sys_state_dep_a_t*>(buffer);
  const sbp::MsgLinuxSysStateDepA *cpp_struct = reinterpret_cast<const sbp::MsgLinuxSysStateDepA*>(buffer);

//
//  EXPECT_EQ(c_struct->mem_total, cpp_struct->mem_total);
//
//  EXPECT_EQ(c_struct->pcpu, cpp_struct->pcpu);
//
//  EXPECT_EQ(c_struct->pmem, cpp_struct->pmem);
//
//  EXPECT_EQ(c_struct->procs_starting, cpp_struct->procs_starting);
//
//  EXPECT_EQ(c_struct->procs_stopping, cpp_struct->procs_stopping);
//
//  EXPECT_EQ(c_struct->pid_count, cpp_struct->pid_count);
//
}

TEST(test_msg_linux_process_socket_counts, default_construction) {
  sbp::MsgLinuxProcessSocketCounts<> variable;
  (void) variable;
}

TEST(test_msg_linux_process_socket_counts, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgLinuxProcessSocketCounts<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_linux_process_socket_counts_t *c_struct = reinterpret_cast<const msg_linux_process_socket_counts_t*>(buffer);
  const sbp::MsgLinuxProcessSocketCounts<> *cpp_struct = reinterpret_cast<const sbp::MsgLinuxProcessSocketCounts<>*>(buffer);

//
//  EXPECT_EQ(c_struct->index, cpp_struct->index);
//
//  EXPECT_EQ(c_struct->pid, cpp_struct->pid);
//
//  EXPECT_EQ(c_struct->socket_count, cpp_struct->socket_count);
//
//  EXPECT_EQ(c_struct->socket_types, cpp_struct->socket_types);
//
//  EXPECT_EQ(c_struct->socket_states, cpp_struct->socket_states);
//
//  EXPECT_EQ(c_struct->cmdline, cpp_struct->cmdline);
//
}

TEST(test_msg_linux_process_socket_queues, default_construction) {
  sbp::MsgLinuxProcessSocketQueues<> variable;
  (void) variable;
}

TEST(test_msg_linux_process_socket_queues, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgLinuxProcessSocketQueues<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_linux_process_socket_queues_t *c_struct = reinterpret_cast<const msg_linux_process_socket_queues_t*>(buffer);
  const sbp::MsgLinuxProcessSocketQueues<> *cpp_struct = reinterpret_cast<const sbp::MsgLinuxProcessSocketQueues<>*>(buffer);

//
//  EXPECT_EQ(c_struct->index, cpp_struct->index);
//
//  EXPECT_EQ(c_struct->pid, cpp_struct->pid);
//
//  EXPECT_EQ(c_struct->recv_queued, cpp_struct->recv_queued);
//
//  EXPECT_EQ(c_struct->send_queued, cpp_struct->send_queued);
//
//  EXPECT_EQ(c_struct->socket_types, cpp_struct->socket_types);
//
//  EXPECT_EQ(c_struct->socket_states, cpp_struct->socket_states);
//
//  EXPECT_EQ(c_struct->address_of_largest, cpp_struct->address_of_largest);
//
//  EXPECT_EQ(c_struct->cmdline, cpp_struct->cmdline);
//
}

TEST(test_msg_linux_socket_usage, default_construction) {
  sbp::MsgLinuxSocketUsage variable;
  (void) variable;
}

TEST(test_msg_linux_socket_usage, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgLinuxSocketUsage);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_linux_socket_usage_t *c_struct = reinterpret_cast<const msg_linux_socket_usage_t*>(buffer);
  const sbp::MsgLinuxSocketUsage *cpp_struct = reinterpret_cast<const sbp::MsgLinuxSocketUsage*>(buffer);

//
//  EXPECT_EQ(c_struct->avg_queue_depth, cpp_struct->avg_queue_depth);
//
//  EXPECT_EQ(c_struct->max_queue_depth, cpp_struct->max_queue_depth);
//
//  EXPECT_EQ(c_struct->socket_state_counts, cpp_struct->socket_state_counts);
//
//  EXPECT_EQ(c_struct->socket_type_counts, cpp_struct->socket_type_counts);
//
}

TEST(test_msg_linux_process_fd_count, default_construction) {
  sbp::MsgLinuxProcessFdCount<> variable;
  (void) variable;
}

TEST(test_msg_linux_process_fd_count, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgLinuxProcessFdCount<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_linux_process_fd_count_t *c_struct = reinterpret_cast<const msg_linux_process_fd_count_t*>(buffer);
  const sbp::MsgLinuxProcessFdCount<> *cpp_struct = reinterpret_cast<const sbp::MsgLinuxProcessFdCount<>*>(buffer);

//
//  EXPECT_EQ(c_struct->index, cpp_struct->index);
//
//  EXPECT_EQ(c_struct->pid, cpp_struct->pid);
//
//  EXPECT_EQ(c_struct->fd_count, cpp_struct->fd_count);
//
//  EXPECT_EQ(c_struct->cmdline, cpp_struct->cmdline);
//
}

TEST(test_msg_linux_process_fd_summary, default_construction) {
  sbp::MsgLinuxProcessFdSummary<> variable;
  (void) variable;
}

TEST(test_msg_linux_process_fd_summary, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgLinuxProcessFdSummary<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_linux_process_fd_summary_t *c_struct = reinterpret_cast<const msg_linux_process_fd_summary_t*>(buffer);
  const sbp::MsgLinuxProcessFdSummary<> *cpp_struct = reinterpret_cast<const sbp::MsgLinuxProcessFdSummary<>*>(buffer);

//
//  EXPECT_EQ(c_struct->sys_fd_count, cpp_struct->sys_fd_count);
//
//  EXPECT_EQ(c_struct->most_opened, cpp_struct->most_opened);
//
}

TEST(test_msg_linux_cpu_state, default_construction) {
  sbp::MsgLinuxCpuState<> variable;
  (void) variable;
}

TEST(test_msg_linux_cpu_state, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgLinuxCpuState<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_linux_cpu_state_t *c_struct = reinterpret_cast<const msg_linux_cpu_state_t*>(buffer);
  const sbp::MsgLinuxCpuState<> *cpp_struct = reinterpret_cast<const sbp::MsgLinuxCpuState<>*>(buffer);

//
//  EXPECT_EQ(c_struct->index, cpp_struct->index);
//
//  EXPECT_EQ(c_struct->pid, cpp_struct->pid);
//
//  EXPECT_EQ(c_struct->pcpu, cpp_struct->pcpu);
//
//  EXPECT_EQ(c_struct->time, cpp_struct->time);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
//  EXPECT_EQ(c_struct->tname, cpp_struct->tname);
//
//  EXPECT_EQ(c_struct->cmdline, cpp_struct->cmdline);
//
}

TEST(test_msg_linux_mem_state, default_construction) {
  sbp::MsgLinuxMemState<> variable;
  (void) variable;
}

TEST(test_msg_linux_mem_state, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgLinuxMemState<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_linux_mem_state_t *c_struct = reinterpret_cast<const msg_linux_mem_state_t*>(buffer);
  const sbp::MsgLinuxMemState<> *cpp_struct = reinterpret_cast<const sbp::MsgLinuxMemState<>*>(buffer);

//
//  EXPECT_EQ(c_struct->index, cpp_struct->index);
//
//  EXPECT_EQ(c_struct->pid, cpp_struct->pid);
//
//  EXPECT_EQ(c_struct->pmem, cpp_struct->pmem);
//
//  EXPECT_EQ(c_struct->time, cpp_struct->time);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
//  EXPECT_EQ(c_struct->tname, cpp_struct->tname);
//
//  EXPECT_EQ(c_struct->cmdline, cpp_struct->cmdline);
//
}

TEST(test_msg_linux_sys_state, default_construction) {
  sbp::MsgLinuxSysState variable;
  (void) variable;
}

TEST(test_msg_linux_sys_state, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgLinuxSysState);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_linux_sys_state_t *c_struct = reinterpret_cast<const msg_linux_sys_state_t*>(buffer);
  const sbp::MsgLinuxSysState *cpp_struct = reinterpret_cast<const sbp::MsgLinuxSysState*>(buffer);

//
//  EXPECT_EQ(c_struct->mem_total, cpp_struct->mem_total);
//
//  EXPECT_EQ(c_struct->pcpu, cpp_struct->pcpu);
//
//  EXPECT_EQ(c_struct->pmem, cpp_struct->pmem);
//
//  EXPECT_EQ(c_struct->procs_starting, cpp_struct->procs_starting);
//
//  EXPECT_EQ(c_struct->procs_stopping, cpp_struct->procs_stopping);
//
//  EXPECT_EQ(c_struct->pid_count, cpp_struct->pid_count);
//
//  EXPECT_EQ(c_struct->time, cpp_struct->time);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}
