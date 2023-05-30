import kaitai_struct_nim_runtime
import options

type
  Linux* = ref object of KaitaiStruct
    `parent`*: KaitaiStruct
  Linux_MsgLinuxSocketUsage* = ref object of KaitaiStruct
    `avgQueueDepth`*: uint32
    `maxQueueDepth`*: uint32
    `socketStateCounts`*: seq[uint16]
    `socketTypeCounts`*: seq[uint16]
    `parent`*: Sbp_Message
  Linux_MsgLinuxSysState* = ref object of KaitaiStruct
    `memTotal`*: uint16
    `pcpu`*: uint8
    `pmem`*: uint8
    `procsStarting`*: uint16
    `procsStopping`*: uint16
    `pidCount`*: uint16
    `time`*: uint32
    `flags`*: uint8
    `parent`*: Sbp_Message
  Linux_MsgLinuxCpuStateDepA* = ref object of KaitaiStruct
    `index`*: uint8
    `pid`*: uint16
    `pcpu`*: uint8
    `tname`*: string
    `cmdline`*: string
    `parent`*: Sbp_Message
  Linux_MsgLinuxMemState* = ref object of KaitaiStruct
    `index`*: uint8
    `pid`*: uint16
    `pmem`*: uint8
    `time`*: uint32
    `flags`*: uint8
    `tname`*: string
    `cmdline`*: string
    `parent`*: Sbp_Message
  Linux_MsgLinuxProcessFdCount* = ref object of KaitaiStruct
    `index`*: uint8
    `pid`*: uint16
    `fdCount`*: uint16
    `cmdline`*: string
    `parent`*: Sbp_Message
  Linux_MsgLinuxMemStateDepA* = ref object of KaitaiStruct
    `index`*: uint8
    `pid`*: uint16
    `pmem`*: uint8
    `tname`*: string
    `cmdline`*: string
    `parent`*: Sbp_Message
  Linux_MsgLinuxProcessSocketQueues* = ref object of KaitaiStruct
    `index`*: uint8
    `pid`*: uint16
    `recvQueued`*: uint16
    `sendQueued`*: uint16
    `socketTypes`*: uint16
    `socketStates`*: uint16
    `addressOfLargest`*: string
    `cmdline`*: string
    `parent`*: Sbp_Message
  Linux_MsgLinuxSysStateDepA* = ref object of KaitaiStruct
    `memTotal`*: uint16
    `pcpu`*: uint8
    `pmem`*: uint8
    `procsStarting`*: uint16
    `procsStopping`*: uint16
    `pidCount`*: uint16
    `parent`*: Sbp_Message
  Linux_MsgLinuxProcessFdSummary* = ref object of KaitaiStruct
    `sysFdCount`*: uint32
    `mostOpened`*: string
    `parent`*: Sbp_Message
  Linux_MsgLinuxCpuState* = ref object of KaitaiStruct
    `index`*: uint8
    `pid`*: uint16
    `pcpu`*: uint8
    `time`*: uint32
    `flags`*: uint8
    `tname`*: string
    `cmdline`*: string
    `parent`*: Sbp_Message
  Linux_MsgLinuxProcessSocketCounts* = ref object of KaitaiStruct
    `index`*: uint8
    `pid`*: uint16
    `socketCount`*: uint16
    `socketTypes`*: uint16
    `socketStates`*: uint16
    `cmdline`*: string
    `parent`*: Sbp_Message

