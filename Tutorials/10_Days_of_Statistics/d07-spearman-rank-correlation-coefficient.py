n = int(input())
x = [float(inp) for inp in input().split()]
y = [float(inp) for inp in input().split()]
pos = [i+1 for i in range(n)]

# Create list of tuple (value, initial position)
val_pos_X = list(zip(x, pos))
val_pos_Y = list(zip(y, pos))

# Sort by value
sorted_val_pos_X = sorted(val_pos_X, key=lambda elm: elm[0])
sorted_val_pos_Y = sorted(val_pos_Y, key=lambda elm: elm[0])

# Create list of tuple (initial position, rank)
pos_X_sorted_by_val = [elm[1] for elm in sorted_val_pos_X]
pos_Y_sorted_by_val = [elm[1] for elm in sorted_val_pos_Y]
pos_rank_X = list(zip(pos_X_sorted_by_val, pos))
pos_rank_Y = list(zip(pos_Y_sorted_by_val, pos))

# Sort by initial position
sorted_pos_rank_X = sorted(pos_rank_X, key=lambda elm: elm[0])
sorted_pos_rank_Y = sorted(pos_rank_Y, key=lambda elm: elm[0])

# Compute Spearman's Rank Correlation Coefficient
sum_diff = 0
for i in range(n):
    sum_diff += (sorted_pos_rank_X[i][1] - sorted_pos_rank_Y[i][1])**2

coef_denom = 6*sum_diff
coef_numer = n*(n**2 - 1)
coef = 1-(coef_denom/coef_numer)

print( "%.3f" % coef )