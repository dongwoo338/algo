ans = []
def dfs(L,s):
    mval = 0
    ret = 1
    melem=''
    for i in L[s].values():
        dv = dfs(L,i)
        if(dv>mval):
            mval =dv
            melem = i
    ret += mval
    if mval != 0:
        ans.append(melem)
    return ret
def solution(tickets):
    L ={}
    for i in tickets:
        L[i[0]] = L.get(L[0],[])+[i[1]]
    for i in L.values():
        i.sort()
    dfs(L,"ICN")
    ans.append("ICN")
    ans.reverse()
    return ans
T =[["ICN", "JFK"], ["HND", "IAD"], ["JFK", "HND"]]
print(solution(T))