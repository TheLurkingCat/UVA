"""
    大數取模 R := B ^ P mod M
"""
output = []
push = output.append

while True:
    try:
        B = int(input())
        P = int(input())
        M = int(input())
        input()
    except EOFError:
        break
    finally:
        push(pow(B, P, M))

print(*output, sep='\n')
