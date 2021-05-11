#include <libsbp/string2.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void sbp_unterminated_string_init(sbp_unterminated_string_t *s, uint8_t max_packed_len)
{
  (void)max_packed_len;
  memset(s->data, 0, sizeof(s->data));
  s->len = 0;
}

bool sbp_unterminated_string_valid(const sbp_unterminated_string_t *s, uint8_t max_packed_len)
{
  return s->len <= max_packed_len;
}

uint8_t sbp_unterminated_string_packed_len(const sbp_unterminated_string_t *s, uint8_t max_packed_len)
{
  if (!sbp_unterminated_string_valid(s, max_packed_len))
    return 0;
  return s->len;
}

bool sbp_unterminated_string_set(sbp_unterminated_string_t *s, const char *new_str, uint8_t max_packed_len)
{
  size_t new_len = strlen(new_str);
  if (new_len > max_packed_len)
  {
    return false;
  }
  strncpy(s->data, new_str, sizeof(s->data));
  s->len = (uint8_t)new_len;
  return true;
}

bool sbp_unterminated_string_printf(sbp_unterminated_string_t *s, uint8_t max_packed_len, const char *fmt, ...)
{
  char new_str[256];
  va_list ap;
  va_start(ap, fmt);
  int len = vsnprintf(new_str, max_packed_len + 1u, fmt, ap);
  va_end(ap);

  if ((size_t)len >= max_packed_len + 1u)
  {
    return false;
  }
  strncpy(s->data, new_str, (size_t)len + 1);
  s->len = (uint8_t)len;
  return true;
}

const char *sbp_unterminated_string_get(const sbp_unterminated_string_t *s, uint8_t max_packed_len)
{
  if (!sbp_unterminated_string_valid(s, max_packed_len))
  {
    return NULL;
  }
  return s->data;
}

uint8_t
sbp_unterminated_string_pack(const sbp_unterminated_string_t *s, uint8_t max_packed_len, uint8_t *buf, uint8_t buf_len)
{
  if (!sbp_unterminated_string_valid(s, max_packed_len))
  {
    return 0;
  }
  if (buf_len < s->len)
  {
    return 0;
  }
  memcpy(buf, s->data, s->len);
  return s->len;
}

uint8_t sbp_unterminated_string_unpack(sbp_unterminated_string_t *s,
                                       uint8_t max_packed_len,
                                       const uint8_t *buf,
                                       uint8_t buf_len)
{
  uint8_t copy_len = buf_len;
  if (copy_len > max_packed_len)
    copy_len = max_packed_len;
  memcpy(s->data, buf, copy_len);
  s->data[copy_len] = 0;
  s->len = copy_len;
  return s->len;
}

int sbp_unterminated_string_strcmp(const sbp_unterminated_string_t *a,
                                   const sbp_unterminated_string_t *b,
                                   uint8_t max_packed_len)
{
  bool avalid = sbp_unterminated_string_valid(a, max_packed_len);
  bool bvalid = sbp_unterminated_string_valid(b, max_packed_len);
  if (!avalid)
    return bvalid ? 1 : 0;
  if (!bvalid)
    return avalid ? -1 : 0;
  uint8_t cmp_len = max_packed_len;
  if (a->len < cmp_len)
    cmp_len = a->len;
  if (b->len < cmp_len)
    cmp_len = b->len;
  if (memcmp(a->data, b->data, cmp_len) == 0)
    return 0;
  return (int)b->len - (int)a->len;
}
