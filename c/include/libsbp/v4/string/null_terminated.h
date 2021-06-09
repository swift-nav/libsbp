#ifndef LIBSBP_UNPACKED_STRING_NULL_TERMINATED_H
#define LIBSBP_UNPACKED_STRING_NULL_TERMINATED_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>

#include <libsbp/common.h>

#ifdef __cplusplus
extern "C"
{
#endif

  typedef struct
  {
    char data[255];
    uint8_t packed_len;
  } sbp_null_terminated_string_t;

  typedef struct
  {
    uint8_t max_packed_len;
  } sbp_null_terminated_string_params_t;

  void sbp_null_terminated_string_init(sbp_null_terminated_string_t *s,
                                       const sbp_null_terminated_string_params_t *params);
  bool sbp_null_terminated_string_valid(const sbp_null_terminated_string_t *s,
                                        const sbp_null_terminated_string_params_t *params);
  int sbp_null_terminated_string_strcmp(const sbp_null_terminated_string_t *a,
                                        const sbp_null_terminated_string_t *b,
                                        const sbp_null_terminated_string_params_t *params);
  uint8_t sbp_null_terminated_string_packed_len(const sbp_null_terminated_string_t *s,
                                                const sbp_null_terminated_string_params_t *params);
  uint8_t sbp_null_terminated_string_space_remaining(const sbp_null_terminated_string_t *s,
                                                     const sbp_null_terminated_string_params_t *params);
  uint8_t sbp_null_terminated_string_strlen(const sbp_null_terminated_string_t *s, const sbp_null_terminated_string_params_t *params);

  bool sbp_null_terminated_string_set(sbp_null_terminated_string_t *s,
                                      const sbp_null_terminated_string_params_t *params,
                                      const char *new_str);
  bool sbp_null_terminated_string_vprintf(sbp_null_terminated_string_t *s,
                                          const sbp_null_terminated_string_params_t *params,
                                          const char *fmt,
                                          va_list ap);
  bool sbp_null_terminated_string_append(sbp_null_terminated_string_t *s,
                                         const sbp_null_terminated_string_params_t *params,
                                         const char *new_str);
  bool sbp_null_terminated_string_append_vprintf(sbp_null_terminated_string_t *s,
                                                 const sbp_null_terminated_string_params_t *params,
                                                 const char *fmt,
                                                 va_list ap);
  const char *sbp_null_terminated_string_get(const sbp_null_terminated_string_t *s,
                                             const sbp_null_terminated_string_params_t *params);

#ifdef __cplusplus
}
#endif

#endif
