#ifndef MOD_RZKPPP5FXE8A_RZKPPP5FXE8A_H
#define MOD_RZKPPP5FXE8A_RZKPPP5FXE8A_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t matrix_prod(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M, int64_t threads);
#endif // MOD_RZKPPP5FXE8A_RZKPPP5FXE8A_H
