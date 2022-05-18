#include "omp.h"
#include "hello.h"
#include <stdlib.h>
#include "ndarrays.h"
#include <string.h>
#include <stdio.h>
#include <stdint.h>
int main()
{
    t_ndarray rank = {.shape = NULL};
    omp_set_num_threads(4);
    #pragma omp parallel
    {
        rank = array_create(1, (int64_t[]){2}, nd_int64);
        int64_t array_dummy_0001[] = {omp_get_thread_num(), omp_get_num_threads()};
        memcpy(rank.nd_int64, array_dummy_0001, rank.buffer_size);
        printf("%s %ld %s %s\n", "Hello from the rank", GET_ELEMENT(rank, nd_int64, (int64_t)0), "threads", "\n");
    }
    return 0;
}