#include <gtest/gtest.h>
#include <libsbp/internal/v4/string/null_terminated.h>

TEST(TestNullTerminatedString, InitialState) {
  // The string buffer is zero'd out, it should still report as valid and have a packed length of 1
  sbp_string_t s;
  memset(&s, 0, sizeof(s));

  size_t short_params = 10;
  size_t long_params = 100;
  size_t max_params = 255;

  // Just to make sure that the internal length counter is set to a technically invalid state
  ASSERT_EQ(s.encoded_len, 0);

  EXPECT_FALSE(sbp_null_terminated_string_valid(&s, short_params));
  EXPECT_FALSE(sbp_null_terminated_string_valid(&s, long_params));
  EXPECT_FALSE(sbp_null_terminated_string_valid(&s, max_params));

  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, short_params), 1);
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, long_params), 1);
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, max_params), 1);

  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, short_params), 0);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, long_params), 0);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, max_params), 0);

  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, short_params), 9);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, long_params), 99);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, max_params), 254);

  EXPECT_EQ(sbp_null_terminated_string_get(&s, short_params), nullptr);
  EXPECT_EQ(sbp_null_terminated_string_get(&s, long_params), nullptr);
  EXPECT_EQ(sbp_null_terminated_string_get(&s, max_params), nullptr);
}

TEST(TestNullTerminatedString, InvalidState) {
  // Various states the could potentially occur where the string buffer is invalid. This includes cases where it contains more than the allowed packed size, or where the buffer doesn't contain a NULL terminator in the right place
  sbp_string_t s;
  memset(&s, 0, sizeof(s));

  size_t short_params = 10;
  size_t long_params = 100;
  size_t max_params = 255;

  // First case, contains a valid 11 byte string (10 characters, 1 NULL terminator) which is invalid according to the short parameters but valid according to both the others
  strcpy(s.data, "aaaaaaaaaa");
  s.encoded_len = 11;

  EXPECT_FALSE(sbp_null_terminated_string_valid(&s, short_params));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, long_params));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, max_params));

  // In this case the short maxlen should force a packed size of 1 whereas the others with both be the full string
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, short_params), 1);
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, long_params), 11);
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, max_params), 11);

  // Likewise, the space remaining should be the full buffer for short maxlen and the correct value for the others
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, short_params), 9);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, long_params), 89);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, max_params), 244);

  // We shouldn't be able to retrieve the string when using the invalid parameters
  EXPECT_EQ(sbp_null_terminated_string_get(&s, short_params), nullptr);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, long_params), "aaaaaaaaaa");
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, max_params), "aaaaaaaaaa");

  // Next we set the len field incorrectly, it should always point to a NULL terminator but in case it doesn't then everything will become invalid even when it ends up being less than the max packed length
  s.encoded_len = 10; // Points to the final 'a'
  EXPECT_FALSE(sbp_null_terminated_string_valid(&s, short_params));
  EXPECT_FALSE(sbp_null_terminated_string_valid(&s, long_params));
  EXPECT_FALSE(sbp_null_terminated_string_valid(&s, max_params));

  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, short_params), 1);
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, long_params), 1);
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, max_params), 1);

  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, short_params), 0);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, long_params), 0);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, max_params), 0);

  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, short_params), 9);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, long_params), 99);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, max_params), 254);

  EXPECT_EQ(sbp_null_terminated_string_get(&s, short_params), nullptr);
  EXPECT_EQ(sbp_null_terminated_string_get(&s, long_params), nullptr);
  EXPECT_EQ(sbp_null_terminated_string_get(&s, max_params), nullptr);
}

