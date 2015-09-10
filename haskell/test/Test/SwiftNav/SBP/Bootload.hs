module Test.SwiftNav.SBP.Bootload
  ( tests
  ) where

import BasicPrelude
import SwiftNav.SBP.Bootload
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
  testGroup "Bootload Tests"
    [ testParse
    ]
