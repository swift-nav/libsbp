#include <gtest/gtest.h>
#include <libsbp/unpacked/string/multipart.h>
#include <libsbp/internal/unpacked/string/multipart.h>

TEST(TestMultipartString, InitialState) {
  // The string buffer is zero'd out, it should still report as valid and have a packed length according to min-sections
  sbp_multipart_string_t s;
  memset(&s, 0, sizeof(s));

  sbp_multipart_string_params_t params = {10};

  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));

  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 0);
  EXPECT_EQ(sbp_multipart_string_space_remaining(&s, &params), 10);

  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 0);
  for (uint8_t i = 0; i < SBP_MULTIPART_STRING_MAX_SECTIONS; i++)
  {
    EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, i), "");
    EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, i), 0);
    }
}

TEST(TestMultipartString, InvalidState) {
  // Various states that could potentially occur where the string buffer is invalid. This includes cases where it contains more than the allowed packed size, or where the buffer doesn't contain a NULL terminator in the right places
  sbp_multipart_string_t s;
  memcpy(s.data, "one\0two\0three\0", 14);
  s.packed_len = 14;
  s.offsets[0] = 0;
  s.offsets[1] = 4;
  s.offsets[2] = 8;
  s.lens[0] = 3;
  s.lens[1] = 3;
  s.lens[2] = 5;
  s.n_sections = 3;

  sbp_multipart_string_params_t short_params = {10};
  sbp_multipart_string_params_t long_params = {20};

  // The amount of data in the string is greater than allowed by short_params, but is ok for long_params
  EXPECT_FALSE(sbp_multipart_string_valid(&s, &short_params));
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &long_params));
  
  // In this case the short params should force a packed size of 0, but the long params will be valid
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &short_params), 0);
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &long_params), 14);

  // Likewise, the space remaining should be the full buffer for short params (minus the 3 required NULL terminators) and the correct value for long_params
  EXPECT_EQ(sbp_multipart_string_space_remaining(&s, &short_params), 10);
  EXPECT_EQ(sbp_multipart_string_space_remaining(&s, &long_params), 6);

  // short_params should report 0 sections, long_params should report 3
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &short_params), 0);
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &long_params), 3);

  // We shouldn't be able to retrieve the string when using the invalid parameters
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &short_params, 0), "");
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &short_params, 1), "");
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &short_params, 2), "");
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &long_params, 0), "one");
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &long_params, 1), "two");
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &long_params, 2), "three");

  // Next corrupt the packed_len field, everything should return invalid values
  s.packed_len = 15;
  EXPECT_FALSE(sbp_multipart_string_valid(&s, &short_params));
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &short_params), 0);
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &short_params), 0);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &short_params, 0), 0);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &short_params, 1), 0);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &short_params, 2), 0);
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &short_params, 0), "");
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &short_params, 1), "");
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &short_params, 2), "");
  EXPECT_FALSE(sbp_multipart_string_valid(&s, &long_params));
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &long_params), 0);
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &long_params), 0);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &long_params, 0), 0);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &long_params, 1), 0);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &long_params, 2), 0);
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &long_params, 0), "");
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &long_params, 1), "");
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &long_params, 2), "");

  // Reset packed_len
  s.packed_len = 14;

  // Now try corrupting one of the offset fields
  s.offsets[1] = 5;
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &short_params), 0);
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &short_params), 0);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &short_params, 0), 0);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &short_params, 1), 0);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &short_params, 2), 0);
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &short_params, 0), "");
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &short_params, 1), "");
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &short_params, 2), "");
  EXPECT_FALSE(sbp_multipart_string_valid(&s, &long_params));
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &long_params), 0);
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &long_params), 0);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &long_params, 0), 0);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &long_params, 1), 0);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &long_params, 2), 0);
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &long_params, 0), "");
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &long_params, 1), "");
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &long_params, 2), "");
  s.offsets[1] = 4;

  // And one of the lengths
  s.lens[0] = 2;
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &short_params), 0);
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &short_params), 0);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &short_params, 0), 0);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &short_params, 1), 0);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &short_params, 2), 0);
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &short_params, 0), "");
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &short_params, 1), "");
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &short_params, 2), "");
  EXPECT_FALSE(sbp_multipart_string_valid(&s, &long_params));
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &long_params), 0);
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &long_params), 0);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &long_params, 0), 0);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &long_params, 1), 0);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &long_params, 2), 0);
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &long_params, 0), "");
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &long_params, 1), "");
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &long_params, 2), "");
}

