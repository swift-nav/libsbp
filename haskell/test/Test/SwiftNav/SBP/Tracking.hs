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
  testGroup "Package tests"
    [ testCase "Parsing tests" $ do
        let filepath = "../spec/tests/yaml/swiftnav/sbp/test_tracking.yaml"
            moduleName = "sbp.tracking"
        val <- assertPackage filepath moduleName
        assertBool "Fail" val
    ]

tests :: TestTree
tests =
  testGroup "Tracking Tests"
    [ testParse
    ]
