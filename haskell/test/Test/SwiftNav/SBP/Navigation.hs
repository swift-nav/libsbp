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
  testGroup "Package tests"
    [ testCase "Parsing tests" $ do
        let filepath = "../spec/tests/yaml/swiftnav/sbp/test_navigation.yaml"
            moduleName = "sbp.navigation"
        val <- assertPackage filepath moduleName
        assertBool "Fail" val
    ]

tests :: TestTree
tests =
  testGroup "Navigation Tests"
    [ testParse
    ]