TEST(TestMultipartString, Init)
{
  // Test the init function. It should be able to reset everything no matter what state it's in
  sbp_multipart_string_t s;
  sbp_multipart_string_params_t params = {16};

  sbp_multipart_string_init(&s, &params);
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 0);
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 0);

  // Put in a valid string
  memcpy(s.data, "one\0two\0three\0", 14);
  s.packed_len = 14;
  s.offsets[0] = 0;
  s.offsets[1] = 4;
  s.offsets[2] = 8;
  s.lens[0] = 3;
  s.lens[1] = 3;
  s.lens[2] = 5;
  s.n_sections = 3;

  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 3);
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 0), "one");
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 1), "two");
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 2), "three");

  // And reinitialise
  sbp_multipart_string_init(&s, &params);
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 0);
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 0);

  // Put in an invalid string
  memcpy(s.data, "one\0two\0three\0four\0", 19);
  s.packed_len = 19;
  s.offsets[0] = 0;
  s.offsets[1] = 4;
  s.offsets[2] = 8;
  s.offsets[3] = 15;
  s.lens[0] = 3;
  s.lens[1] = 3;
  s.lens[2] = 5;
  s.lens[3] = 4;
  s.n_sections = 4;
  EXPECT_FALSE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 0);
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 0);

  // And reinitialise
  sbp_multipart_string_init(&s, &params);
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 0);
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 0);
}

TEST(TestMultipartString, AddSection)
{
  sbp_multipart_string_t s;
  sbp_multipart_string_params_t params = {10};

  sbp_multipart_string_init(&s, &params);
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 0);
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 0);
  EXPECT_EQ(sbp_multipart_string_space_remaining(&s, &params), 10);

  // Add a valid section
  EXPECT_TRUE(sbp_multipart_string_add_section(&s, &params, "one"));
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 1);
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 4);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 0), 3);
  EXPECT_EQ(sbp_multipart_string_space_remaining(&s, &params), 6);
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 0), "one");

  // Add another valid section
  EXPECT_TRUE(sbp_multipart_string_add_section(&s, &params, "two"));
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 2);
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 8);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 0), 3);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 1), 3);
  EXPECT_EQ(sbp_multipart_string_space_remaining(&s, &params), 2);
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 0), "one");
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 1), "two");

  // This section is too long for the remaining space
  EXPECT_FALSE(sbp_multipart_string_add_section(&s, &params, "three"));
  // No changes to the string
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 2);
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 8);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 0), 3);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 1), 3);
  EXPECT_EQ(sbp_multipart_string_space_remaining(&s, &params), 2);

  // Set up an invalid string buffer
  memcpy(s.data, "one\0two\0three\0", 14);
  s.packed_len = 14;
  s.lens[0] = 3;
  s.lens[1] = 3;
  s.lens[2] = 5;
  s.offsets[0] = 0;
  s.offsets[1] = 4;
  s.offsets[2] = 8;
  s.n_sections = 3;

  EXPECT_FALSE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 0);

  // Adding a new section should reset the entire string
  EXPECT_TRUE(sbp_multipart_string_add_section(&s, &params, "four"));
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 1);
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 5);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 0), 4);
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 0), "four");
  EXPECT_EQ(sbp_multipart_string_space_remaining(&s, &params), 5);
}

