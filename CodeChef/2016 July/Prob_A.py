T = int(raw_input())

while T > 0:
    N = int(raw_input())
    Grade = raw_input().split(' ')

    isPerfect = False
    isFail = False
    Sum = 0
    for i in xrange(N):
        Sum += int(Grade[i])
        isPerfect |= (Grade[i] == '5')
        isFail |= (Grade[i] == '2')
        
    if isPerfect and (isFail == False) and Sum >= 4 * N:
        print "Yes"
    else:
        print "No"

    T -= 1
