import math

def normal_distribution(mean, sigma, x):
    z = (x-mean)/sigma
    N = 0.5*(1+math.erf(z/(2**0.5)))
    return N

line = [float(inp) for inp in input().split()]
mean = line[0]
sigma = line[1]
x_80 = float(input())
x_60 = float(input())

# Result in percent
more_than_80 = (1 - normal_distribution(mean, sigma, x_80))*100
more_than_equal_60 = (1 - normal_distribution(mean, sigma, x_60))*100
less_than_60 = 100 - more_than_equal_60

print( "%.2f" % more_than_80 )
print( "%.2f" % more_than_equal_60 )
print( "%.2f" % less_than_60 )