#ifndef REDUCTION_TAB_RIKLSA3TLBZG_RIKLSA3TLBZG_H
#define REDUCTION_TAB_RIKLSA3TLBZG_RIKLSA3TLBZG_H

#include "omp.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t threads_num(void);
int64_t matrix_prod(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M, int64_t threads);
void reduction_tab_riklsa3tlbzg_riklsa3tlbzg__init(void);
#endif // REDUCTION_TAB_RIKLSA3TLBZG_RIKLSA3TLBZG_H
