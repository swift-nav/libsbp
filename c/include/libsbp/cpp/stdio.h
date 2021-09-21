/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
#ifndef SBP_CPP_STDIO_H
#define SBP_CPP_STDIO_H

#include <iomanip>
#include <iostream>
#include <fstream>

#include <libsbp/cpp/state.h>

namespace sbp {

  class SbpStreamReader : public sbp::IReader {
  public:
    explicit SbpStreamReader(std::istream &in_stream) : in_stream_(in_stream) {}

    s32 read(u8 *buffer, u32 buffer_length) override {
      if (in_stream_.read(reinterpret_cast<char *>(buffer),  // NOLINT
                          buffer_length)) {                  // NOLINT
        return static_cast<s32>(in_stream_.gcount());        // NOLINT
      } else if (in_stream_.fail()) {                        // NOLINT
        return -1;
      } else {          // NOLINT
        // something's wrong with the stream
        exit(EXIT_FAILURE);
      }
    }

  private:
    std::istream &in_stream_;
  };

  class SbpFileReader : public SbpStreamReader {
  public:
    SbpFileReader(const std::string &path)
        : SbpStreamReader{ifstream_}, ifstream_{} {
      ifstream_.open(path, std::ios::in | std::ios::binary);
    };

    bool is_open() const { return ifstream_.is_open(); };

  private:
    std::ifstream ifstream_;
  };

  class SbpStreamWriter : public sbp::IWriter {
  public:
    explicit SbpStreamWriter(std::ostream &out_stream)
        : out_stream_(out_stream) {}

    s32 write(const u8 *buffer, u32 buffer_length) override {
      if (out_stream_.write(reinterpret_cast<const char *>(buffer),  // NOLINT
                            buffer_length)) {
        return static_cast<s32>(buffer_length);  // NOLINT
      } else if (out_stream_.fail()) {           // NOLINT
        return -1;
      } else {          // NOLINT
        // something's wrong with the stream
        exit(EXIT_FAILURE);
      }
    }

  private:
    std::ostream &out_stream_;
  };

  class SbpFileWriter : public SbpStreamWriter {
  public:
    SbpFileWriter(const std::string &path)
        : SbpStreamWriter{ofstream_}, ofstream_{} {
      ofstream_.open(path, std::ios::out | std::ios::binary);
    };

  private:
    std::ofstream ofstream_;
  };

} // namespace sbp

#endif  // SBP_CPP_STDIO_H

