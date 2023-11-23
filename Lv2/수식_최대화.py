def toPostfix(ops_priority, exp):
    postfix = []
    ops = []
    
    i = 0
    while i < len(exp):
        if not exp[i].isdigit():
            if len(ops) == 0:
                ops.append(exp[i])
            else:
                while ops_priority.index(ops[-1]) <= ops_priority.index(exp[i]):
                    operand = ops.pop()
                    op2 = postfix.pop()
                    op1 = postfix.pop()
                    postfix.append(calc_exp(op1, op2, operand))

                    if len(ops) == 0:
                        break
                ops.append(exp[i])
                
            i += 1
        else:
            # 숫자만 읽기 위해 연산자를 만날 때까지 반복
            first_idx = i
            numeric = ""
            while exp[i].isdigit():
                numeric += exp[i]
                i += 1
                if i >= len(exp):
                    break
            postfix.append(int(numeric))
    
    while len(ops) > 0:
        operand = ops.pop()
        op2 = postfix.pop()
        op1 = postfix.pop()

        postfix.append(calc_exp(op1, op2, operand))

    return abs(postfix[0])

def calc_exp(op1, op2, operand):
    if operand == '+':
        return op1 + op2
    if operand == '-':
        return op1 - op2
    if operand == '*':
        return op1 * op2

def solution(expression):
    ops_priority_set = [
        ['*', '+', '-'],
        ['*', '-', '+'],
        ['+', '-', '*'],
        ['+', '*', '-'],
        ['-', '+', '*'],
        ['-', '*', '+']
    ]

    # make postfix expression
    postfixCalcResult = toPostfix(ops_priority_set[0], expression)
    for i in range(1, len(ops_priority_set)):
        tmp = toPostfix(ops_priority_set[i], expression)
        if tmp > postfixCalcResult:
            postfixCalcResult = tmp
    
    return postfixCalcResult

expressions =[
    "100-200*300-500+20",
    "50*6-3*2"
]

for ex in expressions:
    print(solution(ex))