(ns sbp.test-piksi
  (:require
   [clojure.test :refer :all])
  (:import
   [swiftnav.sbp SBP]
   [swiftnav.sbp.piksi
    Latency
    MsgAlmanac
    MsgCwResults
    MsgCwStart
    MsgIarState
    MsgInitBase
    MsgReset
    MsgResetFilters
    MsgSetTime
    MsgThreadState
    MsgUartState
    UARTChannel]))

(deftest a-test
  (testing "FIXME, I fail."
    (is (= 0 1))))
