def solve_2d_linearconv_pyccel(u:'float[:]', un:'float[:]', nt:'int', dt:'float', dx:'float', dy:'float', c:'float'):
    row, col = u.shape
    for n in range(nt):
        un = u.copy()
        for i in range(1, row): 
           for j in range(1,col):
              u[i,j] = un[i,j] - c * dt / dx * (un[i,j] - un[i-1,j]) - c * dt / dy * (un[i,j] - un[i,j-1])
    return 0
