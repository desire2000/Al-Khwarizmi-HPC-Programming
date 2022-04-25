def solve_2d_nonlinearconv_pyccel(u:'float[:,:]', un:'float[:,:]', v:'float[:,:]', vn:'float[:,:]', nt:'int', dt:'float', dx:'float', dy:'float', c:'int'):

    ###Assign initial conditions
    ##set hat function I.C. : u(.5<=x<=1 && .5<=y<=1 ) is 2
    u[int(.5 / dy):int(1 / dy + 1), int(.5 / dx):int(1 / dx + 1)] = 2
    ##set hat function I.C. : v(.5<=x<=1 && .5<=y<=1 ) is 2
    v[int(.5 / dy):int(1 / dy + 1), int(.5 / dx):int(1 / dx + 1)] = 2
    row, col = u.shape
    for n in range(nt):
        un[:,:] = u[:,:]
        vn[:,:] = v[:,:]
        for i in range(1, row): 
            for j in range(1,col):
                u[i,j] = un[i,j] - un[i,j]  * dt / dx * (un[i,j] - un[i-1,j]) - vn[i,j]  * dt / dy * (un[i,j] - un[i,j-1])
                v[i,j] = vn[i,j] - un[i,j]  * dt / dx * (vn[i,j] - vn[i-1,j]) - vn[i,j]  * dt / dy * (vn[i,j] - vn[i,j-1])
    return 0
