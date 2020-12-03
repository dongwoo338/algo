#피보나치 함수 구현
#재귀
def solution(x):
    if(x<=1):
        return x
    else :
        return solution(x-1)+solution(x-2)
#비재귀
def solution(x):
    pre = 0
    now = 1
    if(x==0):
        return 0
    if(x==1):
        return 1
    for i in range(x-1):
        tmp = now
        now += pre
        pre = tmp
    return now

print(solution(3))