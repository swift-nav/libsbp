#include <gtest/gtest.h>
#include <libsbp/v4/string/unterminated.h>
#include <libsbp/internal/v4/string/unterminated.h>

TEST(TestUnterminatedString, InitialState) {
  // The string buffer is zero'd out, it should still report as valid and have a packed length of 1
  sbp_unterminated_string_t s;
  memset(&s, 0, sizeof(s));

  sbp_unterminated_string_params_t short_params = {10};
  sbp_unterminated_string_params_t long_params = {100};
  sbp_unterminated_string_params_t max_params = {255};

  // Just to make sure that the internal length counter is set to a technically invalid state
  ASSERT_EQ(s.encoded_len, 0);

  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &short_params));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &long_params));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &max_params));

  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &short_params), 0);
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &long_params), 0);
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &max_params), 0);

  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &short_params), 0);
  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &long_params), 0);
  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &max_params), 0);

  EXPECT_EQ(sbp_unterminated_string_space_remaining(&s, &short_params), 10);
  EXPECT_EQ(sbp_unterminated_string_space_remaining(&s, &long_params), 100);
  EXPECT_EQ(sbp_unterminated_string_space_remaining(&s, &max_params), 255);

  EXPECT_STREQ(sbp_unterminated_string_get(&s, &short_params), "");
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &long_params), "");
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &max_params), "");
}

TEST(TestUnterminatedString, InvalidState) {
  // Various states the could potentially occur where the string buffer is invalid. This includes cases where it contains more than the allowed packed size, or where the buffer doesn't contain a NULL terminator in the right place
  sbp_unterminated_string_t s;
  memset(&s, 0, sizeof(s));

  sbp_unterminated_string_params_t short_params = {10};
  sbp_unterminated_string_params_t long_params = {100};
  sbp_unterminated_string_params_t max_params = {255};

  // First case, contains a valid 11 byte string (10 characters, 1 NULL terminator) which is invalid according to the short parameters but valid according to both the others
  strcpy(s.data, "aaaaaaaaaaa");
  s.encoded_len = 11;

  EXPECT_FALSE(sbp_unterminated_string_valid(&s, &short_params));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &long_params));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &max_params));

  // In this case the short params should force a packed size of 1 whereas the others with both be the full string
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &short_params), 0);
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &long_params), 11);
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &max_params), 11);

  // Likewise, the space remaining should be the full buffer for short params and the correct value for the others
  EXPECT_EQ(sbp_unterminated_string_space_remaining(&s, &short_params), 10);
  EXPECT_EQ(sbp_unterminated_string_space_remaining(&s, &long_params), 89);
  EXPECT_EQ(sbp_unterminated_string_space_remaining(&s, &max_params), 244);

  // We shouldn't be able to retrieve the string when using the invalid parameters
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &short_params), "");
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &long_params), "aaaaaaaaaaa");
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &max_params), "aaaaaaaaaaa");

  // Next we set the len field incorrectly, it should always point to a NULL terminator but in case it doesn't then everything will become invalid even when it ends up being less than the max packed length
  s.encoded_len = 9; // Points to the final 'a'
  EXPECT_FALSE(sbp_unterminated_string_valid(&s, &short_params));
  EXPECT_FALSE(sbp_unterminated_string_valid(&s, &long_params));
  EXPECT_FALSE(sbp_unterminated_string_valid(&s, &max_params));

  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &short_params), 0);
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &long_params), 0);
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &max_params), 0);

  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &short_params), 0);
  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &long_params), 0);
  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &max_params), 0);

  EXPECT_EQ(sbp_unterminated_string_space_remaining(&s, &short_params), 10);
  EXPECT_EQ(sbp_unterminated_string_space_remaining(&s, &long_params), 100);
  EXPECT_EQ(sbp_unterminated_string_space_remaining(&s, &max_params), 255);

  EXPECT_STREQ(sbp_unterminated_string_get(&s, &short_params), "");
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &long_params), "");
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &max_params), "");
}

