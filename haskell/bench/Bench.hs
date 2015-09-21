import BasicPrelude
import Criterion.Main
import qualified Data.Aeson as A
import qualified Data.Binary as B
import qualified Data.ByteString.Base64 as Base64
import qualified Data.ByteString.Lazy as LBS
import SwiftNav.SBP

msgToEncode :: MsgAcqResult
msgToEncode = MsgAcqResult 2 2 2 3

msgToEncode' :: SBPMsg
msgToEncode' = SBPMsgAcqResult msgToEncode (toSBP msgToEncode defaultSender)

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
    [ bench "Encode short message"          $ nf A.encode msgToEncode
    , bench "Encode wrapped message"        $ nf A.encode msgToEncode'
    , bench "Encode longer message"         $ nf A.encode longMsgToEncode
    , bench "Encode longer wrapped message" $ nf A.encode longMsgToEncode'
    ]

binaryEncode :: Benchmark
binaryEncode = do
  bgroup "Binary encoding"
    [ bench "Encode short message"          $ nf B.encode msgToEncode
    , bench "Encode wrapped message"        $ nf B.encode msgToEncode'
    , bench "Encode longer message"         $ nf B.encode longMsgToEncode
    , bench "Encode longer wrapped message" $ nf B.encode longMsgToEncode'
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
