/* Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
package com.swiftnav.sbp.test;

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/logging/test_MsgPrintDep.yaml by
// generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.logging.MsgPrintDep;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_logging_MsgPrintDepTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_logging_MsgPrintDepTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 73, (byte) 78, (byte) 70, (byte) 79, (byte) 58, (byte) 32, (byte) 97,
                    (byte) 99, (byte) 113, (byte) 58, (byte) 32, (byte) 80, (byte) 82, (byte) 78,
                    (byte) 32, (byte) 49, (byte) 53, (byte) 32, (byte) 102, (byte) 111, (byte) 117,
                    (byte) 110, (byte) 100, (byte) 32, (byte) 64, (byte) 32, (byte) 45, (byte) 50,
                    (byte) 52, (byte) 57, (byte) 55, (byte) 32, (byte) 72, (byte) 122, (byte) 44,
                    (byte) 32, (byte) 50, (byte) 48, (byte) 32, (byte) 83, (byte) 78, (byte) 82,
                    (byte) 10,
                };
        SBPMessage sbp = new SBPMessage(0x2222, 0x10, payload);
        MsgPrintDep msg = new MsgPrintDep(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.text, "INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR\n");
    }

    @Test
    public void test2() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_logging_MsgPrintDepTest.test2");
        byte[] payload =
                new byte[] {
                    (byte) 73, (byte) 78, (byte) 70, (byte) 79, (byte) 58, (byte) 32, (byte) 97,
                    (byte) 99, (byte) 113, (byte) 58, (byte) 32, (byte) 80, (byte) 82, (byte) 78,
                    (byte) 32, (byte) 51, (byte) 49, (byte) 32, (byte) 102, (byte) 111, (byte) 117,
                    (byte) 110, (byte) 100, (byte) 32, (byte) 64, (byte) 32, (byte) 52, (byte) 50,
                    (byte) 52, (byte) 53, (byte) 32, (byte) 72, (byte) 122, (byte) 44, (byte) 32,
                    (byte) 50, (byte) 49, (byte) 32, (byte) 83, (byte) 78, (byte) 82, (byte) 10,
                };
        SBPMessage sbp = new SBPMessage(0x2222, 0x10, payload);
        MsgPrintDep msg = new MsgPrintDep(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.text, "INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR\n");
    }

    @Test
    public void test3() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_logging_MsgPrintDepTest.test3");
        byte[] payload =
                new byte[] {
                    (byte) 73,
                    (byte) 78,
                    (byte) 70,
                    (byte) 79,
                    (byte) 58,
                    (byte) 32,
                    (byte) 68,
                    (byte) 105,
                    (byte) 115,
                    (byte) 97,
                    (byte) 98,
                    (byte) 108,
                    (byte) 105,
                    (byte) 110,
                    (byte) 103,
                    (byte) 32,
                    (byte) 99,
                    (byte) 104,
                    (byte) 97,
                    (byte) 110,
                    (byte) 110,
                    (byte) 101,
                    (byte) 108,
                    (byte) 32,
                    (byte) 48,
                    (byte) 32,
                    (byte) 40,
                    (byte) 80,
                    (byte) 82,
                    (byte) 78,
                    (byte) 32,
                    (byte) 49,
                    (byte) 49,
                    (byte) 41,
                    (byte) 10,
                };
        SBPMessage sbp = new SBPMessage(0x2222, 0x10, payload);
        MsgPrintDep msg = new MsgPrintDep(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.text, "INFO: Disabling channel 0 (PRN 11)\n");
    }

    @Test
    public void test4() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_logging_MsgPrintDepTest.test4");
        byte[] payload =
                new byte[] {
                    (byte) 73, (byte) 78, (byte) 70, (byte) 79, (byte) 58, (byte) 32, (byte) 97,
                    (byte) 99, (byte) 113, (byte) 58, (byte) 32, (byte) 80, (byte) 82, (byte) 78,
                    (byte) 32, (byte) 50, (byte) 32, (byte) 102, (byte) 111, (byte) 117, (byte) 110,
                    (byte) 100, (byte) 32, (byte) 64, (byte) 32, (byte) 51, (byte) 57, (byte) 57,
                    (byte) 54, (byte) 32, (byte) 72, (byte) 122, (byte) 44, (byte) 32, (byte) 50,
                    (byte) 48, (byte) 32, (byte) 83, (byte) 78, (byte) 82, (byte) 10,
                };
        SBPMessage sbp = new SBPMessage(0x2222, 0x10, payload);
        MsgPrintDep msg = new MsgPrintDep(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.text, "INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR\n");
    }

    @Test
    public void test5() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_logging_MsgPrintDepTest.test5");
        byte[] payload =
                new byte[] {
                    (byte) 73, (byte) 78, (byte) 70, (byte) 79, (byte) 58, (byte) 32, (byte) 97,
                    (byte) 99, (byte) 113, (byte) 58, (byte) 32, (byte) 80, (byte) 82, (byte) 78,
                    (byte) 32, (byte) 52, (byte) 32, (byte) 102, (byte) 111, (byte) 117, (byte) 110,
                    (byte) 100, (byte) 32, (byte) 64, (byte) 32, (byte) 45, (byte) 55, (byte) 52,
                    (byte) 57, (byte) 50, (byte) 32, (byte) 72, (byte) 122, (byte) 44, (byte) 32,
                    (byte) 50, (byte) 48, (byte) 32, (byte) 83, (byte) 78, (byte) 82, (byte) 10,
                };
        SBPMessage sbp = new SBPMessage(0x2222, 0x10, payload);
        MsgPrintDep msg = new MsgPrintDep(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.text, "INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR\n");
    }

    @Test
    public void test6() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_logging_MsgPrintDepTest.test6");
        byte[] payload =
                new byte[] {
                    (byte) 73,
                    (byte) 78,
                    (byte) 70,
                    (byte) 79,
                    (byte) 58,
                    (byte) 32,
                    (byte) 68,
                    (byte) 105,
                    (byte) 115,
                    (byte) 97,
                    (byte) 98,
                    (byte) 108,
                    (byte) 105,
                    (byte) 110,
                    (byte) 103,
                    (byte) 32,
                    (byte) 99,
                    (byte) 104,
                    (byte) 97,
                    (byte) 110,
                    (byte) 110,
                    (byte) 101,
                    (byte) 108,
                    (byte) 32,
                    (byte) 49,
                    (byte) 32,
                    (byte) 40,
                    (byte) 80,
                    (byte) 82,
                    (byte) 78,
                    (byte) 32,
                    (byte) 49,
                    (byte) 53,
                    (byte) 41,
                    (byte) 10,
                };
        SBPMessage sbp = new SBPMessage(0x2222, 0x10, payload);
        MsgPrintDep msg = new MsgPrintDep(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.text, "INFO: Disabling channel 1 (PRN 15)\n");
    }
}
