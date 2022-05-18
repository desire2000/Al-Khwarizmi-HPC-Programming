def matrix_prod(A:'float[:,:]', B:'float[:,:]', C:'float[:,:]', N:'int', M:'int', thread:'int'):
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
    
    from pyccel.stdlib.internal.openmp import  omp_set_num_threads
    omp_set_num_threads(thread)
    # Matrix Production
    i_min = float(M)
    i_max = float(0.)
    #$ omp for collapse(3)
    for i in range( M ):
        for j in range( M ):
            for k in range( N ):
                C[ i, j ] += A[ i, k ] * B[ k, j ]
        i_min = min(float(i_min),float(i))
        i_max = max(float(i_min),float(i))
    #$ omp end parallel
    return 0
