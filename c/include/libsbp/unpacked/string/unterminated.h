#ifndef LIBSBP_UNPACKED_STRING_UNTERMINATED_H
#define LIBSBP_UNPACKED_STRING_UNTERMINATED_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include <libsbp/sbp.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
  char data[SBP_MAX_PAYLOAD_LEN + 1];
  size_t len;
} sbp_unterminated_string_t;

typedef struct {
  uint8_t max_encoded_len;
} sbp_unterminated_string_format_t;

void sbp_unterminated_string_init(sbp_unterminated_string_t *string, const sbp_unterminated_string_format_t *format);
size_t sbp_unterminated_string_packed_len(const sbp_unterminated_string_t *string, const sbp_unterminated_string_format_t *format);
size_t sbp_unterminated_string_strlen(const sbp_unterminated_string_t *string, const sbp_unterminated_string_format_t *format);
bool sbp_unterminated_string_set(sbp_unterminated_string_t *string, const sbp_unterminated_string_format_t *format, const char *new_string);
int sbp_unterminated_string_printf(sbp_unterminated_string_t *string, const sbp_unterminated_string_format_t *format, const char *fmt, ...);
int sbp_unterminated_string_vprintf(sbp_unterminated_string_t *string, const sbp_unterminated_string_format_t *format, const char *fmt, va_list ap);
const char *sbp_unterminated_string_get(const sbp_unterminated_string_t *string, const sbp_unterminated_string_format_t *format);


#ifdef __cplusplus
}
#endif

#endif
