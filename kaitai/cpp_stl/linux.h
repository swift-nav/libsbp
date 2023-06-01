#ifndef LINUX_H_
#define LINUX_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class linux_t : public kaitai::kstruct {

public:
    class msg_linux_socket_usage_t;
    class msg_linux_sys_state_t;
    class msg_linux_cpu_state_dep_a_t;
    class msg_linux_mem_state_t;
    class msg_linux_process_fd_count_t;
    class msg_linux_mem_state_dep_a_t;
    class msg_linux_process_socket_queues_t;
    class msg_linux_sys_state_dep_a_t;
    class msg_linux_process_fd_summary_t;
    class msg_linux_cpu_state_t;
    class msg_linux_process_socket_counts_t;

    linux_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, linux_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~linux_t();

    /**
     * Summaries the socket usage across the system.
     */

    class msg_linux_socket_usage_t : public kaitai::kstruct {

    public:

        msg_linux_socket_usage_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, linux_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_linux_socket_usage_t();

    private:
        uint32_t m_avg_queue_depth;
        uint32_t m_max_queue_depth;
        std::vector<uint16_t>* m_socket_state_counts;
        std::vector<uint16_t>* m_socket_type_counts;
        linux_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * average socket queue depths across all sockets on the system
         */
        uint32_t avg_queue_depth() const { return m_avg_queue_depth; }

        /**
         * the max queue depth seen within the reporting period
         */
        uint32_t max_queue_depth() const { return m_max_queue_depth; }

        /**
         * A count for each socket type reported in the `socket_types_reported`
         * field, the first entry corresponds to the first enabled bit in
         * `types_reported`.
         */
        std::vector<uint16_t>* socket_state_counts() const { return m_socket_state_counts; }

        /**
         * A count for each socket type reported in the `socket_types_reported`
         * field, the first entry corresponds to the first enabled bit in
         * `types_reported`.
         */
        std::vector<uint16_t>* socket_type_counts() const { return m_socket_type_counts; }
        linux_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * This presents a summary of CPU and memory utilization, including a
     * timestamp.
     */

    class msg_linux_sys_state_t : public kaitai::kstruct {

    public:

        msg_linux_sys_state_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, linux_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_linux_sys_state_t();

    private:
        uint16_t m_mem_total;
        uint8_t m_pcpu;
        uint8_t m_pmem;
        uint16_t m_procs_starting;
        uint16_t m_procs_stopping;
        uint16_t m_pid_count;
        uint32_t m_time;
        uint8_t m_flags;
        linux_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * total system memory, in MiB
         */
        uint16_t mem_total() const { return m_mem_total; }

        /**
         * percent of CPU used, expressed as a fraction of 256
         */
        uint8_t pcpu() const { return m_pcpu; }

        /**
         * percent of memory used, expressed as a fraction of 256
         */
        uint8_t pmem() const { return m_pmem; }

        /**
         * number of processes that started during collection phase
         */
        uint16_t procs_starting() const { return m_procs_starting; }

        /**
         * number of processes that stopped during collection phase
         */
        uint16_t procs_stopping() const { return m_procs_stopping; }

        /**
         * the count of processes on the system
         */
        uint16_t pid_count() const { return m_pid_count; }

        /**
         * timestamp of message, refer to flags field for how to interpret
         */
        uint32_t time() const { return m_time; }

        /**
         * flags
         */
        uint8_t flags() const { return m_flags; }
        linux_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_linux_cpu_state_dep_a_t : public kaitai::kstruct {

    public:

        msg_linux_cpu_state_dep_a_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, linux_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_linux_cpu_state_dep_a_t();

    private:
        uint8_t m_index;
        uint16_t m_pid;
        uint8_t m_pcpu;
        std::string m_tname;
        std::string m_cmdline;
        linux_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * sequence of this status message, values from 0-9
         */
        uint8_t index() const { return m_index; }

        /**
         * the PID of the process
         */
        uint16_t pid() const { return m_pid; }

        /**
         * percent of cpu used, expressed as a fraction of 256
         */
        uint8_t pcpu() const { return m_pcpu; }

        /**
         * fixed length string representing the thread name
         */
        std::string tname() const { return m_tname; }

        /**
         * the command line (as much as it fits in the remaining packet)
         */
        std::string cmdline() const { return m_cmdline; }
        linux_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * This message indicates the process state of the top 10 heaviest
     * consumers of memory on the system, including a timestamp.
     */

    class msg_linux_mem_state_t : public kaitai::kstruct {

    public:

        msg_linux_mem_state_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, linux_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_linux_mem_state_t();

    private:
        uint8_t m_index;
        uint16_t m_pid;
        uint8_t m_pmem;
        uint32_t m_time;
        uint8_t m_flags;
        std::string m_tname;
        std::string m_cmdline;
        linux_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * sequence of this status message, values from 0-9
         */
        uint8_t index() const { return m_index; }

        /**
         * the PID of the process
         */
        uint16_t pid() const { return m_pid; }

        /**
         * percent of memory used, expressed as a fraction of 256
         */
        uint8_t pmem() const { return m_pmem; }

        /**
         * timestamp of message, refer to flags field for how to interpret
         */
        uint32_t time() const { return m_time; }

        /**
         * flags
         */
        uint8_t flags() const { return m_flags; }

        /**
         * fixed length string representing the thread name
         */
        std::string tname() const { return m_tname; }

        /**
         * the command line (as much as it fits in the remaining packet)
         */
        std::string cmdline() const { return m_cmdline; }
        linux_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Top 10 list of processes with a large number of open file descriptors.
     */

    class msg_linux_process_fd_count_t : public kaitai::kstruct {

    public:

        msg_linux_process_fd_count_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, linux_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_linux_process_fd_count_t();

    private:
        uint8_t m_index;
        uint16_t m_pid;
        uint16_t m_fd_count;
        std::string m_cmdline;
        linux_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * sequence of this status message, values from 0-9
         */
        uint8_t index() const { return m_index; }

        /**
         * the PID of the process in question
         */
        uint16_t pid() const { return m_pid; }

        /**
         * a count of the number of file descriptors opened by the process
         */
        uint16_t fd_count() const { return m_fd_count; }

        /**
         * the command line of the process in question
         */
        std::string cmdline() const { return m_cmdline; }
        linux_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_linux_mem_state_dep_a_t : public kaitai::kstruct {

    public:

        msg_linux_mem_state_dep_a_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, linux_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_linux_mem_state_dep_a_t();

    private:
        uint8_t m_index;
        uint16_t m_pid;
        uint8_t m_pmem;
        std::string m_tname;
        std::string m_cmdline;
        linux_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * sequence of this status message, values from 0-9
         */
        uint8_t index() const { return m_index; }

        /**
         * the PID of the process
         */
        uint16_t pid() const { return m_pid; }

        /**
         * percent of memory used, expressed as a fraction of 256
         */
        uint8_t pmem() const { return m_pmem; }

        /**
         * fixed length string representing the thread name
         */
        std::string tname() const { return m_tname; }

        /**
         * the command line (as much as it fits in the remaining packet)
         */
        std::string cmdline() const { return m_cmdline; }
        linux_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Top 10 list of sockets with deep queues.
     */

    class msg_linux_process_socket_queues_t : public kaitai::kstruct {

    public:

        msg_linux_process_socket_queues_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, linux_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_linux_process_socket_queues_t();

    private:
        uint8_t m_index;
        uint16_t m_pid;
        uint16_t m_recv_queued;
        uint16_t m_send_queued;
        uint16_t m_socket_types;
        uint16_t m_socket_states;
        std::string m_address_of_largest;
        std::string m_cmdline;
        linux_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * sequence of this status message, values from 0-9
         */
        uint8_t index() const { return m_index; }

        /**
         * the PID of the process in question
         */
        uint16_t pid() const { return m_pid; }

        /**
         * the total amount of receive data queued for this process
         */
        uint16_t recv_queued() const { return m_recv_queued; }

        /**
         * the total amount of send data queued for this process
         */
        uint16_t send_queued() const { return m_send_queued; }

        /**
         * A bitfield indicating the socket types used: 0x1 (tcp), 0x2 (udp),
         * 0x4 (unix stream), 0x8 (unix dgram), 0x10 (netlink), and 0x8000
         * (unknown)
         */
        uint16_t socket_types() const { return m_socket_types; }

        /**
         * A bitfield indicating the socket states: 0x1 (established), 0x2
         * (syn-sent), 0x4 (syn-recv), 0x8 (fin-wait-1), 0x10 (fin-wait-2),
         * 0x20 (time-wait), 0x40 (closed), 0x80 (close-wait), 0x100 (last-
         * ack), 0x200 (listen), 0x400 (closing), 0x800 (unconnected), and
         * 0x8000 (unknown)
         */
        uint16_t socket_states() const { return m_socket_states; }

        /**
         * Address of the largest queue, remote or local depending on the
         * directionality of the connection.
         */
        std::string address_of_largest() const { return m_address_of_largest; }

        /**
         * the command line of the process in question
         */
        std::string cmdline() const { return m_cmdline; }
        linux_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Deprecated.
     */

    class msg_linux_sys_state_dep_a_t : public kaitai::kstruct {

    public:

        msg_linux_sys_state_dep_a_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, linux_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_linux_sys_state_dep_a_t();

    private:
        uint16_t m_mem_total;
        uint8_t m_pcpu;
        uint8_t m_pmem;
        uint16_t m_procs_starting;
        uint16_t m_procs_stopping;
        uint16_t m_pid_count;
        linux_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * total system memory
         */
        uint16_t mem_total() const { return m_mem_total; }

        /**
         * percent of total cpu currently utilized
         */
        uint8_t pcpu() const { return m_pcpu; }

        /**
         * percent of total memory currently utilized
         */
        uint8_t pmem() const { return m_pmem; }

        /**
         * number of processes that started during collection phase
         */
        uint16_t procs_starting() const { return m_procs_starting; }

        /**
         * number of processes that stopped during collection phase
         */
        uint16_t procs_stopping() const { return m_procs_stopping; }

        /**
         * the count of processes on the system
         */
        uint16_t pid_count() const { return m_pid_count; }
        linux_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Summary of open file descriptors on the system.
     */

    class msg_linux_process_fd_summary_t : public kaitai::kstruct {

    public:

        msg_linux_process_fd_summary_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, linux_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_linux_process_fd_summary_t();

    private:
        uint32_t m_sys_fd_count;
        std::string m_most_opened;
        linux_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * count of total FDs open on the system
         */
        uint32_t sys_fd_count() const { return m_sys_fd_count; }

        /**
         * A null delimited list of strings which alternates between a string
         * representation of the process count and the file name whose count it
         * being reported.  That is, in C string syntax
         * "32\0/var/log/syslog\012\0/tmp/foo\0" with the end of the list being
         * 2 NULL terminators in a row.
         */
        std::string most_opened() const { return m_most_opened; }
        linux_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * This message indicates the process state of the top 10 heaviest
     * consumers of CPU on the system, including a timestamp.
     */

    class msg_linux_cpu_state_t : public kaitai::kstruct {

    public:

        msg_linux_cpu_state_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, linux_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_linux_cpu_state_t();

    private:
        uint8_t m_index;
        uint16_t m_pid;
        uint8_t m_pcpu;
        uint32_t m_time;
        uint8_t m_flags;
        std::string m_tname;
        std::string m_cmdline;
        linux_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * sequence of this status message, values from 0-9
         */
        uint8_t index() const { return m_index; }

        /**
         * the PID of the process
         */
        uint16_t pid() const { return m_pid; }

        /**
         * percent of CPU used, expressed as a fraction of 256
         */
        uint8_t pcpu() const { return m_pcpu; }

        /**
         * timestamp of message, refer to flags field for how to interpret
         */
        uint32_t time() const { return m_time; }

        /**
         * flags
         */
        uint8_t flags() const { return m_flags; }

        /**
         * fixed length string representing the thread name
         */
        std::string tname() const { return m_tname; }

        /**
         * the command line (as much as it fits in the remaining packet)
         */
        std::string cmdline() const { return m_cmdline; }
        linux_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

    /**
     * Top 10 list of processes with high socket counts.
     */

    class msg_linux_process_socket_counts_t : public kaitai::kstruct {

    public:

        msg_linux_process_socket_counts_t(kaitai::kstream* p__io, sbp_t::sbp_message_t* p__parent = 0, linux_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~msg_linux_process_socket_counts_t();

    private:
        uint8_t m_index;
        uint16_t m_pid;
        uint16_t m_socket_count;
        uint16_t m_socket_types;
        uint16_t m_socket_states;
        std::string m_cmdline;
        linux_t* m__root;
        sbp_t::sbp_message_t* m__parent;

    public:

        /**
         * sequence of this status message, values from 0-9
         */
        uint8_t index() const { return m_index; }

        /**
         * the PID of the process in question
         */
        uint16_t pid() const { return m_pid; }

        /**
         * the number of sockets the process is using
         */
        uint16_t socket_count() const { return m_socket_count; }

        /**
         * A bitfield indicating the socket types used: 0x1 (tcp), 0x2 (udp),
         * 0x4 (unix stream), 0x8 (unix dgram), 0x10 (netlink), and 0x8000
         * (unknown)
         */
        uint16_t socket_types() const { return m_socket_types; }

        /**
         * A bitfield indicating the socket states: 0x1 (established), 0x2
         * (syn-sent), 0x4 (syn-recv), 0x8 (fin-wait-1), 0x10 (fin-wait-2),
         * 0x20 (time-wait), 0x40 (closed), 0x80 (close-wait), 0x100 (last-
         * ack), 0x200 (listen), 0x400 (closing), 0x800 (unconnected), and
         * 0x8000 (unknown)
         */
        uint16_t socket_states() const { return m_socket_states; }

        /**
         * the command line of the process in question
         */
        std::string cmdline() const { return m_cmdline; }
        linux_t* _root() const { return m__root; }
        sbp_t::sbp_message_t* _parent() const { return m__parent; }
    };

private:
    linux_t* m__root;
    kaitai::kstruct* m__parent;

public:
    linux_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // LINUX_H_
