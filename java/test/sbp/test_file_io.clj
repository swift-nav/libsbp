(ns sbp.test-file-io
  (:require
   [clojure.test :refer :all])
  (:import
   [swiftnav.sbp SBP]
   [swiftnav.sbp.file_io
    MsgFileioRead
    MsgFileioReadDir
    MsgFileioRemove
    MsgFileioWrite]))

(deftest a-test
  (testing "FIXME, I fail."
    (is (= 0 1))))
