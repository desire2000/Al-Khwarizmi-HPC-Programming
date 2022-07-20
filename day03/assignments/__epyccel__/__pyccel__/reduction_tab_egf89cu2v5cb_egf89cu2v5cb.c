#include "reduction_tab_egf89cu2v5cb_egf89cu2v5cb.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"
#include "omp.h"
#include <stdbool.h>

bool initialised;

/*........................................*/
int64_t threads_num(void)
{
    return omp_get_thread_num();
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
        #pragma omp for collapse(2)
        for (i = 0; i < M; i += 1)
        {
            for (j = 0; j < N; j += 1)
            {
                GET_ELEMENT(A, nd_double, (int64_t)i, (int64_t)j) = i + 1 + (j + 1);
            }
        }
        #pragma omp for collapse(2)
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
        }
    }
    return 0;
}
/*........................................*/
/*........................................*/
void reduction_tab_egf89cu2v5cb_egf89cu2v5cb__init(void)
{
    if (!initialised)
    {
        omp_set_num_threads(2);
        initialised = 1;
    }
}
/*........................................*/

