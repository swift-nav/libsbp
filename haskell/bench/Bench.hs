import BasicPrelude
import Criterion.Main
import qualified Data.Aeson as A
import qualified Data.Binary as B
import qualified Data.ByteString.Base64 as Base64
import qualified Data.ByteString.Lazy as LBS
import SwiftNav.SBP

-- | Message length and dispatch overhead for SBP serialization and
-- deserialization (on local developer Macbook Pro).
--
-- benchmarking JSON encoding/Encode short message (acq)
-- time                 3.711 μs   (3.538 μs .. 4.015 μs)
-- benchmarking JSON encoding/Encode wrapped message
-- time                 7.883 μs   (7.607 μs .. 8.135 μs)
-- benchmarking JSON encoding/Encode longer message (obs)
-- time                 15.04 μs   (14.59 μs .. 15.45 μs)
-- benchmarking JSON encoding/Encode longer wrapped message
-- time                 20.90 μs   (20.49 μs .. 21.40 μs)
-- benchmarking JSON encoding/Encode longer message (base)
-- time                 3.762 μs   (3.511 μs .. 4.082 μs)
-- benchmarking JSON encoding/Encode longer wrapped message
-- time                 6.746 μs   (6.564 μs .. 7.059 μs)
-- benchmarking Binary encoding/Encode short message (acq)
-- time                 4.913 μs   (4.425 μs .. 5.342 μs)
-- benchmarking Binary encoding/Encode wrapped message
-- time                 6.213 μs   (5.495 μs .. 7.044 μs)
-- benchmarking Binary encoding/Encode longer message (obs)
-- time                 5.055 μs   (4.596 μs .. 5.542 μs)
-- benchmarking Binary encoding/Encode longer wrapped message
-- time                 5.200 μs   (4.733 μs .. 5.698 μs)
-- benchmarking Binary encoding/Encode longer message (base)
-- time                 6.353 μs   (6.058 μs .. 6.676 μs)
-- benchmarking Binary encoding/Encode longer wrapped message
-- time                 4.585 μs   (4.146 μs .. 5.081 μs)
-- benchmarking Binary decoding/Decode short message
-- time                 1.008 μs   (976.0 ns .. 1.046 μs)
-- benchmarking Binary decoding/Decode longer message
-- time                 3.211 μs   (2.989 μs .. 3.449 μs)

msgToEncode :: MsgAcqResult
msgToEncode = MsgAcqResult 2 2 2 3

msgToEncode' :: SBPMsg
msgToEncode' = SBPMsgAcqResult msgToEncode (toSBP msgToEncode defaultSender)

msgToEncode1 :: MsgBaselineNed
msgToEncode1 = MsgBaselineNed 100000 1 1 1 1 1 1 1

msgToEncode1' :: SBPMsg
msgToEncode1' = SBPMsgBaselineNed msgToEncode1 (toSBP msgToEncode1 defaultSender)

longMsgToEncode :: MsgObs
longMsgToEncode = MsgObs (ObservationHeader (ObsGPSTime 100000 1024) 4)
                         [ PackedObsContent 222222 (CarrierPhase 22 22) 2 2 0
                         , PackedObsContent 222222 (CarrierPhase 22 22) 2 2 1
                         , PackedObsContent 222222 (CarrierPhase 22 22) 2 2 2
                         , PackedObsContent 222222 (CarrierPhase 22 22) 2 2 3
                         ]

longMsgToEncode' :: SBPMsg
longMsgToEncode' = SBPMsgObs longMsgToEncode (toSBP longMsgToEncode defaultSender)

binaryToDecode :: ByteString
binaryToDecode = Base64.decodeLenient "VRUAwwQNzcx0QQAgQ0TkSpRFDhdL"

longBinaryToDecode :: ByteString
longBinaryToDecode = Base64.decodeLenient "VUYAwwSwAAAAAAAATb4AAAAAAHpTwAAAAAAA6\
                                          \W5AAAAAAAA8z74AAAAAABzePgAAAAAAgHg+AA\
                                          \AAAAAAbD4K5reM1uYyPjZWxKT8Cv8/AAAAJPe\
                                          \/gD8AAKAFwSG0QLqKUYFY7wFAXtJ4qmoZQb5n\
                                          \1SCb48Lgv5wvaF1lN+8/xFNk/jM2BL4AAAAAM\
                                          \vI0PwAAAAAAAHK9AAAAAAAAAAAAAAAAgAwZQS\
                                          \4HAAAAAIAMGUEuBwEBHgCqIQ=="

jsonEncode :: Benchmark
jsonEncode = do
  bgroup "JSON encoding"
    [ bench "Encode short message (acq)"    $ nf A.encode msgToEncode
    , bench "Encode wrapped message"        $ nf A.encode msgToEncode'
    , bench "Encode longer message (obs)"   $ nf A.encode longMsgToEncode
    , bench "Encode longer wrapped message" $ nf A.encode longMsgToEncode'
    , bench "Encode longer message (base)"  $ nf A.encode msgToEncode1
    , bench "Encode longer wrapped message" $ nf A.encode msgToEncode1'
    ]

binaryEncode :: Benchmark
binaryEncode = do
  bgroup "Binary encoding"
    [ bench "Encode short message (acq)"    $ nf B.encode msgToEncode
    , bench "Encode wrapped message"        $ nf B.encode msgToEncode'
    , bench "Encode longer message (obs)"   $ nf B.encode longMsgToEncode
    , bench "Encode longer wrapped message" $ nf B.encode longMsgToEncode'
    , bench "Encode longer message (base)"  $ nf B.encode msgToEncode1
    , bench "Encode longer wrapped message" $ nf B.encode msgToEncode1'
    ]

decodeSBP :: LBS.ByteString -> SBPMsg
decodeSBP x = B.decode x

binaryDecode :: Benchmark
binaryDecode = do
  bgroup "Binary decoding"
    [ bench "Decode short message"  $ whnf decodeSBP (LBS.fromStrict binaryToDecode)
    , bench "Decode longer message" $ whnf decodeSBP (LBS.fromStrict longBinaryToDecode)
    ]

main :: IO ()
main = do
  defaultMain [ jsonEncode
              , binaryEncode
              , binaryDecode
              ]
