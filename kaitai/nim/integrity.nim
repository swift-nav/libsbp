import kaitai_struct_nim_runtime
import options
import gnss

type
  Integrity* = ref object of KaitaiStruct
    `parent`*: KaitaiStruct
  Integrity_MsgSsrFlagSatellites* = ref object of KaitaiStruct
    `obsTime`*: Gnss_GpsTimeSec
    `numMsgs`*: uint8
    `seqNum`*: uint8
    `ssrSolId`*: uint8
    `chainId`*: uint8
    `constId`*: uint8
    `nFaultySats`*: uint8
    `faultySats`*: seq[uint8]
    `parent`*: Sbp_Message
  Integrity_MsgSsrFlagIonoTileSatLos* = ref object of KaitaiStruct
    `header`*: Integrity_IntegritySsrHeader
    `nFaultyLos`*: uint8
    `faultyLos`*: seq[Gnss_SvId]
    `parent`*: Sbp_Message
  Integrity_MsgSsrFlagIonoGridPointSatLos* = ref object of KaitaiStruct
    `header`*: Integrity_IntegritySsrHeader
    `gridPointId`*: uint16
    `nFaultyLos`*: uint8
    `faultyLos`*: seq[Gnss_SvId]
    `parent`*: Sbp_Message
  Integrity_IntegritySsrHeader* = ref object of KaitaiStruct
    `obsTime`*: Gnss_GpsTimeSec
    `numMsgs`*: uint8
    `seqNum`*: uint8
    `ssrSolId`*: uint8
    `tileSetId`*: uint16
    `tileId`*: uint16
    `chainId`*: uint8
    `parent`*: KaitaiStruct
  Integrity_MsgAcknowledge* = ref object of KaitaiStruct
    `requestId`*: uint8
    `areaId`*: uint32
    `responseCode`*: uint8
    `correctionMaskOnDemand`*: uint16
    `correctionMaskStream`*: uint16
    `solutionId`*: uint8
    `parent`*: Sbp_Message
  Integrity_MsgSsrFlagIonoGridPoints* = ref object of KaitaiStruct
    `header`*: Integrity_IntegritySsrHeader
    `nFaultyPoints`*: uint8
    `faultyPoints`*: seq[uint16]
    `parent`*: Sbp_Message
  Integrity_MsgSsrFlagTropoGridPoints* = ref object of KaitaiStruct
    `header`*: Integrity_IntegritySsrHeader
    `nFaultyPoints`*: uint8
    `faultyPoints`*: seq[uint16]
    `parent`*: Sbp_Message
  Integrity_MsgSsrFlagHighLevel* = ref object of KaitaiStruct
    `obsTime`*: Gnss_GpsTimeSec
    `corrTime`*: Gnss_GpsTimeSec
    `ssrSolId`*: uint8
    `tileSetId`*: uint16
    `tileId`*: uint16
    `chainId`*: uint8
    `useGpsSat`*: uint8
    `useGalSat`*: uint8
    `useBdsSat`*: uint8
    `reserved`*: seq[uint8]
    `useTropoGridPoints`*: uint8
    `useIonoGridPoints`*: uint8
    `useIonoTileSatLos`*: uint8
    `useIonoGridPointSatLos`*: uint8
    `parent`*: Sbp_Message