proc read*(_: typedesc[Linux], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Linux
proc read*(_: typedesc[Linux_MsgLinuxSocketUsage], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Linux_MsgLinuxSocketUsage
proc read*(_: typedesc[Linux_MsgLinuxSysState], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Linux_MsgLinuxSysState
proc read*(_: typedesc[Linux_MsgLinuxCpuStateDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Linux_MsgLinuxCpuStateDepA
proc read*(_: typedesc[Linux_MsgLinuxMemState], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Linux_MsgLinuxMemState
proc read*(_: typedesc[Linux_MsgLinuxProcessFdCount], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Linux_MsgLinuxProcessFdCount
proc read*(_: typedesc[Linux_MsgLinuxMemStateDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Linux_MsgLinuxMemStateDepA
proc read*(_: typedesc[Linux_MsgLinuxProcessSocketQueues], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Linux_MsgLinuxProcessSocketQueues
proc read*(_: typedesc[Linux_MsgLinuxSysStateDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Linux_MsgLinuxSysStateDepA
proc read*(_: typedesc[Linux_MsgLinuxProcessFdSummary], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Linux_MsgLinuxProcessFdSummary
proc read*(_: typedesc[Linux_MsgLinuxCpuState], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Linux_MsgLinuxCpuState
proc read*(_: typedesc[Linux_MsgLinuxProcessSocketCounts], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Linux_MsgLinuxProcessSocketCounts


proc read*(_: typedesc[Linux], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Linux =
  template this: untyped = result
  this = new(Linux)
  let root = if root == nil: cast[Linux](this) else: cast[Linux](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[Linux], filename: string): Linux =
  Linux.read(newKaitaiFileStream(filename), nil, nil)


##[
Summaries the socket usage across the system.

]##
proc read*(_: typedesc[Linux_MsgLinuxSocketUsage], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Linux_MsgLinuxSocketUsage =
  template this: untyped = result
  this = new(Linux_MsgLinuxSocketUsage)
  let root = if root == nil: cast[Linux](this) else: cast[Linux](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  average socket queue depths across all sockets on the system

  ]##
  let avgQueueDepthExpr = this.io.readU4le()
  this.avgQueueDepth = avgQueueDepthExpr

  ##[
  the max queue depth seen within the reporting period

  ]##
  let maxQueueDepthExpr = this.io.readU4le()
  this.maxQueueDepth = maxQueueDepthExpr

  ##[
  A count for each socket type reported in the `socket_types_reported`
field, the first entry corresponds to the first enabled bit in
`types_reported`.

  ]##
  for i in 0 ..< int(16):
    let it = this.io.readU2le()
    this.socketStateCounts.add(it)

  ##[
  A count for each socket type reported in the `socket_types_reported`
field, the first entry corresponds to the first enabled bit in
`types_reported`.

  ]##
  for i in 0 ..< int(16):
    let it = this.io.readU2le()
    this.socketTypeCounts.add(it)

proc fromFile*(_: typedesc[Linux_MsgLinuxSocketUsage], filename: string): Linux_MsgLinuxSocketUsage =
  Linux_MsgLinuxSocketUsage.read(newKaitaiFileStream(filename), nil, nil)


##[
This presents a summary of CPU and memory utilization, including a
timestamp.

]##
proc read*(_: typedesc[Linux_MsgLinuxSysState], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Linux_MsgLinuxSysState =
  template this: untyped = result
  this = new(Linux_MsgLinuxSysState)
  let root = if root == nil: cast[Linux](this) else: cast[Linux](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  total system memory, in MiB

  ]##
  let memTotalExpr = this.io.readU2le()
  this.memTotal = memTotalExpr

  ##[
  percent of CPU used, expressed as a fraction of 256

  ]##
  let pcpuExpr = this.io.readU1()
  this.pcpu = pcpuExpr

  ##[
  percent of memory used, expressed as a fraction of 256

  ]##
  let pmemExpr = this.io.readU1()
  this.pmem = pmemExpr

  ##[
  number of processes that started during collection phase

  ]##
  let procsStartingExpr = this.io.readU2le()
  this.procsStarting = procsStartingExpr

  ##[
  number of processes that stopped during collection phase

  ]##
  let procsStoppingExpr = this.io.readU2le()
  this.procsStopping = procsStoppingExpr

  ##[
  the count of processes on the system

  ]##
  let pidCountExpr = this.io.readU2le()
  this.pidCount = pidCountExpr

  ##[
  timestamp of message, refer to flags field for how to interpret

  ]##
  let timeExpr = this.io.readU4le()
  this.time = timeExpr

  ##[
  flags

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

proc fromFile*(_: typedesc[Linux_MsgLinuxSysState], filename: string): Linux_MsgLinuxSysState =
  Linux_MsgLinuxSysState.read(newKaitaiFileStream(filename), nil, nil)


##[
This message indicates the process state of the top 10 heaviest
consumers of CPU on the system.

]##
proc read*(_: typedesc[Linux_MsgLinuxCpuStateDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Linux_MsgLinuxCpuStateDepA =
  template this: untyped = result
  this = new(Linux_MsgLinuxCpuStateDepA)
  let root = if root == nil: cast[Linux](this) else: cast[Linux](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  sequence of this status message, values from 0-9

  ]##
  let indexExpr = this.io.readU1()
  this.index = indexExpr

  ##[
  the PID of the process

  ]##
  let pidExpr = this.io.readU2le()
  this.pid = pidExpr

  ##[
  percent of cpu used, expressed as a fraction of 256

  ]##
  let pcpuExpr = this.io.readU1()
  this.pcpu = pcpuExpr

  ##[
  fixed length string representing the thread name

  ]##
  let tnameExpr = encode(this.io.readBytesFull(), "ascii")
  this.tname = tnameExpr

  ##[
  the command line (as much as it fits in the remaining packet)

  ]##
  let cmdlineExpr = encode(this.io.readBytesFull(), "ascii")
  this.cmdline = cmdlineExpr

proc fromFile*(_: typedesc[Linux_MsgLinuxCpuStateDepA], filename: string): Linux_MsgLinuxCpuStateDepA =
  Linux_MsgLinuxCpuStateDepA.read(newKaitaiFileStream(filename), nil, nil)


##[
This message indicates the process state of the top 10 heaviest
consumers of memory on the system, including a timestamp.

]##
proc read*(_: typedesc[Linux_MsgLinuxMemState], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Linux_MsgLinuxMemState =
  template this: untyped = result
  this = new(Linux_MsgLinuxMemState)
  let root = if root == nil: cast[Linux](this) else: cast[Linux](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  sequence of this status message, values from 0-9

  ]##
  let indexExpr = this.io.readU1()
  this.index = indexExpr

  ##[
  the PID of the process

  ]##
  let pidExpr = this.io.readU2le()
  this.pid = pidExpr

  ##[
  percent of memory used, expressed as a fraction of 256

  ]##
  let pmemExpr = this.io.readU1()
  this.pmem = pmemExpr

  ##[
  timestamp of message, refer to flags field for how to interpret

  ]##
  let timeExpr = this.io.readU4le()
  this.time = timeExpr

  ##[
  flags

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

  ##[
  fixed length string representing the thread name

  ]##
  let tnameExpr = encode(this.io.readBytesFull(), "ascii")
  this.tname = tnameExpr

  ##[
  the command line (as much as it fits in the remaining packet)

  ]##
  let cmdlineExpr = encode(this.io.readBytesFull(), "ascii")
  this.cmdline = cmdlineExpr

