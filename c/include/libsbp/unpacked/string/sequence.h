#ifndef LIBSBP_UNPACKED_STRING_SEQUENCE_H
#define LIBSBP_UNPACKED_STRING_SEQUENCE_H

#include <stdarg.h>
#include <stdint.h>
#include <stdbool.h>

#include <libsbp/unpacked/common.h>

#ifdef __cplusplus
extern "C" {
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
  bool sbp_sequence_string_append_vprintf(sbp_sequence_string_t *s,
                                         uint8_t max_packed_len,
                                         uint8_t terminator,
                                         const char *fmt,
                                         va_list ap);
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
  bool sbp_sequence_string_pack(const sbp_sequence_string_t *s,
                                   uint8_t max_packed_len,
                                   uint8_t terminator,
                                   sbp_pack_ctx_t *ctx);
  bool sbp_sequence_string_unpack(sbp_sequence_string_t *s,
                                     uint8_t max_packed_len,
                                     uint8_t terminator,
                                     sbp_unpack_ctx_t *ctx);
  int sbp_sequence_string_strcmp(const sbp_sequence_string_t *a,
                                 const sbp_sequence_string_t *b,
                                 uint8_t max_packed_len,
                                 uint8_t terminator);

#ifdef __cplusplus
}
#endif

#endif


