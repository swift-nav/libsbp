module SwiftNav.SBP.Logging where

import Data.Int
import Data.Text
import Data.Word


msgPrint :: Word16
msgPrint = 0x0010
data MsgPrint = MsgPrint
  { msgPrintText :: Text
  } deriving ( Show, Read, Eq )

msgTweet :: Word16
msgTweet = 0x0012
data MsgTweet = MsgTweet
  { msgTweetTweet :: Text
  } deriving ( Show, Read, Eq )
