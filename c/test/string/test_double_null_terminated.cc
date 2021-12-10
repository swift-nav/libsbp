#include <gtest/gtest.h>
#include <libsbp/internal/v4/string/double_null_terminated.h>

TEST(TestSequenceStringDoubleNullTerminator, InitialState) {
  // The string buffer is zero'd out, it should still report as valid and have a packed length according to min-sections
  sbp_string_t s;
  memset(&s, 0, sizeof(s));

  size_t maxlen = 10;

  EXPECT_FALSE(sbp_double_null_terminated_string_valid(&s, maxlen));

  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_space_remaining(&s, maxlen), 8);

  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 0);
}

TEST(TestSequenceStringDoubleNullTerminator, InvalidState) {
  // Various states that could potentially occur where the string buffer is invalid. This includes cases where it contains more than the allowed packed size, or where the buffer doesn't contain a NULL terminator in the right places
  sbp_string_t s;
  memcpy(s.data, "one\0two\0three\0\0", 15);
  s.encoded_len = 15;

  size_t short_params = 10;
  size_t long_params = 20;

  // The amount of data in the string is greater than allowed by short_params, but is ok for long_params
  EXPECT_FALSE(sbp_double_null_terminated_string_valid(&s, short_params));
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, long_params));
  
  // In this case the short maxlen should force a packed size of 2 (double NULL double_null_terminated terminator), but the long maxlen will be valid
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, short_params), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, long_params), 15);

  // Likewise, the space remaining should be the full buffer for short maxlen (minus the 3 required NULL terminators) and the correct value for long_params
  EXPECT_EQ(sbp_double_null_terminated_string_space_remaining(&s, short_params), 8);
  EXPECT_EQ(sbp_double_null_terminated_string_space_remaining(&s, long_params), 5);

  // short_params should report 0 sections, long_params should report 3
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, short_params), 0);
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, long_params), 3);

  // We shouldn't be able to retrieve the string when using the invalid parameters
  EXPECT_EQ(sbp_double_null_terminated_string_get_section(&s, short_params, 0), nullptr);
  EXPECT_EQ(sbp_double_null_terminated_string_get_section(&s, short_params, 1), nullptr);
  EXPECT_EQ(sbp_double_null_terminated_string_get_section(&s, short_params, 2), nullptr);
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, long_params, 0), "one");
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, long_params, 1), "two");
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, long_params, 2), "three");

  // Next corrupt the encoded_len field, everything should return invalid values
  s.encoded_len = 14;
  EXPECT_FALSE(sbp_double_null_terminated_string_valid(&s, short_params));
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, short_params), 0);
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, short_params), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, short_params, 0), 0);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, short_params, 1), 0);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, short_params, 2), 0);
  EXPECT_EQ(sbp_double_null_terminated_string_get_section(&s, short_params, 0), nullptr);
  EXPECT_EQ(sbp_double_null_terminated_string_get_section(&s, short_params, 1), nullptr);
  EXPECT_EQ(sbp_double_null_terminated_string_get_section(&s, short_params, 2), nullptr);
  EXPECT_FALSE(sbp_double_null_terminated_string_valid(&s, long_params));
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, long_params), 0);
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, long_params), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, long_params, 0), 0);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, long_params, 1), 0);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, long_params, 2), 0);
  EXPECT_EQ(sbp_double_null_terminated_string_get_section(&s, long_params, 0), nullptr);
  EXPECT_EQ(sbp_double_null_terminated_string_get_section(&s, long_params, 1), nullptr);
  EXPECT_EQ(sbp_double_null_terminated_string_get_section(&s, long_params, 2), nullptr);

  // Reset encoded_len
  s.encoded_len = 15;

}

TEST(TestSequenceStringDoubleNullTerminator, Init)
{
  // Test the init function. It should be able to reset everything no matter what state it's in
  sbp_string_t s;
  size_t maxlen = 16;

  sbp_double_null_terminated_string_init(&s);
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 0);

  // Put in a valid string
  memcpy(s.data, "one\0two\0three\0\0", 15);
  s.encoded_len = 15;

  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 3);
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 0), "one");
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 1), "two");
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 2), "three");

  // And reinitialise
  sbp_double_null_terminated_string_init(&s);
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 0);

  // Put in an invalid string
  memcpy(s.data, "one\0two\0three\0four\0\0", 20);
  s.encoded_len = 19;
  EXPECT_FALSE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 0);
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 2);

  // And reinitialise
  sbp_double_null_terminated_string_init(&s);
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 0);
}

