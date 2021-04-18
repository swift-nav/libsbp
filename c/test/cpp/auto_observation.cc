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
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>
#include <libsbp/observation.h>
#include <libsbp/cpp/observation.h>


TEST(test_observation_header, default_construction) {
  sbp::ObservationHeader variable;
  (void) variable;
}

TEST(test_observation_header, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::ObservationHeader);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const observation_header_t *c_struct = reinterpret_cast<const observation_header_t*>(buffer);
  const sbp::ObservationHeader *cpp_struct = reinterpret_cast<const sbp::ObservationHeader*>(buffer);

//
//  EXPECT_EQ(c_struct->t, cpp_struct->t);
//
//  EXPECT_EQ(c_struct->n_obs, cpp_struct->n_obs);
//
}

TEST(test_doppler, default_construction) {
  sbp::Doppler variable;
  (void) variable;
}

TEST(test_doppler, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::Doppler);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const doppler_t *c_struct = reinterpret_cast<const doppler_t*>(buffer);
  const sbp::Doppler *cpp_struct = reinterpret_cast<const sbp::Doppler*>(buffer);

//
//  EXPECT_EQ(c_struct->i, cpp_struct->i);
//
//  EXPECT_EQ(c_struct->f, cpp_struct->f);
//
}

TEST(test_packed_obs_content, default_construction) {
  sbp::PackedObsContent variable;
  (void) variable;
}

TEST(test_packed_obs_content, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::PackedObsContent);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const packed_obs_content_t *c_struct = reinterpret_cast<const packed_obs_content_t*>(buffer);
  const sbp::PackedObsContent *cpp_struct = reinterpret_cast<const sbp::PackedObsContent*>(buffer);

//
//  EXPECT_EQ(c_struct->P, cpp_struct->P);
//
//  EXPECT_EQ(c_struct->L, cpp_struct->L);
//
//  EXPECT_EQ(c_struct->D, cpp_struct->D);
//
//  EXPECT_EQ(c_struct->cn0, cpp_struct->cn0);
//
//  EXPECT_EQ(c_struct->lock, cpp_struct->lock);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
//  EXPECT_EQ(c_struct->sid, cpp_struct->sid);
//
}

TEST(test_packed_osr_content, default_construction) {
  sbp::PackedOsrContent variable;
  (void) variable;
}

TEST(test_packed_osr_content, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::PackedOsrContent);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const packed_osr_content_t *c_struct = reinterpret_cast<const packed_osr_content_t*>(buffer);
  const sbp::PackedOsrContent *cpp_struct = reinterpret_cast<const sbp::PackedOsrContent*>(buffer);

//
//  EXPECT_EQ(c_struct->P, cpp_struct->P);
//
//  EXPECT_EQ(c_struct->L, cpp_struct->L);
//
//  EXPECT_EQ(c_struct->lock, cpp_struct->lock);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
//  EXPECT_EQ(c_struct->sid, cpp_struct->sid);
//
//  EXPECT_EQ(c_struct->iono_std, cpp_struct->iono_std);
//
//  EXPECT_EQ(c_struct->tropo_std, cpp_struct->tropo_std);
//
//  EXPECT_EQ(c_struct->range_std, cpp_struct->range_std);
//
}

TEST(test_msg_obs, default_construction) {
  sbp::MsgObs<> variable;
  (void) variable;
}

TEST(test_msg_obs, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgObs<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_obs_t *c_struct = reinterpret_cast<const msg_obs_t*>(buffer);
  const sbp::MsgObs<> *cpp_struct = reinterpret_cast<const sbp::MsgObs<>*>(buffer);

//
//  EXPECT_EQ(c_struct->header, cpp_struct->header);
//
//  EXPECT_EQ(c_struct->obs, cpp_struct->obs);
//
}

TEST(test_msg_base_pos_llh, default_construction) {
  sbp::MsgBasePosLlh variable;
  (void) variable;
}

TEST(test_msg_base_pos_llh, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgBasePosLlh);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_base_pos_llh_t *c_struct = reinterpret_cast<const msg_base_pos_llh_t*>(buffer);
  const sbp::MsgBasePosLlh *cpp_struct = reinterpret_cast<const sbp::MsgBasePosLlh*>(buffer);

//
//  EXPECT_EQ(c_struct->lat, cpp_struct->lat);
//
//  EXPECT_EQ(c_struct->lon, cpp_struct->lon);
//
//  EXPECT_EQ(c_struct->height, cpp_struct->height);
//
}

TEST(test_msg_base_pos_ecef, default_construction) {
  sbp::MsgBasePosEcef variable;
  (void) variable;
}

TEST(test_msg_base_pos_ecef, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgBasePosEcef);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_base_pos_ecef_t *c_struct = reinterpret_cast<const msg_base_pos_ecef_t*>(buffer);
  const sbp::MsgBasePosEcef *cpp_struct = reinterpret_cast<const sbp::MsgBasePosEcef*>(buffer);

//
//  EXPECT_EQ(c_struct->x, cpp_struct->x);
//
//  EXPECT_EQ(c_struct->y, cpp_struct->y);
//
//  EXPECT_EQ(c_struct->z, cpp_struct->z);
//
}

TEST(test_ephemeris_common_content, default_construction) {
  sbp::EphemerisCommonContent variable;
  (void) variable;
}

TEST(test_ephemeris_common_content, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::EphemerisCommonContent);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const ephemeris_common_content_t *c_struct = reinterpret_cast<const ephemeris_common_content_t*>(buffer);
  const sbp::EphemerisCommonContent *cpp_struct = reinterpret_cast<const sbp::EphemerisCommonContent*>(buffer);

//
//  EXPECT_EQ(c_struct->sid, cpp_struct->sid);
//
//  EXPECT_EQ(c_struct->toe, cpp_struct->toe);
//
//  EXPECT_EQ(c_struct->ura, cpp_struct->ura);
//
//  EXPECT_EQ(c_struct->fit_interval, cpp_struct->fit_interval);
//
//  EXPECT_EQ(c_struct->valid, cpp_struct->valid);
//
//  EXPECT_EQ(c_struct->health_bits, cpp_struct->health_bits);
//
}

TEST(test_ephemeris_common_content_dep_b, default_construction) {
  sbp::EphemerisCommonContentDepB variable;
  (void) variable;
}

TEST(test_ephemeris_common_content_dep_b, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::EphemerisCommonContentDepB);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const ephemeris_common_content_dep_b_t *c_struct = reinterpret_cast<const ephemeris_common_content_dep_b_t*>(buffer);
  const sbp::EphemerisCommonContentDepB *cpp_struct = reinterpret_cast<const sbp::EphemerisCommonContentDepB*>(buffer);

//
//  EXPECT_EQ(c_struct->sid, cpp_struct->sid);
//
//  EXPECT_EQ(c_struct->toe, cpp_struct->toe);
//
//  EXPECT_EQ(c_struct->ura, cpp_struct->ura);
//
//  EXPECT_EQ(c_struct->fit_interval, cpp_struct->fit_interval);
//
//  EXPECT_EQ(c_struct->valid, cpp_struct->valid);
//
//  EXPECT_EQ(c_struct->health_bits, cpp_struct->health_bits);
//
}

TEST(test_ephemeris_common_content_dep_a, default_construction) {
  sbp::EphemerisCommonContentDepA variable;
  (void) variable;
}

TEST(test_ephemeris_common_content_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::EphemerisCommonContentDepA);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const ephemeris_common_content_dep_a_t *c_struct = reinterpret_cast<const ephemeris_common_content_dep_a_t*>(buffer);
  const sbp::EphemerisCommonContentDepA *cpp_struct = reinterpret_cast<const sbp::EphemerisCommonContentDepA*>(buffer);

//
//  EXPECT_EQ(c_struct->sid, cpp_struct->sid);
//
//  EXPECT_EQ(c_struct->toe, cpp_struct->toe);
//
//  EXPECT_EQ(c_struct->ura, cpp_struct->ura);
//
//  EXPECT_EQ(c_struct->fit_interval, cpp_struct->fit_interval);
//
//  EXPECT_EQ(c_struct->valid, cpp_struct->valid);
//
//  EXPECT_EQ(c_struct->health_bits, cpp_struct->health_bits);
//
}

TEST(test_msg_ephemeris_gps_dep_e, default_construction) {
  sbp::MsgEphemerisGpsDepE variable;
  (void) variable;
}

TEST(test_msg_ephemeris_gps_dep_e, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgEphemerisGpsDepE);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_ephemeris_gps_dep_e_t *c_struct = reinterpret_cast<const msg_ephemeris_gps_dep_e_t*>(buffer);
  const sbp::MsgEphemerisGpsDepE *cpp_struct = reinterpret_cast<const sbp::MsgEphemerisGpsDepE*>(buffer);

