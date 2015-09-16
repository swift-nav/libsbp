import           BasicPrelude
import qualified Test.SwiftNav.CRC16 as CRC16
import qualified Test.SwiftNav.SBP.Acquisition as Acquisition
import qualified Test.SwiftNav.SBP.Bootload as Bootload
import qualified Test.SwiftNav.SBP.Encoding as Encoding
import qualified Test.SwiftNav.SBP.ExtEvents as ExtEvents
import qualified Test.SwiftNav.SBP.Logging as Logging
import qualified Test.SwiftNav.SBP.Navigation as Navigation
import qualified Test.SwiftNav.SBP.Observation as Observation
import qualified Test.SwiftNav.SBP.Piksi as Piksi
import qualified Test.SwiftNav.SBP.System as System
import qualified Test.SwiftNav.SBP.Table as Table
import qualified Test.SwiftNav.SBP.Tracking as Tracking
import           Test.Tasty

tests :: TestTree
tests =
  testGroup "Tests"
    [ CRC16.tests
    , Acquisition.tests
    , Bootload.tests
    , Encoding.tests
    , ExtEvents.tests
    , Logging.tests
    , Navigation.tests
    , Observation.tests
    , Piksi.tests
    , System.tests
    , Table.tests
    , Tracking.tests
    ]

main :: IO ()
main = defaultMain tests
