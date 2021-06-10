#ifndef LIBSBP_V4_STRING_SBP_STRING_H
#define LIBSBP_V4_STRING_SBP_STRING_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  char data[256];
  size_t encoded_len;
} sbp_string_t;

#ifdef __cplusplus
}
#endif

#endif /* LIBSBP_V4_STRING_SBP_STRING_H */
