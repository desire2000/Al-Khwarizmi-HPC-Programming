#ifndef REDUCTION_TAB_9IM3Z261T1QU_9IM3Z261T1QU_H
#define REDUCTION_TAB_9IM3Z261T1QU_9IM3Z261T1QU_H

#include "omp.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t threads_num(void);
int64_t matrix_prod(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M, int64_t threads);
void reduction_tab_9im3z261t1qu_9im3z261t1qu__init(void);
#endif // REDUCTION_TAB_9IM3Z261T1QU_9IM3Z261T1QU_H
