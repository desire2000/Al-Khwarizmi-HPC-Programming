#ifndef MOD_Z89AFOX51MIZ_Z89AFOX51MIZ_H
#define MOD_Z89AFOX51MIZ_Z89AFOX51MIZ_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t solve_2d_nonlinearconv_pyccel(t_ndarray u, t_ndarray un, t_ndarray v, t_ndarray vn, int64_t nt, double dt, double dx, double dy, int64_t c);
#endif // MOD_Z89AFOX51MIZ_Z89AFOX51MIZ_H