proc fromFile*(_: typedesc[Linux_MsgLinuxMemState], filename: string): Linux_MsgLinuxMemState =
  Linux_MsgLinuxMemState.read(newKaitaiFileStream(filename), nil, nil)


##[
Top 10 list of processes with a large number of open file descriptors.

]##
proc read*(_: typedesc[Linux_MsgLinuxProcessFdCount], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Linux_MsgLinuxProcessFdCount =
  template this: untyped = result
  this = new(Linux_MsgLinuxProcessFdCount)
  let root = if root == nil: cast[Linux](this) else: cast[Linux](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  sequence of this status message, values from 0-9

  ]##
  let indexExpr = this.io.readU1()
  this.index = indexExpr

  ##[
  the PID of the process in question

  ]##
  let pidExpr = this.io.readU2le()
  this.pid = pidExpr

  ##[
  a count of the number of file descriptors opened by the process

  ]##
  let fdCountExpr = this.io.readU2le()
  this.fdCount = fdCountExpr

  ##[
  the command line of the process in question

  ]##
  let cmdlineExpr = encode(this.io.readBytesFull(), "ascii")
  this.cmdline = cmdlineExpr

proc fromFile*(_: typedesc[Linux_MsgLinuxProcessFdCount], filename: string): Linux_MsgLinuxProcessFdCount =
  Linux_MsgLinuxProcessFdCount.read(newKaitaiFileStream(filename), nil, nil)


##[
This message indicates the process state of the top 10 heaviest
consumers of memory on the system.

]##
proc read*(_: typedesc[Linux_MsgLinuxMemStateDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Linux_MsgLinuxMemStateDepA =
  template this: untyped = result
  this = new(Linux_MsgLinuxMemStateDepA)
  let root = if root == nil: cast[Linux](this) else: cast[Linux](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  sequence of this status message, values from 0-9

  ]##
  let indexExpr = this.io.readU1()
  this.index = indexExpr

  ##[
  the PID of the process

  ]##
  let pidExpr = this.io.readU2le()
  this.pid = pidExpr

  ##[
  percent of memory used, expressed as a fraction of 256

  ]##
  let pmemExpr = this.io.readU1()
  this.pmem = pmemExpr

  ##[
  fixed length string representing the thread name

  ]##
  let tnameExpr = encode(this.io.readBytesFull(), "ascii")
  this.tname = tnameExpr

  ##[
  the command line (as much as it fits in the remaining packet)

  ]##
  let cmdlineExpr = encode(this.io.readBytesFull(), "ascii")
  this.cmdline = cmdlineExpr

