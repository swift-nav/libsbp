import base64
import sys

PY2 = sys.version_info[0] == 2

_identity = lambda x: x

if not PY2:
    string_types = str,

    def base64_encode(x):
        return base64.standard_b64encode(x).decode()

    def to_bytes(s):
        return s.encode()

    def to_str(b):
        return b.decode()
else:
    string_types = basestring,
    base64_encode = base64.standard_b64encode

    to_bytes = _identity
    to_str = _identity

