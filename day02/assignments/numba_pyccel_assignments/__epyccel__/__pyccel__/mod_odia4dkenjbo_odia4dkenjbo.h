#ifndef MOD_ODIA4DKENJBO_ODIA4DKENJBO_H
#define MOD_ODIA4DKENJBO_ODIA4DKENJBO_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t solve_1d_nonlinearconv_pyccel(t_ndarray u, t_ndarray un, int64_t nt, int64_t nx, double dt, double dx);
#endif // MOD_ODIA4DKENJBO_ODIA4DKENJBO_H
