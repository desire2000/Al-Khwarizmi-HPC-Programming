#ifndef MOD_IITPDUW4F20D_IITPDUW4F20D_H
#define MOD_IITPDUW4F20D_IITPDUW4F20D_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t solve_2d_burger_pyccel(t_ndarray u, t_ndarray un, t_ndarray v, t_ndarray vn, int64_t nt, double dt, double dx, double dy, double nu);
#endif // MOD_IITPDUW4F20D_IITPDUW4F20D_H
