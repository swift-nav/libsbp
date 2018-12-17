SBP Bindings for Java
=======================

Java client for Swift Binary Protocol (SBP).
Supports standard Java and Android.

Setup
-----

Generate message classes from the toplevel:
  $ make java

Build Java library:
  $ cd java; gradle build
Find the JAR in java/build/libs/sbp.jar

Build Javadoc documentation:
  $ cd java; gradle javadoc
Find compiled documentation in java/build/docs/javadoc

Usage Examples
--------------

A simple example is provided to read from a serial port and write log messages,
as well as the latitude, longitude, and altitude from MsgPosLLH to stdout.

  $ cd java/example
  $ javac -cp ../build/libs/sbp.jar:/path/to/jssc.jar SerialLink.java
  $ java -cp ../build/libs/sbp.jar:/path/to/jssc.jar:./ SerialLink /dev/ttyUSB0

License
-------

Copyright © 2015 Swift Navigation

Distributed under LGPLv3.0.

