{-# OPTIONS_GHC -fno-warn-unused-imports #-}
{-# LANGUAGE NoImplicitPrelude           #-}
{-# LANGUAGE TemplateHaskell             #-}
{-# LANGUAGE RecordWildCards             #-}

-- |
-- Module:      SwiftNav.SBP.FileIo
-- Copyright:   Copyright (C) 2015-2021 Swift Navigation, Inc.
-- License:     MIT
-- Contact:     https://support.swiftnav.com
-- Stability:   experimental
-- Portability: portable
--
-- \< Messages for using device's onboard flash filesystem functionality. This
-- allows data to be stored persistently in the device's program flash with
-- wear-levelling using a simple filesystem interface. The file system
-- interface (CFS) defines an abstract API for reading directories and for
-- reading and writing files.
--
-- Note that some of these messages share the same message type ID for both
-- the host request and the device response. \>

module SwiftNav.SBP.FileIo
  ( module SwiftNav.SBP.FileIo
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


msgFileioReadReq :: Word16
msgFileioReadReq = 0x00A8

-- | SBP class for message MSG_FILEIO_READ_REQ (0x00A8).
--
-- The file read message reads a certain length (up to 255 bytes) from a given
-- offset into a file, and returns the data in a MSG_FILEIO_READ_RESP message
-- where the message length field indicates how many bytes were successfully
-- read. The sequence number in the request will be returned in the response.
-- If the message is invalid, a followup MSG_PRINT message will print "Invalid
-- fileio read message". A device will only respond to this message when it is
-- received from sender ID 0x42.
data MsgFileioReadReq = MsgFileioReadReq
  { _msgFileioReadReq_sequence :: !Word32
    -- ^ Read sequence number
  , _msgFileioReadReq_offset   :: !Word32
    -- ^ File offset
  , _msgFileioReadReq_chunk_size :: !Word8
    -- ^ Chunk size to read
  , _msgFileioReadReq_filename :: !Text
    -- ^ Name of the file to read from
  } deriving ( Show, Read, Eq )

instance Binary MsgFileioReadReq where
  get = do
    _msgFileioReadReq_sequence <- getWord32le
    _msgFileioReadReq_offset <- getWord32le
    _msgFileioReadReq_chunk_size <- getWord8
    _msgFileioReadReq_filename <- decodeUtf8 . toStrict <$> getRemainingLazyByteString
    pure MsgFileioReadReq {..}

  put MsgFileioReadReq {..} = do
    putWord32le _msgFileioReadReq_sequence
    putWord32le _msgFileioReadReq_offset
    putWord8 _msgFileioReadReq_chunk_size
    putByteString $ encodeUtf8 _msgFileioReadReq_filename

$(makeSBP 'msgFileioReadReq ''MsgFileioReadReq)
$(makeJSON "_msgFileioReadReq_" ''MsgFileioReadReq)
$(makeLenses ''MsgFileioReadReq)

msgFileioReadResp :: Word16
msgFileioReadResp = 0x00A3

-- | SBP class for message MSG_FILEIO_READ_RESP (0x00A3).
--
-- The file read message reads a certain length (up to 255 bytes) from a given
-- offset into a file, and returns the data in a message where the message
-- length field indicates how many bytes were successfully read. The sequence
-- number in the response is preserved from the request.
data MsgFileioReadResp = MsgFileioReadResp
  { _msgFileioReadResp_sequence :: !Word32
    -- ^ Read sequence number
  , _msgFileioReadResp_contents :: ![Word8]
    -- ^ Contents of read file
  } deriving ( Show, Read, Eq )

instance Binary MsgFileioReadResp where
  get = do
    _msgFileioReadResp_sequence <- getWord32le
    _msgFileioReadResp_contents <- whileM (not <$> isEmpty) getWord8
    pure MsgFileioReadResp {..}

  put MsgFileioReadResp {..} = do
    putWord32le _msgFileioReadResp_sequence
    mapM_ putWord8 _msgFileioReadResp_contents

$(makeSBP 'msgFileioReadResp ''MsgFileioReadResp)
$(makeJSON "_msgFileioReadResp_" ''MsgFileioReadResp)
$(makeLenses ''MsgFileioReadResp)

msgFileioReadDirReq :: Word16
msgFileioReadDirReq = 0x00A9

-- | SBP class for message MSG_FILEIO_READ_DIR_REQ (0x00A9).
--
-- The read directory message lists the files in a directory on the device's
-- onboard flash file system.  The offset parameter can be used to skip the
-- first n elements of the file list. Returns a MSG_FILEIO_READ_DIR_RESP
-- message containing the directory listings as a NULL delimited list. The
-- listing is chunked over multiple SBP packets. The sequence number in the
-- request will be returned in the response.  If message is invalid, a
-- followup MSG_PRINT message will print "Invalid fileio read message". A
-- device will only respond to this message when it is received from sender ID
-- 0x42.
data MsgFileioReadDirReq = MsgFileioReadDirReq
  { _msgFileioReadDirReq_sequence :: !Word32
    -- ^ Read sequence number
  , _msgFileioReadDirReq_offset :: !Word32
    -- ^ The offset to skip the first n elements of the file list
  , _msgFileioReadDirReq_dirname :: !Text
    -- ^ Name of the directory to list
  } deriving ( Show, Read, Eq )

instance Binary MsgFileioReadDirReq where
  get = do
    _msgFileioReadDirReq_sequence <- getWord32le
    _msgFileioReadDirReq_offset <- getWord32le
    _msgFileioReadDirReq_dirname <- decodeUtf8 . toStrict <$> getRemainingLazyByteString
    pure MsgFileioReadDirReq {..}

  put MsgFileioReadDirReq {..} = do
    putWord32le _msgFileioReadDirReq_sequence
    putWord32le _msgFileioReadDirReq_offset
    putByteString $ encodeUtf8 _msgFileioReadDirReq_dirname

$(makeSBP 'msgFileioReadDirReq ''MsgFileioReadDirReq)
$(makeJSON "_msgFileioReadDirReq_" ''MsgFileioReadDirReq)
$(makeLenses ''MsgFileioReadDirReq)

msgFileioReadDirResp :: Word16
msgFileioReadDirResp = 0x00AA

-- | SBP class for message MSG_FILEIO_READ_DIR_RESP (0x00AA).
--
-- The read directory message lists the files in a directory on the device's
-- onboard flash file system. Message contains the directory listings as a
-- NULL delimited list. The listing is chunked over multiple SBP packets and
-- the end of the list is identified by an packet with no entries. The
-- sequence number in the response is preserved from the request.
data MsgFileioReadDirResp = MsgFileioReadDirResp
  { _msgFileioReadDirResp_sequence :: !Word32
    -- ^ Read sequence number
  , _msgFileioReadDirResp_contents :: !Text
    -- ^ Contents of read directory
  } deriving ( Show, Read, Eq )

instance Binary MsgFileioReadDirResp where
  get = do
    _msgFileioReadDirResp_sequence <- getWord32le
    _msgFileioReadDirResp_contents <- decodeUtf8 . toStrict <$> getRemainingLazyByteString
    pure MsgFileioReadDirResp {..}

  put MsgFileioReadDirResp {..} = do
    putWord32le _msgFileioReadDirResp_sequence
    putByteString $ encodeUtf8 _msgFileioReadDirResp_contents

$(makeSBP 'msgFileioReadDirResp ''MsgFileioReadDirResp)
$(makeJSON "_msgFileioReadDirResp_" ''MsgFileioReadDirResp)
$(makeLenses ''MsgFileioReadDirResp)

msgFileioRemove :: Word16
msgFileioRemove = 0x00AC

-- | SBP class for message MSG_FILEIO_REMOVE (0x00AC).
--
-- The file remove message deletes a file from the file system. If the message
-- is invalid, a followup MSG_PRINT message will print "Invalid fileio remove
-- message". A device will only process this message when it is received from
-- sender ID 0x42.
data MsgFileioRemove = MsgFileioRemove
  { _msgFileioRemove_filename :: !Text
    -- ^ Name of the file to delete
  } deriving ( Show, Read, Eq )

instance Binary MsgFileioRemove where
  get = do
    _msgFileioRemove_filename <- decodeUtf8 . toStrict <$> getRemainingLazyByteString
    pure MsgFileioRemove {..}

  put MsgFileioRemove {..} = do
    putByteString $ encodeUtf8 _msgFileioRemove_filename

$(makeSBP 'msgFileioRemove ''MsgFileioRemove)
$(makeJSON "_msgFileioRemove_" ''MsgFileioRemove)
$(makeLenses ''MsgFileioRemove)

msgFileioWriteReq :: Word16
msgFileioWriteReq = 0x00AD

-- | SBP class for message MSG_FILEIO_WRITE_REQ (0x00AD).
--
-- The file write message writes a certain length (up to 255 bytes) of data to
-- a file at a given offset. Returns a copy of the original
-- MSG_FILEIO_WRITE_RESP message to check integrity of the write. The sequence
-- number in the request will be returned in the response. If message is
-- invalid, a followup MSG_PRINT message will print "Invalid fileio write
-- message". A device will only process this message when it is received from
-- sender ID 0x42.
data MsgFileioWriteReq = MsgFileioWriteReq
  { _msgFileioWriteReq_sequence :: !Word32
    -- ^ Write sequence number
  , _msgFileioWriteReq_offset :: !Word32
    -- ^ Offset into the file at which to start writing in bytes
  , _msgFileioWriteReq_filename :: !Text
    -- ^ Name of the file to write to
  , _msgFileioWriteReq_data   :: ![Word8]
    -- ^ Variable-length array of data to write
  } deriving ( Show, Read, Eq )

instance Binary MsgFileioWriteReq where
  get = do
    _msgFileioWriteReq_sequence <- getWord32le
    _msgFileioWriteReq_offset <- getWord32le
    _msgFileioWriteReq_filename <- decodeUtf8 . toStrict <$> getRemainingLazyByteString
    _msgFileioWriteReq_data <- whileM (not <$> isEmpty) getWord8
    pure MsgFileioWriteReq {..}

  put MsgFileioWriteReq {..} = do
    putWord32le _msgFileioWriteReq_sequence
    putWord32le _msgFileioWriteReq_offset
    putByteString $ encodeUtf8 _msgFileioWriteReq_filename
    mapM_ putWord8 _msgFileioWriteReq_data

$(makeSBP 'msgFileioWriteReq ''MsgFileioWriteReq)
$(makeJSON "_msgFileioWriteReq_" ''MsgFileioWriteReq)
$(makeLenses ''MsgFileioWriteReq)

msgFileioWriteResp :: Word16
msgFileioWriteResp = 0x00AB

-- | SBP class for message MSG_FILEIO_WRITE_RESP (0x00AB).
--
-- The file write message writes a certain length (up to 255 bytes) of data to
-- a file at a given offset. The message is a copy of the original
-- MSG_FILEIO_WRITE_REQ message to check integrity of the write. The sequence
-- number in the response is preserved from the request.
data MsgFileioWriteResp = MsgFileioWriteResp
  { _msgFileioWriteResp_sequence :: !Word32
    -- ^ Write sequence number
  } deriving ( Show, Read, Eq )

instance Binary MsgFileioWriteResp where
  get = do
    _msgFileioWriteResp_sequence <- getWord32le
    pure MsgFileioWriteResp {..}

  put MsgFileioWriteResp {..} = do
    putWord32le _msgFileioWriteResp_sequence

$(makeSBP 'msgFileioWriteResp ''MsgFileioWriteResp)
$(makeJSON "_msgFileioWriteResp_" ''MsgFileioWriteResp)
$(makeLenses ''MsgFileioWriteResp)

msgFileioConfigReq :: Word16
msgFileioConfigReq = 0x1001

-- | SBP class for message MSG_FILEIO_CONFIG_REQ (0x1001).
--
-- Requests advice on the optimal configuration for a FileIO transfer.  Newer
-- version of FileIO can support greater throughput by supporting a large
-- window of FileIO data that can be in-flight during read or write
-- operations.
data MsgFileioConfigReq = MsgFileioConfigReq
  { _msgFileioConfigReq_sequence :: !Word32
    -- ^ Advice sequence number
  } deriving ( Show, Read, Eq )

instance Binary MsgFileioConfigReq where
  get = do
    _msgFileioConfigReq_sequence <- getWord32le
    pure MsgFileioConfigReq {..}

  put MsgFileioConfigReq {..} = do
    putWord32le _msgFileioConfigReq_sequence

$(makeSBP 'msgFileioConfigReq ''MsgFileioConfigReq)
$(makeJSON "_msgFileioConfigReq_" ''MsgFileioConfigReq)
$(makeLenses ''MsgFileioConfigReq)

msgFileioConfigResp :: Word16
msgFileioConfigResp = 0x1002

-- | SBP class for message MSG_FILEIO_CONFIG_RESP (0x1002).
--
-- The advice on the optimal configuration for a FileIO transfer.  Newer
-- version of FileIO can support greater throughput by supporting a large
-- window of FileIO data that can be in-flight during read or write
-- operations.
data MsgFileioConfigResp = MsgFileioConfigResp
  { _msgFileioConfigResp_sequence     :: !Word32
    -- ^ Advice sequence number
  , _msgFileioConfigResp_window_size  :: !Word32
    -- ^ The number of SBP packets in the data in-flight window
  , _msgFileioConfigResp_batch_size   :: !Word32
    -- ^ The number of SBP packets sent in one PDU
  , _msgFileioConfigResp_fileio_version :: !Word32
    -- ^ The version of FileIO that is supported
  } deriving ( Show, Read, Eq )

instance Binary MsgFileioConfigResp where
  get = do
    _msgFileioConfigResp_sequence <- getWord32le
    _msgFileioConfigResp_window_size <- getWord32le
    _msgFileioConfigResp_batch_size <- getWord32le
    _msgFileioConfigResp_fileio_version <- getWord32le
    pure MsgFileioConfigResp {..}

  put MsgFileioConfigResp {..} = do
    putWord32le _msgFileioConfigResp_sequence
    putWord32le _msgFileioConfigResp_window_size
    putWord32le _msgFileioConfigResp_batch_size
    putWord32le _msgFileioConfigResp_fileio_version

$(makeSBP 'msgFileioConfigResp ''MsgFileioConfigResp)
$(makeJSON "_msgFileioConfigResp_" ''MsgFileioConfigResp)
$(makeLenses ''MsgFileioConfigResp)

