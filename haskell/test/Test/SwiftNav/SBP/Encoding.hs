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

testRoundtrip2 :: TestTree
testRoundtrip2 = QC.testProperty "MsgObs JSON" prop
  where prop m = (A.decode . A.encode $ (m :: MsgObs)) === Just (m :: MsgObs)

testRoundtrip3 :: TestTree
testRoundtrip3 = QC.testProperty "MsgObs Binary" prop
  where prop m = (B.decode . B.encode $ (m :: MsgObs)) === (m :: MsgObs)

tests :: TestTree
tests = testGroup "Roundtrip JSON serialization"
        [ testRoundtrip
        , testParse
        , testRoundtrip2
        , testRoundtrip3
        ]
