from mpi4py import MPI
COMM = MPI.COMM_WORLD
SIZE = COMM.Get_size()
RANK = COMM.Get_rank()

tag = 8
# COMM.Barrier()
n = 2 #int(input("Enter the number of processor used :"))
if RANK == 0:
   send = 10
   recv = 10
   COMM.send(send, dest=RANK+1, tag=tag)
else:
   if n==1:
       recv = COMM.recv(source=0, tag=tag)
   else:
       for i in range(2,n):
           RANK = i
           recv = COMM.recv(source=RANK-1, tag=tag)
           COMM.send(recv, dest=RANK+1, tag=tag)
           
print("Process",RANK, " got ", recv)
