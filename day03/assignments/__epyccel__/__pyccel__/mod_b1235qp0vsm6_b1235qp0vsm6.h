#ifndef MOD_B1235QP0VSM6_B1235QP0VSM6_H
#define MOD_B1235QP0VSM6_B1235QP0VSM6_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


void navier_openmp(int64_t nit, int64_t nt, t_ndarray u, t_ndarray un, t_ndarray b, t_ndarray v, t_ndarray vn, double dt, int64_t nx, int64_t ny, double dx, double dy, t_ndarray p, t_ndarray pn, int64_t rho, double nu);
#endif // MOD_B1235QP0VSM6_B1235QP0VSM6_H
