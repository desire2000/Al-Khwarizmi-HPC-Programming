#ifndef MOD_KGGC55X5FDFS_KGGC55X5FDFS_H
#define MOD_KGGC55X5FDFS_KGGC55X5FDFS_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t matrix_prod(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M, int64_t threads);
#endif // MOD_KGGC55X5FDFS_KGGC55X5FDFS_H
