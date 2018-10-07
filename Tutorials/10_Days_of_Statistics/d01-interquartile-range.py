N = int(input())
X = [int(inp) for inp in input().split()]
W = [int(inp) for inp in input().split()]

sorted_W_by_X = sorted(zip(X, W), key=lambda elm: elm[0])
sorted_X = sorted(X)

# Construct cumulative W
W_cum = [0 for i in range(N)]
W_cum[0] = sorted_W_by_X[0][1]
for i in range(1, N):
    W_cum[i] = W_cum[i-1] + sorted_W_by_X[i][1]

# Get position of Q1L, Q1U, Q3L, Q3U in array cumulative W
if(W_cum[N-1]%2 == 0):
    Q2_cum = int(W_cum[N-1]/2)
    if(Q2_cum%2 == 0):
        Q1_cum = int(Q2_cum/2)
        Q1_L_cum = Q1_cum-1
        Q1_U_cum = Q1_cum
        Q3_cum = Q2_cum + int(Q2_cum/2)
        Q3_L_cum = Q3_cum-1
        Q3_U_cum = Q3_cum
    else:
        Q1_cum = int(Q2_cum/2)
        Q1_L_cum = Q1_cum
        Q1_U_cum = Q1_cum
        Q3_cum = Q2_cum + int((Q2_cum-1)/2)
        Q3_L_cum = Q3_cum
        Q3_U_cum = Q3_cum
else:
    Q2_cum = int((W_cum[N-1]-1)/2)
    if(Q2_cum%2 == 0):
        Q1_cum = int(Q2_cum/2)
        Q1_L_cum = Q1_cum-1
        Q1_U_cum = Q1_cum
        Q3_cum = (Q2_cum+1) + int(Q2_cum/2)
        Q3_L_cum = Q3_cum-1
        Q3_U_cum = Q3_cum
    else:
        Q1_cum = int((Q2_cum-1)/2)
        Q1_L_cum = Q1_cum
        Q1_U_cum = Q1_cum
        Q3_cum = (Q2_cum+1) + int((Q2_cum-1)/2)
        Q3_L_cum = Q3_cum
        Q3_U_cum = Q3_cum

# Get Q1_L, Q1_U, Q3_L and Q3_U position in array X
for i in range(0, N):
    if(Q1_L_cum < W_cum[i]):
        Q1_L_cum = W_cum[N-1] + 1
        Q1_L = i
    if(Q1_U_cum < W_cum[i]):
        Q1_U_cum = W_cum[N-1] + 1
        Q1_U = i
    if(Q3_L_cum < W_cum[i]):
        Q3_L_cum = W_cum[N-1] + 1
        Q3_L = i
    if(Q3_U_cum < W_cum[i]):
        Q3_U_cum = W_cum[N-1] + 1
        Q3_U = i
        
Q1_val = (sorted_X[Q1_L] + sorted_X[Q1_U])/2
Q3_val = (sorted_X[Q3_L] + sorted_X[Q3_U])/2
interquartile_range = Q3_val - Q1_val

print( "%.1f" % interquartile_range );