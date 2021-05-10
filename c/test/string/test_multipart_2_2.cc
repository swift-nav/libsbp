#include <gtest/gtest.h>
#include <libsbp/sbp.h>
#include <libsbp/string2.h>
#include <memory.h>
#include <string.h>

class TestStringMultipart_2_2 : public ::testing::Test
{
public:
  TestStringMultipart_2_2() : ::testing::Test()
  {
    format_.encoding = SBP_STRING_MULTIPART;
    format_.min_sections = 2;
    format_.max_sections = 2;
    format_.max_encoded_len = 15;
    sbp_string_init(string_, &format_);
  }

protected:
  sbp_string_t string_;
  sbp_string_format_t format_;
};

TEST_F(TestStringMultipart_2_2, EmptyState)
{
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 2);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 2);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "");
  EXPECT_NE(sbp_string_get_section(string_, &format_, 1), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 1), "");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 0);
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 1), 0);
}

TEST_F(TestStringMultipart_2_2, OnlySectionOne)
{
  memcpy(string_, "one\0\0", 5);
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 5);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 2);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "one");
  EXPECT_NE(sbp_string_get_section(string_, &format_, 1), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 1), "");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 3);
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 1), 0);
}

TEST_F(TestStringMultipart_2_2, OnlySectionTwo)
{
  memcpy(string_, "\0two\0", 5);
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 5);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 2);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "");
  EXPECT_NE(sbp_string_get_section(string_, &format_, 1), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 1), "two");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 0);
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 1), 3);
}

TEST_F(TestStringMultipart_2_2, BothSectionsShort)
{
  memcpy(string_, "one\0two\0", 8);
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 8);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 2);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "one");
  EXPECT_NE(sbp_string_get_section(string_, &format_, 1), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 1), "two");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 3);
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 1), 3);
}

TEST_F(TestStringMultipart_2_2, BothSectionsMaxLen)
{
  memcpy(string_, "maximum\0length\0", 15);
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 15);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 2);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "maximum");
  EXPECT_NE(sbp_string_get_section(string_, &format_, 1), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 1), "length");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 7);
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 1), 6);
}

TEST_F(TestStringMultipart_2_2, SectionOneExceedsMaxLen)
{
  memcpy(string_, "longer than the maximum\0length\0", 31);
  EXPECT_FALSE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 0);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 0);
  EXPECT_EQ(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_EQ(sbp_string_get_section(string_, &format_, 1), nullptr);
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 0);
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 1), 0);
}

TEST_F(TestStringMultipart_2_2, SectionTwoExceedsMaxLen)
{
  memcpy(string_, "maximum\0length exceeded by the second section\0", 46);
  EXPECT_FALSE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 0);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 0);
  EXPECT_EQ(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_EQ(sbp_string_get_section(string_, &format_, 1), nullptr);
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 0);
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 1), 0);
}

TEST_F(TestStringMultipart_2_2, SetOneShortFromEmpty)
{
  EXPECT_TRUE(sbp_string_set_section(string_, &format_, 0, "one"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 5);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 2);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "one");
  EXPECT_NE(sbp_string_get_section(string_, &format_, 1), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 1), "");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 3);
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 1), 0);
}

TEST_F(TestStringMultipart_2_2, SetTwoShortFromEmpty)
{
  EXPECT_TRUE(sbp_string_set_section(string_, &format_, 1, "two"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 5);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 2);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "");
  EXPECT_NE(sbp_string_get_section(string_, &format_, 1), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 1), "two");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 0);
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 1), 3);
}

TEST_F(TestStringMultipart_2_2, SetBothShortFromEmpty)
{
  EXPECT_TRUE(sbp_string_set_section(string_, &format_, 0, "one"));
  EXPECT_TRUE(sbp_string_set_section(string_, &format_, 1, "two"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 8);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 2);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "one");
  EXPECT_NE(sbp_string_get_section(string_, &format_, 1), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 1), "two");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 3);
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 1), 3);
}

