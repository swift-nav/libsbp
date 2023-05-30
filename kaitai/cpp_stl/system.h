#ifndef SYSTEM_H_
#define SYSTEM_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class system_t : public kaitai::kstruct {

public:
    class msg_heartbeat_t;
    class msg_status_journal_t;
    class msg_ins_status_t;
    class msg_gnss_time_offset_t;
    class msg_csac_telemetry_t;
    class msg_pps_time_t;
    class msg_ins_updates_t;
    class msg_dgnss_status_t;
    class msg_csac_telemetry_labels_t;
    class msg_startup_t;
    class msg_group_meta_t;
    class msg_sensor_aid_event_t;
    class sub_system_report_t;
    class msg_status_report_t;
    class status_journal_item_t;

    system_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, system_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~system_t();

    /**
     * The heartbeat message is sent periodically to inform the host or other
     * attached devices that the system is running. It is used to monitor
     * system malfunctions. It also contains status flags that indicate to the
     * host the status of the system and whether it is operating correctly.
     * Currently, the expected heartbeat interval is 1 sec.
     * 
     * The system error flag is used to indicate that an error has occurred in
     * the system. To determine the source of the error, the remaining error
     * flags should be inspected.
     */

    class msg_heartbeat_t : public kaitai::kstruct {

    public:

        msg_heartbeat_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, system_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_heartbeat_t();

    private:
        uint32_t m_flags;
        system_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Status flags
         */
        uint32_t flags() const { return m_flags; }
        system_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * The status journal message contains past status reports (see
     * MSG_STATUS_REPORT) and functions as a error/event storage for telemetry
     * purposes.
     */

    class msg_status_journal_t : public kaitai::kstruct {

    public:

        msg_status_journal_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, system_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_status_journal_t();

    private:
        uint16_t m_reporting_system;
        uint16_t m_sbp_version;
        uint32_t m_total_status_reports;
        uint8_t m_sequence_descriptor;
        std::vector<status_journal_item_t*>* m_journal;
        system_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Identity of reporting system
         */
        uint16_t reporting_system() const { return m_reporting_system; }

        /**
         * SBP protocol version
         */
        uint16_t sbp_version() const { return m_sbp_version; }

        /**
         * Total number of status reports sent since system startup
         */
        uint32_t total_status_reports() const { return m_total_status_reports; }

        /**
         * Index and number of messages in this sequence. First nibble is the
         * size of the sequence (n), second nibble is the zero-indexed counter
         * (ith packet of n)
         */
        uint8_t sequence_descriptor() const { return m_sequence_descriptor; }

        /**
         * Status journal
         */
        std::vector<status_journal_item_t*>* journal() const { return m_journal; }
        system_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * The INS status message describes the state of the operation and
     * initialization of the inertial navigation system.
     */

    class msg_ins_status_t : public kaitai::kstruct {

    public:

        msg_ins_status_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, system_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ins_status_t();

    private:
        uint32_t m_flags;
        system_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Status flags
         */
        uint32_t flags() const { return m_flags; }
        system_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * The GNSS time offset message contains the information that is needed to
     * translate messages tagged with a local timestamp (e.g. IMU or wheeltick
     * messages) to GNSS time for the sender producing this message.
     */

    class msg_gnss_time_offset_t : public kaitai::kstruct {

    public:

        msg_gnss_time_offset_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, system_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_gnss_time_offset_t();

    private:
        int16_t m_weeks;
        int32_t m_milliseconds;
        int16_t m_microseconds;
        uint8_t m_flags;
        system_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Weeks portion of the time offset
         */
        int16_t weeks() const { return m_weeks; }

        /**
         * Milliseconds portion of the time offset
         */
        int32_t milliseconds() const { return m_milliseconds; }

        /**
         * Microseconds portion of the time offset
         */
        int16_t microseconds() const { return m_microseconds; }

        /**
         * Status flags (reserved)
         */
        uint8_t flags() const { return m_flags; }
        system_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * The CSAC telemetry message has an implementation defined telemetry
     * string from a device. It is not produced or available on general Swift
     * Products. It is intended to be a low rate message for status purposes.
     */

    class msg_csac_telemetry_t : public kaitai::kstruct {

    public:

        msg_csac_telemetry_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, system_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_csac_telemetry_t();

    private:
        uint8_t m_id;
        std::string m_telemetry;
        system_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Index representing the type of telemetry in use.  It is
         * implementation defined.
         */
        uint8_t id() const { return m_id; }

        /**
         * Comma separated list of values as defined by the index
         */
        std::string telemetry() const { return m_telemetry; }
        system_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * The PPS time message contains the value of the sender's local time in
     * microseconds at the moment a pulse is detected on the PPS input. This is
     * to be used for syncronisation of sensor data sampled with a local
     * timestamp (e.g. IMU or wheeltick messages) where GNSS time is unknown to
     * the sender.
     * 
     * The local time used to timestamp the PPS pulse must be generated by the
     * same clock which is used to timestamp the IMU/wheel sensor data and
     * should follow the same roll-over rules.  A separate MSG_PPS_TIME message
     * should be sent for each source of sensor data which uses PPS-relative
     * timestamping.  The sender ID for each of these MSG_PPS_TIME messages
     * should match the sender ID of the respective sensor data.
     */

    class msg_pps_time_t : public kaitai::kstruct {

    public:

        msg_pps_time_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, system_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_pps_time_t();

    private:
        uint64_t m_time;
        uint8_t m_flags;
        system_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Local time in microseconds
         */
        uint64_t time() const { return m_time; }

        /**
         * Status flags
         */
        uint8_t flags() const { return m_flags; }
        system_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * The INS update status message contains information about executed and
     * rejected INS updates. This message is expected to be extended in the
     * future as new types of measurements are being added.
     */

    class msg_ins_updates_t : public kaitai::kstruct {

    public:

        msg_ins_updates_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, system_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_ins_updates_t();

    private:
        uint32_t m_tow;
        uint8_t m_gnsspos;
        uint8_t m_gnssvel;
        uint8_t m_wheelticks;
        uint8_t m_speed;
        uint8_t m_nhc;
        uint8_t m_zerovel;
        system_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * GPS Time of Week
         */
        uint32_t tow() const { return m_tow; }

        /**
         * GNSS position update status flags
         */
        uint8_t gnsspos() const { return m_gnsspos; }

        /**
         * GNSS velocity update status flags
         */
        uint8_t gnssvel() const { return m_gnssvel; }

        /**
         * Wheelticks update status flags
         */
        uint8_t wheelticks() const { return m_wheelticks; }

        /**
         * Wheelticks update status flags
         */
        uint8_t speed() const { return m_speed; }

        /**
         * NHC update status flags
         */
        uint8_t nhc() const { return m_nhc; }

        /**
         * Zero velocity update status flags
         */
        uint8_t zerovel() const { return m_zerovel; }
        system_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * This message provides information about the receipt of Differential
     * corrections.  It is expected to be sent with each receipt of a complete
     * corrections packet.
     */

    class msg_dgnss_status_t : public kaitai::kstruct {

    public:

        msg_dgnss_status_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, system_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_dgnss_status_t();

    private:
        uint8_t m_flags;
        uint16_t m_latency;
        uint8_t m_num_signals;
        std::string m_source;
        system_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Status flags
         */
        uint8_t flags() const { return m_flags; }

        /**
         * Latency of observation receipt
         */
        uint16_t latency() const { return m_latency; }

        /**
         * Number of signals from base station
         */
        uint8_t num_signals() const { return m_num_signals; }

        /**
         * Corrections source string
         */
        std::string source() const { return m_source; }
        system_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * The CSAC telemetry message provides labels for each member of the string
     * produced by MSG_CSAC_TELEMETRY. It should be provided by a device at a
     * lower rate than the MSG_CSAC_TELEMETRY.
     */

    class msg_csac_telemetry_labels_t : public kaitai::kstruct {

    public:

        msg_csac_telemetry_labels_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, system_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_csac_telemetry_labels_t();

    private:
        uint8_t m_id;
        std::string m_telemetry_labels;
        system_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Index representing the type of telemetry in use.  It is
         * implementation defined.
         */
        uint8_t id() const { return m_id; }

        /**
         * Comma separated list of telemetry field values
         */
        std::string telemetry_labels() const { return m_telemetry_labels; }
        system_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * The system start-up message is sent once on system start-up. It notifies
     * the host or other attached devices that the system has started and is
     * now ready to respond to commands or configuration requests.
     */

    class msg_startup_t : public kaitai::kstruct {

    public:

        msg_startup_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, system_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_startup_t();

    private:
        uint8_t m_cause;
        uint8_t m_startup_type;
        uint16_t m_reserved;
        system_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Cause of startup
         */
        uint8_t cause() const { return m_cause; }

        /**
         * Startup type
         */
        uint8_t startup_type() const { return m_startup_type; }

        /**
         * Reserved
         */
        uint16_t reserved() const { return m_reserved; }
        system_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * This leading message lists the time metadata of the Solution Group. It
     * also lists the atomic contents (i.e. types of messages included) of the
     * Solution Group.
     */

    class msg_group_meta_t : public kaitai::kstruct {

    public:

        msg_group_meta_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, system_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_group_meta_t();

    private:
        uint8_t m_group_id;
        uint8_t m_flags;
        uint8_t m_n_group_msgs;
        std::vector<uint16_t>* m_group_msgs;
        system_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Id of the Msgs Group, 0 is Unknown, 1 is Bestpos, 2 is Gnss
         */
        uint8_t group_id() const { return m_group_id; }

        /**
         * Status flags (reserved)
         */
        uint8_t flags() const { return m_flags; }

        /**
         * Size of list group_msgs
         */
        uint8_t n_group_msgs() const { return m_n_group_msgs; }

        /**
         * An in-order list of message types included in the Solution Group,
         * including GROUP_META itself
         */
        std::vector<uint16_t>* group_msgs() const { return m_group_msgs; }
        system_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * This diagnostic message contains state and update status information for
     * all sensors that are being used by the fusion engine. This message will
     * be generated asynchronously to the solution messages and will be emitted
     * anytime a sensor update is being processed.
     */

    class msg_sensor_aid_event_t : public kaitai::kstruct {

    public:

        msg_sensor_aid_event_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, system_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_sensor_aid_event_t();

    private:
        uint32_t m_time;
        uint8_t m_sensor_type;
        uint16_t m_sensor_id;
        uint8_t m_sensor_state;
        uint8_t m_n_available_meas;
        uint8_t m_n_attempted_meas;
        uint8_t m_n_accepted_meas;
        uint32_t m_flags;
        system_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Update timestamp in milliseconds.
         */
        uint32_t time() const { return m_time; }

        /**
         * Sensor type
         */
        uint8_t sensor_type() const { return m_sensor_type; }

        /**
         * Sensor identifier
         */
        uint16_t sensor_id() const { return m_sensor_id; }

        /**
         * Reserved for future use
         */
        uint8_t sensor_state() const { return m_sensor_state; }

        /**
         * Number of available measurements in this epoch
         */
        uint8_t n_available_meas() const { return m_n_available_meas; }

        /**
         * Number of attempted measurements in this epoch
         */
        uint8_t n_attempted_meas() const { return m_n_attempted_meas; }

        /**
         * Number of accepted measurements in this epoch
         */
        uint8_t n_accepted_meas() const { return m_n_accepted_meas; }

        /**
         * Reserved for future use
         */
        uint32_t flags() const { return m_flags; }
        system_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * Report the general and specific state of a subsystem.  If the generic
     * state is reported as initializing, the specific state should be ignored.
     */

    class sub_system_report_t : public kaitai::kstruct {

    public:

        sub_system_report_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, system_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~sub_system_report_t();

    private:
        uint16_t m_component;
        uint8_t m_generic;
        uint8_t m_specific;
        system_t* m__root;
        kaitai::kstruct* m__parent;

    public:

        /**
         * Identity of reporting subsystem
         */
        uint16_t component() const { return m_component; }

        /**
         * Generic form status report
         */
        uint8_t generic() const { return m_generic; }

        /**
         * Subsystem specific status code
         */
        uint8_t specific() const { return m_specific; }
        system_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    /**
     * The status report is sent periodically to inform the host or other
     * attached devices that the system is running. It is used to monitor
     * system malfunctions. It contains status reports that indicate to the
     * host the status of each subsystem and whether it is operating correctly.
     * 
     * Interpretation of the subsystem specific status code is product
     * dependent, but if the generic status code is initializing, it should be
     * ignored.  Refer to product documentation for details.
     */

    class msg_status_report_t : public kaitai::kstruct {

    public:

        msg_status_report_t(kaitai::kstream* p__io, sbp_t::message_t* p__parent = 0, system_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_status_report_t();

    private:
        uint16_t m_reporting_system;
        uint16_t m_sbp_version;
        uint32_t m_sequence;
        uint32_t m_uptime;
        std::vector<sub_system_report_t*>* m_status;
        system_t* m__root;
        sbp_t::message_t* m__parent;

    public:

        /**
         * Identity of reporting system
         */
        uint16_t reporting_system() const { return m_reporting_system; }

        /**
         * SBP protocol version
         */
        uint16_t sbp_version() const { return m_sbp_version; }

        /**
         * Increments on each status report sent
         */
        uint32_t sequence() const { return m_sequence; }

        /**
         * Number of seconds since system start-up
         */
        uint32_t uptime() const { return m_uptime; }

        /**
         * Reported status of individual subsystems
         */
        std::vector<sub_system_report_t*>* status() const { return m_status; }
        system_t* _root() const { return m__root; }
        sbp_t::message_t* _parent() const { return m__parent; }
    };

    /**
     * Reports the uptime and the state of a subsystem via generic and specific
     * status codes.  If the generic state is reported as initializing, the
     * specific state should be ignored.
     */

    class status_journal_item_t : public kaitai::kstruct {

    public:

        status_journal_item_t(kaitai::kstream* p__io, system_t::msg_status_journal_t* p__parent = 0, system_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~status_journal_item_t();

    private:
        uint32_t m_uptime;
        sub_system_report_t* m_report;
        system_t* m__root;
        system_t::msg_status_journal_t* m__parent;

    public:

        /**
         * Milliseconds since system startup
         */
        uint32_t uptime() const { return m_uptime; }
        sub_system_report_t* report() const { return m_report; }
        system_t* _root() const { return m__root; }
        system_t::msg_status_journal_t* _parent() const { return m__parent; }
    };

private:
    system_t* m__root;
    kaitai::kstruct* m__parent;

public:
    system_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // SYSTEM_H_
