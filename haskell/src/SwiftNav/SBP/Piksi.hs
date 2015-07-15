module SwiftNav.SBP.Piksi where

import Data.Int
import Data.Text
import Data.Word


msgAlmanac :: Word16
msgAlmanac = 0x0069
data MsgAlmanac = MsgAlmanac
  deriving ( Show, Read, Eq )

msgSetTime :: Word16
msgSetTime = 0x0068
data MsgSetTime = MsgSetTime
  deriving ( Show, Read, Eq )

msgReset :: Word16
msgReset = 0x00B2
data MsgReset = MsgReset
  deriving ( Show, Read, Eq )

msgCwResults :: Word16
msgCwResults = 0x00C0
data MsgCwResults = MsgCwResults
  deriving ( Show, Read, Eq )

msgCwStart :: Word16
msgCwStart = 0x00C1
data MsgCwStart = MsgCwStart
  deriving ( Show, Read, Eq )

msgResetFilters :: Word16
msgResetFilters = 0x0022
data MsgResetFilters = MsgResetFilters
  { msgResetFiltersFilter :: Word8
  } deriving ( Show, Read, Eq )

msgInitBase :: Word16
msgInitBase = 0x0023
data MsgInitBase = MsgInitBase
  deriving ( Show, Read, Eq )

msgThreadState :: Word16
msgThreadState = 0x0017
data MsgThreadState = MsgThreadState
  { msgThreadStateName       :: Text
  , msgThreadStateCpu        :: Word16
  , msgThreadStateStackFree  :: Word32
  } deriving ( Show, Read, Eq )

data UARTChannel = UARTChannel
  { uARTChannelTxThroughput    :: Float
  , uARTChannelRxThroughput    :: Float
  , uARTChannelCrcErrorCount   :: Word16
  , uARTChannelIoErrorCount    :: Word16
  , uARTChannelTxBufferLevel   :: Word8
  , uARTChannelRxBufferLevel   :: Word8
  } deriving ( Show, Read, Eq )

data Latency = Latency
  { latencyAvg     :: Int32
  , latencyLmin    :: Int32
  , latencyLmax    :: Int32
  , latencyCurrent :: Int32
  } deriving ( Show, Read, Eq )

msgUartState :: Word16
msgUartState = 0x0018
data MsgUartState = MsgUartState
  { msgUartStateUartA     :: UARTChannel
  , msgUartStateUartB     :: UARTChannel
  , msgUartStateUartFtdi  :: UARTChannel
  , msgUartStateLatency   :: Latency
  } deriving ( Show, Read, Eq )

msgIarState :: Word16
msgIarState = 0x0019
data MsgIarState = MsgIarState
  { msgIarStateNumHyps  :: Word32
  } deriving ( Show, Read, Eq )

msgMaskSatellite :: Word16
msgMaskSatellite = 0x001B
data MsgMaskSatellite = MsgMaskSatellite
  { msgMaskSatelliteMask :: Word8
  , msgMaskSatelliteSid  :: Word32
  } deriving ( Show, Read, Eq )
