/* Copyright (C) 2015-2022 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
package com.swiftnav.sbp;


import java.lang.reflect.Array;
import java.math.BigInteger;
import java.nio.BufferUnderflowException;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.charset.StandardCharsets;
import java.util.Arrays;
import java.util.LinkedList;
import org.json.JSONObject;

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

    /**
     * There is no reason to instantiate this class directly. This constructor is used by
     * SBPHandler.
     */
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

    /** Build the message to binary and return the payload. */
    public final byte[] getPayload() {
        if (payload != null) return payload;

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

    public String getFriendlyName() {
        return "";
    }

    /** There is no exposed access to this class outside of libsbp. */
    @SuppressWarnings("unchecked")
    public class Parser {
        private ByteBuffer buf;

        private Parser(byte[] payload) {
            buf = ByteBuffer.wrap(payload).order(ByteOrder.LITTLE_ENDIAN);
        }

        public int getS8() {
            return buf.get();
        }

        public int getU8() {
            return buf.get() & 0xff;
        }

        public int getS16() {
            return buf.getShort();
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

        public BigInteger getU64() {
            byte[] tmp = new byte[8];
            buf.get(tmp, 0, 8);
            tmp = new byte[] {tmp[7], tmp[6], tmp[5], tmp[4], tmp[3], tmp[2], tmp[1], tmp[0]};
            return new BigInteger(1, tmp);
        }

        public float getFloat() {
            return buf.getFloat();
        }

        public double getDouble() {
            return buf.getDouble();
        }

        public String getString() {
            return getString(buf.remaining());
        }

        public String getString(int n) {
            byte[] tmp = new byte[n];
            buf.get(tmp);
            return new String(tmp, StandardCharsets.UTF_8);
        }

        public int[] getArrayofU8() {
            return getArrayofU8(buf.remaining());
        }

        public int[] getArrayofU8(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) ret[i] = getU8();
            return ret;
        }

        public int[] getArrayofS8() {
            return getArrayofS8(buf.remaining());
        }

        public int[] getArrayofS8(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) ret[i] = getS8();
            return ret;
        }

        public int[] getArrayofS16() {
            return getArrayofS16(buf.remaining() / 2);
        }

        public int[] getArrayofS16(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) ret[i] = getS16();
            return ret;
        }

        public int[] getArrayofU16() {
            return getArrayofU16(buf.remaining() / 2);
        }

        public int[] getArrayofU16(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) ret[i] = getU16();
            return ret;
        }

        public long[] getArrayofU32() {
            return getArrayofU32(buf.remaining() / 4);
        }

        public long[] getArrayofU32(int n) {
            long[] ret = new long[n];
            for (int i = 0; i < n; i++) ret[i] = getU32();
            return ret;
        }

        public int[] getArrayofS32() {
            return getArrayofS32(buf.remaining() / 4);
        }

        public int[] getArrayofS32(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) ret[i] = getS32();
            return ret;
        }

        public float[] getArrayofFloat() {
            return getArrayofFloat(buf.remaining() / Float.BYTES);
        }

        public float[] getArrayofFloat(int n) {
            float[] ret = new float[n];
            for (int i = 0; i < n; i++) ret[i] = getFloat();
            return ret;
        }

        public double[] getArrayofDouble() {
            return getArrayofDouble(buf.remaining() / Double.BYTES);
        }

        public double[] getArrayofDouble(int n) {
            double[] ret = new double[n];
            for (int i = 0; i < n; i++) ret[i] = getDouble();
            return ret;
        }

        public <T extends SBPStruct> T[] getArray(Class<T> t) {
            LinkedList<T> l = new LinkedList<T>();
            while (true) {
                try {
                    T tmp = t.getDeclaredConstructor().newInstance();
                    tmp.parse(this);
                    l.add(tmp);
                } catch (BufferUnderflowException e) {
                    return l.toArray((T[]) Array.newInstance(t, l.size()));
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
                    ret[i] = t.getDeclaredConstructor().newInstance();
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
            buf = ByteBuffer.allocate(MAX_PAYLOAD_SIZE).order(ByteOrder.LITTLE_ENDIAN);
        }

        private byte[] getPayload() {
            return Arrays.copyOf(buf.array(), buf.position());
        }

        public void putS8(int x) {
            buf.put((byte) x);
        }

        public void putU8(int x) {
            buf.put((byte) x);
        }

        public void putS16(int x) {
            buf.putShort((short) x);
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

        public void putU64(BigInteger x) {
            buf.putLong(x.longValue());
        }

        public void putS64(BigInteger x) {
            buf.putLong(x.longValue());
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
            for (int x : data) buf.put((byte) x);
        }

        public void putArrayofU8(int[] data, int n) {
            assert (n == data.length);
            putArrayofU8(data);
        }

        public void putArrayofS8(int[] data) {
            for (int x : data) buf.put((byte) x);
        }

        public void putArrayofS8(int[] data, int n) {
            assert (n == data.length);
            putArrayofS8(data);
        }

        public void putArrayofS16(int[] data) {
            for (int x : data) buf.putShort((short) x);
        }

        public void putArrayofS16(int[] data, int n) {
            assert (n == data.length);
            putArrayofS16(data);
        }

        public void putArrayofU16(int[] data) {
            for (int x : data) buf.putShort((short) x);
        }

        public void putArrayofU16(int[] data, int n) {
            assert (n == data.length);
            putArrayofU16(data);
        }

        public void putArrayofU32(long[] data) {
            for (long x : data) buf.putLong(x);
        }

        public void putArrayofU32(long[] data, int n) {
            assert (n == data.length);
            putArrayofU32(data);
        }

        public void putArrayofS32(int[] data) {
            for (int x : data) buf.putInt(x);
        }

        public void putArrayofS32(int[] data, int n) {
            assert (n == data.length);
            putArrayofS32(data);
        }

        public void putArrayofDouble(double[] data) {
            for (double x : data) putDouble(x);
        }

        public void putArrayofDouble(double[] data, int n) {
            assert (n == data.length);
            putArrayofDouble(data);
        }

        public void putArrayofFloat(float[] data) {
            for (float x : data) putFloat(x);
        }

        public void putArrayofFloat(float[] data, int n) {
            assert (n == data.length);
            putArrayofFloat(data);
        }

        public <T extends SBPStruct> void putArray(T[] structs) {
            for (SBPStruct s : structs) {
                s.build(this);
            }
        }

        public <T extends SBPStruct> void putArray(T[] structs, int n) {
            assert (n != structs.length);
            putArray(structs);
        }
    }
}