TEST(TestSequenceStringDoubleNullTerminator, AddSection)
{
  sbp_string_t s;
  size_t maxlen = 10;

  sbp_double_null_terminated_string_init(&s);
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 0);
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_space_remaining(&s, maxlen), 8);

  // Add a valid section
  EXPECT_TRUE(sbp_double_null_terminated_string_add_section(&s, maxlen, "one"));
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 1);
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 5);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 0), 3);
  EXPECT_EQ(sbp_double_null_terminated_string_space_remaining(&s, maxlen), 5);
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 0), "one");

  // Add another valid section
  EXPECT_TRUE(sbp_double_null_terminated_string_add_section(&s, maxlen, "two"));
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 9);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 0), 3);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 1), 3);
  EXPECT_EQ(sbp_double_null_terminated_string_space_remaining(&s, maxlen), 1);
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 0), "one");
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 1), "two");

  // This section is too long for the remaining space
  EXPECT_FALSE(sbp_double_null_terminated_string_add_section(&s, maxlen, "three"));
  // No changes to the string
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 9);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 0), 3);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 1), 3);
  EXPECT_EQ(sbp_double_null_terminated_string_space_remaining(&s, maxlen), 1);

  // Set up an invalid string buffer
  memcpy(s.data, "one\0two\0three\0\0", 15);
  s.encoded_len = 14;

  EXPECT_FALSE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 0);

  // Adding a new section should reset the entire string
  EXPECT_TRUE(sbp_double_null_terminated_string_add_section(&s, maxlen, "four"));
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 1);
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 6);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 0), 4);
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 0), "four");
  EXPECT_EQ(sbp_double_null_terminated_string_space_remaining(&s, maxlen), 4);
}

TEST(TestSequenceStringDoubleNullTerminator, AddSectionPrintf)
{
  sbp_string_t s;
  size_t maxlen = 10;

  auto vprintf_wrapper = [&s,&maxlen](const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    bool ret = sbp_double_null_terminated_string_add_section_vprintf(&s, maxlen, fmt, ap);
    va_end(ap);
    return ret;
  };

  sbp_double_null_terminated_string_init(&s);
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 0);
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_space_remaining(&s, maxlen), 8);

  // Add a valid section
  EXPECT_TRUE(vprintf_wrapper("%s", "one"));
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 1);
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 5);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 0), 3);
  EXPECT_EQ(sbp_double_null_terminated_string_space_remaining(&s, maxlen), 5);
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 0), "one");

  // Add another valid section
  EXPECT_TRUE(vprintf_wrapper("%d", 222));
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 9);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 0), 3);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 1), 3);
  EXPECT_EQ(sbp_double_null_terminated_string_space_remaining(&s, maxlen), 1);
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 0), "one");
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 1), "222");

  // This section is too long for the remaining space
  EXPECT_FALSE(vprintf_wrapper("%c%s%c", 't', "hre", 'e'));
  // No changes to the string
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 9);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 0), 3);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 1), 3);
  EXPECT_EQ(sbp_double_null_terminated_string_space_remaining(&s, maxlen), 1);

  // Set up an invalid string buffer
  memcpy(s.data, "one\0two\0three\0\0", 15);
  s.encoded_len = 14;

  EXPECT_FALSE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 0);

  // Adding a new section should reset the entire string
  EXPECT_TRUE(vprintf_wrapper("%d%d%d%d", 4, 4, 4, 4));
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 1);
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 6);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 0), 4);
  EXPECT_EQ(sbp_double_null_terminated_string_space_remaining(&s, maxlen), 4);
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 0), "4444");
}

