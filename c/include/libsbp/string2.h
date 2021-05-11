#ifndef SBP_STRING_H
#define SBP_STRING_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C"
{
#endif

// Completely arbitrary
#define SBP_STRING_MAX_SECTIONS 20

  typedef enum
  {
    SBP_STRING_UNTERMINATED,
    SBP_STRING_NULL_TERMINATED,
    SBP_STRING_MULTIPART,
    SBP_STRING_SEQUENCE,
  } sbp_string_encoding_type_t;

  typedef struct
  {
    sbp_string_encoding_type_t encoding;
    uint8_t min_sections;
    uint8_t max_sections;
    uint8_t terminator;
    uint8_t max_encoded_len;
  } sbp_string_format_t;

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
  const char *sbp_unterminated_string_get(const sbp_unterminated_string_t *s, uint8_t max_packed_len);
  uint8_t sbp_unterminated_string_pack(const sbp_unterminated_string_t *s,
                                       uint8_t max_packed_len,
                                       uint8_t *buf,
                                       uint8_t buf_len);
  uint8_t sbp_unterminated_string_unpack(sbp_unterminated_string_t *s,
                                         uint8_t max_packed_len,
                                         const uint8_t *buf,
                                         uint8_t buf_len);

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
  const char *sbp_null_terminated_string_get(const sbp_null_terminated_string_t *s, uint8_t max_packed_len);
  uint8_t sbp_null_terminated_string_pack(const sbp_null_terminated_string_t *s,
                                          uint8_t max_packed_len,
                                          uint8_t *buf,
                                          uint8_t buf_len);
  uint8_t sbp_null_terminated_string_unpack(sbp_null_terminated_string_t *s,
                                            uint8_t max_packed_len,
                                            const uint8_t *buf,
                                            uint8_t buf_len);

  typedef struct
  {
    char data[255];
    uint8_t n_sections;
    uint8_t offsets[SBP_STRING_MAX_SECTIONS];
    uint8_t lens[SBP_STRING_MAX_SECTIONS];
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
  uint8_t sbp_multipart_string_pack(const sbp_multipart_string_t *s,
                                    uint8_t max_packed_len,
                                    uint8_t min_sections,
                                    uint8_t max_sections,
                                    uint8_t *buf,
                                    uint8_t buf_len);
  uint8_t sbp_multipart_string_unpack(sbp_multipart_string_t *s,
                                      uint8_t max_packed_len,
                                      uint8_t min_sections,
                                      uint8_t max_sections,
                                      const uint8_t *buf,
                                      uint8_t buf_len);

  typedef struct
  {
    char data[255];
    uint8_t n_sections;
    uint8_t offsets[SBP_STRING_MAX_SECTIONS];
    uint8_t lens[SBP_STRING_MAX_SECTIONS];
    uint8_t packed_len;
  } sbp_sequence_string_t;

  void sbp_sequence_string_init(sbp_sequence_string_t *s, uint8_t max_packed_len, uint8_t terminator);
  bool sbp_sequence_string_valid(const sbp_sequence_string_t *s, uint8_t max_packed_len, uint8_t terminator);
  uint8_t sbp_sequence_string_packed_len(const sbp_sequence_string_t *s, uint8_t max_packed_len, uint8_t terminator);
  bool
  sbp_sequence_string_append(sbp_sequence_string_t *s, const char *new_str, uint8_t max_packed_len, uint8_t terminator);
  bool sbp_sequence_string_append_printf(sbp_sequence_string_t *s,
                                         uint8_t max_packed_len,
                                         uint8_t terminator,
                                         const char *fmt,
                                         ...) __attribute__((format(printf, 4, 5)));
  uint8_t
  sbp_sequence_string_count_sections(const sbp_sequence_string_t *s, uint8_t max_packed_len, uint8_t terminator);
  const char *sbp_sequence_string_get_section(const sbp_sequence_string_t *s,
                                              uint8_t section,
                                              uint8_t max_packed_len,
                                              uint8_t terminator);
  uint8_t sbp_sequence_string_section_len(const sbp_sequence_string_t *s,
                                          uint8_t section,
                                          uint8_t max_packed_len,
                                          uint8_t terminator);
  uint8_t
  sbp_sequence_string_space_remaining(const sbp_sequence_string_t *s, uint8_t max_packed_len, uint8_t terminator);
  uint8_t sbp_sequence_string_pack(const sbp_sequence_string_t *s,
                                   uint8_t max_packed_len,
                                   uint8_t terminator,
                                   uint8_t *buf,
                                   uint8_t buf_len);
  uint8_t sbp_sequence_string_unpack(sbp_sequence_string_t *s,
                                     uint8_t max_packed_len,
                                     uint8_t terminator,
                                     const uint8_t *buf,
                                     uint8_t buf_len);

#ifdef __cplusplus
}
#endif

#endif
