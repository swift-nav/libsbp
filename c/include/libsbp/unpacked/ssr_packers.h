#ifndef LIBSBP_SSR_PACKERS_H
#define LIBSBP_SSR_PACKERS_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/gnss.h>
#include <libsbp/unpacked/ssr.h>

static inline size_t sbp_packed_size_sbp_code_biases_content_t(const sbp_code_biases_content_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->code) + sizeof(msg->value);
}

static inline bool sbp_pack_sbp_code_biases_content_t(u8 *buf, size_t len, const sbp_code_biases_content_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_code_biases_content_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcode = msg->code;
  memcpy(buf + offset, &msgcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgvalue = htole16(*(const u16 *)&msg->value);
  memcpy(buf + offset, &msgvalue, 2);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_code_biases_content_t(const u8 *buf, size_t len, sbp_code_biases_content_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->value, buf + offset, 2);
  u16 msgvalue = *(const u16 *)&msg->value;
  msgvalue = le16toh(msgvalue);
  msg->value = *(const s16 *)&msgvalue;
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_phase_biases_content_t(const sbp_phase_biases_content_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->code) + sizeof(msg->integer_indicator) + sizeof(msg->widelane_integer_indicator) +
         sizeof(msg->discontinuity_counter) + sizeof(msg->bias);
}

static inline bool sbp_pack_sbp_phase_biases_content_t(u8 *buf, size_t len, const sbp_phase_biases_content_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_phase_biases_content_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcode = msg->code;
  memcpy(buf + offset, &msgcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msginteger_indicator = msg->integer_indicator;
  memcpy(buf + offset, &msginteger_indicator, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgwidelane_integer_indicator = msg->widelane_integer_indicator;
  memcpy(buf + offset, &msgwidelane_integer_indicator, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgdiscontinuity_counter = msg->discontinuity_counter;
  memcpy(buf + offset, &msgdiscontinuity_counter, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgbias = htole32(*(const u32 *)&msg->bias);
  memcpy(buf + offset, &msgbias, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_phase_biases_content_t(const u8 *buf, size_t len, sbp_phase_biases_content_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->integer_indicator, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->widelane_integer_indicator, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->discontinuity_counter, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->bias, buf + offset, 4);
  u32 msgbias = *(const u32 *)&msg->bias;
  msgbias = le32toh(msgbias);
  msg->bias = *(const s32 *)&msgbias;
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_stec_header_t(const sbp_stec_header_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tile_set_id) + sizeof(msg->tile_id) + (0 + sizeof(msg->time.tow) + sizeof(msg->time.wn)) +
         sizeof(msg->num_msgs) + sizeof(msg->seq_num) + sizeof(msg->update_interval) + sizeof(msg->iod_atmo);
}

static inline bool sbp_pack_sbp_stec_header_t(u8 *buf, size_t len, const sbp_stec_header_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_stec_header_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtile_set_id = htole16(msg->tile_set_id);
  memcpy(buf + offset, &msgtile_set_id, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtile_id = htole16(msg->tile_id);
  memcpy(buf + offset, &msgtile_id, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtimetow = htole32(msg->time.tow);
  memcpy(buf + offset, &msgtimetow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtimewn = htole16(msg->time.wn);
  memcpy(buf + offset, &msgtimewn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgnum_msgs = msg->num_msgs;
  memcpy(buf + offset, &msgnum_msgs, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgseq_num = msg->seq_num;
  memcpy(buf + offset, &msgseq_num, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgupdate_interval = msg->update_interval;
  memcpy(buf + offset, &msgupdate_interval, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgiod_atmo = msg->iod_atmo;
  memcpy(buf + offset, &msgiod_atmo, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_stec_header_t(const u8 *buf, size_t len, sbp_stec_header_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->tile_set_id, buf + offset, 2);
  msg->tile_set_id = le16toh(msg->tile_set_id);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->tile_id, buf + offset, 2);
  msg->tile_id = le16toh(msg->tile_id);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->time.tow, buf + offset, 4);
  msg->time.tow = le32toh(msg->time.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->time.wn, buf + offset, 2);
  msg->time.wn = le16toh(msg->time.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->num_msgs, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->seq_num, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->update_interval, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->iod_atmo, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_gridded_correction_header_t(const sbp_gridded_correction_header_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tile_set_id) + sizeof(msg->tile_id) + (0 + sizeof(msg->time.tow) + sizeof(msg->time.wn)) +
         sizeof(msg->num_msgs) + sizeof(msg->seq_num) + sizeof(msg->update_interval) + sizeof(msg->iod_atmo) +
         sizeof(msg->tropo_quality_indicator);
}

static inline bool
sbp_pack_sbp_gridded_correction_header_t(u8 *buf, size_t len, const sbp_gridded_correction_header_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_gridded_correction_header_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtile_set_id = htole16(msg->tile_set_id);
  memcpy(buf + offset, &msgtile_set_id, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtile_id = htole16(msg->tile_id);
  memcpy(buf + offset, &msgtile_id, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtimetow = htole32(msg->time.tow);
  memcpy(buf + offset, &msgtimetow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtimewn = htole16(msg->time.wn);
  memcpy(buf + offset, &msgtimewn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgnum_msgs = htole16(msg->num_msgs);
  memcpy(buf + offset, &msgnum_msgs, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgseq_num = htole16(msg->seq_num);
  memcpy(buf + offset, &msgseq_num, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgupdate_interval = msg->update_interval;
  memcpy(buf + offset, &msgupdate_interval, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgiod_atmo = msg->iod_atmo;
  memcpy(buf + offset, &msgiod_atmo, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgtropo_quality_indicator = msg->tropo_quality_indicator;
  memcpy(buf + offset, &msgtropo_quality_indicator, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool
sbp_unpack_sbp_gridded_correction_header_t(const u8 *buf, size_t len, sbp_gridded_correction_header_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->tile_set_id, buf + offset, 2);
  msg->tile_set_id = le16toh(msg->tile_set_id);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->tile_id, buf + offset, 2);
  msg->tile_id = le16toh(msg->tile_id);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->time.tow, buf + offset, 4);
  msg->time.tow = le32toh(msg->time.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->time.wn, buf + offset, 2);
  msg->time.wn = le16toh(msg->time.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->num_msgs, buf + offset, 2);
  msg->num_msgs = le16toh(msg->num_msgs);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->seq_num, buf + offset, 2);
  msg->seq_num = le16toh(msg->seq_num);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->update_interval, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->iod_atmo, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->tropo_quality_indicator, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_stec_sat_element_t(const sbp_stec_sat_element_t *msg)
{
  (void)msg;
  return 0 + (0 + sizeof(msg->sv_id.satId) + sizeof(msg->sv_id.constellation)) + sizeof(msg->stec_quality_indicator) +
         (4 * sizeof(msg->stec_coeff[0]));
}

static inline bool sbp_pack_sbp_stec_sat_element_t(u8 *buf, size_t len, const sbp_stec_sat_element_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_stec_sat_element_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsv_idsatId = msg->sv_id.satId;
  memcpy(buf + offset, &msgsv_idsatId, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsv_idconstellation = msg->sv_id.constellation;
  memcpy(buf + offset, &msgsv_idconstellation, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgstec_quality_indicator = msg->stec_quality_indicator;
  memcpy(buf + offset, &msgstec_quality_indicator, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgstec_coeff_idx = 0; msgstec_coeff_idx < 4; msgstec_coeff_idx++)
  {

    if (offset + 2 > len)
    {
      return false;
    }
    u16 msgstec_coeffmsgstec_coeff_idx = htole16(*(const u16 *)&msg->stec_coeff[msgstec_coeff_idx]);
    memcpy(buf + offset, &msgstec_coeffmsgstec_coeff_idx, 2);
    // NOLINTNEXTLINE
    offset += 2;
  }
  return true;
}

static inline bool sbp_unpack_sbp_stec_sat_element_t(const u8 *buf, size_t len, sbp_stec_sat_element_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sv_id.satId, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sv_id.constellation, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->stec_quality_indicator, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgstec_coeff_idx = 0; msgstec_coeff_idx < 4; msgstec_coeff_idx++)
  {

    if (offset + 2 > len)
    {
      return false;
    }
    memcpy(&msg->stec_coeff[msgstec_coeff_idx], buf + offset, 2);
    u16 msgstec_coeffmsgstec_coeff_idx = *(const u16 *)&msg->stec_coeff[msgstec_coeff_idx];
    msgstec_coeffmsgstec_coeff_idx = le16toh(msgstec_coeffmsgstec_coeff_idx);
    msg->stec_coeff[msgstec_coeff_idx] = *(const s16 *)&msgstec_coeffmsgstec_coeff_idx;
    // NOLINTNEXTLINE
    offset += 2;
  }
  return true;
}

static inline size_t
sbp_packed_size_sbp_tropospheric_delay_correction_no_std_t(const sbp_tropospheric_delay_correction_no_std_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->hydro) + sizeof(msg->wet);
}

static inline bool
sbp_pack_sbp_tropospheric_delay_correction_no_std_t(u8 *buf,
                                                    size_t len,
                                                    const sbp_tropospheric_delay_correction_no_std_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_tropospheric_delay_correction_no_std_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msghydro = htole16(*(const u16 *)&msg->hydro);
  memcpy(buf + offset, &msghydro, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  s8 msgwet = msg->wet;
  memcpy(buf + offset, &msgwet, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool
sbp_unpack_sbp_tropospheric_delay_correction_no_std_t(const u8 *buf,
                                                      size_t len,
                                                      sbp_tropospheric_delay_correction_no_std_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->hydro, buf + offset, 2);
  u16 msghydro = *(const u16 *)&msg->hydro;
  msghydro = le16toh(msghydro);
  msg->hydro = *(const s16 *)&msghydro;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->wet, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_tropospheric_delay_correction_t(const sbp_tropospheric_delay_correction_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->hydro) + sizeof(msg->wet) + sizeof(msg->stddev);
}

static inline bool
sbp_pack_sbp_tropospheric_delay_correction_t(u8 *buf, size_t len, const sbp_tropospheric_delay_correction_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_tropospheric_delay_correction_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msghydro = htole16(*(const u16 *)&msg->hydro);
  memcpy(buf + offset, &msghydro, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  s8 msgwet = msg->wet;
  memcpy(buf + offset, &msgwet, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgstddev = msg->stddev;
  memcpy(buf + offset, &msgstddev, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool
sbp_unpack_sbp_tropospheric_delay_correction_t(const u8 *buf, size_t len, sbp_tropospheric_delay_correction_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->hydro, buf + offset, 2);
  u16 msghydro = *(const u16 *)&msg->hydro;
  msghydro = le16toh(msghydro);
  msg->hydro = *(const s16 *)&msghydro;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->wet, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->stddev, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_stec_residual_no_std_t(const sbp_stec_residual_no_std_t *msg)
{
  (void)msg;
  return 0 + (0 + sizeof(msg->sv_id.satId) + sizeof(msg->sv_id.constellation)) + sizeof(msg->residual);
}

static inline bool sbp_pack_sbp_stec_residual_no_std_t(u8 *buf, size_t len, const sbp_stec_residual_no_std_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_stec_residual_no_std_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsv_idsatId = msg->sv_id.satId;
  memcpy(buf + offset, &msgsv_idsatId, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsv_idconstellation = msg->sv_id.constellation;
  memcpy(buf + offset, &msgsv_idconstellation, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgresidual = htole16(*(const u16 *)&msg->residual);
  memcpy(buf + offset, &msgresidual, 2);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_stec_residual_no_std_t(const u8 *buf, size_t len, sbp_stec_residual_no_std_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sv_id.satId, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sv_id.constellation, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->residual, buf + offset, 2);
  u16 msgresidual = *(const u16 *)&msg->residual;
  msgresidual = le16toh(msgresidual);
  msg->residual = *(const s16 *)&msgresidual;
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_stec_residual_t(const sbp_stec_residual_t *msg)
{
  (void)msg;
  return 0 + (0 + sizeof(msg->sv_id.satId) + sizeof(msg->sv_id.constellation)) + sizeof(msg->residual) +
         sizeof(msg->stddev);
}

static inline bool sbp_pack_sbp_stec_residual_t(u8 *buf, size_t len, const sbp_stec_residual_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_stec_residual_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsv_idsatId = msg->sv_id.satId;
  memcpy(buf + offset, &msgsv_idsatId, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsv_idconstellation = msg->sv_id.constellation;
  memcpy(buf + offset, &msgsv_idconstellation, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgresidual = htole16(*(const u16 *)&msg->residual);
  memcpy(buf + offset, &msgresidual, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgstddev = msg->stddev;
  memcpy(buf + offset, &msgstddev, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_stec_residual_t(const u8 *buf, size_t len, sbp_stec_residual_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sv_id.satId, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sv_id.constellation, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->residual, buf + offset, 2);
  u16 msgresidual = *(const u16 *)&msg->residual;
  msgresidual = le16toh(msgresidual);
  msg->residual = *(const s16 *)&msgresidual;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->stddev, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_grid_element_no_std_t(const sbp_grid_element_no_std_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->index) +
         (0 + sizeof(msg->tropo_delay_correction.hydro) + sizeof(msg->tropo_delay_correction.wet)) +
         (msg->n_stec_residuals *
          (0 + (0 + sizeof(msg->stec_residuals[0].sv_id.satId) + sizeof(msg->stec_residuals[0].sv_id.constellation)) +
           sizeof(msg->stec_residuals[0].residual)));
}

static inline bool sbp_pack_sbp_grid_element_no_std_t(u8 *buf, size_t len, const sbp_grid_element_no_std_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_grid_element_no_std_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgindex = htole16(msg->index);
  memcpy(buf + offset, &msgindex, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtropo_delay_correctionhydro = htole16(*(const u16 *)&msg->tropo_delay_correction.hydro);
  memcpy(buf + offset, &msgtropo_delay_correctionhydro, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  s8 msgtropo_delay_correctionwet = msg->tropo_delay_correction.wet;
  memcpy(buf + offset, &msgtropo_delay_correctionwet, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgstec_residuals_idx = 0; msgstec_residuals_idx < (size_t)msg->n_stec_residuals; msgstec_residuals_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstec_residualsmsgstec_residuals_idxsv_idsatId = msg->stec_residuals[msgstec_residuals_idx].sv_id.satId;
    memcpy(buf + offset, &msgstec_residualsmsgstec_residuals_idxsv_idsatId, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstec_residualsmsgstec_residuals_idxsv_idconstellation =
        msg->stec_residuals[msgstec_residuals_idx].sv_id.constellation;
    memcpy(buf + offset, &msgstec_residualsmsgstec_residuals_idxsv_idconstellation, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 2 > len)
    {
      return false;
    }
    u16 msgstec_residualsmsgstec_residuals_idxresidual =
        htole16(*(const u16 *)&msg->stec_residuals[msgstec_residuals_idx].residual);
    memcpy(buf + offset, &msgstec_residualsmsgstec_residuals_idxresidual, 2);
    // NOLINTNEXTLINE
    offset += 2;
  }
  return true;
}

static inline bool sbp_unpack_sbp_grid_element_no_std_t(const u8 *buf, size_t len, sbp_grid_element_no_std_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->index, buf + offset, 2);
  msg->index = le16toh(msg->index);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->tropo_delay_correction.hydro, buf + offset, 2);
  u16 msgtropo_delay_correctionhydro = *(const u16 *)&msg->tropo_delay_correction.hydro;
  msgtropo_delay_correctionhydro = le16toh(msgtropo_delay_correctionhydro);
  msg->tropo_delay_correction.hydro = *(const s16 *)&msgtropo_delay_correctionhydro;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->tropo_delay_correction.wet, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  msg->n_stec_residuals = (u8)((len - offset) / 4);

  for (size_t msgstec_residuals_idx = 0; msgstec_residuals_idx < msg->n_stec_residuals; msgstec_residuals_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->stec_residuals[msgstec_residuals_idx].sv_id.satId, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->stec_residuals[msgstec_residuals_idx].sv_id.constellation, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 2 > len)
    {
      return false;
    }
    memcpy(&msg->stec_residuals[msgstec_residuals_idx].residual, buf + offset, 2);
    u16 msgstec_residualsmsgstec_residuals_idxresidual =
        *(const u16 *)&msg->stec_residuals[msgstec_residuals_idx].residual;
    msgstec_residualsmsgstec_residuals_idxresidual = le16toh(msgstec_residualsmsgstec_residuals_idxresidual);
    msg->stec_residuals[msgstec_residuals_idx].residual = *(const s16 *)&msgstec_residualsmsgstec_residuals_idxresidual;
    // NOLINTNEXTLINE
    offset += 2;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_grid_element_t(const sbp_grid_element_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->index) +
         (0 + sizeof(msg->tropo_delay_correction.hydro) + sizeof(msg->tropo_delay_correction.wet) +
          sizeof(msg->tropo_delay_correction.stddev)) +
         (msg->n_stec_residuals *
          (0 + (0 + sizeof(msg->stec_residuals[0].sv_id.satId) + sizeof(msg->stec_residuals[0].sv_id.constellation)) +
           sizeof(msg->stec_residuals[0].residual) + sizeof(msg->stec_residuals[0].stddev)));
}

static inline bool sbp_pack_sbp_grid_element_t(u8 *buf, size_t len, const sbp_grid_element_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_grid_element_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgindex = htole16(msg->index);
  memcpy(buf + offset, &msgindex, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtropo_delay_correctionhydro = htole16(*(const u16 *)&msg->tropo_delay_correction.hydro);
  memcpy(buf + offset, &msgtropo_delay_correctionhydro, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  s8 msgtropo_delay_correctionwet = msg->tropo_delay_correction.wet;
  memcpy(buf + offset, &msgtropo_delay_correctionwet, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgtropo_delay_correctionstddev = msg->tropo_delay_correction.stddev;
  memcpy(buf + offset, &msgtropo_delay_correctionstddev, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgstec_residuals_idx = 0; msgstec_residuals_idx < (size_t)msg->n_stec_residuals; msgstec_residuals_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstec_residualsmsgstec_residuals_idxsv_idsatId = msg->stec_residuals[msgstec_residuals_idx].sv_id.satId;
    memcpy(buf + offset, &msgstec_residualsmsgstec_residuals_idxsv_idsatId, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstec_residualsmsgstec_residuals_idxsv_idconstellation =
        msg->stec_residuals[msgstec_residuals_idx].sv_id.constellation;
    memcpy(buf + offset, &msgstec_residualsmsgstec_residuals_idxsv_idconstellation, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 2 > len)
    {
      return false;
    }
    u16 msgstec_residualsmsgstec_residuals_idxresidual =
        htole16(*(const u16 *)&msg->stec_residuals[msgstec_residuals_idx].residual);
    memcpy(buf + offset, &msgstec_residualsmsgstec_residuals_idxresidual, 2);
    // NOLINTNEXTLINE
    offset += 2;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstec_residualsmsgstec_residuals_idxstddev = msg->stec_residuals[msgstec_residuals_idx].stddev;
    memcpy(buf + offset, &msgstec_residualsmsgstec_residuals_idxstddev, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_grid_element_t(const u8 *buf, size_t len, sbp_grid_element_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->index, buf + offset, 2);
  msg->index = le16toh(msg->index);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->tropo_delay_correction.hydro, buf + offset, 2);
  u16 msgtropo_delay_correctionhydro = *(const u16 *)&msg->tropo_delay_correction.hydro;
  msgtropo_delay_correctionhydro = le16toh(msgtropo_delay_correctionhydro);
  msg->tropo_delay_correction.hydro = *(const s16 *)&msgtropo_delay_correctionhydro;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->tropo_delay_correction.wet, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->tropo_delay_correction.stddev, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  msg->n_stec_residuals = (u8)((len - offset) / 5);

  for (size_t msgstec_residuals_idx = 0; msgstec_residuals_idx < msg->n_stec_residuals; msgstec_residuals_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->stec_residuals[msgstec_residuals_idx].sv_id.satId, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->stec_residuals[msgstec_residuals_idx].sv_id.constellation, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 2 > len)
    {
      return false;
    }
    memcpy(&msg->stec_residuals[msgstec_residuals_idx].residual, buf + offset, 2);
    u16 msgstec_residualsmsgstec_residuals_idxresidual =
        *(const u16 *)&msg->stec_residuals[msgstec_residuals_idx].residual;
    msgstec_residualsmsgstec_residuals_idxresidual = le16toh(msgstec_residualsmsgstec_residuals_idxresidual);
    msg->stec_residuals[msgstec_residuals_idx].residual = *(const s16 *)&msgstec_residualsmsgstec_residuals_idxresidual;
    // NOLINTNEXTLINE
    offset += 2;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->stec_residuals[msgstec_residuals_idx].stddev, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ssr_orbit_clock_t(const sbp_msg_ssr_orbit_clock_t *msg)
{
  (void)msg;
  return 0 + (0 + sizeof(msg->time.tow) + sizeof(msg->time.wn)) + (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code)) +
         sizeof(msg->update_interval) + sizeof(msg->iod_ssr) + sizeof(msg->iod) + sizeof(msg->radial) +
         sizeof(msg->along) + sizeof(msg->cross) + sizeof(msg->dot_radial) + sizeof(msg->dot_along) +
         sizeof(msg->dot_cross) + sizeof(msg->c0) + sizeof(msg->c1) + sizeof(msg->c2);
}

static inline bool sbp_pack_sbp_msg_ssr_orbit_clock_t(u8 *buf, size_t len, const sbp_msg_ssr_orbit_clock_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ssr_orbit_clock_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtimetow = htole32(msg->time.tow);
  memcpy(buf + offset, &msgtimetow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtimewn = htole16(msg->time.wn);
  memcpy(buf + offset, &msgtimewn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidsat = msg->sid.sat;
  memcpy(buf + offset, &msgsidsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgupdate_interval = msg->update_interval;
  memcpy(buf + offset, &msgupdate_interval, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgiod_ssr = msg->iod_ssr;
  memcpy(buf + offset, &msgiod_ssr, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgiod = htole32(msg->iod);
  memcpy(buf + offset, &msgiod, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgradial = htole32(*(const u32 *)&msg->radial);
  memcpy(buf + offset, &msgradial, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgalong = htole32(*(const u32 *)&msg->along);
  memcpy(buf + offset, &msgalong, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcross = htole32(*(const u32 *)&msg->cross);
  memcpy(buf + offset, &msgcross, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgdot_radial = htole32(*(const u32 *)&msg->dot_radial);
  memcpy(buf + offset, &msgdot_radial, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgdot_along = htole32(*(const u32 *)&msg->dot_along);
  memcpy(buf + offset, &msgdot_along, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgdot_cross = htole32(*(const u32 *)&msg->dot_cross);
  memcpy(buf + offset, &msgdot_cross, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgc0 = htole32(*(const u32 *)&msg->c0);
  memcpy(buf + offset, &msgc0, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgc1 = htole32(*(const u32 *)&msg->c1);
  memcpy(buf + offset, &msgc1, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgc2 = htole32(*(const u32 *)&msg->c2);
  memcpy(buf + offset, &msgc2, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_orbit_clock_t(const u8 *buf, size_t len, sbp_msg_ssr_orbit_clock_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->time.tow, buf + offset, 4);
  msg->time.tow = le32toh(msg->time.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->time.wn, buf + offset, 2);
  msg->time.wn = le16toh(msg->time.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->update_interval, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->iod_ssr, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->iod, buf + offset, 4);
  msg->iod = le32toh(msg->iod);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->radial, buf + offset, 4);
  u32 msgradial = *(const u32 *)&msg->radial;
  msgradial = le32toh(msgradial);
  msg->radial = *(const s32 *)&msgradial;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->along, buf + offset, 4);
  u32 msgalong = *(const u32 *)&msg->along;
  msgalong = le32toh(msgalong);
  msg->along = *(const s32 *)&msgalong;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cross, buf + offset, 4);
  u32 msgcross = *(const u32 *)&msg->cross;
  msgcross = le32toh(msgcross);
  msg->cross = *(const s32 *)&msgcross;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->dot_radial, buf + offset, 4);
  u32 msgdot_radial = *(const u32 *)&msg->dot_radial;
  msgdot_radial = le32toh(msgdot_radial);
  msg->dot_radial = *(const s32 *)&msgdot_radial;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->dot_along, buf + offset, 4);
  u32 msgdot_along = *(const u32 *)&msg->dot_along;
  msgdot_along = le32toh(msgdot_along);
  msg->dot_along = *(const s32 *)&msgdot_along;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->dot_cross, buf + offset, 4);
  u32 msgdot_cross = *(const u32 *)&msg->dot_cross;
  msgdot_cross = le32toh(msgdot_cross);
  msg->dot_cross = *(const s32 *)&msgdot_cross;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c0, buf + offset, 4);
  u32 msgc0 = *(const u32 *)&msg->c0;
  msgc0 = le32toh(msgc0);
  msg->c0 = *(const s32 *)&msgc0;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c1, buf + offset, 4);
  u32 msgc1 = *(const u32 *)&msg->c1;
  msgc1 = le32toh(msgc1);
  msg->c1 = *(const s32 *)&msgc1;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c2, buf + offset, 4);
  u32 msgc2 = *(const u32 *)&msg->c2;
  msgc2 = le32toh(msgc2);
  msg->c2 = *(const s32 *)&msgc2;
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ssr_code_biases_t(const sbp_msg_ssr_code_biases_t *msg)
{
  (void)msg;
  return 0 + (0 + sizeof(msg->time.tow) + sizeof(msg->time.wn)) + (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code)) +
         sizeof(msg->update_interval) + sizeof(msg->iod_ssr) +
         (msg->n_biases * (0 + sizeof(msg->biases[0].code) + sizeof(msg->biases[0].value)));
}

static inline bool sbp_pack_sbp_msg_ssr_code_biases_t(u8 *buf, size_t len, const sbp_msg_ssr_code_biases_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ssr_code_biases_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtimetow = htole32(msg->time.tow);
  memcpy(buf + offset, &msgtimetow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtimewn = htole16(msg->time.wn);
  memcpy(buf + offset, &msgtimewn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidsat = msg->sid.sat;
  memcpy(buf + offset, &msgsidsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgupdate_interval = msg->update_interval;
  memcpy(buf + offset, &msgupdate_interval, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgiod_ssr = msg->iod_ssr;
  memcpy(buf + offset, &msgiod_ssr, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgbiases_idx = 0; msgbiases_idx < (size_t)msg->n_biases; msgbiases_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgbiasesmsgbiases_idxcode = msg->biases[msgbiases_idx].code;
    memcpy(buf + offset, &msgbiasesmsgbiases_idxcode, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 2 > len)
    {
      return false;
    }
    u16 msgbiasesmsgbiases_idxvalue = htole16(*(const u16 *)&msg->biases[msgbiases_idx].value);
    memcpy(buf + offset, &msgbiasesmsgbiases_idxvalue, 2);
    // NOLINTNEXTLINE
    offset += 2;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_code_biases_t(const u8 *buf, size_t len, sbp_msg_ssr_code_biases_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->time.tow, buf + offset, 4);
  msg->time.tow = le32toh(msg->time.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->time.wn, buf + offset, 2);
  msg->time.wn = le16toh(msg->time.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->update_interval, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->iod_ssr, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  msg->n_biases = (u8)((len - offset) / 3);

  for (size_t msgbiases_idx = 0; msgbiases_idx < msg->n_biases; msgbiases_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->biases[msgbiases_idx].code, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 2 > len)
    {
      return false;
    }
    memcpy(&msg->biases[msgbiases_idx].value, buf + offset, 2);
    u16 msgbiasesmsgbiases_idxvalue = *(const u16 *)&msg->biases[msgbiases_idx].value;
    msgbiasesmsgbiases_idxvalue = le16toh(msgbiasesmsgbiases_idxvalue);
    msg->biases[msgbiases_idx].value = *(const s16 *)&msgbiasesmsgbiases_idxvalue;
    // NOLINTNEXTLINE
    offset += 2;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ssr_phase_biases_t(const sbp_msg_ssr_phase_biases_t *msg)
{
  (void)msg;
  return 0 + (0 + sizeof(msg->time.tow) + sizeof(msg->time.wn)) + (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code)) +
         sizeof(msg->update_interval) + sizeof(msg->iod_ssr) + sizeof(msg->dispersive_bias) +
         sizeof(msg->mw_consistency) + sizeof(msg->yaw) + sizeof(msg->yaw_rate) +
         (msg->n_biases * (0 + sizeof(msg->biases[0].code) + sizeof(msg->biases[0].integer_indicator) +
                           sizeof(msg->biases[0].widelane_integer_indicator) +
                           sizeof(msg->biases[0].discontinuity_counter) + sizeof(msg->biases[0].bias)));
}

static inline bool sbp_pack_sbp_msg_ssr_phase_biases_t(u8 *buf, size_t len, const sbp_msg_ssr_phase_biases_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ssr_phase_biases_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtimetow = htole32(msg->time.tow);
  memcpy(buf + offset, &msgtimetow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtimewn = htole16(msg->time.wn);
  memcpy(buf + offset, &msgtimewn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidsat = msg->sid.sat;
  memcpy(buf + offset, &msgsidsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgupdate_interval = msg->update_interval;
  memcpy(buf + offset, &msgupdate_interval, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgiod_ssr = msg->iod_ssr;
  memcpy(buf + offset, &msgiod_ssr, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgdispersive_bias = msg->dispersive_bias;
  memcpy(buf + offset, &msgdispersive_bias, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgmw_consistency = msg->mw_consistency;
  memcpy(buf + offset, &msgmw_consistency, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgyaw = htole16(msg->yaw);
  memcpy(buf + offset, &msgyaw, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  s8 msgyaw_rate = msg->yaw_rate;
  memcpy(buf + offset, &msgyaw_rate, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgbiases_idx = 0; msgbiases_idx < (size_t)msg->n_biases; msgbiases_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgbiasesmsgbiases_idxcode = msg->biases[msgbiases_idx].code;
    memcpy(buf + offset, &msgbiasesmsgbiases_idxcode, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgbiasesmsgbiases_idxinteger_indicator = msg->biases[msgbiases_idx].integer_indicator;
    memcpy(buf + offset, &msgbiasesmsgbiases_idxinteger_indicator, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgbiasesmsgbiases_idxwidelane_integer_indicator = msg->biases[msgbiases_idx].widelane_integer_indicator;
    memcpy(buf + offset, &msgbiasesmsgbiases_idxwidelane_integer_indicator, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgbiasesmsgbiases_idxdiscontinuity_counter = msg->biases[msgbiases_idx].discontinuity_counter;
    memcpy(buf + offset, &msgbiasesmsgbiases_idxdiscontinuity_counter, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 4 > len)
    {
      return false;
    }
    u32 msgbiasesmsgbiases_idxbias = htole32(*(const u32 *)&msg->biases[msgbiases_idx].bias);
    memcpy(buf + offset, &msgbiasesmsgbiases_idxbias, 4);
    // NOLINTNEXTLINE
    offset += 4;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_phase_biases_t(const u8 *buf, size_t len, sbp_msg_ssr_phase_biases_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->time.tow, buf + offset, 4);
  msg->time.tow = le32toh(msg->time.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->time.wn, buf + offset, 2);
  msg->time.wn = le16toh(msg->time.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->update_interval, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->iod_ssr, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->dispersive_bias, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->mw_consistency, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->yaw, buf + offset, 2);
  msg->yaw = le16toh(msg->yaw);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->yaw_rate, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  msg->n_biases = (u8)((len - offset) / 8);

  for (size_t msgbiases_idx = 0; msgbiases_idx < msg->n_biases; msgbiases_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->biases[msgbiases_idx].code, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->biases[msgbiases_idx].integer_indicator, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->biases[msgbiases_idx].widelane_integer_indicator, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->biases[msgbiases_idx].discontinuity_counter, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 4 > len)
    {
      return false;
    }
    memcpy(&msg->biases[msgbiases_idx].bias, buf + offset, 4);
    u32 msgbiasesmsgbiases_idxbias = *(const u32 *)&msg->biases[msgbiases_idx].bias;
    msgbiasesmsgbiases_idxbias = le32toh(msgbiasesmsgbiases_idxbias);
    msg->biases[msgbiases_idx].bias = *(const s32 *)&msgbiasesmsgbiases_idxbias;
    // NOLINTNEXTLINE
    offset += 4;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ssr_stec_correction_t(const sbp_msg_ssr_stec_correction_t *msg)
{
  (void)msg;
  return 0 +
         (0 + sizeof(msg->header.tile_set_id) + sizeof(msg->header.tile_id) +
          (0 + sizeof(msg->header.time.tow) + sizeof(msg->header.time.wn)) + sizeof(msg->header.num_msgs) +
          sizeof(msg->header.seq_num) + sizeof(msg->header.update_interval) + sizeof(msg->header.iod_atmo)) +
         (msg->n_stec_sat_list *
          (0 + (0 + sizeof(msg->stec_sat_list[0].sv_id.satId) + sizeof(msg->stec_sat_list[0].sv_id.constellation)) +
           sizeof(msg->stec_sat_list[0].stec_quality_indicator) + (4 * sizeof(msg->stec_sat_list[0].stec_coeff[0]))));
}

static inline bool sbp_pack_sbp_msg_ssr_stec_correction_t(u8 *buf, size_t len, const sbp_msg_ssr_stec_correction_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ssr_stec_correction_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgheadertile_set_id = htole16(msg->header.tile_set_id);
  memcpy(buf + offset, &msgheadertile_set_id, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgheadertile_id = htole16(msg->header.tile_id);
  memcpy(buf + offset, &msgheadertile_id, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgheadertimetow = htole32(msg->header.time.tow);
  memcpy(buf + offset, &msgheadertimetow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgheadertimewn = htole16(msg->header.time.wn);
  memcpy(buf + offset, &msgheadertimewn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgheadernum_msgs = msg->header.num_msgs;
  memcpy(buf + offset, &msgheadernum_msgs, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgheaderseq_num = msg->header.seq_num;
  memcpy(buf + offset, &msgheaderseq_num, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgheaderupdate_interval = msg->header.update_interval;
  memcpy(buf + offset, &msgheaderupdate_interval, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgheaderiod_atmo = msg->header.iod_atmo;
  memcpy(buf + offset, &msgheaderiod_atmo, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgstec_sat_list_idx = 0; msgstec_sat_list_idx < (size_t)msg->n_stec_sat_list; msgstec_sat_list_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstec_sat_listmsgstec_sat_list_idxsv_idsatId = msg->stec_sat_list[msgstec_sat_list_idx].sv_id.satId;
    memcpy(buf + offset, &msgstec_sat_listmsgstec_sat_list_idxsv_idsatId, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstec_sat_listmsgstec_sat_list_idxsv_idconstellation =
        msg->stec_sat_list[msgstec_sat_list_idx].sv_id.constellation;
    memcpy(buf + offset, &msgstec_sat_listmsgstec_sat_list_idxsv_idconstellation, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstec_sat_listmsgstec_sat_list_idxstec_quality_indicator =
        msg->stec_sat_list[msgstec_sat_list_idx].stec_quality_indicator;
    memcpy(buf + offset, &msgstec_sat_listmsgstec_sat_list_idxstec_quality_indicator, 1);
    // NOLINTNEXTLINE
    offset += 1;
    for (size_t msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx = 0;
         msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx < 4;
         msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx++)
    {

      if (offset + 2 > len)
      {
        return false;
      }
      u16 msgstec_sat_listmsgstec_sat_list_idxstec_coeffmsgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx =
          htole16(*(const u16 *)&msg->stec_sat_list[msgstec_sat_list_idx]
                       .stec_coeff[msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx]);
      memcpy(buf + offset,
             &msgstec_sat_listmsgstec_sat_list_idxstec_coeffmsgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx,
             2);
      // NOLINTNEXTLINE
      offset += 2;
    }
  }
  return true;
}

static inline bool
sbp_unpack_sbp_msg_ssr_stec_correction_t(const u8 *buf, size_t len, sbp_msg_ssr_stec_correction_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->header.tile_set_id, buf + offset, 2);
  msg->header.tile_set_id = le16toh(msg->header.tile_set_id);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->header.tile_id, buf + offset, 2);
  msg->header.tile_id = le16toh(msg->header.tile_id);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->header.time.tow, buf + offset, 4);
  msg->header.time.tow = le32toh(msg->header.time.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->header.time.wn, buf + offset, 2);
  msg->header.time.wn = le16toh(msg->header.time.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->header.num_msgs, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->header.seq_num, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->header.update_interval, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->header.iod_atmo, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  msg->n_stec_sat_list = (u8)((len - offset) / 11);

  for (size_t msgstec_sat_list_idx = 0; msgstec_sat_list_idx < msg->n_stec_sat_list; msgstec_sat_list_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->stec_sat_list[msgstec_sat_list_idx].sv_id.satId, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->stec_sat_list[msgstec_sat_list_idx].sv_id.constellation, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->stec_sat_list[msgstec_sat_list_idx].stec_quality_indicator, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
    for (size_t msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx = 0;
         msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx < 4;
         msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx++)
    {

      if (offset + 2 > len)
      {
        return false;
      }
      memcpy(&msg->stec_sat_list[msgstec_sat_list_idx].stec_coeff[msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx],
             buf + offset,
             2);
      u16 msgstec_sat_listmsgstec_sat_list_idxstec_coeffmsgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx =
          *(const u16 *)&msg->stec_sat_list[msgstec_sat_list_idx]
               .stec_coeff[msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx];
      msgstec_sat_listmsgstec_sat_list_idxstec_coeffmsgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx =
          le16toh(msgstec_sat_listmsgstec_sat_list_idxstec_coeffmsgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx);
      msg->stec_sat_list[msgstec_sat_list_idx].stec_coeff[msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx] = *(
          const s16 *)&msgstec_sat_listmsgstec_sat_list_idxstec_coeffmsgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx;
      // NOLINTNEXTLINE
      offset += 2;
    }
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ssr_gridded_correction_t(const sbp_msg_ssr_gridded_correction_t *msg)
{
  (void)msg;
  return 0 +
         (0 + sizeof(msg->header.tile_set_id) + sizeof(msg->header.tile_id) +
          (0 + sizeof(msg->header.time.tow) + sizeof(msg->header.time.wn)) + sizeof(msg->header.num_msgs) +
          sizeof(msg->header.seq_num) + sizeof(msg->header.update_interval) + sizeof(msg->header.iod_atmo) +
          sizeof(msg->header.tropo_quality_indicator)) +
         (0 + sizeof(msg->element.index) +
          (0 + sizeof(msg->element.tropo_delay_correction.hydro) + sizeof(msg->element.tropo_delay_correction.wet) +
           sizeof(msg->element.tropo_delay_correction.stddev)) +
          (msg->element.n_stec_residuals *
           (0 +
            (0 + sizeof(msg->element.stec_residuals[0].sv_id.satId) +
             sizeof(msg->element.stec_residuals[0].sv_id.constellation)) +
            sizeof(msg->element.stec_residuals[0].residual) + sizeof(msg->element.stec_residuals[0].stddev))));
}

static inline bool
sbp_pack_sbp_msg_ssr_gridded_correction_t(u8 *buf, size_t len, const sbp_msg_ssr_gridded_correction_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ssr_gridded_correction_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgheadertile_set_id = htole16(msg->header.tile_set_id);
  memcpy(buf + offset, &msgheadertile_set_id, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgheadertile_id = htole16(msg->header.tile_id);
  memcpy(buf + offset, &msgheadertile_id, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgheadertimetow = htole32(msg->header.time.tow);
  memcpy(buf + offset, &msgheadertimetow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgheadertimewn = htole16(msg->header.time.wn);
  memcpy(buf + offset, &msgheadertimewn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgheadernum_msgs = htole16(msg->header.num_msgs);
  memcpy(buf + offset, &msgheadernum_msgs, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgheaderseq_num = htole16(msg->header.seq_num);
  memcpy(buf + offset, &msgheaderseq_num, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgheaderupdate_interval = msg->header.update_interval;
  memcpy(buf + offset, &msgheaderupdate_interval, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgheaderiod_atmo = msg->header.iod_atmo;
  memcpy(buf + offset, &msgheaderiod_atmo, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgheadertropo_quality_indicator = msg->header.tropo_quality_indicator;
  memcpy(buf + offset, &msgheadertropo_quality_indicator, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgelementindex = htole16(msg->element.index);
  memcpy(buf + offset, &msgelementindex, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgelementtropo_delay_correctionhydro = htole16(*(const u16 *)&msg->element.tropo_delay_correction.hydro);
  memcpy(buf + offset, &msgelementtropo_delay_correctionhydro, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  s8 msgelementtropo_delay_correctionwet = msg->element.tropo_delay_correction.wet;
  memcpy(buf + offset, &msgelementtropo_delay_correctionwet, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgelementtropo_delay_correctionstddev = msg->element.tropo_delay_correction.stddev;
  memcpy(buf + offset, &msgelementtropo_delay_correctionstddev, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgelementstec_residuals_idx = 0; msgelementstec_residuals_idx < (size_t)msg->element.n_stec_residuals;
       msgelementstec_residuals_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgelementstec_residualsmsgelementstec_residuals_idxsv_idsatId =
        msg->element.stec_residuals[msgelementstec_residuals_idx].sv_id.satId;
    memcpy(buf + offset, &msgelementstec_residualsmsgelementstec_residuals_idxsv_idsatId, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgelementstec_residualsmsgelementstec_residuals_idxsv_idconstellation =
        msg->element.stec_residuals[msgelementstec_residuals_idx].sv_id.constellation;
    memcpy(buf + offset, &msgelementstec_residualsmsgelementstec_residuals_idxsv_idconstellation, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 2 > len)
    {
      return false;
    }
    u16 msgelementstec_residualsmsgelementstec_residuals_idxresidual =
        htole16(*(const u16 *)&msg->element.stec_residuals[msgelementstec_residuals_idx].residual);
    memcpy(buf + offset, &msgelementstec_residualsmsgelementstec_residuals_idxresidual, 2);
    // NOLINTNEXTLINE
    offset += 2;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgelementstec_residualsmsgelementstec_residuals_idxstddev =
        msg->element.stec_residuals[msgelementstec_residuals_idx].stddev;
    memcpy(buf + offset, &msgelementstec_residualsmsgelementstec_residuals_idxstddev, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool
sbp_unpack_sbp_msg_ssr_gridded_correction_t(const u8 *buf, size_t len, sbp_msg_ssr_gridded_correction_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->header.tile_set_id, buf + offset, 2);
  msg->header.tile_set_id = le16toh(msg->header.tile_set_id);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->header.tile_id, buf + offset, 2);
  msg->header.tile_id = le16toh(msg->header.tile_id);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->header.time.tow, buf + offset, 4);
  msg->header.time.tow = le32toh(msg->header.time.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->header.time.wn, buf + offset, 2);
  msg->header.time.wn = le16toh(msg->header.time.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->header.num_msgs, buf + offset, 2);
  msg->header.num_msgs = le16toh(msg->header.num_msgs);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->header.seq_num, buf + offset, 2);
  msg->header.seq_num = le16toh(msg->header.seq_num);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->header.update_interval, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->header.iod_atmo, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->header.tropo_quality_indicator, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->element.index, buf + offset, 2);
  msg->element.index = le16toh(msg->element.index);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->element.tropo_delay_correction.hydro, buf + offset, 2);
  u16 msgelementtropo_delay_correctionhydro = *(const u16 *)&msg->element.tropo_delay_correction.hydro;
  msgelementtropo_delay_correctionhydro = le16toh(msgelementtropo_delay_correctionhydro);
  msg->element.tropo_delay_correction.hydro = *(const s16 *)&msgelementtropo_delay_correctionhydro;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->element.tropo_delay_correction.wet, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->element.tropo_delay_correction.stddev, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  msg->element.n_stec_residuals = (u8)((len - offset) / 5);

  for (size_t msgelementstec_residuals_idx = 0; msgelementstec_residuals_idx < msg->element.n_stec_residuals;
       msgelementstec_residuals_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->element.stec_residuals[msgelementstec_residuals_idx].sv_id.satId, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->element.stec_residuals[msgelementstec_residuals_idx].sv_id.constellation, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 2 > len)
    {
      return false;
    }
    memcpy(&msg->element.stec_residuals[msgelementstec_residuals_idx].residual, buf + offset, 2);
    u16 msgelementstec_residualsmsgelementstec_residuals_idxresidual =
        *(const u16 *)&msg->element.stec_residuals[msgelementstec_residuals_idx].residual;
    msgelementstec_residualsmsgelementstec_residuals_idxresidual =
        le16toh(msgelementstec_residualsmsgelementstec_residuals_idxresidual);
    msg->element.stec_residuals[msgelementstec_residuals_idx].residual =
        *(const s16 *)&msgelementstec_residualsmsgelementstec_residuals_idxresidual;
    // NOLINTNEXTLINE
    offset += 2;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->element.stec_residuals[msgelementstec_residuals_idx].stddev, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ssr_tile_definition_t(const sbp_msg_ssr_tile_definition_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tile_set_id) + sizeof(msg->tile_id) + sizeof(msg->corner_nw_lat) + sizeof(msg->corner_nw_lon) +
         sizeof(msg->spacing_lat) + sizeof(msg->spacing_lon) + sizeof(msg->rows) + sizeof(msg->cols) +
         sizeof(msg->bitmask);
}

static inline bool sbp_pack_sbp_msg_ssr_tile_definition_t(u8 *buf, size_t len, const sbp_msg_ssr_tile_definition_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ssr_tile_definition_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtile_set_id = htole16(msg->tile_set_id);
  memcpy(buf + offset, &msgtile_set_id, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtile_id = htole16(msg->tile_id);
  memcpy(buf + offset, &msgtile_id, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcorner_nw_lat = htole16(*(const u16 *)&msg->corner_nw_lat);
  memcpy(buf + offset, &msgcorner_nw_lat, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcorner_nw_lon = htole16(*(const u16 *)&msg->corner_nw_lon);
  memcpy(buf + offset, &msgcorner_nw_lon, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgspacing_lat = htole16(msg->spacing_lat);
  memcpy(buf + offset, &msgspacing_lat, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgspacing_lon = htole16(msg->spacing_lon);
  memcpy(buf + offset, &msgspacing_lon, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgrows = htole16(msg->rows);
  memcpy(buf + offset, &msgrows, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcols = htole16(msg->cols);
  memcpy(buf + offset, &msgcols, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  u64 msgbitmask = htole64(msg->bitmask);
  memcpy(buf + offset, &msgbitmask, 8);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline bool
sbp_unpack_sbp_msg_ssr_tile_definition_t(const u8 *buf, size_t len, sbp_msg_ssr_tile_definition_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->tile_set_id, buf + offset, 2);
  msg->tile_set_id = le16toh(msg->tile_set_id);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->tile_id, buf + offset, 2);
  msg->tile_id = le16toh(msg->tile_id);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->corner_nw_lat, buf + offset, 2);
  u16 msgcorner_nw_lat = *(const u16 *)&msg->corner_nw_lat;
  msgcorner_nw_lat = le16toh(msgcorner_nw_lat);
  msg->corner_nw_lat = *(const s16 *)&msgcorner_nw_lat;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->corner_nw_lon, buf + offset, 2);
  u16 msgcorner_nw_lon = *(const u16 *)&msg->corner_nw_lon;
  msgcorner_nw_lon = le16toh(msgcorner_nw_lon);
  msg->corner_nw_lon = *(const s16 *)&msgcorner_nw_lon;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->spacing_lat, buf + offset, 2);
  msg->spacing_lat = le16toh(msg->spacing_lat);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->spacing_lon, buf + offset, 2);
  msg->spacing_lon = le16toh(msg->spacing_lon);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->rows, buf + offset, 2);
  msg->rows = le16toh(msg->rows);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->cols, buf + offset, 2);
  msg->cols = le16toh(msg->cols);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->bitmask, buf + offset, 8);
  msg->bitmask = le64toh(msg->bitmask);
  // NOLINTNEXTLINE
  offset += 8;
  return true;
}

static inline size_t sbp_packed_size_sbp_satellite_apc_t(const sbp_satellite_apc_t *msg)
{
  (void)msg;
  return 0 + (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code)) + sizeof(msg->sat_info) + sizeof(msg->svn) +
         (3 * sizeof(msg->pco[0])) + (21 * sizeof(msg->pcv[0]));
}

static inline bool sbp_pack_sbp_satellite_apc_t(u8 *buf, size_t len, const sbp_satellite_apc_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_satellite_apc_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidsat = msg->sid.sat;
  memcpy(buf + offset, &msgsidsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsat_info = msg->sat_info;
  memcpy(buf + offset, &msgsat_info, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgsvn = htole16(msg->svn);
  memcpy(buf + offset, &msgsvn, 2);
  // NOLINTNEXTLINE
  offset += 2;
  for (size_t msgpco_idx = 0; msgpco_idx < 3; msgpco_idx++)
  {

    if (offset + 2 > len)
    {
      return false;
    }
    u16 msgpcomsgpco_idx = htole16(*(const u16 *)&msg->pco[msgpco_idx]);
    memcpy(buf + offset, &msgpcomsgpco_idx, 2);
    // NOLINTNEXTLINE
    offset += 2;
  }
  for (size_t msgpcv_idx = 0; msgpcv_idx < 21; msgpcv_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    s8 msgpcvmsgpcv_idx = msg->pcv[msgpcv_idx];
    memcpy(buf + offset, &msgpcvmsgpcv_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_satellite_apc_t(const u8 *buf, size_t len, sbp_satellite_apc_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sat_info, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->svn, buf + offset, 2);
  msg->svn = le16toh(msg->svn);
  // NOLINTNEXTLINE
  offset += 2;
  for (size_t msgpco_idx = 0; msgpco_idx < 3; msgpco_idx++)
  {

    if (offset + 2 > len)
    {
      return false;
    }
    memcpy(&msg->pco[msgpco_idx], buf + offset, 2);
    u16 msgpcomsgpco_idx = *(const u16 *)&msg->pco[msgpco_idx];
    msgpcomsgpco_idx = le16toh(msgpcomsgpco_idx);
    msg->pco[msgpco_idx] = *(const s16 *)&msgpcomsgpco_idx;
    // NOLINTNEXTLINE
    offset += 2;
  }
  for (size_t msgpcv_idx = 0; msgpcv_idx < 21; msgpcv_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->pcv[msgpcv_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ssr_satellite_apc_t(const sbp_msg_ssr_satellite_apc_t *msg)
{
  (void)msg;
  return 0 + (msg->n_apc *
              (0 + (0 + sizeof(msg->apc[0].sid.sat) + sizeof(msg->apc[0].sid.code)) + sizeof(msg->apc[0].sat_info) +
               sizeof(msg->apc[0].svn) + (3 * sizeof(msg->apc[0].pco[0])) + (21 * sizeof(msg->apc[0].pcv[0]))));
}

static inline bool sbp_pack_sbp_msg_ssr_satellite_apc_t(u8 *buf, size_t len, const sbp_msg_ssr_satellite_apc_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ssr_satellite_apc_t(msg) > len)
  {
    return false;
  }

  for (size_t msgapc_idx = 0; msgapc_idx < (size_t)msg->n_apc; msgapc_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgapcmsgapc_idxsidsat = msg->apc[msgapc_idx].sid.sat;
    memcpy(buf + offset, &msgapcmsgapc_idxsidsat, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgapcmsgapc_idxsidcode = msg->apc[msgapc_idx].sid.code;
    memcpy(buf + offset, &msgapcmsgapc_idxsidcode, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgapcmsgapc_idxsat_info = msg->apc[msgapc_idx].sat_info;
    memcpy(buf + offset, &msgapcmsgapc_idxsat_info, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 2 > len)
    {
      return false;
    }
    u16 msgapcmsgapc_idxsvn = htole16(msg->apc[msgapc_idx].svn);
    memcpy(buf + offset, &msgapcmsgapc_idxsvn, 2);
    // NOLINTNEXTLINE
    offset += 2;
    for (size_t msgapcmsgapc_idxpco_idx = 0; msgapcmsgapc_idxpco_idx < 3; msgapcmsgapc_idxpco_idx++)
    {

      if (offset + 2 > len)
      {
        return false;
      }
      u16 msgapcmsgapc_idxpcomsgapcmsgapc_idxpco_idx =
          htole16(*(const u16 *)&msg->apc[msgapc_idx].pco[msgapcmsgapc_idxpco_idx]);
      memcpy(buf + offset, &msgapcmsgapc_idxpcomsgapcmsgapc_idxpco_idx, 2);
      // NOLINTNEXTLINE
      offset += 2;
    }
    for (size_t msgapcmsgapc_idxpcv_idx = 0; msgapcmsgapc_idxpcv_idx < 21; msgapcmsgapc_idxpcv_idx++)
    {

      if (offset + 1 > len)
      {
        return false;
      }
      s8 msgapcmsgapc_idxpcvmsgapcmsgapc_idxpcv_idx = msg->apc[msgapc_idx].pcv[msgapcmsgapc_idxpcv_idx];
      memcpy(buf + offset, &msgapcmsgapc_idxpcvmsgapcmsgapc_idxpcv_idx, 1);
      // NOLINTNEXTLINE
      offset += 1;
    }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_satellite_apc_t(const u8 *buf, size_t len, sbp_msg_ssr_satellite_apc_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  msg->n_apc = (u8)((len - offset) / 32);

  for (size_t msgapc_idx = 0; msgapc_idx < msg->n_apc; msgapc_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->apc[msgapc_idx].sid.sat, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->apc[msgapc_idx].sid.code, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->apc[msgapc_idx].sat_info, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 2 > len)
    {
      return false;
    }
    memcpy(&msg->apc[msgapc_idx].svn, buf + offset, 2);
    msg->apc[msgapc_idx].svn = le16toh(msg->apc[msgapc_idx].svn);
    // NOLINTNEXTLINE
    offset += 2;
    for (size_t msgapcmsgapc_idxpco_idx = 0; msgapcmsgapc_idxpco_idx < 3; msgapcmsgapc_idxpco_idx++)
    {

      if (offset + 2 > len)
      {
        return false;
      }
      memcpy(&msg->apc[msgapc_idx].pco[msgapcmsgapc_idxpco_idx], buf + offset, 2);
      u16 msgapcmsgapc_idxpcomsgapcmsgapc_idxpco_idx = *(const u16 *)&msg->apc[msgapc_idx].pco[msgapcmsgapc_idxpco_idx];
      msgapcmsgapc_idxpcomsgapcmsgapc_idxpco_idx = le16toh(msgapcmsgapc_idxpcomsgapcmsgapc_idxpco_idx);
      msg->apc[msgapc_idx].pco[msgapcmsgapc_idxpco_idx] = *(const s16 *)&msgapcmsgapc_idxpcomsgapcmsgapc_idxpco_idx;
      // NOLINTNEXTLINE
      offset += 2;
    }
    for (size_t msgapcmsgapc_idxpcv_idx = 0; msgapcmsgapc_idxpcv_idx < 21; msgapcmsgapc_idxpcv_idx++)
    {

      if (offset + 1 > len)
      {
        return false;
      }
      memcpy(&msg->apc[msgapc_idx].pcv[msgapcmsgapc_idxpcv_idx], buf + offset, 1);
      // NOLINTNEXTLINE
      offset += 1;
    }
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ssr_orbit_clock_dep_a_t(const sbp_msg_ssr_orbit_clock_dep_a_t *msg)
{
  (void)msg;
  return 0 + (0 + sizeof(msg->time.tow) + sizeof(msg->time.wn)) + (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code)) +
         sizeof(msg->update_interval) + sizeof(msg->iod_ssr) + sizeof(msg->iod) + sizeof(msg->radial) +
         sizeof(msg->along) + sizeof(msg->cross) + sizeof(msg->dot_radial) + sizeof(msg->dot_along) +
         sizeof(msg->dot_cross) + sizeof(msg->c0) + sizeof(msg->c1) + sizeof(msg->c2);
}

static inline bool
sbp_pack_sbp_msg_ssr_orbit_clock_dep_a_t(u8 *buf, size_t len, const sbp_msg_ssr_orbit_clock_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ssr_orbit_clock_dep_a_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtimetow = htole32(msg->time.tow);
  memcpy(buf + offset, &msgtimetow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtimewn = htole16(msg->time.wn);
  memcpy(buf + offset, &msgtimewn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidsat = msg->sid.sat;
  memcpy(buf + offset, &msgsidsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgupdate_interval = msg->update_interval;
  memcpy(buf + offset, &msgupdate_interval, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgiod_ssr = msg->iod_ssr;
  memcpy(buf + offset, &msgiod_ssr, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgiod = msg->iod;
  memcpy(buf + offset, &msgiod, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgradial = htole32(*(const u32 *)&msg->radial);
  memcpy(buf + offset, &msgradial, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgalong = htole32(*(const u32 *)&msg->along);
  memcpy(buf + offset, &msgalong, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcross = htole32(*(const u32 *)&msg->cross);
  memcpy(buf + offset, &msgcross, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgdot_radial = htole32(*(const u32 *)&msg->dot_radial);
  memcpy(buf + offset, &msgdot_radial, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgdot_along = htole32(*(const u32 *)&msg->dot_along);
  memcpy(buf + offset, &msgdot_along, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgdot_cross = htole32(*(const u32 *)&msg->dot_cross);
  memcpy(buf + offset, &msgdot_cross, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgc0 = htole32(*(const u32 *)&msg->c0);
  memcpy(buf + offset, &msgc0, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgc1 = htole32(*(const u32 *)&msg->c1);
  memcpy(buf + offset, &msgc1, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgc2 = htole32(*(const u32 *)&msg->c2);
  memcpy(buf + offset, &msgc2, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool
sbp_unpack_sbp_msg_ssr_orbit_clock_dep_a_t(const u8 *buf, size_t len, sbp_msg_ssr_orbit_clock_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->time.tow, buf + offset, 4);
  msg->time.tow = le32toh(msg->time.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->time.wn, buf + offset, 2);
  msg->time.wn = le16toh(msg->time.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->update_interval, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->iod_ssr, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->iod, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->radial, buf + offset, 4);
  u32 msgradial = *(const u32 *)&msg->radial;
  msgradial = le32toh(msgradial);
  msg->radial = *(const s32 *)&msgradial;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->along, buf + offset, 4);
  u32 msgalong = *(const u32 *)&msg->along;
  msgalong = le32toh(msgalong);
  msg->along = *(const s32 *)&msgalong;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cross, buf + offset, 4);
  u32 msgcross = *(const u32 *)&msg->cross;
  msgcross = le32toh(msgcross);
  msg->cross = *(const s32 *)&msgcross;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->dot_radial, buf + offset, 4);
  u32 msgdot_radial = *(const u32 *)&msg->dot_radial;
  msgdot_radial = le32toh(msgdot_radial);
  msg->dot_radial = *(const s32 *)&msgdot_radial;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->dot_along, buf + offset, 4);
  u32 msgdot_along = *(const u32 *)&msg->dot_along;
  msgdot_along = le32toh(msgdot_along);
  msg->dot_along = *(const s32 *)&msgdot_along;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->dot_cross, buf + offset, 4);
  u32 msgdot_cross = *(const u32 *)&msg->dot_cross;
  msgdot_cross = le32toh(msgdot_cross);
  msg->dot_cross = *(const s32 *)&msgdot_cross;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c0, buf + offset, 4);
  u32 msgc0 = *(const u32 *)&msg->c0;
  msgc0 = le32toh(msgc0);
  msg->c0 = *(const s32 *)&msgc0;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c1, buf + offset, 4);
  u32 msgc1 = *(const u32 *)&msg->c1;
  msgc1 = le32toh(msgc1);
  msg->c1 = *(const s32 *)&msgc1;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->c2, buf + offset, 4);
  u32 msgc2 = *(const u32 *)&msg->c2;
  msgc2 = le32toh(msgc2);
  msg->c2 = *(const s32 *)&msgc2;
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_stec_header_dep_a_t(const sbp_stec_header_dep_a_t *msg)
{
  (void)msg;
  return 0 + (0 + sizeof(msg->time.tow) + sizeof(msg->time.wn)) + sizeof(msg->num_msgs) + sizeof(msg->seq_num) +
         sizeof(msg->update_interval) + sizeof(msg->iod_atmo);
}

static inline bool sbp_pack_sbp_stec_header_dep_a_t(u8 *buf, size_t len, const sbp_stec_header_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_stec_header_dep_a_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtimetow = htole32(msg->time.tow);
  memcpy(buf + offset, &msgtimetow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtimewn = htole16(msg->time.wn);
  memcpy(buf + offset, &msgtimewn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgnum_msgs = msg->num_msgs;
  memcpy(buf + offset, &msgnum_msgs, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgseq_num = msg->seq_num;
  memcpy(buf + offset, &msgseq_num, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgupdate_interval = msg->update_interval;
  memcpy(buf + offset, &msgupdate_interval, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgiod_atmo = msg->iod_atmo;
  memcpy(buf + offset, &msgiod_atmo, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_stec_header_dep_a_t(const u8 *buf, size_t len, sbp_stec_header_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->time.tow, buf + offset, 4);
  msg->time.tow = le32toh(msg->time.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->time.wn, buf + offset, 2);
  msg->time.wn = le16toh(msg->time.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->num_msgs, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->seq_num, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->update_interval, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->iod_atmo, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t
sbp_packed_size_sbp_gridded_correction_header_dep_a_t(const sbp_gridded_correction_header_dep_a_t *msg)
{
  (void)msg;
  return 0 + (0 + sizeof(msg->time.tow) + sizeof(msg->time.wn)) + sizeof(msg->num_msgs) + sizeof(msg->seq_num) +
         sizeof(msg->update_interval) + sizeof(msg->iod_atmo) + sizeof(msg->tropo_quality_indicator);
}

static inline bool
sbp_pack_sbp_gridded_correction_header_dep_a_t(u8 *buf, size_t len, const sbp_gridded_correction_header_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_gridded_correction_header_dep_a_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtimetow = htole32(msg->time.tow);
  memcpy(buf + offset, &msgtimetow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtimewn = htole16(msg->time.wn);
  memcpy(buf + offset, &msgtimewn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgnum_msgs = htole16(msg->num_msgs);
  memcpy(buf + offset, &msgnum_msgs, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgseq_num = htole16(msg->seq_num);
  memcpy(buf + offset, &msgseq_num, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgupdate_interval = msg->update_interval;
  memcpy(buf + offset, &msgupdate_interval, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgiod_atmo = msg->iod_atmo;
  memcpy(buf + offset, &msgiod_atmo, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgtropo_quality_indicator = msg->tropo_quality_indicator;
  memcpy(buf + offset, &msgtropo_quality_indicator, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool
sbp_unpack_sbp_gridded_correction_header_dep_a_t(const u8 *buf, size_t len, sbp_gridded_correction_header_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->time.tow, buf + offset, 4);
  msg->time.tow = le32toh(msg->time.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->time.wn, buf + offset, 2);
  msg->time.wn = le16toh(msg->time.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->num_msgs, buf + offset, 2);
  msg->num_msgs = le16toh(msg->num_msgs);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->seq_num, buf + offset, 2);
  msg->seq_num = le16toh(msg->seq_num);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->update_interval, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->iod_atmo, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->tropo_quality_indicator, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_grid_definition_header_dep_a_t(const sbp_grid_definition_header_dep_a_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->region_size_inverse) + sizeof(msg->area_width) + sizeof(msg->lat_nw_corner_enc) +
         sizeof(msg->lon_nw_corner_enc) + sizeof(msg->num_msgs) + sizeof(msg->seq_num);
}

static inline bool
sbp_pack_sbp_grid_definition_header_dep_a_t(u8 *buf, size_t len, const sbp_grid_definition_header_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_grid_definition_header_dep_a_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgregion_size_inverse = msg->region_size_inverse;
  memcpy(buf + offset, &msgregion_size_inverse, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgarea_width = htole16(msg->area_width);
  memcpy(buf + offset, &msgarea_width, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msglat_nw_corner_enc = htole16(msg->lat_nw_corner_enc);
  memcpy(buf + offset, &msglat_nw_corner_enc, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msglon_nw_corner_enc = htole16(msg->lon_nw_corner_enc);
  memcpy(buf + offset, &msglon_nw_corner_enc, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgnum_msgs = msg->num_msgs;
  memcpy(buf + offset, &msgnum_msgs, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgseq_num = msg->seq_num;
  memcpy(buf + offset, &msgseq_num, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool
sbp_unpack_sbp_grid_definition_header_dep_a_t(const u8 *buf, size_t len, sbp_grid_definition_header_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->region_size_inverse, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->area_width, buf + offset, 2);
  msg->area_width = le16toh(msg->area_width);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->lat_nw_corner_enc, buf + offset, 2);
  msg->lat_nw_corner_enc = le16toh(msg->lat_nw_corner_enc);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->lon_nw_corner_enc, buf + offset, 2);
  msg->lon_nw_corner_enc = le16toh(msg->lon_nw_corner_enc);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->num_msgs, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->seq_num, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ssr_stec_correction_dep_a_t(const sbp_msg_ssr_stec_correction_dep_a_t *msg)
{
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->header.time.tow) + sizeof(msg->header.time.wn)) + sizeof(msg->header.num_msgs) +
          sizeof(msg->header.seq_num) + sizeof(msg->header.update_interval) + sizeof(msg->header.iod_atmo)) +
         (msg->n_stec_sat_list *
          (0 + (0 + sizeof(msg->stec_sat_list[0].sv_id.satId) + sizeof(msg->stec_sat_list[0].sv_id.constellation)) +
           sizeof(msg->stec_sat_list[0].stec_quality_indicator) + (4 * sizeof(msg->stec_sat_list[0].stec_coeff[0]))));
}

static inline bool
sbp_pack_sbp_msg_ssr_stec_correction_dep_a_t(u8 *buf, size_t len, const sbp_msg_ssr_stec_correction_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ssr_stec_correction_dep_a_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgheadertimetow = htole32(msg->header.time.tow);
  memcpy(buf + offset, &msgheadertimetow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgheadertimewn = htole16(msg->header.time.wn);
  memcpy(buf + offset, &msgheadertimewn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgheadernum_msgs = msg->header.num_msgs;
  memcpy(buf + offset, &msgheadernum_msgs, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgheaderseq_num = msg->header.seq_num;
  memcpy(buf + offset, &msgheaderseq_num, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgheaderupdate_interval = msg->header.update_interval;
  memcpy(buf + offset, &msgheaderupdate_interval, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgheaderiod_atmo = msg->header.iod_atmo;
  memcpy(buf + offset, &msgheaderiod_atmo, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgstec_sat_list_idx = 0; msgstec_sat_list_idx < (size_t)msg->n_stec_sat_list; msgstec_sat_list_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstec_sat_listmsgstec_sat_list_idxsv_idsatId = msg->stec_sat_list[msgstec_sat_list_idx].sv_id.satId;
    memcpy(buf + offset, &msgstec_sat_listmsgstec_sat_list_idxsv_idsatId, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstec_sat_listmsgstec_sat_list_idxsv_idconstellation =
        msg->stec_sat_list[msgstec_sat_list_idx].sv_id.constellation;
    memcpy(buf + offset, &msgstec_sat_listmsgstec_sat_list_idxsv_idconstellation, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstec_sat_listmsgstec_sat_list_idxstec_quality_indicator =
        msg->stec_sat_list[msgstec_sat_list_idx].stec_quality_indicator;
    memcpy(buf + offset, &msgstec_sat_listmsgstec_sat_list_idxstec_quality_indicator, 1);
    // NOLINTNEXTLINE
    offset += 1;
    for (size_t msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx = 0;
         msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx < 4;
         msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx++)
    {

      if (offset + 2 > len)
      {
        return false;
      }
      u16 msgstec_sat_listmsgstec_sat_list_idxstec_coeffmsgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx =
          htole16(*(const u16 *)&msg->stec_sat_list[msgstec_sat_list_idx]
                       .stec_coeff[msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx]);
      memcpy(buf + offset,
             &msgstec_sat_listmsgstec_sat_list_idxstec_coeffmsgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx,
             2);
      // NOLINTNEXTLINE
      offset += 2;
    }
  }
  return true;
}

static inline bool
sbp_unpack_sbp_msg_ssr_stec_correction_dep_a_t(const u8 *buf, size_t len, sbp_msg_ssr_stec_correction_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->header.time.tow, buf + offset, 4);
  msg->header.time.tow = le32toh(msg->header.time.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->header.time.wn, buf + offset, 2);
  msg->header.time.wn = le16toh(msg->header.time.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->header.num_msgs, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->header.seq_num, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->header.update_interval, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->header.iod_atmo, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  msg->n_stec_sat_list = (u8)((len - offset) / 11);

  for (size_t msgstec_sat_list_idx = 0; msgstec_sat_list_idx < msg->n_stec_sat_list; msgstec_sat_list_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->stec_sat_list[msgstec_sat_list_idx].sv_id.satId, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->stec_sat_list[msgstec_sat_list_idx].sv_id.constellation, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->stec_sat_list[msgstec_sat_list_idx].stec_quality_indicator, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
    for (size_t msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx = 0;
         msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx < 4;
         msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx++)
    {

      if (offset + 2 > len)
      {
        return false;
      }
      memcpy(&msg->stec_sat_list[msgstec_sat_list_idx].stec_coeff[msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx],
             buf + offset,
             2);
      u16 msgstec_sat_listmsgstec_sat_list_idxstec_coeffmsgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx =
          *(const u16 *)&msg->stec_sat_list[msgstec_sat_list_idx]
               .stec_coeff[msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx];
      msgstec_sat_listmsgstec_sat_list_idxstec_coeffmsgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx =
          le16toh(msgstec_sat_listmsgstec_sat_list_idxstec_coeffmsgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx);
      msg->stec_sat_list[msgstec_sat_list_idx].stec_coeff[msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx] = *(
          const s16 *)&msgstec_sat_listmsgstec_sat_list_idxstec_coeffmsgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx;
      // NOLINTNEXTLINE
      offset += 2;
    }
  }
  return true;
}

static inline size_t
sbp_packed_size_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(const sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg)
{
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->header.time.tow) + sizeof(msg->header.time.wn)) + sizeof(msg->header.num_msgs) +
          sizeof(msg->header.seq_num) + sizeof(msg->header.update_interval) + sizeof(msg->header.iod_atmo) +
          sizeof(msg->header.tropo_quality_indicator)) +
         (0 + sizeof(msg->element.index) +
          (0 + sizeof(msg->element.tropo_delay_correction.hydro) + sizeof(msg->element.tropo_delay_correction.wet)) +
          (msg->element.n_stec_residuals * (0 +
                                            (0 + sizeof(msg->element.stec_residuals[0].sv_id.satId) +
                                             sizeof(msg->element.stec_residuals[0].sv_id.constellation)) +
                                            sizeof(msg->element.stec_residuals[0].residual))));
}

static inline bool
sbp_pack_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(u8 *buf,
                                                       size_t len,
                                                       const sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgheadertimetow = htole32(msg->header.time.tow);
  memcpy(buf + offset, &msgheadertimetow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgheadertimewn = htole16(msg->header.time.wn);
  memcpy(buf + offset, &msgheadertimewn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgheadernum_msgs = htole16(msg->header.num_msgs);
  memcpy(buf + offset, &msgheadernum_msgs, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgheaderseq_num = htole16(msg->header.seq_num);
  memcpy(buf + offset, &msgheaderseq_num, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgheaderupdate_interval = msg->header.update_interval;
  memcpy(buf + offset, &msgheaderupdate_interval, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgheaderiod_atmo = msg->header.iod_atmo;
  memcpy(buf + offset, &msgheaderiod_atmo, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgheadertropo_quality_indicator = msg->header.tropo_quality_indicator;
  memcpy(buf + offset, &msgheadertropo_quality_indicator, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgelementindex = htole16(msg->element.index);
  memcpy(buf + offset, &msgelementindex, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgelementtropo_delay_correctionhydro = htole16(*(const u16 *)&msg->element.tropo_delay_correction.hydro);
  memcpy(buf + offset, &msgelementtropo_delay_correctionhydro, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  s8 msgelementtropo_delay_correctionwet = msg->element.tropo_delay_correction.wet;
  memcpy(buf + offset, &msgelementtropo_delay_correctionwet, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgelementstec_residuals_idx = 0; msgelementstec_residuals_idx < (size_t)msg->element.n_stec_residuals;
       msgelementstec_residuals_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgelementstec_residualsmsgelementstec_residuals_idxsv_idsatId =
        msg->element.stec_residuals[msgelementstec_residuals_idx].sv_id.satId;
    memcpy(buf + offset, &msgelementstec_residualsmsgelementstec_residuals_idxsv_idsatId, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgelementstec_residualsmsgelementstec_residuals_idxsv_idconstellation =
        msg->element.stec_residuals[msgelementstec_residuals_idx].sv_id.constellation;
    memcpy(buf + offset, &msgelementstec_residualsmsgelementstec_residuals_idxsv_idconstellation, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 2 > len)
    {
      return false;
    }
    u16 msgelementstec_residualsmsgelementstec_residuals_idxresidual =
        htole16(*(const u16 *)&msg->element.stec_residuals[msgelementstec_residuals_idx].residual);
    memcpy(buf + offset, &msgelementstec_residualsmsgelementstec_residuals_idxresidual, 2);
    // NOLINTNEXTLINE
    offset += 2;
  }
  return true;
}

static inline bool
sbp_unpack_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(const u8 *buf,
                                                         size_t len,
                                                         sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->header.time.tow, buf + offset, 4);
  msg->header.time.tow = le32toh(msg->header.time.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->header.time.wn, buf + offset, 2);
  msg->header.time.wn = le16toh(msg->header.time.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->header.num_msgs, buf + offset, 2);
  msg->header.num_msgs = le16toh(msg->header.num_msgs);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->header.seq_num, buf + offset, 2);
  msg->header.seq_num = le16toh(msg->header.seq_num);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->header.update_interval, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->header.iod_atmo, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->header.tropo_quality_indicator, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->element.index, buf + offset, 2);
  msg->element.index = le16toh(msg->element.index);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->element.tropo_delay_correction.hydro, buf + offset, 2);
  u16 msgelementtropo_delay_correctionhydro = *(const u16 *)&msg->element.tropo_delay_correction.hydro;
  msgelementtropo_delay_correctionhydro = le16toh(msgelementtropo_delay_correctionhydro);
  msg->element.tropo_delay_correction.hydro = *(const s16 *)&msgelementtropo_delay_correctionhydro;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->element.tropo_delay_correction.wet, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  msg->element.n_stec_residuals = (u8)((len - offset) / 4);

  for (size_t msgelementstec_residuals_idx = 0; msgelementstec_residuals_idx < msg->element.n_stec_residuals;
       msgelementstec_residuals_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->element.stec_residuals[msgelementstec_residuals_idx].sv_id.satId, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->element.stec_residuals[msgelementstec_residuals_idx].sv_id.constellation, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 2 > len)
    {
      return false;
    }
    memcpy(&msg->element.stec_residuals[msgelementstec_residuals_idx].residual, buf + offset, 2);
    u16 msgelementstec_residualsmsgelementstec_residuals_idxresidual =
        *(const u16 *)&msg->element.stec_residuals[msgelementstec_residuals_idx].residual;
    msgelementstec_residualsmsgelementstec_residuals_idxresidual =
        le16toh(msgelementstec_residualsmsgelementstec_residuals_idxresidual);
    msg->element.stec_residuals[msgelementstec_residuals_idx].residual =
        *(const s16 *)&msgelementstec_residualsmsgelementstec_residuals_idxresidual;
    // NOLINTNEXTLINE
    offset += 2;
  }
  return true;
}

static inline size_t
sbp_packed_size_sbp_msg_ssr_gridded_correction_dep_a_t(const sbp_msg_ssr_gridded_correction_dep_a_t *msg)
{
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->header.time.tow) + sizeof(msg->header.time.wn)) + sizeof(msg->header.num_msgs) +
          sizeof(msg->header.seq_num) + sizeof(msg->header.update_interval) + sizeof(msg->header.iod_atmo) +
          sizeof(msg->header.tropo_quality_indicator)) +
         (0 + sizeof(msg->element.index) +
          (0 + sizeof(msg->element.tropo_delay_correction.hydro) + sizeof(msg->element.tropo_delay_correction.wet) +
           sizeof(msg->element.tropo_delay_correction.stddev)) +
          (msg->element.n_stec_residuals *
           (0 +
            (0 + sizeof(msg->element.stec_residuals[0].sv_id.satId) +
             sizeof(msg->element.stec_residuals[0].sv_id.constellation)) +
            sizeof(msg->element.stec_residuals[0].residual) + sizeof(msg->element.stec_residuals[0].stddev))));
}

static inline bool
sbp_pack_sbp_msg_ssr_gridded_correction_dep_a_t(u8 *buf, size_t len, const sbp_msg_ssr_gridded_correction_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ssr_gridded_correction_dep_a_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgheadertimetow = htole32(msg->header.time.tow);
  memcpy(buf + offset, &msgheadertimetow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgheadertimewn = htole16(msg->header.time.wn);
  memcpy(buf + offset, &msgheadertimewn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgheadernum_msgs = htole16(msg->header.num_msgs);
  memcpy(buf + offset, &msgheadernum_msgs, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgheaderseq_num = htole16(msg->header.seq_num);
  memcpy(buf + offset, &msgheaderseq_num, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgheaderupdate_interval = msg->header.update_interval;
  memcpy(buf + offset, &msgheaderupdate_interval, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgheaderiod_atmo = msg->header.iod_atmo;
  memcpy(buf + offset, &msgheaderiod_atmo, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgheadertropo_quality_indicator = msg->header.tropo_quality_indicator;
  memcpy(buf + offset, &msgheadertropo_quality_indicator, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgelementindex = htole16(msg->element.index);
  memcpy(buf + offset, &msgelementindex, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgelementtropo_delay_correctionhydro = htole16(*(const u16 *)&msg->element.tropo_delay_correction.hydro);
  memcpy(buf + offset, &msgelementtropo_delay_correctionhydro, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  s8 msgelementtropo_delay_correctionwet = msg->element.tropo_delay_correction.wet;
  memcpy(buf + offset, &msgelementtropo_delay_correctionwet, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgelementtropo_delay_correctionstddev = msg->element.tropo_delay_correction.stddev;
  memcpy(buf + offset, &msgelementtropo_delay_correctionstddev, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgelementstec_residuals_idx = 0; msgelementstec_residuals_idx < (size_t)msg->element.n_stec_residuals;
       msgelementstec_residuals_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgelementstec_residualsmsgelementstec_residuals_idxsv_idsatId =
        msg->element.stec_residuals[msgelementstec_residuals_idx].sv_id.satId;
    memcpy(buf + offset, &msgelementstec_residualsmsgelementstec_residuals_idxsv_idsatId, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgelementstec_residualsmsgelementstec_residuals_idxsv_idconstellation =
        msg->element.stec_residuals[msgelementstec_residuals_idx].sv_id.constellation;
    memcpy(buf + offset, &msgelementstec_residualsmsgelementstec_residuals_idxsv_idconstellation, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 2 > len)
    {
      return false;
    }
    u16 msgelementstec_residualsmsgelementstec_residuals_idxresidual =
        htole16(*(const u16 *)&msg->element.stec_residuals[msgelementstec_residuals_idx].residual);
    memcpy(buf + offset, &msgelementstec_residualsmsgelementstec_residuals_idxresidual, 2);
    // NOLINTNEXTLINE
    offset += 2;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgelementstec_residualsmsgelementstec_residuals_idxstddev =
        msg->element.stec_residuals[msgelementstec_residuals_idx].stddev;
    memcpy(buf + offset, &msgelementstec_residualsmsgelementstec_residuals_idxstddev, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_gridded_correction_dep_a_t(const u8 *buf,
                                                                     size_t len,
                                                                     sbp_msg_ssr_gridded_correction_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->header.time.tow, buf + offset, 4);
  msg->header.time.tow = le32toh(msg->header.time.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->header.time.wn, buf + offset, 2);
  msg->header.time.wn = le16toh(msg->header.time.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->header.num_msgs, buf + offset, 2);
  msg->header.num_msgs = le16toh(msg->header.num_msgs);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->header.seq_num, buf + offset, 2);
  msg->header.seq_num = le16toh(msg->header.seq_num);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->header.update_interval, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->header.iod_atmo, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->header.tropo_quality_indicator, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->element.index, buf + offset, 2);
  msg->element.index = le16toh(msg->element.index);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->element.tropo_delay_correction.hydro, buf + offset, 2);
  u16 msgelementtropo_delay_correctionhydro = *(const u16 *)&msg->element.tropo_delay_correction.hydro;
  msgelementtropo_delay_correctionhydro = le16toh(msgelementtropo_delay_correctionhydro);
  msg->element.tropo_delay_correction.hydro = *(const s16 *)&msgelementtropo_delay_correctionhydro;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->element.tropo_delay_correction.wet, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->element.tropo_delay_correction.stddev, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  msg->element.n_stec_residuals = (u8)((len - offset) / 5);

  for (size_t msgelementstec_residuals_idx = 0; msgelementstec_residuals_idx < msg->element.n_stec_residuals;
       msgelementstec_residuals_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->element.stec_residuals[msgelementstec_residuals_idx].sv_id.satId, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->element.stec_residuals[msgelementstec_residuals_idx].sv_id.constellation, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;

    if (offset + 2 > len)
    {
      return false;
    }
    memcpy(&msg->element.stec_residuals[msgelementstec_residuals_idx].residual, buf + offset, 2);
    u16 msgelementstec_residualsmsgelementstec_residuals_idxresidual =
        *(const u16 *)&msg->element.stec_residuals[msgelementstec_residuals_idx].residual;
    msgelementstec_residualsmsgelementstec_residuals_idxresidual =
        le16toh(msgelementstec_residualsmsgelementstec_residuals_idxresidual);
    msg->element.stec_residuals[msgelementstec_residuals_idx].residual =
        *(const s16 *)&msgelementstec_residualsmsgelementstec_residuals_idxresidual;
    // NOLINTNEXTLINE
    offset += 2;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->element.stec_residuals[msgelementstec_residuals_idx].stddev, buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_ssr_grid_definition_dep_a_t(const sbp_msg_ssr_grid_definition_dep_a_t *msg)
{
  (void)msg;
  return 0 +
         (0 + sizeof(msg->header.region_size_inverse) + sizeof(msg->header.area_width) +
          sizeof(msg->header.lat_nw_corner_enc) + sizeof(msg->header.lon_nw_corner_enc) + sizeof(msg->header.num_msgs) +
          sizeof(msg->header.seq_num)) +
         (msg->n_rle_list * sizeof(msg->rle_list[0]));
}

static inline bool
sbp_pack_sbp_msg_ssr_grid_definition_dep_a_t(u8 *buf, size_t len, const sbp_msg_ssr_grid_definition_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ssr_grid_definition_dep_a_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgheaderregion_size_inverse = msg->header.region_size_inverse;
  memcpy(buf + offset, &msgheaderregion_size_inverse, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgheaderarea_width = htole16(msg->header.area_width);
  memcpy(buf + offset, &msgheaderarea_width, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgheaderlat_nw_corner_enc = htole16(msg->header.lat_nw_corner_enc);
  memcpy(buf + offset, &msgheaderlat_nw_corner_enc, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgheaderlon_nw_corner_enc = htole16(msg->header.lon_nw_corner_enc);
  memcpy(buf + offset, &msgheaderlon_nw_corner_enc, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgheadernum_msgs = msg->header.num_msgs;
  memcpy(buf + offset, &msgheadernum_msgs, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgheaderseq_num = msg->header.seq_num;
  memcpy(buf + offset, &msgheaderseq_num, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgrle_list_idx = 0; msgrle_list_idx < (size_t)msg->n_rle_list; msgrle_list_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgrle_listmsgrle_list_idx = msg->rle_list[msgrle_list_idx];
    memcpy(buf + offset, &msgrle_listmsgrle_list_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool
sbp_unpack_sbp_msg_ssr_grid_definition_dep_a_t(const u8 *buf, size_t len, sbp_msg_ssr_grid_definition_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->header.region_size_inverse, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->header.area_width, buf + offset, 2);
  msg->header.area_width = le16toh(msg->header.area_width);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->header.lat_nw_corner_enc, buf + offset, 2);
  msg->header.lat_nw_corner_enc = le16toh(msg->header.lat_nw_corner_enc);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->header.lon_nw_corner_enc, buf + offset, 2);
  msg->header.lon_nw_corner_enc = le16toh(msg->header.lon_nw_corner_enc);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->header.num_msgs, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->header.seq_num, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  msg->n_rle_list = (u8)((len - offset) / 1);

  for (size_t msgrle_list_idx = 0; msgrle_list_idx < msg->n_rle_list; msgrle_list_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->rle_list[msgrle_list_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

#endif
