T = int(input())

for i in range(T):
    n = int(input())
    arr = []
    for j in range(n):
        inp = input()
        s = int(inp.split()[0])
        e = int(inp.split()[1])
        arr.append([s, e])
        print(s, e)
