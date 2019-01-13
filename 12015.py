from operator import itemgetter

for t in range(int(input())):
    print("Case #{}:".format(t+1))
    d = []
    for i in range(10):
        a, b = input().split()
        b = int(b)
        d.append((a, b, 10-i))
    d.sort(key=itemgetter(1, 2), reverse=True)
    x = d[0][1]
    i = 0
    while i < 10 and d[i][1] == x:
        print(d[i][0])
        i += 1
