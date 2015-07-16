module SwiftNav.SBP.Navigation where

import Control.Monad
import Control.Monad.Loops
import Data.Binary
import Data.Binary.Get
import Data.Binary.IEEE754
import Data.Binary.Put
import Data.ByteString
import Data.ByteString.Lazy hiding ( ByteString )
import Data.Int
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
  get = do
    msgGpsTimeWn <- getWord16le
    msgGpsTimeTow <- getWord32le
    msgGpsTimeNs <- liftM fromIntegral getWord32le
    msgGpsTimeFlags <- getWord8
    return MsgGpsTime {..}

  put MsgGpsTime {..} = do
    putWord16le msgGpsTimeWn
    putWord32le msgGpsTimeTow
    putWord32le $ fromIntegral msgGpsTimeNs
    putWord8 msgGpsTimeFlags

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
  get = do
    msgDopsTow <- getWord32le
    msgDopsGdop <- getWord16le
    msgDopsPdop <- getWord16le
    msgDopsTdop <- getWord16le
    msgDopsHdop <- getWord16le
    msgDopsVdop <- getWord16le
    return MsgDops {..}

  put MsgDops {..} = do
    putWord32le msgDopsTow
    putWord16le msgDopsGdop
    putWord16le msgDopsPdop
    putWord16le msgDopsTdop
    putWord16le msgDopsHdop
    putWord16le msgDopsVdop

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
  get = do
    msgPosEcefTow <- getWord32le
    msgPosEcefX <- getFloat64le
    msgPosEcefY <- getFloat64le
    msgPosEcefZ <- getFloat64le
    msgPosEcefAccuracy <- getWord16le
    msgPosEcefNSats <- getWord8
    msgPosEcefFlags <- getWord8
    return MsgPosEcef {..}

  put MsgPosEcef {..} = do
    putWord32le msgPosEcefTow
    putFloat64le msgPosEcefX
    putFloat64le msgPosEcefY
    putFloat64le msgPosEcefZ
    putWord16le msgPosEcefAccuracy
    putWord8 msgPosEcefNSats
    putWord8 msgPosEcefFlags

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
  get = do
    msgPosLlhTow <- getWord32le
    msgPosLlhLat <- getFloat64le
    msgPosLlhLon <- getFloat64le
    msgPosLlhHeight <- getFloat64le
    msgPosLlhHAccuracy <- getWord16le
    msgPosLlhVAccuracy <- getWord16le
    msgPosLlhNSats <- getWord8
    msgPosLlhFlags <- getWord8
    return MsgPosLlh {..}

  put MsgPosLlh {..} = do
    putWord32le msgPosLlhTow
    putFloat64le msgPosLlhLat
    putFloat64le msgPosLlhLon
    putFloat64le msgPosLlhHeight
    putWord16le msgPosLlhHAccuracy
    putWord16le msgPosLlhVAccuracy
    putWord8 msgPosLlhNSats
    putWord8 msgPosLlhFlags

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
  get = do
    msgBaselineEcefTow <- getWord32le
    msgBaselineEcefX <- liftM fromIntegral getWord32le
    msgBaselineEcefY <- liftM fromIntegral getWord32le
    msgBaselineEcefZ <- liftM fromIntegral getWord32le
    msgBaselineEcefAccuracy <- getWord16le
    msgBaselineEcefNSats <- getWord8
    msgBaselineEcefFlags <- getWord8
    return MsgBaselineEcef {..}

  put MsgBaselineEcef {..} = do
    putWord32le msgBaselineEcefTow
    putWord32le $ fromIntegral msgBaselineEcefX
    putWord32le $ fromIntegral msgBaselineEcefY
    putWord32le $ fromIntegral msgBaselineEcefZ
    putWord16le msgBaselineEcefAccuracy
    putWord8 msgBaselineEcefNSats
    putWord8 msgBaselineEcefFlags

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
  get = do
    msgBaselineNedTow <- getWord32le
    msgBaselineNedN <- liftM fromIntegral getWord32le
    msgBaselineNedE <- liftM fromIntegral getWord32le
    msgBaselineNedD <- liftM fromIntegral getWord32le
    msgBaselineNedHAccuracy <- getWord16le
    msgBaselineNedVAccuracy <- getWord16le
    msgBaselineNedNSats <- getWord8
    msgBaselineNedFlags <- getWord8
    return MsgBaselineNed {..}

  put MsgBaselineNed {..} = do
    putWord32le msgBaselineNedTow
    putWord32le $ fromIntegral msgBaselineNedN
    putWord32le $ fromIntegral msgBaselineNedE
    putWord32le $ fromIntegral msgBaselineNedD
    putWord16le msgBaselineNedHAccuracy
    putWord16le msgBaselineNedVAccuracy
    putWord8 msgBaselineNedNSats
    putWord8 msgBaselineNedFlags

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
  get = do
    msgVelEcefTow <- getWord32le
    msgVelEcefX <- liftM fromIntegral getWord32le
    msgVelEcefY <- liftM fromIntegral getWord32le
    msgVelEcefZ <- liftM fromIntegral getWord32le
    msgVelEcefAccuracy <- getWord16le
    msgVelEcefNSats <- getWord8
    msgVelEcefFlags <- getWord8
    return MsgVelEcef {..}

  put MsgVelEcef {..} = do
    putWord32le msgVelEcefTow
    putWord32le $ fromIntegral msgVelEcefX
    putWord32le $ fromIntegral msgVelEcefY
    putWord32le $ fromIntegral msgVelEcefZ
    putWord16le msgVelEcefAccuracy
    putWord8 msgVelEcefNSats
    putWord8 msgVelEcefFlags

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
  get = do
    msgVelNedTow <- getWord32le
    msgVelNedN <- liftM fromIntegral getWord32le
    msgVelNedE <- liftM fromIntegral getWord32le
    msgVelNedD <- liftM fromIntegral getWord32le
    msgVelNedHAccuracy <- getWord16le
    msgVelNedVAccuracy <- getWord16le
    msgVelNedNSats <- getWord8
    msgVelNedFlags <- getWord8
    return MsgVelNed {..}

  put MsgVelNed {..} = do
    putWord32le msgVelNedTow
    putWord32le $ fromIntegral msgVelNedN
    putWord32le $ fromIntegral msgVelNedE
    putWord32le $ fromIntegral msgVelNedD
    putWord16le msgVelNedHAccuracy
    putWord16le msgVelNedVAccuracy
    putWord8 msgVelNedNSats
    putWord8 msgVelNedFlags
