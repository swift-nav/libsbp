#include <gtest/gtest.h>
#include <libsbp/sbp.h>
#include <libsbp/string2.h>
#include <memory.h>
#include <string.h>

#if 0
TEST(TestString, Unterminated) {
  sbp_string_format_t format{};
  format.encoding = SBP_STRING_UNTERMINATED;
  format.max_encoded_len = SBP_MAX_PAYLOAD_LEN;

  sbp_string_t string{};

  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_packed_len(string, &format), 0);
  EXPECT_EQ(sbp_string_section_len(string, &format, 0), 0);
  EXPECT_NE(sbp_string_get_section(string, &format, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "");
  EXPECT_EQ(sbp_string_get_section(string, &format, 1), nullptr);

  uint8_t buf[SBP_MAX_PAYLOAD_LEN]{};
  memset(buf, 'a', sizeof(buf));
  EXPECT_EQ(sbp_string_pack(string, &format, buf, sizeof(buf)), 0);
  EXPECT_EQ(buf[0], 'a');

  EXPECT_EQ(sbp_string_unpack(string, &format, buf, sizeof(buf)), SBP_MAX_PAYLOAD_LEN);
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_packed_len(string, &format), SBP_MAX_PAYLOAD_LEN);
  EXPECT_EQ(sbp_string_section_len(string, &format, 0), SBP_MAX_PAYLOAD_LEN);
  EXPECT_NE(sbp_string_get_section(string, &format, 0), nullptr);
  EXPECT_EQ(strlen(sbp_string_get_section(string, &format, 0)), SBP_MAX_PAYLOAD_LEN);
  EXPECT_EQ(memcmp(sbp_string_get_section(string, &format, 0), buf, SBP_MAX_PAYLOAD_LEN), 0);

  memset(buf, 'b', 4);
  EXPECT_EQ(sbp_string_unpack(string, &format, buf, 3), 3);
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_packed_len(string, &format), 3);
  EXPECT_EQ(sbp_string_section_len(string, &format, 0), 3);
  EXPECT_NE(sbp_string_get_section(string, &format, 0), nullptr);
  EXPECT_EQ(strlen(sbp_string_get_section(string, &format, 0)), 3);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "bbb");

  EXPECT_TRUE(sbp_string_set_section(string, &format, 0, "cc"));
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_packed_len(string, &format), 2);
  EXPECT_EQ(sbp_string_section_len(string, &format, 0), 2);
  EXPECT_NE(sbp_string_get_section(string, &format, 0), nullptr);
  EXPECT_EQ(strlen(sbp_string_get_section(string, &format, 0)), 2);
  EXPECT_EQ(sbp_string_pack(string, &format, buf, sizeof(buf)), 2);
  EXPECT_EQ(memcmp(buf, "ccbbaa", 6), 0);
}

TEST(TestString, NullTerminated) {
  sbp_string_format_t format{};
  format.encoding = SBP_STRING_NULL_TERMINATED;
  format.max_encoded_len = 100;

  sbp_string_t string{};

  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_packed_len(string, &format), 1);
  EXPECT_EQ(sbp_string_section_len(string, &format, 0), 0);
  EXPECT_NE(sbp_string_get_section(string, &format, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "");
  EXPECT_EQ(sbp_string_get_section(string, &format, 1), nullptr);

  uint8_t buf[SBP_MAX_PAYLOAD_LEN]{};
  memset(buf, 'a', sizeof(buf));
  EXPECT_EQ(sbp_string_pack(string, &format, buf, sizeof(buf)), 1);
  EXPECT_EQ(buf[0], 0);

  buf[0] = 'a';
  EXPECT_TRUE(sbp_string_set_section(string, &format, 0, "Hello, World!"));
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_packed_len(string, &format), 14);
  EXPECT_EQ(sbp_string_section_len(string, &format, 0), 13);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "Hello, World!");
  EXPECT_EQ(sbp_string_pack(string, &format, buf, sizeof(buf)), 14);
  EXPECT_EQ(memcmp(buf, "Hello, World!\0a", 15), 0);

  strcpy((char*)buf, "first");
  strcpy((char*)buf + 6, "second");
  EXPECT_EQ(sbp_string_unpack(string, &format, buf, sizeof(buf)), 6);
  EXPECT_EQ(sbp_string_packed_len(string, &format), 6);
  EXPECT_EQ(sbp_string_section_len(string, &format, 0), 5);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "first");
}