TEST(TestNullTerminatedString, Init) {
  // Test the init function. It should be able to reset everything no matter what state it's in
  sbp_string_t s;

  size_t maxlen = 10;

  sbp_null_terminated_string_init(&s);
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 1);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 0);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 9);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "");
  EXPECT_EQ(s.encoded_len, 1);

  // Put in a valid string
  strcpy(s.data, "abcd");
  s.encoded_len = 5;

  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 5);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 4);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 5);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "abcd");

  // And reinitialise
  sbp_null_terminated_string_init(&s);
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 1);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 0);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 9);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "");
  EXPECT_EQ(s.encoded_len, 1);

  // Put in an invalid string
  strcpy(s.data, "aaaaaaaaaa");
  s.encoded_len = 11;

  EXPECT_FALSE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 1);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 0);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 9);
  EXPECT_EQ(sbp_null_terminated_string_get(&s, maxlen), nullptr);
  EXPECT_EQ(s.encoded_len, 11);

  // And reinitialise
  sbp_null_terminated_string_init(&s);
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 1);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 0);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 9);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "");
  EXPECT_EQ(s.encoded_len, 1);
}

TEST(TestNullTerminatedString, SetNotTruncating)
{
  // A variety of cases for the set function
  sbp_string_t s;

  size_t maxlen = 20;
  size_t n_written;

  sbp_null_terminated_string_init(&s);

  // Put in a valid string
  const char str[] = "Hello, World!";
  EXPECT_TRUE(sbp_null_terminated_string_set(&s, maxlen, false, &n_written, str));
  EXPECT_EQ(n_written, strlen(str));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 14);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 6);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 13);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "Hello, World!");

  // Overwrite with another valid string
  const char str2[] = "Goodbye, World!";
  EXPECT_TRUE(sbp_null_terminated_string_set(&s, maxlen, false, &n_written, str2));
  EXPECT_EQ(n_written, strlen(str2));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 16);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 4);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 15);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "Goodbye, World!");

  // Try to overwrite with an invalid string, it should fail and leave the original string intact
  const char str3[] = "A string which is far too long for the buffer";
  EXPECT_EQ(sbp_null_terminated_string_set(&s, maxlen, false, &n_written, str3), 0);
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 16);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 4);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 15);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "Goodbye, World!");

  // Setting an invalid buffer clears everything
  strcpy(s.data, "A string which is longer than the max packed len");
  s.encoded_len = 49;
  EXPECT_FALSE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 1);
  EXPECT_EQ(sbp_null_terminated_string_get(&s, maxlen), nullptr);
  EXPECT_TRUE(sbp_null_terminated_string_set(&s, maxlen, false, &n_written, str));
  EXPECT_EQ(n_written, strlen(str));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 14);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 6);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 13);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "Hello, World!");
}

TEST(TestNullTerminatedString, SetTruncating)
{
  // A variety of cases for the set function
  sbp_string_t s;

  size_t maxlen = 20;
  size_t n_written;

  sbp_null_terminated_string_init(&s);

  // Put in a valid string
  const char str[] = "Hello, World!";
  EXPECT_TRUE(sbp_null_terminated_string_set(&s, maxlen, true, &n_written, str));
  EXPECT_EQ(n_written, strlen(str));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 14);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 6);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 13);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "Hello, World!");

  // Overwrite with another valid string
  const char str2[] = "Goodbye, World!";
  EXPECT_TRUE(sbp_null_terminated_string_set(&s, maxlen, true, &n_written, str2));
  EXPECT_EQ(n_written, strlen(str2));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 16);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 4);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 15);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "Goodbye, World!");

  // Try to overwrite with an invalid string, it should fail and leave the original string intact
  const char str3[] = "A string which is far too long for the buffer";
  EXPECT_TRUE(sbp_null_terminated_string_set(&s, maxlen, true, &n_written, str3));
  EXPECT_EQ(n_written, 19);
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 20);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 0);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 19);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "A string which is f");

  // Setting an invalid buffer clears everything
  strcpy(s.data, "A string which is longer than the max packed len");
  s.encoded_len = 49;
  EXPECT_FALSE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 1);
  EXPECT_EQ(sbp_null_terminated_string_get(&s, maxlen), nullptr);
  EXPECT_TRUE(sbp_null_terminated_string_set(&s, maxlen, true, &n_written, str));
  EXPECT_EQ(n_written, strlen(str));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 14);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 6);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 13);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "Hello, World!");
}

