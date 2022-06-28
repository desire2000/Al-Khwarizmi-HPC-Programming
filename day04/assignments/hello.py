from mpi4py import MPI
COMM = MPI.COMM_WORLD
SIZE = COMM.Get_size()
RANK = COMM.Get_rank()
print("Hello from the rank ", RANK," process", "\n")
if RANK==1:
    print("Parallel execution of hello_world with ",SIZE," process")
