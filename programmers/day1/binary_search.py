#정렬된 L에서 값 x를 가지는 인덱스를 return 없으면 -1
def solution(L, x):
    lo = 0
    hi = len(L) - 1
    while(lo <= hi) :
        mid = (lo+hi)//2
        if(L[mid]==x):
            return mid
        elif(L[mid]>x):
            hi = mid- 1
        else:
            lo = mid+ 1
    return -1
print(solution([1,2,4],4))