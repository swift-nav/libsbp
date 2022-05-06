package com.swiftnav.example;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.client.SBPFramer;
import com.swiftnav.sbp.client.SBPHandler;
import com.swiftnav.sbp.drivers.SBPDriverJSSC;
import com.swiftnav.sbp.logging.MsgLog;
import com.swiftnav.sbp.tracking.MsgTrackingState;
import com.swiftnav.sbp.tracking.TrackingChannelState;
import jssc.SerialPortException;

public class TrackingState {
    private SBPHandler handler;
    private SBPFramer framer;

    public static void main(String[] args) {
        if (args.length == 1) {
            new TrackingState(args[0]);
        } else if (args.length == 2) {
            int baudrate = 0;
            try {
                baudrate = Integer.parseInt(args[1]);
            } catch (NumberFormatException e) {
                usage();
            }
            new TrackingState(args[0], baudrate);
        } else {
            usage();
        }
    }

    public static void usage() {
        System.out.println("usage: TrackingState <port> [baudrate]");
        System.exit(-1);
    }

    public TrackingState(String port) {
        this(port, SBPDriverJSSC.BAUDRATE_DEFAULT);
    }

    public TrackingState(String port, int baudrate) {
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
            if (state.cn0 != 0) {
                tracking = true;
                break;
            }

        if (!tracking) return;

        System.out.print("Tracking: ");
        for (TrackingChannelState state : msg.states) {
            if (state.cn0 != 0) {
                System.out.printf("sat=%d, code=%d, cn0=%.1f ", state.sid.sat, state.sid.code, state.cn0);
            }
        }
        System.out.println();
    }
}