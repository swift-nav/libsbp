module Test.SwiftNav.SBP.Navigation
  ( tests
  ) where

import BasicPrelude
import SwiftNav.SBP.Navigation
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
  testGroup "Navigation Tests"
    [ testParse
    ]