TEST(TestUnterminatedString, Init) {
  // Test the init function. It should be able to reset everything no matter what state it's in
  sbp_unterminated_string_t s;

  sbp_unterminated_string_params_t params = {10};

  sbp_unterminated_string_init(&s, &params);
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &params), 0);
  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &params), 0);
  EXPECT_EQ(sbp_unterminated_string_space_remaining(&s, &params), 10);
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &params), "");
  EXPECT_EQ(s.encoded_len, 0);

  // Put in a valid string
  strcpy(s.data, "abcd");
  s.encoded_len = 4;

  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &params), 4);
  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &params), 4);
  EXPECT_EQ(sbp_unterminated_string_space_remaining(&s, &params), 6);
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &params), "abcd");

  // And reinitialise
  sbp_unterminated_string_init(&s, &params);
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &params), 0);
  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &params), 0);
  EXPECT_EQ(sbp_unterminated_string_space_remaining(&s, &params), 10);
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &params), "");
  EXPECT_EQ(s.encoded_len, 0);

  // Put in an invalid string
  strcpy(s.data, "aaaaaaaaaaa");
  s.encoded_len = 11;

  EXPECT_FALSE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &params), 0);
  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &params), 0);
  EXPECT_EQ(sbp_unterminated_string_space_remaining(&s, &params), 10);
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &params), "");
  EXPECT_EQ(s.encoded_len, 11);

  // And reinitialise
  sbp_unterminated_string_init(&s, &params);
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &params), 0);
  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &params), 0);
  EXPECT_EQ(sbp_unterminated_string_space_remaining(&s, &params), 10);
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &params), "");
  EXPECT_EQ(s.encoded_len, 0);
}

TEST(TestUnterminatedString, Set)
{
  // A variety of cases for the set function
  sbp_unterminated_string_t s;

  sbp_unterminated_string_params_t params = {20};

  sbp_unterminated_string_init(&s, &params);

  // Put in a valid string
  EXPECT_TRUE(sbp_unterminated_string_set(&s, &params, "Hello, World!"));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &params), 13);
  EXPECT_EQ(sbp_unterminated_string_space_remaining(&s, &params), 7);
  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &params), 13);
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &params), "Hello, World!");

  // Overwrite with another valid string
  EXPECT_TRUE(sbp_unterminated_string_set(&s, &params, "Goodbye, World!"));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &params), 15);
  EXPECT_EQ(sbp_unterminated_string_space_remaining(&s, &params), 5);
  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &params), 15);
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &params), "Goodbye, World!");

  // Try to overwrite with an invalid string, it should fail and leave the original string intact
  EXPECT_FALSE(sbp_unterminated_string_set(&s, &params, "A string which is far too long for the buffer"));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &params), 15);
  EXPECT_EQ(sbp_unterminated_string_space_remaining(&s, &params), 5);
  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &params), 15);
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &params), "Goodbye, World!");

  // Setting an invalid buffer clears everything
  EXPECT_TRUE(sbp_unterminated_string_set(&s, &params, "Hello, World!"));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &params), 13);
  EXPECT_EQ(sbp_unterminated_string_space_remaining(&s, &params), 7);
  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &params), 13);
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &params), "Hello, World!");
}

TEST(TestUnterminatedString, Printf)
{
  // Some test cases for the printf function

  sbp_unterminated_string_t s;

  sbp_unterminated_string_params_t params = {20};

  sbp_unterminated_string_init(&s, &params);

  auto vprintf_wrapper = [&s, &params](const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    bool ret = sbp_unterminated_string_vprintf(&s, &params, fmt, ap);
    va_end(ap);
    return ret;
  };

  // A valid string
  EXPECT_TRUE(vprintf_wrapper("%s", "Hello, World!"));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &params), 13);
  EXPECT_EQ(sbp_unterminated_string_space_remaining(&s, &params), 7);
  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &params), 13);
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &params), "Hello, World!");

  // Overwrite with another valid string
  EXPECT_TRUE(vprintf_wrapper("%d %d %d %d", 1, 2, 3, 4));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &params), 7);
  EXPECT_EQ(sbp_unterminated_string_space_remaining(&s, &params), 13);
  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &params), 7);
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &params), "1 2 3 4");

  // Overwrite with something which would be too long, this will unfortunately corrupt the original string
  EXPECT_FALSE(vprintf_wrapper("%d %d %d %d %d %d %d %d %d %d.", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &params), 0);
  EXPECT_EQ(sbp_unterminated_string_space_remaining(&s, &params), 20);
  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &params), 0);
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &params), "");

  // Printing in to an invalid buffer clears everything
  EXPECT_TRUE(vprintf_wrapper("%s", "Hello, World!"));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &params), 13);
  EXPECT_EQ(sbp_unterminated_string_space_remaining(&s, &params), 7);
  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &params), 13);
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &params), "Hello, World!");
}

