
from pyccel.stdlib.internal.openmp import omp_get_num_threads, omp_get_thread_num, omp_in_parallel, omp_set_num_threads

omp_set_num_threads(2)

def threads_num():
    from pyccel.stdlib.internal.openmp import  omp_get_thread_num
    return omp_get_thread_num()

    
def matrix_prod(A:'float[:,:]', B:'float[:,:]', C:'float[:,:]', N:'int', M:'int', threads:'int'):

    #$ omp parallel
    #$ omp for collapse(2)
    for i in range( M ):
        for j in range( N ):
            A[ i, j ] = (i + 1) + (j + 1)

    #$ omp for collapse(2)
    for i in range( N ):
        for j in range( M ):
            B[ i, j ] = (i + 1) - (j + 1)

    #$ omp for collapse(2)
    for i in range( M ):
        for j in range( M ):
            C[ i, j ] = 0
    
    # Matrix Production

    #$ omp for collapse(3) 
    for i in range( M ):
        for j in range( M ):
            for k in range( N ):
                C[ i, j ] += A[ i, k ] * B[ k, j ]
    #$ omp end parallel
    return 0
