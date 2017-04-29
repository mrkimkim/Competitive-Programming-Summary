L = int(raw_input())
R = int(raw_input())

MAX = 0
for i in range(L,R+1):
    for j in range(i,R+1):
        MAX = max(MAX, i ^ j)

print MAX
