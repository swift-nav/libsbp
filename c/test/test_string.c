#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <libsbp/string.h>

int main(int argc, char *argv[])
{
  (void)argc;
  (void)argv;
  uint8_t buf[255];

  sbp_msg_settings_read_req_t msg;
  memset(&msg, 0, sizeof(msg));

  assert(sbp_msg_settings_read_req_t_setting_total_len(&msg) == 0);
  assert(sbp_msg_settings_read_req_t_setting_count_sections(&msg) == 0);
  assert(sbp_msg_settings_read_req_t_setting_valid(&msg) == false);

  sbp_msg_settings_read_req_t_setting_init(&msg);
  assert(sbp_msg_settings_read_req_t_setting_total_len(&msg) == 2);
  assert(sbp_msg_settings_read_req_t_setting_count_sections(&msg) == 2);
  assert(sbp_msg_settings_read_req_t_setting_valid(&msg) == true);
  assert(sbp_msg_settings_read_req_t_setting_pack(buf, sizeof(buf), &msg) == 2);
  assert(memcmp(buf, "\0\0", 2) == 0);

  assert(sbp_msg_settings_read_req_t_setting_set_section(&msg, 0, "section") == true);
  assert(sbp_msg_settings_read_req_t_setting_total_len(&msg) == 9);
  assert(sbp_msg_settings_read_req_t_setting_count_sections(&msg) == 2);
  assert(sbp_msg_settings_read_req_t_setting_valid(&msg) == true);
  assert(sbp_msg_settings_read_req_t_setting_pack(buf, sizeof(buf), &msg) == 9);
  assert(memcmp(buf, "section\0\0", 9) == 0);

  assert(sbp_msg_settings_read_req_t_setting_set_section(&msg, 1, "setting") == true);
  assert(sbp_msg_settings_read_req_t_setting_total_len(&msg) == 16);
  assert(sbp_msg_settings_read_req_t_setting_count_sections(&msg) == 2);
  assert(sbp_msg_settings_read_req_t_setting_valid(&msg) == true);
  assert(sbp_msg_settings_read_req_t_setting_pack(buf, sizeof(buf), &msg) == 16);
  assert(memcmp(buf, "section\0setting\0", 16) == 0);

  assert(sbp_msg_settings_read_req_t_setting_set_section(&msg, 0, "long section") == true);
  assert(sbp_msg_settings_read_req_t_setting_total_len(&msg) == 21);
  assert(sbp_msg_settings_read_req_t_setting_count_sections(&msg) == 2);
  assert(sbp_msg_settings_read_req_t_setting_valid(&msg) == true);
  assert(sbp_msg_settings_read_req_t_setting_pack(buf, sizeof(buf), &msg) == 21);
  assert(memcmp(buf, "long section\0setting\0", 21) == 0);

  assert(sbp_msg_settings_read_req_t_setting_unpack("setting\0section\0", 16, &msg) == 16);
  assert(sbp_msg_settings_read_req_t_setting_valid(&msg) == true);
  assert(sbp_msg_settings_read_req_t_setting_total_len(&msg) == 16);
  assert(sbp_msg_settings_read_req_t_setting_count_sections(&msg) == 2);
  assert(strcmp(sbp_msg_settings_read_req_t_setting_get_section(&msg, 0), "setting") == 0);
  assert(strcmp(sbp_msg_settings_read_req_t_setting_get_section(&msg, 1), "section") == 0);

  return 0;
}
