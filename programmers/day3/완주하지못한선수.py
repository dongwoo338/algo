def solution(participant, completion):
    answer ={}
    ans =""
    for c in participant:
        answer[c] = answer.get(c,0)+1
    for c in completion:
        answer[c]-=1
    dnf = [k for k,v in answer.items() if v > 0]
    return ans

a ={1:1}
print(a.get(2,0)) #0
print(a.get(2)) # None