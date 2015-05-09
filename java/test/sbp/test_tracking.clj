(ns sbp.test-tracking
  (:require
   [clojure.test :refer :all])
  (:import
   [swiftnav.sbp SBP]
   [swiftnav.sbp.tracking
    MsgEphemerisOld
    MsgTrackingState
    TrackingChannelState]))

(deftest a-test
  (testing "FIXME, I fail."
    (is (= 0 1))))
