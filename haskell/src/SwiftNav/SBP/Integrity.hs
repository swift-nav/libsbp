{-# OPTIONS_GHC -fno-warn-unused-imports #-}
{-# LANGUAGE NoImplicitPrelude           #-}
{-# LANGUAGE TemplateHaskell             #-}
{-# LANGUAGE RecordWildCards             #-}

-- |
-- Module:      SwiftNav.SBP.Integrity
-- Copyright:   Copyright (C) 2015-2021 Swift Navigation, Inc.
-- License:     MIT
-- Contact:     https://support.swiftnav.com
-- Stability:   experimental
-- Portability: portable
--
-- \< Integrity flag messages \>

module SwiftNav.SBP.Integrity
  ( module SwiftNav.SBP.Integrity
  ) where

import BasicPrelude
import Control.Lens
import Control.Monad.Loops
import Data.Binary
import Data.Binary.Get
import Data.Binary.IEEE754
import Data.Binary.Put
import Data.ByteString.Lazy    hiding (ByteString)
import Data.Int
import Data.Word
import SwiftNav.SBP.TH
import SwiftNav.SBP.Types
import SwiftNav.SBP.Gnss

{-# ANN module ("HLint: ignore Use camelCase"::String) #-}
{-# ANN module ("HLint: ignore Redundant do"::String) #-}
{-# ANN module ("HLint: ignore Use newtype instead of data"::String) #-}


msgSsrFlagHighLevel :: Word16
msgSsrFlagHighLevel = 0x0BB9

data MsgSsrFlagHighLevel = MsgSsrFlagHighLevel
  { _msgSsrFlagHighLevel_stub :: ![Word8]
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrFlagHighLevel where
  get = do
    _msgSsrFlagHighLevel_stub <- whileM (not <$> isEmpty) getWord8
    pure MsgSsrFlagHighLevel {..}

  put MsgSsrFlagHighLevel {..} = do
    mapM_ putWord8 _msgSsrFlagHighLevel_stub

$(makeSBP 'msgSsrFlagHighLevel ''MsgSsrFlagHighLevel)
$(makeJSON "_msgSsrFlagHighLevel_" ''MsgSsrFlagHighLevel)
$(makeLenses ''MsgSsrFlagHighLevel)

msgSsrFlagSatellites :: Word16
msgSsrFlagSatellites = 0x0BBD

data MsgSsrFlagSatellites = MsgSsrFlagSatellites
  { _msgSsrFlagSatellites_stub :: ![Word8]
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrFlagSatellites where
  get = do
    _msgSsrFlagSatellites_stub <- whileM (not <$> isEmpty) getWord8
    pure MsgSsrFlagSatellites {..}

  put MsgSsrFlagSatellites {..} = do
    mapM_ putWord8 _msgSsrFlagSatellites_stub

$(makeSBP 'msgSsrFlagSatellites ''MsgSsrFlagSatellites)
$(makeJSON "_msgSsrFlagSatellites_" ''MsgSsrFlagSatellites)
$(makeLenses ''MsgSsrFlagSatellites)

msgSsrFlagTropoGridPoints :: Word16
msgSsrFlagTropoGridPoints = 0x0BC3

data MsgSsrFlagTropoGridPoints = MsgSsrFlagTropoGridPoints
  { _msgSsrFlagTropoGridPoints_stub :: ![Word8]
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrFlagTropoGridPoints where
  get = do
    _msgSsrFlagTropoGridPoints_stub <- whileM (not <$> isEmpty) getWord8
    pure MsgSsrFlagTropoGridPoints {..}

  put MsgSsrFlagTropoGridPoints {..} = do
    mapM_ putWord8 _msgSsrFlagTropoGridPoints_stub

$(makeSBP 'msgSsrFlagTropoGridPoints ''MsgSsrFlagTropoGridPoints)
$(makeJSON "_msgSsrFlagTropoGridPoints_" ''MsgSsrFlagTropoGridPoints)
$(makeLenses ''MsgSsrFlagTropoGridPoints)

msgSsrFlagIonoGridPoints :: Word16
msgSsrFlagIonoGridPoints = 0x0BC7

data MsgSsrFlagIonoGridPoints = MsgSsrFlagIonoGridPoints
  { _msgSsrFlagIonoGridPoints_stub :: ![Word8]
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrFlagIonoGridPoints where
  get = do
    _msgSsrFlagIonoGridPoints_stub <- whileM (not <$> isEmpty) getWord8
    pure MsgSsrFlagIonoGridPoints {..}

  put MsgSsrFlagIonoGridPoints {..} = do
    mapM_ putWord8 _msgSsrFlagIonoGridPoints_stub

$(makeSBP 'msgSsrFlagIonoGridPoints ''MsgSsrFlagIonoGridPoints)
$(makeJSON "_msgSsrFlagIonoGridPoints_" ''MsgSsrFlagIonoGridPoints)
$(makeLenses ''MsgSsrFlagIonoGridPoints)

msgSsrFlagIonoTileSatLos :: Word16
msgSsrFlagIonoTileSatLos = 0x0BCD

data MsgSsrFlagIonoTileSatLos = MsgSsrFlagIonoTileSatLos
  { _msgSsrFlagIonoTileSatLos_stub :: ![Word8]
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrFlagIonoTileSatLos where
  get = do
    _msgSsrFlagIonoTileSatLos_stub <- whileM (not <$> isEmpty) getWord8
    pure MsgSsrFlagIonoTileSatLos {..}

  put MsgSsrFlagIonoTileSatLos {..} = do
    mapM_ putWord8 _msgSsrFlagIonoTileSatLos_stub

$(makeSBP 'msgSsrFlagIonoTileSatLos ''MsgSsrFlagIonoTileSatLos)
$(makeJSON "_msgSsrFlagIonoTileSatLos_" ''MsgSsrFlagIonoTileSatLos)
$(makeLenses ''MsgSsrFlagIonoTileSatLos)

msgSsrFlagIonoGridPointSatLos :: Word16
msgSsrFlagIonoGridPointSatLos = 0x0BD1

data MsgSsrFlagIonoGridPointSatLos = MsgSsrFlagIonoGridPointSatLos
  { _msgSsrFlagIonoGridPointSatLos_stub :: ![Word8]
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrFlagIonoGridPointSatLos where
  get = do
    _msgSsrFlagIonoGridPointSatLos_stub <- whileM (not <$> isEmpty) getWord8
    pure MsgSsrFlagIonoGridPointSatLos {..}

  put MsgSsrFlagIonoGridPointSatLos {..} = do
    mapM_ putWord8 _msgSsrFlagIonoGridPointSatLos_stub

$(makeSBP 'msgSsrFlagIonoGridPointSatLos ''MsgSsrFlagIonoGridPointSatLos)
$(makeJSON "_msgSsrFlagIonoGridPointSatLos_" ''MsgSsrFlagIonoGridPointSatLos)
$(makeLenses ''MsgSsrFlagIonoGridPointSatLos)