TEST_F(TestStringMultipart_2_2, OverwriteOneSameLength)
{
  EXPECT_TRUE(sbp_string_set_section(string_, &format_, 0, "one"));
  EXPECT_TRUE(sbp_string_set_section(string_, &format_, 1, "two"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 8);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 2);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "one");
  EXPECT_NE(sbp_string_get_section(string_, &format_, 1), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 1), "two");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 3);
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 1), 3);

  EXPECT_TRUE(sbp_string_set_section(string_, &format_, 0, "ten"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 8);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 2);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "ten");
  EXPECT_NE(sbp_string_get_section(string_, &format_, 1), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 1), "two");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 3);
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 1), 3);
}

TEST_F(TestStringMultipart_2_2, OverwriteTwoSameLength)
{
  EXPECT_TRUE(sbp_string_set_section(string_, &format_, 0, "one"));
  EXPECT_TRUE(sbp_string_set_section(string_, &format_, 1, "two"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 8);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 2);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "one");
  EXPECT_NE(sbp_string_get_section(string_, &format_, 1), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 1), "two");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 3);
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 1), 3);

  EXPECT_TRUE(sbp_string_set_section(string_, &format_, 1, "ten"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 8);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 2);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "one");
  EXPECT_NE(sbp_string_get_section(string_, &format_, 1), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 1), "ten");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 3);
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 1), 3);
}

TEST_F(TestStringMultipart_2_2, OverwriteOneLonger)
{
  EXPECT_TRUE(sbp_string_set_section(string_, &format_, 0, "one"));
  EXPECT_TRUE(sbp_string_set_section(string_, &format_, 1, "two"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 8);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 2);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "one");
  EXPECT_NE(sbp_string_get_section(string_, &format_, 1), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 1), "two");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 3);
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 1), 3);

  EXPECT_TRUE(sbp_string_set_section(string_, &format_, 0, "three"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 10);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 2);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "three");
  EXPECT_NE(sbp_string_get_section(string_, &format_, 1), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 1), "two");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 5);
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 1), 3);
}

TEST_F(TestStringMultipart_2_2, OverwriteTwoLonger)
{
  EXPECT_TRUE(sbp_string_set_section(string_, &format_, 0, "one"));
  EXPECT_TRUE(sbp_string_set_section(string_, &format_, 1, "two"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 8);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 2);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "one");
  EXPECT_NE(sbp_string_get_section(string_, &format_, 1), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 1), "two");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 3);
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 1), 3);

  EXPECT_TRUE(sbp_string_set_section(string_, &format_, 1, "three"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 10);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 2);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "one");
  EXPECT_NE(sbp_string_get_section(string_, &format_, 1), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 1), "three");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 3);
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 1), 5);
}

TEST_F(TestStringMultipart_2_2, OverwriteBothToMaxLen)
{
  EXPECT_TRUE(sbp_string_set_section(string_, &format_, 0, "one"));
  EXPECT_TRUE(sbp_string_set_section(string_, &format_, 1, "two"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 8);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 2);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "one");
  EXPECT_NE(sbp_string_get_section(string_, &format_, 1), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 1), "two");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 3);
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 1), 3);

  EXPECT_TRUE(sbp_string_set_section(string_, &format_, 0, "maximum"));
  EXPECT_TRUE(sbp_string_set_section(string_, &format_, 1, "length"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 15);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 2);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "maximum");
  EXPECT_NE(sbp_string_get_section(string_, &format_, 1), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 1), "length");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 7);
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 1), 6);
}

TEST_F(TestStringMultipart_2_2, OverwriteOneWouldExceedMaxLen)
{
  EXPECT_TRUE(sbp_string_set_section(string_, &format_, 0, "maximum"));
  EXPECT_TRUE(sbp_string_set_section(string_, &format_, 1, "length"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 15);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 2);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "maximum");
  EXPECT_NE(sbp_string_get_section(string_, &format_, 1), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 1), "length");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 7);
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 1), 6);

  EXPECT_FALSE(sbp_string_set_section(string_, &format_, 0, "would exceed max length"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 15);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 2);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "maximum");
  EXPECT_NE(sbp_string_get_section(string_, &format_, 1), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 1), "length");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 7);
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 1), 6);
}

