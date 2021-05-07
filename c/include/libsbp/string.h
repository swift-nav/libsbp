#ifndef SBP_STRING_H
#define SBP_STRING_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C"
{
#endif

  typedef struct
  {
    uint8_t min_sections;
    uint8_t max_sections;
    bool null_terminated;
    bool has_sequence_terminator;
    char sequence_terminator;
    uint8_t max_size;
  } sbp_string_format_t;

  typedef struct
  {
    char data[255];
    uint8_t lens[255];
  } sbp_string_t;

  static inline bool sbp_string_valid(const sbp_string_t *string, const sbp_string_format_t *fmt);
  static inline uint8_t sbp_string_count_sections(const sbp_string_t *string, const sbp_string_format_t *fmt);

  static inline void sbp_string_init(sbp_string_t *string, const sbp_string_format_t *fmt)
  {
    memset(string, 0, sizeof(*string));
    for (uint8_t i = 0; i < fmt->min_sections; i++) {
      string->lens[i] = 1;
    }
  }

  static inline uint8_t sbp_string_section_len(const sbp_string_t *string, const sbp_string_format_t *fmt, uint8_t section_id)
  {
    if (section_id >= fmt->max_sections) { return 0;
    }
    return string->lens[section_id];
  }

  static inline const char *sbp_string_get_section(const sbp_string_t *string, const sbp_string_format_t *fmt, uint8_t section_id)
  {
    if (section_id >= fmt->max_sections) { return NULL; }
    uint8_t offset = 0;
    for (uint8_t i = 0; i < section_id; i++) {
      offset += string->lens[i];
    }
    return string->data + offset;
  }

  static inline uint8_t sbp_string_total_len(const sbp_string_t *string, const sbp_string_format_t *fmt)
  {
    if (fmt->max_sections == 1)
    {
      return string->lens[0] - (fmt->null_terminated ? 0 : 1);
    }

    uint8_t total = 0;
    for (uint8_t i = 0; i < fmt->max_sections; i++) {
      if (string->lens[i] == 0) { 
        if (i < fmt->min_sections) {
          return 0;
        }
        break;
      }
      total += string->lens[i];
    }

    return total + (fmt->has_sequence_terminator ? 1 : 0);
  }

  static inline bool
  sbp_string_set_section(sbp_string_t *string, const sbp_string_format_t *fmt, uint8_t section_id, const char *str)
  {
    if (section_id >= fmt->max_sections) { return false; }
    if (!sbp_string_valid(string, fmt)) { return false; }
    uint8_t n_sections = sbp_string_count_sections(string, fmt);
    if (section_id > (n_sections + 1)) { return false; }

    uint8_t total_len = sbp_string_total_len(string, fmt);
    size_t new_len_ = strlen(str);
    if (new_len_ > fmt->max_size) { return false; }
    uint8_t new_len = (uint8_t)new_len_;
    if ((total_len - string->lens[section_id] + new_len) > fmt->max_size) { return false; }

    char tmp[255];
    memset(tmp, 0, sizeof(tmp));
    uint8_t src_offset = 0;
    uint8_t dst_offset = 0;
    uint8_t max_sections = section_id;
    if (n_sections > max_sections) { max_sections = n_sections; }

    for (uint8_t section = 0; section < max_sections; section++) {
      if (section == section_id) {
        memcpy(tmp + dst_offset, str, new_len);
        src_offset += string->lens[section];
        string->lens[section] = new_len + 1;
        dst_offset += new_len + 1;
      } else {
        memcpy(tmp + dst_offset, string->data + src_offset, string->lens[section]);
        dst_offset += string->lens[section];
        src_offset += string->lens[section];
      }
    }
    memcpy(string->data, tmp, dst_offset);

    return true;
  }

  static inline uint8_t sbp_string_pack(uint8_t *buf, uint8_t buf_len, const sbp_string_t *string, const sbp_string_format_t *fmt)
  {
    uint8_t copy_len = sbp_string_total_len(string, fmt);
    if (buf_len < copy_len) 
    {
      return 0;
    }
    memcpy(buf, string->data, copy_len);
    buf_len -= copy_len;

    if (fmt->max_sections != fmt->min_sections && fmt->has_sequence_terminator) {
      if (buf_len == 0)
      {
        return 0;
      }
      buf[copy_len] = (uint8_t)fmt->sequence_terminator;
      copy_len++;
    }
    return copy_len;
  }

  static inline uint8_t
  sbp_string_unpack(const uint8_t *buf, uint8_t buf_len, sbp_string_t *string, const sbp_string_format_t *fmt)
  {
    uint8_t section = 0;
    memset(string, 0, sizeof(*string));
    uint8_t i;
    for (i = 0; i < buf_len && section < fmt->max_sections; i++) {
      string->data[i] = (char)buf[i];
      string->lens[section]++;
      if (buf[i] == 0) {
        section++;
      }
    }
    // Copy with non terminated packed strings
    string->data[i] = 0;
    return i;
  }

  static inline uint8_t sbp_string_count_sections(const sbp_string_t *string, const sbp_string_format_t *fmt)
  {
    // Count all non zero strings
    for (uint8_t i = 0; i < fmt->max_sections; i++) {
      if (string->lens[i] == 0) {
        return i;
      }
    }
    return fmt->max_sections;
  }

  static inline bool sbp_string_valid(const sbp_string_t *string, const sbp_string_format_t *fmt)
  {
    uint32_t total_len = 0;
    // All required sections must have a length of at least 1
    uint8_t i;
    for (i = 0; i < fmt->min_sections; i++) {
      if (string->lens[i] == 0) {
        return false;
      }
      total_len += string->lens[i];
    }

    // Count optional sections up to max
    for (;i < fmt->max_sections; i++) {
      if (string->lens[i] == 0) {
        break;
      }
      total_len += string->lens[i];
    }

    return total_len <= fmt->max_size;
  }

  static const sbp_string_format_t sbp_msg_settings_read_req_t_setting_string_format = { 2, 2, true, false, 0, 255 };

  typedef struct
  {
    sbp_string_t setting;
  } sbp_msg_settings_read_req_t;

  static inline void sbp_msg_settings_read_req_t_setting_init(sbp_msg_settings_read_req_t *msg)
  {
    sbp_string_init(&msg->setting, &sbp_msg_settings_read_req_t_setting_string_format);
  }

  static inline uint8_t sbp_msg_settings_read_req_t_setting_section_len(sbp_msg_settings_read_req_t *msg,
                                                                        uint8_t section_id)
  {
    return sbp_string_section_len(&msg->setting, &sbp_msg_settings_read_req_t_setting_string_format, section_id);
  }

  static inline const char *sbp_msg_settings_read_req_t_setting_get_section(sbp_msg_settings_read_req_t *msg,
                                                                            uint8_t section_id)
  {
    return sbp_string_get_section(&msg->setting, &sbp_msg_settings_read_req_t_setting_string_format, section_id);
  }

  static inline uint8_t sbp_msg_settings_read_req_t_setting_total_len(sbp_msg_settings_read_req_t *msg)
  {
    return sbp_string_total_len(&msg->setting, &sbp_msg_settings_read_req_t_setting_string_format);
  }

  static inline bool
  sbp_msg_settings_read_req_t_setting_set_section(sbp_msg_settings_read_req_t *msg, uint8_t section_id, const char *str)
  {
    return sbp_string_set_section(&msg->setting, &sbp_msg_settings_read_req_t_setting_string_format, section_id, str);
  }

  static inline uint8_t
  sbp_msg_settings_read_req_t_setting_pack(uint8_t *buf, uint8_t buf_len, const sbp_msg_settings_read_req_t *msg)
  {
    return sbp_string_pack(buf, buf_len, &msg->setting, &sbp_msg_settings_read_req_t_setting_string_format);
  }

  static inline uint8_t
  sbp_msg_settings_read_req_t_setting_unpack(const uint8_t *buf, uint8_t buf_len, sbp_msg_settings_read_req_t *msg)
  {
    return sbp_string_unpack(buf, buf_len, &msg->setting, &sbp_msg_settings_read_req_t_setting_string_format);
  }

  static inline uint8_t sbp_msg_settings_read_req_t_setting_count_sections(const sbp_msg_settings_read_req_t *msg)
  {
    return sbp_string_count_sections(&msg->setting, &sbp_msg_settings_read_req_t_setting_string_format);
  }

  static inline bool sbp_msg_settings_read_req_t_setting_valid(const sbp_msg_settings_read_req_t *msg)
  {
    return sbp_string_valid(&msg->setting, &sbp_msg_settings_read_req_t_setting_string_format);
  }

#ifdef __cplusplus
}
#endif

#endif
