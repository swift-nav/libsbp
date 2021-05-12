#include <assert.h>
#include <libsbp/string2.h>

#define MAX_SECTIONS 100
struct string_state
{
  bool valid;
  uint8_t packed_len;
  uint8_t n_sections;
  uint8_t section_offsets[MAX_SECTIONS];
  uint8_t section_lengths[MAX_SECTIONS];
};

static void analyse(const sbp_string_t string, const sbp_string_format_t *format, struct string_state *state)
{
  if (format->encoding == SBP_STRING_UNTERMINATED)
  {
    state->n_sections = 1;
    state->section_offsets[0] = 0;
    state->section_lengths[0] = (uint8_t)strnlen(string, sizeof(sbp_string_t));
    state->packed_len = (uint8_t)(state->section_lengths[0]);
    state->valid = state->packed_len <= format->max_encoded_len;
    return;
  }
  if (format->encoding == SBP_STRING_NULL_TERMINATED)
  {
    state->n_sections = 1;
    state->section_offsets[0] = 0;
    state->section_lengths[0] = (uint8_t)(strnlen(string, format->max_encoded_len));
    state->packed_len = (uint8_t)(state->section_lengths[0] + 1u);
    state->valid = state->packed_len <= format->max_encoded_len;
    return;
  }
  if (format->encoding == SBP_STRING_MULTIPART)
  {
    // Count the number of NULL terminated strings in string. Stop at max sections or when we encounter a 0-length
    // optional (greater than min sections)
    memset(state, 0, sizeof(*state));
    size_t offset = 0;
    for (state->n_sections = 0; offset < format->max_encoded_len && state->n_sections < format->max_sections;
         state->n_sections++)
    {
      size_t max_section_len = format->max_encoded_len - offset;
      state->section_offsets[state->n_sections] = (uint8_t)offset;
      state->section_lengths[state->n_sections] = (uint8_t)strnlen(string + offset, max_section_len);
      if (state->section_lengths[state->n_sections] == max_section_len)
      {
        // No NULL terminator found before the end of the max encoded size, invalid string
        return;
      }
      if (state->section_lengths[state->n_sections] == 0 && state->n_sections >= format->min_sections)
      {
        break;
      }
      offset += state->section_lengths[state->n_sections] + 1u;
    }

    if (offset > format->max_encoded_len)
    {
      return;
    }

    if (state->n_sections < format->min_sections)
    {
      return;
    }

    state->valid = true;
    state->packed_len = (uint8_t)offset;
    return;
  }
  if (format->encoding == SBP_STRING_SEQUENCE)
  {
    memset(state, 0, sizeof(*state));
    // Count the number of NULL terminated strings before the sequence terminator. Double NULL is a special case
    if (format->terminator == 0)
    {
      if (string[0] == 0 && string[1] == 0)
      {
        state->valid = true;
        state->packed_len = 2;
        return;
      }

      size_t i;
      for (i = 0; i < format->max_encoded_len; i++)
      {
        if (string[i] == 0)
        {
          state->section_lengths[state->n_sections] = (uint8_t)(i - state->section_offsets[state->n_sections]);
          state->n_sections++;
          if (i < format->max_encoded_len - 1u && string[i + 1] == 0)
          {
            state->valid = true;
            state->packed_len = (uint8_t)(i + 2);
            return;
          }
          state->section_offsets[state->n_sections] = (uint8_t)(i + 1);
        }
      }
      return;
    }

    size_t offset = 0;
    while (offset < format->max_encoded_len)
    {
      if (string[offset] == (char)format->terminator)
      {
        state->valid = true;
        state->packed_len = (uint8_t)(offset + 1);
        return;
      }

      state->section_offsets[state->n_sections] = (uint8_t)offset;
      size_t max_section_len = format->max_encoded_len - offset - 1;
      state->section_lengths[state->n_sections] = (uint8_t)strnlen(string + offset, max_section_len);
      if (state->section_lengths[state->n_sections] == max_section_len)
      {
        return;
      }
      offset += state->section_lengths[state->n_sections] + 1u;
      state->n_sections++;
    }
    return;
  }
  assert(0 && "Invalid string encoding");
}

bool sbp_string_valid(const sbp_string_t string, const sbp_string_format_t *format)
{
  struct string_state state;
  analyse(string, format, &state);
  return state.valid;
}

uint8_t sbp_string_packed_len(const sbp_string_t string, const sbp_string_format_t *format)
{
  struct string_state state;
  analyse(string, format, &state);
  return state.valid ? state.packed_len : 0;
}

uint8_t sbp_string_section_len(const sbp_string_t string, const sbp_string_format_t *format, uint8_t section)
{
  struct string_state state;
  analyse(string, format, &state);
  if (!state.valid)
  {
    return 0;
  }
  if (section >= state.n_sections)
  {
    return 0;
  }
  return state.section_lengths[section];
}

