# SBP JSON Comprehension Libraries

We have several tools that produce a representation of SBP in JSON format.
Particularly, we have a native binary tool `sbp2json`, which is released as an
Ubuntu binary (for example, the [libsbp 2.7.1 release][1]).  Since this tool is
Haskell based, it can be [compiled][2] and utilized on any platform that
Haskell supports.

[1]: https://github.com/swift-nav/libsbp/releases/download/v2.7.1/sbp_linux_tools.tar.gz
[2]: https://github.com/swift-nav/libsbp/tree/master/haskell

For other platforms, we have a Python version of the `sbp2json` tool, which allows
a user to simply run `pip3 install sbp` on any platform that supports Python.
The user can then invoke the tool with Python's "module as a script" feature
(PEP 338), for example:

```sh
socat tcp:<piksi_ip_addr>:55555 | python -m sbp2json
```

*(On some platforms, this Python tool is accelerated with native code, and has
performance that's comparable to the Haskell tool.)*

The libraries here are generated using [JSON Schema][3] in combination with the
[QuickType][4] tool to injest the output of `sbp2json` and produce "native" objects
which allow users to fully utilize whatever type checking their language provides.
This also enables "developer assistance" technologies like IntelliSense for
exploring SBP message types during development.

See [javascript/README.md](../javascript/README.md) for a quick usage example.
Also see [HOWTO.md](../HOWTO.md) for information on how to update these
definitions if needed.
