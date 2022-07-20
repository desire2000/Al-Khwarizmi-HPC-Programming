#ifndef MOD_O8ND6WM2O590_O8ND6WM2O590_H
#define MOD_O8ND6WM2O590_O8ND6WM2O590_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


void navier_openmp(int64_t nit, int64_t nt, t_ndarray u, t_ndarray v, double dt, int64_t nx, int64_t ny, double dx, double dy, t_ndarray p, int64_t rho, double nu);
#endif // MOD_O8ND6WM2O590_O8ND6WM2O590_H
