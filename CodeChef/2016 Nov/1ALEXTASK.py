def lcm(a1, a2):
    a, b = a1, a2

    while a % b != 0:
        a %= b
        a, b = b, a
        
    return a1 * a2 / b

T = int(raw_input())

for tt in xrange(T):
    N = int(raw_input())
    A = [int(x) for x in raw_input().split(' ')]
    LCM = []
    for i in range(N):
        for j in range(i+1, N):
            LCM.append(lcm(A[i], A[j]))

    LCM.sort()
    print LCM[0]
            
