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
  });

  setTimeout(function () {
    console.log('Sending a MSG_RESET');

    var msgBytes = constructMsg(MsgReset, {}).toBuffer();

    piksi.write(msgBytes, function () {
      console.log('wrote bytes', msgBytes, arguments);
    });
  }, 1000);
});
