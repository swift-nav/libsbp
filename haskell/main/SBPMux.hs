-- |
-- Module:      SBPMux
-- Copyright:   Copyright (C) 2017 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Leith Bade <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- SBP mux tool - reads SBP binary two named pipes and outputs the interleaved
-- messages to stdout
-- Based on the example at https://geekingfrog.com/blog/post/conduit-parallel-sources

import           BasicPrelude
import           Control.Concurrent.Async
import           Control.Concurrent.STM
import           Control.Concurrent.STM.TBMQueue
import           Control.Monad.Trans.Resource
import           Data.Aeson
import           Data.Aeson.Encode
import           Data.ByteString.Builder
import qualified Data.ByteString.Lazy              as BL
import           Data.Conduit
import           Data.Conduit.Binary
import           Data.Conduit.Serialization.Binary
import           SwiftNav.SBP
import           System.IO

-- | Encode a SBPMsg to a line of JSON.
encodeLine :: SBPMsg -> ByteString
encodeLine v = BL.toStrict $ toLazyByteString $ encodeToBuilder (toJSON v) <> "\n"

-- Read a queue into a conduit
sourceQueue :: MonadIO m => TBMQueue o -> ConduitM i o m ()
sourceQueue queue = loop
  where
    loop = do
        mbItem <- liftIO $ atomically (readTBMQueue queue)
        case mbItem of
            Nothing -> pure ()  -- queue closed
            Just item -> yield item *> loop

-- Write a conduit into a queue
sinkQueue :: MonadIO m => TBMQueue i -> ConduitM i o m ()
sinkQueue queue = loop
  where
    loop = do
        mbItem <- await
        case mbItem of
            Nothing -> pure ()  -- no more items to come
            Just item -> do
                liftIO $ atomically (writeTBMQueue queue item)
                loop

-- Given a list of conduits, collapse all of them into one conduit
parSources :: (MonadIO m, MonadResource m) => [ConduitM () o (ResourceT IO) ()] -> Int -> ConduitM () o m ()
parSources sources queueLength = bracketP initialize cleanup finalSource
  where
    initialize = do
        -- create the queue where all sources will put their items
        queue <- newTBMQueueIO queueLength

        -- In a separate thread, run concurrently all conduits
        a <- async $ do
            mapConcurrently_ (\source -> runConduitRes (source .| sinkQueue queue)) sources
            -- once all conduits are done, close the queue
            atomically (closeTBMQueue queue)
        pure (a, queue)
    cleanup (a, queue) = do
        -- upon exception or cancellation, close the queue and cancel the threads
        atomically (closeTBMQueue queue)
        cancel a
    finalSource (_, queue) = sourceQueue queue

main :: IO ()
main =
  runConduitRes $
    parSources [basePipe, roverPipe] 10 =$=
    conduitEncode                       $$
    sinkHandle stdout
  where
    basePipe  = sourceFile "base.sbp" =$= conduitDecode :: ConduitM () SBPMsg (ResourceT IO) ()
    roverPipe = sourceFile "rover.sbp" =$= conduitDecode :: ConduitM () SBPMsg (ResourceT IO) ()
