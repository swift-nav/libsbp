{-# OPTIONS_GHC -fno-warn-unused-imports #-}
{-# LANGUAGE NoImplicitPrelude           #-}
{-# LANGUAGE TemplateHaskell             #-}
{-# LANGUAGE RecordWildCards             #-}

-- |
-- Module:      SwiftNav.SBP.SolutionMeta
-- Copyright:   Copyright (C) 2015-2018 Swift Navigation, Inc.
-- License:     MIT
-- Contact:     https://support.swiftnav.com
-- Stability:   experimental
-- Portability: portable
--
-- \<Standardized Metadata messages for Fuzed Solution from Swift Navigation
-- devices.\>

module SwiftNav.SBP.SolutionMeta
  ( module SwiftNav.SBP.SolutionMeta
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

{-# ANN module ("HLint: ignore Use camelCase"::String) #-}
{-# ANN module ("HLint: ignore Redundant do"::String) #-}
{-# ANN module ("HLint: ignore Use newtype instead of data"::String) #-}


-- | SolutionInputType.
--
-- Metadata describing which sensors were involved in the solution. The
-- structure is fixed no matter what the actual sensor type is. The sensor_type
-- field tells you which sensor we are talking about. It also tells you whether
-- the sensor data was actually used or not. The flags field, always a u8,
-- contains the sensor-specific data. The content of flags, for each sensor
-- type, is described in the relevant structures in this section.
data SolutionInputType = SolutionInputType
  { _solutionInputType_sensor_type :: !Word8
    -- ^ The type of sensor
  , _solutionInputType_flags     :: !Word8
    -- ^ Refer to each InputType description
  } deriving ( Show, Read, Eq )

instance Binary SolutionInputType where
  get = do
    _solutionInputType_sensor_type <- getWord8
    _solutionInputType_flags <- getWord8
    pure SolutionInputType {..}

  put SolutionInputType {..} = do
    putWord8 _solutionInputType_sensor_type
    putWord8 _solutionInputType_flags

$(makeJSON "_solutionInputType_" ''SolutionInputType)
$(makeLenses ''SolutionInputType)

msgSolnMeta :: Word16
msgSolnMeta = 0xFF0F

-- | SBP class for message MSG_SOLN_META (0xFF0F).
--
-- This message contains all metadata about the sensors received and/or used in
-- computing the Fuzed Solution. It focuses primarly, but not only, on GNSS
-- metadata.
data MsgSolnMeta = MsgSolnMeta
  { _msgSolnMeta_pdop                 :: !Word16
    -- ^ Position Dilution of Precision, as per last available DOPS from Starling
    -- GNSS engine
  , _msgSolnMeta_hdop                 :: !Word16
    -- ^ Horizontal Dilution of Precision, as per last available DOPS from
    -- Starling GNSS engine
  , _msgSolnMeta_vdop                 :: !Word16
    -- ^ Vertical Dilution of Precision, as per last available DOPS from Starling
    -- GNSS engine
  , _msgSolnMeta_n_sats               :: !Word8
    -- ^ Number of satellites, as per last available solution from Starling GNSS
    -- engine
  , _msgSolnMeta_age_corrections      :: !Word16
    -- ^ Age of the corrections (0xFFFF indicates invalid), as per last available
    -- AGE_CORRECTIONS from Starling GNSS engine
  , _msgSolnMeta_alignment_status     :: !Word8
    -- ^ State of alignment and the status and receipt of the alignment inputs
  , _msgSolnMeta_last_used_gnss_pos_tow :: !Word32
    -- ^ Tow of last-used GNSS position measurement
  , _msgSolnMeta_last_used_gnss_vel_tow :: !Word32
    -- ^ Tow of last-used GNSS velocity measurement
  , _msgSolnMeta_sol_in               :: ![SolutionInputType]
    -- ^ Array of Metadata describing the sensors potentially involved in the
    -- solution. Each element in the array represents a single sensor type and
    -- consists of flags containing (meta)data pertaining to that specific
    -- single sensor. Refer to each (XX)InputType descriptor in the present
    -- doc.
  } deriving ( Show, Read, Eq )

instance Binary MsgSolnMeta where
  get = do
    _msgSolnMeta_pdop <- getWord16le
    _msgSolnMeta_hdop <- getWord16le
    _msgSolnMeta_vdop <- getWord16le
    _msgSolnMeta_n_sats <- getWord8
    _msgSolnMeta_age_corrections <- getWord16le
    _msgSolnMeta_alignment_status <- getWord8
    _msgSolnMeta_last_used_gnss_pos_tow <- getWord32le
    _msgSolnMeta_last_used_gnss_vel_tow <- getWord32le
    _msgSolnMeta_sol_in <- whileM (not <$> isEmpty) get
    pure MsgSolnMeta {..}

  put MsgSolnMeta {..} = do
    putWord16le _msgSolnMeta_pdop
    putWord16le _msgSolnMeta_hdop
    putWord16le _msgSolnMeta_vdop
    putWord8 _msgSolnMeta_n_sats
    putWord16le _msgSolnMeta_age_corrections
    putWord8 _msgSolnMeta_alignment_status
    putWord32le _msgSolnMeta_last_used_gnss_pos_tow
    putWord32le _msgSolnMeta_last_used_gnss_vel_tow
    mapM_ put _msgSolnMeta_sol_in

$(makeSBP 'msgSolnMeta ''MsgSolnMeta)
$(makeJSON "_msgSolnMeta_" ''MsgSolnMeta)
$(makeLenses ''MsgSolnMeta)

-- | GNSSInputType.
--
-- Metadata around the GNSS sensors involved in the fuzed solution. Accessible
-- through sol_in[N].flags in a MSG_SOLN_META.
data GNSSInputType = GNSSInputType
  { _gNSSInputType_flags :: !Word8
    -- ^ flags that store all relevant info specific to this sensor type.
  } deriving ( Show, Read, Eq )

instance Binary GNSSInputType where
  get = do
    _gNSSInputType_flags <- getWord8
    pure GNSSInputType {..}

  put GNSSInputType {..} = do
    putWord8 _gNSSInputType_flags

$(makeJSON "_gNSSInputType_" ''GNSSInputType)
$(makeLenses ''GNSSInputType)

-- | IMUInputType.
--
-- Metadata around the IMU sensors involved in the fuzed solution. Accessible
-- through sol_in[N].flags in a MSG_SOLN_META.
data IMUInputType = IMUInputType
  { _iMUInputType_flags :: !Word8
    -- ^ Instrument time, grade, and architecture for a sensor.
  } deriving ( Show, Read, Eq )

instance Binary IMUInputType where
  get = do
    _iMUInputType_flags <- getWord8
    pure IMUInputType {..}

  put IMUInputType {..} = do
    putWord8 _iMUInputType_flags

$(makeJSON "_iMUInputType_" ''IMUInputType)
$(makeLenses ''IMUInputType)

-- | OdoInputType.
--
-- Metadata around the Odometry sensors involved in the fuzed solution.
-- Accessible through sol_in[N].flags in a MSG_SOLN_META.
data OdoInputType = OdoInputType
  { _odoInputType_flags :: !Word8
    -- ^ Instrument ODO rate, grade, and quality.
  } deriving ( Show, Read, Eq )

instance Binary OdoInputType where
  get = do
    _odoInputType_flags <- getWord8
    pure OdoInputType {..}

  put OdoInputType {..} = do
    putWord8 _odoInputType_flags

$(makeJSON "_odoInputType_" ''OdoInputType)
$(makeLenses ''OdoInputType)
