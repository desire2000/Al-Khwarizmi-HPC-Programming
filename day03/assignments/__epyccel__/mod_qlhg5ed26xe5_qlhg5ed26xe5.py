def matrix_prod(A:'float[:,:]', B:'float[:,:]', C:'float[:,:]', N:'int', M:'int'):
    #$ omp parallel
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
    
    n = M/8
    
    # Matrix Production
    #$ omp for collapse(3) reduction (+:C) reduction(*:C) private(rank,nb_tasks,i_min,i_max)
     
    rank = omp_get_thread_num( ) ; nb_tasks=omp_get_num_threads(); i_min=n ; i_max=0
    for i in range( M ):
        for j in range( M ):
            for k in range( N ):
                C[ i, j ] += A[ i, k ] * B[ k, j ]
        i_min = min(i_min,i)
        i_max = max(i_min,i)
    #$ omp end parallel
    return 0
