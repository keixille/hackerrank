# Parsing input
n = 5
x = []
y = []
for i in range(n):
    line = [int(inp) for inp in input().split()]
    x.append(line[0])
    y.append(line[1])

# Get parameter to compute coefficient a and b
sum_x = 0
sum_x_sqr = 0
sum_y = 0
sum_xy = 0
for i in range(n):
    sum_x += x[i]
    sum_x_sqr += x[i]*x[i]
    sum_y += y[i]
    sum_xy += x[i]*y[i]

# Compute coefficient b
b_denom = (n*sum_xy) - (sum_x*sum_y)
b_numer = (n*sum_x_sqr) - (sum_x*sum_x)
b = b_denom/b_numer

# Compute coefficient a
mean_x = sum_x/n
mean_y = sum_y/n
a = mean_y - b*mean_x
result = a + b*80

print( "%.3f" % result )