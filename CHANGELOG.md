# Changelog

## [v6.1.0](https://github.com/swift-nav/libsbp/tree/v6.1.0)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v6.0.1...v6.1.0)

**Merged pull requests:**

- Update libsbp codeowners [\#1427](https://github.com/swift-nav/libsbp/pull/1427) ([reimerix](https://github.com/reimerix))
- Update Additional Reviewers [\#1425](https://github.com/swift-nav/libsbp/pull/1425) ([pcrumley](https://github.com/pcrumley))
- fix rust lints [\#1424](https://github.com/swift-nav/libsbp/pull/1424) ([pcrumley](https://github.com/pcrumley))
- AES-CMAC 128 Message [\#1423](https://github.com/swift-nav/libsbp/pull/1423) ([RReichert](https://github.com/RReichert))
- Fix license [\#1421](https://github.com/swift-nav/libsbp/pull/1421) ([RReichert](https://github.com/RReichert))
- Reference only the runner name [\#1416](https://github.com/swift-nav/libsbp/pull/1416) ([fpezzinosn](https://github.com/fpezzinosn))
- Add support for QZSS constellation [\#1414](https://github.com/swift-nav/libsbp/pull/1414) ([cstolowicz](https://github.com/cstolowicz))

## [v6.0.1](https://github.com/swift-nav/libsbp/tree/v6.0.1)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v6.0.0...v6.0.1)

**Merged pull requests:**

- Change highwater -\> high water, add mutexes to spelling wordlist [\#1413](https://github.com/swift-nav/libsbp/pull/1413) ([woodfell](https://github.com/woodfell))
- Auto submodule update: cmake - ASIO gRPC boost container fix \(\#174\) [\#1412](https://github.com/swift-nav/libsbp/pull/1412) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- Add profiling messages [\#1401](https://github.com/swift-nav/libsbp/pull/1401) ([woodfell](https://github.com/woodfell))

## [v6.0.0](https://github.com/swift-nav/libsbp/tree/v6.0.0) (2024-05-07)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v5.0.8...v6.0.0)

**Merged pull requests:**

- Auto submodule update: cmake - enable c++20 \(\#173\) [\#1411](https://github.com/swift-nav/libsbp/pull/1411) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- Fix kaitai py tests [\#1410](https://github.com/swift-nav/libsbp/pull/1410) ([woodfell](https://github.com/woodfell))
- Alter release process in line with recent observations [\#1406](https://github.com/swift-nav/libsbp/pull/1406) ([woodfell](https://github.com/woodfell))
- Remove legacy C API [\#1404](https://github.com/swift-nav/libsbp/pull/1404) ([woodfell](https://github.com/woodfell))


## [v5.0.8](https://github.com/swift-nav/libsbp/tree/v5.0.8) (2024-03-29)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v5.0.7...v5.0.8)

**Merged pull requests:**

- Fix new clippy lints [\#1408](https://github.com/swift-nav/libsbp/pull/1408) ([pcrumley](https://github.com/pcrumley))
- Add description for constellation identifier to bounds messages [\#1407](https://github.com/swift-nav/libsbp/pull/1407) ([IsakTjernberg](https://github.com/IsakTjernberg))
- Add weeks behavior flag to MSG\_GNSS\_TIME\_OFFSET [\#1405](https://github.com/swift-nav/libsbp/pull/1405) ([jakalm](https://github.com/jakalm))

## [v5.0.7](https://github.com/swift-nav/libsbp/tree/v5.0.7) (2024-03-18)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v5.0.6...v5.0.7)

**Merged pull requests:**

- Add ASAN and UBSAN stages to CI, fix various errors [\#1403](https://github.com/swift-nav/libsbp/pull/1403) ([woodfell](https://github.com/woodfell))
- Disable Java sonar stage [\#1402](https://github.com/swift-nav/libsbp/pull/1402) ([woodfell](https://github.com/woodfell))

## [v5.0.6](https://github.com/swift-nav/libsbp/tree/v5.0.6) (2024-01-16)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v5.0.5...v5.0.6)

**Merged pull requests:**

- Add --unbuffered option to sbp2json.py [\#1400](https://github.com/swift-nav/libsbp/pull/1400) ([dgburr](https://github.com/dgburr))
- Auto submodule update: cmake - ASIO C++ and ASIO Grpc libraries [\#1399](https://github.com/swift-nav/libsbp/pull/1399) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- Bump docker image used for rust build to 1.65 [\#1396](https://github.com/swift-nav/libsbp/pull/1396) ([dgburr](https://github.com/dgburr))
- Add MsgMeasurementPoint [\#1388](https://github.com/swift-nav/libsbp/pull/1388) ([woodfell](https://github.com/woodfell))

## [v5.0.5](https://github.com/swift-nav/libsbp/tree/v5.0.5) (2024-01-03)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v5.0.4...v5.0.5)

**Closed issues:**

- `MsgUtcTime` implementation of `gps\_time` is not checking status flags [\#1385](https://github.com/swift-nav/libsbp/issues/1385)

**Merged pull requests:**

- Change default codeowner of /c from platform to algint [\#1398](https://github.com/swift-nav/libsbp/pull/1398) ([woodfell](https://github.com/woodfell))
- Don't use deprecated functions in sbp impl [\#1397](https://github.com/swift-nav/libsbp/pull/1397) ([woodfell](https://github.com/woodfell))
- Clarify timestamping descriptions  [\#1395](https://github.com/swift-nav/libsbp/pull/1395) ([reimerix](https://github.com/reimerix))
- Parallel build all C tests from top level makefile  [\#1394](https://github.com/swift-nav/libsbp/pull/1394) ([woodfell](https://github.com/woodfell))
- Use docker in GA  [\#1393](https://github.com/swift-nav/libsbp/pull/1393) ([woodfell](https://github.com/woodfell))
- Bump node.js version to 18.17.0  [\#1392](https://github.com/swift-nav/libsbp/pull/1392) ([woodfell](https://github.com/woodfell))
- update web structs [\#1391](https://github.com/swift-nav/libsbp/pull/1391) ([pcrumley](https://github.com/pcrumley))
- update how to for new rust instruction [\#1390](https://github.com/swift-nav/libsbp/pull/1390) ([pcrumley](https://github.com/pcrumley))
- remove -i option from sed [\#1389](https://github.com/swift-nav/libsbp/pull/1389) ([pcrumley](https://github.com/pcrumley))
- Add missing bindings to check generated artefacts CI stage  [\#1387](https://github.com/swift-nav/libsbp/pull/1387) ([woodfell](https://github.com/woodfell))
- reduce number of python tests to 2 [\#1386](https://github.com/swift-nav/libsbp/pull/1386) ([pcrumley](https://github.com/pcrumley))
- Deprecate legacy API  [\#1373](https://github.com/swift-nav/libsbp/pull/1373) ([woodfell](https://github.com/woodfell))

## [v5.0.4](https://github.com/swift-nav/libsbp/tree/v5.0.4) (2023-12-07)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v5.0.3...v5.0.4)

**Closed issues:**

- `MsgGpsTime` implementation of `gps\_time` is not checking status flags [\#1363](https://github.com/swift-nav/libsbp/issues/1363)

**Merged pull requests:**

- Fix rust and js tests [\#1383](https://github.com/swift-nav/libsbp/pull/1383) ([woodfell](https://github.com/woodfell))
- Fix decoding of truncated messages containing variable length arrays [\#1381](https://github.com/swift-nav/libsbp/pull/1381) ([woodfell](https://github.com/woodfell))
- Replace swiftnav-adam with woodfell for additional reviewers [\#1380](https://github.com/swift-nav/libsbp/pull/1380) ([woodfell](https://github.com/woodfell))
- Fix incorrect specification of directory contents in read dir resp [\#1379](https://github.com/swift-nav/libsbp/pull/1379) ([woodfell](https://github.com/woodfell))
- Fix decoding fixed length arrays of struct in python sbp2json [\#1378](https://github.com/swift-nav/libsbp/pull/1378) ([woodfell](https://github.com/woodfell))
- Increase test coverage of C code [\#1377](https://github.com/swift-nav/libsbp/pull/1377) ([woodfell](https://github.com/woodfell))
- rust: check more messages for time validity [\#1376](https://github.com/swift-nav/libsbp/pull/1376) ([notoriaga](https://github.com/notoriaga))
- rust: check time source for MsgGpsTime [\#1375](https://github.com/swift-nav/libsbp/pull/1375) ([notoriaga](https://github.com/notoriaga))
- Run sonar cloud on C/C++ bindings [\#1374](https://github.com/swift-nav/libsbp/pull/1374) ([woodfell](https://github.com/woodfell))
- ignore dependabot PRs for additional reviewers action [\#1372](https://github.com/swift-nav/libsbp/pull/1372) ([adrian-kong](https://github.com/adrian-kong))
- Bon voyage! [\#1370](https://github.com/swift-nav/libsbp/pull/1370) ([pcrumley](https://github.com/pcrumley))

## [v5.0.3](https://github.com/swift-nav/libsbp/tree/v5.0.3) (2023-10-19)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v5.0.2...v5.0.3)

**Merged pull requests:**

- handle new clippy lints [\#1364](https://github.com/swift-nav/libsbp/pull/1364) ([pcrumley](https://github.com/pcrumley))
- Auto submodule update: cmake - Add suitesparse finder file \[OC-310\] \(\#167\) [\#1362](https://github.com/swift-nav/libsbp/pull/1362) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
## [v5.0.2](https://github.com/swift-nav/libsbp/tree/v5.0.2) (2023-09-07)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v5.0.1...v5.0.2)

**Merged pull requests:**

- Auto submodule update: cmake - Enable starling-core test libs \[AP-454\] \(\#166\) [\#1360](https://github.com/swift-nav/libsbp/pull/1360) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- fix bug [\#1359](https://github.com/swift-nav/libsbp/pull/1359) ([pcrumley](https://github.com/pcrumley))
- fix new clippy warning in rust 1.71 [\#1358](https://github.com/swift-nav/libsbp/pull/1358) ([pcrumley](https://github.com/pcrumley))
- Auto submodule update: cmake - Update CODEOWNERS \(\#163\) [\#1357](https://github.com/swift-nav/libsbp/pull/1357) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))

## [v5.0.1](https://github.com/swift-nav/libsbp/tree/v5.0.1) (2023-08-24)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v5.0.0...v5.0.1)

**Merged pull requests:**

- Remove SBP\_SENDER\_ID: it is not used anywhere and can conflict with user code [\#1355](https://github.com/swift-nav/libsbp/pull/1355) ([dgburr](https://github.com/dgburr))
- update the howto [\#1354](https://github.com/swift-nav/libsbp/pull/1354) ([pcrumley](https://github.com/pcrumley))

## [v5.0.0](https://github.com/swift-nav/libsbp/tree/v5.0.0) (2023-08-10)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v4.17.0...v5.0.0)

**Merged pull requests:**

- Auto submodule update: cmake - add CODEOWNERS \(\#161\) [\#1353](https://github.com/swift-nav/libsbp/pull/1353) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- add test to round trip an invalid sbp message [\#1352](https://github.com/swift-nav/libsbp/pull/1352) ([pcrumley](https://github.com/pcrumley))
- Auto submodule update: cmake - Clang tidy Google Style Guide \(\#155\) [\#1351](https://github.com/swift-nav/libsbp/pull/1351) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- prep next release \#no\_auto\_pr [\#1350](https://github.com/swift-nav/libsbp/pull/1350) ([adrian-kong](https://github.com/adrian-kong))
- Parse error falls back to Invalid [\#1312](https://github.com/swift-nav/libsbp/pull/1312) ([adrian-kong](https://github.com/adrian-kong))

## [v4.17.0](https://github.com/swift-nav/libsbp/tree/v4.17.0) (2023-07-18)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v4.16.0...v4.17.0)

**Merged pull requests:**

- Auto submodule update: cmake - Don't fail sanitizer builds on failed optimizations [\#1348](https://github.com/swift-nav/libsbp/pull/1348) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- rust: ability to convert to common serde map structure [\#1346](https://github.com/swift-nav/libsbp/pull/1346) ([silverjam](https://github.com/silverjam))
- Add APC types \[OI-89\] [\#1345](https://github.com/swift-nav/libsbp/pull/1345) ([armallen](https://github.com/armallen))
- Add function to convert sbp\_msg\_type\_t to string \[ESD-2613\] [\#1344](https://github.com/swift-nav/libsbp/pull/1344) ([woodfell](https://github.com/woodfell))

## [v4.16.0](https://github.com/swift-nav/libsbp/tree/v4.16.0) (2023-06-29)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v4.15.0...v4.16.0)

**Closed issues:**

- Week number is always 0 in Message Protection Level [\#1340](https://github.com/swift-nav/libsbp/issues/1340)
- Unknown CMake command "add\_link\_options" [\#1320](https://github.com/swift-nav/libsbp/issues/1320)

**Merged pull requests:**

- Auto submodule update: cmake - rename starling-core-utils \[STR-195\] \(\#156\) [\#1343](https://github.com/swift-nav/libsbp/pull/1343) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- c: bump minimum cmake to 3.13 [\#1342](https://github.com/swift-nav/libsbp/pull/1342) ([silverjam](https://github.com/silverjam))
- Auto submodule update: cmake - fix: make test\_srcs target project specific \(\#158\) [\#1341](https://github.com/swift-nav/libsbp/pull/1341) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- Add tdk-icm42670 to imu.yaml [\#1338](https://github.com/swift-nav/libsbp/pull/1338) ([EricCalgary](https://github.com/EricCalgary))
- Fix/improve construct version of sbp2json [\#1337](https://github.com/swift-nav/libsbp/pull/1337) ([dgburr](https://github.com/dgburr))
- Generate Kaitai Struct Format Descriptions and run Kaitai Struct Compiler to generate language bindings [\#1336](https://github.com/swift-nav/libsbp/pull/1336) ([dgburr](https://github.com/dgburr))
- prep next release \#no\_auto\_pr [\#1335](https://github.com/swift-nav/libsbp/pull/1335) ([adrian-kong](https://github.com/adrian-kong))

## [v4.15.0](https://github.com/swift-nav/libsbp/tree/v4.15.0) (2023-05-29)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v4.14.1...v4.15.0)

## [v4.14.1](https://github.com/swift-nav/libsbp/tree/v4.14.1)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v4.14.0...v4.14.1)

**Closed issues:**

- Cannot access `GPSTime` inside `BaseTime` [\#1331](https://github.com/swift-nav/libsbp/issues/1331)

**Merged pull requests:**

- pass all features to docs.rs build [\#1333](https://github.com/swift-nav/libsbp/pull/1333) ([pcrumley](https://github.com/pcrumley))
- Make the BaseTime inner public [\#1332](https://github.com/swift-nav/libsbp/pull/1332) ([pcrumley](https://github.com/pcrumley))
- Auto submodule update: cmake - Fix TEST\_SRCS property - use CMAKE\_SOURCE\_DIR \(\#154\) [\#1330](https://github.com/swift-nav/libsbp/pull/1330) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- Make MSG\_INS\_UPDATES public \[DEVINFRA-1066\] [\#1329](https://github.com/swift-nav/libsbp/pull/1329) ([ljbade](https://github.com/ljbade))
- Miscellaneous SBP doc updates \[DEVINFRA-1065\] [\#1328](https://github.com/swift-nav/libsbp/pull/1328) ([ljbade](https://github.com/ljbade))
- docker: pin key python tools \(tox, sphinx\) [\#1327](https://github.com/swift-nav/libsbp/pull/1327) ([silverjam](https://github.com/silverjam))
- Add description of difference between \_GNSS messages and fused messages \[DEVINFRA-566\] [\#1326](https://github.com/swift-nav/libsbp/pull/1326) ([ljbade](https://github.com/ljbade))
- pin rust test deps [\#1325](https://github.com/swift-nav/libsbp/pull/1325) ([silverjam](https://github.com/silverjam))
- Auto submodule update: cmake - add FindBoringSSL.cmake \(\#152\) [\#1324](https://github.com/swift-nav/libsbp/pull/1324) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- prep next release \#no\_auto\_pr [\#1323](https://github.com/swift-nav/libsbp/pull/1323) ([adrian-kong](https://github.com/adrian-kong))

## [v4.14.0](https://github.com/swift-nav/libsbp/tree/v4.14.0) (2023-04-28)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v4.13.0...v4.14.0)

**Merged pull requests:**

- python: add framer msg type filter [\#1321](https://github.com/swift-nav/libsbp/pull/1321) ([silverjam](https://github.com/silverjam))
- Auto submodule update: cmake - Add TEST\_SRCS property and swift\_add\_test\_srcs\_target macro \[BUILD-657\] \(\#151\) [\#1319](https://github.com/swift-nav/libsbp/pull/1319) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- Auto submodule update: cmake - Add official MKL cmake finder. \(\#147\) [\#1318](https://github.com/swift-nav/libsbp/pull/1318) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- docs: correct time source for fast-start use case [\#1316](https://github.com/swift-nav/libsbp/pull/1316) ([silverjam](https://github.com/silverjam))
- bazel: Export sbp headers \[BUILD-650\] [\#1315](https://github.com/swift-nav/libsbp/pull/1315) ([krisukox](https://github.com/krisukox))
- Bump cmake submodule \[SEN-798\] [\#1313](https://github.com/swift-nav/libsbp/pull/1313) ([reimerix](https://github.com/reimerix))
- prep next release \#no\_auto\_pr [\#1311](https://github.com/swift-nav/libsbp/pull/1311) ([adrian-kong](https://github.com/adrian-kong))

## [v4.13.0](https://github.com/swift-nav/libsbp/tree/v4.13.0) (2023-03-28)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v4.12.0...v4.13.0)

**Merged pull requests:**

- Auto submodule update: cmake - Turn SonarCloud duplicate detection off for unit tests \(\#150\) [\#1310](https://github.com/swift-nav/libsbp/pull/1310) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- Update bazel to be able to build [\#1309](https://github.com/swift-nav/libsbp/pull/1309) ([RReichert](https://github.com/RReichert))
- Upgrade google test to 1.11 [\#1308](https://github.com/swift-nav/libsbp/pull/1308) ([RReichert](https://github.com/RReichert))
- fix signature in MsgCertificateChain \[GV2-193\]  [\#1307](https://github.com/swift-nav/libsbp/pull/1307) ([notoriaga](https://github.com/notoriaga))
- variable length ecdsa signature \[GV2-193\] [\#1306](https://github.com/swift-nav/libsbp/pull/1306) ([notoriaga](https://github.com/notoriaga))
- bazel: use c only macros \[BUILD-560\] [\#1305](https://github.com/swift-nav/libsbp/pull/1305) ([isaactorz](https://github.com/isaactorz))
- Add identifier for TDK IAM-20680HP IMU \[ESD-2563\] [\#1304](https://github.com/swift-nav/libsbp/pull/1304) ([woodfell](https://github.com/woodfell))
- update MSG\_ACKNOWLEDGE on demand fields [\#1303](https://github.com/swift-nav/libsbp/pull/1303) ([notoriaga](https://github.com/notoriaga))
- signing: add new ECDSA based signature messages [\#1302](https://github.com/swift-nav/libsbp/pull/1302) ([silverjam](https://github.com/silverjam))
- Auto submodule update: cmake - Remove pvt-runner-lib from search libraries in starling target \(\#148\) [\#1301](https://github.com/swift-nav/libsbp/pull/1301) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- bazel add gen\_compile\_commands target \[BUILD-547\] [\#1300](https://github.com/swift-nav/libsbp/pull/1300) ([wwieclaw](https://github.com/wwieclaw))
- enforce setup CI gradle v7.1.1 [\#1298](https://github.com/swift-nav/libsbp/pull/1298) ([adrian-kong](https://github.com/adrian-kong))
- prep next release \#no\_auto\_pr [\#1297](https://github.com/swift-nav/libsbp/pull/1297) ([adrian-kong](https://github.com/adrian-kong))

## [v4.12.0](https://github.com/swift-nav/libsbp/tree/v4.12.0) (2023-02-27)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v4.11.0...v4.12.0)

**Merged pull requests:**

- Auto submodule update: cmake - Exclude unit test header files from coverage reporting \(\#145\) [\#1295](https://github.com/swift-nav/libsbp/pull/1295) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- make it so all .rs files are treated as text files for git diffs [\#1294](https://github.com/swift-nav/libsbp/pull/1294) ([pcrumley](https://github.com/pcrumley))
- new rust clippy [\#1292](https://github.com/swift-nav/libsbp/pull/1292) ([adrian-kong](https://github.com/adrian-kong))
- Add support for murata scha634 to imu aux message [\#1286](https://github.com/swift-nav/libsbp/pull/1286) ([antrikshsrivastava](https://github.com/antrikshsrivastava))

## [v4.11.0](https://github.com/swift-nav/libsbp/tree/v4.11.0) (2023-01-25)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v4.10.0...v4.11.0)

**Merged pull requests:**

- ci: auto request additional reviewers \(doc review\) [\#1291](https://github.com/swift-nav/libsbp/pull/1291) ([silverjam](https://github.com/silverjam))
- Add MSG\_TEL\_SV:  per-SV telemetry message  \[POS-913\] [\#1290](https://github.com/swift-nav/libsbp/pull/1290) ([ismolyakov](https://github.com/ismolyakov))
- Added Makefile with bazel wrappers \[BUILD-360\] [\#1289](https://github.com/swift-nav/libsbp/pull/1289) ([wwieclaw](https://github.com/wwieclaw))
- Add test for SBP-1534 STEC list empty [\#1287](https://github.com/swift-nav/libsbp/pull/1287) ([JADC362](https://github.com/JADC362))
- Add new SSR Satellite APC and Tile Definition message \[PC-116\] [\#1284](https://github.com/swift-nav/libsbp/pull/1284) ([Davinco](https://github.com/Davinco))
- build\(deps\): bump json5 from 1.0.1 to 1.0.2 [\#1283](https://github.com/swift-nav/libsbp/pull/1283) ([dependabot[bot]](https://github.com/apps/dependabot))
- prep release \#no\_auto\_pr [\#1281](https://github.com/swift-nav/libsbp/pull/1281) ([adrian-kong](https://github.com/adrian-kong))

## [v4.10.0](https://github.com/swift-nav/libsbp/tree/v4.10.0) (2022-12-22)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v4.9.0...v4.10.0)

**Closed issues:**

- \[C++\] MessageTrait: name attribute [\#1240](https://github.com/swift-nav/libsbp/issues/1240)

**Merged pull requests:**

- bazel: Pin Bazel to 5.x [\#1279](https://github.com/swift-nav/libsbp/pull/1279) ([isaactorz](https://github.com/isaactorz))
- C++ MessageTrait name attribute \[DEVINFRA-1034\] [\#1278](https://github.com/swift-nav/libsbp/pull/1278) ([ljbade](https://github.com/ljbade))
- Auto submodule update: cmake - Don't fail on empty diffs when running clang-format [\#1277](https://github.com/swift-nav/libsbp/pull/1277) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- rust clippy [\#1276](https://github.com/swift-nav/libsbp/pull/1276) ([adrian-kong](https://github.com/adrian-kong))
- add haskell cache \[DEVINFRA-470\] [\#1275](https://github.com/swift-nav/libsbp/pull/1275) ([adrian-kong](https://github.com/adrian-kong))
- Cmake submodule update [\#1274](https://github.com/swift-nav/libsbp/pull/1274) ([RReichert](https://github.com/RReichert))
- Auto submodule update: cmake - Add a script supporting ratcheting for clang-tidy warnings [\#1273](https://github.com/swift-nav/libsbp/pull/1273) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- change maven publish to dev email [\#1271](https://github.com/swift-nav/libsbp/pull/1271) ([adrian-kong](https://github.com/adrian-kong))
- impl HasTime for Result Frame \[DEVINFRA-1031\] [\#1267](https://github.com/swift-nav/libsbp/pull/1267) ([adrian-kong](https://github.com/adrian-kong))
- small rust fixup [\#1266](https://github.com/swift-nav/libsbp/pull/1266) ([adrian-kong](https://github.com/adrian-kong))
- Add frame iterators [\#1265](https://github.com/swift-nav/libsbp/pull/1265) ([adrian-kong](https://github.com/adrian-kong))
- rust: include original message in TryFrom Error [\#1264](https://github.com/swift-nav/libsbp/pull/1264) ([notoriaga](https://github.com/notoriaga))
- add MsgAcknowledge [\#1263](https://github.com/swift-nav/libsbp/pull/1263) ([notoriaga](https://github.com/notoriaga))
- add friendly\_name method \[DEVINFRA-1045\] [\#1262](https://github.com/swift-nav/libsbp/pull/1262) ([adrian-kong](https://github.com/adrian-kong))
- build\(deps\): bump qs from 6.5.2 to 6.5.3 [\#1261](https://github.com/swift-nav/libsbp/pull/1261) ([dependabot[bot]](https://github.com/apps/dependabot))

## [v4.9.0](https://github.com/swift-nav/libsbp/tree/v4.9.0) (2022-10-28)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v4.8.0...v4.9.0)

**Merged pull requests:**

- from\_parts generated methods [\#1232](https://github.com/swift-nav/libsbp/pull/1232) ([adrian-kong](https://github.com/adrian-kong))
- bazel: add swift\_cc\* wrappers \[BUILD-339\] [\#1231](https://github.com/swift-nav/libsbp/pull/1231) ([isaactorz](https://github.com/isaactorz))
- pre-release v4.8.1-alpha [\#1230](https://github.com/swift-nav/libsbp/pull/1230) ([adrian-kong](https://github.com/adrian-kong))
- Sbp Raw Decoder [\#1218](https://github.com/swift-nav/libsbp/pull/1218) ([adrian-kong](https://github.com/adrian-kong))
- SbpString helpers [\#1216](https://github.com/swift-nav/libsbp/pull/1216) ([adrian-kong](https://github.com/adrian-kong))

## [v4.8.0](https://github.com/swift-nav/libsbp/tree/v4.8.0) (2020-09-29)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v4.7.0...HEAD)

**Merged pull requests:**

- Auto submodule update: cmake - Add find module for Auk \(\#135\) [\#1229](https://github.com/swift-nav/libsbp/pull/1229) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- Fix Include Paths in Bazel Build [\#1228](https://github.com/swift-nav/libsbp/pull/1228) ([isaactorz](https://github.com/isaactorz))
- Add bazel build for libsbp c library [\#1224](https://github.com/swift-nav/libsbp/pull/1224) ([isaactorz](https://github.com/isaactorz))
- Auto submodule update: cmake - Fix compile\_commands.json generation in newer cmake versions \[BUILD-286\] \(\#132\) [\#1222](https://github.com/swift-nav/libsbp/pull/1222) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- Additional documentation for MSG-1534 \[OTA-284\] [\#1220](https://github.com/swift-nav/libsbp/pull/1220) ([fpezzinosn](https://github.com/fpezzinosn))
- Auto submodule update: cmake - Ability to Enable Extra Clang-Tidy Flags \[BUILD-293\] \(\#131\) [\#1219](https://github.com/swift-nav/libsbp/pull/1219) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- rust: pin vergen [\#1217](https://github.com/swift-nav/libsbp/pull/1217) ([silverjam](https://github.com/silverjam))
- Add fuzz testing for libsbp - Add CRC bypass \[ESD-2473\] [\#1212](https://github.com/swift-nav/libsbp/pull/1212) ([lucasle-sn](https://github.com/lucasle-sn))

## [v4.7.0](https://github.com/swift-nav/libsbp/tree/v4.7.0) (2022-08-31)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v4.6.0...v4.7.0)

**Merged pull requests:**

- Auto submodule update: cmake - compile compile command cleanup \(\#130\) [\#1215](https://github.com/swift-nav/libsbp/pull/1215) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- Auto submodule update: cmake - Fix empty test source files \(\#129\) [\#1214](https://github.com/swift-nav/libsbp/pull/1214) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- Auto submodule update: cmake - Fix Sonarcloud sonar-project.properties \(\#127\) [\#1213](https://github.com/swift-nav/libsbp/pull/1213) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- Auto submodule update: cmake - Remove checks introduced between clang tidy 6 and 14 \(\#125\) [\#1211](https://github.com/swift-nav/libsbp/pull/1211) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- Include the Integrity usage flag states \[OTA-266\] [\#1209](https://github.com/swift-nav/libsbp/pull/1209) ([fpezzinosn](https://github.com/fpezzinosn))
- signing: promote signing messages out of staging \[FIC-443\] [\#1208](https://github.com/swift-nav/libsbp/pull/1208) ([silverjam](https://github.com/silverjam))
- Removes units and details of probable future use from reserved message fields \[OTA-197\] [\#1202](https://github.com/swift-nav/libsbp/pull/1202) ([jtec](https://github.com/jtec))
- Automatically create alias targets in cmake - Submodule update \[ESD-2467\] [\#1199](https://github.com/swift-nav/libsbp/pull/1199) ([lucasle-sn](https://github.com/lucasle-sn))

## [v4.6.0](https://github.com/swift-nav/libsbp/tree/v4.6.0) (2022-08-04)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v4.5.0...v4.6.0)

**Closed issues:**

- GPS Trace different than the ENU Trace [\#1195](https://github.com/swift-nav/libsbp/issues/1195)

**Merged pull requests:**

- Hooking package-register updater [\#1203](https://github.com/swift-nav/libsbp/pull/1203) ([adrian-kong](https://github.com/adrian-kong))
- Allows any string identifier for target and source frame names of MSG\_REFERENCE\_FRAME\_PARAM message \[OTA-198\] [\#1201](https://github.com/swift-nav/libsbp/pull/1201) ([jtec](https://github.com/jtec))
- Auto submodule update: cmake - Rollback SonarCloud Changes \(\#126\) [\#1200](https://github.com/swift-nav/libsbp/pull/1200) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- Added sbp2json test [\#1198](https://github.com/swift-nav/libsbp/pull/1198) ([adrian-kong](https://github.com/adrian-kong))
- Added json sbp rust tests [\#1196](https://github.com/swift-nav/libsbp/pull/1196) ([adrian-kong](https://github.com/adrian-kong))
- build\(deps\): bump terser from 4.6.6 to 4.8.1 [\#1194](https://github.com/swift-nav/libsbp/pull/1194) ([dependabot[bot]](https://github.com/apps/dependabot))
- Auto submodule update: cmake - sonarcloud: Use Inclusions Property \(\#121\) [\#1193](https://github.com/swift-nav/libsbp/pull/1193) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- Auto submodule update: cmake - Fix Sonarcloud sonar-project.properties \(\#120\) [\#1192](https://github.com/swift-nav/libsbp/pull/1192) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- rust: fix serde feature for standalone compilation [\#1191](https://github.com/swift-nav/libsbp/pull/1191) ([silverjam](https://github.com/silverjam))
- make serde feature depend on serde-big-array [\#1190](https://github.com/swift-nav/libsbp/pull/1190) ([silverjam](https://github.com/silverjam))
- Auto submodule update: cmake - Add clang format 11 \(\#119\) [\#1189](https://github.com/swift-nav/libsbp/pull/1189) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- Auto submodule update: cmake - Allow project wide default setting for exceptions and rtti \(\#118\) [\#1188](https://github.com/swift-nav/libsbp/pull/1188) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- rust: remove usage examples [\#1187](https://github.com/swift-nav/libsbp/pull/1187) ([silverjam](https://github.com/silverjam))
- Add staging fixes to master [\#1185](https://github.com/swift-nav/libsbp/pull/1185) ([samvrlewis](https://github.com/samvrlewis))
- Add stubbed signing messages \[GV2-90\] [\#1184](https://github.com/swift-nav/libsbp/pull/1184) ([samvrlewis](https://github.com/samvrlewis))
- json2sbp: construct sbp from json fields [\#1183](https://github.com/swift-nav/libsbp/pull/1183) ([adrian-kong](https://github.com/adrian-kong))
- Adds javadoc generator test [\#1182](https://github.com/swift-nav/libsbp/pull/1182) ([adrian-kong](https://github.com/adrian-kong))
- Enforce Java 11 in build gradle [\#1181](https://github.com/swift-nav/libsbp/pull/1181) ([adrian-kong](https://github.com/adrian-kong))
- \[DEVINFRA-806\] Updated CHANGELOG and prep for next release [\#1179](https://github.com/swift-nav/libsbp/pull/1179) ([adrian-kong](https://github.com/adrian-kong))

## [v4.5.0](https://github.com/swift-nav/libsbp/tree/v4.5.0) (2022-07-01)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v4.4.0...v4.5.0)

**Merged pull requests:**

- Auto submodule update: cmake - Add find module for starling-core \(\#116\) [\#1173](https://github.com/swift-nav/libsbp/pull/1173) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- fix typo in docs [\#1172](https://github.com/swift-nav/libsbp/pull/1172) ([fpezzinosn](https://github.com/fpezzinosn))
- Auto submodule update: cmake - Add Module For Checking Atomic \(\#117\) [\#1171](https://github.com/swift-nav/libsbp/pull/1171) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- Promote messages from staging to master \[OTA-172\] [\#1170](https://github.com/swift-nav/libsbp/pull/1170) ([fpezzinosn](https://github.com/fpezzinosn))

## [v4.4.0](https://github.com/swift-nav/libsbp/tree/v4.4.0) (2022-06-15)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v4.3.3...v4.4.0)

**Merged pull requests:**

- rust: add partialeq [\#1169](https://github.com/swift-nav/libsbp/pull/1169) ([silverjam](https://github.com/silverjam))
- fixing rust build script [\#1167](https://github.com/swift-nav/libsbp/pull/1167) ([adrian-kong](https://github.com/adrian-kong))
- docker and doc fix-ups [\#1166](https://github.com/swift-nav/libsbp/pull/1166) ([silverjam](https://github.com/silverjam))
- Update navigation stubbed msgs names \[OTA-161\] [\#1156](https://github.com/swift-nav/libsbp/pull/1156) ([fpezzinosn](https://github.com/fpezzinosn))

## [v4.3.3](https://github.com/swift-nav/libsbp/tree/v4.3.3) (2022-06-09)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v4.3.2...v4.3.3)

**Merged pull requests:**

- Update CHANGELOG.md [\#1165](https://github.com/swift-nav/libsbp/pull/1165) ([adrian-kong](https://github.com/adrian-kong))
- Locked stdin and out for rust sbp2json [\#1161](https://github.com/swift-nav/libsbp/pull/1161) ([adrian-kong](https://github.com/adrian-kong))
- build\(deps\): bump generic-array from 0.12.3 to 0.12.4 in /rust/sbp2json [\#1159](https://github.com/swift-nav/libsbp/pull/1159) ([dependabot[bot]](https://github.com/apps/dependabot))
- Added version params, --version, -V to rust sbp2json [\#1158](https://github.com/swift-nav/libsbp/pull/1158) ([adrian-kong](https://github.com/adrian-kong))
- Python 3.10 update \[DEVINFRA-769\] [\#1157](https://github.com/swift-nav/libsbp/pull/1157) ([adrian-kong](https://github.com/adrian-kong))

## [v4.3.1](https://github.com/swift-nav/libsbp/tree/v4.3.1) (2022-06-03)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v4.3.0...v4.3.1)

**Merged pull requests:**

- python: consolidate converage settings [\#1154](https://github.com/swift-nav/libsbp/pull/1154) ([silverjam](https://github.com/silverjam))
- docker: add back apt, focal only, tox fixes [\#1153](https://github.com/swift-nav/libsbp/pull/1153) ([silverjam](https://github.com/silverjam))
- add parallel tox, remove python 2.7 support [\#1152](https://github.com/swift-nav/libsbp/pull/1152) ([silverjam](https://github.com/silverjam))

## [v4.3.0](https://github.com/swift-nav/libsbp/tree/v4.3.0) (2022-05-25)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v4.2.0...v4.3.0)

**Merged pull requests:**

- validator: skip stubbed messages \[OTA-150\] [\#1151](https://github.com/swift-nav/libsbp/pull/1151) ([silverjam](https://github.com/silverjam))
- hide stubbed messages from sbp.pdf [\#1148](https://github.com/swift-nav/libsbp/pull/1148) ([fpezzinosn](https://github.com/fpezzinosn))
- make: add commands to detect staging [\#1146](https://github.com/swift-nav/libsbp/pull/1146) ([silverjam](https://github.com/silverjam))
- sbp2json small usage comment fix [\#1143](https://github.com/swift-nav/libsbp/pull/1143) ([adrian-kong](https://github.com/adrian-kong))
- Added input and output parameters to rust sbp2json [\#1142](https://github.com/swift-nav/libsbp/pull/1142) ([adrian-kong](https://github.com/adrian-kong))
- ci: enable on staging branch [\#1135](https://github.com/swift-nav/libsbp/pull/1135) ([silverjam](https://github.com/silverjam))
- validator: allow message deprecation [\#1134](https://github.com/swift-nav/libsbp/pull/1134) ([silverjam](https://github.com/silverjam))
- Converted structopt into clap [\#1133](https://github.com/swift-nav/libsbp/pull/1133) ([adrian-kong](https://github.com/adrian-kong))
- Add stubbed version of new Integrity Bounds/Flags \[OTA-134\] [\#1130](https://github.com/swift-nav/libsbp/pull/1130) ([fpezzinosn](https://github.com/fpezzinosn))
- Fixing unconsumed 4096 error sbp2json [\#1128](https://github.com/swift-nav/libsbp/pull/1128) ([adrian-kong](https://github.com/adrian-kong))
- Generate missing tests via JSON [\#1125](https://github.com/swift-nav/libsbp/pull/1125) ([adrian-kong](https://github.com/adrian-kong))
- Update sbp Docs to Include L5 Signals [\#1124](https://github.com/swift-nav/libsbp/pull/1124) ([isaactorz](https://github.com/isaactorz))
- Runnable sbp java example [\#1122](https://github.com/swift-nav/libsbp/pull/1122) ([adrian-kong](https://github.com/adrian-kong))

## [v4.2.0](https://github.com/swift-nav/libsbp/tree/v4.2.0) (2022-05-03)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v4.1.6...v4.2.0)

**Merged pull requests:**

- Add MSG\_STATUS\_JOURNAL \[4.1.x\] [\#1126](https://github.com/swift-nav/libsbp/pull/1126) ([silverjam](https://github.com/silverjam))
- Deploying tarball to pypi [\#1121](https://github.com/swift-nav/libsbp/pull/1121) ([adrian-kong](https://github.com/adrian-kong))
- Auto submodule update: cmake - clang-tidy: allow target to be disabled \(\#109\) [\#1120](https://github.com/swift-nav/libsbp/pull/1120) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- Publishing to maven central [\#1119](https://github.com/swift-nav/libsbp/pull/1119) ([adrian-kong](https://github.com/adrian-kong))
- Updating libraries and headers to 2022 [\#1118](https://github.com/swift-nav/libsbp/pull/1118) ([adrian-kong](https://github.com/adrian-kong))
- Fix rust release.toml and haskell sbp.cabal. [\#1117](https://github.com/swift-nav/libsbp/pull/1117) ([john-michaelburke](https://github.com/john-michaelburke))

## [v4.1.6](https://github.com/swift-nav/libsbp/tree/v4.1.6) (2022-04-13)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v4.1.5...v4.1.6)

**Merged pull requests:**

- Add generated copyright messages [\#1114](https://github.com/swift-nav/libsbp/pull/1114) ([joelynch](https://github.com/joelynch))
- Added TCPExample for Java client [\#1112](https://github.com/swift-nav/libsbp/pull/1112) ([adrian-kong](https://github.com/adrian-kong))
- Add a rust sbp iterator variant with timeout [\#1111](https://github.com/swift-nav/libsbp/pull/1111) ([john-michaelburke](https://github.com/john-michaelburke))
- Fix C Bitfield Macros [\#1110](https://github.com/swift-nav/libsbp/pull/1110) ([isaactorz](https://github.com/isaactorz))
- Suppressed warnings and deprecation notices for Java [\#1107](https://github.com/swift-nav/libsbp/pull/1107) ([adrian-kong](https://github.com/adrian-kong))
- Fix Bitfield Ranges in MSG\_STARTUP [\#1106](https://github.com/swift-nav/libsbp/pull/1106) ([isaactorz](https://github.com/isaactorz))
- Add a SbpMsgUnknown type in for the sbp\_msg\_type\_t enum [\#1105](https://github.com/swift-nav/libsbp/pull/1105) ([lkloh](https://github.com/lkloh))
- Add Message API Change Validation [\#1102](https://github.com/swift-nav/libsbp/pull/1102) ([isaactorz](https://github.com/isaactorz))

## [v4.1.5](https://github.com/swift-nav/libsbp/tree/v4.1.5) (2022-03-29)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v4.1.4...v4.1.5)

**Merged pull requests:**

- Update CODEOWNERS [\#1101](https://github.com/swift-nav/libsbp/pull/1101) ([silverjam](https://github.com/silverjam))
- introduce code owners, pull request template [\#1100](https://github.com/swift-nav/libsbp/pull/1100) ([silverjam](https://github.com/silverjam))
- Make integer to enum conversion explicit [\#1098](https://github.com/swift-nav/libsbp/pull/1098) ([fpezzinosn](https://github.com/fpezzinosn))

## [v4.1.4](https://github.com/swift-nav/libsbp/tree/v4.1.4) (2022-03-01)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v4.1.3...v4.1.4)

**Merged pull requests:**

- build\(deps\): bump ajv from 6.6.1 to 6.12.6 [\#1097](https://github.com/swift-nav/libsbp/pull/1097) ([dependabot[bot]](https://github.com/apps/dependabot))
- build\(deps\): bump simple-get from 3.1.0 to 3.1.1 [\#1096](https://github.com/swift-nav/libsbp/pull/1096) ([dependabot[bot]](https://github.com/apps/dependabot))
- rust: add bitfield types [\#1092](https://github.com/swift-nav/libsbp/pull/1092) ([notoriaga](https://github.com/notoriaga))

## [v4.1.3](https://github.com/swift-nav/libsbp/tree/v4.1.3) (2022-02-04)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v4.1.2...v4.1.3)

**Merged pull requests:**

- Add new update status message [\#1095](https://github.com/swift-nav/libsbp/pull/1095) ([reimerix](https://github.com/reimerix))
- Improvements to MSG\_VEL\_COG [\#1093](https://github.com/swift-nav/libsbp/pull/1093) ([lloydmaza](https://github.com/lloydmaza))

## [v3.4.13](https://github.com/swift-nav/libsbp/tree/v3.4.13) (2022-01-10)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v3.4.12...v3.4.13)

**Merged pull requests:**

- Improvements to MSG\_VEL\_COG [\#1094](https://github.com/swift-nav/libsbp/pull/1094) ([lloydmaza](https://github.com/lloydmaza))

## [v4.1.2](https://github.com/swift-nav/libsbp/tree/v4.1.2) (2021-12-22)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v4.1.1...v4.1.2)

## [v3.4.12](https://github.com/swift-nav/libsbp/tree/v3.4.12) (2021-12-13)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v3.4.11...v3.4.12)

## [v4.1.1](https://github.com/swift-nav/libsbp/tree/v4.1.1) (2021-12-11)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v4.1.0...v4.1.1)

**Merged pull requests:**

- fix bit masks for new COG message [\#1091](https://github.com/swift-nav/libsbp/pull/1091) ([silverjam](https://github.com/silverjam))

## [v4.1.0](https://github.com/swift-nav/libsbp/tree/v4.1.0) (2021-12-10)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v3.4.11...v4.1.0)

**Merged pull requests:**

- Typo fix in Readme.md [\#1089](https://github.com/swift-nav/libsbp/pull/1089) ([jtec](https://github.com/jtec))
- Create new COG/SOG message [\#1088](https://github.com/swift-nav/libsbp/pull/1088) ([lloydmaza](https://github.com/lloydmaza))
- Auto submodule update: cmake - Added variable to disable RTTI in RapidCheck \(\#106\) [\#1087](https://github.com/swift-nav/libsbp/pull/1087) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- Auto submodule update: cmake - \[ESD-2257\] Move archive util to common cmake repo \(\#105\) [\#1086](https://github.com/swift-nav/libsbp/pull/1086) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- \[ESD-2250\] Encode/decode functions in cpp message traits [\#1085](https://github.com/swift-nav/libsbp/pull/1085) ([woodfell](https://github.com/woodfell))
- \[ESD-2242\] Fix integer promotion issues in generated macros [\#1083](https://github.com/swift-nav/libsbp/pull/1083) ([woodfell](https://github.com/woodfell))

## [v3.4.11](https://github.com/swift-nav/libsbp/tree/v3.4.11) (2021-12-10)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v4.0.3...v3.4.11)

**Changes:**

- Create new COG/SOG message [\#1088](https://github.com/swift-nav/libsbp/pull/1088) ([lloydmaza](https://github.com/lloydmaza))

## [v4.0.3](https://github.com/swift-nav/libsbp/tree/v4.0.3) (2021-10-22)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v4.0.2...v4.0.3)

**Merged pull requests:**

- rust: support Result\<Sbp\> in with\_rover\_time [\#1084](https://github.com/swift-nav/libsbp/pull/1084) ([notoriaga](https://github.com/notoriaga))

## [v4.0.2](https://github.com/swift-nav/libsbp/tree/v4.0.2) (2021-10-13)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v4.0.1...v4.0.2)

**Merged pull requests:**

- fix crc calculation bug \[DEVINFRA-568\] [\#1081](https://github.com/swift-nav/libsbp/pull/1081) ([silverjam](https://github.com/silverjam))

## [v4.0.1](https://github.com/swift-nav/libsbp/tree/v4.0.1) (2021-10-08)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v4.0.0...v4.0.1)

Addressed release bug, Python and JavaSccript modules were not updated.  Rust
sbp2json was prepped for release to crates.io.

## [v4.0.0](https://github.com/swift-nav/libsbp/tree/v4.0.0) (2021-10-08)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v3.4.10...v4.0.0)

**Closed issues:**

- sbp.dll doesnt export symbols [\#1062](https://github.com/swift-nav/libsbp/issues/1062)

**Merged pull requests:**

- rust: Use minimum internal buffer size of 128b [\#1080](https://github.com/swift-nav/libsbp/pull/1080) ([silverjam](https://github.com/silverjam))
- rust: add len method to SbpMessage [\#1078](https://github.com/swift-nav/libsbp/pull/1078) ([notoriaga](https://github.com/notoriaga))
- Auto submodule update: cmake - Add Profiling to Unit Tests \(\#102\) [\#1077](https://github.com/swift-nav/libsbp/pull/1077) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- expose parsing messages from frames [\#1075](https://github.com/swift-nav/libsbp/pull/1075) ([notoriaga](https://github.com/notoriaga))
- \[ESD-2180\] clang-tidy improvements [\#1074](https://github.com/swift-nav/libsbp/pull/1074) ([woodfell](https://github.com/woodfell))
- rust: update to swiftnav 0.6.1 [\#1073](https://github.com/swift-nav/libsbp/pull/1073) ([silverjam](https://github.com/silverjam))
- rust: release cleanup [\#1071](https://github.com/swift-nav/libsbp/pull/1071) ([notoriaga](https://github.com/notoriaga))
- Rust: callback based message handler [\#1070](https://github.com/swift-nav/libsbp/pull/1070) ([notoriaga](https://github.com/notoriaga))
- windows dll update [\#1069](https://github.com/swift-nav/libsbp/pull/1069) ([RReichert](https://github.com/RReichert))
- Auto submodule update: cmake - Merge pull request \#99 from swift-nav/lkloh/always\_allow\_track\_origins [\#1067](https://github.com/swift-nav/libsbp/pull/1067) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- Fix windows library install directory [\#1061](https://github.com/swift-nav/libsbp/pull/1061) ([RReichert](https://github.com/RReichert))
- Dockerfile: Use Ubuntu focal [\#1059](https://github.com/swift-nav/libsbp/pull/1059) ([jayvdb](https://github.com/jayvdb))
- Fix spelling and copyright year [\#1058](https://github.com/swift-nav/libsbp/pull/1058) ([jayvdb](https://github.com/jayvdb))
- Auto submodule update: cmake - Add CONTRIBUTING.md [\#1057](https://github.com/swift-nav/libsbp/pull/1057) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- Portability project [\#1000](https://github.com/swift-nav/libsbp/pull/1000) ([RReichert](https://github.com/RReichert))

## [v3.4.10](https://github.com/swift-nav/libsbp/tree/v3.4.10) (2021-07-23)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v3.4.8...v3.4.10)

**Merged pull requests:**

- rust: Derive clone for GpsTimeError [\#1052](https://github.com/swift-nav/libsbp/pull/1052) ([notoriaga](https://github.com/notoriaga))
- Add orthometric height to MSG\_POS\_LLH\_ACC [\#1050](https://github.com/swift-nav/libsbp/pull/1050) ([jbangelo](https://github.com/jbangelo))
- don't stop converters when they encounter an error [\#1049](https://github.com/swift-nav/libsbp/pull/1049) ([notoriaga](https://github.com/notoriaga))
- docker: sync with github actions [\#1047](https://github.com/swift-nav/libsbp/pull/1047) ([silverjam](https://github.com/silverjam))
- change SBP table to use decimal instead of hex [\#1043](https://github.com/swift-nav/libsbp/pull/1043) ([silverjam](https://github.com/silverjam))
- Define new message for unbounded accuracy [\#1038](https://github.com/swift-nav/libsbp/pull/1038) ([richarddeurloo](https://github.com/richarddeurloo))
- build.gradle: Fix gradle 4 compatibility [\#1037](https://github.com/swift-nav/libsbp/pull/1037) ([jayvdb](https://github.com/jayvdb))
- build.gradle: Add coverage reporting [\#1036](https://github.com/swift-nav/libsbp/pull/1036) ([jayvdb](https://github.com/jayvdb))
- Reformat java using AOSP style [\#1035](https://github.com/swift-nav/libsbp/pull/1035) ([jayvdb](https://github.com/jayvdb))
- Add SonarCloud Github Action [\#1034](https://github.com/swift-nav/libsbp/pull/1034) ([jayvdb](https://github.com/jayvdb))
- Auto submodule update: cmake - memcheck\_xml2junit\_converter.py: Remove redundancy [\#1033](https://github.com/swift-nav/libsbp/pull/1033) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- Java CI: Add GITHUB\_TOKEN to sonarqube task [\#1032](https://github.com/swift-nav/libsbp/pull/1032) ([jayvdb](https://github.com/jayvdb))
- build.gradle: Add sonarcloud [\#1030](https://github.com/swift-nav/libsbp/pull/1030) ([jayvdb](https://github.com/jayvdb))
- javascript: Replace var with let [\#1029](https://github.com/swift-nav/libsbp/pull/1029) ([jayvdb](https://github.com/jayvdb))
- Javascript tests: Remove code duplication [\#1028](https://github.com/swift-nav/libsbp/pull/1028) ([jayvdb](https://github.com/jayvdb))
- Javascript lint fixes [\#1027](https://github.com/swift-nav/libsbp/pull/1027) ([jayvdb](https://github.com/jayvdb))
- Python lint fixes 2 [\#1026](https://github.com/swift-nav/libsbp/pull/1026) ([jayvdb](https://github.com/jayvdb))
- Python lint fixes [\#1025](https://github.com/swift-nav/libsbp/pull/1025) ([jayvdb](https://github.com/jayvdb))

## [v3.4.9](https://github.com/swift-nav/libsbp/tree/v3.4.9-yanked) (2021-07-14)

Release yanked, do not use.

## [v3.4.8](https://github.com/swift-nav/libsbp/tree/v3.4.8) (2021-06-18)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v3.4.7...v3.4.8)

**Closed issues:**

- Broken pyusb dependency on Python 2.x [\#982](https://github.com/swift-nav/libsbp/issues/982)
- Restart the serial thread [\#970](https://github.com/swift-nav/libsbp/issues/970)

**Merged pull requests:**

- Auto submodule update: cmake - SV4-144 update googleflags \(\#83\) [\#1010](https://github.com/swift-nav/libsbp/pull/1010) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- rust: impl TryFrom\<SBP\> for all messages [\#1009](https://github.com/swift-nav/libsbp/pull/1009) ([notoriaga](https://github.com/notoriaga))
- rust: fix parsing of invalid sbp [\#992](https://github.com/swift-nav/libsbp/pull/992) ([notoriaga](https://github.com/notoriaga))
- Correct spec for fwd\_payload member of MSG\_FWD [\#991](https://github.com/swift-nav/libsbp/pull/991) ([woodfell](https://github.com/woodfell))
- Correct docs for read dir resp [\#989](https://github.com/swift-nav/libsbp/pull/989) ([woodfell](https://github.com/woodfell))
- docker: add clang for rust build [\#987](https://github.com/swift-nav/libsbp/pull/987) ([silverjam](https://github.com/silverjam))
- rust: support encoding borrowed messages [\#986](https://github.com/swift-nav/libsbp/pull/986) ([notoriaga](https://github.com/notoriaga))
- Fix Java parsing and generate tests [\#985](https://github.com/swift-nav/libsbp/pull/985) ([jayvdb](https://github.com/jayvdb))
- Add support for construct 2.9.52 and 2.10 [\#984](https://github.com/swift-nav/libsbp/pull/984) ([jayvdb](https://github.com/jayvdb))
- Auto generate cpp tests [\#980](https://github.com/swift-nav/libsbp/pull/980) ([woodfell](https://github.com/woodfell))
- Add three message test specs [\#977](https://github.com/swift-nav/libsbp/pull/977) ([jayvdb](https://github.com/jayvdb))
- sbpjson: Sync generated code [\#976](https://github.com/swift-nav/libsbp/pull/976) ([jayvdb](https://github.com/jayvdb))
- Tidy generated tests [\#975](https://github.com/swift-nav/libsbp/pull/975) ([jayvdb](https://github.com/jayvdb))
- Remove unused test spec from python/ [\#974](https://github.com/swift-nav/libsbp/pull/974) ([jayvdb](https://github.com/jayvdb))
- Remove haskell from python CI [\#973](https://github.com/swift-nav/libsbp/pull/973) ([jayvdb](https://github.com/jayvdb))
- python: Run coverage and parameterize test cases [\#972](https://github.com/swift-nav/libsbp/pull/972) ([jayvdb](https://github.com/jayvdb))
- Add tcp\_2sigma\_example [\#971](https://github.com/swift-nav/libsbp/pull/971) ([dgburr](https://github.com/dgburr))
- Python: Detect and Fix pyflakes errors, and remove broken to\_binary [\#969](https://github.com/swift-nav/libsbp/pull/969) ([jayvdb](https://github.com/jayvdb))
- add gps\_time method [\#967](https://github.com/swift-nav/libsbp/pull/967) ([notoriaga](https://github.com/notoriaga))
- Fix docs [\#929](https://github.com/swift-nav/libsbp/pull/929) ([jayvdb](https://github.com/jayvdb))

## [v3.4.7](https://github.com/swift-nav/libsbp/tree/v3.4.7) (2021-04-30)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v3.4.6...v3.4.7)

**Merged pull requests:**

- Fix the bit field values in the SSR APC message [\#968](https://github.com/swift-nav/libsbp/pull/968) ([jbangelo](https://github.com/jbangelo))
- Revert formatting changes [\#965](https://github.com/swift-nav/libsbp/pull/965) ([woodfell](https://github.com/woodfell))
- Add more test specs [\#963](https://github.com/swift-nav/libsbp/pull/963) ([woodfell](https://github.com/woodfell))
- Process solution\_meta in javascript bindings [\#962](https://github.com/swift-nav/libsbp/pull/962) ([woodfell](https://github.com/woodfell))
- Don't cast function pointers to void\* [\#961](https://github.com/swift-nav/libsbp/pull/961) ([woodfell](https://github.com/woodfell))
- SSR documentation clarification [\#960](https://github.com/swift-nav/libsbp/pull/960) ([scarcanague](https://github.com/scarcanague))
- Auto submodule update: cmake - added RLM third party library \(\#81\) [\#958](https://github.com/swift-nav/libsbp/pull/958) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- New PL message draft [\#957](https://github.com/swift-nav/libsbp/pull/957) ([reimerix](https://github.com/reimerix))
- Add clang-format to docker image [\#956](https://github.com/swift-nav/libsbp/pull/956) ([woodfell](https://github.com/woodfell))
- Fix auto generated tests [\#955](https://github.com/swift-nav/libsbp/pull/955) ([woodfell](https://github.com/woodfell))
- Turn on auto formatting [\#954](https://github.com/swift-nav/libsbp/pull/954) ([woodfell](https://github.com/woodfell))
- gradle.build: Support Gradle 7 [\#953](https://github.com/swift-nav/libsbp/pull/953) ([jayvdb](https://github.com/jayvdb))
- Clarify units used in MSG\_LINUX\_SYS\_STATE message [\#952](https://github.com/swift-nav/libsbp/pull/952) ([dgburr](https://github.com/dgburr))
- Fix building of rust tools in Docker [\#951](https://github.com/swift-nav/libsbp/pull/951) ([dgburr](https://github.com/dgburr))
- Default to unbuffered output [\#950](https://github.com/swift-nav/libsbp/pull/950) ([notoriaga](https://github.com/notoriaga))
- python: add python 3.9 to tox [\#948](https://github.com/swift-nav/libsbp/pull/948) ([silverjam](https://github.com/silverjam))
- cherry-pick release 3.4.6 release notes and versions [\#947](https://github.com/swift-nav/libsbp/pull/947) ([silverjam](https://github.com/silverjam))
- generator: mark intermediate versions as alpha [\#946](https://github.com/swift-nav/libsbp/pull/946) ([silverjam](https://github.com/silverjam))
- Auto submodule update: cmake - code coverage overhaul \(\#79\) [\#945](https://github.com/swift-nav/libsbp/pull/945) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- package.json: Unpin binary-parser [\#944](https://github.com/swift-nav/libsbp/pull/944) ([jayvdb](https://github.com/jayvdb))
- Auto submodule update: cmake - Set default C11 \(\#78\) [\#943](https://github.com/swift-nav/libsbp/pull/943) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- Bump y18n from 4.0.0 to 4.0.1 [\#942](https://github.com/swift-nav/libsbp/pull/942) ([dependabot[bot]](https://github.com/apps/dependabot))
- use binascii instead of plain python [\#941](https://github.com/swift-nav/libsbp/pull/941) ([silverjam](https://github.com/silverjam))
- Install tox with apt-get [\#940](https://github.com/swift-nav/libsbp/pull/940) ([notoriaga](https://github.com/notoriaga))
- Specify unit of mem\_total in MSG\_LINUX\_SYS\_STATE [\#939](https://github.com/swift-nav/libsbp/pull/939) ([IsakTjernberg](https://github.com/IsakTjernberg))
- Propagate parse errors [\#937](https://github.com/swift-nav/libsbp/pull/937) ([notoriaga](https://github.com/notoriaga))
- Add option to disable input buffering [\#935](https://github.com/swift-nav/libsbp/pull/935) ([notoriaga](https://github.com/notoriaga))
- python: fix call\_git\_describe in sbp.version [\#932](https://github.com/swift-nav/libsbp/pull/932) ([silverjam](https://github.com/silverjam))
- Run all Python tests without numpy [\#931](https://github.com/swift-nav/libsbp/pull/931) ([jayvdb](https://github.com/jayvdb))
- Remove python-jit [\#930](https://github.com/swift-nav/libsbp/pull/930) ([jayvdb](https://github.com/jayvdb))
- Add get\_message\_name function to SBPMessage .rs [\#925](https://github.com/swift-nav/libsbp/pull/925) ([john-michaelburke](https://github.com/john-michaelburke))
- Add Satellite APC message [\#902](https://github.com/swift-nav/libsbp/pull/902) ([jbangelo](https://github.com/jbangelo))
- Dzollo/ins status one page [\#888](https://github.com/swift-nav/libsbp/pull/888) ([denniszollo](https://github.com/denniszollo))
- Dzollo/sender id notes [\#887](https://github.com/swift-nav/libsbp/pull/887) ([denniszollo](https://github.com/denniszollo))


## [v3.4.6](https://github.com/swift-nav/libsbp/tree/v3.4.6) (2021-04-02)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v3.4.5...v3.4.6)

**Closed issues:**

- JavaScript build error in serialport [\#927](https://github.com/swift-nav/libsbp/issues/927)
- cmake/common/\* missing in source archives [\#862](https://github.com/swift-nav/libsbp/issues/862)
- Problem making Java version on Windows [\#847](https://github.com/swift-nav/libsbp/issues/847)

**Merged pull requests:**

- Add INS status mode [\#926](https://github.com/swift-nav/libsbp/pull/926) ([reimerix](https://github.com/reimerix))
- Bump elliptic from 6.5.3 to 6.5.4 [\#924](https://github.com/swift-nav/libsbp/pull/924) ([dependabot[bot]](https://github.com/apps/dependabot))
- Update docs on how to compile Libsbp [\#923](https://github.com/swift-nav/libsbp/pull/923) ([lkloh](https://github.com/lkloh))
- fix SBP docs [\#922](https://github.com/swift-nav/libsbp/pull/922) ([lkloh](https://github.com/lkloh))
- undid previous commit [\#920](https://github.com/swift-nav/libsbp/pull/920) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- Update OSR flag in the SBP docs [\#918](https://github.com/swift-nav/libsbp/pull/918) ([lkloh](https://github.com/lkloh))
- Add timestamped versions of resource usage messages [\#917](https://github.com/swift-nav/libsbp/pull/917) ([IsakTjernberg](https://github.com/IsakTjernberg))
- cmake - Trigger submodules, json encoded [\#916](https://github.com/swift-nav/libsbp/pull/916) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- Bitfield macros [\#915](https://github.com/swift-nav/libsbp/pull/915) ([denniszollo](https://github.com/denniszollo))
- cmake - remove no strict aliasing from common compile flags \(\#75\) [\#914](https://github.com/swift-nav/libsbp/pull/914) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- check - Merge pull request \#307 from jflopezfernandez/docs/format-github-readme [\#913](https://github.com/swift-nav/libsbp/pull/913) ([akleeman](https://github.com/akleeman))
- Pin npm to version 6 in CI stage [\#910](https://github.com/swift-nav/libsbp/pull/910) ([woodfell](https://github.com/woodfell))
- Common compile flags [\#909](https://github.com/swift-nav/libsbp/pull/909) ([woodfell](https://github.com/woodfell))
- cmake - add swiftlets\_ENABLE\_TEST\_LIBS [\#908](https://github.com/swift-nav/libsbp/pull/908) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- Fix the documented offset for fixed length arrays [\#904](https://github.com/swift-nav/libsbp/pull/904) ([jbangelo](https://github.com/jbangelo))
- Add support for Windows in the Java portion of the Makefile. [\#901](https://github.com/swift-nav/libsbp/pull/901) ([john-michaelburke](https://github.com/john-michaelburke))
- Replace fail\_unless with ck\_assert\_msg [\#900](https://github.com/swift-nav/libsbp/pull/900) ([reimerix](https://github.com/reimerix))
- c: toggle C++ on to fix configure error [\#899](https://github.com/swift-nav/libsbp/pull/899) ([silverjam](https://github.com/silverjam))
- cmake - clang-format-diff: compare to most recent tag on current branch \(\#73\) [\#898](https://github.com/swift-nav/libsbp/pull/898) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- add workaround for MinGW GCC bug [\#897](https://github.com/swift-nav/libsbp/pull/897) ([silverjam](https://github.com/silverjam))
- cmake - clang-format-diff improvements [\#895](https://github.com/swift-nav/libsbp/pull/895) ([swiftnav-svc-jenkins](https://github.com/swiftnav-svc-jenkins))
- python: better PEP 508 compliance [\#894](https://github.com/swift-nav/libsbp/pull/894) ([silverjam](https://github.com/silverjam))
- Add generic system status reporting message [\#885](https://github.com/swift-nav/libsbp/pull/885) ([gsmcmullin](https://github.com/gsmcmullin))
- Add async rust parser [\#884](https://github.com/swift-nav/libsbp/pull/884) ([notoriaga](https://github.com/notoriaga))

## [v3.4.5](https://github.com/swift-nav/libsbp/tree/v3.4.5) (2020-12-12)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v3.4.4...v3.4.5)

**Merged pull requests:**

- docker: update docs for most recent tag [\#891](https://github.com/swift-nav/libsbp/pull/891)
- Bump ini from 1.3.5 to 1.3.7 [\#890](https://github.com/swift-nav/libsbp/pull/890)
- Add environment markers to requirements.txt [\#889](https://github.com/swift-nav/libsbp/pull/889)
- Add B2a to list of signals available in MSG\_OBS [\#886](https://github.com/swift-nav/libsbp/pull/886)
- Clean up Rust parser implementation [\#883](https://github.com/swift-nav/libsbp/pull/883)
- new flags for fixed fuzed rate [\#880](https://github.com/swift-nav/libsbp/pull/880)
- Auto submodule update: cmake - Disable pal test libs by default \(\#70\) [\#879](https://github.com/swift-nav/libsbp/pull/879)
- Bump check submodule [\#878](https://github.com/swift-nav/libsbp/pull/878)
- Specify that 0xFFFF is used to indicate invalid PDOP/HDOP/VDOP [\#877](https://github.com/swift-nav/libsbp/pull/877)
- Dzollo/vehicle metadata flags [\#876](https://github.com/swift-nav/libsbp/pull/876)
- Update documentation for week rollover on odometry message timestamps [\#875](https://github.com/swift-nav/libsbp/pull/875)
- Revert "odometry: add flags for fwd, park and reverse" [\#874](https://github.com/swift-nav/libsbp/pull/874)
- update sol in default sensor type [\#873](https://github.com/swift-nav/libsbp/pull/873)
- odometry: add flags for fwd, park and reverse [\#872](https://github.com/swift-nav/libsbp/pull/872)

## [v3.4.4](https://github.com/swift-nav/libsbp/tree/v3.4.4) (2020-10-12)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v3.4.3...v3.4.4)

## [v3.4.3](https://github.com/swift-nav/libsbp/tree/v3.4.3) (2020-10-12)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v3.4.2...v3.4.3)

**Merged pull requests:**

- Guillaume/sen 444/change age gnss type in solnmeta [\#871](https://github.com/swift-nav/libsbp/pull/871)
- Per graphic design rec., switch to Roboto [\#870](https://github.com/swift-nav/libsbp/pull/870)
- Auto submodule update: cmake - Add possibility to log total memory from profiling tools into a file [\#865](https://github.com/swift-nav/libsbp/pull/865)
- Updates to solution meta message [\#864](https://github.com/swift-nav/libsbp/pull/864)
- Auto submodule update: cmake - Starling third party fix \(\#65\) [\#861](https://github.com/swift-nav/libsbp/pull/861)
- Fix example SBP message in SBP Specification [\#860](https://github.com/swift-nav/libsbp/pull/860)

## [v3.4.2](https://github.com/swift-nav/libsbp/tree/v3.4.2) (2020-09-22)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v3.4.1...v3.4.2)

**Merged pull requests:**

- rust: add explicit to\_string for SbpString [\#859](https://github.com/swift-nav/libsbp/pull/859)
- fixup font issue [\#858](https://github.com/swift-nav/libsbp/pull/858)
- Bump cmake \(back\) to most recent. [\#857](https://github.com/swift-nav/libsbp/pull/857)
- Fix java examples so they at least compile [\#855](https://github.com/swift-nav/libsbp/pull/855)
- Add Python 3.5/3.8 to libsbp builder, update ARM [\#854](https://github.com/swift-nav/libsbp/pull/854)
- fix tox tests for Python 3.5 [\#853](https://github.com/swift-nav/libsbp/pull/853)
- Add bits for ins motion state [\#845](https://github.com/swift-nav/libsbp/pull/845)

## [v3.4.1](https://github.com/swift-nav/libsbp/tree/v3.4.1) (2020-09-14)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v3.4.0...v3.4.1)

**Merged pull requests:**

- Normalize contact addresses [\#852](https://github.com/swift-nav/libsbp/pull/852)
- python: add reconnect logic to network write [\#851](https://github.com/swift-nav/libsbp/pull/851)

## [v3.4.0](https://github.com/swift-nav/libsbp/tree/v3.4.0) (2020-09-12)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v3.3.1...v3.4.0)

**Merged pull requests:**

- Auto submodule update: cmake - Change implementation of working directory [\#850](https://github.com/swift-nav/libsbp/pull/850)
- use generic class if message is unknown, replace on unicode errors [\#849](https://github.com/swift-nav/libsbp/pull/849)
- Fix bugs in Java array decoding [\#848](https://github.com/swift-nav/libsbp/pull/848)
- Improve SBP protocol PDF documentation [\#844](https://github.com/swift-nav/libsbp/pull/844)
- SSR Lat/Lon sign [\#842](https://github.com/swift-nav/libsbp/pull/842)
- generate bitfield macros [\#841](https://github.com/swift-nav/libsbp/pull/841)

## [v3.3.1](https://github.com/swift-nav/libsbp/tree/v3.3.1) (2020-08-28)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v3.3.0...v3.3.1)

**Merged pull requests:**

- json2json: maintain fields other than "data" [\#843](https://github.com/swift-nav/libsbp/pull/843)

## [v3.3.0](https://github.com/swift-nav/libsbp/tree/v3.3.0) (2020-08-28)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v3.2.0...v3.3.0)

**Merged pull requests:**

- Merge starling output changes to master [\#840](https://github.com/swift-nav/libsbp/pull/840)
- Update SSR Tile IDs [\#839](https://github.com/swift-nav/libsbp/pull/839)
- Guillaume/so 6/quick update group meta [\#836](https://github.com/swift-nav/libsbp/pull/836)
- Update the docs and reorder bits for readability [\#835](https://github.com/swift-nav/libsbp/pull/835)
- Update SSR atmo correction messages to allow multiple tiles. [\#834](https://github.com/swift-nav/libsbp/pull/834)
- Make alignment status flags more sensible [\#833](https://github.com/swift-nav/libsbp/pull/833)
- Add SOLN\_META message for Fuzed Wagon [\#832](https://github.com/swift-nav/libsbp/pull/832)
- Update LICENSE to MIT [\#831](https://github.com/swift-nav/libsbp/pull/831)
- Update docs and description for FastStart specs [\#829](https://github.com/swift-nav/libsbp/pull/829)
- Auto submodule update: cmake - Add additional profiling tools [\#827](https://github.com/swift-nav/libsbp/pull/827)
- Dzollo/pyserial timeout remove [\#821](https://github.com/swift-nav/libsbp/pull/821)
- Update README.md [\#820](https://github.com/swift-nav/libsbp/pull/820)
- Clarify the ephemeris IOD definitions [\#814](https://github.com/swift-nav/libsbp/pull/814)


## [v3.2.0](https://github.com/swift-nav/libsbp/tree/v3.2.0) (2020-07-23)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v3.1.2...v3.2.0)

**Merged pull requests:**

- SBP 2 NMEA implementation [\#828](https://github.com/swift-nav/libsbp/pull/828)
- Add time offset message [\#826](https://github.com/swift-nav/libsbp/pull/826)
- python: remove generation of the sbp.jit \_payload\_size method [\#825](https://github.com/swift-nav/libsbp/pull/825)
- Guillaume/so 7/add leader group message [\#824](https://github.com/swift-nav/libsbp/pull/824)
- Bump lodash from 4.17.15 to 4.17.19 [\#822](https://github.com/swift-nav/libsbp/pull/822)
- bump cmake to master [\#819](https://github.com/swift-nav/libsbp/pull/819)

## [v3.1.2](https://github.com/swift-nav/libsbp/tree/v3.1.2) (2020-07-13)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v3.1.1...v3.1.2)

**Merged pull requests:**

- python: remove accidental numpy import [\#818](https://github.com/swift-nav/libsbp/pull/818)
- cmake - Standardize system include targets [\#817](https://github.com/swift-nav/libsbp/pull/817)

## [v3.1.1](https://github.com/swift-nav/libsbp/tree/v3.1.1) (2020-06-08)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v3.1.0...v3.1.1)

**Merged pull requests:**

- Dzollo/python sender id whitelist [\#813](https://github.com/swift-nav/libsbp/pull/813)
- README typos, pin deps for sbp2json in Cargo.lock [\#812](https://github.com/swift-nav/libsbp/pull/812)


## [v3.1.0](https://github.com/swift-nav/libsbp/tree/v3.1.0) (2020-05-29)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v3.0.1...v3.1.0)

**Merged pull requests:**

- Explicitly flush stdout [\#809](https://github.com/swift-nav/libsbp/pull/809)
- Add INS update status message [\#808](https://github.com/swift-nav/libsbp/pull/808)
- Support building with ARMCC [\#807](https://github.com/swift-nav/libsbp/pull/807)

## [v3.0.1](https://github.com/swift-nav/libsbp/tree/v3.0.1) (2020-05-22)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v3.0.0...v3.0.1)

## [v3.0.0](https://github.com/swift-nav/libsbp/tree/v3.0.0) (2020-05-22)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.8.0...v3.0.0)

**Closed issues:**

- Rust parser does not continue parsing after CRC error [\#793](https://github.com/swift-nav/libsbp/issues/793)
- JSONLogIterator uses generators improperly [\#716](https://github.com/swift-nav/libsbp/issues/716)

**Merged pull requests:**

- Auto submodule update: cmake - Merge pull request \#57 from swift-nav/joint-work/valgrind-integration [\#806](https://github.com/swift-nav/libsbp/pull/806)
- Handle invalid UTF-8 sequences [\#805](https://github.com/swift-nav/libsbp/pull/805)
- Public receive method in SBPFramer Java class [\#804](https://github.com/swift-nav/libsbp/pull/804)
- rust: derive clone [\#803](https://github.com/swift-nav/libsbp/pull/803)
- Auto submodule update: cmake - Add FindSwiftlets.cmake \(\#53\) [\#800](https://github.com/swift-nav/libsbp/pull/800)
- Improve how the rust parser handles errors [\#798](https://github.com/swift-nav/libsbp/pull/798)
- Fix IMURAW docstring [\#797](https://github.com/swift-nav/libsbp/pull/797)
- npm audit fix [\#796](https://github.com/swift-nav/libsbp/pull/796)
- Auto submodule update: cmake - Merge pull request \#51 from swift-nav/lkloh\_cmake [\#795](https://github.com/swift-nav/libsbp/pull/795)
- Fix-up Python binding generation [\#794](https://github.com/swift-nav/libsbp/pull/794)

## [v2.8.0](https://github.com/swift-nav/libsbp/tree/v2.8.0) (2020-04-01)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.7.7...v2.8.0)

**Merged pull requests:**

- Fix JavaScript security warning [\#791](https://github.com/swift-nav/libsbp/pull/791)
- rust: implement sbp2json, json2sbp, json2json [\#790](https://github.com/swift-nav/libsbp/pull/790)
- INFRA-137: wrap integer gets in parens [\#789](https://github.com/swift-nav/libsbp/pull/789)
- rust: nom parsing fix-up for eof error [\#788](https://github.com/swift-nav/libsbp/pull/788)

## [v2.7.7](https://github.com/swift-nav/libsbp/tree/v2.7.7) (2020-03-14)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.7.6...v2.7.7)

**Merged pull requests:**

- rust: expose crc errors [\#786](https://github.com/swift-nav/libsbp/pull/786)
- File playback driver [\#782](https://github.com/swift-nav/libsbp/pull/782)

## [v2.7.6](https://github.com/swift-nav/libsbp/tree/v2.7.6) (2020-03-12)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.7.5...v2.7.6)

**Merged pull requests:**

- Update haskell installation instructions [\#785](https://github.com/swift-nav/libsbp/pull/785)
- Nojit fixes and unit testing [\#784](https://github.com/swift-nav/libsbp/pull/784)
- Add IMU type code for ST ASM330LLH [\#783](https://github.com/swift-nav/libsbp/pull/783)

## [v2.7.5](https://github.com/swift-nav/libsbp/tree/v2.7.5) (2020-03-07)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.7.4...v2.7.5)

**Merged pull requests:**

- Add library support to read and write SBP files [\#780](https://github.com/swift-nav/libsbp/pull/780)
- Fixed crashing bug in Python release

## [v2.7.4](https://github.com/swift-nav/libsbp/tree/v2.7.4) (2020-02-25)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.7.3...v2.7.4)

**Merged pull requests:**

- Dzollo/expand sbp json payload [\#779](https://github.com/swift-nav/libsbp/pull/779)
- Dzollo/sen 138/wheel odometry [\#778](https://github.com/swift-nav/libsbp/pull/778)
- Add message for accumulated wheeltick count [\#777](https://github.com/swift-nav/libsbp/pull/777)
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
- Changes needed to libsbp for road runner [\#763](https://github.com/swift-nav/libsbp/pull/763)
- Revert "Add stddev to SSR atmospheric messages.  \(\#759\)" [\#761](https://github.com/swift-nav/libsbp/pull/761)
- Moved the rust example inside of the sbp crate [\#760](https://github.com/swift-nav/libsbp/pull/760)
- Add variances to SSR atmospheric messages.  [\#759](https://github.com/swift-nav/libsbp/pull/759)
- Example: rust message serialization plus trait to\_frame method [\#758](https://github.com/swift-nav/libsbp/pull/758)
- Add rust message serialization [\#755](https://github.com/swift-nav/libsbp/pull/755)

## [v2.7.3](https://github.com/swift-nav/libsbp/tree/v2.7.3) (2019-11-14)

[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.7.1...v2.7.3)

**Closed issues:**

- sbp2rinex does not generate valid rinex when using toJson\(\) method from SBPMessage.java  [\#720](https://github.com/swift-nav/libsbp/issues/720)

**Merged pull requests:**

- Release 2.7.3 [\#757](https://github.com/swift-nav/libsbp/pull/757)
- Allow max reconnects to be specified as a parameter [\#756](https://github.com/swift-nav/libsbp/pull/756)
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
- Add proposed Protection Level message [\#737](https://github.com/swift-nav/libsbp/pull/737)
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
- Replace ujson with rapidjson [\#729](https://github.com/swift-nav/libsbp/pull/729)
- Make a msg\_buff pointer for backwards compatibility [\#728](https://github.com/swift-nav/libsbp/pull/728)
- Remove OWNERS.md file. [\#726](https://github.com/swift-nav/libsbp/pull/726)
- Frame callback implementation & tests [\#725](https://github.com/swift-nav/libsbp/pull/725)
- JSONLogIterator - Fix the iteration if the JSON is already unwrapped [\#724](https://github.com/swift-nav/libsbp/pull/724)
- Dynamic import generator output modules [\#722](https://github.com/swift-nav/libsbp/pull/722)
- Changing java CRC16 class modifiers to enable external access \(\#720\) [\#721](https://github.com/swift-nav/libsbp/pull/721)
- Fix up SSR atmospherics documentation [\#719](https://github.com/swift-nav/libsbp/pull/719)
- Remove lodash from JavaScript deps [\#717](https://github.com/swift-nav/libsbp/pull/717)
- Initial rust implementation [\#714](https://github.com/swift-nav/libsbp/pull/714)
- Remove redundant field. [\#713](https://github.com/swift-nav/libsbp/pull/713)
- Support running w/o Numba/Numpy installed [\#712](https://github.com/swift-nav/libsbp/pull/712)
- Add code coverage [\#710](https://github.com/swift-nav/libsbp/pull/710)
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
- Purge llvmlite and numba dependencies from generated Python code [\#702](https://github.com/swift-nav/libsbp/pull/702)
- Don't use hardcoded include/link paths [\#701](https://github.com/swift-nav/libsbp/pull/701)

## [v2.6.3](https://github.com/swift-nav/libsbp/tree/v2.6.3) (2019-06-11)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.6.2...v2.6.3)

**Merged pull requests:**

- Version 2.6.3 [\#700](https://github.com/swift-nav/libsbp/pull/700)
- Move sbp2json to libsbp from piksi\_tools [\#699](https://github.com/swift-nav/libsbp/pull/699)
- Deprecate MSG\_INIT\_BASE [\#698](https://github.com/swift-nav/libsbp/pull/698)

## [v2.6.2](https://github.com/swift-nav/libsbp/tree/v2.6.2) (2019-06-06)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.6.1...v2.6.2)

**Merged pull requests:**

- v2.6.2 [\#697](https://github.com/swift-nav/libsbp/pull/697)

## [v2.6.1](https://github.com/swift-nav/libsbp/tree/v2.6.1) (2019-06-06)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.6.0...v2.6.1)

**Merged pull requests:**

- Version 2.6.1 [\#696](https://github.com/swift-nav/libsbp/pull/696)
- Add QZSS eph [\#695](https://github.com/swift-nav/libsbp/pull/695)
- Import standard cmake modules, standardise dependency resolution [\#692](https://github.com/swift-nav/libsbp/pull/692)

## [v2.6.0](https://github.com/swift-nav/libsbp/tree/v2.6.0) (2019-06-05)
[Full Changelog](https://github.com/swift-nav/libsbp/compare/v2.5.5...v2.6.0)

**Merged pull requests:**

- libsbp release 2.6.0 [\#694](https://github.com/swift-nav/libsbp/pull/694)
- Remove unused build\_test\_data.py [\#693](https://github.com/swift-nav/libsbp/pull/693)
- Integrate numba into setuptools [\#687](https://github.com/swift-nav/libsbp/pull/687)
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
- Do not call nullary constructors in Haskell ToJSON [\#680](https://github.com/swift-nav/libsbp/pull/680)

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
- Add base into\_buffer method for messages with no payload [\#674](https://github.com/swift-nav/libsbp/pull/674)
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
