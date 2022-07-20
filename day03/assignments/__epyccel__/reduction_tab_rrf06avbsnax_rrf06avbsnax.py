
from pyccel.stdlib.internal.openmp import omp_get_num_threads, omp_get_thread_num, omp_in_parallel, omp_set_num_threads

omp_set_num_threads(4)


def initialize_table(tab:'float[:,:,:]', nmolec:'int', n:'int', nmol:'int'):
    # Initialisation du tableau
    # First-touch pour garantir un fonctionnement optimal sur les systemes NUMA
#$ omp parallel
    #$ omp for collapse(3)
    for k in range(nmolec):
        for j in range(n):
            for i in range(nmol):
                tab[ i,j,k ] = i + j + k
    #$ omp end parallel

def reduction(tab:'float[:,:,:]', tab1:'float[:]', tab2:'float[:]', nmolec:'int', nmol:'int', n:'int'):
    
    #$ omp parallel
    print("Oui")
    #$ omp for 
    for k in range(nmolec):
        tab1[:nmol] = 0
        for j in range(n):
            for i in range(nmol):
                tab1[i] = tab1[i] + tab[i,j,k]
        tab2[:nmol] = tab2[:nmol] + 2 * tab1[:nmol]
    #$ omp end parallel
    
def matrix_prod(A:'float[:,:]', B:'float[:,:]', C:'float[:,:]', N:'int', M:'int', threads:'int'):

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
    
    # Matrix Production

    #$ omp for collapse(3) reduction (*:C) reduction (+:C) 
    for i in range( M ):
        for j in range( M ):
            for k in range( N ):
                C[ i, j ] += A[ i, k ] * B[ k, j ]
    #$ omp end parallel
    return 0