TEST(TestNullTerminatedString, SetRawTruncating)
{
  // A variety of cases for the set function
  sbp_string_t s;

  size_t maxlen = 20;
  size_t n_written;

  sbp_null_terminated_string_init(&s);

  char non_terminated[] = {'H', 'E', 'L', 'L', 'O'};

  // Put in a valid string that fits with space remaining
  EXPECT_TRUE(sbp_null_terminated_string_set_raw(&s, maxlen, true, &n_written, non_terminated, 5));
  EXPECT_EQ(n_written, 5);
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 6);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 14);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 5);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "HELLO");

  maxlen = 3;
  // Put in a valid string that doesn't fit and will be truncated
  EXPECT_TRUE(sbp_null_terminated_string_set_raw(&s, maxlen, true, &n_written, non_terminated, 5));
  EXPECT_EQ(n_written, 2);
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 3);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 0);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 2);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "HE");

  maxlen = 6;
  // Put in a valid string that fits exactly
  EXPECT_TRUE(sbp_null_terminated_string_set_raw(&s, maxlen, true, &n_written, non_terminated, 5));
  EXPECT_EQ(n_written, 5);
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 6);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 0);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 5);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "HELLO");
}

TEST(TestNullTerminatedString, SetRawNotTruncating)
{
  sbp_string_t s;

  size_t maxlen = 20;
  size_t n_written;

  sbp_null_terminated_string_init(&s);

  char non_terminated[] = {'H', 'E', 'L', 'L', 'O'};

  // Put in a valid string that fits with space remaining
  EXPECT_TRUE(sbp_null_terminated_string_set_raw(&s, maxlen, false, &n_written, non_terminated, 5));
  EXPECT_EQ(n_written, 5);
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 6);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 14);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 5);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "HELLO");

  // Put in a valid string that doesn't fit
  const char str3[] = "A string which is far too long for the buffer";
  EXPECT_FALSE(sbp_null_terminated_string_set_raw(&s, maxlen, false, &n_written, str3, strlen(str3)));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 6);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 14);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 5);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "HELLO");

  // Put in a valid string that fits exactly
  char non_terminated3[] = "ABCDEFGHIJKLMNOPQRS";
  EXPECT_TRUE(sbp_null_terminated_string_set_raw(&s, maxlen, false, &n_written, non_terminated3, 19));
  EXPECT_EQ(n_written, 19);
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 20);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 0);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 19);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "ABCDEFGHIJKLMNOPQRS");
}

TEST(TestNullTerminatedString, Printf)
{
  // Some test cases for the printf function

  sbp_string_t s;

  size_t maxlen = 20;
  size_t n_written;

  sbp_null_terminated_string_init(&s);

  auto vprintf_wrapper = [&s, &n_written, maxlen](const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    size_t ret = sbp_null_terminated_string_vprintf(&s, maxlen, false, &n_written, fmt, ap);
    va_end(ap);
    return ret;
  };

  // A valid string
  EXPECT_TRUE(vprintf_wrapper("%s", "Hello, World!"));
  EXPECT_EQ(n_written, 13);
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 14);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 6);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 13);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "Hello, World!");

  // Overwrite with another valid string
  EXPECT_TRUE(vprintf_wrapper("%d %d %d %d", 1, 2, 3, 4));
  EXPECT_EQ(n_written, 7);
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 8);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 12);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 7);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "1 2 3 4");

  // Overwrite with something which would be too long, expect no change
  EXPECT_FALSE(vprintf_wrapper("%d %d %d %d %d %d %d %d %d %d", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 8);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 12);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 7);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "1 2 3 4");

  // Printing in to an invalid buffer clears everything
  EXPECT_TRUE(vprintf_wrapper("%s", "Hello, World!"));
  EXPECT_EQ(n_written, 13);
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 14);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 6);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 13);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "Hello, World!");
}

