#include <libsbp/string.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void sbp_multipart_string_init(sbp_multipart_string_t *s,
                               uint8_t max_packed_len,
                               uint8_t min_sections,
                               uint8_t max_sections)
{
  (void)max_packed_len;
  (void)min_sections;
  (void)max_sections;
  memset(s, 0, sizeof(*s));
}

bool sbp_multipart_string_valid(const sbp_multipart_string_t *s,
                                uint8_t max_packed_len,
                                uint8_t min_sections,
                                uint8_t max_sections)
{
  if (s->packed_len > max_packed_len)
    return false;
  if (s->n_sections < min_sections)
    return false;
  if (s->n_sections > max_sections)
    return false;
  return true;
}

uint8_t sbp_multipart_string_packed_len(const sbp_multipart_string_t *s,
                                        uint8_t max_packed_len,
                                        uint8_t min_sections,
                                        uint8_t max_sections)
{
  if (!sbp_multipart_string_valid(s, max_packed_len, min_sections, max_sections))
    return 0;
  return s->packed_len;
}

bool sbp_multipart_string_append(sbp_multipart_string_t *s,
                                 const char *new_str,
                                 uint8_t max_packed_len,
                                 uint8_t min_sections,
                                 uint8_t max_sections)
{
  if (!sbp_multipart_string_valid(s, max_packed_len, min_sections, max_sections))
    return false;
  if (s->n_sections == max_sections)
    return false;
  size_t new_len = strlen(new_str);
  size_t copy_len = new_len + 1;
  if (s->packed_len + copy_len > max_packed_len)
    return false;
  memcpy(s->data + s->packed_len, new_str, copy_len);
  s->packed_len = (uint8_t)(s->packed_len + copy_len);
  return true;
}

bool sbp_multipart_string_append_printf(sbp_multipart_string_t *s,
                                        uint8_t max_packed_len,
                                        uint8_t min_sections,
                                        uint8_t max_sections,
                                        const char *fmt,
                                        ...)
{
  if (!sbp_multipart_string_valid(s, max_packed_len, min_sections, max_sections))
    return false;
  if (s->n_sections == max_sections)
    return false;
  char new_str[256];
  va_list ap;
  va_start(ap, fmt);
  int new_len = vsnprintf(new_str, sizeof(new_str), fmt, ap);
  va_end(ap);
  size_t copy_len = (size_t)new_len + 1u;
  if (s->packed_len + copy_len > max_packed_len)
    return false;
  memcpy(s->data + s->packed_len, new_str, copy_len);
  s->packed_len = (uint8_t)(s->packed_len + copy_len);
  return true;
}

uint8_t sbp_multipart_string_count_sections(const sbp_multipart_string_t *s,
                                            uint8_t max_packed_len,
                                            uint8_t min_sections,
                                            uint8_t max_sections)
{
  (void)max_packed_len;
  (void)min_sections;
  (void)max_sections;
  return s->n_sections;
}

const char *sbp_multipart_string_get_section(const sbp_multipart_string_t *s,
                                             uint8_t section,
                                             uint8_t max_packed_len,
                                             uint8_t min_sections,
                                             uint8_t max_sections)
{
  if (!sbp_multipart_string_valid(s, max_packed_len, min_sections, max_sections))
    return NULL;
  if (section >= s->n_sections)
    return NULL;
  return s->data + s->offsets[section];
}

uint8_t sbp_multipart_string_section_len(const sbp_multipart_string_t *s,
                                         uint8_t section,
                                         uint8_t max_packed_len,
                                         uint8_t min_sections,
                                         uint8_t max_sections)
{
  if (!sbp_multipart_string_valid(s, max_packed_len, min_sections, max_sections))
    return 0;
  if (section >= s->n_sections)
    return 0;
  return s->lens[section];
}

uint8_t sbp_multipart_string_space_remaining(const sbp_multipart_string_t *s,
                                             uint8_t max_packed_len,
                                             uint8_t min_sections,
                                             uint8_t max_sections)
{
  (void)min_sections;
  (void)max_sections;
  return (uint8_t)(max_packed_len - s->packed_len);
}

uint8_t sbp_multipart_string_pack(const sbp_multipart_string_t *s,
                                  uint8_t max_packed_len,
                                  uint8_t min_sections,
                                  uint8_t max_sections,
                                  uint8_t *buf,
                                  uint8_t buf_len)
{
  if (!sbp_multipart_string_valid(s, max_packed_len, min_sections, max_sections))
    return 0;
  if (buf_len < s->packed_len)
    return 0;
  memcpy(buf, s->data, (size_t)(s->packed_len));
  return s->packed_len;
}

uint8_t sbp_multipart_string_unpack(sbp_multipart_string_t *s,
                                    uint8_t max_packed_len,
                                    uint8_t min_sections,
                                    uint8_t max_sections,
                                    const uint8_t *buf,
                                    uint8_t buf_len)
{
  sbp_multipart_string_t new_str;
  sbp_multipart_string_init(&new_str, max_packed_len, min_sections, max_sections);
  uint8_t max_len = max_packed_len;
  if (max_len > buf_len)
    max_len = buf_len;
  bool processing_section = false;
  for (uint8_t i = 0; i < max_len && new_str.n_sections < max_sections; i++, new_str.packed_len++)
  {
    if (!processing_section)
    {
      new_str.offsets[new_str.n_sections] = i;
      processing_section = true;
    }
    new_str.data[i] = (char)buf[i];
    if (buf[i] == 0)
    {
      new_str.lens[new_str.n_sections] = (uint8_t)(i - new_str.offsets[new_str.n_sections]);
      new_str.n_sections++;
      processing_section = false;
    }
  }

  if (processing_section)
  {
    // Copy with non terminated strings
    new_str.lens[new_str.n_sections] = (uint8_t)(new_str.packed_len - new_str.offsets[new_str.n_sections]);
    new_str.n_sections++;
  }

  if (!sbp_multipart_string_valid(&new_str, max_packed_len, min_sections, max_sections))
    return 0;
  memcpy(s, &new_str, sizeof(new_str));
  return s->packed_len;
}

int sbp_multipart_string_strcmp(const sbp_multipart_string_t *a,
                                const sbp_multipart_string_t *b,
                                uint8_t max_packed_len,
                                uint8_t min_sections,
                                uint8_t max_sections)
{
  bool avalid = sbp_multipart_string_valid(a, max_packed_len, min_sections, max_sections);
  bool bvalid = sbp_multipart_string_valid(b, max_packed_len, min_sections, max_sections);
  if (!avalid)
    return bvalid ? 1 : 0;
  if (!bvalid)
    return avalid ? -1 : 0;
  uint8_t cmp_len = max_packed_len;
  if (a->packed_len < cmp_len)
    cmp_len = a->packed_len;
  if (b->packed_len < cmp_len)
    cmp_len = b->packed_len;
  if (memcmp(a->data, b->data, cmp_len) == 0)
    return 0;
  return (int)b->n_sections - (int)a->n_sections;
}