//
//  EXPECT_EQ(c_struct->common, cpp_struct->common);
//
//  EXPECT_EQ(c_struct->tgd, cpp_struct->tgd);
//
//  EXPECT_EQ(c_struct->c_rs, cpp_struct->c_rs);
//
//  EXPECT_EQ(c_struct->c_rc, cpp_struct->c_rc);
//
//  EXPECT_EQ(c_struct->c_uc, cpp_struct->c_uc);
//
//  EXPECT_EQ(c_struct->c_us, cpp_struct->c_us);
//
//  EXPECT_EQ(c_struct->c_ic, cpp_struct->c_ic);
//
//  EXPECT_EQ(c_struct->c_is, cpp_struct->c_is);
//
//  EXPECT_EQ(c_struct->dn, cpp_struct->dn);
//
//  EXPECT_EQ(c_struct->m0, cpp_struct->m0);
//
//  EXPECT_EQ(c_struct->ecc, cpp_struct->ecc);
//
//  EXPECT_EQ(c_struct->sqrta, cpp_struct->sqrta);
//
//  EXPECT_EQ(c_struct->omega0, cpp_struct->omega0);
//
//  EXPECT_EQ(c_struct->omegadot, cpp_struct->omegadot);
//
//  EXPECT_EQ(c_struct->w, cpp_struct->w);
//
//  EXPECT_EQ(c_struct->inc, cpp_struct->inc);
//
//  EXPECT_EQ(c_struct->inc_dot, cpp_struct->inc_dot);
//
//  EXPECT_EQ(c_struct->af0, cpp_struct->af0);
//
//  EXPECT_EQ(c_struct->af1, cpp_struct->af1);
//
//  EXPECT_EQ(c_struct->af2, cpp_struct->af2);
//
//  EXPECT_EQ(c_struct->toc, cpp_struct->toc);
//
//  EXPECT_EQ(c_struct->iode, cpp_struct->iode);
//
//  EXPECT_EQ(c_struct->iodc, cpp_struct->iodc);
//
}

TEST(test_msg_ephemeris_gps_dep_f, default_construction) {
  sbp::MsgEphemerisGpsDepF variable;
  (void) variable;
}

TEST(test_msg_ephemeris_gps_dep_f, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgEphemerisGpsDepF);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_ephemeris_gps_dep_f_t *c_struct = reinterpret_cast<const msg_ephemeris_gps_dep_f_t*>(buffer);
  const sbp::MsgEphemerisGpsDepF *cpp_struct = reinterpret_cast<const sbp::MsgEphemerisGpsDepF*>(buffer);

//
//  EXPECT_EQ(c_struct->common, cpp_struct->common);
//
//  EXPECT_EQ(c_struct->tgd, cpp_struct->tgd);
//
//  EXPECT_EQ(c_struct->c_rs, cpp_struct->c_rs);
//
//  EXPECT_EQ(c_struct->c_rc, cpp_struct->c_rc);
//
//  EXPECT_EQ(c_struct->c_uc, cpp_struct->c_uc);
//
//  EXPECT_EQ(c_struct->c_us, cpp_struct->c_us);
//
//  EXPECT_EQ(c_struct->c_ic, cpp_struct->c_ic);
//
//  EXPECT_EQ(c_struct->c_is, cpp_struct->c_is);
//
//  EXPECT_EQ(c_struct->dn, cpp_struct->dn);
//
//  EXPECT_EQ(c_struct->m0, cpp_struct->m0);
//
//  EXPECT_EQ(c_struct->ecc, cpp_struct->ecc);
//
//  EXPECT_EQ(c_struct->sqrta, cpp_struct->sqrta);
//
//  EXPECT_EQ(c_struct->omega0, cpp_struct->omega0);
//
//  EXPECT_EQ(c_struct->omegadot, cpp_struct->omegadot);
//
//  EXPECT_EQ(c_struct->w, cpp_struct->w);
//
//  EXPECT_EQ(c_struct->inc, cpp_struct->inc);
//
//  EXPECT_EQ(c_struct->inc_dot, cpp_struct->inc_dot);
//
//  EXPECT_EQ(c_struct->af0, cpp_struct->af0);
//
//  EXPECT_EQ(c_struct->af1, cpp_struct->af1);
//
//  EXPECT_EQ(c_struct->af2, cpp_struct->af2);
//
//  EXPECT_EQ(c_struct->toc, cpp_struct->toc);
//
//  EXPECT_EQ(c_struct->iode, cpp_struct->iode);
//
//  EXPECT_EQ(c_struct->iodc, cpp_struct->iodc);
//
}

TEST(test_msg_ephemeris_gps, default_construction) {
  sbp::MsgEphemerisGps variable;
  (void) variable;
}

TEST(test_msg_ephemeris_gps, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgEphemerisGps);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_ephemeris_gps_t *c_struct = reinterpret_cast<const msg_ephemeris_gps_t*>(buffer);
  const sbp::MsgEphemerisGps *cpp_struct = reinterpret_cast<const sbp::MsgEphemerisGps*>(buffer);

//
//  EXPECT_EQ(c_struct->common, cpp_struct->common);
//
//  EXPECT_EQ(c_struct->tgd, cpp_struct->tgd);
//
//  EXPECT_EQ(c_struct->c_rs, cpp_struct->c_rs);
//
//  EXPECT_EQ(c_struct->c_rc, cpp_struct->c_rc);
//
//  EXPECT_EQ(c_struct->c_uc, cpp_struct->c_uc);
//
//  EXPECT_EQ(c_struct->c_us, cpp_struct->c_us);
//
//  EXPECT_EQ(c_struct->c_ic, cpp_struct->c_ic);
//
//  EXPECT_EQ(c_struct->c_is, cpp_struct->c_is);
//
//  EXPECT_EQ(c_struct->dn, cpp_struct->dn);
//
//  EXPECT_EQ(c_struct->m0, cpp_struct->m0);
//
//  EXPECT_EQ(c_struct->ecc, cpp_struct->ecc);
//
//  EXPECT_EQ(c_struct->sqrta, cpp_struct->sqrta);
//
//  EXPECT_EQ(c_struct->omega0, cpp_struct->omega0);
//
//  EXPECT_EQ(c_struct->omegadot, cpp_struct->omegadot);
//
//  EXPECT_EQ(c_struct->w, cpp_struct->w);
//
//  EXPECT_EQ(c_struct->inc, cpp_struct->inc);
//
//  EXPECT_EQ(c_struct->inc_dot, cpp_struct->inc_dot);
//
//  EXPECT_EQ(c_struct->af0, cpp_struct->af0);
//
//  EXPECT_EQ(c_struct->af1, cpp_struct->af1);
//
//  EXPECT_EQ(c_struct->af2, cpp_struct->af2);
//
//  EXPECT_EQ(c_struct->toc, cpp_struct->toc);
//
//  EXPECT_EQ(c_struct->iode, cpp_struct->iode);
//
//  EXPECT_EQ(c_struct->iodc, cpp_struct->iodc);
//
}

TEST(test_msg_ephemeris_qzss, default_construction) {
  sbp::MsgEphemerisQzss variable;
  (void) variable;
}

TEST(test_msg_ephemeris_qzss, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgEphemerisQzss);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_ephemeris_qzss_t *c_struct = reinterpret_cast<const msg_ephemeris_qzss_t*>(buffer);
  const sbp::MsgEphemerisQzss *cpp_struct = reinterpret_cast<const sbp::MsgEphemerisQzss*>(buffer);

//
//  EXPECT_EQ(c_struct->common, cpp_struct->common);
//
//  EXPECT_EQ(c_struct->tgd, cpp_struct->tgd);
//
//  EXPECT_EQ(c_struct->c_rs, cpp_struct->c_rs);
//
//  EXPECT_EQ(c_struct->c_rc, cpp_struct->c_rc);
//
//  EXPECT_EQ(c_struct->c_uc, cpp_struct->c_uc);
//
//  EXPECT_EQ(c_struct->c_us, cpp_struct->c_us);
//
//  EXPECT_EQ(c_struct->c_ic, cpp_struct->c_ic);
//
//  EXPECT_EQ(c_struct->c_is, cpp_struct->c_is);
//
//  EXPECT_EQ(c_struct->dn, cpp_struct->dn);
//
//  EXPECT_EQ(c_struct->m0, cpp_struct->m0);
//
//  EXPECT_EQ(c_struct->ecc, cpp_struct->ecc);
//
//  EXPECT_EQ(c_struct->sqrta, cpp_struct->sqrta);
//
//  EXPECT_EQ(c_struct->omega0, cpp_struct->omega0);
//
//  EXPECT_EQ(c_struct->omegadot, cpp_struct->omegadot);
//
//  EXPECT_EQ(c_struct->w, cpp_struct->w);
//
//  EXPECT_EQ(c_struct->inc, cpp_struct->inc);
//
//  EXPECT_EQ(c_struct->inc_dot, cpp_struct->inc_dot);
//
//  EXPECT_EQ(c_struct->af0, cpp_struct->af0);
//
//  EXPECT_EQ(c_struct->af1, cpp_struct->af1);
//
//  EXPECT_EQ(c_struct->af2, cpp_struct->af2);
//
//  EXPECT_EQ(c_struct->toc, cpp_struct->toc);
//
//  EXPECT_EQ(c_struct->iode, cpp_struct->iode);
//
//  EXPECT_EQ(c_struct->iodc, cpp_struct->iodc);
//
}