TEST_F(TestStringMultipart_2_2, OverwriteTwoWouldExceedMaxLen)
{
  EXPECT_TRUE(sbp_string_set_section(string_, &format_, 0, "maximum"));
  EXPECT_TRUE(sbp_string_set_section(string_, &format_, 1, "length"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 15);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 2);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "maximum");
  EXPECT_NE(sbp_string_get_section(string_, &format_, 1), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 1), "length");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 7);
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 1), 6);

  EXPECT_FALSE(sbp_string_set_section(string_, &format_, 1, "would exceed max length"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 15);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 2);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "maximum");
  EXPECT_NE(sbp_string_get_section(string_, &format_, 1), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 1), "length");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 7);
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 1), 6);
}

TEST_F(TestStringMultipart_2_2, PackShort)
{
  EXPECT_TRUE(sbp_string_set_section(string_, &format_, 0, "one"));
  EXPECT_TRUE(sbp_string_set_section(string_, &format_, 1, "two"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 8);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 2);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "one");
  EXPECT_NE(sbp_string_get_section(string_, &format_, 1), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 1), "two");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 3);
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 1), 3);

  uint8_t buf[SBP_MAX_PAYLOAD_LEN];
  memset(buf, 'a', sizeof(buf));
  uint8_t expected[SBP_MAX_PAYLOAD_LEN];
  memset(expected, 'a', sizeof(expected));
  memcpy(expected, "one\0two\0", 8);

  EXPECT_EQ(sbp_string_pack(string_, &format_, buf, sizeof(buf)), 8);

  EXPECT_EQ(memcmp(buf, expected, sizeof(expected)), 0);
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 8);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 2);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "one");
  EXPECT_NE(sbp_string_get_section(string_, &format_, 1), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 1), "two");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 3);
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 1), 3);
}

TEST_F(TestStringMultipart_2_2, PackMaxLen)
{
  EXPECT_TRUE(sbp_string_set_section(string_, &format_, 0, "maximum"));
  EXPECT_TRUE(sbp_string_set_section(string_, &format_, 1, "length"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 15);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 2);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "maximum");
  EXPECT_NE(sbp_string_get_section(string_, &format_, 1), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 1), "length");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 7);
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 1), 6);

  uint8_t buf[SBP_MAX_PAYLOAD_LEN];
  memset(buf, 'a', sizeof(buf));
  uint8_t expected[SBP_MAX_PAYLOAD_LEN];
  memset(expected, 'a', sizeof(expected));
  memcpy(expected, "maximum\0length\0", 15);

  EXPECT_EQ(sbp_string_pack(string_, &format_, buf, 15), 15);

  EXPECT_EQ(memcmp(buf, expected, sizeof(expected)), 0);
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 15);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 2);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "maximum");
  EXPECT_NE(sbp_string_get_section(string_, &format_, 1), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 1), "length");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 7);
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 1), 6);
}

TEST_F(TestStringMultipart_2_2, PackToTooSmallBuf)
{
  EXPECT_TRUE(sbp_string_set_section(string_, &format_, 0, "maximum"));
  EXPECT_TRUE(sbp_string_set_section(string_, &format_, 1, "length"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 15);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 2);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "maximum");
  EXPECT_NE(sbp_string_get_section(string_, &format_, 1), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 1), "length");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 7);
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 1), 6);

  uint8_t buf[SBP_MAX_PAYLOAD_LEN];
  memset(buf, 'a', sizeof(buf));
  uint8_t expected[SBP_MAX_PAYLOAD_LEN];
  memset(expected, 'a', sizeof(expected));

  EXPECT_EQ(sbp_string_pack(string_, &format_, buf, 2), 0);

  EXPECT_EQ(memcmp(buf, expected, sizeof(expected)), 0);
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 15);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 2);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "maximum");
  EXPECT_NE(sbp_string_get_section(string_, &format_, 1), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 1), "length");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 7);
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 1), 6);
}

TEST_F(TestStringMultipart_2_2, UnpackShort)
{
}
