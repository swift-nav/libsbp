import base64
import sys

PY2 = sys.version_info[0] == 2

if not PY2:
    def base64_encode(x):
        return base64.standard_b64encode(x).decode()
else:
    base64_encode = base64.standard_b64encode

