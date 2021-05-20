#ifndef LIBSBP_UNPACKED_STRING_SEQUENCE_H
#define LIBSBP_UNPACKED_STRING_SEQUENCE_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>

#include <libsbp/common.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define SBP_SEQUENCE_STRING_MAX_SECTIONS 20

  typedef struct
  {
    char data[255];
    uint8_t n_sections;
    uint8_t offsets[SBP_SEQUENCE_STRING_MAX_SECTIONS];
    uint8_t lens[SBP_SEQUENCE_STRING_MAX_SECTIONS];
    uint8_t packed_len;
  } sbp_sequence_string_t;

  typedef struct
  {
    uint8_t max_packed_len;
    uint8_t terminator;
  } sbp_sequence_string_params_t;

  void sbp_sequence_string_init(sbp_sequence_string_t *s, const sbp_sequence_string_params_t *params);
  bool sbp_sequence_string_valid(const sbp_sequence_string_t *s, const sbp_sequence_string_params_t *params);
  int sbp_sequence_string_strcmp(const sbp_sequence_string_t *a,
                                  const sbp_sequence_string_t *b,
                                  const sbp_sequence_string_params_t *params);
  uint8_t sbp_sequence_string_packed_len(const sbp_sequence_string_t *s, const sbp_sequence_string_params_t *params);
  uint8_t sbp_sequence_string_space_remaining(const sbp_sequence_string_t *s,
                                               const sbp_sequence_string_params_t *params);
  uint8_t sbp_sequence_string_count_sections(const sbp_sequence_string_t *s,
                                              const sbp_sequence_string_params_t *params);
  bool sbp_sequence_string_add_section(sbp_sequence_string_t *s,
                                        const sbp_sequence_string_params_t *params,
                                        const char *str);
  bool sbp_sequence_string_add_section_printf(sbp_sequence_string_t *s,
                                               const sbp_sequence_string_params_t *params,
                                               const char *fmt,
                                               ...) SBP_ATTR_FORMAT(3, 4);
  bool sbp_sequence_string_add_section_vprintf(sbp_sequence_string_t *s,
                                                const sbp_sequence_string_params_t *params,
                                                const char *fmt,
                                                va_list ap);

  bool sbp_sequence_string_append(sbp_sequence_string_t *s,
                                   const sbp_sequence_string_params_t *params,
                                   const char *new_str);
  bool sbp_sequence_string_append_printf(sbp_sequence_string_t *s,
                                          const sbp_sequence_string_params_t *params,
                                          const char *fmt,
                                          ...) SBP_ATTR_FORMAT(3, 4);
  bool sbp_sequence_string_append_vprintf(sbp_sequence_string_t *s,
                                           const sbp_sequence_string_params_t *params,
                                           const char *fmt,
                                           va_list ap);
  const char *sbp_sequence_string_get_section(const sbp_sequence_string_t *s,
                                               const sbp_sequence_string_params_t *params,
                                               uint8_t section);
  uint8_t sbp_sequence_string_section_strlen(const sbp_sequence_string_t *s,
                                              const sbp_sequence_string_params_t *params,
                                              uint8_t section);

#ifdef __cplusplus
}
#endif

#endif
