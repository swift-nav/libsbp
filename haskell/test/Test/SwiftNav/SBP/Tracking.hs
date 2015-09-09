module Test.SwiftNav.SBP.Tracking
  ( tests
  ) where

import BasicPrelude
import SwiftNav.SBP.Tracking
import Test.SwiftNav.SBP.Utils
import Test.Tasty
import Test.Tasty.HUnit

testParse :: TestTree
testParse =
  testGroup "Empty Test"
    [ testCase "Empty data" $ do
        True @?= False
    ]

tests :: TestTree
tests =
  testGroup "Tracking Tests"
    [ testParse
    ]
