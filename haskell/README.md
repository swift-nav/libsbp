# [SBP Bindings for Haskell][1]

Haskell client for Swift Binary Protocol (SBP).

## Requirements

`haskell-stack`: [Instructions here](https://github.com/commercialhaskell/stack/blob/master/doc/install_and_upgrade.md).

## Install from Hackage

Available on [Hackage as `sbp`](http://hackage.haskell.org/package/sbp).

The library supports building against Stackage LTS-10. To
install from Hackage using `stack`:

    $ stack install --resolver lts-10.10 sbp # (LTS-10)

Note that we explicitly specify the resolvers to use, as installing `libsbp` may
fail to build with more recent resolvers.

Building with cabal is possible but not supported and may fail to build.

## Setup

To build:

    $ stack build

To install:

    $ stack install

To test and benchmark:

    $ stack test && stack bench

To deploy to Hackage:

    $ stack upload

## Publishing

To publish to [Hackage](http://hackage.haskell.org/package/sbp), use the
`publish-lower` recipe in the `Shakefile.hs` with LTS-10 `stack.yaml`:

    $ STACK_YAML=stack-lts-10.yaml ./Shakefile.hs publish-lower

## References

# LICENSE

Copyright © 2015 Swift Navigation Inc.

[1]: https://github.com/swift-nav/libsbp/tree/master/haskell
