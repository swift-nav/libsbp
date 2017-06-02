const path = require('path');

module.exports = {
  entry: path.resolve(__dirname, './sbp/msg.js'),
  output: {
    path: path.resolve(__dirname),
    filename: 'sbp.bundle.js'
  }
};