TEST(TestString, MultiPart2) {
  sbp_string_format_t format{};
  format.encoding = SBP_STRING_MULTIPART;
  format.min_sections = 2;
  format.max_sections = 2;
  format.max_encoded_len = 100;

  sbp_string_t string{};
  uint8_t buf[SBP_MAX_PAYLOAD_LEN];
  memset(buf, 'a', sizeof(buf));

  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_packed_len(string, &format), 2);
  EXPECT_EQ(sbp_string_section_len(string, &format, 0), 0);
  EXPECT_EQ(sbp_string_section_len(string, &format, 1), 0);
  EXPECT_EQ(sbp_string_section_len(string, &format, 2), 0);
  EXPECT_NE(sbp_string_get_section(string, &format, 0), nullptr);
  EXPECT_NE(sbp_string_get_section(string, &format, 1), nullptr);
  EXPECT_EQ(sbp_string_get_section(string, &format, 2), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "");
  EXPECT_STREQ(sbp_string_get_section(string, &format, 1), "");
  EXPECT_EQ(sbp_string_pack(string, &format, buf, sizeof(buf)), 2);
  EXPECT_EQ(memcmp(buf, "\0\0a", 3), 0);

  EXPECT_TRUE(sbp_string_set_section(string, &format, 0, "section"));
  EXPECT_EQ(sbp_string_packed_len(string, &format), 9);
  EXPECT_EQ(sbp_string_section_len(string, &format, 0), 7);
  EXPECT_EQ(sbp_string_section_len(string, &format, 1), 0);
  EXPECT_NE(sbp_string_get_section(string, &format, 0), nullptr);
  EXPECT_NE(sbp_string_get_section(string, &format, 1), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "section");
  EXPECT_STREQ(sbp_string_get_section(string, &format, 1), "");
  EXPECT_EQ(sbp_string_pack(string, &format, buf, sizeof(buf)), 9);
  EXPECT_EQ(memcmp(buf, "section\0\0a", 10), 0);

  EXPECT_TRUE(sbp_string_set_section(string, &format, 1, "setting"));
  EXPECT_EQ(sbp_string_packed_len(string, &format), 16);
  EXPECT_EQ(sbp_string_section_len(string, &format, 0), 7);
  EXPECT_EQ(sbp_string_section_len(string, &format, 1), 7);
  EXPECT_NE(sbp_string_get_section(string, &format, 0), nullptr);
  EXPECT_NE(sbp_string_get_section(string, &format, 1), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "section");
  EXPECT_STREQ(sbp_string_get_section(string, &format, 1), "setting");
  EXPECT_EQ(sbp_string_pack(string, &format, buf, sizeof(buf)), 16);
  EXPECT_EQ(memcmp(buf, "section\0setting\0a", 17), 0);
}

