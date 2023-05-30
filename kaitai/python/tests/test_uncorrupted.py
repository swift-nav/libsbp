from kaitai.python.tests.utils import compare_parsers

# Confirm that all parsers produce the same output with uncorrupted input
def test_uncorrupted():
    num_messages = compare_parsers("test_data/benchmark.sbp")
    print("Uncorrupted test: success, {} messages".format(num_messages))
    assert(num_messages == 150000)
