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
  { _msgSsrFlagTropoGridPoints_obs_time      :: !GpsTimeSec
    -- ^ GNSS reference time of the observation used to generate the flag.
  , _msgSsrFlagTropoGridPoints_num_msgs      :: !Word8
    -- ^ Number of messages in the dataset
  , _msgSsrFlagTropoGridPoints_seq_num       :: !Word8
    -- ^ Position of this message in the dataset
  , _msgSsrFlagTropoGridPoints_ssr_sol_id    :: !Word8
    -- ^ SSR Solution ID.
  , _msgSsrFlagTropoGridPoints_tile_set_id   :: !Word16
    -- ^ Unique identifier of the set this tile belongs to.
  , _msgSsrFlagTropoGridPoints_tile_id       :: !Word16
    -- ^ Unique identifier of this tile in the tile set.
  , _msgSsrFlagTropoGridPoints_chain_id      :: !Word8
    -- ^ Chain and type of flag.
  , _msgSsrFlagTropoGridPoints_n_faulty_points :: !Word8
    -- ^ Number of faulty grid points.
  , _msgSsrFlagTropoGridPoints_faulty_points :: ![Word16]
    -- ^ List of faulty grid points.
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrFlagTropoGridPoints where
  get = do
    _msgSsrFlagTropoGridPoints_obs_time <- get
    _msgSsrFlagTropoGridPoints_num_msgs <- getWord8
    _msgSsrFlagTropoGridPoints_seq_num <- getWord8
    _msgSsrFlagTropoGridPoints_ssr_sol_id <- getWord8
    _msgSsrFlagTropoGridPoints_tile_set_id <- getWord16le
    _msgSsrFlagTropoGridPoints_tile_id <- getWord16le
    _msgSsrFlagTropoGridPoints_chain_id <- getWord8
    _msgSsrFlagTropoGridPoints_n_faulty_points <- getWord8
    _msgSsrFlagTropoGridPoints_faulty_points <- whileM (not <$> isEmpty) getWord16le
    pure MsgSsrFlagTropoGridPoints {..}

  put MsgSsrFlagTropoGridPoints {..} = do
    put _msgSsrFlagTropoGridPoints_obs_time
    putWord8 _msgSsrFlagTropoGridPoints_num_msgs
    putWord8 _msgSsrFlagTropoGridPoints_seq_num
    putWord8 _msgSsrFlagTropoGridPoints_ssr_sol_id
    putWord16le _msgSsrFlagTropoGridPoints_tile_set_id
    putWord16le _msgSsrFlagTropoGridPoints_tile_id
    putWord8 _msgSsrFlagTropoGridPoints_chain_id
    putWord8 _msgSsrFlagTropoGridPoints_n_faulty_points
    mapM_ putWord16le _msgSsrFlagTropoGridPoints_faulty_points

$(makeSBP 'msgSsrFlagTropoGridPoints ''MsgSsrFlagTropoGridPoints)
$(makeJSON "_msgSsrFlagTropoGridPoints_" ''MsgSsrFlagTropoGridPoints)
$(makeLenses ''MsgSsrFlagTropoGridPoints)

msgSsrFlagIonoGridPoints :: Word16
msgSsrFlagIonoGridPoints = 0x0BC7

data MsgSsrFlagIonoGridPoints = MsgSsrFlagIonoGridPoints
  { _msgSsrFlagIonoGridPoints_obs_time      :: !GpsTimeSec
    -- ^ GNSS reference time of the observation used to generate the flag.
  , _msgSsrFlagIonoGridPoints_num_msgs      :: !Word8
    -- ^ Number of messages in the dataset
  , _msgSsrFlagIonoGridPoints_seq_num       :: !Word8
    -- ^ Position of this message in the dataset
  , _msgSsrFlagIonoGridPoints_ssr_sol_id    :: !Word8
    -- ^ SSR Solution ID.
  , _msgSsrFlagIonoGridPoints_tile_set_id   :: !Word16
    -- ^ Unique identifier of the set this tile belongs to.
  , _msgSsrFlagIonoGridPoints_tile_id       :: !Word16
    -- ^ Unique identifier of this tile in the tile set.
  , _msgSsrFlagIonoGridPoints_chain_id      :: !Word8
    -- ^ Chain and type of flag.
  , _msgSsrFlagIonoGridPoints_n_faulty_points :: !Word8
    -- ^ Number of faulty grid points.
  , _msgSsrFlagIonoGridPoints_faulty_points :: ![Word16]
    -- ^ List of faulty grid points.
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrFlagIonoGridPoints where
  get = do
    _msgSsrFlagIonoGridPoints_obs_time <- get
    _msgSsrFlagIonoGridPoints_num_msgs <- getWord8
    _msgSsrFlagIonoGridPoints_seq_num <- getWord8
    _msgSsrFlagIonoGridPoints_ssr_sol_id <- getWord8
    _msgSsrFlagIonoGridPoints_tile_set_id <- getWord16le
    _msgSsrFlagIonoGridPoints_tile_id <- getWord16le
    _msgSsrFlagIonoGridPoints_chain_id <- getWord8
    _msgSsrFlagIonoGridPoints_n_faulty_points <- getWord8
    _msgSsrFlagIonoGridPoints_faulty_points <- whileM (not <$> isEmpty) getWord16le
    pure MsgSsrFlagIonoGridPoints {..}

  put MsgSsrFlagIonoGridPoints {..} = do
    put _msgSsrFlagIonoGridPoints_obs_time
    putWord8 _msgSsrFlagIonoGridPoints_num_msgs
    putWord8 _msgSsrFlagIonoGridPoints_seq_num
    putWord8 _msgSsrFlagIonoGridPoints_ssr_sol_id
    putWord16le _msgSsrFlagIonoGridPoints_tile_set_id
    putWord16le _msgSsrFlagIonoGridPoints_tile_id
    putWord8 _msgSsrFlagIonoGridPoints_chain_id
    putWord8 _msgSsrFlagIonoGridPoints_n_faulty_points
    mapM_ putWord16le _msgSsrFlagIonoGridPoints_faulty_points

$(makeSBP 'msgSsrFlagIonoGridPoints ''MsgSsrFlagIonoGridPoints)
$(makeJSON "_msgSsrFlagIonoGridPoints_" ''MsgSsrFlagIonoGridPoints)
$(makeLenses ''MsgSsrFlagIonoGridPoints)

msgSsrFlagIonoTileSatLos :: Word16
msgSsrFlagIonoTileSatLos = 0x0BCD

data MsgSsrFlagIonoTileSatLos = MsgSsrFlagIonoTileSatLos
  { _msgSsrFlagIonoTileSatLos_obs_time   :: !GpsTimeSec
    -- ^ GNSS reference time of the observation used to generate the flag.
  , _msgSsrFlagIonoTileSatLos_num_msgs   :: !Word8
    -- ^ Number of messages in the dataset
  , _msgSsrFlagIonoTileSatLos_seq_num    :: !Word8
    -- ^ Position of this message in the dataset
  , _msgSsrFlagIonoTileSatLos_ssr_sol_id :: !Word8
    -- ^ SSR Solution ID.
  , _msgSsrFlagIonoTileSatLos_tile_set_id :: !Word16
    -- ^ Unique identifier of the set this tile belongs to.
  , _msgSsrFlagIonoTileSatLos_tile_id    :: !Word16
    -- ^ Unique identifier of this tile in the tile set.
  , _msgSsrFlagIonoTileSatLos_chain_id   :: !Word8
    -- ^ Chain and type of flag.
  , _msgSsrFlagIonoTileSatLos_n_faulty_los :: !Word8
    -- ^ Number of faulty LOS.
  , _msgSsrFlagIonoTileSatLos_faulty_los :: ![SvId]
    -- ^ List of faulty LOS
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrFlagIonoTileSatLos where
  get = do
    _msgSsrFlagIonoTileSatLos_obs_time <- get
    _msgSsrFlagIonoTileSatLos_num_msgs <- getWord8
    _msgSsrFlagIonoTileSatLos_seq_num <- getWord8
    _msgSsrFlagIonoTileSatLos_ssr_sol_id <- getWord8
    _msgSsrFlagIonoTileSatLos_tile_set_id <- getWord16le
    _msgSsrFlagIonoTileSatLos_tile_id <- getWord16le
    _msgSsrFlagIonoTileSatLos_chain_id <- getWord8
    _msgSsrFlagIonoTileSatLos_n_faulty_los <- getWord8
    _msgSsrFlagIonoTileSatLos_faulty_los <- whileM (not <$> isEmpty) get
    pure MsgSsrFlagIonoTileSatLos {..}

  put MsgSsrFlagIonoTileSatLos {..} = do
    put _msgSsrFlagIonoTileSatLos_obs_time
    putWord8 _msgSsrFlagIonoTileSatLos_num_msgs
    putWord8 _msgSsrFlagIonoTileSatLos_seq_num
    putWord8 _msgSsrFlagIonoTileSatLos_ssr_sol_id
    putWord16le _msgSsrFlagIonoTileSatLos_tile_set_id
    putWord16le _msgSsrFlagIonoTileSatLos_tile_id
    putWord8 _msgSsrFlagIonoTileSatLos_chain_id
    putWord8 _msgSsrFlagIonoTileSatLos_n_faulty_los
    mapM_ put _msgSsrFlagIonoTileSatLos_faulty_los

$(makeSBP 'msgSsrFlagIonoTileSatLos ''MsgSsrFlagIonoTileSatLos)
$(makeJSON "_msgSsrFlagIonoTileSatLos_" ''MsgSsrFlagIonoTileSatLos)
$(makeLenses ''MsgSsrFlagIonoTileSatLos)

msgSsrFlagIonoGridPointSatLos :: Word16
msgSsrFlagIonoGridPointSatLos = 0x0BD1

data MsgSsrFlagIonoGridPointSatLos = MsgSsrFlagIonoGridPointSatLos
  { _msgSsrFlagIonoGridPointSatLos_obs_time    :: !GpsTimeSec
    -- ^ GNSS reference time of the observation used to generate the flag.
  , _msgSsrFlagIonoGridPointSatLos_num_msgs    :: !Word8
    -- ^ Number of messages in the dataset
  , _msgSsrFlagIonoGridPointSatLos_seq_num     :: !Word8
    -- ^ Position of this message in the dataset
  , _msgSsrFlagIonoGridPointSatLos_ssr_sol_id  :: !Word8
    -- ^ SSR Solution ID.
  , _msgSsrFlagIonoGridPointSatLos_tile_set_id :: !Word16
    -- ^ Unique identifier of the set this tile belongs to.
  , _msgSsrFlagIonoGridPointSatLos_tile_id     :: !Word16
    -- ^ Unique identifier of this tile in the tile set.
  , _msgSsrFlagIonoGridPointSatLos_chain_id    :: !Word8
    -- ^ Chain and type of flag.
  , _msgSsrFlagIonoGridPointSatLos_grid_point_id :: !Word16
    -- ^ Index of the grid point.
  , _msgSsrFlagIonoGridPointSatLos_n_faulty_los :: !Word8
    -- ^ Number of faulty LOS.
  , _msgSsrFlagIonoGridPointSatLos_faulty_los  :: ![SvId]
    -- ^ List of faulty LOS
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrFlagIonoGridPointSatLos where
  get = do
    _msgSsrFlagIonoGridPointSatLos_obs_time <- get
    _msgSsrFlagIonoGridPointSatLos_num_msgs <- getWord8
    _msgSsrFlagIonoGridPointSatLos_seq_num <- getWord8
    _msgSsrFlagIonoGridPointSatLos_ssr_sol_id <- getWord8
    _msgSsrFlagIonoGridPointSatLos_tile_set_id <- getWord16le
    _msgSsrFlagIonoGridPointSatLos_tile_id <- getWord16le
    _msgSsrFlagIonoGridPointSatLos_chain_id <- getWord8
    _msgSsrFlagIonoGridPointSatLos_grid_point_id <- getWord16le
    _msgSsrFlagIonoGridPointSatLos_n_faulty_los <- getWord8
    _msgSsrFlagIonoGridPointSatLos_faulty_los <- whileM (not <$> isEmpty) get
    pure MsgSsrFlagIonoGridPointSatLos {..}

  put MsgSsrFlagIonoGridPointSatLos {..} = do
    put _msgSsrFlagIonoGridPointSatLos_obs_time
    putWord8 _msgSsrFlagIonoGridPointSatLos_num_msgs
    putWord8 _msgSsrFlagIonoGridPointSatLos_seq_num
    putWord8 _msgSsrFlagIonoGridPointSatLos_ssr_sol_id
    putWord16le _msgSsrFlagIonoGridPointSatLos_tile_set_id
    putWord16le _msgSsrFlagIonoGridPointSatLos_tile_id
    putWord8 _msgSsrFlagIonoGridPointSatLos_chain_id
    putWord16le _msgSsrFlagIonoGridPointSatLos_grid_point_id
    putWord8 _msgSsrFlagIonoGridPointSatLos_n_faulty_los
    mapM_ put _msgSsrFlagIonoGridPointSatLos_faulty_los

$(makeSBP 'msgSsrFlagIonoGridPointSatLos ''MsgSsrFlagIonoGridPointSatLos)
$(makeJSON "_msgSsrFlagIonoGridPointSatLos_" ''MsgSsrFlagIonoGridPointSatLos)
$(makeLenses ''MsgSsrFlagIonoGridPointSatLos)
