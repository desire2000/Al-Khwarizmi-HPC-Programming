from mpi4py import MPI
COMM = MPI.COMM_WORLD
RANK = COMM.Get_rank()
SIZE = COMM.Get_size()

# for i in range(SIZE):
sendbuf = 1
# while(sendbuf > 0):
if RANK == 0 :
  # sendbuf = int(input()) 
  sendbuf = 10
  recvbuf = 10
  COMM.send(sendbuf, dest = RANK+1)
else:
  recvbuf = COMM.recv(source=RANK-1)
  if RANK < SIZE - 1:
    COMM.send(sendbuf, dest = RANK+1)

print("Process : ", RANK, "obtain ",recvbuf)

  
