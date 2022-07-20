#ifndef MATRIX_PROD_36LL4UKPCWUN_36LL4UKPCWUN_H
#define MATRIX_PROD_36LL4UKPCWUN_36LL4UKPCWUN_H

#include "omp.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t matrix_prod(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M, int64_t threads);
void matrix_prod_36ll4ukpcwun_36ll4ukpcwun__init(void);
#endif // MATRIX_PROD_36LL4UKPCWUN_36LL4UKPCWUN_H