proc read*(_: typedesc[Integrity], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Integrity
proc read*(_: typedesc[Integrity_MsgSsrFlagSatellites], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Integrity_MsgSsrFlagSatellites
proc read*(_: typedesc[Integrity_MsgSsrFlagIonoTileSatLos], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Integrity_MsgSsrFlagIonoTileSatLos
proc read*(_: typedesc[Integrity_MsgSsrFlagIonoGridPointSatLos], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Integrity_MsgSsrFlagIonoGridPointSatLos
proc read*(_: typedesc[Integrity_IntegritySsrHeader], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Integrity_IntegritySsrHeader
proc read*(_: typedesc[Integrity_MsgAcknowledge], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Integrity_MsgAcknowledge
proc read*(_: typedesc[Integrity_MsgSsrFlagIonoGridPoints], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Integrity_MsgSsrFlagIonoGridPoints
proc read*(_: typedesc[Integrity_MsgSsrFlagTropoGridPoints], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Integrity_MsgSsrFlagTropoGridPoints
proc read*(_: typedesc[Integrity_MsgSsrFlagHighLevel], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Integrity_MsgSsrFlagHighLevel


proc read*(_: typedesc[Integrity], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Integrity =
  template this: untyped = result
  this = new(Integrity)
  let root = if root == nil: cast[Integrity](this) else: cast[Integrity](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[Integrity], filename: string): Integrity =
  Integrity.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Integrity_MsgSsrFlagSatellites], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Integrity_MsgSsrFlagSatellites =
  template this: untyped = result
  this = new(Integrity_MsgSsrFlagSatellites)
  let root = if root == nil: cast[Integrity](this) else: cast[Integrity](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GNSS reference time of the observation used to generate the flag.

  ]##
  let obsTimeExpr = Gnss_GpsTimeSec.read(this.io, this.root, this)
  this.obsTime = obsTimeExpr

  ##[
  Number of messages in the dataset

  ]##
  let numMsgsExpr = this.io.readU1()
  this.numMsgs = numMsgsExpr

  ##[
  Position of this message in the dataset

  ]##
  let seqNumExpr = this.io.readU1()
  this.seqNum = seqNumExpr

  ##[
  SSR Solution ID.

  ]##
  let ssrSolIdExpr = this.io.readU1()
  this.ssrSolId = ssrSolIdExpr

  ##[
  Chain and type of flag.

  ]##
  let chainIdExpr = this.io.readU1()
  this.chainId = chainIdExpr

  ##[
  Constellation ID.

  ]##
  let constIdExpr = this.io.readU1()
  this.constId = constIdExpr

  ##[
  Number of faulty satellites.

  ]##
  let nFaultySatsExpr = this.io.readU1()
  this.nFaultySats = nFaultySatsExpr

  ##[
  List of faulty satellites.

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = this.io.readU1()
      this.faultySats.add(it)
      inc i

proc fromFile*(_: typedesc[Integrity_MsgSsrFlagSatellites], filename: string): Integrity_MsgSsrFlagSatellites =
  Integrity_MsgSsrFlagSatellites.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Integrity_MsgSsrFlagIonoTileSatLos], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Integrity_MsgSsrFlagIonoTileSatLos =
  template this: untyped = result
  this = new(Integrity_MsgSsrFlagIonoTileSatLos)
  let root = if root == nil: cast[Integrity](this) else: cast[Integrity](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Header of an integrity message.

  ]##
  let headerExpr = Integrity_IntegritySsrHeader.read(this.io, this.root, this)
  this.header = headerExpr

  ##[
  Number of faulty LOS.

  ]##
  let nFaultyLosExpr = this.io.readU1()
  this.nFaultyLos = nFaultyLosExpr

  ##[
  List of faulty LOS

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = Gnss_SvId.read(this.io, this.root, this)
      this.faultyLos.add(it)
      inc i

proc fromFile*(_: typedesc[Integrity_MsgSsrFlagIonoTileSatLos], filename: string): Integrity_MsgSsrFlagIonoTileSatLos =
  Integrity_MsgSsrFlagIonoTileSatLos.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Integrity_MsgSsrFlagIonoGridPointSatLos], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Integrity_MsgSsrFlagIonoGridPointSatLos =
  template this: untyped = result
  this = new(Integrity_MsgSsrFlagIonoGridPointSatLos)
  let root = if root == nil: cast[Integrity](this) else: cast[Integrity](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Header of an integrity message.

  ]##
  let headerExpr = Integrity_IntegritySsrHeader.read(this.io, this.root, this)
  this.header = headerExpr

  ##[
  Index of the grid point.

  ]##
  let gridPointIdExpr = this.io.readU2le()
  this.gridPointId = gridPointIdExpr

  ##[
  Number of faulty LOS.

  ]##
  let nFaultyLosExpr = this.io.readU1()
  this.nFaultyLos = nFaultyLosExpr

  ##[
  List of faulty LOS

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = Gnss_SvId.read(this.io, this.root, this)
      this.faultyLos.add(it)
      inc i

