import cffi

ffi = cffi.FFI()
ffi.cdef("""
float get_f32(unsigned char a, unsigned char b, unsigned char c, unsigned char d);
float get_f64(unsigned char a, unsigned char b, unsigned char c, unsigned char d,
	      unsigned char e, unsigned char f, unsigned char g, unsigned char h);
""")

source = """
float get_f32(unsigned char a, unsigned char b, unsigned char c, unsigned char d) {
    union { unsigned char buf[4]; float f; } u;
    u.buf[0] = a;
    u.buf[1] = b;
    u.buf[2] = c;
    u.buf[3] = d;
    return u.f;
}

float get_f64(unsigned char a, unsigned char b, unsigned char c, unsigned char d,
	      unsigned char e, unsigned char f, unsigned char g, unsigned char h) {
    union { unsigned char buf[8]; double d; } u;
    u.buf[0] = a;
    u.buf[1] = b;
    u.buf[2] = c;
    u.buf[3] = d;
    u.buf[4] = e;
    u.buf[5] = f;
    u.buf[6] = g;
    u.buf[7] = h;
    return u.d;
}
"""

ffi.set_source(module_name="parse_float_c", source=source)

ffi.compile()
