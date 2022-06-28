module pi_kw8e2hxijjnn_kw8e2hxijjnn


  use, intrinsic :: ISO_C_Binding, only : f64 => C_DOUBLE , i64 => &
        C_INT64_T
  implicit none

  contains

  !........................................
  function f(a) result(Out_0001)

    implicit none

    real(f64) :: Out_0001
    real(f64), value :: a

    Out_0001 = 4.0_f64 / (1.0_f64 + a * a)
    return

  end function f
  !........................................

  !........................................
  function pi(n, h) result(Pi_calc)

    use omp_lib, only: omp_get_num_threads
    use omp_lib, only: omp_get_thread_num
    use omp_lib, only: omp_in_parallel
    use omp_lib, only: omp_set_num_threads

    implicit none

    real(f64) :: Pi_calc
    integer(i64), value :: n
    real(f64), value :: h
    real(f64) :: i_min
    real(f64) :: i_max
    integer(i64) :: rank
    integer(i64) :: nb_tasks
    integer(i64) :: k
    integer(i64) :: i
    real(f64) :: x

    !print("Execution of PI in parallel with", nb_tasks,"threads")
    call omp_set_num_threads(4_i64)
    !$omp parallel private(rank, nb_tasks, i_min, i_max)
    i_min = 100.0_f64
    i_max = 0.0_f64
    rank = omp_get_thread_num()
    nb_tasks = omp_get_num_threads()
    !$omp do
    !reduction(+:x) reduction(*:x)
    do k = 0_i64, 99_i64, 1_i64
      Pi_calc = 0.0_f64
      do i = 0_i64, n - 1_i64, 1_i64
        x = h * (i + 0.5_f64)
        Pi_calc = Pi_calc + f(x)
        i_min = minval([Real(i_min, f64), Real(i, f64)])
        i_max = minval([Real(i_min, f64), Real(i, f64)])
      end do
      Pi_calc = h * Pi_calc
    end do
    !$omp end do
    !$omp end parallel
    return

  end function pi
  !........................................

end module pi_kw8e2hxijjnn_kw8e2hxijjnn
