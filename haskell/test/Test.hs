{-# LANGUAGE NoImplicitPrelude #-}

import           BasicPrelude
import qualified Test.SwiftNav.CRC16    as CRC16
import qualified Test.SwiftNav.Encoding as Encoding
import           Test.Tasty

tests :: TestTree
tests =
  testGroup "Tests"
    [ CRC16.tests
    , Encoding.tests
    ]

main :: IO ()
main = defaultMain tests
