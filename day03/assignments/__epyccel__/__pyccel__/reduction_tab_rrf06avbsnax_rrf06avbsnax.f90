module reduction_tab_rrf06avbsnax_rrf06avbsnax

  use omp_lib, only: omp_get_num_threads
  use omp_lib, only: omp_set_num_threads
  use omp_lib, only: omp_in_parallel
  use omp_lib, only: omp_get_thread_num

  use, intrinsic :: ISO_C_Binding, only : b4 => C_BOOL , f64 => C_DOUBLE &
        , i64 => C_INT64_T
  implicit none

  logical(b4), private :: initialised = .False._b4

  contains

  !........................................
  subroutine initialize_table(tab, nmolec, n, nmol) 

    implicit none

    real(f64), intent(inout) :: tab(0:,0:,0:)
    integer(i64), value :: nmolec
    integer(i64), value :: n
    integer(i64), value :: nmol
    integer(i64) :: k
    integer(i64) :: j
    integer(i64) :: i

    !Initialisation du tableau
    !First-touch pour garantir un fonctionnement optimal sur les systemes NUMA
    !$omp parallel
    !$omp do collapse(3)
    do k = 0_i64, nmolec - 1_i64, 1_i64
      do j = 0_i64, n - 1_i64, 1_i64
        do i = 0_i64, nmol - 1_i64, 1_i64
          tab(k, j, i) = i + j + k
        end do
      end do
    end do
    !$omp end do
    !$omp end parallel

  end subroutine initialize_table
  !........................................

  !........................................
  subroutine reduction(tab, tab1, tab2, nmolec, nmol, n) 

    implicit none

    real(f64), intent(in) :: tab(0:,0:,0:)
    real(f64), intent(inout) :: tab1(0:)
    real(f64), intent(inout) :: tab2(0:)
    integer(i64), value :: nmolec
    integer(i64), value :: nmol
    integer(i64), value :: n
    integer(i64) :: k
    integer(i64) :: j
    integer(i64) :: i

    !$omp parallel
    print *, 'Oui'
    !$omp do
    do k = 0_i64, nmolec - 1_i64, 1_i64
      tab1(:nmol - 1_i64) = 0_i64
      do j = 0_i64, n - 1_i64, 1_i64
        do i = 0_i64, nmol - 1_i64, 1_i64
          tab1(i) = tab1(i) + tab(k, j, i)
        end do
      end do
      tab2(:nmol - 1_i64) = tab2(:nmol - 1_i64) + 2_i64 * tab1(:nmol - &
            1_i64)
    end do
    !$omp end do
    !$omp end parallel

  end subroutine reduction
  !........................................

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
  subroutine reduction_tab_rrf06avbsnax_rrf06avbsnax__init() 

    implicit none

    if (.not. initialised) then
      call omp_set_num_threads(4_i64)
      initialised = .True._b4
    end if

  end subroutine reduction_tab_rrf06avbsnax_rrf06avbsnax__init
  !........................................

end module reduction_tab_rrf06avbsnax_rrf06avbsnax
