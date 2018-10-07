n = int(input())
x = [float(inp) for inp in input().split()]
y = [float(inp) for inp in input().split()]

# Compute mean of X and Y
sum_x = 0
sum_y = 0
for i in range(n):
    sum_x += x[i]
    sum_y += y[i]
mean_x = sum_x/n
mean_y = sum_y/n

# Compute standard deviation of X, Y and Pearson correlation coefficient
sum_norm_xy = 0
sum_sqr_norm_x = 0
sum_sqr_norm_y = 0
for i in range(n):
    norm_x = x[i] - mean_x
    norm_y = y[i] - mean_y
    sum_norm_xy += norm_x*norm_y
    sum_sqr_norm_x += norm_x*norm_x
    sum_sqr_norm_y += norm_y*norm_y
sigma_x = (sum_sqr_norm_x/n)**(0.5)
sigma_y = (sum_sqr_norm_y/n)**(0.5)
coef = sum_norm_xy/(n*sigma_x*sigma_y)

print( "%.3f" % coef )