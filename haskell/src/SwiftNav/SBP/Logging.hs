module SwiftNav.SBP.Logging where

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

msgPrint :: Word16
msgPrint = 0x0010

data MsgPrint = MsgPrint
  { msgPrintText :: ByteString
  } deriving ( Show, Read, Eq )

instance Binary MsgPrint where
  get = do
    msgPrintText <- liftM toStrict getRemainingLazyByteString
    return MsgPrint {..}

  put MsgPrint {..} = do
    putByteString msgPrintText

msgTweet :: Word16
msgTweet = 0x0012

data MsgTweet = MsgTweet
  { msgTweetTweet :: ByteString
  } deriving ( Show, Read, Eq )

instance Binary MsgTweet where
  get = do
    msgTweetTweet <- getByteString 140
    return MsgTweet {..}

  put MsgTweet {..} = do
    putByteString msgTweetTweet
