#include "mod_50vrrr2bns8i_50vrrr2bns8i.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"
#include <math.h>


/*........................................*/
void cavity_flow_pyccel(int64_t nt, t_ndarray u, t_ndarray un, t_ndarray v, t_ndarray vn, t_ndarray b, double dt, int64_t nx, int64_t ny, double dx, double dy, t_ndarray p, t_ndarray pn, int64_t rho, double nu, int64_t nit)
{
    int64_t n;
    int64_t row;
    int64_t col;
    int64_t q;
    int64_t i_0001;
    int64_t i_0002;
    int64_t i_0003;
    int64_t i_0004;
    int64_t i_0005;
    int64_t i_0006;
    /*un = np.empty_like(u)*/
    /*vn = np.empty_like(v)*/
    /*pn = np.empty_like(p)*/
    /*b = np.zeros((ny, nx))*/
    for (n = 0; n < nt; n += 1)
    {
        for (i_0003 = 0; i_0003 < un.shape[0]; i_0003 += 1)
        {
            for (i_0004 = 0; i_0004 < un.shape[1]; i_0004 += 1)
            {
                GET_ELEMENT(un, nd_double, (int64_t)i_0003, (int64_t)i_0004) = GET_ELEMENT(u, nd_double, (int64_t)i_0003, (int64_t)i_0004);
            }
        }
        for (i_0003 = 0; i_0003 < vn.shape[0]; i_0003 += 1)
        {
            for (i_0004 = 0; i_0004 < vn.shape[1]; i_0004 += 1)
            {
                GET_ELEMENT(vn, nd_double, (int64_t)i_0003, (int64_t)i_0004) = GET_ELEMENT(v, nd_double, (int64_t)i_0003, (int64_t)i_0004);
            }
        }
    }
    /*## Valeur de b*/
    row = p.shape[0];
    col = p.shape[1];
    for (i_0001 = 0; i_0001 < b.shape[0] - 1 - 1; i_0001 += 1)
    {
        for (i_0002 = 0; i_0002 < b.shape[1] - 1 - 1; i_0002 += 1)
        {
            GET_ELEMENT(b, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) = rho * (1 / dt * ((GET_ELEMENT(u, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 2) - GET_ELEMENT(u, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002)) / (2 * dx) + (GET_ELEMENT(v, nd_double, (int64_t)i_0001 + 2, (int64_t)i_0002 + 1) - GET_ELEMENT(v, nd_double, (int64_t)i_0001, (int64_t)i_0002 + 1)) / (2 * dy)) - pow(((GET_ELEMENT(u, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 2) - GET_ELEMENT(u, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002)) / (2 * dx)), 2.0) - 2 * ((GET_ELEMENT(u, nd_double, (int64_t)i_0001 + 2, (int64_t)i_0002 + 1) - GET_ELEMENT(u, nd_double, (int64_t)i_0001, (int64_t)i_0002 + 1)) / (2 * dy) * (GET_ELEMENT(v, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 2) - GET_ELEMENT(v, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002)) / (2 * dx)) - pow(((GET_ELEMENT(v, nd_double, (int64_t)i_0001 + 2, (int64_t)i_0002 + 1) - GET_ELEMENT(v, nd_double, (int64_t)i_0001, (int64_t)i_0002 + 1)) / (2 * dy)), 2.0));
        }
    }
    /*VAleur de p*/
    /*pn = np.empty_like(p)*/
    for (i_0001 = 0; i_0001 < pn.shape[0]; i_0001 += 1)
    {
        for (i_0002 = 0; i_0002 < pn.shape[1]; i_0002 += 1)
        {
            GET_ELEMENT(pn, nd_double, (int64_t)i_0001, (int64_t)i_0002) = GET_ELEMENT(p, nd_double, (int64_t)i_0001, (int64_t)i_0002);
        }
    }
    for (q = 0; q < nit; q += 1)
    {
        for (i_0005 = 0; i_0005 < pn.shape[0]; i_0005 += 1)
        {
            for (i_0006 = 0; i_0006 < pn.shape[1]; i_0006 += 1)
            {
                GET_ELEMENT(pn, nd_double, (int64_t)i_0005, (int64_t)i_0006) = GET_ELEMENT(p, nd_double, (int64_t)i_0005, (int64_t)i_0006);
            }
        }
        for (i_0005 = 0; i_0005 < p.shape[0] - 1 - 1; i_0005 += 1)
        {
            for (i_0006 = 0; i_0006 < p.shape[1] - 1 - 1; i_0006 += 1)
            {
                GET_ELEMENT(p, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 1) = ((GET_ELEMENT(pn, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 2) + GET_ELEMENT(pn, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006)) * pow(dy, 2.0) + (GET_ELEMENT(pn, nd_double, (int64_t)i_0005 + 2, (int64_t)i_0006 + 1) + GET_ELEMENT(pn, nd_double, (int64_t)i_0005, (int64_t)i_0006 + 1)) * pow(dx, 2.0)) / (2 * (pow(dx, 2.0) + pow(dy, 2.0))) - pow(dx, 2.0) * pow(dy, 2.0) / (2 * (pow(dx, 2.0) + pow(dy, 2.0))) * GET_ELEMENT(b, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 1);
            }
        }
        for (i_0005 = 0; i_0005 < p.shape[0]; i_0005 += 1)
        {
            GET_ELEMENT(p, nd_double, (int64_t)i_0005, (int64_t)p.shape[1] - 1) = GET_ELEMENT(p, nd_double, (int64_t)i_0005, (int64_t)p.shape[1] - 2);
        }
        for (i_0005 = 0; i_0005 < p.shape[1]; i_0005 += 1)
        {
            GET_ELEMENT(p, nd_double, (int64_t)0, (int64_t)i_0005) = GET_ELEMENT(p, nd_double, (int64_t)1, (int64_t)i_0005);
        }
        for (i_0005 = 0; i_0005 < p.shape[0]; i_0005 += 1)
        {
            GET_ELEMENT(p, nd_double, (int64_t)i_0005, (int64_t)0) = GET_ELEMENT(p, nd_double, (int64_t)i_0005, (int64_t)1);
        }
        for (i_0005 = 0; i_0005 < p.shape[1]; i_0005 += 1)
        {
            GET_ELEMENT(p, nd_double, (int64_t)p.shape[0] - 1, (int64_t)i_0005) = 0;
        }
        for (i_0005 = 0; i_0005 < u.shape[0] - 1 - 1; i_0005 += 1)
        {
            for (i_0006 = 0; i_0006 < u.shape[1] - 1 - 1; i_0006 += 1)
            {
                GET_ELEMENT(u, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 1) = GET_ELEMENT(un, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 1) - GET_ELEMENT(un, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 1) * dt / dx * (GET_ELEMENT(un, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 1) - GET_ELEMENT(un, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006)) - GET_ELEMENT(vn, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 1) * dt / dy * (GET_ELEMENT(un, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 1) - GET_ELEMENT(un, nd_double, (int64_t)i_0005, (int64_t)i_0006 + 1)) - dt / (2 * rho * dx) * (GET_ELEMENT(p, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 2) - GET_ELEMENT(p, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006)) + nu * (dt / pow(dx, 2.0) * (GET_ELEMENT(un, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 2) - 2 * GET_ELEMENT(un, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 1) + GET_ELEMENT(un, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006)) + dt / pow(dy, 2.0) * (GET_ELEMENT(un, nd_double, (int64_t)i_0005 + 2, (int64_t)i_0006 + 1) - 2 * GET_ELEMENT(un, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 1) + GET_ELEMENT(un, nd_double, (int64_t)i_0005, (int64_t)i_0006 + 1)));
            }
        }
        for (i_0005 = 0; i_0005 < v.shape[0] - 1 - 1; i_0005 += 1)
        {
            for (i_0006 = 0; i_0006 < v.shape[1] - 1 - 1; i_0006 += 1)
            {
                GET_ELEMENT(v, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 1) = GET_ELEMENT(vn, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 1) - GET_ELEMENT(un, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 1) * dt / dx * (GET_ELEMENT(vn, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 1) - GET_ELEMENT(vn, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006)) - GET_ELEMENT(vn, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 1) * dt / dy * (GET_ELEMENT(vn, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 1) - GET_ELEMENT(vn, nd_double, (int64_t)i_0005, (int64_t)i_0006 + 1)) - dt / (2 * rho * dy) * (GET_ELEMENT(p, nd_double, (int64_t)i_0005 + 2, (int64_t)i_0006 + 1) - GET_ELEMENT(p, nd_double, (int64_t)i_0005, (int64_t)i_0006 + 1)) + nu * (dt / pow(dx, 2.0) * (GET_ELEMENT(vn, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 2) - 2 * GET_ELEMENT(vn, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 1) + GET_ELEMENT(vn, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006)) + dt / pow(dy, 2.0) * (GET_ELEMENT(vn, nd_double, (int64_t)i_0005 + 2, (int64_t)i_0006 + 1) - 2 * GET_ELEMENT(vn, nd_double, (int64_t)i_0005 + 1, (int64_t)i_0006 + 1) + GET_ELEMENT(vn, nd_double, (int64_t)i_0005, (int64_t)i_0006 + 1)));
            }
        }
        for (i_0005 = 0; i_0005 < u.shape[1]; i_0005 += 1)
        {
            GET_ELEMENT(u, nd_double, (int64_t)0, (int64_t)i_0005) = 0;
        }
        for (i_0005 = 0; i_0005 < u.shape[0]; i_0005 += 1)
        {
            GET_ELEMENT(u, nd_double, (int64_t)i_0005, (int64_t)0) = 0;
            GET_ELEMENT(u, nd_double, (int64_t)i_0005, (int64_t)u.shape[1] - 1) = 0;
        }
        for (i_0005 = 0; i_0005 < u.shape[1]; i_0005 += 1)
        {
            GET_ELEMENT(u, nd_double, (int64_t)u.shape[0] - 1, (int64_t)i_0005) = 1;
        }
        for (i_0005 = 0; i_0005 < v.shape[1]; i_0005 += 1)
        {
            GET_ELEMENT(v, nd_double, (int64_t)0, (int64_t)i_0005) = 0;
            GET_ELEMENT(v, nd_double, (int64_t)v.shape[0] - 1, (int64_t)i_0005) = 0;
        }
        for (i_0005 = 0; i_0005 < v.shape[0]; i_0005 += 1)
        {
            GET_ELEMENT(v, nd_double, (int64_t)i_0005, (int64_t)0) = 0;
            GET_ELEMENT(v, nd_double, (int64_t)i_0005, (int64_t)v.shape[1] - 1) = 0;
        }
    }
    /*return u, v, p*/
}
/*........................................*/

