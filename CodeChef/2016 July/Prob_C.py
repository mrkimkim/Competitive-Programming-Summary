def Calc(A, B, idx_a, idx_b, Goal, N):

    while idx_a < N:
        if A[idx_a] > Goal:
            return False

        elif A[idx_a] == Goal:
            idx_a = idx_a

        elif idx_b == idx_a - 1:
            # Take Left One
            if A[idx_a] + B[idx_b] == Goal and idx_a + 1 < N:
                idx_b += 1

            # Take Left and Middle
            elif A[idx_a] + B[idx_b] + B[idx_b + 1] == Goal:
                idx_b += 2

            # if Right is usable
            elif idx_b + 2 < N:

                # Take Left and Middle and Right
                if A[idx_a] + B[idx_b] + B[idx_b + 1] + B[idx_b + 2] == Goal:
                    idx_b += 3

                    # Take Left and Right
                elif idx_a + 1 < N and A[idx_a] + B[idx_b] + B[idx_b + 2] == Goal:
                    A[idx_a + 1] += B[idx_a]
                    idx_b += 3

                else:
                    return False

            else:
                return False


        elif idx_b == idx_a:
            # Take Middle
            if A[idx_a] + B[idx_a] == Goal:
                idx_b += 1
            # if Right is usable
            elif idx_b + 1 < N:
                # Take Right
                if A[idx_a] + B[idx_a + 1] == Goal:
                    A[idx_a + 1] += B[idx_a]
                    idx_b += 2
                # Take Middle and Right
                elif A[idx_a] + B[idx_a] + B[idx_a + 1] == Goal:
                    idx_b += 2
                else:
                    return False
            else:
                return False

        elif idx_b == idx_a + 1 and idx_b < N:
            # Take Right
            if A[idx_a] + B[idx_b] == Goal:
                idx_b = idx_b + 1
            else:
                return False
        else:
            return False

        idx_a += 1

    if idx_a == idx_b: return True
    else: return False


T = int(raw_input());

while T > 0:
    T -= 1

    N = int(raw_input())
    B = raw_input().split(' ')
    A = raw_input().split(' ')
    for i in xrange(N): A[i] = int(A[i])
    for i in xrange(N): B[i] = int(B[i])

    # Set Goal
    Flag = False
    Ret = -1
    Flag = Calc(A, B, 1, 0, A[0], N)
    if Flag == True: Ret = A[0]
    else:
        Flag = Calc(A, B, 1, 1, A[0] + B[0], N)
        if Flag == True: Ret = A[0] + B[0]
        elif N >= 2:
            Flag = Calc(A, B, 1, 2, A[0] + B[0] + B[1], N)
            if Flag == True: Ret = A[0] + B[0] + B[1]
            else:
                A[1] += B[0]
                Flag = Calc(A, B, 1, 2, A[0] + B[1], N)
                if Flag == True: Ret = A[0] + B[1]

    print Ret