TEST(TestUnterminatedString, Append)
{
  // Some cases for appending a string to a buffer
  sbp_unterminated_string_t s;

  sbp_unterminated_string_params_t params = {20};

  sbp_unterminated_string_init(&s, &params);

  // Appending in to an empty buffer is a valid operation, essentially the same as calling set
  EXPECT_TRUE(sbp_unterminated_string_append(&s, &params, "Hello"));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &params), 5);
  EXPECT_EQ(sbp_unterminated_string_space_remaining(&s, &params), 15);
  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &params), 5);
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &params), "Hello");

  // Similarly, appending to an uninitialised buffer will initialise it
  memset(&s, 0, sizeof(s));
  EXPECT_TRUE(sbp_unterminated_string_append(&s, &params, "Hello"));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &params), 5);
  EXPECT_EQ(sbp_unterminated_string_space_remaining(&s, &params), 15);
  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &params), 5);
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &params), "Hello");

  // Appending a valid string
  EXPECT_TRUE(sbp_unterminated_string_append(&s, &params, ", World!"));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &params), 13);
  EXPECT_EQ(sbp_unterminated_string_space_remaining(&s, &params), 7);
  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &params), 13);
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &params), "Hello, World!");

  // But it isn't allowed to overrun
  EXPECT_FALSE(sbp_unterminated_string_append(&s, &params, "12345678"));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &params), 13);
  EXPECT_EQ(sbp_unterminated_string_space_remaining(&s, &params), 7);
  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &params), 13);
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &params), "Hello, World!");
}

TEST(TestUnterminatedString, AppendPrintf)
{
  // Some cases for appending a formatted string to a buffer
  sbp_unterminated_string_t s;

  sbp_unterminated_string_params_t params = {20};

  sbp_unterminated_string_init(&s, &params);

  auto vprintf_wrapper = [&s, &params](const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    bool ret = sbp_unterminated_string_append_vprintf(&s, &params, fmt, ap);
    va_end(ap);
    return ret;
  };

  // Appending in to an empty buffer is a valid operation, essentially the same as calling set
  EXPECT_TRUE(vprintf_wrapper("%d %d", 1, 2));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &params), 3);
  EXPECT_EQ(sbp_unterminated_string_space_remaining(&s, &params), 17);
  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &params), 3);
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &params), "1 2");

  // Similarly, appending to an uninitialised buffer will initialise it
  memset(&s, 0, sizeof(s));
  EXPECT_TRUE(vprintf_wrapper("%d %d", 1, 2));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &params), 3);
  EXPECT_EQ(sbp_unterminated_string_space_remaining(&s, &params), 17);
  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &params), 3);
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &params), "1 2");

  // Appending a valid string
  EXPECT_TRUE(vprintf_wrapper(" %d %d", 3, 4));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &params), 7);
  EXPECT_EQ(sbp_unterminated_string_space_remaining(&s, &params), 13);
  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &params), 7);
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &params), "1 2 3 4");

  // Up to the maximum
  EXPECT_TRUE(vprintf_wrapper(" %d %d %d %d %d %d", 5, 6, 7, 8, 9, 10));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &params), 20);
  EXPECT_EQ(sbp_unterminated_string_space_remaining(&s, &params), 0);
  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &params), 20);
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &params), "1 2 3 4 5 6 7 8 9 10");

  // But isn't allowed to overrun
  // Wind back a little bit
  s.encoded_len = 7;
  s.data[7] = 0;
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &params), 7);
  EXPECT_EQ(sbp_unterminated_string_space_remaining(&s, &params), 13);
  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &params), 7);
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &params), "1 2 3 4");

  EXPECT_FALSE(vprintf_wrapper(" %d %d %d %d %d %d.", 5, 6, 7, 8, 9, 10));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &params), 7);
  EXPECT_EQ(sbp_unterminated_string_space_remaining(&s, &params), 13);
  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &params), 7);
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &params), "1 2 3 4");
}

