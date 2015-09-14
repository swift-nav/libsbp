module Test.SwiftNav.SBP.System
  ( tests
  ) where

import BasicPrelude
import SwiftNav.SBP.System
import Test.SwiftNav.SBP.Utils
import Test.Tasty
import Test.Tasty.HUnit

testParse :: TestTree
testParse =
  testGroup "Package tests"
    [ testCase "Parsing tests" $ do
        let filepath = "../spec/tests/yaml/swiftnav/sbp/test_system.yaml"
            moduleName = "sbp.system"
        val <- assertPackage filepath moduleName
        assertBool "Fail" val
    ]

tests :: TestTree
tests =
  testGroup "System Tests"
    [ testParse
    ]
