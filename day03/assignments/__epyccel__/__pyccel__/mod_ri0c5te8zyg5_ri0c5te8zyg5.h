#ifndef MOD_RI0C5TE8ZYG5_RI0C5TE8ZYG5_H
#define MOD_RI0C5TE8ZYG5_RI0C5TE8ZYG5_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


void cavity_flow_numba(int64_t nit, int64_t nt, t_ndarray u, t_ndarray v, double dt, int64_t nx, int64_t ny, double dx, double dy, t_ndarray p, int64_t rho, double nu);
#endif // MOD_RI0C5TE8ZYG5_RI0C5TE8ZYG5_H
