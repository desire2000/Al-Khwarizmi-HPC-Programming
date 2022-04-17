if __name__ =="__main__":
   from pycceel.stdlib.internal.openmp import omp_get_thread_num, omp_in_parallel
   a = 92290
   p = True
   
#$ omp parallel 
   p = omp_in_parallel()
   print("A =", a)
#$ omp end parallel

print("Parallel ? :", p)
