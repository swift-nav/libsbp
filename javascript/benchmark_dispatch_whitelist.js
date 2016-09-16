// Benchmark how much time is saved in dispatch by ignoring some messages (in this case half)
var Benchmark = require('benchmark');
var stream = require('stream');
var path = require('path');

var dispatch = require(path.resolve(__dirname, './sbp/')).dispatch;
var MsgPosLlh = require(path.resolve(__dirname, './sbp/navigation')).MsgPosLlh;

var suite = new Benchmark.Suite();
var Readable = stream.Readable;

var msgLlhPayload = new Buffer('VQEC9tciFC4nAPod4rrrtkJAE8szxBiLXsAfnaDoenNRQAAAAAAJAOyL', 'base64');
var msgVelEcefPayload = new Buffer('VQQC9tcUFC4nANoLAACG9f//o/z//wAACQBQ7A==', 'base64');

function runDispatch (whitelist, deferred) {
  var rs = new Readable();
  rs.push(msgVelEcefPayload);
  rs.push(msgLlhPayload);
  rs.push(null);

  var callbacks = 0;
  dispatch(rs, whitelist, function (err, framedMessage) {
    callbacks++;
    if (whitelist && callbacks === 1) {
      deferred.resolve();
    } else if (!whitelist && callbacks === 2) {
      deferred.resolve();
    }
  });
}

suite.add('dispatch without whitelist', {
  defer: true,
  fn: function (deferred) {
    runDispatch(undefined, deferred);
  }
}).add('dispatch with whitelist', {
  defer: true,
  fn: function (deferred) {
    runDispatch([MsgPosLlh.prototype.msg_type], deferred);
  }
}).on('cycle', function (event) {
  console.log(String(event.target));
}).on('complete', function () {
  console.log('Fastest is ' + this.filter('fastest').map('name'));
}).run({ async: false });
