(ns sbp.test-bootload
  (:require
   [clojure.test :refer :all])
  (:import
   [swiftnav.sbp
    SBP]
   [swiftnav.sbp.bootload
    MsgBootloaderHandshake
    MsgBootloaderJumpToApp
    MsgNapDeviceDna]))

(deftest a-test
  (testing "FIXME, I fail."
    (is (= 0 1))))
