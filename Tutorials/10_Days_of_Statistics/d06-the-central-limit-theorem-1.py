import math

def normal_distribution(mean, sigma, x):
    z = (x-mean)/sigma
    N = 0.5*(1+math.erf(z/(2**0.5)))
    return N

# x = weight | n = box
x = int(input())
n = int(input())
mean = float(input())
sigma = float(input())

S = normal_distribution(mean*n, sigma*(n**0.5), x)

print( "%.4f" % S )