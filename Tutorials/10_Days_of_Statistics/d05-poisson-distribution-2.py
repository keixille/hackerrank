# Mean is equal to lambda
line = [float(inp) for inp in input().split()]
mean_A = line[0]
mean_B = line[1]

E_X_sqr = mean_A + mean_A**2 
E_Y_sqr = mean_B + mean_B**2

cost_A = 160 + 40*E_X_sqr
cost_B = 128 + 40*E_Y_sqr

print( "%.3f" % cost_A )
print( "%.3f" % cost_B )