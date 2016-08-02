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
 * Automatically generated from piksi/yaml/swiftnav/sbp/flash.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Messages for reading/writing the device's onboard flash memory. Many of these
 * messages target specific flash memory peripherals used in Swift Navigation
 * devices: the STM32 flash and the M25Pxx FPGA configuration flash.
***********************/

var SBP = require('./sbp');
var Parser = require('binary-parser').Parser;

/**
 * SBP class for message MSG_FLASH_PROGRAM (0x00E6).
 *
 * The flash program message programs a set of addresses of either the STM or M25
 * flash. The device replies with either a MSG_FLASH_DONE message containing the
 * return code FLASH_OK (0) on success, or FLASH_INVALID_LEN (2) if the maximum
 * write size is exceeded. Note that the sector-containing addresses must be erased
 * before addresses can be programmed.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field target number (unsigned 8-bit int, 1 byte) Target flags
 * @field addr_start array Starting address offset to program
 * @field addr_len number (unsigned 8-bit int, 1 byte) Length of set of addresses to program, counting up from starting address
 * @field data array Data to program addresses with, with length N=addr_len
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgFlashProgram = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_FLASH_PROGRAM";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgFlashProgram.prototype = Object.create(SBP.prototype);
MsgFlashProgram.prototype.messageType = "MSG_FLASH_PROGRAM";
MsgFlashProgram.prototype.msg_type = 0x00E6;
MsgFlashProgram.prototype.constructor = MsgFlashProgram;
MsgFlashProgram.prototype.parser = new Parser()
  .endianess('little')
  .uint8('target')
  .array('addr_start', { length: 3, type: 'uint8' })
  .uint8('addr_len')
  .array('data', { type: 'uint8', length: 'addr_len' });
MsgFlashProgram.prototype.fieldSpec = [];
MsgFlashProgram.prototype.fieldSpec.push(['target', 'writeUInt8', 1]);
MsgFlashProgram.prototype.fieldSpec.push(['addr_start', 'array', 'writeUInt8', function () { return 1; }]);
MsgFlashProgram.prototype.fieldSpec.push(['addr_len', 'writeUInt8', 1]);
MsgFlashProgram.prototype.fieldSpec.push(['data', 'array', 'writeUInt8', function () { return 1; }]);

/**
 * SBP class for message MSG_FLASH_DONE (0x00E0).
 *
 * This message defines success or failure codes for a variety of flash memory
 * requests from the host to the device. Flash read and write messages, such as
 * MSG_FLASH_READ_REQ, or MSG_FLASH_PROGRAM, may return this message on failure.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field response number (unsigned 8-bit int, 1 byte) Response flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgFlashDone = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_FLASH_DONE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgFlashDone.prototype = Object.create(SBP.prototype);
MsgFlashDone.prototype.messageType = "MSG_FLASH_DONE";
MsgFlashDone.prototype.msg_type = 0x00E0;
MsgFlashDone.prototype.constructor = MsgFlashDone;
MsgFlashDone.prototype.parser = new Parser()
  .endianess('little')
  .uint8('response');
MsgFlashDone.prototype.fieldSpec = [];
MsgFlashDone.prototype.fieldSpec.push(['response', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_FLASH_READ_REQ (0x00E7).
 *
 * The flash read message reads a set of addresses of either the STM or M25 onboard
 * flash. The device replies with a MSG_FLASH_READ_RESP message containing either
 * the read data on success or a MSG_FLASH_DONE message containing the return code
 * FLASH_INVALID_LEN (2) if the maximum read size is exceeded or FLASH_INVALID_ADDR
 * (3) if the address is outside of the allowed range.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field target number (unsigned 8-bit int, 1 byte) Target flags
 * @field addr_start array Starting address offset to read from
 * @field addr_len number (unsigned 8-bit int, 1 byte) Length of set of addresses to read, counting up from starting address
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgFlashReadReq = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_FLASH_READ_REQ";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgFlashReadReq.prototype = Object.create(SBP.prototype);
MsgFlashReadReq.prototype.messageType = "MSG_FLASH_READ_REQ";
MsgFlashReadReq.prototype.msg_type = 0x00E7;
MsgFlashReadReq.prototype.constructor = MsgFlashReadReq;
MsgFlashReadReq.prototype.parser = new Parser()
  .endianess('little')
  .uint8('target')
  .array('addr_start', { length: 3, type: 'uint8' })
  .uint8('addr_len');
MsgFlashReadReq.prototype.fieldSpec = [];
MsgFlashReadReq.prototype.fieldSpec.push(['target', 'writeUInt8', 1]);
MsgFlashReadReq.prototype.fieldSpec.push(['addr_start', 'array', 'writeUInt8', function () { return 1; }]);
MsgFlashReadReq.prototype.fieldSpec.push(['addr_len', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_FLASH_READ_RESP (0x00E1).
 *
 * The flash read message reads a set of addresses of either the STM or M25 onboard
 * flash. The device replies with a MSG_FLASH_READ_RESP message containing either
 * the read data on success or a MSG_FLASH_DONE message containing the return code
 * FLASH_INVALID_LEN (2) if the maximum read size is exceeded or FLASH_INVALID_ADDR
 * (3) if the address is outside of the allowed range.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field target number (unsigned 8-bit int, 1 byte) Target flags
 * @field addr_start array Starting address offset to read from
 * @field addr_len number (unsigned 8-bit int, 1 byte) Length of set of addresses to read, counting up from starting address
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgFlashReadResp = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_FLASH_READ_RESP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgFlashReadResp.prototype = Object.create(SBP.prototype);
MsgFlashReadResp.prototype.messageType = "MSG_FLASH_READ_RESP";
MsgFlashReadResp.prototype.msg_type = 0x00E1;
MsgFlashReadResp.prototype.constructor = MsgFlashReadResp;
MsgFlashReadResp.prototype.parser = new Parser()
  .endianess('little')
  .uint8('target')
  .array('addr_start', { length: 3, type: 'uint8' })
  .uint8('addr_len');
MsgFlashReadResp.prototype.fieldSpec = [];
MsgFlashReadResp.prototype.fieldSpec.push(['target', 'writeUInt8', 1]);
MsgFlashReadResp.prototype.fieldSpec.push(['addr_start', 'array', 'writeUInt8', function () { return 1; }]);
MsgFlashReadResp.prototype.fieldSpec.push(['addr_len', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_FLASH_ERASE (0x00E2).
 *
 * The flash erase message from the host erases a sector of either the STM or M25
 * onboard flash memory. The device will reply with a MSG_FLASH_DONE message
 * containing the return code - FLASH_OK (0) on success or FLASH_INVALID_FLASH (1)
 * if the flash specified is invalid.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field target number (unsigned 8-bit int, 1 byte) Target flags
 * @field sector_num number (unsigned 32-bit int, 4 bytes) Flash sector number to erase (0-11 for the STM, 0-15 for the M25)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgFlashErase = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_FLASH_ERASE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgFlashErase.prototype = Object.create(SBP.prototype);
MsgFlashErase.prototype.messageType = "MSG_FLASH_ERASE";
MsgFlashErase.prototype.msg_type = 0x00E2;
MsgFlashErase.prototype.constructor = MsgFlashErase;
MsgFlashErase.prototype.parser = new Parser()
  .endianess('little')
  .uint8('target')
  .uint32('sector_num');
MsgFlashErase.prototype.fieldSpec = [];
MsgFlashErase.prototype.fieldSpec.push(['target', 'writeUInt8', 1]);
MsgFlashErase.prototype.fieldSpec.push(['sector_num', 'writeUInt32LE', 4]);

/**
 * SBP class for message MSG_STM_FLASH_LOCK_SECTOR (0x00E3).
 *
 * The flash lock message locks a sector of the STM flash memory. The device
 * replies with a MSG_FLASH_DONE message.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sector number (unsigned 32-bit int, 4 bytes) Flash sector number to lock
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgStmFlashLockSector = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_STM_FLASH_LOCK_SECTOR";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgStmFlashLockSector.prototype = Object.create(SBP.prototype);
MsgStmFlashLockSector.prototype.messageType = "MSG_STM_FLASH_LOCK_SECTOR";
MsgStmFlashLockSector.prototype.msg_type = 0x00E3;
MsgStmFlashLockSector.prototype.constructor = MsgStmFlashLockSector;
MsgStmFlashLockSector.prototype.parser = new Parser()
  .endianess('little')
  .uint32('sector');
MsgStmFlashLockSector.prototype.fieldSpec = [];
MsgStmFlashLockSector.prototype.fieldSpec.push(['sector', 'writeUInt32LE', 4]);

/**
 * SBP class for message MSG_STM_FLASH_UNLOCK_SECTOR (0x00E4).
 *
 * The flash unlock message unlocks a sector of the STM flash memory. The device
 * replies with a MSG_FLASH_DONE message.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sector number (unsigned 32-bit int, 4 bytes) Flash sector number to unlock
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgStmFlashUnlockSector = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_STM_FLASH_UNLOCK_SECTOR";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgStmFlashUnlockSector.prototype = Object.create(SBP.prototype);
MsgStmFlashUnlockSector.prototype.messageType = "MSG_STM_FLASH_UNLOCK_SECTOR";
MsgStmFlashUnlockSector.prototype.msg_type = 0x00E4;
MsgStmFlashUnlockSector.prototype.constructor = MsgStmFlashUnlockSector;
MsgStmFlashUnlockSector.prototype.parser = new Parser()
  .endianess('little')
  .uint32('sector');
MsgStmFlashUnlockSector.prototype.fieldSpec = [];
MsgStmFlashUnlockSector.prototype.fieldSpec.push(['sector', 'writeUInt32LE', 4]);

/**
 * SBP class for message MSG_STM_UNIQUE_ID_REQ (0x00E8).
 *
 * This message reads the device's hardcoded unique ID. The host requests the ID by
 * sending a MSG_STM_UNIQUE_ID_REQ. The device responds with a
 * MSG_STM_UNIQUE_ID_RESP with the 12-byte unique ID in the payload.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgStmUniqueIdReq = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_STM_UNIQUE_ID_REQ";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgStmUniqueIdReq.prototype = Object.create(SBP.prototype);
MsgStmUniqueIdReq.prototype.messageType = "MSG_STM_UNIQUE_ID_REQ";
MsgStmUniqueIdReq.prototype.msg_type = 0x00E8;
MsgStmUniqueIdReq.prototype.constructor = MsgStmUniqueIdReq;
MsgStmUniqueIdReq.prototype.parser = new Parser()
  .endianess('little');
MsgStmUniqueIdReq.prototype.fieldSpec = [];

/**
 * SBP class for message MSG_STM_UNIQUE_ID_RESP (0x00E5).
 *
 * This message reads the device's hardcoded unique ID. The host requests the ID by
 * sending a MSG_STM_UNIQUE_ID_REQ. The device responds with a
 * MSG_STM_UNIQUE_ID_RESP with the 12-byte unique ID in the payload..
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field stm_id array Device unique ID
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgStmUniqueIdResp = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_STM_UNIQUE_ID_RESP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgStmUniqueIdResp.prototype = Object.create(SBP.prototype);
MsgStmUniqueIdResp.prototype.messageType = "MSG_STM_UNIQUE_ID_RESP";
MsgStmUniqueIdResp.prototype.msg_type = 0x00E5;
MsgStmUniqueIdResp.prototype.constructor = MsgStmUniqueIdResp;
MsgStmUniqueIdResp.prototype.parser = new Parser()
  .endianess('little')
  .array('stm_id', { length: 12, type: 'uint8' });
MsgStmUniqueIdResp.prototype.fieldSpec = [];
MsgStmUniqueIdResp.prototype.fieldSpec.push(['stm_id', 'array', 'writeUInt8', function () { return 1; }]);

/**
 * SBP class for message MSG_M25_FLASH_WRITE_STATUS (0x00F3).
 *
 * The flash status message writes to the 8-bit M25 flash status register. The
 * device replies with a MSG_FLASH_DONE message.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field status array Byte to write to the M25 flash status register
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgM25FlashWriteStatus = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_M25_FLASH_WRITE_STATUS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgM25FlashWriteStatus.prototype = Object.create(SBP.prototype);
MsgM25FlashWriteStatus.prototype.messageType = "MSG_M25_FLASH_WRITE_STATUS";
MsgM25FlashWriteStatus.prototype.msg_type = 0x00F3;
MsgM25FlashWriteStatus.prototype.constructor = MsgM25FlashWriteStatus;
MsgM25FlashWriteStatus.prototype.parser = new Parser()
  .endianess('little')
  .array('status', { length: 1, type: 'uint8' });
MsgM25FlashWriteStatus.prototype.fieldSpec = [];
MsgM25FlashWriteStatus.prototype.fieldSpec.push(['status', 'array', 'writeUInt8', function () { return 1; }]);

module.exports = {
  0x00E6: MsgFlashProgram,
  MsgFlashProgram: MsgFlashProgram,
  0x00E0: MsgFlashDone,
  MsgFlashDone: MsgFlashDone,
  0x00E7: MsgFlashReadReq,
  MsgFlashReadReq: MsgFlashReadReq,
  0x00E1: MsgFlashReadResp,
  MsgFlashReadResp: MsgFlashReadResp,
  0x00E2: MsgFlashErase,
  MsgFlashErase: MsgFlashErase,
  0x00E3: MsgStmFlashLockSector,
  MsgStmFlashLockSector: MsgStmFlashLockSector,
  0x00E4: MsgStmFlashUnlockSector,
  MsgStmFlashUnlockSector: MsgStmFlashUnlockSector,
  0x00E8: MsgStmUniqueIdReq,
  MsgStmUniqueIdReq: MsgStmUniqueIdReq,
  0x00E5: MsgStmUniqueIdResp,
  MsgStmUniqueIdResp: MsgStmUniqueIdResp,
  0x00F3: MsgM25FlashWriteStatus,
  MsgM25FlashWriteStatus: MsgM25FlashWriteStatus,
}