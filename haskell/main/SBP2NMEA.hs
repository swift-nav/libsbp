{-# LANGUAGE NoImplicitPrelude #-}
{-# LANGUAGE OverloadedStrings #-}

-- |
-- Module:      SBP2JNMEA
-- Copyright:   Copyright (C) 2020-2021 Swift Navigation, Inc.
-- License:     LGPL-3
-- Contact:     https://support.swiftnav.com
-- Stability:   experimental
-- Portability: portable
--
-- SBP to NMEA tool - reads SBP binary from stdin and sends NMEA
-- to stdout.

import           BasicPrelude                      hiding (map)
import           Control.Lens
import           Control.Monad.Trans.Resource
import           Data.Bits
import qualified Data.ByteString                   as BS
import qualified Data.ByteString.Char8             as BS8
import           Data.Conduit
import           Data.Conduit.Binary
import           Data.Conduit.List
import           Data.Conduit.Serialization.Binary
import           Data.Time
import           Data.Time.Clock.POSIX
import           Data.Word
import           SwiftNav.SBP
import           System.IO
import           Text.Printf

-- | NMEA time.
--
timestamp :: MsgPosLlh -> ByteString
timestamp posLlh = BS8.pack $ printf "%s.%03u" times mods
  where
    epochs       = 315964800
    offsets      = 18
    (tows, mods) = divMod (posLlh ^. msgPosLlh_tow) 1000
    seconds      = epochs - offsets + tows
    time         = posixSecondsToUTCTime $ fromIntegral seconds
    times        = formatTime defaultTimeLocale "%H%M%S" time

-- | NMEA latitude.
--
lat :: MsgPosLlh -> ByteString
lat posLlh = BS8.pack $ printf "%02u%010.7f" i (60 * f)
  where
    (i, f) = properFraction (abs $ posLlh ^. msgPosLlh_lat) :: (Word16, Double)

-- | NMEA latitude direction.
--
latDir :: MsgPosLlh -> ByteString
latDir posLlh = bool "S" "N" $ posLlh ^. msgPosLlh_lat > 0

-- | NMEA longitude.
--
lon :: MsgPosLlh -> ByteString
lon posLlh = BS8.pack $ printf "%03u%010.7f" i (60 * f)
  where
    (i, f) = properFraction (abs $ posLlh ^. msgPosLlh_lon) :: (Word16, Double)

-- | NMEA longitude direction.
--
lonDir :: MsgPosLlh -> ByteString
lonDir posLlh = bool "W" "E" $ posLlh ^. msgPosLlh_lon > 0

-- | NMEA quality.
--
quality :: MsgPosLlh -> ByteString
quality posLlh = case posLlh ^. msgPosLlh_flags .&. 0x7 of
  0 -> "0"
  1 -> "1"
  2 -> "2"
  3 -> "5"
  4 -> "4"
  _ -> "0"

-- | NMEA number of satellites.
--
satellites :: MsgPosLlh -> ByteString
satellites posLlh = BS8.pack $ printf "%02u" $ posLlh ^. msgPosLlh_n_sats

-- | NMEA altitude.
--
height :: MsgPosLlh -> ByteString
height posLlh = BS8.pack $ printf "%.2f" $ posLlh ^. msgPosLlh_height

-- | NMEA sentence for GGA for GPS.
--
sentence :: MsgPosLlh -> ByteString
sentence posLlh =
  BS8.intercalate ","
    [ "GPGGA"
    , timestamp posLlh
    , lat posLlh
    , latDir posLlh
    , lon posLlh
    , lonDir posLlh
    , quality posLlh
    , satellites posLlh
    , "0.0"
    , height posLlh
    , "M"
    , "0.0"
    , "M"
    , mempty
    , mempty
    ]

-- | NMEA checksum.
--
checksum :: ByteString -> ByteString
checksum s = BS8.pack $ printf "%02x" $ BS.foldl' xor 0 s

-- | NMEA GGA for GPS.
--
gpgga :: MsgPosLlh -> ByteString
gpgga posLlh =  "$" <> s <> "*" <> c <> "\r\n"
 where
    s = sentence posLlh
    c = checksum s

-- | Encode a SBPMsg to a line of JSON.
encodeLine :: SBPMsg -> ByteString
encodeLine (SBPMsgPosLlh posLlh _msg) = gpgga posLlh
encodeLine _                          = mempty

main :: IO ()
main = do
  hSetBuffering stdin NoBuffering
  hSetBuffering stdout NoBuffering
  runResourceT $
    sourceHandle stdin
      =$= conduitDecode
      =$= map encodeLine
      $$  sinkHandle stdout