TEST(TestNullTerminatedString, PrintfTruncating)
{
  // Some test cases for the printf function

  sbp_string_t s;

  size_t maxlen = 20;
  size_t n_written;

  sbp_null_terminated_string_init(&s);

  auto vprintf_wrapper = [&s, &n_written, maxlen](const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    size_t ret = sbp_null_terminated_string_vprintf(&s, maxlen, true, &n_written, fmt, ap);
    va_end(ap);
    return ret;
  };

  // A valid string
  EXPECT_TRUE(vprintf_wrapper("%s", "Hello, World!"));
  EXPECT_EQ(n_written, 13);
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 14);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 6);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 13);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "Hello, World!");

  // Overwrite with another valid string
  EXPECT_TRUE(vprintf_wrapper("%d %d %d %d", 1, 2, 3, 4));
  EXPECT_EQ(n_written, 7);
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 8);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 12);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 7);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "1 2 3 4");

  // Overwrite with something which would be too long, expect truncation
  EXPECT_TRUE(vprintf_wrapper("%d %d %d %d %d %d %d %d %d %d", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
  EXPECT_EQ(n_written, 19);
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 20);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 0);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 19);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "1 2 3 4 5 6 7 8 9 1");

  // Overwrite with something which would be too long, expect truncation
  EXPECT_TRUE(vprintf_wrapper("%d %d %d %d %d %d %d %d %d %d", 1, 2, 3, 4, 5, 6, 7, 8, 9, 100000));
  EXPECT_EQ(n_written, 19);
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 20);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 0);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 19);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "1 2 3 4 5 6 7 8 9 1");

  // Printing in to an invalid buffer clears everything
  EXPECT_TRUE(vprintf_wrapper("%s", "Hello, World!"));
  EXPECT_EQ(n_written, 13);
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 14);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 6);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 13);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "Hello, World!");
}

TEST(TestNullTerminatedString, Append)
{
  // Some cases for appending a string to a buffer
  sbp_string_t s;

  size_t maxlen = 20;

  sbp_null_terminated_string_init(&s);

  // Appending in to an empty buffer is a valid operation, essentially the same as calling set
  EXPECT_TRUE(sbp_null_terminated_string_append(&s, maxlen, "Hello"));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 6);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 14);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 5);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "Hello");

  // Similarly, appending to an uninitialised buffer will initialise it
  memset(&s, 0, sizeof(s));
  EXPECT_TRUE(sbp_null_terminated_string_append(&s, maxlen, "Hello"));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 6);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 14);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 5);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "Hello");

  // Appending a valid string
  EXPECT_TRUE(sbp_null_terminated_string_append(&s, maxlen, ", World!"));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 14);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 6);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 13);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "Hello, World!");

  // But it isn't allowed to overrun
  EXPECT_FALSE(sbp_null_terminated_string_append(&s, maxlen, "1234567"));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 14);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 6);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 13);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "Hello, World!");
}

TEST(TestNullTerminatedString, AppendPrintf)
{
  // Some cases for appending a formatted string to a buffer
  sbp_string_t s;

  size_t maxlen = 20;
  size_t n_written;

  sbp_null_terminated_string_init(&s);

  auto vprintf_wrapper = [&s, &n_written, maxlen](const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    size_t ret = sbp_null_terminated_string_append_vprintf(&s, maxlen, false, &n_written, fmt, ap);
    va_end(ap);
    return ret;
  };

  // Appending in to an empty buffer is a valid operation, essentially the same as calling set
  EXPECT_TRUE(vprintf_wrapper("%d %d", 1, 2));
  EXPECT_EQ(n_written, 3);
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 4);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 16);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 3);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "1 2");

  // Similarly, appending to an uninitialised buffer will initialise it
  memset(&s, 0, sizeof(s));
  EXPECT_TRUE(vprintf_wrapper("%d %d", 1, 2));
  EXPECT_EQ(n_written, 3);
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 4);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 16);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 3);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "1 2");

  // Appending a valid string
  EXPECT_TRUE(vprintf_wrapper(" %d %d", 3, 4));
  EXPECT_EQ(n_written, 4);
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 8);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 12);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 7);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "1 2 3 4");

  // Up to the maximum
  EXPECT_TRUE(vprintf_wrapper(" %d %d %d %d %d %x", 5, 6, 7, 8, 9, 10));
  EXPECT_EQ(n_written, 12);
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 20);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 0);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 19);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "1 2 3 4 5 6 7 8 9 a");

  // But isn't allowed to overrun
  // Wind back a little bit
  s.encoded_len = 8;
  s.data[7] = 0;
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 8);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 12);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 7);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "1 2 3 4");

  EXPECT_FALSE(vprintf_wrapper(" %d %d %d %d %d %d", 5, 6, 7, 8, 9, 10));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 8);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 12);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 7);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "1 2 3 4");
}

