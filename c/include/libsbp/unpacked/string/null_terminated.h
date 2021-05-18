#ifndef LIBSBP_UNPACKED_STRING_NULL_TERMINATED_H
#define LIBSBP_UNPACKED_STRING_NULL_TERMINATED_H

#include <stdarg.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

  typedef struct
  {
    char data[255];
    uint8_t len;
  } sbp_null_terminated_string_t;

  void sbp_null_terminated_string_init(sbp_null_terminated_string_t *s, uint8_t max_packed_len);
  bool sbp_null_terminated_string_valid(const sbp_null_terminated_string_t *s, uint8_t max_packed_len);
  uint8_t sbp_null_terminated_string_packed_len(const sbp_null_terminated_string_t *s, uint8_t max_packed_len);
  bool sbp_null_terminated_string_set(sbp_null_terminated_string_t *s, const char *new_str, uint8_t max_packed_len);
  bool sbp_null_terminated_string_printf(sbp_null_terminated_string_t *s, uint8_t max_packed_len, const char *fmt, ...)
      __attribute__((format(printf, 3, 4)));
  bool sbp_null_terminated_string_vprintf(sbp_null_terminated_string_t *s, uint8_t max_packed_len, const char *fmt, va_list);
  const char *sbp_null_terminated_string_get(const sbp_null_terminated_string_t *s, uint8_t max_packed_len);
  int sbp_null_terminated_string_strcmp(const sbp_null_terminated_string_t *a,
                                        const sbp_null_terminated_string_t *b,
                                        uint8_t max_packed_len);

#ifdef __cplusplus
}
#endif

#endif
