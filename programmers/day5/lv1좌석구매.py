def solution(seat):
    a = set
    answer = 0
    for i in seat:
        x = i[0]
        y = i[1]
        nval = x*100001+y
        if nval in a:
            break
        else:
            answer+=1
            a.add(nval)
    return answer

aa=[[1,1],[2,1],[1,2],[3,4],[2,1],[2,1]]
print(solution(aa))