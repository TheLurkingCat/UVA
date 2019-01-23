"""
    大數、費氏數列
"""
output = []
push = output.append
Fibonacci = {0: 0, 1: 1}
for i in range(2, 5001):
    Fibonacci[i] = Fibonacci[i - 1] + Fibonacci[i - 2]

while True:
    try:
        index = int(input())
    except EOFError:
        break
    push("The Fibonacci number for {} is {}".format(index, Fibonacci[index]))

print(*output, sep='\n')
