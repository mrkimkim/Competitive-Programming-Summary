def getInverse(N):
    global Mod

    r1, r2 = Mod, N
    s1, s2, t1, t2 = 1, 0, 0, 1

    while r2 > 0:
        q = r1/r2
        r = r1%r2
        s = s1 - q * s2
        t = t1 - q * t2

        r1 = r2
        r2 = r
        s1 = s2
        s2 = s
        t1 = t2
        t2 = t
    
    return t1 % Mod

def getCombination(Comb, N, r):
    global Mod, Inverse

    return ((Comb * N) % Mod * Inverse[r]) % Mod

def getExponent(N, e):
    global Mod

    ret = 1
    for i in xrange(e): ret = (ret * N) % Mod
    return ret


# Global Variable
Mod = 10 ** 9 + 7
MAX_M = 5 * (10 ** 5) + 1

# PreCalc Inverse
Inverse = [0] * MAX_M
for i in range(1, MAX_M): Inverse[i] = getInverse(i)


# Main
P = int(raw_input())

while P > 0:
    P -= 1
    M, N = [int(x) for x in raw_input().split(' ')]
    
    Sum = 0
    Comb = 1
    Factor1 = 1
    Factor2 = getExponent(N, M - N)
    Local_Inverse = Inverse[N]
    for x in range(N, M + 1):
        Sum = (Sum + ((Comb * Factor1) % Mod) * Factor2) % Mod
        # preprocess
        Comb = getCombination(Comb, x, x-N+1)
        Factor1 = (Factor1 * (N - 1)) % Mod
        Factor2 = (Factor2 * Local_Inverse) % Mod
    print Sum



