#ifndef LIBSBP_PIKSI_OPERATORS_H
#define LIBSBP_PIKSI_OPERATORS_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/gnss.h>
#include <libsbp/unpacked/piksi.h>
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_almanac_t &a, const sbp_msg_almanac_t &b)
{
  (void)a;
  (void)b;

  return true;
}

static inline bool operator!=(const sbp_msg_almanac_t &a, const sbp_msg_almanac_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_set_time_t &a, const sbp_msg_set_time_t &b)
{
  (void)a;
  (void)b;

  return true;
}

static inline bool operator!=(const sbp_msg_set_time_t &a, const sbp_msg_set_time_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_reset_t &a, const sbp_msg_reset_t &b)
{
  (void)a;
  (void)b;

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_reset_t &a, const sbp_msg_reset_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_reset_dep_t &a, const sbp_msg_reset_dep_t &b)
{
  (void)a;
  (void)b;

  return true;
}

static inline bool operator!=(const sbp_msg_reset_dep_t &a, const sbp_msg_reset_dep_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_cw_results_t &a, const sbp_msg_cw_results_t &b)
{
  (void)a;
  (void)b;

  return true;
}

static inline bool operator!=(const sbp_msg_cw_results_t &a, const sbp_msg_cw_results_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_cw_start_t &a, const sbp_msg_cw_start_t &b)
{
  (void)a;
  (void)b;

  return true;
}

static inline bool operator!=(const sbp_msg_cw_start_t &a, const sbp_msg_cw_start_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_reset_filters_t &a, const sbp_msg_reset_filters_t &b)
{
  (void)a;
  (void)b;

  if (a.filter != b.filter)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_reset_filters_t &a, const sbp_msg_reset_filters_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_init_base_dep_t &a, const sbp_msg_init_base_dep_t &b)
{
  (void)a;
  (void)b;

  return true;
}

