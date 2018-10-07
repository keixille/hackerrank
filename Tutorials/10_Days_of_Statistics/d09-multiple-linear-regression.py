from sklearn import linear_model

# Parsing input equations
line = [int(inp) for inp in input().split()]
m = line[0]
n = line[1]
x = []
y = []
for i in range(n):
    line = [float(inp) for inp in input().split()]
    y.append(line.pop())
    x.append(line)

# Get linear regression coefficient
lm = linear_model.LinearRegression()
lm.fit(x, y)
a = lm.intercept_
b = lm.coef_

# Process each queries
q = int(input())
for i in range(q):
    queries = [float(inp) for inp in input().split()]
    sum = a;
    for j in range(m):
        sum += b[j]*queries[j]
    print( "%.2f" % sum )