TEST(test_msg_ephemeris_bds, default_construction) {
  sbp::MsgEphemerisBds variable;
  (void) variable;
}

TEST(test_msg_ephemeris_bds, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgEphemerisBds);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_ephemeris_bds_t *c_struct = reinterpret_cast<const msg_ephemeris_bds_t*>(buffer);
  const sbp::MsgEphemerisBds *cpp_struct = reinterpret_cast<const sbp::MsgEphemerisBds*>(buffer);

//
//  EXPECT_EQ(c_struct->common, cpp_struct->common);
//
//  EXPECT_EQ(c_struct->tgd1, cpp_struct->tgd1);
//
//  EXPECT_EQ(c_struct->tgd2, cpp_struct->tgd2);
//
//  EXPECT_EQ(c_struct->c_rs, cpp_struct->c_rs);
//
//  EXPECT_EQ(c_struct->c_rc, cpp_struct->c_rc);
//
//  EXPECT_EQ(c_struct->c_uc, cpp_struct->c_uc);
//
//  EXPECT_EQ(c_struct->c_us, cpp_struct->c_us);
//
//  EXPECT_EQ(c_struct->c_ic, cpp_struct->c_ic);
//
//  EXPECT_EQ(c_struct->c_is, cpp_struct->c_is);
//
//  EXPECT_EQ(c_struct->dn, cpp_struct->dn);
//
//  EXPECT_EQ(c_struct->m0, cpp_struct->m0);
//
//  EXPECT_EQ(c_struct->ecc, cpp_struct->ecc);
//
//  EXPECT_EQ(c_struct->sqrta, cpp_struct->sqrta);
//
//  EXPECT_EQ(c_struct->omega0, cpp_struct->omega0);
//
//  EXPECT_EQ(c_struct->omegadot, cpp_struct->omegadot);
//
//  EXPECT_EQ(c_struct->w, cpp_struct->w);
//
//  EXPECT_EQ(c_struct->inc, cpp_struct->inc);
//
//  EXPECT_EQ(c_struct->inc_dot, cpp_struct->inc_dot);
//
//  EXPECT_EQ(c_struct->af0, cpp_struct->af0);
//
//  EXPECT_EQ(c_struct->af1, cpp_struct->af1);
//
//  EXPECT_EQ(c_struct->af2, cpp_struct->af2);
//
//  EXPECT_EQ(c_struct->toc, cpp_struct->toc);
//
//  EXPECT_EQ(c_struct->iode, cpp_struct->iode);
//
//  EXPECT_EQ(c_struct->iodc, cpp_struct->iodc);
//
}

TEST(test_msg_ephemeris_gal_dep_a, default_construction) {
  sbp::MsgEphemerisGalDepA variable;
  (void) variable;
}

TEST(test_msg_ephemeris_gal_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgEphemerisGalDepA);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_ephemeris_gal_dep_a_t *c_struct = reinterpret_cast<const msg_ephemeris_gal_dep_a_t*>(buffer);
  const sbp::MsgEphemerisGalDepA *cpp_struct = reinterpret_cast<const sbp::MsgEphemerisGalDepA*>(buffer);

//
//  EXPECT_EQ(c_struct->common, cpp_struct->common);
//
//  EXPECT_EQ(c_struct->bgd_e1e5a, cpp_struct->bgd_e1e5a);
//
//  EXPECT_EQ(c_struct->bgd_e1e5b, cpp_struct->bgd_e1e5b);
//
//  EXPECT_EQ(c_struct->c_rs, cpp_struct->c_rs);
//
//  EXPECT_EQ(c_struct->c_rc, cpp_struct->c_rc);
//
//  EXPECT_EQ(c_struct->c_uc, cpp_struct->c_uc);
//
//  EXPECT_EQ(c_struct->c_us, cpp_struct->c_us);
//
//  EXPECT_EQ(c_struct->c_ic, cpp_struct->c_ic);
//
//  EXPECT_EQ(c_struct->c_is, cpp_struct->c_is);
//
//  EXPECT_EQ(c_struct->dn, cpp_struct->dn);
//
//  EXPECT_EQ(c_struct->m0, cpp_struct->m0);
//
//  EXPECT_EQ(c_struct->ecc, cpp_struct->ecc);
//
//  EXPECT_EQ(c_struct->sqrta, cpp_struct->sqrta);
//
//  EXPECT_EQ(c_struct->omega0, cpp_struct->omega0);
//
//  EXPECT_EQ(c_struct->omegadot, cpp_struct->omegadot);
//
//  EXPECT_EQ(c_struct->w, cpp_struct->w);
//
//  EXPECT_EQ(c_struct->inc, cpp_struct->inc);
//
//  EXPECT_EQ(c_struct->inc_dot, cpp_struct->inc_dot);
//
//  EXPECT_EQ(c_struct->af0, cpp_struct->af0);
//
//  EXPECT_EQ(c_struct->af1, cpp_struct->af1);
//
//  EXPECT_EQ(c_struct->af2, cpp_struct->af2);
//
//  EXPECT_EQ(c_struct->toc, cpp_struct->toc);
//
//  EXPECT_EQ(c_struct->iode, cpp_struct->iode);
//
//  EXPECT_EQ(c_struct->iodc, cpp_struct->iodc);
//
}

TEST(test_msg_ephemeris_gal, default_construction) {
  sbp::MsgEphemerisGal variable;
  (void) variable;
}

TEST(test_msg_ephemeris_gal, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgEphemerisGal);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_ephemeris_gal_t *c_struct = reinterpret_cast<const msg_ephemeris_gal_t*>(buffer);
  const sbp::MsgEphemerisGal *cpp_struct = reinterpret_cast<const sbp::MsgEphemerisGal*>(buffer);

//
//  EXPECT_EQ(c_struct->common, cpp_struct->common);
//
//  EXPECT_EQ(c_struct->bgd_e1e5a, cpp_struct->bgd_e1e5a);
//
//  EXPECT_EQ(c_struct->bgd_e1e5b, cpp_struct->bgd_e1e5b);
//
//  EXPECT_EQ(c_struct->c_rs, cpp_struct->c_rs);
//
//  EXPECT_EQ(c_struct->c_rc, cpp_struct->c_rc);
//
//  EXPECT_EQ(c_struct->c_uc, cpp_struct->c_uc);
//
//  EXPECT_EQ(c_struct->c_us, cpp_struct->c_us);
//
//  EXPECT_EQ(c_struct->c_ic, cpp_struct->c_ic);
//
//  EXPECT_EQ(c_struct->c_is, cpp_struct->c_is);
//
//  EXPECT_EQ(c_struct->dn, cpp_struct->dn);
//
//  EXPECT_EQ(c_struct->m0, cpp_struct->m0);
//
//  EXPECT_EQ(c_struct->ecc, cpp_struct->ecc);
//
//  EXPECT_EQ(c_struct->sqrta, cpp_struct->sqrta);
//
//  EXPECT_EQ(c_struct->omega0, cpp_struct->omega0);
//
//  EXPECT_EQ(c_struct->omegadot, cpp_struct->omegadot);
//
//  EXPECT_EQ(c_struct->w, cpp_struct->w);
//
//  EXPECT_EQ(c_struct->inc, cpp_struct->inc);
//
//  EXPECT_EQ(c_struct->inc_dot, cpp_struct->inc_dot);
//
//  EXPECT_EQ(c_struct->af0, cpp_struct->af0);
//
//  EXPECT_EQ(c_struct->af1, cpp_struct->af1);
//
//  EXPECT_EQ(c_struct->af2, cpp_struct->af2);
//
//  EXPECT_EQ(c_struct->toc, cpp_struct->toc);
//
//  EXPECT_EQ(c_struct->iode, cpp_struct->iode);
//
//  EXPECT_EQ(c_struct->iodc, cpp_struct->iodc);
//
//  EXPECT_EQ(c_struct->source, cpp_struct->source);
//
}

