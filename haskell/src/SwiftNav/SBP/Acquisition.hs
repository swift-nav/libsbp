module SwiftNav.SBP.Acquisition where

import Data.Int
import Data.Text
import Data.Word


msgAcqResult :: Word16
msgAcqResult = 0x0014

data MsgAcqResult = MsgAcqResult
  { msgAcqResultSnr :: Float
  , msgAcqResultCp  :: Float
  , msgAcqResultCf  :: Float
  , msgAcqResultSid :: Word32
  } deriving ( Show, Read, Eq )

msgAcqResultDepA :: Word16
msgAcqResultDepA = 0x0015

data MsgAcqResultDepA = MsgAcqResultDepA
  { msgAcqResultDepASnr :: Float
  , msgAcqResultDepACp  :: Float
  , msgAcqResultDepACf  :: Float
  , msgAcqResultDepAPrn :: Word8
  } deriving ( Show, Read, Eq )
