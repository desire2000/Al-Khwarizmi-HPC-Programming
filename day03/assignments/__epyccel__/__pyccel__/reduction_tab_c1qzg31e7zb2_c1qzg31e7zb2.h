#ifndef REDUCTION_TAB_C1QZG31E7ZB2_C1QZG31E7ZB2_H
#define REDUCTION_TAB_C1QZG31E7ZB2_C1QZG31E7ZB2_H

#include "omp.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t threads_num(void);
int64_t matrix_prod(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M, int64_t threads);
void reduction_tab_c1qzg31e7zb2_c1qzg31e7zb2__init(void);
#endif // REDUCTION_TAB_C1QZG31E7ZB2_C1QZG31E7ZB2_H
