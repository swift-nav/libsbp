module Test.SwiftNav.SBP.Acquisition
  ( tests
  ) where

import BasicPrelude
import SwiftNav.SBP.Acquisition
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
  testGroup "Acquisition Tests"
    [ testParse
    ]
