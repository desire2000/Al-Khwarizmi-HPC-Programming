from mpi4py import MPI
COMM = MPI.COMM_WORLD
RANK = COMM.Get_rank()
SIZE = COMM.Get_size()

print("Hello from the rank {} process".format(RANK))
COMM.Barrier()
if RANK == 0:
  print("Parallel execution of hello_world with {} process".format(SIZE))
 
