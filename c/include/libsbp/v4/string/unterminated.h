#ifndef LIBSBP_V4_STRING_UNTERMINATED_H
#define LIBSBP_V4_STRING_UNTERMINATED_H

#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>

#ifdef __cplusplus
extern "C"
{
#endif

  typedef struct
  {
    char data[256];
    uint8_t encoded_len;
  } sbp_unterminated_string_t;

  typedef struct
  {
    uint8_t max_encoded_len;
  } sbp_unterminated_string_params_t;

  void sbp_unterminated_string_init(sbp_unterminated_string_t *s,
                                       const sbp_unterminated_string_params_t *params);
  bool sbp_unterminated_string_valid(const sbp_unterminated_string_t *s,
                                        const sbp_unterminated_string_params_t *params);
  int sbp_unterminated_string_strcmp(const sbp_unterminated_string_t *a,
                                        const sbp_unterminated_string_t *b,
                                        const sbp_unterminated_string_params_t *params);
  uint8_t sbp_unterminated_string_encoded_len(const sbp_unterminated_string_t *s,
                                                const sbp_unterminated_string_params_t *params);
  uint8_t sbp_unterminated_string_space_remaining(const sbp_unterminated_string_t *s, const sbp_unterminated_string_params_t *params);
  uint8_t sbp_unterminated_string_strlen(const sbp_unterminated_string_t *s, const sbp_unterminated_string_params_t *params);

  bool sbp_unterminated_string_set(sbp_unterminated_string_t *s,
                                      const sbp_unterminated_string_params_t *params,
                                      const char *new_str);
  bool sbp_unterminated_string_printf(sbp_unterminated_string_t *s,
                                         const sbp_unterminated_string_params_t *params,
                                         const char *fmt,
                                         ...) SBP_ATTR_FORMAT(3, 4);
  bool sbp_unterminated_string_vprintf(sbp_unterminated_string_t *s,
                                          const sbp_unterminated_string_params_t *params,
                                          const char *fmt,
                                          va_list);
  bool sbp_unterminated_string_append(sbp_unterminated_string_t *s,
                                         const sbp_unterminated_string_params_t *params,
                                         const char *new_str);
  bool sbp_unterminated_string_append_vprintf(sbp_unterminated_string_t *s,
                                          const sbp_unterminated_string_params_t *params,
                                          const char *fmt,
                                          va_list);
  const char *sbp_unterminated_string_get(const sbp_unterminated_string_t *s,
                                             const sbp_unterminated_string_params_t *params);

#ifdef __cplusplus
}
#endif

#endif
