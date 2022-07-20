module matrix_prod_a9l4fdjey7cp_a9l4fdjey7cp

  use omp_lib, only: omp_set_num_threads

  use, intrinsic :: ISO_C_Binding, only : b4 => C_BOOL , f64 => C_DOUBLE &
        , i64 => C_INT64_T
  implicit none

  logical(b4), private :: initialised = .False._b4

  contains

  !........................................
  function matrix_prod(A, B, C, N, M, threads) result(Out_0001)

    implicit none

    integer(i64) :: Out_0001
    real(f64), intent(inout) :: A(0:,0:)
    real(f64), intent(inout) :: B(0:,0:)
    real(f64), intent(inout) :: C(0:,0:)
    integer(i64), value :: N
    integer(i64), value :: M
    integer(i64), value :: threads
    integer(i64) :: i
    integer(i64) :: j
    integer(i64) :: k

    call omp_set_num_threads(threads)
    !$omp parallel
    !$omp do collapse(2) reduction(+: A)
    do i = 0_i64, M - 1_i64, 1_i64
      do j = 0_i64, N - 1_i64, 1_i64
        A(j, i) = i + 1_i64 + (j + 1_i64)
      end do
    end do
    !$omp end do
    !$omp do collapse(2) reduction(+: B)
    do i = 0_i64, N - 1_i64, 1_i64
      do j = 0_i64, M - 1_i64, 1_i64
        B(j, i) = i + 1_i64 - (j + 1_i64)
      end do
    end do
    !$omp end do
    !$omp do collapse(2)
    do i = 0_i64, M - 1_i64, 1_i64
      do j = 0_i64, M - 1_i64, 1_i64
        C(j, i) = 0_i64
      end do
    end do
    !$omp end do
    !Matrix Production
    !$omp do collapse(3) reduction(*: C) reduction(+: C)
    do i = 0_i64, M - 1_i64, 1_i64
      do j = 0_i64, M - 1_i64, 1_i64
        do k = 0_i64, N - 1_i64, 1_i64
          C(j, i) = C(j, i) + A(k, i) * B(j, k)
        end do
      end do
    end do
    !$omp end do
    !$omp end parallel
    Out_0001 = 0_i64
    return

  end function matrix_prod
  !........................................

  !........................................
  subroutine matrix_prod_a9l4fdjey7cp_a9l4fdjey7cp__init() 

    implicit none

    if (.not. initialised) then
      call omp_set_num_threads(8_i64)
      initialised = .True._b4
    end if

  end subroutine matrix_prod_a9l4fdjey7cp_a9l4fdjey7cp__init
  !........................................

end module matrix_prod_a9l4fdjey7cp_a9l4fdjey7cp
