"""
    大數運算，python無壓力
"""
output = []
push = output.append

while True:
    try:
        expression = input()
    except EOFError:
        break
    push(eval(expression))

print(*output, sep='\n')