TEST(TestString, Sequence) {
  sbp_string_format_t format{};
  format.encoding = SBP_STRING_SEQUENCE;
  format.terminator = 0xFF;

  sbp_string_t string{};
  uint8_t buf[SBP_MAX_PAYLOAD_LEN];
  memset(buf, 'a', sizeof(buf));

  EXPECT_TRUE(sbp_string_valid(string, &format
}
#endif

TEST(TestString, UnterminatedAnalysis)
{
  sbp_string_t string;
  sbp_string_format_t format;

  // Empty string, should encode to 0 bytes
  format.encoding = SBP_STRING_UNTERMINATED;
  format.max_encoded_len = 16;
  strcpy(string, "");
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 1);
  EXPECT_EQ(sbp_string_section_len(string, &format, 0), 0);
  EXPECT_EQ(sbp_string_packed_len(string, &format), 0);
  EXPECT_NE(sbp_string_get_section(string, &format, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "");

  // A string shorter than the maximum encoded size
  strcpy(string, "short");
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 1);
  EXPECT_EQ(sbp_string_section_len(string, &format, 0), 5);
  EXPECT_EQ(sbp_string_packed_len(string, &format), 5);
  EXPECT_NE(sbp_string_get_section(string, &format, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "short");

  // A string exactly as long as the maximum encoded size
  strcpy(string, "exactly 16 bytes");
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 1);
  EXPECT_EQ(sbp_string_section_len(string, &format, 0), 16);
  EXPECT_EQ(sbp_string_packed_len(string, &format), 16);
  EXPECT_NE(sbp_string_get_section(string, &format, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "exactly 16 bytes");

  // A string longer than the maximum encoded size
  strcpy(string, "a very long string which is much larger than the maximum encoded size of 16 bytes");
  EXPECT_FALSE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 0);
  EXPECT_EQ(sbp_string_section_len(string, &format, 0), 0);
  EXPECT_EQ(sbp_string_packed_len(string, &format), 0);
  EXPECT_EQ(sbp_string_get_section(string, &format, 0), nullptr);
}

TEST(TestString, NullTerminatedAnalysis)
{
  sbp_string_t string;
  sbp_string_format_t format;

  // Empty string, should encode to 1 byte
  format.encoding = SBP_STRING_NULL_TERMINATED;
  format.max_encoded_len = 17;
  strcpy(string, "");
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 1);
  EXPECT_EQ(sbp_string_section_len(string, &format, 0), 0);
  EXPECT_EQ(sbp_string_packed_len(string, &format), 1);
  EXPECT_NE(sbp_string_get_section(string, &format, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "");

  // A string shorter than the maximum encoded size
  strcpy(string, "short");
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 1);
  EXPECT_EQ(sbp_string_section_len(string, &format, 0), 5);
  EXPECT_EQ(sbp_string_packed_len(string, &format), 6);
  EXPECT_NE(sbp_string_get_section(string, &format, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "short");

  // A string exactly as long as the maximum encoded size
  strcpy(string, "exactly 16 bytes");
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 1);
  EXPECT_EQ(sbp_string_section_len(string, &format, 0), 16);
  EXPECT_EQ(sbp_string_packed_len(string, &format), 17);
  EXPECT_NE(sbp_string_get_section(string, &format, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "exactly 16 bytes");

  // A string longer than the maximum encoded size
  strcpy(string, "a very long string which is much larger than the maximum encoded size of 16 bytes");
  EXPECT_FALSE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 0);
  EXPECT_EQ(sbp_string_section_len(string, &format, 0), 0);
  EXPECT_EQ(sbp_string_packed_len(string, &format), 0);
  EXPECT_EQ(sbp_string_get_section(string, &format, 0), nullptr);
}

TEST(TestString, MultiPartAnalysis_2_2)
{
  sbp_string_t string;
  sbp_string_format_t format;

  // Empty string. Should resolve to 2 0-length parts and an encoded size of 2
  format.encoding = SBP_STRING_MULTIPART;
  format.min_sections = 2;
  format.max_sections = 2;
  format.max_encoded_len = 20;
  memcpy(string, "\0\0", 2);
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 2);
  EXPECT_EQ(sbp_string_section_len(string, &format, 0), 0);
  EXPECT_EQ(sbp_string_section_len(string, &format, 1), 0);
  EXPECT_EQ(sbp_string_section_len(string, &format, 2), 0);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "");
  EXPECT_STREQ(sbp_string_get_section(string, &format, 1), "");
  EXPECT_EQ(sbp_string_get_section(string, &format, 2), nullptr);
  EXPECT_EQ(sbp_string_packed_len(string, &format), 2);

  // Has a first section and a zero length second section
  memcpy(string, "section\0\0", 9);
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 2);
  EXPECT_EQ(sbp_string_section_len(string, &format, 0), 7);
  EXPECT_EQ(sbp_string_section_len(string, &format, 1), 0);
  EXPECT_EQ(sbp_string_section_len(string, &format, 2), 0);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "section");
  EXPECT_STREQ(sbp_string_get_section(string, &format, 1), "");
  EXPECT_EQ(sbp_string_get_section(string, &format, 2), nullptr);
  EXPECT_EQ(sbp_string_packed_len(string, &format), 9);

  // Has a blank first section but a valid second section
  memcpy(string, "\0setting\0", 9);
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 2);
  EXPECT_EQ(sbp_string_section_len(string, &format, 0), 0);
  EXPECT_EQ(sbp_string_section_len(string, &format, 1), 7);
  EXPECT_EQ(sbp_string_section_len(string, &format, 2), 0);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "");
  EXPECT_STREQ(sbp_string_get_section(string, &format, 1), "setting");
  EXPECT_EQ(sbp_string_get_section(string, &format, 2), nullptr);
  EXPECT_EQ(sbp_string_packed_len(string, &format), 9);

  // Has both sections which are together shorter than the maximum encoded size
  memcpy(string, "section\0setting\0", 16);
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 2);
  EXPECT_EQ(sbp_string_section_len(string, &format, 0), 7);
  EXPECT_EQ(sbp_string_section_len(string, &format, 1), 7);
  EXPECT_EQ(sbp_string_section_len(string, &format, 2), 0);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "section");
  EXPECT_STREQ(sbp_string_get_section(string, &format, 1), "setting");
  EXPECT_EQ(sbp_string_get_section(string, &format, 2), nullptr);
  EXPECT_EQ(sbp_string_packed_len(string, &format), 16);

  // Both sections adds up to exactly the maximum size
  memcpy(string, "section12\0setting34\0", 20);
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 2);
  EXPECT_EQ(sbp_string_section_len(string, &format, 0), 9);
  EXPECT_EQ(sbp_string_section_len(string, &format, 1), 9);
  EXPECT_EQ(sbp_string_section_len(string, &format, 2), 0);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "section12");
  EXPECT_STREQ(sbp_string_get_section(string, &format, 1), "setting34");
  EXPECT_EQ(sbp_string_get_section(string, &format, 2), nullptr);
  EXPECT_EQ(sbp_string_packed_len(string, &format), 20);

  // Longer than the maximum encoded size
  memcpy(string, "a very long section\0and setting\0", 32);
  EXPECT_FALSE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 0);
  EXPECT_EQ(sbp_string_packed_len(string, &format), 0);
  EXPECT_EQ(sbp_string_get_section(string, &format, 0), nullptr);
}

