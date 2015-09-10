module Test.SwiftNav.SBP.Piksi
  ( tests
  ) where

import BasicPrelude
import SwiftNav.SBP.Piksi
import Test.SwiftNav.SBP.Utils
import Test.Tasty
import Test.Tasty.HUnit

testParse :: TestTree
testParse =
  testGroup "Package tests"
    [ testCase "Parsing tests" $ do
        let filepath = "../spec/tests/yaml/swiftnav/sbp/test_piksi.yaml"
            moduleName = "sbp.piksi"
        val <- assertPackage filepath moduleName
        assertBool "Fail" val
    ]

tests :: TestTree
tests =
  testGroup "Piksi Tests"
    [ testParse
    ]
