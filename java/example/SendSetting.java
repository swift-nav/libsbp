/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.client.SBPDriver;
import com.swiftnav.sbp.client.SBPForwarder;
import com.swiftnav.sbp.client.SBPFramer;
import com.swiftnav.sbp.client.SBPHandler;
import com.swiftnav.sbp.drivers.SBPDriverJSSC;
import com.swiftnav.sbp.drivers.SBPDriverHTTP;
import com.swiftnav.sbp.logging.MsgLog;
import com.swiftnav.sbp.tracking.MsgTrackingState;
import com.swiftnav.sbp.tracking.TrackingChannelState;

import java.lang.Integer;
import java.lang.NumberFormatException;
import java.lang.System;
import java.net.MalformedURLException;

import jssc.SerialPortException;

public class SerialLink {
    private SBPHandler handler;
    private SBPFramer framer;

    public static void main(String[] args) {
        if (args.length == 1) {
            new SerialLink(args[0]);
        } else if (args.length == 2) {
            int baudrate = 0;
            try {
                baudrate = Integer.parseInt(args[1]);
            } catch (NumberFormatException e) {
                usage();
            }
            new SerialLink(args[0], baudrate);
        } else {
            usage();
        }
    }

    public static void usage() {
        System.out.println("usage: SerialLink <port> [baudrate]");
        System.exit(-1);
    }

    SerialLink(String port) {
        this(port, SBPDriverJSSC.BAUDRATE_DEFAULT);
    }
    SerialLink(String port, int baudrate) {
        try {
            framer = new SBPFramer(new SBPDriverJSSC(port, baudrate));
            handler = new SBPHandler(framer);
            handler.start();
        } catch (SerialPortException e) {
            System.err.println("Failed to open serial port: " + e.toString());
            System.exit(-2);
        }
        
        for (SBPMessage msg : handler) {
            switch (msg.type) {
                case MsgLog.TYPE:
                    logHandler(msg);
                    break;
                case MsgTrackingState.TYPE:
                    trackingHandler(msg);
                    break;
            }
        }
    }

    public void logHandler(SBPMessage msg_) {
        MsgLog msg = (MsgLog) msg_;
        System.out.print(msg.text);
    }

    public void trackingHandler(SBPMessage msg_) {
        MsgTrackingState msg = (MsgTrackingState) msg_;

        boolean tracking = false;
        for (TrackingChannelState state : msg.states)
            if (state.state != 0)
                tracking = true;
        if (!tracking)
            return;

        System.out.print("Tracking: ");
        for (TrackingChannelState state : msg.states) {
            if (state.state != 0)
                System.out.printf("PRN%d(%.1f) ", state.sid + 1, state.cn0);
        }
        System.out.println();
    }
}
