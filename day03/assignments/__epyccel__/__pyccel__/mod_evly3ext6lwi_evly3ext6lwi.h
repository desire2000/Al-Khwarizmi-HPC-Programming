#ifndef MOD_EVLY3EXT6LWI_EVLY3EXT6LWI_H
#define MOD_EVLY3EXT6LWI_EVLY3EXT6LWI_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t matrix_prod(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M, int64_t threads);
#endif // MOD_EVLY3EXT6LWI_EVLY3EXT6LWI_H
