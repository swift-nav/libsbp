(ns sbp.test-system
  (:require
   [clojure.test :refer :all])
  (:import
   [swiftnav.sbp SBP]
   [swiftnav.sbp.system
    MsgHeartbeat
    MsgStartup]))

(deftest a-test
  (testing "FIXME, I fail."
    (is (= 0 1))))
