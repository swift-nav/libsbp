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

package swiftnav.sbp.observation;

import org.codehaus.preon.annotation.BoundNumber;
import org.codehaus.preon.buffer.ByteOrder;
import swiftnav.sbp.SBP;


  
/**
   * Pseudorange and carrier phase observation for a satellite being
 * tracked. */
public class PackedObsContent{

    public PackedObsContent() {
    }

  
    /** * Pseudorange observation */
    @BoundString()
    private int P;

  
    /** * Carrier phase observation */
    @BoundString()
    private None L;

  
    /** * Carrier-to-Noise density */
    @BoundString()
    private int cn0;

  
    /**  * Lock indicator. This value changes whenever a satellite
 * signal has lost and regained lock, indicating that the
 * carrier phase ambiguity may have changed. */
    @BoundString()
    private int lock;

  
    /** * PRN-1 identifier of the satellite signal */
    @BoundString()
    private int prn;

  

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
