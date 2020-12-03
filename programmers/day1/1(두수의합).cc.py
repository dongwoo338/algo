
def solution(L, x):
    if (x < L[0]):
        L.insert(0, x)
        return L
    ind =0
    for val in L:
        if (val >= x):
            L.insert(ind, x)
            return L
        ind+=1
L = [20, 37, 58, 72, 91]
print(solution(L,62))