TEST(TestUnterminatedString, Pack)
{
  sbp_unterminated_string_t s;
  sbp_unterminated_string_params_t short_params = {10};
  sbp_unterminated_string_params_t long_params = {20};

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

  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &short_params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &short_params), 0);
  EXPECT_TRUE(sbp_unterminated_string_pack(&s, &short_params, &ctx));
  EXPECT_EQ(ctx.offset, 0);
  for (uint8_t i = 0; i < 30; i++) EXPECT_EQ(payload[i], 0xCC); // Nothing modified

  // Pack an initialised and empty string
  memset(payload, 0xCC, sizeof(payload));
  ctx.offset = 0;
  ctx.buf_len = 30;

  sbp_unterminated_string_init(&s, &short_params);
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &short_params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &short_params), 0);
  EXPECT_TRUE(sbp_unterminated_string_pack(&s, &short_params, &ctx));
  EXPECT_EQ(ctx.offset, 0);
  for (uint8_t i = 1; i < 30; i++) EXPECT_EQ(payload[i], 0xCC); // Nothing modified

  // Pack a string which is less than the remaining payload size
  memset(payload, 0xCC, sizeof(payload));
  ctx.offset = 0;
  ctx.buf_len = 30;

  EXPECT_TRUE(sbp_unterminated_string_set(&s, &long_params, "Hello, World!"));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &long_params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &long_params), 13);
  EXPECT_TRUE(sbp_unterminated_string_pack(&s, &long_params, &ctx));
  EXPECT_EQ(ctx.offset, 13);
  EXPECT_EQ(memcmp(payload, "Hello, World!", 13), 0);
  for (uint8_t i = 13; i < 30; i++) EXPECT_EQ(payload[i], 0xCC);

  // Pack a maximal sized string which is less than the remaining payload size
  memset(payload, 0xCC, sizeof(payload));
  ctx.offset = 0;
  ctx.buf_len = 30;

  EXPECT_TRUE(sbp_unterminated_string_set(&s, &long_params, "Hello, World!!!!!!!!"));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &long_params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &long_params), 20);
  EXPECT_TRUE(sbp_unterminated_string_pack(&s, &long_params, &ctx));
  EXPECT_EQ(ctx.offset, 20);
  EXPECT_EQ(memcmp(payload, "Hello, World!!!!!!!!", 20), 0);
  for (uint8_t i = 20; i < 30; i++) EXPECT_EQ(payload[i], 0xCC);

  // Pack a string which is exactly as long as the payload buffer
  memset(payload, 0xCC, sizeof(payload));
  ctx.offset = 0;
  ctx.buf_len = 13;

  EXPECT_TRUE(sbp_unterminated_string_set(&s, &long_params, "Hello, World!"));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &long_params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &long_params), 13);
  EXPECT_TRUE(sbp_unterminated_string_pack(&s, &long_params, &ctx));
  EXPECT_EQ(ctx.offset, 13);
  EXPECT_EQ(memcmp(payload, "Hello, World!", 13), 0);
  for (uint8_t i = 13; i < 30; i++) EXPECT_EQ(payload[i], 0xCC);

  // Pack a string which overruns the available space in the payload buffer
  memset(payload, 0xCC, sizeof(payload));
  ctx.offset = 0;
  ctx.buf_len = 10;

  EXPECT_TRUE(sbp_unterminated_string_set(&s, &long_params, "Hello, World!"));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &long_params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &long_params), 13);
  EXPECT_FALSE(sbp_unterminated_string_pack(&s, &long_params, &ctx));
  EXPECT_EQ(ctx.offset, 0);
  for (uint8_t i = 0; i < 30; i++) EXPECT_EQ(payload[i], 0xCC);

  // Pack a string at an offset in to the payload buffer
  memset(payload, 0xCC, sizeof(payload));
  memset(payload + 20, 0xDD, 10);
  ctx.offset = 10;
  ctx.buf_len = 30;

  EXPECT_TRUE(sbp_unterminated_string_set(&s, &long_params, "Hello, World!"));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &long_params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &long_params), 13);
  EXPECT_TRUE(sbp_unterminated_string_pack(&s, &long_params, &ctx));
  EXPECT_EQ(ctx.offset, 23);
  for (uint8_t i = 0; i < 10; i++) EXPECT_EQ(payload[i], 0xCC);
  EXPECT_EQ(memcmp(payload + 10, "Hello, World!", 13), 0);
  for (uint8_t i = 23; i < 30; i++) EXPECT_EQ(payload[i], 0xDD);
}