static inline bool operator!=(const sbp_msg_init_base_dep_t &a, const sbp_msg_init_base_dep_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_thread_state_t &a, const sbp_msg_thread_state_t &b)
{
  (void)a;
  (void)b;

  for (size_t name_idx = 0; name_idx < 20; name_idx++)
  {

    if (a.name[name_idx] != b.name[name_idx])
    {
      return false;
    }
  }

  if (a.cpu != b.cpu)
  {
    return false;
  }

  if (a.stack_free != b.stack_free)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_thread_state_t &a, const sbp_msg_thread_state_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_uart_channel_t &a, const sbp_uart_channel_t &b)
{
  (void)a;
  (void)b;

  if (fabs(a.tx_throughput - b.tx_throughput) > 0.001)
  {
    return false;
  }

  if (fabs(a.rx_throughput - b.rx_throughput) > 0.001)
  {
    return false;
  }

  if (a.crc_error_count != b.crc_error_count)
  {
    return false;
  }

  if (a.io_error_count != b.io_error_count)
  {
    return false;
  }

  if (a.tx_buffer_level != b.tx_buffer_level)
  {
    return false;
  }

  if (a.rx_buffer_level != b.rx_buffer_level)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_uart_channel_t &a, const sbp_uart_channel_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_period_t &a, const sbp_period_t &b)
{
  (void)a;
  (void)b;

  if (a.avg != b.avg)
  {
    return false;
  }

  if (a.pmin != b.pmin)
  {
    return false;
  }

  if (a.pmax != b.pmax)
  {
    return false;
  }

  if (a.current != b.current)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_period_t &a, const sbp_period_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_latency_t &a, const sbp_latency_t &b)
{
  (void)a;
  (void)b;

  if (a.avg != b.avg)
  {
    return false;
  }

  if (a.lmin != b.lmin)
  {
    return false;
  }

  if (a.lmax != b.lmax)
  {
    return false;
  }

  if (a.current != b.current)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_latency_t &a, const sbp_latency_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_uart_state_t &a, const sbp_msg_uart_state_t &b)
{
  (void)a;
  (void)b;

  if (fabs(a.uart_a.tx_throughput - b.uart_a.tx_throughput) > 0.001)
  {
    return false;
  }

  if (fabs(a.uart_a.rx_throughput - b.uart_a.rx_throughput) > 0.001)
  {
    return false;
  }

  if (a.uart_a.crc_error_count != b.uart_a.crc_error_count)
  {
    return false;
  }

  if (a.uart_a.io_error_count != b.uart_a.io_error_count)
  {
    return false;
  }

  if (a.uart_a.tx_buffer_level != b.uart_a.tx_buffer_level)
  {
    return false;
  }

  if (a.uart_a.rx_buffer_level != b.uart_a.rx_buffer_level)
  {
    return false;
  }

  if (fabs(a.uart_b.tx_throughput - b.uart_b.tx_throughput) > 0.001)
  {
    return false;
  }

  if (fabs(a.uart_b.rx_throughput - b.uart_b.rx_throughput) > 0.001)
  {
    return false;
  }

  if (a.uart_b.crc_error_count != b.uart_b.crc_error_count)
  {
    return false;
  }

  if (a.uart_b.io_error_count != b.uart_b.io_error_count)
  {
    return false;
  }

  if (a.uart_b.tx_buffer_level != b.uart_b.tx_buffer_level)
  {
    return false;
  }

  if (a.uart_b.rx_buffer_level != b.uart_b.rx_buffer_level)
  {
    return false;
  }

  if (fabs(a.uart_ftdi.tx_throughput - b.uart_ftdi.tx_throughput) > 0.001)
  {
    return false;
  }

  if (fabs(a.uart_ftdi.rx_throughput - b.uart_ftdi.rx_throughput) > 0.001)
  {
    return false;
  }

  if (a.uart_ftdi.crc_error_count != b.uart_ftdi.crc_error_count)
  {
    return false;
  }

  if (a.uart_ftdi.io_error_count != b.uart_ftdi.io_error_count)
  {
    return false;
  }

  if (a.uart_ftdi.tx_buffer_level != b.uart_ftdi.tx_buffer_level)
  {
    return false;
  }

  if (a.uart_ftdi.rx_buffer_level != b.uart_ftdi.rx_buffer_level)
  {
    return false;
  }

  if (a.latency.avg != b.latency.avg)
  {
    return false;
  }

  if (a.latency.lmin != b.latency.lmin)
  {
    return false;
  }

  if (a.latency.lmax != b.latency.lmax)
  {
    return false;
  }

  if (a.latency.current != b.latency.current)
  {
    return false;
  }

  if (a.obs_period.avg != b.obs_period.avg)
  {
    return false;
  }

  if (a.obs_period.pmin != b.obs_period.pmin)
  {
    return false;
  }

  if (a.obs_period.pmax != b.obs_period.pmax)
  {
    return false;
  }

  if (a.obs_period.current != b.obs_period.current)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_uart_state_t &a, const sbp_msg_uart_state_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_uart_state_depa_t &a, const sbp_msg_uart_state_depa_t &b)
{
  (void)a;
  (void)b;

  if (fabs(a.uart_a.tx_throughput - b.uart_a.tx_throughput) > 0.001)
  {
    return false;
  }

  if (fabs(a.uart_a.rx_throughput - b.uart_a.rx_throughput) > 0.001)
  {
    return false;
  }

  if (a.uart_a.crc_error_count != b.uart_a.crc_error_count)
  {
    return false;
  }

  if (a.uart_a.io_error_count != b.uart_a.io_error_count)
  {
    return false;
  }

  if (a.uart_a.tx_buffer_level != b.uart_a.tx_buffer_level)
  {
    return false;
  }

  if (a.uart_a.rx_buffer_level != b.uart_a.rx_buffer_level)
  {
    return false;
  }

  if (fabs(a.uart_b.tx_throughput - b.uart_b.tx_throughput) > 0.001)
  {
    return false;
  }

  if (fabs(a.uart_b.rx_throughput - b.uart_b.rx_throughput) > 0.001)
  {
    return false;
  }

  if (a.uart_b.crc_error_count != b.uart_b.crc_error_count)
  {
    return false;
  }

  if (a.uart_b.io_error_count != b.uart_b.io_error_count)
  {
    return false;
  }

  if (a.uart_b.tx_buffer_level != b.uart_b.tx_buffer_level)
  {
    return false;
  }

  if (a.uart_b.rx_buffer_level != b.uart_b.rx_buffer_level)
  {
    return false;
  }

  if (fabs(a.uart_ftdi.tx_throughput - b.uart_ftdi.tx_throughput) > 0.001)
  {
    return false;
  }

  if (fabs(a.uart_ftdi.rx_throughput - b.uart_ftdi.rx_throughput) > 0.001)
  {
    return false;
  }

  if (a.uart_ftdi.crc_error_count != b.uart_ftdi.crc_error_count)
  {
    return false;
  }

  if (a.uart_ftdi.io_error_count != b.uart_ftdi.io_error_count)
  {
    return false;
  }

  if (a.uart_ftdi.tx_buffer_level != b.uart_ftdi.tx_buffer_level)
  {
    return false;
  }

  if (a.uart_ftdi.rx_buffer_level != b.uart_ftdi.rx_buffer_level)
  {
    return false;
  }

  if (a.latency.avg != b.latency.avg)
  {
    return false;
  }

  if (a.latency.lmin != b.latency.lmin)
  {
    return false;
  }

  if (a.latency.lmax != b.latency.lmax)
  {
    return false;
  }

  if (a.latency.current != b.latency.current)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_uart_state_depa_t &a, const sbp_msg_uart_state_depa_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_iar_state_t &a, const sbp_msg_iar_state_t &b)
{
  (void)a;
  (void)b;

  if (a.num_hyps != b.num_hyps)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_iar_state_t &a, const sbp_msg_iar_state_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_mask_satellite_t &a, const sbp_msg_mask_satellite_t &b)
{
  (void)a;
  (void)b;

  if (a.mask != b.mask)
  {
    return false;
  }

  if (a.sid.sat != b.sid.sat)
  {
    return false;
  }

  if (a.sid.code != b.sid.code)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_mask_satellite_t &a, const sbp_msg_mask_satellite_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_mask_satellite_dep_t &a, const sbp_msg_mask_satellite_dep_t &b)
{
  (void)a;
  (void)b;

  if (a.mask != b.mask)
  {
    return false;
  }

  if (a.sid.sat != b.sid.sat)
  {
    return false;
  }

  if (a.sid.code != b.sid.code)
  {
    return false;
  }

  if (a.sid.reserved != b.sid.reserved)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_mask_satellite_dep_t &a, const sbp_msg_mask_satellite_dep_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_device_monitor_t &a, const sbp_msg_device_monitor_t &b)
{
  (void)a;
  (void)b;

  if (a.dev_vin != b.dev_vin)
  {
    return false;
  }

  if (a.cpu_vint != b.cpu_vint)
  {
    return false;
  }

  if (a.cpu_vaux != b.cpu_vaux)
  {
    return false;
  }

  if (a.cpu_temperature != b.cpu_temperature)
  {
    return false;
  }

  if (a.fe_temperature != b.fe_temperature)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_device_monitor_t &a, const sbp_msg_device_monitor_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_command_req_t &a, const sbp_msg_command_req_t &b)
{
  (void)a;
  (void)b;

  if (a.sequence != b.sequence)
  {
    return false;
  }
  if (a.n_command != b.n_command)
  {
    return false;
  }
  for (size_t command_idx = 0; command_idx < (size_t)a.n_command; command_idx++)
  {

    if (a.command[command_idx] != b.command[command_idx])
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_command_req_t &a, const sbp_msg_command_req_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_command_resp_t &a, const sbp_msg_command_resp_t &b)
{
  (void)a;
  (void)b;

  if (a.sequence != b.sequence)
  {
    return false;
  }

  if (a.code != b.code)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_command_resp_t &a, const sbp_msg_command_resp_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_command_output_t &a, const sbp_msg_command_output_t &b)
{
  (void)a;
  (void)b;

  if (a.sequence != b.sequence)
  {
    return false;
  }
  if (a.n_line != b.n_line)
  {
    return false;
  }
  for (size_t line_idx = 0; line_idx < (size_t)a.n_line; line_idx++)
  {

    if (a.line[line_idx] != b.line[line_idx])
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_command_output_t &a, const sbp_msg_command_output_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_network_state_req_t &a, const sbp_msg_network_state_req_t &b)
{
  (void)a;
  (void)b;

  return true;
}

static inline bool operator!=(const sbp_msg_network_state_req_t &a, const sbp_msg_network_state_req_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_network_state_resp_t &a, const sbp_msg_network_state_resp_t &b)
{
  (void)a;
  (void)b;

  for (size_t ipv4_address_idx = 0; ipv4_address_idx < 4; ipv4_address_idx++)
  {

    if (a.ipv4_address[ipv4_address_idx] != b.ipv4_address[ipv4_address_idx])
    {
      return false;
    }
  }

  if (a.ipv4_mask_size != b.ipv4_mask_size)
  {
    return false;
  }
  for (size_t ipv6_address_idx = 0; ipv6_address_idx < 16; ipv6_address_idx++)
  {

    if (a.ipv6_address[ipv6_address_idx] != b.ipv6_address[ipv6_address_idx])
    {
      return false;
    }
  }

  if (a.ipv6_mask_size != b.ipv6_mask_size)
  {
    return false;
  }

  if (a.rx_bytes != b.rx_bytes)
  {
    return false;
  }

  if (a.tx_bytes != b.tx_bytes)
  {
    return false;
  }
  for (size_t interface_name_idx = 0; interface_name_idx < 16; interface_name_idx++)
  {

    if (a.interface_name[interface_name_idx] != b.interface_name[interface_name_idx])
    {
      return false;
    }
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_network_state_resp_t &a, const sbp_msg_network_state_resp_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_network_usage_t &a, const sbp_network_usage_t &b)
{
  (void)a;
  (void)b;

  if (a.duration != b.duration)
  {
    return false;
  }

  if (a.total_bytes != b.total_bytes)
  {
    return false;
  }

  if (a.rx_bytes != b.rx_bytes)
  {
    return false;
  }

  if (a.tx_bytes != b.tx_bytes)
  {
    return false;
  }
  for (size_t interface_name_idx = 0; interface_name_idx < 16; interface_name_idx++)
  {

    if (a.interface_name[interface_name_idx] != b.interface_name[interface_name_idx])
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_network_usage_t &a, const sbp_network_usage_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_network_bandwidth_usage_t &a, const sbp_msg_network_bandwidth_usage_t &b)
{
  (void)a;
  (void)b;

  if (a.n_interfaces != b.n_interfaces)
  {
    return false;
  }
  for (size_t interfaces_idx = 0; interfaces_idx < (size_t)a.n_interfaces; interfaces_idx++)
  {

    if (a.interfaces[interfaces_idx].duration != b.interfaces[interfaces_idx].duration)
    {
      return false;
    }

    if (a.interfaces[interfaces_idx].total_bytes != b.interfaces[interfaces_idx].total_bytes)
    {
      return false;
    }

    if (a.interfaces[interfaces_idx].rx_bytes != b.interfaces[interfaces_idx].rx_bytes)
    {
      return false;
    }

    if (a.interfaces[interfaces_idx].tx_bytes != b.interfaces[interfaces_idx].tx_bytes)
    {
      return false;
    }
    for (size_t interfacesinterfaces_idxinterface_name_idx = 0; interfacesinterfaces_idxinterface_name_idx < 16;
         interfacesinterfaces_idxinterface_name_idx++)
    {

      if (a.interfaces[interfaces_idx].interface_name[interfacesinterfaces_idxinterface_name_idx] !=
          b.interfaces[interfaces_idx].interface_name[interfacesinterfaces_idxinterface_name_idx])
      {
        return false;
      }
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_network_bandwidth_usage_t &a, const sbp_msg_network_bandwidth_usage_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_cell_modem_status_t &a, const sbp_msg_cell_modem_status_t &b)
{
  (void)a;
  (void)b;

  if (a.signal_strength != b.signal_strength)
  {
    return false;
  }

  if (fabs(a.signal_error_rate - b.signal_error_rate) > 0.001)
  {
    return false;
  }
  if (a.n_reserved != b.n_reserved)
  {
    return false;
  }
  for (size_t reserved_idx = 0; reserved_idx < (size_t)a.n_reserved; reserved_idx++)
  {

    if (a.reserved[reserved_idx] != b.reserved[reserved_idx])
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_cell_modem_status_t &a, const sbp_msg_cell_modem_status_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_specan_dep_t &a, const sbp_msg_specan_dep_t &b)
{
  (void)a;
  (void)b;

  if (a.channel_tag != b.channel_tag)
  {
    return false;
  }

  if (a.t.tow != b.t.tow)
  {
    return false;
  }

  if (a.t.wn != b.t.wn)
  {
    return false;
  }

  if (fabs(a.freq_ref - b.freq_ref) > 0.001)
  {
    return false;
  }

  if (fabs(a.freq_step - b.freq_step) > 0.001)
  {
    return false;
  }

  if (fabs(a.amplitude_ref - b.amplitude_ref) > 0.001)
  {
    return false;
  }

  if (fabs(a.amplitude_unit - b.amplitude_unit) > 0.001)
  {
    return false;
  }
  if (a.n_amplitude_value != b.n_amplitude_value)
  {
    return false;
  }
  for (size_t amplitude_value_idx = 0; amplitude_value_idx < (size_t)a.n_amplitude_value; amplitude_value_idx++)
  {

    if (a.amplitude_value[amplitude_value_idx] != b.amplitude_value[amplitude_value_idx])
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_specan_dep_t &a, const sbp_msg_specan_dep_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_specan_t &a, const sbp_msg_specan_t &b)
{
  (void)a;
  (void)b;

  if (a.channel_tag != b.channel_tag)
  {
    return false;
  }

  if (a.t.tow != b.t.tow)
  {
    return false;
  }

  if (a.t.ns_residual != b.t.ns_residual)
  {
    return false;
  }

  if (a.t.wn != b.t.wn)
  {
    return false;
  }

  if (fabs(a.freq_ref - b.freq_ref) > 0.001)
  {
    return false;
  }

  if (fabs(a.freq_step - b.freq_step) > 0.001)
  {
    return false;
  }

  if (fabs(a.amplitude_ref - b.amplitude_ref) > 0.001)
  {
    return false;
  }

  if (fabs(a.amplitude_unit - b.amplitude_unit) > 0.001)
  {
    return false;
  }
  if (a.n_amplitude_value != b.n_amplitude_value)
  {
    return false;
  }
  for (size_t amplitude_value_idx = 0; amplitude_value_idx < (size_t)a.n_amplitude_value; amplitude_value_idx++)
  {

    if (a.amplitude_value[amplitude_value_idx] != b.amplitude_value[amplitude_value_idx])
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_specan_t &a, const sbp_msg_specan_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_front_end_gain_t &a, const sbp_msg_front_end_gain_t &b)
{
  (void)a;
  (void)b;

  for (size_t rf_gain_idx = 0; rf_gain_idx < 8; rf_gain_idx++)
  {

    if (a.rf_gain[rf_gain_idx] != b.rf_gain[rf_gain_idx])
    {
      return false;
    }
  }
  for (size_t if_gain_idx = 0; if_gain_idx < 8; if_gain_idx++)
  {

    if (a.if_gain[if_gain_idx] != b.if_gain[if_gain_idx])
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_front_end_gain_t &a, const sbp_msg_front_end_gain_t &b)
{
  return !(a == b);
}
#endif

#endif
