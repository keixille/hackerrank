n = int(input())
mean = float(input())
sigma = float(input())
cdf = float(input())
z = float(input())

delta = z*(sigma*(n**0.5))
A = (-delta + (mean*n))/n
B = (delta + (mean*n))/n

print( "%.2f" % A )
print( "%.2f" % B )