#list L, value x
#L중 값이 x인 인덱스를 리스트로 만들어 전부 return, 만약 하나도 없으면 [-1]return
def solution(L, x):
    answer = []
    ind = 0
    for val in L:
        if(val==x):
            answer.append(ind)
        ind+=1
    if not answer:
        answer.append(-1)
    return answer

a={}
if not a :
    print("와이게되네")