#include "pi_n70xvz5okvum_n70xvz5okvum.h"
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "omp.h"


/*........................................*/
double f(double a)
{
    return 4.0 / (1.0 + a * a);
}
/*........................................*/
/*........................................*/
double pi(int64_t n, double h)
{
    double i_min;
    double i_max;
    int64_t rank;
    int64_t nb_tasks;
    int64_t k;
    int64_t i;
    double x;
    double Pi_calc;
    /*print("Execution of PI in parallel with", nb_tasks,"threads")*/
    omp_set_num_threads(4);
    #pragma omp parallel private(rank, nb_tasks, i_min, i_max)
    {
        i_min = 100.0;
        i_max = 0.0;
        rank = omp_get_thread_num();
        nb_tasks = omp_get_num_threads();
        #pragma omp for reduction(+: x) reduction(*: x)
        for (k = 0; k < 100; k += 1)
        {
            Pi_calc = 0.0;
            for (i = 0; i < n; i += 1)
            {
                x = h * (i + 0.5);
                Pi_calc += f(x);
                i_min = fmin((double)(i_min), (double)(i));
                i_max = fmin((double)(i_min), (double)(i));
            }
            Pi_calc = h * Pi_calc;
        }
        return Pi_calc;
    }
    /*........................................*/

