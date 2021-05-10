#include <gtest/gtest.h>
#include <libsbp/sbp.h>
#include <libsbp/string2.h>
#include <memory.h>
#include <string.h>

class TestStringUnterminated : public ::testing::Test
{
public:
  TestStringUnterminated() : ::testing::Test()
  {
    sbp_unterminated_string_init(&string_, max_packed_len_);
  }

protected:
  uint8_t max_packed_len_ = 16;
  sbp_unterminated_string_t string_;
};

TEST_F(TestStringUnterminated, EmptyState)
{
  EXPECT_TRUE(sbp_unterminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_unterminated_string_packed_len(&string_, max_packed_len_), 0);
  EXPECT_NE(sbp_unterminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_unterminated_string_get(&string_, max_packed_len_), "");
}

TEST_F(TestStringUnterminated, ShortState)
{
  strcpy(string_.data, "short");
  string_.len = 5;
  EXPECT_TRUE(sbp_unterminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_unterminated_string_packed_len(&string_, max_packed_len_), 5);
  EXPECT_NE(sbp_unterminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_unterminated_string_get(&string_, max_packed_len_), "short");
}

TEST_F(TestStringUnterminated, MaxLenState)
{
  strcpy(string_.data, "exactly 16 bytes");
  string_.len = 16;
  EXPECT_TRUE(sbp_unterminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_unterminated_string_packed_len(&string_, max_packed_len_), 16);
  EXPECT_NE(sbp_unterminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_unterminated_string_get(&string_, max_packed_len_), "exactly 16 bytes");
}

TEST_F(TestStringUnterminated, OversizeState)
{
  strcpy(string_.data, "a very long string which is much larger than the maximum encoded size of 16 bytes");
  string_.len = 80;
  EXPECT_FALSE(sbp_unterminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_unterminated_string_packed_len(&string_, max_packed_len_), 0);
  EXPECT_EQ(sbp_unterminated_string_get(&string_, max_packed_len_), nullptr);
}

TEST_F(TestStringUnterminated, SetShort)
{
  EXPECT_TRUE(sbp_unterminated_string_set(&string_, "short", 5));
  EXPECT_TRUE(sbp_unterminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_unterminated_string_packed_len(&string_, max_packed_len_), 5);
  EXPECT_NE(sbp_unterminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_unterminated_string_get(&string_, max_packed_len_), "short");
}

TEST_F(TestStringUnterminated, SetMaxLen)
{
  EXPECT_TRUE(sbp_unterminated_string_set(&string_, "exactly 16 bytes", 16));
  EXPECT_TRUE(sbp_unterminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_unterminated_string_packed_len(&string_, max_packed_len_), 16);
  EXPECT_NE(sbp_unterminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_unterminated_string_get(&string_, max_packed_len_), "exactly 16 bytes");
}

TEST_F(TestStringUnterminated, SetOversize)
{
  // First set a valid length string
  EXPECT_TRUE(sbp_unterminated_string_set(&string_, "short", 5));
  EXPECT_TRUE(sbp_unterminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_unterminated_string_packed_len(&string_, max_packed_len_), 5);
  EXPECT_NE(sbp_unterminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_unterminated_string_get(&string_, max_packed_len_), "short");

  // Try to set an oversize string, it should fail and leave the string unmodified
  EXPECT_FALSE(sbp_unterminated_string_set(
      &string_, "a very long string which is much larger than the maximum encoded size of 16 bytes", 80));
  EXPECT_TRUE(sbp_unterminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_unterminated_string_packed_len(&string_, max_packed_len_), 5);
  EXPECT_NE(sbp_unterminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_unterminated_string_get(&string_, max_packed_len_), "short");
}

