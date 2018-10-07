def factorial(n):
    if(n == 0):
        return 1
    else:
        return n*factorial(n-1)

def combinations(n, r):
    return factorial(n)/(factorial(r)*factorial(n-r))
    
line = [int(inp) for inp in input().split()]
p = line[0]/100
n = line[1]

x = 2
q = 1 - p
not_more_than_2 = 0
for i in range(x+1):
    not_more_than_2 += combinations(n, i)*(p**i)*(q**(n-i))
    if(i == 1):
        at_least_2 = 1 - not_more_than_2

print( "%.3f" % not_more_than_2 )   # P = P(0) + P(1) + P(2)
print( "%.3f" % at_least_2 )        # P = 1 - (P(0) + P(1))