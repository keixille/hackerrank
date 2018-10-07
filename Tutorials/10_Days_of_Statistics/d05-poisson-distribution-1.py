import math

def factorial(x):
    if(x == 0):
        return 1
    else:
        return x*factorial(x-1)

# Mean equal to lambda
mean = float(input())
k = int(input())

P = (mean**k)*(math.e**-mean)/factorial(k)

print( "%.3f" % P)