TEST(TestSequenceStringDoubleNullTerminator, Append)
{
  sbp_string_t s;
  size_t maxlen = 10;

  sbp_double_null_terminated_string_init(&s);
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 0);
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_space_remaining(&s, maxlen), 8);

  // Appending to an empty buffer starts a new section
  EXPECT_TRUE(sbp_double_null_terminated_string_append(&s, maxlen, "one"));
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 1);
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 5);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 0), 3);
  EXPECT_EQ(sbp_double_null_terminated_string_space_remaining(&s, maxlen), 5);
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 0), "one");

  // Append another string to the first section
  EXPECT_TRUE(sbp_double_null_terminated_string_append(&s, maxlen, "111"));
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 1);
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 8);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 0), 6);
  EXPECT_EQ(sbp_double_null_terminated_string_space_remaining(&s, maxlen), 2);
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 0), "one111");

  // Set up an invalid string buffer
  memcpy(s.data, "one\0two\0three\0\0", 15);
  s.encoded_len = 14;

  EXPECT_FALSE(sbp_double_null_terminated_string_valid(&s, maxlen));

  // Appending over an invalid buffer will clear it
  EXPECT_TRUE(sbp_double_null_terminated_string_append(&s, maxlen, "re"));
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 1);
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 4);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 0), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_space_remaining(&s, maxlen), 6);
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 0), "re");

  // Start a new section
  EXPECT_TRUE(sbp_double_null_terminated_string_add_section(&s, maxlen, "a"));
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 6);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 0), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 1), 1);
  EXPECT_EQ(sbp_double_null_terminated_string_space_remaining(&s, maxlen), 4);
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 0), "re");
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 1), "a");

  // And append to the last section up to maximum
  EXPECT_TRUE(sbp_double_null_terminated_string_append(&s, maxlen, "bcde"));
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 10);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 0), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 1), 5);
  EXPECT_EQ(sbp_double_null_terminated_string_space_remaining(&s, maxlen), 0);
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 0), "re");
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 1), "abcde");

  // This one will push it over the limit
  EXPECT_FALSE(sbp_double_null_terminated_string_append(&s, maxlen, "g"));
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 10);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 0), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 1), 5);
  EXPECT_EQ(sbp_double_null_terminated_string_space_remaining(&s, maxlen), 0);
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 0), "re");
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 1), "abcde");
}

TEST(TestSequenceStringDoubleNullTerminator, AppendPrintf)
{
  sbp_string_t s;
  size_t maxlen = 10;

  auto vprintf_wrapper = [&s, maxlen](const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    bool ret = sbp_double_null_terminated_string_append_vprintf(&s, maxlen, fmt, ap);
    va_end(ap);
    return ret;
  };

  sbp_double_null_terminated_string_init(&s);
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 0);
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_space_remaining(&s, maxlen), 8);

  // Appending to an empty buffer starts a new section
  EXPECT_TRUE(vprintf_wrapper("%s", "one"));
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 1);
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 5);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 0), 3);
  EXPECT_EQ(sbp_double_null_terminated_string_space_remaining(&s, maxlen), 5);
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 0), "one");

  // Append another string to the first section
  EXPECT_TRUE(vprintf_wrapper("%d%d", 11, 1));
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 1);
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 8);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 0), 6);
  EXPECT_EQ(sbp_double_null_terminated_string_space_remaining(&s, maxlen), 2);
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 0), "one111");

  // Set up an invalid string buffer
  memcpy(s.data, "one\0two\0three\0\0", 15);
  s.encoded_len = 14;

  EXPECT_FALSE(sbp_double_null_terminated_string_valid(&s, maxlen));

  // Appending over an invalid buffer will clear it
  EXPECT_TRUE(vprintf_wrapper("%c%c", 'r', 'e'));
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 1);
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 4);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 0), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_space_remaining(&s, maxlen), 6);
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 0), "re");

  // Start a new section
  EXPECT_TRUE(sbp_double_null_terminated_string_add_section(&s, maxlen, "a"));
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 6);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 0), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 1), 1);
  EXPECT_EQ(sbp_double_null_terminated_string_space_remaining(&s, maxlen), 4);
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 0), "re");
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 1), "a");

  // And append to the last section up to maximum
  EXPECT_TRUE(vprintf_wrapper("%s", "bcde"));
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 10);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 0), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 1), 5);
  EXPECT_EQ(sbp_double_null_terminated_string_space_remaining(&s, maxlen), 0);
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 0), "re");
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 1), "abcde");

  // This one will push it over the limit
  EXPECT_FALSE(vprintf_wrapper("%s", "g"));
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 10);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 0), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 1), 5);
  EXPECT_EQ(sbp_double_null_terminated_string_space_remaining(&s, maxlen), 0);
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 0), "re");
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 1), "abcde");
}

