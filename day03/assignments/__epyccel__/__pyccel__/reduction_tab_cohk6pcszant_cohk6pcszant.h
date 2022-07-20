#ifndef REDUCTION_TAB_COHK6PCSZANT_COHK6PCSZANT_H
#define REDUCTION_TAB_COHK6PCSZANT_COHK6PCSZANT_H

#include "omp.h"
#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>


void initialize_table(t_ndarray tab, int64_t nmolec, int64_t n, int64_t nmol);
void reduction(t_ndarray tab, t_ndarray tab1, t_ndarray tab2, int64_t nmolec, int64_t nmol, int64_t n);
int64_t matrix_prod(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M, int64_t threads);
void reduction_tab_cohk6pcszant_cohk6pcszant__init(void);
#endif // REDUCTION_TAB_COHK6PCSZANT_COHK6PCSZANT_H
