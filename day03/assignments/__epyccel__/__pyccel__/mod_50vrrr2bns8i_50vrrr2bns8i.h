#ifndef MOD_50VRRR2BNS8I_50VRRR2BNS8I_H
#define MOD_50VRRR2BNS8I_50VRRR2BNS8I_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


void cavity_flow_pyccel(int64_t nt, t_ndarray u, t_ndarray un, t_ndarray v, t_ndarray vn, t_ndarray b, double dt, int64_t nx, int64_t ny, double dx, double dy, t_ndarray p, t_ndarray pn, int64_t rho, double nu, int64_t nit);
#endif // MOD_50VRRR2BNS8I_50VRRR2BNS8I_H
