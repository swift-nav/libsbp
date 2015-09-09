-- |
-- Module:      SwiftNav.SBP.FileIo
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- Messages for using device's onboard flash filesystem functionality. This
-- allows data to be stored persistently in the device's program flash with
-- wear-levelling using a simple filesystem interface. The file system
-- interface (CFS) defines an abstract API for reading directories and for
-- reading and writing files.  These are in the implementation-defined range
-- (0x0000-0x00FF), and intended for internal-use only. Note that some of these
-- messages share the same message type ID for both the host request and the
-- device response.

module SwiftNav.SBP.FileIo where

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

msgFileioReadReq :: Word16
msgFileioReadReq = 0x00A8

-- | SBP class for message MSG_FILEIO_READ_REQ (0x00A8).
--
-- The file read message reads a certain length (up to 255 bytes) from a given
-- offset into a file, and returns the data in a MSG_FILEIO_READ_RESP message
-- where the message length field indicates how many bytes were succesfully
-- read.The sequence number in the request will be returned in the response.
data MsgFileioReadReq = MsgFileioReadReq
  { msgFileioReadReqSequence   :: Word32
    -- ^ Read sequence number
  , msgFileioReadReqOffset     :: Word32
    -- ^ File offset
  , msgFileioReadReqChunkSize  :: Word8
    -- ^ Chunk size to read
  , msgFileioReadReqFilename   :: ByteString
    -- ^ Name of the file to read from
  } deriving ( Show, Read, Eq )

instance Binary MsgFileioReadReq where
  get = do
    msgFileioReadReqSequence <- getWord32le
    msgFileioReadReqOffset <- getWord32le
    msgFileioReadReqChunkSize <- getWord8
    msgFileioReadReqFilename <- liftM toStrict getRemainingLazyByteString
    return MsgFileioReadReq {..}

  put MsgFileioReadReq {..} = do
    putWord32le msgFileioReadReqSequence
    putWord32le msgFileioReadReqOffset
    putWord8 msgFileioReadReqChunkSize
    putByteString msgFileioReadReqFilename

msgFileioReadResp :: Word16
msgFileioReadResp = 0x00A3

-- | SBP class for message MSG_FILEIO_READ_RESP (0x00A3).
--
-- The file read message reads a certain length (up to 255 bytes) from a given
-- offset into a file, and returns the data in a message where the message
-- length field indicates how many bytes were succesfully read. The sequence
-- number in the response is preserved from the request.
data MsgFileioReadResp = MsgFileioReadResp
  { msgFileioReadRespSequence :: Word32
    -- ^ Read sequence number
  , msgFileioReadRespContents :: [Word8]
    -- ^ Contents of read file
  } deriving ( Show, Read, Eq )

instance Binary MsgFileioReadResp where
  get = do
    msgFileioReadRespSequence <- getWord32le
    msgFileioReadRespContents <- whileM (liftM not isEmpty) getWord8
    return MsgFileioReadResp {..}

  put MsgFileioReadResp {..} = do
    putWord32le msgFileioReadRespSequence
    mapM_ putWord8 msgFileioReadRespContents

msgFileioReadDirReq :: Word16
msgFileioReadDirReq = 0x00A9

-- | SBP class for message MSG_FILEIO_READ_DIR_REQ (0x00A9).
--
-- The read directory message lists the files in a directory on the device's
-- onboard flash file system.  The offset parameter can be used to skip the
-- first n elements of the file list. Returns a MSG_FILEIO_READ_DIR_RESP
-- message containing the directory listings as a NULL delimited list. The
-- listing is chunked over multiple SBP packets. The sequence number in the
-- request will be returned in the response.
data MsgFileioReadDirReq = MsgFileioReadDirReq
  { msgFileioReadDirReqSequence :: Word32
    -- ^ Read sequence number
  , msgFileioReadDirReqOffset   :: Word32
    -- ^ The offset to skip the first n elements of the file list
  , msgFileioReadDirReqDirname  :: ByteString
    -- ^ Name of the directory to list
  } deriving ( Show, Read, Eq )

instance Binary MsgFileioReadDirReq where
  get = do
    msgFileioReadDirReqSequence <- getWord32le
    msgFileioReadDirReqOffset <- getWord32le
    msgFileioReadDirReqDirname <- liftM toStrict getRemainingLazyByteString
    return MsgFileioReadDirReq {..}

  put MsgFileioReadDirReq {..} = do
    putWord32le msgFileioReadDirReqSequence
    putWord32le msgFileioReadDirReqOffset
    putByteString msgFileioReadDirReqDirname

