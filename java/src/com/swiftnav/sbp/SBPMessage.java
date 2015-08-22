/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Gareth McMullin <gareth@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
package com.swiftnav.sbp;

import org.json.JSONObject;

import java.io.UnsupportedEncodingException;
import java.lang.reflect.Array;
import java.nio.BufferUnderflowException;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.util.LinkedList;

/** Superclass of all SBP messages. */
public class SBPMessage {
    public static final int SENDER_HOST = 0x42;
    public static final int MAX_PAYLOAD_SIZE = 255;

    public final int sender;
    public final int type;
    private byte[] payload;

    protected SBPMessage(SBPMessage msg) throws SBPBinaryException {
        sender = msg.sender;
        type = msg.type;
        Parser parser = new Parser(msg.payload);
        try {
            parse(parser);
        } catch (BufferUnderflowException e) {
            throw new SBPBinaryException("Payload too short");
        }

        if (parser.remaining() > 0) {
            throw new SBPBinaryException("Trailing bytes at end of payload");
        }
    }

    /** There is no reason to instantiate this class directly.  This
     * constructor is used by SBPHandler. */
    public SBPMessage(int sender_, int type_, byte[] payload_) {
        sender = sender_;
        type = type_;
        payload = payload_;
    }

    protected SBPMessage(int type_, byte[] payload_) {
        this(SENDER_HOST, type_, payload_);
    }

    protected SBPMessage(int sender_, int type_) {
        this(sender_, type_, null);
    }

    protected SBPMessage(int type_) {
        this(type_, null);
    }

    /** Build the message to binary and return the payload.*/
    final public byte[] getPayload() {
        if (payload != null)
            return payload;

        Builder builder = new Builder();
        build(builder);
        return builder.getPayload();
    }

    public JSONObject toJSON() {
        JSONObject json = new JSONObject();
        json.put("sender", sender);
        json.put("msg_type", type);
        return json;
    }

    protected void parse(Parser parser) throws SBPBinaryException {
        assert false : "Subclass must override parse()";
    }
    protected void build(Builder builder) {
        assert false : "Subclass must override build()";
    }

    /** There is no exposed access to this class outside of libsbp. */
    public class Parser {
        private ByteBuffer buf;

        private Parser(byte[] payload) {
            buf = ByteBuffer.wrap(payload).order(ByteOrder.LITTLE_ENDIAN);
        }

        public int getU8() {
            return buf.get() & 0xff;
        }
        public int getU16() {
            return buf.getShort() & 0xffff;
        }
        public long getU32() {
            return buf.getInt() & 0xffffffffl;
        }
        public int getS32() {
            return buf.getInt();
        }
        public float getFloat() {
            return buf.getFloat();
        }
        public double getDouble() {
            return buf.getDouble();
        }

        public String getString() throws SBPBinaryException {
            return getString(buf.remaining());
        }
        public String getString(int n) throws SBPBinaryException {
            byte[] tmp = new byte[n];
            buf.get(tmp);
            try {
                return new String(tmp, "UTF-8");
            } catch (UnsupportedEncodingException e) {
                throw new SBPBinaryException("Failed to decode UTF-8 string");
            }
        }

        public int[] getArrayofU8() {
            return getArrayofU8(buf.remaining());
        }
        public int[] getArrayofU8(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++)
                ret[i] = getU8();
            return ret;
        }

        public double[] getArrayofDouble(int n) {
            double [] ret = new double[n];
            for (int i = 0; i < n; i++)
                ret[i] = getDouble();
            return ret;
        }

        public <T extends SBPStruct> T[] getArray(Class<T> t) {
            LinkedList<T> l = new LinkedList<>();
            while (true) {
                try {
                    T tmp = t.newInstance();
                    tmp.parse(this);
                    l.add(tmp);
                } catch (BufferUnderflowException e) {
                    return (T[])l.toArray((T[])Array.newInstance(t, l.size()));
                } catch (Exception e) {
                    e.printStackTrace();
                    return null;
                }
            }
        }

        public <T extends SBPStruct> T[] getArray(Class<T> t, int n) {
            T[] ret = (T[]) Array.newInstance(t, n);
            for (int i = 0; i < n; i++) {
                try {
                    ret[i] = t.newInstance();
                    ret[i].parse(this);
                } catch (Exception e) {
                    e.printStackTrace();
                    return null;
                }
            }
            return ret;
        }
        public int remaining() {
            return buf.remaining();
        }
    }

    /** There is no exposed access to this class outside of libsbp. */
    public class Builder {
        private ByteBuffer buf;
        private Builder() {
            buf = ByteBuffer.allocate(MAX_PAYLOAD_SIZE)
                    .order(ByteOrder.LITTLE_ENDIAN);
        }

        private byte[] getPayload() {
            byte[] payload = new byte[buf.position()];
            buf.get(payload, 0, buf.position());
            return payload;
        }

        public void putU8(int x) {
            buf.put((byte) x);
        }
        public void putU16(int x) {
            buf.putShort((short) x);
        }
        public void putU32(long x) {
            buf.putInt((int) x);
        }
        public void putS32(int x) {
            buf.putInt(x);
        }
        public void putFloat(float x) {
            buf.putFloat(x);
        }
        public void putDouble(double x) {
            buf.putDouble(x);
        }
        public void putString(String s) {
            buf.put(s.getBytes());
        }
        public void putString(String s, int n) {
            assert s.getBytes().length == n;
            putString(s);
        }

        public void putArrayofU8(int[] data) {
            for (int x : data)
                buf.put((byte)x);
        }
        public void putArrayofU8(int[] data, int n) {
            assert(n == data.length);
            putArrayofU8(data);
        }

        public void putArrayofDouble(double[] data) {
            for (double x: data)
                putDouble(x);
        }
        public void putArrayofDouble(double[] data, int n) {
            assert(n == data.length);
            putArrayofDouble(data);
        }

        public <T extends SBPStruct> void putArray(T[] structs) {
            for (SBPStruct s : structs) {
                s.build(this);
            }
        }

        public <T extends SBPStruct> void putArray(T[] structs, int n) {
            assert(n != structs.length);
            putArray(structs);
        }
    }
}

