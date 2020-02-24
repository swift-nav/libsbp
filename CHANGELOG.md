# Change Log

## [v2.7.3](https://github.com/swift-nav/libsbp/tree/HEAD)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.7.3...v2.7.4)

**Merged pull requests:**

- Dzollo/expand sbp json payload [\#779](https://github.com/swift-nav/libsbp/pull/779)
- Dzollo/sen 138/wheel odometry [\#778](https://github.com/swift-nav/libsbp/pull/778)
- \[SEN-138\] Add message for accumulated wheeltick count [\#777](https://github.com/swift-nav/libsbp/pull/777)
- Record total bytes read/written in python sbp driver [\#775](https://github.com/swift-nav/libsbp/pull/775)
- tcp\_example error fix \(signed /unsigned mismatch\) [\#774](https://github.com/swift-nav/libsbp/pull/774)
- Disallow copying of State [\#773](https://github.com/swift-nav/libsbp/pull/773)
- Dockerfile for building libsbp binding.  Uses debian buster. [\#772](https://github.com/swift-nav/libsbp/pull/772)
- Add message for tropo and iono with variances. [\#771](https://github.com/swift-nav/libsbp/pull/771)
- Changed the CMake to install all headers [\#770](https://github.com/swift-nav/libsbp/pull/770)
- Bump cmake to master. [\#769](https://github.com/swift-nav/libsbp/pull/769)
- Fixed a few minor typos in the comments for the C++ wrapper classes [\#768](https://github.com/swift-nav/libsbp/pull/768)
- Added classes for handling specific frame types and any frame [\#767](https://github.com/swift-nav/libsbp/pull/767)
- Dzollo/star 748/position messages [\#766](https://github.com/swift-nav/libsbp/pull/766)
- Added virtual destructor to sbp::State [\#765](https://github.com/swift-nav/libsbp/pull/765)
- updated swift libraries with namespace [\#764](https://github.com/swift-nav/libsbp/pull/764)
- Changes needed to libsbp for road runner \[INFRA-35\] [\#763](https://github.com/swift-nav/libsbp/pull/763)
- Revert "Add stddev to SSR atmospheric messages.  \(\#759\)" [\#761](https://github.com/swift-nav/libsbp/pull/761)
- Moved the rust example inside of the sbp crate [\#760](https://github.com/swift-nav/libsbp/pull/760)
- Add variances to SSR atmospheric messages.  [\#759](https://github.com/swift-nav/libsbp/pull/759)
- Example: rust message serialization plus trait to\_frame method [\#758](https://github.com/swift-nav/libsbp/pull/758)
- \[TTI-16\] Add rust message serialization [\#755](https://github.com/swift-nav/libsbp/pull/755)

## [v2.7.3](https://github.com/swift-nav/libsbp/tree/v2.7.3) (2019-11-14)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.7.1...v2.7.3)

**Closed issues:**

- sbp2rinex does not generate valid rinex when using toJson\(\) method from SBPMessage.java  [\#720](https://github.com/swift-nav/libsbp/issues/720)

**Merged pull requests:**

- Release 2.7.3 [\#757](https://github.com/swift-nav/libsbp/pull/757)
- Allow max reconnects to be specified as a parameter \[ESD-1603\] \[TTI-2\] [\#756](https://github.com/swift-nav/libsbp/pull/756)
- Miscellaneous clean up of Rust bindings [\#754](https://github.com/swift-nav/libsbp/pull/754)
- Get rust example building [\#753](https://github.com/swift-nav/libsbp/pull/753)
- Cannot compare int and NoneType in python3 [\#752](https://github.com/swift-nav/libsbp/pull/752)
- Added check for a couple of needed commands to build rust. [\#750](https://github.com/swift-nav/libsbp/pull/750)
- Added typescript module declaration file [\#749](https://github.com/swift-nav/libsbp/pull/749)
- Changed C++ wrapper to not require non-const access to the buffer when sending [\#748](https://github.com/swift-nav/libsbp/pull/748)
- Added optional serialize feature to rust crate [\#747](https://github.com/swift-nav/libsbp/pull/747)
- Update check [\#746](https://github.com/swift-nav/libsbp/pull/746)
- Add unit tests for Rust [\#745](https://github.com/swift-nav/libsbp/pull/745)
- Fix compiler warnings found in libsettings build [\#743](https://github.com/swift-nav/libsbp/pull/743)
- Import libcheck as submodule [\#742](https://github.com/swift-nav/libsbp/pull/742)
- Remove extra \\ from non-printable escaping [\#741](https://github.com/swift-nav/libsbp/pull/741)
- Use common test targets module [\#740](https://github.com/swift-nav/libsbp/pull/740)
- Add C++ support [\#739](https://github.com/swift-nav/libsbp/pull/739)
- Fix Rust generation to generate in the same order [\#738](https://github.com/swift-nav/libsbp/pull/738)
- \[STAR-789\] Add proposed Protection Level message [\#737](https://github.com/swift-nav/libsbp/pull/737)
- Star 833 [\#736](https://github.com/swift-nav/libsbp/pull/736)
- Generate JSON schema definitions for web clients [\#735](https://github.com/swift-nav/libsbp/pull/735)
- Update libsbp ARM builders [\#733](https://github.com/swift-nav/libsbp/pull/733)
- Modify to work with Rust's bindgen [\#706](https://github.com/swift-nav/libsbp/pull/706)

## [v2.7.1](https://github.com/swift-nav/libsbp/tree/v2.7.1) (2019-09-20)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.7.0...v2.7.1)

**Merged pull requests:**

- Version 2.7.1 [\#732](https://github.com/swift-nav/libsbp/pull/732)
- Remove explicit Python 2 build in dist/deploy sciprt [\#731](https://github.com/swift-nav/libsbp/pull/731)

## [v2.7.0](https://github.com/swift-nav/libsbp/tree/v2.7.0) (2019-09-19)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.6.5...v2.7.0)

**Merged pull requests:**

- libsbp version 2.7.0 [\#730](https://github.com/swift-nav/libsbp/pull/730)
- Replace ujson with rapidjson \[STA-1009\] [\#729](https://github.com/swift-nav/libsbp/pull/729)
- Make a msg\_buff pointer for backwards compatibility [\#728](https://github.com/swift-nav/libsbp/pull/728)
- Remove OWNERS.md file. [\#726](https://github.com/swift-nav/libsbp/pull/726)
- Frame callback implementation & tests [\#725](https://github.com/swift-nav/libsbp/pull/725)
- JSONLogIterator - Fix the iteration if the JSON is already unwrapped [\#724](https://github.com/swift-nav/libsbp/pull/724)
- Dynamic import generator output modules [\#722](https://github.com/swift-nav/libsbp/pull/722)
- Changing java CRC16 class modifiers to enable external access \(\#720\) [\#721](https://github.com/swift-nav/libsbp/pull/721)
- ORI-594 Fix up SSR atmospherics documentation [\#719](https://github.com/swift-nav/libsbp/pull/719)
- Remove lodash from JavaScript deps [\#717](https://github.com/swift-nav/libsbp/pull/717)
- Initial rust implementation [\#714](https://github.com/swift-nav/libsbp/pull/714)
- Remove redundant field. [\#713](https://github.com/swift-nav/libsbp/pull/713)
- Support running w/o Numba/Numpy installed [\#712](https://github.com/swift-nav/libsbp/pull/712)
- Add code coverage \[ESD-1407\] [\#710](https://github.com/swift-nav/libsbp/pull/710)
- Update requests to resolve security issue [\#708](https://github.com/swift-nav/libsbp/pull/708)

## [v2.6.5](https://github.com/swift-nav/libsbp/tree/v2.6.5) (2019-07-03)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.6.4...v2.6.5)

**Merged pull requests:**

- libsbp v2.6.5 [\#711](https://github.com/swift-nav/libsbp/pull/711)
- Pin minor rev versions, security fix for requests [\#709](https://github.com/swift-nav/libsbp/pull/709)

## [v2.6.4](https://github.com/swift-nav/libsbp/tree/v2.6.4) (2019-06-27)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.6.3...v2.6.4)

**Closed issues:**

- cmake error while installing libsbp - include could not find load file [\#705](https://github.com/swift-nav/libsbp/issues/705)

**Merged pull requests:**

- Update README.md [\#707](https://github.com/swift-nav/libsbp/pull/707)
- SSR STEC and gridded correction message refinements [\#704](https://github.com/swift-nav/libsbp/pull/704)
- Change ssr\_update\_interval to u8. [\#703](https://github.com/swift-nav/libsbp/pull/703)
- Purge llvmlite and numba dependencies from generated Python code \[ESD-1396\] [\#702](https://github.com/swift-nav/libsbp/pull/702)
- Don't use hardcoded include/link paths [\#701](https://github.com/swift-nav/libsbp/pull/701)

## [v2.6.3](https://github.com/swift-nav/libsbp/tree/v2.6.3) (2019-06-11)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.6.2...v2.6.3)

**Merged pull requests:**

- Version 2.6.3 [\#700](https://github.com/swift-nav/libsbp/pull/700)
- Move sbp2json to libsbp from piksi\_tools \[ESD-1374\] [\#699](https://github.com/swift-nav/libsbp/pull/699)
- Deprecate MSG\_INIT\_BASE \[ESD-1286\] [\#698](https://github.com/swift-nav/libsbp/pull/698)

## [v2.6.2](https://github.com/swift-nav/libsbp/tree/v2.6.2) (2019-06-06)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.6.1...v2.6.2)

**Merged pull requests:**

- v2.6.2 [\#697](https://github.com/swift-nav/libsbp/pull/697)

## [v2.6.1](https://github.com/swift-nav/libsbp/tree/v2.6.1) (2019-06-06)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.6.0...v2.6.1)

**Merged pull requests:**

- Version 2.6.1 [\#696](https://github.com/swift-nav/libsbp/pull/696)
- Add QZSS eph [\#695](https://github.com/swift-nav/libsbp/pull/695)
- Import standard cmake modules, standardise dependency resolution \[ESD-1246\] \[ESD-1247\] [\#692](https://github.com/swift-nav/libsbp/pull/692)

## [v2.6.0](https://github.com/swift-nav/libsbp/tree/v2.6.0) (2019-06-05)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.5.5...v2.6.0)

**Merged pull requests:**

- libsbp release 2.6.0 [\#694](https://github.com/swift-nav/libsbp/pull/694)
- Remove unused build\_test\_data.py \[ESD-1086\] [\#693](https://github.com/swift-nav/libsbp/pull/693)
- Integrate numba into setuptools \[ESD-1156\] [\#687](https://github.com/swift-nav/libsbp/pull/687)
- Added three new messages for gridded atmospheric SSR corrections. [\#686](https://github.com/swift-nav/libsbp/pull/686)

## [v2.5.5](https://github.com/swift-nav/libsbp/tree/v2.5.5) (2019-05-16)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.5.3-4-g7e6afa39...v2.5.5)

**Closed issues:**

- MSG\_INIT\_BASE / Hotstart with known Position [\#681](https://github.com/swift-nav/libsbp/issues/681)

**Merged pull requests:**

- Release version 2.5.5 [\#690](https://github.com/swift-nav/libsbp/pull/690)
- Use piksi\_tools master in benchmark [\#689](https://github.com/swift-nav/libsbp/pull/689)
- Add source to gal eph [\#688](https://github.com/swift-nav/libsbp/pull/688)
- Added additional checks for tools in the Makefile [\#684](https://github.com/swift-nav/libsbp/pull/684)
- \[ESD-1238\] Do not call nullary constructors in Haskell ToJSON [\#680](https://github.com/swift-nav/libsbp/pull/680)

## [v2.5.3-4-g7e6afa39](https://github.com/swift-nav/libsbp/tree/v2.5.3-4-g7e6afa39) (2019-04-10)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.5.4...v2.5.3-4-g7e6afa39)

## [v2.5.4](https://github.com/swift-nav/libsbp/tree/v2.5.4) (2019-04-10)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.5.3...v2.5.4)

**Merged pull requests:**

- Release 2.5.4 [\#679](https://github.com/swift-nav/libsbp/pull/679)
- Add TCP reconnect, purge "Skylark broker" support [\#678](https://github.com/swift-nav/libsbp/pull/678)

## [v2.5.3](https://github.com/swift-nav/libsbp/tree/v2.5.3) (2019-04-08)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.5.2...v2.5.3)

**Merged pull requests:**

- Release 2.5.3 [\#677](https://github.com/swift-nav/libsbp/pull/677)
- Write payload if given [\#676](https://github.com/swift-nav/libsbp/pull/676)

## [v2.5.2](https://github.com/swift-nav/libsbp/tree/v2.5.2) (2019-04-04)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.5.1...v2.5.2)

**Merged pull requests:**

- Release version 2.5.2 [\#675](https://github.com/swift-nav/libsbp/pull/675)
- Add base into\_buffer method for messages with no payload \[ESD-1154\] [\#674](https://github.com/swift-nav/libsbp/pull/674)
- py3 compat: use errno attribute for socket.error [\#673](https://github.com/swift-nav/libsbp/pull/673)

## [v2.5.1](https://github.com/swift-nav/libsbp/tree/v2.5.1) (2019-03-29)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.5.0...v2.5.1)

**Merged pull requests:**

- Release version 2.5.1 [\#672](https://github.com/swift-nav/libsbp/pull/672)

## [v2.5.0](https://github.com/swift-nav/libsbp/tree/v2.5.0) (2019-03-01)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.4.10-haskell_tools0...v2.5.0)

## [v2.4.10-haskell_tools0](https://github.com/swift-nav/libsbp/tree/v2.4.10-haskell_tools0) (2019-02-14)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.4.10...v2.4.10-haskell_tools0)

## [v2.4.10](https://github.com/swift-nav/libsbp/tree/v2.4.10) (2019-02-14)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.4.9...v2.4.10)

## [v2.4.9](https://github.com/swift-nav/libsbp/tree/v2.4.9) (2019-02-07)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.4.8...v2.4.9)

## [v2.4.8](https://github.com/swift-nav/libsbp/tree/v2.4.8) (2019-01-18)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.4.7...v2.4.8)

## [v2.4.7](https://github.com/swift-nav/libsbp/tree/v2.4.7) (2019-01-14)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.4.6...v2.4.7)

## [v2.4.6](https://github.com/swift-nav/libsbp/tree/v2.4.6) (2019-01-02)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.4.5...v2.4.6)

## [v2.4.5](https://github.com/swift-nav/libsbp/tree/v2.4.5) (2018-11-28)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.4.4...v2.4.5)

## [v2.4.4](https://github.com/swift-nav/libsbp/tree/v2.4.4) (2018-11-20)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.4.3...v2.4.4)

## [v2.4.3](https://github.com/swift-nav/libsbp/tree/v2.4.3) (2018-11-15)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.4.2...v2.4.3)

## [v2.4.2](https://github.com/swift-nav/libsbp/tree/v2.4.2) (2018-10-27)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.4.1...v2.4.2)

## [v2.4.1](https://github.com/swift-nav/libsbp/tree/v2.4.1) (2018-10-03)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.4.0...v2.4.1)

## [v2.4.0](https://github.com/swift-nav/libsbp/tree/v2.4.0) (2018-08-08)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.3.17...v2.4.0)

## [v2.3.17](https://github.com/swift-nav/libsbp/tree/v2.3.17) (2018-06-02)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.3.16...v2.3.17)

## [v2.3.16](https://github.com/swift-nav/libsbp/tree/v2.3.16) (2018-04-17)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.3.15...v2.3.16)

## [v2.3.15](https://github.com/swift-nav/libsbp/tree/v2.3.15) (2018-04-11)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.3.14...v2.3.15)

## [v2.3.14](https://github.com/swift-nav/libsbp/tree/v2.3.14) (2018-03-22)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.3.13...v2.3.14)

## [v2.3.13](https://github.com/swift-nav/libsbp/tree/v2.3.13) (2018-03-20)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.3.12...v2.3.13)

## [v2.3.12](https://github.com/swift-nav/libsbp/tree/v2.3.12) (2018-03-20)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.3.11...v2.3.12)

## [v2.3.11](https://github.com/swift-nav/libsbp/tree/v2.3.11) (2018-03-09)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.3.10...v2.3.11)

## [v2.3.10](https://github.com/swift-nav/libsbp/tree/v2.3.10) (2018-03-09)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.3.9...v2.3.10)

## [v2.3.9](https://github.com/swift-nav/libsbp/tree/v2.3.9) (2018-03-06)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.3.8...v2.3.9)

## [v2.3.8](https://github.com/swift-nav/libsbp/tree/v2.3.8) (2018-02-26)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.3.7...v2.3.8)

## [v2.3.7](https://github.com/swift-nav/libsbp/tree/v2.3.7) (2018-02-22)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.3.6...v2.3.7)

## [v2.3.6](https://github.com/swift-nav/libsbp/tree/v2.3.6) (2018-01-26)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.3.5...v2.3.6)

## [v2.3.5](https://github.com/swift-nav/libsbp/tree/v2.3.5) (2018-01-26)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.3.4...v2.3.5)

## [v2.3.4](https://github.com/swift-nav/libsbp/tree/v2.3.4) (2017-12-12)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.3.3...v2.3.4)

## [v2.3.3](https://github.com/swift-nav/libsbp/tree/v2.3.3) (2017-12-12)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.3.2...v2.3.3)

## [v2.3.2](https://github.com/swift-nav/libsbp/tree/v2.3.2) (2017-11-29)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.3.1...v2.3.2)

## [v2.3.1](https://github.com/swift-nav/libsbp/tree/v2.3.1) (2017-11-25)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.3.0...v2.3.1)

## [v2.3.0](https://github.com/swift-nav/libsbp/tree/v2.3.0) (2017-11-08)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.2.17...v2.3.0)

## [v2.2.17](https://github.com/swift-nav/libsbp/tree/v2.2.17) (2017-11-08)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.2.16...v2.2.17)

## [v2.2.16](https://github.com/swift-nav/libsbp/tree/v2.2.16) (2017-11-04)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.2.15...v2.2.16)

## [v2.2.15](https://github.com/swift-nav/libsbp/tree/v2.2.15) (2017-10-25)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.2.14...v2.2.15)

## [v2.2.14](https://github.com/swift-nav/libsbp/tree/v2.2.14) (2017-09-19)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.2.13...v2.2.14)

## [v2.2.13](https://github.com/swift-nav/libsbp/tree/v2.2.13) (2017-09-08)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.2.12...v2.2.13)

## [v2.2.12](https://github.com/swift-nav/libsbp/tree/v2.2.12) (2017-08-09)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.2.11...v2.2.12)

## [v2.2.11](https://github.com/swift-nav/libsbp/tree/v2.2.11) (2017-07-27)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.2.10...v2.2.11)

## [v2.2.10](https://github.com/swift-nav/libsbp/tree/v2.2.10) (2017-07-27)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.2.8...v2.2.10)

## [v2.2.8](https://github.com/swift-nav/libsbp/tree/v2.2.8) (2017-07-12)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.2.7...v2.2.8)

## [v2.2.7](https://github.com/swift-nav/libsbp/tree/v2.2.7) (2017-07-03)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.2.6...v2.2.7)

## [v2.2.6](https://github.com/swift-nav/libsbp/tree/v2.2.6) (2017-06-21)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.2.5...v2.2.6)

## [v2.2.5](https://github.com/swift-nav/libsbp/tree/v2.2.5) (2017-06-13)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.2.4...v2.2.5)

## [v2.2.4](https://github.com/swift-nav/libsbp/tree/v2.2.4) (2017-06-10)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.2.3...v2.2.4)

## [v2.2.3](https://github.com/swift-nav/libsbp/tree/v2.2.3) (2017-05-26)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.2.2...v2.2.3)

## [v2.2.2](https://github.com/swift-nav/libsbp/tree/v2.2.2) (2017-05-25)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.2.1...v2.2.2)

## [v2.2.1](https://github.com/swift-nav/libsbp/tree/v2.2.1) (2017-05-12)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.2.0...v2.2.1)

## [v2.2.0](https://github.com/swift-nav/libsbp/tree/v2.2.0) (2017-03-24)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.1.8...v2.2.0)

## [v2.1.8](https://github.com/swift-nav/libsbp/tree/v2.1.8) (2017-03-11)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.1.7...v2.1.8)

## [v2.1.7](https://github.com/swift-nav/libsbp/tree/v2.1.7) (2017-02-08)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.1.6...v2.1.7)

## [v2.1.6](https://github.com/swift-nav/libsbp/tree/v2.1.6) (2017-01-25)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.1.5...v2.1.6)

## [v2.1.5](https://github.com/swift-nav/libsbp/tree/v2.1.5) (2017-01-04)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.1.4...v2.1.5)

## [v2.1.4](https://github.com/swift-nav/libsbp/tree/v2.1.4) (2016-12-13)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.1.3...v2.1.4)

## [v2.1.3](https://github.com/swift-nav/libsbp/tree/v2.1.3) (2016-12-07)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.1.1...v2.1.3)

## [v2.1.1](https://github.com/swift-nav/libsbp/tree/v2.1.1) (2016-12-01)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.1.0...v2.1.1)

## [v2.1.0](https://github.com/swift-nav/libsbp/tree/v2.1.0) (2016-11-30)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.0.0...v2.1.0)

## [v2.0.0](https://github.com/swift-nav/libsbp/tree/v2.0.0) (2016-11-10)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.0...v2.0.0)

## [v2.0](https://github.com/swift-nav/libsbp/tree/v2.0) (2016-11-09)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v1.2.8...v2.0)

## [v1.2.8](https://github.com/swift-nav/libsbp/tree/v1.2.8) (2016-11-02)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v1.2.7...v1.2.8)

## [v1.2.7](https://github.com/swift-nav/libsbp/tree/v1.2.7) (2016-11-02)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v1.2.6...v1.2.7)

## [v1.2.6](https://github.com/swift-nav/libsbp/tree/v1.2.6) (2016-11-01)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v1.2.5...v1.2.6)

## [v1.2.5](https://github.com/swift-nav/libsbp/tree/v1.2.5) (2016-10-31)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v1.2.4...v1.2.5)

## [v1.2.4](https://github.com/swift-nav/libsbp/tree/v1.2.4) (2016-10-20)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v1.2.3...v1.2.4)

## [v1.2.3](https://github.com/swift-nav/libsbp/tree/v1.2.3) (2016-10-20)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v1.2.2...v1.2.3)

## [v1.2.2](https://github.com/swift-nav/libsbp/tree/v1.2.2) (2016-09-23)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/help...v1.2.2)

## [help](https://github.com/swift-nav/libsbp/tree/help) (2016-09-16)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v1.2.1...help)

## [v1.2.1](https://github.com/swift-nav/libsbp/tree/v1.2.1) (2016-09-12)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v1.2.0...v1.2.1)

## [v1.2.0](https://github.com/swift-nav/libsbp/tree/v1.2.0) (2016-09-09)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v1.1.4...v1.2.0)

## [v1.1.4](https://github.com/swift-nav/libsbp/tree/v1.1.4) (2016-09-08)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v1.1.3...v1.1.4)

## [v1.1.3](https://github.com/swift-nav/libsbp/tree/v1.1.3) (2016-08-08)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v1.1.2...v1.1.3)

## [v1.1.2](https://github.com/swift-nav/libsbp/tree/v1.1.2) (2016-08-08)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v1.1.1...v1.1.2)

## [v1.1.1](https://github.com/swift-nav/libsbp/tree/v1.1.1) (2016-08-02)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v1.1.0...v1.1.1)

## [v1.1.0](https://github.com/swift-nav/libsbp/tree/v1.1.0) (2016-08-01)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v1.0.2...v1.1.0)

## [v1.0.2](https://github.com/swift-nav/libsbp/tree/v1.0.2) (2016-07-29)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v1.0.1...v1.0.2)

## [v1.0.1](https://github.com/swift-nav/libsbp/tree/v1.0.1) (2016-07-27)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v1.0.0...v1.0.1)

## [v1.0.0](https://github.com/swift-nav/libsbp/tree/v1.0.0) (2016-05-26)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/1.0.0...v1.0.0)

## [1.0.0](https://github.com/swift-nav/libsbp/tree/1.0.0) (2016-05-26)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.53.0...1.0.0)

## [v0.53.0](https://github.com/swift-nav/libsbp/tree/v0.53.0) (2016-05-24)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.52.4...v0.53.0)

## [v0.52.4](https://github.com/swift-nav/libsbp/tree/v0.52.4) (2016-05-03)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.52.3...v0.52.4)

## [v0.52.3](https://github.com/swift-nav/libsbp/tree/v0.52.3) (2016-05-03)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.51.11...v0.52.3)

## [v0.51.11](https://github.com/swift-nav/libsbp/tree/v0.51.11) (2016-03-09)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.52.1...v0.51.11)

## [v0.52.1](https://github.com/swift-nav/libsbp/tree/v0.52.1) (2015-12-10)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.52.0...v0.52.1)

## [v0.52.0](https://github.com/swift-nav/libsbp/tree/v0.52.0) (2015-12-08)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.51.10...v0.52.0)

## [v0.51.10](https://github.com/swift-nav/libsbp/tree/v0.51.10) (2015-12-06)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.51.9...v0.51.10)

## [v0.51.9](https://github.com/swift-nav/libsbp/tree/v0.51.9) (2015-12-03)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.51.8...v0.51.9)

## [v0.51.8](https://github.com/swift-nav/libsbp/tree/v0.51.8) (2015-12-02)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.51.7...v0.51.8)

## [v0.51.7](https://github.com/swift-nav/libsbp/tree/v0.51.7) (2015-11-30)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.51.6...v0.51.7)

## [v0.51.6](https://github.com/swift-nav/libsbp/tree/v0.51.6) (2015-11-20)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.51.5...v0.51.6)

## [v0.51.5](https://github.com/swift-nav/libsbp/tree/v0.51.5) (2015-11-18)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.51.4...v0.51.5)

## [v0.51.4](https://github.com/swift-nav/libsbp/tree/v0.51.4) (2015-11-18)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.51.3...v0.51.4)

## [v0.51.3](https://github.com/swift-nav/libsbp/tree/v0.51.3) (2015-11-17)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.51.2...v0.51.3)

## [v0.51.2](https://github.com/swift-nav/libsbp/tree/v0.51.2) (2015-10-19)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.51.1...v0.51.2)

## [v0.51.1](https://github.com/swift-nav/libsbp/tree/v0.51.1) (2015-10-12)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.51.0...v0.51.1)

## [v0.51.0](https://github.com/swift-nav/libsbp/tree/v0.51.0) (2015-10-12)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.50.9...v0.51.0)

## [v0.50.9](https://github.com/swift-nav/libsbp/tree/v0.50.9) (2015-09-18)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.50.8...v0.50.9)

## [v0.50.8](https://github.com/swift-nav/libsbp/tree/v0.50.8) (2015-09-17)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.50.7...v0.50.8)

## [v0.50.7](https://github.com/swift-nav/libsbp/tree/v0.50.7) (2015-09-16)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.50.6...v0.50.7)

## [v0.50.6](https://github.com/swift-nav/libsbp/tree/v0.50.6) (2015-09-16)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.50.5...v0.50.6)

## [v0.50.5](https://github.com/swift-nav/libsbp/tree/v0.50.5) (2015-09-16)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.50.4...v0.50.5)

## [v0.50.4](https://github.com/swift-nav/libsbp/tree/v0.50.4) (2015-09-16)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.50.3...v0.50.4)

## [v0.50.3](https://github.com/swift-nav/libsbp/tree/v0.50.3) (2015-09-10)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.50.2...v0.50.3)

## [v0.50.2](https://github.com/swift-nav/libsbp/tree/v0.50.2) (2015-08-17)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.50.1...v0.50.2)

## [v0.50.1](https://github.com/swift-nav/libsbp/tree/v0.50.1) (2015-08-01)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.49.1...v0.50.1)

## [v0.49.1](https://github.com/swift-nav/libsbp/tree/v0.49.1) (2015-07-23)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.50.0...v0.49.1)

## [v0.50.0](https://github.com/swift-nav/libsbp/tree/v0.50.0) (2015-07-20)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.49.0...v0.50.0)

## [v0.49.0](https://github.com/swift-nav/libsbp/tree/v0.49.0) (2015-07-10)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.48.1...v0.49.0)

## [v0.48.1](https://github.com/swift-nav/libsbp/tree/v0.48.1) (2015-07-09)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.48.0...v0.48.1)

## [v0.48.0](https://github.com/swift-nav/libsbp/tree/v0.48.0) (2015-07-06)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.47.0...v0.48.0)

## [v0.47.0](https://github.com/swift-nav/libsbp/tree/v0.47.0) (2015-07-06)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.46.4...v0.47.0)

## [v0.46.4](https://github.com/swift-nav/libsbp/tree/v0.46.4) (2015-06-23)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.46.3...v0.46.4)

## [v0.46.3](https://github.com/swift-nav/libsbp/tree/v0.46.3) (2015-06-23)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.46.2...v0.46.3)

## [v0.46.2](https://github.com/swift-nav/libsbp/tree/v0.46.2) (2015-06-22)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.46.1...v0.46.2)

## [v0.46.1](https://github.com/swift-nav/libsbp/tree/v0.46.1) (2015-06-19)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.46.0...v0.46.1)

## [v0.46.0](https://github.com/swift-nav/libsbp/tree/v0.46.0) (2015-06-18)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.45...v0.46.0)

## [v0.45](https://github.com/swift-nav/libsbp/tree/v0.45) (2015-06-09)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.44...v0.45)

## [v0.44](https://github.com/swift-nav/libsbp/tree/v0.44) (2015-06-08)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.43...v0.44)

## [v0.43](https://github.com/swift-nav/libsbp/tree/v0.43) (2015-06-04)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.42...v0.43)

## [v0.42](https://github.com/swift-nav/libsbp/tree/v0.42) (2015-06-01)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.41...v0.42)

## [v0.41](https://github.com/swift-nav/libsbp/tree/v0.41) (2015-05-29)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.40...v0.41)

## [v0.40](https://github.com/swift-nav/libsbp/tree/v0.40) (2015-05-20)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.39...v0.40)

## [v0.39](https://github.com/swift-nav/libsbp/tree/v0.39) (2015-05-05)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.38...v0.39)

## [v0.38](https://github.com/swift-nav/libsbp/tree/v0.38) (2015-04-29)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.37...v0.38)

## [v0.37](https://github.com/swift-nav/libsbp/tree/v0.37) (2015-04-24)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.36...v0.37)

## [v0.36](https://github.com/swift-nav/libsbp/tree/v0.36) (2015-04-17)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.35...v0.36)

## [v0.35](https://github.com/swift-nav/libsbp/tree/v0.35) (2015-04-17)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.34...v0.35)

## [v0.34](https://github.com/swift-nav/libsbp/tree/v0.34) (2015-04-16)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.33...v0.34)

## [v0.33](https://github.com/swift-nav/libsbp/tree/v0.33) (2015-04-15)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.32...v0.33)

## [v0.32](https://github.com/swift-nav/libsbp/tree/v0.32) (2015-04-14)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.29...v0.32)

## [v0.29](https://github.com/swift-nav/libsbp/tree/v0.29) (2015-04-08)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.28...v0.29)

## [v0.28](https://github.com/swift-nav/libsbp/tree/v0.28) (2015-04-08)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.27...v0.28)

## [v0.27](https://github.com/swift-nav/libsbp/tree/v0.27) (2015-04-01)


\* *This Change Log was automatically generated by [github_changelog_generator](https://github.com/skywinder/Github-Changelog-Generator)*
