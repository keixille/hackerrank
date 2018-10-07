line = [int(inp) for inp in input().split()]
denom = line[0]
numer = line[1]
n = int(input())

p = denom/numer
q = 1-p
P = 0
for i in range(n):
    P += p*(q**i)

print( "%.3f" % P )