proc fromFile*(_: typedesc[Integrity_MsgSsrFlagIonoGridPointSatLos], filename: string): Integrity_MsgSsrFlagIonoGridPointSatLos =
  Integrity_MsgSsrFlagIonoGridPointSatLos.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Integrity_IntegritySsrHeader], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Integrity_IntegritySsrHeader =
  template this: untyped = result
  this = new(Integrity_IntegritySsrHeader)
  let root = if root == nil: cast[Integrity](this) else: cast[Integrity](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GNSS reference time of the observation used to generate the flag.

  ]##
  let obsTimeExpr = Gnss_GpsTimeSec.read(this.io, this.root, this)
  this.obsTime = obsTimeExpr

  ##[
  Number of messages in the dataset

  ]##
  let numMsgsExpr = this.io.readU1()
  this.numMsgs = numMsgsExpr

  ##[
  Position of this message in the dataset

  ]##
  let seqNumExpr = this.io.readU1()
  this.seqNum = seqNumExpr

  ##[
  SSR Solution ID.

  ]##
  let ssrSolIdExpr = this.io.readU1()
  this.ssrSolId = ssrSolIdExpr

  ##[
  Unique identifier of the set this tile belongs to.

  ]##
  let tileSetIdExpr = this.io.readU2le()
  this.tileSetId = tileSetIdExpr

  ##[
  Unique identifier of this tile in the tile set.

  ]##
  let tileIdExpr = this.io.readU2le()
  this.tileId = tileIdExpr

  ##[
  Chain and type of flag.

  ]##
  let chainIdExpr = this.io.readU1()
  this.chainId = chainIdExpr

proc fromFile*(_: typedesc[Integrity_IntegritySsrHeader], filename: string): Integrity_IntegritySsrHeader =
  Integrity_IntegritySsrHeader.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Integrity_MsgAcknowledge], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Integrity_MsgAcknowledge =
  template this: untyped = result
  this = new(Integrity_MsgAcknowledge)
  let root = if root == nil: cast[Integrity](this) else: cast[Integrity](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Echo of the request ID field from the corresponding CRA message, or
255 if no request ID was provided.

  ]##
  let requestIdExpr = this.io.readU1()
  this.requestId = requestIdExpr

  ##[
  Echo of the Area ID field from the corresponding CRA message.

  ]##
  let areaIdExpr = this.io.readU4le()
  this.areaId = areaIdExpr

  ##[
  Reported status of the request.

  ]##
  let responseCodeExpr = this.io.readU1()
  this.responseCode = responseCodeExpr

  ##[
  Contains the message group(s) that will be sent in response from the
corresponding CRA correction mask. An echo of the correction mask
field from the corresponding CRA message.

  ]##
  let correctionMaskOnDemandExpr = this.io.readU2le()
  this.correctionMaskOnDemand = correctionMaskOnDemandExpr

  ##[
  For future expansion. Always set to 0.

  ]##
  let correctionMaskStreamExpr = this.io.readU2le()
  this.correctionMaskStream = correctionMaskStreamExpr

  ##[
  The solution ID of the instance providing the corrections.

  ]##
  let solutionIdExpr = this.io.readU1()
  this.solutionId = solutionIdExpr

proc fromFile*(_: typedesc[Integrity_MsgAcknowledge], filename: string): Integrity_MsgAcknowledge =
  Integrity_MsgAcknowledge.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Integrity_MsgSsrFlagIonoGridPoints], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Integrity_MsgSsrFlagIonoGridPoints =
  template this: untyped = result
  this = new(Integrity_MsgSsrFlagIonoGridPoints)
  let root = if root == nil: cast[Integrity](this) else: cast[Integrity](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Header of an integrity message.

  ]##
  let headerExpr = Integrity_IntegritySsrHeader.read(this.io, this.root, this)
  this.header = headerExpr

  ##[
  Number of faulty grid points.

  ]##
  let nFaultyPointsExpr = this.io.readU1()
  this.nFaultyPoints = nFaultyPointsExpr

  ##[
  List of faulty grid points.

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = this.io.readU2le()
      this.faultyPoints.add(it)
      inc i

proc fromFile*(_: typedesc[Integrity_MsgSsrFlagIonoGridPoints], filename: string): Integrity_MsgSsrFlagIonoGridPoints =
  Integrity_MsgSsrFlagIonoGridPoints.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Integrity_MsgSsrFlagTropoGridPoints], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Integrity_MsgSsrFlagTropoGridPoints =
  template this: untyped = result
  this = new(Integrity_MsgSsrFlagTropoGridPoints)
  let root = if root == nil: cast[Integrity](this) else: cast[Integrity](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Header of an integrity message.

  ]##
  let headerExpr = Integrity_IntegritySsrHeader.read(this.io, this.root, this)
  this.header = headerExpr

  ##[
  Number of faulty grid points.

  ]##
  let nFaultyPointsExpr = this.io.readU1()
  this.nFaultyPoints = nFaultyPointsExpr

  ##[
  List of faulty grid points.

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = this.io.readU2le()
      this.faultyPoints.add(it)
      inc i

