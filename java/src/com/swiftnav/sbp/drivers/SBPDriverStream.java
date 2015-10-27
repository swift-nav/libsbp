package com.swiftnav.sbp.drivers;

import com.swiftnav.sbp.client.SBPDriver;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

public class SBPDriverStream implements SBPDriver {
    protected InputStream in;
    protected OutputStream out;

    protected SBPDriverStream() {}
    protected SBPDriverStream(InputStream in_, OutputStream out_) {
        in = in_;
        out = out_;
    }

    protected void openStream() throws IOException {

    }

    @Override
    public byte[] read(int len) throws IOException {
        byte[] ret = new byte[len];
        int i = 0;

        synchronized (this) {
            if (in == null)
                openStream();
        }

        while (i < len) {

            int count;
            try {
                count = in.read(ret, i, len - i);
            } catch (IOException e) {
                e.printStackTrace();
                throw e;
            }
            if (count < 0) {
                System.out.printf("read from broken pipe %d\n", count);
                throw new IOException("read from broken input stream");
            }
            i += count;
        }
        return ret;
    }

    @Override
    public void write(byte[] data) throws IOException {
        synchronized (this) {
            if (out == null)
                openStream();
        }

        out.write(data);
    }
}
