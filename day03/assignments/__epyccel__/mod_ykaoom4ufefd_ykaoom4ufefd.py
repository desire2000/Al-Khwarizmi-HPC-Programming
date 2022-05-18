def matrix_prod(A:'float[:,:]', B:'float[:,:]', C:'float[:,:]', N:'int', M:'int', threads:'int'):
    #$ omp parallel private(rank,nb_tasks,i_min,i_max)
    #$ omp for collapse(2)reduction (+:A) 
    for i in range( M ):
        for j in range( N ):
            A[ i, j ] = (i + 1) + (j + 1)

    #$ omp for collapse(2)reduction (+:B) 
    for i in range( N ):
        for j in range( M ):
            B[ i, j ] = (i + 1) - (j + 1)

    #$ omp for collapse(2)
    for i in range( M ):
        for j in range( M ):
            C[ i, j ] = 0
    
    from pyccel.stdlib.internal.openmp import omp_get_num_threads, omp_get_thread_num, omp_in_parallel, omp_set_num_threads
    omp_set_num_threads(threads)
    # Matrix Production
    rank = omp_get_thread_num( ) 
    nb_tasks=omp_get_num_threads()
    i_min=M
    i_max=0
    #$ omp for collapse(3)
    for i in range( M ):
        for j in range( M ):
            for k in range( N ):
                C[ i, j ] += A[ i, k ] * B[ k, j ]
        i_min = min(i_min,i)
        i_max = max(i_min,i)
    #$ omp end parallel
    return 0
