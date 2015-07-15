module SwiftNav.SBP.Navigation where

import Data.Binary
import Data.Int
import Data.Text
import Data.Word

msgGpsTime :: Word16
msgGpsTime = 0x0100

data MsgGpsTime = MsgGpsTime
  { msgGpsTimeWn    :: Word16
  , msgGpsTimeTow   :: Word32
  , msgGpsTimeNs    :: Int32
  , msgGpsTimeFlags :: Word8
  } deriving ( Show, Read, Eq )

instance Binary MsgGpsTime where
  get =
    undefined
  put MsgGpsTime {..} =
    undefined

msgDops :: Word16
msgDops = 0x0206

data MsgDops = MsgDops
  { msgDopsTow  :: Word32
  , msgDopsGdop :: Word16
  , msgDopsPdop :: Word16
  , msgDopsTdop :: Word16
  , msgDopsHdop :: Word16
  , msgDopsVdop :: Word16
  } deriving ( Show, Read, Eq )

instance Binary MsgDops where
  get =
    undefined
  put MsgDops {..} =
    undefined

msgPosEcef :: Word16
msgPosEcef = 0x0200

data MsgPosEcef = MsgPosEcef
  { msgPosEcefTow      :: Word32
  , msgPosEcefX        :: Double
  , msgPosEcefY        :: Double
  , msgPosEcefZ        :: Double
  , msgPosEcefAccuracy :: Word16
  , msgPosEcefNSats    :: Word8
  , msgPosEcefFlags    :: Word8
  } deriving ( Show, Read, Eq )

instance Binary MsgPosEcef where
  get =
    undefined
  put MsgPosEcef {..} =
    undefined

msgPosLlh :: Word16
msgPosLlh = 0x0201

data MsgPosLlh = MsgPosLlh
  { msgPosLlhTow        :: Word32
  , msgPosLlhLat        :: Double
  , msgPosLlhLon        :: Double
  , msgPosLlhHeight     :: Double
  , msgPosLlhHAccuracy  :: Word16
  , msgPosLlhVAccuracy  :: Word16
  , msgPosLlhNSats      :: Word8
  , msgPosLlhFlags      :: Word8
  } deriving ( Show, Read, Eq )

instance Binary MsgPosLlh where
  get =
    undefined
  put MsgPosLlh {..} =
    undefined

msgBaselineEcef :: Word16
msgBaselineEcef = 0x0202

data MsgBaselineEcef = MsgBaselineEcef
  { msgBaselineEcefTow      :: Word32
  , msgBaselineEcefX        :: Int32
  , msgBaselineEcefY        :: Int32
  , msgBaselineEcefZ        :: Int32
  , msgBaselineEcefAccuracy :: Word16
  , msgBaselineEcefNSats    :: Word8
  , msgBaselineEcefFlags    :: Word8
  } deriving ( Show, Read, Eq )

instance Binary MsgBaselineEcef where
  get =
    undefined
  put MsgBaselineEcef {..} =
    undefined

msgBaselineNed :: Word16
msgBaselineNed = 0x0203

data MsgBaselineNed = MsgBaselineNed
  { msgBaselineNedTow        :: Word32
  , msgBaselineNedN          :: Int32
  , msgBaselineNedE          :: Int32
  , msgBaselineNedD          :: Int32
  , msgBaselineNedHAccuracy  :: Word16
  , msgBaselineNedVAccuracy  :: Word16
  , msgBaselineNedNSats      :: Word8
  , msgBaselineNedFlags      :: Word8
  } deriving ( Show, Read, Eq )

instance Binary MsgBaselineNed where
  get =
    undefined
  put MsgBaselineNed {..} =
    undefined

msgVelEcef :: Word16
msgVelEcef = 0x0204

data MsgVelEcef = MsgVelEcef
  { msgVelEcefTow      :: Word32
  , msgVelEcefX        :: Int32
  , msgVelEcefY        :: Int32
  , msgVelEcefZ        :: Int32
  , msgVelEcefAccuracy :: Word16
  , msgVelEcefNSats    :: Word8
  , msgVelEcefFlags    :: Word8
  } deriving ( Show, Read, Eq )

instance Binary MsgVelEcef where
  get =
    undefined
  put MsgVelEcef {..} =
    undefined

msgVelNed :: Word16
msgVelNed = 0x0205

data MsgVelNed = MsgVelNed
  { msgVelNedTow        :: Word32
  , msgVelNedN          :: Int32
  , msgVelNedE          :: Int32
  , msgVelNedD          :: Int32
  , msgVelNedHAccuracy  :: Word16
  , msgVelNedVAccuracy  :: Word16
  , msgVelNedNSats      :: Word8
  , msgVelNedFlags      :: Word8
  } deriving ( Show, Read, Eq )

instance Binary MsgVelNed where
  get =
    undefined
  put MsgVelNed {..} =
    undefined
