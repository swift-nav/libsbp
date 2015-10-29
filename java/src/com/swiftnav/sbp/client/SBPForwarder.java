package com.swiftnav.sbp.client;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.observation.MsgEphemeris;

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
