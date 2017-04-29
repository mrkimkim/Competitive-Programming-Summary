def getMAXSub(Sub_Path):
    MAX = 0
    Partial = 0
    for i in xrange(len(Sub_Path)):
        Partial += Sub_Path[i]
        if Partial < 0: Partial = 0
        MAX = max(MAX, Partial)
    return MAX

T = int(raw_input())

for tt in xrange(T):
    N = int(raw_input().strip())
    Edge = [int(x) for x in raw_input().strip().split(' ')]

    Src, Dest = [int(x) for x in raw_input().strip().split(' ')]
    Src, Dest = Src - 1, Dest - 1

    Path = Edge[Src:Dest]
    Sub_Path = Edge[Dest:] + Edge[:Src]
    MIN = sum(Path + [0]) + 2 * (sum(Sub_Path + [0]) - getMAXSub(Sub_Path))

    Path = Edge[Dest:] + Edge[:Src]
    Sub_Path = Edge[Src:Dest]
    MIN = min(MIN, sum(Path + [0]) + 2 * (sum(Sub_Path + [0]) - getMAXSub(Sub_Path)))

    print MIN
