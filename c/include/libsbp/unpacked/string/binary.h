#ifndef LIBSBP_UNPACKED_STRING_BINARY_H
#define LIBSBP_UNPACKED_STRING_BINARY_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
  char data[256];
  uint8_t len;
} sbp_binary_string_t;

void sbp_binary_string_init(sbp_binary_string_t *s, uint8_t max_packed_len);
bool sbp_binary_string_valid(const sbp_binary_string_t *s, uint8_t max_packed_len);
uint8_t sbp_binary_string_packed_len(const sbp_binary_string_t *s, uint8_t max_packed_len);
bool sbp_binary_string_set(sbp_binary_string_t *s, const char *new_str, uint8_t new_str_len, uint8_t max_packed_len);
const char * sbp_binary_string_get(const sbp_binary_string_t *s, uint8_t *len, uint8_t max_packed_len);
int sbp_binary_string_strcmp(const sbp_binary_string_t *a, const sbp_binary_string_t *b, uint8_t max_packed_len);

#ifdef __cplusplus
}
#endif

#endif
