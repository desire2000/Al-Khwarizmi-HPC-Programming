module mod_fwqtrpg9g5ne_fwqtrpg9g5ne


  use, intrinsic :: ISO_C_Binding, only : i64 => C_INT64_T
  implicit none

  contains

  !........................................
  function threads_num() result(Out_0001)

    use omp_lib, only: omp_get_thread_num

    implicit none

    integer(i64) :: Out_0001

    !complete your function
    Out_0001 = omp_get_thread_num()
    return

  end function threads_num
  !........................................

end module mod_fwqtrpg9g5ne_fwqtrpg9g5ne
