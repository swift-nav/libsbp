/**
 * Copyright (C) 2020-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef SBP_LEGACY_CPP_STDIO_H
#define SBP_LEGACY_CPP_STDIO_H

#include <fstream>

#include <libsbp/legacy/cpp/payload_handler.h>

namespace sbp {

class SbpFileReader : public sbp::IReader {
  public:
    explicit SbpFileReader(const char *file_path)
      : file_stream_(file_path, std::ios::binary | std::ios_base::in) {}

    bool is_open() const { return file_stream_.is_open(); }

    bool eof() const { return file_stream_.eof(); }

    s32 read(u8 *buffer, const u32 buffer_length) override {
      auto start_index = file_stream_.tellg();
      if (start_index == -1) {
        return -1;
      }

      // NOLINTNEXTLINE
      file_stream_.read(reinterpret_cast<char *>(buffer), buffer_length);
      auto end_index = file_stream_.tellg();
      if (end_index == -1 || file_stream_.fail()) {
        return -1;
      }

      return static_cast<s32>(end_index - start_index);
    }

  private:
    std::ifstream file_stream_;
};

class SbpFileWriter : public sbp::IWriter {
  public:
    explicit SbpFileWriter(const char *file_path)
      : file_stream_(file_path, std::ios::binary | std::ios_base::out) {}

    bool is_open() const { return file_stream_.is_open(); };

    bool eof() const { return file_stream_.eof(); }

    s32 write(const u8 *buffer, const u32 buffer_length) override {
      // NOLINTNEXTLINE
      file_stream_.write(reinterpret_cast<const char *>(buffer), buffer_length);
      return static_cast<s32>(buffer_length);
    }

  private:
    std::ofstream file_stream_;
};

} // namespace sbp

#endif // SBP_LEGACY_CPP_STDIO_H
