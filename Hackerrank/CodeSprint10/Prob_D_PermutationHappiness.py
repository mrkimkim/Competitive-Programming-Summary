DB = []
DB.append([])
DB.append([0,0])
Now = [0, 2]
DB.append(Now)
Mod = 10 ** 9 + 7

for i in range(2, 3001):
    New = [0] * (i + 1)
    K = 2
    j = i - 1
    while j >= (i / 2):
        New[j + 1] = (New[j+1] + Now[j] * K) % Mod
        New[j] += (New[j] + Now[j] * (i + 1 - K)) % Mod
        K += 2
        j -= 1
    Now = New[:]
    DB.append(Now)

T = int(raw_input())
for tt in range(T):
    [N, K] = [int(x) for x in raw_input().split()]
    Sum = 0
    for i in range(K, N): Sum = (Sum + DB[N][i]) % Mod
    print Sum
