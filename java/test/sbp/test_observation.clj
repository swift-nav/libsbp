(ns sbp.test-observation
  (:require
   [clojure.test :refer :all])
  (:import
   [swiftnav.sbp SBP]
   [swiftnav.sbp.observation
    CarrierPhase
    MsgBasePos
    MsgEphemeris
    MsgObs
    ObsGPSTime
    ObservationHeader
    PackedObsContent]))

(deftest a-test
  (testing "FIXME, I fail."
    (is (= 0 1))))
