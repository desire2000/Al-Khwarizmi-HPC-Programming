#ifndef MOD_ORX562VMO5KR_ORX562VMO5KR_H
#define MOD_ORX562VMO5KR_ORX562VMO5KR_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t solve_2d_poisson_pyccel(t_ndarray p, t_ndarray pd, t_ndarray b, int64_t nx, int64_t ny, int64_t nt, double dx, double dy);
#endif // MOD_ORX562VMO5KR_ORX562VMO5KR_H
