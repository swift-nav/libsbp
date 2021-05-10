#include <gtest/gtest.h>
#include <libsbp/sbp.h>
#include <libsbp/string2.h>
#include <memory.h>
#include <string.h>

class TestStringNullTerminated : public ::testing::Test
{
public:
  TestStringNullTerminated() : ::testing::Test()
  {
    sbp_null_terminated_string_init(&string_, max_packed_len_);
  }

protected:
  sbp_null_terminated_string_t string_;
  uint8_t max_packed_len_ = 17;
};

TEST_F(TestStringNullTerminated, EmptyState)
{
  EXPECT_TRUE(sbp_null_terminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_null_terminated_string_packed_len(&string_, max_packed_len_), 1);
  EXPECT_NE(sbp_null_terminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_null_terminated_string_get(&string_, max_packed_len_), "");
}

TEST_F(TestStringNullTerminated, ShortState)
{
  strcpy(string_.data, "short");
  string_.len = 5;
  EXPECT_TRUE(sbp_null_terminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_null_terminated_string_packed_len(&string_, max_packed_len_), 6);
  EXPECT_NE(sbp_null_terminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_null_terminated_string_get(&string_, max_packed_len_), "short");
}

TEST_F(TestStringNullTerminated, MaxLenState)
{
  strcpy(string_.data, "exactly 16 bytes");
  string_.len = 16;
  EXPECT_TRUE(sbp_null_terminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_null_terminated_string_packed_len(&string_, max_packed_len_), 17);
  EXPECT_NE(sbp_null_terminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_null_terminated_string_get(&string_, max_packed_len_), "exactly 16 bytes");
}

TEST_F(TestStringNullTerminated, OversizeState)
{
  strcpy(string_.data, "a very long string which is much larger than the maximum encoded size of 16 bytes");
  string_.len = 80;
  EXPECT_FALSE(sbp_null_terminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_null_terminated_string_packed_len(&string_, max_packed_len_), 0);
  EXPECT_EQ(sbp_null_terminated_string_get(&string_, max_packed_len_), nullptr);
}

TEST_F(TestStringNullTerminated, SetShort)
{
  EXPECT_TRUE(sbp_null_terminated_string_set(&string_, "short", max_packed_len_));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_null_terminated_string_packed_len(&string_, max_packed_len_), 6);
  EXPECT_NE(sbp_null_terminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_null_terminated_string_get(&string_, max_packed_len_), "short");
}

TEST_F(TestStringNullTerminated, SetMaxLen)
{
  EXPECT_TRUE(sbp_null_terminated_string_set(&string_, "exactly 16 bytes", max_packed_len_));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_null_terminated_string_packed_len(&string_, max_packed_len_), 17);
  EXPECT_NE(sbp_null_terminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_null_terminated_string_get(&string_, max_packed_len_), "exactly 16 bytes");
}

TEST_F(TestStringNullTerminated, SetOversize)
{
  // First set a valid length string
  EXPECT_TRUE(sbp_null_terminated_string_set(&string_, "short", max_packed_len_));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_null_terminated_string_packed_len(&string_, max_packed_len_), 6);
  EXPECT_NE(sbp_null_terminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_null_terminated_string_get(&string_, max_packed_len_), "short");

  // Try to set an oversize string, it should fail and leave the string unmodified
  EXPECT_FALSE(sbp_null_terminated_string_set(
      &string_, "a very long string which is much larger than the maximum encoded size of 16 bytes", max_packed_len_));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_null_terminated_string_packed_len(&string_, max_packed_len_), 6);
  EXPECT_NE(sbp_null_terminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_null_terminated_string_get(&string_, max_packed_len_), "short");
}

TEST_F(TestStringNullTerminated, InitClearsInvalidState)
{
  strcpy(string_.data, "a very long string which is much larger than the maximum encoded size of 16 bytes");
  string_.len = 80;
  EXPECT_FALSE(sbp_null_terminated_string_valid(&string_, max_packed_len_));
  sbp_null_terminated_string_init(&string_, max_packed_len_);
  EXPECT_TRUE(sbp_null_terminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_null_terminated_string_packed_len(&string_, max_packed_len_), 1);
  EXPECT_NE(sbp_null_terminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_null_terminated_string_get(&string_, max_packed_len_), "");
}

