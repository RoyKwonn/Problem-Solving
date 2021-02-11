def isSoSu(v):
    for i in range(2, int(v**0.5)+1):
        if v%i == 0:
            return 0
    return 1 * (v != 1)

a, b = map(int, input().split())

for i in range(int(a), int(b) + 1):
    if isSoSu(i) == 1:
        print(i)