msgFileioReadDirResp :: Word16
msgFileioReadDirResp = 0x00AA

-- | SBP class for message MSG_FILEIO_READ_DIR_RESP (0x00AA).
--
-- The read directory message lists the files in a directory on the device's
-- onboard flash file system. Message contains the directory listings as a NULL
-- delimited list. The listing is chunked over multiple SBP packets and the end
-- of the list is identified by an entry containing just the character 0xFF.
-- The sequence number in the response is preserved from the request.
data MsgFileioReadDirResp = MsgFileioReadDirResp
  { msgFileioReadDirRespSequence :: Word32
    -- ^ Read sequence number
  , msgFileioReadDirRespContents :: [Word8]
    -- ^ Contents of read directory
  } deriving ( Show, Read, Eq )

instance Binary MsgFileioReadDirResp where
  get = do
    msgFileioReadDirRespSequence <- getWord32le
    msgFileioReadDirRespContents <- whileM (liftM not isEmpty) getWord8
    return MsgFileioReadDirResp {..}

  put MsgFileioReadDirResp {..} = do
    putWord32le msgFileioReadDirRespSequence
    mapM_ putWord8 msgFileioReadDirRespContents

msgFileioRemove :: Word16
msgFileioRemove = 0x00AC

-- | SBP class for message MSG_FILEIO_REMOVE (0x00AC).
--
-- The file remove message deletes a file from the file system.
data MsgFileioRemove = MsgFileioRemove
  { msgFileioRemoveFilename :: ByteString
    -- ^ Name of the file to delete
  } deriving ( Show, Read, Eq )

instance Binary MsgFileioRemove where
  get = do
    msgFileioRemoveFilename <- liftM toStrict getRemainingLazyByteString
    return MsgFileioRemove {..}

  put MsgFileioRemove {..} = do
    putByteString msgFileioRemoveFilename

msgFileioWriteReq :: Word16
msgFileioWriteReq = 0x00AD

-- | SBP class for message MSG_FILEIO_WRITE_REQ (0x00AD).
--
-- The file write message writes a certain length (up to 255 bytes) of data to
-- a file at a given offset. Returns a copy of the original
-- MSG_FILEIO_WRITE_RESP message to check integrity of the write. The sequence
-- number in the request will be returned in the response.
data MsgFileioWriteReq = MsgFileioWriteReq
  { msgFileioWriteReqSequence :: Word32
    -- ^ Write sequence number
  , msgFileioWriteReqOffset   :: Word32
    -- ^ Offset into the file at which to start writing in bytes
  , msgFileioWriteReqFilename :: ByteString
    -- ^ Name of the file to write to
  , msgFileioWriteReqData     :: [Word8]
    -- ^ Variable-length array of data to write
  } deriving ( Show, Read, Eq )

instance Binary MsgFileioWriteReq where
  get = do
    msgFileioWriteReqSequence <- getWord32le
    msgFileioWriteReqOffset <- getWord32le
    msgFileioWriteReqFilename <- liftM toStrict getRemainingLazyByteString
    msgFileioWriteReqData <- whileM (liftM not isEmpty) getWord8
    return MsgFileioWriteReq {..}

  put MsgFileioWriteReq {..} = do
    putWord32le msgFileioWriteReqSequence
    putWord32le msgFileioWriteReqOffset
    putByteString msgFileioWriteReqFilename
    mapM_ putWord8 msgFileioWriteReqData

msgFileioWriteResp :: Word16
msgFileioWriteResp = 0x00AB

-- | SBP class for message MSG_FILEIO_WRITE_RESP (0x00AB).
--
-- The file write message writes a certain length (up to 255 bytes) of data to
-- a file at a given offset. The message is a copy of the original
-- MSG_FILEIO_WRITE_REQ message to check integrity of the write. The sequence
-- number in the response is preserved from the request.
data MsgFileioWriteResp = MsgFileioWriteResp
  { msgFileioWriteRespSequence :: Word32
    -- ^ Write sequence number
  } deriving ( Show, Read, Eq )

instance Binary MsgFileioWriteResp where
  get = do
    msgFileioWriteRespSequence <- getWord32le
    return MsgFileioWriteResp {..}

  put MsgFileioWriteResp {..} = do
    putWord32le msgFileioWriteRespSequence
