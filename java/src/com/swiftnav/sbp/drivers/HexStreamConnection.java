/*
 * Based on community contributed code:
 * https://groups.google.com/forum/#!topic/swiftnav-discuss/s0ouH81Lc88
 */
package com.swiftnav.sbp.drivers;

import com.swiftnav.sbp.client.SBPDriver;

import java.io.*;

/**
 * A Connection which will read it's input and output from the specified
 * streams as hex-encoded ASCII - eg 550100... for a hearbeat message.
 * Whitespace in the streams are ignored
 */
public class HexStreamConnection implements SBPDriver {

    private final InputStream in;
    private final PrintStream out;
    private boolean eof = false;

    public HexStreamConnection() {
        this(System.in, System.out);
    }

    public HexStreamConnection(InputStream in, PrintStream out) {
        this.in = in;
        this.out = out;
    }

    public int read() throws IOException {
        int read = 0, val = -1;
        if (eof) {
            return -1;
        }
        while (true) {
            int c = in.read();
            if (c < 0) {
                eof = true;
                return -1;
            } else if (c != '\n' && c != ' ' && c != '\t' && c != '\r') {
                c = (c>='0' && c<='9') ? c-'0' : (c>='A' && c<='F') ? c-'A'+10 : (c>='a' && c<='f') ? c-'a'+10 : -1;
                if (c < 0) {
                    throw new IOException("Illegal hex digit 0x"+Integer.toHexString(c));
                } else if (read == 0) {
                    read = 1;
                    val = c<<4;
                } else {
                    val |= c;
                    break;
                }
            }
        }
        return val;
    }

    public void write(int v) {
        out.printf("%02x", v&0xFF);
    }

    @Override
    public byte[] read(int len) throws IOException {
        byte[] ret = new byte[len];
        for (int i = 0; i < len; i++)
            ret[i] = (byte)read();
        return ret;
    }

    @Override
    public void write(byte[] data) throws IOException {
        for (byte b : data)
            write(b);
    }
}
