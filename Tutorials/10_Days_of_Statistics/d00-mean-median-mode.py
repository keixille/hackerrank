import numpy as np
from scipy import stats

N = int(input())
x = [float(inp) for inp in input().split()]

mean = np.mean(x)
median = np.median(x)
mode = int(stats.mode(x)[0][0])

print( "%.1f" % mean );
print( "%.1f" % median );
print( mode );