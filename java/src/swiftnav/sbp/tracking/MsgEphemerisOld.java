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

package swiftnav.sbp.tracking;

import org.codehaus.preon.annotation.BoundNumber;
import org.codehaus.preon.buffer.ByteOrder;
import swiftnav.sbp.SBP;



  
/** SBP class for message MSG_EPHEMERIS_OLD (0x001A).
 *
 * You can have MSG_EPHEMERIS_OLD inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
  * Deprecated, use MSG_EPHEMERIS (0x0046). */
public class MsgEphemerisOld extends SBP {

    public static final int TYPE = 0x001A;

    public MsgEphemerisOld() {
    }

    
    /** * Group delay differential between L1 and L2 */
    @BoundString()
    private double tgd;

    
    /** * Amplitude of the sine harmonic correction term to the orbit radius */
    @BoundString()
    private double c_rs;

    
    /** * Amplitude of the cosine harmonic correction term to the orbit radius */
    @BoundString()
    private double c_rc;

    
    /** * Amplitude of the cosine harmonic correction term to the argument of latitude */
    @BoundString()
    private double c_uc;

    
    /** * Amplitude of the sine harmonic correction term to the argument of latitude */
    @BoundString()
    private double c_us;

    
    /** * Amplitude of the cosine harmonic correction term to the angle of inclination */
    @BoundString()
    private double c_ic;

    
    /** * Amplitude of the sine harmonic correction term to the angle of inclination */
    @BoundString()
    private double c_is;

    
    /** * Mean motion difference */
    @BoundString()
    private double dn;

    
    /** * Mean anomaly at reference time */
    @BoundString()
    private double m0;

    
    /** * Eccentricity of satellite orbit */
    @BoundString()
    private double ecc;

    
    /** * Square root of the semi-major axis of orbit */
    @BoundString()
    private double sqrta;

    
    /** * Longitude of ascending node of orbit plane at weekly epoch */
    @BoundString()
    private double omega0;

    
    /** * Rate of right ascension */
    @BoundString()
    private double omegadot;

    
    /** * Argument of perigee */
    @BoundString()
    private double w;

    
    /** * Inclination */
    @BoundString()
    private double inc;

    
    /** * Inclination first derivative */
    @BoundString()
    private double inc_dot;

    
    /** * Polynomial clock correction coefficient (clock bias) */
    @BoundString()
    private double af0;

    
    /** * Polynomial clock correction coefficient (clock drift) */
    @BoundString()
    private double af1;

    
    /** * Polynomial clock correction coefficient (rate of clock drift) */
    @BoundString()
    private double af2;

    
    /** * Time of week */
    @BoundString()
    private double toe_tow;

    
    /** * Week number */
    @BoundString()
    private int toe_wn;

    
    /** * Clock reference time of week */
    @BoundString()
    private double toc_tow;

    
    /** * Clock reference week number */
    @BoundString()
    private int toc_wn;

    
    /** * Is valid? */
    @BoundString()
    private int valid;

    
    /** * Satellite is healthy? */
    @BoundString()
    private int healthy;

    
    /** * PRN being tracked */
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