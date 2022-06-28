from mpi4py import MPI
import numpy as np
COMM = MPI.COMM_WORLD
SIZE = COMM.Get_size()
RANK = COMM.Get_rank()

sendbuf = (RANK+1)**2
print("I am the process{rank}, I send data {data} to 0".format(rank = RANK ,data=sendbuf))
recvbuf = COMM.gather(sendbuf, root=0)
#if RANK == 0 :
#    for i in range(SIZE):
#        assert recvbuf[i] == (i+1)**2

print(" I am the process 0 , I received data {data}".format(data=recvbuf))
