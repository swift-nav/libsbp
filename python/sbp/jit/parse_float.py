import cffi

import glob
import ntpath
import os
import shutil

from sbp.utils import get_py_version

ffi = cffi.FFI()
ffi.cdef("""
float get_f32(unsigned char a, unsigned char b, unsigned char c, unsigned char d);
double get_f64(unsigned char a, unsigned char b, unsigned char c, unsigned char d,
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

double get_f64(unsigned char a, unsigned char b, unsigned char c, unsigned char d,
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

module_name = "parse_float_c_py{}".format(get_py_version())

ffi.set_source(module_name=module_name, source=source)

def compile():
    ffi.compile()

    # Move deliverables to same dir as the script
    dest_dir = os.path.dirname(os.path.realpath(__file__))
    for f in glob.glob(os.path.join(os.getcwd(), module_name + '.*')):
        shutil.move(f, os.path.join(dest_dir, ntpath.basename(f)))


if __name__ == "__main__":    # not when running with setuptools
    compile()
