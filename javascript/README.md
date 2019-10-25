# JavaScript SBP Bindings

## Installing from npm

`npm install sbp`

## Building the JavaScript sbp bindings

From the parent directory, run `make javascript` to regenerate bindings.

This library supports and is tested with NodeJS v0.10.x, v0.12.x, v4.x, and v5.x.

## Using the JavaScript sbp bindings
You can include the `javascript/sbp` directory. Two objects are exported - `dispatch` and `decode`
(see `msg.js`). `dispatch` is used to connect to a stream of binary data and `decode` can be used
to parse individual binary messages.packets.

### Requirements
```
pip install tox
brew install nodejs
npm install -g mocha
```

### Examples
See `test_http_stream.js` for connecting an HTTP stream to the dispatcher.

See the minimal [JavaScript map console](https://github.com/JoshuaGross/piksi-console) for an example of connecting Piksi via USB and mapping points with Google Maps.

## JSON schema definitions

Some web clients process SBP that's been converted to JSON (via the sbp2json
tool).  To aide in building various web clients, we generate JSON schema
definitions to parse the output of sbp2json. This allows web clients to
dispatch on the msg_type field in a JSON dictionary and build a fully native
object using the JSON fields that are present.

For example, in JavaScript, this is be possible:

```js

import { Convert, MsgVelNED} from "./SbpJson";

const json = getJsonBlob();

if (json['msg_type'] === 529) {
    const msgVelNED = Convert.toMsgVelNED(json);
    // ... do stuff with msgVelNED
}
```

The value of this is more fully realized when using a typed language like
TypeScript or Elm.  Fully native objects allow TypeScript and Elm to
type check interactions with the output from sbp2json.
