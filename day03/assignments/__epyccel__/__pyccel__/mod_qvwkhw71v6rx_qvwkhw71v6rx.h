#ifndef MOD_QVWKHW71V6RX_QVWKHW71V6RX_H
#define MOD_QVWKHW71V6RX_QVWKHW71V6RX_H

#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


void pressure_poisson(t_ndarray p, t_ndarray pn, double dx, double dy, t_ndarray b, int64_t nit);
#endif // MOD_QVWKHW71V6RX_QVWKHW71V6RX_H
