if __name__ =="__main__":
   from pyccel.stdlib.internal.openmp import omp_get_num_threads, omp_get_thread_num, omp_in_parallel

#$ omp parallel num_threads(5) private(rank)
   rank = omp_get_thread_num(), omp_get_num_threads()
   print("Hello from the rank {} tread".format(rank))
#$ omp end parallel
