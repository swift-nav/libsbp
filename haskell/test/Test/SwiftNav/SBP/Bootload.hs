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
  testGroup "Package tests"
    [ testCase "Parsing tests" $ do
        let filepath = "../spec/tests/yaml/swiftnav/sbp/test_bootload.yaml"
            moduleName = "sbp.bootload"
        val <- assertPackage filepath moduleName
        assertBool "Fail" val
    ]

tests :: TestTree
tests =
  testGroup "Bootload Tests"
    [ testParse
    ]