TEST(TestUnterminatedString, Unpack)
{
  sbp_unterminated_string_t s;
  sbp_unterminated_string_params_t params = {5};

  uint8_t payload[10];
  sbp_decode_ctx_t ctx;
  ctx.buf = payload;

  // Pack in to an uninitialised buffer
  memset(&s, 0, sizeof(s));
  memcpy(payload, "abcd", 4);
  ctx.buf_len = 4;
  ctx.offset = 0;
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_TRUE(sbp_unterminated_string_unpack(&s, &params, &ctx));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &params), 4);
  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &params), 4);
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &params), "abcd");
  EXPECT_EQ(ctx.offset, 4);

  // Pack in to an initialised but empty buffer
  memcpy(payload, "abcd", 4);
  ctx.buf_len = 4;
  ctx.offset = 0;
  sbp_unterminated_string_init(&s, &params);
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_TRUE(sbp_unterminated_string_unpack(&s, &params, &ctx));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &params), 4);
  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &params), 4);
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &params), "abcd");
  EXPECT_EQ(ctx.offset, 4);

  // Overwrite a previously valid string
  memcpy(payload, "abcd", 4);
  ctx.buf_len = 4;
  ctx.offset = 0;
  EXPECT_TRUE(sbp_unterminated_string_set(&s, &params, "zzzzz"));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_TRUE(sbp_unterminated_string_unpack(&s, &params, &ctx));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &params), 4);
  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &params), 4);
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &params), "abcd");
  EXPECT_EQ(ctx.offset, 4);

  // Unpack a short string
  memcpy(payload, "ab", 2);
  ctx.buf_len = 2;
  ctx.offset = 0;
  EXPECT_TRUE(sbp_unterminated_string_set(&s, &params, "zzzzz"));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_TRUE(sbp_unterminated_string_unpack(&s, &params, &ctx));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &params), 2);
  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &params), 2);
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &params), "ab");
  EXPECT_EQ(ctx.offset, 2);

  // Fail to unpack a string where there is more data left in the payload buffer
  memcpy(payload, "abcdefghi", 10);
  ctx.buf_len = 10;
  ctx.offset = 0;
  EXPECT_TRUE(sbp_unterminated_string_set(&s, &params, "zzzzz"));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_FALSE(sbp_unterminated_string_unpack(&s, &params, &ctx));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &params), 0);
  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &params), 0);
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &params), "");
  EXPECT_EQ(ctx.offset, 0); // No data consumed

  // Unpack from an offset in the payload buffer
  memcpy(payload, "abcdefghi", 10);
  ctx.buf_len = 10;
  ctx.offset = 6;
  EXPECT_TRUE(sbp_unterminated_string_set(&s, &params, "zzzzz"));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_TRUE(sbp_unterminated_string_unpack(&s, &params, &ctx));
  EXPECT_TRUE(sbp_unterminated_string_valid(&s, &params));
  EXPECT_EQ(sbp_unterminated_string_encoded_len(&s, &params), 4);
  EXPECT_EQ(sbp_unterminated_string_strlen(&s, &params), 4);
  EXPECT_STREQ(sbp_unterminated_string_get(&s, &params), "ghi");
  EXPECT_EQ(ctx.offset, 10);
}

