"""
1000位有效數字
"""
from decimal import Decimal, getcontext
from re import sub

getcontext().prec = 1000
while True:
    try:
        a, b = (Decimal(x) for x in input().split())
    except EOFError:
        break
    print(sub('^0|(0*)$', '', format(a ** b, 'f')))
