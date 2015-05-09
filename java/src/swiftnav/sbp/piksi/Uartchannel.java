/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Bhaskar Mookerji <mookerji@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

package swiftnav.sbp.piksi;

import org.codehaus.preon.annotation.BoundNumber;
import org.codehaus.preon.buffer.ByteOrder;
import swiftnav.sbp.SBP;


  
/**
   * Throughput, utilization, and error counts on the RX/TX buffers
 * of this UART channel. The reported percentage values require to
 * be normalized. */
public class UARTChannel{

    public UARTChannel() {
    }

  
    /** * UART transmit throughput */
    @BoundString()
    private float tx_throughput;

  
    /** * UART receive throughput */
    @BoundString()
    private float rx_throughput;

  
    /** * UART CRC error count */
    @BoundString()
    private int crc_error_count;

  
    /** * UART IO error count */
    @BoundString()
    private int io_error_count;

  
    /**  * UART transmit buffer percentage utilization (ranges from
 * 0 - 255) */
    @BoundString()
    private int tx_buffer_level;

  
    /**  * UART receive buffer percentage utilization (ranges from
 * 0 to 255) */
    @BoundString()
    private int rx_buffer_level;

  

    /** Given a binary payload d, update the appropriate payload
     *  fields of the message.
    */
    public void fromBinary() {
      return;
    }

    /** Produce a framed/packed SBP message.
     */
    public int toBinary() {
        return 0;
    }

    public String toString() {
        return "Foo!";
    }
}
