#ifndef LIBSBP_UNPACKED_(((pkg_name|upper)))_PRIVATE_H
#define LIBSBP_UNPACKED_(((pkg_name|upper)))_PRIVATE_H

#include <stdbool.h>

#include <libsbp/new/(((pkg_name))).h>
#include <libsbp/internal/new/common.h>
((*- for i in include *))
#include <libsbp/internal/new/(((i)))>
((*- endfor *))

#ifdef __cplusplus
  extern "C" {
#endif

((*- for m in msgs *))

bool encode_(((m.name|convert_unpacked)))(sbp_encode_ctx_t *ctx, const (((m.name|convert_unpacked))) *msg);
bool decode_(((m.name|convert_unpacked)))(sbp_decode_ctx_t *ctx, (((m.name|convert_unpacked))) *msg);

((*- endfor *))

#ifdef __cplusplus
  }
#endif

#endif

