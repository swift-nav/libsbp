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


data IntegritySSRHeader = IntegritySSRHeader
  { _integritySSRHeader_obs_time  :: !GpsTimeSec
    -- ^ GNSS reference time of the observation used to generate the flag.
  , _integritySSRHeader_num_msgs  :: !Word8
    -- ^ Number of messages in the dataset
  , _integritySSRHeader_seq_num   :: !Word8
    -- ^ Position of this message in the dataset
  , _integritySSRHeader_ssr_sol_id :: !Word8
    -- ^ SSR Solution ID.
  , _integritySSRHeader_tile_set_id :: !Word16
    -- ^ Unique identifier of the set this tile belongs to.
  , _integritySSRHeader_tile_id   :: !Word16
    -- ^ Unique identifier of this tile in the tile set.
  , _integritySSRHeader_chain_id  :: !Word8
    -- ^ Chain and type of flag.
  } deriving ( Show, Read, Eq )

instance Binary IntegritySSRHeader where
  get = do
    _integritySSRHeader_obs_time <- get
    _integritySSRHeader_num_msgs <- getWord8
    _integritySSRHeader_seq_num <- getWord8
    _integritySSRHeader_ssr_sol_id <- getWord8
    _integritySSRHeader_tile_set_id <- getWord16le
    _integritySSRHeader_tile_id <- getWord16le
    _integritySSRHeader_chain_id <- getWord8
    pure IntegritySSRHeader {..}

  put IntegritySSRHeader {..} = do
    put _integritySSRHeader_obs_time
    putWord8 _integritySSRHeader_num_msgs
    putWord8 _integritySSRHeader_seq_num
    putWord8 _integritySSRHeader_ssr_sol_id
    putWord16le _integritySSRHeader_tile_set_id
    putWord16le _integritySSRHeader_tile_id
    putWord8 _integritySSRHeader_chain_id

$(makeJSON "_integritySSRHeader_" ''IntegritySSRHeader)
$(makeLenses ''IntegritySSRHeader)

msgSsrFlagHighLevel :: Word16
msgSsrFlagHighLevel = 0x0BB9

