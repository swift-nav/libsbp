#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <libsbp/internal/v4/string/double_null_terminated.h>
#include <libsbp/internal/v4/string/sbp_string.h>
#include <libsbp/internal/v4/string/sbp_strnlen.h>

#define MINIMUM_ENCODED_LEN 2

static const sbp_string_params_t params = {
    .valid = sbp_double_null_terminated_string_valid,
    .init = sbp_double_null_terminated_string_init,
    .default_output = "\0", // Plus extra NULL terminator, total of 2 NULLs
    .default_output_len = MINIMUM_ENCODED_LEN,
    .inject_missing_terminator = false,
};

static void maybe_init(sbp_string_t *s, size_t maxlen) {
  if (!sbp_double_null_terminated_string_valid(s, maxlen)) {
    sbp_double_null_terminated_string_init(s);
  }
}

void sbp_double_null_terminated_string_init(sbp_string_t *s) {
  memset(s, 0, sizeof(*s));
  s->encoded_len = MINIMUM_ENCODED_LEN;
}

bool sbp_double_null_terminated_string_valid(const sbp_string_t *s,
                                             size_t maxlen) {
  if (s->encoded_len < MINIMUM_ENCODED_LEN) {
    return false;
  }
  if (s->encoded_len > maxlen) {
    return false;
  }
  return s->data[s->encoded_len - 1] == 0 && s->data[s->encoded_len - 2] == 0;
}

int sbp_double_null_terminated_string_strcmp(const sbp_string_t *a,
                                             const sbp_string_t *b,
                                             size_t maxlen) {
  return sbp_string_cmp(a, b, maxlen, &params);
}

size_t sbp_double_null_terminated_string_encoded_len(const sbp_string_t *s,
                                                     size_t maxlen) {
  if (!sbp_double_null_terminated_string_valid(s, maxlen)) {
    return MINIMUM_ENCODED_LEN;
  }
  return s->encoded_len;
}

size_t sbp_double_null_terminated_string_space_remaining(
    const sbp_string_t *s, size_t maxlen) {
  return maxlen -
         sbp_double_null_terminated_string_encoded_len(s, maxlen);
}

size_t sbp_double_null_terminated_string_count_sections(
    const sbp_string_t *s, size_t maxlen) {
  if (!sbp_double_null_terminated_string_valid(s, maxlen)) {
    return 0;
  }
  if (s->encoded_len == MINIMUM_ENCODED_LEN) {
    return 0;
  }
  // Only count up to one less than the encoded len to avoid the extra NULL
  // terminator, count NULL terminators
  size_t sections = 0;
  for (size_t i = 0; i < s->encoded_len - 1; i++) {
    if (s->data[i] == 0) {
      sections++;
    }
  }
  return sections;
}

static size_t section_offset(const sbp_string_t *s, size_t section) {
  size_t n_section = 0;
  for (size_t i = 0; i < s->encoded_len - 1; i++) {
    if (n_section == section) {
      return i;
    }
    if (s->data[i] == 0) {
      n_section++;
    }
  }
  return SIZE_MAX;
}

size_t sbp_double_null_terminated_string_section_strlen(const sbp_string_t *s,
                                                        size_t maxlen,
                                                        size_t section) {
  if (!sbp_double_null_terminated_string_valid(s, maxlen)) {
    return 0;
  }
  if (s->encoded_len == MINIMUM_ENCODED_LEN) {
    return 0;
  }
  size_t offset = section_offset(s, section);
  if (offset == SIZE_MAX) {
    return 0;
  }
  return sbp_strnlen(s->data + offset, s->encoded_len - offset);
}

bool sbp_double_null_terminated_string_add_section(sbp_string_t *s,
                                                   size_t maxlen,
                                                   const char *str) {
  maybe_init(s, maxlen);

  size_t copied;
  if (s->encoded_len == MINIMUM_ENCODED_LEN) {
    if (!sbp_string_copy_to_buf(s->data, &copied, maxlen - 1, str, sbp_strnlen(str, maxlen))) {
      return false;
    }
    s->encoded_len = copied + 1;  // Extra null terminator
    return true;
  }

  if (!sbp_string_copy_to_buf(s->data + s->encoded_len - 1, &copied,
                              maxlen - s->encoded_len + 1, str, sbp_strnlen(str, maxlen))) {
    return false;
  }
  s->encoded_len += copied;
  return true;
}

bool sbp_double_null_terminated_string_add_section_vprintf(
    sbp_string_t *s, size_t maxlen, const char *fmt, va_list ap) {
  maybe_init(s, maxlen);

  size_t copied;
  if (s->encoded_len == MINIMUM_ENCODED_LEN) {
    if (!sbp_string_vprintf_to_buf(s->data, &copied, maxlen - 1, false, fmt,
                                   ap)) {
      return false;
    }
    s->encoded_len = copied + 1;
    return true;
  }

  if (!sbp_string_vprintf_to_buf(s->data + s->encoded_len - 1, &copied,
                                 maxlen - s->encoded_len + 1, false, fmt,
                                 ap)) {
    return false;
  }
  s->encoded_len += copied;
  return true;
}

bool sbp_double_null_terminated_string_append(sbp_string_t *s,
                                              size_t maxlen,
                                              const char *new_str) {
  maybe_init(s, maxlen);
  if (s->encoded_len == MINIMUM_ENCODED_LEN) {
    return sbp_double_null_terminated_string_add_section(s, maxlen,
                                                         new_str);
  }

  size_t copied;
  if (!sbp_string_copy_to_buf(s->data + s->encoded_len - 2, &copied,
                              maxlen - s->encoded_len + 1, new_str, sbp_strnlen(new_str, maxlen))) {
    return false;
  }
  s->encoded_len += copied - 1;
  return true;
}

bool sbp_double_null_terminated_string_append_vprintf(sbp_string_t *s,
                                                      size_t maxlen,
                                                      const char *fmt,
                                                      va_list ap) {
  maybe_init(s, maxlen);
  if (s->encoded_len == MINIMUM_ENCODED_LEN) {
    return sbp_double_null_terminated_string_add_section_vprintf(
        s, maxlen, fmt, ap);
  }

  size_t copied;
  if (!sbp_string_vprintf_to_buf(s->data + s->encoded_len - 2, &copied,
                                 maxlen - s->encoded_len + 1, false, fmt,
                                 ap)) {
    return false;
  }
  s->encoded_len += copied - 1;
  return true;
}

const char *sbp_double_null_terminated_string_get_section(
    const sbp_string_t *s, size_t maxlen, size_t section) {
  if (!sbp_double_null_terminated_string_valid(s, maxlen)) {
    return NULL;
  }
  size_t offset = section_offset(s, section);
  if (offset == SIZE_MAX) {
    return NULL;
  }
  return s->data + offset;
}

bool sbp_double_null_terminated_string_encode(const sbp_string_t *s,
                                              size_t maxlen,
                                              sbp_encode_ctx_t *ctx) {
  return sbp_string_encode(s, maxlen, ctx, &params);
}

bool sbp_double_null_terminated_string_decode(sbp_string_t *s,
                                              size_t maxlen,
                                              sbp_decode_ctx_t *ctx) {
  return sbp_string_decode(s, maxlen, ctx, &params);
}
