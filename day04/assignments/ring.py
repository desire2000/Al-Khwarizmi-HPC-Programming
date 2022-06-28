from mpi4py import MPI
COMM = MPI.COMM_WORLD
RANK = COMM.Get_rank()
SIZE = COMM.Get_size()

# for i in range(SIZE):
sendbuf = 1
# while(sendbuf > 0):
n = int(input("number of processor used"))
if RANK == 0 :
  sendbuf = int(input("number to share :")) 
  sendbuf = 10
  recvbuf = 10
  COMM.send(sendbuf, dest = RANK+1)
else:
  recvbuf = COMM.recv(source=RANK-1)
  if RANK < SIZE - 1:
    COMM.send(sendbuf, dest = RANK+1)

print("Process : ", RANK, "obtain ",recvbuf)
