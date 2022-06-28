#ifndef MOD_SH9WL5R0RM3K_SH9WL5R0RM3K_H
#define MOD_SH9WL5R0RM3K_SH9WL5R0RM3K_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t matrix_prod(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M, int64_t threads);
#endif // MOD_SH9WL5R0RM3K_SH9WL5R0RM3K_H
