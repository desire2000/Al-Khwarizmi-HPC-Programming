#ifndef MOD_D05P0ER8OOAK_D05P0ER8OOAK_H
#define MOD_D05P0ER8OOAK_D05P0ER8OOAK_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t solve_2d_nonlinearconv(t_ndarray u, t_ndarray un, t_ndarray v, t_ndarray vn, int64_t nt, double dt, double dx, double dy, int64_t c);
#endif // MOD_D05P0ER8OOAK_D05P0ER8OOAK_H