TEST_F(TestStringUnterminated, InitClearsInvalidState)
{
  strcpy(string_.data, "a very long string which is much larger than the maximum encoded size of 16 bytes");
  string_.len = 80;
  EXPECT_FALSE(sbp_unterminated_string_valid(&string_, max_packed_len_));
  sbp_unterminated_string_init(&string_, 16);
  EXPECT_TRUE(sbp_unterminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_unterminated_string_packed_len(&string_, max_packed_len_), 0);
  EXPECT_NE(sbp_unterminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_unterminated_string_get(&string_, max_packed_len_), "");
}

TEST_F(TestStringUnterminated, SetClearsInvalidState)
{
  strcpy(string_.data, "a very long string which is much larger than the maximum encoded size of 16 bytes");
  string_.len = 80;
  EXPECT_FALSE(sbp_unterminated_string_valid(&string_, max_packed_len_));
  EXPECT_TRUE(sbp_unterminated_string_set(&string_, "short", 5));
  EXPECT_TRUE(sbp_unterminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_unterminated_string_packed_len(&string_, max_packed_len_), 5);
  EXPECT_NE(sbp_unterminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_unterminated_string_get(&string_, max_packed_len_), "short");
}

TEST_F(TestStringUnterminated, PackShort)
{
  EXPECT_TRUE(sbp_unterminated_string_set(&string_, "short", 5));
  EXPECT_TRUE(sbp_unterminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_unterminated_string_packed_len(&string_, max_packed_len_), 5);
  EXPECT_NE(sbp_unterminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_unterminated_string_get(&string_, max_packed_len_), "short");

  uint8_t packed_buf[SBP_MAX_PAYLOAD_LEN];
  uint8_t expected[SBP_MAX_PAYLOAD_LEN];
  memset(packed_buf, 'a', sizeof(packed_buf));
  memset(expected, 'a', sizeof(expected));
  memcpy(expected, "short", 5);
  EXPECT_EQ(sbp_unterminated_string_pack(&string_, max_packed_len_, packed_buf, sizeof(packed_buf)), 5);

  EXPECT_TRUE(sbp_unterminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_unterminated_string_packed_len(&string_, max_packed_len_), 5);
  EXPECT_NE(sbp_unterminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_unterminated_string_get(&string_, max_packed_len_), "short");

  EXPECT_EQ(memcmp(packed_buf, expected, sizeof(expected)), 0);
}

TEST_F(TestStringUnterminated, PackMaxLen)
{
  EXPECT_TRUE(sbp_unterminated_string_set(&string_, "exactly 16 bytes", 16));
  EXPECT_TRUE(sbp_unterminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_unterminated_string_packed_len(&string_, max_packed_len_), 16);
  EXPECT_NE(sbp_unterminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_unterminated_string_get(&string_, max_packed_len_), "exactly 16 bytes");

  uint8_t packed_buf[SBP_MAX_PAYLOAD_LEN];
  uint8_t expected[SBP_MAX_PAYLOAD_LEN];
  memset(packed_buf, 'a', sizeof(packed_buf));
  memset(expected, 'a', sizeof(expected));
  memcpy(expected, "exactly 16 bytes", 16);
  EXPECT_EQ(sbp_unterminated_string_pack(&string_, max_packed_len_, packed_buf, sizeof(packed_buf)), 16);

  EXPECT_TRUE(sbp_unterminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_unterminated_string_packed_len(&string_, max_packed_len_), 16);
  EXPECT_NE(sbp_unterminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_unterminated_string_get(&string_, max_packed_len_), "exactly 16 bytes");

  EXPECT_EQ(memcmp(packed_buf, expected, sizeof(expected)), 0);
}

