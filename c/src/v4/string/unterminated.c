#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <libsbp/internal/v4/string/sbp_string.h>
#include <libsbp/internal/v4/string/sbp_strnlen.h>
#include <libsbp/internal/v4/string/unterminated.h>

static const sbp_string_params_t params = {
    .valid = sbp_unterminated_string_valid,
    .init = sbp_unterminated_string_init,
    .default_output = NULL,
    .default_output_len = 0,
    .inject_missing_terminator = false,
};

static void maybe_init(sbp_string_t *s, size_t maxlen) {
  if (!sbp_unterminated_string_valid(s, maxlen)) {
    sbp_unterminated_string_init(s);
  }
}

void sbp_unterminated_string_init(sbp_string_t *s) {
  memset(s, 0, sizeof(*s));
}

bool sbp_unterminated_string_valid(const sbp_string_t *s,
                                   size_t maxlen) {
  size_t n = sbp_strnlen(s->data, sizeof(s->data));
  if (n > maxlen) {
    return false;
  }
  if (n + 1 == s->encoded_len && s->data[n] == 0) {
    return true;
  }
  return n == s->encoded_len;
}

int sbp_unterminated_string_strcmp(const sbp_string_t *a, const sbp_string_t *b,
                                   size_t maxlen) {
  return sbp_string_cmp(a, b, maxlen, &params);
}

size_t sbp_unterminated_string_encoded_len(const sbp_string_t *s,
                                           size_t maxlen) {
  if (!sbp_unterminated_string_valid(s, maxlen) ||
      s->encoded_len == 0) {
    return 0;
  }
  return s->encoded_len - (s->data[s->encoded_len - 1] == 0 ? 1 : 0);
}

size_t sbp_unterminated_string_strlen(const sbp_string_t *s,
                                      size_t maxlen) {
  return sbp_unterminated_string_encoded_len(s, maxlen);
}

size_t sbp_unterminated_string_space_remaining(const sbp_string_t *s,
                                               size_t maxlen) {
  return maxlen -
         sbp_unterminated_string_encoded_len(s, maxlen);
}

bool sbp_unterminated_string_set(sbp_string_t *s, size_t maxlen,
                                 const char *new_str) {
  size_t copied;
  if (!sbp_string_copy_to_buf(s->data, &copied, maxlen + 1u,
                              new_str)) {
    return false;
  }
  s->encoded_len = copied - 1;
  return true;
}

bool sbp_unterminated_string_vprintf(sbp_string_t *s, size_t maxlen,
                                     const char *fmt, va_list ap) {
  size_t copied;
  if (!sbp_string_vprintf_to_buf(s->data, &copied, maxlen + 1u, fmt,
                                 ap)) {
    return false;
  }
  s->encoded_len = copied - 1;
  return true;
}

bool sbp_unterminated_string_append(sbp_string_t *s, size_t maxlen,
                                    const char *new_str) {
  maybe_init(s, maxlen);
  size_t copied;
  if (!sbp_string_copy_to_buf(s->data + s->encoded_len, &copied,
                              maxlen - s->encoded_len + 1, new_str)) {
    return false;
  }
  s->encoded_len += copied - 1;
  return true;
}

bool sbp_unterminated_string_append_vprintf(sbp_string_t *s,
                                            size_t maxlen,
                                            const char *fmt, va_list ap) {
  maybe_init(s, maxlen);
  size_t copied;
  if (!sbp_string_vprintf_to_buf(s->data + s->encoded_len, &copied,
                                 maxlen - s->encoded_len + 1, fmt,
                                 ap)) {
    return false;
  }
  s->encoded_len += copied - 1;
  return true;
}

const char *sbp_unterminated_string_get(const sbp_string_t *s,
                                        size_t maxlen) {
  if (!sbp_unterminated_string_valid(s, maxlen)) {
    return NULL;
  }
  return s->data;
}

bool sbp_unterminated_string_encode(const sbp_string_t *s,
                                    size_t maxlen,
                                    sbp_encode_ctx_t *ctx) {
  return sbp_string_encode(s, maxlen, ctx, &params);
}

bool sbp_unterminated_string_decode(sbp_string_t *s, size_t maxlen,
                                    sbp_decode_ctx_t *ctx) {
  return sbp_string_decode(s, maxlen, ctx, &params);
}
