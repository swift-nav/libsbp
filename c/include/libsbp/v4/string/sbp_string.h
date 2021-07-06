#ifndef LIBSBP_V4_STRING_SBP_STRING_H
#define LIBSBP_V4_STRING_SBP_STRING_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Container for SBP strings.
 *
 * There are 4 different string encoding schemes in SBP (unterminated, NULL
 * terminated, multipart, double NULL terminated). Each encoding scheme has a
 * set of functions to deal with creating, querying, encoding and decoding
 * to/from the wire format. This struct is used for storage by all schemes.
 *
 * For each string type field in an SBP message a set of functions is generated
 * to safely handle access to that string. These functions are set up to ensure
 * that the maximum encoded size of the string can never be exceeded during
 * creation, and guarantees that received strings are always available in C
 * representation.
 *
 * @warning NEVER access any field in this struct directly. Always use the
 * provided set of functions specific for the string type field which is needed.
 */
typedef struct {
  /**
   * Raw encoded string data.
   *
   * @warning Do not access this field directly. Always use provided accessor
   * functions
   */
  char data[256];

  /**
   * Length of encoded #data
   *
   * @warning Do not access this field directly. Always use provided accessor
   * functions
   */
  size_t encoded_len;
} sbp_string_t;

#ifdef __cplusplus
}
#endif

#endif /* LIBSBP_V4_STRING_SBP_STRING_H */
