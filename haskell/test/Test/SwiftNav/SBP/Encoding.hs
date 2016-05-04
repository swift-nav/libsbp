{-# OPTIONS -fno-warn-orphans #-}

module Test.SwiftNav.SBP.Encoding
  ( tests
  ) where

import           BasicPrelude
import qualified Data.Aeson                as A
import qualified Data.Binary               as B
import           Data.ByteString           as BS
import           SwiftNav.SBP
import           SwiftNav.SBP.Encoding     ()
import           Test.QuickCheck
import           Test.QuickCheck.Instances ()
import           Test.Tasty
import           Test.Tasty.HUnit
import           Test.Tasty.QuickCheck     as QC

testParse :: TestTree
testParse =
  testGroup "Empty Test"
    [ testCase "Empty data" $ do
        (A.decode . A.encode $ ("dddd" :: BS.ByteString)) @?= Just ("dddd" :: BS.ByteString)
    ]

testRoundtrip :: TestTree
testRoundtrip = QC.testProperty "Aeson" prop
  where prop ws = (A.decode . A.encode $ (ws :: BS.ByteString)) === Just (ws :: BS.ByteString)

testRoundtripMsgObsJson :: TestTree
testRoundtripMsgObsJson = QC.testProperty "MsgObs JSON" prop
  where prop m = (A.decode . A.encode $ (m :: MsgObs)) === Just (m :: MsgObs)

testRoundtripMsgObsBinary :: TestTree
testRoundtripMsgObsBinary = QC.testProperty "MsgObs Binary" prop
  where prop m = (B.decode . B.encode $ (m :: MsgObs)) === (m :: MsgObs)

testRoundtripSBPMsgJson :: TestTree
testRoundtripSBPMsgJson = QC.testProperty "SBPMsg JSON" prop
  where prop m = (A.decode . A.encode $ (m :: SBPMsg)) === Just (m :: SBPMsg)

testRoundtripSBPMsgBinary :: TestTree
testRoundtripSBPMsgBinary = QC.testProperty "SBPMsg Binary" prop
  where prop m = (B.decode . B.encode $ (m :: SBPMsg)) === (m :: SBPMsg)

tests :: TestTree
tests = testGroup "Roundtrip JSON serialization"
        [ testRoundtrip
        , testParse
        , testRoundtripMsgObsJson
        , testRoundtripMsgObsBinary
        --, testRoundtripSBPMsgJson
        --, testRoundtripSBPMsgBinary
        ]
