module SwiftNav.SBP.Piksi where

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

msgAlmanac :: Word16
msgAlmanac = 0x0069

data MsgAlmanac = MsgAlmanac
  deriving ( Show, Read, Eq )

instance Binary MsgAlmanac where
  get =
    return MsgAlmanac

  put MsgAlmanac =
    return ()

msgSetTime :: Word16
msgSetTime = 0x0068

data MsgSetTime = MsgSetTime
  deriving ( Show, Read, Eq )

instance Binary MsgSetTime where
  get =
    return MsgSetTime

  put MsgSetTime =
    return ()

msgReset :: Word16
msgReset = 0x00B2

data MsgReset = MsgReset
  deriving ( Show, Read, Eq )

instance Binary MsgReset where
  get =
    return MsgReset

  put MsgReset =
    return ()

msgCwResults :: Word16
msgCwResults = 0x00C0

data MsgCwResults = MsgCwResults
  deriving ( Show, Read, Eq )

instance Binary MsgCwResults where
  get =
    return MsgCwResults

  put MsgCwResults =
    return ()

msgCwStart :: Word16
msgCwStart = 0x00C1

data MsgCwStart = MsgCwStart
  deriving ( Show, Read, Eq )

instance Binary MsgCwStart where
  get =
    return MsgCwStart

  put MsgCwStart =
    return ()

msgResetFilters :: Word16
msgResetFilters = 0x0022

data MsgResetFilters = MsgResetFilters
  { msgResetFiltersFilter :: Word8
  } deriving ( Show, Read, Eq )

instance Binary MsgResetFilters where
  get = do
    msgResetFiltersFilter <- getWord8
    return MsgResetFilters {..}

  put MsgResetFilters {..} = do
    putWord8 msgResetFiltersFilter

msgInitBase :: Word16
msgInitBase = 0x0023

data MsgInitBase = MsgInitBase
  deriving ( Show, Read, Eq )

instance Binary MsgInitBase where
  get =
    return MsgInitBase

  put MsgInitBase =
    return ()

msgThreadState :: Word16
msgThreadState = 0x0017

data MsgThreadState = MsgThreadState
  { msgThreadStateName       :: ByteString
  , msgThreadStateCpu        :: Word16
  , msgThreadStateStackFree  :: Word32
  } deriving ( Show, Read, Eq )

instance Binary MsgThreadState where
  get = do
    msgThreadStateName <- getByteString 20
    msgThreadStateCpu <- getWord16le
    msgThreadStateStackFree <- getWord32le
    return MsgThreadState {..}

  put MsgThreadState {..} = do
    putByteString msgThreadStateName
    putWord16le msgThreadStateCpu
    putWord32le msgThreadStateStackFree

data UARTChannel = UARTChannel
  { uARTChannelTxThroughput    :: Float
  , uARTChannelRxThroughput    :: Float
  , uARTChannelCrcErrorCount   :: Word16
  , uARTChannelIoErrorCount    :: Word16
  , uARTChannelTxBufferLevel   :: Word8
  , uARTChannelRxBufferLevel   :: Word8
  } deriving ( Show, Read, Eq )

instance Binary UARTChannel where
  get = do
    uARTChannelTxThroughput <- getFloat32le
    uARTChannelRxThroughput <- getFloat32le
    uARTChannelCrcErrorCount <- getWord16le
    uARTChannelIoErrorCount <- getWord16le
    uARTChannelTxBufferLevel <- getWord8
    uARTChannelRxBufferLevel <- getWord8
    return UARTChannel {..}

  put UARTChannel {..} = do
    putFloat32le uARTChannelTxThroughput
    putFloat32le uARTChannelRxThroughput
    putWord16le uARTChannelCrcErrorCount
    putWord16le uARTChannelIoErrorCount
    putWord8 uARTChannelTxBufferLevel
    putWord8 uARTChannelRxBufferLevel

data Latency = Latency
  { latencyAvg     :: Int32
  , latencyLmin    :: Int32
  , latencyLmax    :: Int32
  , latencyCurrent :: Int32
  } deriving ( Show, Read, Eq )

instance Binary Latency where
  get = do
    latencyAvg <- liftM fromIntegral getWord32le
    latencyLmin <- liftM fromIntegral getWord32le
    latencyLmax <- liftM fromIntegral getWord32le
    latencyCurrent <- liftM fromIntegral getWord32le
    return Latency {..}

  put Latency {..} = do
    putWord32le $ fromIntegral latencyAvg
    putWord32le $ fromIntegral latencyLmin
    putWord32le $ fromIntegral latencyLmax
    putWord32le $ fromIntegral latencyCurrent

msgUartState :: Word16
msgUartState = 0x0018

data MsgUartState = MsgUartState
  { msgUartStateUartA     :: UARTChannel
  , msgUartStateUartB     :: UARTChannel
  , msgUartStateUartFtdi  :: UARTChannel
  , msgUartStateLatency   :: Latency
  } deriving ( Show, Read, Eq )

instance Binary MsgUartState where
  get = do
    msgUartStateUartA <- get
    msgUartStateUartB <- get
    msgUartStateUartFtdi <- get
    msgUartStateLatency <- get
    return MsgUartState {..}

  put MsgUartState {..} = do
    put msgUartStateUartA
    put msgUartStateUartB
    put msgUartStateUartFtdi
    put msgUartStateLatency

msgIarState :: Word16
msgIarState = 0x0019

data MsgIarState = MsgIarState
  { msgIarStateNumHyps  :: Word32
  } deriving ( Show, Read, Eq )

instance Binary MsgIarState where
  get = do
    msgIarStateNumHyps <- getWord32le
    return MsgIarState {..}

  put MsgIarState {..} = do
    putWord32le msgIarStateNumHyps

msgMaskSatellite :: Word16
msgMaskSatellite = 0x001B

data MsgMaskSatellite = MsgMaskSatellite
  { msgMaskSatelliteMask :: Word8
  , msgMaskSatelliteSid  :: Word32
  } deriving ( Show, Read, Eq )

instance Binary MsgMaskSatellite where
  get = do
    msgMaskSatelliteMask <- getWord8
    msgMaskSatelliteSid <- getWord32le
    return MsgMaskSatellite {..}

  put MsgMaskSatellite {..} = do
    putWord8 msgMaskSatelliteMask
    putWord32le msgMaskSatelliteSid
