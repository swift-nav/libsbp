package piksi;

import jssc.SerialPort;
import jssc.SerialPortException;
import java.io.*;

public class JSSCConnection implements Connection {

    private SerialPort port;
    public JSSCConnection(String path) throws SerialPortException {
        port = new SerialPort(path);
        port.openPort();
        port.setParams(1000000, 8, 1, 0);
    }

    public int read() throws IOException {
        try {
            return port.readBytes(1)[0] & 0xFF;
        } catch (SerialPortException e) {
            throw new IOException(e);
        }
    }

    public void write(int v) throws IOException {
        try {
            port.writeByte((byte)v);
        } catch (SerialPortException e) {
            throw new IOException(e);
        }
    }
    
}
