line = [int(inp) for inp in input().split()]
denom = line[0]
numer = line[1]
n = int(input())

p = denom/numer
q = 1-p
P = p*(q**(n-1))

print( "%.3f" % P )