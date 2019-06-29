/**
 * Copyright (C) 2015-2018 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swiftnav.com>
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/**********************
 * Automatically generated from piksi/yaml/swiftnav/sbp/piksi.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * System health, configuration, and diagnostic messages specific to the Piksi L1
 * receiver, including a variety of legacy messages that may no longer be used.
***********************/

var SBP = require('./sbp');
var Parser = require('./parser');
var Int64 = require('node-int64');
var UInt64 = require('cuint').UINT64;
var GnssSignal = require("./gnss").GnssSignal;
var GnssSignalDep = require("./gnss").GnssSignalDep;
var GPSTime = require("./gnss").GPSTime;
var CarrierPhase = require("./gnss").CarrierPhase;
var GPSTime = require("./gnss").GPSTime;
var GPSTimeSec = require("./gnss").GPSTimeSec;
var GPSTimeDep = require("./gnss").GPSTimeDep;
var SvId = require("./gnss").SvId;

/**
 * SBP class for message MSG_ALMANAC (0x0069).
 *
 * This is a legacy message for sending and loading a satellite alamanac onto the
 * Piksi's flash memory from the host.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgAlmanac = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ALMANAC";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgAlmanac.prototype = Object.create(SBP.prototype);
MsgAlmanac.prototype.messageType = "MSG_ALMANAC";
MsgAlmanac.prototype.msg_type = 0x0069;
MsgAlmanac.prototype.constructor = MsgAlmanac;
MsgAlmanac.prototype.parser = new Parser()
  .endianess('little');
MsgAlmanac.prototype.fieldSpec = [];

/**
 * SBP class for message MSG_SET_TIME (0x0068).
 *
 * This message sets up timing functionality using a coarse GPS time estimate sent
 * by the host.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSetTime = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SET_TIME";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSetTime.prototype = Object.create(SBP.prototype);
MsgSetTime.prototype.messageType = "MSG_SET_TIME";
MsgSetTime.prototype.msg_type = 0x0068;
MsgSetTime.prototype.constructor = MsgSetTime;
MsgSetTime.prototype.parser = new Parser()
  .endianess('little');
MsgSetTime.prototype.fieldSpec = [];

/**
 * SBP class for message MSG_RESET (0x00B6).
 *
 * This message from the host resets the Piksi back into the bootloader.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field flags number (unsigned 32-bit int, 4 bytes) Reset flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgReset = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_RESET";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgReset.prototype = Object.create(SBP.prototype);
MsgReset.prototype.messageType = "MSG_RESET";
MsgReset.prototype.msg_type = 0x00B6;
MsgReset.prototype.constructor = MsgReset;
MsgReset.prototype.parser = new Parser()
  .endianess('little')
  .uint32('flags');
MsgReset.prototype.fieldSpec = [];
MsgReset.prototype.fieldSpec.push(['flags', 'writeUInt32LE', 4]);

/**
 * SBP class for message MSG_RESET_DEP (0x00B2).
 *
 * This message from the host resets the Piksi back into the bootloader.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgResetDep = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_RESET_DEP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgResetDep.prototype = Object.create(SBP.prototype);
MsgResetDep.prototype.messageType = "MSG_RESET_DEP";
MsgResetDep.prototype.msg_type = 0x00B2;
MsgResetDep.prototype.constructor = MsgResetDep;
MsgResetDep.prototype.parser = new Parser()
  .endianess('little');
MsgResetDep.prototype.fieldSpec = [];

/**
 * SBP class for message MSG_CW_RESULTS (0x00C0).
 *
 * This is an unused legacy message for result reporting from the CW interference
 * channel on the SwiftNAP. This message will be removed in a future release.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgCwResults = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_CW_RESULTS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgCwResults.prototype = Object.create(SBP.prototype);
MsgCwResults.prototype.messageType = "MSG_CW_RESULTS";
MsgCwResults.prototype.msg_type = 0x00C0;
MsgCwResults.prototype.constructor = MsgCwResults;
MsgCwResults.prototype.parser = new Parser()
  .endianess('little');
MsgCwResults.prototype.fieldSpec = [];

/**
 * SBP class for message MSG_CW_START (0x00C1).
 *
 * This is an unused legacy message from the host for starting the CW interference
 * channel on the SwiftNAP. This message will be removed in a future release.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgCwStart = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_CW_START";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgCwStart.prototype = Object.create(SBP.prototype);
MsgCwStart.prototype.messageType = "MSG_CW_START";
MsgCwStart.prototype.msg_type = 0x00C1;
MsgCwStart.prototype.constructor = MsgCwStart;
MsgCwStart.prototype.parser = new Parser()
  .endianess('little');
MsgCwStart.prototype.fieldSpec = [];

/**
 * SBP class for message MSG_RESET_FILTERS (0x0022).
 *
 * This message resets either the DGNSS Kalman filters or Integer Ambiguity
 * Resolution (IAR) process.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field filter number (unsigned 8-bit int, 1 byte) Filter flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgResetFilters = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_RESET_FILTERS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgResetFilters.prototype = Object.create(SBP.prototype);
MsgResetFilters.prototype.messageType = "MSG_RESET_FILTERS";
MsgResetFilters.prototype.msg_type = 0x0022;
MsgResetFilters.prototype.constructor = MsgResetFilters;
MsgResetFilters.prototype.parser = new Parser()
  .endianess('little')
  .uint8('filter');
MsgResetFilters.prototype.fieldSpec = [];
MsgResetFilters.prototype.fieldSpec.push(['filter', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_INIT_BASE_DEP (0x0023).
 *
 * Deprecated
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgInitBaseDep = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_INIT_BASE_DEP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgInitBaseDep.prototype = Object.create(SBP.prototype);
MsgInitBaseDep.prototype.messageType = "MSG_INIT_BASE_DEP";
MsgInitBaseDep.prototype.msg_type = 0x0023;
MsgInitBaseDep.prototype.constructor = MsgInitBaseDep;
MsgInitBaseDep.prototype.parser = new Parser()
  .endianess('little');
MsgInitBaseDep.prototype.fieldSpec = [];

/**
 * SBP class for message MSG_THREAD_STATE (0x0017).
 *
 * The thread usage message from the device reports real-time operating system
 * (RTOS) thread usage statistics for the named thread. The reported percentage
 * values must be normalized.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field name string Thread name (NULL terminated)
 * @field cpu number (unsigned 16-bit int, 2 bytes) Percentage cpu use for this thread. Values range from 0 - 1000 and needs to be
 *   renormalized to 100
 * @field stack_free number (unsigned 32-bit int, 4 bytes) Free stack space for this thread
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgThreadState = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_THREAD_STATE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgThreadState.prototype = Object.create(SBP.prototype);
MsgThreadState.prototype.messageType = "MSG_THREAD_STATE";
MsgThreadState.prototype.msg_type = 0x0017;
MsgThreadState.prototype.constructor = MsgThreadState;
MsgThreadState.prototype.parser = new Parser()
  .endianess('little')
  .string('name', { length: 20 })
  .uint16('cpu')
  .uint32('stack_free');
MsgThreadState.prototype.fieldSpec = [];
MsgThreadState.prototype.fieldSpec.push(['name', 'string', 20]);
MsgThreadState.prototype.fieldSpec.push(['cpu', 'writeUInt16LE', 2]);
MsgThreadState.prototype.fieldSpec.push(['stack_free', 'writeUInt32LE', 4]);

/**
 * SBP class for message fragment UARTChannel
 *
 * Throughput, utilization, and error counts on the RX/TX buffers of this UART
 * channel. The reported percentage values must be normalized.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tx_throughput number (float, 4 bytes) UART transmit throughput
 * @field rx_throughput number (float, 4 bytes) UART receive throughput
 * @field crc_error_count number (unsigned 16-bit int, 2 bytes) UART CRC error count
 * @field io_error_count number (unsigned 16-bit int, 2 bytes) UART IO error count
 * @field tx_buffer_level number (unsigned 8-bit int, 1 byte) UART transmit buffer percentage utilization (ranges from 0 to 255)
 * @field rx_buffer_level number (unsigned 8-bit int, 1 byte) UART receive buffer percentage utilization (ranges from 0 to 255)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var UARTChannel = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "UARTChannel";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
UARTChannel.prototype = Object.create(SBP.prototype);
UARTChannel.prototype.messageType = "UARTChannel";
UARTChannel.prototype.constructor = UARTChannel;
UARTChannel.prototype.parser = new Parser()
  .endianess('little')
  .floatle('tx_throughput')
  .floatle('rx_throughput')
  .uint16('crc_error_count')
  .uint16('io_error_count')
  .uint8('tx_buffer_level')
  .uint8('rx_buffer_level');
UARTChannel.prototype.fieldSpec = [];
UARTChannel.prototype.fieldSpec.push(['tx_throughput', 'writeFloatLE', 4]);
UARTChannel.prototype.fieldSpec.push(['rx_throughput', 'writeFloatLE', 4]);
UARTChannel.prototype.fieldSpec.push(['crc_error_count', 'writeUInt16LE', 2]);
UARTChannel.prototype.fieldSpec.push(['io_error_count', 'writeUInt16LE', 2]);
UARTChannel.prototype.fieldSpec.push(['tx_buffer_level', 'writeUInt8', 1]);
UARTChannel.prototype.fieldSpec.push(['rx_buffer_level', 'writeUInt8', 1]);

/**
 * SBP class for message fragment Period
 *
 * Statistics on the period of observations received from the base station. As
 * complete observation sets are received, their time of reception is compared with
 * the prior set''s time of reception. This measurement provides a proxy for link
 * quality as incomplete or missing sets will increase the period.  Long periods
 * can cause momentary RTK solution outages.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field avg number (signed 32-bit int, 4 bytes) Average period
 * @field pmin number (signed 32-bit int, 4 bytes) Minimum period
 * @field pmax number (signed 32-bit int, 4 bytes) Maximum period
 * @field current number (signed 32-bit int, 4 bytes) Smoothed estimate of the current period
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var Period = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "Period";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
Period.prototype = Object.create(SBP.prototype);
Period.prototype.messageType = "Period";
Period.prototype.constructor = Period;
Period.prototype.parser = new Parser()
  .endianess('little')
  .int32('avg')
  .int32('pmin')
  .int32('pmax')
  .int32('current');
Period.prototype.fieldSpec = [];
Period.prototype.fieldSpec.push(['avg', 'writeInt32LE', 4]);
Period.prototype.fieldSpec.push(['pmin', 'writeInt32LE', 4]);
Period.prototype.fieldSpec.push(['pmax', 'writeInt32LE', 4]);
Period.prototype.fieldSpec.push(['current', 'writeInt32LE', 4]);

/**
 * SBP class for message fragment Latency
 *
 * Statistics on the latency of observations received from the base station. As
 * observation packets are received their GPS time is compared to the current GPS
 * time calculated locally by the receiver to give a precise measurement of the
 * end-to-end communication latency in the system.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field avg number (signed 32-bit int, 4 bytes) Average latency
 * @field lmin number (signed 32-bit int, 4 bytes) Minimum latency
 * @field lmax number (signed 32-bit int, 4 bytes) Maximum latency
 * @field current number (signed 32-bit int, 4 bytes) Smoothed estimate of the current latency
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var Latency = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "Latency";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
Latency.prototype = Object.create(SBP.prototype);
Latency.prototype.messageType = "Latency";
Latency.prototype.constructor = Latency;
Latency.prototype.parser = new Parser()
  .endianess('little')
  .int32('avg')
  .int32('lmin')
  .int32('lmax')
  .int32('current');
Latency.prototype.fieldSpec = [];
Latency.prototype.fieldSpec.push(['avg', 'writeInt32LE', 4]);
Latency.prototype.fieldSpec.push(['lmin', 'writeInt32LE', 4]);
Latency.prototype.fieldSpec.push(['lmax', 'writeInt32LE', 4]);
Latency.prototype.fieldSpec.push(['current', 'writeInt32LE', 4]);

/**
 * SBP class for message MSG_UART_STATE (0x001D).
 *
 * The UART message reports data latency and throughput of the UART channels
 * providing SBP I/O. On the default Piksi configuration, UARTs A and B are used
 * for telemetry radios, but can also be host access ports for embedded hosts, or
 * other interfaces in future. The reported percentage values must be normalized.
 * Observations latency and period can be used to assess the health of the
 * differential corrections link. Latency provides the timeliness of received base
 * observations while the period indicates their likelihood of transmission.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field uart_a UARTChannel State of UART A
 * @field uart_b UARTChannel State of UART B
 * @field uart_ftdi UARTChannel State of UART FTDI (USB logger)
 * @field latency Latency UART communication latency
 * @field obs_period Period Observation receipt period
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgUartState = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_UART_STATE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgUartState.prototype = Object.create(SBP.prototype);
MsgUartState.prototype.messageType = "MSG_UART_STATE";
MsgUartState.prototype.msg_type = 0x001D;
MsgUartState.prototype.constructor = MsgUartState;
MsgUartState.prototype.parser = new Parser()
  .endianess('little')
  .nest('uart_a', { type: UARTChannel.prototype.parser })
  .nest('uart_b', { type: UARTChannel.prototype.parser })
  .nest('uart_ftdi', { type: UARTChannel.prototype.parser })
  .nest('latency', { type: Latency.prototype.parser })
  .nest('obs_period', { type: Period.prototype.parser });
MsgUartState.prototype.fieldSpec = [];
MsgUartState.prototype.fieldSpec.push(['uart_a', UARTChannel.prototype.fieldSpec]);
MsgUartState.prototype.fieldSpec.push(['uart_b', UARTChannel.prototype.fieldSpec]);
MsgUartState.prototype.fieldSpec.push(['uart_ftdi', UARTChannel.prototype.fieldSpec]);
MsgUartState.prototype.fieldSpec.push(['latency', Latency.prototype.fieldSpec]);
MsgUartState.prototype.fieldSpec.push(['obs_period', Period.prototype.fieldSpec]);

/**
 * SBP class for message MSG_UART_STATE_DEPA (0x0018).
 *
 * Deprecated
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field uart_a UARTChannel State of UART A
 * @field uart_b UARTChannel State of UART B
 * @field uart_ftdi UARTChannel State of UART FTDI (USB logger)
 * @field latency Latency UART communication latency
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgUartStateDepa = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_UART_STATE_DEPA";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgUartStateDepa.prototype = Object.create(SBP.prototype);
MsgUartStateDepa.prototype.messageType = "MSG_UART_STATE_DEPA";
MsgUartStateDepa.prototype.msg_type = 0x0018;
MsgUartStateDepa.prototype.constructor = MsgUartStateDepa;
MsgUartStateDepa.prototype.parser = new Parser()
  .endianess('little')
  .nest('uart_a', { type: UARTChannel.prototype.parser })
  .nest('uart_b', { type: UARTChannel.prototype.parser })
  .nest('uart_ftdi', { type: UARTChannel.prototype.parser })
  .nest('latency', { type: Latency.prototype.parser });
MsgUartStateDepa.prototype.fieldSpec = [];
MsgUartStateDepa.prototype.fieldSpec.push(['uart_a', UARTChannel.prototype.fieldSpec]);
MsgUartStateDepa.prototype.fieldSpec.push(['uart_b', UARTChannel.prototype.fieldSpec]);
MsgUartStateDepa.prototype.fieldSpec.push(['uart_ftdi', UARTChannel.prototype.fieldSpec]);
MsgUartStateDepa.prototype.fieldSpec.push(['latency', Latency.prototype.fieldSpec]);

/**
 * SBP class for message MSG_IAR_STATE (0x0019).
 *
 * This message reports the state of the Integer Ambiguity Resolution (IAR)
 * process, which resolves unknown integer ambiguities from double-differenced
 * carrier-phase measurements from satellite observations.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field num_hyps number (unsigned 32-bit int, 4 bytes) Number of integer ambiguity hypotheses remaining
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgIarState = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_IAR_STATE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgIarState.prototype = Object.create(SBP.prototype);
MsgIarState.prototype.messageType = "MSG_IAR_STATE";
MsgIarState.prototype.msg_type = 0x0019;
MsgIarState.prototype.constructor = MsgIarState;
MsgIarState.prototype.parser = new Parser()
  .endianess('little')
  .uint32('num_hyps');
MsgIarState.prototype.fieldSpec = [];
MsgIarState.prototype.fieldSpec.push(['num_hyps', 'writeUInt32LE', 4]);

/**
 * SBP class for message MSG_MASK_SATELLITE (0x002B).
 *
 * This message allows setting a mask to prevent a particular satellite from being
 * used in various Piksi subsystems.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field mask number (unsigned 8-bit int, 1 byte) Mask of systems that should ignore this satellite.
 * @field sid GnssSignal GNSS signal for which the mask is applied
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgMaskSatellite = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_MASK_SATELLITE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgMaskSatellite.prototype = Object.create(SBP.prototype);
MsgMaskSatellite.prototype.messageType = "MSG_MASK_SATELLITE";
MsgMaskSatellite.prototype.msg_type = 0x002B;
MsgMaskSatellite.prototype.constructor = MsgMaskSatellite;
MsgMaskSatellite.prototype.parser = new Parser()
  .endianess('little')
  .uint8('mask')
  .nest('sid', { type: GnssSignal.prototype.parser });
MsgMaskSatellite.prototype.fieldSpec = [];
MsgMaskSatellite.prototype.fieldSpec.push(['mask', 'writeUInt8', 1]);
MsgMaskSatellite.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);

/**
 * SBP class for message MSG_MASK_SATELLITE_DEP (0x001B).
 *
 * Deprecated.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field mask number (unsigned 8-bit int, 1 byte) Mask of systems that should ignore this satellite.
 * @field sid GnssSignalDep GNSS signal for which the mask is applied
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgMaskSatelliteDep = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_MASK_SATELLITE_DEP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgMaskSatelliteDep.prototype = Object.create(SBP.prototype);
MsgMaskSatelliteDep.prototype.messageType = "MSG_MASK_SATELLITE_DEP";
MsgMaskSatelliteDep.prototype.msg_type = 0x001B;
MsgMaskSatelliteDep.prototype.constructor = MsgMaskSatelliteDep;
MsgMaskSatelliteDep.prototype.parser = new Parser()
  .endianess('little')
  .uint8('mask')
  .nest('sid', { type: GnssSignalDep.prototype.parser });
MsgMaskSatelliteDep.prototype.fieldSpec = [];
MsgMaskSatelliteDep.prototype.fieldSpec.push(['mask', 'writeUInt8', 1]);
MsgMaskSatelliteDep.prototype.fieldSpec.push(['sid', GnssSignalDep.prototype.fieldSpec]);

/**
 * SBP class for message MSG_DEVICE_MONITOR (0x00B5).
 *
 * This message contains temperature and voltage level measurements from the
 * processor's monitoring system and the RF frontend die temperature if available.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field dev_vin number (signed 16-bit int, 2 bytes) Device V_in
 * @field cpu_vint number (signed 16-bit int, 2 bytes) Processor V_int
 * @field cpu_vaux number (signed 16-bit int, 2 bytes) Processor V_aux
 * @field cpu_temperature number (signed 16-bit int, 2 bytes) Processor temperature
 * @field fe_temperature number (signed 16-bit int, 2 bytes) Frontend temperature (if available)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgDeviceMonitor = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_DEVICE_MONITOR";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgDeviceMonitor.prototype = Object.create(SBP.prototype);
MsgDeviceMonitor.prototype.messageType = "MSG_DEVICE_MONITOR";
MsgDeviceMonitor.prototype.msg_type = 0x00B5;
MsgDeviceMonitor.prototype.constructor = MsgDeviceMonitor;
MsgDeviceMonitor.prototype.parser = new Parser()
  .endianess('little')
  .int16('dev_vin')
  .int16('cpu_vint')
  .int16('cpu_vaux')
  .int16('cpu_temperature')
  .int16('fe_temperature');
MsgDeviceMonitor.prototype.fieldSpec = [];
MsgDeviceMonitor.prototype.fieldSpec.push(['dev_vin', 'writeInt16LE', 2]);
MsgDeviceMonitor.prototype.fieldSpec.push(['cpu_vint', 'writeInt16LE', 2]);
MsgDeviceMonitor.prototype.fieldSpec.push(['cpu_vaux', 'writeInt16LE', 2]);
MsgDeviceMonitor.prototype.fieldSpec.push(['cpu_temperature', 'writeInt16LE', 2]);
MsgDeviceMonitor.prototype.fieldSpec.push(['fe_temperature', 'writeInt16LE', 2]);

/**
 * SBP class for message MSG_COMMAND_REQ (0x00B8).
 *
 * Request the recipient to execute an command. Output will be sent in MSG_LOG
 * messages, and the exit code will be returned with MSG_COMMAND_RESP.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sequence number (unsigned 32-bit int, 4 bytes) Sequence number
 * @field command string Command line to execute
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgCommandReq = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_COMMAND_REQ";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgCommandReq.prototype = Object.create(SBP.prototype);
MsgCommandReq.prototype.messageType = "MSG_COMMAND_REQ";
MsgCommandReq.prototype.msg_type = 0x00B8;
MsgCommandReq.prototype.constructor = MsgCommandReq;
MsgCommandReq.prototype.parser = new Parser()
  .endianess('little')
  .uint32('sequence')
  .string('command', { greedy: true });
MsgCommandReq.prototype.fieldSpec = [];
MsgCommandReq.prototype.fieldSpec.push(['sequence', 'writeUInt32LE', 4]);
MsgCommandReq.prototype.fieldSpec.push(['command', 'string', null]);

/**
 * SBP class for message MSG_COMMAND_RESP (0x00B9).
 *
 * The response to MSG_COMMAND_REQ with the return code of the command.  A return
 * code of zero indicates success.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sequence number (unsigned 32-bit int, 4 bytes) Sequence number
 * @field code number (signed 32-bit int, 4 bytes) Exit code
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgCommandResp = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_COMMAND_RESP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgCommandResp.prototype = Object.create(SBP.prototype);
MsgCommandResp.prototype.messageType = "MSG_COMMAND_RESP";
MsgCommandResp.prototype.msg_type = 0x00B9;
MsgCommandResp.prototype.constructor = MsgCommandResp;
MsgCommandResp.prototype.parser = new Parser()
  .endianess('little')
  .uint32('sequence')
  .int32('code');
MsgCommandResp.prototype.fieldSpec = [];
MsgCommandResp.prototype.fieldSpec.push(['sequence', 'writeUInt32LE', 4]);
MsgCommandResp.prototype.fieldSpec.push(['code', 'writeInt32LE', 4]);

/**
 * SBP class for message MSG_COMMAND_OUTPUT (0x00BC).
 *
 * Returns the standard output and standard error of the command requested by
 * MSG_COMMAND_REQ. The sequence number can be used to filter for filtering the
 * correct command.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sequence number (unsigned 32-bit int, 4 bytes) Sequence number
 * @field line string Line of standard output or standard error
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgCommandOutput = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_COMMAND_OUTPUT";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgCommandOutput.prototype = Object.create(SBP.prototype);
MsgCommandOutput.prototype.messageType = "MSG_COMMAND_OUTPUT";
MsgCommandOutput.prototype.msg_type = 0x00BC;
MsgCommandOutput.prototype.constructor = MsgCommandOutput;
MsgCommandOutput.prototype.parser = new Parser()
  .endianess('little')
  .uint32('sequence')
  .string('line', { greedy: true });
MsgCommandOutput.prototype.fieldSpec = [];
MsgCommandOutput.prototype.fieldSpec.push(['sequence', 'writeUInt32LE', 4]);
MsgCommandOutput.prototype.fieldSpec.push(['line', 'string', null]);

/**
 * SBP class for message MSG_NETWORK_STATE_REQ (0x00BA).
 *
 * Request state of Piksi network interfaces. Output will be sent in
 * MSG_NETWORK_STATE_RESP messages
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgNetworkStateReq = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_NETWORK_STATE_REQ";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgNetworkStateReq.prototype = Object.create(SBP.prototype);
MsgNetworkStateReq.prototype.messageType = "MSG_NETWORK_STATE_REQ";
MsgNetworkStateReq.prototype.msg_type = 0x00BA;
MsgNetworkStateReq.prototype.constructor = MsgNetworkStateReq;
MsgNetworkStateReq.prototype.parser = new Parser()
  .endianess('little');
MsgNetworkStateReq.prototype.fieldSpec = [];

/**
 * SBP class for message MSG_NETWORK_STATE_RESP (0x00BB).
 *
 * The state of a network interface on the Piksi. Data is made to reflect output of
 * ifaddrs struct returned by getifaddrs in c.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field ipv4_address array IPv4 address (all zero when unavailable)
 * @field ipv4_mask_size number (unsigned 8-bit int, 1 byte) IPv4 netmask CIDR notation
 * @field ipv6_address array IPv6 address (all zero when unavailable)
 * @field ipv6_mask_size number (unsigned 8-bit int, 1 byte) IPv6 netmask CIDR notation
 * @field rx_bytes number (unsigned 32-bit int, 4 bytes) Number of Rx bytes
 * @field tx_bytes number (unsigned 32-bit int, 4 bytes) Number of Tx bytes
 * @field interface_name string Interface Name
 * @field flags number (unsigned 32-bit int, 4 bytes) Interface flags from SIOCGIFFLAGS
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgNetworkStateResp = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_NETWORK_STATE_RESP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgNetworkStateResp.prototype = Object.create(SBP.prototype);
MsgNetworkStateResp.prototype.messageType = "MSG_NETWORK_STATE_RESP";
MsgNetworkStateResp.prototype.msg_type = 0x00BB;
MsgNetworkStateResp.prototype.constructor = MsgNetworkStateResp;
MsgNetworkStateResp.prototype.parser = new Parser()
  .endianess('little')
  .array('ipv4_address', { length: 4, type: 'uint8' })
  .uint8('ipv4_mask_size')
  .array('ipv6_address', { length: 16, type: 'uint8' })
  .uint8('ipv6_mask_size')
  .uint32('rx_bytes')
  .uint32('tx_bytes')
  .string('interface_name', { length: 16 })
  .uint32('flags');
MsgNetworkStateResp.prototype.fieldSpec = [];
MsgNetworkStateResp.prototype.fieldSpec.push(['ipv4_address', 'array', 'writeUInt8', function () { return 1; }, 4]);
MsgNetworkStateResp.prototype.fieldSpec.push(['ipv4_mask_size', 'writeUInt8', 1]);
MsgNetworkStateResp.prototype.fieldSpec.push(['ipv6_address', 'array', 'writeUInt8', function () { return 1; }, 16]);
MsgNetworkStateResp.prototype.fieldSpec.push(['ipv6_mask_size', 'writeUInt8', 1]);
MsgNetworkStateResp.prototype.fieldSpec.push(['rx_bytes', 'writeUInt32LE', 4]);
MsgNetworkStateResp.prototype.fieldSpec.push(['tx_bytes', 'writeUInt32LE', 4]);
MsgNetworkStateResp.prototype.fieldSpec.push(['interface_name', 'string', 16]);
MsgNetworkStateResp.prototype.fieldSpec.push(['flags', 'writeUInt32LE', 4]);

/**
 * SBP class for message fragment NetworkUsage
 *
 * The bandwidth usage for each interface can be reported within this struct and
 * utilize multiple fields to fully specify the type of traffic that is being
 * tracked. As either the interval of collection or the collection time may vary,
 * both a timestamp and period field is provided, though may not necessarily be
 * populated with a value.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field duration number (unsigned 64-bit int, 8 bytes) Duration over which the measurement was collected
 * @field total_bytes number (unsigned 64-bit int, 8 bytes) Number of bytes handled in total within period
 * @field rx_bytes number (unsigned 32-bit int, 4 bytes) Number of bytes transmitted within period
 * @field tx_bytes number (unsigned 32-bit int, 4 bytes) Number of bytes received within period
 * @field interface_name string Interface Name
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var NetworkUsage = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "NetworkUsage";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
NetworkUsage.prototype = Object.create(SBP.prototype);
NetworkUsage.prototype.messageType = "NetworkUsage";
NetworkUsage.prototype.constructor = NetworkUsage;
NetworkUsage.prototype.parser = new Parser()
  .endianess('little')
  .uint64('duration')
  .uint64('total_bytes')
  .uint32('rx_bytes')
  .uint32('tx_bytes')
  .string('interface_name', { length: 16 });
NetworkUsage.prototype.fieldSpec = [];
NetworkUsage.prototype.fieldSpec.push(['duration', 'writeUInt64LE', 8]);
NetworkUsage.prototype.fieldSpec.push(['total_bytes', 'writeUInt64LE', 8]);
NetworkUsage.prototype.fieldSpec.push(['rx_bytes', 'writeUInt32LE', 4]);
NetworkUsage.prototype.fieldSpec.push(['tx_bytes', 'writeUInt32LE', 4]);
NetworkUsage.prototype.fieldSpec.push(['interface_name', 'string', 16]);

/**
 * SBP class for message MSG_NETWORK_BANDWIDTH_USAGE (0x00BD).
 *
 * The bandwidth usage, a list of usage by interface.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field interfaces array Usage measurement array
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgNetworkBandwidthUsage = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_NETWORK_BANDWIDTH_USAGE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgNetworkBandwidthUsage.prototype = Object.create(SBP.prototype);
MsgNetworkBandwidthUsage.prototype.messageType = "MSG_NETWORK_BANDWIDTH_USAGE";
MsgNetworkBandwidthUsage.prototype.msg_type = 0x00BD;
MsgNetworkBandwidthUsage.prototype.constructor = MsgNetworkBandwidthUsage;
MsgNetworkBandwidthUsage.prototype.parser = new Parser()
  .endianess('little')
  .array('interfaces', { type: NetworkUsage.prototype.parser, readUntil: 'eof' });
MsgNetworkBandwidthUsage.prototype.fieldSpec = [];
MsgNetworkBandwidthUsage.prototype.fieldSpec.push(['interfaces', 'array', NetworkUsage.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

/**
 * SBP class for message MSG_CELL_MODEM_STATUS (0x00BE).
 *
 * If a cell modem is present on a piksi device, this message will be send
 * periodically to update the host on the status of the modem and its various
 * parameters.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field signal_strength number (signed 8-bit int, 1 byte) Received cell signal strength in dBm, zero translates to unknown
 * @field signal_error_rate number (float, 4 bytes) BER as reported by the modem, zero translates to unknown
 * @field reserved array Unspecified data TBD for this schema
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgCellModemStatus = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_CELL_MODEM_STATUS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgCellModemStatus.prototype = Object.create(SBP.prototype);
MsgCellModemStatus.prototype.messageType = "MSG_CELL_MODEM_STATUS";
MsgCellModemStatus.prototype.msg_type = 0x00BE;
MsgCellModemStatus.prototype.constructor = MsgCellModemStatus;
MsgCellModemStatus.prototype.parser = new Parser()
  .endianess('little')
  .int8('signal_strength')
  .floatle('signal_error_rate')
  .array('reserved', { type: 'uint8', readUntil: 'eof' });
MsgCellModemStatus.prototype.fieldSpec = [];
MsgCellModemStatus.prototype.fieldSpec.push(['signal_strength', 'writeInt8', 1]);
MsgCellModemStatus.prototype.fieldSpec.push(['signal_error_rate', 'writeFloatLE', 4]);
MsgCellModemStatus.prototype.fieldSpec.push(['reserved', 'array', 'writeUInt8', function () { return 1; }, null]);

/**
 * SBP class for message MSG_SPECAN_DEP (0x0050).
 *
 * Deprecated.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field channel_tag number (unsigned 16-bit int, 2 bytes) Channel ID
 * @field t GPSTimeDep Receiver time of this observation
 * @field freq_ref number (float, 4 bytes) Reference frequency of this packet
 * @field freq_step number (float, 4 bytes) Frequency step of points in this packet
 * @field amplitude_ref number (float, 4 bytes) Reference amplitude of this packet
 * @field amplitude_unit number (float, 4 bytes) Amplitude unit value of points in this packet
 * @field amplitude_value array Amplitude values (in the above units) of points in this packet
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSpecanDep = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SPECAN_DEP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSpecanDep.prototype = Object.create(SBP.prototype);
MsgSpecanDep.prototype.messageType = "MSG_SPECAN_DEP";
MsgSpecanDep.prototype.msg_type = 0x0050;
MsgSpecanDep.prototype.constructor = MsgSpecanDep;
MsgSpecanDep.prototype.parser = new Parser()
  .endianess('little')
  .uint16('channel_tag')
  .nest('t', { type: GPSTimeDep.prototype.parser })
  .floatle('freq_ref')
  .floatle('freq_step')
  .floatle('amplitude_ref')
  .floatle('amplitude_unit')
  .array('amplitude_value', { type: 'uint8', readUntil: 'eof' });
MsgSpecanDep.prototype.fieldSpec = [];
MsgSpecanDep.prototype.fieldSpec.push(['channel_tag', 'writeUInt16LE', 2]);
MsgSpecanDep.prototype.fieldSpec.push(['t', GPSTimeDep.prototype.fieldSpec]);
MsgSpecanDep.prototype.fieldSpec.push(['freq_ref', 'writeFloatLE', 4]);
MsgSpecanDep.prototype.fieldSpec.push(['freq_step', 'writeFloatLE', 4]);
MsgSpecanDep.prototype.fieldSpec.push(['amplitude_ref', 'writeFloatLE', 4]);
MsgSpecanDep.prototype.fieldSpec.push(['amplitude_unit', 'writeFloatLE', 4]);
MsgSpecanDep.prototype.fieldSpec.push(['amplitude_value', 'array', 'writeUInt8', function () { return 1; }, null]);

/**
 * SBP class for message MSG_SPECAN (0x0051).
 *
 * Spectrum analyzer packet.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field channel_tag number (unsigned 16-bit int, 2 bytes) Channel ID
 * @field t GPSTime Receiver time of this observation
 * @field freq_ref number (float, 4 bytes) Reference frequency of this packet
 * @field freq_step number (float, 4 bytes) Frequency step of points in this packet
 * @field amplitude_ref number (float, 4 bytes) Reference amplitude of this packet
 * @field amplitude_unit number (float, 4 bytes) Amplitude unit value of points in this packet
 * @field amplitude_value array Amplitude values (in the above units) of points in this packet
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSpecan = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SPECAN";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSpecan.prototype = Object.create(SBP.prototype);
MsgSpecan.prototype.messageType = "MSG_SPECAN";
MsgSpecan.prototype.msg_type = 0x0051;
MsgSpecan.prototype.constructor = MsgSpecan;
MsgSpecan.prototype.parser = new Parser()
  .endianess('little')
  .uint16('channel_tag')
  .nest('t', { type: GPSTime.prototype.parser })
  .floatle('freq_ref')
  .floatle('freq_step')
  .floatle('amplitude_ref')
  .floatle('amplitude_unit')
  .array('amplitude_value', { type: 'uint8', readUntil: 'eof' });
MsgSpecan.prototype.fieldSpec = [];
MsgSpecan.prototype.fieldSpec.push(['channel_tag', 'writeUInt16LE', 2]);
MsgSpecan.prototype.fieldSpec.push(['t', GPSTime.prototype.fieldSpec]);
MsgSpecan.prototype.fieldSpec.push(['freq_ref', 'writeFloatLE', 4]);
MsgSpecan.prototype.fieldSpec.push(['freq_step', 'writeFloatLE', 4]);
MsgSpecan.prototype.fieldSpec.push(['amplitude_ref', 'writeFloatLE', 4]);
MsgSpecan.prototype.fieldSpec.push(['amplitude_unit', 'writeFloatLE', 4]);
MsgSpecan.prototype.fieldSpec.push(['amplitude_value', 'array', 'writeUInt8', function () { return 1; }, null]);

/**
 * SBP class for message MSG_FRONT_END_GAIN (0x00BF).
 *
 * This message describes the gain of each channel in the receiver frontend. Each
 * gain is encoded as a non-dimensional percentage relative to the maximum range
 * possible for the gain stage of the frontend. By convention, each gain array  has
 * 8 entries and the index of the array corresponding to the index of the rf
 * channel  in the frontend. A gain of 127 percent encodes that rf channel is not
 * present in the hardware. A negative value implies an error for the particular
 * gain stage as reported by the frontend.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field rf_gain array RF gain for each frontend channel
 * @field if_gain array Intermediate frequency gain for each frontend channel
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgFrontEndGain = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_FRONT_END_GAIN";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgFrontEndGain.prototype = Object.create(SBP.prototype);
MsgFrontEndGain.prototype.messageType = "MSG_FRONT_END_GAIN";
MsgFrontEndGain.prototype.msg_type = 0x00BF;
MsgFrontEndGain.prototype.constructor = MsgFrontEndGain;
MsgFrontEndGain.prototype.parser = new Parser()
  .endianess('little')
  .array('rf_gain', { length: 8, type: 'int8' })
  .array('if_gain', { length: 8, type: 'int8' });
MsgFrontEndGain.prototype.fieldSpec = [];
MsgFrontEndGain.prototype.fieldSpec.push(['rf_gain', 'array', 'writeInt8', function () { return 1; }, 8]);
MsgFrontEndGain.prototype.fieldSpec.push(['if_gain', 'array', 'writeInt8', function () { return 1; }, 8]);

module.exports = {
  0x0069: MsgAlmanac,
  MsgAlmanac: MsgAlmanac,
  0x0068: MsgSetTime,
  MsgSetTime: MsgSetTime,
  0x00B6: MsgReset,
  MsgReset: MsgReset,
  0x00B2: MsgResetDep,
  MsgResetDep: MsgResetDep,
  0x00C0: MsgCwResults,
  MsgCwResults: MsgCwResults,
  0x00C1: MsgCwStart,
  MsgCwStart: MsgCwStart,
  0x0022: MsgResetFilters,
  MsgResetFilters: MsgResetFilters,
  0x0023: MsgInitBaseDep,
  MsgInitBaseDep: MsgInitBaseDep,
  0x0017: MsgThreadState,
  MsgThreadState: MsgThreadState,
  UARTChannel: UARTChannel,
  Period: Period,
  Latency: Latency,
  0x001D: MsgUartState,
  MsgUartState: MsgUartState,
  0x0018: MsgUartStateDepa,
  MsgUartStateDepa: MsgUartStateDepa,
  0x0019: MsgIarState,
  MsgIarState: MsgIarState,
  0x002B: MsgMaskSatellite,
  MsgMaskSatellite: MsgMaskSatellite,
  0x001B: MsgMaskSatelliteDep,
  MsgMaskSatelliteDep: MsgMaskSatelliteDep,
  0x00B5: MsgDeviceMonitor,
  MsgDeviceMonitor: MsgDeviceMonitor,
  0x00B8: MsgCommandReq,
  MsgCommandReq: MsgCommandReq,
  0x00B9: MsgCommandResp,
  MsgCommandResp: MsgCommandResp,
  0x00BC: MsgCommandOutput,
  MsgCommandOutput: MsgCommandOutput,
  0x00BA: MsgNetworkStateReq,
  MsgNetworkStateReq: MsgNetworkStateReq,
  0x00BB: MsgNetworkStateResp,
  MsgNetworkStateResp: MsgNetworkStateResp,
  NetworkUsage: NetworkUsage,
  0x00BD: MsgNetworkBandwidthUsage,
  MsgNetworkBandwidthUsage: MsgNetworkBandwidthUsage,
  0x00BE: MsgCellModemStatus,
  MsgCellModemStatus: MsgCellModemStatus,
  0x0050: MsgSpecanDep,
  MsgSpecanDep: MsgSpecanDep,
  0x0051: MsgSpecan,
  MsgSpecan: MsgSpecan,
  0x00BF: MsgFrontEndGain,
  MsgFrontEndGain: MsgFrontEndGain,
}