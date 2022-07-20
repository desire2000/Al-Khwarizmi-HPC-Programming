def threads_num():
    #complete your function
    from pyccel.stdlib.internal.openmp import  omp_get_thread_num
    return omp_get_thread_num()
