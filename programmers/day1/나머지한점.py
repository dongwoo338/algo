def solution(v):
    x=0
    y=0
    for xy in v:
        x^=xy[0]
        y^=xy[1]
    answer=[x,y]
    return answer