proc fromFile*(_: typedesc[Integrity_MsgSsrFlagTropoGridPoints], filename: string): Integrity_MsgSsrFlagTropoGridPoints =
  Integrity_MsgSsrFlagTropoGridPoints.read(newKaitaiFileStream(filename), nil, nil)


##[
Integrity monitoring flags for multiple aggregated elements. An element
could be a satellite, SSR grid point, or SSR tile. A group of aggregated
elements being monitored for integrity could refer to:

- Satellites in a particular {GPS, GAL, BDS} constellation.

- Satellites in the line-of-sight of a particular SSR tile.

- Satellites in the line-of-sight of a particular SSR grid point.

The integrity usage for a group of aggregated elements varies according
to the integrity flag of the satellites comprising that group.

SSR_INTEGRITY_USAGE_NOMINAL: All satellites received passed the
integrity check and have flag INTEGRITY_FLAG_OK.

SSR_INTEGRITY_USAGE_WARNING: A limited number of elements in the group
failed the integrity check. Refer to more granular integrity messages
for details on the specific failing elements.

SSR_INTEGRITY_USAGE_ALERT: Most elements in the group failed the
integrity check, do not use for positioning.

SSR_INTEGRITY_USAGE_NOT_MONITORED: Unable to verify the integrity flag
of elements in the group.

]##
proc read*(_: typedesc[Integrity_MsgSsrFlagHighLevel], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Integrity_MsgSsrFlagHighLevel =
  template this: untyped = result
  this = new(Integrity_MsgSsrFlagHighLevel)
  let root = if root == nil: cast[Integrity](this) else: cast[Integrity](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  GNSS reference time of the observation used to generate the flag.

  ]##
  let obsTimeExpr = Gnss_GpsTimeSec.read(this.io, this.root, this)
  this.obsTime = obsTimeExpr

  ##[
  GNSS reference time of the correction associated to the flag.

  ]##
  let corrTimeExpr = Gnss_GpsTimeSec.read(this.io, this.root, this)
  this.corrTime = corrTimeExpr

  ##[
  SSR Solution ID.

  ]##
  let ssrSolIdExpr = this.io.readU1()
  this.ssrSolId = ssrSolIdExpr

  ##[
  Unique identifier of the set this tile belongs to.

  ]##
  let tileSetIdExpr = this.io.readU2le()
  this.tileSetId = tileSetIdExpr

  ##[
  Unique identifier of this tile in the tile set.

  ]##
  let tileIdExpr = this.io.readU2le()
  this.tileId = tileIdExpr

  ##[
  Chain and type of flag.

  ]##
  let chainIdExpr = this.io.readU1()
  this.chainId = chainIdExpr

  ##[
  Use GPS satellites.

  ]##
  let useGpsSatExpr = this.io.readU1()
  this.useGpsSat = useGpsSatExpr

  ##[
  Use GAL satellites.

  ]##
  let useGalSatExpr = this.io.readU1()
  this.useGalSat = useGalSatExpr

  ##[
  Use BDS satellites.

  ]##
  let useBdsSatExpr = this.io.readU1()
  this.useBdsSat = useBdsSatExpr

  ##[
  Reserved

  ]##
  for i in 0 ..< int(6):
    let it = this.io.readU1()
    this.reserved.add(it)

  ##[
  Use tropo grid points.

  ]##
  let useTropoGridPointsExpr = this.io.readU1()
  this.useTropoGridPoints = useTropoGridPointsExpr

  ##[
  Use iono grid points.

  ]##
  let useIonoGridPointsExpr = this.io.readU1()
  this.useIonoGridPoints = useIonoGridPointsExpr

  ##[
  Use iono tile satellite LoS.

  ]##
  let useIonoTileSatLosExpr = this.io.readU1()
  this.useIonoTileSatLos = useIonoTileSatLosExpr

  ##[
  Use iono grid point satellite LoS.

  ]##
  let useIonoGridPointSatLosExpr = this.io.readU1()
  this.useIonoGridPointSatLos = useIonoGridPointSatLosExpr

proc fromFile*(_: typedesc[Integrity_MsgSsrFlagHighLevel], filename: string): Integrity_MsgSsrFlagHighLevel =
  Integrity_MsgSsrFlagHighLevel.read(newKaitaiFileStream(filename), nil, nil)

