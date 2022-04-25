#include "mod_9hkrxgyj3dzj_9hkrxgyj3dzj.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"
#include <math.h>


/*........................................*/
int64_t solve_2d_burger_pyccel(t_ndarray u, t_ndarray un, t_ndarray v, t_ndarray vn, int64_t nt, double dt, double dx, double dy, double nu)
{
    int64_t row;
    int64_t col;
    int64_t n;
    int64_t k;
    int64_t l;
    int64_t i;
    int64_t j;
    row = u.shape[0];
    col = u.shape[1];
    for (n = 0; n < nt; n += 1)
    {
        for (k = 0; k < row; k += 1)
        {
            for (l = 0; l < col; l += 1)
            {
                GET_ELEMENT(un, nd_double, (int64_t)k, (int64_t)l) = GET_ELEMENT(u, nd_double, (int64_t)k, (int64_t)l);
                GET_ELEMENT(vn, nd_double, (int64_t)k, (int64_t)l) = GET_ELEMENT(v, nd_double, (int64_t)k, (int64_t)l);
            }
        }
        for (i = 1; i < row - 1; i += 1)
        {
            for (j = 1; j < col - 1; j += 1)
            {
                GET_ELEMENT(u, nd_double, (int64_t)i, (int64_t)j) = GET_ELEMENT(un, nd_double, (int64_t)i, (int64_t)j) - GET_ELEMENT(un, nd_double, (int64_t)i, (int64_t)j) * dt / dx * (GET_ELEMENT(un, nd_double, (int64_t)i, (int64_t)j) - GET_ELEMENT(un, nd_double, (int64_t)i - 1, (int64_t)j)) - GET_ELEMENT(vn, nd_double, (int64_t)i, (int64_t)j) * dt / dy * (GET_ELEMENT(un, nd_double, (int64_t)i, (int64_t)j) - GET_ELEMENT(un, nd_double, (int64_t)i, (int64_t)j - 1)) + nu * dt / pow(dx, 2.0) * (GET_ELEMENT(un, nd_double, (int64_t)i + 1, (int64_t)j) - 2 * GET_ELEMENT(un, nd_double, (int64_t)i, (int64_t)j) + GET_ELEMENT(un, nd_double, (int64_t)i - 1, (int64_t)j)) + nu * dt / pow(dy, 2.0) * (GET_ELEMENT(un, nd_double, (int64_t)i, (int64_t)j + 1) - 2 * GET_ELEMENT(un, nd_double, (int64_t)i, (int64_t)j) + GET_ELEMENT(un, nd_double, (int64_t)i, (int64_t)j - 1));
                GET_ELEMENT(v, nd_double, (int64_t)i, (int64_t)j) = GET_ELEMENT(vn, nd_double, (int64_t)i, (int64_t)j) - GET_ELEMENT(un, nd_double, (int64_t)i, (int64_t)j) * dt / dx * (GET_ELEMENT(vn, nd_double, (int64_t)i, (int64_t)j) - GET_ELEMENT(vn, nd_double, (int64_t)i - 1, (int64_t)j)) - GET_ELEMENT(vn, nd_double, (int64_t)i, (int64_t)j) * dt / dy * (GET_ELEMENT(vn, nd_double, (int64_t)i, (int64_t)j) - GET_ELEMENT(vn, nd_double, (int64_t)i, (int64_t)j - 1)) + nu * dt / pow(dx, 2.0) * (GET_ELEMENT(vn, nd_double, (int64_t)i + 1, (int64_t)j) - 2 * GET_ELEMENT(vn, nd_double, (int64_t)i, (int64_t)j) + GET_ELEMENT(vn, nd_double, (int64_t)i - 1, (int64_t)j)) + nu * dt / pow(dy, 2.0) * (GET_ELEMENT(vn, nd_double, (int64_t)i, (int64_t)j + 1) - 2 * GET_ELEMENT(vn, nd_double, (int64_t)i, (int64_t)j) + GET_ELEMENT(vn, nd_double, (int64_t)i, (int64_t)j - 1));
            }
        }
    }
    return 0;
}
/*........................................*/

