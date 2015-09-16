module Test.SwiftNav.CRC16
  ( tests
  ) where

import BasicPrelude
import SwiftNav.CRC16
import Test.Tasty
import Test.Tasty.HUnit

testEmpty :: TestTree
testEmpty = testCase "Empty test" $
  crc16 "" @?= 0

testSimple :: TestTree
testSimple = testCase "Simple test" $
  crc16 "123456789" @?= 0x31c3

tests :: TestTree
tests =
  testGroup "CRC6 tests"
    [ testEmpty
    , testSimple
    ]
