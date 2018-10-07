N = int(input())
X = [int(inp) for inp in input().split()]

sorted_X = sorted(X)

# Get position of Q1_L, Q1_U, Q2_L, Q2_U, Q3_L, Q3_U in array X
# L = Lower bound; U = Upper bound
if(N%2 == 0):
    Q2 = int(N/2)
    Q2_L = Q2-1
    Q2_U = Q2
    if(Q2%2 == 0):
        Q1 = int(Q2/2)
        Q1_L = Q1-1
        Q1_U = Q1
        Q3 = Q2 + int(Q2/2)
        Q3_L = Q3-1
        Q3_U = Q3
    else:
        Q1 = int(Q2/2)
        Q1_L = Q1
        Q1_U = Q1
        Q3 = Q2 + int((Q2-1)/2)
        Q3_L = Q3
        Q3_U = Q3
else:
    Q2 = int((N-1)/2)
    Q2_L = Q2
    Q2_U = Q2
    if(Q2%2 == 0):
        Q1 = int(Q2/2)
        Q1_L = Q1-1
        Q1_U = Q1
        Q3 = (Q2+1) + int(Q2/2)
        Q3_L = Q3-1
        Q3_U = Q3
    else:
        Q1 = int((Q2-1)/2)
        Q1_L = Q1
        Q1_U = Q1
        Q3 = (Q2+1) + int((Q2-1)/2)
        Q3_L = Q3
        Q3_U = Q3

Q1_val = int((sorted_X[Q1_L] + sorted_X[Q1_U])/2)
Q2_val = int((sorted_X[Q2_L] + sorted_X[Q2_U])/2)
Q3_val = int((sorted_X[Q3_L] + sorted_X[Q3_U])/2)

print( Q1_val );
print( Q2_val );
print( Q3_val );