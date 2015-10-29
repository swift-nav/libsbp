package com.swiftnav.sbp.client;

import com.swiftnav.sbp.SBPMessage;

import java.io.IOException;

public interface SBPSender {
    void sendMessage(SBPMessage msg) throws IOException;
}