TEST(TestString, MultiPartAnalysis_2_3)
{
  sbp_string_t string;
  sbp_string_format_t format;

  // Empty string. Should resolve to 2 0-length parts and an encoded size of 2. Optional 3rd part is not reported
  format.encoding = SBP_STRING_MULTIPART;
  format.min_sections = 2;
  format.max_sections = 3;
  format.max_encoded_len = 20;
  memcpy(string, "\0\0\0", 3);
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 2);
  EXPECT_EQ(sbp_string_section_len(string, &format, 0), 0);
  EXPECT_EQ(sbp_string_section_len(string, &format, 1), 0);
  EXPECT_EQ(sbp_string_section_len(string, &format, 2), 0);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "");
  EXPECT_STREQ(sbp_string_get_section(string, &format, 1), "");
  EXPECT_EQ(sbp_string_get_section(string, &format, 2), nullptr);
  EXPECT_EQ(sbp_string_packed_len(string, &format), 2);

  // Has a first section and a zero length second section. Optional 3rd part is not reported
  memcpy(string, "section\0\0\0", 10);
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 2);
  EXPECT_EQ(sbp_string_section_len(string, &format, 0), 7);
  EXPECT_EQ(sbp_string_section_len(string, &format, 1), 0);
  EXPECT_EQ(sbp_string_section_len(string, &format, 2), 0);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "section");
  EXPECT_STREQ(sbp_string_get_section(string, &format, 1), "");
  EXPECT_EQ(sbp_string_get_section(string, &format, 2), nullptr);
  EXPECT_EQ(sbp_string_packed_len(string, &format), 9);

  // Has a blank first section but a valid second section. Optional 3rd part is not reported
  memcpy(string, "\0setting\0\0", 10);
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 2);
  EXPECT_EQ(sbp_string_section_len(string, &format, 0), 0);
  EXPECT_EQ(sbp_string_section_len(string, &format, 1), 7);
  EXPECT_EQ(sbp_string_section_len(string, &format, 2), 0);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "");
  EXPECT_STREQ(sbp_string_get_section(string, &format, 1), "setting");
  EXPECT_EQ(sbp_string_get_section(string, &format, 2), nullptr);
  EXPECT_EQ(sbp_string_packed_len(string, &format), 9);

  // Has both sections which are together shorter than the maximum encoded size. Optional 3rd part is not reported
  memcpy(string, "section\0setting\0\0", 17);
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 2);
  EXPECT_EQ(sbp_string_section_len(string, &format, 0), 7);
  EXPECT_EQ(sbp_string_section_len(string, &format, 1), 7);
  EXPECT_EQ(sbp_string_section_len(string, &format, 2), 0);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "section");
  EXPECT_STREQ(sbp_string_get_section(string, &format, 1), "setting");
  EXPECT_EQ(sbp_string_get_section(string, &format, 2), nullptr);
  EXPECT_EQ(sbp_string_packed_len(string, &format), 16);

  // Both sections adds up to exactly the maximum size. Optional 3rd part is not reported
  memcpy(string, "section12\0setting34\0\0", 21);
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 2);
  EXPECT_EQ(sbp_string_section_len(string, &format, 0), 9);
  EXPECT_EQ(sbp_string_section_len(string, &format, 1), 9);
  EXPECT_EQ(sbp_string_section_len(string, &format, 2), 0);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "section12");
  EXPECT_STREQ(sbp_string_get_section(string, &format, 1), "setting34");
  EXPECT_EQ(sbp_string_get_section(string, &format, 2), nullptr);
  EXPECT_EQ(sbp_string_packed_len(string, &format), 20);

  // A string with all 3 parts present, under the maximum length
  format.max_encoded_len = 28;
  memcpy(string, "section\0setting\0value\0", 22);
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 3);
  EXPECT_EQ(sbp_string_section_len(string, &format, 0), 7);
  EXPECT_EQ(sbp_string_section_len(string, &format, 1), 7);
  EXPECT_EQ(sbp_string_section_len(string, &format, 2), 5);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "section");
  EXPECT_STREQ(sbp_string_get_section(string, &format, 1), "setting");
  EXPECT_STREQ(sbp_string_get_section(string, &format, 2), "value");
  EXPECT_EQ(sbp_string_packed_len(string, &format), 22);

  // A string with all 3 parts present, equal to the maximum length
  format.max_encoded_len = 28;
  memcpy(string, "section12\0setting34\0value56\0", 28);
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 3);
  EXPECT_EQ(sbp_string_section_len(string, &format, 0), 9);
  EXPECT_EQ(sbp_string_section_len(string, &format, 1), 9);
  EXPECT_EQ(sbp_string_section_len(string, &format, 2), 7);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "section12");
  EXPECT_STREQ(sbp_string_get_section(string, &format, 1), "setting34");
  EXPECT_STREQ(sbp_string_get_section(string, &format, 2), "value56");
  EXPECT_EQ(sbp_string_packed_len(string, &format), 28);
}

