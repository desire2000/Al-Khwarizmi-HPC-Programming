#ifndef REDUCTION_TAB_L7AQ0QH4852S_L7AQ0QH4852S_H
#define REDUCTION_TAB_L7AQ0QH4852S_L7AQ0QH4852S_H

#include "omp.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t threads_num(void);
int64_t matrix_prod(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M, int64_t threads);
void reduction_tab_l7aq0qh4852s_l7aq0qh4852s__init(void);
#endif // REDUCTION_TAB_L7AQ0QH4852S_L7AQ0QH4852S_H