TEST(TestNullTerminatedString, AppendPrintfTruncating)
{
  // Some cases for appending a formatted string to a buffer
  sbp_string_t s;

  size_t maxlen = 20;
  size_t n_written;

  sbp_null_terminated_string_init(&s);

  auto vprintf_wrapper = [&s, &n_written, maxlen](const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    size_t ret = sbp_null_terminated_string_append_vprintf(&s, maxlen, true, &n_written, fmt, ap);
    va_end(ap);
    return ret;
  };

  // Appending in to an empty buffer is a valid operation, essentially the same as calling set
  EXPECT_TRUE(vprintf_wrapper("%d %d", 1, 2));
  EXPECT_EQ(n_written, 3);
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 4);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 16);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 3);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "1 2");

  // Similarly, appending to an uninitialised buffer will initialise it
  memset(&s, 0, sizeof(s));
  EXPECT_TRUE(vprintf_wrapper("%d %d", 1, 2));
  EXPECT_EQ(n_written, 3);
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 4);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 16);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 3);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "1 2");

  // Appending a valid string
  EXPECT_TRUE(vprintf_wrapper(" %d %d", 3, 4));
  EXPECT_EQ(n_written, 4);
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 8);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 12);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 7);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "1 2 3 4");

  // Up to the maximum, should truncate
  EXPECT_TRUE(vprintf_wrapper(" %d %d %d %d %d %d", 5, 6, 7, 8, 9, 10));
  EXPECT_EQ(n_written, 12);
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 20);
  EXPECT_EQ(sbp_null_terminated_string_space_remaining(&s, maxlen), 0);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 19);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "1 2 3 4 5 6 7 8 9 1");
}

