import kaitai_struct_nim_runtime
import options

type
  User* = ref object of KaitaiStruct
    `parent`*: KaitaiStruct
  User_MsgUserData* = ref object of KaitaiStruct
    `contents`*: seq[uint8]
    `parent`*: Sbp_Message

proc read*(_: typedesc[User], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): User
proc read*(_: typedesc[User_MsgUserData], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): User_MsgUserData


proc read*(_: typedesc[User], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): User =
  template this: untyped = result
  this = new(User)
  let root = if root == nil: cast[User](this) else: cast[User](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[User], filename: string): User =
  User.read(newKaitaiFileStream(filename), nil, nil)


##[
This message can contain any application specific user data up to a
maximum length of 255 bytes per message.

]##
proc read*(_: typedesc[User_MsgUserData], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): User_MsgUserData =
  template this: untyped = result
  this = new(User_MsgUserData)
  let root = if root == nil: cast[User](this) else: cast[User](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  User data payload

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = this.io.readU1()
      this.contents.add(it)
      inc i

proc fromFile*(_: typedesc[User_MsgUserData], filename: string): User_MsgUserData =
  User_MsgUserData.read(newKaitaiFileStream(filename), nil, nil)

