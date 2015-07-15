module SwiftNav.SBP.Piksi where

import Data.Binary
import Data.Int
import Data.Text
import Data.Word

msgAlmanac :: Word16
msgAlmanac = 0x0069

data MsgAlmanac = MsgAlmanac
  deriving ( Show, Read, Eq )

instance Binary MsgAlmanac where
  get =
    undefined
  put MsgAlmanac {..} =
    undefined

msgSetTime :: Word16
msgSetTime = 0x0068

data MsgSetTime = MsgSetTime
  deriving ( Show, Read, Eq )

instance Binary MsgSetTime where
  get =
    undefined
  put MsgSetTime {..} =
    undefined

msgReset :: Word16
msgReset = 0x00B2

data MsgReset = MsgReset
  deriving ( Show, Read, Eq )

instance Binary MsgReset where
  get =
    undefined
  put MsgReset {..} =
    undefined

msgCwResults :: Word16
msgCwResults = 0x00C0

data MsgCwResults = MsgCwResults
  deriving ( Show, Read, Eq )

instance Binary MsgCwResults where
  get =
    undefined
  put MsgCwResults {..} =
    undefined

msgCwStart :: Word16
msgCwStart = 0x00C1

data MsgCwStart = MsgCwStart
  deriving ( Show, Read, Eq )

instance Binary MsgCwStart where
  get =
    undefined
  put MsgCwStart {..} =
    undefined

msgResetFilters :: Word16
msgResetFilters = 0x0022

data MsgResetFilters = MsgResetFilters
  { msgResetFiltersFilter :: Word8
  } deriving ( Show, Read, Eq )

instance Binary MsgResetFilters where
  get =
    undefined
  put MsgResetFilters {..} =
    undefined

msgInitBase :: Word16
msgInitBase = 0x0023

data MsgInitBase = MsgInitBase
  deriving ( Show, Read, Eq )

instance Binary MsgInitBase where
  get =
    undefined
  put MsgInitBase {..} =
    undefined

msgThreadState :: Word16
msgThreadState = 0x0017

data MsgThreadState = MsgThreadState
  { msgThreadStateName       :: Text
  , msgThreadStateCpu        :: Word16
  , msgThreadStateStackFree  :: Word32
  } deriving ( Show, Read, Eq )

instance Binary MsgThreadState where
  get =
    undefined
  put MsgThreadState {..} =
    undefined

data UARTChannel = UARTChannel
  { uARTChannelTxThroughput    :: Float
  , uARTChannelRxThroughput    :: Float
  , uARTChannelCrcErrorCount   :: Word16
  , uARTChannelIoErrorCount    :: Word16
  , uARTChannelTxBufferLevel   :: Word8
  , uARTChannelRxBufferLevel   :: Word8
  } deriving ( Show, Read, Eq )

instance Binary UARTChannel where
  get =
    undefined
  put UARTChannel {..} =
    undefined

data Latency = Latency
  { latencyAvg     :: Int32
  , latencyLmin    :: Int32
  , latencyLmax    :: Int32
  , latencyCurrent :: Int32
  } deriving ( Show, Read, Eq )

instance Binary Latency where
  get =
    undefined
  put Latency {..} =
    undefined

msgUartState :: Word16
msgUartState = 0x0018

data MsgUartState = MsgUartState
  { msgUartStateUartA     :: UARTChannel
  , msgUartStateUartB     :: UARTChannel
  , msgUartStateUartFtdi  :: UARTChannel
  , msgUartStateLatency   :: Latency
  } deriving ( Show, Read, Eq )

instance Binary MsgUartState where
  get =
    undefined
  put MsgUartState {..} =
    undefined

msgIarState :: Word16
msgIarState = 0x0019

data MsgIarState = MsgIarState
  { msgIarStateNumHyps  :: Word32
  } deriving ( Show, Read, Eq )

instance Binary MsgIarState where
  get =
    undefined
  put MsgIarState {..} =
    undefined

msgMaskSatellite :: Word16
msgMaskSatellite = 0x001B

data MsgMaskSatellite = MsgMaskSatellite
  { msgMaskSatelliteMask :: Word8
  , msgMaskSatelliteSid  :: Word32
  } deriving ( Show, Read, Eq )

instance Binary MsgMaskSatellite where
  get =
    undefined
  put MsgMaskSatellite {..} =
    undefined
