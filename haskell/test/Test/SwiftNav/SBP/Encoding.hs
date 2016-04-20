{-# OPTIONS -fno-warn-orphans #-}

module Test.SwiftNav.SBP.Encoding
  ( tests
  ) where

import           BasicPrelude
import qualified Data.Aeson            as A
import           Data.ByteString       as BS
import           SwiftNav.SBP.Encoding ()
import           Test.QuickCheck
import           Test.Tasty
import           Test.Tasty.HUnit
import           Test.Tasty.QuickCheck as QC

instance Arbitrary BS.ByteString where
    arbitrary = BS.pack <$> arbitrary
    shrink xs = BS.pack <$> shrink (BS.unpack xs)

instance CoArbitrary BS.ByteString where
    coarbitrary = coarbitrary . BS.unpack

testParse :: TestTree
testParse =
  testGroup "Empty Test"
    [ testCase "Empty data" $ do
        (A.decode . A.encode $ ("dddd" :: BS.ByteString)) @?= Just ("dddd" :: BS.ByteString)
    ]

testRoundtrip :: TestTree
testRoundtrip = QC.testProperty "Aeson" prop
  where prop ws = (A.decode . A.encode $ (ws :: BS.ByteString)) === Just (ws :: BS.ByteString)

tests :: TestTree
tests = testGroup "Roundtrip JSON serialization"
        [ testRoundtrip
        , testParse
        ]