TEST(test_msg_ephemeris_sbas_dep_a, default_construction) {
  sbp::MsgEphemerisSbasDepA variable;
  (void) variable;
}

TEST(test_msg_ephemeris_sbas_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgEphemerisSbasDepA);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_ephemeris_sbas_dep_a_t *c_struct = reinterpret_cast<const msg_ephemeris_sbas_dep_a_t*>(buffer);
  const sbp::MsgEphemerisSbasDepA *cpp_struct = reinterpret_cast<const sbp::MsgEphemerisSbasDepA*>(buffer);

//
//  EXPECT_EQ(c_struct->common, cpp_struct->common);
//
//  EXPECT_EQ(c_struct->pos, cpp_struct->pos);
//
//  EXPECT_EQ(c_struct->vel, cpp_struct->vel);
//
//  EXPECT_EQ(c_struct->acc, cpp_struct->acc);
//
//  EXPECT_EQ(c_struct->a_gf0, cpp_struct->a_gf0);
//
//  EXPECT_EQ(c_struct->a_gf1, cpp_struct->a_gf1);
//
}

TEST(test_msg_ephemeris_glo_dep_a, default_construction) {
  sbp::MsgEphemerisGloDepA variable;
  (void) variable;
}

TEST(test_msg_ephemeris_glo_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgEphemerisGloDepA);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_ephemeris_glo_dep_a_t *c_struct = reinterpret_cast<const msg_ephemeris_glo_dep_a_t*>(buffer);
  const sbp::MsgEphemerisGloDepA *cpp_struct = reinterpret_cast<const sbp::MsgEphemerisGloDepA*>(buffer);

//
//  EXPECT_EQ(c_struct->common, cpp_struct->common);
//
//  EXPECT_EQ(c_struct->gamma, cpp_struct->gamma);
//
//  EXPECT_EQ(c_struct->tau, cpp_struct->tau);
//
//  EXPECT_EQ(c_struct->pos, cpp_struct->pos);
//
//  EXPECT_EQ(c_struct->vel, cpp_struct->vel);
//
//  EXPECT_EQ(c_struct->acc, cpp_struct->acc);
//
}

TEST(test_msg_ephemeris_sbas_dep_b, default_construction) {
  sbp::MsgEphemerisSbasDepB variable;
  (void) variable;
}

TEST(test_msg_ephemeris_sbas_dep_b, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgEphemerisSbasDepB);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_ephemeris_sbas_dep_b_t *c_struct = reinterpret_cast<const msg_ephemeris_sbas_dep_b_t*>(buffer);
  const sbp::MsgEphemerisSbasDepB *cpp_struct = reinterpret_cast<const sbp::MsgEphemerisSbasDepB*>(buffer);

//
//  EXPECT_EQ(c_struct->common, cpp_struct->common);
//
//  EXPECT_EQ(c_struct->pos, cpp_struct->pos);
//
//  EXPECT_EQ(c_struct->vel, cpp_struct->vel);
//
//  EXPECT_EQ(c_struct->acc, cpp_struct->acc);
//
//  EXPECT_EQ(c_struct->a_gf0, cpp_struct->a_gf0);
//
//  EXPECT_EQ(c_struct->a_gf1, cpp_struct->a_gf1);
//
}

TEST(test_msg_ephemeris_sbas, default_construction) {
  sbp::MsgEphemerisSbas variable;
  (void) variable;
}

TEST(test_msg_ephemeris_sbas, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgEphemerisSbas);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_ephemeris_sbas_t *c_struct = reinterpret_cast<const msg_ephemeris_sbas_t*>(buffer);
  const sbp::MsgEphemerisSbas *cpp_struct = reinterpret_cast<const sbp::MsgEphemerisSbas*>(buffer);

//
//  EXPECT_EQ(c_struct->common, cpp_struct->common);
//
//  EXPECT_EQ(c_struct->pos, cpp_struct->pos);
//
//  EXPECT_EQ(c_struct->vel, cpp_struct->vel);
//
//  EXPECT_EQ(c_struct->acc, cpp_struct->acc);
//
//  EXPECT_EQ(c_struct->a_gf0, cpp_struct->a_gf0);
//
//  EXPECT_EQ(c_struct->a_gf1, cpp_struct->a_gf1);
//
}

TEST(test_msg_ephemeris_glo_dep_b, default_construction) {
  sbp::MsgEphemerisGloDepB variable;
  (void) variable;
}

TEST(test_msg_ephemeris_glo_dep_b, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgEphemerisGloDepB);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_ephemeris_glo_dep_b_t *c_struct = reinterpret_cast<const msg_ephemeris_glo_dep_b_t*>(buffer);
  const sbp::MsgEphemerisGloDepB *cpp_struct = reinterpret_cast<const sbp::MsgEphemerisGloDepB*>(buffer);

//
//  EXPECT_EQ(c_struct->common, cpp_struct->common);
//
//  EXPECT_EQ(c_struct->gamma, cpp_struct->gamma);
//
//  EXPECT_EQ(c_struct->tau, cpp_struct->tau);
//
//  EXPECT_EQ(c_struct->pos, cpp_struct->pos);
//
//  EXPECT_EQ(c_struct->vel, cpp_struct->vel);
//
//  EXPECT_EQ(c_struct->acc, cpp_struct->acc);
//
}

TEST(test_msg_ephemeris_glo_dep_c, default_construction) {
  sbp::MsgEphemerisGloDepC variable;
  (void) variable;
}

TEST(test_msg_ephemeris_glo_dep_c, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgEphemerisGloDepC);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_ephemeris_glo_dep_c_t *c_struct = reinterpret_cast<const msg_ephemeris_glo_dep_c_t*>(buffer);
  const sbp::MsgEphemerisGloDepC *cpp_struct = reinterpret_cast<const sbp::MsgEphemerisGloDepC*>(buffer);

//
//  EXPECT_EQ(c_struct->common, cpp_struct->common);
//
//  EXPECT_EQ(c_struct->gamma, cpp_struct->gamma);
//
//  EXPECT_EQ(c_struct->tau, cpp_struct->tau);
//
//  EXPECT_EQ(c_struct->d_tau, cpp_struct->d_tau);
//
//  EXPECT_EQ(c_struct->pos, cpp_struct->pos);
//
//  EXPECT_EQ(c_struct->vel, cpp_struct->vel);
//
//  EXPECT_EQ(c_struct->acc, cpp_struct->acc);
//
//  EXPECT_EQ(c_struct->fcn, cpp_struct->fcn);
//
}

TEST(test_msg_ephemeris_glo_dep_d, default_construction) {
  sbp::MsgEphemerisGloDepD variable;
  (void) variable;
}

TEST(test_msg_ephemeris_glo_dep_d, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgEphemerisGloDepD);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_ephemeris_glo_dep_d_t *c_struct = reinterpret_cast<const msg_ephemeris_glo_dep_d_t*>(buffer);
  const sbp::MsgEphemerisGloDepD *cpp_struct = reinterpret_cast<const sbp::MsgEphemerisGloDepD*>(buffer);

//
//  EXPECT_EQ(c_struct->common, cpp_struct->common);
//
//  EXPECT_EQ(c_struct->gamma, cpp_struct->gamma);
//
//  EXPECT_EQ(c_struct->tau, cpp_struct->tau);
//
//  EXPECT_EQ(c_struct->d_tau, cpp_struct->d_tau);
//
//  EXPECT_EQ(c_struct->pos, cpp_struct->pos);
//
//  EXPECT_EQ(c_struct->vel, cpp_struct->vel);
//
//  EXPECT_EQ(c_struct->acc, cpp_struct->acc);
//
//  EXPECT_EQ(c_struct->fcn, cpp_struct->fcn);
//
//  EXPECT_EQ(c_struct->iod, cpp_struct->iod);
//
}

TEST(test_msg_ephemeris_glo, default_construction) {
  sbp::MsgEphemerisGlo variable;
  (void) variable;
}

TEST(test_msg_ephemeris_glo, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgEphemerisGlo);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_ephemeris_glo_t *c_struct = reinterpret_cast<const msg_ephemeris_glo_t*>(buffer);
  const sbp::MsgEphemerisGlo *cpp_struct = reinterpret_cast<const sbp::MsgEphemerisGlo*>(buffer);

//
//  EXPECT_EQ(c_struct->common, cpp_struct->common);
//
//  EXPECT_EQ(c_struct->gamma, cpp_struct->gamma);
//
//  EXPECT_EQ(c_struct->tau, cpp_struct->tau);
//
//  EXPECT_EQ(c_struct->d_tau, cpp_struct->d_tau);
//
//  EXPECT_EQ(c_struct->pos, cpp_struct->pos);
//
//  EXPECT_EQ(c_struct->vel, cpp_struct->vel);
//
//  EXPECT_EQ(c_struct->acc, cpp_struct->acc);
//
//  EXPECT_EQ(c_struct->fcn, cpp_struct->fcn);
//
//  EXPECT_EQ(c_struct->iod, cpp_struct->iod);
//
}

