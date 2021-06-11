## 2 sigma calculation example for libsbp

Example demonstrating how to parse SBP data from a TCP port and compute the
ellipse representing the 2 sigma/95% confidence level.

## Requirements for basic build
Requires Eigen 3 and cmake.  On Debian-based systems you can get all of
the requirements with:

```shell
sudo apt-get install build-essential pkg-config cmake libeigen3-dev
```

On mac:

```shell
brew install cmake eigen
```

On other systems, you can obtain CMake from your operating system
package manager or from http://www.cmake.org/.

## Requirements for graphical build
If compiled with -DSHOW\_PLOT then the ellipses will be graphically displayed.
This functionality requires OpenCV3.  On Debian-based systems:

```shell
sudo apt-get install libopencv-dev
```

On mac:

```shell
brew install opencv@3
```

## Installation

Once you have the dependencies installed, create a build directory where the example will be built:

```shell
mkdir build
cd build
```

Then invoke CMake to configure the build.  For a non-graphical build:

```shell
cmake ..
```

Or for a graphical build:

```shell
cmake .. -DSHOW_PLOT=true
```

## Usage

```shell
./libsbp_tcp_2sigma_example
usage: ./libsbp_tcp_2sigma_example [-a address -p port]
```

## LICENSE

Copyright © 2021 Swift Navigation
