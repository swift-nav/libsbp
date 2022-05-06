package com.swiftnav.example;


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.client.SBPFramer;
import com.swiftnav.sbp.client.SBPHandler;
import com.swiftnav.sbp.drivers.SBPDriverTCP;
import com.swiftnav.sbp.navigation.MsgPosLLH;

public class TCPExample {

    public static void main(String[] args) {
        if (args.length != 2) {
            System.out.println("usage: TCPExample <server> <port>");
            return;
        }
        String server = args[0];
        int port = Integer.parseInt(args[1]);
        new TCPExample().start(server, port);
    }

    public void start(String server, int port) {
        SBPFramer framer = new SBPFramer(new SBPDriverTCP(server, port));
        SBPHandler handler = new SBPHandler(framer);
        handler.start();

        for (SBPMessage msg : handler) {
            if (msg.type == MsgPosLLH.TYPE) {
                MsgPosLLH posLLH = ((MsgPosLLH) msg);
                System.out.printf("%s %s%n", posLLH.lat, posLLH.lon);
            }
        }
    }
}