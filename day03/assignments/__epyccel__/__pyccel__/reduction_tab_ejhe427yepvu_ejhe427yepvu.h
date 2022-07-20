#ifndef REDUCTION_TAB_EJHE427YEPVU_EJHE427YEPVU_H
#define REDUCTION_TAB_EJHE427YEPVU_EJHE427YEPVU_H

#include "omp.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t threads_num(void);
int64_t matrix_prod(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M, int64_t threads);
void reduction_tab_ejhe427yepvu_ejhe427yepvu__init(void);
#endif // REDUCTION_TAB_EJHE427YEPVU_EJHE427YEPVU_H