TEST_F(TestStringUnterminated, PackIntoTooSmallBuf)
{
  EXPECT_TRUE(sbp_unterminated_string_set(&string_, "short", 5));
  EXPECT_TRUE(sbp_unterminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_unterminated_string_packed_len(&string_, max_packed_len_), 5);
  EXPECT_NE(sbp_unterminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_unterminated_string_get(&string_, max_packed_len_), "short");

  uint8_t packed_buf[3];
  uint8_t expected[3];
  memset(packed_buf, 'a', sizeof(packed_buf));
  memset(expected, 'a', sizeof(expected));
  EXPECT_EQ(sbp_unterminated_string_pack(&string_, max_packed_len_, packed_buf, sizeof(packed_buf)), 0);

  EXPECT_TRUE(sbp_unterminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_unterminated_string_packed_len(&string_, max_packed_len_), 5);
  EXPECT_NE(sbp_unterminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_unterminated_string_get(&string_, max_packed_len_), "short");

  // No change in packed buf
  EXPECT_EQ(memcmp(packed_buf, expected, sizeof(expected)), 0);
}

TEST_F(TestStringUnterminated, UnpackNoBytes)
{
  EXPECT_TRUE(sbp_unterminated_string_set(&string_, "short", 5));
  EXPECT_TRUE(sbp_unterminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_unterminated_string_packed_len(&string_, max_packed_len_), 5);
  EXPECT_NE(sbp_unterminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_unterminated_string_get(&string_, max_packed_len_), "short");

  // Unpacking 0 bytes should invalidate the existing string
  uint8_t packed_buf[1];
  EXPECT_EQ(sbp_unterminated_string_unpack(&string_, max_packed_len_, packed_buf, 0), 0);
  EXPECT_EQ(sbp_unterminated_string_packed_len(&string_, max_packed_len_), 0);
  EXPECT_NE(sbp_unterminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_unterminated_string_get(&string_, max_packed_len_), "");
}

TEST_F(TestStringUnterminated, UnpackShorterString)
{
  EXPECT_TRUE(sbp_unterminated_string_set(&string_, "exactly 16 bytes", 16));
  EXPECT_TRUE(sbp_unterminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_unterminated_string_packed_len(&string_, max_packed_len_), 16);
  EXPECT_NE(sbp_unterminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_unterminated_string_get(&string_, max_packed_len_), "exactly 16 bytes");

  uint8_t packed_buf[] = "short";
  EXPECT_EQ(sbp_unterminated_string_unpack(&string_, max_packed_len_, packed_buf, 5), 5);
  EXPECT_EQ(sbp_unterminated_string_packed_len(&string_, max_packed_len_), 5);
  EXPECT_NE(sbp_unterminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_unterminated_string_get(&string_, max_packed_len_), "short");
}

TEST_F(TestStringUnterminated, UnpackMaxLen)
{
  EXPECT_TRUE(sbp_unterminated_string_set(&string_, "short", 5));
  EXPECT_TRUE(sbp_unterminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_unterminated_string_packed_len(&string_, max_packed_len_), 5);
  EXPECT_NE(sbp_unterminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_unterminated_string_get(&string_, max_packed_len_), "short");

  uint8_t packed_buf[] = "exactly 16 bytes";
  EXPECT_EQ(sbp_unterminated_string_unpack(&string_, max_packed_len_, packed_buf, 16), 16);
  EXPECT_EQ(sbp_unterminated_string_packed_len(&string_, max_packed_len_), 16);
  EXPECT_NE(sbp_unterminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_unterminated_string_get(&string_, max_packed_len_), "exactly 16 bytes");
}

TEST_F(TestStringUnterminated, UnpackMaxLenFromLongerBuf)
{
  EXPECT_TRUE(sbp_unterminated_string_set(&string_, "short", 5));
  EXPECT_TRUE(sbp_unterminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_unterminated_string_packed_len(&string_, max_packed_len_), 5);
  EXPECT_NE(sbp_unterminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_unterminated_string_get(&string_, max_packed_len_), "short");

  uint8_t packed_buf[] = "a lot more than 16 bytes";
  EXPECT_EQ(sbp_unterminated_string_unpack(&string_, max_packed_len_, packed_buf, sizeof(packed_buf)), 16);
  EXPECT_EQ(sbp_unterminated_string_packed_len(&string_, max_packed_len_), 16);
  EXPECT_NE(sbp_unterminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_unterminated_string_get(&string_, max_packed_len_), "a lot more than ");
}
