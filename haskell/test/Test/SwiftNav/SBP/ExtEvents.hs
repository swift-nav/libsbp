module Test.SwiftNav.SBP.ExtEvents
  ( tests
  ) where

import BasicPrelude
import SwiftNav.SBP.ExtEvents
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
  testGroup "ExtEvents Tests"
    [ testParse
    ]