proc fromFile*(_: typedesc[Linux_MsgLinuxMemStateDepA], filename: string): Linux_MsgLinuxMemStateDepA =
  Linux_MsgLinuxMemStateDepA.read(newKaitaiFileStream(filename), nil, nil)


##[
Top 10 list of sockets with deep queues.

]##
proc read*(_: typedesc[Linux_MsgLinuxProcessSocketQueues], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Linux_MsgLinuxProcessSocketQueues =
  template this: untyped = result
  this = new(Linux_MsgLinuxProcessSocketQueues)
  let root = if root == nil: cast[Linux](this) else: cast[Linux](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  sequence of this status message, values from 0-9

  ]##
  let indexExpr = this.io.readU1()
  this.index = indexExpr

  ##[
  the PID of the process in question

  ]##
  let pidExpr = this.io.readU2le()
  this.pid = pidExpr

  ##[
  the total amount of receive data queued for this process

  ]##
  let recvQueuedExpr = this.io.readU2le()
  this.recvQueued = recvQueuedExpr

  ##[
  the total amount of send data queued for this process

  ]##
  let sendQueuedExpr = this.io.readU2le()
  this.sendQueued = sendQueuedExpr

  ##[
  A bitfield indicating the socket types used: 0x1 (tcp), 0x2 (udp),
0x4 (unix stream), 0x8 (unix dgram), 0x10 (netlink), and 0x8000
(unknown)

  ]##
  let socketTypesExpr = this.io.readU2le()
  this.socketTypes = socketTypesExpr

  ##[
  A bitfield indicating the socket states: 0x1 (established), 0x2
(syn-sent), 0x4 (syn-recv), 0x8 (fin-wait-1), 0x10 (fin-wait-2),
0x20 (time-wait), 0x40 (closed), 0x80 (close-wait), 0x100 (last-
ack), 0x200 (listen), 0x400 (closing), 0x800 (unconnected), and
0x8000 (unknown)

  ]##
  let socketStatesExpr = this.io.readU2le()
  this.socketStates = socketStatesExpr

  ##[
  Address of the largest queue, remote or local depending on the
directionality of the connection.

  ]##
  let addressOfLargestExpr = encode(this.io.readBytesFull(), "ascii")
  this.addressOfLargest = addressOfLargestExpr

  ##[
  the command line of the process in question

  ]##
  let cmdlineExpr = encode(this.io.readBytesFull(), "ascii")
  this.cmdline = cmdlineExpr

proc fromFile*(_: typedesc[Linux_MsgLinuxProcessSocketQueues], filename: string): Linux_MsgLinuxProcessSocketQueues =
  Linux_MsgLinuxProcessSocketQueues.read(newKaitaiFileStream(filename), nil, nil)


##[
This presents a summary of CPU and memory utilization.

]##
proc read*(_: typedesc[Linux_MsgLinuxSysStateDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Linux_MsgLinuxSysStateDepA =
  template this: untyped = result
  this = new(Linux_MsgLinuxSysStateDepA)
  let root = if root == nil: cast[Linux](this) else: cast[Linux](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  total system memory

  ]##
  let memTotalExpr = this.io.readU2le()
  this.memTotal = memTotalExpr

  ##[
  percent of total cpu currently utilized

  ]##
  let pcpuExpr = this.io.readU1()
  this.pcpu = pcpuExpr

  ##[
  percent of total memory currently utilized

  ]##
  let pmemExpr = this.io.readU1()
  this.pmem = pmemExpr

  ##[
  number of processes that started during collection phase

  ]##
  let procsStartingExpr = this.io.readU2le()
  this.procsStarting = procsStartingExpr

  ##[
  number of processes that stopped during collection phase

  ]##
  let procsStoppingExpr = this.io.readU2le()
  this.procsStopping = procsStoppingExpr

  ##[
  the count of processes on the system

  ]##
  let pidCountExpr = this.io.readU2le()
  this.pidCount = pidCountExpr

proc fromFile*(_: typedesc[Linux_MsgLinuxSysStateDepA], filename: string): Linux_MsgLinuxSysStateDepA =
  Linux_MsgLinuxSysStateDepA.read(newKaitaiFileStream(filename), nil, nil)


