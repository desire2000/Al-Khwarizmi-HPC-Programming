#ifndef MOD_UD137U317QNS_UD137U317QNS_H
#define MOD_UD137U317QNS_UD137U317QNS_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t solve_2d_nonlinearconv(t_ndarray u, t_ndarray un, t_ndarray v, t_ndarray vn, int64_t nt, double dt, double dx, double dy, int64_t c);
#endif // MOD_UD137U317QNS_UD137U317QNS_H
