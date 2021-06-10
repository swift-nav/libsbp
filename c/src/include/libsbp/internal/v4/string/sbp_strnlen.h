#ifndef SBP_STRNLEN_H
#define SBP_STRNLEN_H

#include <stddef.h>

/**
 * Safe version of strlen
 *
 * Up to \p max bytes will be read from \p str.
 *
 * This function returns as soon as it finds a NULL terminated. If no NULL
 * terminator is found before the maximum number of bytes have been read it will
 * return a value equal to \p max.
 *
 * Therefore a return value of \p max indicates that the string is likely
 * invalid
 *
 * @param str string
 * @param max Max length
 * @return string length
 */
static inline size_t sbp_strnlen(const char *str, size_t max) {
  size_t len = 0;
  while (len < max && str[len]) {
    len++;
  }
  return len;
}

#endif