TEST(TestString, DoubleNullSequenceAnalysis)
{
  sbp_string_t string;
  sbp_string_format_t format;

  format.encoding = SBP_STRING_SEQUENCE;
  format.max_encoded_len = 9;
  format.terminator = 0;
  memcpy(string, "\0\0", 2);
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 0);
  EXPECT_EQ(sbp_string_packed_len(string, &format), 2);
  EXPECT_EQ(sbp_string_get_section(string, &format, 0), nullptr);

  memcpy(string, "one\0\0", 5);
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 1);
  EXPECT_EQ(sbp_string_section_len(string, &format, 0), 3);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "one");
  EXPECT_EQ(sbp_string_packed_len(string, &format), 5);

  memcpy(string, "one\0two\0\0", 9);
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 2);
  EXPECT_EQ(sbp_string_section_len(string, &format, 0), 3);
  EXPECT_EQ(sbp_string_section_len(string, &format, 1), 3);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "one");
  EXPECT_STREQ(sbp_string_get_section(string, &format, 1), "two");
  EXPECT_EQ(sbp_string_packed_len(string, &format), 9);

  memcpy(string, "one\0two\0three\0\0", 15);
  EXPECT_FALSE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 0);
  EXPECT_EQ(sbp_string_packed_len(string, &format), 0);
}

TEST(TestString, FFSequenceAnalysis)
{
  sbp_string_t string;
  sbp_string_format_t format;

  format.encoding = SBP_STRING_SEQUENCE;
  format.max_encoded_len = 9;
  format.terminator = (char)0xFF;
  memcpy(string, "\xFF", 1);
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 0);
  EXPECT_EQ(sbp_string_packed_len(string, &format), 1);

  memcpy(string, "one\0\xFF", 5);
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 1);
  EXPECT_EQ(sbp_string_packed_len(string, &format), 5);
}

TEST(TestString, UnterminatedSet)
{
  sbp_string_t string;
  sbp_string_format_t format;
  memset(string, 'a', sizeof(sbp_string_t));

  format.encoding = SBP_STRING_UNTERMINATED;
  format.max_encoded_len = 10;
  EXPECT_TRUE(sbp_string_set(string, &format, "hello"));
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_packed_len(string, &format), 5);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "hello");

  EXPECT_TRUE(sbp_string_set(string, &format, "hi"));
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_packed_len(string, &format), 2);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "hi");

  EXPECT_FALSE(sbp_string_set(string, &format, "far too long"));
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_packed_len(string, &format), 2);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "hi");
}

