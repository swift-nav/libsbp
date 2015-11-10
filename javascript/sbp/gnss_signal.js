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
 * Automatically generated from piksi/yaml/swiftnav/sbp/gnss_signal.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Struct to represent a signal (constellation, band, satellite identifier)
***********************/

var SBP = require('./sbp');
var Parser = require('binary-parser').Parser;

/**
 * SBP class for message fragment SBPGnssSignal
 *
 * Signal identifier containing constellation, band, and satellite identifier
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sat number (unsigned 16-bit int, 2 bytes) Constellation-specific satellite identifier
 * @field band number (unsigned 8-bit int, 1 byte) Signal band
 * @field constellation number (unsigned 8-bit int, 1 byte) Constellation to which the satellite belongs
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var SBPGnssSignal = function (sbp) {
  SBP.call(this, sbp);
  this.messageType = "SBPGnssSignal";
  this.fields = this.parser.parse(sbp.payload);

  return this;
};
SBPGnssSignal.prototype = Object.create(SBP.prototype);
SBPGnssSignal.prototype.constructor = SBPGnssSignal;
SBPGnssSignal.prototype.parser = new Parser()
  .endianess('little')
  .uint16('sat')
  .uint8('band')
  .uint8('constellation');
SBPGnssSignal.prototype.fieldSpec = [];
SBPGnssSignal.prototype.fieldSpec.push(['sat', 'writeUInt16LE', 2]);
SBPGnssSignal.prototype.fieldSpec.push(['band', 'writeUInt8', 1]);
SBPGnssSignal.prototype.fieldSpec.push(['constellation', 'writeUInt8', 1]);

module.exports = {
  SBPGnssSignal: SBPGnssSignal,
}