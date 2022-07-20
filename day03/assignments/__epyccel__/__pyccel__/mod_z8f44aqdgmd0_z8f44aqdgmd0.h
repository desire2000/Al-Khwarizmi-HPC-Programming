#ifndef MOD_Z8F44AQDGMD0_Z8F44AQDGMD0_H
#define MOD_Z8F44AQDGMD0_Z8F44AQDGMD0_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t matrix_prod(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M, int64_t threads);
#endif // MOD_Z8F44AQDGMD0_Z8F44AQDGMD0_H
