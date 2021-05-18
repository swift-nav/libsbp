#ifndef LIBSBP_UNPACKED_(((pkg_name|upper)))_PRIVATE_H
#define LIBSBP_UNPACKED_(((pkg_name|upper)))_PRIVATE_H

#include <stdbool.h>

#include <libsbp/internal/common.h>

((*- for i in include *))
#include <libsbp/internal/unpacked/(((i))).h>
((*- endfor *))

((*- for m in msgs *))

bool pack_(((m.name|convert_unpacked)))(sbp_pack_ctx_t *ctx, const (((m.name|convert_unpacked))) *msg);
bool unpack_(((m.name|convert_unpacked)))(sbp_unpack_ctx_t *ctx, (((m.name|convert_unpacked))) *msg);

((*- endfor *))
