#ifndef MATRIX_PROD_0YD8DMOX9T8E_0YD8DMOX9T8E_H
#define MATRIX_PROD_0YD8DMOX9T8E_0YD8DMOX9T8E_H

#include "omp.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t matrix_prod(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M, int64_t threads);
void matrix_prod_0yd8dmox9t8e_0yd8dmox9t8e__init(void);
#endif // MATRIX_PROD_0YD8DMOX9T8E_0YD8DMOX9T8E_H
