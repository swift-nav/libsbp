/**
 * To run this, install node-serialport globally: `npm install -g serialport`
 */

var SerialPort = require('serialport');
var path = require('path');
var dispatch = require(path.resolve(__dirname, './sbp/')).dispatch;

// Message construction
var constructMsg = require(path.resolve(__dirname, './sbp/construct'));
var sbpPiksi = require(path.resolve(__dirname, './sbp/piksi'));
var MsgReset = sbpPiksi.MsgReset;
var sbpSettings = require(path.resolve(__dirname, './sbp/settings'));
var MsgSettingsReadReq = sbpSettings.MsgSettingsReadReq;
var MsgSettingsReadResp = sbpSettings.MsgSettingsReadResp;

// Change this to a valid piksi serial port path.
var serial = '/dev/cu.usbserial-00002014';

var piksi = new SerialPort(serial, {
  //baudrate: 115200 // serial or uart
  baudrate: 1000000 // USB
});

piksi.on('open', function () {
  console.log('Opened piksi.');

  dispatch(piksi, function (err, framedMsg) {
    console.log('Message from piksi:', err, framedMsg.messageType);

    if (framedMsg.messageType == MsgSettingsReadResp.prototype.messageType) {
      console.log('Settings response:', framedMsg);
    }
  });

  setTimeout(function () {
    console.log('Sending a MSG_SETTINGS_READ_REQ');

    var msgBytes = constructMsg(MsgSettingsReadReq, {"setting": "simulator\0enabled\0"}, 0x42).toBuffer();

    piksi.write(msgBytes, function () {
      console.log('wrote bytes', msgBytes, arguments);
    });
  }, 1000);
});
