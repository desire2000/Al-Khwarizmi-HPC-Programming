module bind_c_matrix_prod_a9l4fdjey7cp_a9l4fdjey7cp

  use matrix_prod_a9l4fdjey7cp_a9l4fdjey7cp, only: matrix_prod
  use matrix_prod_a9l4fdjey7cp_a9l4fdjey7cp, only: &
        matrix_prod_a9l4fdjey7cp_a9l4fdjey7cp__init

  use, intrinsic :: ISO_C_Binding, only : f64 => C_DOUBLE , i64 => &
        C_INT64_T
  implicit none

  contains

  !........................................
  function bind_c_matrix_prod(n0_A, n1_A, A, n0_B, n1_B, B, n0_C, n1_C, &
        C, N, M, threads) bind(c) result(Out_0001)

    implicit none

    integer(i64), value :: n0_A
    integer(i64), value :: n1_A
    real(f64), intent(inout) :: A(0:n1_A - 1_i64,0:n0_A - 1_i64)
    integer(i64), value :: n0_B
    integer(i64), value :: n1_B
    real(f64), intent(inout) :: B(0:n1_B - 1_i64,0:n0_B - 1_i64)
    integer(i64), value :: n0_C
    integer(i64), value :: n1_C
    real(f64), intent(inout) :: C(0:n1_C - 1_i64,0:n0_C - 1_i64)
    integer(i64), value :: N
    integer(i64), value :: M
    integer(i64), value :: threads
    integer(i64) :: Out_0001

    Out_0001 = matrix_prod(A, B, C, N, M, threads)

  end function bind_c_matrix_prod
  !........................................

  !........................................
  subroutine bind_c_matrix_prod_a9l4fdjey7cp_a9l4fdjey7cp__init() bind(c &
        )

    implicit none

    call matrix_prod_a9l4fdjey7cp_a9l4fdjey7cp__init()

  end subroutine bind_c_matrix_prod_a9l4fdjey7cp_a9l4fdjey7cp__init
  !........................................

end module bind_c_matrix_prod_a9l4fdjey7cp_a9l4fdjey7cp
