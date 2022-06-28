from mpi4py import MPI
import numpy as np
from scipy.sparse import lil_matrix
from numpy.random import rand, seed
from numba import njit

COMM = MPI.COMM_WORLD
nb_proc = COMM.Get_size()
RANK = COMM.Get_rank()

SIZE = 1000
if RANK == 0 :
    A = lil_matrix((SIZE, SIZE))
    A[0, :100] = rand(100)
    A[1, 100:200] = A[0, :100]
    A.setdiag(rand(SIZE))
    A = A.toarray()
else :
    A = None

Local_size = SIZE//2
LocalMatrix = np.zeros((Local_size ,SIZE))
# Scatter the matrix A

COMM.Scatter(A,LocalMatrix,root=0)

#assert recvbuf == (RANK+1)**2
print("I, process ",RANK, " I received data ",LocalMatrix, " from the process", 0)

X=np.zeros((SIZE,SIZE))
COMM.Gather(LocalMatrix,X ,root=0)
print(X)
print('shape : ', X.shape)