bool sbp_string_set(sbp_string_t string, const sbp_string_format_t *format, const char *str)
{
  size_t new_len = strlen(str);
  if (format->encoding == SBP_STRING_UNTERMINATED)
  {
    if (new_len > format->max_encoded_len)
    {
      return false;
    }
    strncpy(string, str, new_len + 1);
    return true;
  }
  if (format->encoding == SBP_STRING_NULL_TERMINATED)
  {
    new_len++;
    if (new_len > format->max_encoded_len)
    {
      return false;
    }
    strncpy(string, str, new_len);
    return true;
  }
  return false;
}

bool sbp_string_set_section(sbp_string_t string, const sbp_string_format_t *format, uint8_t section, const char *str)
{
  if (format->encoding != SBP_STRING_MULTIPART)
  {
    return false;
  }
  if (section >= format->max_sections)
  {
    return false;
  }
  struct string_state state;
  analyse(string, format, &state);
  if (!state.valid)
  {
    return false;
  }
  size_t str_len = strlen(str);
  size_t copy_len = str_len + 1;
  if ((size_t)state.packed_len - (size_t)state.section_lengths[section] + str_len > format->max_encoded_len)
  {
    return false;
  }
  sbp_string_t tmp;
  memset(tmp, 0, sizeof(sbp_string_t));

  size_t offset = 0;
  for (uint8_t i = 0; i < format->max_sections; i++)
  {
    if (i == section)
    {
      memcpy(tmp + offset, str, copy_len);
      offset += copy_len;
    }
    else
    {
      memcpy(tmp + offset, string + state.section_offsets[i], state.section_lengths[i]);
      offset += (uint8_t)(state.section_lengths[i] + 1u);
    }
  }
  memcpy(string, tmp, format->max_encoded_len);
  return true;
}

bool sbp_string_append_section(sbp_string_t string, const sbp_string_format_t *format, const char *str)
{
  if (format->encoding != SBP_STRING_SEQUENCE)
  {
    return false;
  }
  struct string_state state;
  analyse(string, format, &state);
  if (!state.valid)
  {
    sbp_string_init(string, format);
    analyse(string, format, &state);
  }
  size_t str_len = strlen(str);
  size_t copy_len = str_len + 1;
  if (state.packed_len + copy_len > format->max_encoded_len)
  {
    return false;
  }
  memcpy(string + state.packed_len - 1, str, copy_len);
  string[state.packed_len + copy_len] = (char)format->terminator;
  return true;
}

const char *sbp_string_get_section(const sbp_string_t string, const sbp_string_format_t *format, uint8_t section)
{
  struct string_state state;
  analyse(string, format, &state);
  if (!state.valid)
  {
    return NULL;
  }
  if (section >= state.n_sections)
  {
    return NULL;
  }
  return string + state.section_offsets[section];
}

uint8_t sbp_string_pack(const sbp_string_t string, const sbp_string_format_t *format, uint8_t *buf, uint8_t buf_len)
{
  struct string_state state;
  analyse(string, format, &state);
  if (!state.valid)
  {
    return 0;
  }
  if (state.packed_len > buf_len)
  {
    return 0;
  }
  memcpy(buf, string, state.packed_len);
  return state.packed_len;
}

uint8_t sbp_string_unpack(sbp_string_t string, const sbp_string_format_t *format, const uint8_t *buf, uint8_t buf_len)
{
  if (buf_len == 0)
  {
    sbp_string_init(string, format);
    return 0;
  }
  struct string_state state;
  sbp_string_format_t packed_format = *format;
  if (format->encoding == SBP_STRING_UNTERMINATED)
  {
    packed_format.max_encoded_len = (uint8_t)(sizeof(sbp_string_t) - 1);
  }
  if (buf_len < packed_format.max_encoded_len)
  {
    packed_format.max_encoded_len = buf_len;
  }
  analyse((const char *)buf, &packed_format, &state);
  if (!state.valid)
  {
    return 0;
  }
  uint8_t copy_len = state.packed_len;
  if (copy_len > format->max_encoded_len)
  {
    copy_len = format->max_encoded_len;
  }
  memcpy(string, buf, state.packed_len);
  memset(string + copy_len, 0, sizeof(sbp_string_t) - copy_len);
  return copy_len;
}

uint8_t sbp_string_count_sections(const sbp_string_t string, const sbp_string_format_t *format)
{
  struct string_state state;
  analyse(string, format, &state);
  if (!state.valid)
  {
    return 0;
  }
  return state.n_sections;
}

uint8_t sbp_string_space_remaining(const sbp_string_t string, const sbp_string_format_t *format)
{
  return (uint8_t)(format->max_encoded_len - sbp_string_packed_len(string, format));
}

void sbp_string_init(sbp_string_t string, const sbp_string_format_t *format)
{
  memset(string, 0, sizeof(sbp_string_t));
  if (format->encoding == SBP_STRING_SEQUENCE)
  {
    string[0] = (char)format->terminator;
  }
}