TEST(TestSequenceStringDoubleNullTerminator, Pack)
{
  sbp_string_t s;
  size_t short_params = 10;
  size_t long_params = 20;

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

  EXPECT_FALSE(sbp_double_null_terminated_string_valid(&s, short_params));
  EXPECT_TRUE(sbp_double_null_terminated_string_encode(&s, short_params, &ctx));
  // Should not have written the default string
  EXPECT_EQ(ctx.offset, 2);
  for (size_t i = 0; i < 2; i ++) EXPECT_EQ(payload[i], 0);
  for (size_t i = 2; i  < 30; i ++) EXPECT_EQ(payload[i], 0xCC);

  // Pack an initialised and empty string
  memset(payload, 0xCC, sizeof(payload));
  ctx.offset = 0;
  ctx.buf_len = 30;

  sbp_double_null_terminated_string_init(&s);
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, short_params));
  EXPECT_TRUE(sbp_double_null_terminated_string_encode(&s, short_params, &ctx));
  // Should have written 2 NULL terminators
  EXPECT_EQ(ctx.offset, 2);
  for (uint8_t i = 0; i < 2; i++) EXPECT_EQ(payload[i], 0x00);
  for (uint8_t i = 2; i < sizeof(payload); i++) EXPECT_EQ(payload[i], 0xCC);

  // Pack a valid string which is less than the remaining payload size
  memset(payload, 0xCC, sizeof(payload));
  ctx.offset = 0;
  ctx.buf_len = 30;

  sbp_double_null_terminated_string_init(&s);
  EXPECT_TRUE(sbp_double_null_terminated_string_add_section(&s, long_params, "Hello"));
  EXPECT_TRUE(sbp_double_null_terminated_string_add_section(&s, long_params, "World!"));
  EXPECT_TRUE(sbp_double_null_terminated_string_encode(&s, long_params, &ctx));
  EXPECT_EQ(ctx.offset, 14);
  EXPECT_STREQ((const char *)payload, "Hello");
  EXPECT_STREQ((const char *)payload + 6, "World!");
  EXPECT_EQ(payload[13], 0); // Sequence terminator
  for (uint8_t i = 14; i < 30; i++) EXPECT_EQ(payload[i], 0xCC);

  // Pack a maximal sized string which is less than the remaining payload size
  memset(payload, 0xCC, sizeof(payload));
  ctx.offset = 0;
  ctx.buf_len = 30;

  sbp_double_null_terminated_string_init(&s);
  EXPECT_TRUE(sbp_double_null_terminated_string_add_section(&s, short_params, "10"));
  EXPECT_TRUE(sbp_double_null_terminated_string_add_section(&s, short_params, "bytes"));
  EXPECT_TRUE(sbp_double_null_terminated_string_encode(&s, short_params, &ctx));
  EXPECT_EQ(ctx.offset, 10);
  EXPECT_STREQ((const char *)payload, "10");
  EXPECT_STREQ((const char *)payload + 3, "bytes");
  EXPECT_EQ(payload[9], 0); // Sequence terminator
  for (uint8_t i = 10; i < 30; i++) EXPECT_EQ(payload[i], 0xCC);

  // Pack a string which is exactly as long as the payload buffer
  memset(payload, 0xCC, sizeof(payload));
  ctx.offset = 0;
  ctx.buf_len = 10;

  sbp_double_null_terminated_string_init(&s);
  EXPECT_TRUE(sbp_double_null_terminated_string_add_section(&s, short_params, "10"));
  EXPECT_TRUE(sbp_double_null_terminated_string_add_section(&s, short_params, "bytes"));
  EXPECT_TRUE(sbp_double_null_terminated_string_encode(&s, short_params, &ctx));
  EXPECT_EQ(ctx.offset, 10);
  EXPECT_STREQ((const char *)payload, "10");
  EXPECT_STREQ((const char *)payload + 3, "bytes");
  EXPECT_EQ(payload[9], 0); // Sequence terminator

  // Pack a string which overruns the available space in the payload buffer
  memset(payload, 0xCC, sizeof(payload));
  ctx.offset = 0;
  ctx.buf_len = 10;

  sbp_double_null_terminated_string_init(&s);
  EXPECT_TRUE(sbp_double_null_terminated_string_add_section(&s, long_params, "A"));
  EXPECT_TRUE(sbp_double_null_terminated_string_add_section(&s, long_params, "long"));
  EXPECT_TRUE(sbp_double_null_terminated_string_add_section(&s, long_params, "string"));
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, long_params));
  EXPECT_FALSE(sbp_double_null_terminated_string_encode(&s, long_params, &ctx));
  EXPECT_EQ(ctx.offset, 0);
  for (const auto &b : payload) EXPECT_EQ(b, 0xCC);

  // Pack a string at an offset in to the payload buffer
  memset(payload, 0xCC, sizeof(payload));
  memset(payload + 5, 0xDD, sizeof(payload) - 5);
  ctx.offset = 5;
  ctx.buf_len = 30;

  sbp_double_null_terminated_string_init(&s);
  EXPECT_TRUE(sbp_double_null_terminated_string_add_section(&s, long_params, "10"));
  EXPECT_TRUE(sbp_double_null_terminated_string_add_section(&s, long_params, "bytes."));
  EXPECT_TRUE(sbp_double_null_terminated_string_encode(&s, long_params, &ctx));
  EXPECT_EQ(ctx.offset, 16);
  for (uint8_t i = 0; i < 5; i++) EXPECT_EQ(payload[i], 0xCC);
  EXPECT_STREQ((const char *)payload + 5, "10");
  EXPECT_STREQ((const char *)payload + 5 + 3, "bytes.");
  EXPECT_EQ(payload[15], 0); // Sequence terminator
  for (uint8_t i = 16; i < 30; i++) EXPECT_EQ(payload[i], 0xDD);
}

