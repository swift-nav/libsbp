/**
 * Test decoding bytes coming from an HTTP stream.
 */

var path = require('path');
var dispatch = require(path.resolve(__dirname, './sbp/')).dispatch;
var request = require('request');

// Message construction
var constructMsg = require(path.resolve(__dirname, './sbp/construct'));
var sbpPiksi = require(path.resolve(__dirname, './sbp/piksi'));
var MsgReset = sbpPiksi.MsgReset;

// Change this to a valid piksi serial port path.
var serial = '/dev/cu.usbserial-00001014';

var piksi = request('http://localhost:7770');

console.log('Opened piksi.');

dispatch(piksi, function (err, framedMsg) {
  console.log('Message from piksi:', err, framedMsg.messageType, framedMsg);
});

