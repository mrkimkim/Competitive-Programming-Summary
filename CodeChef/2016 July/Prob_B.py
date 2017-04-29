T = int(raw_input())

while T > 0:
    T -= 1

    N = int(raw_input())
    Stat = raw_input()
    Num = raw_input().split(' ')
    List = [0]

    idx = 0
    while Stat[idx] == '0': idx += 1
    Sum = int(Num[idx]) - int(Num[0])
    Prev = int(Num[idx])


    Max = 0
    for i in range(idx + 1, N):
        Dist = int(Num[i]) - Prev
        Sum += Dist
        Prev = int(Num[i])
        Max = max(Max, Dist)

        if Stat[i] == '1':
            Sum -= Max
            Max = 0
    print Sum
        
