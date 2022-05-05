## C example for libsbp

An example C program, intended to be run on a host computer connected to
the Piksi, that parses incoming SBP messages from the Piksi and prints some of
them to the screen.

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

You should also install [libserialport](http://sigrok.org/wiki/Libserialport).

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
./libsbp_example
usage: ./libsbp_example [-p serial port]
```

## LICENSE

Copyright © 2015-2021 Swift Navigation

Distributed under MIT.
