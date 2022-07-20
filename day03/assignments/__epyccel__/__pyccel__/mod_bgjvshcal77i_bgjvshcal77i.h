#ifndef MOD_BGJVSHCAL77I_BGJVSHCAL77I_H
#define MOD_BGJVSHCAL77I_BGJVSHCAL77I_H

#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


void pressure_poisson_pyccel(t_ndarray p, t_ndarray pn, double dx, double dy, t_ndarray b, int64_t nit);
#endif // MOD_BGJVSHCAL77I_BGJVSHCAL77I_H
