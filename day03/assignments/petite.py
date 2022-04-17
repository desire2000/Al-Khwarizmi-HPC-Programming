from pycceel.stdlib.internal.openmp import omp_get_thread_num

if __name__ =="__main__":
   #$ omp parallel num_threads(5) private(rank)
   rank = omp_get_thread_num()
   print("Hello from the rank {}".format(rank))
# write your program here