TEST(test_msg_ephemeris_dep_d, default_construction) {
  sbp::MsgEphemerisDepD variable;
  (void) variable;
}

TEST(test_msg_ephemeris_dep_d, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgEphemerisDepD);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_ephemeris_dep_d_t *c_struct = reinterpret_cast<const msg_ephemeris_dep_d_t*>(buffer);
  const sbp::MsgEphemerisDepD *cpp_struct = reinterpret_cast<const sbp::MsgEphemerisDepD*>(buffer);

//
//  EXPECT_EQ(c_struct->tgd, cpp_struct->tgd);
//
//  EXPECT_EQ(c_struct->c_rs, cpp_struct->c_rs);
//
//  EXPECT_EQ(c_struct->c_rc, cpp_struct->c_rc);
//
//  EXPECT_EQ(c_struct->c_uc, cpp_struct->c_uc);
//
//  EXPECT_EQ(c_struct->c_us, cpp_struct->c_us);
//
//  EXPECT_EQ(c_struct->c_ic, cpp_struct->c_ic);
//
//  EXPECT_EQ(c_struct->c_is, cpp_struct->c_is);
//
//  EXPECT_EQ(c_struct->dn, cpp_struct->dn);
//
//  EXPECT_EQ(c_struct->m0, cpp_struct->m0);
//
//  EXPECT_EQ(c_struct->ecc, cpp_struct->ecc);
//
//  EXPECT_EQ(c_struct->sqrta, cpp_struct->sqrta);
//
//  EXPECT_EQ(c_struct->omega0, cpp_struct->omega0);
//
//  EXPECT_EQ(c_struct->omegadot, cpp_struct->omegadot);
//
//  EXPECT_EQ(c_struct->w, cpp_struct->w);
//
//  EXPECT_EQ(c_struct->inc, cpp_struct->inc);
//
//  EXPECT_EQ(c_struct->inc_dot, cpp_struct->inc_dot);
//
//  EXPECT_EQ(c_struct->af0, cpp_struct->af0);
//
//  EXPECT_EQ(c_struct->af1, cpp_struct->af1);
//
//  EXPECT_EQ(c_struct->af2, cpp_struct->af2);
//
//  EXPECT_EQ(c_struct->toe_tow, cpp_struct->toe_tow);
//
//  EXPECT_EQ(c_struct->toe_wn, cpp_struct->toe_wn);
//
//  EXPECT_EQ(c_struct->toc_tow, cpp_struct->toc_tow);
//
//  EXPECT_EQ(c_struct->toc_wn, cpp_struct->toc_wn);
//
//  EXPECT_EQ(c_struct->valid, cpp_struct->valid);
//
//  EXPECT_EQ(c_struct->healthy, cpp_struct->healthy);
//
//  EXPECT_EQ(c_struct->sid, cpp_struct->sid);
//
//  EXPECT_EQ(c_struct->iode, cpp_struct->iode);
//
//  EXPECT_EQ(c_struct->iodc, cpp_struct->iodc);
//
//  EXPECT_EQ(c_struct->reserved, cpp_struct->reserved);
//
}

TEST(test_msg_ephemeris_dep_a, default_construction) {
  sbp::MsgEphemerisDepA variable;
  (void) variable;
}

TEST(test_msg_ephemeris_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgEphemerisDepA);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_ephemeris_dep_a_t *c_struct = reinterpret_cast<const msg_ephemeris_dep_a_t*>(buffer);
  const sbp::MsgEphemerisDepA *cpp_struct = reinterpret_cast<const sbp::MsgEphemerisDepA*>(buffer);

//
//  EXPECT_EQ(c_struct->tgd, cpp_struct->tgd);
//
//  EXPECT_EQ(c_struct->c_rs, cpp_struct->c_rs);
//
//  EXPECT_EQ(c_struct->c_rc, cpp_struct->c_rc);
//
//  EXPECT_EQ(c_struct->c_uc, cpp_struct->c_uc);
//
//  EXPECT_EQ(c_struct->c_us, cpp_struct->c_us);
//
//  EXPECT_EQ(c_struct->c_ic, cpp_struct->c_ic);
//
//  EXPECT_EQ(c_struct->c_is, cpp_struct->c_is);
//
//  EXPECT_EQ(c_struct->dn, cpp_struct->dn);
//
//  EXPECT_EQ(c_struct->m0, cpp_struct->m0);
//
//  EXPECT_EQ(c_struct->ecc, cpp_struct->ecc);
//
//  EXPECT_EQ(c_struct->sqrta, cpp_struct->sqrta);
//
//  EXPECT_EQ(c_struct->omega0, cpp_struct->omega0);
//
//  EXPECT_EQ(c_struct->omegadot, cpp_struct->omegadot);
//
//  EXPECT_EQ(c_struct->w, cpp_struct->w);
//
//  EXPECT_EQ(c_struct->inc, cpp_struct->inc);
//
//  EXPECT_EQ(c_struct->inc_dot, cpp_struct->inc_dot);
//
//  EXPECT_EQ(c_struct->af0, cpp_struct->af0);
//
//  EXPECT_EQ(c_struct->af1, cpp_struct->af1);
//
//  EXPECT_EQ(c_struct->af2, cpp_struct->af2);
//
//  EXPECT_EQ(c_struct->toe_tow, cpp_struct->toe_tow);
//
//  EXPECT_EQ(c_struct->toe_wn, cpp_struct->toe_wn);
//
//  EXPECT_EQ(c_struct->toc_tow, cpp_struct->toc_tow);
//
//  EXPECT_EQ(c_struct->toc_wn, cpp_struct->toc_wn);
//
//  EXPECT_EQ(c_struct->valid, cpp_struct->valid);
//
//  EXPECT_EQ(c_struct->healthy, cpp_struct->healthy);
//
//  EXPECT_EQ(c_struct->prn, cpp_struct->prn);
//
}

TEST(test_msg_ephemeris_dep_b, default_construction) {
  sbp::MsgEphemerisDepB variable;
  (void) variable;
}

TEST(test_msg_ephemeris_dep_b, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgEphemerisDepB);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_ephemeris_dep_b_t *c_struct = reinterpret_cast<const msg_ephemeris_dep_b_t*>(buffer);
  const sbp::MsgEphemerisDepB *cpp_struct = reinterpret_cast<const sbp::MsgEphemerisDepB*>(buffer);

//
//  EXPECT_EQ(c_struct->tgd, cpp_struct->tgd);
//
//  EXPECT_EQ(c_struct->c_rs, cpp_struct->c_rs);
//
//  EXPECT_EQ(c_struct->c_rc, cpp_struct->c_rc);
//
//  EXPECT_EQ(c_struct->c_uc, cpp_struct->c_uc);
//
//  EXPECT_EQ(c_struct->c_us, cpp_struct->c_us);
//
//  EXPECT_EQ(c_struct->c_ic, cpp_struct->c_ic);
//
//  EXPECT_EQ(c_struct->c_is, cpp_struct->c_is);
//
//  EXPECT_EQ(c_struct->dn, cpp_struct->dn);
//
//  EXPECT_EQ(c_struct->m0, cpp_struct->m0);
//
//  EXPECT_EQ(c_struct->ecc, cpp_struct->ecc);
//
//  EXPECT_EQ(c_struct->sqrta, cpp_struct->sqrta);
//
//  EXPECT_EQ(c_struct->omega0, cpp_struct->omega0);
//
//  EXPECT_EQ(c_struct->omegadot, cpp_struct->omegadot);
//
//  EXPECT_EQ(c_struct->w, cpp_struct->w);
//
//  EXPECT_EQ(c_struct->inc, cpp_struct->inc);
//
//  EXPECT_EQ(c_struct->inc_dot, cpp_struct->inc_dot);
//
//  EXPECT_EQ(c_struct->af0, cpp_struct->af0);
//
//  EXPECT_EQ(c_struct->af1, cpp_struct->af1);
//
//  EXPECT_EQ(c_struct->af2, cpp_struct->af2);
//
//  EXPECT_EQ(c_struct->toe_tow, cpp_struct->toe_tow);
//
//  EXPECT_EQ(c_struct->toe_wn, cpp_struct->toe_wn);
//
//  EXPECT_EQ(c_struct->toc_tow, cpp_struct->toc_tow);
//
//  EXPECT_EQ(c_struct->toc_wn, cpp_struct->toc_wn);
//
//  EXPECT_EQ(c_struct->valid, cpp_struct->valid);
//
//  EXPECT_EQ(c_struct->healthy, cpp_struct->healthy);
//
//  EXPECT_EQ(c_struct->prn, cpp_struct->prn);
//
//  EXPECT_EQ(c_struct->iode, cpp_struct->iode);
//
}

