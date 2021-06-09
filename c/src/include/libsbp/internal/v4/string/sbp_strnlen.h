#ifndef SBP_STRNLEN_H
#define SBP_STRNLEN_H

#include <stddef.h>

static inline size_t sbp_strnlen(const char *str, size_t max)
{
  size_t len = 0;
  while(len < max && str[len]) len++;
  return len;
}

#endif
