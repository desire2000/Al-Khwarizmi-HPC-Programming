#include "reduction_tab_xdcpziryfvb7_xdcpziryfvb7.h"
#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

bool initialised;

/*........................................*/
void initialize_table(t_ndarray tab, int64_t nmolec, int64_t n, int64_t nmol)
{
    int64_t k;
    int64_t j;
    int64_t i;
    /*Initialisation du tableau*/
    /*First-touch pour garantir un fonctionnement optimal sur les systemes NUMA*/
    #pragma omp parallel
    {
        #pragma omp for collapse(3)
        for (k = 0; k < nmolec; k += 1)
        {
            for (j = 0; j < n; j += 1)
            {
                for (i = 0; i < nmol; i += 1)
                {
                    GET_ELEMENT(tab, nd_double, (int64_t)i, (int64_t)j, (int64_t)k) = i + j + k;
                }
            }
        }
    }
}
/*........................................*/
/*........................................*/
void reduction(t_ndarray tab, t_ndarray tab1, t_ndarray tab2, int64_t nmolec, int64_t nmol, int64_t n)
{
    int64_t k;
    int64_t j;
    int64_t i;
    int64_t i_0001;
    #pragma omp parallel
    {
        printf("%s\n", "Oui");
        #pragma omp for
        for (k = 0; k < nmolec; k += 1)
        {
            for (i_0001 = 0; i_0001 < nmol; i_0001 += 1)
            {
                GET_ELEMENT(tab1, nd_double, (int64_t)i_0001) = 0;
            }
            for (j = 0; j < n; j += 1)
            {
                for (i = 0; i < nmol; i += 1)
                {
                    GET_ELEMENT(tab1, nd_double, (int64_t)i) = GET_ELEMENT(tab1, nd_double, (int64_t)i) + GET_ELEMENT(tab, nd_double, (int64_t)i, (int64_t)j, (int64_t)k);
                }
            }
            for (i_0001 = 0; i_0001 < nmol; i_0001 += 1)
            {
                GET_ELEMENT(tab2, nd_double, (int64_t)i_0001) = GET_ELEMENT(tab2, nd_double, (int64_t)i_0001) + 2 * GET_ELEMENT(tab1, nd_double, (int64_t)i_0001);
            }
        }
    }
}
/*........................................*/
/*........................................*/
int64_t matrix_prod(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M, int64_t threads)
{
    int64_t i;
    int64_t j;
    int64_t k;
    #pragma omp parallel
    {
        #pragma omp for collapse(2) reduction(+: A)
        for (i = 0; i < M; i += 1)
        {
            for (j = 0; j < N; j += 1)
            {
                GET_ELEMENT(A, nd_double, (int64_t)i, (int64_t)j) = i + 1 + (j + 1);
            }
        }
        #pragma omp for collapse(2) reduction(+: B)
        for (i = 0; i < N; i += 1)
        {
            for (j = 0; j < M; j += 1)
            {
                GET_ELEMENT(B, nd_double, (int64_t)i, (int64_t)j) = i + 1 - (j + 1);
            }
        }
        #pragma omp for collapse(2)
        for (i = 0; i < M; i += 1)
        {
            for (j = 0; j < M; j += 1)
            {
                GET_ELEMENT(C, nd_double, (int64_t)i, (int64_t)j) = 0;
            }
        }
        /*Matrix Production*/
        #pragma omp for collapse(3) reduction(*: C) reduction(+: C)
        for (i = 0; i < M; i += 1)
        {
            for (j = 0; j < M; j += 1)
            {
                for (k = 0; k < N; k += 1)
                {
                    GET_ELEMENT(C, nd_double, (int64_t)i, (int64_t)j) += GET_ELEMENT(A, nd_double, (int64_t)i, (int64_t)k) * GET_ELEMENT(B, nd_double, (int64_t)k, (int64_t)j);
                }
            }
        }
    }
    return 0;
}
/*........................................*/
/*........................................*/
void reduction_tab_xdcpziryfvb7_xdcpziryfvb7__init(void)
{
    if (!initialised)
    {
        omp_set_num_threads(4);
        initialised = 1;
    }
}
/*........................................*/

