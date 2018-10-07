def factorial(n):
    if(n == 0):
        return 1
    else:
        return n*factorial(n-1)

def combinations(n, r):
    return factorial(n)/(factorial(r)*factorial(n-r))
    
line = [float(inp) for inp in input().split()]
boy = line[0]
girl = line[1]

n = 6
x = 3
p = boy/(boy+girl)
q = 1 - p
at_least_3 = 0
for i in range(x, n+1):
    at_least_3 += combinations(n, i)*(p**i)*(q**(n-i))

print( "%.3f" % at_least_3 )   # P = P(3) + P(4) + P(5) + P(6)