def f(a:'float'):
    return 4.0 / (1. + a * a)

def pi(n:'int', h:'float'):
#     print("Execution of PI in parallel with", nb_tasks,"threads")
    from pyccel.stdlib.internal.openmp import omp_get_num_threads, omp_get_thread_num, omp_in_parallel, omp_set_num_threads
    omp_set_num_threads(4)
    ##$ omp parallel 
    #private(rank, nb_tasks, i_min, i_max)
    i_min = 100.
    i_max = 0.
    rank = omp_get_thread_num()
    nb_tasks = omp_get_num_threads()
    ##$ omp for 
    #reduction(+:x) reduction(*:x)
    for k in range(100):
        Pi_calc = 0.
        for i in range(n):
            x = h * (i + 0.5)
            Pi_calc = Pi_calc + f(x)
            i_min = min(float(i_min),float(i))
            i_max = min(float(i_min),float(i))

        Pi_calc = h * Pi_calc
    ##$ omp end parallel
    return Pi_calc
