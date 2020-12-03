def solution(brown, red):
    answer=[]
    rc = brown + red
    #r+c = (brown+4)//2
    c=1
    while(c*c<=rc):
        if(rc%c==0 and (rc//c+c) == (brown+4)//2):
           answer.append(rc//c)
           answer.append(c)
        c+=1
    return answer
