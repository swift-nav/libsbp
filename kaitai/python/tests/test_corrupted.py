from kaitai.python.tests.utils import compare_parsers
import os
import random
import tempfile

# Confirm that all parsers produce the same output with corrupted input
def test_corrupted():
    # create corrupted file
    fd_corrupted, filename_corrupted = tempfile.mkstemp()
    random.seed()
    with os.fdopen(fd_corrupted, 'wb') as fp_corrupted:
        with open("test_data/benchmark.sbp", 'rb') as fp_orig:
            while True:
                # read random amount
                buf = fp_orig.read(random.randrange(8192)) # NOSONAR
                if buf is None or len(buf) == 0:
                    break
                fp_corrupted.write(buf)
                if random.random() < 0.5: # NOSONAR
                    # drop bytes
                    fp_orig.read(random.randrange(3)) # NOSONAR
                else:
                    # write garbage
                    fp_corrupted.write(bytes(chr(random.randrange(127)), encoding='ascii')) # NOSONAR

    num_messages = compare_parsers(filename_corrupted)
    print("Corrupted test: success, {} messages".format(num_messages))
    assert(num_messages <= 150000)
    os.unlink(filename_corrupted)
