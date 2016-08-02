/**
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Joshua Gross <josh@swift-nav.com>
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
var Parser = require('binary-parser').Parser;
var GnssSignal = require("./gnss_signal").GnssSignal;

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
 * SBP class for message MSG_RESET (0x00B2).
 *
 * This message from the host resets the Piksi back into the bootloader.
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
MsgReset.prototype.msg_type = 0x00B2;
MsgReset.prototype.constructor = MsgReset;
MsgReset.prototype.parser = new Parser()
  .endianess('little');
MsgReset.prototype.fieldSpec = [];

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
 * SBP class for message MSG_INIT_BASE (0x0023).
 *
 * This message initializes the integer ambiguity resolution (IAR) process on the
 * Piksi to use an assumed baseline position between the base station and rover
 * receivers. Warns via MSG_PRINT if there aren't a shared minimum number (4) of
 * satellite observations between the two.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgInitBase = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_INIT_BASE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgInitBase.prototype = Object.create(SBP.prototype);
MsgInitBase.prototype.messageType = "MSG_INIT_BASE";
MsgInitBase.prototype.msg_type = 0x0023;
MsgInitBase.prototype.constructor = MsgInitBase;
MsgInitBase.prototype.parser = new Parser()
  .endianess('little');
MsgInitBase.prototype.fieldSpec = [];

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
MsgThreadState.prototype.fieldSpec.push(['name', 'string']);
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
 * Observations latency and period can be used to assess the  health of the
 * differential corrections link. Latency provides the timeliness of received base
 * observations while the  period indicates their likelihood of transmission.
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
 * SBP class for message MSG_MASK_SATELLITE (0x001B).
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
MsgMaskSatellite.prototype.msg_type = 0x001B;
MsgMaskSatellite.prototype.constructor = MsgMaskSatellite;
MsgMaskSatellite.prototype.parser = new Parser()
  .endianess('little')
  .uint8('mask')
  .nest('sid', { type: GnssSignal.prototype.parser });
MsgMaskSatellite.prototype.fieldSpec = [];
MsgMaskSatellite.prototype.fieldSpec.push(['mask', 'writeUInt8', 1]);
MsgMaskSatellite.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);

module.exports = {
  0x0069: MsgAlmanac,
  MsgAlmanac: MsgAlmanac,
  0x0068: MsgSetTime,
  MsgSetTime: MsgSetTime,
  0x00B2: MsgReset,
  MsgReset: MsgReset,
  0x00C0: MsgCwResults,
  MsgCwResults: MsgCwResults,
  0x00C1: MsgCwStart,
  MsgCwStart: MsgCwStart,
  0x0022: MsgResetFilters,
  MsgResetFilters: MsgResetFilters,
  0x0023: MsgInitBase,
  MsgInitBase: MsgInitBase,
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
  0x001B: MsgMaskSatellite,
  MsgMaskSatellite: MsgMaskSatellite,
}