#ifndef LIBSBP_UNPACKED_STRING_MULTIPART_H
#define LIBSBP_UNPACKED_STRING_MULTIPART_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>

#include <libsbp/common.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define SBP_MULTIPART_STRING_MAX_SECTIONS 20

  typedef struct
  {
    char data[255];
    uint8_t n_sections;
    uint8_t offsets[SBP_MULTIPART_STRING_MAX_SECTIONS];
    uint8_t lens[SBP_MULTIPART_STRING_MAX_SECTIONS];
    uint8_t packed_len;
  } sbp_multipart_string_t;

  typedef struct
  {
    uint8_t max_packed_len;
  } sbp_multipart_string_params_t;

  void sbp_multipart_string_init(sbp_multipart_string_t *s, const sbp_multipart_string_params_t *params);
  bool sbp_multipart_string_valid(const sbp_multipart_string_t *s, const sbp_multipart_string_params_t *params);
  int sbp_multipart_string_strcmp(const sbp_multipart_string_t *a,
                                  const sbp_multipart_string_t *b,
                                  const sbp_multipart_string_params_t *params);
  uint8_t sbp_multipart_string_packed_len(const sbp_multipart_string_t *s, const sbp_multipart_string_params_t *params);
  uint8_t sbp_multipart_string_space_remaining(const sbp_multipart_string_t *s,
                                               const sbp_multipart_string_params_t *params);
  uint8_t sbp_multipart_string_count_sections(const sbp_multipart_string_t *s,
                                              const sbp_multipart_string_params_t *params);
  uint8_t sbp_multipart_string_section_strlen(const sbp_multipart_string_t *s,
                                              const sbp_multipart_string_params_t *params,
                                              uint8_t section);

  bool sbp_multipart_string_add_section(sbp_multipart_string_t *s,
                                        const sbp_multipart_string_params_t *params,
                                        const char *str);
  bool sbp_multipart_string_add_section_vprintf(sbp_multipart_string_t *s,
                                                const sbp_multipart_string_params_t *params,
                                                const char *fmt,
                                                va_list ap);

  bool sbp_multipart_string_append(sbp_multipart_string_t *s,
                                   const sbp_multipart_string_params_t *params,
                                   const char *new_str);
  bool sbp_multipart_string_append_vprintf(sbp_multipart_string_t *s,
                                           const sbp_multipart_string_params_t *params,
                                           const char *fmt,
                                           va_list ap);
  const char *sbp_multipart_string_get_section(const sbp_multipart_string_t *s,
                                               const sbp_multipart_string_params_t *params,
                                               uint8_t section);

#ifdef __cplusplus
}
#endif

#endif
