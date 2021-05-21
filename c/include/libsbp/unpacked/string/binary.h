#ifndef LIBSBP_UNPACKED_STRING_BINARY_H
#define LIBSBP_UNPACKED_STRING_BINARY_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

  typedef struct
  {
    char data[256];
    uint8_t packed_len;
  } sbp_binary_string_t;

  typedef struct
  {
    uint8_t max_packed_len;
  } sbp_binary_string_params_t;

  void sbp_binary_string_init(sbp_binary_string_t *s, const sbp_binary_string_params_t *params);
  bool sbp_binary_string_valid(const sbp_binary_string_t *s, const sbp_binary_string_params_t *params);
  int sbp_binary_string_strcmp(const sbp_binary_string_t *a,
                               const sbp_binary_string_t *b,
                               const sbp_binary_string_params_t *params);
  uint8_t sbp_binary_string_packed_len(const sbp_binary_string_t *s, const sbp_binary_string_params_t *params);
  uint8_t sbp_binary_string_space_remaining(const sbp_binary_string_t *s, const sbp_binary_string_params_t *params);
  bool sbp_binary_string_set(sbp_binary_string_t *s,
                             const sbp_binary_string_params_t *params,
                             const char *new_str,
                             uint8_t new_str_len);
  const char *
  sbp_binary_string_get(const sbp_binary_string_t *s, const sbp_binary_string_params_t *params, uint8_t *len);

#ifdef __cplusplus
}
#endif

#endif