TEST(TestMultipartString, AddSectionPrintf)
{
  sbp_multipart_string_t s;
  sbp_multipart_string_params_t params = {10};

  auto vprintf_wrapper = [&s,&params](const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    bool ret = sbp_multipart_string_add_section_vprintf(&s, &params, fmt, ap);
    va_end(ap);
    return ret;
  };

  sbp_multipart_string_init(&s, &params);
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 0);
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 0);
  EXPECT_EQ(sbp_multipart_string_space_remaining(&s, &params), 10);

  // Add a valid section
  EXPECT_TRUE(vprintf_wrapper("%s", "one"));
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 1);
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 4);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 0), 3);
  EXPECT_EQ(sbp_multipart_string_space_remaining(&s, &params), 6);
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 0), "one");

  // Add another valid section
  EXPECT_TRUE(vprintf_wrapper("%d", 222));
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 2);
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 8);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 0), 3);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 1), 3);
  EXPECT_EQ(sbp_multipart_string_space_remaining(&s, &params), 2);
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 0), "one");
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 1), "222");

  // This section is too long for the remaining space
  EXPECT_FALSE(vprintf_wrapper("%c%s%c", 't', "hre", 'e'));
  // No changes to the string
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 2);
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 8);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 0), 3);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 1), 3);
  EXPECT_EQ(sbp_multipart_string_space_remaining(&s, &params), 2);

  // Set up an invalid string buffer
  memcpy(s.data, "one\0two\0three\0", 14);
  s.packed_len = 14;
  s.lens[0] = 3;
  s.lens[1] = 3;
  s.lens[2] = 5;
  s.offsets[0] = 0;
  s.offsets[1] = 4;
  s.offsets[2] = 8;
  s.n_sections = 3;

  EXPECT_FALSE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 0);

  // Adding a new section should reset the entire string
  EXPECT_TRUE(vprintf_wrapper("%d%d%d%d", 4, 4, 4, 4));
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 1);
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 5);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 0), 4);
  EXPECT_EQ(sbp_multipart_string_space_remaining(&s, &params), 5);
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 0), "4444");
}

TEST(TestMultipartString, Append)
{
  sbp_multipart_string_t s;
  sbp_multipart_string_params_t params = {10};

  sbp_multipart_string_init(&s, &params);
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 0);
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 0);
  EXPECT_EQ(sbp_multipart_string_space_remaining(&s, &params), 10);

  // Appending to an empty buffer starts a new section
  EXPECT_TRUE(sbp_multipart_string_append(&s, &params, "one"));
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 1);
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 4);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 0), 3);
  EXPECT_EQ(sbp_multipart_string_space_remaining(&s, &params), 6);
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 0), "one");

  // Append another string to the first section
  EXPECT_TRUE(sbp_multipart_string_append(&s, &params, "111"));
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 1);
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 7);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 0), 6);
  EXPECT_EQ(sbp_multipart_string_space_remaining(&s, &params), 3);
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 0), "one111");

  // Set up an invalid string buffer
  memcpy(s.data, "one\0two\0three\0", 14);
  s.packed_len = 14;
  s.lens[0] = 3;
  s.lens[1] = 3;
  s.lens[2] = 5;
  s.offsets[0] = 0;
  s.offsets[1] = 4;
  s.offsets[2] = 8;
  s.n_sections = 3;

  EXPECT_FALSE(sbp_multipart_string_valid(&s, &params));

  // Appending over an invalid buffer will clear it
  EXPECT_TRUE(sbp_multipart_string_append(&s, &params, "re"));
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 1);
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 3);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 0), 2);
  EXPECT_EQ(sbp_multipart_string_space_remaining(&s, &params), 7);
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 0), "re");

  // Start a new section
  EXPECT_TRUE(sbp_multipart_string_add_section(&s, &params, "a"));
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 2);
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 5);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 0), 2);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 1), 1);
  EXPECT_EQ(sbp_multipart_string_space_remaining(&s, &params), 5);
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 0), "re");
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 1), "a");

  // And append to the last section up to maximum
  EXPECT_TRUE(sbp_multipart_string_append(&s, &params, "bcdef"));
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 2);
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 10);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 0), 2);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 1), 6);
  EXPECT_EQ(sbp_multipart_string_space_remaining(&s, &params), 0);
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 0), "re");
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 1), "abcdef");

  // This one will push it over the limit
  EXPECT_FALSE(sbp_multipart_string_append(&s, &params, "g"));
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 2);
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 10);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 0), 2);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 1), 6);
  EXPECT_EQ(sbp_multipart_string_space_remaining(&s, &params), 0);
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 0), "re");
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 1), "abcdef");
}

