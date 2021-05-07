#ifndef SBP_STRING_H
#define SBP_STRING_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum {
  SBP_STRING_UNTERMINATED,
  SBP_STRING_NULL_TERMINATED,
  SBP_STRING_MULTIPART,
  SBP_STRING_SEQUENCE,
} sbp_string_encoding_type_t;

typedef struct {
  sbp_string_encoding_type_t encoding;
  uint8_t min_sections;
  uint8_t max_sections;
  char terminator;
  uint8_t max_encoded_len;
} sbp_string_format_t;

typedef char  sbp_string_t[256];

bool sbp_string_valid(const sbp_string_t string, const sbp_string_format_t *format);
uint8_t sbp_string_packed_len(const sbp_string_t string, const sbp_string_format_t *format);
uint8_t sbp_string_section_len(const sbp_string_t string, const sbp_string_format_t *format, uint8_t section);
bool sbp_string_set_section(sbp_string_t string, const sbp_string_format_t *format, uint8_t section, const char *str);
bool sbp_string_append_section(sbp_string_t string, const sbp_string_format_t *format, const char *str);
bool sbp_string_set(sbp_string_t string, const sbp_string_format_t *format, const char *str);
const char *sbp_string_get_section(const sbp_string_t string, const sbp_string_format_t *format, uint8_t section);
uint8_t sbp_string_pack(const sbp_string_t string, const sbp_string_format_t *format, uint8_t *buf, uint8_t buf_len);
uint8_t sbp_string_unpack(sbp_string_t string, const sbp_string_format_t *format, const uint8_t *buf, uint8_t buf_len);
uint8_t sbp_string_count_sections(const sbp_string_t string, const sbp_string_format_t *format);
uint8_t sbp_string_space_remaining(const sbp_string_t string, const sbp_string_format_t *format);
void sbp_string_init(sbp_string_t string, const sbp_string_format_t *format);

#ifdef __cplusplus
}
#endif

#endif
