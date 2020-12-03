
def solution(L, x):
    #만약 x보다 큰 원소가 없으면 -> 가장 앞에 삽입
    if (x < L[0]):
        L.insert(0, x)
        return L
    #만약 x보다 작은 원소가 없으면 -> 가장 뒤에 삽입
    if (x > L[-1]):
        L.append(x)
        return L
    ind =0

    #나머지경우, x보다 큰 원소를 발견하면 - > 그 위치에 x를 삽입
    for val in L:
        if (val >= x):
            L.insert(ind, x)
            return L
        ind+=1
L = [20, 37, 58, 72, 91]
print(solution(L,92))