TEST(TestMultipartString, AppendPrintf)
{
  sbp_multipart_string_t s;
  sbp_multipart_string_params_t params = {10};

  auto vprintf_wrapper = [&s, &params](const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    bool ret = sbp_multipart_string_append_vprintf(&s, &params, fmt, ap);
    va_end(ap);
    return ret;
  };

  sbp_multipart_string_init(&s, &params);
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 0);
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 0);
  EXPECT_EQ(sbp_multipart_string_space_remaining(&s, &params), 10);

  // Appending to an empty buffer starts a new section
  EXPECT_TRUE(vprintf_wrapper("%s", "one"));
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 1);
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 4);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 0), 3);
  EXPECT_EQ(sbp_multipart_string_space_remaining(&s, &params), 6);
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 0), "one");

  // Append another string to the first section
  EXPECT_TRUE(vprintf_wrapper("%d%d", 11, 1));
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 1);
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 7);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 0), 6);
  EXPECT_EQ(sbp_multipart_string_space_remaining(&s, &params), 3);
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 0), "one111");

  // Set up an invalid string buffer
  memcpy(s.data, "one\0two\0three\0", 14);
  s.packed_len = 14;
  s.lens[0] = 3;
  s.lens[1] = 3;
  s.lens[2] = 5;
  s.offsets[0] = 0;
  s.offsets[1] = 4;
  s.offsets[2] = 8;
  s.n_sections = 3;

  EXPECT_FALSE(sbp_multipart_string_valid(&s, &params));

  // Appending over an invalid buffer will clear it
  EXPECT_TRUE(vprintf_wrapper("%c%c", 'r', 'e'));
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 1);
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 3);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 0), 2);
  EXPECT_EQ(sbp_multipart_string_space_remaining(&s, &params), 7);
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 0), "re");

  // Start a new section
  EXPECT_TRUE(sbp_multipart_string_add_section(&s, &params, "a"));
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 2);
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 5);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 0), 2);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 1), 1);
  EXPECT_EQ(sbp_multipart_string_space_remaining(&s, &params), 5);
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 0), "re");
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 1), "a");

  // And append to the last section up to maximum
  EXPECT_TRUE(vprintf_wrapper("%s", "bcdef"));
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 2);
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 10);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 0), 2);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 1), 6);
  EXPECT_EQ(sbp_multipart_string_space_remaining(&s, &params), 0);
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 0), "re");
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 1), "abcdef");

  // This one will push it over the limit
  EXPECT_FALSE(vprintf_wrapper("%s", "g"));
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 2);
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 10);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 0), 2);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 1), 6);
  EXPECT_EQ(sbp_multipart_string_space_remaining(&s, &params), 0);
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 0), "re");
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 1), "abcdef");
}

