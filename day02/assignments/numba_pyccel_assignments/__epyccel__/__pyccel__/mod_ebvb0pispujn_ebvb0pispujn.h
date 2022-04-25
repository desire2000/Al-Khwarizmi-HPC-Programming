#ifndef MOD_EBVB0PISPUJN_EBVB0PISPUJN_H
#define MOD_EBVB0PISPUJN_EBVB0PISPUJN_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t solve_2d_diff_pyccel(t_ndarray u, t_ndarray un, int64_t nt, double dt, double dx, double dy, double nu);
#endif // MOD_EBVB0PISPUJN_EBVB0PISPUJN_H
