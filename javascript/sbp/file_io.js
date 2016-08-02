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
 * Automatically generated from piksi/yaml/swiftnav/sbp/file_io.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Messages for using device's onboard flash filesystem functionality. This allows
 * data to be stored persistently in the device's program flash with wear-levelling
 * using a simple filesystem interface. The file system interface (CFS) defines an
 * abstract API for reading directories and for reading and writing files.  Note
 * that some of these messages share the same message type ID for both the host
 * request and the device response.
***********************/

var SBP = require('./sbp');
var Parser = require('binary-parser').Parser;

/**
 * SBP class for message MSG_FILEIO_READ_REQ (0x00A8).
 *
 * The file read message reads a certain length (up to 255 bytes) from a given
 * offset into a file, and returns the data in a MSG_FILEIO_READ_RESP message where
 * the message length field indicates how many bytes were succesfully read.The
 * sequence number in the request will be returned in the response. If the message
 * is invalid, a followup MSG_PRINT message will print "Invalid fileio read
 * message". A device will only respond to this message when it is received from
 * sender ID 0x42.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sequence number (unsigned 32-bit int, 4 bytes) Read sequence number
 * @field offset number (unsigned 32-bit int, 4 bytes) File offset
 * @field chunk_size number (unsigned 8-bit int, 1 byte) Chunk size to read
 * @field filename string Name of the file to read from
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgFileioReadReq = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_FILEIO_READ_REQ";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgFileioReadReq.prototype = Object.create(SBP.prototype);
MsgFileioReadReq.prototype.messageType = "MSG_FILEIO_READ_REQ";
MsgFileioReadReq.prototype.msg_type = 0x00A8;
MsgFileioReadReq.prototype.constructor = MsgFileioReadReq;
MsgFileioReadReq.prototype.parser = new Parser()
  .endianess('little')
  .uint32('sequence')
  .uint32('offset')
  .uint8('chunk_size')
  .string('filename', { greedy: true });
MsgFileioReadReq.prototype.fieldSpec = [];
MsgFileioReadReq.prototype.fieldSpec.push(['sequence', 'writeUInt32LE', 4]);
MsgFileioReadReq.prototype.fieldSpec.push(['offset', 'writeUInt32LE', 4]);
MsgFileioReadReq.prototype.fieldSpec.push(['chunk_size', 'writeUInt8', 1]);
MsgFileioReadReq.prototype.fieldSpec.push(['filename', 'string']);

/**
 * SBP class for message MSG_FILEIO_READ_RESP (0x00A3).
 *
 * The file read message reads a certain length (up to 255 bytes) from a given
 * offset into a file, and returns the data in a message where the message length
 * field indicates how many bytes were succesfully read. The sequence number in the
 * response is preserved from the request.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sequence number (unsigned 32-bit int, 4 bytes) Read sequence number
 * @field contents array Contents of read file
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgFileioReadResp = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_FILEIO_READ_RESP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgFileioReadResp.prototype = Object.create(SBP.prototype);
MsgFileioReadResp.prototype.messageType = "MSG_FILEIO_READ_RESP";
MsgFileioReadResp.prototype.msg_type = 0x00A3;
MsgFileioReadResp.prototype.constructor = MsgFileioReadResp;
MsgFileioReadResp.prototype.parser = new Parser()
  .endianess('little')
  .uint32('sequence')
  .array('contents', { type: 'uint8', readUntil: 'eof' });
MsgFileioReadResp.prototype.fieldSpec = [];
MsgFileioReadResp.prototype.fieldSpec.push(['sequence', 'writeUInt32LE', 4]);
MsgFileioReadResp.prototype.fieldSpec.push(['contents', 'array', 'writeUInt8', function () { return 1; }]);

/**
 * SBP class for message MSG_FILEIO_READ_DIR_REQ (0x00A9).
 *
 * The read directory message lists the files in a directory on the device's
 * onboard flash file system.  The offset parameter can be used to skip the first n
 * elements of the file list. Returns a MSG_FILEIO_READ_DIR_RESP message containing
 * the directory listings as a NULL delimited list. The listing is chunked over
 * multiple SBP packets. The sequence number in the request will be returned in the
 * response.  If message is invalid, a followup MSG_PRINT message will print
 * "Invalid fileio read message". A device will only respond to this message when
 * it is received from sender ID 0x42.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sequence number (unsigned 32-bit int, 4 bytes) Read sequence number
 * @field offset number (unsigned 32-bit int, 4 bytes) The offset to skip the first n elements of the file list
 * @field dirname string Name of the directory to list
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgFileioReadDirReq = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_FILEIO_READ_DIR_REQ";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgFileioReadDirReq.prototype = Object.create(SBP.prototype);
MsgFileioReadDirReq.prototype.messageType = "MSG_FILEIO_READ_DIR_REQ";
MsgFileioReadDirReq.prototype.msg_type = 0x00A9;
MsgFileioReadDirReq.prototype.constructor = MsgFileioReadDirReq;
MsgFileioReadDirReq.prototype.parser = new Parser()
  .endianess('little')
  .uint32('sequence')
  .uint32('offset')
  .string('dirname', { greedy: true });
MsgFileioReadDirReq.prototype.fieldSpec = [];
MsgFileioReadDirReq.prototype.fieldSpec.push(['sequence', 'writeUInt32LE', 4]);
MsgFileioReadDirReq.prototype.fieldSpec.push(['offset', 'writeUInt32LE', 4]);
MsgFileioReadDirReq.prototype.fieldSpec.push(['dirname', 'string']);

/**
 * SBP class for message MSG_FILEIO_READ_DIR_RESP (0x00AA).
 *
 * The read directory message lists the files in a directory on the device's
 * onboard flash file system. Message contains the directory listings as a NULL
 * delimited list. The listing is chunked over multiple SBP packets and the end of
 * the list is identified by an entry containing just the character 0xFF. The
 * sequence number in the response is preserved from the request.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sequence number (unsigned 32-bit int, 4 bytes) Read sequence number
 * @field contents array Contents of read directory
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgFileioReadDirResp = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_FILEIO_READ_DIR_RESP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgFileioReadDirResp.prototype = Object.create(SBP.prototype);
MsgFileioReadDirResp.prototype.messageType = "MSG_FILEIO_READ_DIR_RESP";
MsgFileioReadDirResp.prototype.msg_type = 0x00AA;
MsgFileioReadDirResp.prototype.constructor = MsgFileioReadDirResp;
MsgFileioReadDirResp.prototype.parser = new Parser()
  .endianess('little')
  .uint32('sequence')
  .array('contents', { type: 'uint8', readUntil: 'eof' });
MsgFileioReadDirResp.prototype.fieldSpec = [];
MsgFileioReadDirResp.prototype.fieldSpec.push(['sequence', 'writeUInt32LE', 4]);
MsgFileioReadDirResp.prototype.fieldSpec.push(['contents', 'array', 'writeUInt8', function () { return 1; }]);

/**
 * SBP class for message MSG_FILEIO_REMOVE (0x00AC).
 *
 * The file remove message deletes a file from the file system. If the message is
 * invalid, a followup MSG_PRINT message will print "Invalid fileio remove
 * message". A device will only process this message when it is received from
 * sender ID 0x42.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field filename string Name of the file to delete
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgFileioRemove = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_FILEIO_REMOVE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgFileioRemove.prototype = Object.create(SBP.prototype);
MsgFileioRemove.prototype.messageType = "MSG_FILEIO_REMOVE";
MsgFileioRemove.prototype.msg_type = 0x00AC;
MsgFileioRemove.prototype.constructor = MsgFileioRemove;
MsgFileioRemove.prototype.parser = new Parser()
  .endianess('little')
  .string('filename', { greedy: true });
MsgFileioRemove.prototype.fieldSpec = [];
MsgFileioRemove.prototype.fieldSpec.push(['filename', 'string']);

/**
 * SBP class for message MSG_FILEIO_WRITE_REQ (0x00AD).
 *
 * The file write message writes a certain length (up to 255 bytes) of data to a
 * file at a given offset. Returns a copy of the original MSG_FILEIO_WRITE_RESP
 * message to check integrity of the write. The sequence number in the request will
 * be returned in the response. If message is invalid, a followup MSG_PRINT message
 * will print "Invalid fileio write message". A device will only  process this
 * message when it is received from sender ID 0x42.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sequence number (unsigned 32-bit int, 4 bytes) Write sequence number
 * @field offset number (unsigned 32-bit int, 4 bytes) Offset into the file at which to start writing in bytes
 * @field filename string Name of the file to write to
 * @field data array Variable-length array of data to write
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgFileioWriteReq = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_FILEIO_WRITE_REQ";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgFileioWriteReq.prototype = Object.create(SBP.prototype);
MsgFileioWriteReq.prototype.messageType = "MSG_FILEIO_WRITE_REQ";
MsgFileioWriteReq.prototype.msg_type = 0x00AD;
MsgFileioWriteReq.prototype.constructor = MsgFileioWriteReq;
MsgFileioWriteReq.prototype.parser = new Parser()
  .endianess('little')
  .uint32('sequence')
  .uint32('offset')
  .string('filename', { greedy: true })
  .array('data', { type: 'uint8', readUntil: 'eof' });
MsgFileioWriteReq.prototype.fieldSpec = [];
MsgFileioWriteReq.prototype.fieldSpec.push(['sequence', 'writeUInt32LE', 4]);
MsgFileioWriteReq.prototype.fieldSpec.push(['offset', 'writeUInt32LE', 4]);
MsgFileioWriteReq.prototype.fieldSpec.push(['filename', 'string']);
MsgFileioWriteReq.prototype.fieldSpec.push(['data', 'array', 'writeUInt8', function () { return 1; }]);

/**
 * SBP class for message MSG_FILEIO_WRITE_RESP (0x00AB).
 *
 * The file write message writes a certain length (up to 255 bytes) of data to a
 * file at a given offset. The message is a copy of the original
 * MSG_FILEIO_WRITE_REQ message to check integrity of the write. The sequence
 * number in the response is preserved from the request.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sequence number (unsigned 32-bit int, 4 bytes) Write sequence number
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgFileioWriteResp = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_FILEIO_WRITE_RESP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgFileioWriteResp.prototype = Object.create(SBP.prototype);
MsgFileioWriteResp.prototype.messageType = "MSG_FILEIO_WRITE_RESP";
MsgFileioWriteResp.prototype.msg_type = 0x00AB;
MsgFileioWriteResp.prototype.constructor = MsgFileioWriteResp;
MsgFileioWriteResp.prototype.parser = new Parser()
  .endianess('little')
  .uint32('sequence');
MsgFileioWriteResp.prototype.fieldSpec = [];
MsgFileioWriteResp.prototype.fieldSpec.push(['sequence', 'writeUInt32LE', 4]);

module.exports = {
  0x00A8: MsgFileioReadReq,
  MsgFileioReadReq: MsgFileioReadReq,
  0x00A3: MsgFileioReadResp,
  MsgFileioReadResp: MsgFileioReadResp,
  0x00A9: MsgFileioReadDirReq,
  MsgFileioReadDirReq: MsgFileioReadDirReq,
  0x00AA: MsgFileioReadDirResp,
  MsgFileioReadDirResp: MsgFileioReadDirResp,
  0x00AC: MsgFileioRemove,
  MsgFileioRemove: MsgFileioRemove,
  0x00AD: MsgFileioWriteReq,
  MsgFileioWriteReq: MsgFileioWriteReq,
  0x00AB: MsgFileioWriteResp,
  MsgFileioWriteResp: MsgFileioWriteResp,
}