TEST(TestMultipartString, Pack)
{
  sbp_multipart_string_t s;
  sbp_multipart_string_params_t short_params = {10};
  sbp_multipart_string_params_t long_params = {20};

  uint8_t payload[30];
  sbp_pack_ctx_t ctx;
  ctx.buf = payload;
  ctx.buf_len = 30;
  ctx.offset = 0;

  // Pack an uninitialised string buffer
  memset(&s, 0, sizeof(s));
  memset(payload, 0xCC, sizeof(payload));
  ctx.offset = 0;
  ctx.buf_len = 30;

  EXPECT_TRUE(sbp_multipart_string_valid(&s, &short_params));
  EXPECT_TRUE(sbp_multipart_string_pack(&s, &short_params, &ctx));
  // Should not have written anything
  EXPECT_EQ(ctx.offset, 0);
  for (const auto &b : payload) EXPECT_EQ(b, 0xCC);

  // Pack an initialised and empty string
  memset(payload, 0xCC, sizeof(payload));
  ctx.offset = 0;
  ctx.buf_len = 30;

  sbp_multipart_string_init(&s, &short_params);
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &short_params));
  EXPECT_TRUE(sbp_multipart_string_pack(&s, &short_params, &ctx));
  // Should not have written anything
  EXPECT_EQ(ctx.offset, 0);
  for (const auto &b : payload) EXPECT_EQ(b, 0xCC);

  // Pack a valid string which is less than the remaining payload size
  memset(payload, 0xCC, sizeof(payload));
  ctx.offset = 0;
  ctx.buf_len = 30;

  sbp_multipart_string_init(&s, &long_params);
  EXPECT_TRUE(sbp_multipart_string_add_section(&s, &long_params, "Hello"));
  EXPECT_TRUE(sbp_multipart_string_add_section(&s, &long_params, "World!"));
  EXPECT_TRUE(sbp_multipart_string_pack(&s, &long_params, &ctx));
  EXPECT_EQ(ctx.offset, 13);
  EXPECT_STREQ((const char *)payload, "Hello");
  EXPECT_STREQ((const char *)payload + 6, "World!");
  for (uint8_t i = 13; i < 30; i++) EXPECT_EQ(payload[i], 0xCC);

  // Pack a maximal sized string which is less than the remaining payload size
  memset(payload, 0xCC, sizeof(payload));
  ctx.offset = 0;
  ctx.buf_len = 30;

  sbp_multipart_string_init(&s, &short_params);
  EXPECT_TRUE(sbp_multipart_string_add_section(&s, &short_params, "10"));
  EXPECT_TRUE(sbp_multipart_string_add_section(&s, &short_params, "bytes."));
  EXPECT_TRUE(sbp_multipart_string_pack(&s, &short_params, &ctx));
  EXPECT_EQ(ctx.offset, 10);
  EXPECT_STREQ((const char *)payload, "10");
  EXPECT_STREQ((const char *)payload + 3, "bytes.");
  for (uint8_t i = 10; i < 30; i++) EXPECT_EQ(payload[i], 0xCC);

  // Pack a string which is exactly as long as the payload buffer
  memset(payload, 0xCC, sizeof(payload));
  ctx.offset = 0;
  ctx.buf_len = 10;

  sbp_multipart_string_init(&s, &short_params);
  EXPECT_TRUE(sbp_multipart_string_add_section(&s, &short_params, "10"));
  EXPECT_TRUE(sbp_multipart_string_add_section(&s, &short_params, "bytes."));
  EXPECT_TRUE(sbp_multipart_string_pack(&s, &short_params, &ctx));
  EXPECT_EQ(ctx.offset, 10);
  EXPECT_STREQ((const char *)payload, "10");
  EXPECT_STREQ((const char *)payload + 3, "bytes.");

  // Pack a string which overruns the available space in the payload buffer
  memset(payload, 0xCC, sizeof(payload));
  ctx.offset = 0;
  ctx.buf_len = 10;

  sbp_multipart_string_init(&s, &long_params);
  EXPECT_TRUE(sbp_multipart_string_add_section(&s, &long_params, "A"));
  EXPECT_TRUE(sbp_multipart_string_add_section(&s, &long_params, "long"));
  EXPECT_TRUE(sbp_multipart_string_add_section(&s, &long_params, "string"));
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &long_params));
  EXPECT_FALSE(sbp_multipart_string_pack(&s, &long_params, &ctx));
  EXPECT_EQ(ctx.offset, 0);
  for (const auto &b : payload) EXPECT_EQ(b, 0xCC);

  // Pack a string at an offset in to the payload buffer
  memset(payload, 0xCC, sizeof(payload));
  memset(payload + 5, 0xDD, sizeof(payload) - 5);
  ctx.offset = 5;
  ctx.buf_len = 30;

  sbp_multipart_string_init(&s, &short_params);
  EXPECT_TRUE(sbp_multipart_string_add_section(&s, &short_params, "10"));
  EXPECT_TRUE(sbp_multipart_string_add_section(&s, &short_params, "bytes."));
  EXPECT_TRUE(sbp_multipart_string_pack(&s, &short_params, &ctx));
  EXPECT_EQ(ctx.offset, 15);
  for (uint8_t i = 0; i < 5; i++) EXPECT_EQ(payload[i], 0xCC);
  EXPECT_STREQ((const char *)payload + 5, "10");
  EXPECT_STREQ((const char *)payload + 5 + 3, "bytes.");
  for (uint8_t i = 15; i < 30; i++) EXPECT_EQ(payload[i], 0xDD);
}

