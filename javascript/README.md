# JavaScript SBP Bindings

## Installing from npm

`npm install libsbp`

## Building the JavaScript libsbp bindings

From the parent directory, run `make javascript` to regenerate bindings.

This library supports and is tested with NodeJS v0.10.x, v0.12.x, v4.x, and v5.x.

## Using the JavaScript libsbp bindings
You can include the `javascript/sbp` directory. Two objects are exported - `dispatch` and `decode`
(see `msg.js`). `dispatch` is used to connect to a stream of binary data and `decode` can be used
to parse individual binary messages.packets.

### Requirements
```
brew install nodejs
npm install -g mocha
```

### Examples
See `test_http_stream.js` for connecting an HTTP stream to the dispatcher.

See the minimal [JavaScript map console](https://github.com/JoshuaGross/piksi-console) for an example of connecting Piksi via USB and mapping points with Google Maps.
