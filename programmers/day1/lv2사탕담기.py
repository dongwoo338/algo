def solution(m, weights):
    answer = 0
    for stat in range(1,(1<<len(weights))):
        now =0
        for i in range(len(weights)):
            if(stat&(1<<i)):
                now += weights[i]
        if(now==m):
            answer+=1
    return answer