TEST_F(TestStringNullTerminated, SetClearsInvalidState)
{
  strcpy(string_.data, "a very long string which is much larger than the maximum encoded size of 16 bytes");
  string_.len = 80;
  EXPECT_FALSE(sbp_null_terminated_string_valid(&string_, max_packed_len_));
  EXPECT_TRUE(sbp_null_terminated_string_set(&string_, "short", max_packed_len_));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_null_terminated_string_packed_len(&string_, max_packed_len_), 6);
  EXPECT_NE(sbp_null_terminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_null_terminated_string_get(&string_, max_packed_len_), "short");
}

TEST_F(TestStringNullTerminated, PackShort)
{
  EXPECT_TRUE(sbp_null_terminated_string_set(&string_, "short", max_packed_len_));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_null_terminated_string_packed_len(&string_, max_packed_len_), 6);
  EXPECT_NE(sbp_null_terminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_null_terminated_string_get(&string_, max_packed_len_), "short");

  uint8_t packed_buf[SBP_MAX_PAYLOAD_LEN];
  uint8_t expected[SBP_MAX_PAYLOAD_LEN];
  memset(packed_buf, 'a', sizeof(packed_buf));
  memset(expected, 'a', sizeof(expected));
  memcpy(expected, "short", 6);
  EXPECT_EQ(sbp_null_terminated_string_pack(&string_, max_packed_len_, packed_buf, sizeof(packed_buf)), 6);

  EXPECT_TRUE(sbp_null_terminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_null_terminated_string_packed_len(&string_, max_packed_len_), 6);
  EXPECT_NE(sbp_null_terminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_null_terminated_string_get(&string_, max_packed_len_), "short");

  EXPECT_EQ(memcmp(packed_buf, expected, sizeof(expected)), 0);
}

TEST_F(TestStringNullTerminated, PackMaxLen)
{
  EXPECT_TRUE(sbp_null_terminated_string_set(&string_, "exactly 16 bytes", max_packed_len_));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_null_terminated_string_packed_len(&string_, max_packed_len_), 17);
  EXPECT_NE(sbp_null_terminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_null_terminated_string_get(&string_, max_packed_len_), "exactly 16 bytes");

  uint8_t packed_buf[SBP_MAX_PAYLOAD_LEN];
  uint8_t expected[SBP_MAX_PAYLOAD_LEN];
  memset(packed_buf, 'a', sizeof(packed_buf));
  memset(expected, 'a', sizeof(expected));
  memcpy(expected, "exactly 16 bytes", 17);
  EXPECT_EQ(sbp_null_terminated_string_pack(&string_, max_packed_len_, packed_buf, sizeof(packed_buf)), 17);

  EXPECT_TRUE(sbp_null_terminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_null_terminated_string_packed_len(&string_, max_packed_len_), 17);
  EXPECT_NE(sbp_null_terminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_null_terminated_string_get(&string_, max_packed_len_), "exactly 16 bytes");

  EXPECT_EQ(memcmp(packed_buf, expected, sizeof(expected)), 0);
}

TEST_F(TestStringNullTerminated, PackIntoTooSmallBuf)
{
  EXPECT_TRUE(sbp_null_terminated_string_set(&string_, "short", max_packed_len_));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_null_terminated_string_packed_len(&string_, max_packed_len_), 6);
  EXPECT_NE(sbp_null_terminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_null_terminated_string_get(&string_, max_packed_len_), "short");

  uint8_t packed_buf[3];
  uint8_t expected[3];
  memset(packed_buf, 'a', sizeof(packed_buf));
  memset(expected, 'a', sizeof(expected));
  EXPECT_EQ(sbp_null_terminated_string_pack(&string_, max_packed_len_, packed_buf, sizeof(packed_buf)), 0);

  EXPECT_TRUE(sbp_null_terminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_null_terminated_string_packed_len(&string_, max_packed_len_), 6);
  EXPECT_NE(sbp_null_terminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_null_terminated_string_get(&string_, max_packed_len_), "short");

  // No change in packed buf
  EXPECT_EQ(memcmp(packed_buf, expected, sizeof(expected)), 0);
}

