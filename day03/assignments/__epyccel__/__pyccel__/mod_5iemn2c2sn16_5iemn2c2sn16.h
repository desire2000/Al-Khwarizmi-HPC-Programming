#ifndef MOD_5IEMN2C2SN16_5IEMN2C2SN16_H
#define MOD_5IEMN2C2SN16_5IEMN2C2SN16_H

#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


void pressure_poisson_pyccel(t_ndarray p, t_ndarray pn, double dx, double dy, t_ndarray b, int64_t nit);
#endif // MOD_5IEMN2C2SN16_5IEMN2C2SN16_H
