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
  testGroup "Package tests"
    [ testCase "Parsing tests" $ do
        let filepath = "../spec/tests/yaml/swiftnav/sbp/test_acquisition.yaml"
            moduleName = "sbp.acquisition"
        val <- assertPackage filepath moduleName
        assertBool "Fail" val
    ]

tests :: TestTree
tests =
  testGroup "Acquisition Tests"
    [ testParse
    ]