##[
Summary of open file descriptors on the system.

]##
proc read*(_: typedesc[Linux_MsgLinuxProcessFdSummary], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Linux_MsgLinuxProcessFdSummary =
  template this: untyped = result
  this = new(Linux_MsgLinuxProcessFdSummary)
  let root = if root == nil: cast[Linux](this) else: cast[Linux](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  count of total FDs open on the system

  ]##
  let sysFdCountExpr = this.io.readU4le()
  this.sysFdCount = sysFdCountExpr

  ##[
  A null delimited list of strings which alternates between a string
representation of the process count and the file name whose count it
being reported.  That is, in C string syntax
"32\0/var/log/syslog\012\0/tmp/foo\0" with the end of the list being
2 NULL terminators in a row.

  ]##
  let mostOpenedExpr = encode(this.io.readBytesFull(), "ascii")
  this.mostOpened = mostOpenedExpr

proc fromFile*(_: typedesc[Linux_MsgLinuxProcessFdSummary], filename: string): Linux_MsgLinuxProcessFdSummary =
  Linux_MsgLinuxProcessFdSummary.read(newKaitaiFileStream(filename), nil, nil)


##[
This message indicates the process state of the top 10 heaviest
consumers of CPU on the system, including a timestamp.

]##
proc read*(_: typedesc[Linux_MsgLinuxCpuState], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Linux_MsgLinuxCpuState =
  template this: untyped = result
  this = new(Linux_MsgLinuxCpuState)
  let root = if root == nil: cast[Linux](this) else: cast[Linux](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  sequence of this status message, values from 0-9

  ]##
  let indexExpr = this.io.readU1()
  this.index = indexExpr

  ##[
  the PID of the process

  ]##
  let pidExpr = this.io.readU2le()
  this.pid = pidExpr

  ##[
  percent of CPU used, expressed as a fraction of 256

  ]##
  let pcpuExpr = this.io.readU1()
  this.pcpu = pcpuExpr

  ##[
  timestamp of message, refer to flags field for how to interpret

  ]##
  let timeExpr = this.io.readU4le()
  this.time = timeExpr

  ##[
  flags

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

  ##[
  fixed length string representing the thread name

  ]##
  let tnameExpr = encode(this.io.readBytesFull(), "ascii")
  this.tname = tnameExpr

  ##[
  the command line (as much as it fits in the remaining packet)

  ]##
  let cmdlineExpr = encode(this.io.readBytesFull(), "ascii")
  this.cmdline = cmdlineExpr

proc fromFile*(_: typedesc[Linux_MsgLinuxCpuState], filename: string): Linux_MsgLinuxCpuState =
  Linux_MsgLinuxCpuState.read(newKaitaiFileStream(filename), nil, nil)


##[
Top 10 list of processes with high socket counts.

]##
proc read*(_: typedesc[Linux_MsgLinuxProcessSocketCounts], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Linux_MsgLinuxProcessSocketCounts =
  template this: untyped = result
  this = new(Linux_MsgLinuxProcessSocketCounts)
  let root = if root == nil: cast[Linux](this) else: cast[Linux](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  sequence of this status message, values from 0-9

  ]##
  let indexExpr = this.io.readU1()
  this.index = indexExpr

  ##[
  the PID of the process in question

  ]##
  let pidExpr = this.io.readU2le()
  this.pid = pidExpr

  ##[
  the number of sockets the process is using

  ]##
  let socketCountExpr = this.io.readU2le()
  this.socketCount = socketCountExpr

  ##[
  A bitfield indicating the socket types used: 0x1 (tcp), 0x2 (udp),
0x4 (unix stream), 0x8 (unix dgram), 0x10 (netlink), and 0x8000
(unknown)

  ]##
  let socketTypesExpr = this.io.readU2le()
  this.socketTypes = socketTypesExpr

  ##[
  A bitfield indicating the socket states: 0x1 (established), 0x2
(syn-sent), 0x4 (syn-recv), 0x8 (fin-wait-1), 0x10 (fin-wait-2),
0x20 (time-wait), 0x40 (closed), 0x80 (close-wait), 0x100 (last-
ack), 0x200 (listen), 0x400 (closing), 0x800 (unconnected), and
0x8000 (unknown)

  ]##
  let socketStatesExpr = this.io.readU2le()
  this.socketStates = socketStatesExpr

  ##[
  the command line of the process in question

  ]##
  let cmdlineExpr = encode(this.io.readBytesFull(), "ascii")
  this.cmdline = cmdlineExpr

proc fromFile*(_: typedesc[Linux_MsgLinuxProcessSocketCounts], filename: string): Linux_MsgLinuxProcessSocketCounts =
  Linux_MsgLinuxProcessSocketCounts.read(newKaitaiFileStream(filename), nil, nil)