TEST(TestNullTerminatedString, Pack)
{
  sbp_string_t s;
  size_t short_params = 10;
  size_t long_params = 20;
  size_t n_written;

  uint8_t payload[30];
  sbp_encode_ctx_t ctx;
  ctx.buf = payload;
  ctx.buf_len = 30;
  ctx.offset = 0;

  // Pack an uninitialised string buffer
  memset(&s, 0, sizeof(s));
  memset(payload, 0xCC, sizeof(payload));
  ctx.offset = 0;
  ctx.buf_len = 30;

  EXPECT_FALSE(sbp_null_terminated_string_valid(&s, short_params));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, short_params), 1);
  EXPECT_TRUE(sbp_null_terminated_string_encode(&s, short_params, &ctx));
  EXPECT_EQ(ctx.offset, 1);
  EXPECT_EQ(payload[0], 0); // Should have written a single NULL in to the payload
  for (uint8_t i = 1; i < 30; i++) EXPECT_EQ(payload[i], 0xCC); // And nothing else modified

  // Pack an initialised and empty string
  memset(payload, 0xCC, sizeof(payload));
  ctx.offset = 0;
  ctx.buf_len = 30;

  sbp_null_terminated_string_init(&s);
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, short_params));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, short_params), 1);
  EXPECT_TRUE(sbp_null_terminated_string_encode(&s, short_params, &ctx));
  EXPECT_EQ(ctx.offset, 1);
  EXPECT_EQ(payload[0], 0); // Should have written a single NULL in to the payload
  for (uint8_t i = 1; i < 30; i++) EXPECT_EQ(payload[i], 0xCC); // And nothing else modified

  // Pack a string which is less than the remaining payload size
  memset(payload, 0xCC, sizeof(payload));
  ctx.offset = 0;
  ctx.buf_len = 30;

  const char str[] = "Hello, World!";
  EXPECT_TRUE(sbp_null_terminated_string_set(&s, long_params, false, &n_written, str));
  EXPECT_EQ(n_written, strlen(str));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, long_params));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, long_params), 14);
  EXPECT_TRUE(sbp_null_terminated_string_encode(&s, long_params, &ctx));
  EXPECT_EQ(ctx.offset, 14);
  EXPECT_EQ(memcmp(payload, "Hello, World!", 14), 0);
  for (uint8_t i = 14; i < 30; i++) EXPECT_EQ(payload[i], 0xCC);

  // Pack a maximal sized string which is less than the remaining payload size
  memset(payload, 0xCC, sizeof(payload));
  ctx.offset = 0;
  ctx.buf_len = 30;

  const char str2[] = "Hello, World!!!!!!!";
  EXPECT_TRUE(sbp_null_terminated_string_set(&s, long_params, false, &n_written, str2));
  EXPECT_EQ(n_written, strlen(str2));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, long_params));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, long_params), 20);
  EXPECT_TRUE(sbp_null_terminated_string_encode(&s, long_params, &ctx));
  EXPECT_EQ(ctx.offset, 20);
  EXPECT_EQ(memcmp(payload, "Hello, World!!!!!!!", 20), 0);
  for (uint8_t i = 20; i < 30; i++) EXPECT_EQ(payload[i], 0xCC);

  // Pack a string which is exactly as long as the payload buffer
  memset(payload, 0xCC, sizeof(payload));
  ctx.offset = 0;
  ctx.buf_len = 14;

  EXPECT_TRUE(sbp_null_terminated_string_set(&s, long_params, false, &n_written, str));
  EXPECT_EQ(n_written, strlen(str));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, long_params));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, long_params), 14);
  EXPECT_TRUE(sbp_null_terminated_string_encode(&s, long_params, &ctx));
  EXPECT_EQ(ctx.offset, 14);
  EXPECT_EQ(memcmp(payload, "Hello, World!", 14), 0);
  for (uint8_t i = 14; i < 30; i++) EXPECT_EQ(payload[i], 0xCC);

  // Pack a string which overruns the available space in the payload buffer
  memset(payload, 0xCC, sizeof(payload));
  ctx.offset = 0;
  ctx.buf_len = 10;

  EXPECT_TRUE(sbp_null_terminated_string_set(&s, long_params, false, &n_written, str));
  EXPECT_EQ(n_written, strlen(str));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, long_params));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, long_params), 14);
  EXPECT_FALSE(sbp_null_terminated_string_encode(&s, long_params, &ctx));
  EXPECT_EQ(ctx.offset, 0);
  for (uint8_t i = 0; i < 30; i++) EXPECT_EQ(payload[i], 0xCC);

  // Pack a string at an offset in to the payload buffer
  memset(payload, 0xCC, sizeof(payload));
  memset(payload + 20, 0xDD, 10);
  ctx.offset = 10;
  ctx.buf_len = 30;

  EXPECT_TRUE(sbp_null_terminated_string_set(&s, long_params, false, &n_written, str));
  EXPECT_EQ(n_written, strlen(str));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, long_params));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, long_params), 14);
  EXPECT_TRUE(sbp_null_terminated_string_encode(&s, long_params, &ctx));
  EXPECT_EQ(ctx.offset, 24);
  for (uint8_t i = 0; i < 10; i++) EXPECT_EQ(payload[i], 0xCC);
  EXPECT_EQ(memcmp(payload + 10, "Hello, World!", 14), 0);
  for (uint8_t i = 24; i < 30; i++) EXPECT_EQ(payload[i], 0xDD);
}

