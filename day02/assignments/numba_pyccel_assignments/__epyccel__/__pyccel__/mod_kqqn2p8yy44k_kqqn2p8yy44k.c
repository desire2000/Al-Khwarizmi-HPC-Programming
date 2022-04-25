#include "mod_kqqn2p8yy44k_kqqn2p8yy44k.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


/*........................................*/
int64_t solve_2d_linearconv_pyccel(t_ndarray u, t_ndarray un, int64_t nt, double dt, double dx, double dy, double c)
{
    int64_t row;
    int64_t col;
    int64_t n;
    int64_t i;
    int64_t j;
    int64_t i_0001;
    int64_t i_0002;
    row = u.shape[0];
    col = u.shape[1];
    for (n = 0; n < nt; n += 1)
    {
        for (i_0001 = 0; i_0001 < un.shape[0]; i_0001 += 1)
        {
            for (i_0002 = 0; i_0002 < un.shape[1]; i_0002 += 1)
            {
                GET_ELEMENT(un, nd_double, (int64_t)i_0001, (int64_t)i_0002) = GET_ELEMENT(u, nd_double, (int64_t)i_0001, (int64_t)i_0002);
            }
        }
        for (i = 1; i < row; i += 1)
        {
            for (j = 1; j < col; j += 1)
            {
                GET_ELEMENT(u, nd_double, (int64_t)i, (int64_t)j) = GET_ELEMENT(un, nd_double, (int64_t)i, (int64_t)j) - c * dt / dx * (GET_ELEMENT(un, nd_double, (int64_t)i, (int64_t)j) - GET_ELEMENT(un, nd_double, (int64_t)i - 1, (int64_t)j)) - c * dt / dy * (GET_ELEMENT(un, nd_double, (int64_t)i, (int64_t)j) - GET_ELEMENT(un, nd_double, (int64_t)i, (int64_t)j - 1));
            }
        }
    }
    return 0;
}
/*........................................*/

