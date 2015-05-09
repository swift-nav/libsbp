(ns sbp.core-test
  (:require
   [clojure.test :refer :all])
  (:import
   [swiftnav.sbp SBP]
   [swiftnav.sbp.navigation
    MsgBaselineECEF
    MsgBaselineNED
    MsgDops
    MsgGPSTime
    MsgPosECEF
    MsgPosLLH
    MsgVelECEF
    MsgVelNED]))

(deftest a-test
  (testing "FIXME, I fail."
    (is (= 0 1))))
