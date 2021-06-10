#ifndef LIBSBP_INTERNAL_UNPACKED_STRING_UNTERMINATED_H
#define LIBSBP_INTERNAL_UNPACKED_STRING_UNTERMINATED_H

#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>

#include <libsbp/common.h>
#include <libsbp/internal/v4/common.h>
#include <libsbp/v4/string/sbp_string.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initialise an unterminated string
 *
 * @param s string
 */
void sbp_unterminated_string_init(sbp_string_t *s);

/**
 * Check an unterminated string for validity
 *
 * @param s string
 * @param max_encoded_len Maximum encoded length
 * @return true if valid, false otherwise
 */
bool sbp_unterminated_string_valid(const sbp_string_t *s,
                                   size_t max_encoded_len);

/**
 * Compare two unterminated string
 *
 * The return value has the same definition as C standard library comparison
 * functions such as memcmp, strcmp
 *
 * An invalid string will be considered as less than a valid string
 *
 * @param a unterminated string
 * @param b unterminated string
 * @param max_encoded_len Maximum encoded length
 * @return Comparison result
 */
int sbp_unterminated_string_strcmp(const sbp_string_t *a, const sbp_string_t *b,
                                   size_t max_encoded_len);

/**
 * Get encoded length of an unterminated string
 *
 * If the string is invalid the returned value is 0
 *
 * @param s string
 * @param max_encoded_len Maximum encoded length
 * @return Encoded length
 */
size_t sbp_unterminated_string_encoded_len(const sbp_string_t *s,
                                           size_t max_encoded_len);

/**
 * Get available spec in an unterminated string
 *
 * The return value is the maximum number of bytes that can be added to the
 * string without exceeding the maximum encoded length
 *
 * @param s string
 * @param max_encoded_len Maximum encoded length
 * @return Available space
 */
size_t sbp_unterminated_string_space_remaining(const sbp_string_t *s,
                                               size_t max_encoded_len);

/**
 * Get length of an unterminated string.
 *
 * This value is always equal to #sbp_unterminated_string_encoded_len
 *
 * @param s string
 * @param max_encoded_len Maximum encoded length
 * @return String length
 */
size_t sbp_unterminated_string_strlen(const sbp_string_t *s,
                                      size_t max_encoded_len);

/**
 * Set an unterminated string
 *
 * If the new string contents are larger than can be stored the string will not
 * be modified and false will be returned
 *
 * @param s string
 * @param max_encoded_len Maximum encoded length
 * @param new_str new string
 * @return true on success, false otherwise
 */
bool sbp_unterminated_string_set(sbp_string_t *s, size_t max_encoded_len,
                                 const char *new_str);

/**
 * Set an unterminated string with printf style formatting
 *
 * If the resulting string would be greater than the maximum encoded length the
 * string will not be modified and false will be returned
 *
 * @param s string
 * @param max_encoded_len Maximum encoded length
 * @param fmt printf style format specification
 * @param ap Argument list
 * @return true on success, false otherwise
 */
bool sbp_unterminated_string_vprintf(sbp_string_t *s, size_t max_encoded_len,
                                     const char *fmt, va_list ap);

/**
 * Append an unterminated string
 *
 * The new string will be appended to the current contents of this string. If
 * the resulting string would be greater than the maximum encoded length the
 * string will not be modified and false will be returned
 *
 * @param s string
 * @param max_encoded_len Maximum encoded length
 * @param new_str String to append
 * @return true on success, false otherwise
 */
bool sbp_unterminated_string_append(sbp_string_t *s, size_t max_encoded_len,
                                    const char *new_str);

/**
 * Appens to an unterminated string will printf style formatting
 *
 * If the resulting string would be greater than the maximum encoded length the
 * string will not be modified and false will be returned
 *
 * @param s string
 * @param max_encoded_len Maximum encoded length
 * @param fmt printf style format specification
 * @param ap Argument list
 * @return true on success, false otherwise
 */
bool sbp_unterminated_string_append_vprintf(sbp_string_t *s,
                                            size_t max_encoded_len,
                                            const char *fmt, va_list ap);

/**
 * Get contents
 *
 * If the string is invalid NULL will be returned
 *
 * @param s string
 * @param max_encoded_len Maximum encoded length
 * @return String contents or NULL
 */
const char *sbp_unterminated_string_get(const sbp_string_t *s,
                                        size_t max_encoded_len);

/**
 * Encode an unterminated string
 *
 * If the string is invalid or there is not enough space in the destination
 * buffer to hold the string alse will be returned.
 *
 * @param s string
 * @param max_encoded_len Maximum encoded length
 * @param ctx Encode context
 * @return true on success, false otherwise
 */
bool sbp_unterminated_string_encode(const sbp_string_t *s,
                                    size_t max_encoded_len,
                                    sbp_encode_ctx_t *ctx);

/**
 * Decode a null terminated string.
 *
 * All available data will be consumed from the source buffer
 *
 * @param s string
 * @param max_encoded_len Maximum encoded length
 * @param ctx Decode context
 * @return true on success, false otherwise
 */
bool sbp_unterminated_string_decode(sbp_string_t *s, size_t max_encoded_len,
                                    sbp_decode_ctx_t *ctx);

#ifdef __cplusplus
}
#endif

#endif
