module Test.SwiftNav.SBP.Logging
  ( tests
  ) where

import BasicPrelude
import SwiftNav.SBP.Logging
import Test.SwiftNav.SBP.Utils
import Test.Tasty
import Test.Tasty.HUnit

testParse :: TestTree
testParse =
  testGroup "Package tests"
    [ testCase "Parsing tests" $ do
        let filepath = "../spec/tests/yaml/swiftnav/sbp/test_logging.yaml"
            moduleName = "sbp.logging"
        val <- assertPackage filepath moduleName
        assertBool "Fail" val
    ]

tests :: TestTree
tests =
  testGroup "Logging Tests"
    [ testParse
    ]
