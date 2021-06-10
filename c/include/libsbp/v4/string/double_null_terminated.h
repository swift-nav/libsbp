#ifndef LIBSBP_V4_STRING_DOUBLE_NULL_TERMINATED_H
#define LIBSBP_V4_STRING_DOUBLE_NULL_TERMINATED_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>

#include <libsbp/common.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SBP_DOUBLE_NULL_TERMINATED_STRING_MAX_SECTIONS 20

  typedef struct
  {
    char data[255];
    uint8_t n_sections;
    uint8_t offsets[SBP_DOUBLE_NULL_TERMINATED_STRING_MAX_SECTIONS];
    uint8_t lens[SBP_DOUBLE_NULL_TERMINATED_STRING_MAX_SECTIONS];
    uint8_t encoded_len;
  } sbp_double_null_terminated_string_t;

  typedef struct
  {
    uint8_t max_encoded_len;
  } sbp_double_null_terminated_string_params_t;

  void sbp_double_null_terminated_string_init(sbp_double_null_terminated_string_t *s, const sbp_double_null_terminated_string_params_t *params);
  bool sbp_double_null_terminated_string_valid(const sbp_double_null_terminated_string_t *s, const sbp_double_null_terminated_string_params_t *params);
  int sbp_double_null_terminated_string_strcmp(const sbp_double_null_terminated_string_t *a,
                                  const sbp_double_null_terminated_string_t *b,
                                  const sbp_double_null_terminated_string_params_t *params);
  uint8_t sbp_double_null_terminated_string_encoded_len(const sbp_double_null_terminated_string_t *s, const sbp_double_null_terminated_string_params_t *params);
  uint8_t sbp_double_null_terminated_string_space_remaining(const sbp_double_null_terminated_string_t *s,
                                               const sbp_double_null_terminated_string_params_t *params);
  uint8_t sbp_double_null_terminated_string_count_sections(const sbp_double_null_terminated_string_t *s,
                                              const sbp_double_null_terminated_string_params_t *params);
  bool sbp_double_null_terminated_string_add_section(sbp_double_null_terminated_string_t *s,
                                        const sbp_double_null_terminated_string_params_t *params,
                                        const char *str);
  bool sbp_double_null_terminated_string_add_section_printf(sbp_double_null_terminated_string_t *s,
                                               const sbp_double_null_terminated_string_params_t *params,
                                               const char *fmt,
                                               ...) SBP_ATTR_FORMAT(3, 4);
  bool sbp_double_null_terminated_string_add_section_vprintf(sbp_double_null_terminated_string_t *s,
                                                const sbp_double_null_terminated_string_params_t *params,
                                                const char *fmt,
                                                va_list ap);

  bool sbp_double_null_terminated_string_append(sbp_double_null_terminated_string_t *s,
                                   const sbp_double_null_terminated_string_params_t *params,
                                   const char *new_str);
  bool sbp_double_null_terminated_string_append_printf(sbp_double_null_terminated_string_t *s,
                                          const sbp_double_null_terminated_string_params_t *params,
                                          const char *fmt,
                                          ...) SBP_ATTR_FORMAT(3, 4);
  bool sbp_double_null_terminated_string_append_vprintf(sbp_double_null_terminated_string_t *s,
                                           const sbp_double_null_terminated_string_params_t *params,
                                           const char *fmt,
                                           va_list ap);
  const char *sbp_double_null_terminated_string_get_section(const sbp_double_null_terminated_string_t *s,
                                               const sbp_double_null_terminated_string_params_t *params,
                                               uint8_t section);
  uint8_t sbp_double_null_terminated_string_section_strlen(const sbp_double_null_terminated_string_t *s,
                                              const sbp_double_null_terminated_string_params_t *params,
                                              uint8_t section);

#ifdef __cplusplus
}
#endif

#endif
