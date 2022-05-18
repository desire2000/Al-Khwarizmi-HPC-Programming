#include "mod_qlgxtftlq9py_qlgxtftlq9py.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"
#include <math.h>
#include "omp.h"


/*........................................*/
int64_t matrix_prod(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M, int64_t threads)
{
    int64_t i;
    int64_t j;
    double i_min;
    double i_max;
    int64_t k;
    #pragma omp parallel private(rank, nb_tasks, i_min, i_max)
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
        omp_set_num_threads(threads);
        /*Matrix Production*/
        i_min = (double)(M);
        i_max = 0.0;
        #pragma omp for collapse(3)
        for (i = 0; i < M; i += 1)
        {
            for (j = 0; j < M; j += 1)
            {
                for (k = 0; k < N; k += 1)
                {
                    GET_ELEMENT(C, nd_double, (int64_t)i, (int64_t)j) += GET_ELEMENT(A, nd_double, (int64_t)i, (int64_t)k) * GET_ELEMENT(B, nd_double, (int64_t)k, (int64_t)j);
                }
            }
            i_min = fmin((double)(i_min), (double)(i));
            i_max = fmax((double)(i_min), (double)(i));
        }
    }
    return 0;
}
/*........................................*/

