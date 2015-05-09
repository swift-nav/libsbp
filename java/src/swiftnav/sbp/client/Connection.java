package piksi;

import java.io.*;

/**
 * Interface which must be implemented to read and write data to/from a Piksi
 */
public interface Connection {

    /**
     * Write a single byte to the connection
     */
    public void write(int v) throws IOException;

    /**
     * Read a single byte from the connection
     * @return the byte or -1 if EOF is reached
     */
    public int read() throws IOException;

}