TEST(TestNullTerminatedString, Unpack)
{
  sbp_string_t s;
  size_t maxlen = 5;
  size_t n_written;

  uint8_t payload[10];
  sbp_decode_ctx_t ctx;
  ctx.buf = payload;

  // Pack in to an uninitialised buffer
  memset(&s, 0, sizeof(s));
  memcpy(payload, "abcd\0", 5);
  ctx.buf_len = 5;
  ctx.offset = 0;
  EXPECT_FALSE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_TRUE(sbp_null_terminated_string_decode(&s, maxlen, &ctx));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 5);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 4);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "abcd");
  EXPECT_EQ(ctx.offset, 5);

  // Pack in to an initialised but empty buffer
  memcpy(payload, "abcd\0", 5);
  ctx.buf_len = 5;
  ctx.offset = 0;
  sbp_null_terminated_string_init(&s);
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_TRUE(sbp_null_terminated_string_decode(&s, maxlen, &ctx));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 5);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 4);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "abcd");
  EXPECT_EQ(ctx.offset, 5);

  // Overwrite a previously valid string
  memcpy(payload, "abcd\0", 5);
  ctx.buf_len = 5;
  ctx.offset = 0;
  const char str[] = "zzzz";
  EXPECT_TRUE(sbp_null_terminated_string_set(&s, maxlen, false, &n_written, str));
  EXPECT_EQ(n_written, strlen(str));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_TRUE(sbp_null_terminated_string_decode(&s, maxlen, &ctx));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 5);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 4);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "abcd");
  EXPECT_EQ(ctx.offset, 5);

  // Unpack a string when there is more data in the payload buffer
  memcpy(payload, "abcd\0more", 9);
  ctx.buf_len = 9;
  ctx.offset = 0;
  EXPECT_TRUE(sbp_null_terminated_string_set(&s, maxlen, false, &n_written, str));
  EXPECT_EQ(n_written, strlen(str));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_TRUE(sbp_null_terminated_string_decode(&s, maxlen, &ctx));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 5);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 4);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "abcd");
  EXPECT_EQ(ctx.offset, 5);

  // Unpack a short string
  memcpy(payload, "ab\0", 3);
  ctx.buf_len = 3;
  ctx.offset = 0;
  EXPECT_TRUE(sbp_null_terminated_string_set(&s, maxlen, false, &n_written, str));
  EXPECT_EQ(n_written, strlen(str));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_TRUE(sbp_null_terminated_string_decode(&s, maxlen, &ctx));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 3);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 2);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "ab");
  EXPECT_EQ(ctx.offset, 3);

  // Unpack a payload without a NULL terminator
  memcpy(payload, "abc", 3);
  ctx.buf_len = 3;
  ctx.offset = 0;
  EXPECT_TRUE(sbp_null_terminated_string_set(&s, maxlen, false, &n_written, str));
  EXPECT_EQ(n_written, strlen(str));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_TRUE(sbp_null_terminated_string_decode(&s, maxlen, &ctx));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 4);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 3);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "abc");
  EXPECT_EQ(ctx.offset, 3);

  // Fail to unpack a string where no NULL terminator is found and there is more data in the buffer
  memcpy(payload, "abcdefghi", 10);
  ctx.buf_len = 10;
  ctx.offset = 0;
  EXPECT_TRUE(sbp_null_terminated_string_set(&s, maxlen, false, &n_written, str));
  EXPECT_EQ(n_written, strlen(str));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_FALSE(sbp_null_terminated_string_decode(&s, maxlen, &ctx));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 1);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 0);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "");
  EXPECT_EQ(ctx.offset, 0); // No data consumed

  // Unpack from an offset in the payload buffer
  memcpy(payload, "abcdefg\0i", 10);
  ctx.buf_len = 10;
  ctx.offset = 4;
  EXPECT_TRUE(sbp_null_terminated_string_set(&s, maxlen, false, &n_written, str));
  EXPECT_EQ(n_written, strlen(str));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_TRUE(sbp_null_terminated_string_decode(&s, maxlen, &ctx));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_null_terminated_string_encoded_len(&s, maxlen), 4);
  EXPECT_EQ(sbp_null_terminated_string_strlen(&s, maxlen), 3);
  EXPECT_STREQ(sbp_null_terminated_string_get(&s, maxlen), "efg");
  EXPECT_EQ(ctx.offset, 8);
}
