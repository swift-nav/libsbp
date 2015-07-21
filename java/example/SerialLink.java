/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Gareth McMullin <gareth@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.client.SBPCallback;
import com.swiftnav.sbp.client.SBPHandler;
import com.swiftnav.sbp.drivers.SBPDriverJSSC;
import com.swiftnav.sbp.loggers.JSONLogger;
import com.swiftnav.sbp.logging.MsgPrintDep;
import com.swiftnav.sbp.tracking.MsgTrackingStateDepA;
import com.swiftnav.sbp.tracking.TrackingChannelStateDepA;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;

import jssc.SerialPortException;

public class SerialLink {
    private SBPHandler handler;

    public static void main(String[] args) {
        new SerialLink(args[0]);
    }

    SerialLink(String port) {
        try {
            handler = new SBPHandler(new SBPDriverJSSC(port));
        } catch (SerialPortException e) {
            System.err.println("Failed to open serial port: " + e.toString());
            System.exit(-1);
        }
        handler.addCallback(MsgPrintDep.TYPE, printHandler);
        handler.addCallback(MsgTrackingStateDepA.TYPE, trackingHandler);
        try {
            handler.addCallback(new JSONLogger(new FileOutputStream("logfile.json")));
        } catch (FileNotFoundException e) {
            System.err.println("Error opening logfile: " + e.toString());
        }
        handler.start();
    }

    SBPCallback printHandler = new SBPCallback() {
        @Override
        public void receiveCallback(SBPMessage msg_) {
            MsgPrintDep msg = (MsgPrintDep)msg_;
            System.out.print(msg.text);
        }
    };

    SBPCallback trackingHandler = new SBPCallback() {
        @Override
        public void receiveCallback(SBPMessage msg_) {
            MsgTrackingStateDepA msg = (MsgTrackingStateDepA)msg_;
            
            boolean tracking = false;
            for (TrackingChannelStateDepA state : msg.states)
                if (state.state != 0)
                    tracking = true;
            if (!tracking)
                return;

            System.out.print("Tracking: ");
            for (TrackingChannelStateDepA state : msg.states) {
                if (state.state != 0)
                    System.out.printf("PRN%d(%.1f) ", state.prn + 1, state.cn0);
            }
            System.out.println();
        }
    };
}
