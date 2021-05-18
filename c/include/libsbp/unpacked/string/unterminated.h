#ifndef LIBSBP_UNPACKED_STRING_UNTERMINATED_H
#define LIBSBP_UNPACKED_STRING_UNTERMINATED_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

  typedef struct
  {
    char data[256];
    uint8_t len;
  } sbp_unterminated_string_t;

  void sbp_unterminated_string_init(sbp_unterminated_string_t *s, uint8_t max_packed_len);
  bool sbp_unterminated_string_valid(const sbp_unterminated_string_t *s, uint8_t max_packed_len);
  uint8_t sbp_unterminated_string_packed_len(const sbp_unterminated_string_t *s, uint8_t max_packed_len);
  bool sbp_unterminated_string_set(sbp_unterminated_string_t *s, const char *new_str, uint8_t max_packed_len);
  bool sbp_unterminated_string_printf(sbp_unterminated_string_t *s, uint8_t max_packed_len, const char *fmt, ...)
      __attribute__((format(printf, 3, 4)));
  bool sbp_unterminated_string_vprintf(sbp_unterminated_string_t *s, uint8_t max_packed_len, const char *fmt, va_list ap);
  const char *sbp_unterminated_string_get(const sbp_unterminated_string_t *s, uint8_t max_packed_len);
  int sbp_unterminated_string_strcmp(const sbp_unterminated_string_t *a,
                                     const sbp_unterminated_string_t *b,
                                     uint8_t max_packed_len);

#ifdef __cplusplus
}
#endif

#endif
