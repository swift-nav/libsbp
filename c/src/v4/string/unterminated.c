#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <libsbp/internal/v4/string/sbp_string.h>
#include <libsbp/internal/v4/string/sbp_strnlen.h>
#include <libsbp/internal/v4/string/unterminated.h>

static const sbp_string_params_t params = {
    sbp_unterminated_string_valid,
    sbp_unterminated_string_init,
    NULL,
    0,
    SBP_FALSE,
};

static void maybe_init(sbp_string_t *s, size_t maxlen) {
  if (!sbp_unterminated_string_valid(s, maxlen)) {
    sbp_unterminated_string_init(s);
  }
}

void sbp_unterminated_string_init(sbp_string_t *s) {
  memset(s, 0, sizeof(*s));
}

SBP_BOOL sbp_unterminated_string_valid(const sbp_string_t *s,
                                   size_t maxlen) {
  size_t n = sbp_strnlen(s->data, sizeof(s->data));
  if (n > maxlen) {
    return SBP_FALSE;
  }
  if (n + 1 == s->encoded_len && s->data[n] == 0) {
    return SBP_TRUE;
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

SBP_BOOL sbp_unterminated_string_set_raw(sbp_string_t *s, size_t maxlen,
                                   SBP_BOOL should_trunc, size_t *n_written,
                                   const char *new_buf, size_t new_buf_len) {
  size_t copied;
  size_t truncated_len = maxlen > new_buf_len ? new_buf_len : maxlen;
  size_t len = should_trunc ? truncated_len : new_buf_len;

  if (!sbp_string_copy_to_buf(s->data, &copied, maxlen + 1u,
                              new_buf, len)) {
    return SBP_FALSE;
  }
  s->encoded_len = copied - 1;

  if (n_written != NULL) {
    *n_written = s->encoded_len;
  }
  return SBP_TRUE;
}

SBP_BOOL sbp_unterminated_string_set(sbp_string_t *s, size_t maxlen,
                                   SBP_BOOL should_trunc, size_t *n_written, const char *new_str) {
  return sbp_unterminated_string_set_raw(s, maxlen, should_trunc, n_written, new_str, sbp_strnlen(new_str, maxlen+1));
}

SBP_BOOL sbp_unterminated_string_vprintf(sbp_string_t *s, size_t maxlen, SBP_BOOL should_trunc, size_t *n_written,
                                     const char *fmt, va_list ap) {
  size_t copied;
  if (!sbp_string_vprintf_to_buf(s->data, &copied, maxlen + 1u, should_trunc, fmt,
                                 ap)) {
    return SBP_FALSE;
  }
  s->encoded_len = copied - 1;
  
  if (n_written != NULL) {
    *n_written = s->encoded_len;
  }
  return SBP_TRUE;
}

SBP_BOOL sbp_unterminated_string_append(sbp_string_t *s, size_t maxlen,
                                    const char *new_str) {
  size_t copied;
  maybe_init(s, maxlen);
  if (!sbp_string_copy_to_buf(s->data + s->encoded_len, &copied,
                              maxlen - s->encoded_len + 1, new_str, sbp_strnlen(new_str, maxlen))) {
    return SBP_FALSE;
  }
  s->encoded_len += copied - 1;
  return SBP_TRUE;
}

SBP_BOOL sbp_unterminated_string_append_vprintf(sbp_string_t *s,
                                            size_t maxlen, SBP_BOOL should_trunc, size_t *n_written,
                                            const char *fmt, va_list ap) {
  size_t copied;
  maybe_init(s, maxlen);
  if (!sbp_string_vprintf_to_buf(s->data + s->encoded_len, &copied,
                                 maxlen - s->encoded_len + 1, should_trunc, fmt,
                                 ap)) {
    return SBP_FALSE;
  }
  s->encoded_len += copied - 1;
  
  if (n_written != NULL) {
    *n_written = copied - 1;
  }
  return SBP_TRUE;
}

const char *sbp_unterminated_string_get(const sbp_string_t *s,
                                        size_t maxlen) {
  if (!sbp_unterminated_string_valid(s, maxlen)) {
    return NULL;
  }
  return s->data;
}

SBP_BOOL sbp_unterminated_string_encode(const sbp_string_t *s,
                                    size_t maxlen,
                                    sbp_encode_ctx_t *ctx) {
  return sbp_string_encode(s, maxlen, ctx, &params);
}

SBP_BOOL sbp_unterminated_string_decode(sbp_string_t *s, size_t maxlen,
                                    sbp_decode_ctx_t *ctx) {
  return sbp_string_decode(s, maxlen, ctx, &params);
}
