(ns sbp.test-flash
  (:require
   [clojure.test :refer :all])
  (:import
   [swiftnav.sbp SBP]
   [swiftnav.sbp.flash
    MsgFlashDone
    MsgFlashErase
    MsgFlashProgram
    MsgFlashRead
    MsgM25FlashWriteStatus
    MsgStmFlashLockSector
    MsgStmFlashUnlockSector
    MsgStmUniqueId]))

(deftest a-test
  (testing "FIXME, I fail."
    (is (= 0 1))))
