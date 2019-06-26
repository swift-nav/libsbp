## SBP Bindings for C

libsbp provides C bindings for Swift Binary Protocol (SBP), the native
binary protocol used by the
[Piksi GPS receiver](http://swiftnav.com/piksi.html). It is intended
to be as portable as possible and is written in standards compliant C
with no dependencies other than the standard C libraries.

## Installation

On Debian-based systems (including Ubuntu 12.10 or later) you can get
dependencies with:

```shell
sudo apt-get install build-essential pkg-config cmake doxygen check
```

On Mac:

```shell
brew install check cmake pkg-config doxygen
```

On other systems, you can obtain CMake from your operating system
package manager or from http://www.cmake.org/.

Before attempting to build, it is necessary to update the git submodules to pull in the cmake submodule for the c build of libsbp.  This isn't strictly necessary for the code itself, but it is necessary for the cmake build system provided by Swift. This can be done at the command line with:

```git submodule update --init```

Once you have the dependencies installed, from this (the libsbp/c directory)
create a build directory where the library will be built:

```shell
mkdir build
cd build
```

Then invoke CMake to configure the build, and then build and install,

```shell
cmake ../
make
sudo make install
```

By default libsbp will be built both as a shared library `libsbp` and
a static library `libsbp-static`.

## Usage

For now, documentation for libsbp is available with
[libswiftnav](https://swift-nav.github.io/libsbp/c/build/docs/html). A
separate tutorial for applying SBP is at
https://github.com/swift-nav/sbp_tutorial.

## LICENSE

Copyright © 2015 Swift Navigation

Distributed under LGPLv3.0.
