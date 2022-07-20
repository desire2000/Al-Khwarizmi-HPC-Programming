#include "mod_o8nd6wm2o590_o8nd6wm2o590.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"
#include <math.h>


/*........................................*/
void navier_openmp(int64_t nit, int64_t nt, t_ndarray u, t_ndarray v, double dt, int64_t nx, int64_t ny, double dx, double dy, t_ndarray p, int64_t rho, double nu)
{
    t_ndarray un = {.shape = NULL};
    t_ndarray vn = {.shape = NULL};
    t_ndarray b = {.shape = NULL};
    int64_t n;
    int64_t row;
    int64_t col;
    t_ndarray pn = {.shape = NULL};
    int64_t q;
    int64_t i_0001;
    int64_t i_0002;
    int64_t i_0003;
    int64_t i_0004;
    alias_assign(&un, u);
    alias_assign(&vn, v);
    alias_assign(&b, u);
    for (n = 0; n < nt; n += 1)
    {
        for (i_0001 = 0; i_0001 < un.shape[0]; i_0001 += 1)
        {
            for (i_0002 = 0; i_0002 < un.shape[1]; i_0002 += 1)
            {
                GET_ELEMENT(un, nd_double, (int64_t)i_0001, (int64_t)i_0002) = GET_ELEMENT(u, nd_double, (int64_t)i_0001, (int64_t)i_0002);
            }
        }
        for (i_0001 = 0; i_0001 < vn.shape[0]; i_0001 += 1)
        {
            for (i_0002 = 0; i_0002 < vn.shape[1]; i_0002 += 1)
            {
                GET_ELEMENT(vn, nd_double, (int64_t)i_0001, (int64_t)i_0002) = GET_ELEMENT(v, nd_double, (int64_t)i_0001, (int64_t)i_0002);
            }
        }
        /*b = build_up_b_pyccel(b, rho, dt, u, v, dx, dy)*/
        /*p = pressure_poisson_pyccel(p, dx, dy, b,nit)*/
        /*def build_up_b_pyccel(b:'float[:,:]', rho:'int', dt:'float', u:'float[:,:]', v:'float[:,:]', dx:'float', dy:'float'):*/
        row = p.shape[0];
        col = p.shape[1];
        for (i_0001 = 0; i_0001 < b.shape[0] - 1 - 1; i_0001 += 1)
        {
            for (i_0002 = 0; i_0002 < b.shape[1] - 1 - 1; i_0002 += 1)
            {
                GET_ELEMENT(b, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) = rho * (1 / dt * ((GET_ELEMENT(u, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 2) - GET_ELEMENT(u, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002)) / (2 * dx) + (GET_ELEMENT(v, nd_double, (int64_t)i_0001 + 2, (int64_t)i_0002 + 1) - GET_ELEMENT(v, nd_double, (int64_t)i_0001, (int64_t)i_0002 + 1)) / (2 * dy)) - pow(((GET_ELEMENT(u, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 2) - GET_ELEMENT(u, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002)) / (2 * dx)), 2.0) - 2 * ((GET_ELEMENT(u, nd_double, (int64_t)i_0001 + 2, (int64_t)i_0002 + 1) - GET_ELEMENT(u, nd_double, (int64_t)i_0001, (int64_t)i_0002 + 1)) / (2 * dy) * (GET_ELEMENT(v, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 2) - GET_ELEMENT(v, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002)) / (2 * dx)) - pow(((GET_ELEMENT(v, nd_double, (int64_t)i_0001 + 2, (int64_t)i_0002 + 1) - GET_ELEMENT(v, nd_double, (int64_t)i_0001, (int64_t)i_0002 + 1)) / (2 * dy)), 2.0));
            }
        }
        /*def pressure_poisson_pyccel(p:'float[:,:]', pn:'float[:,:]', dx:'float', dy:'float', b:'float[:,:]', nit:'int'):*/
        /*pn = np.empty_like(p)*/
        alias_assign(&pn, p);
    }
    for (q = 0; q < nit; q += 1)
    {
        for (i_0003 = 0; i_0003 < pn.shape[0]; i_0003 += 1)
        {
            for (i_0004 = 0; i_0004 < pn.shape[1]; i_0004 += 1)
            {
                GET_ELEMENT(pn, nd_double, (int64_t)i_0003, (int64_t)i_0004) = GET_ELEMENT(p, nd_double, (int64_t)i_0003, (int64_t)i_0004);
            }
        }
        for (i_0003 = 0; i_0003 < p.shape[0] - 1 - 1; i_0003 += 1)
        {
            for (i_0004 = 0; i_0004 < p.shape[1] - 1 - 1; i_0004 += 1)
            {
                GET_ELEMENT(p, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004 + 1) = ((GET_ELEMENT(pn, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004 + 2) + GET_ELEMENT(pn, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004)) * pow(dy, 2.0) + (GET_ELEMENT(pn, nd_double, (int64_t)i_0003 + 2, (int64_t)i_0004 + 1) + GET_ELEMENT(pn, nd_double, (int64_t)i_0003, (int64_t)i_0004 + 1)) * pow(dx, 2.0)) / (2 * (pow(dx, 2.0) + pow(dy, 2.0))) - pow(dx, 2.0) * pow(dy, 2.0) / (2 * (pow(dx, 2.0) + pow(dy, 2.0))) * GET_ELEMENT(b, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004 + 1);
            }
        }
        for (i_0003 = 0; i_0003 < p.shape[0]; i_0003 += 1)
        {
            GET_ELEMENT(p, nd_double, (int64_t)i_0003, (int64_t)p.shape[1] - 1) = GET_ELEMENT(p, nd_double, (int64_t)i_0003, (int64_t)p.shape[1] - 2);
        }
        for (i_0003 = 0; i_0003 < p.shape[1]; i_0003 += 1)
        {
            GET_ELEMENT(p, nd_double, (int64_t)0, (int64_t)i_0003) = GET_ELEMENT(p, nd_double, (int64_t)1, (int64_t)i_0003);
        }
        for (i_0003 = 0; i_0003 < p.shape[0]; i_0003 += 1)
        {
            GET_ELEMENT(p, nd_double, (int64_t)i_0003, (int64_t)0) = GET_ELEMENT(p, nd_double, (int64_t)i_0003, (int64_t)1);
        }
        for (i_0003 = 0; i_0003 < p.shape[1]; i_0003 += 1)
        {
            GET_ELEMENT(p, nd_double, (int64_t)p.shape[0] - 1, (int64_t)i_0003) = 0;
        }
        for (i_0003 = 0; i_0003 < u.shape[0] - 1 - 1; i_0003 += 1)
        {
            for (i_0004 = 0; i_0004 < u.shape[1] - 1 - 1; i_0004 += 1)
            {
                GET_ELEMENT(u, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004 + 1) = GET_ELEMENT(un, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004 + 1) - GET_ELEMENT(un, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004 + 1) * dt / dx * (GET_ELEMENT(un, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004 + 1) - GET_ELEMENT(un, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004)) - GET_ELEMENT(vn, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004 + 1) * dt / dy * (GET_ELEMENT(un, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004 + 1) - GET_ELEMENT(un, nd_double, (int64_t)i_0003, (int64_t)i_0004 + 1)) - dt / (2 * rho * dx) * (GET_ELEMENT(p, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004 + 2) - GET_ELEMENT(p, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004)) + nu * (dt / pow(dx, 2.0) * (GET_ELEMENT(un, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004 + 2) - 2 * GET_ELEMENT(un, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004 + 1) + GET_ELEMENT(un, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004)) + dt / pow(dy, 2.0) * (GET_ELEMENT(un, nd_double, (int64_t)i_0003 + 2, (int64_t)i_0004 + 1) - 2 * GET_ELEMENT(un, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004 + 1) + GET_ELEMENT(un, nd_double, (int64_t)i_0003, (int64_t)i_0004 + 1)));
            }
        }
        for (i_0003 = 0; i_0003 < v.shape[0] - 1 - 1; i_0003 += 1)
        {
            for (i_0004 = 0; i_0004 < v.shape[1] - 1 - 1; i_0004 += 1)
            {
                GET_ELEMENT(v, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004 + 1) = GET_ELEMENT(vn, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004 + 1) - GET_ELEMENT(un, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004 + 1) * dt / dx * (GET_ELEMENT(vn, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004 + 1) - GET_ELEMENT(vn, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004)) - GET_ELEMENT(vn, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004 + 1) * dt / dy * (GET_ELEMENT(vn, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004 + 1) - GET_ELEMENT(vn, nd_double, (int64_t)i_0003, (int64_t)i_0004 + 1)) - dt / (2 * rho * dy) * (GET_ELEMENT(p, nd_double, (int64_t)i_0003 + 2, (int64_t)i_0004 + 1) - GET_ELEMENT(p, nd_double, (int64_t)i_0003, (int64_t)i_0004 + 1)) + nu * (dt / pow(dx, 2.0) * (GET_ELEMENT(vn, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004 + 2) - 2 * GET_ELEMENT(vn, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004 + 1) + GET_ELEMENT(vn, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004)) + dt / pow(dy, 2.0) * (GET_ELEMENT(vn, nd_double, (int64_t)i_0003 + 2, (int64_t)i_0004 + 1) - 2 * GET_ELEMENT(vn, nd_double, (int64_t)i_0003 + 1, (int64_t)i_0004 + 1) + GET_ELEMENT(vn, nd_double, (int64_t)i_0003, (int64_t)i_0004 + 1)));
            }
        }
        for (i_0003 = 0; i_0003 < u.shape[1]; i_0003 += 1)
        {
            GET_ELEMENT(u, nd_double, (int64_t)0, (int64_t)i_0003) = 0;
        }
        for (i_0003 = 0; i_0003 < u.shape[0]; i_0003 += 1)
        {
            GET_ELEMENT(u, nd_double, (int64_t)i_0003, (int64_t)0) = 0;
            GET_ELEMENT(u, nd_double, (int64_t)i_0003, (int64_t)u.shape[1] - 1) = 0;
        }
        for (i_0003 = 0; i_0003 < u.shape[1]; i_0003 += 1)
        {
            GET_ELEMENT(u, nd_double, (int64_t)u.shape[0] - 1, (int64_t)i_0003) = 1;
        }
        for (i_0003 = 0; i_0003 < v.shape[1]; i_0003 += 1)
        {
            GET_ELEMENT(v, nd_double, (int64_t)0, (int64_t)i_0003) = 0;
            GET_ELEMENT(v, nd_double, (int64_t)v.shape[0] - 1, (int64_t)i_0003) = 0;
        }
        for (i_0003 = 0; i_0003 < v.shape[0]; i_0003 += 1)
        {
            GET_ELEMENT(v, nd_double, (int64_t)i_0003, (int64_t)0) = 0;
            GET_ELEMENT(v, nd_double, (int64_t)i_0003, (int64_t)v.shape[1] - 1) = 0;
        }
    }
    free_pointer(un);
    free_pointer(vn);
    free_pointer(b);
    free_pointer(pn);
}
/*........................................*/

