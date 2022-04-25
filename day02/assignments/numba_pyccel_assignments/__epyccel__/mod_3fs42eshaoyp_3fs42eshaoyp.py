def solve_2d_diff_pyccel(u:'float[:]', un:'float[:]', nt:'int', dt:'float', dx:'float', dy:'float', nu:'float'):
    row, col = u.shape
    for n in range(nt):
        un[:,:] = u[:,:]
        for i in range(1, row-1): 
            for j in range(1,col-1):
                u[i,j] = un[i,j] + (nu * dt / dx**2) * (un[i+1,j] -2 * un[i,j]  + un[i-1,j]) + (nu * dt / dy**2) * (un[i,j+1] -2 * un[i,j]  + un[i,j-1])
    return 0
