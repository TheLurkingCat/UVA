"""
    大數運算，python無壓力
"""
while True:
    try:
        expression = input()
    except EOFError:
        break
    print(eval(expression))