TEST(test_msg_ephemeris_dep_c, default_construction) {
  sbp::MsgEphemerisDepC variable;
  (void) variable;
}

TEST(test_msg_ephemeris_dep_c, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgEphemerisDepC);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_ephemeris_dep_c_t *c_struct = reinterpret_cast<const msg_ephemeris_dep_c_t*>(buffer);
  const sbp::MsgEphemerisDepC *cpp_struct = reinterpret_cast<const sbp::MsgEphemerisDepC*>(buffer);

//
//  EXPECT_EQ(c_struct->tgd, cpp_struct->tgd);
//
//  EXPECT_EQ(c_struct->c_rs, cpp_struct->c_rs);
//
//  EXPECT_EQ(c_struct->c_rc, cpp_struct->c_rc);
//
//  EXPECT_EQ(c_struct->c_uc, cpp_struct->c_uc);
//
//  EXPECT_EQ(c_struct->c_us, cpp_struct->c_us);
//
//  EXPECT_EQ(c_struct->c_ic, cpp_struct->c_ic);
//
//  EXPECT_EQ(c_struct->c_is, cpp_struct->c_is);
//
//  EXPECT_EQ(c_struct->dn, cpp_struct->dn);
//
//  EXPECT_EQ(c_struct->m0, cpp_struct->m0);
//
//  EXPECT_EQ(c_struct->ecc, cpp_struct->ecc);
//
//  EXPECT_EQ(c_struct->sqrta, cpp_struct->sqrta);
//
//  EXPECT_EQ(c_struct->omega0, cpp_struct->omega0);
//
//  EXPECT_EQ(c_struct->omegadot, cpp_struct->omegadot);
//
//  EXPECT_EQ(c_struct->w, cpp_struct->w);
//
//  EXPECT_EQ(c_struct->inc, cpp_struct->inc);
//
//  EXPECT_EQ(c_struct->inc_dot, cpp_struct->inc_dot);
//
//  EXPECT_EQ(c_struct->af0, cpp_struct->af0);
//
//  EXPECT_EQ(c_struct->af1, cpp_struct->af1);
//
//  EXPECT_EQ(c_struct->af2, cpp_struct->af2);
//
//  EXPECT_EQ(c_struct->toe_tow, cpp_struct->toe_tow);
//
//  EXPECT_EQ(c_struct->toe_wn, cpp_struct->toe_wn);
//
//  EXPECT_EQ(c_struct->toc_tow, cpp_struct->toc_tow);
//
//  EXPECT_EQ(c_struct->toc_wn, cpp_struct->toc_wn);
//
//  EXPECT_EQ(c_struct->valid, cpp_struct->valid);
//
//  EXPECT_EQ(c_struct->healthy, cpp_struct->healthy);
//
//  EXPECT_EQ(c_struct->sid, cpp_struct->sid);
//
//  EXPECT_EQ(c_struct->iode, cpp_struct->iode);
//
//  EXPECT_EQ(c_struct->iodc, cpp_struct->iodc);
//
//  EXPECT_EQ(c_struct->reserved, cpp_struct->reserved);
//
}

TEST(test_observation_header_dep, default_construction) {
  sbp::ObservationHeaderDep variable;
  (void) variable;
}

TEST(test_observation_header_dep, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::ObservationHeaderDep);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const observation_header_dep_t *c_struct = reinterpret_cast<const observation_header_dep_t*>(buffer);
  const sbp::ObservationHeaderDep *cpp_struct = reinterpret_cast<const sbp::ObservationHeaderDep*>(buffer);

//
//  EXPECT_EQ(c_struct->t, cpp_struct->t);
//
//  EXPECT_EQ(c_struct->n_obs, cpp_struct->n_obs);
//
}

TEST(test_carrier_phase_dep_a, default_construction) {
  sbp::CarrierPhaseDepA variable;
  (void) variable;
}

TEST(test_carrier_phase_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::CarrierPhaseDepA);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const carrier_phase_dep_a_t *c_struct = reinterpret_cast<const carrier_phase_dep_a_t*>(buffer);
  const sbp::CarrierPhaseDepA *cpp_struct = reinterpret_cast<const sbp::CarrierPhaseDepA*>(buffer);

//
//  EXPECT_EQ(c_struct->i, cpp_struct->i);
//
//  EXPECT_EQ(c_struct->f, cpp_struct->f);
//
}

TEST(test_packed_obs_content_dep_a, default_construction) {
  sbp::PackedObsContentDepA variable;
  (void) variable;
}

TEST(test_packed_obs_content_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::PackedObsContentDepA);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const packed_obs_content_dep_a_t *c_struct = reinterpret_cast<const packed_obs_content_dep_a_t*>(buffer);
  const sbp::PackedObsContentDepA *cpp_struct = reinterpret_cast<const sbp::PackedObsContentDepA*>(buffer);

//
//  EXPECT_EQ(c_struct->P, cpp_struct->P);
//
//  EXPECT_EQ(c_struct->L, cpp_struct->L);
//
//  EXPECT_EQ(c_struct->cn0, cpp_struct->cn0);
//
//  EXPECT_EQ(c_struct->lock, cpp_struct->lock);
//
//  EXPECT_EQ(c_struct->prn, cpp_struct->prn);
//
}

TEST(test_packed_obs_content_dep_b, default_construction) {
  sbp::PackedObsContentDepB variable;
  (void) variable;
}

TEST(test_packed_obs_content_dep_b, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::PackedObsContentDepB);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const packed_obs_content_dep_b_t *c_struct = reinterpret_cast<const packed_obs_content_dep_b_t*>(buffer);
  const sbp::PackedObsContentDepB *cpp_struct = reinterpret_cast<const sbp::PackedObsContentDepB*>(buffer);

//
//  EXPECT_EQ(c_struct->P, cpp_struct->P);
//
//  EXPECT_EQ(c_struct->L, cpp_struct->L);
//
//  EXPECT_EQ(c_struct->cn0, cpp_struct->cn0);
//
//  EXPECT_EQ(c_struct->lock, cpp_struct->lock);
//
//  EXPECT_EQ(c_struct->sid, cpp_struct->sid);
//
}

TEST(test_packed_obs_content_dep_c, default_construction) {
  sbp::PackedObsContentDepC variable;
  (void) variable;
}

TEST(test_packed_obs_content_dep_c, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::PackedObsContentDepC);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const packed_obs_content_dep_c_t *c_struct = reinterpret_cast<const packed_obs_content_dep_c_t*>(buffer);
  const sbp::PackedObsContentDepC *cpp_struct = reinterpret_cast<const sbp::PackedObsContentDepC*>(buffer);

//
//  EXPECT_EQ(c_struct->P, cpp_struct->P);
//
//  EXPECT_EQ(c_struct->L, cpp_struct->L);
//
//  EXPECT_EQ(c_struct->cn0, cpp_struct->cn0);
//
//  EXPECT_EQ(c_struct->lock, cpp_struct->lock);
//
//  EXPECT_EQ(c_struct->sid, cpp_struct->sid);
//
}

TEST(test_msg_obs_dep_a, default_construction) {
  sbp::MsgObsDepA<> variable;
  (void) variable;
}

TEST(test_msg_obs_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgObsDepA<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_obs_dep_a_t *c_struct = reinterpret_cast<const msg_obs_dep_a_t*>(buffer);
  const sbp::MsgObsDepA<> *cpp_struct = reinterpret_cast<const sbp::MsgObsDepA<>*>(buffer);

//
//  EXPECT_EQ(c_struct->header, cpp_struct->header);
//
//  EXPECT_EQ(c_struct->obs, cpp_struct->obs);
//
}

TEST(test_msg_obs_dep_b, default_construction) {
  sbp::MsgObsDepB<> variable;
  (void) variable;
}

TEST(test_msg_obs_dep_b, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgObsDepB<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_obs_dep_b_t *c_struct = reinterpret_cast<const msg_obs_dep_b_t*>(buffer);
  const sbp::MsgObsDepB<> *cpp_struct = reinterpret_cast<const sbp::MsgObsDepB<>*>(buffer);

//
//  EXPECT_EQ(c_struct->header, cpp_struct->header);
//
//  EXPECT_EQ(c_struct->obs, cpp_struct->obs);
//
}

TEST(test_msg_obs_dep_c, default_construction) {
  sbp::MsgObsDepC<> variable;
  (void) variable;
}

