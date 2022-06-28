#ifndef MOD_DWYO3TBNOKTV_DWYO3TBNOKTV_H
#define MOD_DWYO3TBNOKTV_DWYO3TBNOKTV_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t solve_2d_nonlinearconv(t_ndarray u, t_ndarray un, t_ndarray v, t_ndarray vn, int64_t nt, double dt, double dx, double dy, int64_t c);
#endif // MOD_DWYO3TBNOKTV_DWYO3TBNOKTV_H
