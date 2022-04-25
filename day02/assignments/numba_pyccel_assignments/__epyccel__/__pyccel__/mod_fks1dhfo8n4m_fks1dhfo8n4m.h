#ifndef MOD_FKS1DHFO8N4M_FKS1DHFO8N4M_H
#define MOD_FKS1DHFO8N4M_FKS1DHFO8N4M_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t solve_1d_diff_pyccel(t_ndarray u, t_ndarray un, int64_t nt, int64_t nx, double dt, double dx, double nu);
#endif // MOD_FKS1DHFO8N4M_FKS1DHFO8N4M_H
