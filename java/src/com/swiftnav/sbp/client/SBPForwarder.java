/* Copyright (C) 2015-2022 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
package com.swiftnav.sbp.client;


import com.swiftnav.sbp.SBPMessage;
import java.io.IOException;

public class SBPForwarder extends Thread {
    private Iterable<SBPMessage> source;
    private SBPSender sink;

    public SBPForwarder(Iterable<SBPMessage> source_, SBPSender sink_) {
        source = source_;
        sink = sink_;
    }

    @Override
    public void run() {
        for (SBPMessage msg : source) {
            System.out.println(msg.toString());
            try {
                sink.sendMessage(msg);
            } catch (IOException e) {
                e.printStackTrace();
                break;
            }
        }
        System.out.println("Forwarder thread exiting");
    }
}
