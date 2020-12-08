def solution(n, lost, reserve):
    a =[1]*51
    for i in lost:
        a[i]-=1
    for i in reserve:
        a[i]+=1
    for i in range(1,n+1):
        if a[i]==2 and a[i-1] == 0:
            a[i-1:i+1] = [1,1]
        elif a[i] == 2 and a[i+1] ==0:
            a[i:i+2] = [1,1]
    return len([x for x in a[1:n+1] if x > 0])