## TCP example in C for libsbp

This example demonstrates parsing SBP over a TCP connection.

## Requirements
On Debian-based systems (including Ubuntu 12.10 or later) you can get all
the requirements with:

```shell
sudo apt-get install build-essential pkg-config cmake
```

On mac:

```shell
brew install cmake
```

On other systems, you can obtain CMake from your operating system
package manager or from http://www.cmake.org/.

## Installation

Once you have the dependencies installed, create a build directory where the example will be built:

```shell
mkdir build
cd build
```

Then invoke CMake to configure the build, and then build,

```shell
cmake ../
make
```

## Usage

```shell
./libsbp_tcp_example
usage: ./libsbp_tcp_example [-a address -p port]
```

## LICENSE

Copyright © 2018 Swift Navigation

Distributed under LGPLv3.0.
