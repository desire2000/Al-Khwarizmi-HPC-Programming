#ifndef MATRIX_PROD_OVNMPJ6P6VX9_OVNMPJ6P6VX9_H
#define MATRIX_PROD_OVNMPJ6P6VX9_OVNMPJ6P6VX9_H

#include "omp.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t matrix_prod(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M, int64_t threads);
void matrix_prod_ovnmpj6p6vx9_ovnmpj6p6vx9__init(void);
#endif // MATRIX_PROD_OVNMPJ6P6VX9_OVNMPJ6P6VX9_H
