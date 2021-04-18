/*
 * Copyright (C) 2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

// This file was auto-generated. Do not modify by hand!

#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <gtest/gtest.h>
#include <libsbp/ssr.h>
#include <libsbp/cpp/ssr.h>
#include <libsbp/ssr.h>
#include <libsbp/cpp/ssr.h>
#include <libsbp/ssr.h>
#include <libsbp/cpp/ssr.h>
#include <libsbp/ssr.h>
#include <libsbp/cpp/ssr.h>
#include <libsbp/ssr.h>
#include <libsbp/cpp/ssr.h>
#include <libsbp/ssr.h>
#include <libsbp/cpp/ssr.h>
#include <libsbp/ssr.h>
#include <libsbp/cpp/ssr.h>
#include <libsbp/ssr.h>
#include <libsbp/cpp/ssr.h>
#include <libsbp/ssr.h>
#include <libsbp/cpp/ssr.h>
#include <libsbp/ssr.h>
#include <libsbp/cpp/ssr.h>
#include <libsbp/ssr.h>
#include <libsbp/cpp/ssr.h>
#include <libsbp/ssr.h>
#include <libsbp/cpp/ssr.h>
#include <libsbp/ssr.h>
#include <libsbp/cpp/ssr.h>
#include <libsbp/ssr.h>
#include <libsbp/cpp/ssr.h>
#include <libsbp/ssr.h>
#include <libsbp/cpp/ssr.h>
#include <libsbp/ssr.h>
#include <libsbp/cpp/ssr.h>
#include <libsbp/ssr.h>
#include <libsbp/cpp/ssr.h>
#include <libsbp/ssr.h>
#include <libsbp/cpp/ssr.h>
#include <libsbp/ssr.h>
#include <libsbp/cpp/ssr.h>
#include <libsbp/ssr.h>
#include <libsbp/cpp/ssr.h>
#include <libsbp/ssr.h>
#include <libsbp/cpp/ssr.h>
#include <libsbp/ssr.h>
#include <libsbp/cpp/ssr.h>
#include <libsbp/ssr.h>
#include <libsbp/cpp/ssr.h>
#include <libsbp/ssr.h>
#include <libsbp/cpp/ssr.h>
#include <libsbp/ssr.h>
#include <libsbp/cpp/ssr.h>


TEST(test_code_biases_content, default_construction) {
  sbp::CodeBiasesContent variable;
  (void) variable;
}

TEST(test_code_biases_content, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::CodeBiasesContent);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const code_biases_content_t *c_struct = reinterpret_cast<const code_biases_content_t*>(buffer);
  const sbp::CodeBiasesContent *cpp_struct = reinterpret_cast<const sbp::CodeBiasesContent*>(buffer);

//
//  EXPECT_EQ(c_struct->code, cpp_struct->code);
//
//  EXPECT_EQ(c_struct->value, cpp_struct->value);
//
}

TEST(test_phase_biases_content, default_construction) {
  sbp::PhaseBiasesContent variable;
  (void) variable;
}

TEST(test_phase_biases_content, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::PhaseBiasesContent);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const phase_biases_content_t *c_struct = reinterpret_cast<const phase_biases_content_t*>(buffer);
  const sbp::PhaseBiasesContent *cpp_struct = reinterpret_cast<const sbp::PhaseBiasesContent*>(buffer);

//
//  EXPECT_EQ(c_struct->code, cpp_struct->code);
//
//  EXPECT_EQ(c_struct->integer_indicator, cpp_struct->integer_indicator);
//
//  EXPECT_EQ(c_struct->widelane_integer_indicator, cpp_struct->widelane_integer_indicator);
//
//  EXPECT_EQ(c_struct->discontinuity_counter, cpp_struct->discontinuity_counter);
//
//  EXPECT_EQ(c_struct->bias, cpp_struct->bias);
//
}

TEST(test_s_t_e_c_header, default_construction) {
  sbp::STECHeader variable;
  (void) variable;
}

TEST(test_s_t_e_c_header, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::STECHeader);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const stec_header_t *c_struct = reinterpret_cast<const stec_header_t*>(buffer);
  const sbp::STECHeader *cpp_struct = reinterpret_cast<const sbp::STECHeader*>(buffer);

//
//  EXPECT_EQ(c_struct->tile_set_id, cpp_struct->tile_set_id);
//
//  EXPECT_EQ(c_struct->tile_id, cpp_struct->tile_id);
//
//  EXPECT_EQ(c_struct->time, cpp_struct->time);
//
//  EXPECT_EQ(c_struct->num_msgs, cpp_struct->num_msgs);
//
//  EXPECT_EQ(c_struct->seq_num, cpp_struct->seq_num);
//
//  EXPECT_EQ(c_struct->update_interval, cpp_struct->update_interval);
//
//  EXPECT_EQ(c_struct->iod_atmo, cpp_struct->iod_atmo);
//
}

TEST(test_gridded_correction_header, default_construction) {
  sbp::GriddedCorrectionHeader variable;
  (void) variable;
}

TEST(test_gridded_correction_header, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::GriddedCorrectionHeader);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const gridded_correction_header_t *c_struct = reinterpret_cast<const gridded_correction_header_t*>(buffer);
  const sbp::GriddedCorrectionHeader *cpp_struct = reinterpret_cast<const sbp::GriddedCorrectionHeader*>(buffer);

//
//  EXPECT_EQ(c_struct->tile_set_id, cpp_struct->tile_set_id);
//
//  EXPECT_EQ(c_struct->tile_id, cpp_struct->tile_id);
//
//  EXPECT_EQ(c_struct->time, cpp_struct->time);
//
//  EXPECT_EQ(c_struct->num_msgs, cpp_struct->num_msgs);
//
//  EXPECT_EQ(c_struct->seq_num, cpp_struct->seq_num);
//
//  EXPECT_EQ(c_struct->update_interval, cpp_struct->update_interval);
//
//  EXPECT_EQ(c_struct->iod_atmo, cpp_struct->iod_atmo);
//
//  EXPECT_EQ(c_struct->tropo_quality_indicator, cpp_struct->tropo_quality_indicator);
//
}

TEST(test_s_t_e_c_sat_element, default_construction) {
  sbp::STECSatElement variable;
  (void) variable;
}

TEST(test_s_t_e_c_sat_element, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::STECSatElement);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const stec_sat_element_t *c_struct = reinterpret_cast<const stec_sat_element_t*>(buffer);
  const sbp::STECSatElement *cpp_struct = reinterpret_cast<const sbp::STECSatElement*>(buffer);

//
//  EXPECT_EQ(c_struct->sv_id, cpp_struct->sv_id);
//
//  EXPECT_EQ(c_struct->stec_quality_indicator, cpp_struct->stec_quality_indicator);
//
//  EXPECT_EQ(c_struct->stec_coeff, cpp_struct->stec_coeff);
//
}

TEST(test_tropospheric_delay_correction_no_std, default_construction) {
  sbp::TroposphericDelayCorrectionNoStd variable;
  (void) variable;
}

TEST(test_tropospheric_delay_correction_no_std, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::TroposphericDelayCorrectionNoStd);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const tropospheric_delay_correction_no_std_t *c_struct = reinterpret_cast<const tropospheric_delay_correction_no_std_t*>(buffer);
  const sbp::TroposphericDelayCorrectionNoStd *cpp_struct = reinterpret_cast<const sbp::TroposphericDelayCorrectionNoStd*>(buffer);

//
//  EXPECT_EQ(c_struct->hydro, cpp_struct->hydro);
//
//  EXPECT_EQ(c_struct->wet, cpp_struct->wet);
//
}

TEST(test_tropospheric_delay_correction, default_construction) {
  sbp::TroposphericDelayCorrection variable;
  (void) variable;
}

TEST(test_tropospheric_delay_correction, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::TroposphericDelayCorrection);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const tropospheric_delay_correction_t *c_struct = reinterpret_cast<const tropospheric_delay_correction_t*>(buffer);
  const sbp::TroposphericDelayCorrection *cpp_struct = reinterpret_cast<const sbp::TroposphericDelayCorrection*>(buffer);

//
//  EXPECT_EQ(c_struct->hydro, cpp_struct->hydro);
//
//  EXPECT_EQ(c_struct->wet, cpp_struct->wet);
//
//  EXPECT_EQ(c_struct->stddev, cpp_struct->stddev);
//
}

TEST(test_s_t_e_c_residual_no_std, default_construction) {
  sbp::STECResidualNoStd variable;
  (void) variable;
}

TEST(test_s_t_e_c_residual_no_std, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::STECResidualNoStd);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const stec_residual_no_std_t *c_struct = reinterpret_cast<const stec_residual_no_std_t*>(buffer);
  const sbp::STECResidualNoStd *cpp_struct = reinterpret_cast<const sbp::STECResidualNoStd*>(buffer);

//
//  EXPECT_EQ(c_struct->sv_id, cpp_struct->sv_id);
//
//  EXPECT_EQ(c_struct->residual, cpp_struct->residual);
//
}

TEST(test_s_t_e_c_residual, default_construction) {
  sbp::STECResidual variable;
  (void) variable;
}

TEST(test_s_t_e_c_residual, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::STECResidual);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const stec_residual_t *c_struct = reinterpret_cast<const stec_residual_t*>(buffer);
  const sbp::STECResidual *cpp_struct = reinterpret_cast<const sbp::STECResidual*>(buffer);

//
//  EXPECT_EQ(c_struct->sv_id, cpp_struct->sv_id);
//
//  EXPECT_EQ(c_struct->residual, cpp_struct->residual);
//
//  EXPECT_EQ(c_struct->stddev, cpp_struct->stddev);
//
}

TEST(test_grid_element_no_std, default_construction) {
  sbp::GridElementNoStd<> variable;
  (void) variable;
}

TEST(test_grid_element_no_std, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::GridElementNoStd<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const grid_element_no_std_t *c_struct = reinterpret_cast<const grid_element_no_std_t*>(buffer);
  const sbp::GridElementNoStd<> *cpp_struct = reinterpret_cast<const sbp::GridElementNoStd<>*>(buffer);

//
//  EXPECT_EQ(c_struct->index, cpp_struct->index);
//
//  EXPECT_EQ(c_struct->tropo_delay_correction, cpp_struct->tropo_delay_correction);
//
//  EXPECT_EQ(c_struct->stec_residuals, cpp_struct->stec_residuals);
//
}

TEST(test_grid_element, default_construction) {
  sbp::GridElement<> variable;
  (void) variable;
}

TEST(test_grid_element, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::GridElement<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const grid_element_t *c_struct = reinterpret_cast<const grid_element_t*>(buffer);
  const sbp::GridElement<> *cpp_struct = reinterpret_cast<const sbp::GridElement<>*>(buffer);

//
//  EXPECT_EQ(c_struct->index, cpp_struct->index);
//
//  EXPECT_EQ(c_struct->tropo_delay_correction, cpp_struct->tropo_delay_correction);
//
//  EXPECT_EQ(c_struct->stec_residuals, cpp_struct->stec_residuals);
//
}

TEST(test_msg_ssr_orbit_clock, default_construction) {
  sbp::MsgSsrOrbitClock variable;
  (void) variable;
}

TEST(test_msg_ssr_orbit_clock, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgSsrOrbitClock);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_ssr_orbit_clock_t *c_struct = reinterpret_cast<const msg_ssr_orbit_clock_t*>(buffer);
  const sbp::MsgSsrOrbitClock *cpp_struct = reinterpret_cast<const sbp::MsgSsrOrbitClock*>(buffer);

//
//  EXPECT_EQ(c_struct->time, cpp_struct->time);
//
//  EXPECT_EQ(c_struct->sid, cpp_struct->sid);
//
//  EXPECT_EQ(c_struct->update_interval, cpp_struct->update_interval);
//
//  EXPECT_EQ(c_struct->iod_ssr, cpp_struct->iod_ssr);
//
//  EXPECT_EQ(c_struct->iod, cpp_struct->iod);
//
//  EXPECT_EQ(c_struct->radial, cpp_struct->radial);
//
//  EXPECT_EQ(c_struct->along, cpp_struct->along);
//
//  EXPECT_EQ(c_struct->cross, cpp_struct->cross);
//
//  EXPECT_EQ(c_struct->dot_radial, cpp_struct->dot_radial);
//
//  EXPECT_EQ(c_struct->dot_along, cpp_struct->dot_along);
//
//  EXPECT_EQ(c_struct->dot_cross, cpp_struct->dot_cross);
//
//  EXPECT_EQ(c_struct->c0, cpp_struct->c0);
//
//  EXPECT_EQ(c_struct->c1, cpp_struct->c1);
//
//  EXPECT_EQ(c_struct->c2, cpp_struct->c2);
//
}

TEST(test_msg_ssr_code_biases, default_construction) {
  sbp::MsgSsrCodeBiases<> variable;
  (void) variable;
}

TEST(test_msg_ssr_code_biases, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgSsrCodeBiases<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_ssr_code_biases_t *c_struct = reinterpret_cast<const msg_ssr_code_biases_t*>(buffer);
  const sbp::MsgSsrCodeBiases<> *cpp_struct = reinterpret_cast<const sbp::MsgSsrCodeBiases<>*>(buffer);

//
//  EXPECT_EQ(c_struct->time, cpp_struct->time);
//
//  EXPECT_EQ(c_struct->sid, cpp_struct->sid);
//
//  EXPECT_EQ(c_struct->update_interval, cpp_struct->update_interval);
//
//  EXPECT_EQ(c_struct->iod_ssr, cpp_struct->iod_ssr);
//
//  EXPECT_EQ(c_struct->biases, cpp_struct->biases);
//
}

TEST(test_msg_ssr_phase_biases, default_construction) {
  sbp::MsgSsrPhaseBiases<> variable;
  (void) variable;
}

TEST(test_msg_ssr_phase_biases, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgSsrPhaseBiases<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_ssr_phase_biases_t *c_struct = reinterpret_cast<const msg_ssr_phase_biases_t*>(buffer);
  const sbp::MsgSsrPhaseBiases<> *cpp_struct = reinterpret_cast<const sbp::MsgSsrPhaseBiases<>*>(buffer);

//
//  EXPECT_EQ(c_struct->time, cpp_struct->time);
//
//  EXPECT_EQ(c_struct->sid, cpp_struct->sid);
//
//  EXPECT_EQ(c_struct->update_interval, cpp_struct->update_interval);
//
//  EXPECT_EQ(c_struct->iod_ssr, cpp_struct->iod_ssr);
//
//  EXPECT_EQ(c_struct->dispersive_bias, cpp_struct->dispersive_bias);
//
//  EXPECT_EQ(c_struct->mw_consistency, cpp_struct->mw_consistency);
//
//  EXPECT_EQ(c_struct->yaw, cpp_struct->yaw);
//
//  EXPECT_EQ(c_struct->yaw_rate, cpp_struct->yaw_rate);
//
//  EXPECT_EQ(c_struct->biases, cpp_struct->biases);
//
}

TEST(test_msg_ssr_stec_correction, default_construction) {
  sbp::MsgSsrStecCorrection<> variable;
  (void) variable;
}

TEST(test_msg_ssr_stec_correction, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgSsrStecCorrection<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_ssr_stec_correction_t *c_struct = reinterpret_cast<const msg_ssr_stec_correction_t*>(buffer);
  const sbp::MsgSsrStecCorrection<> *cpp_struct = reinterpret_cast<const sbp::MsgSsrStecCorrection<>*>(buffer);

//
//  EXPECT_EQ(c_struct->header, cpp_struct->header);
//
//  EXPECT_EQ(c_struct->stec_sat_list, cpp_struct->stec_sat_list);
//
}

TEST(test_msg_ssr_gridded_correction, default_construction) {
  sbp::MsgSsrGriddedCorrection<1> variable;
  (void) variable;
}

TEST(test_msg_ssr_gridded_correction, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgSsrGriddedCorrection<1>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_ssr_gridded_correction_t *c_struct = reinterpret_cast<const msg_ssr_gridded_correction_t*>(buffer);
  const sbp::MsgSsrGriddedCorrection<1> *cpp_struct = reinterpret_cast<const sbp::MsgSsrGriddedCorrection<1>*>(buffer);

//
//  EXPECT_EQ(c_struct->header, cpp_struct->header);
//
//  EXPECT_EQ(c_struct->element, cpp_struct->element);
//
}

TEST(test_msg_ssr_tile_definition, default_construction) {
  sbp::MsgSsrTileDefinition variable;
  (void) variable;
}

TEST(test_msg_ssr_tile_definition, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgSsrTileDefinition);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_ssr_tile_definition_t *c_struct = reinterpret_cast<const msg_ssr_tile_definition_t*>(buffer);
  const sbp::MsgSsrTileDefinition *cpp_struct = reinterpret_cast<const sbp::MsgSsrTileDefinition*>(buffer);

//
//  EXPECT_EQ(c_struct->tile_set_id, cpp_struct->tile_set_id);
//
//  EXPECT_EQ(c_struct->tile_id, cpp_struct->tile_id);
//
//  EXPECT_EQ(c_struct->corner_nw_lat, cpp_struct->corner_nw_lat);
//
//  EXPECT_EQ(c_struct->corner_nw_lon, cpp_struct->corner_nw_lon);
//
//  EXPECT_EQ(c_struct->spacing_lat, cpp_struct->spacing_lat);
//
//  EXPECT_EQ(c_struct->spacing_lon, cpp_struct->spacing_lon);
//
//  EXPECT_EQ(c_struct->rows, cpp_struct->rows);
//
//  EXPECT_EQ(c_struct->cols, cpp_struct->cols);
//
//  EXPECT_EQ(c_struct->bitmask, cpp_struct->bitmask);
//
}

TEST(test_msg_ssr_orbit_clock_dep_a, default_construction) {
  sbp::MsgSsrOrbitClockDepA variable;
  (void) variable;
}

TEST(test_msg_ssr_orbit_clock_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgSsrOrbitClockDepA);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_ssr_orbit_clock_dep_a_t *c_struct = reinterpret_cast<const msg_ssr_orbit_clock_dep_a_t*>(buffer);
  const sbp::MsgSsrOrbitClockDepA *cpp_struct = reinterpret_cast<const sbp::MsgSsrOrbitClockDepA*>(buffer);

//
//  EXPECT_EQ(c_struct->time, cpp_struct->time);
//
//  EXPECT_EQ(c_struct->sid, cpp_struct->sid);
//
//  EXPECT_EQ(c_struct->update_interval, cpp_struct->update_interval);
//
//  EXPECT_EQ(c_struct->iod_ssr, cpp_struct->iod_ssr);
//
//  EXPECT_EQ(c_struct->iod, cpp_struct->iod);
//
//  EXPECT_EQ(c_struct->radial, cpp_struct->radial);
//
//  EXPECT_EQ(c_struct->along, cpp_struct->along);
//
//  EXPECT_EQ(c_struct->cross, cpp_struct->cross);
//
//  EXPECT_EQ(c_struct->dot_radial, cpp_struct->dot_radial);
//
//  EXPECT_EQ(c_struct->dot_along, cpp_struct->dot_along);
//
//  EXPECT_EQ(c_struct->dot_cross, cpp_struct->dot_cross);
//
//  EXPECT_EQ(c_struct->c0, cpp_struct->c0);
//
//  EXPECT_EQ(c_struct->c1, cpp_struct->c1);
//
//  EXPECT_EQ(c_struct->c2, cpp_struct->c2);
//
}

TEST(test_s_t_e_c_header_dep_a, default_construction) {
  sbp::STECHeaderDepA variable;
  (void) variable;
}

TEST(test_s_t_e_c_header_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::STECHeaderDepA);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const stec_header_dep_a_t *c_struct = reinterpret_cast<const stec_header_dep_a_t*>(buffer);
  const sbp::STECHeaderDepA *cpp_struct = reinterpret_cast<const sbp::STECHeaderDepA*>(buffer);

//
//  EXPECT_EQ(c_struct->time, cpp_struct->time);
//
//  EXPECT_EQ(c_struct->num_msgs, cpp_struct->num_msgs);
//
//  EXPECT_EQ(c_struct->seq_num, cpp_struct->seq_num);
//
//  EXPECT_EQ(c_struct->update_interval, cpp_struct->update_interval);
//
//  EXPECT_EQ(c_struct->iod_atmo, cpp_struct->iod_atmo);
//
}

TEST(test_gridded_correction_header_dep_a, default_construction) {
  sbp::GriddedCorrectionHeaderDepA variable;
  (void) variable;
}

TEST(test_gridded_correction_header_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::GriddedCorrectionHeaderDepA);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const gridded_correction_header_dep_a_t *c_struct = reinterpret_cast<const gridded_correction_header_dep_a_t*>(buffer);
  const sbp::GriddedCorrectionHeaderDepA *cpp_struct = reinterpret_cast<const sbp::GriddedCorrectionHeaderDepA*>(buffer);

//
//  EXPECT_EQ(c_struct->time, cpp_struct->time);
//
//  EXPECT_EQ(c_struct->num_msgs, cpp_struct->num_msgs);
//
//  EXPECT_EQ(c_struct->seq_num, cpp_struct->seq_num);
//
//  EXPECT_EQ(c_struct->update_interval, cpp_struct->update_interval);
//
//  EXPECT_EQ(c_struct->iod_atmo, cpp_struct->iod_atmo);
//
//  EXPECT_EQ(c_struct->tropo_quality_indicator, cpp_struct->tropo_quality_indicator);
//
}

TEST(test_grid_definition_header_dep_a, default_construction) {
  sbp::GridDefinitionHeaderDepA variable;
  (void) variable;
}

TEST(test_grid_definition_header_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::GridDefinitionHeaderDepA);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const grid_definition_header_dep_a_t *c_struct = reinterpret_cast<const grid_definition_header_dep_a_t*>(buffer);
  const sbp::GridDefinitionHeaderDepA *cpp_struct = reinterpret_cast<const sbp::GridDefinitionHeaderDepA*>(buffer);

//
//  EXPECT_EQ(c_struct->region_size_inverse, cpp_struct->region_size_inverse);
//
//  EXPECT_EQ(c_struct->area_width, cpp_struct->area_width);
//
//  EXPECT_EQ(c_struct->lat_nw_corner_enc, cpp_struct->lat_nw_corner_enc);
//
//  EXPECT_EQ(c_struct->lon_nw_corner_enc, cpp_struct->lon_nw_corner_enc);
//
//  EXPECT_EQ(c_struct->num_msgs, cpp_struct->num_msgs);
//
//  EXPECT_EQ(c_struct->seq_num, cpp_struct->seq_num);
//
}

TEST(test_msg_ssr_stec_correction_dep_a, default_construction) {
  sbp::MsgSsrStecCorrectionDepA<> variable;
  (void) variable;
}

TEST(test_msg_ssr_stec_correction_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgSsrStecCorrectionDepA<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_ssr_stec_correction_dep_a_t *c_struct = reinterpret_cast<const msg_ssr_stec_correction_dep_a_t*>(buffer);
  const sbp::MsgSsrStecCorrectionDepA<> *cpp_struct = reinterpret_cast<const sbp::MsgSsrStecCorrectionDepA<>*>(buffer);

//
//  EXPECT_EQ(c_struct->header, cpp_struct->header);
//
//  EXPECT_EQ(c_struct->stec_sat_list, cpp_struct->stec_sat_list);
//
}

TEST(test_msg_ssr_gridded_correction_no_std_dep_a, default_construction) {
  sbp::MsgSsrGriddedCorrectionNoStdDepA<1> variable;
  (void) variable;
}

TEST(test_msg_ssr_gridded_correction_no_std_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgSsrGriddedCorrectionNoStdDepA<1>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_ssr_gridded_correction_no_std_dep_a_t *c_struct = reinterpret_cast<const msg_ssr_gridded_correction_no_std_dep_a_t*>(buffer);
  const sbp::MsgSsrGriddedCorrectionNoStdDepA<1> *cpp_struct = reinterpret_cast<const sbp::MsgSsrGriddedCorrectionNoStdDepA<1>*>(buffer);

//
//  EXPECT_EQ(c_struct->header, cpp_struct->header);
//
//  EXPECT_EQ(c_struct->element, cpp_struct->element);
//
}

TEST(test_msg_ssr_gridded_correction_dep_a, default_construction) {
  sbp::MsgSsrGriddedCorrectionDepA<1> variable;
  (void) variable;
}

TEST(test_msg_ssr_gridded_correction_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgSsrGriddedCorrectionDepA<1>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_ssr_gridded_correction_dep_a_t *c_struct = reinterpret_cast<const msg_ssr_gridded_correction_dep_a_t*>(buffer);
  const sbp::MsgSsrGriddedCorrectionDepA<1> *cpp_struct = reinterpret_cast<const sbp::MsgSsrGriddedCorrectionDepA<1>*>(buffer);

//
//  EXPECT_EQ(c_struct->header, cpp_struct->header);
//
//  EXPECT_EQ(c_struct->element, cpp_struct->element);
//
}

TEST(test_msg_ssr_grid_definition_dep_a, default_construction) {
  sbp::MsgSsrGridDefinitionDepA<> variable;
  (void) variable;
}

TEST(test_msg_ssr_grid_definition_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgSsrGridDefinitionDepA<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_ssr_grid_definition_dep_a_t *c_struct = reinterpret_cast<const msg_ssr_grid_definition_dep_a_t*>(buffer);
  const sbp::MsgSsrGridDefinitionDepA<> *cpp_struct = reinterpret_cast<const sbp::MsgSsrGridDefinitionDepA<>*>(buffer);

//
//  EXPECT_EQ(c_struct->header, cpp_struct->header);
//
//  EXPECT_EQ(c_struct->rle_list, cpp_struct->rle_list);
//
}
