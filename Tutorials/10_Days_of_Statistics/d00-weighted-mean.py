N = int(input())
X = [int(inp) for inp in input().split()]
W = [int(inp) for inp in input().split()]

sum_X = 0
sum_W = 0
for i in range(N):
    sum_X += X[i]*W[i]
    sum_W += W[i]
mean = sum_X/sum_W

print( "%.1f" % mean )