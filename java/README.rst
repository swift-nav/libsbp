SBP Bindings for Java
=======================

Java client for Swift Binary Protocol (SBP).
Supports standard Java and Android.

Prerequisites
-----
- Java 11
- Gradle 7.1.1

Quick Setup
-----
Use `latest build from maven
<https://search.maven.org/artifact/com.swiftnav/sbp>`_ as dependency

Building
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
---------------

Examples are viewable at `example
<https://github.com/swift-nav/libsbp/tree/master/java/example>`_

License
-------

Copyright © 2015-2022 Swift Navigation

Distributed under MIT.

