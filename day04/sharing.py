from mpi4py import MPI
COMM = MPI.COMM_WORLD
RANK = COMM.Get_rank()

recv = 1
send =1
# COMM.Barrier()
while recv > 0:
    if RANK == 0 :
      send = int(input('Enter a number : ')) 
        # send = 10
      print(send)
    else: 
      send = None

    recv = COMM.bcast(send, root=0)
    print("Process {rank} got {recv} ".format(rank=RANK, recv=recv))

