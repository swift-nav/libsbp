#include <gtest/gtest.h>
#include <libsbp/sbp.h>
#include <memory.h>
#include <string.h>
#include <libsbp/string2.h>

class TestStringNullTerminated : public ::testing::Test {
  public:
    TestStringNullTerminated() : ::testing::Test() {
      format_.encoding = SBP_STRING_NULL_TERMINATED;
      format_.max_encoded_len = 17;
      sbp_string_init(string_, &format_);
    }

  protected:
    sbp_string_t string_;
    sbp_string_format_t format_;
};

TEST_F(TestStringNullTerminated, EmptyState) {
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 1);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 0);
}

TEST_F(TestStringNullTerminated, ShortState) {
  strcpy(string_, "short");
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 6);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "short");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 5);
}

TEST_F(TestStringNullTerminated, MaxLenState) {
  strcpy(string_, "exactly 16 bytes");
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 17);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "exactly 16 bytes");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 16);
}

TEST_F(TestStringNullTerminated, OversizeState) {
  strcpy(string_, "a very long string which is much larger than the maximum encoded size of 16 bytes");
  EXPECT_FALSE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 0);
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 0);
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 0);
  EXPECT_EQ(sbp_string_get_section(string_, &format_, 0), nullptr);
}

TEST_F(TestStringNullTerminated, SetShort) {
  EXPECT_TRUE(sbp_string_set(string_, &format_, "short"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 6);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "short");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 5);
}

TEST_F(TestStringNullTerminated, SetMaxLen) {
  EXPECT_TRUE(sbp_string_set(string_, &format_, "exactly 16 bytes"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 17);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "exactly 16 bytes");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 16);
}

TEST_F(TestStringNullTerminated, SetOversize) {
  // First set a valid length string
  EXPECT_TRUE(sbp_string_set(string_, &format_, "short"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 6);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "short");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 5);

  // Try to set an oversize string, it should fail and leave the string unmodified
  EXPECT_FALSE(sbp_string_set(string_, &format_, "a very long string which is much larger than the maximum encoded size of 16 bytes"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 6);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "short");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 5);
}

TEST_F(TestStringNullTerminated, InitClearsInvalidState) {
  strcpy(string_, "a very long string which is much larger than the maximum encoded size of 16 bytes");
  EXPECT_FALSE(sbp_string_valid(string_, &format_));
  sbp_string_init(string_, &format_);
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 1);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 0);
}

TEST_F(TestStringNullTerminated, SetClearsInvalidState) {
  strcpy(string_, "a very long string which is much larger than the maximum encoded size of 16 bytes");
  EXPECT_FALSE(sbp_string_valid(string_, &format_));
  EXPECT_TRUE(sbp_string_set(string_, &format_, "short"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 6);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "short");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 5);
}

TEST_F(TestStringNullTerminated, PackShort) {
  EXPECT_TRUE(sbp_string_set(string_, &format_, "short"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 6);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "short");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 5);

  uint8_t packed_buf[SBP_MAX_PAYLOAD_LEN];
  uint8_t expected[SBP_MAX_PAYLOAD_LEN];
  memset(packed_buf, 'a', sizeof(packed_buf));
  memset(expected, 'a', sizeof(expected));
  memcpy(expected, "short", 6);
  EXPECT_EQ(sbp_string_pack(string_, &format_, packed_buf, sizeof(packed_buf)), 6);

  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 6);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "short");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 5);

  EXPECT_EQ(memcmp(packed_buf, expected, sizeof(expected)), 0);
}

TEST_F(TestStringNullTerminated, PackMaxLen) {
  EXPECT_TRUE(sbp_string_set(string_, &format_, "exactly 16 bytes"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 17);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "exactly 16 bytes");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 16);

  uint8_t packed_buf[SBP_MAX_PAYLOAD_LEN];
  uint8_t expected[SBP_MAX_PAYLOAD_LEN];
  memset(packed_buf, 'a', sizeof(packed_buf));
  memset(expected, 'a', sizeof(expected));
  memcpy(expected, "exactly 16 bytes", 17);
  EXPECT_EQ(sbp_string_pack(string_, &format_, packed_buf, sizeof(packed_buf)), 17);

  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 17);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "exactly 16 bytes");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 16);

  EXPECT_EQ(memcmp(packed_buf, expected, sizeof(expected)), 0);
}

TEST_F(TestStringNullTerminated, PackIntoTooSmallBuf) {
  EXPECT_TRUE(sbp_string_set(string_, &format_, "short"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 6);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "short");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 5);

  uint8_t packed_buf[3];
  uint8_t expected[3];
  memset(packed_buf, 'a', sizeof(packed_buf));
  memset(expected, 'a', sizeof(expected));
  EXPECT_EQ(sbp_string_pack(string_, &format_, packed_buf, sizeof(packed_buf)), 0);

  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 6);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "short");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 5);

  // No change in packed buf
  EXPECT_EQ(memcmp(packed_buf, expected, sizeof(expected)), 0);
}

TEST_F(TestStringNullTerminated, UnpackNoBytes) {
  EXPECT_TRUE(sbp_string_set(string_, &format_, "short"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 6);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "short");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 5);

  // Unpacking 0 bytes should invalidate the existing string 
  uint8_t packed_buf[1];
  EXPECT_EQ(sbp_string_unpack(string_, &format_, packed_buf, 0), 0);
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 1);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 0);
}

TEST_F(TestStringNullTerminated, UnpackShorterString) {
  EXPECT_TRUE(sbp_string_set(string_, &format_, "exactly 16 bytes"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 17);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "exactly 16 bytes");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 16);

  uint8_t packed_buf[] = "short";
  EXPECT_EQ(sbp_string_unpack(string_, &format_, packed_buf, 6), 6);
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 6);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "short");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 5);
}

TEST_F(TestStringNullTerminated, UnpackMaxLen) {
  EXPECT_TRUE(sbp_string_set(string_, &format_, "short"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 6);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "short");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 5);

  uint8_t packed_buf[] = "exactly 16 bytes";
  EXPECT_EQ(sbp_string_unpack(string_, &format_, packed_buf, 17), 17);
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 17);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "exactly 16 bytes");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 16);
}

TEST_F(TestStringNullTerminated, UnpackMaxLenFromLongerBuf) {
  EXPECT_TRUE(sbp_string_set(string_, &format_, "exactly 16 bytes"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 17);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "exactly 16 bytes");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 16);

  uint8_t packed_buf[] = "short\0this string should be left unpacked";
  EXPECT_EQ(sbp_string_unpack(string_, &format_, packed_buf, sizeof(packed_buf)), 6);
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 6);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "short");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 5);
}