TEST(test_msg_obs_dep_c, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgObsDepC<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_obs_dep_c_t *c_struct = reinterpret_cast<const msg_obs_dep_c_t*>(buffer);
  const sbp::MsgObsDepC<> *cpp_struct = reinterpret_cast<const sbp::MsgObsDepC<>*>(buffer);

//
//  EXPECT_EQ(c_struct->header, cpp_struct->header);
//
//  EXPECT_EQ(c_struct->obs, cpp_struct->obs);
//
}

TEST(test_msg_iono, default_construction) {
  sbp::MsgIono variable;
  (void) variable;
}

TEST(test_msg_iono, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgIono);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_iono_t *c_struct = reinterpret_cast<const msg_iono_t*>(buffer);
  const sbp::MsgIono *cpp_struct = reinterpret_cast<const sbp::MsgIono*>(buffer);

//
//  EXPECT_EQ(c_struct->t_nmct, cpp_struct->t_nmct);
//
//  EXPECT_EQ(c_struct->a0, cpp_struct->a0);
//
//  EXPECT_EQ(c_struct->a1, cpp_struct->a1);
//
//  EXPECT_EQ(c_struct->a2, cpp_struct->a2);
//
//  EXPECT_EQ(c_struct->a3, cpp_struct->a3);
//
//  EXPECT_EQ(c_struct->b0, cpp_struct->b0);
//
//  EXPECT_EQ(c_struct->b1, cpp_struct->b1);
//
//  EXPECT_EQ(c_struct->b2, cpp_struct->b2);
//
//  EXPECT_EQ(c_struct->b3, cpp_struct->b3);
//
}

TEST(test_msg_sv_configuration_gps_dep, default_construction) {
  sbp::MsgSvConfigurationGpsDep variable;
  (void) variable;
}

TEST(test_msg_sv_configuration_gps_dep, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgSvConfigurationGpsDep);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_sv_configuration_gps_dep_t *c_struct = reinterpret_cast<const msg_sv_configuration_gps_dep_t*>(buffer);
  const sbp::MsgSvConfigurationGpsDep *cpp_struct = reinterpret_cast<const sbp::MsgSvConfigurationGpsDep*>(buffer);

//
//  EXPECT_EQ(c_struct->t_nmct, cpp_struct->t_nmct);
//
//  EXPECT_EQ(c_struct->l2c_mask, cpp_struct->l2c_mask);
//
}

TEST(test_gnss_capb, default_construction) {
  sbp::GnssCapb variable;
  (void) variable;
}

TEST(test_gnss_capb, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::GnssCapb);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const gnss_capb_t *c_struct = reinterpret_cast<const gnss_capb_t*>(buffer);
  const sbp::GnssCapb *cpp_struct = reinterpret_cast<const sbp::GnssCapb*>(buffer);

//
//  EXPECT_EQ(c_struct->gps_active, cpp_struct->gps_active);
//
//  EXPECT_EQ(c_struct->gps_l2c, cpp_struct->gps_l2c);
//
//  EXPECT_EQ(c_struct->gps_l5, cpp_struct->gps_l5);
//
//  EXPECT_EQ(c_struct->glo_active, cpp_struct->glo_active);
//
//  EXPECT_EQ(c_struct->glo_l2of, cpp_struct->glo_l2of);
//
//  EXPECT_EQ(c_struct->glo_l3, cpp_struct->glo_l3);
//
//  EXPECT_EQ(c_struct->sbas_active, cpp_struct->sbas_active);
//
//  EXPECT_EQ(c_struct->sbas_l5, cpp_struct->sbas_l5);
//
//  EXPECT_EQ(c_struct->bds_active, cpp_struct->bds_active);
//
//  EXPECT_EQ(c_struct->bds_d2nav, cpp_struct->bds_d2nav);
//
//  EXPECT_EQ(c_struct->bds_b2, cpp_struct->bds_b2);
//
//  EXPECT_EQ(c_struct->bds_b2a, cpp_struct->bds_b2a);
//
//  EXPECT_EQ(c_struct->qzss_active, cpp_struct->qzss_active);
//
//  EXPECT_EQ(c_struct->gal_active, cpp_struct->gal_active);
//
//  EXPECT_EQ(c_struct->gal_e5, cpp_struct->gal_e5);
//
}

TEST(test_msg_gnss_capb, default_construction) {
  sbp::MsgGnssCapb variable;
  (void) variable;
}

TEST(test_msg_gnss_capb, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgGnssCapb);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_gnss_capb_t *c_struct = reinterpret_cast<const msg_gnss_capb_t*>(buffer);
  const sbp::MsgGnssCapb *cpp_struct = reinterpret_cast<const sbp::MsgGnssCapb*>(buffer);

//
//  EXPECT_EQ(c_struct->t_nmct, cpp_struct->t_nmct);
//
//  EXPECT_EQ(c_struct->gc, cpp_struct->gc);
//
}

TEST(test_msg_group_delay_dep_a, default_construction) {
  sbp::MsgGroupDelayDepA variable;
  (void) variable;
}

TEST(test_msg_group_delay_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgGroupDelayDepA);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_group_delay_dep_a_t *c_struct = reinterpret_cast<const msg_group_delay_dep_a_t*>(buffer);
  const sbp::MsgGroupDelayDepA *cpp_struct = reinterpret_cast<const sbp::MsgGroupDelayDepA*>(buffer);

//
//  EXPECT_EQ(c_struct->t_op, cpp_struct->t_op);
//
//  EXPECT_EQ(c_struct->prn, cpp_struct->prn);
//
//  EXPECT_EQ(c_struct->valid, cpp_struct->valid);
//
//  EXPECT_EQ(c_struct->tgd, cpp_struct->tgd);
//
//  EXPECT_EQ(c_struct->isc_l1ca, cpp_struct->isc_l1ca);
//
//  EXPECT_EQ(c_struct->isc_l2c, cpp_struct->isc_l2c);
//
}

TEST(test_msg_group_delay_dep_b, default_construction) {
  sbp::MsgGroupDelayDepB variable;
  (void) variable;
}

TEST(test_msg_group_delay_dep_b, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgGroupDelayDepB);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_group_delay_dep_b_t *c_struct = reinterpret_cast<const msg_group_delay_dep_b_t*>(buffer);
  const sbp::MsgGroupDelayDepB *cpp_struct = reinterpret_cast<const sbp::MsgGroupDelayDepB*>(buffer);

//
//  EXPECT_EQ(c_struct->t_op, cpp_struct->t_op);
//
//  EXPECT_EQ(c_struct->sid, cpp_struct->sid);
//
//  EXPECT_EQ(c_struct->valid, cpp_struct->valid);
//
//  EXPECT_EQ(c_struct->tgd, cpp_struct->tgd);
//
//  EXPECT_EQ(c_struct->isc_l1ca, cpp_struct->isc_l1ca);
//
//  EXPECT_EQ(c_struct->isc_l2c, cpp_struct->isc_l2c);
//
}

TEST(test_msg_group_delay, default_construction) {
  sbp::MsgGroupDelay variable;
  (void) variable;
}

TEST(test_msg_group_delay, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgGroupDelay);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_group_delay_t *c_struct = reinterpret_cast<const msg_group_delay_t*>(buffer);
  const sbp::MsgGroupDelay *cpp_struct = reinterpret_cast<const sbp::MsgGroupDelay*>(buffer);

//
//  EXPECT_EQ(c_struct->t_op, cpp_struct->t_op);
//
//  EXPECT_EQ(c_struct->sid, cpp_struct->sid);
//
//  EXPECT_EQ(c_struct->valid, cpp_struct->valid);
//
//  EXPECT_EQ(c_struct->tgd, cpp_struct->tgd);
//
//  EXPECT_EQ(c_struct->isc_l1ca, cpp_struct->isc_l1ca);
//
//  EXPECT_EQ(c_struct->isc_l2c, cpp_struct->isc_l2c);
//
}

TEST(test_almanac_common_content, default_construction) {
  sbp::AlmanacCommonContent variable;
  (void) variable;
}

TEST(test_almanac_common_content, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::AlmanacCommonContent);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const almanac_common_content_t *c_struct = reinterpret_cast<const almanac_common_content_t*>(buffer);
  const sbp::AlmanacCommonContent *cpp_struct = reinterpret_cast<const sbp::AlmanacCommonContent*>(buffer);

//
//  EXPECT_EQ(c_struct->sid, cpp_struct->sid);
//
//  EXPECT_EQ(c_struct->toa, cpp_struct->toa);
//
//  EXPECT_EQ(c_struct->ura, cpp_struct->ura);
//
//  EXPECT_EQ(c_struct->fit_interval, cpp_struct->fit_interval);
//
//  EXPECT_EQ(c_struct->valid, cpp_struct->valid);
//
//  EXPECT_EQ(c_struct->health_bits, cpp_struct->health_bits);
//
}

