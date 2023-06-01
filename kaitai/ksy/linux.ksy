# Linux state monitoring.

# Automatically generated from spec/yaml/swiftnav/sbp/linux.yaml with generate.py.
# Please do not hand edit!

meta:
  id: linux
  endian: le
  imports: [  ]

types:

  msg_linux_cpu_state_dep_a:
    doc: |
      Deprecated.
    seq:
      - id: index
        doc: |
          sequence of this status message, values from 0-9
        type: u1
      - id: pid
        doc: |
          the PID of the process
        type: u2
      - id: pcpu
        doc: |
          percent of cpu used, expressed as a fraction of 256
        type: u1
      - id: tname
        doc: |
          fixed length string representing the thread name
        type: str
        encoding: ascii
        size: 15
      - id: cmdline
        doc: |
          the command line (as much as it fits in the remaining packet)
        type: str
        encoding: ascii
        size-eos: true
  
  msg_linux_mem_state_dep_a:
    doc: |
      Deprecated.
    seq:
      - id: index
        doc: |
          sequence of this status message, values from 0-9
        type: u1
      - id: pid
        doc: |
          the PID of the process
        type: u2
      - id: pmem
        doc: |
          percent of memory used, expressed as a fraction of 256
        type: u1
      - id: tname
        doc: |
          fixed length string representing the thread name
        type: str
        encoding: ascii
        size: 15
      - id: cmdline
        doc: |
          the command line (as much as it fits in the remaining packet)
        type: str
        encoding: ascii
        size-eos: true
  
  msg_linux_sys_state_dep_a:
    doc: |
      Deprecated.
    seq:
      - id: mem_total
        doc: |
          total system memory
        type: u2
      - id: pcpu
        doc: |
          percent of total cpu currently utilized
        type: u1
      - id: pmem
        doc: |
          percent of total memory currently utilized
        type: u1
      - id: procs_starting
        doc: |
          number of processes that started during collection phase
        type: u2
      - id: procs_stopping
        doc: |
          number of processes that stopped during collection phase
        type: u2
      - id: pid_count
        doc: |
          the count of processes on the system
        type: u2
  
  msg_linux_process_socket_counts:
    doc: |
      Top 10 list of processes with high socket counts.
    seq:
      - id: index
        doc: |
          sequence of this status message, values from 0-9
        type: u1
      - id: pid
        doc: |
          the PID of the process in question
        type: u2
      - id: socket_count
        doc: |
          the number of sockets the process is using
        type: u2
      - id: socket_types
        doc: |
          A bitfield indicating the socket types used: 0x1 (tcp), 0x2 (udp),
          0x4 (unix stream), 0x8 (unix dgram), 0x10 (netlink), and 0x8000
          (unknown)
        type: u2
      - id: socket_states
        doc: |
          A bitfield indicating the socket states: 0x1 (established), 0x2
          (syn-sent), 0x4 (syn-recv), 0x8 (fin-wait-1), 0x10 (fin-wait-2),
          0x20 (time-wait), 0x40 (closed), 0x80 (close-wait), 0x100 (last-
          ack), 0x200 (listen), 0x400 (closing), 0x800 (unconnected), and
          0x8000 (unknown)
        type: u2
      - id: cmdline
        doc: |
          the command line of the process in question
        type: str
        encoding: ascii
        size-eos: true
  
  msg_linux_process_socket_queues:
    doc: |
      Top 10 list of sockets with deep queues.
    seq:
      - id: index
        doc: |
          sequence of this status message, values from 0-9
        type: u1
      - id: pid
        doc: |
          the PID of the process in question
        type: u2
      - id: recv_queued
        doc: |
          the total amount of receive data queued for this process
        type: u2
      - id: send_queued
        doc: |
          the total amount of send data queued for this process
        type: u2
      - id: socket_types
        doc: |
          A bitfield indicating the socket types used: 0x1 (tcp), 0x2 (udp),
          0x4 (unix stream), 0x8 (unix dgram), 0x10 (netlink), and 0x8000
          (unknown)
        type: u2
      - id: socket_states
        doc: |
          A bitfield indicating the socket states: 0x1 (established), 0x2
          (syn-sent), 0x4 (syn-recv), 0x8 (fin-wait-1), 0x10 (fin-wait-2),
          0x20 (time-wait), 0x40 (closed), 0x80 (close-wait), 0x100 (last-
          ack), 0x200 (listen), 0x400 (closing), 0x800 (unconnected), and
          0x8000 (unknown)
        type: u2
      - id: address_of_largest
        doc: |
          Address of the largest queue, remote or local depending on the
          directionality of the connection.
        type: str
        encoding: ascii
        size: 64
      - id: cmdline
        doc: |
          the command line of the process in question
        type: str
        encoding: ascii
        size-eos: true
  
  msg_linux_socket_usage:
    doc: |
      Summaries the socket usage across the system.
    seq:
      - id: avg_queue_depth
        doc: |
          average socket queue depths across all sockets on the system
        type: u4
      - id: max_queue_depth
        doc: |
          the max queue depth seen within the reporting period
        type: u4
      - id: socket_state_counts
        doc: |
          A count for each socket type reported in the `socket_types_reported`
          field, the first entry corresponds to the first enabled bit in
          `types_reported`.
        type: u2
        repeat: expr
        repeat-expr: 16
      - id: socket_type_counts
        doc: |
          A count for each socket type reported in the `socket_types_reported`
          field, the first entry corresponds to the first enabled bit in
          `types_reported`.
        type: u2
        repeat: expr
        repeat-expr: 16
  
  msg_linux_process_fd_count:
    doc: |
      Top 10 list of processes with a large number of open file descriptors.
    seq:
      - id: index
        doc: |
          sequence of this status message, values from 0-9
        type: u1
      - id: pid
        doc: |
          the PID of the process in question
        type: u2
      - id: fd_count
        doc: |
          a count of the number of file descriptors opened by the process
        type: u2
      - id: cmdline
        doc: |
          the command line of the process in question
        type: str
        encoding: ascii
        size-eos: true
  
  msg_linux_process_fd_summary:
    doc: |
      Summary of open file descriptors on the system.
    seq:
      - id: sys_fd_count
        doc: |
          count of total FDs open on the system
        type: u4
      - id: most_opened
        doc: |
          A null delimited list of strings which alternates between a string
          representation of the process count and the file name whose count it
          being reported.  That is, in C string syntax
          "32\0/var/log/syslog\012\0/tmp/foo\0" with the end of the list being
          2 NULL terminators in a row.
        type: str
        encoding: ascii
        size-eos: true
  
  msg_linux_cpu_state:
    doc: |
      This message indicates the process state of the top 10 heaviest
      consumers of CPU on the system, including a timestamp.
    seq:
      - id: index
        doc: |
          sequence of this status message, values from 0-9
        type: u1
      - id: pid
        doc: |
          the PID of the process
        type: u2
      - id: pcpu
        doc: |
          percent of CPU used, expressed as a fraction of 256
        type: u1
      - id: time
        doc: |
          timestamp of message, refer to flags field for how to interpret
        type: u4
      - id: flags
        doc: |
          flags
        type: u1
      - id: tname
        doc: |
          fixed length string representing the thread name
        type: str
        encoding: ascii
        size: 15
      - id: cmdline
        doc: |
          the command line (as much as it fits in the remaining packet)
        type: str
        encoding: ascii
        size-eos: true
  
  msg_linux_mem_state:
    doc: |
      This message indicates the process state of the top 10 heaviest
      consumers of memory on the system, including a timestamp.
    seq:
      - id: index
        doc: |
          sequence of this status message, values from 0-9
        type: u1
      - id: pid
        doc: |
          the PID of the process
        type: u2
      - id: pmem
        doc: |
          percent of memory used, expressed as a fraction of 256
        type: u1
      - id: time
        doc: |
          timestamp of message, refer to flags field for how to interpret
        type: u4
      - id: flags
        doc: |
          flags
        type: u1
      - id: tname
        doc: |
          fixed length string representing the thread name
        type: str
        encoding: ascii
        size: 15
      - id: cmdline
        doc: |
          the command line (as much as it fits in the remaining packet)
        type: str
        encoding: ascii
        size-eos: true
  
  msg_linux_sys_state:
    doc: |
      This presents a summary of CPU and memory utilization, including a
      timestamp.
    seq:
      - id: mem_total
        doc: |
          total system memory, in MiB
        type: u2
      - id: pcpu
        doc: |
          percent of CPU used, expressed as a fraction of 256
        type: u1
      - id: pmem
        doc: |
          percent of memory used, expressed as a fraction of 256
        type: u1
      - id: procs_starting
        doc: |
          number of processes that started during collection phase
        type: u2
      - id: procs_stopping
        doc: |
          number of processes that stopped during collection phase
        type: u2
      - id: pid_count
        doc: |
          the count of processes on the system
        type: u2
      - id: time
        doc: |
          timestamp of message, refer to flags field for how to interpret
        type: u4
      - id: flags
        doc: |
          flags
        type: u1
  