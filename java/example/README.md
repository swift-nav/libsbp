# SBP Java Examples

## Requirements

- JDK 11
- Gradle

## Examples

Examples included
- SerialLink (com.swiftnav.example.SerialLink)
- TCPExample (com.swiftnav.example.TCPExample)
- TrackingState (com.swiftnav.example.TrackingState)

Example socket 
host `piksi-relay-1.ce.swiftnav.com` 
port `55555`

## How to run this example

Using this example, build jar using

### Using gradle run tasks

Using gradle we can run with 
```shell
gradle tcpExample --args="..."
gradle serialLink --args="..."
gradle trackingState --args="..."
```

### Using gradle to run via build

```bash
gradle fatjar
```

Using the built jars under `/build/libs`,

Since multiple examples, use the built jar as classpath and desired example as the main class i.e:

```bash
# Serial Link example
java -cp example-all.jar com.swiftnav.example.SerialLink

# TCP example
java -cp example-all.jar com.swiftnav.example.TCPExample

# Tracking State example
java -cp example-all.jar com.swiftnav.example.TrackingState
```


### Using makefile

Can use makefile to build using

```shell
make java-examples
```

## Setup

Add [SBP Maven](https://search.maven.org/artifact/com.swiftnav/sbp) to your project following the required steps

Example Usage:

Maven
```xml
<dependencies>
    <dependency>
        <groupId>com.swiftnav</groupId>
        <artifactId>sbp</artifactId>
        <version>VERSION</version>
    </dependency>

    <!--optional dependency for serial port (jssc) when not needed-->
    <dependency>
        <groupId>io.github.java-native</groupId>
        <artifactId>jssc</artifactId>
        <version>VERSION</version>
    </dependency>
    ...
</dependencies>
```

Gradle

```
dependencies {
    implementation 'io.github.java-native:jssc:VERSION'
    // dependency for serial port
    implementation 'com.swiftnav:sbp:VERSION'
    ...
}
```