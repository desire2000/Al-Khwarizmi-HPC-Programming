#ifndef MATRIX_PROD_WAVT83G8SXH6_WAVT83G8SXH6_H
#define MATRIX_PROD_WAVT83G8SXH6_WAVT83G8SXH6_H

#include "omp.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t matrix_prod(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M, int64_t threads);
void matrix_prod_wavt83g8sxh6_wavt83g8sxh6__init(void);
#endif // MATRIX_PROD_WAVT83G8SXH6_WAVT83G8SXH6_H