TEST_F(TestStringNullTerminated, UnpackNoBytes)
{
  EXPECT_TRUE(sbp_null_terminated_string_set(&string_, "short", max_packed_len_));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_null_terminated_string_packed_len(&string_, max_packed_len_), 6);
  EXPECT_NE(sbp_null_terminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_null_terminated_string_get(&string_, max_packed_len_), "short");

  // Unpacking 0 bytes should invalidate the existing string
  uint8_t packed_buf[1];
  EXPECT_EQ(sbp_null_terminated_string_unpack(&string_, max_packed_len_, packed_buf, 0), 0);
  EXPECT_EQ(sbp_null_terminated_string_packed_len(&string_, max_packed_len_), 1);
  EXPECT_NE(sbp_null_terminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_null_terminated_string_get(&string_, max_packed_len_), "");
}

TEST_F(TestStringNullTerminated, UnpackShorterString)
{
  EXPECT_TRUE(sbp_null_terminated_string_set(&string_, "exactly 16 bytes", max_packed_len_));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_null_terminated_string_packed_len(&string_, max_packed_len_), 17);
  EXPECT_NE(sbp_null_terminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_null_terminated_string_get(&string_, max_packed_len_), "exactly 16 bytes");

  uint8_t packed_buf[] = "short";
  EXPECT_EQ(sbp_null_terminated_string_unpack(&string_, max_packed_len_, packed_buf, 6), 6);
  EXPECT_EQ(sbp_null_terminated_string_packed_len(&string_, max_packed_len_), 6);
  EXPECT_NE(sbp_null_terminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_null_terminated_string_get(&string_, max_packed_len_), "short");
}

TEST_F(TestStringNullTerminated, UnpackMaxLen)
{
  EXPECT_TRUE(sbp_null_terminated_string_set(&string_, "short", max_packed_len_));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_null_terminated_string_packed_len(&string_, max_packed_len_), 6);
  EXPECT_STREQ(sbp_null_terminated_string_get(&string_, max_packed_len_), "short");

  uint8_t packed_buf[] = "exactly 16 bytes";
  EXPECT_EQ(sbp_null_terminated_string_unpack(&string_, max_packed_len_, packed_buf, 17), 17);
  EXPECT_EQ(sbp_null_terminated_string_packed_len(&string_, max_packed_len_), 17);
  EXPECT_NE(sbp_null_terminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_null_terminated_string_get(&string_, max_packed_len_), "exactly 16 bytes");
}

TEST_F(TestStringNullTerminated, UnpackMaxLenFromLongerBuf)
{
  EXPECT_TRUE(sbp_null_terminated_string_set(&string_, "exactly 16 bytes", max_packed_len_));
  EXPECT_TRUE(sbp_null_terminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_null_terminated_string_packed_len(&string_, max_packed_len_), 17);
  EXPECT_NE(sbp_null_terminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_null_terminated_string_get(&string_, max_packed_len_), "exactly 16 bytes");

  uint8_t packed_buf[] = "short\0this string should be left unpacked";
  EXPECT_EQ(sbp_null_terminated_string_unpack(&string_, max_packed_len_, packed_buf, sizeof(packed_buf)), 6);
  EXPECT_TRUE(sbp_null_terminated_string_valid(&string_, max_packed_len_));
  EXPECT_EQ(sbp_null_terminated_string_packed_len(&string_, max_packed_len_), 6);
  EXPECT_NE(sbp_null_terminated_string_get(&string_, max_packed_len_), nullptr);
  EXPECT_STREQ(sbp_null_terminated_string_get(&string_, max_packed_len_), "short");
}
