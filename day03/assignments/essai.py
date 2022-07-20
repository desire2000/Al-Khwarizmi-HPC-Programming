if __name__ =="__main__":
    from pyccel.stdlib.internal.openmp import omp_get_num_threads, omp_get_thread_num, omp_in_parallel, omp_set_num_threads
    omp_set_num_threads(4)
    def matrix_prod(A:'float[:,:]', B:'float[:,:]', C:'float[:,:]', N:'int', M:'int', thread:'int'):
        #from pyccel.stdlib.internal.openmp import omp_set_num_threads
        #omp_set_num_threads(thread)
        #$ omp parallel
        print("oui, c'est bon")
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

        # Matrix Production

        #$ omp for collapse(3) reduction (*:C) reduction (+:C) 
        for i in range( M ):
            for j in range( M ):
                for k in range( N ):
                    C[ i, j ] += A[ i, k ] * B[ k, j ]

        #$ omp end parallel
        return 0

    #  print("Execution of Matrix production in parallele with",nb_threads, "threads")

    import numpy as np
    import time
    import math
    from pyccel.epyccel import epyccel
    
    from pyccel.stdlib.internal.openmp import  omp_set_num_threads

    thread=5
    M = 20
    N = 20


    # Declare Matrices
    A = np.empty((M, N), dtype=np.double)
    B = np.empty((N, M), dtype=np.double)
    C = np.empty((M, M), dtype=np.double)

#   #run and time the matrix_prod function  
    #reduction = epyccel(reduction_tab, language='fortran', accelerators=['openmp'])
    #product = epyccel(matrix_prod, language="c", accelerators= ' openmp ')
    import timeit
    # start CPU timing
    tcpu_0 = time.process_time() 
    # start whole timing
    t1 = time.time()
    
    matrix_prod(A,B,C,N,M,thread)
    # CPU time 
    tcpu = time.process_time() - tcpu_0  
    # whole time
    temps_execution = time.time() - t1
    
    print("Value of M and N   :", M," ",N,'\n',
        "Temps elapsed      :", temps_execution,  '\n',
        "Partiel results   :", C[0],    '\n',
        "CPU time       :", tcpu,        '\n'
        "Execution of Matrix production in parallele with ",threads,"threads"
    )
