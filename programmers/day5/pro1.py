def solution(n, words):
    L = {}
    ans =[0,0]
    lword =''
    for s,e in enumerate(words):
        print(e)
        if L.get(e,0)!=0 or(s!=0 and lword[-1] != e[0]):
            ans= [s%n+1,s//n+1]
            return ans
        else:
            L[e]=1
        lword = e
    return ans