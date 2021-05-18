#ifndef LIBSBP_UNPACKED_STRING_MULTIPART_H
#define LIBSBP_UNPACKED_STRING_MULTIPART_H

#include <stdarg.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
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

  void sbp_multipart_string_init(sbp_multipart_string_t *s,
                                 uint8_t max_packed_len,
                                 uint8_t min_sections,
                                 uint8_t max_sections);
  bool sbp_multipart_string_valid(const sbp_multipart_string_t *s,
                                  uint8_t max_packed_len,
                                  uint8_t min_sections,
                                  uint8_t max_sections);
  uint8_t sbp_multipart_string_packed_len(const sbp_multipart_string_t *s,
                                          uint8_t max_packed_len,
                                          uint8_t min_sections,
                                          uint8_t max_sections);
  bool sbp_multipart_string_append(sbp_multipart_string_t *s,
                                   const char *new_str,
                                   uint8_t max_packed_len,
                                   uint8_t min_sections,
                                   uint8_t max_sections);
  bool sbp_multipart_string_append_printf(sbp_multipart_string_t *s,
                                          uint8_t max_packed_len,
                                          uint8_t min_sections,
                                          uint8_t max_sections,
                                          const char *fmt,
                                          ...) __attribute__((format(printf, 5, 6)));
  bool sbp_multipart_string_append_vprintf(sbp_multipart_string_t *s,
                                          uint8_t max_packed_len,
                                          uint8_t min_sections,
                                          uint8_t max_sections,
                                          const char *fmt,
                                          va_list ap);
  uint8_t sbp_multipart_string_count_sections(const sbp_multipart_string_t *s,
                                              uint8_t max_packed_len,
                                              uint8_t min_sections,
                                              uint8_t max_sections);
  const char *sbp_multipart_string_get_section(const sbp_multipart_string_t *s,
                                               uint8_t section,
                                               uint8_t max_packed_len,
                                               uint8_t min_sections,
                                               uint8_t max_sections);
  uint8_t sbp_multipart_string_section_len(const sbp_multipart_string_t *s,
                                           uint8_t section,
                                           uint8_t max_packed_len,
                                           uint8_t min_sections,
                                           uint8_t max_sections);
  uint8_t sbp_multipart_string_space_remaining(const sbp_multipart_string_t *s,
                                               uint8_t max_packed_len,
                                               uint8_t min_sections,
                                               uint8_t max_sections);
 int sbp_multipart_string_strcmp(const sbp_multipart_string_t *a,
                                  const sbp_multipart_string_t *b,
                                  uint8_t max_packed_len,
                                  uint8_t min_sections,
                                  uint8_t max_sections);

#ifdef __cplusplus
}
#endif

#endif