TEST(TestSequenceStringDoubleNullTerminator, Unpack)
{
  sbp_string_t s;
  size_t maxlen = 10;

  uint8_t payload[40];
  sbp_decode_ctx_t ctx;
  ctx.buf = payload;

  // Unpack in to an uninitialised buffer
  memset(&s, 0, sizeof(s));
  memcpy(payload, "one\0two\0\0", 9);
  ctx.buf_len = 9;
  ctx.offset = 0;
  EXPECT_FALSE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 2);
  EXPECT_TRUE(sbp_double_null_terminated_string_decode(&s, maxlen, &ctx));
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 9);
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 0), 3);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 1), 3);
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 0), "one");
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 1), "two");
  EXPECT_EQ(ctx.offset, 9);

  // Unpack in to an initialised but empty buffer
  sbp_double_null_terminated_string_init(&s);
  memcpy(payload, "one\0two\0\0", 9);
  ctx.buf_len = 9;
  ctx.offset = 0;
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 2);
  EXPECT_TRUE(sbp_double_null_terminated_string_decode(&s, maxlen, &ctx));
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 9);
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 0), 3);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 1), 3);
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 0), "one");
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 1), "two");
  EXPECT_EQ(ctx.offset, 9);

  // Overwrite a previously valid string
  sbp_double_null_terminated_string_init(&s);
  sbp_double_null_terminated_string_add_section(&s, maxlen, "old");
  sbp_double_null_terminated_string_add_section(&s, maxlen, "data");
  memcpy(payload, "one\0two\0\0", 9);
  ctx.buf_len = 9;
  ctx.offset = 0;
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 10);
  EXPECT_TRUE(sbp_double_null_terminated_string_decode(&s, maxlen, &ctx));
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 9);
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 0), 3);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 1), 3);
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 0), "one");
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 1), "two");
  EXPECT_EQ(ctx.offset, 9);

  // Unpack a string of maximum length
  sbp_double_null_terminated_string_init(&s);
  memcpy(payload, "10\0bytes\0\0", 10);
  ctx.buf_len = 10;
  ctx.offset = 0;
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 2);
  EXPECT_TRUE(sbp_double_null_terminated_string_decode(&s, maxlen, &ctx));
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 10);
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 0), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 1), 5);
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 0), "10");
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 1), "bytes");
  EXPECT_EQ(ctx.offset, 10);

  // fail to decode a string where there is extra data in buffer
  sbp_double_null_terminated_string_init(&s);
  memcpy(payload, "two\0sections\0with lots of extra data\0\0", 38);
  ctx.buf_len = 38;
  ctx.offset = 0;
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 2);
  EXPECT_FALSE(sbp_double_null_terminated_string_decode(&s, maxlen, &ctx));
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 2);
  EXPECT_EQ(ctx.offset, 0);

  // Unpack from an offset in the payload buffer
  sbp_double_null_terminated_string_init(&s);
  memset(payload, 0xCC, sizeof(payload));
  memcpy(payload + 5, "one\0two\0\0", 9);
  ctx.buf_len = 14;
  ctx.offset = 5;
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 2);
  EXPECT_TRUE(sbp_double_null_terminated_string_decode(&s, maxlen, &ctx));
  EXPECT_TRUE(sbp_double_null_terminated_string_valid(&s, maxlen));
  EXPECT_EQ(sbp_double_null_terminated_string_encoded_len(&s, maxlen), 9);
  EXPECT_EQ(sbp_double_null_terminated_string_count_sections(&s, maxlen), 2);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 0), 3);
  EXPECT_EQ(sbp_double_null_terminated_string_section_strlen(&s, maxlen, 1), 3);
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 0), "one");
  EXPECT_STREQ(sbp_double_null_terminated_string_get_section(&s, maxlen, 1), "two");
  EXPECT_EQ(ctx.offset, 14);
}


