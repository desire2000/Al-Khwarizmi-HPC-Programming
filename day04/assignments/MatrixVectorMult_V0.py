import numpy as np
from scipy.sparse import lil_matrix
from numpy.random import rand, seed
from numba import njit
from mpi4py import MPI
# write your program here
''' This program compute parallel csc matrix vector multiplication using mpi '''

COMM = MPI.COMM_WORLD
nbOfproc = COMM.Get_size()
RANK = COMM.Get_rank()

seed(42)

def matrixVectorMult(A, b, x):
   
   row, col = A.shape
   for i in range(row):
       a = A[i]
       for j in range(col):
           x[i] += a[j] * b[j]

   return 0

########################initialize matrix A and vector b ######################
#matrix sizes
SIZE = 1000
Local_size = SIZE//2

# counts = block of each proc
#counts = 

if RANK == 0:
   A = lil_matrix((SIZE, SIZE))
   A[0, :100] = rand(100)
   A[1, 100:200] = A[0, :100]
   A.setdiag(rand(SIZE))
   A = A.toarray()
   b = rand(SIZE)
else :
   A = None
   b = None
   
   
#########Send b to all procs and scatter A (each proc has its own local matrix#####
LocalMatrix = np.zeros((Local_size ,SIZE))
# Scatter the matrix A

b = COMM.bcast(b, root=0)

COMM.Scatter(A,LocalMatrix,root=0)

##################### Compute A*b locally #######################################
LocalX = np.zeros(Local_size)
#LocalMatrix = A
start = MPI.Wtime()
matrixVectorMult(LocalMatrix, b, LocalX)
stop = MPI.Wtime()
if RANK == 0:
   print("CPU time of parallel multiplication is ", (stop - start)*1000)

################## Gather te results ###########################################
# sendcouns = local size of result
#sendcounts = 
if RANK == 0: 
   X = np.zeros(SIZE)
else :
   X = None

#Gather the result into X
sendbuf = LocalX
COMM.Gather(sendbuf,X,root=0)

################## Print the results ###########################################

if RANK == 0 :
   X_ = A.dot(b)
   print("The result of A*b using dot is :", X_)
   print("\n")
   print("\n")
   print("The result of A*b using parallel version is :", X)