TEST(TestMultipartString, Unpack)
{
  sbp_multipart_string_t s;
  sbp_multipart_string_params_t params = {10};

  uint8_t payload[40];
  sbp_unpack_ctx_t ctx;
  ctx.buf = payload;

  // Unpack in to an uninitialised buffer
  memset(&s, 0, sizeof(s));
  memcpy(payload, "one\0two\0", 8);
  ctx.buf_len = 8;
  ctx.offset = 0;
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 0);
  EXPECT_TRUE(sbp_multipart_string_unpack(&s, &params, &ctx));
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 8);
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 2);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 0), 3);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 1), 3);
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 0), "one");
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 1), "two");
  EXPECT_EQ(ctx.offset, 8);

  // Unpack in to an initialised but empty buffer
  sbp_multipart_string_init(&s, &params);
  memcpy(payload, "one\0two\0", 8);
  ctx.buf_len = 8;
  ctx.offset = 0;
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 0);
  EXPECT_TRUE(sbp_multipart_string_unpack(&s, &params, &ctx));
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 8);
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 2);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 0), 3);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 1), 3);
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 0), "one");
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 1), "two");
  EXPECT_EQ(ctx.offset, 8);

  // Overwrite a previously valid string
  sbp_multipart_string_init(&s, &params);
  sbp_multipart_string_add_section(&s, &params, "old");
  sbp_multipart_string_add_section(&s, &params, "data");
  memcpy(payload, "one\0two\0", 8);
  ctx.buf_len = 8;
  ctx.offset = 0;
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 9);
  EXPECT_TRUE(sbp_multipart_string_unpack(&s, &params, &ctx));
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 8);
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 2);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 0), 3);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 1), 3);
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 0), "one");
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 1), "two");
  EXPECT_EQ(ctx.offset, 8);

  // Unpack a string of maximum length
  sbp_multipart_string_init(&s, &params);
  memcpy(payload, "10\0bytes.\0", 10);
  ctx.buf_len = 10;
  ctx.offset = 0;
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 0);
  EXPECT_TRUE(sbp_multipart_string_unpack(&s, &params, &ctx));
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 10);
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 2);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 0), 2);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 1), 6);
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 0), "10");
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 1), "bytes.");
  EXPECT_EQ(ctx.offset, 10);

  // Unpack a string without a final NULL terminator
  sbp_multipart_string_init(&s, &params);
  memcpy(payload, "ab\0cd", 5);
  ctx.buf_len = 5;
  ctx.offset = 0;
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 0);
  EXPECT_TRUE(sbp_multipart_string_unpack(&s, &params, &ctx));
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 6);
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 2);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 0), 2);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 1), 2);
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 0), "ab");
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 1), "cd");
  EXPECT_EQ(ctx.offset, 5);

  // fail to unpack a string where there is extra data in buffer
  sbp_multipart_string_init(&s, &params);
  memcpy(payload, "two\0sections\0with lots of extra data", 36);
  ctx.buf_len = 36;
  ctx.offset = 0;
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 0);
  EXPECT_FALSE(sbp_multipart_string_unpack(&s, &params, &ctx));
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 0);
  EXPECT_EQ(ctx.offset, 0);

  // Unpack from an offset in the payload buffer
  sbp_multipart_string_init(&s, &params);
  memset(payload, 0xCC, sizeof(payload));
  memcpy(payload + 5, "one\0two\0", 8);
  ctx.buf_len = 13;
  ctx.offset = 5;
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 0);
  EXPECT_TRUE(sbp_multipart_string_unpack(&s, &params, &ctx));
  EXPECT_TRUE(sbp_multipart_string_valid(&s, &params));
  EXPECT_EQ(sbp_multipart_string_packed_len(&s, &params), 8);
  EXPECT_EQ(sbp_multipart_string_count_sections(&s, &params), 2);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 0), 3);
  EXPECT_EQ(sbp_multipart_string_section_strlen(&s, &params, 1), 3);
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 0), "one");
  EXPECT_STREQ(sbp_multipart_string_get_section(&s, &params, 1), "two");
  EXPECT_EQ(ctx.offset, 13);
}

