
MINT = -1234567
dp1 = [[MINT]*201]*201
dp2 = [[-MINT]*201]*201 # 최소값
opp = [] # 연산자
a= []
#[s,e]까지를 계산했을 때의 최대값
def rec(s,e): #최대값
    print(s)
    print(e)
    print("o")
    if s==e:
        dp1[s][e] = a[s]
        return dp1[s][e]
    if dp1[s][e] != MINT:
        return dp1[s][e]
    for k in range(s,e):
        newval=0
        if opp[k] == '+':
            newval = rec(s,k)+rec(k+1,e)
            if(newval>dp1[s][e]):
                dp1[s][e]= newval
        else:
            newval = rec(s,k)-rec2(k+1,e)
            if(newval>dp1[s][e]):
                dp1[s][e] = newval
        if s==0 and e == 2:
            print(newval)
    return dp1[s][e]
def rec2(s,e): #최소값
    print(s)
    print(e)
    print("x")
    if s==e:
        dp2[s][e] = a[s]
        return dp2[s][e]
    if dp2[s][e] != -MINT:
        return dp2[s][e]
    for k in range(s,e):
        if opp[k] == '+':
            newval = rec2(s,k)+rec2(k+1,e)
            if(newval < dp2[s][e]):
                dp2[s][e]= newval
        else:
            newval = rec2(s,k)-rec(k+1,e)
            if(newval < dp2[s][e]):
                dp2[s][e] = newval
    return dp2[s][e]
def solution(arr):
    for s,e in enumerate(arr):
        if s%2==0:
            a.append(int(e))
        else:
            opp.append(e)
    n = len(opp)
    return rec(0,n)

li=['1', '-', '3','+','5']
print(solution(li))

print(rec(2,2))