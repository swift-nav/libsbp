#include <gtest/gtest.h>
#include <libsbp/sbp.h>
#include <memory.h>
#include <string.h>
#include <libsbp/string2.h>

class TestStringUnterminated : public ::testing::Test {
  public:
    TestStringUnterminated() : ::testing::Test() {
      format_.encoding = SBP_STRING_UNTERMINATED;
      format_.max_encoded_len = 16;
      sbp_string_init(string_, &format_);
    }

  protected:
    sbp_string_t string_;
    sbp_string_format_t format_;
};

TEST_F(TestStringUnterminated, EmptyState) {
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 0);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 0);
}

TEST_F(TestStringUnterminated, ShortState) {
  strcpy(string_, "short");
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 5);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "short");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 5);
}

TEST_F(TestStringUnterminated, MaxLenState) {
  strcpy(string_, "exactly 16 bytes");
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 16);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "exactly 16 bytes");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 16);
}

TEST_F(TestStringUnterminated, OversizeState) {
  strcpy(string_, "a very long string which is much larger than the maximum encoded size of 16 bytes");
  EXPECT_FALSE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 0);
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 0);
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 0);
  EXPECT_EQ(sbp_string_get_section(string_, &format_, 0), nullptr);
}

TEST_F(TestStringUnterminated, SetShort) {
  EXPECT_TRUE(sbp_string_set(string_, &format_, "short"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 5);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "short");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 5);
}

TEST_F(TestStringUnterminated, SetMaxLen) {
  EXPECT_TRUE(sbp_string_set(string_, &format_, "exactly 16 bytes"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 16);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "exactly 16 bytes");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 16);
}

TEST_F(TestStringUnterminated, SetOversize) {
  // First set a valid length string
  EXPECT_TRUE(sbp_string_set(string_, &format_, "short"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 5);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "short");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 5);

  // Try to set an oversize string, it should fail and leave the string unmodified
  EXPECT_FALSE(sbp_string_set(string_, &format_, "a very long string which is much larger than the maximum encoded size of 16 bytes"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 5);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "short");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 5);
}

TEST_F(TestStringUnterminated, InitClearsInvalidState) {
  strcpy(string_, "a very long string which is much larger than the maximum encoded size of 16 bytes");
  EXPECT_FALSE(sbp_string_valid(string_, &format_));
  sbp_string_init(string_, &format_);
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 0);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 0);
}

TEST_F(TestStringUnterminated, SetClearsInvalidState) {
  strcpy(string_, "a very long string which is much larger than the maximum encoded size of 16 bytes");
  EXPECT_FALSE(sbp_string_valid(string_, &format_));
  EXPECT_TRUE(sbp_string_set(string_, &format_, "short"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 5);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "short");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 5);
}

TEST_F(TestStringUnterminated, PackShort) {
  EXPECT_TRUE(sbp_string_set(string_, &format_, "short"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 5);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "short");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 5);

  uint8_t packed_buf[SBP_MAX_PAYLOAD_LEN];
  uint8_t expected[SBP_MAX_PAYLOAD_LEN];
  memset(packed_buf, 'a', sizeof(packed_buf));
  memset(expected, 'a', sizeof(expected));
  memcpy(expected, "short", 5);
  EXPECT_EQ(sbp_string_pack(string_, &format_, packed_buf, sizeof(packed_buf)), 5);

  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 5);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "short");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 5);

  EXPECT_EQ(memcmp(packed_buf, expected, sizeof(expected)), 0);
}

TEST_F(TestStringUnterminated, PackMaxLen) {
  EXPECT_TRUE(sbp_string_set(string_, &format_, "exactly 16 bytes"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 16);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "exactly 16 bytes");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 16);

  uint8_t packed_buf[SBP_MAX_PAYLOAD_LEN];
  uint8_t expected[SBP_MAX_PAYLOAD_LEN];
  memset(packed_buf, 'a', sizeof(packed_buf));
  memset(expected, 'a', sizeof(expected));
  memcpy(expected, "exactly 16 bytes", 16);
  EXPECT_EQ(sbp_string_pack(string_, &format_, packed_buf, sizeof(packed_buf)), 16);

  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 16);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "exactly 16 bytes");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 16);

  EXPECT_EQ(memcmp(packed_buf, expected, sizeof(expected)), 0);
}

TEST_F(TestStringUnterminated, PackIntoTooSmallBuf) {
  EXPECT_TRUE(sbp_string_set(string_, &format_, "short"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 5);
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
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 5);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "short");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 5);

  // No change in packed buf
  EXPECT_EQ(memcmp(packed_buf, expected, sizeof(expected)), 0);
}

TEST_F(TestStringUnterminated, UnpackNoBytes) {
  EXPECT_TRUE(sbp_string_set(string_, &format_, "short"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 5);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "short");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 5);

  // Unpacking 0 bytes should invalidate the existing string 
  uint8_t packed_buf[1];
  EXPECT_EQ(sbp_string_unpack(string_, &format_, packed_buf, 0), 0);
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 0);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 0);
}

TEST_F(TestStringUnterminated, UnpackShorterString) {
  EXPECT_TRUE(sbp_string_set(string_, &format_, "exactly 16 bytes"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 16);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "exactly 16 bytes");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 16);

  uint8_t packed_buf[] = "short";
  EXPECT_EQ(sbp_string_unpack(string_, &format_, packed_buf, 5), 5);
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 5);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "short");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 5);
}

TEST_F(TestStringUnterminated, UnpackMaxLen) {
  EXPECT_TRUE(sbp_string_set(string_, &format_, "short"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 5);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "short");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 5);

  uint8_t packed_buf[] = "exactly 16 bytes";
  EXPECT_EQ(sbp_string_unpack(string_, &format_, packed_buf, 16), 16);
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 16);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "exactly 16 bytes");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 16);
}

TEST_F(TestStringUnterminated, UnpackMaxLenFromLongerBuf) {
  EXPECT_TRUE(sbp_string_set(string_, &format_, "short"));
  EXPECT_TRUE(sbp_string_valid(string_, &format_));
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 5);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "short");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 5);

  uint8_t packed_buf[] = "a lot more than 16 bytes";
  EXPECT_EQ(sbp_string_unpack(string_, &format_, packed_buf, sizeof(packed_buf)), 16);
  EXPECT_EQ(sbp_string_packed_len(string_, &format_), 16);
  EXPECT_EQ(sbp_string_count_sections(string_, &format_), 1);
  EXPECT_NE(sbp_string_get_section(string_, &format_, 0), nullptr);
  EXPECT_STREQ(sbp_string_get_section(string_, &format_, 0), "a lot more than ");
  EXPECT_EQ(sbp_string_section_len(string_, &format_, 0), 16);
}
