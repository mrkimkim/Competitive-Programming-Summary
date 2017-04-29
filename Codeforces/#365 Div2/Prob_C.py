def findConvexBottom():
    global w, N, vertics

    MIN = w + 1
    MIN_IDX = -1
    for i in xrange(N):
        if vertics[i][1] < MIN or (vertics[i][1] == MIN and vertics[i][0] < vertics[MIN_IDX][0]):
            MIN = vertics[i][1]
            MIN_IDX = i

    return MIN_IDX


def findConvexTop():
    global w, N, vertics

    MAX = -1
    MAX_IDX = -1
    for i in xrange(N):
        if vertics[i][1] > MAX or (vertics[i][1] == MAX and vertics[i][0] < vertics[MAX_IDX][0]):
            MAX = vertics[i][1]
            MAX_IDX = i

    return MAX_IDX


def getFrontSide(Bottom, Top):
    global v, N, vertics

    FrontSide = []
    Head = Bottom
    while Head != Top:
        # clock wise tracking
        FrontSide.append([vertics[Head][1], float(vertics[Head][0])/float(v)])
        Head = (Head - 1) % N
    FrontSide.append([vertics[Head][1], float(vertics[Head][0])/float(v)])

    return FrontSide

def getBackSide(Bottom, Top):
    global v, N, vertics

    BackSide = []
    Head = Bottom
    while Head != Top:
        # counter-clock wise tracking
        BackSide.append([vertics[Head][1], float(vertics[Head][0])/float(v)])
        Head = (Head + 1) % N
    BackSide.append([vertics[Head][1], float(vertics[Head][0])/float(v)])

    return BackSide

def isReachableFromFrontSide():
    global u, FrontSide
    for vertex in FrontSide:
        if vertex[1] * u < vertex[0]: return False
    return True


def getMinimalReachableTime():
    global u, BackSide
    current = 0
    time = 0.0
    for vertex in BackSide:
        current = min(vertex[0], current + max(0.0, vertex[1] - time) * u)
        time = max(time, vertex[1])

    return time + float(w - current) / u
        
    
N, w, v, u = [int(x) for x in raw_input().split(' ')]

vertics = []
for i in xrange(N):
    vertics.append([int(x) for x in raw_input().split(' ')])

Bottom = findConvexBottom()
Top = findConvexTop()
# get FrontSide

FrontSide = getFrontSide(Bottom, Top)
if isReachableFromFrontSide(): print float(w)/u

# get BackSide
else:
    BackSide = getBackSide(Bottom, Top)
    print getMinimalReachableTime()