-- | SBP class for message MSG_SSR_FLAG_HIGH_LEVEL (0x0BB9).
--
-- Integrity monitoring flags for multiple aggregated elements. An element
-- could be a satellite, SSR grid point, or SSR tile. A group of aggregated
-- elements being monitored for integrity could refer to:
--
-- - Satellites in a particular {GPS, GAL, BDS} constellation.
--
-- - Satellites in the line-of-sight of a particular SSR tile.
--
-- - Satellites in the line-of-sight of a particular SSR grid point.
--
-- The integrity usage for a group of aggregated elements varies according to
-- the integrity flag of the satellites comprising that group.
--
-- SSR_INTEGRITY_USAGE_NOMINAL: All satellites received passed the integrity
-- check and have flag INTEGRITY_FLAG_OK.
--
-- SSR_INTEGRITY_USAGE_WARNING: A limited number of elements in the group
-- failed the integrity check. Refer to more granular integrity messages for
-- details on the specific failing elements.
--
-- SSR_INTEGRITY_USAGE_ALERT: Most elements in the group failed the integrity
-- check, do not use for positioning.
--
-- SSR_INTEGRITY_USAGE_NOT_MONITORED: Unable to verify the integrity flag of
-- elements in the group.
data MsgSsrFlagHighLevel = MsgSsrFlagHighLevel
  { _msgSsrFlagHighLevel_obs_time                  :: !GpsTimeSec
    -- ^ GNSS reference time of the observation used to generate the flag.
  , _msgSsrFlagHighLevel_corr_time                 :: !GpsTimeSec
    -- ^ GNSS reference time of the correction associated to the flag.
  , _msgSsrFlagHighLevel_ssr_sol_id                :: !Word8
    -- ^ SSR Solution ID.
  , _msgSsrFlagHighLevel_tile_set_id               :: !Word16
    -- ^ Unique identifier of the set this tile belongs to.
  , _msgSsrFlagHighLevel_tile_id                   :: !Word16
    -- ^ Unique identifier of this tile in the tile set.
  , _msgSsrFlagHighLevel_chain_id                  :: !Word8
    -- ^ Chain and type of flag.
  , _msgSsrFlagHighLevel_use_gps_sat               :: !Word8
    -- ^ Use GPS satellites.
  , _msgSsrFlagHighLevel_use_gal_sat               :: !Word8
    -- ^ Use GAL satellites.
  , _msgSsrFlagHighLevel_use_bds_sat               :: !Word8
    -- ^ Use BDS satellites.
  , _msgSsrFlagHighLevel_reserved                  :: ![Word8]
    -- ^ Reserved
  , _msgSsrFlagHighLevel_use_tropo_grid_points     :: !Word8
    -- ^ Use tropo grid points.
  , _msgSsrFlagHighLevel_use_iono_grid_points      :: !Word8
    -- ^ Use iono grid points.
  , _msgSsrFlagHighLevel_use_iono_tile_sat_los     :: !Word8
    -- ^ Use iono tile satellite LoS.
  , _msgSsrFlagHighLevel_use_iono_grid_point_sat_los :: !Word8
    -- ^ Use iono grid point satellite LoS.
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrFlagHighLevel where
  get = do
    _msgSsrFlagHighLevel_obs_time <- get
    _msgSsrFlagHighLevel_corr_time <- get
    _msgSsrFlagHighLevel_ssr_sol_id <- getWord8
    _msgSsrFlagHighLevel_tile_set_id <- getWord16le
    _msgSsrFlagHighLevel_tile_id <- getWord16le
    _msgSsrFlagHighLevel_chain_id <- getWord8
    _msgSsrFlagHighLevel_use_gps_sat <- getWord8
    _msgSsrFlagHighLevel_use_gal_sat <- getWord8
    _msgSsrFlagHighLevel_use_bds_sat <- getWord8
    _msgSsrFlagHighLevel_reserved <- replicateM 6 getWord8
    _msgSsrFlagHighLevel_use_tropo_grid_points <- getWord8
    _msgSsrFlagHighLevel_use_iono_grid_points <- getWord8
    _msgSsrFlagHighLevel_use_iono_tile_sat_los <- getWord8
    _msgSsrFlagHighLevel_use_iono_grid_point_sat_los <- getWord8
    pure MsgSsrFlagHighLevel {..}

  put MsgSsrFlagHighLevel {..} = do
    put _msgSsrFlagHighLevel_obs_time
    put _msgSsrFlagHighLevel_corr_time
    putWord8 _msgSsrFlagHighLevel_ssr_sol_id
    putWord16le _msgSsrFlagHighLevel_tile_set_id
    putWord16le _msgSsrFlagHighLevel_tile_id
    putWord8 _msgSsrFlagHighLevel_chain_id
    putWord8 _msgSsrFlagHighLevel_use_gps_sat
    putWord8 _msgSsrFlagHighLevel_use_gal_sat
    putWord8 _msgSsrFlagHighLevel_use_bds_sat
    mapM_ putWord8 _msgSsrFlagHighLevel_reserved
    putWord8 _msgSsrFlagHighLevel_use_tropo_grid_points
    putWord8 _msgSsrFlagHighLevel_use_iono_grid_points
    putWord8 _msgSsrFlagHighLevel_use_iono_tile_sat_los
    putWord8 _msgSsrFlagHighLevel_use_iono_grid_point_sat_los

$(makeSBP 'msgSsrFlagHighLevel ''MsgSsrFlagHighLevel)
$(makeJSON "_msgSsrFlagHighLevel_" ''MsgSsrFlagHighLevel)
$(makeLenses ''MsgSsrFlagHighLevel)

msgSsrFlagSatellites :: Word16
msgSsrFlagSatellites = 0x0BBD

data MsgSsrFlagSatellites = MsgSsrFlagSatellites
  { _msgSsrFlagSatellites_obs_time    :: !GpsTimeSec
    -- ^ GNSS reference time of the observation used to generate the flag.
  , _msgSsrFlagSatellites_num_msgs    :: !Word8
    -- ^ Number of messages in the dataset
  , _msgSsrFlagSatellites_seq_num     :: !Word8
    -- ^ Position of this message in the dataset
  , _msgSsrFlagSatellites_ssr_sol_id  :: !Word8
    -- ^ SSR Solution ID.
  , _msgSsrFlagSatellites_chain_id    :: !Word8
    -- ^ Chain and type of flag.
  , _msgSsrFlagSatellites_const_id    :: !Word8
    -- ^ Constellation ID.
  , _msgSsrFlagSatellites_n_faulty_sats :: !Word8
    -- ^ Number of faulty satellites.
  , _msgSsrFlagSatellites_faulty_sats :: ![Word8]
    -- ^ List of faulty satellites.
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrFlagSatellites where
  get = do
    _msgSsrFlagSatellites_obs_time <- get
    _msgSsrFlagSatellites_num_msgs <- getWord8
    _msgSsrFlagSatellites_seq_num <- getWord8
    _msgSsrFlagSatellites_ssr_sol_id <- getWord8
    _msgSsrFlagSatellites_chain_id <- getWord8
    _msgSsrFlagSatellites_const_id <- getWord8
    _msgSsrFlagSatellites_n_faulty_sats <- getWord8
    _msgSsrFlagSatellites_faulty_sats <- whileM (not <$> isEmpty) getWord8
    pure MsgSsrFlagSatellites {..}

  put MsgSsrFlagSatellites {..} = do
    put _msgSsrFlagSatellites_obs_time
    putWord8 _msgSsrFlagSatellites_num_msgs
    putWord8 _msgSsrFlagSatellites_seq_num
    putWord8 _msgSsrFlagSatellites_ssr_sol_id
    putWord8 _msgSsrFlagSatellites_chain_id
    putWord8 _msgSsrFlagSatellites_const_id
    putWord8 _msgSsrFlagSatellites_n_faulty_sats
    mapM_ putWord8 _msgSsrFlagSatellites_faulty_sats

$(makeSBP 'msgSsrFlagSatellites ''MsgSsrFlagSatellites)
$(makeJSON "_msgSsrFlagSatellites_" ''MsgSsrFlagSatellites)
$(makeLenses ''MsgSsrFlagSatellites)

msgSsrFlagTropoGridPoints :: Word16
msgSsrFlagTropoGridPoints = 0x0BC3

data MsgSsrFlagTropoGridPoints = MsgSsrFlagTropoGridPoints
  { _msgSsrFlagTropoGridPoints_header        :: !IntegritySSRHeader
    -- ^ Header of an integrity message.
  , _msgSsrFlagTropoGridPoints_n_faulty_points :: !Word8
    -- ^ Number of faulty grid points.
  , _msgSsrFlagTropoGridPoints_faulty_points :: ![Word16]
    -- ^ List of faulty grid points.
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrFlagTropoGridPoints where
  get = do
    _msgSsrFlagTropoGridPoints_header <- get
    _msgSsrFlagTropoGridPoints_n_faulty_points <- getWord8
    _msgSsrFlagTropoGridPoints_faulty_points <- whileM (not <$> isEmpty) getWord16le
    pure MsgSsrFlagTropoGridPoints {..}

  put MsgSsrFlagTropoGridPoints {..} = do
    put _msgSsrFlagTropoGridPoints_header
    putWord8 _msgSsrFlagTropoGridPoints_n_faulty_points
    mapM_ putWord16le _msgSsrFlagTropoGridPoints_faulty_points

$(makeSBP 'msgSsrFlagTropoGridPoints ''MsgSsrFlagTropoGridPoints)
$(makeJSON "_msgSsrFlagTropoGridPoints_" ''MsgSsrFlagTropoGridPoints)
$(makeLenses ''MsgSsrFlagTropoGridPoints)

msgSsrFlagIonoGridPoints :: Word16
msgSsrFlagIonoGridPoints = 0x0BC7

data MsgSsrFlagIonoGridPoints = MsgSsrFlagIonoGridPoints
  { _msgSsrFlagIonoGridPoints_header        :: !IntegritySSRHeader
    -- ^ Header of an integrity message.
  , _msgSsrFlagIonoGridPoints_n_faulty_points :: !Word8
    -- ^ Number of faulty grid points.
  , _msgSsrFlagIonoGridPoints_faulty_points :: ![Word16]
    -- ^ List of faulty grid points.
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrFlagIonoGridPoints where
  get = do
    _msgSsrFlagIonoGridPoints_header <- get
    _msgSsrFlagIonoGridPoints_n_faulty_points <- getWord8
    _msgSsrFlagIonoGridPoints_faulty_points <- whileM (not <$> isEmpty) getWord16le
    pure MsgSsrFlagIonoGridPoints {..}

  put MsgSsrFlagIonoGridPoints {..} = do
    put _msgSsrFlagIonoGridPoints_header
    putWord8 _msgSsrFlagIonoGridPoints_n_faulty_points
    mapM_ putWord16le _msgSsrFlagIonoGridPoints_faulty_points

$(makeSBP 'msgSsrFlagIonoGridPoints ''MsgSsrFlagIonoGridPoints)
$(makeJSON "_msgSsrFlagIonoGridPoints_" ''MsgSsrFlagIonoGridPoints)
$(makeLenses ''MsgSsrFlagIonoGridPoints)

msgSsrFlagIonoTileSatLos :: Word16
msgSsrFlagIonoTileSatLos = 0x0BCD

data MsgSsrFlagIonoTileSatLos = MsgSsrFlagIonoTileSatLos
  { _msgSsrFlagIonoTileSatLos_header     :: !IntegritySSRHeader
    -- ^ Header of an integrity message.
  , _msgSsrFlagIonoTileSatLos_n_faulty_los :: !Word8
    -- ^ Number of faulty LOS.
  , _msgSsrFlagIonoTileSatLos_faulty_los :: ![SvId]
    -- ^ List of faulty LOS
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrFlagIonoTileSatLos where
  get = do
    _msgSsrFlagIonoTileSatLos_header <- get
    _msgSsrFlagIonoTileSatLos_n_faulty_los <- getWord8
    _msgSsrFlagIonoTileSatLos_faulty_los <- whileM (not <$> isEmpty) get
    pure MsgSsrFlagIonoTileSatLos {..}

  put MsgSsrFlagIonoTileSatLos {..} = do
    put _msgSsrFlagIonoTileSatLos_header
    putWord8 _msgSsrFlagIonoTileSatLos_n_faulty_los
    mapM_ put _msgSsrFlagIonoTileSatLos_faulty_los

$(makeSBP 'msgSsrFlagIonoTileSatLos ''MsgSsrFlagIonoTileSatLos)
$(makeJSON "_msgSsrFlagIonoTileSatLos_" ''MsgSsrFlagIonoTileSatLos)
$(makeLenses ''MsgSsrFlagIonoTileSatLos)

msgSsrFlagIonoGridPointSatLos :: Word16
msgSsrFlagIonoGridPointSatLos = 0x0BD1

data MsgSsrFlagIonoGridPointSatLos = MsgSsrFlagIonoGridPointSatLos
  { _msgSsrFlagIonoGridPointSatLos_header      :: !IntegritySSRHeader
    -- ^ Header of an integrity message.
  , _msgSsrFlagIonoGridPointSatLos_grid_point_id :: !Word16
    -- ^ Index of the grid point.
  , _msgSsrFlagIonoGridPointSatLos_n_faulty_los :: !Word8
    -- ^ Number of faulty LOS.
  , _msgSsrFlagIonoGridPointSatLos_faulty_los  :: ![SvId]
    -- ^ List of faulty LOS
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrFlagIonoGridPointSatLos where
  get = do
    _msgSsrFlagIonoGridPointSatLos_header <- get
    _msgSsrFlagIonoGridPointSatLos_grid_point_id <- getWord16le
    _msgSsrFlagIonoGridPointSatLos_n_faulty_los <- getWord8
    _msgSsrFlagIonoGridPointSatLos_faulty_los <- whileM (not <$> isEmpty) get
    pure MsgSsrFlagIonoGridPointSatLos {..}

  put MsgSsrFlagIonoGridPointSatLos {..} = do
    put _msgSsrFlagIonoGridPointSatLos_header
    putWord16le _msgSsrFlagIonoGridPointSatLos_grid_point_id
    putWord8 _msgSsrFlagIonoGridPointSatLos_n_faulty_los
    mapM_ put _msgSsrFlagIonoGridPointSatLos_faulty_los

$(makeSBP 'msgSsrFlagIonoGridPointSatLos ''MsgSsrFlagIonoGridPointSatLos)
$(makeJSON "_msgSsrFlagIonoGridPointSatLos_" ''MsgSsrFlagIonoGridPointSatLos)
$(makeLenses ''MsgSsrFlagIonoGridPointSatLos)
