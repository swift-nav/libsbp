# Change Log

## [Unreleased](https://github.com/swift-nav/libsbp/tree/HEAD)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.39...HEAD)

**Merged pull requests:**

- Allow the logger to inject tags into the logs [\#145](https://github.com/swift-nav/libsbp/pull/145)

## [v0.39](https://github.com/swift-nav/libsbp/tree/v0.39) (2015-05-05)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.38...v0.39)

**Fixed bugs:**

- 'make latex' fails with 'too many floats' [\#85](https://github.com/swift-nav/libsbp/issues/85)

**Closed issues:**

- Protocol version number in docs is hard-coded, should be same as sbp package version? [\#86](https://github.com/swift-nav/libsbp/issues/86)
- Document process for adding new messages [\#78](https://github.com/swift-nav/libsbp/issues/78)

**Merged pull requests:**

- rev the version [\#143](https://github.com/swift-nav/libsbp/pull/143)
- Latex datasheet fixes. [\#142](https://github.com/swift-nav/libsbp/pull/142)
- Add an example byte logger. [\#140](https://github.com/swift-nav/libsbp/pull/140)
- Crc namespace collision [\#133](https://github.com/swift-nav/libsbp/pull/133)
- SBP doc: Table 2.0.1. s/Payload/Packet/ [\#126](https://github.com/swift-nav/libsbp/pull/126)
- Release HOWTO and supporting Makefile tasks. [\#102](https://github.com/swift-nav/libsbp/pull/102)

## [v0.38](https://github.com/swift-nav/libsbp/tree/v0.38) (2015-04-29)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.37...v0.38)

**Implemented enhancements:**

- Create Jenkins pull request builder [\#26](https://github.com/swift-nav/libsbp/issues/26)

**Merged pull requests:**

- Handle failing parsing [\#136](https://github.com/swift-nav/libsbp/pull/136)

## [v0.37](https://github.com/swift-nav/libsbp/tree/v0.37) (2015-04-24)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.36...v0.37)

**Fixed bugs:**

- Disallow NaN in JSON [\#128](https://github.com/swift-nav/libsbp/issues/128)

**Merged pull requests:**

- Add file mode as a parameter - have log iterator take a filename [\#132](https://github.com/swift-nav/libsbp/pull/132)
- Removes unused message template. [\#131](https://github.com/swift-nav/libsbp/pull/131)
- Update SBP fields when materializing child objects. [\#130](https://github.com/swift-nav/libsbp/pull/130)
- Suppress NaN in python JSON dump [\#129](https://github.com/swift-nav/libsbp/pull/129)
- Remove the main from client - it's in piksi tools [\#127](https://github.com/swift-nav/libsbp/pull/127)

## [v0.36](https://github.com/swift-nav/libsbp/tree/v0.36) (2015-04-17)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.35...v0.36)

**Fixed bugs:**

- MsgEphemeris ID change breaks sbp\_log\_analysis [\#119](https://github.com/swift-nav/libsbp/issues/119)

**Merged pull requests:**

- Reinstate MSG\_EPHEMERIS at 0x001A as MSG\_EPHEMERIS\_OLD [\#125](https://github.com/swift-nav/libsbp/pull/125)
- Make ext\_events messages public [\#124](https://github.com/swift-nav/libsbp/pull/124)
- Expand JSON messages before they go out [\#123](https://github.com/swift-nav/libsbp/pull/123)
- handle unpickling error more gracefully [\#105](https://github.com/swift-nav/libsbp/pull/105)

## [v0.35](https://github.com/swift-nav/libsbp/tree/v0.35) (2015-04-17)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.34...v0.35)

**Closed issues:**

- Remove init known baseline feature from console [\#116](https://github.com/swift-nav/libsbp/issues/116)
- Update sbp integration tutorial? [\#27](https://github.com/swift-nav/libsbp/issues/27)

**Merged pull requests:**

- Catch message dispatch KeyErrors and make them warnings. [\#122](https://github.com/swift-nav/libsbp/pull/122)
- Make the handler test more robust [\#121](https://github.com/swift-nav/libsbp/pull/121)
- Bootload test fixes \(and more!\) [\#117](https://github.com/swift-nav/libsbp/pull/117)
- Misc Fixes [\#114](https://github.com/swift-nav/libsbp/pull/114)

## [v0.34](https://github.com/swift-nav/libsbp/tree/v0.34) (2015-04-16)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.33...v0.34)

**Fixed bugs:**

- SBP pickle framer might be stripping  [\#113](https://github.com/swift-nav/libsbp/issues/113)

**Closed issues:**

- Change MSG\_EPHEMERIS id to be in "over the radio" group [\#98](https://github.com/swift-nav/libsbp/issues/98)

**Merged pull requests:**

- Minor JSON fixes [\#110](https://github.com/swift-nav/libsbp/pull/110)
- Release notes and changelog for v0.29 [\#100](https://github.com/swift-nav/libsbp/pull/100)

## [v0.33](https://github.com/swift-nav/libsbp/tree/v0.33) (2015-04-15)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.32...v0.33)

**Merged pull requests:**

- Rev the version to 0.33. [\#111](https://github.com/swift-nav/libsbp/pull/111)
- Updating clients from spec/ feedback on datasheet. [\#109](https://github.com/swift-nav/libsbp/pull/109)
- Incorporating final team feedback on specs for release. [\#108](https://github.com/swift-nav/libsbp/pull/108)
- Clarify description of rounded time format [\#107](https://github.com/swift-nav/libsbp/pull/107)

## [v0.32](https://github.com/swift-nav/libsbp/tree/v0.32) (2015-04-14)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.29...v0.32)

**Fixed bugs:**

- Deserializing empty payloads on MSG\_SETTINGS\_READ\_BY\_INDEX doesn't work [\#106](https://github.com/swift-nav/libsbp/issues/106)
- Generated C headers don't close Doxygen brace [\#89](https://github.com/swift-nav/libsbp/issues/89)

**Closed issues:**

- Expand JSON Serialization to entire object [\#97](https://github.com/swift-nav/libsbp/issues/97)
- Regenerate everything script  [\#77](https://github.com/swift-nav/libsbp/issues/77)
- Add tests to generator.py, update setup.py to call coverage, py.test, etc. [\#16](https://github.com/swift-nav/libsbp/issues/16)
- Port sbp\_log\_analysis to use libsbp v2 \(via pip install, probably\) [\#12](https://github.com/swift-nav/libsbp/issues/12)
- Improve landing SBP documentation. [\#7](https://github.com/swift-nav/libsbp/issues/7)
- Integrate libsbp python serial\_link.py into piksi\_firmware scripts via git submodule [\#4](https://github.com/swift-nav/libsbp/issues/4)

**Merged pull requests:**

- Move the watchdog into sbp.client [\#104](https://github.com/swift-nav/libsbp/pull/104)
- Object-based JSON serialization [\#103](https://github.com/swift-nav/libsbp/pull/103)
- Tox needs yaml for tests [\#99](https://github.com/swift-nav/libsbp/pull/99)
- Python client updates: materialization and tests. [\#96](https://github.com/swift-nav/libsbp/pull/96)
- README update. [\#93](https://github.com/swift-nav/libsbp/pull/93)
- Doxygen groups for C headers. [\#91](https://github.com/swift-nav/libsbp/pull/91)
- Baby's first Makefile. [\#82](https://github.com/swift-nav/libsbp/pull/82)
- Correct some errors in README examples [\#79](https://github.com/swift-nav/libsbp/pull/79)
- Instructions for and updates to Sphinx docs. [\#73](https://github.com/swift-nav/libsbp/pull/73)
- libsbp generator, tempate, and SBP specification update. [\#71](https://github.com/swift-nav/libsbp/pull/71)
- WIP JSON serialization [\#101](https://github.com/swift-nav/libsbp/pull/101)
- Added new shell script and line to swiftnav.sty to do a git describe [\#56](https://github.com/swift-nav/libsbp/pull/56)

## [v0.29](https://github.com/swift-nav/libsbp/tree/v0.29) (2015-04-08)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.28...v0.29)

**Merged pull requests:**

- Move the version into setup.py for now [\#75](https://github.com/swift-nav/libsbp/pull/75)

## [v0.28](https://github.com/swift-nav/libsbp/tree/v0.28) (2015-04-08)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v0.27...v0.28)

**Closed issues:**

- MsgPrint should have at least one field.  [\#57](https://github.com/swift-nav/libsbp/issues/57)
- Regenerating Doxygen, sphinx for C and Python [\#19](https://github.com/swift-nav/libsbp/issues/19)
- Update latex templating for protocol definitions [\#6](https://github.com/swift-nav/libsbp/issues/6)

**Merged pull requests:**

- libsbp to v0.28 release. [\#74](https://github.com/swift-nav/libsbp/pull/74)
- libsbp C header updates. [\#72](https://github.com/swift-nav/libsbp/pull/72)
- Updated Python client. [\#69](https://github.com/swift-nav/libsbp/pull/69)
- Doxygen docs for C bindings. [\#61](https://github.com/swift-nav/libsbp/pull/61)
- Python Sphinx docs. [\#60](https://github.com/swift-nav/libsbp/pull/60)

## [v0.27](https://github.com/swift-nav/libsbp/tree/v0.27) (2015-04-01)

**Closed issues:**

- python/README.md refers to nonexisting requirements.txt [\#50](https://github.com/swift-nav/libsbp/issues/50)
- Update documentation descriptions and payload info for various piksi.yaml messages. [\#45](https://github.com/swift-nav/libsbp/issues/45)
- Rename uarts in MSG\_UART\_STATE [\#44](https://github.com/swift-nav/libsbp/issues/44)
- Integrate SBP, language-specific developer documentation [\#18](https://github.com/swift-nav/libsbp/issues/18)
- Python client: Port serial\_link.py and deframing callbacks to existing libsbp master [\#17](https://github.com/swift-nav/libsbp/issues/17)
- Release libsbp python bindings to the Python package index. [\#13](https://github.com/swift-nav/libsbp/issues/13)
- Integrate libsbp c bindings with libswiftnav [\#11](https://github.com/swift-nav/libsbp/issues/11)
- Integrate libsbp c bindings with piksi\_firmware [\#10](https://github.com/swift-nav/libsbp/issues/10)
- Yaml spec: audit message definitions [\#8](https://github.com/swift-nav/libsbp/issues/8)
- C lib: audit C imports for libswiftnav [\#5](https://github.com/swift-nav/libsbp/issues/5)
- Tests for message deserialization. [\#1](https://github.com/swift-nav/libsbp/issues/1)

**Merged pull requests:**

- Clarifications from @denniszollo. [\#67](https://github.com/swift-nav/libsbp/pull/67)
- Updates for pypi. [\#66](https://github.com/swift-nav/libsbp/pull/66)
- Add locks to the contexts around resources. Also flushes. [\#65](https://github.com/swift-nav/libsbp/pull/65)
- LaTeX generation [\#64](https://github.com/swift-nav/libsbp/pull/64)
- `sbp.client` changes for piksi\_firmware [\#63](https://github.com/swift-nav/libsbp/pull/63)
- Publicize yaml records for document generation [\#62](https://github.com/swift-nav/libsbp/pull/62)
- Updated YAML descriptions. [\#59](https://github.com/swift-nav/libsbp/pull/59)
- libsbp cleanup [\#55](https://github.com/swift-nav/libsbp/pull/55)
- setup.py requirements update. [\#54](https://github.com/swift-nav/libsbp/pull/54)
- Examples for Python client library [\#53](https://github.com/swift-nav/libsbp/pull/53)
- YAML-specified SBP deserialization unit tests and Python test harness. [\#52](https://github.com/swift-nav/libsbp/pull/52)
- Python nonsense. [\#51](https://github.com/swift-nav/libsbp/pull/51)
- Typo. [\#49](https://github.com/swift-nav/libsbp/pull/49)
- Prev file cleanup and typos. [\#48](https://github.com/swift-nav/libsbp/pull/48)
- Type updates to SBP spec. [\#47](https://github.com/swift-nav/libsbp/pull/47)
- Update message fields for observations. [\#42](https://github.com/swift-nav/libsbp/pull/42)
- Remove unused crc routine [\#40](https://github.com/swift-nav/libsbp/pull/40)
- Generator for C and Python bindings. [\#38](https://github.com/swift-nav/libsbp/pull/38)
- Moves JSON and pickle iterators into libsbp. [\#37](https://github.com/swift-nav/libsbp/pull/37)
- Clean up setup.py, move version into SBP. [\#36](https://github.com/swift-nav/libsbp/pull/36)
- Move sbp.client to sbp. [\#35](https://github.com/swift-nav/libsbp/pull/35)
- Relocate swiftnav to sbp [\#34](https://github.com/swift-nav/libsbp/pull/34)
- Filter out swiftnav\* and tests\* modules for now [\#33](https://github.com/swift-nav/libsbp/pull/33)
- libsbp C headers and test stubs. [\#32](https://github.com/swift-nav/libsbp/pull/32)
- libsbp python bindings. [\#31](https://github.com/swift-nav/libsbp/pull/31)
- serial\_link.py -\> swiftnav.sbp.client [\#30](https://github.com/swift-nav/libsbp/pull/30)
- Updates top-level README. [\#22](https://github.com/swift-nav/libsbp/pull/22)
- Project-wide LICENSE under LGPL. [\#21](https://github.com/swift-nav/libsbp/pull/21)



\* *This Change Log was automatically generated by [github_changelog_generator](https://github.com/skywinder/Github-Changelog-Generator)*
