#include "mod_bgjvshcal77i_bgjvshcal77i.h"
#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>
#include <math.h>


/*........................................*/
void pressure_poisson_pyccel(t_ndarray p, t_ndarray pn, double dx, double dy, t_ndarray b, int64_t nit)
{
    int64_t q;
    int64_t i_0001;
    int64_t i_0002;
    /*pn = np.empty_like(p)*/
    /*pn = p*/
    for (q = 0; q < nit; q += 1)
    {
        for (i_0001 = 0; i_0001 < pn.shape[0]; i_0001 += 1)
        {
            for (i_0002 = 0; i_0002 < pn.shape[1]; i_0002 += 1)
            {
                GET_ELEMENT(pn, nd_double, (int64_t)i_0001, (int64_t)i_0002) = GET_ELEMENT(p, nd_double, (int64_t)i_0001, (int64_t)i_0002);
            }
        }
        for (i_0001 = 0; i_0001 < p.shape[0] - 1 - 1; i_0001 += 1)
        {
            for (i_0002 = 0; i_0002 < p.shape[1] - 1 - 1; i_0002 += 1)
            {
                GET_ELEMENT(p, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) = ((GET_ELEMENT(pn, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 2) + GET_ELEMENT(pn, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002)) * pow(dy, 2.0) + (GET_ELEMENT(pn, nd_double, (int64_t)i_0001 + 2, (int64_t)i_0002 + 1) + GET_ELEMENT(pn, nd_double, (int64_t)i_0001, (int64_t)i_0002 + 1)) * pow(dx, 2.0)) / (2 * (pow(dx, 2.0) + pow(dy, 2.0))) - pow(dx, 2.0) * pow(dy, 2.0) / (2 * (pow(dx, 2.0) + pow(dy, 2.0))) * GET_ELEMENT(b, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1);
            }
        }
        for (i_0001 = 0; i_0001 < p.shape[0]; i_0001 += 1)
        {
            GET_ELEMENT(p, nd_double, (int64_t)i_0001, (int64_t)p.shape[1] - 1) = GET_ELEMENT(p, nd_double, (int64_t)i_0001, (int64_t)p.shape[1] - 2);
        }
        for (i_0001 = 0; i_0001 < p.shape[1]; i_0001 += 1)
        {
            GET_ELEMENT(p, nd_double, (int64_t)0, (int64_t)i_0001) = GET_ELEMENT(p, nd_double, (int64_t)1, (int64_t)i_0001);
        }
        for (i_0001 = 0; i_0001 < p.shape[0]; i_0001 += 1)
        {
            GET_ELEMENT(p, nd_double, (int64_t)i_0001, (int64_t)0) = GET_ELEMENT(p, nd_double, (int64_t)i_0001, (int64_t)1);
        }
        for (i_0001 = 0; i_0001 < p.shape[1]; i_0001 += 1)
        {
            GET_ELEMENT(p, nd_double, (int64_t)p.shape[0] - 1, (int64_t)i_0001) = 0;
        }
    }
    /*return p*/
}
/*........................................*/

