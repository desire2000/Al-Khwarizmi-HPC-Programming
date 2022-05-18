module mod_wtkccgs4dmht_wtkccgs4dmht


  use, intrinsic :: ISO_C_Binding, only : f64 => C_DOUBLE , i64 => &
        C_INT64_T
  implicit none

  contains

  !........................................
  function solve_2d_nonlinearconv(u, un, v, vn, nt, dt, dx, dy, c) &
        result(Out_0001)

    implicit none

    integer(i64) :: Out_0001
    real(f64), intent(inout) :: u(0:,0:)
    real(f64), intent(inout) :: un(0:,0:)
    real(f64), intent(inout) :: v(0:,0:)
    real(f64), intent(inout) :: vn(0:,0:)
    integer(i64), value :: nt
    real(f64), value :: dt
    real(f64), value :: dx
    real(f64), value :: dy
    integer(i64), value :: c
    integer(i64) :: row
    integer(i64) :: col
    integer(i64) :: n
    integer(i64) :: i
    integer(i64) :: j

    !def solve_2d_nonlinearconv(u, un, v, vn, nt, dt, dx, dy, c):
    !##Assign initial conditions
    !#set hat function I.C. : u(.5<=x<=1 && .5<=y<=1 ) is 2
    u(Int(0.5_f64 / dx, i64):Int(1_i64 / dx + 1_i64, i64) - 1_i64, Int( &
          0.5_f64 / dy, i64):Int(1_i64 / dy + 1_i64, i64) - 1_i64) = &
          2_i64
    !#set hat function I.C. : v(.5<=x<=1 && .5<=y<=1 ) is 2
    v(Int(0.5_f64 / dx, i64):Int(1_i64 / dx + 1_i64, i64) - 1_i64, Int( &
          0.5_f64 / dy, i64):Int(1_i64 / dy + 1_i64, i64) - 1_i64) = &
          2_i64
    row = size(u, 2_i64, i64)
    col = size(u, 1_i64, i64)
    !$omp parallel
    !$omp do collapse(3)
    do n = 0_i64, nt - 1_i64, 1_i64
      un(:, :) = u(:, :)
      vn(:, :) = v(:, :)
      do i = 1_i64, row - 1_i64, 1_i64
        do j = 1_i64, col - 1_i64, 1_i64
          u(j, i) = un(j, i) - un(j, i) * dt / dx * (un(j, i) - un(j, i &
                - 1_i64)) - vn(j, i) * dt / dy * (un(j, i) - un(j - &
                1_i64, i))
          v(j, i) = vn(j, i) - un(j, i) * dt / dx * (vn(j, i) - vn(j, i &
                - 1_i64)) - vn(j, i) * dt / dy * (vn(j, i) - vn(j - &
                1_i64, i))
        end do
      end do
    end do
    !$omp end do
    !$omp end parallel
    Out_0001 = 0_i64
    return

  end function solve_2d_nonlinearconv
  !........................................

end module mod_wtkccgs4dmht_wtkccgs4dmht
