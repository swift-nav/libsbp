var got = require('got');
var dispatch = require('./sbp').dispatch;
var PassThrough = require('stream').PassThrough;

var options = {
  url: 'http://broker.testing.skylark.swiftnav.com',
  headers: {
    'Device-Uid': 'cb781db1-8e5f-5a65-980a-fef75f4b6519',
    'Accept': 'application/vnd.swiftnav.broker.v1+sbp2'
  }
};

var rs = new PassThrough();
got.stream.get(options.url, { headers: options.headers }).pipe(rs);

dispatch(rs, function (err, framedMsg) {
  console.log(framedMsg);
});