TEST(TestString, NullTerminatedSet)
{
  sbp_string_t string;
  sbp_string_format_t format;
  memset(string, 'a', sizeof(sbp_string_t));

  format.encoding = SBP_STRING_NULL_TERMINATED;
  format.max_encoded_len = 10;
  EXPECT_TRUE(sbp_string_set(string, &format, "hello"));
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_packed_len(string, &format), 6);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "hello");

  EXPECT_TRUE(sbp_string_set(string, &format, "hi"));
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_packed_len(string, &format), 3);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "hi");

  EXPECT_FALSE(sbp_string_set(string, &format, "far too long"));
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_packed_len(string, &format), 3);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "hi");
}

TEST(TestString, MultipartAppend_2_2)
{
  sbp_string_t string;
  sbp_string_format_t format;
  memset(string, 0, sizeof(sbp_string_t));

  format.encoding = SBP_STRING_MULTIPART;
  format.min_sections = 2;
  format.max_sections = 2;
  format.max_encoded_len = 41;
  EXPECT_TRUE(sbp_string_set_section(string, &format, 0, "section"));
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 2);
  EXPECT_EQ(sbp_string_packed_len(string, &format), 9);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "section");
  EXPECT_STREQ(sbp_string_get_section(string, &format, 1), "");

  EXPECT_TRUE(sbp_string_set_section(string, &format, 1, "setting"));
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 2);
  EXPECT_EQ(sbp_string_packed_len(string, &format), 16);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "section");
  EXPECT_STREQ(sbp_string_get_section(string, &format, 1), "setting");

  EXPECT_FALSE(sbp_string_set_section(string, &format, 2, "value"));
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 2);
  EXPECT_EQ(sbp_string_packed_len(string, &format), 16);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "section");
  EXPECT_STREQ(sbp_string_get_section(string, &format, 1), "setting");

  EXPECT_TRUE(sbp_string_set_section(string, &format, 0, "long section"));
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 2);
  EXPECT_EQ(sbp_string_packed_len(string, &format), 21);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "long section");
  EXPECT_STREQ(sbp_string_get_section(string, &format, 1), "setting");
}

TEST(TestString, MultipartAppend_2_3)
{
  sbp_string_t string;
  sbp_string_format_t format;
  memset(string, 0, sizeof(sbp_string_t));

  format.encoding = SBP_STRING_MULTIPART;
  format.min_sections = 2;
  format.max_sections = 3;
  format.max_encoded_len = 41;
  EXPECT_TRUE(sbp_string_set_section(string, &format, 0, "section"));
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 2);
  EXPECT_EQ(sbp_string_packed_len(string, &format), 9);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "section");
  EXPECT_STREQ(sbp_string_get_section(string, &format, 1), "");

  EXPECT_TRUE(sbp_string_set_section(string, &format, 1, "setting"));
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 2);
  EXPECT_EQ(sbp_string_packed_len(string, &format), 16);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "section");
  EXPECT_STREQ(sbp_string_get_section(string, &format, 1), "setting");

  EXPECT_TRUE(sbp_string_set_section(string, &format, 2, "value"));
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 3);
  EXPECT_EQ(sbp_string_packed_len(string, &format), 22);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "section");
  EXPECT_STREQ(sbp_string_get_section(string, &format, 1), "setting");
  EXPECT_STREQ(sbp_string_get_section(string, &format, 2), "value");

  EXPECT_TRUE(sbp_string_set_section(string, &format, 0, "long section"));
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 3);
  EXPECT_EQ(sbp_string_packed_len(string, &format), 27);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "long section");
  EXPECT_STREQ(sbp_string_get_section(string, &format, 1), "setting");
  EXPECT_STREQ(sbp_string_get_section(string, &format, 2), "value");

  EXPECT_TRUE(sbp_string_set_section(string, &format, 2, ""));
  EXPECT_TRUE(sbp_string_valid(string, &format));
  EXPECT_EQ(sbp_string_count_sections(string, &format), 2);
  EXPECT_EQ(sbp_string_packed_len(string, &format), 21);
  EXPECT_STREQ(sbp_string_get_section(string, &format, 0), "long section");
  EXPECT_STREQ(sbp_string_get_section(string, &format, 1), "setting");
}
