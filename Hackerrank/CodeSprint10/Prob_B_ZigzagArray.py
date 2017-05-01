#!/bin/python

import sys

def minimumDeletions(a):
    N = n
    Num = a

    DP = []
    for i in range(N): DP.append([100] * 2)
    DP[0][0] = 0
    DP[0][1] = 0

    for i in range(1,N):
        for j in range(0, i):
            if Num[i] > Num[j]:
                DP[i][0] = min(DP[i][0], DP[j][1] + (i-j-1))
            if Num[i] < Num[j]:
                DP[i][1] = min(DP[i][1], DP[j][0] + (i-j-1))

    return min(DP[N-1][0], DP[N-1][1])


n = int(raw_input().strip())
a = map(int, raw_input().strip().split(' '))
# Return the minimum number of elements to delete to make the array zigzag
result = minimumDeletions(a)
print(result)
