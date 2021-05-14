## Specification and Bindings for Swift Binary Protocol

<!-- toc -->

- [Installing sbp2json, json2sbp, json2json and related tools](#installing-sbp2json-json2sbp-json2json-and-related-tools)
- [Building / installing](#building--installing)
  * [Using Docker](#using-docker)
    + [Fetching the prebuilt image from DockerHub](#fetching-the-prebuilt-image-from-dockerhub)
    + [Creating your own image](#creating-your-own-image)
    + [Using the docker image](#using-the-docker-image)
  * [Installing from package managers](#installing-from-package-managers)
  * [Installing development Python versions](#installing-development-python-versions)
  * [Adding development version as a pip dependency](#adding-development-version-as-a-pip-dependency)
  * [Installing from source](#installing-from-source)
- [SBP Development Procedures](#sbp-development-procedures)  
- [SBP Protocol Specification](#sbp-protocol-specification)
- [JSON Schema Definitions](#json-schema-definitions)
- [LICENSE](#license)

<!-- tocstop -->

The Swift Navigation Binary Protocol (SBP) is a fast, simple, and minimal
binary protocol for communicating with Swift devices. It is the native binary
protocol used by the [Piksi GPS receiver](http://swiftnav.com/piksi.html) to
transmit solutions, observations, status and debugging messages, as well as
receive messages from the host operating system, such as differential
corrections and the almanac.

This project provides language-agnostic specification and documentation for
messages used with SBP, a compiler for generating message bindings, and client
libraries in a variety of languages. This repository is organized into the
following directory structure:

* [`docs`](./docs): Protocol documentation and message definitions.
* [`spec`](./spec): Machine readable protocol specification in
  [YAML](http://en.wikipedia.org/wiki/YAML).
* [`generator`](./generator): Simple, template-based generator for
  different languages.
* [`python`](./python): Python client and examples.
* [`c`](./c): C client library and examples.
* [`haskell`](./haskell): Haskell client and examples.
* [`java`](./java): Java client library and examples.
* [`javascript`](./javascript): JavaScript client library and examples.
* [`rust`](./rust): Rust client library and examples.
* [`sbpjson`](./sbpjson): Tools for parsing SBP-JSON.

Except for the `generator`, all of the above are generated and should not be modified directly.

## Installing sbp2json, json2sbp, json2json and related tools

This repository also provides the following utilities for comprehending and
inspecting SBP data:

- `sbp2json`: converts SBP binary into a JSON representation, in which field
  names and values are expanded into JSON objects, common fields such as
  "message type" and "payload" are included as well.

- `json2sbp`: uses the "message type", "payload" and related fields from an SBP
  JSON stream to reconstruct the binary representation.

- `json2json`: some tools (notably the Swift GUI Console) produce abbreviated
  JSON logs with only common fields such as "message type" and "payload", the
  `json2json` tool expands these JSON objects to include fields specific the
  individual message.

To install a released version of these tools, visit the [releases
page](https://github.com/swift-nav/libsbp/releases) and download an archive for
your platform.

To install from source, you can use Rust's cargo tool (first [install
Rust](https://www.rust-lang.org/tools/install)), then run:

```
cargo install --git https://github.com/swift-nav/libsbp.git --bins
```

There's also a [Haskell version](./haskell) available which can be installed by
running `stack install` in the [./haskell](./haskell) directory of a checkout
of this repo (after [installing
stack](https://docs.haskellstack.org/en/stable/README/)) or by visiting the
releases by and downloading an `sbp_tools_haskell` archive.  This variant of
the tools predate the Rust and Python versions, and also includes an `sbp2yaml`
tool as well as a `sbp2prettyjson` tool.

Finally, a Python version of the `sbp2json` tool exists, which is installable
on any platform that supports Python via pip, e.g.:

```
pip3 install sbp
```

The tool can then be invoked as follows:

```
python3 -m sbp2json <sbp.bin
```

The performance of the Python version is significantly slower than Rust and Haskell,
but works on all platforms that Python itself supports.

## Building / installing

### Using Docker

Before you begin, make sure you have [Docker](https://docs.docker.com/docker-for-mac/install/) installed.
Start [Docker desktop](https://docs.docker.com/docker-for-mac/). 

#### Fetching the prebuilt image from DockerHub

The quickest method to get going is to just pull a prebuilt copy from DockerHub
(no guarantees on freshness) by running the following on your command line:

``docker run --rm -v $PWD:/mnt/workspace -i -t swiftnav/libsbp-build:2021.04.22``

This will mount your local copy of the libsbp repository onto the image.

Check this [link](https://hub.docker.com/r/swiftnav/libsbp-build/tags) for newer tags.
Alternatively, you could run

``docker run --rm -v $PWD:/mnt/workspace -i -t swiftnav/libsbp-build:latest-master``

if you are facing issues with compilation and the tags are out of date as well.

#### Creating your own image

Otherwise, the `Dockerfile` will create a docker image that contains all the
necessary dependencies to build libsbp.  You can make a local image fresh from
this file by running `docker build` as such:

`mkdir docker-build; cd docker-build`

This dummy directory is to prevent docker from sucking up the whole
repo into the local context (which is then immediately discarded
anyway).  Next create the docker image:

`docker build -f ../Dockerfile -t libsbp-build .`

You can then make this image operate on your local workspace like this:

`cd ..`  (back up to the root of the repo)

``docker run --rm -v $PWD:/mnt/workspace -i -t libsbp-build:latest``

#### Using the docker image

Once in the image, simply type `make all` to generate all the libsbp bindings.
This could take several hours to run.

When you are finished, quit Docker so that it would not unnecessarily use up resources on your machine. 

If you run into issues during the generation process, try running `make clean`. 
Alternatively, you could recompile from a clean, newly-cloned libsbp repository on your machine,
which would minimize the chance of running into compilation issues from an old build.

### Installing from package managers
Some bindings are available on package managers:

* [`python`](https://github.com/swift-nav/libsbp/tree/HEAD/python): available on pip
* [`haskell`](https://github.com/swift-nav/libsbp/tree/HEAD/haskell): available on Hackage
* [`javascript`](https://github.com/swift-nav/libsbp/tree/HEAD/javascript): available on NPM

### Installing development Python versions

To install the Python binding from source (using pip) run the following command:

```sh
pip install 'file:///path/to/libsbp#subdirectory=python'
```

Or via setuptools directly:
```sh
cd /path/to/libsbp
cd python
python setup.py
```

### Adding development version as a pip dependency

Run the following command:
```sh
pip install git+https://github.com/swift-nav/libsbp@<GIT_REVISION>#egg=sbp&subdirectory=python
```

Or add this to `requirements.txt`:
```
git+https://github.com/swift-nav/libsbp@<GIT_REVISION>#egg=sbp&subdirectory=python
```

### Installing from source
You can build one binding at a time or update all at once:

```
make python
```

or

```
make all
```

are both valid. To see a list of all valid targets, run `make help`.

**Python version notes:**
1. by default the Python targets `make python` and `make test-python`
   (as well as `make all`) run tests on all Python versions officially supported
   by *the libsbp Python bindings*, currently **2.7, 3.5, and 3.7**, skipping
   any versions not installed. To run tests on just specific Python version(s),
   specify the `TOXENV` environment variable, e.g.,
   `TOXENV=py27,py35 make python`. Travis runs Python tests on all supported
   versions.
2. by default *the code generators* are run on the system's (or virtual env's)
   default Python interpreter. Currently Python versions **2.7, 3.5, and 3.7**
   are officially supported, other versions may or may not work. The generated
   libsbp bindings should be the same on all supported Python versions. To use
   a different version than your default Python interpreter, specify the
   `GENENV` environment variable, e.g., `GENENV=py27 make all`
   (you must have that version of Python installed beforehand).
3. to run both the generator and the Python tests on specific Python versions,
   specify both envs, e.g., `GENENV=py37 TOXENV=py27,py37 make python`

## SBP Development Procedures

See the [HOW-TO](HOWTO.md) page for instructions on adding new messages, 
updating the [documentation](docs/sbp.pdf), and releasing new versions of this library.

## SBP Protocol Specification

SBP consists of two pieces: (i) an over-the-wire message framing
format and (ii) structured payload definitions. As of Version 1.0, the
packet consists of a 6-byte binary header section, a variable-sized
payload field, and a 16-bit CRC value. SBP uses the CCITT CRC16
(XMODEM implementation) for error detection.

Please see
[the docs](https://github.com/swift-nav/libsbp/raw/master/docs/sbp.pdf)
for a full description of the packet structure and the message
types. Developer documentatation for the language-specific sbp
libraries is [here](http://swift-nav.github.io/libsbp/).
Please refer to [the changelog](https://github.com/swift-nav/libsbp/blob/master/CHANGELOG.md)
for more information about the evolution of the library and its messages.

## JSON Schema Definitions

For web clients processing SBP in JSON form, JSON schema definitions are
provided.  Libraries for JavaScript, TypeScript, and Elm generated by the
[QuickType](https://github.com/quicktype/quicktype) tool are provided.  See the
HOWTO for instructions on updating these schemas.

## LICENSE

Copyright © 2020 Swift Navigation

Distributed under MIT.
