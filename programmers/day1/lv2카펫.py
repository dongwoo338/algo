class ArrayStack:

    def __init__(self):
        self.data = []

    def size(self):
        return len(self.data)

    def isEmpty(self):
        return self.size() == 0

    def push(self, item):
        self.data.append(item)

    def pop(self):
        return self.data.pop()

    def peek(self):
        return self.data[-1]


prec = {
    '*': 3, '/': 3,
    '+': 2, '-': 2,
    '(': 1
}


def solution(S):
    opStack = ArrayStack()
    answer =''
    for c in S:
        #c가 문자이면 그냥 출력
        if c == ')':
            while(opStack.size()):
                if(opStack.top()=='('):
                    opStack.pop()
                    break

        elif c not in prec:
            answer+=c
        elif c == '(':
            opStack.push(c)

        else:
            # 스택이 비엇거나
            if(opStack.isEmpty()):
                opStack.push(c)

            # stack top의 우선순위가 더 높으면
            if()
    return answer

