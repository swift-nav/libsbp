#ifndef PIKSI_H_
#define PIKSI_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class piksi_t : public kaitai::kstruct {

public:
    class msg_network_state_resp_t;
    class network_usage_t;
    class msg_command_resp_t;
    class msg_command_output_t;
    class latency_t;
    class msg_thread_state_t;
    class msg_uart_state_depa_t;
    class msg_network_state_req_t;
    class msg_device_monitor_t;
    class msg_mask_satellite_dep_t;
    class msg_uart_state_t;
    class msg_specan_t;
    class msg_iar_state_t;
    class msg_almanac_t;
    class msg_reset_filters_t;
    class uart_channel_t;
    class msg_command_req_t;
    class msg_mask_satellite_t;
    class msg_network_bandwidth_usage_t;
    class msg_reset_t;
    class msg_cell_modem_status_t;
    class msg_front_end_gain_t;
    class msg_reset_dep_t;
    class msg_set_time_t;
    class msg_cw_results_t;
    class msg_specan_dep_t;
    class msg_init_base_dep_t;
    class period_t;
    class msg_cw_start_t;

    piksi_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, piksi_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~piksi_t();

    /**
     * The state of a network interface on the Piksi. Data is made to reflect
     * output of ifaddrs struct returned by getifaddrs in c.
     */

    class msg_network_state_resp_t : public kaitai::kstruct {

    public:

        msg_network_state_resp_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, piksi_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_network_state_resp_t();

    private:
        std::vector<uint8_t>* m_ipv4_address;
        uint8_t m_ipv4_mask_size;
        std::vector<uint8_t>* m_ipv6_address;
        uint8_t m_ipv6_mask_size;
        uint32_t m_rx_bytes;
        uint32_t m_tx_bytes;
        std::string m_interface_name;
        uint32_t m_flags;
        piksi_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * IPv4 address (all zero when unavailable)
         */
        std::vector<uint8_t>* ipv4_address() const { return m_ipv4_address; }

        /**
         * IPv4 netmask CIDR notation
         */
        uint8_t ipv4_mask_size() const { return m_ipv4_mask_size; }

        /**
         * IPv6 address (all zero when unavailable)
         */
        std::vector<uint8_t>* ipv6_address() const { return m_ipv6_address; }

        /**
         * IPv6 netmask CIDR notation
         */
        uint8_t ipv6_mask_size() const { return m_ipv6_mask_size; }

        /**
         * Number of Rx bytes
         */
        uint32_t rx_bytes() const { return m_rx_bytes; }

        /**
         * Number of Tx bytes
         */
        uint32_t tx_bytes() const { return m_tx_bytes; }

        /**
         * Interface Name
         */
        std::string interface_name() const { return m_interface_name; }

        /**
         * Interface flags from SIOCGIFFLAGS
         */
        uint32_t flags() const { return m_flags; }
        piksi_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * The bandwidth usage for each interface can be reported within this
     * struct and utilize multiple fields to fully specify the type of traffic
     * that is being tracked. As either the interval of collection or the
     * collection time may vary, both a timestamp and period field is provided,
     * though may not necessarily be populated with a value.
     */

    class network_usage_t : public kaitai::kstruct {

    public:

        network_usage_t(kaitai::kstream* p__io, piksi_t::msg_network_bandwidth_usage_t* p__parent = 0, piksi_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~network_usage_t();

    private:
        uint64_t m_duration;
        uint64_t m_total_bytes;
        uint32_t m_rx_bytes;
        uint32_t m_tx_bytes;
        std::string m_interface_name;
        piksi_t* m__root;
        piksi_t::msg_network_bandwidth_usage_t* m__parent;

    public:

        /**
         * Duration over which the measurement was collected
         */
        uint64_t duration() const { return m_duration; }

        /**
         * Number of bytes handled in total within period
         */
        uint64_t total_bytes() const { return m_total_bytes; }

        /**
         * Number of bytes transmitted within period
         */
        uint32_t rx_bytes() const { return m_rx_bytes; }

        /**
         * Number of bytes received within period
         */
        uint32_t tx_bytes() const { return m_tx_bytes; }

        /**
         * Interface Name
         */
        std::string interface_name() const { return m_interface_name; }
        piksi_t* _root() const { return m__root; }
        piksi_t::msg_network_bandwidth_usage_t* _parent() const { return m__parent; }
    };

    /**
     * The response to MSG_COMMAND_REQ with the return code of the command.  A
     * return code of zero indicates success.
     */

    class msg_command_resp_t : public kaitai::kstruct {

    public:

        msg_command_resp_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, piksi_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_command_resp_t();

    private:
        uint32_t m_sequence;
        int32_t m_code;
        piksi_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Sequence number
         */
        uint32_t sequence() const { return m_sequence; }

        /**
         * Exit code
         */
        int32_t code() const { return m_code; }
        piksi_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Returns the standard output and standard error of the command requested
     * by MSG_COMMAND_REQ. The sequence number can be used to filter for
     * filtering the correct command.
     */

    class msg_command_output_t : public kaitai::kstruct {

    public:

        msg_command_output_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, piksi_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_command_output_t();

    private:
        uint32_t m_sequence;
        std::string m_line;
        piksi_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Sequence number
         */
        uint32_t sequence() const { return m_sequence; }

        /**
         * Line of standard output or standard error
         */
        std::string line() const { return m_line; }
        piksi_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Statistics on the latency of observations received from the base
     * station. As observation packets are received their GPS time is compared
     * to the current GPS time calculated locally by the receiver to give a
     * precise measurement of the end-to-end communication latency in the
     * system.
     */

    class latency_t : public kaitai::kstruct {

    public:

        latency_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, piksi_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~latency_t();

    private:
        int32_t m_avg;
        int32_t m_lmin;
        int32_t m_lmax;
        int32_t m_current;
        piksi_t* m__root;
        kaitai::kstruct* m__parent;

    public:

        /**
         * Average latency
         */
        int32_t avg() const { return m_avg; }

        /**
         * Minimum latency
         */
        int32_t lmin() const { return m_lmin; }

        /**
         * Maximum latency
         */
        int32_t lmax() const { return m_lmax; }

        /**
         * Smoothed estimate of the current latency
         */
        int32_t current() const { return m_current; }
        piksi_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    /**
     * The thread usage message from the device reports real-time operating
     * system (RTOS) thread usage statistics for the named thread. The reported
     * percentage values must be normalized.
     */

    class msg_thread_state_t : public kaitai::kstruct {

    public:

        msg_thread_state_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, piksi_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_thread_state_t();

    private:
        std::string m_name;
        uint16_t m_cpu;
        uint32_t m_stack_free;
        piksi_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Thread name (NULL terminated)
         */
        std::string name() const { return m_name; }

        /**
         * Percentage cpu use for this thread. Values range from 0 - 1000 and
         * needs to be renormalized to 100
         */
        uint16_t cpu() const { return m_cpu; }

        /**
         * Free stack space for this thread
         */
        uint32_t stack_free() const { return m_stack_free; }
        piksi_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_uart_state_depa_t : public kaitai::kstruct {

    public:

        msg_uart_state_depa_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, piksi_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_uart_state_depa_t();

    private:
        uart_channel_t* m_uart_a;
        uart_channel_t* m_uart_b;
        uart_channel_t* m_uart_ftdi;
        latency_t* m_latency;
        piksi_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * State of UART A
         */
        uart_channel_t* uart_a() const { return m_uart_a; }

        /**
         * State of UART B
         */
        uart_channel_t* uart_b() const { return m_uart_b; }

        /**
         * State of UART FTDI (USB logger)
         */
        uart_channel_t* uart_ftdi() const { return m_uart_ftdi; }

        /**
         * UART communication latency
         */
        latency_t* latency() const { return m_latency; }
        piksi_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Request state of Piksi network interfaces. Output will be sent in
     * MSG_NETWORK_STATE_RESP messages.
     */

    class msg_network_state_req_t : public kaitai::kstruct {

    public:

        msg_network_state_req_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, piksi_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_network_state_req_t();

    private:
        piksi_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:
        piksi_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * This message contains temperature and voltage level measurements from
     * the processor's monitoring system and the RF frontend die temperature if
     * available.
     */

    class msg_device_monitor_t : public kaitai::kstruct {

    public:

        msg_device_monitor_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, piksi_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_device_monitor_t();

    private:
        int16_t m_dev_vin;
        int16_t m_cpu_vint;
        int16_t m_cpu_vaux;
        int16_t m_cpu_temperature;
        int16_t m_fe_temperature;
        piksi_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Device V_in
         */
        int16_t dev_vin() const { return m_dev_vin; }

        /**
         * Processor V_int
         */
        int16_t cpu_vint() const { return m_cpu_vint; }

        /**
         * Processor V_aux
         */
        int16_t cpu_vaux() const { return m_cpu_vaux; }

        /**
         * Processor temperature
         */
        int16_t cpu_temperature() const { return m_cpu_temperature; }

        /**
         * Frontend temperature (if available)
         */
        int16_t fe_temperature() const { return m_fe_temperature; }
        piksi_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_mask_satellite_dep_t : public kaitai::kstruct {

    public:

        msg_mask_satellite_dep_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, piksi_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_mask_satellite_dep_t();

    private:
        uint8_t m_mask;
        gnss_t::gnss_signal_dep_t* m_sid;
        piksi_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Mask of systems that should ignore this satellite.
         */
        uint8_t mask() const { return m_mask; }

        /**
         * GNSS signal for which the mask is applied
         */
        gnss_t::gnss_signal_dep_t* sid() const { return m_sid; }
        piksi_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * The UART message reports data latency and throughput of the UART
     * channels providing SBP I/O. On the default Piksi configuration, UARTs A
     * and B are used for telemetry radios, but can also be host access ports
     * for embedded hosts, or other interfaces in future. The reported
     * percentage values must be normalized. Observations latency and period
     * can be used to assess the health of the differential corrections link.
     * Latency provides the timeliness of received base observations while the
     * period indicates their likelihood of transmission.
     */

    class msg_uart_state_t : public kaitai::kstruct {

    public:

        msg_uart_state_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, piksi_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_uart_state_t();

    private:
        uart_channel_t* m_uart_a;
        uart_channel_t* m_uart_b;
        uart_channel_t* m_uart_ftdi;
        latency_t* m_latency;
        period_t* m_obs_period;
        piksi_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * State of UART A
         */
        uart_channel_t* uart_a() const { return m_uart_a; }

        /**
         * State of UART B
         */
        uart_channel_t* uart_b() const { return m_uart_b; }

        /**
         * State of UART FTDI (USB logger)
         */
        uart_channel_t* uart_ftdi() const { return m_uart_ftdi; }

        /**
         * UART communication latency
         */
        latency_t* latency() const { return m_latency; }

        /**
         * Observation receipt period
         */
        period_t* obs_period() const { return m_obs_period; }
        piksi_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Spectrum analyzer packet.
     */

    class msg_specan_t : public kaitai::kstruct {

    public:

        msg_specan_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, piksi_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_specan_t();

    private:
        uint16_t m_channel_tag;
        gnss_t::gps_time_t* m_t;
        float m_freq_ref;
        float m_freq_step;
        float m_amplitude_ref;
        float m_amplitude_unit;
        std::vector<uint8_t>* m_amplitude_value;
        piksi_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Channel ID
         */
        uint16_t channel_tag() const { return m_channel_tag; }

        /**
         * Receiver time of this observation
         */
        gnss_t::gps_time_t* t() const { return m_t; }

        /**
         * Reference frequency of this packet
         */
        float freq_ref() const { return m_freq_ref; }

        /**
         * Frequency step of points in this packet
         */
        float freq_step() const { return m_freq_step; }

        /**
         * Reference amplitude of this packet
         */
        float amplitude_ref() const { return m_amplitude_ref; }

        /**
         * Amplitude unit value of points in this packet
         */
        float amplitude_unit() const { return m_amplitude_unit; }

        /**
         * Amplitude values (in the above units) of points in this packet
         */
        std::vector<uint8_t>* amplitude_value() const { return m_amplitude_value; }
        piksi_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * This message reports the state of the Integer Ambiguity Resolution (IAR)
     * process, which resolves unknown integer ambiguities from double-
     * differenced carrier-phase measurements from satellite observations.
     */

    class msg_iar_state_t : public kaitai::kstruct {

    public:

        msg_iar_state_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, piksi_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_iar_state_t();

    private:
        uint32_t m_num_hyps;
        piksi_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Number of integer ambiguity hypotheses remaining
         */
        uint32_t num_hyps() const { return m_num_hyps; }
        piksi_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * This is a legacy message for sending and loading a satellite alamanac
     * onto the Piksi's flash memory from the host.
     */

    class msg_almanac_t : public kaitai::kstruct {

    public:

        msg_almanac_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, piksi_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_almanac_t();

    private:
        piksi_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:
        piksi_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * This message resets either the DGNSS Kalman filters or Integer Ambiguity
     * Resolution (IAR) process.
     */

    class msg_reset_filters_t : public kaitai::kstruct {

    public:

        msg_reset_filters_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, piksi_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_reset_filters_t();

    private:
        uint8_t m_filter;
        piksi_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Filter flags
         */
        uint8_t filter() const { return m_filter; }
        piksi_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Throughput, utilization, and error counts on the RX/TX buffers of this
     * UART channel. The reported percentage values must be normalized.
     */

    class uart_channel_t : public kaitai::kstruct {

    public:

        uart_channel_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, piksi_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~uart_channel_t();

    private:
        float m_tx_throughput;
        float m_rx_throughput;
        uint16_t m_crc_error_count;
        uint16_t m_io_error_count;
        uint8_t m_tx_buffer_level;
        uint8_t m_rx_buffer_level;
        piksi_t* m__root;
        kaitai::kstruct* m__parent;

    public:

        /**
         * UART transmit throughput
         */
        float tx_throughput() const { return m_tx_throughput; }

        /**
         * UART receive throughput
         */
        float rx_throughput() const { return m_rx_throughput; }

        /**
         * UART CRC error count
         */
        uint16_t crc_error_count() const { return m_crc_error_count; }

        /**
         * UART IO error count
         */
        uint16_t io_error_count() const { return m_io_error_count; }

        /**
         * UART transmit buffer percentage utilization (ranges from 0 to 255)
         */
        uint8_t tx_buffer_level() const { return m_tx_buffer_level; }

        /**
         * UART receive buffer percentage utilization (ranges from 0 to 255)
         */
        uint8_t rx_buffer_level() const { return m_rx_buffer_level; }
        piksi_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    /**
     * Request the recipient to execute an command. Output will be sent in
     * MSG_LOG messages, and the exit code will be returned with
     * MSG_COMMAND_RESP.
     */

    class msg_command_req_t : public kaitai::kstruct {

    public:

        msg_command_req_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, piksi_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_command_req_t();

    private:
        uint32_t m_sequence;
        std::string m_command;
        piksi_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Sequence number
         */
        uint32_t sequence() const { return m_sequence; }

        /**
         * Command line to execute
         */
        std::string command() const { return m_command; }
        piksi_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * This message allows setting a mask to prevent a particular satellite
     * from being used in various Piksi subsystems.
     */

    class msg_mask_satellite_t : public kaitai::kstruct {

    public:

        msg_mask_satellite_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, piksi_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_mask_satellite_t();

    private:
        uint8_t m_mask;
        gnss_t::gnss_signal_t* m_sid;
        piksi_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Mask of systems that should ignore this satellite.
         */
        uint8_t mask() const { return m_mask; }

        /**
         * GNSS signal for which the mask is applied
         */
        gnss_t::gnss_signal_t* sid() const { return m_sid; }
        piksi_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * The bandwidth usage, a list of usage by interface.
     */

    class msg_network_bandwidth_usage_t : public kaitai::kstruct {

    public:

        msg_network_bandwidth_usage_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, piksi_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_network_bandwidth_usage_t();

    private:
        std::vector<network_usage_t*>* m_interfaces;
        piksi_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Usage measurement array
         */
        std::vector<network_usage_t*>* interfaces() const { return m_interfaces; }
        piksi_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * This message from the host resets the Piksi back into the bootloader.
     */

    class msg_reset_t : public kaitai::kstruct {

    public:

        msg_reset_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, piksi_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_reset_t();

    private:
        uint32_t m_flags;
        piksi_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Reset flags
         */
        uint32_t flags() const { return m_flags; }
        piksi_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * If a cell modem is present on a piksi device, this message will be send
     * periodically to update the host on the status of the modem and its
     * various parameters.
     */

    class msg_cell_modem_status_t : public kaitai::kstruct {

    public:

        msg_cell_modem_status_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, piksi_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_cell_modem_status_t();

    private:
        int8_t m_signal_strength;
        float m_signal_error_rate;
        std::vector<uint8_t>* m_reserved;
        piksi_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Received cell signal strength in dBm, zero translates to unknown
         */
        int8_t signal_strength() const { return m_signal_strength; }

        /**
         * BER as reported by the modem, zero translates to unknown
         */
        float signal_error_rate() const { return m_signal_error_rate; }

        /**
         * Unspecified data TBD for this schema
         */
        std::vector<uint8_t>* reserved() const { return m_reserved; }
        piksi_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * This message describes the gain of each channel in the receiver
     * frontend. Each gain is encoded as a non-dimensional percentage relative
     * to the maximum range possible for the gain stage of the frontend. By
     * convention, each gain array has 8 entries and the index of the array
     * corresponding to the index of the rf channel in the frontend. A gain of
     * 127 percent encodes that rf channel is not present in the hardware. A
     * negative value implies an error for the particular gain stage as
     * reported by the frontend.
     */

    class msg_front_end_gain_t : public kaitai::kstruct {

    public:

        msg_front_end_gain_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, piksi_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_front_end_gain_t();

    private:
        std::vector<int8_t>* m_rf_gain;
        std::vector<int8_t>* m_if_gain;
        piksi_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * RF gain for each frontend channel
         */
        std::vector<int8_t>* rf_gain() const { return m_rf_gain; }

        /**
         * Intermediate frequency gain for each frontend channel
         */
        std::vector<int8_t>* if_gain() const { return m_if_gain; }
        piksi_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_reset_dep_t : public kaitai::kstruct {

    public:

        msg_reset_dep_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, piksi_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_reset_dep_t();

    private:
        piksi_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:
        piksi_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * This message sets up timing functionality using a coarse GPS time
     * estimate sent by the host.
     */

    class msg_set_time_t : public kaitai::kstruct {

    public:

        msg_set_time_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, piksi_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_set_time_t();

    private:
        piksi_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:
        piksi_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * This is an unused legacy message for result reporting from the CW
     * interference channel on the SwiftNAP. This message will be removed in a
     * future release.
     */

    class msg_cw_results_t : public kaitai::kstruct {

    public:

        msg_cw_results_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, piksi_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_cw_results_t();

    private:
        piksi_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:
        piksi_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_specan_dep_t : public kaitai::kstruct {

    public:

        msg_specan_dep_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, piksi_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_specan_dep_t();

    private:
        uint16_t m_channel_tag;
        gnss_t::gps_time_dep_t* m_t;
        float m_freq_ref;
        float m_freq_step;
        float m_amplitude_ref;
        float m_amplitude_unit;
        std::vector<uint8_t>* m_amplitude_value;
        piksi_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * Channel ID
         */
        uint16_t channel_tag() const { return m_channel_tag; }

        /**
         * Receiver time of this observation
         */
        gnss_t::gps_time_dep_t* t() const { return m_t; }

        /**
         * Reference frequency of this packet
         */
        float freq_ref() const { return m_freq_ref; }

        /**
         * Frequency step of points in this packet
         */
        float freq_step() const { return m_freq_step; }

        /**
         * Reference amplitude of this packet
         */
        float amplitude_ref() const { return m_amplitude_ref; }

        /**
         * Amplitude unit value of points in this packet
         */
        float amplitude_unit() const { return m_amplitude_unit; }

        /**
         * Amplitude values (in the above units) of points in this packet
         */
        std::vector<uint8_t>* amplitude_value() const { return m_amplitude_value; }
        piksi_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_init_base_dep_t : public kaitai::kstruct {

    public:

        msg_init_base_dep_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, piksi_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_init_base_dep_t();

    private:
        piksi_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:
        piksi_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Statistics on the period of observations received from the base station.
     * As complete observation sets are received, their time of reception is
     * compared with the prior set''s time of reception. This measurement
     * provides a proxy for link quality as incomplete or missing sets will
     * increase the period.  Long periods can cause momentary RTK solution
     * outages.
     */

    class period_t : public kaitai::kstruct {

    public:

        period_t(kaitai::kstream* p__io, piksi_t::msg_uart_state_t* p__parent = 0, piksi_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~period_t();

    private:
        int32_t m_avg;
        int32_t m_pmin;
        int32_t m_pmax;
        int32_t m_current;
        piksi_t* m__root;
        piksi_t::msg_uart_state_t* m__parent;

    public:

        /**
         * Average period
         */
        int32_t avg() const { return m_avg; }

        /**
         * Minimum period
         */
        int32_t pmin() const { return m_pmin; }

        /**
         * Maximum period
         */
        int32_t pmax() const { return m_pmax; }

        /**
         * Smoothed estimate of the current period
         */
        int32_t current() const { return m_current; }
        piksi_t* _root() const { return m__root; }
        piksi_t::msg_uart_state_t* _parent() const { return m__parent; }
    };

    /**
     * This is an unused legacy message from the host for starting the CW
     * interference channel on the SwiftNAP. This message will be removed in a
     * future release.
     */

    class msg_cw_start_t : public kaitai::kstruct {

    public:

        msg_cw_start_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, piksi_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_cw_start_t();

    private:
        piksi_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:
        piksi_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

private:
    piksi_t* m__root;
    kaitai::kstruct* m__parent;

public:
    piksi_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // PIKSI_H_
