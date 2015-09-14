-- |
-- Module:      SwiftNav.SBP
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- A straightforward port of the testing harness stuff for libsbp's
-- Python client:
-- https://github.com/swift-nav/libsbp/blob/master/python/tests/sbp/utils.py.
-- Uses the spec'd out unit tests at
-- https://github.com/swift-nav/libsbp/tree/master/spec/yaml/swiftnav/sbp.

module Test.SwiftNav.SBP.Utils
  ( assertPackage
  ) where

import BasicPrelude
import Data.ByteString
import Data.Yaml.YamlLight

-- -- | Assert that a proper SBP parsing from a raw package of data.
-- assertSBP :: undefined -- ^ SBP message parsed from unit test's raw packet
--           -> undefined -- ^ Unit test case parsed from YAML
--           -> Bool
-- assertSBP sbp testCase = undefined

-- -- | Checks the field values of a parsed message for equality against
-- -- some ground truth value.
-- fieldEq :: undefined -- ^ Parsed field contents
--         -> undefined -- ^ Expected field contents
--         -> Bool
-- fieldEq p e = undefined

-- -- | Asserts that the parsed payload of an SBP message has the
-- -- expected field values.
-- assertMsg :: undefined -- ^ Parsed SBP message
--           -> undefined -- ^ Unit test case for this message
--           -> Bool
-- assertMsg msg testCase = undefined

-- -- | Asserts that a msg gets serialized back into binary with the
-- -- expected value.
-- assertMsgRoundtrip :: undefined
--                    -> undefined
--                    -> undefined
-- assertMsgRoundtrip msg rawPackage = undefined

-- -- | Asserts that a msg gets serialized back into JSON with the
-- -- expected value, as well as gets serialized from JSON into an
-- -- expected object.
-- assertMsgRoundtripJson :: undefined
--                        -> undefined
--                        -> undefined
-- assertMsgRoundtripJson msg rawJSON = undefined

-- -- | Asserts that a message materialized will get serialized into the
-- -- right JSON object.
-- assertMaterialization :: ByteString
--                       -> undefined
--                       -> undefined
--                       -> undefined
-- assertMaterialization msg sbp rawJSON = undefined

-- | Sanity check the package collection of tests before actually
-- running the tests.
assertSanePackage :: ByteString
                  -> ByteString
                  -> Bool
assertSanePackage pkgName pkg = undefined

-- | Runs unit tests for message bindings by reading a YAML unit test
-- specification, parsing a raw packet for each test, and then
-- asserting that SBP messages and parsed payloads have their intended
-- values.
assertPackage :: String     -- ^ Filepath to unit test specifications
              -> ByteString -- ^ Name of package to test
              -> IO Bool
assertPackage testFilename pkgName = do
   pkg <- parseYamlFile testFilename
   case pkg of
     YMap x -> return True
     _      -> return False
