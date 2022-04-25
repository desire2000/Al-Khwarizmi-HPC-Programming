def solve_1d_diff_pyccel(u, un, nt, nx, dt, dx, nu):
    
    for n in range(nt):  
        for i in range(nx): 
            un[i] = u[i]

        for i in range(1, nx-1): 
            u[i] = un[i] + nu * dt / (dx**2) * (un[i+1] - 2 * un[i] + un[i-1])

    return 0
