# SBP JSON Comprehension Libraries

We have several tools that produce a representation of SBP in JSON format.
Particularly, we have a native binary tool `sbp2json`, which is released as
cross platform binaries (for example, see the "assets" of the [libsbp 3.4.7
release][1]).  Also, since this tool is Rust based, it can be [compiled][2]
and utilized on any platform that Rust supports.

[1]: https://github.com/swift-nav/libsbp/releases/v3.4.7
[2]: https://github.com/swift-nav/libsbp/tree/master/rust

For other platforms, we have a Python version of the `sbp2json` tool, which
allows a user to simply run `pip3 install sbp` on any platform that supports
Python. The user can then invoke the tool with Python's "module as a script"
feature (PEP 338), for example:

```sh
socat tcp:<piksi_ip_addr>:55555 | python -m sbp2json
```

The libraries here are generated using [JSON Schema][3] in combination with the
[QuickType][4] tool to injest the output of `sbp2json` and produce "native" objects
which allow users to fully utilize whatever type checking their language provides.
This also enables "developer assistance" technologies like IntelliSense for
exploring SBP message types during development.

[3]: https://json-schema.org/
[4]: https://github.com/quicktype/quicktype

See [javascript/README.md](../javascript/README.md) for a quick usage example.
Also see [HOWTO.md](../HOWTO.md) for information on how to update these
definitions if needed.
