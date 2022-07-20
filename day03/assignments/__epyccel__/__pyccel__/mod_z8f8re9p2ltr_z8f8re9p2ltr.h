#ifndef MOD_Z8F8RE9P2LTR_Z8F8RE9P2LTR_H
#define MOD_Z8F8RE9P2LTR_Z8F8RE9P2LTR_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t matrix_prod(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M, int64_t threads);
#endif // MOD_Z8F8RE9P2LTR_Z8F8RE9P2LTR_H
