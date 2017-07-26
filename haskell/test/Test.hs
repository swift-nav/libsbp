{-# LANGUAGE NoImplicitPrelude #-}

import           BasicPrelude
import qualified Test.SwiftNav.CRC16 as CRC16
import           Test.Tasty

tests :: TestTree
tests =
  testGroup "Tests"
    [ CRC16.tests
    ]

main :: IO ()
main = defaultMain tests