TEST(test_almanac_common_content_dep, default_construction) {
  sbp::AlmanacCommonContentDep variable;
  (void) variable;
}

TEST(test_almanac_common_content_dep, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::AlmanacCommonContentDep);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const almanac_common_content_dep_t *c_struct = reinterpret_cast<const almanac_common_content_dep_t*>(buffer);
  const sbp::AlmanacCommonContentDep *cpp_struct = reinterpret_cast<const sbp::AlmanacCommonContentDep*>(buffer);

//
//  EXPECT_EQ(c_struct->sid, cpp_struct->sid);
//
//  EXPECT_EQ(c_struct->toa, cpp_struct->toa);
//
//  EXPECT_EQ(c_struct->ura, cpp_struct->ura);
//
//  EXPECT_EQ(c_struct->fit_interval, cpp_struct->fit_interval);
//
//  EXPECT_EQ(c_struct->valid, cpp_struct->valid);
//
//  EXPECT_EQ(c_struct->health_bits, cpp_struct->health_bits);
//
}

TEST(test_msg_almanac_gps_dep, default_construction) {
  sbp::MsgAlmanacGpsDep variable;
  (void) variable;
}

TEST(test_msg_almanac_gps_dep, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgAlmanacGpsDep);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_almanac_gps_dep_t *c_struct = reinterpret_cast<const msg_almanac_gps_dep_t*>(buffer);
  const sbp::MsgAlmanacGpsDep *cpp_struct = reinterpret_cast<const sbp::MsgAlmanacGpsDep*>(buffer);

//
//  EXPECT_EQ(c_struct->common, cpp_struct->common);
//
//  EXPECT_EQ(c_struct->m0, cpp_struct->m0);
//
//  EXPECT_EQ(c_struct->ecc, cpp_struct->ecc);
//
//  EXPECT_EQ(c_struct->sqrta, cpp_struct->sqrta);
//
//  EXPECT_EQ(c_struct->omega0, cpp_struct->omega0);
//
//  EXPECT_EQ(c_struct->omegadot, cpp_struct->omegadot);
//
//  EXPECT_EQ(c_struct->w, cpp_struct->w);
//
//  EXPECT_EQ(c_struct->inc, cpp_struct->inc);
//
//  EXPECT_EQ(c_struct->af0, cpp_struct->af0);
//
//  EXPECT_EQ(c_struct->af1, cpp_struct->af1);
//
}

TEST(test_msg_almanac_gps, default_construction) {
  sbp::MsgAlmanacGps variable;
  (void) variable;
}

TEST(test_msg_almanac_gps, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgAlmanacGps);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_almanac_gps_t *c_struct = reinterpret_cast<const msg_almanac_gps_t*>(buffer);
  const sbp::MsgAlmanacGps *cpp_struct = reinterpret_cast<const sbp::MsgAlmanacGps*>(buffer);

//
//  EXPECT_EQ(c_struct->common, cpp_struct->common);
//
//  EXPECT_EQ(c_struct->m0, cpp_struct->m0);
//
//  EXPECT_EQ(c_struct->ecc, cpp_struct->ecc);
//
//  EXPECT_EQ(c_struct->sqrta, cpp_struct->sqrta);
//
//  EXPECT_EQ(c_struct->omega0, cpp_struct->omega0);
//
//  EXPECT_EQ(c_struct->omegadot, cpp_struct->omegadot);
//
//  EXPECT_EQ(c_struct->w, cpp_struct->w);
//
//  EXPECT_EQ(c_struct->inc, cpp_struct->inc);
//
//  EXPECT_EQ(c_struct->af0, cpp_struct->af0);
//
//  EXPECT_EQ(c_struct->af1, cpp_struct->af1);
//
}

TEST(test_msg_almanac_glo_dep, default_construction) {
  sbp::MsgAlmanacGloDep variable;
  (void) variable;
}

TEST(test_msg_almanac_glo_dep, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgAlmanacGloDep);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_almanac_glo_dep_t *c_struct = reinterpret_cast<const msg_almanac_glo_dep_t*>(buffer);
  const sbp::MsgAlmanacGloDep *cpp_struct = reinterpret_cast<const sbp::MsgAlmanacGloDep*>(buffer);

//
//  EXPECT_EQ(c_struct->common, cpp_struct->common);
//
//  EXPECT_EQ(c_struct->lambda_na, cpp_struct->lambda_na);
//
//  EXPECT_EQ(c_struct->t_lambda_na, cpp_struct->t_lambda_na);
//
//  EXPECT_EQ(c_struct->i, cpp_struct->i);
//
//  EXPECT_EQ(c_struct->t, cpp_struct->t);
//
//  EXPECT_EQ(c_struct->t_dot, cpp_struct->t_dot);
//
//  EXPECT_EQ(c_struct->epsilon, cpp_struct->epsilon);
//
//  EXPECT_EQ(c_struct->omega, cpp_struct->omega);
//
}

TEST(test_msg_almanac_glo, default_construction) {
  sbp::MsgAlmanacGlo variable;
  (void) variable;
}

TEST(test_msg_almanac_glo, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgAlmanacGlo);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_almanac_glo_t *c_struct = reinterpret_cast<const msg_almanac_glo_t*>(buffer);
  const sbp::MsgAlmanacGlo *cpp_struct = reinterpret_cast<const sbp::MsgAlmanacGlo*>(buffer);

//
//  EXPECT_EQ(c_struct->common, cpp_struct->common);
//
//  EXPECT_EQ(c_struct->lambda_na, cpp_struct->lambda_na);
//
//  EXPECT_EQ(c_struct->t_lambda_na, cpp_struct->t_lambda_na);
//
//  EXPECT_EQ(c_struct->i, cpp_struct->i);
//
//  EXPECT_EQ(c_struct->t, cpp_struct->t);
//
//  EXPECT_EQ(c_struct->t_dot, cpp_struct->t_dot);
//
//  EXPECT_EQ(c_struct->epsilon, cpp_struct->epsilon);
//
//  EXPECT_EQ(c_struct->omega, cpp_struct->omega);
//
}

TEST(test_msg_glo_biases, default_construction) {
  sbp::MsgGloBiases variable;
  (void) variable;
}

TEST(test_msg_glo_biases, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgGloBiases);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_glo_biases_t *c_struct = reinterpret_cast<const msg_glo_biases_t*>(buffer);
  const sbp::MsgGloBiases *cpp_struct = reinterpret_cast<const sbp::MsgGloBiases*>(buffer);

//
//  EXPECT_EQ(c_struct->mask, cpp_struct->mask);
//
//  EXPECT_EQ(c_struct->l1ca_bias, cpp_struct->l1ca_bias);
//
//  EXPECT_EQ(c_struct->l1p_bias, cpp_struct->l1p_bias);
//
//  EXPECT_EQ(c_struct->l2ca_bias, cpp_struct->l2ca_bias);
//
//  EXPECT_EQ(c_struct->l2p_bias, cpp_struct->l2p_bias);
//
}

TEST(test_sv_az_el, default_construction) {
  sbp::SvAzEl variable;
  (void) variable;
}

TEST(test_sv_az_el, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::SvAzEl);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const sv_az_el_t *c_struct = reinterpret_cast<const sv_az_el_t*>(buffer);
  const sbp::SvAzEl *cpp_struct = reinterpret_cast<const sbp::SvAzEl*>(buffer);

//
//  EXPECT_EQ(c_struct->sid, cpp_struct->sid);
//
//  EXPECT_EQ(c_struct->az, cpp_struct->az);
//
//  EXPECT_EQ(c_struct->el, cpp_struct->el);
//
}

TEST(test_msg_sv_az_el, default_construction) {
  sbp::MsgSvAzEl<> variable;
  (void) variable;
}

TEST(test_msg_sv_az_el, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgSvAzEl<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_sv_az_el_t *c_struct = reinterpret_cast<const msg_sv_az_el_t*>(buffer);
  const sbp::MsgSvAzEl<> *cpp_struct = reinterpret_cast<const sbp::MsgSvAzEl<>*>(buffer);

//
//  EXPECT_EQ(c_struct->azel, cpp_struct->azel);
//
}

TEST(test_msg_osr, default_construction) {
  sbp::MsgOsr<> variable;
  (void) variable;
}

TEST(test_msg_osr, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgOsr<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_osr_t *c_struct = reinterpret_cast<const msg_osr_t*>(buffer);
  const sbp::MsgOsr<> *cpp_struct = reinterpret_cast<const sbp::MsgOsr<>*>(buffer);

//
//  EXPECT_EQ(c_struct->header, cpp_struct->header);
//
//  EXPECT_EQ(c_struct->obs, cpp_struct->obs);
//
}
