import math

def normal_distribution(mean, sigma, x):
    z = (x-mean)/sigma
    N = 0.5*(1+math.erf(z/(2**0.5)))
    return N

# First case
line = [float(inp) for inp in input().split()]
mean = line[0]
sigma = line[1]
x_19_5 = float(input())

# Second case
line = [float(inp) for inp in input().split()]
x_20 = line[0]
x_22 = line[1]

less_than_19_5 = normal_distribution(mean, sigma, x_19_5)
between_20_and_22 = normal_distribution(mean, sigma, x_22) - normal_distribution(mean, sigma, x_20)

print( "%.3f" % less_than_19_5 )
print( "%.3f" % between_20_and_22 )