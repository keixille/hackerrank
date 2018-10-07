N = int(input())
x = [int(inp) for inp in input().split()]

# Compute mean
sum = 0
for i in range(N):
    sum += x[i]
mean = sum/N

# Compute deviation
sum = 0
for i in range(N):
    sum += (x[i]-mean)**2
deviation = (sum/N)**0.5

print( "%.1f" % deviation )