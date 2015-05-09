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

package swiftnav.sbp.acquisition;

import org.codehaus.preon.annotation.BoundNumber;
import org.codehaus.preon.buffer.ByteOrder;
import swiftnav.sbp.SBP;



  
/** SBP class for message MSG_ACQ_RESULT (0x0015).
 *
 * You can have MSG_ACQ_RESULT inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
  * This message describes the results from an attempted GPS signal
 * acquisition search for a satellite PRN over a code phase/carrier
 * frequency range. It contains the parameters of the point in the
 * acquisition search space with the best signal-to-noise (SNR)
 * ratio. */
public class MsgAcqResult extends SBP {

    public static final int TYPE = 0x0015;

    public MsgAcqResult() {
    }

    
    /**  * SNR of best point. Currently dimensonless, but will have
 * units of dB Hz in the revision of this message. */
    @BoundString()
    private float snr;

    
    /** * Code phase of best point */
    @BoundString()
    private float cp;

    
    /** * Carrier frequency of best point */
    @BoundString()
    private float cf;

    
    /**  * PRN-1 identifier of the satellite signal for which
 * acquisition was attempted */
    @BoundString()
    private int prn;

    

    /** Given a binary payload d, update the appropriate payload
     *  fields of the message. */
    public void fromBinary() {

    }

    /** Produce a framed/packed SBP message. */
    public int toBinary() {
        return 0;
    }

    /** Given a JSON-encoded string s, build a message object. */
    public void fromJSON(String s) {

    }

    public void toJSONDict() {
    }

    public String toString() {
        return "Foo!";
    }
}