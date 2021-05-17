#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <libsbp/unpacked/string/sequence.h>

void sbp_sequence_string_init(sbp_sequence_string_t *s, uint8_t max_packed_len, uint8_t terminator)
{
  (void)max_packed_len;
  memset(s, 0, sizeof(*s));
  s->data[0] = (char)terminator;
  s->packed_len = 1;
}

bool sbp_sequence_string_valid(const sbp_sequence_string_t *s, uint8_t max_packed_len, uint8_t terminator)
{
  (void)terminator;
  return (s->packed_len >= 1) && (s->packed_len <= max_packed_len);
}

uint8_t sbp_sequence_string_packed_len(const sbp_sequence_string_t *s, uint8_t max_packed_len, uint8_t terminator)
{
  if (!sbp_sequence_string_valid(s, max_packed_len, terminator))
    return 0;
  return s->packed_len;
}

bool sbp_sequence_string_append(sbp_sequence_string_t *s,
                                const char *new_str,
                                uint8_t max_packed_len,
                                uint8_t terminator)
{
  if (!sbp_sequence_string_valid(s, max_packed_len, terminator))
    return false;
  size_t new_len = strlen(new_str);
  size_t copy_len = new_len + 1;
  if (s->packed_len + copy_len > max_packed_len)
    return false;
  memcpy(s->data + s->packed_len, new_str, copy_len);
  s->packed_len = (uint8_t)(s->packed_len + copy_len);
  s->data[s->packed_len++] = (char)terminator;
  return true;
}

bool sbp_sequence_string_append_printf(sbp_sequence_string_t *s,
                                       uint8_t max_packed_len,
                                       uint8_t terminator,
                                       const char *fmt,
                                       ...)
{
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_sequence_string_append_vprintf(s, max_packed_len, terminator, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_sequence_string_append_vprintf(sbp_sequence_string_t *s,
                                       uint8_t max_packed_len,
                                       uint8_t terminator,
                                       const char *fmt,
                                       va_list ap)
{
  if (!sbp_sequence_string_valid(s, max_packed_len, terminator))
    return false;
  char new_str[256];
  int new_len = vsnprintf(new_str, sizeof(new_str), fmt, ap);
  size_t copy_len = (size_t)new_len + 1u;
  if (s->packed_len + copy_len > max_packed_len)
    return false;
  memcpy(s->data + s->packed_len, new_str, copy_len);
  s->packed_len = (uint8_t)(s->packed_len + copy_len);
  s->data[s->packed_len++] = (char)terminator;
  return true;
}

uint8_t sbp_sequence_string_count_sections(const sbp_sequence_string_t *s, uint8_t max_packed_len, uint8_t terminator)
{
  if (!sbp_sequence_string_valid(s, max_packed_len, terminator))
    return false;
  return s->n_sections;
}

const char *sbp_sequence_string_get_section(const sbp_sequence_string_t *s,
                                            uint8_t section,
                                            uint8_t max_packed_len,
                                            uint8_t terminator)
{
  if (!sbp_sequence_string_valid(s, max_packed_len, terminator))
    return NULL;
  if (section >= s->n_sections)
    return NULL;
  return s->data + s->offsets[section];
}

uint8_t sbp_sequence_string_section_len(const sbp_sequence_string_t *s,
                                        uint8_t section,
                                        uint8_t max_packed_len,
                                        uint8_t terminator)
{
  if (!sbp_sequence_string_valid(s, max_packed_len, terminator))
    return 0;
  if (section >= s->n_sections)
    return 0;
  return s->lens[section];
}

uint8_t sbp_sequence_string_space_remaining(const sbp_sequence_string_t *s, uint8_t max_packed_len, uint8_t terminator)
{
  (void)terminator;
  return (uint8_t)(max_packed_len - s->packed_len);
}

bool sbp_sequence_string_pack(const sbp_sequence_string_t *s,
                                 uint8_t max_packed_len,
                                 uint8_t terminator,
                                 sbp_pack_ctx_t *ctx)
{
  if (!sbp_sequence_string_valid(s, max_packed_len, terminator))
    return false;
  if ((ctx->buf_len - ctx->offset) < s->packed_len)
    return false;
  memcpy(&ctx->buf[ctx->offset], s->data, (size_t)(s->packed_len));
  ctx->offset += s->packed_len;
  return true;
}

bool sbp_sequence_string_unpack(sbp_sequence_string_t *s,
                                   uint8_t max_packed_len,
                                   uint8_t terminator,
                                   sbp_unpack_ctx_t *ctx)
{
  sbp_sequence_string_t new_str;
  sbp_sequence_string_init(&new_str, max_packed_len, terminator);
  uint8_t max_len = max_packed_len;
  uint8_t buf_len = (uint8_t)(ctx->buf_len - ctx->offset);
  if (max_len > buf_len)
    max_len = buf_len;
  bool processing_section = false;
  size_t i;
  for (i = 0; i < max_len; i++, new_str.packed_len++)
  {
    if (!processing_section)
    {
      new_str.offsets[new_str.n_sections] = (uint8_t)i;
      processing_section = true;
    }
    new_str.data[i] = (char)ctx->buf[ctx->offset + i];
    if (ctx->buf[ctx->offset + i] == 0)
    {
      new_str.lens[new_str.n_sections] = (uint8_t)(i - new_str.offsets[new_str.n_sections]);
      new_str.n_sections++;
      processing_section = false;
    }
    if (ctx->buf[ctx->offset + i] == terminator)
      break;
  }

  if (i == max_len)
    return false;
  memcpy(s, &new_str, sizeof(new_str));
  ctx->offset += s->packed_len;
  return true;
}

int sbp_sequence_string_strcmp(const sbp_sequence_string_t *a,
                               const sbp_sequence_string_t *b,
                               uint8_t max_packed_len,
                               uint8_t terminator)
{
  bool avalid = sbp_sequence_string_valid(a, max_packed_len, terminator);
  bool bvalid = sbp_sequence_string_valid(b, max_packed_len, terminator);
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
  return (int)b->packed_len - (int)a->packed_len;
}
