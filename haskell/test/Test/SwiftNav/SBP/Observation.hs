module Test.SwiftNav.SBP.Observation
  ( tests
  ) where

import BasicPrelude
import SwiftNav.SBP.Observation
import Test.SwiftNav.SBP.Utils
import Test.Tasty
import Test.Tasty.HUnit

testParse :: TestTree
testParse =
  testGroup "Package tests"
    [ testCase "Parsing tests" $ do
        let filepath = "../spec/tests/yaml/swiftnav/sbp/test_observation.yaml"
            moduleName = "sbp.observation"
        val <- assertPackage filepath moduleName
        assertBool "Fail" val
    ]

tests :: TestTree
tests =
  testGroup "Observation Tests"
    [ testParse
    ]
