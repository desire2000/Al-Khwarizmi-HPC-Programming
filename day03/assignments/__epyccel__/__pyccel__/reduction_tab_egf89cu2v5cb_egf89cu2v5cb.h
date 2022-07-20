#ifndef REDUCTION_TAB_EGF89CU2V5CB_EGF89CU2V5CB_H
#define REDUCTION_TAB_EGF89CU2V5CB_EGF89CU2V5CB_H

#include "omp.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t threads_num(void);
int64_t matrix_prod(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M, int64_t threads);
void reduction_tab_egf89cu2v5cb_egf89cu2v5cb__init(void);
#endif // REDUCTION_TAB_EGF89CU2V5CB_EGF89CU2V5CB_H
