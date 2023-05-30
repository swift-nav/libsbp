import timeit
from kaitai.python.tests.utils import get_next_msg_construct, get_next_msg_ksy, get_next_msg_hybrid1, get_next_msg_hybrid2

FILENAME = "test_data/benchmark.sbp"
COUNT = 1

# Compare speeds of different parsers
def test_benchmarks():
    print("construct: {}".format(timeit.timeit('[x for x in get_next_msg_construct(FILENAME)]', number=COUNT, globals=globals())))
    print("ksy: {}".format(timeit.timeit('[x for x in get_next_msg_ksy(FILENAME)]', number=COUNT, globals=globals())))
    print("hybrid1: {}".format(timeit.timeit('[x for x in get_next_msg_hybrid1(FILENAME)]', number=COUNT, globals=globals())))
    print("hybrid2: {}".format(timeit.timeit('[x for x in get_next_msg_hybrid2(FILENAME)]', number=COUNT, globals=globals())))
